# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Ana\Documents\GitHub\SD

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Ana\Documents\GitHub\SD\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/temalab1sd.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/temalab1sd.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/temalab1sd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/temalab1sd.dir/flags.make

CMakeFiles/temalab1sd.dir/main.cpp.obj: CMakeFiles/temalab1sd.dir/flags.make
CMakeFiles/temalab1sd.dir/main.cpp.obj: ../main.cpp
CMakeFiles/temalab1sd.dir/main.cpp.obj: CMakeFiles/temalab1sd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Ana\Documents\GitHub\SD\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/temalab1sd.dir/main.cpp.obj"
	"D:\CLion 2021.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/temalab1sd.dir/main.cpp.obj -MF CMakeFiles\temalab1sd.dir\main.cpp.obj.d -o CMakeFiles\temalab1sd.dir\main.cpp.obj -c C:\Users\Ana\Documents\GitHub\SD\main.cpp

CMakeFiles/temalab1sd.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/temalab1sd.dir/main.cpp.i"
	"D:\CLion 2021.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ana\Documents\GitHub\SD\main.cpp > CMakeFiles\temalab1sd.dir\main.cpp.i

CMakeFiles/temalab1sd.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/temalab1sd.dir/main.cpp.s"
	"D:\CLion 2021.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ana\Documents\GitHub\SD\main.cpp -o CMakeFiles\temalab1sd.dir\main.cpp.s

# Object files for target temalab1sd
temalab1sd_OBJECTS = \
"CMakeFiles/temalab1sd.dir/main.cpp.obj"

# External object files for target temalab1sd
temalab1sd_EXTERNAL_OBJECTS =

temalab1sd.exe: CMakeFiles/temalab1sd.dir/main.cpp.obj
temalab1sd.exe: CMakeFiles/temalab1sd.dir/build.make
temalab1sd.exe: CMakeFiles/temalab1sd.dir/linklibs.rsp
temalab1sd.exe: CMakeFiles/temalab1sd.dir/objects1.rsp
temalab1sd.exe: CMakeFiles/temalab1sd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Ana\Documents\GitHub\SD\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable temalab1sd.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\temalab1sd.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/temalab1sd.dir/build: temalab1sd.exe
.PHONY : CMakeFiles/temalab1sd.dir/build

CMakeFiles/temalab1sd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\temalab1sd.dir\cmake_clean.cmake
.PHONY : CMakeFiles/temalab1sd.dir/clean

CMakeFiles/temalab1sd.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Ana\Documents\GitHub\SD C:\Users\Ana\Documents\GitHub\SD C:\Users\Ana\Documents\GitHub\SD\cmake-build-debug C:\Users\Ana\Documents\GitHub\SD\cmake-build-debug C:\Users\Ana\Documents\GitHub\SD\cmake-build-debug\CMakeFiles\temalab1sd.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/temalab1sd.dir/depend

