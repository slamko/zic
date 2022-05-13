#ifndef ZIC_ERROR_HANDLING
#define ZIC_ERROR_HANDLING

#include "defer.h"

#define ERROR_PREFIX "error"

#ifndef MINIMAL_ZIC

#define OK_CLEAN() \
    ZIC_res = OK; \
    goto exit;

#define OK_FINAL() \
    ZIC_res = OK; \
    goto deferfinal;

#define OK_LABEL(LABEL) \
    ZIC_res = OK; \
    goto defer##LABEL;

#define GET_OK_MACRO(_A1, _A2, OK_MACRO,...) OK_MACRO
#define OK(...) GET_OK_MACRO(__VA_ARGS__, OK_LABEL, OK_FINAL)(__VA_ARGS__)

#define ERROR_CLEAN(ERR) \
    ZIC_res = ERR; \
    goto exit;

#define ERROR_FINAL(ERR) \
    ZIC_res = ERR; \
    goto deferfinal;

#define ERROR_LABEL(ERR, LABEL) \
    ZIC_res = ERR; \
    goto defer##LABEL;

#define GET_ERROR_MACRO(_A1, _A2, ERROR_MACRO,...) ERROR_MACRO
#define ERROR(...) GET_ERROR_MACRO(__VA_ARGS__, ERROR_LABEL, ERROR_FINAL)(__VA_ARGS__)

#define FAIL_CLEAN() \
    ZIC_res = FAIL; \
    goto exit;

#define FAIL_FINAL() \
    ZIC_res = FAIL; \
    goto deferfinal;

#define FAIL_LABEL(LABEL) \
    ZIC_res = FAIL; \
    goto defer##LABEL;

#define GET_FAIL_MACRO(_A1, _A2, FAIL_MACRO,...) FAIL_MACRO
#define FAIL(...) GET_FAIL_MACRO(__VA_ARGS__, FAIL_LABEL, FAIL_FINAL)(__VA_ARGS__)

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

#define UNWRAP_CLEAN(EXP) { \
    int res = (EXP); \
    if (res < 0) { ERROR_CLEAN(ERR_SYS); } \
    else if (res) { ERROR_CLEAN(res); } }

#define UNWRAP_FINAL(EXP) { \
    int res = (EXP); \
    if (res < 0) { ERROR(ERR_SYS); } \
    else if (res) { ERROR(res); } }

#define UNWRAP_LABEL(EXP, LABEL) { \
    int res = (EXP); \
    if (res < 0) { ERROR(ERR_SYS, LABEL); } \
    else if (res) ERROR(res, LABEL); }

#define GET_UNWRAP_MACRO(_A1, _A2, UNWRAP_MACRO,...) UNWRAP_MACRO
#define UNWRAP(...) GET_UNWRAP_MACRO(__VA_ARGS__, UNWRAP_LABEL, UNWRAP_FINAL)(__VA_ARGS__)

#define UNWRAP_NEG_CLEAN(EXP) { \
    int res = (EXP); \
    if (res < 0) ERROR_CLEAN(ERR_SYS); }

#define UNWRAP_NEG_FINAL(EXP) { \
    int res = (EXP); \
    if (res < 0) ERROR(ERR_SYS); }

#define UNWRAP_NEG_LABEL(EXP, LABEL) { \
    int res = (EXP); \
    if (res < 0) ERROR(ERR_SYS, LABEL); }

#define GET_UNWRAP_NEG(_A1, _A2, UNWRAP_NEG_MACRO,...) UNWRAP_NEG_MACRO

#define UNWRAP_NEG(...) GET_UNWRAP_NEG(__VA_ARGS__, UNWRAP_NEG_LABEL, UNWRAP_NEG_FINAL)(__VA_ARGS__)

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

#define UNWRAP_PTR_CLEAN(EXP) { \
    const void *res = (EXP); \
    if (!res) ERROR_CLEAN(ERR_SYS) }

#define UNWRAP_PTR_FINAL(EXP) { \
    const void *res = (EXP); \
    if (!res) ERROR(ERR_SYS) }

#define UNWRAP_PTR_LABEL(EXP, LABEL) { \
    const void *res = (EXP); \
    if (!res) ERROR(ERR_SYS, defer##LABEL) }

#define GET_UNWRAP_PTR(_A1, _A2, UNWRAP_PTR_MACRO,...) UNWRAP_PTR_MACRO

#define UNWRAP_PTR(...) GET_UNWRAP_PTR(__VA_ARGS__, UNWRAP_PTR_LABEL, UNWRAP_PTR_FINAL)(__VA_ARGS__)

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

#define PTR_UNWRAP_CLEAN(EXP) \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; 
    //{ if (!ZIC_unwrap_ptr_res) { puts("ewfwfe"); ERROR_CLEAN(ERR_SYS) } }

#define PTR_UNWRAP_FINAL(EXP) \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) ERROR(ERR_SYS) }

#define PTR_UNWRAP_LABEL(EXP, LABEL) \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) ERROR(ERR_SYS, LABEL) }

#define GET_PTR_UNWRAP(_A1, _A2, PTR_UNWRAP_MACRO,...) PTR_UNWRAP_MACRO

#define PTR_UNWRAP(...) GET_PTR_UNWRAP(__VA_ARGS__, PTR_UNWRAP_LABEL, PTR_UNWRAP_FINAL)(__VA_ARGS__)

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


#define MATCH switch(

#define CASE_NONE() 

#define CASE(CASE_EXP) case CASE_EXP  
/*
#define GET_CASE(_A1, CASE_MACRO,...) CASE_MACRO

#define CASE(...) GET_CASE(__VA_ARGS__, CASE1, CASE_NONE)(__VA_ARGS__)
*/
#define WITH4(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4) ) { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); }

#define WITH3(CASEEXP1, CASEEXP2, CASEEXP3) ) { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEXP3); }

#define WITH2(CASEEXP1, CASEEXP2) ) { CASE(CASEEXP1); CASE(CASEEXP2); }

#define WITH1(CASEEXP) ) { CASE(CASEEXP) }
/*_A5, _A6, _A7, _A8, _A9, _A10, _A11, _A12, _A13, _A14, _A15, _A16,*/
#define GET_WITH(_A1, _A2, _A3, _A4,  WITH_MACRO,...) WITH_MACRO

#define WITH(...) GET_WITH(__VA_ARGS__, WITH4, WITH3, WITH2, WITH1)(__VA_ARGS__)


#endif