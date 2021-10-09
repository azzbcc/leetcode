cmake_minimum_required(VERSION 3.10)
project(leetcode C)

set(CMAKE_C_STANDARD 99)

# 定义公共依赖库
set(COMMON_LIBRARIES common m pthread)

# 使用pkg-config检查check依赖
find_package(PkgConfig REQUIRED)
pkg_check_modules(CHECK REQUIRED check)
list(APPEND COMMON_LIBRARIES ${CHECK_LIBRARIES})

# 宏定义 加载目录下所有程序
macro(DIR_PROGRAMS _regexp)
    set(separator "/")
    set(root ${CMAKE_CURRENT_SOURCE_DIR})
    file(GLOB_RECURSE children RELATIVE ${root} *suites.c)

    if (${ARGC} GREATER 1)
        set(prefix ${ARGV1})
    else ()
        string(REGEX REPLACE ".*/(.*)" "\\1" folder ${CMAKE_CURRENT_SOURCE_DIR})
        set(prefix "${folder}_")
    endif ()

    foreach (child ${children})
        string(REGEX REPLACE "(.*)/suites.c" "\\1" folder ${child})
        string(REGEX REPLACE ".*/(.*)" "\\1" folder ${folder})
        if (NOT folder MATCHES ${_regexp})
            continue()
        endif ()
        set(program_name ${prefix}${folder})
        add_executable(${program_name} ${child})
        target_compile_definitions(${program_name} PRIVATE -DPROGRAM="${program_name}")
        target_link_libraries(${program_name} ${COMMON_LIBRARIES} ${${folder}_libraries})

        add_test(NAME ${program_name} COMMAND ${program_name})
    endforeach (child)
endmacro()

# memory check
option(ENABLE_MEMORY_CHECK "Enable Memory Leak Check." OFF)
if (ENABLE_MEMORY_CHECK)
    message("Enable Memory Leak Check.")
    add_definitions(-DENABLE_MEMORY_CHECK)
endif (ENABLE_MEMORY_CHECK)

# 公共头文件夹
include_directories(common)

include(CTest)

add_library(main SHARED ${CMAKE_CURRENT_SOURCE_DIR}/main.c)
list(APPEND COMMON_LIBRARIES main)

dir_programs(demo "")
add_subdirectory(common)
add_subdirectory(base)
add_subdirectory(interview)
add_subdirectory(lcp)
add_subdirectory(offer)