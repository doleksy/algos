# CMakeList.txt : CMake project for sort, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.27)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("intro_to_algorithms_4th_ed")

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

add_executable(chapter2 "chapter2.cpp")
set_property(TARGET chapter2 PROPERTY CXX_STANDARD 20)
set_property(TARGET chapter2 PROPERTY CMAKE_CXX_STANDARD_REQUIRED ON)

target_link_libraries(
  chapter2
  GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(chapter2)
