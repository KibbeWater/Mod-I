//
// Created by kibbe on 2025-04-06.
//

#ifndef UNITY_H
#define UNITY_H

namespace UnityHelpers {
    enum RPC {
        Logic,
        Writer,
        Reader,
    };

    void Initialize();

    Unity::il2cppMethodInfo* FindMethod(const char* methodName, int args = -1);
    Unity::il2cppMethodInfo* FindMethodByClass(const char* methodName, const char* className, int args = -1);
    Unity::il2cppClass* FindClassByMethod(const char* methodName, const char* className, int args = -1);
    Unity::il2cppClass* FindClassByField(const char* fieldName, const char* methodName = "");

    Unity::il2cppMethodInfo* FindRPCMethod(RPC rpcType, Unity::il2cppClass* rpcClass, const char* methodName);

    Unity::CComponent* GetComponentInstance(const char* systemType);
    void NotifyEnvReset();
}

#endif //UNITY_H
