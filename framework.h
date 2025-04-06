//
// Created by kibbe on 2025-04-06.
//

#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <stdint.h>
#include <Windows.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <mutex>
#include <dxgi.h>
#include <d3d11.h>

// Third party libs
#include <MinHook.h>
#include "Resolver/IL2CPP_Resolver.hpp"
#include "Kiero/kiero.h"

// ImGUI
#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>

// Utils
#include "Util/il2cpp.h"
#include "Util/Globals.h"
#include "Util/Memory.h"
#include "Util/game_thread.h"

// GameAPI
#include "GameAPI/GameAPI.h"

// DX11
#include "DX11/D3D11Hook.h"

// Hooks
#include "Hooks/MoneyManager.h"
#include "Hooks/Hook.h"

// Menu
#include "Menu/Menu.h"

#endif //FRAMEWORK_H
