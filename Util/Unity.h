//
// Created by kibbe on 2025-04-06.
//

#ifndef UNITY_H
#define UNITY_H

namespace UnityHelpers {
    void Initialize();

    Unity::il2cppMethodInfo* FindMethod(const char* methodName, int args = -1);
    Unity::il2cppMethodInfo* FindMethodByClass(const char* methodName, const char* className, int args = -1);
    Unity::il2cppClass* FindClassByField(const char* fieldName, const char* methodName = "");
}

#endif //UNITY_H
