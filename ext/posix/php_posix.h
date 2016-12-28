/* 
   +----------------------------------------------------------------------+
   | PHP Version 4                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2003 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.02 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available at through the world-wide-web at                           |
   | http://www.php.net/license/2_02.txt.                                 |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Kristian Koehntopp <kris@koehntopp.de>                       |
   +----------------------------------------------------------------------+
 */


/* $Id: php_posix.h,v 1.11.8.1 2002/12/31 16:35:13 sebastian Exp $ */

#ifndef PHP_POSIX_H
#define PHP_POSIX_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#if HAVE_POSIX
#ifndef DLEXPORT
#define DLEXPORT
#endif

extern zend_module_entry posix_module_entry;
#define posix_module_ptr &posix_module_entry

/* POSIX.1, 3.3 */
PHP_FUNCTION(posix_kill);

/* POSIX.1, 4.1 */
PHP_FUNCTION(posix_getpid);
PHP_FUNCTION(posix_getppid);

/* POSIX.1,  4.2 */
PHP_FUNCTION(posix_getuid);
PHP_FUNCTION(posix_getgid);
PHP_FUNCTION(posix_geteuid);
PHP_FUNCTION(posix_getegid);
PHP_FUNCTION(posix_setuid);
PHP_FUNCTION(posix_setgid);
#ifdef HAVE_SETEUID
PHP_FUNCTION(posix_seteuid);
#endif
#ifdef HAVE_SETEGID
PHP_FUNCTION(posix_setegid);
#endif
PHP_FUNCTION(posix_getgroups);
PHP_FUNCTION(posix_getlogin);

/* POSIX.1, 4.3 */
PHP_FUNCTION(posix_getpgrp);
#ifdef HAVE_SETSID
PHP_FUNCTION(posix_setsid);
#endif
PHP_FUNCTION(posix_setpgid);
/* Non-Posix functions which are common */
#ifdef HAVE_GETPGID
PHP_FUNCTION(posix_getpgid);
#endif
#ifdef HAVE_GETSID
PHP_FUNCTION(posix_getsid);
#endif

/* POSIX.1, 4.4 */
PHP_FUNCTION(posix_uname);
PHP_FUNCTION(posix_times);

/* POSIX.1, 4.5 */
#ifdef HAVE_CTERMID
PHP_FUNCTION(posix_ctermid);
#endif
PHP_FUNCTION(posix_ttyname);
PHP_FUNCTION(posix_isatty);

/* POSIX.1, 5.2 */
PHP_FUNCTION(posix_getcwd);

/* POSIX.1, 5.4 */
#ifdef HAVE_MKFIFO
PHP_FUNCTION(posix_mkfifo);
#endif

/* POSIX.1, 9.2 */
PHP_FUNCTION(posix_getgrnam);
PHP_FUNCTION(posix_getgrgid);
PHP_FUNCTION(posix_getpwnam);
PHP_FUNCTION(posix_getpwuid);

#ifdef HAVE_GETRLIMIT
PHP_FUNCTION(posix_getrlimit);
#endif

PHP_FUNCTION(posix_get_last_error);
PHP_FUNCTION(posix_strerror);

ZEND_BEGIN_MODULE_GLOBALS(posix)
	int last_error;
ZEND_END_MODULE_GLOBALS(posix)

#ifdef ZTS
# define POSIX_G(v) TSRMG(posix_globals_id, zend_posix_globals *, v)
#else
# define POSIX_G(v)	(posix_globals.v)
#endif

#else

#define posix_module_ptr NULL

#endif

#define phpext_posix_ptr posix_module_ptr

#endif /* PHP_POSIX_H */