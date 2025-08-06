project(Graph)

add_executable(graph
    src/main.cpp
    src/Graph.cpp
    src/DSU.cpp
  )

target_include_directories(graph
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)