// GetCardInfo.h : Declaration of the CGetCardInfo
// Author: XiaoMiao (C) 2011

#pragma once
#include "resource.h"       // main symbols
#include <windows.h>
#include "ReadCardX_i.h"
#include "_IGetCardInfoEvents_CP.h"

static const char *dll_filename = ".\\AIO_API.dll";
static const unsigned int beep_seconds = 50;

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全DCOM 支持的Windows Mobile 平台)上无法正确支持单线程COM 对象。定义_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制ATL 支持创建单线程COM 对象实现并允许使用其单线程COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非DCOM Windows CE 平台支持的唯一线程模型。"
#endif


// CGetCardInfo

class ATL_NO_VTABLE CGetCardInfo :
	//增加一下一行：安全提示解除，--当运行浏览器调用时，不会提示安全问题。
	public IObjectSafetyImpl<CGetCardInfo, INTERFACESAFE_FOR_UNTRUSTED_CALLER| INTERFACESAFE_FOR_UNTRUSTED_DATA>, 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CGetCardInfo, &CLSID_GetCardInfo>,
	public IConnectionPointContainerImpl<CGetCardInfo>,
	public CProxy_IGetCardInfoEvents<CGetCardInfo>,
	public IObjectWithSiteImpl<CGetCardInfo>,
	public IDispatchImpl<IGetCardInfo, &IID_IGetCardInfo, &LIBID_ReadCardXLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	typedef int (__stdcall *LPTA_CRInit)(short,int,long);
	typedef BOOL (__stdcall *LPTA_CRClose)(void);
	typedef int (__stdcall *LPTA_FastGetCardNo)(unsigned int*);
	typedef int (_stdcall *LPTA_CRBeep)(unsigned int);

	HINSTANCE hInstDll;

	LPTA_CRInit CRInitFunc;
	LPTA_CRClose CRCloseFunc;
	LPTA_FastGetCardNo FastGetCardNoFunc;
	LPTA_CRBeep CRBeepFunc;

	CGetCardInfo() : bCRInitFlag(false),bDllInitFlag(false)
	{
	  //TODO: 开始装载DLL动态链接库，得到接口函数地址并调用获取卡片序列号 
	  //NOTE: 调用DLL文件存放路径需要放到PATH环境变量 或者生成的ActiveX DLL同一目录 

	  //L表示使用Unicode字符集，需要和项目的字符集保持一致(VS 2005/2008项目缺省使用WideChar(Unicode)字符集）

      hInstDll = LoadLibrary(L".\\AIO_API.dll");

	  if (hInstDll == NULL) 
	  { 
		::MessageBox(NULL,TEXT("加载动态库AIO_API.dll失败!"), TEXT("提示信息"), MB_OK | MB_ICONINFORMATION);  
		FreeLibrary(hInstDll);//资源释放 
	  }else{ 
 		//调用GetProcAddress()获取DLL动态库中的函数入口地址 
		CRInitFunc = (LPTA_CRInit)GetProcAddress(hInstDll,"TA_CRInit");
		CRCloseFunc = (LPTA_CRClose)GetProcAddress(hInstDll,"TA_CRClose");
		FastGetCardNoFunc = (LPTA_FastGetCardNo)GetProcAddress(hInstDll,"TA_FastGetCardNo");
		CRBeepFunc = (LPTA_CRBeep)GetProcAddress(hInstDll,"TA_CRBeep"); 

		bDllInitFlag = true;
	  }
	}


DECLARE_REGISTRY_RESOURCEID(IDR_GETCARDINFO)


BEGIN_COM_MAP(CGetCardInfo)
	COM_INTERFACE_ENTRY(IGetCardInfo)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	//增加一下一行：安全提示解除，--当运行浏览器调用时，不会提示安全问题。 
	COM_INTERFACE_ENTRY(IObjectSafety) 
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CGetCardInfo)
	CONNECTION_POINT_ENTRY(__uuidof(_IGetCardInfoEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		if (bCRInitFlag)
		{
			if (this->CRCloseFunc() != TRUE)
				::MessageBox(NULL,TEXT("关闭读卡器失败!"),TEXT("提示信息"), MB_OK | MB_ICONINFORMATION);
		}

	    if (bDllInitFlag) 
			FreeLibrary(hInstDll);
	}

public:

	STDMETHOD(GetCardNo)(SHORT cr_type, LONG port_num, LONG baud_rate, LONG* card_no);

private:
	bool bCRInitFlag;
	bool bDllInitFlag;
};

OBJECT_ENTRY_AUTO(__uuidof(GetCardInfo), CGetCardInfo)
