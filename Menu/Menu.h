//
// Created by kibbe on 4/3/2025.
//

#ifndef MENU_H
#define MENU_H

#include <string>

#include <imgui.h>

#include "../Util/Globals.h"
#include "../Util/game_thread.h"

namespace Menu {
    static inline bool bIsOpen = true;

    void Render();
}

#endif //MENU_H
