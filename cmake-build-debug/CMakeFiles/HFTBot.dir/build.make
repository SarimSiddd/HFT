# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /Users/muhammadsarimsiddiqui/CLionProjects/HFTBot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/muhammadsarimsiddiqui/CLionProjects/HFTBot/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HFTBot.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/HFTBot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HFTBot.dir/flags.make

CMakeFiles/HFTBot.dir/main.cpp.o: CMakeFiles/HFTBot.dir/flags.make
CMakeFiles/HFTBot.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/muhammadsarimsiddiqui/CLionProjects/HFTBot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HFTBot.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HFTBot.dir/main.cpp.o -c /Users/muhammadsarimsiddiqui/CLionProjects/HFTBot/main.cpp

CMakeFiles/HFTBot.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HFTBot.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/muhammadsarimsiddiqui/CLionProjects/HFTBot/main.cpp > CMakeFiles/HFTBot.dir/main.cpp.i

CMakeFiles/HFTBot.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HFTBot.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/muhammadsarimsiddiqui/CLionProjects/HFTBot/main.cpp -o CMakeFiles/HFTBot.dir/main.cpp.s

# Object files for target HFTBot
HFTBot_OBJECTS = \
"CMakeFiles/HFTBot.dir/main.cpp.o"

# External object files for target HFTBot
HFTBot_EXTERNAL_OBJECTS =

HFTBot: CMakeFiles/HFTBot.dir/main.cpp.o
HFTBot: CMakeFiles/HFTBot.dir/build.make
HFTBot: CMakeFiles/HFTBot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/muhammadsarimsiddiqui/CLionProjects/HFTBot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HFTBot"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HFTBot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HFTBot.dir/build: HFTBot
.PHONY : CMakeFiles/HFTBot.dir/build

CMakeFiles/HFTBot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HFTBot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HFTBot.dir/clean

CMakeFiles/HFTBot.dir/depend:
	cd /Users/muhammadsarimsiddiqui/CLionProjects/HFTBot/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/muhammadsarimsiddiqui/CLionProjects/HFTBot /Users/muhammadsarimsiddiqui/CLionProjects/HFTBot /Users/muhammadsarimsiddiqui/CLionProjects/HFTBot/cmake-build-debug /Users/muhammadsarimsiddiqui/CLionProjects/HFTBot/cmake-build-debug /Users/muhammadsarimsiddiqui/CLionProjects/HFTBot/cmake-build-debug/CMakeFiles/HFTBot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HFTBot.dir/depend
