add_library(list SHARED list.c)
add_library(tree SHARED tree.c)

add_executable(test_common ${CMAKE_SOURCE_DIR}/main.c suites.c)
target_compile_definitions(test_common PRIVATE -DPROGRAM="test_common")
target_link_libraries(test_common ${CHECK_LIBRARIES})
target_link_libraries(test_common list)
target_link_libraries(test_common tree)