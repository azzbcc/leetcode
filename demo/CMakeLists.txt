project(demo C)

add_executable(demo suites.c ${CMAKE_SOURCE_DIR}/main.c)
target_compile_definitions(demo PRIVATE -DPROGRAM="demo")
target_link_libraries(demo check)