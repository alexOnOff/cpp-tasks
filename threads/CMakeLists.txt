project(Threads)

add_executable(threads
    src/main.cpp
    src/Waiter.cpp
    src/Counter.cpp
    src/QueueTask.cpp
    src/ArraySumTask.cpp
    src/ParallelSortTask.cpp
)

target_include_directories(threads
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)