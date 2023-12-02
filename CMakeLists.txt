cmake_minimum_required(VERSION 3.16)

project(
  coding-challenges
  DESCRIPTION "Solutions to the Coding Challenges."
  HOMEPAGE_URL "https://github.com/ardabbour/coding-challenges"
  LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

if(CMAKE_BUILD_TYPE MATCHES "Debug" OR CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Wdeprecated)
endif()

option(${PROJECT}_ENABLE_TESTING "Enables testing" ON)
if(${PROJECT}_ENABLE_TESTING)
  enable_testing()
endif()
