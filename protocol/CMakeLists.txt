add_library(messenger_protocol
    src/protocol.c
    src/fsm.c
)

target_include_directories(messenger_protocol
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(messenger_protocol
    PRIVATE
        messenger_shared
)

target_compile_options(messenger_core PRIVATE -Wall -Wextra -Werror)
