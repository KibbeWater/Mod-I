//
// Created by kibbe on 2025-04-07.
//

#include "pch.h"

typedef void (*fFastForwardToWakeTime)(ScheduleOne_GameTime_TimeManager_o *pThis);
void Hook::TimeManager::hkUpdate(ScheduleOne_GameTime_TimeManager_o *pThis) {
    ORIGINAL_HOOK(Update);

    Unity::CComponent* m_pTimeManager = UnityHelpers::GetComponentInstance("ScheduleOne.GameTime.TimeManager");
    auto time = m_pTimeManager->GetMemberValue<int>("CurrentTime");
    if (time == 400 && F::m_bTimeRollover) {
        static fFastForwardToWakeTime ffMethod = reinterpret_cast<fFastForwardToWakeTime>(m_pTimeManager->GetMethodPointer("FastForwardToWakeTime"));
        ffMethod(pThis);
    }

    std::cout << "Current Time: " << std::to_string(time) << std::endl;

    G::m_iGameTimeManager = pThis;

    return oUpdate(pThis);
}
