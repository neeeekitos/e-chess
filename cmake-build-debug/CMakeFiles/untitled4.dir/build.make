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
CMAKE_COMMAND = /home/lpietropao/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lpietropao/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lpietropao/etu/s2/GL/e-chess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lpietropao/etu/s2/GL/e-chess/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled4.dir/flags.make

CMakeFiles/untitled4.dir/main.cpp.o: CMakeFiles/untitled4.dir/flags.make
CMakeFiles/untitled4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lpietropao/etu/s2/GL/e-chess/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled4.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled4.dir/main.cpp.o -c /home/lpietropao/etu/s2/GL/e-chess/main.cpp

CMakeFiles/untitled4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled4.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lpietropao/etu/s2/GL/e-chess/main.cpp > CMakeFiles/untitled4.dir/main.cpp.i

CMakeFiles/untitled4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled4.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lpietropao/etu/s2/GL/e-chess/main.cpp -o CMakeFiles/untitled4.dir/main.cpp.s

# Object files for target untitled4
untitled4_OBJECTS = \
"CMakeFiles/untitled4.dir/main.cpp.o"

# External object files for target untitled4
untitled4_EXTERNAL_OBJECTS =

untitled4: CMakeFiles/untitled4.dir/main.cpp.o
untitled4: CMakeFiles/untitled4.dir/build.make
untitled4: CMakeFiles/untitled4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lpietropao/etu/s2/GL/e-chess/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable untitled4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled4.dir/build: untitled4

.PHONY : CMakeFiles/untitled4.dir/build

CMakeFiles/untitled4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled4.dir/clean

CMakeFiles/untitled4.dir/depend:
	cd /home/lpietropao/etu/s2/GL/e-chess/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lpietropao/etu/s2/GL/e-chess /home/lpietropao/etu/s2/GL/e-chess /home/lpietropao/etu/s2/GL/e-chess/cmake-build-debug /home/lpietropao/etu/s2/GL/e-chess/cmake-build-debug /home/lpietropao/etu/s2/GL/e-chess/cmake-build-debug/CMakeFiles/untitled4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled4.dir/depend

