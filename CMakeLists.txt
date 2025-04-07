cmake_minimum_required(VERSION 3.30)
project(Mod_I)

set(CMAKE_CXX_STANDARD 23)

# Fetch MinHook dependency
include(FetchContent)
FetchContent_Declare(
        MinHook
        GIT_REPOSITORY https://github.com/TsudaKageyu/minhook.git
        GIT_TAG master  # or use a specific commit/tag as needed
)
FetchContent_MakeAvailable(MinHook)

# Fetch Resolver dependency
#[[FetchContent_Declare(
        resolver
        GIT_REPOSITORY https://github.com/KibbeWater/IL2CPP_Resolver.git
        GIT_TAG main  # Use a specific commit/tag as needed
)
FetchContent_MakeAvailable(resolver)]]

# Fetch ImGui dependency
FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG master  # Use a specific commit/tag as needed
)
FetchContent_MakeAvailable(imgui)

# Fetch FreeType dependency
FetchContent_Declare(
        freetype
        GIT_REPOSITORY https://gitlab.freedesktop.org/freetype/freetype.git
        GIT_TAG        VER-2-13-2  # Update this tag for the desired version
)
FetchContent_MakeAvailable(freetype)

set(IMGUI_SOURCES
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_demo.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
        ${imgui_SOURCE_DIR}/misc/freetype/imgui_freetype.cpp
        ${imgui_SOURCE_DIR}/misc/freetype/imgui_freetype.h
        ${imgui_SOURCE_DIR}/misc/cpp/imgui_stdlib.cpp
        ${imgui_SOURCE_DIR}/misc/cpp/imgui_stdlib.h
        ${imgui_SOURCE_DIR}/backends/imgui_impl_dx11.cpp
        ${imgui_SOURCE_DIR}/backends/imgui_impl_win32.cpp
)

add_library(imgui STATIC ${IMGUI_SOURCES})

target_include_directories(imgui PUBLIC
        ${imgui_SOURCE_DIR}
        ${imgui_SOURCE_DIR}/backends
        ${imgui_SOURCE_DIR}/misc/freetype
)

target_compile_definitions(imgui PUBLIC IMGUI_ENABLE_FREETYPE)

target_link_libraries(imgui PUBLIC freetype)

set(RESOLVER_FILES
        /Resolver
)

add_library(Mod_I SHARED Main.cpp
        DX11/D3D11Hook.cpp
        DX11/D3D11Hook.h
        Util/Globals.h
        Menu/Menu.cpp
        Menu/Menu.h
        Kiero/kiero.cpp
        Kiero/kiero.h
        GameAPI/MoneyManager/MoneyManager.cpp
        GameAPI/MoneyManager/MoneyManager.h
        Hooks/Hook.cpp
        Hooks/Hook.h
        Util/il2cpp.h
        Hooks/MoneyManager.cpp
        Hooks/MoneyManager.h
        Util/Memory.cpp
        Util/Memory.h
        Util/game_thread.cpp
        Util/game_thread.h
        pch.h
        framework.h
        GameAPI/GameAPI.h
        Util/Unity.cpp
        Util/Unity.h
        Hooks/TimeManager.cpp
        Hooks/TimeManager.h
        Hooks/Player.cpp
        Hooks/Player.h
        GameAPI/InstanceFinder/Instance.cpp
        GameAPI/InstanceFinder/Instance.h
        GameAPI/NetworkManager/NetworkManager.cpp
        GameAPI/NetworkManager/NetworkManager.h
        GameAPI/Player/Player.cpp
        GameAPI/Player/Player.h
)

target_include_directories(Mod_I PUBLIC
        ./
        ${RESOLVER_FILES}
)

target_link_libraries(Mod_I PRIVATE minhook imgui)

if(WIN32)
    target_link_libraries(Mod_I PRIVATE d3d11 d3dcompiler dwmapi shell32 kernel32 user32 gdi32 winspool ole32 oleaut32 uuid comdlg32 advapi32)
endif()

target_precompile_headers(Mod_I PRIVATE pch.h)
