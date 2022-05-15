#ifndef ZIC_ERROR_HANDLING
#define ZIC_ERROR_HANDLING

#include "macroutils.h"

#ifndef MINI_ZIC
#define FULL_API
#endif

#ifdef FULL_API

#include "defer.h"

#endif
#include "basesyntax.h"

#include "catcherror.h"

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
    if (res < 0) { ERROR_FINAL(ERR); } \
    else if (res) { ERROR_FINAL(res); } }

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
    if (res < 0) { ERROR_FINAL(ERR) } 

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
    if (!res) { ERROR_FINAL(ERR) } }

#define UNWRAP_PTR_ERR_LABEL(EXP, LABEL, ERR) { \
    const void *res = (EXP); \
    if (!res) { ERROR_LABEL(ERR, LABEL) } }

#define UNWRAP_PTR_ERR(...) GET_LABEL_MACRO(__VA_ARGS__, UNWRAP_PTR_ERR_LABEL, UNWRAP_PTR_ERR_FINAL)

#define UNWRAP_PTR_LOCAL(...) UNWRAP_PTR_ERR(__VA_ARGS__, ERR_LOCAL)

#define UNWRAP_PTR_USER(...) UNWRAP_PTR_ERR(__VA_ARGS__, ERR_USER)

#ifdef FULL_API
#include "ptrunwrap.h"
#endif

#define OR(EXP) \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res

#define ELSE(EXP) : (EXP) ;

#include "matchwith.h"

#endif