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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/horqin/Desktop/2021T2/9024/lab05

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/horqin/Desktop/2021T2/9024/lab05/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab0501.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab0501.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab0501.dir/flags.make

CMakeFiles/lab0501.dir/component_graphs/component.c.o: CMakeFiles/lab0501.dir/flags.make
CMakeFiles/lab0501.dir/component_graphs/component.c.o: ../component_graphs/component.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/horqin/Desktop/2021T2/9024/lab05/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab0501.dir/component_graphs/component.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab0501.dir/component_graphs/component.c.o -c /Users/horqin/Desktop/2021T2/9024/lab05/component_graphs/component.c

CMakeFiles/lab0501.dir/component_graphs/component.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab0501.dir/component_graphs/component.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/horqin/Desktop/2021T2/9024/lab05/component_graphs/component.c > CMakeFiles/lab0501.dir/component_graphs/component.c.i

CMakeFiles/lab0501.dir/component_graphs/component.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab0501.dir/component_graphs/component.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/horqin/Desktop/2021T2/9024/lab05/component_graphs/component.c -o CMakeFiles/lab0501.dir/component_graphs/component.c.s

CMakeFiles/lab0501.dir/component_graphs/graph.c.o: CMakeFiles/lab0501.dir/flags.make
CMakeFiles/lab0501.dir/component_graphs/graph.c.o: ../component_graphs/graph.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/horqin/Desktop/2021T2/9024/lab05/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab0501.dir/component_graphs/graph.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab0501.dir/component_graphs/graph.c.o -c /Users/horqin/Desktop/2021T2/9024/lab05/component_graphs/graph.c

CMakeFiles/lab0501.dir/component_graphs/graph.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab0501.dir/component_graphs/graph.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/horqin/Desktop/2021T2/9024/lab05/component_graphs/graph.c > CMakeFiles/lab0501.dir/component_graphs/graph.c.i

CMakeFiles/lab0501.dir/component_graphs/graph.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab0501.dir/component_graphs/graph.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/horqin/Desktop/2021T2/9024/lab05/component_graphs/graph.c -o CMakeFiles/lab0501.dir/component_graphs/graph.c.s

CMakeFiles/lab0501.dir/component_graphs/graph_driver.c.o: CMakeFiles/lab0501.dir/flags.make
CMakeFiles/lab0501.dir/component_graphs/graph_driver.c.o: ../component_graphs/graph_driver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/horqin/Desktop/2021T2/9024/lab05/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lab0501.dir/component_graphs/graph_driver.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab0501.dir/component_graphs/graph_driver.c.o -c /Users/horqin/Desktop/2021T2/9024/lab05/component_graphs/graph_driver.c

CMakeFiles/lab0501.dir/component_graphs/graph_driver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab0501.dir/component_graphs/graph_driver.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/horqin/Desktop/2021T2/9024/lab05/component_graphs/graph_driver.c > CMakeFiles/lab0501.dir/component_graphs/graph_driver.c.i

CMakeFiles/lab0501.dir/component_graphs/graph_driver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab0501.dir/component_graphs/graph_driver.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/horqin/Desktop/2021T2/9024/lab05/component_graphs/graph_driver.c -o CMakeFiles/lab0501.dir/component_graphs/graph_driver.c.s

# Object files for target lab0501
lab0501_OBJECTS = \
"CMakeFiles/lab0501.dir/component_graphs/component.c.o" \
"CMakeFiles/lab0501.dir/component_graphs/graph.c.o" \
"CMakeFiles/lab0501.dir/component_graphs/graph_driver.c.o"

# External object files for target lab0501
lab0501_EXTERNAL_OBJECTS =

lab0501: CMakeFiles/lab0501.dir/component_graphs/component.c.o
lab0501: CMakeFiles/lab0501.dir/component_graphs/graph.c.o
lab0501: CMakeFiles/lab0501.dir/component_graphs/graph_driver.c.o
lab0501: CMakeFiles/lab0501.dir/build.make
lab0501: CMakeFiles/lab0501.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/horqin/Desktop/2021T2/9024/lab05/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable lab0501"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab0501.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab0501.dir/build: lab0501

.PHONY : CMakeFiles/lab0501.dir/build

CMakeFiles/lab0501.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab0501.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab0501.dir/clean

CMakeFiles/lab0501.dir/depend:
	cd /Users/horqin/Desktop/2021T2/9024/lab05/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/horqin/Desktop/2021T2/9024/lab05 /Users/horqin/Desktop/2021T2/9024/lab05 /Users/horqin/Desktop/2021T2/9024/lab05/cmake-build-debug /Users/horqin/Desktop/2021T2/9024/lab05/cmake-build-debug /Users/horqin/Desktop/2021T2/9024/lab05/cmake-build-debug/CMakeFiles/lab0501.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab0501.dir/depend

