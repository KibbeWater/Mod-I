//
// Created by kibbe on 2025-04-08.
//

#include "pch.h"

static const float maxValue = 100000;
static const float minValue = 10;

float Hook::BlackjackInterface::hkGetBetFromSliderValue(ScheduleOne_Casino_UI_BlackjackInterface_o* pThis, float percent) {
    static auto oGetBetFromSliderValue = reinterpret_cast<decltype(&hkGetBetFromSliderValue)>(pGetBetFromSliderValue);

    return lerp(minValue, maxValue, pow(percent, 2.0f));
}
