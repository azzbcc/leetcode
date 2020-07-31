cmake_minimum_required(VERSION 3.18)
project(leetcode C)

set(CMAKE_C_STANDARD 99)

# 使用pkg-config检查check依赖
find_package(PkgConfig REQUIRED)
pkg_check_modules(CHECK REQUIRED check)

# 宏定义 加载目录下所有程序
macro(DIR_PROGRAMS _regexp)
    set(separator "/")
    set(root ${CMAKE_CURRENT_SOURCE_DIR})
    file(GLOB children RELATIVE ${root} *)
    foreach(child ${children})
        set(absolute_dir ${root}${separator}${child})
        if(NOT IS_DIRECTORY ${absolute_dir})
            continue()
        endif()
        if(NOT child MATCHES ${_regexp})
            continue()
        endif()
        string(REGEX REPLACE ".*/(.*)" "\\1" folder ${CMAKE_CURRENT_SOURCE_DIR})
        add_executable(${folder}_${child} ${CMAKE_SOURCE_DIR}${separator}main.c ${child}/suites.c)
        target_compile_definitions(${folder}_${child} PRIVATE -DPROGRAM="${folder}${separator}${child}")
        target_link_libraries(${folder}_${child} ${CHECK_LIBRARIES})
    endforeach(child)
endmacro()

dir_programs(demo)
add_subdirectory(base)
add_subdirectory(lcp)