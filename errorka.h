#ifndef DEF_TYPES
#define DEF_TYPES

void errdefer(void);

void defer(void);

#define HANDLE_ERR(ERR, ...) error(ERR, ##__VA_ARGS__); return FAIL;

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

extern void *unwrap_ptr_res;

#define PTR_UNWRAP(EXP) (unwrap_ptr_res = (EXP)) ? unwrap_ptr_res : NULL; \
    { if (!unwrap_ptr_res) return ERR_SYS; }


#define DEFER(STATEMENT) goto next; \
    defer: \
    STATEMENT; \
    goto exit; \
    next: 

#define ERR_DEFER(STATEMENT) goto errnext; \
    errdefer: \
    STATEMENT; \
    goto defer; \
    errnext: 

typedef enum {
    OK = 0,
    FAIL = 1,
    ERR_LOCAL = 2,
    ERR_SYS = 3,
    ERR_USER = 4
} base_result;

typedef int result;

#define DEF { \
    result res;
    void *unwrap_ptr_res;

/*#define END errdefer: \
    if (err_defer_cnt > 0) { \
        if (err_defer_cnt == 1) { \
            goto errdefer1; \
        } else if (err_defer_cnt == 2) { \
            goto errdefer2; \
        } else if (err_defer_cnt == 3) { \
            goto errdefer3; \
        } else { \
            #error Reached max count of ERR_DEFER labels \
        } \
    } \
    defer: \
    if (defer_cnt > 0) { \
        if (defer_cnt == 1) { \
            goto defer1; \
        } else if (defer_cnt == 2) { \
            goto defer2; \
        } else if (defer_cnt == 3) { \
            goto defer3; \
        } else { \
            #error Reached max count of DEFER labels \
        } \
    } \
    exit: return res; \
}*/

#define END exit: return res;\
}

#define IS_HANDLED(ERR) (ERR == FAIL)

#define IS_UNHANDLED(ERR) (ERR != FAIL)

#define IS_OK(EXP) (EXP == OK)

#define IS_ERROR(EXP) (EXP != OK)

#define OK() res = OK; \
    goto exit;

#define ERROR(ERR) res = ERR; \
    goto exit;

#define FAIL() res = FAIL; \
    goto exit;

#endif