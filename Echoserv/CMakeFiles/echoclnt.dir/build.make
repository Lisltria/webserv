# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/pip/Project/webserv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pip/Project/webserv

# Include any dependencies generated for this target.
include CMakeFiles/echoclnt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/echoclnt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/echoclnt.dir/flags.make

CMakeFiles/echoclnt.dir/echoclnt.c.o: CMakeFiles/echoclnt.dir/flags.make
CMakeFiles/echoclnt.dir/echoclnt.c.o: echoclnt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pip/Project/webserv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/echoclnt.dir/echoclnt.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/echoclnt.dir/echoclnt.c.o   -c /home/pip/Project/webserv/echoclnt.c

CMakeFiles/echoclnt.dir/echoclnt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/echoclnt.dir/echoclnt.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pip/Project/webserv/echoclnt.c > CMakeFiles/echoclnt.dir/echoclnt.c.i

CMakeFiles/echoclnt.dir/echoclnt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/echoclnt.dir/echoclnt.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pip/Project/webserv/echoclnt.c -o CMakeFiles/echoclnt.dir/echoclnt.c.s

CMakeFiles/echoclnt.dir/echoclnt.c.o.requires:

.PHONY : CMakeFiles/echoclnt.dir/echoclnt.c.o.requires

CMakeFiles/echoclnt.dir/echoclnt.c.o.provides: CMakeFiles/echoclnt.dir/echoclnt.c.o.requires
	$(MAKE) -f CMakeFiles/echoclnt.dir/build.make CMakeFiles/echoclnt.dir/echoclnt.c.o.provides.build
.PHONY : CMakeFiles/echoclnt.dir/echoclnt.c.o.provides

CMakeFiles/echoclnt.dir/echoclnt.c.o.provides.build: CMakeFiles/echoclnt.dir/echoclnt.c.o


CMakeFiles/echoclnt.dir/helper.c.o: CMakeFiles/echoclnt.dir/flags.make
CMakeFiles/echoclnt.dir/helper.c.o: helper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pip/Project/webserv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/echoclnt.dir/helper.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/echoclnt.dir/helper.c.o   -c /home/pip/Project/webserv/helper.c

CMakeFiles/echoclnt.dir/helper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/echoclnt.dir/helper.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pip/Project/webserv/helper.c > CMakeFiles/echoclnt.dir/helper.c.i

CMakeFiles/echoclnt.dir/helper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/echoclnt.dir/helper.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pip/Project/webserv/helper.c -o CMakeFiles/echoclnt.dir/helper.c.s

CMakeFiles/echoclnt.dir/helper.c.o.requires:

.PHONY : CMakeFiles/echoclnt.dir/helper.c.o.requires

CMakeFiles/echoclnt.dir/helper.c.o.provides: CMakeFiles/echoclnt.dir/helper.c.o.requires
	$(MAKE) -f CMakeFiles/echoclnt.dir/build.make CMakeFiles/echoclnt.dir/helper.c.o.provides.build
.PHONY : CMakeFiles/echoclnt.dir/helper.c.o.provides

CMakeFiles/echoclnt.dir/helper.c.o.provides.build: CMakeFiles/echoclnt.dir/helper.c.o


# Object files for target echoclnt
echoclnt_OBJECTS = \
"CMakeFiles/echoclnt.dir/echoclnt.c.o" \
"CMakeFiles/echoclnt.dir/helper.c.o"

# External object files for target echoclnt
echoclnt_EXTERNAL_OBJECTS =

echoclnt: CMakeFiles/echoclnt.dir/echoclnt.c.o
echoclnt: CMakeFiles/echoclnt.dir/helper.c.o
echoclnt: CMakeFiles/echoclnt.dir/build.make
echoclnt: CMakeFiles/echoclnt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pip/Project/webserv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable echoclnt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/echoclnt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/echoclnt.dir/build: echoclnt

.PHONY : CMakeFiles/echoclnt.dir/build

CMakeFiles/echoclnt.dir/requires: CMakeFiles/echoclnt.dir/echoclnt.c.o.requires
CMakeFiles/echoclnt.dir/requires: CMakeFiles/echoclnt.dir/helper.c.o.requires

.PHONY : CMakeFiles/echoclnt.dir/requires

CMakeFiles/echoclnt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/echoclnt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/echoclnt.dir/clean

CMakeFiles/echoclnt.dir/depend:
	cd /home/pip/Project/webserv && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pip/Project/webserv /home/pip/Project/webserv /home/pip/Project/webserv /home/pip/Project/webserv /home/pip/Project/webserv/CMakeFiles/echoclnt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/echoclnt.dir/depend
