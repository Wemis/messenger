#pragma once

enum {
    PROTOCOL_CURRENT_VERSION = 1
};

// Public session states, visible for core
typedef enum {
    PROTO_SESSION_CREATED,
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

typedef struct {
    void (*on_state_changed)(
        proto_session_state_t state,
        void *user_ctx
    );
} proto_callbacks_t;

proto_session_t *protocol_session_create(const proto_role_t role,
                                         const proto_callbacks_t cb,
                                         void *user_ctx);
void protocol_session_start(proto_session_t *session);
void protocol_session_close(proto_session_t *session);
void protocol_session_destroy(proto_session_t *session);
