cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_STANDARD 14)

set(base_protocol
    mqtt_protocol.cpp
)

add_library(mqtt ${base_protocol})

#add_library(muduo_base_cpp11 ${base_SRCS})
#target_link_libraries(muduo_base_cpp11 pthread rt)
#set_target_properties(muduo_base_cpp11 PROPERTIES COMPILE_FLAGS "-std=c++0x")

install(TARGETS mqtt DESTINATION lib)
#install(TARGETS muduo_base_cpp11 DESTINATION lib)

target_include_directories(muduo_base
  PUBLIC
  ../
)
install(FILES ${HEADERS} DESTINATION include/com_protocol/mqtt)
