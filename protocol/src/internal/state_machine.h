#pragma once

// Internal session states, not visible for everyone
typedef enum {
    PS_CREATED = 0,
    PS_SENT_HELLO,
    PS_WAIT_HELLO_ACK
} proto_internal_state_t;
