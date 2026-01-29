#pragma once

#include "protocol/session.h"
#include "internal/state_machine.h"

// Internal session struct
struct proto_session {
    proto_role_t role;
    proto_session_state_t pstate;
    proto_internal_state_t istate;
};
