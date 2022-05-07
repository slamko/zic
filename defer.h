typedef void(*defer_func)(void *);

struct defer_arr {
    defer_func defers[32];
    void *args[32];
    int defercnt;
};

#define DEFER(DFUNC, PTR)\
    ZIC_defer_arr.defers[ZIC_defer_arr.defercnt] = DFUNC; \
    ZIC_defer_arr.args[ZIC_defer_arr.defercnt] = PTR; \
    ZIC_defer_arr.defercnt++;

