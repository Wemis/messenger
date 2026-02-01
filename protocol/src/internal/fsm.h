#pragma once

#include <stddef.h>
#include <stdint.h>
#include "protocol/protocol.h"

// Internal session states, not visible for everyone
typedef enum {
    PS_INIT,
    PS_WAIT_HELLO_ACK,
    PS_READY,
    PS_ERROR
} proto_internal_state_t;

// Protocol events
typedef enum {
    EV_START,
    EV_RECV_HELLO,
    EV_RECV_HELLO_ACK,
    EV_TIMEOUT,
    EV_FATAL_ERROR
} proto_event_t;

// Action function
typedef int (*proto_action_fn)(
    proto_session_t *session,
    const void *event_data
);

// FSM transitions struct
typedef struct {
    proto_internal_state_t state;
    proto_event_t event;
    proto_action_fn action;
    proto_internal_state_t next_state;
} proto_fsm_transitions_t;

extern const proto_fsm_transitions_t client_fsm[];
extern const proto_fsm_transitions_t server_fsm[];
extern const size_t client_fsm_table_len;
extern const size_t server_fsm_table_len;

void protocol_fsm_update_state(proto_session_t *session,
                               proto_internal_state_t state);
