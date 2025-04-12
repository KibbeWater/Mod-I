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

typedef uintptr_t il2cpp_array_size_t;
typedef int32_t il2cpp_array_lower_bound_t;
struct Il2CppArrayBounds
{
	il2cpp_array_size_t length;
	il2cpp_array_lower_bound_t lower_bound;
};

struct il2cppObject
{
	il2cppClass* m_pClass = nullptr;
	void* m_pMonitor = nullptr;
};

struct UnityEngine_LayerMask_Fields {
	int32_t m_Mask;
};
struct UnityEngine_LayerMask_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct UnityEngine_LayerMask_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_LayerMask_VTable vtable;
};
struct UnityEngine_LayerMask_o {
	UnityEngine_LayerMask_Fields fields;
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

struct UnityEngine_Color_Fields {
	float r;
	float g;
	float b;
	float a;
};
struct UnityEngine_Color_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
	VirtualInvokeData _5_ToString;
};
struct UnityEngine_Color_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Color_VTable vtable;
};
struct UnityEngine_Color_o {
	UnityEngine_Color_Fields fields;
};

struct UnityEngine_Vector2_Fields {
	float x;
	float y;
};
struct UnityEngine_Vector2_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
	VirtualInvokeData _5_ToString;
};
struct UnityEngine_Vector2_c {
	Il2CppClass_1 _1;
	struct UnityEngine_Vector2_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Vector2_VTable vtable;
};
struct UnityEngine_Vector2_o {
	UnityEngine_Vector2_Fields fields;
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

struct UnityEngine_Vector2Int_Fields {
	int32_t m_X;
	int32_t m_Y;
};
struct UnityEngine_Vector2Int_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
	VirtualInvokeData _5_ToString;
};
struct UnityEngine_Vector2Int_c {
	Il2CppClass_1 _1;
	struct UnityEngine_Vector2Int_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Vector2Int_VTable vtable;
};
struct UnityEngine_Vector2Int_o {
	UnityEngine_Vector2Int_Fields fields;
};
struct UnityEngine_Vector2Int_StaticFields {
	struct UnityEngine_Vector2Int_o s_Zero;
	struct UnityEngine_Vector2Int_o s_One;
	struct UnityEngine_Vector2Int_o s_Up;
	struct UnityEngine_Vector2Int_o s_Down;
	struct UnityEngine_Vector2Int_o s_Left;
	struct UnityEngine_Vector2Int_o s_Right;
};

struct FishNet_Object_TransformProperties_Fields {
	struct UnityEngine_Vector3_o Position;
	struct UnityEngine_Quaternion_o Rotation;
	struct UnityEngine_Vector3_o LocalScale;
};
struct FishNet_Object_TransformProperties_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct FishNet_Object_TransformProperties_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	FishNet_Object_TransformProperties_VTable vtable;
};
struct FishNet_Object_TransformProperties_o {
	FishNet_Object_TransformProperties_Fields fields;
};

struct FishNet_Object_NetworkObject_Fields : UnityEngine_MonoBehaviour_Fields {
	bool _IsNested_k__BackingField;
	struct FishNet_Connection_NetworkConnection_o* _PredictedSpawner_k__BackingField;
	bool ActiveDuringEdit;
	uint8_t _ComponentIndex_k__BackingField;
	int32_t _ObjectId_k__BackingField;
	bool _IsDeinitializing_k__BackingField;
	struct FishNet_Component_Ownership_PredictedSpawn_o* _PredictedSpawn_k__BackingField;
	struct FishNet_Object_NetworkBehaviour_array* _networkBehaviours;
	struct FishNet_Object_NetworkObject_o* _ParentNetworkObject_k__BackingField;
	struct System_Collections_Generic_List_NetworkObject__o* _ChildNetworkObjects_k__BackingField;
	struct FishNet_Object_NetworkObject_o* _RuntimeParentNetworkObject_k__BackingField;
	struct UnityEngine_Transform_o* _RuntimeParentTransform_k__BackingField;
	struct System_Collections_Generic_List_NetworkObject__o* _RuntimeChildNetworkObjects_k__BackingField;
	struct FishNet_Object_TransformProperties_o SerializedTransformProperties;
	uint8_t State;
	bool _isNetworked;
	bool _isGlobal;
	int8_t _initializeOrder;
	uint8_t _defaultDespawnType;
	bool _disabledNetworkBehavioursInitialized;
	struct FishNet_Object_NetworkObject_HostVisibilityUpdatedDelegate_o* OnHostVisibilityUpdated;
	struct System_Action_NetworkObject__o* OnObserversActive;
	struct FishNet_Observing_NetworkObserver_o* NetworkObserver;
	struct System_Collections_Generic_HashSet_NetworkConnection__o* Observers;
	struct FishNet_Component_Observing_GridEntry_o* HashGridEntry;
	bool _networkObserverInitiliazed;
	struct UnityEngine_Renderer_array* _renderers;
	bool _renderersPopulated;
	bool _lastClientHostVisibility;
	struct FishNet_Component_Observing_HashGrid_o* _hashGrid;
	float _nextHashGridUpdateTime;
	bool _isStatic;
	struct UnityEngine_Vector2Int_o _hashGridPosition;
	bool _IsClientInitialized_k__BackingField;
	bool _IsServerInitialized_k__BackingField;
	struct FishNet_Connection_NetworkConnection_o* _owner;
	struct FishNet_Managing_NetworkManager_o* _NetworkManager_k__BackingField;
	struct FishNet_Managing_Server_ServerManager_o* _ServerManager_k__BackingField;
	struct FishNet_Managing_Client_ClientManager_o* _ClientManager_k__BackingField;
	struct FishNet_Managing_Observing_ObserverManager_o* _ObserverManager_k__BackingField;
	struct FishNet_Managing_Transporting_TransportManager_o* _TransportManager_k__BackingField;
	struct FishNet_Managing_Timing_TimeManager_o* _TimeManager_k__BackingField;
	struct FishNet_Managing_Scened_SceneManager_o* _SceneManager_k__BackingField;
	struct FishNet_Managing_Predicting_PredictionManager_o* _PredictionManager_k__BackingField;
	struct FishNet_Component_ColliderRollback_RollbackManager_o* _RollbackManager_k__BackingField;
	uint16_t _PrefabId_k__BackingField;
	uint16_t _SpawnableCollectionId_k__BackingField;
	uint32_t _scenePathHash;
	uint64_t _SceneId_k__BackingField;
	uint64_t _AssetPathHash_k__BackingField;
	struct System_Collections_Generic_List_ushort__o* _rpcLinkIndexes;
};
struct FishNet_Object_NetworkObject_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Awake;
	VirtualInvokeData _5_Start;
};
struct FishNet_Object_NetworkObject_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	FishNet_Object_NetworkObject_VTable vtable;
};
struct FishNet_Object_NetworkObject_o {
	FishNet_Object_NetworkObject_c *klass;
	void *monitor;
	FishNet_Object_NetworkObject_Fields fields;
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

struct ScheduleOne_PlayerScripts_Player_Fields : FishNet_Object_NetworkBehaviour_Fields {
	struct System_Collections_Generic_List_NetworkObject__o* objectsTemporarilyOwnedByPlayer;
	struct UnityEngine_GameObject_o* LocalGameObject;
	struct ScheduleOne_AvatarFramework_Avatar_o* Avatar;
	struct ScheduleOne_AvatarFramework_Animation_AvatarAnimation_o* Anim;
	struct ScheduleOne_Tools_SmoothedVelocityCalculator_o* VelocityCalculator;
	struct UnityEngine_Vector3_o EyePosition;
	struct ScheduleOne_AvatarFramework_AvatarSettings_o* TestAvatarSettings;
	struct ScheduleOne_PlayerScripts_PlayerVisualState_o* VisualState;
	struct ScheduleOne_Stealth_PlayerVisibility_o* Visibility;
	struct UnityEngine_CapsuleCollider_o* CapCol;
	struct ScheduleOne_Map_POI_o* PoI;
	struct ScheduleOne_PlayerScripts_Health_PlayerHealth_o* Health;
	struct ScheduleOne_PlayerScripts_PlayerCrimeData_o* CrimeData;
	struct ScheduleOne_PlayerScripts_PlayerEnergy_o* Energy;
	struct UnityEngine_Transform_o* MimicCamera;
	struct ScheduleOne_AvatarFramework_Animation_AvatarFootstepDetector_o* FootstepDetector;
	struct ScheduleOne_PlayerScripts_LocalPlayerFootstepGenerator_o* LocalFootstepDetector;
	struct UnityEngine_CharacterController_o* CharacterController;
	struct ScheduleOne_Audio_AudioSourceController_o* PunchSound;
	struct ScheduleOne_DevUtilities_OptimizedLight_o* ThirdPersonFlashlight;
	struct ScheduleOne_UI_WorldspaceDialogueRenderer_o* NameLabel;
	struct ScheduleOne_PlayerScripts_PlayerClothing_o* Clothing;
	struct UnityEngine_LayerMask_o GroundDetectionMask;
	float AvatarOffset_Standing;
	float AvatarOffset_Crouched;
	struct UnityEngine_AnimationCurve_o* WalkingMapCurve;
	struct UnityEngine_AnimationCurve_o* CrouchWalkMapCurve;
	struct System_String_o* _PlayerName_k__BackingField;
	struct FishNet_Connection_NetworkConnection_o* Connection;
	struct System_String_o* _PlayerCode_k__BackingField;
	struct FishNet_Object_NetworkObject_o* _CurrentVehicle_k__BackingField;
	struct ScheduleOne_PlayerScripts_Player_VehicleEvent_o* onEnterVehicle;
	struct ScheduleOne_PlayerScripts_Player_VehicleTransformEvent_o* onExitVehicle;
	struct ScheduleOne_Vehicles_LandVehicle_o* LastDrivenVehicle;
	float _TimeSinceVehicleExit_k__BackingField;
	bool _Crouched_k__BackingField;
	struct FishNet_Object_NetworkObject_o* _CurrentBed_k__BackingField;
	bool _IsReadyToSleep_k__BackingField;
	bool _IsSkating_k__BackingField;
	struct ScheduleOne_Skating_Skateboard_o* _ActiveSkateboard_k__BackingField;
	struct System_Action_Skateboard__o* onSkateboardMounted;
	struct System_Action_o* onSkateboardDismounted;
	bool _IsSleeping_k__BackingField;
	bool _IsRagdolled_k__BackingField;
	bool _IsArrested_k__BackingField;
	bool _IsTased_k__BackingField;
	bool _IsUnconscious_k__BackingField;
	float _Scale_k__BackingField;
	struct ScheduleOne_Property_Property_o* _CurrentProperty_k__BackingField;
	struct ScheduleOne_Property_Property_o* _LastVisitedProperty_k__BackingField;
	struct ScheduleOne_Property_Business_o* _CurrentBusiness_k__BackingField;
	bool HasCompletedIntro;
	struct UnityEngine_Vector3_o _CameraPosition_k__BackingField;
	struct UnityEngine_Quaternion_o _CameraRotation_k__BackingField;
	struct ScheduleOne_ItemFramework_ItemSlot_array* Inventory;
	struct ScheduleOne_AvatarFramework_Customization_BasicAvatarSettings_o* _CurrentAvatarSettings_k__BackingField;
	struct ScheduleOne_Product_ProductItemInstance_o* _ConsumedProduct_k__BackingField;
	int32_t _TimeSinceProductConsumed_k__BackingField;
	struct ScheduleOne_AvatarFramework_Customization_BasicAvatarSettings_o* DebugAvatarSettings;
	struct ScheduleOne_Persistence_Loaders_PlayerLoader_o* loader;
	struct System_Collections_Generic_List_string__o* _LocalExtraFiles_k__BackingField;
	struct System_Collections_Generic_List_string__o* _LocalExtraFolders_k__BackingField;
	bool _HasChanged_k__BackingField;
	struct UnityEngine_Events_UnityEvent_o* onRagdoll;
	struct UnityEngine_Events_UnityEvent_o* onRagdollEnd;
	struct UnityEngine_Events_UnityEvent_o* onArrested;
	struct UnityEngine_Events_UnityEvent_o* onFreed;
	struct UnityEngine_Events_UnityEvent_o* onTased;
	struct UnityEngine_Events_UnityEvent_o* onTasedEnd;
	struct UnityEngine_Events_UnityEvent_o* onPassedOut;
	struct UnityEngine_Events_UnityEvent_o* onPassOutRecovery;
	struct System_Collections_Generic_List_BaseVariable__o* PlayerVariables;
	struct System_Collections_Generic_Dictionary_string__BaseVariable__o* VariableDict;
	float standingScale;
	float timeAirborne;
	bool _avatarVisibleToLocalPlayer_k__BackingField;
	bool _playerDataRetrieveReturned_k__BackingField;
	struct UnityEngine_Coroutine_o* taseCoroutine;
	struct System_Collections_Generic_List_ConstantForce__o* ragdollForceComponents;
	bool _playerSaveRequestReturned_k__BackingField;
	bool _PlayerInitializedOverNetwork_k__BackingField;
	struct System_Collections_Generic_List_int__o* impactHistory;
	bool _Paranoid_k__BackingField;
	bool _Sneaky_k__BackingField;
	bool _Disoriented_k__BackingField;
	bool _Seizure_k__BackingField;
	struct System_Collections_Generic_List_Quaternion__o* seizureRotations;
	bool _Slippery_k__BackingField;
	bool _Schizophrenic_k__BackingField;
	struct System_Collections_Generic_List_int__o* equippableMessageIDHistory;
	struct UnityEngine_Coroutine_o* lerpScaleRoutine;
	struct FishNet_Object_Synchronizing_SyncVar_string__o* syncVar____PlayerName_k__BackingField;
	struct FishNet_Object_Synchronizing_SyncVar_string__o* syncVar____PlayerCode_k__BackingField;
	struct FishNet_Object_Synchronizing_SyncVar_NetworkObject__o* syncVar____CurrentVehicle_k__BackingField;
	struct FishNet_Object_Synchronizing_SyncVar_NetworkObject__o* syncVar____CurrentBed_k__BackingField;
	struct FishNet_Object_Synchronizing_SyncVar_bool__o* syncVar____IsReadyToSleep_k__BackingField;
	struct FishNet_Object_Synchronizing_SyncVar_Vector3__o* syncVar____CameraPosition_k__BackingField;
	struct FishNet_Object_Synchronizing_SyncVar_Quaternion__o* syncVar____CameraRotation_k__BackingField;
	bool NetworkInitialize___EarlyScheduleOne_PlayerScripts_PlayerAssembly_CSharp_dll_Excuted;
	bool NetworkInitialize__LateScheduleOne_PlayerScripts_PlayerAssembly_CSharp_dll_Excuted;
};
struct ScheduleOne_PlayerScripts_Player_VTable {
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
	VirtualInvokeData _16_OnValidate;
	VirtualInvokeData _17_DeleteUnapprovedFiles;
	VirtualInvokeData _18_GetContainerFolder;
	VirtualInvokeData _19_WriteSubfile;
	VirtualInvokeData _20_WriteFolder;
	VirtualInvokeData _21_TryLoadFile;
	VirtualInvokeData _22_TryLoadFile;
	VirtualInvokeData _23_get_LocalExtraFiles;
	VirtualInvokeData _24_set_LocalExtraFiles;
	VirtualInvokeData _25_get_LocalExtraFolders;
	VirtualInvokeData _26_set_LocalExtraFolders;
	VirtualInvokeData _27_get_HasChanged;
	VirtualInvokeData _28_set_HasChanged;
	VirtualInvokeData _29_unknown;
	VirtualInvokeData _30_unknown;
	VirtualInvokeData _31_unknown;
	VirtualInvokeData _32_unknown;
	VirtualInvokeData _33_unknown;
	VirtualInvokeData _34_unknown;
	VirtualInvokeData _35_unknown;
	VirtualInvokeData _36_unknown;
	VirtualInvokeData _37_unknown;
	VirtualInvokeData _38_unknown;
	VirtualInvokeData _39_unknown;
	VirtualInvokeData _40_unknown;
	VirtualInvokeData _41_unknown;
	VirtualInvokeData _42_unknown;
	VirtualInvokeData _43_unknown;
	VirtualInvokeData _44_Awake;
	VirtualInvokeData _45_InitializeSaveable;
	VirtualInvokeData _46_Start;
	VirtualInvokeData _47_OnDestroy;
	VirtualInvokeData _48_Update;
	VirtualInvokeData _49_MinPass;
	VirtualInvokeData _50_LateUpdate;
	VirtualInvokeData _51_ApplyScale;
	VirtualInvokeData _52_GetSaveString;
	VirtualInvokeData _53_WriteData;
	VirtualInvokeData _54_Load;
	VirtualInvokeData _55_Load;
	VirtualInvokeData _56_LoadInventory;
	VirtualInvokeData _57_LoadAppearance;
	VirtualInvokeData _58_LoadClothing;
	VirtualInvokeData _59_SendImpact;
	VirtualInvokeData _60_ReceiveImpact;
	VirtualInvokeData _61_ProcessImpactForce;
	VirtualInvokeData _62_OnDied;
	VirtualInvokeData _63_OnRevived;
	VirtualInvokeData _64_NetworkInitialize___Early;
	VirtualInvokeData _65_NetworkInitialize__Late;
	VirtualInvokeData _66_RpcLogic___SendImpact_427288424;
	VirtualInvokeData _67_RpcLogic___ReceiveImpact_427288424;
	VirtualInvokeData _68_ReadSyncVar___ScheduleOne_PlayerScripts_Player;
	VirtualInvokeData _69_Awake_UserLogic_ScheduleOne_PlayerScripts_Player_Assembly_CSharp_dll;
};
struct ScheduleOne_PlayerScripts_Player_c {
	Il2CppClass_1 _1;
	struct ScheduleOne_PlayerScripts_Player_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	ScheduleOne_PlayerScripts_Player_VTable vtable;
};
struct ScheduleOne_PlayerScripts_Player_o {
	ScheduleOne_PlayerScripts_Player_c *klass;
	void *monitor;
	ScheduleOne_PlayerScripts_Player_Fields fields;
};
struct ScheduleOne_PlayerScripts_Player_StaticFields {
	struct System_Action_o* onLocalPlayerSpawned;
	struct System_Action_Player__o* onPlayerSpawned;
	struct System_Action_Player__o* onPlayerDespawned;
	struct ScheduleOne_PlayerScripts_Player_o* Local;
	struct System_Collections_Generic_List_Player__o* PlayerList;
};

struct FishNet_Managing_NetworkManager_Fields : UnityEngine_MonoBehaviour_Fields {
	bool _Initialized_k__BackingField;
	struct FishNet_Managing_Predicting_PredictionManager_o* _PredictionManager_k__BackingField;
	struct FishNet_Managing_Server_ServerManager_o* _ServerManager_k__BackingField;
	struct FishNet_Managing_Client_ClientManager_o* _ClientManager_k__BackingField;
	struct FishNet_Managing_Transporting_TransportManager_o* _TransportManager_k__BackingField;
	struct FishNet_Managing_Timing_TimeManager_o* _TimeManager_k__BackingField;
	struct FishNet_Managing_Scened_SceneManager_o* _SceneManager_k__BackingField;
	struct FishNet_Managing_Observing_ObserverManager_o* _ObserverManager_k__BackingField;
	struct FishNet_Managing_Debugging_DebugManager_o* _DebugManager_k__BackingField;
	struct FishNet_Managing_Statistic_StatisticsManager_o* _StatisticsManager_k__BackingField;
	bool _refreshDefaultPrefabs;
	bool _runInBackground;
	bool _dontDestroyOnLoad;
	struct FishNet_Utility_Performance_ObjectPool_o* _objectPool;
	int32_t _persistence;
	bool _canPersist;
	struct FishNet_Managing_Logging_LoggingConfiguration_o* _logging;
	struct FishNet_Component_ColliderRollback_RollbackManager_o* _RollbackManager_k__BackingField;
	struct FishNet_Managing_Object_PrefabObjects_o* _spawnablePrefabs;
	struct System_Collections_Generic_Dictionary_ushort__PrefabObjects__o* _runtimeSpawnablePrefabs;
	struct System_Collections_Generic_Dictionary_string__List_Action_Component____o* _pendingInvokes;
	struct System_Collections_Generic_Dictionary_string__Component__o* _registeredComponents;
};
struct FishNet_Managing_NetworkManager_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct FishNet_Managing_NetworkManager_c {
	Il2CppClass_1 _1;
	struct FishNet_Managing_NetworkManager_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	FishNet_Managing_NetworkManager_VTable vtable;
};
struct FishNet_Managing_NetworkManager_o {
	FishNet_Managing_NetworkManager_c *klass;
	void *monitor;
	FishNet_Managing_NetworkManager_Fields fields;
};
struct FishNet_Managing_NetworkManager_StaticFields {
	struct System_Collections_Generic_List_NetworkManager__o* _instances;
	struct FishNet_Connection_NetworkConnection_o* _EmptyConnection_k__BackingField;
	uint16_t StartingRpcLinkIndex;
};

struct FishNet_InstanceFinder_Fields {
};
struct FishNet_InstanceFinder_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct FishNet_InstanceFinder_c {
	Il2CppClass_1 _1;
	struct FishNet_InstanceFinder_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	FishNet_InstanceFinder_VTable vtable;
};
struct FishNet_InstanceFinder_o {
	FishNet_InstanceFinder_c *klass;
	void *monitor;
	FishNet_InstanceFinder_Fields fields;
};
struct FishNet_InstanceFinder_StaticFields {
	struct FishNet_Managing_NetworkManager_o* _networkManager;
};

struct FishNet_Managing_Server_ServerManager_Fields : UnityEngine_MonoBehaviour_Fields {
	struct System_Collections_Generic_Dictionary_ushort__HashSet_ServerManager_ClientBroadcastDelegate___o* _broadcastHandlers;
	struct System_Collections_Generic_Dictionary_ushort__HashSet_ValueTuple_int__ServerManager_ClientBroadcastDelegate____o* _handlerTargets;
	struct System_Collections_Generic_HashSet_NetworkConnection__o* _connectionsWithoutExclusions;
	struct System_Action_ServerConnectionStateArgs__o* OnServerConnectionState;
	struct System_Action_NetworkConnection__bool__o* OnAuthenticationResult;
	struct System_Action_NetworkConnection__RemoteConnectionStateArgs__o* OnRemoteConnectionState;
	bool _Started_k__BackingField;
	struct FishNet_Managing_Server_ServerObjects_o* _Objects_k__BackingField;
	struct System_Collections_Generic_Dictionary_int__NetworkConnection__o* Clients;
	struct FishNet_Managing_NetworkManager_o* _NetworkManager_k__BackingField;
	struct FishNet_Authenticating_Authenticator_o* _authenticator;
	int32_t _remoteClientTimeout;
	uint16_t _remoteClientTimeoutDuration;
	float _syncTypeRate;
	struct FishNet_Serializing_TransformPackingData_o* SpawnPacking;
	bool _changeFrameRate;
	uint16_t _frameRate;
	bool _shareIds;
	bool _startOnHeadless;
	bool _limitClientMTU;
	int32_t _nextClientTimeoutCheckIndex;
	float _nextTimeoutCheckTime;
	struct FishNet_Managing_Transporting_SplitReader_o* _splitReader;
	uint32_t _cachedLevelOfDetailInterval;
	bool _cachedUseLod;
	struct System_Action_NetworkConnection__int__KickReason__o* OnClientKick;
	struct System_Collections_Generic_Dictionary_ushort__RpcLink__o* RpcLinks;
	struct System_Collections_Generic_Queue_ushort__o* _availableRpcLinkIndexes;
};
struct FishNet_Managing_Server_ServerManager_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct FishNet_Managing_Server_ServerManager_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	FishNet_Managing_Server_ServerManager_VTable vtable;
};
struct FishNet_Managing_Server_ServerManager_o {
	FishNet_Managing_Server_ServerManager_c *klass;
	void *monitor;
	FishNet_Managing_Server_ServerManager_Fields fields;
};

struct FishNet_Managing_Client_ClientManager_Fields : UnityEngine_MonoBehaviour_Fields {
	struct System_Collections_Generic_Dictionary_ushort__HashSet_ClientManager_ServerBroadcastDelegate___o* _broadcastHandlers;
	struct System_Collections_Generic_Dictionary_ushort__HashSet_ValueTuple_int__ClientManager_ServerBroadcastDelegate____o* _handlerTargets;
	struct System_Action_o* OnAuthenticated;
	struct System_Action_o* OnClientTimeOut;
	struct System_Action_ClientConnectionStateArgs__o* OnClientConnectionState;
	struct System_Action_RemoteConnectionStateArgs__o* OnRemoteConnectionState;
	struct System_Action_ConnectedClientsArgs__o* OnConnectedClients;
	bool _Started_k__BackingField;
	struct FishNet_Connection_NetworkConnection_o* Connection;
	struct FishNet_Managing_Client_ClientObjects_o* _Objects_k__BackingField;
	struct System_Collections_Generic_Dictionary_int__NetworkConnection__o* Clients;
	struct FishNet_Managing_NetworkManager_o* _NetworkManager_k__BackingField;
	int32_t _remoteServerTimeout;
	uint16_t _remoteServerTimeoutDuration;
	bool _changeFrameRate;
	uint16_t _frameRate;
	float _lastPacketTime;
	struct FishNet_Managing_Transporting_SplitReader_o* _splitReader;
	struct System_Collections_Generic_List_Vector3__o* _objectsPositionsCache;
	int32_t _nextLodNobIndex;
	uint32_t _LastPacketLocalTick_k__BackingField;
};
struct FishNet_Managing_Client_ClientManager_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct FishNet_Managing_Client_ClientManager_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	FishNet_Managing_Client_ClientManager_VTable vtable;
};
struct FishNet_Managing_Client_ClientManager_o {
	FishNet_Managing_Client_ClientManager_c *klass;
	void *monitor;
	FishNet_Managing_Client_ClientManager_Fields fields;
};

struct FishNet_Managing_Timing_EstimatedTick_Fields {
	uint32_t LocalTick;
	uint32_t RemoteTick;
	uint32_t LastRemoteTick;
};
struct FishNet_Managing_Timing_EstimatedTick_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct FishNet_Managing_Timing_EstimatedTick_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	FishNet_Managing_Timing_EstimatedTick_VTable vtable;
};
struct FishNet_Managing_Timing_EstimatedTick_o {
	FishNet_Managing_Timing_EstimatedTick_Fields fields;
};

struct __declspec(align(8)) FishNet_Connection_NetworkConnection_Fields {
	struct System_Collections_Generic_List_PacketBundle__o* _toClientBundles;
	bool _serverDirtied;
	struct System_Action_NetworkConnection__bool__o* OnLoadedStartScenes;
	struct System_Action_NetworkObject__o* OnObjectAdded;
	struct System_Action_NetworkObject__o* OnObjectRemoved;
	struct FishNet_Managing_NetworkManager_o* _NetworkManager_k__BackingField;
	bool _loadedStartScenesAsServer;
	bool _loadedStartScenesAsClient;
	struct System_Collections_Generic_Queue_int__o* PredictedObjectIds;
	int32_t _TransportIndex_k__BackingField;
	bool _Authenticated_k__BackingField;
	int32_t ClientId;
	struct System_Collections_Generic_HashSet_NetworkObject__o* Objects;
	struct FishNet_Object_NetworkObject_o* _FirstObject_k__BackingField;
	struct System_Collections_Generic_HashSet_Scene__o* _Scenes_k__BackingField;
	bool _Disconnecting_k__BackingField;
	uint32_t _DisconnectingTick_k__BackingField;
	Il2CppObject* CustomData;
	uint32_t ServerConnectionTick;
	struct FishNet_Managing_Timing_EstimatedTick_o PacketTick;
	struct FishNet_Managing_Timing_EstimatedTick_o LocalTick;
	struct System_Collections_Generic_Dictionary_NetworkObject__NetworkConnection_LevelOfDetailData__o* LevelOfDetails;
	int32_t AllowedForcedLodUpdates;
	uint32_t LastLevelOfDetailUpdate;
	int32_t LevelOfDetailInfractions;
	struct FishNet_Component_Observing_GridEntry_o* HashGridEntry;
	struct FishNet_Component_Observing_HashGrid_o* _hashGrid;
	float _nextHashGridUpdateTime;
	struct UnityEngine_Vector2Int_o _hashGridPosition;
	uint32_t _lastPingTick;
	uint32_t _requiredPingTicks;
	struct FishNet_Managing_Timing_MovingAverage_o* _replicateQueueAverage;
	uint32_t _lastAverageQueueAddTick;
	uint32_t _LocalReplicateTick_k__BackingField;
};
struct FishNet_Connection_NetworkConnection_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
};
struct FishNet_Connection_NetworkConnection_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	FishNet_Connection_NetworkConnection_VTable vtable;
};
struct FishNet_Connection_NetworkConnection_o {
	FishNet_Connection_NetworkConnection_c *klass;
	void *monitor;
	FishNet_Connection_NetworkConnection_Fields fields;
};

struct ScheduleOne_PlayerScripts_Player_array {
	Il2CppObject obj;
	Il2CppArrayBounds *bounds;
	il2cpp_array_size_t max_length;
	ScheduleOne_PlayerScripts_Player_o* m_Items[65535];
};

struct System_Collections_Generic_List_Player__Fields {
	struct ScheduleOne_PlayerScripts_Player_array* _items;
	int32_t _size;
	int32_t _version;
	Il2CppObject* _syncRoot;
};
struct System_Collections_Generic_List_Player__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_set_Item;
	VirtualInvokeData _6_IndexOf;
	VirtualInvokeData _7_Insert;
	VirtualInvokeData _8_unknown;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_System_Collections_Generic_ICollection_T__get_IsReadOnly;
	VirtualInvokeData _11_Add;
	VirtualInvokeData _12_unknown;
	VirtualInvokeData _13_Contains;
	VirtualInvokeData _14_CopyTo;
	VirtualInvokeData _15_Remove;
	VirtualInvokeData _16_System_Collections_Generic_IEnumerable_T__GetEnumerator;
	VirtualInvokeData _17_System_Collections_IEnumerable_GetEnumerator;
	VirtualInvokeData _18_System_Collections_IList_get_Item;
	VirtualInvokeData _19_System_Collections_IList_set_Item;
	VirtualInvokeData _20_System_Collections_IList_Add;
	VirtualInvokeData _21_System_Collections_IList_Contains;
	VirtualInvokeData _22_Clear;
	VirtualInvokeData _23_System_Collections_IList_get_IsReadOnly;
	VirtualInvokeData _24_System_Collections_IList_get_IsFixedSize;
	VirtualInvokeData _25_System_Collections_IList_IndexOf;
	VirtualInvokeData _26_System_Collections_IList_Insert;
	VirtualInvokeData _27_System_Collections_IList_Remove;
	VirtualInvokeData _28_RemoveAt;
	VirtualInvokeData _29_System_Collections_ICollection_CopyTo;
	VirtualInvokeData _30_unknown;
	VirtualInvokeData _31_System_Collections_ICollection_get_SyncRoot;
	VirtualInvokeData _32_System_Collections_ICollection_get_IsSynchronized;
	VirtualInvokeData _33_get_Item;
	VirtualInvokeData _34_get_Count;
};
struct System_Collections_Generic_List_Player__c {
	Il2CppClass_1 _1;
	struct System_Collections_Generic_List_Player__StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Collections_Generic_List_Player__VTable vtable;
};
struct System_Collections_Generic_List_Player__o {
	System_Collections_Generic_List_Player__c *klass;
	void *monitor;
	System_Collections_Generic_List_Player__Fields fields;
};
struct System_Collections_Generic_List_Player__StaticFields {
	struct ScheduleOne_PlayerScripts_Player_array* s_emptyArray;
};

struct UnityEngine_DrivenRectTransformTracker_Fields {
};
struct UnityEngine_DrivenRectTransformTracker_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct UnityEngine_DrivenRectTransformTracker_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_DrivenRectTransformTracker_VTable vtable;
};
struct UnityEngine_DrivenRectTransformTracker_o {
	UnityEngine_DrivenRectTransformTracker_Fields fields;
};

struct UnityEngine_UI_Navigation_Fields {
	int32_t m_Mode;
	bool m_WrapAround;
	struct UnityEngine_UI_Selectable_o* m_SelectOnUp;
	struct UnityEngine_UI_Selectable_o* m_SelectOnDown;
	struct UnityEngine_UI_Selectable_o* m_SelectOnLeft;
	struct UnityEngine_UI_Selectable_o* m_SelectOnRight;
};
struct UnityEngine_UI_Navigation_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
};
struct UnityEngine_UI_Navigation_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_UI_Navigation_VTable vtable;
};
struct UnityEngine_UI_Navigation_o {
	UnityEngine_UI_Navigation_Fields fields;
};

struct UnityEngine_UI_ColorBlock_Fields {
	struct UnityEngine_Color_o m_NormalColor;
	struct UnityEngine_Color_o m_HighlightedColor;
	struct UnityEngine_Color_o m_PressedColor;
	struct UnityEngine_Color_o m_SelectedColor;
	struct UnityEngine_Color_o m_DisabledColor;
	float m_ColorMultiplier;
	float m_FadeDuration;
};
struct UnityEngine_UI_ColorBlock_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
};
struct UnityEngine_UI_ColorBlock_c {
	Il2CppClass_1 _1;
	struct UnityEngine_UI_ColorBlock_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_UI_ColorBlock_VTable vtable;
};
struct UnityEngine_UI_ColorBlock_o {
	UnityEngine_UI_ColorBlock_Fields fields;
};
struct UnityEngine_UI_ColorBlock_StaticFields {
	struct UnityEngine_UI_ColorBlock_o defaultColorBlock;
};

struct UnityEngine_UI_SpriteState_Fields {
	struct UnityEngine_Sprite_o* m_HighlightedSprite;
	struct UnityEngine_Sprite_o* m_PressedSprite;
	struct UnityEngine_Sprite_o* m_SelectedSprite;
	struct UnityEngine_Sprite_o* m_DisabledSprite;
};
struct UnityEngine_UI_SpriteState_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
};
struct UnityEngine_UI_SpriteState_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_UI_SpriteState_VTable vtable;
};
struct UnityEngine_UI_SpriteState_o {
	UnityEngine_UI_SpriteState_Fields fields;
};

struct UnityEngine_EventSystems_UIBehaviour_Fields : UnityEngine_MonoBehaviour_Fields {
};
struct UnityEngine_EventSystems_UIBehaviour_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Awake;
	VirtualInvokeData _5_OnEnable;
	VirtualInvokeData _6_Start;
	VirtualInvokeData _7_OnDisable;
	VirtualInvokeData _8_OnDestroy;
	VirtualInvokeData _9_IsActive;
	VirtualInvokeData _10_OnRectTransformDimensionsChange;
	VirtualInvokeData _11_OnBeforeTransformParentChanged;
	VirtualInvokeData _12_OnTransformParentChanged;
	VirtualInvokeData _13_OnDidApplyAnimationProperties;
	VirtualInvokeData _14_OnCanvasGroupChanged;
	VirtualInvokeData _15_OnCanvasHierarchyChanged;
	VirtualInvokeData _16_IsDestroyed;
};
struct UnityEngine_EventSystems_UIBehaviour_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_EventSystems_UIBehaviour_VTable vtable;
};
struct UnityEngine_EventSystems_UIBehaviour_o {
	UnityEngine_EventSystems_UIBehaviour_c *klass;
	void *monitor;
	UnityEngine_EventSystems_UIBehaviour_Fields fields;
};

struct UnityEngine_UI_Selectable_Fields : UnityEngine_EventSystems_UIBehaviour_Fields {
	bool m_EnableCalled;
	struct UnityEngine_UI_Navigation_o m_Navigation;
	int32_t m_Transition;
	struct UnityEngine_UI_ColorBlock_o m_Colors;
	struct UnityEngine_UI_SpriteState_o m_SpriteState;
	struct UnityEngine_UI_AnimationTriggers_o* m_AnimationTriggers;
	bool m_Interactable;
	struct UnityEngine_UI_Graphic_o* m_TargetGraphic;
	bool m_GroupsAllowInteraction;
	int32_t m_CurrentIndex;
	bool _isPointerInside_k__BackingField;
	bool _isPointerDown_k__BackingField;
	bool _hasSelection_k__BackingField;
	struct System_Collections_Generic_List_CanvasGroup__o* m_CanvasGroupCache;
};
struct UnityEngine_UI_Selectable_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Awake;
	VirtualInvokeData _5_OnEnable;
	VirtualInvokeData _6_Start;
	VirtualInvokeData _7_OnDisable;
	VirtualInvokeData _8_OnDestroy;
	VirtualInvokeData _9_IsActive;
	VirtualInvokeData _10_OnRectTransformDimensionsChange;
	VirtualInvokeData _11_OnBeforeTransformParentChanged;
	VirtualInvokeData _12_OnTransformParentChanged;
	VirtualInvokeData _13_OnDidApplyAnimationProperties;
	VirtualInvokeData _14_OnCanvasGroupChanged;
	VirtualInvokeData _15_OnCanvasHierarchyChanged;
	VirtualInvokeData _16_IsDestroyed;
	VirtualInvokeData _17_unknown;
	VirtualInvokeData _18_unknown;
	VirtualInvokeData _19_unknown;
	VirtualInvokeData _20_unknown;
	VirtualInvokeData _21_unknown;
	VirtualInvokeData _22_unknown;
	VirtualInvokeData _23_unknown;
	VirtualInvokeData _24_IsInteractable;
	VirtualInvokeData _25_InstantClearState;
	VirtualInvokeData _26_DoStateTransition;
	VirtualInvokeData _27_FindSelectableOnLeft;
	VirtualInvokeData _28_FindSelectableOnRight;
	VirtualInvokeData _29_FindSelectableOnUp;
	VirtualInvokeData _30_FindSelectableOnDown;
	VirtualInvokeData _31_OnMove;
	VirtualInvokeData _32_OnPointerDown;
	VirtualInvokeData _33_OnPointerUp;
	VirtualInvokeData _34_OnPointerEnter;
	VirtualInvokeData _35_OnPointerExit;
	VirtualInvokeData _36_OnSelect;
	VirtualInvokeData _37_OnDeselect;
	VirtualInvokeData _38_Select;
};
struct UnityEngine_UI_Selectable_c {
	Il2CppClass_1 _1;
	struct UnityEngine_UI_Selectable_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_UI_Selectable_VTable vtable;
};
struct UnityEngine_UI_Selectable_o {
	UnityEngine_UI_Selectable_c *klass;
	void *monitor;
	UnityEngine_UI_Selectable_Fields fields;
};
struct UnityEngine_UI_Selectable_StaticFields {
	struct UnityEngine_UI_Selectable_array* s_Selectables;
	int32_t s_SelectableCount;
};

struct UnityEngine_UI_Slider_Fields : UnityEngine_UI_Selectable_Fields {
	struct UnityEngine_RectTransform_o* m_FillRect;
	struct UnityEngine_RectTransform_o* m_HandleRect;
	int32_t m_Direction;
	float m_MinValue;
	float m_MaxValue;
	bool m_WholeNumbers;
	float m_Value;
	struct UnityEngine_UI_Slider_SliderEvent_o* m_OnValueChanged;
	struct UnityEngine_UI_Image_o* m_FillImage;
	struct UnityEngine_Transform_o* m_FillTransform;
	struct UnityEngine_RectTransform_o* m_FillContainerRect;
	struct UnityEngine_Transform_o* m_HandleTransform;
	struct UnityEngine_RectTransform_o* m_HandleContainerRect;
	struct UnityEngine_Vector2_o m_Offset;
	struct UnityEngine_DrivenRectTransformTracker_o m_Tracker;
	bool m_DelayedUpdateVisuals;
};
struct UnityEngine_UI_Slider_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Awake;
	VirtualInvokeData _5_OnEnable;
	VirtualInvokeData _6_Start;
	VirtualInvokeData _7_OnDisable;
	VirtualInvokeData _8_OnDestroy;
	VirtualInvokeData _9_IsActive;
	VirtualInvokeData _10_OnRectTransformDimensionsChange;
	VirtualInvokeData _11_OnBeforeTransformParentChanged;
	VirtualInvokeData _12_OnTransformParentChanged;
	VirtualInvokeData _13_OnDidApplyAnimationProperties;
	VirtualInvokeData _14_OnCanvasGroupChanged;
	VirtualInvokeData _15_OnCanvasHierarchyChanged;
	VirtualInvokeData _16_IsDestroyed;
	VirtualInvokeData _17_unknown;
	VirtualInvokeData _18_unknown;
	VirtualInvokeData _19_unknown;
	VirtualInvokeData _20_unknown;
	VirtualInvokeData _21_unknown;
	VirtualInvokeData _22_unknown;
	VirtualInvokeData _23_unknown;
	VirtualInvokeData _24_IsInteractable;
	VirtualInvokeData _25_InstantClearState;
	VirtualInvokeData _26_DoStateTransition;
	VirtualInvokeData _27_FindSelectableOnLeft;
	VirtualInvokeData _28_FindSelectableOnRight;
	VirtualInvokeData _29_FindSelectableOnUp;
	VirtualInvokeData _30_FindSelectableOnDown;
	VirtualInvokeData _31_OnMove;
	VirtualInvokeData _32_OnPointerDown;
	VirtualInvokeData _33_OnPointerUp;
	VirtualInvokeData _34_OnPointerEnter;
	VirtualInvokeData _35_OnPointerExit;
	VirtualInvokeData _36_OnSelect;
	VirtualInvokeData _37_OnDeselect;
	VirtualInvokeData _38_Select;
	VirtualInvokeData _39_unknown;
	VirtualInvokeData _40_unknown;
	VirtualInvokeData _41_unknown;
	VirtualInvokeData _42_UnityEngine_UI_ICanvasElement_get_transform;
	VirtualInvokeData _43_unknown;
	VirtualInvokeData _44_unknown;
	VirtualInvokeData _45_unknown;
	VirtualInvokeData _46_get_value;
	VirtualInvokeData _47_set_value;
	VirtualInvokeData _48_SetValueWithoutNotify;
	VirtualInvokeData _49_Rebuild;
	VirtualInvokeData _50_LayoutComplete;
	VirtualInvokeData _51_GraphicUpdateComplete;
	VirtualInvokeData _52_Update;
	VirtualInvokeData _53_Set;
	VirtualInvokeData _54_OnDrag;
	VirtualInvokeData _55_OnInitializePotentialDrag;
};
struct UnityEngine_UI_Slider_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_UI_Slider_VTable vtable;
};
struct UnityEngine_UI_Slider_o {
	UnityEngine_UI_Slider_c *klass;
	void *monitor;
	UnityEngine_UI_Slider_Fields fields;
};

struct ScheduleOne_DevUtilities_Singleton_BlackjackInterface__Fields : UnityEngine_MonoBehaviour_Fields {
	bool Destroyed;
};

struct ScheduleOne_Casino_UI_BlackjackInterface_Fields : ScheduleOne_DevUtilities_Singleton_BlackjackInterface__Fields {
	struct ScheduleOne_Casino_BlackjackGameController_o* _CurrentGame_k__BackingField;
	struct UnityEngine_Canvas_o* Canvas;
	struct ScheduleOne_Casino_UI_CasinoGamePlayerDisplay_o* PlayerDisplay;
	struct UnityEngine_RectTransform_o* BetContainer;
	struct TMPro_TextMeshProUGUI_o* BetTitleLabel;
	struct UnityEngine_UI_Slider_o* BetSlider;
	struct TMPro_TextMeshProUGUI_o* BetAmount;
	struct UnityEngine_UI_Button_o* ReadyButton;
	struct TMPro_TextMeshProUGUI_o* ReadyLabel;
	struct UnityEngine_RectTransform_o* WaitingContainer;
	struct TMPro_TextMeshProUGUI_o* WaitingLabel;
	struct TMPro_TextMeshProUGUI_o* DealerScoreLabel;
	struct TMPro_TextMeshProUGUI_o* PlayerScoreLabel;
	struct UnityEngine_UI_Button_o* HitButton;
	struct UnityEngine_UI_Button_o* StandButton;
	struct UnityEngine_Animation_o* InputContainerAnimation;
	struct UnityEngine_CanvasGroup_o* InputContainerCanvasGroup;
	struct UnityEngine_AnimationClip_o* InputContainerFadeIn;
	struct UnityEngine_AnimationClip_o* InputContainerFadeOut;
	struct UnityEngine_RectTransform_o* SelectionIndicator;
	struct UnityEngine_Animation_o* ScoresContainerAnimation;
	struct UnityEngine_CanvasGroup_o* ScoresContainerCanvasGroup;
	struct TMPro_TextMeshProUGUI_o* PositiveOutcomeLabel;
	struct TMPro_TextMeshProUGUI_o* PayoutLabel;
	struct UnityEngine_Events_UnityEvent_o* onBust;
	struct UnityEngine_Events_UnityEvent_o* onBlackjack;
	struct UnityEngine_Events_UnityEvent_o* onWin;
	struct UnityEngine_Events_UnityEvent_o* onLose;
	struct UnityEngine_Events_UnityEvent_o* onPush;
};
struct ScheduleOne_Casino_UI_BlackjackInterface_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Start;
	VirtualInvokeData _5_Awake;
	VirtualInvokeData _6_OnDestroy;
};
struct ScheduleOne_Casino_UI_BlackjackInterface_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	ScheduleOne_Casino_UI_BlackjackInterface_VTable vtable;
};
struct ScheduleOne_Casino_UI_BlackjackInterface_o {
	ScheduleOne_Casino_UI_BlackjackInterface_c *klass;
	void *monitor;
	ScheduleOne_Casino_UI_BlackjackInterface_Fields fields;
};

struct ScheduleOne_Casino_CasinoGameController_Fields : FishNet_Object_NetworkBehaviour_Fields {
	bool _IsOpen_k__BackingField;
	struct ScheduleOne_Casino_CasinoGamePlayers_o* Players;
	struct ScheduleOne_Casino_CasinoGameInteraction_o* Interaction;
	struct UnityEngine_Transform_array* DefaultCameraTransforms;
	struct UnityEngine_Transform_o* localDefaultCameraTransform;
	bool NetworkInitialize___EarlyScheduleOne_Casino_CasinoGameControllerAssembly_CSharp_dll_Excuted;
	bool NetworkInitialize__LateScheduleOne_Casino_CasinoGameControllerAssembly_CSharp_dll_Excuted;
};

struct ScheduleOne_Casino_BlackjackGameController_Fields : ScheduleOne_Casino_CasinoGameController_Fields {
	int32_t _CurrentStage_k__BackingField;
	struct ScheduleOne_PlayerScripts_Player_o* _PlayerTurn_k__BackingField;
	float _LocalPlayerBet_k__BackingField;
	int32_t _DealerScore_k__BackingField;
	int32_t _LocalPlayerScore_k__BackingField;
	bool _IsLocalPlayerBlackjack_k__BackingField;
	bool _IsLocalPlayerBust_k__BackingField;
	struct ScheduleOne_Casino_PlayingCard_array* Cards;
	struct UnityEngine_Transform_array* DefaultCardPositions;
	struct UnityEngine_Transform_array* FocusedCameraTransforms;
	struct UnityEngine_Transform_array* FinalCameraTransforms;
	struct UnityEngine_Transform_array* Player1CardPositions;
	struct UnityEngine_Transform_array* Player2CardPositions;
	struct UnityEngine_Transform_array* Player3CardPositions;
	struct UnityEngine_Transform_array* Player4CardPositions;
	struct UnityEngine_Transform_array* DealerCardPositions;
	struct System_Collections_Generic_List_Player__o* playersInCurrentRound;
	struct System_Collections_Generic_List_PlayingCard__o* playStack;
	struct System_Collections_Generic_List_PlayingCard__o* player1Hand;
	struct System_Collections_Generic_List_PlayingCard__o* player2Hand;
	struct System_Collections_Generic_List_PlayingCard__o* player3Hand;
	struct System_Collections_Generic_List_PlayingCard__o* player4Hand;
	struct System_Collections_Generic_List_PlayingCard__o* dealerHand;
	struct System_Collections_Generic_List_PlayingCard_CardData__o* cardValuesInDeck;
	struct System_Collections_Generic_List_PlayingCard_CardData__o* drawnCardsValues;
	struct UnityEngine_Transform_o* localFocusCameraTransform;
	struct UnityEngine_Transform_o* localFinalCameraTransform;
	struct System_Action_o* onLocalPlayerBetChange;
	struct System_Action_o* onLocalPlayerExitRound;
	struct System_Action_o* onInitialCardsDealt;
	struct System_Action_o* onLocalPlayerReadyForInput;
	struct System_Action_o* onLocalPlayerBust;
	struct System_Action_BlackjackGameController_EPayoutType__o* onLocalPlayerRoundCompleted;
	bool NetworkInitialize___EarlyScheduleOne_Casino_BlackjackGameControllerAssembly_CSharp_dll_Excuted;
	bool NetworkInitialize__LateScheduleOne_Casino_BlackjackGameControllerAssembly_CSharp_dll_Excuted;
};
struct ScheduleOne_Casino_BlackjackGameController_VTable {
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
	VirtualInvokeData _12_OnStopClient;
	VirtualInvokeData _13_OnOwnershipClient;
	VirtualInvokeData _14_NetworkInitializeIfDisabled;
	VirtualInvokeData _15_Reset;
	VirtualInvokeData _16_OnValidate;
	VirtualInvokeData _17_ClearReplicateCache_Virtual;
	VirtualInvokeData _18_ResetSyncVarFields;
	VirtualInvokeData _19_Awake;
	VirtualInvokeData _20_OnLocalPlayerRequestJoin;
	VirtualInvokeData _21_Exit;
	VirtualInvokeData _22_Update;
	VirtualInvokeData _23_FixedUpdate;
	VirtualInvokeData _24_Open;
	VirtualInvokeData _25_Close;
	VirtualInvokeData _26_NetworkInitialize___Early;
	VirtualInvokeData _27_NetworkInitialize__Late;
	VirtualInvokeData _28_Awake_UserLogic_ScheduleOne_Casino_CasinoGameController_Assembly_CSharp_dll;
	VirtualInvokeData _29_Awake_UserLogic_ScheduleOne_Casino_BlackjackGameController_Assembly_CSharp_dll;
};
struct ScheduleOne_Casino_BlackjackGameController_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	ScheduleOne_Casino_BlackjackGameController_VTable vtable;
};
struct ScheduleOne_Casino_BlackjackGameController_o {
	ScheduleOne_Casino_BlackjackGameController_c *klass;
	void *monitor;
	ScheduleOne_Casino_BlackjackGameController_Fields fields;
};

struct ScheduleOne_Economy_Customer_Fields : FishNet_Object_NetworkBehaviour_Fields {
	bool DEBUG;
	float _CurrentAddiction_k__BackingField;
	struct ScheduleOne_Quests_ContractInfo_o* offeredContractInfo;
	struct ScheduleOne_GameTime_GameDateTime_o _OfferedContractTime_k__BackingField;
	struct ScheduleOne_Quests_Contract_o* _CurrentContract_k__BackingField;
	bool _IsAwaitingDelivery_k__BackingField;
	int32_t _TimeSinceLastDealCompleted_k__BackingField;
	int32_t _TimeSinceLastDealOffered_k__BackingField;
	int32_t _TimeSincePlayerApproached_k__BackingField;
	int32_t _TimeSinceInstantDealOffered_k__BackingField;
	int32_t _OfferedDeals_k__BackingField;
	int32_t _CompletedDeliveries_k__BackingField;
	bool _HasBeenRecommended_k__BackingField;
	struct ScheduleOne_NPCs_NPC_o* _NPC_k__BackingField;
	struct ScheduleOne_Economy_Dealer_o* _AssignedDealer_k__BackingField;
	struct ScheduleOne_NPCs_Schedules_NPCSignal_WaitForDelivery_o* DealSignal;
	bool AvailableInDemo;
	struct ScheduleOne_Economy_CustomerData_o* customerData;
	struct ScheduleOne_Economy_DeliveryLocation_o* DefaultDeliveryLocation;
	bool CanRecommendFriends;
	struct UnityEngine_Events_UnityEvent_o* onUnlocked;
	struct UnityEngine_Events_UnityEvent_o* onDealCompleted;
	struct UnityEngine_Events_UnityEvent_Contract__o* onContractAssigned;
	bool awaitingSample;
	struct ScheduleOne_Dialogue_DialogueController_DialogueChoice_o* sampleChoice;
	struct ScheduleOne_Dialogue_DialogueController_DialogueChoice_o* completeContractChoice;
	struct ScheduleOne_Dialogue_DialogueController_DialogueChoice_o* offerDealChoice;
	struct ScheduleOne_Dialogue_DialogueController_GreetingOverride_o* awaitingDealGreeting;
	int32_t minsSinceUnlocked;
	bool sampleOfferedToday;
	struct ScheduleOne_Map_NPCPoI_o* _potentialCustomerPoI_k__BackingField;
	struct ScheduleOne_Economy_CustomerAffinityData_o* currentAffinityData;
	bool pendingInstantDeal;
	struct System_Collections_Generic_List_string__o* _LocalExtraFiles_k__BackingField;
	struct System_Collections_Generic_List_string__o* _LocalExtraFolders_k__BackingField;
	bool _HasChanged_k__BackingField;
	struct ScheduleOne_Product_ProductItemInstance_o* consumedSample;
	struct FishNet_Object_Synchronizing_SyncVar_float__o* syncVar____CurrentAddiction_k__BackingField;
	struct FishNet_Object_Synchronizing_SyncVar_bool__o* syncVar____HasBeenRecommended_k__BackingField;
	bool NetworkInitialize___EarlyScheduleOne_Economy_CustomerAssembly_CSharp_dll_Excuted;
	bool NetworkInitialize__LateScheduleOne_Economy_CustomerAssembly_CSharp_dll_Excuted;
};
struct ScheduleOne_Economy_Customer_VTable {
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
	VirtualInvokeData _16_OnValidate;
	VirtualInvokeData _17_DeleteUnapprovedFiles;
	VirtualInvokeData _18_GetContainerFolder;
	VirtualInvokeData _19_WriteSubfile;
	VirtualInvokeData _20_WriteFolder;
	VirtualInvokeData _21_TryLoadFile;
	VirtualInvokeData _22_TryLoadFile;
	VirtualInvokeData _23_get_LocalExtraFiles;
	VirtualInvokeData _24_set_LocalExtraFiles;
	VirtualInvokeData _25_get_LocalExtraFolders;
	VirtualInvokeData _26_set_LocalExtraFolders;
	VirtualInvokeData _27_get_HasChanged;
	VirtualInvokeData _28_set_HasChanged;
	VirtualInvokeData _29_unknown;
	VirtualInvokeData _30_unknown;
	VirtualInvokeData _31_unknown;
	VirtualInvokeData _32_unknown;
	VirtualInvokeData _33_unknown;
	VirtualInvokeData _34_unknown;
	VirtualInvokeData _35_unknown;
	VirtualInvokeData _36_unknown;
	VirtualInvokeData _37_unknown;
	VirtualInvokeData _38_unknown;
	VirtualInvokeData _39_unknown;
	VirtualInvokeData _40_unknown;
	VirtualInvokeData _41_unknown;
	VirtualInvokeData _42_Awake;
	VirtualInvokeData _43_InitializeSaveable;
	VirtualInvokeData _44_MinPass;
	VirtualInvokeData _45_DayPass;
	VirtualInvokeData _46_OnCustomerUnlocked;
	VirtualInvokeData _47_OfferContract;
	VirtualInvokeData _48_ExpireOffer;
	VirtualInvokeData _49_AssignContract;
	VirtualInvokeData _50_NotifyPlayerOfContract;
	VirtualInvokeData _51_AcceptContractClicked;
	VirtualInvokeData _52_CounterOfferClicked;
	VirtualInvokeData _53_SendCounteroffer;
	VirtualInvokeData _54_PlayerAcceptedContract;
	VirtualInvokeData _55_ContractAccepted;
	VirtualInvokeData _56_PlayContractAcceptedReaction;
	VirtualInvokeData _57_EvaluateCounteroffer;
	VirtualInvokeData _58_ContractRejected;
	VirtualInvokeData _59_PlayContractRejectedReaction;
	VirtualInvokeData _60_SetIsAwaitingDelivery;
	VirtualInvokeData _61_ShouldTryGenerateDeal;
	VirtualInvokeData _62_OfferDealItems;
	VirtualInvokeData _63_CustomerRejectedDeal;
	VirtualInvokeData _64_ProcessHandover;
	VirtualInvokeData _65_CurrentContractEnded;
	VirtualInvokeData _66_EvaluateDelivery;
	VirtualInvokeData _67_ShowOfferDealOption;
	VirtualInvokeData _68_OfferDealValid;
	VirtualInvokeData _69_InstantDealOffered;
	VirtualInvokeData _70_ShouldTryApproachPlayer;
	VirtualInvokeData _71_GetSaveString;
	VirtualInvokeData _72_WriteData;
	VirtualInvokeData _73_Load;
	VirtualInvokeData _74_IsReadyForHandover;
	VirtualInvokeData _75_IsHandoverChoiceValid;
	VirtualInvokeData _76_ShowDirectApproachOption;
	VirtualInvokeData _77_IsUnlockable;
	VirtualInvokeData _78_SampleOptionValid;
	VirtualInvokeData _79_GetSampleRequestSuccessChance;
	VirtualInvokeData _80_SampleAccepted;
	VirtualInvokeData _81_DirectApproachRejected;
	VirtualInvokeData _82_NetworkInitialize___Early;
	VirtualInvokeData _83_NetworkInitialize__Late;
	VirtualInvokeData _84_RpcLogic___ExpireOffer_2166136261;
	VirtualInvokeData _85_ReadSyncVar___ScheduleOne_Economy_Customer;
	VirtualInvokeData _86_Awake_UserLogic_ScheduleOne_Economy_Customer_Assembly_CSharp_dll;
};
struct ScheduleOne_Economy_Customer_c {
	Il2CppClass_1 _1;
	struct ScheduleOne_Economy_Customer_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	ScheduleOne_Economy_Customer_VTable vtable;
};
struct ScheduleOne_Economy_Customer_o {
	ScheduleOne_Economy_Customer_c *klass;
	void *monitor;
	ScheduleOne_Economy_Customer_Fields fields;
};
struct ScheduleOne_Economy_Customer_StaticFields {
	struct System_Action_Customer__o* onCustomerUnlocked;
	struct System_Collections_Generic_List_Customer__o* UnlockedCustomers;
	struct System_String_array* PlayerAcceptMessages;
	struct System_String_array* PlayerRejectMessages;
};

struct ScheduleOne_Economy_Customer_array {
	Il2CppObject obj;
	Il2CppArrayBounds *bounds;
	il2cpp_array_size_t max_length;
	ScheduleOne_Economy_Customer_o* m_Items[65535];
};

struct System_Collections_Generic_List_Customer__Fields {
	struct ScheduleOne_Economy_Customer_array* _items;
	int32_t _size;
	int32_t _version;
	Il2CppObject* _syncRoot;
};
struct System_Collections_Generic_List_Customer__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_set_Item;
	VirtualInvokeData _6_IndexOf;
	VirtualInvokeData _7_Insert;
	VirtualInvokeData _8_unknown;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_System_Collections_Generic_ICollection_T__get_IsReadOnly;
	VirtualInvokeData _11_Add;
	VirtualInvokeData _12_unknown;
	VirtualInvokeData _13_Contains;
	VirtualInvokeData _14_CopyTo;
	VirtualInvokeData _15_Remove;
	VirtualInvokeData _16_System_Collections_Generic_IEnumerable_T__GetEnumerator;
	VirtualInvokeData _17_System_Collections_IEnumerable_GetEnumerator;
	VirtualInvokeData _18_System_Collections_IList_get_Item;
	VirtualInvokeData _19_System_Collections_IList_set_Item;
	VirtualInvokeData _20_System_Collections_IList_Add;
	VirtualInvokeData _21_System_Collections_IList_Contains;
	VirtualInvokeData _22_Clear;
	VirtualInvokeData _23_System_Collections_IList_get_IsReadOnly;
	VirtualInvokeData _24_System_Collections_IList_get_IsFixedSize;
	VirtualInvokeData _25_System_Collections_IList_IndexOf;
	VirtualInvokeData _26_System_Collections_IList_Insert;
	VirtualInvokeData _27_System_Collections_IList_Remove;
	VirtualInvokeData _28_RemoveAt;
	VirtualInvokeData _29_System_Collections_ICollection_CopyTo;
	VirtualInvokeData _30_unknown;
	VirtualInvokeData _31_System_Collections_ICollection_get_SyncRoot;
	VirtualInvokeData _32_System_Collections_ICollection_get_IsSynchronized;
	VirtualInvokeData _33_get_Item;
	VirtualInvokeData _34_get_Count;
};
struct System_Collections_Generic_List_Customer__c {
	Il2CppClass_1 _1;
	struct System_Collections_Generic_List_Customer__StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Collections_Generic_List_Customer__VTable vtable;
};
struct System_Collections_Generic_List_Customer__o {
	System_Collections_Generic_List_Customer__c *klass;
	void *monitor;
	System_Collections_Generic_List_Customer__Fields fields;
};
struct System_Collections_Generic_List_Customer__StaticFields {
	struct ScheduleOne_Economy_Customer_array* s_emptyArray;
};

struct ScheduleOne_DevUtilities_PlayerSingleton_PlayerInventory__Fields : UnityEngine_MonoBehaviour_Fields {
};
struct ScheduleOne_DevUtilities_PlayerSingleton_PlayerInventory__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Awake;
	VirtualInvokeData _5_Start;
	VirtualInvokeData _6_OnStartClient;
	VirtualInvokeData _7_OnDestroy;
};
struct ScheduleOne_DevUtilities_PlayerSingleton_PlayerInventory__c {
	Il2CppClass_1 _1;
	struct ScheduleOne_DevUtilities_PlayerSingleton_PlayerInventory__StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	ScheduleOne_DevUtilities_PlayerSingleton_PlayerInventory__VTable vtable;
};
struct ScheduleOne_DevUtilities_PlayerSingleton_PlayerInventory__o {
	ScheduleOne_DevUtilities_PlayerSingleton_PlayerInventory__c *klass;
	void *monitor;
	ScheduleOne_DevUtilities_PlayerSingleton_PlayerInventory__Fields fields;
};
struct ScheduleOne_DevUtilities_PlayerSingleton_PlayerInventory__StaticFields {
	struct ScheduleOne_PlayerScripts_PlayerInventory_o* instance;
};

struct ScheduleOne_PlayerScripts_PlayerInventory_Fields : ScheduleOne_DevUtilities_PlayerSingleton_PlayerInventory__Fields {
	bool giveStartupItems;
	struct System_Collections_Generic_List_PlayerInventory_ItemAmount__o* startupItems;
	struct UnityEngine_Transform_o* equipContainer;
	struct System_Collections_Generic_List_HotbarSlot__o* hotbarSlots;
	struct ScheduleOne_Money_CashSlot_o* _cashSlot_k__BackingField;
	struct ScheduleOne_ItemFramework_CashInstance_o* _cashInstance_k__BackingField;
	struct ScheduleOne_ItemFramework_ClipboardSlot_o* clipboardSlot;
	struct System_Collections_Generic_List_ItemSlotUI__o* slotUIs;
	struct ScheduleOne_ItemFramework_ItemSlot_o* discardSlot;
	struct System_Collections_Generic_List_PlayerInventory_ItemVariable__o* ItemVariables;
	int32_t _EquippedSlotIndex_k__BackingField;
	bool _HotbarEnabled_k__BackingField;
	bool _EquippingEnabled_k__BackingField;
	struct ScheduleOne_Equipping_Equippable_o* _equippable_k__BackingField;
	struct System_Action_bool__o* onInventoryStateChanged;
	int32_t PriorEquippedSlotIndex;
	int32_t PreviousEquippedSlotIndex;
	struct UnityEngine_Events_UnityEvent_o* onPreItemEquipped;
	struct UnityEngine_Events_UnityEvent_o* onItemEquipped;
	bool ManagementSlotEnabled;
	float currentEquipTime;
	float currentDiscardTime;
};
struct ScheduleOne_PlayerScripts_PlayerInventory_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Awake;
	VirtualInvokeData _5_Start;
	VirtualInvokeData _6_OnStartClient;
	VirtualInvokeData _7_OnDestroy;
	VirtualInvokeData _8_Update;
};
struct ScheduleOne_PlayerScripts_PlayerInventory_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	ScheduleOne_PlayerScripts_PlayerInventory_VTable vtable;
};
struct ScheduleOne_PlayerScripts_PlayerInventory_o {
	ScheduleOne_PlayerScripts_PlayerInventory_c *klass;
	void *monitor;
	ScheduleOne_PlayerScripts_PlayerInventory_Fields fields;
};

struct ScheduleOne_ItemFramework_ItemInstance_Fields {
	struct ScheduleOne_ItemFramework_ItemDefinition_o* definition;
	struct System_String_o* ID;
	int32_t Quantity;
	struct System_Action_o* onDataChanged;
	struct System_Action_o* requestClearSlot;
};
struct ScheduleOne_ItemFramework_ItemInstance_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_get_Name;
	VirtualInvokeData _5_get_Description;
	VirtualInvokeData _6_get_Icon;
	VirtualInvokeData _7_get_Category;
	VirtualInvokeData _8_get_StackLimit;
	VirtualInvokeData _9_get_LabelDisplayColor;
	VirtualInvokeData _10_get_Equippable;
	VirtualInvokeData _11_CanStackWith;
	VirtualInvokeData _12_GetCopy;
	VirtualInvokeData _13_IsValidInstance;
	VirtualInvokeData _14_GetItemData;
	VirtualInvokeData _15_GetMonetaryValue;
};
struct ScheduleOne_ItemFramework_ItemInstance_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	ScheduleOne_ItemFramework_ItemInstance_VTable vtable;
};
struct ScheduleOne_ItemFramework_ItemInstance_o {
	ScheduleOne_ItemFramework_ItemInstance_c *klass;
	void *monitor;
	ScheduleOne_ItemFramework_ItemInstance_Fields fields;
};

struct ScheduleOne_Storage_StorableItemInstance_Fields : ScheduleOne_ItemFramework_ItemInstance_Fields {
};
struct ScheduleOne_Storage_StorableItemInstance_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_get_Name;
	VirtualInvokeData _5_get_Description;
	VirtualInvokeData _6_get_Icon;
	VirtualInvokeData _7_get_Category;
	VirtualInvokeData _8_get_StackLimit;
	VirtualInvokeData _9_get_LabelDisplayColor;
	VirtualInvokeData _10_get_Equippable;
	VirtualInvokeData _11_CanStackWith;
	VirtualInvokeData _12_GetCopy;
	VirtualInvokeData _13_IsValidInstance;
	VirtualInvokeData _14_GetItemData;
	VirtualInvokeData _15_GetMonetaryValue;
	VirtualInvokeData _16_get_StoredItem;
};
struct ScheduleOne_Storage_StorableItemInstance_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	ScheduleOne_Storage_StorableItemInstance_VTable vtable;
};
struct ScheduleOne_Storage_StorableItemInstance_o {
	ScheduleOne_Storage_StorableItemInstance_c *klass;
	void *monitor;
	ScheduleOne_Storage_StorableItemInstance_Fields fields;
};

struct ScheduleOne_ItemFramework_CashInstance_Fields : ScheduleOne_Storage_StorableItemInstance_Fields {
	float _Balance_k__BackingField;
};
struct ScheduleOne_ItemFramework_CashInstance_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_get_Name;
	VirtualInvokeData _5_get_Description;
	VirtualInvokeData _6_get_Icon;
	VirtualInvokeData _7_get_Category;
	VirtualInvokeData _8_get_StackLimit;
	VirtualInvokeData _9_get_LabelDisplayColor;
	VirtualInvokeData _10_get_Equippable;
	VirtualInvokeData _11_CanStackWith;
	VirtualInvokeData _12_GetCopy;
	VirtualInvokeData _13_IsValidInstance;
	VirtualInvokeData _14_GetItemData;
	VirtualInvokeData _15_GetMonetaryValue;
	VirtualInvokeData _16_get_StoredItem;
};
struct ScheduleOne_ItemFramework_CashInstance_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	ScheduleOne_ItemFramework_CashInstance_VTable vtable;
};
struct ScheduleOne_ItemFramework_CashInstance_o {
	ScheduleOne_ItemFramework_CashInstance_c *klass;
	void *monitor;
	ScheduleOne_ItemFramework_CashInstance_Fields fields;
};

struct ScheduleOne_Equipping_Equippable_Fields : UnityEngine_MonoBehaviour_Fields {
	struct ScheduleOne_ItemFramework_ItemInstance_o* itemInstance;
	bool CanInteractWhenEquipped;
	bool CanPickUpWhenEquipped;
};

struct ScheduleOne_Equipping_Equippable_StorableItem_Fields : ScheduleOne_Equipping_Equippable_Fields {
	bool isBuildingStoredItem;
	bool lookingAtStorageObject;
	float rotation;
};

struct ScheduleOne_Equipping_Equippable_Viewmodel_Fields : ScheduleOne_Equipping_Equippable_StorableItem_Fields {
	struct UnityEngine_Vector3_o localPosition;
	struct UnityEngine_Vector3_o localEulerAngles;
	struct UnityEngine_Vector3_o localScale;
	struct ScheduleOne_AvatarFramework_Equipping_AvatarEquippable_o* AvatarEquippable;
};

struct ScheduleOne_Equipping_Equippable_Cuke_Fields : ScheduleOne_Equipping_Equippable_Viewmodel_Fields {
	bool _IsDrinking_k__BackingField;
	float BaseEnergyGain;
	float MinEnergyGain;
	float ConsecutiveReduction;
	float HealthGain;
	float AnimationDuration;
	bool ClearDrugEffects;
	struct UnityEngine_Animation_o* OpenAnim;
	struct UnityEngine_Animation_o* DrinkAnim;
	struct ScheduleOne_Audio_AudioSourceController_o* OpenSound;
	struct ScheduleOne_Audio_AudioSourceController_o* SlurpSound;
	struct ScheduleOne_Trash_TrashItem_o* TrashPrefab;
};
struct ScheduleOne_Equipping_Equippable_Cuke_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equip;
	VirtualInvokeData _5_Unequip;
	VirtualInvokeData _6_Update;
	VirtualInvokeData _7_StartBuildingStoredItem;
	VirtualInvokeData _8_StopBuildingStoredItem;
	VirtualInvokeData _9_PlayEquipAnimation;
	VirtualInvokeData _10_PlayUnequipAnimation;
};
struct ScheduleOne_Equipping_Equippable_Cuke_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	ScheduleOne_Equipping_Equippable_Cuke_VTable vtable;
};
struct ScheduleOne_Equipping_Equippable_Cuke_o {
	ScheduleOne_Equipping_Equippable_Cuke_c *klass;
	void *monitor;
	ScheduleOne_Equipping_Equippable_Cuke_Fields fields;
};

#endif //IL2CPP_H
