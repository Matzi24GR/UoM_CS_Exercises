# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\Student_Exercises\Exercise_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Student_Exercises\Exercise_2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Exercise_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Exercise_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Exercise_2.dir/flags.make

CMakeFiles/Exercise_2.dir/a14f2.c.obj: CMakeFiles/Exercise_2.dir/flags.make
CMakeFiles/Exercise_2.dir/a14f2.c.obj: ../a14f2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Student_Exercises\Exercise_2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Exercise_2.dir/a14f2.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Exercise_2.dir\a14f2.c.obj   -c F:\Student_Exercises\Exercise_2\a14f2.c

CMakeFiles/Exercise_2.dir/a14f2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Exercise_2.dir/a14f2.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Student_Exercises\Exercise_2\a14f2.c > CMakeFiles\Exercise_2.dir\a14f2.c.i

CMakeFiles/Exercise_2.dir/a14f2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Exercise_2.dir/a14f2.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Student_Exercises\Exercise_2\a14f2.c -o CMakeFiles\Exercise_2.dir\a14f2.c.s

CMakeFiles/Exercise_2.dir/a7f2.c.obj: CMakeFiles/Exercise_2.dir/flags.make
CMakeFiles/Exercise_2.dir/a7f2.c.obj: ../a7f2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Student_Exercises\Exercise_2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Exercise_2.dir/a7f2.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Exercise_2.dir\a7f2.c.obj   -c F:\Student_Exercises\Exercise_2\a7f2.c

CMakeFiles/Exercise_2.dir/a7f2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Exercise_2.dir/a7f2.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Student_Exercises\Exercise_2\a7f2.c > CMakeFiles\Exercise_2.dir\a7f2.c.i

CMakeFiles/Exercise_2.dir/a7f2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Exercise_2.dir/a7f2.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Student_Exercises\Exercise_2\a7f2.c -o CMakeFiles\Exercise_2.dir\a7f2.c.s

# Object files for target Exercise_2
Exercise_2_OBJECTS = \
"CMakeFiles/Exercise_2.dir/a14f2.c.obj" \
"CMakeFiles/Exercise_2.dir/a7f2.c.obj"

# External object files for target Exercise_2
Exercise_2_EXTERNAL_OBJECTS =

Exercise_2.exe: CMakeFiles/Exercise_2.dir/a14f2.c.obj
Exercise_2.exe: CMakeFiles/Exercise_2.dir/a7f2.c.obj
Exercise_2.exe: CMakeFiles/Exercise_2.dir/build.make
Exercise_2.exe: CMakeFiles/Exercise_2.dir/linklibs.rsp
Exercise_2.exe: CMakeFiles/Exercise_2.dir/objects1.rsp
Exercise_2.exe: CMakeFiles/Exercise_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Student_Exercises\Exercise_2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Exercise_2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Exercise_2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Exercise_2.dir/build: Exercise_2.exe

.PHONY : CMakeFiles/Exercise_2.dir/build

CMakeFiles/Exercise_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Exercise_2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Exercise_2.dir/clean

CMakeFiles/Exercise_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Student_Exercises\Exercise_2 F:\Student_Exercises\Exercise_2 F:\Student_Exercises\Exercise_2\cmake-build-debug F:\Student_Exercises\Exercise_2\cmake-build-debug F:\Student_Exercises\Exercise_2\cmake-build-debug\CMakeFiles\Exercise_2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Exercise_2.dir/depend

