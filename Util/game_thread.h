//
// Created by kibbe on 2025-04-05.
//

#ifndef GAME_THREAD_H
#define GAME_THREAD_H

#include <windows.h>
#include <functional>
#include <iostream>
#include <tlhelp32.h>

namespace game_thread {
    bool execute(const std::function<void()>& lambda);
    bool init(DWORD targetProcessId = GetCurrentProcessId());
    DWORD get_thread_id();
}

#endif //GAME_THREAD_H
