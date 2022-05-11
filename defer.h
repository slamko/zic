#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

#ifndef MINIMAL_ZIC
#define ALLOW_HIDDEN_STACKALLOC
#endif

#define USE_ZIC_STD

#ifndef USE_ZIC_STD
#ifdef __GNUC__ 
#define USE_NESTED_FUNCTIONS
#endif
#endif

#ifdef USE_NESTED_FUNCTIONS

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

#define DEFER1(LABEL, ST)  goto next##LABEL; defer##LABEL: defer1: ST; goto defer2; next##LABEL:;
#define DEFER2(LABEL, ST)  goto next##LABEL; defer##LABEL: goto defer1; defer2:  ST; goto defer3; next##LABEL:;
#define DEFER3(LABEL, ST)  goto next##LABEL; defer##LABEL: goto defer1; defer3:  ST; goto defer4; next##LABEL:;
#define DEFER4(LABEL, ST)  goto next##LABEL; defer##LABEL: goto defer1; defer4:  ST; goto defer5; next##LABEL:;
#define DEFER5(LABEL, ST)  goto next##LABEL; defer##LABEL: goto defer1; defer5:  ST; goto defer6; next##LABEL:;
#define DEFER6(LABEL, ST)  goto next##LABEL; defer##LABEL: goto defer1; defer6:  ST; goto defer7; next##LABEL:;
#define DEFER7(LABEL, ST)  goto next##LABEL; defer##LABEL: goto defer1; defer7:  ST; goto defer8; next##LABEL:;
#define DEFER8(LABEL, ST)  goto next##LABEL; defer##LABEL: goto defer1; defer8:  ST; goto defer9; next##LABEL:;
#define DEFER9(LABEL, ST)  goto next##LABEL; defer##LABEL: goto defer1; defer9:  ST; goto defer10; next##LABEL:;
#define DEFER10(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer10: ST; goto defer11; next##LABEL:;
#define DEFER11(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer11: ST; goto defer12; next##LABEL:;
#define DEFER12(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer12: ST; goto defer13; next##LABEL:;
#define DEFER13(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer13: ST; goto defer14; next##LABEL:;
#define DEFER14(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer14: ST; goto defer15; next##LABEL:;
#define DEFER15(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer15: ST; goto defer16; next##LABEL:;
#define DEFER16(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer16: ST; goto exit; next##LABEL:;

#define DEFER1_FINAL(ST)  goto next_final; defer##final: defer1:  ST; goto exit; next_final:;
#define DEFER2_FINAL(ST)  goto next_final; defer##final: defer2:  ST; goto exit; next_final:;
#define DEFER3_FINAL(ST)  goto next_final; defer##final: defer3:  ST; goto exit; next_final:;
#define DEFER4_FINAL(ST)  goto next_final; defer##final: defer4:  ST; goto exit; next_final:;
#define DEFER5_FINAL(ST)  goto next_final; defer##final: defer5:  ST; goto exit; next_final:;
#define DEFER6_FINAL(ST)  goto next_final; defer##final: defer6:  ST; goto exit; next_final:;
#define DEFER7_FINAL(ST)  goto next_final; defer##final: defer7:  ST; goto exit; next_final:;
#define DEFER8_FINAL(ST)  goto next_final; defer##final: defer8:  ST; goto exit; next_final:;
#define DEFER9_FINAL(ST)  goto next_final; defer##final: defer9:  ST; goto exit; next_final:;
#define DEFER10_FINAL(ST) goto next_final; defer##final: defer10: ST; goto exit; next_final:;
#define DEFER11_FINAL(ST) goto next_final; defer##final: defer11: ST; goto exit; next_final:;
#define DEFER12_FINAL(ST) goto next_final; defer##final: defer12: ST; goto exit; next_final:;
#define DEFER13_FINAL(ST) goto next_final; defer##final: defer13: ST; goto exit; next_final:;
#define DEFER14_FINAL(ST) goto next_final; defer##final: defer14: ST; goto exit; next_final:;
#define DEFER15_FINAL(ST) goto next_final; defer##final: defer15: ST; goto exit; next_final:;
#define DEFER16_FINAL(ST) goto next_final; defer##final: defer16: ST; goto exit; next_final:;

#define ERR_CLEANUP(LABEL, ERR) ZIC_res = ERR; goto LABEL;

#define CLEANUP(LABEL, CLEAN) LABEL: CLEAN;

#define DO_DEFER()

#define DO_ERRDEFER()

#define INIT_DEFER()

#define NO_CLEANUP() deferfinal: ;

#endif