#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/new/assert.h>
#include <criterion/assert.h>
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
