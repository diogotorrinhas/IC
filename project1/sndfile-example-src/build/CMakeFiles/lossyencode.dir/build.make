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
CMAKE_SOURCE_DIR = /home/diogo/Desktop/IC/project1/sndfile-example-src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/diogo/Desktop/IC/project1/sndfile-example-src/build

# Include any dependencies generated for this target.
include CMakeFiles/lossyencode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lossyencode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lossyencode.dir/flags.make

CMakeFiles/lossyencode.dir/lossyencode.cpp.o: CMakeFiles/lossyencode.dir/flags.make
CMakeFiles/lossyencode.dir/lossyencode.cpp.o: ../lossyencode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diogo/Desktop/IC/project1/sndfile-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lossyencode.dir/lossyencode.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lossyencode.dir/lossyencode.cpp.o -c /home/diogo/Desktop/IC/project1/sndfile-example-src/lossyencode.cpp

CMakeFiles/lossyencode.dir/lossyencode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lossyencode.dir/lossyencode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diogo/Desktop/IC/project1/sndfile-example-src/lossyencode.cpp > CMakeFiles/lossyencode.dir/lossyencode.cpp.i

CMakeFiles/lossyencode.dir/lossyencode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lossyencode.dir/lossyencode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diogo/Desktop/IC/project1/sndfile-example-src/lossyencode.cpp -o CMakeFiles/lossyencode.dir/lossyencode.cpp.s

# Object files for target lossyencode
lossyencode_OBJECTS = \
"CMakeFiles/lossyencode.dir/lossyencode.cpp.o"

# External object files for target lossyencode
lossyencode_EXTERNAL_OBJECTS =

/home/diogo/Desktop/IC/project1/sndfile-example-bin/lossyencode: CMakeFiles/lossyencode.dir/lossyencode.cpp.o
/home/diogo/Desktop/IC/project1/sndfile-example-bin/lossyencode: CMakeFiles/lossyencode.dir/build.make
/home/diogo/Desktop/IC/project1/sndfile-example-bin/lossyencode: CMakeFiles/lossyencode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/diogo/Desktop/IC/project1/sndfile-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/diogo/Desktop/IC/project1/sndfile-example-bin/lossyencode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lossyencode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lossyencode.dir/build: /home/diogo/Desktop/IC/project1/sndfile-example-bin/lossyencode

.PHONY : CMakeFiles/lossyencode.dir/build

CMakeFiles/lossyencode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lossyencode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lossyencode.dir/clean

CMakeFiles/lossyencode.dir/depend:
	cd /home/diogo/Desktop/IC/project1/sndfile-example-src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/diogo/Desktop/IC/project1/sndfile-example-src /home/diogo/Desktop/IC/project1/sndfile-example-src /home/diogo/Desktop/IC/project1/sndfile-example-src/build /home/diogo/Desktop/IC/project1/sndfile-example-src/build /home/diogo/Desktop/IC/project1/sndfile-example-src/build/CMakeFiles/lossyencode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lossyencode.dir/depend
