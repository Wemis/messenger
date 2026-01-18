#include <string.h>

#include "core/device.h"
#include "crypto/hash.h"
#include "crypto/random.h"
#include "crypto/key_derivation.h"

result_t new_device(Device *d, const uint8_t master_key[identity_MASTERKEYBYTES]) {
    if (random_bytes(d->id, device_IDBYTES) != OK) {
        return CORE_DEVICE_IMPORT_FAILED;
    }

    if (key_expand(d->device_root_secret, device_ROOTSECRETBYTES, d->id, device_IDBYTES, master_key) != OK) {
        return CORE_DEVICE_IMPORT_FAILED;
    }

    if (identity_from_master_key(d->device_root_secret, d->sk_signature, d->pk_signature, d->sk_encryption, d->pk_encryption) != OK) {
        return CORE_DEVICE_IDENTITY_IMPORT_FAILED;
    }

    uint8_t public_keys[identity_encr_PUBLICKEYBYTES + identity_sign_PUBLICKEYBYTES];
    memcpy(public_keys, d->pk_encryption, identity_encr_PUBLICKEYBYTES);
    memcpy(public_keys + identity_encr_PUBLICKEYBYTES, d->pk_signature, identity_sign_PUBLICKEYBYTES);

    uint8_t hash[hash_BYTES];
    cryptohash(hash, public_keys, identity_encr_PUBLICKEYBYTES + identity_sign_PUBLICKEYBYTES);

    cryptosign(d->keys_signature, hash, hash_BYTES, ????);
}
