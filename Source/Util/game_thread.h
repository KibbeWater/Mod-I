//
// Created by kibbe on 2025-04-05.
//

#ifndef GAME_THREAD_H
#define GAME_THREAD_H

namespace game_thread {
    void execute(const std::function<void()>& lambda);
    void _processQueue();
}

#endif //GAME_THREAD_H
