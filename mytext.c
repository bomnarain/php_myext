/* mytext extension for PHP */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_mytext.h"

/* If you declare any globals in php_myext.h */
ZEND_DECLARE_MODULE_GLOBALS(mytext)

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE()  \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

static PHP_GINIT_FUNCTION(mytext)
{
#if defined(COMPILE_DL_BCMATH) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	mytext_globals->scale= 1;
}

/* "mytext_functions"에서 사용되는 확장 함수의 목록입니다. 목록은 PHP_FE_END 매크로에 의해 종료됩니다. */
/* {{{ mytext_functions[]
 */
static const zend_function_entry mytext_functions[] = {
	PHP_FE(mytext_test1, arginfo_mytext_test1)
	PHP_FE(mytext_test2, arginfo_mytext_test2)
	PHP_FE(mytext_scale, arginfo_mytext_scale)
	PHP_FE_END};
/* }}} */

/* {{{ mytext_module_entry
 */
zend_module_entry mytext_module_entry = {
	STANDARD_MODULE_HEADER,
	"mytext",							/* 확장 모듈 이름 */
	mytext_functions,					/* zend_function_entry */
	PHP_MINIT(mytext),					/* PHP_MINIT - 모듈 초기화시 처리 기능 사용시 at php startup */
	PHP_MSHUTDOWN(mytext),				/* PHP_MSHUTDOWN - 모듈 종료시 처리 기능 사용시 at php shutdown */
	PHP_RINIT(mytext),					/* PHP_RINIT - 초기화 at request start */
	PHP_RSHUTDOWN(mytext),				/* PHP_RSHUTDOWN - 종료 at request end */
	PHP_MINFO(mytext),					/* PHP_MINFO - 모듈 정보 */
	PHP_MYTEXT_VERSION,					/* Version */
	PHP_MODULE_GLOBALS(mytext),			/* Module globals */
	PHP_GINIT(mytext),					/* PHP_GINIT – 전역 초기와 */
	NULL								/* PHP_GSHUTDOWN – Globals shutdown */
	NULL,
	STANDARD_MODULE_PROPERTIES_EX	
	/* STANDARD_MODULE_PROPERTIES */
	};
/* }}} */

#ifdef COMPILE_DL_MYTEXT
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(mytext)
#endif

/* 전역변수 초기화 처리 */
static PHP_GINIT_FUNCTION(mytext)
{
#if defined(COMPILE_DL_BCMATH) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	mytext_globals->scale= 1;
}

/* {{{ PHP_RINIT_FUNCTION
PHP_RINIT_FUNCTION()은 각 요청 시작 시 호출될 콜백 함수를 정의합니다. 
우리의 경우 스레드 로컬 저장소 캐시만 초기화합니다. 
초기에 이 작업을 수행하는 것이 훨씬 더 좋습니다(MINIT 또는 GINIT 콜백).
 */
PHP_RINIT_FUNCTION(mytext)
{
#if defined(ZTS) && defined(COMPILE_DL_MYTEXT)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
PHP_MINFO_FUNCTION()은 확장모듈에 대한 정보출력
phpinfo() 함수에서 호출될 콜백 함수를 정의합니다.
 */
PHP_MINFO_FUNCTION(mytext)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "mytext support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MINIT_FUNCTION(mytext){
	/* INI 항목이 있는 경우 이 행의 주석 처리를 제거합니다.
    ZEND_INIT_MODULE_GLOBALS(mytext, php_mytext_init_globals, NULL);
    REGISTER_INI_ENTRIES();
    */
#if defined(ZTS) && defined(COMPILE_DL_MYEXT)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	REGISTER_LONG_CONSTANT("MYEXT_SCALE_FACTOR", 2,
		CONST_CS | CONST_PERSISTENT);
	return SUCCESS;
	/* 모듈 로드시 처리 기능 추가 */
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(mytext)
{
	/* INI 항목이 있는 경우 이 줄의 주석 처리를 제거합니다.
    UNREGISTER_INI_ENTRIES();
    */
	/* 모듈 종료시 처리 기능 추가 */
	return SUCCESS;
}
/* }}} */

/* 요청 시작 시 할 일이 없으면 제거 */
/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(qrencode)
{
	/* 모듈 요청 시작시 기능 추가 */
	return SUCCESS;
}
/* }}} */

/* 요청 종료 시 할 일이 없으면 제거 */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(mytext)
{
	/* 모듈 요청 종료시 기능 추가 */
	return SUCCESS;
}
/* }}} */

/* argument(전달인자)가 없는 함수 */
/* {{{ void mytext_test1()
 */
PHP_FUNCTION(mytext_test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "mytext");
}
/* }}} */

/* argument(전달인자)가 하나인 함수 */
/* {{{ string mytext_test2( [ string $var ] )
 */
PHP_FUNCTION(mytext_test2)
{
	char *var = "World";
	/* 문자열 *var 값의 길이 */
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;
	/* {{{ ZEND_PARSE_PARAMETERS_START(min_argument_count, max_argument_count)
	 */
	ZEND_PARSE_PARAMETERS_START(0, 1)
	/* Z_PARAM_OPTIONAL : 매개변수를 선택적 매개변수로 추가하려면 다음 매크로를 사용합니다. */
	Z_PARAM_OPTIONAL
	Z_PARAM_STRING(var, var_len)
	/* 사용 할 수 있는 매개변수 매크로
	Z_PARAM_ARRAY()
	Z_PARAM_ARRAY_OR_OBJECT()
	Z_PARAM_BOOL()
	Z_PARAM_CLASS()
	Z_PARAM_DOUBLE()
	Z_PARAM_FUNC()
	Z_PARAM_ARRAY_HT()
	Z_PARAM_ARRAY_OR_OBJECT_HT()
	Z_PARAM_LONG()
	Z_PARAM_STRICT_LONG()
	Z_PARAM_OBJECT()
	Z_PARAM_OBJECT_OF_CLASS()
	Z_PARAM_PATH()
	Z_PARAM_PATH_STR()
	Z_PARAM_RESOURCE()
	Z_PARAM_STRING()
	Z_PARAM_STR()
	Z_PARAM_ZVAL()
	Z_PARAM_VARIADIC()
	*/
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/

PHP_FUNCTION(mytext_scale)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_DOUBLE(x * MYEXT_GLOBAL(scale));
}

/* 함수의 인수에 대한 정보 */
/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_mytext_test1, 0)
ZEND_END_ARG_INFO()

/* 함수의 인수에 대한 정보, str인 단일 선택 인수값 전달 */
ZEND_BEGIN_ARG_INFO(arginfo_mytext_test2, 0)
ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

/* 함수의 인수에 대한 정보, str인 단일 선택 인수값 전달 */
ZEND_BEGIN_ARG_INFO(arginfo_mytext_scale, 0)
ZEND_ARG_INFO(0, x)
ZEND_END_ARG_INFO()
/* }}} */
