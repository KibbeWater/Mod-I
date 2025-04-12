//
// Created by kibbe on 2025-04-10.
//

#include "pch.h"

void Hook::Equippable_Cuke::hkDrink(ScheduleOne_Equipping_Equippable_Cuke_o *pThis) {
    ORIGINAL_HOOK(Drink);

    if (F::m_bFastDrinker) {
        pThis->fields._IsDrinking_k__BackingField = false;
        pThis->fields.AnimationDuration = 0.01;
    }

    return oDrink(pThis);
}
