#ifdef FULL_API

#define R_OK_CLEAN() \
    ZIC_res = OK; \
    goto exit;

#define R_OK_FINAL() \
    ZIC_res = OK; \
    goto deferfinal;

#define R_OK_LABEL(LABEL) \
    ZIC_res = OK; \
    goto defer##LABEL;

#define RET_OK(...) GET_LABEL_MACRO(__VA_ARGS__, OK_LABEL, OK_FINAL)(__VA_ARGS__)

#define ERROR_CLEAN(ERR) \
    ZIC_res = ERR; \
    goto exit;

#define ERROR_FINAL(ERR) \
    ZIC_res = ERR; \
    goto deferfinal;

#define ERROR_LABEL(ERR, LABEL) \
    ZIC_res = ERR; \
    goto defer##LABEL;

#define ERROR(...) GET_LABEL_MACRO(__VA_ARGS__, ERROR_LABEL, ERROR_FINAL)(__VA_ARGS__)

#define FAIL_CLEAN() \
    ZIC_res = FAIL; \
    goto exit;

#define FAIL_FINAL() \
    ZIC_res = FAIL; \
    goto deferfinal;

#define FAIL_LABEL(LABEL) \
    ZIC_res = FAIL; \
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
    result ZIC_res = OK; \
    void *ZIC_unwrap_ptr_res = NULL;

#define END goto deferfinal; \
    errexit: ;\
    exit: ;\
    return ZIC_res; \
}

#define END_CLEAN deferfinal: ; \
    errexit: ;\
    exit: ;\
    return ZIC_res; \
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
