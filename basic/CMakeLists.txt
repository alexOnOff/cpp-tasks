project(Basic)

add_executable(basic
    src/main.cpp
    src/MemoryLeakage.cpp 
 "include/WeakPtr.h")

target_include_directories(basic
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)