# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vladimir/Документы/АиСД/task1_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vladimir/Документы/АиСД/task1_3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/task1_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task1_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task1_3.dir/flags.make

CMakeFiles/task1_3.dir/main.cpp.o: CMakeFiles/task1_3.dir/flags.make
CMakeFiles/task1_3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vladimir/Документы/АиСД/task1_3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task1_3.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task1_3.dir/main.cpp.o -c /home/vladimir/Документы/АиСД/task1_3/main.cpp

CMakeFiles/task1_3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task1_3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vladimir/Документы/АиСД/task1_3/main.cpp > CMakeFiles/task1_3.dir/main.cpp.i

CMakeFiles/task1_3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task1_3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vladimir/Документы/АиСД/task1_3/main.cpp -o CMakeFiles/task1_3.dir/main.cpp.s

# Object files for target task1_3
task1_3_OBJECTS = \
"CMakeFiles/task1_3.dir/main.cpp.o"

# External object files for target task1_3
task1_3_EXTERNAL_OBJECTS =

task1_3: CMakeFiles/task1_3.dir/main.cpp.o
task1_3: CMakeFiles/task1_3.dir/build.make
task1_3: CMakeFiles/task1_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vladimir/Документы/АиСД/task1_3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task1_3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task1_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task1_3.dir/build: task1_3

.PHONY : CMakeFiles/task1_3.dir/build

CMakeFiles/task1_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task1_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task1_3.dir/clean

CMakeFiles/task1_3.dir/depend:
	cd /home/vladimir/Документы/АиСД/task1_3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vladimir/Документы/АиСД/task1_3 /home/vladimir/Документы/АиСД/task1_3 /home/vladimir/Документы/АиСД/task1_3/cmake-build-debug /home/vladimir/Документы/АиСД/task1_3/cmake-build-debug /home/vladimir/Документы/АиСД/task1_3/cmake-build-debug/CMakeFiles/task1_3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task1_3.dir/depend

