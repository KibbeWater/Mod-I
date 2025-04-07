//
// Created by kibbe on 2025-04-04.
//

#ifndef IL2CPP_H
#define IL2CPP_H

typedef void(*Il2CppMethodPointer)();

struct MethodInfo;

struct VirtualInvokeData
{
    Il2CppMethodPointer methodPtr;
    const MethodInfo* method;
};

struct Il2CppType
{
    void* data;
    unsigned int bits;
};

struct Il2CppClass;

struct Il2CppObject
{
    Il2CppClass *klass;
    void *monitor;
};

union Il2CppRGCTXData
{
    void* rgctxDataDummy;
    const MethodInfo* method;
    const Il2CppType* type;
    Il2CppClass* klass;
};

struct Il2CppRuntimeInterfaceOffsetPair
{
    Il2CppClass* interfaceType;
    int32_t offset;
};
struct Il2CppClass_1
{
    void* image;
    void* gc_desc;
    const char* name;
    const char* namespaze;
    Il2CppType byval_arg;
    Il2CppType this_arg;
    Il2CppClass* element_class;
    Il2CppClass* castClass;
    Il2CppClass* declaringType;
    Il2CppClass* parent;
    void *generic_class;
    void* typeMetadataHandle;
    void* interopData;
    Il2CppClass* klass;
    void* fields;
    void* events;
    void* properties;
    void* methods;
    Il2CppClass** nestedTypes;
    Il2CppClass** implementedInterfaces;
    Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
};

struct Il2CppClass_2
{
    Il2CppClass** typeHierarchy;
    void *unity_user_data;
    uint32_t initializationExceptionGCHandle;
    uint32_t cctor_started;
    uint32_t cctor_finished;
    size_t cctor_thread;
    void* genericContainerHandle;
    uint32_t instance_size;
    uint32_t actualSize;
    uint32_t element_size;
    int32_t native_size;
    uint32_t static_fields_size;
    uint32_t thread_static_fields_size;
    int32_t thread_static_fields_offset;
    uint32_t flags;
    uint32_t token;
    uint16_t method_count;
    uint16_t property_count;
    uint16_t field_count;
    uint16_t event_count;
    uint16_t nested_type_count;
    uint16_t vtable_count;
    uint16_t interfaces_count;
    uint16_t interface_offsets_count;
    uint8_t typeHierarchyDepth;
    uint8_t genericRecursionDepth;
    uint8_t rank;
    uint8_t minimumAlignment;
    uint8_t naturalAligment;
    uint8_t packingSize;
    uint8_t bitflags1;
    uint8_t bitflags2;
};

struct Il2CppClass
{
    Il2CppClass_1 _1;
    void* static_fields;
    Il2CppRGCTXData* rgctx_data;
    Il2CppClass_2 _2;
    VirtualInvokeData vtable[255];
};

struct il2cppClass
{
	void* m_pImage;
	void* m_pGC;
	const char* m_pName;
	const char* m_pNamespace;
	void* m_pValue;
	void* m_pArgs;
	il2cppClass* m_pElementClass;
	il2cppClass* m_pCastClass;
	il2cppClass* m_pDeclareClass;
	il2cppClass* m_pParentClass;
	void* m_pGenericClass;
	void* m_pTypeDefinition;
	void* m_pInteropData;
	void* m_pFields;
	void* m_pEvents;
	void* m_pProperties;
	void** m_pMethods;
	il2cppClass** m_pNestedTypes;
	il2cppClass** m_ImplementedInterfaces;
	void* m_pInterfaceOffsets;
	void* m_pStaticFields;
	void* m_pRGCTX;
};

struct il2cppObject
{
	il2cppClass* m_pClass = nullptr;
	void* m_pMonitor = nullptr;
};

struct System_String : il2cppObject
{
	int m_iLength;
	wchar_t m_wString[1024];

	void Clear()
	{
		if (!this) return;

		memset(m_wString, 0, static_cast<size_t>(m_iLength) * 2);
		m_iLength = 0;
	}

	std::string ToString()
	{
		if (!this) return "";

		std::string sRet(static_cast<size_t>(m_iLength + 1) * 4, '\0');
		WideCharToMultiByte(CP_UTF8, 0, m_wString, m_iLength, &sRet[0], static_cast<int>(sRet.size()), 0, 0);
		return sRet;
	}
};

struct UnityEngine_Object_Fields {
	intptr_t m_CachedPtr;
};

struct UnityEngine_Component_Fields : UnityEngine_Object_Fields {
};

struct UnityEngine_Behaviour_Fields : UnityEngine_Component_Fields {
};

struct UnityEngine_MonoBehaviour_Fields : UnityEngine_Behaviour_Fields {
	struct System_Threading_CancellationTokenSource_o* m_CancellationTokenSource;
};

struct UnityEngine_Vector3_Fields {
	float x;
	float y;
	float z;
};
struct UnityEngine_Vector3_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
	VirtualInvokeData _5_ToString;
};
struct UnityEngine_Vector3_c {
	Il2CppClass_1 _1;
	struct UnityEngine_Vector3_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Vector3_VTable vtable;
};
struct UnityEngine_Vector3_o {
	UnityEngine_Vector3_Fields fields;
};
struct UnityEngine_Vector3_StaticFields {
	struct UnityEngine_Vector3_o zeroVector;
	struct UnityEngine_Vector3_o oneVector;
	struct UnityEngine_Vector3_o upVector;
	struct UnityEngine_Vector3_o downVector;
	struct UnityEngine_Vector3_o leftVector;
	struct UnityEngine_Vector3_o rightVector;
	struct UnityEngine_Vector3_o forwardVector;
	struct UnityEngine_Vector3_o backVector;
	struct UnityEngine_Vector3_o positiveInfinityVector;
	struct UnityEngine_Vector3_o negativeInfinityVector;
};

struct UnityEngine_Quaternion_Fields {
	float x;
	float y;
	float z;
	float w;
};
struct UnityEngine_Quaternion_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
	VirtualInvokeData _5_ToString;
};
struct UnityEngine_Quaternion_c {
	Il2CppClass_1 _1;
	struct UnityEngine_Quaternion_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Quaternion_VTable vtable;
};
struct UnityEngine_Quaternion_o {
	UnityEngine_Quaternion_Fields fields;
};
struct UnityEngine_Quaternion_StaticFields {
	struct UnityEngine_Quaternion_o identityQuaternion;
};

struct FishNet_Object_NetworkBehaviour_Fields : UnityEngine_MonoBehaviour_Fields {
	bool _OnStartServerCalled_k__BackingField;
	bool _OnStartClientCalled_k__BackingField;
	bool _onStartNetworkCalled;
	bool _onStopNetworkCalled;
	uint8_t _componentIndexCache;
	struct FishNet_Managing_Transporting_TransportManager_o* _transportManagerCache;
	struct FishNet_Object_NetworkObject_o* _networkObjectCache;
	bool _initializedOnceServer;
	bool _initializedOnceClient;
	bool ClientHasReconcileData;
	uint32_t _lastReplicateTick;
	bool _IsReconciling_k__BackingField;
	struct System_Collections_Generic_Dictionary_uint__ReplicateRpcDelegate__o* _replicateRpcDelegates;
	struct System_Collections_Generic_Dictionary_uint__ReconcileRpcDelegate__o* _reconcileRpcDelegates;
	bool _predictionInitialized;
	struct UnityEngine_Rigidbody_o* _predictionRigidbody;
	struct UnityEngine_Rigidbody2D_o* _predictionRigidbody2d;
	struct UnityEngine_Vector3_o _lastMayChangePosition;
	struct UnityEngine_Quaternion_o _lastMayChangeRotation;
	struct UnityEngine_Vector3_o _lastMayChangeScale;
	int32_t _remainingResends;
	uint32_t _lastSentReplicateTick;
	uint32_t _lastReceivedReplicateTick;
	uint32_t _lastReceivedReconcileTick;
	uint32_t _lastReconcileTick;
	struct System_Collections_Generic_Dictionary_uint__RpcLinkType__o* _rpcLinks;
	struct System_Collections_Generic_Dictionary_uint__ServerRpcDelegate__o* _serverRpcDelegates;
	struct System_Collections_Generic_Dictionary_uint__ClientRpcDelegate__o* _observersRpcDelegates;
	struct System_Collections_Generic_Dictionary_uint__ClientRpcDelegate__o* _targetRpcDelegates;
	uint32_t _rpcMethodCount;
	uint8_t _rpcHashSize;
	struct System_Collections_Generic_Dictionary_uint__NetworkBehaviour_BufferedRpc__o* _bufferedRpcs;
	struct System_Collections_Generic_HashSet_NetworkConnection__o* _networkConnectionCache;
	struct FishNet_Object_NetworkBehaviour_SyncTypeWriter_array* _syncTypeWriters;
	struct System_Collections_Generic_Dictionary_uint__SyncBase__o* _syncVars;
	bool SyncVarDirty;
	struct System_Collections_Generic_Dictionary_uint__SyncBase__o* _syncObjects;
	bool SyncObjectDirty;
	struct System_Collections_Generic_List_SyncVarReadDelegate__o* _syncVarReadDelegates;
};

struct ScheduleOne_DevUtilities_NetworkSingleton_MoneyManager__Fields : FishNet_Object_NetworkBehaviour_Fields {
	bool Destroyed;
	bool NetworkInitialize___EarlyScheduleOne_DevUtilities_NetworkSingleton_1Assembly_CSharp_dll_Excuted;
	bool NetworkInitialize__LateScheduleOne_DevUtilities_NetworkSingleton_1Assembly_CSharp_dll_Excuted;
};

struct ScheduleOne_Money_MoneyManager_Fields : ScheduleOne_DevUtilities_NetworkSingleton_MoneyManager__Fields {
	struct System_Collections_Generic_List_Transaction__o* ledger;
	float onlineBalance;
	float lifetimeEarnings;
	float _LastCalculatedNetworth_k__BackingField;
	struct ScheduleOne_Audio_AudioSourceController_o* CashSound;
	struct UnityEngine_GameObject_o* moneyChangePrefab;
	struct UnityEngine_GameObject_o* cashChangePrefab;
	struct UnityEngine_Sprite_o* LaunderingNotificationIcon;
	struct System_Action_MoneyManager_FloatContainer__o* onNetworthCalculation;
	struct ScheduleOne_Persistence_Loaders_MoneyLoader_o* loader;
	struct System_Collections_Generic_List_string__o* _LocalExtraFiles_k__BackingField;
	struct System_Collections_Generic_List_string__o* _LocalExtraFolders_k__BackingField;
	bool _HasChanged_k__BackingField;
	struct FishNet_Object_Synchronizing_SyncVar_float__o* syncVar___onlineBalance;
	struct FishNet_Object_Synchronizing_SyncVar_float__o* syncVar___lifetimeEarnings;
	bool NetworkInitialize___EarlyScheduleOne_Money_MoneyManagerAssembly_CSharp_dll_Excuted;
	bool NetworkInitialize__LateScheduleOne_Money_MoneyManagerAssembly_CSharp_dll_Excuted;
};
struct ScheduleOne_Money_MoneyManager_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_OnStartNetwork;
	VirtualInvokeData _5_OnStopNetwork;
	VirtualInvokeData _6_OnStartServer;
	VirtualInvokeData _7_OnStopServer;
	VirtualInvokeData _8_OnOwnershipServer;
	VirtualInvokeData _9_OnSpawnServer;
	VirtualInvokeData _10_OnDespawnServer;
	VirtualInvokeData _11_OnStartClient;
	VirtualInvokeData _12_Save;
	VirtualInvokeData _13_WriteBaseData;
	VirtualInvokeData _14_GetLocalPath;
	VirtualInvokeData _15_CompleteSave;
	VirtualInvokeData _16_WriteData;
	VirtualInvokeData _17_DeleteUnapprovedFiles;
	VirtualInvokeData _18_GetContainerFolder;
	VirtualInvokeData _19_WriteSubfile;
	VirtualInvokeData _20_WriteFolder;
	VirtualInvokeData _21_TryLoadFile;
	VirtualInvokeData _22_TryLoadFile;
	VirtualInvokeData _23_NetworkInitialize__Late;
	VirtualInvokeData _24_Awake_UserLogic_ScheduleOne_DevUtilities_NetworkSingleton_1_Assembly_CSharp_dll;
	VirtualInvokeData _25_get_SaveFolderName;
	VirtualInvokeData _26_get_SaveFileName;
	VirtualInvokeData _27_get_Loader;
	VirtualInvokeData _28_get_ShouldSaveUnderFolder;
	VirtualInvokeData _29_get_LocalExtraFiles;
	VirtualInvokeData _30_set_LocalExtraFiles;
	VirtualInvokeData _31_get_LocalExtraFolders;
	VirtualInvokeData _32_set_LocalExtraFolders;
	VirtualInvokeData _33_get_HasChanged;
	VirtualInvokeData _34_set_HasChanged;
	VirtualInvokeData _35_unknown;
	VirtualInvokeData _36_unknown;
	VirtualInvokeData _37_unknown;
	VirtualInvokeData _38_unknown;
	VirtualInvokeData _39_unknown;
	VirtualInvokeData _40_unknown;
	VirtualInvokeData _41_unknown;
	VirtualInvokeData _42_unknown;
	VirtualInvokeData _43_unknown;
	VirtualInvokeData _44_unknown;
	VirtualInvokeData _45_unknown;
	VirtualInvokeData _46_unknown;
	VirtualInvokeData _47_unknown;
	VirtualInvokeData _48_InitializeSaveable;
	VirtualInvokeData _49_GetSaveString;
	VirtualInvokeData _50_ReadSyncVar___ScheduleOne_Money_MoneyManager;
	VirtualInvokeData _51_Awake_UserLogic_ScheduleOne_Money_MoneyManager_Assembly_CSharp_dll;
};
struct ScheduleOne_Money_MoneyManager_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	ScheduleOne_Money_MoneyManager_VTable vtable;
};
struct ScheduleOne_Money_MoneyManager_o {
	ScheduleOne_Money_MoneyManager_c *klass;
	void *monitor;
	ScheduleOne_Money_MoneyManager_Fields fields;
};

struct ScheduleOne_GameTime_GameDateTime_Fields {
	int32_t elapsedDays;
	int32_t time;
};
struct ScheduleOne_GameTime_GameDateTime_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct ScheduleOne_GameTime_GameDateTime_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	ScheduleOne_GameTime_GameDateTime_VTable vtable;
};
struct ScheduleOne_GameTime_GameDateTime_o {
	ScheduleOne_GameTime_GameDateTime_Fields fields;
};

struct ScheduleOne_DevUtilities_NetworkSingleton_TimeManager__Fields : FishNet_Object_NetworkBehaviour_Fields {
	bool Destroyed;
	bool NetworkInitialize___EarlyScheduleOne_DevUtilities_NetworkSingleton_1Assembly_CSharp_dll_Excuted;
	bool NetworkInitialize__LateScheduleOne_DevUtilities_NetworkSingleton_1Assembly_CSharp_dll_Excuted;
};
struct ScheduleOne_GameTime_TimeManager_Fields : ScheduleOne_DevUtilities_NetworkSingleton_TimeManager__Fields {
	bool _SleepInProgress_k__BackingField;
	int32_t _ElapsedDays_k__BackingField;
	int32_t _CurrentTime_k__BackingField;
	float _TimeOnCurrentMinute_k__BackingField;
	int32_t DefaultTime;
	int32_t DefaultDay;
	float TimeProgressionMultiplier;
	int32_t _DailyMinTotal_k__BackingField;
	float _Playtime_k__BackingField;
	int32_t savedTime;
	bool _TimeOverridden_k__BackingField;
	struct System_Action_o* onMinutePass;
	struct System_Action_o* onHourPass;
	struct System_Action_o* onDayPass;
	struct System_Action_o* onWeekPass;
	struct System_Action_o* onUpdate;
	struct System_Action_o* onFixedUpdate;
	struct System_Action_int__o* onTimeSkip;
	struct System_Action_o* onTick;
	struct UnityEngine_Events_UnityEvent_o* _onSleepStart;
	struct UnityEngine_Events_UnityEvent_o* _onSleepEnd;
	struct UnityEngine_Events_UnityEvent_o* onFirstNight;
	struct System_Action_o* onTimeChanged;
	struct ScheduleOne_GameTime_GameDateTime_o sleepStartTime;
	int32_t sleepEndTime;
	bool _HostDailySummaryDone_k__BackingField;
	float defaultFixedTimeScale;
	struct ScheduleOne_Persistence_Loaders_TimeLoader_o* loader;
	struct System_Collections_Generic_List_string__o* _LocalExtraFiles_k__BackingField;
	struct System_Collections_Generic_List_string__o* _LocalExtraFolders_k__BackingField;
	bool _HasChanged_k__BackingField;
	bool NetworkInitialize___EarlyScheduleOne_GameTime_TimeManagerAssembly_CSharp_dll_Excuted;
	bool NetworkInitialize__LateScheduleOne_GameTime_TimeManagerAssembly_CSharp_dll_Excuted;
};
struct ScheduleOne_GameTime_TimeManager_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_OnStartNetwork;
	VirtualInvokeData _5_OnStopNetwork;
	VirtualInvokeData _6_OnStartServer;
	VirtualInvokeData _7_OnStopServer;
	VirtualInvokeData _8_OnOwnershipServer;
	VirtualInvokeData _9_OnSpawnServer;
	VirtualInvokeData _10_OnDespawnServer;
	VirtualInvokeData _11_OnStartClient;
	VirtualInvokeData _12_Save;
	VirtualInvokeData _13_WriteBaseData;
	VirtualInvokeData _14_GetLocalPath;
	VirtualInvokeData _15_CompleteSave;
	VirtualInvokeData _16_WriteData;
	VirtualInvokeData _17_DeleteUnapprovedFiles;
	VirtualInvokeData _18_GetContainerFolder;
	VirtualInvokeData _19_WriteSubfile;
	VirtualInvokeData _20_WriteFolder;
	VirtualInvokeData _21_TryLoadFile;
	VirtualInvokeData _22_TryLoadFile;
	VirtualInvokeData _23_NetworkInitialize__Late;
	VirtualInvokeData _24_Awake_UserLogic_ScheduleOne_DevUtilities_NetworkSingleton_1_Assembly_CSharp_dll;
	VirtualInvokeData _25_get_SaveFolderName;
	VirtualInvokeData _26_get_SaveFileName;
	VirtualInvokeData _27_get_Loader;
	VirtualInvokeData _28_get_ShouldSaveUnderFolder;
	VirtualInvokeData _29_get_LocalExtraFiles;
	VirtualInvokeData _30_set_LocalExtraFiles;
	VirtualInvokeData _31_get_LocalExtraFolders;
	VirtualInvokeData _32_set_LocalExtraFolders;
	VirtualInvokeData _33_get_HasChanged;
	VirtualInvokeData _34_set_HasChanged;
	VirtualInvokeData _35_unknown;
	VirtualInvokeData _36_unknown;
	VirtualInvokeData _37_unknown;
	VirtualInvokeData _38_unknown;
	VirtualInvokeData _39_unknown;
	VirtualInvokeData _40_unknown;
	VirtualInvokeData _41_unknown;
	VirtualInvokeData _42_unknown;
	VirtualInvokeData _43_unknown;
	VirtualInvokeData _44_unknown;
	VirtualInvokeData _45_unknown;
	VirtualInvokeData _46_unknown;
	VirtualInvokeData _47_unknown;
	VirtualInvokeData _48_InitializeSaveable;
	VirtualInvokeData _49_Update;
	VirtualInvokeData _50_FixedUpdate;
	VirtualInvokeData _51_GetSaveString;
	VirtualInvokeData _52_Awake_UserLogic_ScheduleOne_GameTime_TimeManager_Assembly_CSharp_dll;
};
struct ScheduleOne_GameTime_TimeManager_c {
	Il2CppClass_1 _1;
	struct ScheduleOne_GameTime_TimeManager_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	ScheduleOne_GameTime_TimeManager_VTable vtable;
};
struct ScheduleOne_GameTime_TimeManager_o {
	ScheduleOne_GameTime_TimeManager_c *klass;
	void *monitor;
	ScheduleOne_GameTime_TimeManager_Fields fields;
};
struct ScheduleOne_GameTime_TimeManager_StaticFields {
	struct System_Action_o* onSleepStart;
	struct System_Action_int__o* onSleepEnd;
};

#endif //IL2CPP_H
