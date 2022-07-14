#include "zic.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

DEFINE_ERROR(ERR_INVARG, 10);
DEFINE_ERROR_MSG(ERR_TOO_LONG_STRING, 11, "Too long string");

result file_io(int argc, char **argv) {
    FILE *fp = NULL;
    char ch;
    ZIC_RESULT_INIT();

    if (argc < 2) {
        ERROR(ERR_INVARG);
    }

    UNWRAP_PTR(fp = fopen(argv[1], "r"));

    ch = fgetc(fp);
    TRY_NEG(fputc(ch, stdout), DO_CLEAN(cl_fp));
	fputc('\n', stdout);
	
    CLEANUP(cl_fp, fclose(fp))
    ZIC_RETURN_RESULT()
}

result string_op(int argc, char **argv) {
    ZIC_RESULT_INIT();
    char *buf = NULL;

    if (argc < 2) {
        ERROR(ERR_INVARG);
    }

    puts("Guess my number (0-9)");

    UNWRAP_PTR(buf = calloc(sizeof(*buf), 2));
    TRY_PTR(fgets(buf, 2, stdin), DO_CLEAN_ALL());
	
    if (strcmp(buf, "7")) {
		PRINT_TO_STDERR("Incorrect\n");
        DO_CLEAN_ALL();
    }

    puts("Right!");

    CLEANUP_ALL(free(buf));
    ZIC_RETURN_RESULT();
}

int main(int argc, char **argv) DEF
    TRY(file_io(argc, argv), CATCH(ERR_INVARG, PRINT_ERR("Invalid argument!"));
        CATCH_SYS());

    TRY(string_op(argc, argv),
        CATCH(ERR_INVARG, PRINT_ERR("Invalid argument!"); CATCH_SYS()));
END
