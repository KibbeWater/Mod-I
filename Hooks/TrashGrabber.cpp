//
// Created by kibbe on 2025-04-10.
//

#include "pch.h"

int Hook::Equippable_TrashGrabber::hkGetCapacity(Unity::il2cppObject *pThis) {
    ORIGINAL_HOOK(GetCapacity);

    if (F::m_bEndlessGrabber)
        return 20;

    return oGetCapacity(pThis);
}
