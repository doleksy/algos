# CMakeList.txt : CMake project for sort, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.27)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("educative")

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

add_executable(word_search "WordSearch.cpp")
set_property(TARGET word_search PROPERTY CXX_STANDARD 20)
set_property(TARGET word_search PROPERTY CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(n_queens "N_Queens.cpp")
set_property(TARGET n_queens PROPERTY CXX_STANDARD 20)
set_property(TARGET n_queens PROPERTY CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source to this project's executable.
add_executable (educative
    "HappyNumber.cpp"
)

# GoogleTest requires at least C++14
set_property(TARGET educative PROPERTY CXX_STANDARD 20)
set_property(TARGET educative PROPERTY CMAKE_CXX_STANDARD_REQUIRED ON)

target_link_libraries(
  educative
  GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(educative)
