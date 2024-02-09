# CMakeList.txt : CMake project for arrays_and_strings, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.27)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("arrays_and_strings")

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add source to this project's executable.
add_executable (
  arrays_and_strings
  "is_unique_1_1.cpp"
  "check_permutation_1_2.cpp")

# GoogleTest requires at least C++14
set_property(TARGET arrays_and_strings PROPERTY CXX_STANDARD 20)
set_property(TARGET arrays_and_strings PROPERTY CMAKE_CXX_STANDARD_REQUIRED ON)

target_link_libraries(
  arrays_and_strings
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(arrays_and_strings)