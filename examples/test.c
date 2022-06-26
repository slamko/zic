#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "zic.h"

DEFINE_ERROR(ERR_INVARG, 10)

result
defer_close_file(int argc, char **argv) DEF
    char file[] = "file1";
    FILE *fp;
    char ch;

    fp = PTR_UNWRAP_CLEAN (fopen(file, "r"))
    DEFER1_FINAL(fclose(fp))

    printf("%p\n", fp);

    ch = fgetc(fp);
    UNWRAP_NEG (fputc(ch, stdout))
END


result
defer_free_t(int argc, char **argv) DEF
    char *str = NULL;
    FILE *fp = NULL;

    fp = PTR_UNWRAP_CLEAN (fopen("file1", "r"))
    DEFER1(close_file, fclose(fp))

    str = PTR_UNWRAP (calloc(10, sizeof(*str)), close_file)
    DEFER2_FINAL(free(str))

    if (argc != 2) {
        ERROR(ERR_INVARG)
    }

    if (strnlen(argv[1], 10) >= 10) {
        ERROR(ERR_USER)
    }
    
    strcpy(str, argv[1]);
    UNWRAP (puts(str))
END

int
main(int argc, char **argv) DEF
    result res = defer_free_t(argc, argv); 
    MATCH res WITH (
        OK: return 24,
        ERR_SYS: return OK,
        ERR_USER: return 67
    )
END_CLEAN
