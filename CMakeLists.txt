cmake_minimum_required(VERSION 3.15)

project(litmath VERSION 1.0.0 LANGUAGES CXX)

add_library(litmath INTERFACE)

target_include_directories(litmath INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    option(LIT_MATH_DEV_TOOL "Enable dev tools" ON)
endif()

if(LIT_MATH_DEV_TOOL)
    # TESTS
    enable_testing()
    add_subdirectory(test)

    # CLANG-FORMAT
    find_program(CLANG_FORMAT clang-format-21 REQUIRED)
    file(GLOB_RECURSE LIT_MATH_FORMAT_SRC CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
        # ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp
    )
    add_custom_target(format-fix
        COMMAND ${CLANG_FORMAT}
                -style=file
                -i
                ${LIT_MATH_FORMAT_SRC}
        COMMENT "Formatting litmath"
    )
    add_custom_target(format-check
        COMMAND ${CLANG_FORMAT}
                -style=file
                --dry-run
                --Werror
                ${LIT_MATH_FORMAT_SRC}
        COMMENT "Checking formatting"
    )

    # CLANG-TIDY
    find_program(CLANG_TIDY clang-tidy-21 REQUIRED)
    set(CLANG_TIDY_COMMAND 
        ${CLANG_TIDY} 
        "-config-file=${CMAKE_CURRENT_SOURCE_DIR}/.clang-tidy"
    )
    add_custom_target(tidy
        COMMAND ${CLANG_TIDY}
                -p ${CMAKE_BINARY_DIR}
                -config-file=${CMAKE_CURRENT_SOURCE_DIR}/.clang-tidy
                ${LIT_MATH_FORMAT_SRC}
        COMMENT "Running clang-tidy"
    )
endif()
