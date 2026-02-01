#pragma once

#include "internal/fsm.h"

// Internal session struct
struct proto_session {
    const proto_callbacks_t cb;
    const proto_fsm_transitions_t *fsm_table; 
    void *user_ctx;
    const size_t fsm_len;
    const proto_role_t role;
    proto_session_state_t pstate;
    proto_internal_state_t istate;
};

int session_close(proto_session_t *session, const void *event_data);

int protocol_send_hello(proto_session_t *session,
                        const void *event_data);

int protocol_send_hello_ack(proto_session_t *session,
                        const void *event_data);

int protocol_process_hello(proto_session_t *session,
                        const void *event_data);

int protocol_process_hello_ack(proto_session_t *session,
                        const void *event_data);
