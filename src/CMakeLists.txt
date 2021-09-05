# CMakeList.txt : CMake project for SuffixArrayReadMapper, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)


# Include sub-projects.
add_subdirectory (SuffixArrayReadMapper)

# Add source to this project's executable.
add_executable (BasicReadMapper "main.cpp" "main.h" "SuffixArrayReadMapper/SuffixArrayReadMapper.cpp" "SuffixArrayReadMapper/SuffixArrayReadMapper.h" "SuffixArrayReadMapper/SuffixArray.h" "SuffixArrayReadMapper/SuffixArray.cpp" "SuffixArrayReadMapper/ParseFasta.h" "SuffixArrayReadMapper/ParseFasta.cpp" "SuffixArrayReadMapper/SuffixArraySearch.h" "SuffixArrayReadMapper/SuffixArraySearch.cpp")

