srcdir = /home/lkq/php
builddir = /home/lkq/php
top_srcdir = /home/lkq/php
top_builddir = /home/lkq/php
SHLIB_SUFFIX_NAME = so
SAPI_CLI_PATH = sapi/cli/php
BUILD_CLI = $(LIBTOOL) --mode=link $(CC) -export-dynamic $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(EXTRA_LDFLAGS_PROGRAM) $(LDFLAGS) $(PHP_RPATHS) $(PHP_GLOBAL_OBJS) $(PHP_CLI_OBJS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $(SAPI_CLI_PATH)
INSTALL_CLI = $(mkinstalldirs) $(INSTALL_ROOT)$(bindir); $(INSTALL) -m 0755 $(SAPI_CLI_PATH) $(INSTALL_ROOT)$(bindir)/$(program_prefix)php$(program_suffix)
SERVLET_CLASSPATH =
SAPI_CGI_PATH = sapi/cgi/php
BUILD_CGI = $(LIBTOOL) --mode=link $(CC) -export-dynamic $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(EXTRA_LDFLAGS_PROGRAM) $(LDFLAGS) $(PHP_RPATHS) $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $(SAPI_CGI_PATH)
MYSQL_SHARED_LIBADD =
MYSQL_MODULE_TYPE = builtin
MYSQL_LIBS =
MYSQL_INCLUDE =
PCRE_SHARED_LIBADD =
SESSION_SHARED_LIBADD =
PHP_CLI_TARGET = $(SAPI_CLI_PATH)
PHP_SAPI_OBJS = sapi/cgi/cgi_main.lo sapi/cgi/getopt.lo main/internal_functions.lo
PHP_CLI_OBJS = sapi/cli/php_cli.lo sapi/cli/getopt.lo main/internal_functions_cli.lo
PHP_GLOBAL_OBJS = ext/ctype/ctype.lo ext/mysql/php_mysql.lo ext/mysql/libmysql/libmysql.lo ext/mysql/libmysql/errmsg.lo ext/mysql/libmysql/net.lo ext/mysql/libmysql/violite.lo ext/mysql/libmysql/password.lo ext/mysql/libmysql/my_init.lo ext/mysql/libmysql/my_lib.lo ext/mysql/libmysql/my_static.lo ext/mysql/libmysql/my_malloc.lo ext/mysql/libmysql/my_realloc.lo ext/mysql/libmysql/my_create.lo ext/mysql/libmysql/my_delete.lo ext/mysql/libmysql/my_tempnam.lo ext/mysql/libmysql/my_open.lo ext/mysql/libmysql/mf_casecnv.lo ext/mysql/libmysql/my_read.lo ext/mysql/libmysql/my_write.lo ext/mysql/libmysql/errors.lo ext/mysql/libmysql/my_error.lo ext/mysql/libmysql/my_getwd.lo ext/mysql/libmysql/my_div.lo ext/mysql/libmysql/mf_pack.lo ext/mysql/libmysql/my_messnc.lo ext/mysql/libmysql/mf_dirname.lo ext/mysql/libmysql/mf_fn_ext.lo ext/mysql/libmysql/mf_wcomp.lo ext/mysql/libmysql/typelib.lo ext/mysql/libmysql/safemalloc.lo ext/mysql/libmysql/my_alloc.lo ext/mysql/libmysql/mf_format.lo ext/mysql/libmysql/mf_path.lo ext/mysql/libmysql/mf_unixpath.lo ext/mysql/libmysql/my_fopen.lo ext/mysql/libmysql/mf_loadpath.lo ext/mysql/libmysql/my_pthread.lo ext/mysql/libmysql/my_thr_init.lo ext/mysql/libmysql/thr_mutex.lo ext/mysql/libmysql/mulalloc.lo ext/mysql/libmysql/string.lo ext/mysql/libmysql/default.lo ext/mysql/libmysql/my_compress.lo ext/mysql/libmysql/array.lo ext/mysql/libmysql/my_once.lo ext/mysql/libmysql/list.lo ext/mysql/libmysql/my_net.lo ext/mysql/libmysql/dbug.lo ext/mysql/libmysql/strmov.lo ext/mysql/libmysql/strxmov.lo ext/mysql/libmysql/strnmov.lo ext/mysql/libmysql/strmake.lo ext/mysql/libmysql/strend.lo ext/mysql/libmysql/strfill.lo ext/mysql/libmysql/is_prefix.lo ext/mysql/libmysql/int2str.lo ext/mysql/libmysql/str2int.lo ext/mysql/libmysql/strinstr.lo ext/mysql/libmysql/strcont.lo ext/mysql/libmysql/strcend.lo ext/mysql/libmysql/bchange.lo ext/mysql/libmysql/bmove.lo ext/mysql/libmysql/bmove_upp.lo ext/mysql/libmysql/longlong2str.lo ext/mysql/libmysql/strtoull.lo ext/mysql/libmysql/strtoll.lo ext/mysql/libmysql/charset.lo ext/mysql/libmysql/ctype.lo ext/overload/overload.lo ext/pcre/pcrelib/maketables.lo ext/pcre/pcrelib/get.lo ext/pcre/pcrelib/study.lo ext/pcre/pcrelib/pcre.lo ext/pcre/php_pcre.lo ext/posix/posix.lo ext/session/session.lo ext/session/mod_files.lo ext/session/mod_mm.lo ext/session/mod_user.lo regex/regcomp.lo regex/regexec.lo regex/regerror.lo regex/regfree.lo ext/standard/array.lo ext/standard/base64.lo ext/standard/basic_functions.lo ext/standard/browscap.lo ext/standard/crc32.lo ext/standard/crypt.lo ext/standard/cyr_convert.lo ext/standard/datetime.lo ext/standard/dir.lo ext/standard/dl.lo ext/standard/dns.lo ext/standard/exec.lo ext/standard/file.lo ext/standard/filestat.lo ext/standard/flock_compat.lo ext/standard/formatted_print.lo ext/standard/fsock.lo ext/standard/head.lo ext/standard/html.lo ext/standard/image.lo ext/standard/info.lo ext/standard/iptc.lo ext/standard/lcg.lo ext/standard/link.lo ext/standard/mail.lo ext/standard/math.lo ext/standard/md5.lo ext/standard/metaphone.lo ext/standard/microtime.lo ext/standard/pack.lo ext/standard/pageinfo.lo ext/standard/parsedate.lo ext/standard/quot_print.lo ext/standard/rand.lo ext/standard/reg.lo ext/standard/soundex.lo ext/standard/string.lo ext/standard/scanf.lo ext/standard/syslog.lo ext/standard/type.lo ext/standard/uniqid.lo ext/standard/url.lo ext/standard/url_scanner.lo ext/standard/var.lo ext/standard/versioning.lo ext/standard/assert.lo ext/standard/strnatcmp.lo ext/standard/levenshtein.lo ext/standard/incomplete_class.lo ext/standard/url_scanner_ex.lo ext/standard/ftp_fopen_wrapper.lo ext/standard/http_fopen_wrapper.lo ext/standard/php_fopen_wrapper.lo ext/standard/credits.lo ext/standard/css.lo ext/standard/var_unserializer.lo ext/standard/ftok.lo ext/standard/aggregation.lo ext/standard/sha1.lo ext/tokenizer/tokenizer.lo ext/xml/xml.lo ext/xml/expat/xmlparse.lo ext/xml/expat/xmlrole.lo ext/xml/expat/xmltok.lo TSRM/TSRM.lo TSRM/tsrm_strtok_r.lo TSRM/tsrm_virtual_cwd.lo main/main.lo main/snprintf.lo main/spprintf.lo main/php_sprintf.lo main/safe_mode.lo main/fopen_wrappers.lo main/alloca.lo main/php_scandir.lo main/php_ini.lo main/SAPI.lo main/rfc1867.lo main/php_content_types.lo main/strlcpy.lo main/strlcat.lo main/mergesort.lo main/reentrancy.lo main/php_variables.lo main/php_ticks.lo main/streams.lo main/network.lo main/php_open_temporary_file.lo main/php_logos.lo main/output.lo main/memory_streams.lo main/user_streams.lo Zend/zend_language_parser.lo Zend/zend_language_scanner.lo Zend/zend_ini_parser.lo Zend/zend_ini_scanner.lo Zend/zend_alloc.lo Zend/zend_compile.lo Zend/zend_constants.lo Zend/zend_dynamic_array.lo Zend/zend_execute_API.lo Zend/zend_highlight.lo Zend/zend_llist.lo Zend/zend_opcode.lo Zend/zend_operators.lo Zend/zend_ptr_stack.lo Zend/zend_stack.lo Zend/zend_variables.lo Zend/zend.lo Zend/zend_API.lo Zend/zend_extensions.lo Zend/zend_hash.lo Zend/zend_list.lo Zend/zend_indent.lo Zend/zend_builtin_functions.lo Zend/zend_sprintf.lo Zend/zend_ini.lo Zend/zend_qsort.lo Zend/zend_multibyte.lo Zend/zend_strtod.lo Zend/zend_execute.lo Zend/dezender/dezender.lo
PHP_MODULES =
EXT_LIBS =
abs_builddir = /home/lkq/php
abs_srcdir = /home/lkq/php
php_abs_top_builddir = /home/lkq/php
php_abs_top_srcdir = /home/lkq/php
bindir = ${exec_prefix}/bin
exec_prefix = ${prefix}
program_prefix =
program_suffix =
includedir = ${prefix}/include
libdir = ${exec_prefix}/lib/php
mandir = ${prefix}/man
phplibdir = /home/lkq/php/modules
phptempdir = /home/lkq/php/libs
prefix = /usr/local
localstatedir = ${prefix}/var
datadir = ${prefix}/share/php
sysconfdir = ${prefix}/etc
AWK = gawk
CC = gcc -g
CFLAGS = $(CFLAGS_CLEAN) -prefer-non-pic -static
CFLAGS_CLEAN = -g -O2
CONFIGURE_COMMAND = './configure'
CPP = gcc -E
CPPFLAGS =
CXX =
CXXFLAGS = -prefer-non-pic -static
CXXFLAGS_CLEAN =
CXX_PHP_COMPILE = $(LIBTOOL) --mode=compile $(CXX_COMPILE) -c $<
DEBUG_CFLAGS =
EXTENSION_DIR = /usr/local/lib/php/extensions/no-debug-non-zts-20020429
EXTRA_LDFLAGS =
EXTRA_LDFLAGS_PROGRAM =
EXTRA_LIBS = -lcrypt -lcrypt -lresolv -lm -ldl -lnsl -lcrypt -lcrypt
ZEND_EXTRA_LIBS =
INCLUDES = -I/home/lkq/php/ext/xml/expat -I$(top_builddir)/TSRM -I$(top_builddir)/Zend
EXTRA_INCLUDES =
INCLUDE_PATH = .:/usr/local/lib/php
INSTALL_IT = @echo "Installing PHP CGI into: $(INSTALL_ROOT)$(bindir)/"; $(INSTALL) -m 0755 $(SAPI_CGI_PATH) $(INSTALL_ROOT)$(bindir)/$(program_prefix)php$(program_suffix)
LEX = flex
LEX_OUTPUT_ROOT = lex.yy
LFLAGS =
LIBTOOL = $(SHELL) $(top_builddir)/libtool --silent --preserve-dup-deps
LN_S = ln -s
NATIVE_RPATHS =
PEAR_INSTALLDIR = ${exec_prefix}/lib/php
PHP_BUILD_DATE = 2005-09-11
PHP_COMPILE = $(LIBTOOL) --mode=compile $(COMPILE) -c $<
PHP_LDFLAGS =
PHP_LIBS =
OVERALL_TARGET = $(SAPI_CGI_PATH)
PHP_RPATHS =
PHP_SAPI = cgi
PHP_VERSION = 4.3.11
PROG_SENDMAIL = /usr/sbin/sendmail
RE2C = exit 0;
SHELL = /bin/sh
SHARED_LIBTOOL = $(LIBTOOL)
WARNING_LEVEL =
PHP_FRAMEWORKS =
PHP_FRAMEWORKPATH =
YACC = bison -y
SHLIB_SUFFIX_NAME = so
all_targets = $(OVERALL_TARGET) $(PHP_MODULES) $(PHP_CLI_TARGET)
install_targets = install-sapi install-pear install-build install-headers install-programs
mkinstalldirs = $(top_srcdir)/build/shtool mkdir -p
INSTALL = $(top_srcdir)/build/shtool install -c
INSTALL_DATA = $(INSTALL) -m 644

DEFS = -DPHP_ATOM_INC -I$(top_builddir)/include -I$(top_builddir)/main -I$(top_srcdir)
COMMON_FLAGS = $(DEFS) $(INCLUDES) $(EXTRA_INCLUDES) $(CPPFLAGS) $(PHP_FRAMEWORKPATH)


all: $(all_targets) 
	@echo
	@echo "Build complete."
	@echo "(It is safe to ignore warnings about tempnam and tmpnam)."
	@echo
	
build-modules: $(PHP_MODULES)

libphp4.la: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(LIBTOOL) --mode=link $(CC) $(CFLAGS) $(EXTRA_CFLAGS) -rpath $(phptempdir) $(EXTRA_LDFLAGS) $(LDFLAGS) $(PHP_RPATHS) $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@
	-@$(LIBTOOL) --silent --mode=install cp libphp4.la $(phptempdir)/libphp4.la >/dev/null 2>&1

libs/libphp4.bundle: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(CC) $(MH_BUNDLE_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) $(EXTRA_LDFLAGS) $(PHP_GLOBAL_OBJS:.lo=.o) $(PHP_SAPI_OBJS:.lo=.o) $(PHP_FRAMEWORKS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@ && cp $@ libs/libphp4.so

install: $(all_targets) $(install_targets)

install-sapi: $(OVERALL_TARGET)
	@echo "Installing PHP SAPI module:       $(PHP_SAPI)"
	-@$(mkinstalldirs) $(INSTALL_ROOT)$(bindir)
	-@if test ! -r $(phptempdir)/libphp4.$(SHLIB_SUFFIX_NAME); then \
		for i in 0.0.0 0.0 0; do \
			if test -r $(phptempdir)/libphp4.$(SHLIB_SUFFIX_NAME).$$i; then \
				$(LN_S) $(phptempdir)/libphp4.$(SHLIB_SUFFIX_NAME).$$i $(phptempdir)/libphp4.$(SHLIB_SUFFIX_NAME); \
				break; \
			fi; \
		done; \
	fi
	@$(INSTALL_IT)

install-modules: build-modules
	@test -d modules && \
	$(mkinstalldirs) $(INSTALL_ROOT)$(EXTENSION_DIR)
	@echo "Installing shared extensions:     $(INSTALL_ROOT)$(EXTENSION_DIR)/"
	@rm -f modules/*.la >/dev/null 2>&1
	@$(INSTALL) modules/* $(INSTALL_ROOT)$(EXTENSION_DIR)

install-tester:
	@echo "Installing regression tester:     $(INSTALL_ROOT)$(PEAR_INSTALLDIR)/"
	@$(mkinstalldirs) $(INSTALL_ROOT)$(PEAR_INSTALLDIR)
	@$(INSTALL) -m 755 $(top_srcdir)/run-tests.php $(INSTALL_ROOT)$(PEAR_INSTALLDIR)

install-su: install-pear install-tester

test: 
	-@if test -x $(SAPI_CLI_PATH) && test ! -z $(SAPI_CLI_PATH); then \
		TEST_PHP_EXECUTABLE=$(top_builddir)/$(SAPI_CLI_PATH) \
		TEST_PHP_SRCDIR=$(top_srcdir) \
		CC="$(CC)" \
			$(top_builddir)/$(SAPI_CLI_PATH) -d 'open_basedir=' -d 'safe_mode=0' -d 'output_buffering=0' $(top_srcdir)/run-tests.php $(TESTS); \
	else \
		echo "ERROR: Cannot run tests without CLI sapi."; \
	fi

clean:
	find . -name \*.lo | xargs rm -f
	find . -name \*.o | xargs rm -f
	find . -name \*.la | xargs rm -f
	find . -name \*.a | xargs rm -f
	find . -name \*.so | xargs rm -f
	find . -name .libs -a -type d|xargs rm -rf
	rm -f libphp4.la $(SAPI_CLI_PATH) $(OVERALL_TARGET) modules/* libs/*

distclean: clean
	rm -f config.cache config.log config.status Makefile.objects Makefile.fragments libtool main/php_config.h stamp-h php4.spec sapi/apache/libphp4.module buildmk.stamp
	egrep define'.*include/php' configure|sed 's/.*>//'|xargs rm -f
	find . -name Makefile | xargs rm -f

.PHONY: all clean install distclean test
.NOEXPORT:
$(SAPI_CLI_PATH): $(PHP_GLOBAL_OBJS) $(PHP_CLI_OBJS)
	$(BUILD_CLI)

install-cli: $(SAPI_CLI_PATH)
	@echo "Installing PHP CLI binary:        $(INSTALL_ROOT)$(bindir)/"
	@$(INSTALL_CLI)
	@echo "Installing PHP CLI man page:      $(INSTALL_ROOT)$(mandir)/man1/"
	@$(mkinstalldirs) $(INSTALL_ROOT)$(mandir)/man1
	@$(INSTALL_DATA) sapi/cli/php.1 $(INSTALL_ROOT)$(mandir)/man1/php.1
$(SAPI_CGI_PATH): $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(BUILD_CGI)

/home/lkq/php/ext/standard/parsedate.c: /home/lkq/php/ext/standard/parsedate.y

/home/lkq/php/ext/standard/var_unserializer.c: /home/lkq/php/ext/standard/var_unserializer.re
	$(RE2C) -b /home/lkq/php/ext/standard/var_unserializer.re > $@

/home/lkq/php/ext/standard/url_scanner_ex.c: /home/lkq/php/ext/standard/url_scanner_ex.re
	$(RE2C) -b /home/lkq/php/ext/standard/url_scanner_ex.re > $@

ext/standard/info.lo: ext/standard/../../main/build-defs.h
Zend/zend_language_parser.h:
ext/tokenizer/tokenizer.lo: Zend/zend_language_parser.h
# -*- makefile -*-

peardir=$(PEAR_INSTALLDIR)

# Skip all php.ini files altogether
PEAR_INSTALL_FLAGS = -n -dshort_open_tag=0 -dsafe_mode=0

install-pear-installer: $(top_builddir)/sapi/cli/php
	@$(top_builddir)/sapi/cli/php $(PEAR_INSTALL_FLAGS) /home/lkq/php/pear/install-pear.php -d "$(peardir)" -b "$(bindir)" /home/lkq/php/pear/package-*.xml

install-pear-packages: $(top_builddir)/sapi/cli/php
	@$(top_builddir)/sapi/cli/php $(PEAR_INSTALL_FLAGS) /home/lkq/php/pear/install-pear.php -d "$(peardir)" -b "$(bindir)" /home/lkq/php/pear/packages/*.tar

install-pear:
	@echo "Installing PEAR environment:      $(INSTALL_ROOT)$(peardir)/"
	@if $(mkinstalldirs) $(INSTALL_ROOT)$(peardir); then \
		$(MAKE) -s install-pear-installer install-pear-packages; \
	else \
		cat /home/lkq/php/pear/install-pear.txt; \
		exit 5; \
	fi


#
# Build environment install
#

phpincludedir = $(includedir)/php
phpbuilddir = $(prefix)/lib/php/build

BUILD_FILES = \
	scripts/phpize.m4 \
	build/mkdep.awk \
	build/scan_makefile_in.awk \
	build/libtool.m4 \
	Makefile.global \
	acinclude.m4 \
	ltmain.sh

BUILD_FILES_EXEC = \
	build/shtool \
	config.guess \
	config.sub

bin_SCRIPTS = phpize php-config
bin_src_SCRIPTS = phpextdist

install-build:
	@echo "Installing build environment:     $(INSTALL_ROOT)$(phpbuilddir)/"
	@$(mkinstalldirs) $(INSTALL_ROOT)$(phpbuilddir) $(INSTALL_ROOT)$(bindir) && \
	(cd $(top_srcdir) && \
	$(INSTALL) $(BUILD_FILES_EXEC) $(INSTALL_ROOT)$(phpbuilddir) && \
	$(INSTALL_DATA) $(BUILD_FILES) $(INSTALL_ROOT)$(phpbuilddir))

HEADER_DIRS = \
	/ \
	Zend \
	TSRM \
	ext/standard \
	ext/session \
	ext/xml \
	ext/xml/expat \
	main \
	ext/mbstring \
	ext/mbstring/libmbfl \
	ext/mbstring/libmbfl/mbfl \
	ext/pgsql \
	regex

install-headers:
	-@for i in $(HEADER_DIRS); do \
		paths="$$paths $(INSTALL_ROOT)$(phpincludedir)/$$i"; \
	done; \
	$(mkinstalldirs) $$paths && \
	echo "Installing header files:          $(INSTALL_ROOT)$(phpincludedir)/" && \
	for i in $(HEADER_DIRS); do \
		(cd $(top_srcdir)/$$i && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i; \
		cd $(top_builddir)/$$i && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i) 2>/dev/null || true; \
	done; \
	cd $(top_srcdir)/sapi/embed && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/main

install-programs: scripts/phpize scripts/php-config 
	@echo "Installing helper programs:       $(INSTALL_ROOT)$(bindir)/"
	@for prog in $(bin_SCRIPTS); do \
		echo "  program: $(program_prefix)$$prog$(program_suffix)"; \
		$(INSTALL) -m 755 scripts/$$prog $(INSTALL_ROOT)$(bindir)/$(program_prefix)$$prog$(program_suffix); \
	done
	@for prog in $(bin_src_SCRIPTS); do \
		echo "  program: $(program_prefix)$$prog$(program_suffix)"; \
		$(INSTALL) -m 755 $(top_srcdir)/scripts/$$prog $(INSTALL_ROOT)$(bindir)/$(program_prefix)$$prog$(program_suffix); \
	done

scripts/phpize: /home/lkq/php/scripts/phpize.in $(top_builddir)/config.status
	(CONFIG_FILES=$@ CONFIG_HEADERS= $(top_builddir)/config.status)

scripts/php-config: /home/lkq/php/scripts/php-config.in $(top_builddir)/config.status
	(CONFIG_FILES=$@ CONFIG_HEADERS= $(top_builddir)/config.status)

#
# Zend
#

Zend/zend_language_scanner.lo: Zend/zend_language_parser.h
Zend/zend_ini_scanner.lo: Zend/zend_ini_parser.h

Zend/zend_language_scanner.c: /home/lkq/php/Zend/zend_language_scanner.l
	$(LEX) -Pzend -S/home/lkq/php/Zend/flex.skl -o$@ -i /home/lkq/php/Zend/zend_language_scanner.l

Zend/zend_language_parser.h: Zend/zend_language_parser.c
Zend/zend_language_parser.c: /home/lkq/php/Zend/zend_language_parser.y
	$(YACC) -p zend -v -d /home/lkq/php/Zend/zend_language_parser.y -o $@

Zend/zend_ini_parser.h: Zend/zend_ini_parser.c
Zend/zend_ini_parser.c: /home/lkq/php/Zend/zend_ini_parser.y
	$(YACC) -p ini_ -v -d /home/lkq/php/Zend/zend_ini_parser.y -o $@

Zend/zend_ini_scanner.c: /home/lkq/php/Zend/zend_ini_scanner.l
	$(LEX) -Pini_ -S/home/lkq/php/Zend/flex.skl -o$@ -i /home/lkq/php/Zend/zend_ini_scanner.l

Zend/zend_indent.lo Zend/zend_highlight.lo Zend/zend_compile.lo: Zend/zend_language_parser.h
sapi/cgi/cgi_main.lo: /home/lkq/php/sapi/cgi/cgi_main.c
	$(CC)  -Isapi/cgi/ -I/home/lkq/php/sapi/cgi/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/sapi/cgi/cgi_main.c -o sapi/cgi/cgi_main.o  && echo > $@
sapi/cgi/getopt.lo: /home/lkq/php/sapi/cgi/getopt.c
	$(CC)  -Isapi/cgi/ -I/home/lkq/php/sapi/cgi/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/sapi/cgi/getopt.c -o sapi/cgi/getopt.o  && echo > $@
ext/ctype/ctype.lo: /home/lkq/php/ext/ctype/ctype.c
	$(CC)  -Iext/ctype/ -I/home/lkq/php/ext/ctype/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/ctype/ctype.c -o ext/ctype/ctype.o  && echo > $@
ext/mysql/php_mysql.lo: /home/lkq/php/ext/mysql/php_mysql.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/php_mysql.c -o ext/mysql/php_mysql.o  && echo > $@
ext/mysql/libmysql/libmysql.lo: /home/lkq/php/ext/mysql/libmysql/libmysql.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/libmysql.c -o ext/mysql/libmysql/libmysql.o  && echo > $@
ext/mysql/libmysql/errmsg.lo: /home/lkq/php/ext/mysql/libmysql/errmsg.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/errmsg.c -o ext/mysql/libmysql/errmsg.o  && echo > $@
ext/mysql/libmysql/net.lo: /home/lkq/php/ext/mysql/libmysql/net.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/net.c -o ext/mysql/libmysql/net.o  && echo > $@
ext/mysql/libmysql/violite.lo: /home/lkq/php/ext/mysql/libmysql/violite.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/violite.c -o ext/mysql/libmysql/violite.o  && echo > $@
ext/mysql/libmysql/password.lo: /home/lkq/php/ext/mysql/libmysql/password.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/password.c -o ext/mysql/libmysql/password.o  && echo > $@
ext/mysql/libmysql/my_init.lo: /home/lkq/php/ext/mysql/libmysql/my_init.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_init.c -o ext/mysql/libmysql/my_init.o  && echo > $@
ext/mysql/libmysql/my_lib.lo: /home/lkq/php/ext/mysql/libmysql/my_lib.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_lib.c -o ext/mysql/libmysql/my_lib.o  && echo > $@
ext/mysql/libmysql/my_static.lo: /home/lkq/php/ext/mysql/libmysql/my_static.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_static.c -o ext/mysql/libmysql/my_static.o  && echo > $@
ext/mysql/libmysql/my_malloc.lo: /home/lkq/php/ext/mysql/libmysql/my_malloc.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_malloc.c -o ext/mysql/libmysql/my_malloc.o  && echo > $@
ext/mysql/libmysql/my_realloc.lo: /home/lkq/php/ext/mysql/libmysql/my_realloc.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_realloc.c -o ext/mysql/libmysql/my_realloc.o  && echo > $@
ext/mysql/libmysql/my_create.lo: /home/lkq/php/ext/mysql/libmysql/my_create.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_create.c -o ext/mysql/libmysql/my_create.o  && echo > $@
ext/mysql/libmysql/my_delete.lo: /home/lkq/php/ext/mysql/libmysql/my_delete.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_delete.c -o ext/mysql/libmysql/my_delete.o  && echo > $@
ext/mysql/libmysql/my_tempnam.lo: /home/lkq/php/ext/mysql/libmysql/my_tempnam.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_tempnam.c -o ext/mysql/libmysql/my_tempnam.o  && echo > $@
ext/mysql/libmysql/my_open.lo: /home/lkq/php/ext/mysql/libmysql/my_open.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_open.c -o ext/mysql/libmysql/my_open.o  && echo > $@
ext/mysql/libmysql/mf_casecnv.lo: /home/lkq/php/ext/mysql/libmysql/mf_casecnv.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/mf_casecnv.c -o ext/mysql/libmysql/mf_casecnv.o  && echo > $@
ext/mysql/libmysql/my_read.lo: /home/lkq/php/ext/mysql/libmysql/my_read.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_read.c -o ext/mysql/libmysql/my_read.o  && echo > $@
ext/mysql/libmysql/my_write.lo: /home/lkq/php/ext/mysql/libmysql/my_write.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_write.c -o ext/mysql/libmysql/my_write.o  && echo > $@
ext/mysql/libmysql/errors.lo: /home/lkq/php/ext/mysql/libmysql/errors.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/errors.c -o ext/mysql/libmysql/errors.o  && echo > $@
ext/mysql/libmysql/my_error.lo: /home/lkq/php/ext/mysql/libmysql/my_error.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_error.c -o ext/mysql/libmysql/my_error.o  && echo > $@
ext/mysql/libmysql/my_getwd.lo: /home/lkq/php/ext/mysql/libmysql/my_getwd.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_getwd.c -o ext/mysql/libmysql/my_getwd.o  && echo > $@
ext/mysql/libmysql/my_div.lo: /home/lkq/php/ext/mysql/libmysql/my_div.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_div.c -o ext/mysql/libmysql/my_div.o  && echo > $@
ext/mysql/libmysql/mf_pack.lo: /home/lkq/php/ext/mysql/libmysql/mf_pack.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/mf_pack.c -o ext/mysql/libmysql/mf_pack.o  && echo > $@
ext/mysql/libmysql/my_messnc.lo: /home/lkq/php/ext/mysql/libmysql/my_messnc.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_messnc.c -o ext/mysql/libmysql/my_messnc.o  && echo > $@
ext/mysql/libmysql/mf_dirname.lo: /home/lkq/php/ext/mysql/libmysql/mf_dirname.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/mf_dirname.c -o ext/mysql/libmysql/mf_dirname.o  && echo > $@
ext/mysql/libmysql/mf_fn_ext.lo: /home/lkq/php/ext/mysql/libmysql/mf_fn_ext.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/mf_fn_ext.c -o ext/mysql/libmysql/mf_fn_ext.o  && echo > $@
ext/mysql/libmysql/mf_wcomp.lo: /home/lkq/php/ext/mysql/libmysql/mf_wcomp.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/mf_wcomp.c -o ext/mysql/libmysql/mf_wcomp.o  && echo > $@
ext/mysql/libmysql/typelib.lo: /home/lkq/php/ext/mysql/libmysql/typelib.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/typelib.c -o ext/mysql/libmysql/typelib.o  && echo > $@
ext/mysql/libmysql/safemalloc.lo: /home/lkq/php/ext/mysql/libmysql/safemalloc.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/safemalloc.c -o ext/mysql/libmysql/safemalloc.o  && echo > $@
ext/mysql/libmysql/my_alloc.lo: /home/lkq/php/ext/mysql/libmysql/my_alloc.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_alloc.c -o ext/mysql/libmysql/my_alloc.o  && echo > $@
ext/mysql/libmysql/mf_format.lo: /home/lkq/php/ext/mysql/libmysql/mf_format.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/mf_format.c -o ext/mysql/libmysql/mf_format.o  && echo > $@
ext/mysql/libmysql/mf_path.lo: /home/lkq/php/ext/mysql/libmysql/mf_path.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/mf_path.c -o ext/mysql/libmysql/mf_path.o  && echo > $@
ext/mysql/libmysql/mf_unixpath.lo: /home/lkq/php/ext/mysql/libmysql/mf_unixpath.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/mf_unixpath.c -o ext/mysql/libmysql/mf_unixpath.o  && echo > $@
ext/mysql/libmysql/my_fopen.lo: /home/lkq/php/ext/mysql/libmysql/my_fopen.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_fopen.c -o ext/mysql/libmysql/my_fopen.o  && echo > $@
ext/mysql/libmysql/mf_loadpath.lo: /home/lkq/php/ext/mysql/libmysql/mf_loadpath.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/mf_loadpath.c -o ext/mysql/libmysql/mf_loadpath.o  && echo > $@
ext/mysql/libmysql/my_pthread.lo: /home/lkq/php/ext/mysql/libmysql/my_pthread.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_pthread.c -o ext/mysql/libmysql/my_pthread.o  && echo > $@
ext/mysql/libmysql/my_thr_init.lo: /home/lkq/php/ext/mysql/libmysql/my_thr_init.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_thr_init.c -o ext/mysql/libmysql/my_thr_init.o  && echo > $@
ext/mysql/libmysql/thr_mutex.lo: /home/lkq/php/ext/mysql/libmysql/thr_mutex.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/thr_mutex.c -o ext/mysql/libmysql/thr_mutex.o  && echo > $@
ext/mysql/libmysql/mulalloc.lo: /home/lkq/php/ext/mysql/libmysql/mulalloc.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/mulalloc.c -o ext/mysql/libmysql/mulalloc.o  && echo > $@
ext/mysql/libmysql/string.lo: /home/lkq/php/ext/mysql/libmysql/string.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/string.c -o ext/mysql/libmysql/string.o  && echo > $@
ext/mysql/libmysql/default.lo: /home/lkq/php/ext/mysql/libmysql/default.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/default.c -o ext/mysql/libmysql/default.o  && echo > $@
ext/mysql/libmysql/my_compress.lo: /home/lkq/php/ext/mysql/libmysql/my_compress.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_compress.c -o ext/mysql/libmysql/my_compress.o  && echo > $@
ext/mysql/libmysql/array.lo: /home/lkq/php/ext/mysql/libmysql/array.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/array.c -o ext/mysql/libmysql/array.o  && echo > $@
ext/mysql/libmysql/my_once.lo: /home/lkq/php/ext/mysql/libmysql/my_once.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_once.c -o ext/mysql/libmysql/my_once.o  && echo > $@
ext/mysql/libmysql/list.lo: /home/lkq/php/ext/mysql/libmysql/list.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/list.c -o ext/mysql/libmysql/list.o  && echo > $@
ext/mysql/libmysql/my_net.lo: /home/lkq/php/ext/mysql/libmysql/my_net.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/my_net.c -o ext/mysql/libmysql/my_net.o  && echo > $@
ext/mysql/libmysql/dbug.lo: /home/lkq/php/ext/mysql/libmysql/dbug.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/dbug.c -o ext/mysql/libmysql/dbug.o  && echo > $@
ext/mysql/libmysql/strmov.lo: /home/lkq/php/ext/mysql/libmysql/strmov.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/strmov.c -o ext/mysql/libmysql/strmov.o  && echo > $@
ext/mysql/libmysql/strxmov.lo: /home/lkq/php/ext/mysql/libmysql/strxmov.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/strxmov.c -o ext/mysql/libmysql/strxmov.o  && echo > $@
ext/mysql/libmysql/strnmov.lo: /home/lkq/php/ext/mysql/libmysql/strnmov.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/strnmov.c -o ext/mysql/libmysql/strnmov.o  && echo > $@
ext/mysql/libmysql/strmake.lo: /home/lkq/php/ext/mysql/libmysql/strmake.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/strmake.c -o ext/mysql/libmysql/strmake.o  && echo > $@
ext/mysql/libmysql/strend.lo: /home/lkq/php/ext/mysql/libmysql/strend.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/strend.c -o ext/mysql/libmysql/strend.o  && echo > $@
ext/mysql/libmysql/strfill.lo: /home/lkq/php/ext/mysql/libmysql/strfill.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/strfill.c -o ext/mysql/libmysql/strfill.o  && echo > $@
ext/mysql/libmysql/is_prefix.lo: /home/lkq/php/ext/mysql/libmysql/is_prefix.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/is_prefix.c -o ext/mysql/libmysql/is_prefix.o  && echo > $@
ext/mysql/libmysql/int2str.lo: /home/lkq/php/ext/mysql/libmysql/int2str.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/int2str.c -o ext/mysql/libmysql/int2str.o  && echo > $@
ext/mysql/libmysql/str2int.lo: /home/lkq/php/ext/mysql/libmysql/str2int.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/str2int.c -o ext/mysql/libmysql/str2int.o  && echo > $@
ext/mysql/libmysql/strinstr.lo: /home/lkq/php/ext/mysql/libmysql/strinstr.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/strinstr.c -o ext/mysql/libmysql/strinstr.o  && echo > $@
ext/mysql/libmysql/strcont.lo: /home/lkq/php/ext/mysql/libmysql/strcont.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/strcont.c -o ext/mysql/libmysql/strcont.o  && echo > $@
ext/mysql/libmysql/strcend.lo: /home/lkq/php/ext/mysql/libmysql/strcend.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/strcend.c -o ext/mysql/libmysql/strcend.o  && echo > $@
ext/mysql/libmysql/bchange.lo: /home/lkq/php/ext/mysql/libmysql/bchange.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/bchange.c -o ext/mysql/libmysql/bchange.o  && echo > $@
ext/mysql/libmysql/bmove.lo: /home/lkq/php/ext/mysql/libmysql/bmove.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/bmove.c -o ext/mysql/libmysql/bmove.o  && echo > $@
ext/mysql/libmysql/bmove_upp.lo: /home/lkq/php/ext/mysql/libmysql/bmove_upp.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/bmove_upp.c -o ext/mysql/libmysql/bmove_upp.o  && echo > $@
ext/mysql/libmysql/longlong2str.lo: /home/lkq/php/ext/mysql/libmysql/longlong2str.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/longlong2str.c -o ext/mysql/libmysql/longlong2str.o  && echo > $@
ext/mysql/libmysql/strtoull.lo: /home/lkq/php/ext/mysql/libmysql/strtoull.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/strtoull.c -o ext/mysql/libmysql/strtoull.o  && echo > $@
ext/mysql/libmysql/strtoll.lo: /home/lkq/php/ext/mysql/libmysql/strtoll.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/strtoll.c -o ext/mysql/libmysql/strtoll.o  && echo > $@
ext/mysql/libmysql/charset.lo: /home/lkq/php/ext/mysql/libmysql/charset.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/charset.c -o ext/mysql/libmysql/charset.o  && echo > $@
ext/mysql/libmysql/ctype.lo: /home/lkq/php/ext/mysql/libmysql/ctype.c
	$(CC) -I/home/lkq/php/ext/mysql/libmysql -Iext/mysql/ -I/home/lkq/php/ext/mysql/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/mysql/libmysql/ctype.c -o ext/mysql/libmysql/ctype.o  && echo > $@
ext/overload/overload.lo: /home/lkq/php/ext/overload/overload.c
	$(CC)  -Iext/overload/ -I/home/lkq/php/ext/overload/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/overload/overload.c -o ext/overload/overload.o  && echo > $@
ext/pcre/pcrelib/maketables.lo: /home/lkq/php/ext/pcre/pcrelib/maketables.c
	$(CC) -DSUPPORT_UTF8 -DLINK_SIZE=2 -DPOSIX_MALLOC_THRESHOLD=10 -I/home/lkq/php/ext/pcre/pcrelib -Iext/pcre/ -I/home/lkq/php/ext/pcre/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/pcre/pcrelib/maketables.c -o ext/pcre/pcrelib/maketables.o  && echo > $@
ext/pcre/pcrelib/get.lo: /home/lkq/php/ext/pcre/pcrelib/get.c
	$(CC) -DSUPPORT_UTF8 -DLINK_SIZE=2 -DPOSIX_MALLOC_THRESHOLD=10 -I/home/lkq/php/ext/pcre/pcrelib -Iext/pcre/ -I/home/lkq/php/ext/pcre/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/pcre/pcrelib/get.c -o ext/pcre/pcrelib/get.o  && echo > $@
ext/pcre/pcrelib/study.lo: /home/lkq/php/ext/pcre/pcrelib/study.c
	$(CC) -DSUPPORT_UTF8 -DLINK_SIZE=2 -DPOSIX_MALLOC_THRESHOLD=10 -I/home/lkq/php/ext/pcre/pcrelib -Iext/pcre/ -I/home/lkq/php/ext/pcre/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/pcre/pcrelib/study.c -o ext/pcre/pcrelib/study.o  && echo > $@
ext/pcre/pcrelib/pcre.lo: /home/lkq/php/ext/pcre/pcrelib/pcre.c
	$(CC) -DSUPPORT_UTF8 -DLINK_SIZE=2 -DPOSIX_MALLOC_THRESHOLD=10 -I/home/lkq/php/ext/pcre/pcrelib -Iext/pcre/ -I/home/lkq/php/ext/pcre/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/pcre/pcrelib/pcre.c -o ext/pcre/pcrelib/pcre.o  && echo > $@
ext/pcre/php_pcre.lo: /home/lkq/php/ext/pcre/php_pcre.c
	$(CC) -DSUPPORT_UTF8 -DLINK_SIZE=2 -DPOSIX_MALLOC_THRESHOLD=10 -I/home/lkq/php/ext/pcre/pcrelib -Iext/pcre/ -I/home/lkq/php/ext/pcre/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/pcre/php_pcre.c -o ext/pcre/php_pcre.o  && echo > $@
ext/posix/posix.lo: /home/lkq/php/ext/posix/posix.c
	$(CC)  -Iext/posix/ -I/home/lkq/php/ext/posix/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/posix/posix.c -o ext/posix/posix.o  && echo > $@
ext/session/session.lo: /home/lkq/php/ext/session/session.c
	$(CC)  -Iext/session/ -I/home/lkq/php/ext/session/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/session/session.c -o ext/session/session.o  && echo > $@
ext/session/mod_files.lo: /home/lkq/php/ext/session/mod_files.c
	$(CC)  -Iext/session/ -I/home/lkq/php/ext/session/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/session/mod_files.c -o ext/session/mod_files.o  && echo > $@
ext/session/mod_mm.lo: /home/lkq/php/ext/session/mod_mm.c
	$(CC)  -Iext/session/ -I/home/lkq/php/ext/session/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/session/mod_mm.c -o ext/session/mod_mm.o  && echo > $@
ext/session/mod_user.lo: /home/lkq/php/ext/session/mod_user.c
	$(CC)  -Iext/session/ -I/home/lkq/php/ext/session/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/session/mod_user.c -o ext/session/mod_user.o  && echo > $@
regex/regcomp.lo: /home/lkq/php/regex/regcomp.c
	$(CC)  -Iregex/ -I/home/lkq/php/regex/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/regex/regcomp.c -o regex/regcomp.o  && echo > $@
regex/regexec.lo: /home/lkq/php/regex/regexec.c
	$(CC)  -Iregex/ -I/home/lkq/php/regex/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/regex/regexec.c -o regex/regexec.o  && echo > $@
regex/regerror.lo: /home/lkq/php/regex/regerror.c
	$(CC)  -Iregex/ -I/home/lkq/php/regex/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/regex/regerror.c -o regex/regerror.o  && echo > $@
regex/regfree.lo: /home/lkq/php/regex/regfree.c
	$(CC)  -Iregex/ -I/home/lkq/php/regex/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/regex/regfree.c -o regex/regfree.o  && echo > $@
ext/standard/array.lo: /home/lkq/php/ext/standard/array.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/array.c -o ext/standard/array.o  && echo > $@
ext/standard/base64.lo: /home/lkq/php/ext/standard/base64.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/base64.c -o ext/standard/base64.o  && echo > $@
ext/standard/basic_functions.lo: /home/lkq/php/ext/standard/basic_functions.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/basic_functions.c -o ext/standard/basic_functions.o  && echo > $@
ext/standard/browscap.lo: /home/lkq/php/ext/standard/browscap.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/browscap.c -o ext/standard/browscap.o  && echo > $@
ext/standard/crc32.lo: /home/lkq/php/ext/standard/crc32.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/crc32.c -o ext/standard/crc32.o  && echo > $@
ext/standard/crypt.lo: /home/lkq/php/ext/standard/crypt.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/crypt.c -o ext/standard/crypt.o  && echo > $@
ext/standard/cyr_convert.lo: /home/lkq/php/ext/standard/cyr_convert.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/cyr_convert.c -o ext/standard/cyr_convert.o  && echo > $@
ext/standard/datetime.lo: /home/lkq/php/ext/standard/datetime.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/datetime.c -o ext/standard/datetime.o  && echo > $@
ext/standard/dir.lo: /home/lkq/php/ext/standard/dir.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/dir.c -o ext/standard/dir.o  && echo > $@
ext/standard/dl.lo: /home/lkq/php/ext/standard/dl.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/dl.c -o ext/standard/dl.o  && echo > $@
ext/standard/dns.lo: /home/lkq/php/ext/standard/dns.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/dns.c -o ext/standard/dns.o  && echo > $@
ext/standard/exec.lo: /home/lkq/php/ext/standard/exec.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/exec.c -o ext/standard/exec.o  && echo > $@
ext/standard/file.lo: /home/lkq/php/ext/standard/file.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/file.c -o ext/standard/file.o  && echo > $@
ext/standard/filestat.lo: /home/lkq/php/ext/standard/filestat.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/filestat.c -o ext/standard/filestat.o  && echo > $@
ext/standard/flock_compat.lo: /home/lkq/php/ext/standard/flock_compat.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/flock_compat.c -o ext/standard/flock_compat.o  && echo > $@
ext/standard/formatted_print.lo: /home/lkq/php/ext/standard/formatted_print.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/formatted_print.c -o ext/standard/formatted_print.o  && echo > $@
ext/standard/fsock.lo: /home/lkq/php/ext/standard/fsock.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/fsock.c -o ext/standard/fsock.o  && echo > $@
ext/standard/head.lo: /home/lkq/php/ext/standard/head.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/head.c -o ext/standard/head.o  && echo > $@
ext/standard/html.lo: /home/lkq/php/ext/standard/html.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/html.c -o ext/standard/html.o  && echo > $@
ext/standard/image.lo: /home/lkq/php/ext/standard/image.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/image.c -o ext/standard/image.o  && echo > $@
ext/standard/info.lo: /home/lkq/php/ext/standard/info.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/info.c -o ext/standard/info.o  && echo > $@
ext/standard/iptc.lo: /home/lkq/php/ext/standard/iptc.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/iptc.c -o ext/standard/iptc.o  && echo > $@
ext/standard/lcg.lo: /home/lkq/php/ext/standard/lcg.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/lcg.c -o ext/standard/lcg.o  && echo > $@
ext/standard/link.lo: /home/lkq/php/ext/standard/link.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/link.c -o ext/standard/link.o  && echo > $@
ext/standard/mail.lo: /home/lkq/php/ext/standard/mail.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/mail.c -o ext/standard/mail.o  && echo > $@
ext/standard/math.lo: /home/lkq/php/ext/standard/math.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/math.c -o ext/standard/math.o  && echo > $@
ext/standard/md5.lo: /home/lkq/php/ext/standard/md5.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/md5.c -o ext/standard/md5.o  && echo > $@
ext/standard/metaphone.lo: /home/lkq/php/ext/standard/metaphone.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/metaphone.c -o ext/standard/metaphone.o  && echo > $@
ext/standard/microtime.lo: /home/lkq/php/ext/standard/microtime.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/microtime.c -o ext/standard/microtime.o  && echo > $@
ext/standard/pack.lo: /home/lkq/php/ext/standard/pack.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/pack.c -o ext/standard/pack.o  && echo > $@
ext/standard/pageinfo.lo: /home/lkq/php/ext/standard/pageinfo.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/pageinfo.c -o ext/standard/pageinfo.o  && echo > $@
ext/standard/parsedate.lo: /home/lkq/php/ext/standard/parsedate.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/parsedate.c -o ext/standard/parsedate.o  && echo > $@
ext/standard/quot_print.lo: /home/lkq/php/ext/standard/quot_print.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/quot_print.c -o ext/standard/quot_print.o  && echo > $@
ext/standard/rand.lo: /home/lkq/php/ext/standard/rand.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/rand.c -o ext/standard/rand.o  && echo > $@
ext/standard/reg.lo: /home/lkq/php/ext/standard/reg.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/reg.c -o ext/standard/reg.o  && echo > $@
ext/standard/soundex.lo: /home/lkq/php/ext/standard/soundex.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/soundex.c -o ext/standard/soundex.o  && echo > $@
ext/standard/string.lo: /home/lkq/php/ext/standard/string.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/string.c -o ext/standard/string.o  && echo > $@
ext/standard/scanf.lo: /home/lkq/php/ext/standard/scanf.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/scanf.c -o ext/standard/scanf.o  && echo > $@
ext/standard/syslog.lo: /home/lkq/php/ext/standard/syslog.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/syslog.c -o ext/standard/syslog.o  && echo > $@
ext/standard/type.lo: /home/lkq/php/ext/standard/type.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/type.c -o ext/standard/type.o  && echo > $@
ext/standard/uniqid.lo: /home/lkq/php/ext/standard/uniqid.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/uniqid.c -o ext/standard/uniqid.o  && echo > $@
ext/standard/url.lo: /home/lkq/php/ext/standard/url.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/url.c -o ext/standard/url.o  && echo > $@
ext/standard/url_scanner.lo: /home/lkq/php/ext/standard/url_scanner.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/url_scanner.c -o ext/standard/url_scanner.o  && echo > $@
ext/standard/var.lo: /home/lkq/php/ext/standard/var.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/var.c -o ext/standard/var.o  && echo > $@
ext/standard/versioning.lo: /home/lkq/php/ext/standard/versioning.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/versioning.c -o ext/standard/versioning.o  && echo > $@
ext/standard/assert.lo: /home/lkq/php/ext/standard/assert.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/assert.c -o ext/standard/assert.o  && echo > $@
ext/standard/strnatcmp.lo: /home/lkq/php/ext/standard/strnatcmp.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/strnatcmp.c -o ext/standard/strnatcmp.o  && echo > $@
ext/standard/levenshtein.lo: /home/lkq/php/ext/standard/levenshtein.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/levenshtein.c -o ext/standard/levenshtein.o  && echo > $@
ext/standard/incomplete_class.lo: /home/lkq/php/ext/standard/incomplete_class.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/incomplete_class.c -o ext/standard/incomplete_class.o  && echo > $@
ext/standard/url_scanner_ex.lo: /home/lkq/php/ext/standard/url_scanner_ex.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/url_scanner_ex.c -o ext/standard/url_scanner_ex.o  && echo > $@
ext/standard/ftp_fopen_wrapper.lo: /home/lkq/php/ext/standard/ftp_fopen_wrapper.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/ftp_fopen_wrapper.c -o ext/standard/ftp_fopen_wrapper.o  && echo > $@
ext/standard/http_fopen_wrapper.lo: /home/lkq/php/ext/standard/http_fopen_wrapper.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/http_fopen_wrapper.c -o ext/standard/http_fopen_wrapper.o  && echo > $@
ext/standard/php_fopen_wrapper.lo: /home/lkq/php/ext/standard/php_fopen_wrapper.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/php_fopen_wrapper.c -o ext/standard/php_fopen_wrapper.o  && echo > $@
ext/standard/credits.lo: /home/lkq/php/ext/standard/credits.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/credits.c -o ext/standard/credits.o  && echo > $@
ext/standard/css.lo: /home/lkq/php/ext/standard/css.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/css.c -o ext/standard/css.o  && echo > $@
ext/standard/var_unserializer.lo: /home/lkq/php/ext/standard/var_unserializer.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/var_unserializer.c -o ext/standard/var_unserializer.o  && echo > $@
ext/standard/ftok.lo: /home/lkq/php/ext/standard/ftok.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/ftok.c -o ext/standard/ftok.o  && echo > $@
ext/standard/aggregation.lo: /home/lkq/php/ext/standard/aggregation.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/aggregation.c -o ext/standard/aggregation.o  && echo > $@
ext/standard/sha1.lo: /home/lkq/php/ext/standard/sha1.c
	$(CC)  -Iext/standard/ -I/home/lkq/php/ext/standard/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/standard/sha1.c -o ext/standard/sha1.o  && echo > $@
ext/tokenizer/tokenizer.lo: /home/lkq/php/ext/tokenizer/tokenizer.c
	$(CC)  -Iext/tokenizer/ -I/home/lkq/php/ext/tokenizer/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/tokenizer/tokenizer.c -o ext/tokenizer/tokenizer.o  && echo > $@
ext/xml/xml.lo: /home/lkq/php/ext/xml/xml.c
	$(CC) -DBYTEORDER=1234 -Iext/xml/ -I/home/lkq/php/ext/xml/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/xml/xml.c -o ext/xml/xml.o  && echo > $@
ext/xml/expat/xmlparse.lo: /home/lkq/php/ext/xml/expat/xmlparse.c
	$(CC) -DBYTEORDER=1234 -Iext/xml/ -I/home/lkq/php/ext/xml/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/xml/expat/xmlparse.c -o ext/xml/expat/xmlparse.o  && echo > $@
ext/xml/expat/xmlrole.lo: /home/lkq/php/ext/xml/expat/xmlrole.c
	$(CC) -DBYTEORDER=1234 -Iext/xml/ -I/home/lkq/php/ext/xml/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/xml/expat/xmlrole.c -o ext/xml/expat/xmlrole.o  && echo > $@
ext/xml/expat/xmltok.lo: /home/lkq/php/ext/xml/expat/xmltok.c
	$(CC) -DBYTEORDER=1234 -Iext/xml/ -I/home/lkq/php/ext/xml/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/ext/xml/expat/xmltok.c -o ext/xml/expat/xmltok.o  && echo > $@
sapi/cli/php_cli.lo: /home/lkq/php/sapi/cli/php_cli.c
	$(CC)  -Isapi/cli/ -I/home/lkq/php/sapi/cli/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/sapi/cli/php_cli.c -o sapi/cli/php_cli.o  && echo > $@
sapi/cli/getopt.lo: /home/lkq/php/sapi/cli/getopt.c
	$(CC)  -Isapi/cli/ -I/home/lkq/php/sapi/cli/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/sapi/cli/getopt.c -o sapi/cli/getopt.o  && echo > $@
TSRM/TSRM.lo: /home/lkq/php/TSRM/TSRM.c
	$(CC)  -ITSRM/ -I/home/lkq/php/TSRM/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/TSRM/TSRM.c -o TSRM/TSRM.o  && echo > $@
TSRM/tsrm_strtok_r.lo: /home/lkq/php/TSRM/tsrm_strtok_r.c
	$(CC)  -ITSRM/ -I/home/lkq/php/TSRM/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/TSRM/tsrm_strtok_r.c -o TSRM/tsrm_strtok_r.o  && echo > $@
TSRM/tsrm_virtual_cwd.lo: /home/lkq/php/TSRM/tsrm_virtual_cwd.c
	$(CC)  -ITSRM/ -I/home/lkq/php/TSRM/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/TSRM/tsrm_virtual_cwd.c -o TSRM/tsrm_virtual_cwd.o  && echo > $@
main/main.lo: /home/lkq/php/main/main.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/main.c -o main/main.o  && echo > $@
main/snprintf.lo: /home/lkq/php/main/snprintf.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/snprintf.c -o main/snprintf.o  && echo > $@
main/spprintf.lo: /home/lkq/php/main/spprintf.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/spprintf.c -o main/spprintf.o  && echo > $@
main/php_sprintf.lo: /home/lkq/php/main/php_sprintf.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/php_sprintf.c -o main/php_sprintf.o  && echo > $@
main/safe_mode.lo: /home/lkq/php/main/safe_mode.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/safe_mode.c -o main/safe_mode.o  && echo > $@
main/fopen_wrappers.lo: /home/lkq/php/main/fopen_wrappers.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/fopen_wrappers.c -o main/fopen_wrappers.o  && echo > $@
main/alloca.lo: /home/lkq/php/main/alloca.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/alloca.c -o main/alloca.o  && echo > $@
main/php_scandir.lo: /home/lkq/php/main/php_scandir.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/php_scandir.c -o main/php_scandir.o  && echo > $@
main/php_ini.lo: /home/lkq/php/main/php_ini.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/php_ini.c -o main/php_ini.o  && echo > $@
main/SAPI.lo: /home/lkq/php/main/SAPI.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/SAPI.c -o main/SAPI.o  && echo > $@
main/rfc1867.lo: /home/lkq/php/main/rfc1867.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/rfc1867.c -o main/rfc1867.o  && echo > $@
main/php_content_types.lo: /home/lkq/php/main/php_content_types.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/php_content_types.c -o main/php_content_types.o  && echo > $@
main/strlcpy.lo: /home/lkq/php/main/strlcpy.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/strlcpy.c -o main/strlcpy.o  && echo > $@
main/strlcat.lo: /home/lkq/php/main/strlcat.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/strlcat.c -o main/strlcat.o  && echo > $@
main/mergesort.lo: /home/lkq/php/main/mergesort.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/mergesort.c -o main/mergesort.o  && echo > $@
main/reentrancy.lo: /home/lkq/php/main/reentrancy.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/reentrancy.c -o main/reentrancy.o  && echo > $@
main/php_variables.lo: /home/lkq/php/main/php_variables.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/php_variables.c -o main/php_variables.o  && echo > $@
main/php_ticks.lo: /home/lkq/php/main/php_ticks.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/php_ticks.c -o main/php_ticks.o  && echo > $@
main/streams.lo: /home/lkq/php/main/streams.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/streams.c -o main/streams.o  && echo > $@
main/network.lo: /home/lkq/php/main/network.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/network.c -o main/network.o  && echo > $@
main/php_open_temporary_file.lo: /home/lkq/php/main/php_open_temporary_file.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/php_open_temporary_file.c -o main/php_open_temporary_file.o  && echo > $@
main/php_logos.lo: /home/lkq/php/main/php_logos.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/php_logos.c -o main/php_logos.o  && echo > $@
main/output.lo: /home/lkq/php/main/output.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/output.c -o main/output.o  && echo > $@
main/memory_streams.lo: /home/lkq/php/main/memory_streams.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/memory_streams.c -o main/memory_streams.o  && echo > $@
main/user_streams.lo: /home/lkq/php/main/user_streams.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/main/user_streams.c -o main/user_streams.o  && echo > $@
main/internal_functions.lo: main/internal_functions.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c main/internal_functions.c -o main/internal_functions.o  && echo > $@
main/internal_functions_cli.lo: main/internal_functions_cli.c
	$(CC)  -Imain/ -I/home/lkq/php/main/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c main/internal_functions_cli.c -o main/internal_functions_cli.o  && echo > $@
Zend/zend_language_parser.lo: Zend/zend_language_parser.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c Zend/zend_language_parser.c -o Zend/zend_language_parser.o  && echo > $@
Zend/zend_language_scanner.lo: Zend/zend_language_scanner.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c Zend/zend_language_scanner.c -o Zend/zend_language_scanner.o  && echo > $@
Zend/zend_ini_parser.lo: Zend/zend_ini_parser.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c Zend/zend_ini_parser.c -o Zend/zend_ini_parser.o  && echo > $@
Zend/zend_ini_scanner.lo: Zend/zend_ini_scanner.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c Zend/zend_ini_scanner.c -o Zend/zend_ini_scanner.o  && echo > $@
Zend/zend_alloc.lo: /home/lkq/php/Zend/zend_alloc.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_alloc.c -o Zend/zend_alloc.o  && echo > $@
Zend/zend_compile.lo: /home/lkq/php/Zend/zend_compile.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_compile.c -o Zend/zend_compile.o  && echo > $@
Zend/zend_constants.lo: /home/lkq/php/Zend/zend_constants.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_constants.c -o Zend/zend_constants.o  && echo > $@
Zend/zend_dynamic_array.lo: /home/lkq/php/Zend/zend_dynamic_array.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_dynamic_array.c -o Zend/zend_dynamic_array.o  && echo > $@
Zend/zend_execute_API.lo: /home/lkq/php/Zend/zend_execute_API.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_execute_API.c -o Zend/zend_execute_API.o  && echo > $@
Zend/zend_highlight.lo: /home/lkq/php/Zend/zend_highlight.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_highlight.c -o Zend/zend_highlight.o  && echo > $@
Zend/zend_llist.lo: /home/lkq/php/Zend/zend_llist.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_llist.c -o Zend/zend_llist.o  && echo > $@
Zend/zend_opcode.lo: /home/lkq/php/Zend/zend_opcode.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_opcode.c -o Zend/zend_opcode.o  && echo > $@
Zend/zend_operators.lo: /home/lkq/php/Zend/zend_operators.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_operators.c -o Zend/zend_operators.o  && echo > $@
Zend/zend_ptr_stack.lo: /home/lkq/php/Zend/zend_ptr_stack.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_ptr_stack.c -o Zend/zend_ptr_stack.o  && echo > $@
Zend/zend_stack.lo: /home/lkq/php/Zend/zend_stack.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_stack.c -o Zend/zend_stack.o  && echo > $@
Zend/zend_variables.lo: /home/lkq/php/Zend/zend_variables.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_variables.c -o Zend/zend_variables.o  && echo > $@
Zend/zend.lo: /home/lkq/php/Zend/zend.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend.c -o Zend/zend.o  && echo > $@
Zend/zend_API.lo: /home/lkq/php/Zend/zend_API.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_API.c -o Zend/zend_API.o  && echo > $@
Zend/zend_extensions.lo: /home/lkq/php/Zend/zend_extensions.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_extensions.c -o Zend/zend_extensions.o  && echo > $@
Zend/zend_hash.lo: /home/lkq/php/Zend/zend_hash.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_hash.c -o Zend/zend_hash.o  && echo > $@
Zend/zend_list.lo: /home/lkq/php/Zend/zend_list.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_list.c -o Zend/zend_list.o  && echo > $@
Zend/zend_indent.lo: /home/lkq/php/Zend/zend_indent.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_indent.c -o Zend/zend_indent.o  && echo > $@
Zend/zend_builtin_functions.lo: /home/lkq/php/Zend/zend_builtin_functions.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_builtin_functions.c -o Zend/zend_builtin_functions.o  && echo > $@
Zend/zend_sprintf.lo: /home/lkq/php/Zend/zend_sprintf.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_sprintf.c -o Zend/zend_sprintf.o  && echo > $@
Zend/zend_ini.lo: /home/lkq/php/Zend/zend_ini.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_ini.c -o Zend/zend_ini.o  && echo > $@
Zend/zend_qsort.lo: /home/lkq/php/Zend/zend_qsort.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_qsort.c -o Zend/zend_qsort.o  && echo > $@
Zend/zend_multibyte.lo: /home/lkq/php/Zend/zend_multibyte.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_multibyte.c -o Zend/zend_multibyte.o  && echo > $@
Zend/zend_strtod.lo: /home/lkq/php/Zend/zend_strtod.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_strtod.c -o Zend/zend_strtod.o  && echo > $@
Zend/zend_execute.lo: /home/lkq/php/Zend/zend_execute.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/zend_execute.c -o Zend/zend_execute.o  && echo > $@
Zend/dezender/dezender.lo: /home/lkq/php/Zend/dezender/dezender.c
	$(CC)  -IZend/ -I/home/lkq/php/Zend/ $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) -c /home/lkq/php/Zend/dezender/dezender.c -o Zend/dezender/dezender.o  && echo > $@