
#define MATCH switch(

#define CASE_NONE() 

#define MATCH_CASE(CASE_EXP) 

#define GET_CASE(_A1, CASE_MACRO,...) CASE_MACRO

#define CASE(...) GET_PTR_UNWRAP(__VA_ARGS__, MATCH_CASE, CASE_NONE)(__VA_ARGS__)


#define WITH32(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, \
     CASEEXP9, CASEEXP10, CASEEXP11, CASEEXP12, CASEEXP13, CASEEXP14, CASEEXP15, CASEEXP16, \
     CASEEXP17, CASEEXP18, CASEEXP19, CASEEXP20, CASEEXP21, CASEEXP22, CASEEXP23, CASEEXP24, \
     CASEEXP25, CASEEXP26, CASEEXP27, CASEEXP28, CASEEXP29, CASEEXP30, CASEEXP31, CASEEXP32) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
        CASE(CASEEXP8); CASE(CASEEXP9)}

#define WITH9(CASEEXP1, CASEEXP2, CASEEXP3, CASEEXP4, CASEEXP5, CASEEXP6, CASEEXP7, CASEEXP8, CASEEXP9) ) \
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEEXP3); CASE(CASEXP4); CASE(CASEEXP5); CASE(CASEEXP6); CASE(CASEEXP7);\
    CASE(CASEEXP8); CASE(CASEEXP9)}

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
    { CASE(CASEEXP1); CASE(CASEEXP2); CASE(CASEXP3); }

#define WITH2(CASEEXP1, CASEEXP2) ) { CASE(CASEEXP1); CASE(CASEEXP2); }

#define WITH1(CASEEXP) ) { CASE(CASEEXP) }
/*_A5, _A6, _A7, _A8, _A9, _A10, _A11, _A12, _A13, _A14, _A15, _A16,*/
#define GET_WITH(_A1, _A2, _A3, _A4,  WITH_MACRO,...) WITH_MACRO

#define WITH(...) GET_WITH(__VA_ARGS__, WITH4, WITH3, WITH2, WITH1)(__VA_ARGS__)

