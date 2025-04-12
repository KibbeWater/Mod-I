//
// Created by kibbe on 2025-04-08.
//

#include "pch.h"

bool Hook::PursuitBehaviour::hkCanShoot(Unity::il2cppClass* pThis) {
    ORIGINAL_HOOK(CanShoot);

    if (F::m_bCopAlwaysShoot)
        return true;

    return oCanShoot(pThis);
}
