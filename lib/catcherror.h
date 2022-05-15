
#define ZIC_BASE_CATCH(ERR, ...) \
    fprintf(stderr, ERROR_PREFIX); \
    fprintf(stderr, ERR, ##__VA_ARGS__); \
    fprintf(stderr, "\n");

#ifdef FULL_API

#define CATCH_CLEAN(ERR, ...) \
    ZIC_BASE_CATCH(ERR, __VA_ARGS__) \
    FAIL_CLEAN();

#define CATCH_FINAL(ERR, ...) \
    ZIC_BASE_CATCH(ERR, __VA_ARGS__) \
    FAIL_FINAL();

#define CATCH_LABEL(ERR, LABEL, ...) \
    ZIC_BASE_CATCH(ERR, __VA_ARGS__) \
    FAIL_LABEL(LABEL);

#define CATCH(...) GET_LABEL_MACRO(__VA_ARGS__, CATCH_LABEL, CATCH_FINAL)(__VA_ARGS__)

#define CATCH_SYS_CLEAN() perror(ERROR_PREFIX); FAIL();

#define CATCH_SYS_FINAL() perror(ERROR_PREFIX); FAIL_FINAL();

#define CATCH_SYS_LABEL(LABEL) perror(ERROR_PREFIX); FAIL_CLEAN(LABEL);

#define CATCH_SYS(...) GET_LABEL_MACRO(__VA_ARGS__, CATCH_SYS_LABEL, CATCH_SYS_FINAL)(__VA_ARGS__)

#else

#define CATCH(ERR, ...) \
    fprintf(stderr, ERROR_PREFIX); \
    fprintf(stderr, ERR, ##__VA_ARGS__); \
    fprintf(stderr, "\n"); \
    FAIL();

#define CATCH_SYS() perror(ERROR_PREFIX); FAIL();
#endif