cmake_minimum_required(VERSION 2.6)

project(ssl_server C CXX)
set(CMAKE_CXX_STANDARD 14)

add_executable(server src/server.cc)
add_executable(client src/client.cc)

add_subdirectory(include/muduo/base)
add_subdirectory(include/muduo/net)
add_subdirectory(include/com_protocol/mqtt)


find_package(OpenSSL REQUIRED)

include_directories(
    src
    CMAKE_SOURCE_DIR/include)

target_link_libraries(server muduo_base muduo_net OpenSSL::SSL mqtt)
target_link_libraries(client muduo_base muduo_net mqtt)
