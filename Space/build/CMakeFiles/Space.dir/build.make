# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/student/C++/Space

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/C++/Space/build

# Include any dependencies generated for this target.
include CMakeFiles/Space.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Space.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Space.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Space.dir/flags.make

CMakeFiles/Space.dir/app/src/main.cpp.o: CMakeFiles/Space.dir/flags.make
CMakeFiles/Space.dir/app/src/main.cpp.o: /home/student/C++/Space/app/src/main.cpp
CMakeFiles/Space.dir/app/src/main.cpp.o: CMakeFiles/Space.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/student/C++/Space/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Space.dir/app/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Space.dir/app/src/main.cpp.o -MF CMakeFiles/Space.dir/app/src/main.cpp.o.d -o CMakeFiles/Space.dir/app/src/main.cpp.o -c /home/student/C++/Space/app/src/main.cpp

CMakeFiles/Space.dir/app/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Space.dir/app/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/C++/Space/app/src/main.cpp > CMakeFiles/Space.dir/app/src/main.cpp.i

CMakeFiles/Space.dir/app/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Space.dir/app/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/C++/Space/app/src/main.cpp -o CMakeFiles/Space.dir/app/src/main.cpp.s

# Object files for target Space
Space_OBJECTS = \
"CMakeFiles/Space.dir/app/src/main.cpp.o"

# External object files for target Space
Space_EXTERNAL_OBJECTS =

Space: CMakeFiles/Space.dir/app/src/main.cpp.o
Space: CMakeFiles/Space.dir/build.make
Space: raylib_binary_dir/raylib/libraylib.a
Space: /usr/lib/x86_64-linux-gnu/libOpenGL.so
Space: /usr/lib/x86_64-linux-gnu/libGLX.so
Space: /usr/lib/x86_64-linux-gnu/libGLU.so
Space: /usr/lib/x86_64-linux-gnu/librt.a
Space: /usr/lib/x86_64-linux-gnu/libm.so
Space: CMakeFiles/Space.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/student/C++/Space/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Space"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Space.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Space.dir/build: Space
.PHONY : CMakeFiles/Space.dir/build

CMakeFiles/Space.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Space.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Space.dir/clean

CMakeFiles/Space.dir/depend:
	cd /home/student/C++/Space/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/C++/Space /home/student/C++/Space /home/student/C++/Space/build /home/student/C++/Space/build /home/student/C++/Space/build/CMakeFiles/Space.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Space.dir/depend

