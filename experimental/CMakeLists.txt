# CMakeList.txt : CMake project for linked_lists, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.30)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("experimental")

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.16.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
)
FetchContent_MakeAvailable(fmt)

enable_testing()

# Add source to this project's executable.
add_executable (blocking_queue "blocking_queue.h" "blocking_queue_tests.cpp")

# GoogleTest requires at least C++14
set_property(TARGET blocking_queue PROPERTY CXX_STANDARD 20)
set_property(TARGET blocking_queue PROPERTY CMAKE_CXX_STANDARD_REQUIRED ON)

target_link_libraries(
  blocking_queue
  fmt::fmt
  GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(blocking_queue)