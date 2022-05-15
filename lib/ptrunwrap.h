#define PTR_UNWRAP_CLEAN(EXP) \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) { ERROR_CLEAN(ERR_SYS) } }

#define PTR_UNWRAP_FINAL(EXP) \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) ERROR(ERR_SYS) }

#define PTR_UNWRAP_LABEL(EXP, LABEL) \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) ERROR(ERR_SYS, LABEL) }

#define PTR_UNWRAP(...) GET_LABEL_MACRO(__VA_ARGS__, PTR_UNWRAP_LABEL, PTR_UNWRAP_FINAL)(__VA_ARGS__)

#define PTR_UNWRAP_SYS(EXP, ...) PTR_UNWRAP(EXP, __VA_ARGS__)

#define PTR_UNWRAP_ERR_CLEAN(EXP, ERR) { \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) ERROR_CLEAN(ERR) }

#define PTR_UNWRAP_LOCAL_CLEAN(EXP) PTR_UNWRAP_ERR_CLEAN(EXP, ERR_LOCAL)

#define PTR_UNWRAP_USER_CLEAN(EXP) PTR_UNWRAP_ERR_CLEAN(EXP, ERR_USER)

#define PTR_UNWRAP_ERR_FINAL(EXP, ERR) { \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) ERROR_FINAL(ERR) }

#define PTR_UNWRAP_ERR_LABEL(EXP, LABEL, ERR) { \
    (ZIC_unwrap_ptr_res = (EXP)) ? ZIC_unwrap_ptr_res : NULL; \
    { if (!ZIC_unwrap_ptr_res) ERROR_LABEL(ERR, LABEL) }

#define PTR_UNWRAP_ERR(...) GET_LABEL_MACRO(__VA_ARGS__, PTR_UNWRAP_ERR_LABEL, PTR_UNWRAP_ERR_FINAL)(__VA_ARGS__)

#define PTR_UNWRAP_LOCAL(...) PTR_UNWRAP_ERR(__VA_ARGS__, ERR_LOCAL)

#define PTR_UNWRAP_USER(...) PTR_UNWRAP_ERR(__VA_ARGS_, ERR_USER)
