#include <stdlib.h>

#include "protocol/session.h"
#include "internal/session.h"

proto_session_t *protocol_session_create(proto_role_t role) {
    proto_session_t *session = malloc(sizeof(struct proto_session));
    session->role = role;
        
    return session;
}

void protocol_session_destroy(proto_session_t *session) {
    free(session);
}
