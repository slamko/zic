#ifndef ZIC_ZIC
#define ZIC_ZIC

#if defined(_MSVC_TRADITIONAL) && _MSVC_TRADITIONAL
#warning Some macro wrappers may not be available for MSVC. Specify /Zc:preprocessor option to enable full macro-feature set
#elif defined __GNUC__ && !defined MINI_ZIC
#undef ZIC_ENABLE_LABEL_OVERLOADING
#define ZIC_ENABLE_LABEL_OVERLOADING
#endif

#define GET_LABEL_MACRO(_A1, _A2, MACRO, ...) MACRO

#define GET_3ARG_MACRO(_A1, _A2, _A3, MACRO, ...) MACRO

#define GET_SINGLE_LABEL_MACRO(_A1, MACRO, ...) MACRO

#define ERROR_PREFIX "error"

#define ZIC_RES_VAR_NAME ZIC_res

#define ZIC_RESULT ZIC_RES_VAR_NAME

#define ZIC_CLEANUP_LABEL_NAME ZIC_cleanup

#ifndef MINI_ZIC
#define FULL_API
#endif

#define RET_OK_CLEANUP() {                     \
    ZIC_RES_VAR_NAME = OK;                     \
    goto ZIC_CLEANUP_LABEL_NAME; }

#define RET_OK() \
    return OK;

#define RET_OK_LABEL(LABEL) {                  \
    ZIC_RES_VAR_NAME = OK;                     \
    goto LABEL; }

#define ERROR_CLEANUP(ERR) {                   \
    ZIC_RES_VAR_NAME = ERR;                    \
    goto ZIC_CLEANUP_GOTO_NAME; }

#define ERROR_FINAL(ERR) \
    return ERR;

#define ERROR_GOTO(ERR, GOTO) {              \
    ZIC_RES_VAR_NAME = ERR;                    \
    goto GOTO; }

#ifdef ZIC_ENABLE_GOTO_OVERLOADING
#define ERROR(...) GET_GOTO_MACRO(__VA_ARGS__, ERROR_GOTO, ERROR_FINAL)(__VA_ARGS__)
#else
#define ERROR(ERR) ERROR_FINAL(ERR)
#endif

#define FAIL_CLEANUP() {    \
    ZIC_RES_VAR_NAME = FAIL; \
    goto ZIC_CLEANUP_GOTO_NAME; }

#define FAIL() \
    return FAIL;

#define FAIL_GOTO(GOTO) { \
    ZIC_RES_VAR_NAME = FAIL; \
    goto GOTO; }

#define ZIC_RETURN_RESULT() return ZIC_RES_VAR_NAME;

#define ZIC_RESULT_INIT() result ZIC_RES_VAR_NAME = 0;

#define CLEANUP(CLEAN) ZIC_CLEANUP_GOTO_NAME: CLEAN; return ZIC_RES_VAR_NAME;

#define CLEANUP_OK(CLEAN) ZIC_CLEANUP_GOTO_NAME: CLEAN; return OK;

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

#define RES_IS_OK() (ZIC_RESULT_VAR_NAME == OK)

#define RES_IS_ERROR() (ZIC_RESULT_VAR_NAME != OK)

#define RES_IS_ERR(ERR) (ZIC_RESULT_VAR_NAME == ERR)
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

#define THROW() UNWRAP_FINAL(ZIC_RES_VAR_NAME)

#define THROW_GOTO(LABEL) UNWRAP_GOTO(ZIC_RES_VAR_NAME, LABEL)
// HANDLE

#define HANDLE_NO_FORMAT(HANDLE_STR) \
    fprinf(stderr, HANDLE_STR); \
    FAIL()

#define HANDLE_CLEANUP(...) \
    FORMAT_ERR(__VA_ARGS__) \
    FAIL_CLEANUP();

#define HANDLE(...) \
    FORMAT_ERR(__VA_ARGS__) \
    FAIL()

#define HANDLE_ERR(ERR) \
    FORMAT_ERR(ERR_TO_STR(ERR)) \
    FAIL()

#define HANDLE_GOTO(GOTO, ...) \
    FORMAT_ERR(__VA_ARGS__) \
    FAIL_GOTO(GOTO);

#define HANDLE_SYS_CLEANUP() perror(ERROR_PREFIX); FAIL_CLEANUP();

#define HANDLE_SYS_FINAL() perror(ERROR_PREFIX); FAIL();

#define HANDLE_SYS_GOTO(GOTO) perror(ERROR_PREFIX); FAIL_GOTO(GOTO);

#define HANDLE_SYS() HANDLE_SYS_FINAL()

// UNWRAP


#define UNWRAP_CLEANUP(EXP) { \
    int res = (EXP); \
    if (res < 0) { ERROR_CLEANUP(ERR_SYS); } \
    else if (res) { ERROR_CLEANUP(res); } }

#define UNWRAP_FINAL(EXP) { \
    int res = (EXP); \
    if (res < 0) { ERROR_FINAL(ERR_SYS); } \
    else if (res) { ERROR_FINAL(res); } }

#define UNWRAP_GOTO(EXP, GOTO) { \
    int res = (EXP); \
    if (res < 0) { ERROR_GOTO(ERR_SYS, GOTO); } \
    else if (res) { ERROR_GOTO(res, GOTO); } }

#define UNWRAP_SYS_CLEANUP(EXP) UNWRAP_CLEANUP(EXP)

#define UNWRAP_ERR_CLEANUP(EXP, ERR) { \
    int res = (EXP); \
    if (res < 0) { ERROR_CLEANUP(ERR); } \
    else if (res) { ERROR_CLEANUP(res); } }

#define UNWRAP_ERR_FINAL(EXP, ERR) { \
    int res = (EXP); \
    if (res < 0) { ERROR_FINAL(ERR); } \
    else if (res) { ERROR_FINAL(res); } }

#define UNWRAP_ERR_GOTO(EXP, GOTO, ERR) { \
    int res = (EXP); \
    if (res < 0) { ERROR_GOTO(ERR, GOTO); } \
    else if (res) { ERROR_GOTO(ERR, GOTO); } }

#define UNWRAP_LOCAL_CLEANUP(EXP) UNWRAP_ERR_CLEANUP(EXP, ERR_LOCAL)

#define UNWRAP_USER_CLEANUP(EXP) UNWRAP_ERR_CLEANUP(EXP, ERR_USER)

#define UNWRAP_ERR(EXP, ERR) UNWRAP_ERR_FINAL(EXP, ERR)

#define UNWRAP(EXP) UNWRAP_FINAL(EXP)

#define UNWRAP_SYS(EXP) UNWRAP_FINAL(EXP)

#define UNWRAP_LOCAL(EXP) UNWRAP_ERR_FINAL(EXP, ERR_LOCAL)

#define UNWRAP_USER(EXP) UNWRAP_ERR_FINAL(EXP, ERR_USER)


// RESULT UNWRAP


#define RES_UNWRAP_CLEANUP(EXP) { \
    ZIC_RES_VAR_NAME = (EXP); \
    if (ZIC_RES_VAR_NAME < 0) { ERROR_CLEANUP(ERR_SYS); } \
    else if (ZIC_RES_VAR_NAME) { ERROR_CLEANUP(ZIC_RES_VAR_NAME); } }

#define RES_UNWRAP_FINAL(EXP) { \
    ZIC_RES_VAR_NAME = (EXP); \
    if (ZIC_RES_VAR_NAME < 0) { ERROR_FINAL(ERR_SYS); } \
    else if (ZIC_RES_VAR_NAME) { ERROR_FINAL(ZIC_RES_VAR_NAME); } }

#define RES_UNWRAP_GOTO(EXP, GOTO) { \
    ZIC_RES_VAR_NAME = (EXP); \
    if (ZIC_RES_VAR_NAME < 0) { ERROR_GOTO(ERR_SYS, GOTO); } \
    else if (ZIC_RES_VAR_NAME) { ERROR_GOTO(ZIC_RES_VAR_NAME, GOTO); } }

#define RES_UNWRAP_SYS_CLEANUP(EXP) RES_UNWRAP_CLEANUP(EXP)

#define RES_UNWRAP_ERR_CLEANUP(EXP, ERR) { \
    ZIC_RES_VAR_NAME = (EXP); \
    if (ZIC_RES_VAR_NAME < 0) { ERROR_CLEANUP(ERR); } \
    else if (ZIC_RES_VAR_NAME) { ERROR_CLEANUP(ZIC_RES_VAR_NAME); } }

#define RES_UNWRAP_ERR_FINAL(EXP, ERR) { \
    ZIC_RES_VAR_NAME = (EXP); \
    if (ZIC_RES_VAR_NAME < 0) { ERROR_FINAL(ERR); } \
    else if (ZIC_RES_VAR_NAME) { ERROR_FINAL(ZIC_RES_VAR_NAME); } }

#define RES_UNWRAP_ERR_GOTO(EXP, GOTO, ERR) { \
    ZIC_RES_VAR_NAME = (EXP); \
    if (ZIC_RES_VAR_NAME < 0) { ERROR_GOTO(ERR, GOTO); } \
    else if (ZIC_RES_VAR_NAME) { ERROR_GOTO(ERR, GOTO); } }

#define RES_UNWRAP_LOCAL_CLEANUP(EXP) RES_UNWRAP_ERR_CLEANUP(EXP, ERR_LOCAL)

#define RES_UNWRAP_USER_CLEANUP(EXP) RES_UNWRAP_ERR_CLEANUP(EXP, ERR_USER)

#define RES_UNWRAP_ERR(EXP, ERR) RES_UNWRAP_ERR_FINAL(EXP, ERR)

#define RES_UNWRAP(EXP) RES_UNWRAP_FINAL(EXP)

#define RES_UNWRAP_SYS(EXP) RES_UNWRAP_FINAL(EXP)

#define RES_UNWRAP_LOCAL(EXP) RES_UNWRAP_ERR_FINAL(EXP, ERR_LOCAL)

#define RES_UNWRAP_USER(EXP) RES_UNWRAP_ERR_FINAL(EXP, ERR_USER)


// UNWRAP_NEG

#define UNWRAP_NEG_CLEANUP(EXP) { \
    int res = (EXP); \
    if (res < 0) { ERROR_CLEANUP(ERR_SYS); } }

#define UNWRAP_NEG_FINAL(EXP) { \
    int res = (EXP); \
    if (res < 0) { ERROR_FINAL(ERR_SYS); } }

#define UNWRAP_NEG_GOTO(EXP, GOTO) { \
    int res = (EXP); \
    if (res < 0) { ERROR_GOTO(ERR_SYS, GOTO); } }

#define UNWRAP_NSYS_CLEANUP(EXP) UWNRAP_NEG_CLEANUP(EXP) 

#define UNWRAP_NERR_CLEANUP(EXP, ERR) { \
    const int res = (EXP); \
    if (res < 0) { ERROR_CLEANUP(ERR) } 

#define UNWRAP_NERR_FINAL(EXP, ERR) { \
    const int res = (EXP); \
    if (res < 0) { ERROR_FINAL(ERR) } 

#define UNWRAP_NERR_GOTO(EXP, GOTO, ERR) { \
    const int res = (EXP); \
    if (res < 0) { ERROR_GOTO(ERR, GOTO) } 

#define UNWRAP_NLOCAL_CLEANUP(EXP) UNWRAP_NERR_CLEANUP(EXP, ERR_LOCAL)

#define UNWRAP_NUSER_CLEANUP(EXP) UNWRAP_NERR_CLEANUP(EXP, ERR_USER)

#define UNWRAP_NERR(EXP, ERR) UNWRAP_NERR_FINAL(EXP, ERR)

#define UNWRAP_NEG(EXP) UNWRAP_NEG_FINAL(EXP)

#define UNWRAP_NSYS(EXP) UNWRAP_NEG_FINAL(EXP)

#define UNWRAP_NLOCAL(EXP) UNWRAP_NERR_FINAL(EXP, ERR_LOCAL)

#define UNWRAP_NUSER(EXP) UNWRAP_NERR_FINAL(EXP, ERR_USER)


// RESULT UNWRAP_NEG


#define RES_UNWRAP_NEG_CLEANUP(EXP) { \
    ZIC_RES_VAR_NAME = (EXP); \
    if (ZIC_RES_VAR_NAME < 0) { ERROR_CLEANUP(ERR_SYS); } }

#define RES_UNWRAP_NEG_FINAL(EXP) { \
    ZIC_RES_VAR_NAME = (EXP); \
    if (ZIC_RES_VAR_NAME < 0) { ERROR_FINAL(ERR_SYS); } }

#define RES_UNWRAP_NEG_GOTO(EXP, GOTO) { \
    ZIC_RES_VAR_NAME = (EXP); \
    if (ZIC_RES_VAR_NAME < 0) { ERROR_GOTO(ERR_SYS, GOTO); } }

#define RES_UNWRAP_NSYS_CLEANUP(EXP) RES_UNWRAP_NEG_CLEANUP(EXP) 

#define RES_UNWRAP_NERR_CLEANUP(EXP, ERR) { \
    ZIC_RES_VAR_NAME = (EXP); \
    if (ZIC_RES_VAR_NAME < 0) { ERROR_CLEANUP(ERR) } 

#define RES_UNWRAP_NERR_FINAL(EXP, ERR) { \
    ZIC_RES_VAR_NAME = (EXP); \
    if (ZIC_RES_VAR_NAME < 0) { ERROR_FINAL(ERR) } 

#define RES_UNWRAP_NERR_GOTO(EXP, GOTO, ERR) { \
    ZIC_RES_VAR_NAME = (EXP); \
    if (ZIC_RES_VAR_NAME < 0) { ERROR_GOTO(ERR, GOTO) } 

#define RES_UNWRAP_NLOCAL_CLEANUP(EXP) RES_UNWRAP_NERR_CLEANUP(EXP, ERR_LOCAL)

#define RES_UNWRAP_NUSER_CLEANUP(EXP) RES_UNWRAP_NERR_CLEANUP(EXP, ERR_USER)

#define RES_UNWRAP_NERR(EXP, ERR) RES_UNWRAP_NERR_FINAL(EXP, ERR)

#define RES_UNWRAP_NEG(EXP) RES_UNWRAP_NEG_FINAL(EXP)

#define RES_UNWRAP_NSYS(EXP) RES_UNWRAP_NEG_FINAL(EXP)

#define RES_UNWRAP_NLOCAL(EXP) RES_UNWRAP_NERR_FINAL(EXP, ERR_LOCAL)

#define RES_UNWRAP_NUSER(EXP) RES_UNWRAP_NERR_FINAL(EXP, ERR_USER)


// UNWRAP_PTR


#define UNWRAP_PTR_CLEANUP(EXP) {   \
    const void *res = (EXP);        \
    if (!res) { ERROR_CLEANUP(ERR_SYS) } }

#define UNWRAP_PTR_FINAL(EXP) {     \
    const void *res = (EXP);        \
    if (!res) { ERROR_FINAL(ERR_SYS) } }

#define UNWRAP_PTR_GOTO(EXP, GOTO) { \
    const void *res = (EXP); \
    if (!res) { ERROR_GOTO(ERR_SYS, GOTO) } }

#define UNWRAP_PTR_SYS_CLEANUP(EXP) UNWRAP_PTR_CLEANUP(EXP)

#define UNWRAP_PTR_ERR_CLEANUP(EXP, ERR) { \
    const void *res = (EXP); \
    if (!res) { ERROR_CLEANUP(ERR) } }

#define UNWRAP_PTR_ERR_FINAL(EXP, ERR) { \
    const void *res = (EXP); \
    if (!res) { ERROR_FINAL(ERR) } }

#define UNWRAP_PTR_ERR_GOTO(EXP, GOTO, ERR) { \
    const void *res = (EXP); \
    if (!res) { ERROR_GOTO(ERR, GOTO) } }

#define UNWRAP_PTR_LOCAL_CLEANUP(EXP) UNWRAP_PTR_ERR_CLEANUP(EXP, ERR_LOCAL)

#define UNWRAP_PTR_USER_CLEANUP(EXP) UNWRAP_PTR_ERR_CLEANUP(EXP, ERR_USER)

#define UNWRAP_PTR_ERR(EXP, ERR) UNWRAP_PTR_ERR_FINAL(EXP, ERR)

#define UNWRAP_PTR(EXP) UNWRAP_PTR_FINAL(EXP)

#define UNWRAP_PTR_SYS(EXP) UNWRAP_PTR_FINAL(EXP)

#define UNWRAP_PTR_LOCAL(EXP) UNWRAP_PTR_ERR_FINAL(EXP, ERR_LOCAL)

#define UNWRAP_PTR_USER(EXP) UNWRAP_PTR_ERR_FINAL(EXP, ERR_USER)

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
