# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\toxic\Desktop\code\Cprac

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\toxic\Desktop\code\Cprac\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/C.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/C.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C.dir/flags.make

CMakeFiles/C.dir/stacks/paren_checker.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/stacks/paren_checker.c.obj: ../stacks/paren_checker.c
CMakeFiles/C.dir/stacks/paren_checker.c.obj: CMakeFiles/C.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\toxic\Desktop\code\Cprac\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/C.dir/stacks/paren_checker.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/C.dir/stacks/paren_checker.c.obj -MF CMakeFiles\C.dir\stacks\paren_checker.c.obj.d -o CMakeFiles\C.dir\stacks\paren_checker.c.obj -c C:\Users\toxic\Desktop\code\Cprac\stacks\paren_checker.c

CMakeFiles/C.dir/stacks/paren_checker.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/stacks/paren_checker.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\toxic\Desktop\code\Cprac\stacks\paren_checker.c > CMakeFiles\C.dir\stacks\paren_checker.c.i

CMakeFiles/C.dir/stacks/paren_checker.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/stacks/paren_checker.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\toxic\Desktop\code\Cprac\stacks\paren_checker.c -o CMakeFiles\C.dir\stacks\paren_checker.c.s

CMakeFiles/C.dir/stacks/stackArray.c.obj: CMakeFiles/C.dir/flags.make
CMakeFiles/C.dir/stacks/stackArray.c.obj: ../stacks/stackArray.c
CMakeFiles/C.dir/stacks/stackArray.c.obj: CMakeFiles/C.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\toxic\Desktop\code\Cprac\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/C.dir/stacks/stackArray.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/C.dir/stacks/stackArray.c.obj -MF CMakeFiles\C.dir\stacks\stackArray.c.obj.d -o CMakeFiles\C.dir\stacks\stackArray.c.obj -c C:\Users\toxic\Desktop\code\Cprac\stacks\stackArray.c

CMakeFiles/C.dir/stacks/stackArray.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C.dir/stacks/stackArray.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\toxic\Desktop\code\Cprac\stacks\stackArray.c > CMakeFiles\C.dir\stacks\stackArray.c.i

CMakeFiles/C.dir/stacks/stackArray.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C.dir/stacks/stackArray.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\toxic\Desktop\code\Cprac\stacks\stackArray.c -o CMakeFiles\C.dir\stacks\stackArray.c.s

# Object files for target C
C_OBJECTS = \
"CMakeFiles/C.dir/stacks/paren_checker.c.obj" \
"CMakeFiles/C.dir/stacks/stackArray.c.obj"

# External object files for target C
C_EXTERNAL_OBJECTS =

C.exe: CMakeFiles/C.dir/stacks/paren_checker.c.obj
C.exe: CMakeFiles/C.dir/stacks/stackArray.c.obj
C.exe: CMakeFiles/C.dir/build.make
C.exe: CMakeFiles/C.dir/linklibs.rsp
C.exe: CMakeFiles/C.dir/objects1.rsp
C.exe: CMakeFiles/C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\toxic\Desktop\code\Cprac\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable C.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\C.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C.dir/build: C.exe
.PHONY : CMakeFiles/C.dir/build

CMakeFiles/C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\C.dir\cmake_clean.cmake
.PHONY : CMakeFiles/C.dir/clean

CMakeFiles/C.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\toxic\Desktop\code\Cprac C:\Users\toxic\Desktop\code\Cprac C:\Users\toxic\Desktop\code\Cprac\cmake-build-debug C:\Users\toxic\Desktop\code\Cprac\cmake-build-debug C:\Users\toxic\Desktop\code\Cprac\cmake-build-debug\CMakeFiles\C.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/C.dir/depend

