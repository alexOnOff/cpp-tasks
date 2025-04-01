project(OOP)

add_executable(oop
    src/main.cpp
    src/Parent.cpp
    src/Child.cpp
    src/AnotherChild.cpp
    src/StepChild.cpp
)

target_include_directories(oop
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)