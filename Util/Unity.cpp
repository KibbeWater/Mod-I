//
// Created by kibbe on 2025-04-06.
//

std::vector<Unity::il2cppMethodInfo*> cachedMethods = std::vector<Unity::il2cppMethodInfo*>();

void cacheModule(const char *moduleName) {
    auto classList = std::vector<Unity::il2cppClass*>();
    IL2CPP::Class::FetchClasses(&classList, moduleName, nullptr);

    for (size_t i = 0; i < classList.size(); i++) {
        auto methodList = std::vector<Unity::il2cppMethodInfo*>();
        IL2CPP::Class::FetchMethods(classList[i], &methodList);

        for (size_t x = 0; x < methodList.size(); x++)
            if (methodList[x]->m_pName[0] > 64 && methodList[x]->m_pName[0] < 123)
                cachedMethods.push_back(methodList[x]);
    }
}

void UnityHelpers::Initialize() {
    cachedMethods.clear();

    cacheModule("Assembly-CSharp");
    cacheModule("FishNet.Runtime");
}

Unity::il2cppMethodInfo* UnityHelpers::FindMethod(const char* methodName, int args) {
    for (size_t i = 0; i < cachedMethods.size(); i++)
        if (!strcmp(methodName, cachedMethods[i]->m_pName) && (args == -1 || cachedMethods[i]->m_uArgsCount == args))
            return cachedMethods[i];
    return nullptr;
}

Unity::il2cppMethodInfo * UnityHelpers::FindMethodByClass(const char *methodName, const char *className, int args) {
    for (size_t i = 0; i < cachedMethods.size(); i++)
        if (!strcmp(methodName, cachedMethods[i]->m_pName) && !strcmp(className, cachedMethods[i]->m_pClass->m_pName) && (args == -1 || cachedMethods[i]->m_uArgsCount == args))
            return cachedMethods[i];
    return nullptr;
}

Unity::il2cppClass * UnityHelpers::FindClassByMethod(const char *methodName, const char *className, int args) {
    for (size_t i = 0; i < cachedMethods.size(); i++)
        if (!strcmp(methodName, cachedMethods[i]->m_pName) && !strcmp(className, cachedMethods[i]->m_pClass->m_pName) && (args == -1 || cachedMethods[i]->m_uArgsCount == args))
            return cachedMethods[i]->m_pClass;
    return nullptr;
}

Unity::il2cppClass* UnityHelpers::FindClassByField(const char* fieldName, const char* methodName) {
    for (size_t i = 0; i < cachedMethods.size(); i++)
        if (strcmp(methodName, "") == 0 || strcmp(methodName, cachedMethods[i]->m_pName) == 0) {
            auto fields = std::vector<Unity::il2cppFieldInfo*>();
            IL2CPP::Class::FetchFields(cachedMethods[i]->m_pClass, &fields);

            for (size_t x = 0; x < fields.size(); x++)
                if (!strcmp(fieldName, fields[x]->m_pName))
                    return fields[x]->m_pParentClass;
        }
    return nullptr;
}

Unity::il2cppMethodInfo* UnityHelpers::FindRPCMethod(RPC rpcType, Unity::il2cppClass *rpcClass, const char *methodName) {
    auto methodList = std::vector<Unity::il2cppMethodInfo*>();
    IL2CPP::Class::FetchMethods(rpcClass, &methodList);

    std::string rpcName;
    switch (rpcType) {
        case Logic:
            rpcName = "RpcLogic";
        break;

        case Reader:
            rpcName = "RpcReader";
        break;

        case Writer:
            rpcName = "RpcWriter";
        break;

        default:
            return nullptr;
    }

    for (size_t i = 0; i < methodList.size(); i++) {
        if (methodList[i]->m_pName[0] > 64 && methodList[i]->m_pName[0] < 123) {
            std::string _methodName = methodList[i]->m_pName;
            if (_methodName.starts_with(rpcName) && _methodName.contains(methodName)) {
                return methodList[i];
            }
        }
    }

    return nullptr;
}

std::map<std::string, Unity::il2cppObject*> m_vTypeCache;
std::map<std::string, Unity::CComponent*> m_vComponentCache;

Unity::CComponent* UnityHelpers::GetComponentInstance(const char* systemType) {
    Unity::CComponent* m_pComponent = m_vComponentCache[systemType];
    if (m_pComponent != nullptr) return m_pComponent;

    Unity::il2cppObject* m_pSystemType = m_vTypeCache[systemType];
    if (!m_pSystemType) {
        Unity::il2cppClass* m_pSystemTypeClass = IL2CPP::Class::Find(systemType);
        auto _m_pSystemType = IL2CPP::Class::GetSystemType(m_pSystemTypeClass);

        m_vTypeCache[systemType] = _m_pSystemType;
        m_pSystemType = _m_pSystemType;
    }

    auto m_pComponents = Unity::Object::FindObjectsOfType<Unity::CComponent>(m_pSystemType);
    if (m_pComponents->m_uMaxLength == 0) return nullptr;

    m_pComponent = m_pComponents->At(0);
    m_vComponentCache[systemType] = m_pComponent;
    return m_pComponent;
}

void UnityHelpers::NotifyEnvReset() {
    m_vTypeCache.clear();
    m_vComponentCache.clear();
}
