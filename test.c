#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "zic.h"

result
defer_close_file(int argc, char **argv) DEF
    char file[] = "file1";
    FILE *fp;
    char ch;

    fp = fopen(file, "r");
    printf("%p\n", fp);

    ch = fgetc(fp);
    fputc(ch, stdout);
    FAIL()
END


result
defer_free_t(int argc, char **argv) DEF 
    char *str = NULL;
    FILE *fp = NULL;

    fp = PTR_UNWRAP (fopen("file1", "r"))

    str = PTR_UNWRAP (calloc(10, sizeof(*str)), close_file)

    if (argc != 2) {
        ERROR(ERR_USER, free_str)
    }

    if (strnlen(argv[1], 10) >= 10) {
        ERROR(ERR_USER, free_str)
    }

    UNWRAP_PTR(strcpy(str, argv[1]));
    printf("%s\n", str);

    CLEANUP(free_str, free(str))
    CLEANUP(close_file, fclose(fp))
END

int
main(int argc, char **argv) DEF
    return defer_close_file(argc, argv);
END
