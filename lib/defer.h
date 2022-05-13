
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

#define CLEANUP(LABEL, CLEAN) LABEL: CLEAN;

#define DO_DEFER()

#define DO_ERRDEFER()

#define INIT_DEFER()

#define NO_CLEANUP() deferfinal: ;
