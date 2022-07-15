/* mytext extension for PHP */

#ifndef PHP_MYTEXT_H
# define PHP_MYTEXT_H

extern zend_module_entry mytext_module_entry;
# define phpext_mytext_ptr &mytext_module_entry

#ifdef PHP_WIN32
#define PHP_MYEXT_API __declspec(dllexport)
#else
#define PHP_MYEXT_API
#endif

# define PHP_MYTEXT_VERSION "0.1.0"

/* mytext.c functions */
PHP_MINFO_FUNCTION(mytext);

/* MINIT : 모듈 초기화 추가 정보 처리가 필요한 경우. 아파치 프로세스가 생성되면서 모듈을 로드할 때 호출. */
PHP_MINIT_FUNCTION(mytext);

/* MSHUTDOWN : 모듈 종료시 추가 정보 처리가 필요한 경우. 아파치 프로세스가 종료되면서 모듈을 언로드할 때 호출. */
PHP_MSHUTDOWN_FUNCTION(mytext);

/* RINIT : Request 초기화. 페이지가 요청될 때마다 발생. 요청된 페이지에서 해당 모듈을 사용하지 않아도 호출됨. */
/* RSHUTDOWN : Request 종료. 페이지 요청이 끝날 때마다 발생. 요청된 페이지에서 해당 모듈을 사용하지 않아도 호출됨. */
PHP_RSHUTDOWN_FUNCTION(mytext);

PHP_FUNCTION(arginfo_mytext_test1);
PHP_FUNCTION(arginfo_mytext_test2);
PHP_FUNCTION(arginfo_mytext_scale);


/* BEGIN과 END 사이에 필요할 수 있는 전역 변수를 선언합니다. */
ZEND_BEGIN_MODULE_GLOBALS(mytext)
    /* long  global_value; */
    /* char *global_string; */
    zend_long scale;
ZEND_END_MODULE_GLOBALS(mytext)

ZEND_EXTERN_MODULE_GLOBALS(mytext)

/* 전역변수 정의 : 이름으로 가지고 오기 */
#define MYEXT_G(name) ZEND_MODULE_GLOBALS_ACCESSOR(mytext, name)


# if defined(ZTS) && defined(COMPILE_DL_MYTEXT)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_MYTEXT_H */
