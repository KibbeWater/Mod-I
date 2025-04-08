//
// Created by kibbe on 2025-04-07.
//

#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

namespace Hook
{
    namespace TimeManager
    {
        inline void* pUpdate;
        void __fastcall hkUpdate(ScheduleOne_GameTime_TimeManager_o* pThis);
    }
}

#endif //TIMEMANAGER_H
