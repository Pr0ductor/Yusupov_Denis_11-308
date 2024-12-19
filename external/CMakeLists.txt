include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
  SOURCE_DIR     ${PROJECT_SOURCE_DIR}/external/googletest
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED
        ../hw04/src/hw04.cpp
        ../hw04/src/hw04.cpp
        ../hw04/src/hw04.cpp
        ../hw04/src/hw04.cpp
        ../hw04/tests/hw04_test.cpp
        ../hw04/src/include/hw04.h
        ../hw04/src/include/hw04.h)
target_link_libraries(GTest::GTest INTERFACE gtest_main)