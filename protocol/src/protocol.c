#include <stdlib.h>

#include "protocol/protocol.h"
#include "internal/protocol.h"
#include "internal/fsm.h"

proto_session_t *protocol_session_create(const proto_role_t role,
                                         const proto_callbacks_t cb,
                                         void *user_ctx) {
    proto_session_t *session = malloc(sizeof(struct proto_session));
    if (!session || !user_ctx) return NULL;

    *session = (proto_session_t){
        .role = role,
        .istate = PS_INIT,
        .pstate = PROTO_SESSION_CREATED,
        .fsm_table = (role == PROTO_ROLE_CLIENT)
            ? client_fsm : server_fsm,
        .fsm_len = (role == PROTO_ROLE_CLIENT)
            ? client_fsm_table_len : server_fsm_table_len,
        .cb = cb,
        .user_ctx = user_ctx
    };
    
    return session;
}

void protocol_session_start(proto_session_t *session) {
    //
}

void protocol_session_close(proto_session_t *session) {
    session_close(session, NULL);
}

void protocol_session_destroy(proto_session_t *session) {
    free(session);
}

int session_close(proto_session_t *session, const void *event_data) {
    //
}

int protocol_send_hello(proto_session_t *session,
                        const void *event_data) {
    //
}

int protocol_send_hello_ack(proto_session_t *session,
                        const void *event_data) {
    //
}

int protocol_process_hello(proto_session_t *session,
                        const void *event_data) {
    //
}

int protocol_process_hello_ack(proto_session_t *session,
                        const void *event_data) {
    //
}
