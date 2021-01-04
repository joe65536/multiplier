cmake_minimum_required(VERSION 3.11)
Project(multiplier)
enable_testing()
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()
add_executable(multiplier_test multiplier_test.cpp multiplier_impl.cpp multiplier_opti.cpp)
target_link_libraries(multiplier_test gtest gmock gtest_main)
add_test(multiplier_test multiplier_test)
