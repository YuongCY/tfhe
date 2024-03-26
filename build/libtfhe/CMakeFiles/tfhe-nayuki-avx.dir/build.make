# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/yuong/tfhe/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yuong/tfhe/build

# Include any dependencies generated for this target.
include libtfhe/CMakeFiles/tfhe-nayuki-avx.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libtfhe/CMakeFiles/tfhe-nayuki-avx.dir/compiler_depend.make

# Include the progress variables for this target.
include libtfhe/CMakeFiles/tfhe-nayuki-avx.dir/progress.make

# Include the compile flags for this target's objects.
include libtfhe/CMakeFiles/tfhe-nayuki-avx.dir/flags.make

# Object files for target tfhe-nayuki-avx
tfhe__nayuki__avx_OBJECTS =

# External object files for target tfhe-nayuki-avx
tfhe__nayuki__avx_EXTERNAL_OBJECTS = \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/autogenerated.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/lwebootstrappingkey.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/lwe.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/lwe-functions.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/lwekey.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/lwekeyswitch.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/lweparams.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/lwesamples.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/multiplication.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/numeric-functions.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/polynomials.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/tgsw.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/tlwe.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/tlwe-functions.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/tgsw-functions.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/tlwe-fft-operations.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/tgsw-fft-operations.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/toruspolynomial-functions.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/boot-gates.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/lwe-keyswitch-functions.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/lwe-bootstrapping-functions.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/lwe-bootstrapping-functions-fft.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/tfhe_io.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/tfhe_generic_streams.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/tfhe_garbage_collector.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/tfhe_gate_bootstrapping.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-core.dir/tfhe_gate_bootstrapping_structures.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/fft_processors/nayuki/CMakeFiles/tfhe-fft-nayuki-avx.dir/fft-x8664-avx-aux.c.o" \
"/home/yuong/tfhe/build/libtfhe/fft_processors/nayuki/CMakeFiles/tfhe-fft-nayuki-avx.dir/fft-x8664-avx.s.o" \
"/home/yuong/tfhe/build/libtfhe/fft_processors/nayuki/CMakeFiles/tfhe-fft-nayuki-avx.dir/fft-x8664-avx-reverse.s.o" \
"/home/yuong/tfhe/build/libtfhe/fft_processors/nayuki/CMakeFiles/tfhe-fft-nayuki-avx.dir/fft_processor_nayuki.cpp.o" \
"/home/yuong/tfhe/build/libtfhe/fft_processors/nayuki/CMakeFiles/tfhe-fft-nayuki-avx.dir/lagrangehalfc_impl.cpp.o"

libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/autogenerated.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/lwebootstrappingkey.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/lwe.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/lwe-functions.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/lwekey.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/lwekeyswitch.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/lweparams.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/lwesamples.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/multiplication.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/numeric-functions.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/polynomials.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/tgsw.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/tlwe.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/tlwe-functions.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/tgsw-functions.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/tlwe-fft-operations.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/tgsw-fft-operations.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/toruspolynomial-functions.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/boot-gates.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/lwe-keyswitch-functions.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/lwe-bootstrapping-functions.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/lwe-bootstrapping-functions-fft.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/tfhe_io.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/tfhe_generic_streams.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/tfhe_garbage_collector.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/tfhe_gate_bootstrapping.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-core.dir/tfhe_gate_bootstrapping_structures.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/fft_processors/nayuki/CMakeFiles/tfhe-fft-nayuki-avx.dir/fft-x8664-avx-aux.c.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/fft_processors/nayuki/CMakeFiles/tfhe-fft-nayuki-avx.dir/fft-x8664-avx.s.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/fft_processors/nayuki/CMakeFiles/tfhe-fft-nayuki-avx.dir/fft-x8664-avx-reverse.s.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/fft_processors/nayuki/CMakeFiles/tfhe-fft-nayuki-avx.dir/fft_processor_nayuki.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/fft_processors/nayuki/CMakeFiles/tfhe-fft-nayuki-avx.dir/lagrangehalfc_impl.cpp.o
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-nayuki-avx.dir/build.make
libtfhe/libtfhe-nayuki-avx.so: libtfhe/CMakeFiles/tfhe-nayuki-avx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yuong/tfhe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX shared library libtfhe-nayuki-avx.so"
	cd /home/yuong/tfhe/build/libtfhe && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tfhe-nayuki-avx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libtfhe/CMakeFiles/tfhe-nayuki-avx.dir/build: libtfhe/libtfhe-nayuki-avx.so
.PHONY : libtfhe/CMakeFiles/tfhe-nayuki-avx.dir/build

libtfhe/CMakeFiles/tfhe-nayuki-avx.dir/clean:
	cd /home/yuong/tfhe/build/libtfhe && $(CMAKE_COMMAND) -P CMakeFiles/tfhe-nayuki-avx.dir/cmake_clean.cmake
.PHONY : libtfhe/CMakeFiles/tfhe-nayuki-avx.dir/clean

libtfhe/CMakeFiles/tfhe-nayuki-avx.dir/depend:
	cd /home/yuong/tfhe/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yuong/tfhe/src /home/yuong/tfhe/src/libtfhe /home/yuong/tfhe/build /home/yuong/tfhe/build/libtfhe /home/yuong/tfhe/build/libtfhe/CMakeFiles/tfhe-nayuki-avx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libtfhe/CMakeFiles/tfhe-nayuki-avx.dir/depend

