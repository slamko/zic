#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

#ifdef __GNUC__ 
#define USE_NESTED_FUNCTIONS

void defer1(void);
void defer2(void);
void defer3(void);
void defer4(void);
void defer5(void);
void defer6(void);
void defer7(void);
void defer8(void);

void errdefer1(void);
void errdefer2(void);
void errdefer3(void);
void errdefer4(void);
void errdefer5(void);
void errdefer6(void);
void errdefer7(void);
void errdefer8(void);

#define DEFER1(EXP) \
    void defer1(void) { \
        EXP; \
    }

#define DEFER2(EXP) \
    void defer2(void) { \
        EXP; \
    }

#define DEFER3(EXP) \
    void defer3(void) { \
        EXP; \
    }

#define DEFER4(EXP) \
    void defer4(void) { \
        EXP; \
    }

#define DEFER5(EXP) \
    void defer5(void) { \
        EXP; \
    }

#define DEFER6(EXP) \
    void defer6(void) { \
        EXP; \
    }

#define DEFER7(EXP) \
    void defer7(void) { \
        EXP; \
    }

#define DEFER8(EXP) \
    void defer8(void) { \
        EXP; \
    }



#define ERRDEFER1(EXP) \
    void errdefer1(void) { \
        EXP; \
    }

#define ERRDEFER2(EXP) \
    void errdefer2(void) { \
        EXP; \
    }

#define ERRDEFER3(EXP) \
    void errdefer3(void) { \
        EXP; \
    }

#define ERRDEFER4(EXP) \
    void errdefer4(void) { \
        EXP; \
    }

#define ERRDEFER5(EXP) \
    void errdefer5(void) { \
        EXP; \
    }

#define ERRDEFER6(EXP) \
    void errdefer6(void) { \
        EXP; \
    }

#define ERRDEFER7(EXP) \
    void errdefer7(void) { \
        EXP; \
    }

#define ERRDEFER8(EXP) \
    void errdefer8(void) { \
        EXP; \
    }
    

#define DO_DEFER() \
    defer1(); \
    defer2(); \
    defer3(); \
    defer4(); \
    defer5(); \
    defer6(); \
    defer7(); \
    defer8(); 

#define DO_ERRDEFER() \
    errdefer1(); \
    errdefer2(); \
    errdefer3(); \
    errdefer4(); \
    errdefer5(); \
    errdefer6(); \
    errdefer7(); \
    errdefer8(); 


#else

typedef void(*defer_free)(void *);

typedef int(*defer_fclose)(FILE *);

typedef int(*defer_str)(const char *, ...);

typedef int(*defer_closedir)(DIR *);

typedef unsigned short defer_cnt;

#define DEFERS_COUNT 8

#define USE_DEFER

#define INIT_DEFER() \
    struct defer_arr ZIC_defer_arr = {0}; \
    struct defer_arr ZIC_errdefer_arr = {0};

#define DO_DEFER() \
    for(int deferid = 0; deferid < ZIC_defer_arr.free_cnt; deferid++) \
    free(ZIC_defer_arr.free_args[deferid]); \
    for(int deferid = 0; deferid < ZIC_defer_arr.fclose_cnt; deferid++) \
    fclose(ZIC_defer_arr.fclose_args[deferid]); \
    for(int deferid = 0; deferid < ZIC_defer_arr.closedir_cnt; deferid++) \
    closedir(ZIC_defer_arr.closedir_args[deferid]); \
    for(int deferid = 0; deferid < ZIC_defer_arr.str_cnt; deferid++) \
    ZIC_defer_arr.defers_str[deferid](ZIC_defer_arr.str_args[deferid]); \

#define DO_ERRDEFER() \
    for(int deferid = 0; deferid < ZIC_errdefer_arr.free_cnt; deferid++) \
    free(ZIC_errdefer_arr.free_args[deferid]); \
    for(int deferid = 0; deferid < ZIC_errdefer_arr.fclose_cnt; deferid++) \
    fclose(ZIC_errdefer_arr.fclose_args[deferid]); \
    for(int deferid = 0; deferid < ZIC_errdefer_arr.closedir_cnt; deferid++) \
    closedir(ZIC_errdefer_arr.closedir_args[deferid]); \
    for(int deferid = 0; deferid < ZIC_errdefer_arr.str_cnt; deferid++) \
    ZIC_errdefer_arr.defers_str[deferid](ZIC_errdefer_arr.str_args[deferid]); \

struct defer_arr {
    defer_free defers_free[DEFERS_COUNT];
    defer_fclose defers_fclose[DEFERS_COUNT];
    defer_closedir defers_closedir[DEFERS_COUNT];
    defer_str defers_str[DEFERS_COUNT];
    void *free_args[DEFERS_COUNT];
    FILE *fclose_args[DEFERS_COUNT];
    DIR *closedir_args[DEFERS_COUNT];
    char *str_args[DEFERS_COUNT];
    defer_cnt free_cnt;
    defer_cnt fclose_cnt;
    defer_cnt closedir_cnt;
    defer_cnt str_cnt;
};

#define ERRDEFER_FREE(PTR) \
    ZIC_errdefer_arr.free_args[ZIC_errdefer_arr.free_cnt] = PTR; \
    ZIC_errdefer_arr.void_cnt++;

#define ERRDEFER_FCLOSE(PTR) \
    ZIC_errdefer_arr.fclose_args[ZIC_errdefer_arr.fclose_cnt] = PTR; \
    ZIC_errdefer_arr.fclose_cnt++;

#define ERRDEFER_CLOSE_DIR(PTR) \
    ZIC_errdefer_arr.closedir_args[ZIC_errdefer_arr.closedir_cnt] = PTR; \
    ZIC_errdefer_arr.closedir_cnt++;

#define ERRDEFER_STR(FUNC, PTR) \
    ZIC_errdefer_arr.defers_str[ZIC_errdefer_arr.str_cnt] = FUNC; \
    ZIC_errdefer_arr.str_args[ZIC_errdefer_arr.str_cnt] = PTR; \
    ZIC_errdefer_arr.str_cnt++;



#define DEFER_FREE(PTR) \
    ZIC_defer_arr.free_args[ZIC_defer_arr.free_cnt] = PTR; \
    ZIC_defer_arr.free_cnt++;

#define DEFER_FCLOSE(PTR) \
    ZIC_defer_arr.fclose_args[ZIC_defer_arr.fclose_cnt] = PTR; \
    ZIC_defer_arr.fclose_cnt++;

#define DEFER_CLOSE_DIR(PTR) \
    ZIC_defer_arr.closedir_args[ZIC_defer_arr.closedir_cnt] = PTR; \
    ZIC_defer_arr.closedir_cnt++;

#define DEFER_STR(FUNC, PTR) \
    ZIC_defer_arr.defers_str[ZIC_defer_arr.str_cnt] = FUNC; \
    ZIC_defer_arr.str_args[ZIC_defer_arr.str_cnt] = PTR; \
    ZIC_defer_arr.str_cnt++;

#endif