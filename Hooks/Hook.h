//
// Created by kibbe on 2025-04-04.
//

#ifndef HOOK_H
#define HOOK_H

#define DO_HOOK(FuncAdr, Class, Function) if (MH_CreateHook(FuncAdr, (LPVOID)&##Class##::hk##Function##, &##Class##::p##Function##) != MH_OK) { return false; }

#define CREATE_HOOK(method, original, hook) \
if (MH_CreateHook(method->m_pMethodPointer, (LPVOID) &hook, &original) != MH_OK) { \
return false; \
}

namespace Hook {
    bool Init();
}

#endif //HOOK_H
