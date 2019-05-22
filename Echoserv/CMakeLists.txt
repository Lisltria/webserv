cmake_minimum_required ( VERSION 3.10)

project (Echoserv)

add_executable(echoserv echoserv.c helper.c)

add_executable(echoclnt echoclnt.c helper.c)
