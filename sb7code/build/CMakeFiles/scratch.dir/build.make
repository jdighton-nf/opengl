# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jdighton/Code/opengl/sb7code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jdighton/Code/opengl/sb7code/build

# Include any dependencies generated for this target.
include CMakeFiles/scratch.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/scratch.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/scratch.dir/flags.make

CMakeFiles/scratch.dir/src/scratch/scratch.cpp.o: CMakeFiles/scratch.dir/flags.make
CMakeFiles/scratch.dir/src/scratch/scratch.cpp.o: ../src/scratch/scratch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jdighton/Code/opengl/sb7code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/scratch.dir/src/scratch/scratch.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/scratch.dir/src/scratch/scratch.cpp.o -c /home/jdighton/Code/opengl/sb7code/src/scratch/scratch.cpp

CMakeFiles/scratch.dir/src/scratch/scratch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scratch.dir/src/scratch/scratch.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jdighton/Code/opengl/sb7code/src/scratch/scratch.cpp > CMakeFiles/scratch.dir/src/scratch/scratch.cpp.i

CMakeFiles/scratch.dir/src/scratch/scratch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scratch.dir/src/scratch/scratch.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jdighton/Code/opengl/sb7code/src/scratch/scratch.cpp -o CMakeFiles/scratch.dir/src/scratch/scratch.cpp.s

# Object files for target scratch
scratch_OBJECTS = \
"CMakeFiles/scratch.dir/src/scratch/scratch.cpp.o"

# External object files for target scratch
scratch_EXTERNAL_OBJECTS =

../bin/scratch: CMakeFiles/scratch.dir/src/scratch/scratch.cpp.o
../bin/scratch: CMakeFiles/scratch.dir/build.make
../bin/scratch: lib/libsb7.a
../bin/scratch: CMakeFiles/scratch.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jdighton/Code/opengl/sb7code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/scratch"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scratch.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/scratch.dir/build: ../bin/scratch

.PHONY : CMakeFiles/scratch.dir/build

CMakeFiles/scratch.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/scratch.dir/cmake_clean.cmake
.PHONY : CMakeFiles/scratch.dir/clean

CMakeFiles/scratch.dir/depend:
	cd /home/jdighton/Code/opengl/sb7code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jdighton/Code/opengl/sb7code /home/jdighton/Code/opengl/sb7code /home/jdighton/Code/opengl/sb7code/build /home/jdighton/Code/opengl/sb7code/build /home/jdighton/Code/opengl/sb7code/build/CMakeFiles/scratch.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/scratch.dir/depend

