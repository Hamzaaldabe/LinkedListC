# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/hamza/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.6693.114/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/hamza/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/211.6693.114/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hamza/Desktop/hamza/project1Data

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hamza/Desktop/hamza/project1Data/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project1Data.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project1Data.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project1Data.dir/flags.make

CMakeFiles/project1Data.dir/main.c.o: CMakeFiles/project1Data.dir/flags.make
CMakeFiles/project1Data.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hamza/Desktop/hamza/project1Data/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/project1Data.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project1Data.dir/main.c.o -c /home/hamza/Desktop/hamza/project1Data/main.c

CMakeFiles/project1Data.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project1Data.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hamza/Desktop/hamza/project1Data/main.c > CMakeFiles/project1Data.dir/main.c.i

CMakeFiles/project1Data.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project1Data.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hamza/Desktop/hamza/project1Data/main.c -o CMakeFiles/project1Data.dir/main.c.s

# Object files for target project1Data
project1Data_OBJECTS = \
"CMakeFiles/project1Data.dir/main.c.o"

# External object files for target project1Data
project1Data_EXTERNAL_OBJECTS =

project1Data: CMakeFiles/project1Data.dir/main.c.o
project1Data: CMakeFiles/project1Data.dir/build.make
project1Data: CMakeFiles/project1Data.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hamza/Desktop/hamza/project1Data/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable project1Data"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project1Data.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project1Data.dir/build: project1Data

.PHONY : CMakeFiles/project1Data.dir/build

CMakeFiles/project1Data.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project1Data.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project1Data.dir/clean

CMakeFiles/project1Data.dir/depend:
	cd /home/hamza/Desktop/hamza/project1Data/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hamza/Desktop/hamza/project1Data /home/hamza/Desktop/hamza/project1Data /home/hamza/Desktop/hamza/project1Data/cmake-build-debug /home/hamza/Desktop/hamza/project1Data/cmake-build-debug /home/hamza/Desktop/hamza/project1Data/cmake-build-debug/CMakeFiles/project1Data.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project1Data.dir/depend

