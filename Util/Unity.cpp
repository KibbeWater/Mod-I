//
// Created by kibbe on 2025-04-06.
//

std::vector<Unity::il2cppMethodInfo*> cachedMethods = std::vector<Unity::il2cppMethodInfo*>();

void UnityHelpers::Initialize() {
    cachedMethods.clear();

    auto classList = std::vector<Unity::il2cppClass*>();
    IL2CPP::Class::FetchClasses(&classList, "Assembly-CSharp", "ScheduleOne.Money");

    for (size_t i = 0; i < classList.size(); i++) {
        auto methodList = std::vector<Unity::il2cppMethodInfo*>();
        IL2CPP::Class::FetchMethods(classList[i], &methodList);

        for (size_t x = 0; x < methodList.size(); x++)
            if (methodList[x]->m_pName[0] > 64 && methodList[x]->m_pName[0] < 123)
                cachedMethods.push_back(methodList[x]);
    }
}

Unity::il2cppMethodInfo* UnityHelpers::FindMethod(const char* methodName, int args) {
    for (size_t i = 0; i < cachedMethods.size(); i++)
        if (!strcmp(methodName, cachedMethods[i]->m_pName) && (args == -1 || cachedMethods[i]->m_uArgsCount == args))
            return cachedMethods[i];
    return nullptr;
}

Unity::il2cppMethodInfo * UnityHelpers::FindMethod(const char *methodName, const char *className, int args) {
    for (size_t i = 0; i < cachedMethods.size(); i++)
        if (!strcmp(methodName, cachedMethods[i]->m_pName) && !strcmp(className, cachedMethods[i]->m_pClass->m_pName) && (args == -1 || cachedMethods[i]->m_uArgsCount == args))
            return cachedMethods[i];
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
