```cmake
    include(FetchContent)

    FetchContent_Declare(
        hard_assert
        GIT_REPOSITORY https://github.com/CesarBerriot/hard_assert.git
        GIT_TAG 1.1.0
    )
    FetchContent_MakeAvailable(hard_assert)

    target_link_libraries(PROJECT_NAME PRIVATE hard_assert)
```