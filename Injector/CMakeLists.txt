# injector/CMakeLists.txt
project(Injector)

include(FetchContent)
FetchContent_Declare(
        Blackbone
        GIT_REPOSITORY https://github.com/DarthTon/Blackbone.git
        GIT_TAG        master  # Or specify a specific commit or tag
        SOURCE_SUBDIR  src
)
FetchContent_MakeAvailable(Blackbone)

target_include_directories(Injector ${BLACKBONE_BUILD_DIR})

# Define the Injector executable target
add_executable(Injector
        src/injector_main.cpp
        # add additional Injector source files as needed
)

target_link_libraries(Injector PRIVATE Blackbone)
