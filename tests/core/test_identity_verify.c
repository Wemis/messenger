#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <sys/select.h>

#include "core/account.h"
#include "shared/result.h"

static void test_username_verify_integrity_ok() {
    const char *username = "alice#DGfAX29q1dhytj";
    result_t r = account_username_verify_integrity(username);

    assert_int_equal(r, OK);
}

static void test_username_verify_integrity_null_username() {
    const char *username = NULL;
    result_t r = account_username_verify_integrity(username);

    assert_int_equal(r, CORE_ACCOUNT_USERNAME_CORRUPTED);
}

static void test_username_verify_integrity_invalid_size() {
    const char *username_long = "alice#DGfAX29q1dhytjooooooooooooooooo";
    const char *username_empty = "";

    result_t r_long = account_username_verify_integrity(username_long);
    result_t r_empty = account_username_verify_integrity(username_empty);

    assert_int_equal(r_long, CORE_ACCOUNT_USERNAME_INVALID_SIZE);
    assert_int_equal(r_empty, CORE_ACCOUNT_USERNAME_INVALID_SIZE);
}

static void test_username_verify_integrity_missing_separator() {
    const char *username = "aliceDGfAX29q1dhytj";
    result_t r = account_username_verify_integrity(username);

    assert_int_equal(r, CORE_ACCOUNT_USERNAME_CORRUPTED);
}

static void test_username_verify_integrity_invalid_prefix_size() {
    const char *username_long = "aliceeeeeeeeeeeeeeeee#DGfAX29q1dhytj";
    const char *username_short = "#DGfAX29q1dhytj";

    result_t r_long = account_username_verify_integrity(username_long);
    result_t r_short = account_username_verify_integrity(username_short);

    assert_int_equal(r_long, CORE_ACCOUNT_USERNAME_INVALID_SIZE);
    assert_int_equal(r_short, CORE_ACCOUNT_USERNAME_INVALID_SIZE);
}

static void test_username_verify_integrity_invalid_symbol() {
    const char *username = "@alice#DGfAX29q1dhytj";
    result_t r = account_username_verify_integrity(username);

    assert_int_equal(r, CORE_ACCOUNT_USERNAME_UNSUPPORTED_SYMBOL);
}

static void test_username_verify_integrity_invalid_checksum() {
    const char *username = "alice#DGfAX29q1dhytt";
    result_t r = account_username_verify_integrity(username);

    assert_int_equal(r, CORE_ACCOUNT_USERNAME_INVALID_CHECKSUM);
}

static void test_username_verify_authenticity_ok() {
    const char *username = "alice#9MLiobrvhQGT84";

    const uint8_t user_id[account_USERIDBYTES] = {
        0x94, 0xa3, 0x0a, 0xa4, 0xd2, 0x53, 0x97, 0xfb,
        0x39, 0x04, 0x99, 0x4a, 0xb7, 0xb8, 0x19, 0xfa,
        0x71, 0xfa, 0x1f, 0x5a, 0x2f, 0x49, 0x46, 0x33,
        0x79, 0xd4, 0xcb, 0xe3, 0x42, 0x63, 0x1b, 0x51
    };

    result_t r = account_username_verify_authenticity(username, user_id);

    assert_int_equal(r, OK);
}

static void test_username_verify_authenticity_corrupted_username() {
    const char *username = "aliceeee#9MLiobrvhQGT84";

    const uint8_t user_id[account_USERIDBYTES] = {
        0x94, 0xa3, 0x0a, 0xa4, 0xd2, 0x53, 0x97, 0xfb,
        0x39, 0x04, 0x99, 0x4a, 0xb7, 0xb8, 0x19, 0xfa,
        0x71, 0xfa, 0x1f, 0x5a, 0x2f, 0x49, 0x46, 0x33,
        0x79, 0xd4, 0xcb, 0xe3, 0x42, 0x63, 0x1b, 0x51
    };

    result_t r = account_username_verify_authenticity(username, user_id);

    assert_int_equal(r, CORE_ACCOUNT_USERNAME_FORGED);
}

static void test_username_verify_authenticity_forged() {
    const char *username = "alice#9MLiobrvhQGT84";

    const uint8_t user_id[account_USERIDBYTES] = {
        0x94, 0xa3, 0x0a, 0xa4, 0xd2, 0x53, 0x97, 0xfc, // <- invalid byte
        0x39, 0x04, 0x99, 0x4a, 0xb7, 0xb8, 0x19, 0xfa,
        0x71, 0xfa, 0x1f, 0x5a, 0x2f, 0x49, 0x46, 0x33,
        0x79, 0xd4, 0xcb, 0xe3, 0x42, 0x63, 0x1b, 0x51
    };

    result_t r = account_username_verify_authenticity(username, user_id);

    assert_int_equal(r, CORE_ACCOUNT_USERNAME_FORGED);
}

static void test_account_verify_ok() {
    User u = {0};

    const char *name = "Alice";
    const char *prefix = "alice";
    account_create(&u, name, prefix);

    result_t r = account_verify(&u);
    assert_int_equal(r, OK);
}

static void test_account_verify_forged() {
    User u = {0};

    const char *name = "Alice";
    const char *prefix = "alice";
    account_create(&u, name, prefix);

    u.name[0] = 'E'; // Change first character of name to 'E'

    result_t r = account_verify(&u);
    assert_int_equal(r, CORE_ACCOUNT_FORGED);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_username_verify_integrity_ok),
        cmocka_unit_test(test_username_verify_integrity_null_username),
        cmocka_unit_test(test_username_verify_integrity_invalid_size),
        cmocka_unit_test(test_username_verify_integrity_missing_separator),
        cmocka_unit_test(test_username_verify_integrity_invalid_prefix_size),
        cmocka_unit_test(test_username_verify_integrity_invalid_symbol),
        cmocka_unit_test(test_username_verify_integrity_invalid_checksum),
        cmocka_unit_test(test_username_verify_authenticity_ok),
        cmocka_unit_test(test_username_verify_authenticity_corrupted_username),
        cmocka_unit_test(test_username_verify_authenticity_forged),
        cmocka_unit_test(test_account_verify_ok),
        cmocka_unit_test(test_account_verify_forged)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
