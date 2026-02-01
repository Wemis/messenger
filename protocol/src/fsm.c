#include <stddef.h>
#include <stdint.h>

#include "internal/fsm.h"
#include "internal/protocol.h"

// Client FSM transitions table
const proto_fsm_transitions_t client_fsm[] = {
    {PS_INIT, EV_START, protocol_send_hello, PS_WAIT_HELLO_ACK},
    {PS_WAIT_HELLO_ACK, EV_RECV_HELLO_ACK, protocol_process_hello_ack, PS_READY},

    {PS_READY, EV_FATAL_ERROR, session_close, PS_ERROR}
};

// Server FSM transitions table
const proto_fsm_transitions_t server_fsm[] = {
    {PS_INIT, EV_RECV_HELLO, protocol_send_hello_ack, PS_READY},

    {PS_READY, EV_FATAL_ERROR, session_close, PS_ERROR}
};

const size_t client_fsm_table_len = sizeof(client_fsm) / sizeof(client_fsm[0]);
const size_t server_fsm_table_len = sizeof(server_fsm) / sizeof(server_fsm[0]);

void protocol_fsm_update_state(proto_session_t *session, proto_internal_state_t state) {
    session->istate = state;

    switch (session->istate) {
        case PS_INIT:
        case PS_WAIT_HELLO_ACK:
            if (session->pstate != PROTO_SESSION_CONNECTING) {
                session->pstate = PROTO_SESSION_CONNECTING;
                session->cb.on_state_changed(session->pstate, session->user_ctx);
            }
        case PS_READY:
            if (session->pstate != PROTO_SESSION_READY) {
                session->pstate = PROTO_SESSION_READY;
                session->cb.on_state_changed(session->pstate, session->user_ctx);
            }
        case PS_ERROR:
            session->pstate = PROTO_SESSION_ERROR;
            session->cb.on_state_changed(session->pstate, session->user_ctx);
    }
}
