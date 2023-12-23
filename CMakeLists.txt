cmake_minimum_required(VERSION 3.20)
project(HFTBot)

set(CMAKE_CXX_STANDARD 20)

add_executable(HFTBot main.cpp thread_utils.h mem_pool.h macros.h lf_queue.h time_utils.h logging.h socket_utils.h)
