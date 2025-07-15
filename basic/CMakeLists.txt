project(Basic)

add_executable(basic
    src/main.cpp
)

target_include_directories(basic
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)