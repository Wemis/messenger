#pragma once

// Public session states, visible for core
typedef enum {
    PROTO_SESSION_CONNECTING,
    PROTO_SESSION_AUTHENTICATING,
    PROTO_SESSION_READY,
    PROTO_SESSION_CLOSED,
    PROTO_SESSION_ERROR
} proto_session_state_t;

typedef enum {
    PROTO_ROLE_CLIENT,
    PROTO_ROLE_SERVER
} proto_role_t;

// Forward declaration session struct
// proto_session implemented in internal headers
typedef struct proto_session proto_session_t;

proto_session_t *protocol_session_create(proto_role_t role);
void protocol_session_destroy(proto_session_t *session);
