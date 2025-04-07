//
// Created by kibbe on 2025-04-07.
//

#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H

namespace GameAPI {

class Player {
    static ScheduleOne_PlayerScripts_Player_c* GetPlayerClass();

    ScheduleOne_PlayerScripts_Player_o* _instance;

    Player(ScheduleOne_PlayerScripts_Player_o* instance);

public:
    static std::vector<Player> GetAllPlayers();
    static Player* GetLocalPlayer();

    bool IsLocalPlayer();
    bool IsReadyToSleep();
};

} // GameAPI

#endif //PLAYERCLASS_H
