//
// Created by kibbe on 2025-04-04.
//

#ifndef HOOK_H
#define HOOK_H

// The inner macro performs the actual token pasting.
#define CREATE_HOOK_IMPL(method, Class, func) \
if (MH_CreateHook(method, (LPVOID)&Class::hk##func, &Class::p##func) != MH_OK) { \
return false; \
}

// The user-friendly macro that appears in your code.
#define CREATE_HOOK(method, Class, func) \
CREATE_HOOK_IMPL(method, Class, func)

// Inner macro to perform token pasting and stringizing.
#define CREATE_HOOK_H_IMPL(Class, func) \
if (MH_CreateHook(UnityHelpers::FindMethodByClass(#func, #Class)->m_pMethodPointer, (LPVOID)&Class::hk##func, &Class::p##func) != MH_OK) { \
return false; \
}

// User-facing macro that allows simpler syntax.
#define CREATE_HOOK_H(Class, func) CREATE_HOOK_H_IMPL(Class, func)

#define ORIGINAL_HOOK(func) \
    static auto o##func = reinterpret_cast<decltype(&hk##func)>(p##func);

namespace Hook {
    bool Init();
}

#endif //HOOK_H
