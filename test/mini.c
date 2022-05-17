#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define MINI_ZIC

#include "zic.h"
#include "ptrunwrap.h"
#include "matchwith.h"

DEFINE_ERROR(ERR_INVARG, 10)

DEFINE_ERROR_MSG(ERR_TO_LONG_STR, 11, "to long string")

result
defer_close_file(int argc, char **argv) {
    ZIC_PTR_UNWRAP_INIT()

    char file[] = "file1";
    FILE *fp;
    char ch;

    fp = PTR_UNWRAP (fopen(file, "r"))

    printf("%p\n", fp);

    ch = fgetc(fp);
    UNWRAP_NEG (fputc(ch, stdout))
}

result 
some(int arg) {
    printf("%d", arg);

    RET_OK()
}


result
defer_free_t(int argc, char **argv) {
    char *str = NULL;
    FILE *fp = NULL;

    ZIC_RESULT_INIT()
    ZIC_PTR_UNWRAP_INIT()

    fp = PTR_UNWRAP (fopen("file1", "r"))

    str = PTR_UNWRAP (calloc(10, sizeof(*str)), close_file)

    if (argc != 2) {
        ERROR_CLEANUP(ERR_INVARG)
    }

    if (strnlen(argv[1], 10) >= 10) {
        ERROR_CLEANUP(ERR_TO_LONG_STR)
    }
    
    strcpy(str, argv[1]);
    UNWRAP_CLEANUP (puts(str))

    CLEANUP(
        free_str: free(str);
        close_file: fclose(fp)
    )
}

int
main(int argc, char **argv) {
    ZIC_RESULT_INIT()

    TRY (defer_free_t(argc, argv), 
        CATCH_ERR(ERR_TO_LONG_STR) 
        CATCH(ERR_INVARG, 
            PRINT_ERR("NEPRAVILNOE ARGUMENT")
        )
        CATCH_SYS()
    )

    RETURN_ZIC_RESULT()
}
