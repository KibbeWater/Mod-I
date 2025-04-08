//
// Created by kibbe on 2025-04-08.
//

#ifndef BLACKJACKINTERFACE_H
#define BLACKJACKINTERFACE_H

namespace Hook
{
    namespace BlackjackInterface
    {
        inline void* pGetBetFromSliderValue;
        float hkGetBetFromSliderValue(ScheduleOne_Casino_UI_BlackjackInterface_o* pThis, float percent);
    }
}

#endif //BLACKJACKINTERFACE_H
