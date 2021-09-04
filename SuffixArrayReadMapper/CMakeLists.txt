# CMakeList.txt : CMake project for SuffixArrayReadMapper, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (SuffixArrayReadMapper "SuffixArrayReadMapper.cpp" "SuffixArrayReadMapper.h" "SuffixArray.h" "SuffixArray.cpp" "ParseFasta.h" "ParseFasta.cpp")

# TODO: Add tests and install targets if needed.
