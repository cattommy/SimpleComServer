// dllmain.h : Declaration of module class.

class CSimpleComServerModule : public ATL::CAtlDllModuleT< CSimpleComServerModule >
{
public :
	DECLARE_LIBID(LIBID_SimpleComServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SIMPLECOMSERVER, "{3D042A0E-556D-4623-90CF-C7294FF30378}")
};

extern class CSimpleComServerModule _AtlModule;
