# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.3

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\codeRepertory\QT\SimpleCode_CPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\codeRepertory\QT\SimpleCode_CPP-build

# Include any dependencies generated for this target.
include CMakeFiles/SimpleCode_CPP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SimpleCode_CPP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SimpleCode_CPP.dir/flags.make

CMakeFiles/SimpleCode_CPP.dir/main.cpp.obj: CMakeFiles/SimpleCode_CPP.dir/flags.make
CMakeFiles/SimpleCode_CPP.dir/main.cpp.obj: E:/codeRepertory/QT/SimpleCode_CPP/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\codeRepertory\QT\SimpleCode_CPP-build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SimpleCode_CPP.dir/main.cpp.obj"
	C:\ProgramFiels\Qt\Tools\mingw492_32\bin\g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\SimpleCode_CPP.dir\main.cpp.obj -c E:\codeRepertory\QT\SimpleCode_CPP\main.cpp

CMakeFiles/SimpleCode_CPP.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimpleCode_CPP.dir/main.cpp.i"
	C:\ProgramFiels\Qt\Tools\mingw492_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E E:\codeRepertory\QT\SimpleCode_CPP\main.cpp > CMakeFiles\SimpleCode_CPP.dir\main.cpp.i

CMakeFiles/SimpleCode_CPP.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimpleCode_CPP.dir/main.cpp.s"
	C:\ProgramFiels\Qt\Tools\mingw492_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S E:\codeRepertory\QT\SimpleCode_CPP\main.cpp -o CMakeFiles\SimpleCode_CPP.dir\main.cpp.s

CMakeFiles/SimpleCode_CPP.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/SimpleCode_CPP.dir/main.cpp.obj.requires

CMakeFiles/SimpleCode_CPP.dir/main.cpp.obj.provides: CMakeFiles/SimpleCode_CPP.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\SimpleCode_CPP.dir\build.make CMakeFiles/SimpleCode_CPP.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/SimpleCode_CPP.dir/main.cpp.obj.provides

CMakeFiles/SimpleCode_CPP.dir/main.cpp.obj.provides.build: CMakeFiles/SimpleCode_CPP.dir/main.cpp.obj


# Object files for target SimpleCode_CPP
SimpleCode_CPP_OBJECTS = \
"CMakeFiles/SimpleCode_CPP.dir/main.cpp.obj"

# External object files for target SimpleCode_CPP
SimpleCode_CPP_EXTERNAL_OBJECTS =

SimpleCode_CPP.exe: CMakeFiles/SimpleCode_CPP.dir/main.cpp.obj
SimpleCode_CPP.exe: CMakeFiles/SimpleCode_CPP.dir/build.make
SimpleCode_CPP.exe: CMakeFiles/SimpleCode_CPP.dir/linklibs.rsp
SimpleCode_CPP.exe: CMakeFiles/SimpleCode_CPP.dir/objects1.rsp
SimpleCode_CPP.exe: CMakeFiles/SimpleCode_CPP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\codeRepertory\QT\SimpleCode_CPP-build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SimpleCode_CPP.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SimpleCode_CPP.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SimpleCode_CPP.dir/build: SimpleCode_CPP.exe

.PHONY : CMakeFiles/SimpleCode_CPP.dir/build

CMakeFiles/SimpleCode_CPP.dir/requires: CMakeFiles/SimpleCode_CPP.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/SimpleCode_CPP.dir/requires

CMakeFiles/SimpleCode_CPP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SimpleCode_CPP.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SimpleCode_CPP.dir/clean

CMakeFiles/SimpleCode_CPP.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\codeRepertory\QT\SimpleCode_CPP E:\codeRepertory\QT\SimpleCode_CPP E:\codeRepertory\QT\SimpleCode_CPP-build E:\codeRepertory\QT\SimpleCode_CPP-build E:\codeRepertory\QT\SimpleCode_CPP-build\CMakeFiles\SimpleCode_CPP.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SimpleCode_CPP.dir/depend

