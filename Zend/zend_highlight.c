/*
   +----------------------------------------------------------------------+
   | Zend Engine                                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) 1998-2003 Zend Technologies Ltd. (http://www.zend.com) |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.00 of the Zend license,     |
   | that is bundled with this package in the file LICENSE, and is        | 
   | available at through the world-wide-web at                           |
   | http://www.zend.com/license/2_00.txt.                                |
   | If you did not receive a copy of the Zend license and are unable to  |
   | obtain it through the world-wide-web, please send a note to          |
   | license@zend.com so we can mail you a copy immediately.              |
   +----------------------------------------------------------------------+
   | Authors: Andi Gutmans <andi@zend.com>                                |
   |          Zeev Suraski <zeev@zend.com>                                |
   +----------------------------------------------------------------------+
*/


#include "zend.h"
#include <zend_language_parser.h>
#include "zend_compile.h"
#include "zend_highlight.h"
#include "zend_ptr_stack.h"
#include "zend_globals.h"

ZEND_API void zend_html_putc(char c)
{
	switch (c) {
		case '\n':
			ZEND_PUTS("<br />");
			break;
		case '<':
			ZEND_PUTS("&lt;");
			break;
		case '>':
			ZEND_PUTS("&gt;");
			break;
		case '&':
			ZEND_PUTS("&amp;");
			break;
		case ' ':
			ZEND_PUTS("&nbsp;");
			break;
		case '\t':
			ZEND_PUTS("&nbsp;&nbsp;&nbsp;&nbsp;");
			break;
		default:
			ZEND_PUTC(c);
			break;
	}
}


ZEND_API void zend_html_puts(const char *s, uint len TSRMLS_DC)
{
	const char *ptr=s, *end=s+len;
#ifdef ZEND_MULTIBYTE
	char *mbs;
	int mblen;

	if (LANG_SCNG(output_filter)) {
		LANG_SCNG(output_filter)(&mbs, &mblen, s, len TSRMLS_CC);
		ptr = mbs;
		end = mbs+mblen;
	}
#endif /* ZEND_MULTIBYTE */
	
	while (ptr<end) {
		if (*ptr==' ') {
			/* Series of spaces should be displayed as &nbsp;'s
			 * whereas single spaces should be displayed as a space
			 */
			if ((ptr+1) < end && *(ptr+1)==' ') {
				do {
					zend_html_putc(*ptr);
				} while ((++ptr < end) && (*ptr==' '));
			} else {
				(void) ZEND_PUTC(*ptr);
				ptr++;
			}
		} else {
			zend_html_putc(*ptr++);
		}
	}

#ifdef ZEND_MULTIBYTE
	if (LANG_SCNG(output_filter)) {
		efree(mbs);
	}
#endif /* ZEND_MULTIBYTE */
}



ZEND_API void zend_highlight(zend_syntax_highlighter_ini *syntax_highlighter_ini TSRMLS_DC)
{
	zval token;
	int token_type;
	char *last_color = syntax_highlighter_ini->highlight_html;
	char *next_color;
	int in_string=0, post_heredoc = 0;

	zend_printf("<code>");
	zend_printf("<font color=\"%s\">\n", last_color);
	/* highlight stuff coming back from zendlex() */
	token.type = 0;
	while ((token_type=lex_scan(&token TSRMLS_CC))) {
		switch (token_type) {
			case T_INLINE_HTML:
				next_color = syntax_highlighter_ini->highlight_html;
				break;
			case T_COMMENT:
				next_color = syntax_highlighter_ini->highlight_comment;
				break;
			case T_OPEN_TAG:
			case T_OPEN_TAG_WITH_ECHO:
				next_color = syntax_highlighter_ini->highlight_default;
				break;
			case T_CLOSE_TAG:
				next_color = syntax_highlighter_ini->highlight_default;
				break;
			case T_CONSTANT_ENCAPSED_STRING:
				next_color = syntax_highlighter_ini->highlight_string;
				break;
			case '"':
				next_color = syntax_highlighter_ini->highlight_string;
				in_string = !in_string;
				break;				
			case T_WHITESPACE:
				zend_html_puts(LANG_SCNG(yy_text), LANG_SCNG(yy_leng) TSRMLS_CC);  /* no color needed */
				token.type = 0;
				continue;
				break;
			default:
				if (in_string) {
					next_color = syntax_highlighter_ini->highlight_string;
				} else if (token.type == 0) {
					next_color = syntax_highlighter_ini->highlight_keyword;
				} else {
					next_color = syntax_highlighter_ini->highlight_default;
				}
				break;
		}

		if (last_color != next_color) {
			if (last_color != syntax_highlighter_ini->highlight_html) {
				zend_printf("</font>");
			}
			last_color = next_color;
			if (last_color != syntax_highlighter_ini->highlight_html) {
				zend_printf("<font color=\"%s\">", last_color);
			}
		}
		switch (token_type) {
			case T_END_HEREDOC:
				zend_html_puts(token.value.str.val, token.value.str.len TSRMLS_CC);
				post_heredoc = 1;
				break;
			default:
				zend_html_puts(LANG_SCNG(yy_text), LANG_SCNG(yy_leng) TSRMLS_CC);
				if (post_heredoc) {
					 zend_html_putc('\n');
					 post_heredoc = 0;
				}
				break;
		}

		if (token.type == IS_STRING) {
			switch (token_type) {
				case T_OPEN_TAG:
				case T_OPEN_TAG_WITH_ECHO:
				case T_CLOSE_TAG:
				case T_WHITESPACE:
				case T_COMMENT:
					break;
				default:
					efree(token.value.str.val);
					break;
			}
		} else if (token_type == T_END_HEREDOC) {
			efree(token.value.str.val);
		}
		token.type = 0;
	}
	if (last_color != syntax_highlighter_ini->highlight_html) {
		zend_printf("</font>\n");
	}
	zend_printf("</font>\n");
	zend_printf("</code>");
}


ZEND_API void zend_strip(TSRMLS_D)
{
	zval token;
	int token_type;
	int prev_space = 0;

	token.type = 0;
	while ((token_type=lex_scan(&token TSRMLS_CC))) {
		switch (token_type) {
			case T_WHITESPACE:
				if (!prev_space) {
					putchar(' ');
					prev_space = 1;
				}
						/* lack of break; is intentional */
			case T_COMMENT:
				token.type = 0;
				continue;
			
			case T_END_HEREDOC: {
					char *ptr = LANG_SCNG(yy_text);

					fwrite(ptr, LANG_SCNG(yy_leng) - 1, 1, stdout);
					/* The ensure that we only write one ; and that it followed by the required newline */
					putchar('\n');
					if (ptr[LANG_SCNG(yy_leng) - 1] == ';') {
						lex_scan(&token TSRMLS_CC);
					}
					efree(token.value.str.val);
				}
				break;
			
			default:
				fwrite(LANG_SCNG(yy_text), LANG_SCNG(yy_leng), 1, stdout);
				break;
		}

		if (token.type == IS_STRING) {
			switch (token_type) {
				case T_OPEN_TAG:
				case T_OPEN_TAG_WITH_ECHO:
				case T_CLOSE_TAG:
				case T_WHITESPACE:
				case T_COMMENT:
					break;

				default:
					efree(token.value.str.val);
					break;
			}
		}
		prev_space = token.type = 0;
	}
#ifdef ZEND_MULTIBYTE
	if (LANG_SCNG(code)) {
		efree(LANG_SCNG(code));
	}
	if (LANG_SCNG(current_code)) {
		efree(LANG_SCNG(current_code));
	}
#endif /* ZEND_MULTIBYTE */
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 */

