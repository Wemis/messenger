#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "core/device.h"

static void test_new_device_ok() {
    Device d = {0};

    const uint8_t master_key[] = {
        0x4a, 0x07, 0xb8, 0xdb, 0xd8, 0xaf, 0x46, 0xf2,
        0x8a, 0x2a, 0xe0, 0xb9, 0xd7, 0x33, 0x6d, 0x17,
        0x3d, 0xfd, 0xee, 0xdc, 0x46, 0x8d, 0x00, 0x6c,
        0xc0, 0x2a, 0xc7, 0x70, 0x55, 0x43, 0x6f, 0xad
    };

    const char *name = "Google Pixel 10 Pro";
    
    result_t r = new_device(&d, master_key, name);

    print_message("\n");
    for (int i = 0; i < 32; i++) {
        print_message("%02x", d.device_root_secret[i]);
    }
    print_message("\n");
    for (int i = 0; i < 32; i++) {
        print_message("%02x", d.id[i]);
    }
    print_message("\n\n");

    assert_int_equal(r, OK);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_new_device_ok)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
