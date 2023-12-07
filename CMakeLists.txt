cmake_minimum_required(VERSION 3.22.1)

project(
  coding-challenges
  DESCRIPTION "Solutions to the Coding Challenges."
  HOMEPAGE_URL "https://github.com/ardabbour/coding-challenges"
  LANGUAGES CXX)

include(CTest)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

if(CMAKE_BUILD_TYPE MATCHES "Debug"
   OR CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo"
   OR BUILD_TESTING)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Wdeprecated)
endif()

if(BUILD_TESTING)
  find_program(CPPCHECK_FOUND cppcheck)
  if(CPPCHECK_FOUND)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/cppcheck)
    add_test(NAME test_cppcheck COMMAND cppcheck --cppcheck-build-dir=${CMAKE_CURRENT_BINARY_DIR}/cppcheck
                                        --project=${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json)
  else()
    message(WARNING "cppcheck is not found; will not run it")
  endif()
  find_program(CLANG_TIDY_FOUND clang-tidy)
  if(CLANG_TIDY_FOUND)
    add_test(NAME test_clang-tidy COMMAND run-clang-tidy -p=${CMAKE_CURRENT_BINARY_DIR}
                                          -config-file=${CMAKE_CURRENT_SOURCE_DIR}/.clang-tidy)
  else()
    message(WARNING "clang-tidy is not found; will not run it")
  endif()
endif()

add_subdirectory(001-wc-tool)
