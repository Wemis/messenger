#include <sodium/randombytes.h>
#include <sodium/core.h>

#include "crypto/random.h"

result_t random_bytes(uint8_t *buf, const size_t size) {
    if (sodium_init() < 0) {
        return CRYPTO_ERR;
    }

    randombytes_buf(buf, size);

    return OK;
}
