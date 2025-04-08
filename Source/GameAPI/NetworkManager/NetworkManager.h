//
// Created by kibbe on 2025-04-07.
//

#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

namespace GameAPI {

class NetworkManager {
    FishNet_Managing_NetworkManager_o* _instance;

public:
    NetworkManager(FishNet_Managing_NetworkManager_o* instance);

private:
    FishNet_Managing_Client_ClientManager_o* GetClientManager() const;
    FishNet_Managing_Server_ServerManager_o* GetServerManager() const;

public:
    bool IsServer();
    bool IsClient();
    bool IsClientOnly();
    bool IsHost();
};

} // GameAPI

#endif //NETWORKMANAGER_H
