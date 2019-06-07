cmake_minimum_required (VERSION 3.10 )
project (threadpool)

find_package (Threads)

add_executable (pool test.cc threadspool.cc )

target_link_libraries (pool ${CMAKE_THREAD_LIBS_INIT})
