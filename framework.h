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
#include <map>
#include <mutex>
#include <dxgi.h>
#include <d3d11.h>
#include <functional>

// Third party libs
#include <MinHook.h>
#include "Resolver/IL2CPP_Resolver.hpp"
#include "Kiero/kiero.h"

// ImGUI
#include <imgui.h>
#include <imgui_stdlib.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>

// Utils
#include "Util/il2cpp.h"
#include "Util/Globals.h"
#include "Util/Memory.h"
#include "Util/game_thread.h"
#include "Util/Unity.h"
#include "Util/HookHelper.h"

// GameAPI
#include "GameAPI/GameAPI.h"

// DX11
#include "DX11/D3D11Hook.h"

// Hooks
#include "Hooks/BlackjackInterface.h"
#include "Hooks/PursuitBehaviour.h"
#include "Hooks/PlayerInventory.h"
#include "Hooks/TrashGrabber.h"
#include "Hooks/MoneyManager.h"
#include "Hooks/TimeManager.h"
#include "Hooks/Player.h"
#include "Hooks/Cuke.h"
#include "Hooks/Hook.h"

// Menu
#include "Menu/Menu.h"

#endif //FRAMEWORK_H
