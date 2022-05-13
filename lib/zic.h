#ifndef ZIC_ERROR_HANDLING
#define ZIC_ERROR_HANDLING

#include "defer.h"

#define ERROR_PREFIX "error"

#ifndef MINIMAL_ZIC

#define OK() \
    ZIC_res = OK; \
    goto deferfinal;

#define ERROR_FORCE(ERR) \
    ZIC_res = ERR; \
    goto exit;

#define ERROR_LABEL(ERR, LABEL) \
    ZIC_res = ERR; \
    goto defer##LABEL;

#define GET_ERROR_MACRO(_A1, _A2, ERROR_MACRO,...) ERROR_MACRO
#define ERROR(...) GET_ERROR_MACRO(__VA_ARGS__, ERROR_LABEL, ERROR_FORCE)(__VA_ARGS__)

#define FAIL() \
    ZIC_res = FAIL; \
    goto deferfinal;

#else
#define OK() \
    DO_DEFER();\
    return OK;

#define ERROR(ERR) \
    DO_ERRDEFER();\
    DO_DEFER();\
    return ERR;

#define FAIL() \
    DO_ERRDEFER();\
    DO_DEFER();\
    return FAIL; 

#endif

#define CATCH(ERR, ...) \
    fprintf(stderr, ERROR_PREFIX); \
    fprintf(stderr, ERR, ##__VA_ARGS__); \
    fprintf(stderr, "\n"); \
    FAIL();

#define CATCH_SYS() perror(ERROR_PREFIX); FAIL();

#define UNWRAP_FORCE(EXP) { \
    int res = (EXP); \
    if (res < 0) ERROR(ERR_SYS); \
    else if (res) ERROR(res); }

#define UNWRAP_LABEL(EXP, LABEL) { \
    int res = (EXP); \
    if (res < 0) { ERROR(ERR_SYS, LABEL); } \
    else if (res) ERROR(res, LABEL); }

#define GET_UNWRAP_MACRO(_A1, _A2, UNWRAP_MACRO,...) UNWRAP_MACRO
#define UNWRAP(...) GET_UNWRAP_MACRO(__VA_ARGS__, UNWRAP_LABEL, UNWRAP_FORCE)(__VA_ARGS__)


#define UNWRAP_NEG_FORCE(EXP) { \
    int res = (EXP); \
    if (res < 0) ERROR(ERR_SYS); }

#define UNWRAP_NEG_LABEL(EXP, LABEL) { \
    int res = (EXP); \
    if (res < 0) ERROR(ERR_SYS, LABEL); }

#define GET_UNWRAP_NEG(_A1, _A2, UNWRAP_NEG_MACRO,...) UNWRAP_NEG_MACRO

#define UNWRAP_NEG(...) GET_UNWRAP_NEG(__VA_ARGS__, UNWRAP_NEG_LABEL, UNWRAP_NEG_FORCE)(__VA_ARGS__)


#define UNWRAP_SYS(EXP) UNWRAP(EXP)

#define UNWRAP_NSYS(EXP) UNWRAP_NEG(EXP)

#define UNWRAP_LOCAL(EXP) { \
    int res = (EXP); \
    if (res < 0) ERROR(ERR_LOCAL) \
    else if (res) ERROR(res) }

#define UNWRAP_NLOCAL(EXP) { \
    int res = (EXP); \
    if (res < 0) ERROR(ERR_LOCAL) \
}

#define UNWRAP_USER(EXP) { \
    int res = (EXP); \
    if (res < 0) ERROR(ERR_USER) \
    else if (res) ERROR(res) }

#define UNWRAP_NUSER(EXP) { \
    int res = (EXP); \
    if (res < 0) ERROR(ERR_USER)

#define UNWRAP_ERR(EXP, ERR) { \
    const int res = (EXP); \
    if (res < 0) ERROR(ERR) \
    else if (res) ERROR(res) }

#define UNWRAP_NERR(EXP, ERR) { \
    const int res = (EXP); \
    if (res < 0) ERROR(ERR) 

#define UNWRAP_PTR_FORCE(EXP) { \
    const void *res = (EXP); \
    if (!res) ERROR(ERR_SYS) }

#define UNWRAP_PTR_LABEL(EXP, LABEL) { \
    const void *res = (EXP); \
    if (!res) ERROR(ERR_SYS, LABEL) }

#define GET_UNWRAP_PTR(_A1, _A2, UNWRAP_PTR_MACRO,...) UNWRAP_PTR_MACRO

#define UNWRAP_PTR(...) GET_UNWRAP_PTR(__VA_ARGS__, UNWRAP_PTR_LABEL, UNWRAP_PTR_FORCE)(__VA_ARGS__)

#define UNWRAP_PTR_SYS(EXP) UNWRAP_PTR(EXP)

#define UNWRAP_PTR_LOCAL(EXP) { \
    const void *res = (EXP); \
    if (!res) ERROR(ERR_LOCAL) }

#define UNWRAP_PTR_USER(EXP) { \
    const void *res = (EXP); \
    if (!res) ERROR(ERR_USER) }

#define UNWRAP_PTR_ERR(EXP, ERR) { \
    const void *res = (EXP); \
    if (!res) ERROR(ERR) }

#ifndef MINIMAL_ZIC

#define PTR_UNWRAP_FORCE(EXP) \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) ERROR(ERR_SYS) }

#define PTR_UNWRAP_LABEL(EXP, LABEL) \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) ERROR(ERR_SYS, LABEL) }

#define GET_PTR_UNWRAP(_A1, _A2, PTR_UNWRAP_MACRO,...) PTR_UNWRAP_MACRO

#define PTR_UNWRAP(...) GET_PTR_UNWRAP(__VA_ARGS__, PTR_UNWRAP_LABEL, PTR_UNWRAP_FORCE)(__VA_ARGS__)

#define PTR_UNWRAP_SYS(EXP) PTR_UNWRAP(EXP)

#define PTR_UNWRAP_LOCAL(EXP) { \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) ERROR(ERR_LOCAL) }

#define PTR_UNWRAP_USER(EXP) { \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) ERROR(ERR_USER) }

#define PTR_UNWRAP_ERR(EXP, ERR) { \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) ERROR(ERR) }

#endif

typedef enum {
    OK = 0,
    FAIL = 1,
    ERR_LOCAL = 2,
    ERR_SYS = 3,
    ERR_USER = 4
} base_result;

typedef int result;

#ifndef MINIMAL_ZIC
#ifdef USE_NESTED_FUNCTIONS

#define DEF { \
    result ZIC_res = OK; \
    void *ZIC_unwrap_ptr_res = NULL; 
#else

#define DEF { \
    result ZIC_res = OK; \
    void *ZIC_unwrap_ptr_res = NULL; \
    INIT_DEFER()
#endif

#else
#define DEF {
#endif

#ifndef MINIMAL_ZIC
#define END goto deferfinal; \
    errexit: \
    DO_ERRDEFER(); \
    exit: \
    DO_DEFER(); \
    return ZIC_res; \
}

#define END_CLEAN deferfinal: ; \
    errexit: \
    DO_ERRDEFER(); \
    exit: \
    DO_DEFER(); \
    return ZIC_res; \
}

#else
#define END }
#endif

#define IS_HANDLED(ERR) (ERR == FAIL || ERR == OK)

#define IS_UNHANDLED(ERR) (ERR != FAIL && ERR != OK)

#define IS_OK(EXP) (EXP == OK)

#define IS_ERROR(EXP) (EXP != OK)

#define ISNULL(PTR) !PTR

#define IS_NOTNULL(PTR) PTR

#define OR(EXP) \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res

#define ELSE(EXP) : (EXP) ;

#endif