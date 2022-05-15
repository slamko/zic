
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
