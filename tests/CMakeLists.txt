find_package(cmocka REQUIRED)

function(add_messenger_test name source)
    add_executable(${name} ${source})
    target_link_libraries(${name}
        messenger_core
        messenger_shared
        messenger_crypto
        cmocka
    )
    add_test(NAME ${name} COMMAND ${name})
endfunction()

add_messenger_test(
    test_account_create
    core/test_account_create.c
)
add_messenger_test(
    test_account_import
    core/test_account_import.c
)
add_messenger_test(
    test_identity_verify
    core/test_identity_verify.c
)
add_messenger_test(
    test_sign
    crypto/test_sign.c
)
add_messenger_test(
    test_hash
    crypto/test_hash.c
)
add_messenger_test(
    test_device_new
    core/test_device_new.c
)
add_messenger_test(
    test_device_verify
    core/test_device_verify.c
)
add_messenger_test(
    test_key_derivation
    crypto/test_key_derivation.c
)
