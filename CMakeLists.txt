cmake_minimum_required(VERSION 3.29)
project(hard_assert)

include(cmake/dependencies.cmake)

add_library(hard_assert source/hard_assert.c source/message_formatter/message_formatter.cpp)
target_include_directories(hard_assert PUBLIC include)

if(${BUILD_TESTING})
  setup_gtest(hard_assert)
endif()