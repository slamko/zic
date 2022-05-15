#ifndef ZIC_ZIC
#define ZIC_ZIC

#define GET_LABEL_MACRO(_A1, _A2, MACRO, ...) MACRO

#define ERROR_PREFIX "error"

#define ZIC_RES_VAR_NAME_VAR_NAME ZIC_res

#ifndef MINI_ZIC
#define FULL_API
#endif

#ifdef FULL_API

#define R_OK_CLEAN() \
    ZIC_RES_VAR_NAME = OK; \
    goto exit;

#define R_OK_FINAL() \
    ZIC_RES_VAR_NAME = OK; \
    goto deferfinal;

#define R_OK_LABEL(LABEL) \
    ZIC_RES_VAR_NAME = OK; \
    goto defer##LABEL;

#define RET_OK(...) GET_LABEL_MACRO(__VA_ARGS__, OK_LABEL, OK_FINAL)(__VA_ARGS__)

#define ERROR_CLEAN(ERR) \
    ZIC_RES_VAR_NAME = ERR; \
    goto exit;

#define ERROR_FINAL(ERR) \
    ZIC_RES_VAR_NAME = ERR; \
    goto deferfinal;

#define ERROR_LABEL(ERR, LABEL) \
    ZIC_RES_VAR_NAME = ERR; \
    goto defer##LABEL;

#define ERROR(...) GET_LABEL_MACRO(__VA_ARGS__, ERROR_LABEL, ERROR_FINAL)(__VA_ARGS__)

#define FAIL_CLEAN() \
    ZIC_RES_VAR_NAME = FAIL; \
    goto exit;

#define FAIL_FINAL() \
    ZIC_RES_VAR_NAME = FAIL; \
    goto deferfinal;

#define FAIL_LABEL(LABEL) \
    ZIC_RES_VAR_NAME = FAIL; \
    goto defer##LABEL;

#define FAIL(...) GET_LABEL_MACRO(__VA_ARGS__, FAIL_LABEL, FAIL_FINAL)(__VA_ARGS__)

#else
#define RET_OK() \
    return OK;

#define ERROR(ERR) \
    return ERR;

#define FAIL() \
    return FAIL; 

#endif


typedef enum {
    OK = 0,
    FAIL = 1,
    ERR_LOCAL = 2,
    ERR_SYS = 3,
    ERR_USER = 4
} base_result;

typedef int result;

#if __STDC_VERSION__ == 201112L

#define DEFINE_ERROR(ERR_NAME, NUM) \
    enum {                          \
        ERR_NAME = NUM              \
    };

#else

#if defined _MSC_VER
#define GEN_ENUM_NAME_LINE(COUNTER, NUM) zic_error_##COUNTER##_##NUM

#define GEN_ENUM_NAME(COUNTER, NUM) GEN_ENUM_NAME_LINE(LINE, NFILE, NUM)

#define ENUM_NAME(NUM) GEN_ENUM_NAME(__COUNTER__, NUM)
#else
#define GEN_ENUM_NAME_LINE(LINE, NFILE, NUM) zic_error_##LINE##_##NUM

#define GEN_ENUM_NAME(LINE, NFILE, NUM) GEN_ENUM_NAME_LINE(LINE, NFILE, NUM)

#define ENUM_NAME(NUM) GEN_ENUM_NAME(__LINE__, __FILE__, NUM)
#endif

#define DEFINE_ERROR(ERR_NAME, NUM) \
    enum ENUM_NAME(NUM) { \
        ERR_NAME = NUM \
    };

#endif

#ifdef FULL_API

#define DEF { \
    result ZIC_RES_VAR_NAME = OK; \
    void *ZIC_unwrap_ptr_res = NULL;

#define END goto deferfinal;  \
    errexit:                  \
    exit: ;                   \
    return ZIC_RES_VAR_NAME;  \
}

#define END_CLEAN deferfinal: \
    errexit:                  \
    exit: ;                   \
    return ZIC_RES_VAR_NAME;  \
}

#else
#define DEF {
    
#define END }
#endif

#define IS_HANDLED(ERR) (ERR == FAIL || ERR == OK)

#define IS_UNHANDLED(ERR) (ERR != FAIL && ERR != OK)

#define IS_OK(EXP) (EXP == OK)

#define IS_ERROR(EXP) (EXP != OK)

#define ISNULL(PTR) !PTR

#define IS_NOTNULL(PTR) PTR

#define ZIC_BASE_CATCH(ERR, ...) \
    fprintf(stderr, ERROR_PREFIX); \
    fprintf(stderr, ERR, ##__VA_ARGS__); \
    fprintf(stderr, "\n");

#ifdef FULL_API

#define CATCH_CLEAN(ERR, ...) \
    ZIC_BASE_CATCH(ERR, __VA_ARGS__) \
    FAIL_CLEAN();

#define CATCH_FINAL(ERR, ...) \
    ZIC_BASE_CATCH(ERR, __VA_ARGS__) \
    FAIL();

#define CATCH_LABEL(ERR, LABEL, ...) \
    ZIC_BASE_CATCH(ERR, __VA_ARGS__) \
    FAIL_LABEL(LABEL);

#define CATCH(...) GET_LABEL_MACRO(__VA_ARGS__, CATCH_LABEL, CATCH_FINAL)(__VA_ARGS__)

#define CATCH_SYS_CLEAN() perror(ERROR_PREFIX); FAIL();

#define CATCH_SYS_FINAL() perror(ERROR_PREFIX); FAIL();

#define CATCH_SYS_LABEL(LABEL) perror(ERROR_PREFIX); FAIL_CLEAN(LABEL);

#define CATCH_SYS(...) GET_LABEL_MACRO(__VA_ARGS__, CATCH_SYS_LABEL, CATCH_SYS_FINAL)(__VA_ARGS__)

#else

#define CATCH(ERR, ...) \
    fprintf(stderr, ERROR_PREFIX); \
    fprintf(stderr, ERR, ##__VA_ARGS__); \
    fprintf(stderr, "\n"); \
    FAIL();

#define CATCH_SYS() perror(ERROR_PREFIX); FAIL();
#endif

#ifdef FULL_API
#define UNWRAP_CLEAN(EXP) { \
    int res = (EXP); \
    if (res < 0) { ERROR_CLEAN(ERR_SYS); } \
    else if (res) { ERROR_CLEAN(res); } }

#define UNWRAP_ERR_CLEAN(EXP, ERR) { \
    const int res = (EXP); \
    if (res < 0) ERROR_CLEAN(ERR) \
    else if (res) ERROR_CLEAN(res) }

#define UNWRAP_SYS_CLEAN(EXP) UNWRAP_CLEAN(EXP)

#define UNWRAP_LOCAL_CLEAN(EXP) UNWRAP_ERR_CLEAN(EXP, ERR_LOCAL)

#define UNWRAP_USER_CLEAN(EXP) UNWRAP_ERR_CLEAN(EXP, ERR_USER)

#endif

#define UNWRAP_FINAL(EXP) { \
    int res = (EXP); \
    if (res < 0) { ERROR(ERR_SYS); } \
    else if (res) { ERROR(res); } }

#define UNWRAP_LABEL(EXP, LABEL) { \
    int res = (EXP); \
    if (res < 0) { ERROR(ERR_SYS, LABEL); } \
    else if (res) { ERROR(res, LABEL); } }

#define UNWRAP(...) GET_LABEL_MACRO(__VA_ARGS__, UNWRAP_LABEL, UNWRAP_FINAL)(__VA_ARGS__)

#define UNWRAP_SYS(...) UNWRAP(__VA_ARGS__)

#define UNWRAP_ERR_FINAL(EXP, ERR) { \
    int res = (EXP); \
    if (res < 0) { ERROR(ERR); } \
    else if (res) { ERROR(res); } }

#define UNWRAP_ERR_LABEL(EXP, LABEL, ERR) { \
    int res = (EXP); \
    if (res < 0) { ERROR_LABEL(ERR, LABEL); } \
    else if (res) { ERROR_LABEL(ERR, LABEL); } }

#define UNWRAP_ERR(...) GET_LABEL_MACRO(__VA_ARGS__, UNWRAP_ERR_LABEL, UNWRAP_ERR_FINAL)(__VA_ARGS__)

#define UNWRAP_LOCAL(...) UNWRAP_ERR(__VA_ARGS__, ERR_LOCAL)

#define UNWRAP_USER(...) UNWRAP_ERR(__VA_ARGS__, ERR_USER)

#ifdef FULL_API
#define UNWRAP_NEG_CLEAN(EXP) { \
    int res = (EXP); \
    if (res < 0) ERROR_CLEAN(ERR_SYS); }

#define UNWRAP_NSYS_CLEAN(EXP) UNWRAP_NEG_CLEAN(EXP)

#endif

#define UNWRAP_NEG_FINAL(EXP) { \
    int res = (EXP); \
    if (res < 0) { ERROR(ERR_SYS); } }

#define UNWRAP_NEG_LABEL(EXP, LABEL) { \
    int res = (EXP); \
    if (res < 0) { ERROR(ERR_SYS, LABEL); } }

#define UNWRAP_NEG(...) GET_LABEL_MACRO(__VA_ARGS__, UNWRAP_NEG_LABEL, UNWRAP_NEG_FINAL)(__VA_ARGS__)

#define UNWRAP_NSYS(...) UNWRAP_NEG(__VA_ARGS__)

#ifdef FULL_API
#define UNWRAP_NERR_CLEAN(EXP, ERR) { \
    const int res = (EXP); \
    if (res < 0) { ERROR_CLEAN(ERR) } 

#define UNWRAP_NLOCAL_CLEAN(EXP) UNWRAP_NERR_CLEAN(EXP, ERR_LOCAL) 

#define UNWRAP_NUSER_CLEAN(EXP) UNWRAP_NERR_CLEAN(EXP, ERR_USER) 
#endif

#define UNWRAP_NERR_FINAL(EXP, ERR) { \
    const int res = (EXP); \
    if (res < 0) { ERROR(ERR) } 

#define UNWRAP_NERR_LABEL(EXP, LABEL, ERR) { \
    const int res = (EXP); \
    if (res < 0) { ERROR_LABEL(ERR, LABEL) } 

#define UNWRAP_NERR(...) GET_LABEL_MACRO(__VA_ARGS__, UNWRAP_NERR_LABEL, UNWRAP_NERR_FINAL)(__VA_ARGS__)

#define UNWRAP_NLOCAL(...) UNWRAP_NERR(__VA_ARGS__, ERR_LOCAL)

#define UNWRAP_NUSER(...) UNWRAP_NERR(__VA_ARGS__, ERR_USER)

#ifdef FULL_API
#define UNWRAP_PTR_CLEAN(EXP) { \
    const void *res = (EXP); \
    if (!res) { ERROR_CLEAN(ERR_SYS) } }

#define UNWRAP_PTR_SYS_CLEAN(EXP) UNWRAP_PTR_CLEAN(EXP)

#endif

#define UNWRAP_PTR_FINAL(EXP) { \
    const void *res = (EXP); \
    if (!res) { ERROR(ERR_SYS) } }

#define UNWRAP_PTR_LABEL(EXP, LABEL) { \
    const void *res = (EXP); \
    if (!res) { ERROR(ERR_SYS, defer##LABEL) } }

#define UNWRAP_PTR(...) GET_LABEL_MACRO(__VA_ARGS__, UNWRAP_PTR_LABEL, UNWRAP_PTR_FINAL)(__VA_ARGS__)

#define UNWRAP_PTR_SYS(EXP, ...) UNWRAP_PTR(EXP, __VA_ARGS__)

#ifdef FULL_API
#define UNWRAP_PTR_ERR_CLEAN(EXP, ERR) { \
    const void *res = (EXP); \
    if (!res) { ERROR_CLEAN(ERR) } }

#define UNWRAP_PTR_LOCAL_CLEAN(EXP) UNWRAP_PTR_ERR_CLEAN(EXP, ERR_LOCAL)

#define UNWRAP_PTR_USER_CLEAN(EXP) UNWRAP_PTR_ERR_CLEAN(EXP, ERR_USER)
#endif

#define UNWRAP_PTR_ERR_FINAL(EXP, ERR) { \
    const void *res = (EXP); \
    if (!res) { ERROR(ERR) } }

#define UNWRAP_PTR_ERR_LABEL(EXP, LABEL, ERR) { \
    const void *res = (EXP); \
    if (!res) { ERROR_LABEL(ERR, LABEL) } }

#define UNWRAP_PTR_ERR(...) GET_LABEL_MACRO(__VA_ARGS__, UNWRAP_PTR_ERR_LABEL, UNWRAP_PTR_ERR_FINAL)

#define UNWRAP_PTR_LOCAL(...) UNWRAP_PTR_ERR(__VA_ARGS__, ERR_LOCAL)

#define UNWRAP_PTR_USER(...) UNWRAP_PTR_ERR(__VA_ARGS__, ERR_USER)

#ifdef FULL_API

#include "ptrunwrap.h"

#include "matchwith.h"

#include "defer.h"

#endif

#endif