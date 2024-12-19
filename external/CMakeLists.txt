include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
  SOURCE_DIR     ${PROJECT_SOURCE_DIR}/external/googletest
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED
        ../hw03/src/hw03.cpp)
target_link_libraries(GTest::GTest INTERFACE gtest_main)