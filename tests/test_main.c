#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "core/test_account.c"

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_account_create),
        cmocka_unit_test(test_account_import),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
