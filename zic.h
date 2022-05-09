#ifndef ZIC_ERROR_HANDLING
#define ZIC_ERROR_HANDLING

#include "defer.h"

#define ERROR_PREFIX "error"

#define CATCH(ERR, ...) \
    fprintf(stderr, ERROR_PREFIX); \
    fprintf(stderr, ERR, ##__VA_ARGS__); \
    fprintf(stderr, "\n"); \
    return FAIL;

#define CATCH_SYS() perror(ERROR_PREFIX); return FAIL;

#define UNWRAP(EXP) { \
    int res = (EXP); \
    if (res < 0) return ERR_SYS; \
    else if (res) return res; }

#define UNWRAP_NEG(EXP) { \
    int res = (EXP); \
    if (res < 0) return ERR_SYS; }

#define UNWRAP_SYS(EXP) UNWRAP(EXP)

#define UNWRAP_NSYS(EXP) UNWRAP_NEG(EXP)

#define UNWRAP_LOCAL(EXP) { \
    int res = (EXP); \
    if (res < 0) return ERR_LOCAL; \
    else if (res) return res; }

#define UNWRAP_NLOCAL(EXP) { \
    int res = (EXP); \
    if (res < 0) return ERR_LOCAL; \
}

#define UNWRAP_USER(EXP) { \
    int res = (EXP); \
    if (res < 0) return ERR_USER; \
    else if (res) return res; }

#define UNWRAP_NUSER(EXP) { \
    int res = (EXP); \
    if (res < 0) return ERR_USER;

#define UNWRAP_ERR(EXP, ERR) { \
    const int res = (EXP); \
    if (res < 0) return ERR; \
    else if (res) return res; }

#define UNWRAP_NERR(EXP, ERR) { \
    const int res = (EXP); \
    if (res < 0) return ERR; 

#define UNWRAP_PTR(EXP) { \
    const void *res = (EXP); \
    if (!res) return ERR_SYS; }

#define UNWRAP_PTR_SYS(EXP) UNWRAP_PTR(EXP)

#define UNWRAP_PTR_LOCAL(EXP) { \
    const void *res = (EXP); \
    if (!res) return ERR_LOCAL; }

#define UNWRAP_PTR_USER(EXP) { \
    const void *res = (EXP); \
    if (!res) return ERR_USER; }

#define UNWRAP_PTR_ERR(EXP, ERR) { \
    const void *res = (EXP); \
    if (!res) return ERR; }

#ifndef MINIMAL_ZIC

#define PTR_UNWRAP(EXP) \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) return ERR_SYS; }

#define PTR_UNWRAP_SYS(EXP) PTR_UNWRAP(EXP)

#define PTR_UNWRAP_LOCAL(EXP) { \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) return ERR_LOCAL; }

#define PTR_UNWRAP_USER(EXP) { \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) return ERR_USER; }

#define PTR_UNWRAP_ERR(EXP, ERR) { \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) return ERR; }

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
#define END ;\
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

#ifndef MINIMAL_ZIC

#define OK() \
    ZIC_res = OK; \
    goto exit;

#define ERROR(ERR) \
    ZIC_res = ERR; \
    goto errexit;

#define FAIL() \
    ZIC_res = FAIL; \
    goto errexit;

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

#endif