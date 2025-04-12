//
// Created by kibbe on 2025-04-12.
//

#include "pch.h"

/*template<typename Ret, typename... Args>
inline Ret HookHelper::call_original(void* pOriginal, Args&&... args) {
    using OriginalFunction = Ret(*)(Args...);
    // static variable so that reinterpret_cast is only done once,
    // similar to what you had in call_original.
    static OriginalFunction oOriginal = reinterpret_cast<OriginalFunction>(pOriginal);
    return oOriginal(std::forward<Args>(args)...);
}*/
