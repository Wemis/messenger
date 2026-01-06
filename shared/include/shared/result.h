#pragma once

typedef enum {
    OK = 0,

    // Shared
    ENCODING_BASE58_ERR,

    // Core
    CORE_ACCOUNT_CREATE_FAILED,
    CORE_ACCOUNT_IMPORT_FAILED,
    CORE_ACCOUNT_NAME_TOO_LONG,
    CORE_ACCOUNT_PREFIX_TOO_LONG,
    CORE_ACCOUNT_INVALID,
    CORE_ACCOUNT_USERNAME_FORGED,
    CORE_ACCOUNT_USERNAME_CORRUPTED,
    CORE_ACCOUNT_USERNAME_INVALID_SIZE,
    CORE_ACCOUNT_USERNAME_INVALID_CHECKSUM,
    CORE_ACCOUNT_USERNAME_UNSUPPORTED_SYMBOL,

    // Crypto
    CRYPTO_ERR,
    CRYPTO_INVALID_SIGNATURE,
    CRYPTO_AUTH_FAILED,
} result_t;


static inline const char* result_to_string(result_t err) {
    switch (err) {
        case OK:
            return "OK";
        case ENCODING_BASE58_ERR:
            return "SHARED.Base58: Encoding base58 failed";
        case CORE_ACCOUNT_CREATE_FAILED:
        case CORE_ACCOUNT_IMPORT_FAILED:
        case CORE_ACCOUNT_NAME_TOO_LONG:
        case CORE_ACCOUNT_PREFIX_TOO_LONG:
        case CORE_ACCOUNT_INVALID:
        case CORE_ACCOUNT_USERNAME_FORGED:
            return "CORE.Account: username is not authentic";
        case CORE_ACCOUNT_USERNAME_CORRUPTED:
            return "CORE.Account: username is corrupted";
        case CORE_ACCOUNT_USERNAME_INVALID_SIZE:
            return "CORE.Account: username size is invalid";
        case CORE_ACCOUNT_USERNAME_INVALID_CHECKSUM:
            return "CORE.Account: invalid username checksum";
        case CORE_ACCOUNT_USERNAME_UNSUPPORTED_SYMBOL:
            return "CORE.Account: username contains unsupported symbol";

        // Crypto
        case CRYPTO_ERR:
        case CRYPTO_INVALID_SIGNATURE:
        case CRYPTO_AUTH_FAILED:
            return "CRYPTO: authentication failed";
    }

    return "Unknown error";
}
