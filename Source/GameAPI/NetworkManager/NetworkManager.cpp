//
// Created by kibbe on 2025-04-07.
//

#include "NetworkManager.h"

namespace GameAPI {
    NetworkManager::NetworkManager(FishNet_Managing_NetworkManager_o *instance) {
        this->_instance = instance;
    }

    FishNet_Managing_Client_ClientManager_o * NetworkManager::GetClientManager() const {
        return this->_instance->fields._ClientManager_k__BackingField;
    }

    FishNet_Managing_Server_ServerManager_o * NetworkManager::GetServerManager() const {
        return this->_instance->fields._ServerManager_k__BackingField;
    }

    bool NetworkManager::IsServer() {
        return this->GetServerManager()->fields._Started_k__BackingField;
    }

    bool NetworkManager::IsClient() {
        auto client = this->GetClientManager()->fields;
        return client._Started_k__BackingField && client.Connection->fields._Authenticated_k__BackingField;
    }

    bool NetworkManager::IsClientOnly() {
        return !this->IsServer() && this->IsClient();
    }

    bool NetworkManager::IsHost() {
        return this->IsServer() && this->IsClient();
    }
} // GameAPI