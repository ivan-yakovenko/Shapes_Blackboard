# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Shapes_Blackboard.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Shapes_Blackboard.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Shapes_Blackboard.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Shapes_Blackboard.dir/flags.make

CMakeFiles/Shapes_Blackboard.dir/src/main.cpp.o: CMakeFiles/Shapes_Blackboard.dir/flags.make
CMakeFiles/Shapes_Blackboard.dir/src/main.cpp.o: /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/main.cpp
CMakeFiles/Shapes_Blackboard.dir/src/main.cpp.o: CMakeFiles/Shapes_Blackboard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Shapes_Blackboard.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Shapes_Blackboard.dir/src/main.cpp.o -MF CMakeFiles/Shapes_Blackboard.dir/src/main.cpp.o.d -o CMakeFiles/Shapes_Blackboard.dir/src/main.cpp.o -c /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/main.cpp

CMakeFiles/Shapes_Blackboard.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Shapes_Blackboard.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/main.cpp > CMakeFiles/Shapes_Blackboard.dir/src/main.cpp.i

CMakeFiles/Shapes_Blackboard.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Shapes_Blackboard.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/main.cpp -o CMakeFiles/Shapes_Blackboard.dir/src/main.cpp.s

CMakeFiles/Shapes_Blackboard.dir/src/Board/Board.cpp.o: CMakeFiles/Shapes_Blackboard.dir/flags.make
CMakeFiles/Shapes_Blackboard.dir/src/Board/Board.cpp.o: /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/Board/Board.cpp
CMakeFiles/Shapes_Blackboard.dir/src/Board/Board.cpp.o: CMakeFiles/Shapes_Blackboard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Shapes_Blackboard.dir/src/Board/Board.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Shapes_Blackboard.dir/src/Board/Board.cpp.o -MF CMakeFiles/Shapes_Blackboard.dir/src/Board/Board.cpp.o.d -o CMakeFiles/Shapes_Blackboard.dir/src/Board/Board.cpp.o -c /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/Board/Board.cpp

CMakeFiles/Shapes_Blackboard.dir/src/Board/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Shapes_Blackboard.dir/src/Board/Board.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/Board/Board.cpp > CMakeFiles/Shapes_Blackboard.dir/src/Board/Board.cpp.i

CMakeFiles/Shapes_Blackboard.dir/src/Board/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Shapes_Blackboard.dir/src/Board/Board.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/Board/Board.cpp -o CMakeFiles/Shapes_Blackboard.dir/src/Board/Board.cpp.s

CMakeFiles/Shapes_Blackboard.dir/src/HorizontalLine/HorizontalLine.cpp.o: CMakeFiles/Shapes_Blackboard.dir/flags.make
CMakeFiles/Shapes_Blackboard.dir/src/HorizontalLine/HorizontalLine.cpp.o: /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/HorizontalLine/HorizontalLine.cpp
CMakeFiles/Shapes_Blackboard.dir/src/HorizontalLine/HorizontalLine.cpp.o: CMakeFiles/Shapes_Blackboard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Shapes_Blackboard.dir/src/HorizontalLine/HorizontalLine.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Shapes_Blackboard.dir/src/HorizontalLine/HorizontalLine.cpp.o -MF CMakeFiles/Shapes_Blackboard.dir/src/HorizontalLine/HorizontalLine.cpp.o.d -o CMakeFiles/Shapes_Blackboard.dir/src/HorizontalLine/HorizontalLine.cpp.o -c /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/HorizontalLine/HorizontalLine.cpp

CMakeFiles/Shapes_Blackboard.dir/src/HorizontalLine/HorizontalLine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Shapes_Blackboard.dir/src/HorizontalLine/HorizontalLine.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/HorizontalLine/HorizontalLine.cpp > CMakeFiles/Shapes_Blackboard.dir/src/HorizontalLine/HorizontalLine.cpp.i

CMakeFiles/Shapes_Blackboard.dir/src/HorizontalLine/HorizontalLine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Shapes_Blackboard.dir/src/HorizontalLine/HorizontalLine.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/HorizontalLine/HorizontalLine.cpp -o CMakeFiles/Shapes_Blackboard.dir/src/HorizontalLine/HorizontalLine.cpp.s

CMakeFiles/Shapes_Blackboard.dir/src/VerticalLine/VerticalLine.cpp.o: CMakeFiles/Shapes_Blackboard.dir/flags.make
CMakeFiles/Shapes_Blackboard.dir/src/VerticalLine/VerticalLine.cpp.o: /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/VerticalLine/VerticalLine.cpp
CMakeFiles/Shapes_Blackboard.dir/src/VerticalLine/VerticalLine.cpp.o: CMakeFiles/Shapes_Blackboard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Shapes_Blackboard.dir/src/VerticalLine/VerticalLine.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Shapes_Blackboard.dir/src/VerticalLine/VerticalLine.cpp.o -MF CMakeFiles/Shapes_Blackboard.dir/src/VerticalLine/VerticalLine.cpp.o.d -o CMakeFiles/Shapes_Blackboard.dir/src/VerticalLine/VerticalLine.cpp.o -c /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/VerticalLine/VerticalLine.cpp

CMakeFiles/Shapes_Blackboard.dir/src/VerticalLine/VerticalLine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Shapes_Blackboard.dir/src/VerticalLine/VerticalLine.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/VerticalLine/VerticalLine.cpp > CMakeFiles/Shapes_Blackboard.dir/src/VerticalLine/VerticalLine.cpp.i

CMakeFiles/Shapes_Blackboard.dir/src/VerticalLine/VerticalLine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Shapes_Blackboard.dir/src/VerticalLine/VerticalLine.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/VerticalLine/VerticalLine.cpp -o CMakeFiles/Shapes_Blackboard.dir/src/VerticalLine/VerticalLine.cpp.s

CMakeFiles/Shapes_Blackboard.dir/src/Rectangle/Rectangle.cpp.o: CMakeFiles/Shapes_Blackboard.dir/flags.make
CMakeFiles/Shapes_Blackboard.dir/src/Rectangle/Rectangle.cpp.o: /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/Rectangle/Rectangle.cpp
CMakeFiles/Shapes_Blackboard.dir/src/Rectangle/Rectangle.cpp.o: CMakeFiles/Shapes_Blackboard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Shapes_Blackboard.dir/src/Rectangle/Rectangle.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Shapes_Blackboard.dir/src/Rectangle/Rectangle.cpp.o -MF CMakeFiles/Shapes_Blackboard.dir/src/Rectangle/Rectangle.cpp.o.d -o CMakeFiles/Shapes_Blackboard.dir/src/Rectangle/Rectangle.cpp.o -c /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/Rectangle/Rectangle.cpp

CMakeFiles/Shapes_Blackboard.dir/src/Rectangle/Rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Shapes_Blackboard.dir/src/Rectangle/Rectangle.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/Rectangle/Rectangle.cpp > CMakeFiles/Shapes_Blackboard.dir/src/Rectangle/Rectangle.cpp.i

CMakeFiles/Shapes_Blackboard.dir/src/Rectangle/Rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Shapes_Blackboard.dir/src/Rectangle/Rectangle.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/Rectangle/Rectangle.cpp -o CMakeFiles/Shapes_Blackboard.dir/src/Rectangle/Rectangle.cpp.s

CMakeFiles/Shapes_Blackboard.dir/src/Circle/Circle.cpp.o: CMakeFiles/Shapes_Blackboard.dir/flags.make
CMakeFiles/Shapes_Blackboard.dir/src/Circle/Circle.cpp.o: /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/Circle/Circle.cpp
CMakeFiles/Shapes_Blackboard.dir/src/Circle/Circle.cpp.o: CMakeFiles/Shapes_Blackboard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Shapes_Blackboard.dir/src/Circle/Circle.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Shapes_Blackboard.dir/src/Circle/Circle.cpp.o -MF CMakeFiles/Shapes_Blackboard.dir/src/Circle/Circle.cpp.o.d -o CMakeFiles/Shapes_Blackboard.dir/src/Circle/Circle.cpp.o -c /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/Circle/Circle.cpp

CMakeFiles/Shapes_Blackboard.dir/src/Circle/Circle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Shapes_Blackboard.dir/src/Circle/Circle.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/Circle/Circle.cpp > CMakeFiles/Shapes_Blackboard.dir/src/Circle/Circle.cpp.i

CMakeFiles/Shapes_Blackboard.dir/src/Circle/Circle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Shapes_Blackboard.dir/src/Circle/Circle.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/Circle/Circle.cpp -o CMakeFiles/Shapes_Blackboard.dir/src/Circle/Circle.cpp.s

CMakeFiles/Shapes_Blackboard.dir/src/Triangle/Triangle.cpp.o: CMakeFiles/Shapes_Blackboard.dir/flags.make
CMakeFiles/Shapes_Blackboard.dir/src/Triangle/Triangle.cpp.o: /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/Triangle/Triangle.cpp
CMakeFiles/Shapes_Blackboard.dir/src/Triangle/Triangle.cpp.o: CMakeFiles/Shapes_Blackboard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Shapes_Blackboard.dir/src/Triangle/Triangle.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Shapes_Blackboard.dir/src/Triangle/Triangle.cpp.o -MF CMakeFiles/Shapes_Blackboard.dir/src/Triangle/Triangle.cpp.o.d -o CMakeFiles/Shapes_Blackboard.dir/src/Triangle/Triangle.cpp.o -c /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/Triangle/Triangle.cpp

CMakeFiles/Shapes_Blackboard.dir/src/Triangle/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Shapes_Blackboard.dir/src/Triangle/Triangle.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/Triangle/Triangle.cpp > CMakeFiles/Shapes_Blackboard.dir/src/Triangle/Triangle.cpp.i

CMakeFiles/Shapes_Blackboard.dir/src/Triangle/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Shapes_Blackboard.dir/src/Triangle/Triangle.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/Triangle/Triangle.cpp -o CMakeFiles/Shapes_Blackboard.dir/src/Triangle/Triangle.cpp.s

CMakeFiles/Shapes_Blackboard.dir/src/CLI/CLI.cpp.o: CMakeFiles/Shapes_Blackboard.dir/flags.make
CMakeFiles/Shapes_Blackboard.dir/src/CLI/CLI.cpp.o: /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/CLI/CLI.cpp
CMakeFiles/Shapes_Blackboard.dir/src/CLI/CLI.cpp.o: CMakeFiles/Shapes_Blackboard.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Shapes_Blackboard.dir/src/CLI/CLI.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Shapes_Blackboard.dir/src/CLI/CLI.cpp.o -MF CMakeFiles/Shapes_Blackboard.dir/src/CLI/CLI.cpp.o.d -o CMakeFiles/Shapes_Blackboard.dir/src/CLI/CLI.cpp.o -c /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/CLI/CLI.cpp

CMakeFiles/Shapes_Blackboard.dir/src/CLI/CLI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Shapes_Blackboard.dir/src/CLI/CLI.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/CLI/CLI.cpp > CMakeFiles/Shapes_Blackboard.dir/src/CLI/CLI.cpp.i

CMakeFiles/Shapes_Blackboard.dir/src/CLI/CLI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Shapes_Blackboard.dir/src/CLI/CLI.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/src/CLI/CLI.cpp -o CMakeFiles/Shapes_Blackboard.dir/src/CLI/CLI.cpp.s

# Object files for target Shapes_Blackboard
Shapes_Blackboard_OBJECTS = \
"CMakeFiles/Shapes_Blackboard.dir/src/main.cpp.o" \
"CMakeFiles/Shapes_Blackboard.dir/src/Board/Board.cpp.o" \
"CMakeFiles/Shapes_Blackboard.dir/src/HorizontalLine/HorizontalLine.cpp.o" \
"CMakeFiles/Shapes_Blackboard.dir/src/VerticalLine/VerticalLine.cpp.o" \
"CMakeFiles/Shapes_Blackboard.dir/src/Rectangle/Rectangle.cpp.o" \
"CMakeFiles/Shapes_Blackboard.dir/src/Circle/Circle.cpp.o" \
"CMakeFiles/Shapes_Blackboard.dir/src/Triangle/Triangle.cpp.o" \
"CMakeFiles/Shapes_Blackboard.dir/src/CLI/CLI.cpp.o"

# External object files for target Shapes_Blackboard
Shapes_Blackboard_EXTERNAL_OBJECTS =

Shapes_Blackboard: CMakeFiles/Shapes_Blackboard.dir/src/main.cpp.o
Shapes_Blackboard: CMakeFiles/Shapes_Blackboard.dir/src/Board/Board.cpp.o
Shapes_Blackboard: CMakeFiles/Shapes_Blackboard.dir/src/HorizontalLine/HorizontalLine.cpp.o
Shapes_Blackboard: CMakeFiles/Shapes_Blackboard.dir/src/VerticalLine/VerticalLine.cpp.o
Shapes_Blackboard: CMakeFiles/Shapes_Blackboard.dir/src/Rectangle/Rectangle.cpp.o
Shapes_Blackboard: CMakeFiles/Shapes_Blackboard.dir/src/Circle/Circle.cpp.o
Shapes_Blackboard: CMakeFiles/Shapes_Blackboard.dir/src/Triangle/Triangle.cpp.o
Shapes_Blackboard: CMakeFiles/Shapes_Blackboard.dir/src/CLI/CLI.cpp.o
Shapes_Blackboard: CMakeFiles/Shapes_Blackboard.dir/build.make
Shapes_Blackboard: CMakeFiles/Shapes_Blackboard.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Shapes_Blackboard"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Shapes_Blackboard.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Shapes_Blackboard.dir/build: Shapes_Blackboard
.PHONY : CMakeFiles/Shapes_Blackboard.dir/build

CMakeFiles/Shapes_Blackboard.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Shapes_Blackboard.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Shapes_Blackboard.dir/clean

CMakeFiles/Shapes_Blackboard.dir/depend:
	cd /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/cmake-build-debug /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/cmake-build-debug /Users/ivanyakovenko/CLionProjects/Shapes_Blackboard/cmake-build-debug/CMakeFiles/Shapes_Blackboard.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Shapes_Blackboard.dir/depend

