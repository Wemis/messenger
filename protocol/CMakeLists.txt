add_library(messenger_protocol
    src/session.c
    src/state_machine.c
)

target_include_directories(messenger_protocol
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(messenger_core PRIVATE -Wall -Wextra -Werror)
