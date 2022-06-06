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

result
defer_close_file(int argc, char **argv) {
    ZIC_RESULT_INIT()

    char file[] = "file1";
    FILE *fp;
    char ch;

    UNWRAP_PTR (fp = fopen(file, "r"))

    printf("%p\n", fp);

    ch = fgetc(fp);
    TRY (fputc(ch, stdout), DO_CLEAN(cl_fp))
		CLEANUP(cl_fp, fclose(fp))
		ZIC_RETURN_RESULT()
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


#define CLEAN(LABEL) UNWRAP_GOTO(ZIC_RES_VAR_NAME, LABEL)

result some() {
  char soup = malloc(69);
  ZIC_RESULT_INIT()
  
  strncpy(soup, "privet mam", 69);
  TRY (strcmp(soup, "alle mama"),
	   CLEAN(cl_some)
  )

	CLEANUP(free(soup); cl_some: printf("cleaned"))
}


int
main(int argc, char **argv) {
    ZIC_RESULT_INIT()

    TRY (defer_free_t(argc, argv), 
        CATCH(ERR_INVARG, 
            FORMAT_ERR("NEPRAVILNOE ARGUMENT")
        )
        CATCH_SYS()
    )

    ZIC_RETURN_RESULT()
}
