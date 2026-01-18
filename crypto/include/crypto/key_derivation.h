#pragma once

#include <stddef.h>
#include <stdint.h>

#include "shared/result.h"
#include "crypto/identity.h"

result_t key_expand(
    uint8_t *out, size_t out_len, const uint8_t *context,
    size_t context_len, const uint8_t master_key[identity_MASTERKEYBYTES]
);
