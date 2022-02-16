// dllmain.h : Declaration of module class.

class CIntelliDataHandlersModule : public ATL::CAtlDllModuleT<CIntelliDataHandlersModule>
{
public :
	DECLARE_LIBID(LIBID_IntelliDataHandlersLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_INTELLIDATAHANDLERS, "{cf0d863a-d076-4df4-b54c-0801d5a542dd}")
};

extern class CIntelliDataHandlersModule _AtlModule;
