# injector/CMakeLists.txt
project(Injector)

include(FetchContent)
FetchContent_Declare(
        blackbone
        GIT_REPOSITORY https://github.com/DarthTon/Blackbone.git
        GIT_TAG        master  # Or specify a specific commit or tag
        SOURCE_SUBDIR  src
)
FetchContent_MakeAvailable(blackbone)
message(STATUS "Blackbone source directory: ${blackbone_SOURCE_DIR}/src")

# Define the Injector executable target
add_executable(Injector
        src/injector_main.cpp
        # add additional Injector source files as needed
)

# Optionally remove this if Blackbone already sets include directories
target_include_directories(Injector PUBLIC ${blackbone_SOURCE_DIR}/src)

# Link against the correct Blackbone target (matching case)
target_link_libraries(Injector PRIVATE blackbone)
