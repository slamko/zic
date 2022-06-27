#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "zic.h"

result return_ok() {
	ZIC_RESULT_INIT();

	if (RES_IS_OK()) {
		RET_OK();
	}

	FAIL();
}

Test(Result, ReturnOk) {
	result r = return_ok();
	cr_assert(eq(r, OK));
}

Test(DefineError, ReturnError) {
	DEFINE_ERROR(ERR_SOME_ERR, 5);
	ZIC_RESULT_INIT();
	ZIC_RESULT = ERR_SOME_ERR;

	switch (ZIC_RESULT) {
	case ERR_SOME_ERR:
		break;
	default:
		cr_fail("Should be SOME_ERR");
	}
}

Test(DefineError, CheckErrorMsg) {
	char *error_msg = "error occured";
	DEFINE_ERROR_MSG(ERR_WITH_MSG, 6, error_msg);
	cr_assert(not(strcmp(ERR_TO_STR(ERR_WITH_MSG), error_msg)));
}


