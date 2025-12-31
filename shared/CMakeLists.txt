add_library(messenger_shared STATIC
    src/base58.c
)

target_include_directories(messenger_shared
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(messenger_shared
    PUBLIC c_std_11
)

target_compile_options(messenger_shared
    PRIVATE -Wall -Wextra -Wpedantic
)
