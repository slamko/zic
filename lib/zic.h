#ifndef ZIC_ZIC
#define ZIC_ZIC

#define GET_LABEL_MACRO(_A1, _A2, MACRO, ...) MACRO

#define GET_3ARG_MACRO(_A1, _A2, _A3, MACRO, ...) MACRO

#define GET_SINGLE_LABEL_MACRO(_A1, MACRO, ...) MACRO

#define ERROR_PREFIX "error"

#define ZIC_RES_VAR_NAME ZIC_res

#define ZIC_RESULT ZIC_RES_VAR_NAME

#define ZIC_CLEANUP_LABEL_NAME_LABEL_NAME ZIC_CLEANUP_LABEL_NAME

#ifndef MINI_ZIC
#define FULL_API
#endif

#define OK_CLEANUP() \
    ZIC_RES_VAR_NAME = OK; \
    goto cleanup; 

#define RET_OK() \
    return OK;

#define RET_OK_LABEL(LABEL) \
    ZIC_RES_VAR_NAME = OK; \
    goto LABEL;

#define ERROR_CLEANUP(ERR) \
    ZIC_RES_VAR_NAME = ERR; \
    goto ZIC_CLEANUP_LABEL_NAME;

#define ERROR_FINAL(ERR) \
    return ERR;

#define ERROR_LABEL(ERR, LABEL) \
    ZIC_RES_VAR_NAME = ERR; \
    goto LABEL;

#define ERROR(...) GET_LABEL_MACRO(__VA_ARGS__, ERROR_LABEL, ERROR_FINAL)(__VA_ARGS__)

#define FAIL_CLEANUP() \
    ZIC_RES_VAR_NAME = FAIL; \
    goto ZIC_CLEANUP_LABEL_NAME;

#define FAIL() \
    return FAIL;

#define FAIL_LABEL(LABEL) \
    ZIC_RES_VAR_NAME = FAIL; \
    goto LABEL;

#define ZIC_RETURN_RESULT() ZIC_CLEANUP_LABEL_NAME: return ZIC_RES_VAR_NAME;

#define ZIC_RESULT_INIT() result ZIC_RES_VAR_NAME;

#define CLEANUP(CLEAN) ZIC_CLEANUP_LABEL_NAME: CLEAN; return ZIC_RES_VAR_NAME;

typedef enum {
    OK = 0,
    FAIL = 1,
    ERR_LOCAL = 2,
    ERR_SYS = 3,
    ERR_USER = 4
} base_result;

typedef int result;


// ERROR FORMATTING

#define PRINT_ERR(...) fprintf(stderr, ##__VA_ARGS__);

#define FORMAT_ERR(...) \
    PRINT_ERR(ERROR_PREFIX ": ") \
    PRINT_ERR(__VA_ARGS__) \
    PRINT_ERR("\n") \

#define GEN_ERR_MSG(MSG) ZIC_error_msg_##MSG

#define ERR_MSG_NAME(MSG) GEN_ERR_MSG(MSG)

#if __STDC_VERSION__ >= 201112L

#define DEFINE_ERROR(ERR_NAME, NUM) \
    enum {                          \
        ERR_NAME = NUM              \
    };
#define DEFINE_ERROR_MSG(ERR_NAME, NUM, ERR_MSG) \
    enum { ERR_NAME = NUM };                     \
    const char *const ERR_MSG_NAME(ERR_NAME) = ERR_MSG;

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

#define DEFINE_ERROR(ERR_NAME, NUM) \
    enum ENUM_NAME(NUM) {           \
        ERR_NAME = NUM              \
    };                              \
    const char *const ERR_MSG_NAME(ERR_NAME) = ERR_MSG;

#endif

#define ERR_TO_STR(ERR) ERR_MSG_NAME(ERR)

#define IS_HANDLED(ERR) (ERR == FAIL || ERR == OK)

#define IS_UNHANDLED(ERR) (ERR != FAIL && ERR != OK)

#define IS_OK(EXP) (EXP == OK)

#define IS_ERROR(EXP) (EXP != OK)

#define ISNULL(PTR) (!PTR)

#define IS_NOTNULL(PTR) (PTR)

#define IS_ERR(ERR) == ERR


// TRY CATCH


#define TRY(EXP, CATCH_ST) \
    (ZIC_RES_VAR_NAME = (EXP)); \
    if (IS_ERROR(ZIC_RES_VAR_NAME)) { \
        CATCH_ST ; \
    }

#define UNREACHABLE PRINT_ERR("unreachable code")

#define CATCH(CATCH_ERR_NUM, CATCH_ST) \
    if (ZIC_RES_VAR_NAME == CATCH_ERR_NUM) { \
        CATCH_ST ;\
    }

#define CATCH_ERR(CATCH_ERR_NUM) \
    if (ZIC_RES_VAR_NAME == CATCH_ERR_NUM) { \
        FORMAT_ERR(ERR_TO_STR(CATCH_ERR_NUM)) \
    }

#define CATCH_SYS() \
    if (ZIC_RES_VAR_NAME == ERR_SYS) { \
        perror(ERROR_PREFIX); \
    }

#define CATCH_SYS_ERR(CATCH_ERR_NUM) \
    if (ZIC_RES_VAR_NAME == CATCH_ERR_NUM) { \
        perror(ERROR_PREFIX); \
    }

// HANDLE

#define HANDLE_CLEANUP(...) \
    FORMAT_ERR(__VA_ARGS__) \
    FAIL_CLEANUP();

#define HANDLE(...) \
    FORMAT_ERR(__VA_ARGS__) \
    FAIL()

#define HANDLE_ERR(ERR) \
    FORMAT_ERR(ERR_TO_STR(ERR)) \
    FAIL()

#define HANDLE_LABEL(LABEL, ...) \
    FORMAT_ERR(__VA_ARGS__) \
    FAIL_LABEL(LABEL);

#define HANDLE_SYS_CLEANUP() perror(ERROR_PREFIX); FAIL_CLEANUP();

#define HANDLE_SYS_FINAL() perror(ERROR_PREFIX); FAIL();

#define HANDLE_SYS_LABEL(LABEL) perror(ERROR_PREFIX); FAIL_LABEL(LABEL);

#define HANDLE_SYS(...) GET_LABEL_MACRO(__VA_ARGS__, HANDLE_SYS_LABEL, HANDLE_SYS_FINAL)(__VA_ARGS__)


// UNWRAP


#define UNWRAP_CLEANUP(EXP) { \
    int res = (EXP); \
    if (res < 0) { ERROR_CLEANUP(ERR_SYS); } \
    else if (res) { ERROR_CLEANUP(res); } }

#define UNWRAP_FINAL(EXP) { \
    int res = (EXP); \
    if (res < 0) { ERROR_FINAL(ERR_SYS); } \
    else if (res) { ERROR_FINAL(res); } }

#define UNWRAP_LABEL(EXP, LABEL) { \
    int res = (EXP); \
    if (res < 0) { ERROR_LABEL(ERR_SYS, LABEL); } \
    else if (res) { ERROR_LABEL(res, LABEL); } }

#define UNWRAP(...) GET_LABEL_MACRO(__VA_ARGS__, UNWRAP_LABEL, UNWRAP_FINAL)(__VA_ARGS__)

#define UNWRAP_SYS_CLEANUP(EXP) UNWRAP_CLEANUP(EXP)

#define UNWRAP_SYS(...) UNWRAP(__VA_ARGS__)

#define UNWRAP_ERR_CLEANUP(EXP, ERR) { \
    int res = (EXP); \
    if (res < 0) { ERROR_CLEANUP(ERR); } \
    else if (res) { ERROR_CLEANUP(res); } }

#define UNWRAP_ERR_FINAL(EXP, ERR) { \
    int res = (EXP); \
    if (res < 0) { ERROR_FINAL(ERR); } \
    else if (res) { ERROR_FINAL(res); } }

#define UNWRAP_ERR_LABEL(EXP, LABEL, ERR) { \
    int res = (EXP); \
    if (res < 0) { ERROR_LABEL(ERR, LABEL); } \
    else if (res) { ERROR_LABEL(ERR, LABEL); } }

#define UNWRAP_ERR(...) GET_LABEL_MACRO(__VA_ARGS__, UNWRAP_ERR_LABEL, UNWRAP_ERR_FINAL)(__VA_ARGS__)

#define UNWRAP_LOCAL_CLEANUP(EXP) UNWRAP_ERR_CLEANUP(EXP, ERR_LOCAL)

#define UNWRAP_LOCAL(...) UNWRAP_ERR(__VA_ARGS__, ERR_LOCAL)

#define UNWRAP_USER_CLEANUP(EXP) UNWRAP_ERR_CLEANUP(EXP, ERR_USER)

#define UNWRAP_USER(...) UNWRAP_ERR(__VA_ARGS__, ERR_USER)


// UNWRAP_NEG

#define UNWRAP_NEG_CLEANUP(EXP) { \
    int res = (EXP); \
    if (res < 0) { ERROR_CLEANUP(ERR_SYS); } }

#define UNWRAP_NEG_FINAL(EXP) { \
    int res = (EXP); \
    if (res < 0) { ERROR_FINAL(ERR_SYS); } }

#define UNWRAP_NEG_LABEL(EXP, LABEL) { \
    int res = (EXP); \
    if (res < 0) { ERROR_LABEL(ERR_SYS, LABEL); } }

#define UNWRAP_NEG(...) GET_LABEL_MACRO(__VA_ARGS__, UNWRAP_NEG_LABEL, UNWRAP_NEG_FINAL)(__VA_ARGS__)

#define UNWRAP_NSYS_CLEANUP(EXP) UWNRAP_NEG_CLEANUP(EXP) 

#define UNWRAP_NSYS(...) UNWRAP_NEG(__VA_ARGS__)

#define UNWRAP_NERR_CLEANUP(EXP, ERR) { \
    const int res = (EXP); \
    if (res < 0) { ERROR_CLEANUP(ERR) } 

#define UNWRAP_NERR_FINAL(EXP, ERR) { \
    const int res = (EXP); \
    if (res < 0) { ERROR_FINAL(ERR) } 

#define UNWRAP_NERR_LABEL(EXP, LABEL, ERR) { \
    const int res = (EXP); \
    if (res < 0) { ERROR_LABEL(ERR, LABEL) } 

#define UNWRAP_NERR(...) GET_LABEL_MACRO(__VA_ARGS__, UNWRAP_NERR_LABEL, UNWRAP_NERR_FINAL)(__VA_ARGS__)

#define UNWRAP_NLOCAL_CLEANUP(EXP) UNWRAP_NERR_CLEANUP(EXP, ERR_LOCAL)

#define UNWRAP_NLOCAL(...) UNWRAP_NERR(__VA_ARGS__, ERR_LOCAL)

#define UNWRAP_NUSER_CLEANUP(EXP) UNWRAP_NERR_CLEANUP(EXP, ERR_USER)

#define UNWRAP_NUSER(...) UNWRAP_NERR(__VA_ARGS__, ERR_USER)


// UNWRAP_PTR


#define UNWRAP_PTR_CLEANUP(EXP) {   \
    const void *res = (EXP);        \
    if (!res) { ERROR_CLEANUP(ERR_SYS) } }

#define UNWRAP_PTR_FINAL(EXP) {     \
    const void *res = (EXP);        \
    if (!res) { ERROR_FINAL(ERR_SYS) } }

#define UNWRAP_PTR_LABEL(EXP, LABEL) { \
    const void *res = (EXP); \
    if (!res) { ERROR_LABEL(ERR_SYS, LABEL) } }

#define UNWRAP_PTR(...) GET_LABEL_MACRO(__VA_ARGS__, UNWRAP_PTR_LABEL, UNWRAP_PTR_FINAL)(__VA_ARGS__)

#define UNWRAP_PTR_SYS_CLEANUP(EXP) UNWRAP_PTR_CLEANUP(EXP)

#define UNWRAP_PTR_SYS(EXP, ...) UNWRAP_PTR(EXP, __VA_ARGS__)

#define UNWRAP_PTR_ERR_CLEANUP(EXP, ERR) { \
    const void *res = (EXP); \
    if (!res) { ERROR_CLEANUP(ERR) } }

#define UNWRAP_PTR_ERR_FINAL(EXP, ERR) { \
    const void *res = (EXP); \
    if (!res) { ERROR_FINAL(ERR) } }

#define UNWRAP_PTR_ERR_LABEL(EXP, LABEL, ERR) { \
    const void *res = (EXP); \
    if (!res) { ERROR_LABEL(ERR, LABEL) } }

#define UNWRAP_PTR_ERR(...) GET_3ARG_MACRO(__VA_ARGS__, UNWRAP_PTR_ERR_LABEL, UNWRAP_PTR_ERR_FINAL)(__VA_ARGS__)

#define UNWRAP_PTR_LOCAL_CLEANUP(EXP) UNWRAP_PTR_ERR_CLEANUP(EXP, ERR_LOCAL)

#define UNWRAP_PTR_LOCAL(...) UNWRAP_PTR_ERR(__VA_ARGS__, ERR_LOCAL)

#define UNWRAP_PTR_USER_CLEANUP(EXP) UNWRAP_PTR_ERR_CLEANUP(EXP, ERR_USER)

#define UNWRAP_PTR_USER(...) UNWRAP_PTR_ERR(__VA_ARGS__, ERR_USER)


#ifdef FULL_API

#include "matchwith.h"

#include "ptrunwrap.h"

#include "defer.h"


#undef DEF
#undef END
#undef END_CLEAN

#define DEF { \
    ZIC_RESULT_INIT() \
    ZIC_PTR_UNWRAP_INIT()

#define END goto deferfinal;  \
    errexit:                  \
    exit: ;                   \
    RETURN_ZIC_RESULT()       \
}

#define END_CLEAN deferfinal: \
    errexit:                  \
    exit: ;                   \
    RETURN_ZIC_RESULT()       \
}

#else // FULL_API

#if !defined DEF && !defined END_CLEAN
#define DEF { ZIC_RESULT_INIT()
    
#define END_CLEAN }
#endif

#endif // FULL_API

#endif // ZIC_ZIC