#pragma once

#include <stdint.h>
#include "crypto/sign.h"
#include "shared/result.h"
#include "crypto/identity.h"

#define DEVICE_NAME_MAX_LENGTH    64

#define device_IDBYTES            32
#define device_ROOTSECRETBYTES    32

typedef struct {
    uint8_t id[device_IDBYTES];
    char name[DEVICE_NAME_MAX_LENGTH];
    uint8_t device_root_secret[device_ROOTSECRETBYTES];
    uint8_t sk_signature[identity_sign_SECRETKEYBYTES];
    uint8_t pk_signature[identity_sign_PUBLICKEYBYTES];
    uint8_t sk_encryption[identity_encr_SECRETKEYBYTES];
    uint8_t pk_encryption[identity_encr_PUBLICKEYBYTES];
    uint8_t keys_signature[signature_BYTES];
} Device;

result_t new_device(Device *d, const uint8_t master_key[identity_MASTERKEYBYTES], const char *name);
result_t verify_device_identity(
    const uint8_t pk_signature[identity_sign_PUBLICKEYBYTES],
    const uint8_t pk_encryption[identity_encr_PUBLICKEYBYTES],
    const uint8_t signature[signature_BYTES],
    const uint8_t account_pk[identity_sign_PUBLICKEYBYTES]
);
