
#ifdef ZIC_MATCH_WITH
#define ZIC_MATCH_WITH

#define MATCH switch(

#define CASE_NONE() 

#define MATCH_CASE(CASE_EXP) case CASE_EXP; break

#define GET_CASE(_A1, CASE_MACRO,...) CASE_MACRO

#define CASE(...) GET_CASE(__VA_ARGS__, MATCH_CASE, CASE_NONE)(__VA_ARGS__)

#define WITH32(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
     CASEEXP9, CASEEXP10, CASEEXP11, CASEEXP12, CASEEXP13, CASEEXP14, CASEEXP15, CASEEXP16, \
     CASEEXP17, CASEEXP18, CASEEXP19, CASEEXP20, CASEEXP21, CASEEXP22, CASEEXP23, CASEEXP24, \
     CASEEXP25, CASEEXP26, CASEEXP27, CASEEXP28, CASEEXP29, CASEEXP30, CASEEXP31, CASEEXP32) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
        CASE(CASEEXP8); CASE(CASEEXP9)}

#define WITH24(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
    CASEEXP9, CASEEXP10, CASEEXP11, CASEEXP12, CASEEXP13, CASEEXP14, CASEEXP15, CASEEXP16, \
    CASEEXP17, CASEEXP18, CASEEXP19, CASEEXP20, CASEEXP21, CASEEXP22, CASEEXP23, CASEEXP24) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9); CASE(CASEEXP10); CASE(CASEEXP11); CASE(CASEEXP12); CASE(CASEEXP13); CASE(CASEEXP14); \
    CASE(CASEEXP15); CASE(CASEEXP16); CASE(CASEEXP17); CASE(CASEEXP18); CASE(CASEEXP19); CASE(CASEEXP20); CASE(CASEEXP21); \
    CASE(CASEEXP22); CASE(CASEEXP23); CASE(CASEEXP24);}

#define WITH23(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
    CASEEXP9, CASEEXP10, CASEEXP11, CASEEXP12, CASEEXP13, CASEEXP14, CASEEXP15, CASEEXP16, \
    CASEEXP17, CASEEXP18, CASEEXP19, CASEEXP20, CASEEXP21, CASEEXP22, CASEEXP23) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9); CASE(CASEEXP10); CASE(CASEEXP11); CASE(CASEEXP12); CASE(CASEEXP13); CASE(CASEEXP14); \
    CASE(CASEEXP15); CASE(CASEEXP16); CASE(CASEEXP17); CASE(CASEEXP18); CASE(CASEEXP19); CASE(CASEEXP20); CASE(CASEEXP21); \
    CASE(CASEEXP22); CASE(CASEEXP23);} 

#define WITH22(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
    CASEEXP9, CASEEXP10, CASEEXP11, CASEEXP12, CASEEXP13, CASEEXP14, CASEEXP15, CASEEXP16, \
    CASEEXP17, CASEEXP18, CASEEXP19, CASEEXP20, CASEEXP21, CASEEXP22) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9); CASE(CASEEXP10); CASE(CASEEXP11); CASE(CASEEXP12); CASE(CASEEXP13); CASE(CASEEXP14); \
    CASE(CASEEXP15); CASE(CASEEXP16); CASE(CASEEXP17); CASE(CASEEXP18); CASE(CASEEXP19); CASE(CASEEXP20); CASE(CASEEXP21); \
    CASE(CASEEXP22);} 

#define WITH21(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
    CASEEXP9, CASEEXP10, CASEEXP11, CASEEXP12, CASEEXP13, CASEEXP14, CASEEXP15, CASEEXP16, \
    CASEEXP17, CASEEXP18, CASEEXP19, CASEEXP20, CASEEXP21) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9); CASE(CASEEXP10); CASE(CASEEXP11); CASE(CASEEXP12); CASE(CASEEXP13); CASE(CASEEXP14); \
    CASE(CASEEXP15); CASE(CASEEXP16); CASE(CASEEXP17); CASE(CASEEXP18); CASE(CASEEXP19); CASE(CASEEXP20); CASE(CASEEXP21); }

#define WITH20(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
    CASEEXP9, CASEEXP10, CASEEXP11, CASEEXP12, CASEEXP13, CASEEXP14, CASEEXP15, CASEEXP16, \
    CASEEXP17, CASEEXP18, CASEEXP19, CASEEXP20) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9); CASE(CASEEXP10); CASE(CASEEXP11); CASE(CASEEXP12); CASE(CASEEXP13); CASE(CASEEXP14); \
    CASE(CASEEXP15); CASE(CASEEXP16); CASE(CASEEXP17); CASE(CASEEXP18); CASE(CASEEXP19); CASE(CASEEXP20);}

#define WITH19(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
    CASEEXP9, CASEEXP10, CASEEXP11, CASEEXP12, CASEEXP13, CASEEXP14, CASEEXP15, CASEEXP16, \
    CASEEXP17, CASEEXP18, CASEEXP19) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9); CASE(CASEEXP10); CASE(CASEEXP11); CASE(CASEEXP12); CASE(CASEEXP13); CASE(CASEEXP14); \
    CASE(CASEEXP15); CASE(CASEEXP16); CASE(CASEEXP17); CASE(CASEEXP18); CASE(CASEEXP19);}

#define WITH18(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
    CASEEXP9, CASEEXP10, CASEEXP11, CASEEXP12, CASEEXP13, CASEEXP14, CASEEXP15, CASEEXP16, \
    CASEEXP17, CASEEXP18) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9); CASE(CASEEXP10); CASE(CASEEXP11); CASE(CASEEXP12); CASE(CASEEXP13); CASE(CASEEXP14); \
    CASE(CASEEXP15); CASE(CASEEXP16); CASE(CASEEXP17); CASE(CASEEXP18);}

#define WITH17(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
    CASEEXP9, CASEEXP10, CASEEXP11, CASEEXP12, CASEEXP13, CASEEXP14, CASEEXP15, CASEEXP16, \
    CASEEXP17) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9); CASE(CASEEXP10); CASE(CASEEXP11); CASE(CASEEXP12); CASE(CASEEXP13); CASE(CASEEXP14); \
    CASE(CASEEXP15); CASE(CASEEXP16); CASE(CASEEXP17);}

#define WITH16(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
    CASEEXP9, CASEEXP10, CASEEXP11, CASEEXP12, CASEEXP13, CASEEXP14, CASEEXP15, CASEEXP16) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9); CASE(CASEEXP10); CASE(CASEEXP11); CASE(CASEEXP12); CASE(CASEEXP13); CASE(CASEEXP14); \
    CASE(CASEEXP15); CASE(CASEEXP16);}

#define WITH15(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
    CASEEXP9, CASEEXP10, CASEEXP11, CASEEXP12, CASEEXP13, CASEEXP14, CASEEXP15) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9); CASE(CASEEXP10); CASE(CASEEXP11); CASE(CASEEXP12); CASE(CASEEXP13); CASE(CASEEXP14); \
    CASE(CASEEXP15);}

#define WITH14(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
    CASEEXP9, CASEEXP10, CASEEXP11, CASEEXP12, CASEEXP13, CASEEXP14) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9); CASE(CASEEXP10); CASE(CASEEXP11); CASE(CASEEXP12); CASE(CASEEXP13); CASE(CASEEXP14);}

#define WITH13(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
    CASEEXP9, CASEEXP10, CASEEXP11, CASEEXP12, CASEEXP13) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9); CASE(CASEEXP10); CASE(CASEEXP11); CASE(CASEEXP12); CASE(CASEEXP13);}

#define WITH12(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
    CASEEXP9, CASEEXP10, CASEEXP11, CASEEXP12) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9); CASE(CASEEXP10); CASE(CASEEXP11); CASE(CASEEXP12);}

#define WITH11(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
    CASEEXP9, CASEEXP10, CASEEXP11) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9); CASE(CASEEXP10); CASE(CASEEXP11); }

#define WITH10(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
    CASEEXP9, CASEEXP10) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9); CASE(CASEEXP10); }

#define WITH9(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
    CASEEXP9) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9);}

#define WITH8(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8);}

#define WITH7(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7); }

#define WITH6(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); }

#define WITH5(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); }

#define WITH4(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); }

#define WITH3(CASEEXP1, CASEEXP2, CASEEXP3) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); }

#define WITH2(CASEEXP1, CASEEXP2) ) { CASE(CASEEXP1); CASE(CASEEXP2); }

#define WITH1(CASEEXP) ) { CASE(CASEEXP); }

#define GET_WITH(_A1, _A2, _A3, _A4, _A5, _A6, _A7, _A8, \
    _A9, _A10, _A11, _A12, _A13, _A14, _A15, _A16, _A17, \
    _A18, _A19, _A20, _A21, _A22, _A23, _A24, _A25, \
    _A26, _A27, _A28, _A29, _A30, _A31, _A32, WITH_MACRO,...) \
    WITH_MACRO

#define WITH(...) \
    GET_WITH(__VA_ARGS__, WITH32, WITH31, WITH30, WITH29, WITH28, WITH27, WITH26, WITH25, WITH24, \
    WITH23, WITH22, WITH21, WITH20, WITH19, WITH18, WITH17, WITH16, \
    WITH15, WITH14, WITH13, WITH12, WITH11, WITH10, WITH9, WITH8, \
    WITH7, WITH6, WITH5, WITH4, WITH3, WITH2, WITH1)(__VA_ARGS__)

#endif
