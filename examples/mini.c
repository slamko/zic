#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MINI_ZIC

#include "matchwith.h"
#include "ptrunwrap.h"
#include "zic.h"

result some() { RET_OK(); }

/* DEFINE_ERROR(ERR_INVARG, 10); */

DEFINE_ERROR_MSG(ERR_TOO_LONG_STRING, 11, "Too long string")

result defer_close_file(int argc, char **argv) {
    ZIC_RESULT_INIT()

    char file[] = "file1";
    FILE *fp;
    char ch;

    UNWRAP_PTR(fp = fopen(file, "r"))

    printf("%p\n", fp);

    ch = fgetc(fp);
    TRY(fputc(ch, stdout), DO_CLEAN(cl_fp))
    CLEANUP(cl_fp, fclose(fp))
    ZIC_RETURN_RESULT()
}

result some(int arg) {
    printf("%d", arg);
    RET_OK()
}

result defer_free_t(int argc, char **argv) {
    char *str = NULL;
    FILE *fp = NULL;

    ZIC_RESULT_INIT();
    ZIC_PTR_UNWRAP_INIT();

    fp = PTR_UNWRAP(fopen("file1", "r"));

    if (argc != 2) {
        ERROR_DO_CLEAN(ERR_INVARG, DO_CLEAN(close_file))
    }

    if (strnlen(argv[1], 10) >= 10) {
        ERROR_DO_CLEAN(ERR_TOO_LONG_STRING, DO_CLEAN_ALL())
    }

    strcpy(str, argv[1]);
    UNWRAP_DO_CLEAN_ALL(puts(str));

    CLEANUP_ALL(free(str));

    CLEANUP(close_file, fclose(fp))
}

#define CLEAN(LABEL) UNWRAP_GOTO(ZIC_RES_VAR_NAME, LABEL)

result some() {
    char soup = malloc(69);
    ZIC_RESULT_INIT()

    strncpy(soup, "privet mam", 69);
    TRY(strcmp(soup, "alle mama"), DO_CLEAN_ALL());

    CLEANUP_ALL(free(soup));
}

int main(int argc, char **argv) {
    ZIC_RESULT_INIT()

    TRY(defer_free_t(argc, argv),
        CATCH(ERR_INVARG, FORMAT_ERR("NEPRAVILNOE ARGUMENT")) CATCH_SYS())

    ZIC_RETURN_RESULT()
}
