cmake_minimum_required(VERSION 3.18)
project(leetcode C)

set(CMAKE_C_STANDARD 99)

# 使用pkg-config检查check依赖
find_package(PkgConfig REQUIRED)
pkg_check_modules(CHECK REQUIRED check)

# 宏定义 获取程序目录
macro(PROGRAM_DIRS result)
    set(${result} "")
    set(root ${CMAKE_CURRENT_SOURCE_DIR})
    file(GLOB children RELATIVE ${root} *)
    foreach(child ${children})
        if(NOT IS_DIRECTORY ${root}/${child})
            continue()
        endif()
        if (child MATCHES ^[0-9]+$)
            list(APPEND ${result} ${child})
        endif()
    endforeach(child)
endmacro()

# 加载程序子目录
program_dirs(RESULT)
list(APPEND RESULT demo)

foreach(dir ${RESULT})
    add_executable(${dir} main.c ${dir}/suites.c)
    target_compile_definitions(${dir} PRIVATE -DPROGRAM="${dir}")
    target_link_libraries(${dir} ${CHECK_LIBRARIES})
endforeach()