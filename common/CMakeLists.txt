add_library(common SHARED print.c)

add_library(23_tree SHARED 23_tree.c)
target_link_libraries(23_tree common)

add_library(234_tree SHARED 234_tree.c)
target_link_libraries(234_tree common)

add_library(avl_tree SHARED avl_tree.c)
target_link_libraries(avl_tree common)

add_library(list SHARED list.c)
target_link_libraries(list common)

add_library(rb_tree SHARED rb_tree.c)
target_link_libraries(rb_tree common)

add_library(tree SHARED tree.c)
target_link_libraries(tree common)

add_executable(test_common suites.c)
target_compile_definitions(test_common PRIVATE -DPROGRAM="test_common")
target_link_libraries(test_common ${COMMON_LIBRARIES})
target_link_libraries(test_common 23_tree)
target_link_libraries(test_common 234_tree)
target_link_libraries(test_common avl_tree)
target_link_libraries(test_common list)
target_link_libraries(test_common rb_tree)
target_link_libraries(test_common tree)