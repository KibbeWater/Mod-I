//
// Created by kibbe on 2025-04-08.
//

#include "pch.h"

static const float minValue = 10;

typedef void (*fSetLocalPlayerBet)(ScheduleOne_Casino_BlackjackGameController_o *pThis, float bet);
typedef void (*fSetValueWithoutNotify)(UnityEngine_UI_Slider_o *pThis, float value);
void Hook::BlackjackInterface::hkBetSliderChanged(ScheduleOne_Casino_UI_BlackjackInterface_o* pThis, float amount) {
    ORIGINAL_HOOK(BetSliderChanged);

    const float maxValue = F::m_iBlackjackMaxBet;
    if (maxValue == 1000)
        return oBetSliderChanged(pThis, amount);

    auto _amount = lerp(minValue, maxValue, pow(pThis->fields.BetSlider->fields.m_Value, 2.0f));

    static fSetLocalPlayerBet oSetLocalPlayerBet = reinterpret_cast<fSetLocalPlayerBet>(
        UnityHelpers::FindMethodByClass("SetLocalPlayerBet", "BlackjackGameController")->m_pMethodPointer
    );

    static fSetValueWithoutNotify oSetValueWithoutNotify = reinterpret_cast<fSetValueWithoutNotify>(
        UnityHelpers::FindMethodByClass("SetValueWithoutNotify", "Slider")->m_pMethodPointer
    );

    oSetLocalPlayerBet(pThis->fields._CurrentGame_k__BackingField, _amount);
    oSetValueWithoutNotify(
        pThis->fields.BetSlider,
        std::sqrt((_amount - minValue) / (maxValue - minValue)));
}
