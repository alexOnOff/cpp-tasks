project(Threads)

add_executable(threads
    src/main.cpp
)

target_include_directories(oop
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)