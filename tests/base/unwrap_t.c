#include <criterion/criterion.h>
#include <criterion/internal/new_asserts.h>
#include <criterion/new/assert.h>
#include "zic.h"

result unwrap_final() {
	ZIC_RESULT_INIT();
	ZIC_RESULT = FAIL;

	UNWRAP(ZIC_RESULT);
	RET_OK();
}

DEFINE_ERROR(ERR_INVARG, 5);

result unwrap_error() {
	ZIC_RESULT_INIT();
	ZIC_RESULT = ERR_INVARG;

	UNWRAP(ZIC_RESULT);
	RET_OK();
}

result unwrap_ok() {
	ZIC_RESULT_INIT();

	UNWRAP(ZIC_RESULT);
	FAIL();
}

Test(Unwrap, Final) {
	result res = unwrap_final();
	cr_expect(eq(res, FAIL));

	result res_err = unwrap_error();
	cr_expect(eq(res_err, ERR_INVARG));

	result res_ok= unwrap_ok();
	cr_expect(eq(res, FAIL));
}

result unwrap_clean_final() {
	ZIC_RESULT_INIT();
	ZIC_RESULT = FAIL;

	UNWRAP_DO_CLEAN_ALL(ZIC_RESULT);
	cr_fail("resource leak");
	CLEANUP_ALL();
	ZIC_RETURN_RESULT();
}

result unwrap_clean_ok() {
	ZIC_RESULT_INIT();

	UNWRAP_DO_CLEAN_ALL(ZIC_RESULT);
	ZIC_RESULT = FAIL;
	CLEANUP_ALL();
	ZIC_RETURN_RESULT();
}

Test(Unwrap, Clean) {
	result res = unwrap_clean_final();
	cr_expect(eq(res, FAIL));

	result res_ok = unwrap_clean_ok();
	cr_expect(eq(res_ok, FAIL));

}
