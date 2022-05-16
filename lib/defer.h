
#ifndef ZIC_DEFER
#define ZIC_DEFER

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
#define DEFER16(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer16: ST; goto defer17; next##LABEL:;
#define DEFER17(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer17: ST; goto defer18; next##LABEL:;
#define DEFER18(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer18: ST; goto defer19; next##LABEL:;
#define DEFER19(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer19: ST; goto defer20; next##LABEL:;
#define DEFER20(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer20: ST; goto defer21; next##LABEL:;
#define DEFER21(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer21: ST; goto defer22; next##LABEL:;
#define DEFER22(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer22: ST; goto defer23; next##LABEL:;
#define DEFER23(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer23: ST; goto defer24; next##LABEL:;
#define DEFER24(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer24: ST; goto defer25; next##LABEL:;
#define DEFER25(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer25: ST; goto defer26; next##LABEL:;
#define DEFER26(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer26: ST; goto defer27; next##LABEL:;
#define DEFER27(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer27: ST; goto defer28; next##LABEL:;
#define DEFER28(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer28: ST; goto defer29; next##LABEL:;
#define DEFER29(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer29: ST; goto defer30; next##LABEL:;
#define DEFER30(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer30: ST; goto defer31; next##LABEL:;
#define DEFER31(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer31: ST; goto defer32; next##LABEL:;
#define DEFER32(LABEL, ST) goto next##LABEL; defer##LABEL: goto defer1; defer32: ST; goto exit; next##LABEL:;

#define DEFER1_FINAL(ST)  goto next_final; deferfinal: defer1:  ST; goto exit; next_final:;
#define DEFER2_FINAL(ST)  goto next_final; deferfinal: defer2:  ST; goto exit; next_final:;
#define DEFER3_FINAL(ST)  goto next_final; deferfinal: defer3:  ST; goto exit; next_final:;
#define DEFER4_FINAL(ST)  goto next_final; deferfinal: defer4:  ST; goto exit; next_final:;
#define DEFER5_FINAL(ST)  goto next_final; deferfinal: defer5:  ST; goto exit; next_final:;
#define DEFER6_FINAL(ST)  goto next_final; deferfinal: defer6:  ST; goto exit; next_final:;
#define DEFER7_FINAL(ST)  goto next_final; deferfinal: defer7:  ST; goto exit; next_final:;
#define DEFER8_FINAL(ST)  goto next_final; deferfinal: defer8:  ST; goto exit; next_final:;
#define DEFER9_FINAL(ST)  goto next_final; deferfinal: defer9:  ST; goto exit; next_final:;
#define DEFER10_FINAL(ST) goto next_final; deferfinal: defer10: ST; goto exit; next_final:;
#define DEFER11_FINAL(ST) goto next_final; deferfinal: defer11: ST; goto exit; next_final:;
#define DEFER12_FINAL(ST) goto next_final; deferfinal: defer12: ST; goto exit; next_final:;
#define DEFER13_FINAL(ST) goto next_final; deferfinal: defer13: ST; goto exit; next_final:;
#define DEFER14_FINAL(ST) goto next_final; deferfinal: defer14: ST; goto exit; next_final:;
#define DEFER15_FINAL(ST) goto next_final; deferfinal: defer15: ST; goto exit; next_final:;
#define DEFER16_FINAL(ST) goto next_final; deferfinal: defer16: ST; goto exit; next_final:;
#define DEFER17_FINAL(ST) goto next_final; deferfinal: defer17: ST; goto exit; next_final:;
#define DEFER18_FINAL(ST) goto next_final; deferfinal: defer18: ST; goto exit; next_final:;
#define DEFER19_FINAL(ST) goto next_final; deferfinal: defer19: ST; goto exit; next_final:;
#define DEFER20_FINAL(ST) goto next_final; deferfinal: defer20: ST; goto exit; next_final:;
#define DEFER21_FINAL(ST) goto next_final; deferfinal: defer21: ST; goto exit; next_final:;
#define DEFER22_FINAL(ST) goto next_final; deferfinal: defer22: ST; goto exit; next_final:;
#define DEFER23_FINAL(ST) goto next_final; deferfinal: defer23: ST; goto exit; next_final:;
#define DEFER24_FINAL(ST) goto next_final; deferfinal: defer24: ST; goto exit; next_final:;
#define DEFER25_FINAL(ST) goto next_final; deferfinal: defer25: ST; goto exit; next_final:;
#define DEFER26_FINAL(ST) goto next_final; deferfinal: defer26: ST; goto exit; next_final:;
#define DEFER27_FINAL(ST) goto next_final; deferfinal: defer27: ST; goto exit; next_final:;
#define DEFER28_FINAL(ST) goto next_final; deferfinal: defer28: ST; goto exit; next_final:;
#define DEFER29_FINAL(ST) goto next_final; deferfinal: defer29: ST; goto exit; next_final:;
#define DEFER30_FINAL(ST) goto next_final; deferfinal: defer30: ST; goto exit; next_final:;
#define DEFER31_FINAL(ST) goto next_final; deferfinal: defer31: ST; goto exit; next_final:;
#define DEFER32_FINAL(ST) goto next_final; deferfinal: defer32: ST; goto exit; next_final:;

#define NO_CLEANUP() deferfinal: ;

// DEF END END_CLEAN

#undef DEF
#undef END
#undef END_CLEAN

#define DEF { \
    ZIC_RESULT_INIT()

#define END goto deferfinal;  \
    errexit:                  \
    exit: ;                   \
    RETURN_ZIC_RESULT()       \
}

#define END_CLEAN deferfinal: \
    errexit:                  \
    exit: ;                   \
    RETURN_ZIC_RESULT()       \
}


// (ERROR OK FAIL)_CLEAN


#undef R_OK_CLEAN
#undef R_OK_FINAL
#undef R_OK_LABEL
#undef RET_OK

#undef ERROR_CLEAN
#undef ERROR_FINAL
#undef ERROR_LABEL
#undef ERROR

#undef FAIL_CLEAN
#undef FAIL_FINAL
#undef FAIL_LABEL
#undef FAIL


#define R_OK_CLEAN()            \
    ZIC_RES_VAR_NAME = OK;      \
    goto exit;

#define R_OK_FINAL()            \
    ZIC_RES_VAR_NAME = OK;      \
    goto deferfinal;

#define R_OK_LABEL(LABEL)       \
    ZIC_RES_VAR_NAME = OK;      \
    goto defer##LABEL;

#define RET_OK(...) GET_LABEL_MACRO(__VA_ARGS__, R_OK_LABEL, R_OK_FINAL)(__VA_ARGS__)

#define ERROR_CLEAN(ERR)        \
    ZIC_RES_VAR_NAME = ERR;     \
    goto exit;

#define ERROR_FINAL(ERR)        \
    ZIC_RES_VAR_NAME = ERR;     \
    goto deferfinal;

#define ERROR_LABEL(ERR, LABEL) \
    ZIC_RES_VAR_NAME = ERR;     \
    goto defer##LABEL;

#define ERROR(...) GET_LABEL_MACRO(__VA_ARGS__, ERROR_LABEL, ERROR_FINAL)(__VA_ARGS__)

#define FAIL_CLEAN()            \
    ZIC_RES_VAR_NAME = FAIL;    \
    goto exit;

#define FAIL_FINAL()            \
    ZIC_RES_VAR_NAME = FAIL;    \
    goto deferfinal;

#define FAIL_LABEL(LABEL)       \
    ZIC_RES_VAR_NAME = FAIL;    \
    goto defer##LABEL;

#define FAIL(...) GET_LABEL_MACRO(__VA_ARGS__, FAIL_LABEL, FAIL_FINAL)(__VA_ARGS__)



// UNWRAP DEFINES_CLEAN


#define UNWRAP_CLEAN(EXP) {     \
    int res = (EXP);            \
    if (res < 0) { ERROR_CLEAN(ERR_SYS); } \
    else if (res) { ERROR_CLEAN(res); } }

#define UNWRAP_ERR_CLEAN(EXP, ERR) { \
    const int res = (EXP);      \
    if (res < 0) ERROR_CLEAN(ERR) \
    else if (res) ERROR_CLEAN(res) }

#define UNWRAP_SYS_CLEAN(EXP) UNWRAP_CLEAN(EXP)

#define UNWRAP_LOCAL_CLEAN(EXP) UNWRAP_ERR_CLEAN(EXP, ERR_LOCAL)

#define UNWRAP_USER_CLEAN(EXP) UNWRAP_ERR_CLEAN(EXP, ERR_USER)

#define UNWRAP_NEG_CLEAN(EXP) { \
    int res = (EXP);            \
    if (res < 0) ERROR_CLEAN(ERR_SYS); }

#define UNWRAP_NSYS_CLEAN(EXP) UNWRAP_NEG_CLEAN(EXP)

#define UNWRAP_NERR_CLEAN(EXP, ERR) { \
    const int res = (EXP);      \
    if (res < 0) { ERROR_CLEAN(ERR) } 

#define UNWRAP_NLOCAL_CLEAN(EXP) UNWRAP_NERR_CLEAN(EXP, ERR_LOCAL) 

#define UNWRAP_NUSER_CLEAN(EXP) UNWRAP_NERR_CLEAN(EXP, ERR_USER) 

#define UNWRAP_PTR_CLEAN(EXP) { \
    const void *res = (EXP);    \
    if (!res) { ERROR_CLEAN(ERR_SYS) } }

#define UNWRAP_PTR_SYS_CLEAN(EXP) UNWRAP_PTR_CLEAN(EXP)

#define UNWRAP_PTR_ERR_CLEAN(EXP, ERR) { \
    const void *res = (EXP);    \
    if (!res) { ERROR_CLEAN(ERR) } }

#define UNWRAP_PTR_LOCAL_CLEAN(EXP) UNWRAP_PTR_ERR_CLEAN(EXP, ERR_LOCAL)

#define UNWRAP_PTR_USER_CLEAN(EXP) UNWRAP_PTR_ERR_CLEAN(EXP, ERR_USER)


// PTR_UNWRAP_CLEAN


#define PTR_UNWRAP_CLEAN(EXP) \
    (ZIC_PTR_UNWRAP_VAR_NAME = (EXP)) ? ZIC_PTR_UNWRAP_VAR_NAME : NULL; \
    { if (!ZIC_PTR_UNWRAP_VAR_NAME) { ERROR_CLEAN(ERR_SYS) } }

#define PTR_UNWRAP_SYS_CLEAN(EXP) PTR_UNWRAP_CLEAN(EXP)

#define PTR_UNWRAP_ERR_CLEAN(EXP, ERR) { \
    (ZIC_PTR_UNWRAP_VAR_NAME = (EXP)) ? ZIC_PTR_UNWRAP_VAR_NAME : NULL; \
    { if (!ZIC_PTR_UNWRAP_VAR_NAME) ERROR_CLEAN(ERR) }

#define PTR_UNWRAP_LOCAL_CLEAN(EXP) PTR_UNWRAP_ERR_CLEAN(EXP, ERR_LOCAL)

#define PTR_UNWRAP_USER_CLEAN(EXP) PTR_UNWRAP_ERR_CLEAN(EXP, ERR_USER)



// CATCH_CLEAN

#define CATCH_CLEAN(ERR, ...) \
    ZIC_BASE_CATCH(ERR, __VA_ARGS__) \
    FAIL_CLEAN();

#define CATCH_SYS_CLEAN() perror(ERROR_PREFIX); FAIL_CLEAN();



#endif // ZIC_DEFER