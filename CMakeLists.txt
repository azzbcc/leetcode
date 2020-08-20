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

    if (${ARGC} GREATER 1)
        set(prefix ${ARGV1})
    else()
        string(REGEX REPLACE ".*/(.*)" "\\1" folder ${CMAKE_CURRENT_SOURCE_DIR})
        set(prefix "${folder}_")
    endif()

    foreach(child ${children})
        set(program_name ${prefix}${child})
        if(NOT IS_DIRECTORY ${root}${separator}${child})
            continue()
        endif()
        if(NOT child MATCHES ${_regexp})
            continue()
        endif()
        add_executable(${program_name} ${CMAKE_SOURCE_DIR}${separator}main.c ${child}/suites.c)
        target_compile_definitions(${program_name} PRIVATE -DPROGRAM="${program_name}")
        target_link_libraries(${program_name} ${CHECK_LIBRARIES})

        add_test(NAME ${program_name} COMMAND ${program_name})
    endforeach(child)
endmacro()

# 公共头文件夹
include_directories(common)

enable_testing()

dir_programs(demo "")
add_subdirectory(common)
add_subdirectory(base)
add_subdirectory(interview)
add_subdirectory(lcp)