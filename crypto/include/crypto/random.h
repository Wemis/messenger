#pragma once

#include <stddef.h>
#include <stdint.h>

#include "shared/result.h"

result_t random_bytes(uint8_t *buf, size_t size);
