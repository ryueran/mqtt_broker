# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/me_and_my_guitar/Documents/mqtt_server_broker/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build

# Include any dependencies generated for this target.
include include/muduo/net/http/CMakeFiles/muduo_http.dir/depend.make

# Include the progress variables for this target.
include include/muduo/net/http/CMakeFiles/muduo_http.dir/progress.make

# Include the compile flags for this target's objects.
include include/muduo/net/http/CMakeFiles/muduo_http.dir/flags.make

include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpServer.cc.o: include/muduo/net/http/CMakeFiles/muduo_http.dir/flags.make
include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpServer.cc.o: ../include/muduo/net/http/HttpServer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpServer.cc.o"
	cd /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/http && /bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/muduo_http.dir/HttpServer.cc.o -c /home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/http/HttpServer.cc

include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpServer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo_http.dir/HttpServer.cc.i"
	cd /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/http && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/http/HttpServer.cc > CMakeFiles/muduo_http.dir/HttpServer.cc.i

include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpServer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo_http.dir/HttpServer.cc.s"
	cd /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/http && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/http/HttpServer.cc -o CMakeFiles/muduo_http.dir/HttpServer.cc.s

include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpResponse.cc.o: include/muduo/net/http/CMakeFiles/muduo_http.dir/flags.make
include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpResponse.cc.o: ../include/muduo/net/http/HttpResponse.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpResponse.cc.o"
	cd /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/http && /bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/muduo_http.dir/HttpResponse.cc.o -c /home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/http/HttpResponse.cc

include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpResponse.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo_http.dir/HttpResponse.cc.i"
	cd /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/http && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/http/HttpResponse.cc > CMakeFiles/muduo_http.dir/HttpResponse.cc.i

include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpResponse.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo_http.dir/HttpResponse.cc.s"
	cd /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/http && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/http/HttpResponse.cc -o CMakeFiles/muduo_http.dir/HttpResponse.cc.s

include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpContext.cc.o: include/muduo/net/http/CMakeFiles/muduo_http.dir/flags.make
include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpContext.cc.o: ../include/muduo/net/http/HttpContext.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpContext.cc.o"
	cd /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/http && /bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/muduo_http.dir/HttpContext.cc.o -c /home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/http/HttpContext.cc

include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpContext.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo_http.dir/HttpContext.cc.i"
	cd /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/http && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/http/HttpContext.cc > CMakeFiles/muduo_http.dir/HttpContext.cc.i

include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpContext.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo_http.dir/HttpContext.cc.s"
	cd /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/http && /bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/http/HttpContext.cc -o CMakeFiles/muduo_http.dir/HttpContext.cc.s

# Object files for target muduo_http
muduo_http_OBJECTS = \
"CMakeFiles/muduo_http.dir/HttpServer.cc.o" \
"CMakeFiles/muduo_http.dir/HttpResponse.cc.o" \
"CMakeFiles/muduo_http.dir/HttpContext.cc.o"

# External object files for target muduo_http
muduo_http_EXTERNAL_OBJECTS =

include/muduo/net/http/libmuduo_http.a: include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpServer.cc.o
include/muduo/net/http/libmuduo_http.a: include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpResponse.cc.o
include/muduo/net/http/libmuduo_http.a: include/muduo/net/http/CMakeFiles/muduo_http.dir/HttpContext.cc.o
include/muduo/net/http/libmuduo_http.a: include/muduo/net/http/CMakeFiles/muduo_http.dir/build.make
include/muduo/net/http/libmuduo_http.a: include/muduo/net/http/CMakeFiles/muduo_http.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libmuduo_http.a"
	cd /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/http && $(CMAKE_COMMAND) -P CMakeFiles/muduo_http.dir/cmake_clean_target.cmake
	cd /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/http && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/muduo_http.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/muduo/net/http/CMakeFiles/muduo_http.dir/build: include/muduo/net/http/libmuduo_http.a

.PHONY : include/muduo/net/http/CMakeFiles/muduo_http.dir/build

include/muduo/net/http/CMakeFiles/muduo_http.dir/clean:
	cd /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/http && $(CMAKE_COMMAND) -P CMakeFiles/muduo_http.dir/cmake_clean.cmake
.PHONY : include/muduo/net/http/CMakeFiles/muduo_http.dir/clean

include/muduo/net/http/CMakeFiles/muduo_http.dir/depend:
	cd /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/me_and_my_guitar/Documents/mqtt_server_broker/server /home/me_and_my_guitar/Documents/mqtt_server_broker/server/include/muduo/net/http /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/http /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/include/muduo/net/http/CMakeFiles/muduo_http.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/muduo/net/http/CMakeFiles/muduo_http.dir/depend

