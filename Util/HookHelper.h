//
// Created by kibbe on 2025-04-12.
//

#ifndef HOOKHELPER_H
#define HOOKHELPER_H

namespace HookHelper {
    template<typename Ret, typename... Args>
    inline Ret call_original(void* pOriginal, Args&&... args) {
        using OriginalFunction = Ret(*)(Args...);
        // static variable so that reinterpret_cast is only done once,
        // similar to what you had in call_original.
        static OriginalFunction oOriginal = reinterpret_cast<OriginalFunction>(pOriginal);
        return oOriginal(std::forward<Args>(args)...);
    }
}

#endif //HOOKHELPER_H
