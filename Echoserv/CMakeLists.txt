cmake_minimum_required ( VERSION 3.10)

project (Echoserv)

add_executable(echoserv activeblock.cc echoserv.cc helper.cc)

add_executable(echoclnt echoclnt.cc helper.cc)
add_executable(echoclntlc echoclntlc.cc helper.cc)
