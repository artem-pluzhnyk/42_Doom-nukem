# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Users/apluzhni/.brew/Cellar/cmake/3.15.3/bin/cmake

# The command to remove a file.
RM = /Users/apluzhni/.brew/Cellar/cmake/3.15.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/apluzhni/Desktop/doom-nukem/libzip

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/apluzhni/Desktop/doom-nukem/libzip/build

# Utility rule file for cleanup.

# Include the progress variables for this target.
include regress/CMakeFiles/cleanup.dir/progress.make

regress/CMakeFiles/cleanup:
	cd /Users/apluzhni/Desktop/doom-nukem/libzip/build/regress && /Users/apluzhni/.brew/Cellar/cmake/3.15.3/bin/cmake -DDIR=/Users/apluzhni/Desktop/doom-nukem/libzip/build/regress -P /Users/apluzhni/Desktop/doom-nukem/libzip/regress/cleanup.cmake

cleanup: regress/CMakeFiles/cleanup
cleanup: regress/CMakeFiles/cleanup.dir/build.make

.PHONY : cleanup

# Rule to build all files generated by this target.
regress/CMakeFiles/cleanup.dir/build: cleanup

.PHONY : regress/CMakeFiles/cleanup.dir/build

regress/CMakeFiles/cleanup.dir/clean:
	cd /Users/apluzhni/Desktop/doom-nukem/libzip/build/regress && $(CMAKE_COMMAND) -P CMakeFiles/cleanup.dir/cmake_clean.cmake
.PHONY : regress/CMakeFiles/cleanup.dir/clean

regress/CMakeFiles/cleanup.dir/depend:
	cd /Users/apluzhni/Desktop/doom-nukem/libzip/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/apluzhni/Desktop/doom-nukem/libzip /Users/apluzhni/Desktop/doom-nukem/libzip/regress /Users/apluzhni/Desktop/doom-nukem/libzip/build /Users/apluzhni/Desktop/doom-nukem/libzip/build/regress /Users/apluzhni/Desktop/doom-nukem/libzip/build/regress/CMakeFiles/cleanup.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : regress/CMakeFiles/cleanup.dir/depend

