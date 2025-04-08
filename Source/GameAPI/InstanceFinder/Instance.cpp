//
// Created by kibbe on 2025-04-07.
//

#include "pch.h"

namespace GameAPI {
    Instance::Instance(FishNet_InstanceFinder_c *instance) {
        _instance = instance;
    }

    Instance *Instance::GetInstance() {
        static FishNet_InstanceFinder_c *instance = reinterpret_cast<FishNet_InstanceFinder_c*>(
            IL2CPP::Class::Find("FishNet.InstanceFinder"));
        static Instance* instanceClass = new Instance(instance);

        return instanceClass;
    }

    NetworkManager Instance::GetNetworkManager() {
        return NetworkManager(this->_instance->static_fields->_networkManager);
    }

    bool Instance::IsServer() {
        return GetNetworkManager().IsServer();
    }
    bool Instance::IsClient() {
        return GetNetworkManager().IsClient();
    }
    bool Instance::IsClientOnly() {
        return GetNetworkManager().IsClientOnly();
    }
    bool Instance::IsHost() {
        return GetNetworkManager().IsHost();
    }
}
