# CMakeList.txt : CMake project for linked_lists, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.27)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("linked_lists")

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
add_executable (linked_lists "list.cpp" "list.h" "lists.cpp")

# GoogleTest requires at least C++14
set_property(TARGET linked_lists PROPERTY CXX_STANDARD 20)
set_property(TARGET linked_lists PROPERTY CMAKE_CXX_STANDARD_REQUIRED ON)

target_link_libraries(
  linked_lists
  GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(linked_lists)