// dllmain.h : Declaration of module class.

class CReadCardXModule : public CAtlDllModuleT< CReadCardXModule >
{
public :
	DECLARE_LIBID(LIBID_ReadCardXLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_READCARDX, "{44DA6610-F6A3-4890-9DCF-66868F6196E1}")
};

extern class CReadCardXModule _AtlModule;
