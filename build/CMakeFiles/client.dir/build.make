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
include CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

CMakeFiles/client.dir/src/client.cc.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/client.cc.o: ../src/client.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client.dir/src/client.cc.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/client.cc.o -c /home/me_and_my_guitar/Documents/mqtt_server_broker/server/src/client.cc

CMakeFiles/client.dir/src/client.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/client.cc.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/me_and_my_guitar/Documents/mqtt_server_broker/server/src/client.cc > CMakeFiles/client.dir/src/client.cc.i

CMakeFiles/client.dir/src/client.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/client.cc.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/me_and_my_guitar/Documents/mqtt_server_broker/server/src/client.cc -o CMakeFiles/client.dir/src/client.cc.s

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/src/client.cc.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

client: CMakeFiles/client.dir/src/client.cc.o
client: CMakeFiles/client.dir/build.make
client: include/muduo/base/libmuduo_base.a
client: include/muduo/net/libmuduo_net.a
client: include/com_protocol/mqtt/libmqtt.a
client: include/muduo/base/libmuduo_base.a
client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: client

.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend:
	cd /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/me_and_my_guitar/Documents/mqtt_server_broker/server /home/me_and_my_guitar/Documents/mqtt_server_broker/server /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build /home/me_and_my_guitar/Documents/mqtt_server_broker/server/build/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client.dir/depend

