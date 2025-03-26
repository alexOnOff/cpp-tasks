project(Algorithms)

add_executable(algorithms
    src/main.cpp
)

target_include_directories(algorithms
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)