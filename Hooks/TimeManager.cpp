//
// Created by kibbe on 2025-04-07.
//

#include "pch.h"

void Hook::TimeManager::hkUpdate(ScheduleOne_GameTime_TimeManager_o *pThis) {
    static auto oUpdate = reinterpret_cast<decltype(&hkUpdate)>(pUpdate);

    Unity::CComponent* m_pTimeManager = UnityHelpers::GetComponentInstance("ScheduleOne.GameTime.TimeManager");
    auto time = m_pTimeManager->GetMemberValue<int>("CurrentTime");
    if (time == 400)
        m_pTimeManager->SetMemberValue<int>("CurrentTime", 600);

    std::cout << "Current Time: " << std::to_string(time) << std::endl;

    G::m_iGameTimeManager = pThis;

    return oUpdate(pThis);
}
