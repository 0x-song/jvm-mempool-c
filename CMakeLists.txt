cmake_minimum_required(VERSION 3.29)
project(jvm_mempool_c)

set(CMAKE_CXX_STANDARD 11)

include_directories("D:/Program Files/Java/jdk-8/include/")
include_directories("D:/Program Files/Java/jdk-8/include/win32")

add_library(jvm_mempool_c SHARED src/jni/com_sz_jvm_jdk_Threads.cpp include/jni/com_sz_jvm_jdk_Threads.h
        include/memory/memory_pool.h
        include/memory/memory_chunk.h
        include/memory/memory_cell.h
        src/memory/memory_pool.cpp
        src/memory/memory_chunk.cpp
        src/memory/memory_cell.cpp
        include/common.h)