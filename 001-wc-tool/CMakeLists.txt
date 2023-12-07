add_library(ccwc_lib STATIC lib.cpp)
target_include_directories(ccwc_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(ccwc main.cpp)
add_dependencies(ccwc ccwc_lib)
target_link_libraries(ccwc ccwc_lib)

install(TARGETS ccwc RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

if(BUILD_TESTING)
  add_executable(test_ccwc test.cpp)
  add_dependencies(test_ccwc ccwc_lib)
  target_link_libraries(test_ccwc ccwc_lib)
  add_test(NAME test_ccwc COMMAND ${CMAKE_CURRENT_BINARY_DIR}/ccwc ${CMAKE_CURRENT_SOURCE_DIR}/test.txt)
endif()
