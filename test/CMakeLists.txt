include(FetchContent)
FetchContent_Declare(
googletest
GIT_REPOSITORY https://github.com/google/googletest.git
GIT_TAG v1.15.2
)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SOURCES
    add_test.cpp
    subtract_test.cpp
    multiply_test.cpp
    divide_test.cpp
    pow_test.cpp
    factorial_test.cpp
)

add_executable(unit_tests 
  ${SOURCES}
)

set(DEBUG_FLAGS 
    -Wall -Wextra -Wpedantic 
    -Wconversion -Wsign-conversion 
    -Wold-style-cast -Werror -g
    -fsanitize=address,undefined
)

target_compile_options(unit_tests PRIVATE
    $<$<CONFIG:Debug>:${DEBUG_FLAGS}>
    $<$<CONFIG:Release>:-O2>
)

target_link_options(unit_tests PRIVATE
    $<$<CONFIG:Debug>:-fsanitize=address,undefined>
)

target_link_libraries(unit_tests PRIVATE
    GTest::gtest_main
    litmath
)

include(GoogleTest)
gtest_discover_tests(unit_tests)
