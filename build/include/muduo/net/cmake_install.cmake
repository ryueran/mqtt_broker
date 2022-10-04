# Install script for directory: /home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/libmuduo_net.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/muduo/net" TYPE FILE FILES
    "/home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/Buffer.h"
    "/home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/Callbacks.h"
    "/home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/Channel.h"
    "/home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/Endian.h"
    "/home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/EventLoop.h"
    "/home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/EventLoopThread.h"
    "/home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/EventLoopThreadPool.h"
    "/home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/InetAddress.h"
    "/home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/TcpClient.h"
    "/home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/TcpConnection.h"
    "/home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/TcpServer.h"
    "/home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/TimerId.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/http/cmake_install.cmake")
  include("/home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/inspect/cmake_install.cmake")

endif()

