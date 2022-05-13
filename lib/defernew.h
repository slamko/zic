typedef void(*defer_void_func)(void *);

typedef int(*defer_func)(void *);

typedef unsigned short defer_cnt;

#define DEFERS_COUNT 32

#define USE_DEFER

#define INIT_DEFER() \
    struct defer_arr ZIC_defer_arr = {0}; \
    struct defer_arr ZIC_errdefer_arr = {0};

#define DO_DEFER() \
    for(int deferid = 0; deferid < ZIC_defer_arr.cnt; deferid++) \
    ZIC_defer_arr.defers[deferid](ZIC_defer_arr.args[deferid]); \
    for(int deferid = 0; deferid < ZIC_defer_arr.void_cnt; deferid++) \
    ZIC_defer_arr.defers_void[deferid](ZIC_defer_arr.void_args[deferid]);

#define DO_ERRDEFER() \
    for(int deferid = 0; deferid < ZIC_errdefer_arr.cnt; deferid++) \
    ZIC_errdefer_arr.defers[deferid](ZIC_errdefer_arr.args[deferid]); \
    for(int deferid = 0; deferid < ZIC_errdefer_arr.void_cnt; deferid++) \
    ZIC_errdefer_arr.defers_void[deferid](ZIC_errdefer_arr.void_args[deferid]);

struct defer_arr {
    defer_void_func defers_void[DEFERS_COUNT / 2];
    defer_func defers[DEFERS_COUNT / 2];
    void *void_args[DEFERS_COUNT / 2];
    void *args[DEFERS_COUNT / 2];
    defer_cnt cnt;
    defer_cnt void_cnt;
};

#define L_DEFER_VOID(DFUNC, PTR)\
    ZIC_defer_arr.defers_void[ZIC_defer_arr.void_cnt] = DFUNC; \
    ZIC_defer_arr.void_args[ZIC_defer_arr.void_cnt] = PTR; \
    ZIC_defer_arr.void_cnt++;

#define L_DEFER(DFUNC, PTR)\
    ZIC_defer_arr.defers[ZIC_defer_arr.cnt] = DFUNC; \
    ZIC_defer_arr.args[ZIC_defer_arr.cnt] = PTR; \
    ZIC_defer_arr.cnt++;

#define L_ERRDEFER_VOID(DFUNC, PTR)\
    ZIC_errdefer_arr.defers_void[ZIC_errdefer_arr.void_cnt] = DFUNC; \
    ZIC_errdefer_arr.void_args[ZIC_errdefer_arr.void_cnt] = PTR; \
    ZIC_errdefer_arr.void_cnt++;

#define L_ERRDEFER(DFUNC, PTR)\
    ZIC_errdefer_arr.defers[ZIC_errdefer_arr.cnt] = DFUNC; \
    ZIC_errdefer_arr.args[ZIC_errdefer_arr.cnt] = PTR; \
    ZIC_errdefer_arr.cnt++;


#define DEFER_FREE(DFUNC, PTR) L_DEFER_VOID(DFUNC, PTR)

#define DEFER(DFUNC, PTR) L_DEFER((defer_func)DFUNC, (void *)PTR)

#define ERRDEFER_FREE(DFUNC, PTR) L_ERRDEFER_VOID((defer_void_func)DFUNC, (void *)PTR)

#define ERRDEFER(DFUNC, PTR) L_ERRDEFER((defer_func)DFUNC, (void *)PTR)