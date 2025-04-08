//
// Created by kibbe on 2025-04-07.
//

#ifndef INSTANCE_H
#define INSTANCE_H

namespace GameAPI {
    class Instance {
        FishNet_InstanceFinder_c* _instance;

    public:
        Instance(FishNet_InstanceFinder_c* instance);

        static Instance* GetInstance();
        NetworkManager GetNetworkManager();

        bool IsServer();
        bool IsClient();
        bool IsClientOnly();
        bool IsHost();
    };
}

#endif //INSTANCE_H
