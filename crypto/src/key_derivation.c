#include <sodium/crypto_kdf_hkdf_sha256.h>

#include "crypto/key_derivation.h"

result_t key_expand(
    uint8_t *out, size_t out_len, const uint8_t *context,
    size_t context_len, const uint8_t master_key[identity_MASTERKEYBYTES]
){
    if (sodium_init() < 0) {
        return CRYPTO_ERR;
    }

    uint8_t prk[crypto_kdf_hkdf_sha256_KEYBYTES];

    crypto_kdf_hkdf_sha256_extract(prk, NULL, 0, master_key, identity_MASTERKEYBYTES);
    crypto_kdf_hkdf_sha256_expand(out, out_len, (char*)context, context_len, prk);

    return OK;
}
