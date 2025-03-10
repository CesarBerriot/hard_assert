include(FetchContent)

FetchContent_Declare(
  SetupGTest
  GIT_REPOSITORY https://github.com/CesarBerriot/SetupGTest.git
  GIT_TAG 1.0.0
)

FetchContent_MakeAvailable(SetupGTest)

include(SetupGTest)