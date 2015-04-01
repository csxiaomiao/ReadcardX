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
#error "Windows CE ƽ̨(�粻�ṩ��ȫDCOM ֧�ֵ�Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳�COM ���󡣶���_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ��ATL ֧�ִ������߳�COM ����ʵ�ֲ�����ʹ���䵥�߳�COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ�DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif


// CGetCardInfo

class ATL_NO_VTABLE CGetCardInfo :
	//����һ��һ�У���ȫ��ʾ�����--���������������ʱ��������ʾ��ȫ���⡣
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
	  //TODO: ��ʼװ��DLL��̬���ӿ⣬�õ��ӿں�����ַ�����û�ȡ��Ƭ���к� 
	  //NOTE: ����DLL�ļ����·����Ҫ�ŵ�PATH�������� �������ɵ�ActiveX DLLͬһĿ¼ 

	  //L��ʾʹ��Unicode�ַ�������Ҫ����Ŀ���ַ�������һ��(VS 2005/2008��Ŀȱʡʹ��WideChar(Unicode)�ַ�����

      hInstDll = LoadLibrary(L".\\AIO_API.dll");

	  if (hInstDll == NULL) 
	  { 
		::MessageBox(NULL,TEXT("���ض�̬��AIO_API.dllʧ��!"), TEXT("��ʾ��Ϣ"), MB_OK | MB_ICONINFORMATION);  
		FreeLibrary(hInstDll);//��Դ�ͷ� 
	  }else{ 
 		//����GetProcAddress()��ȡDLL��̬���еĺ�����ڵ�ַ 
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
	//����һ��һ�У���ȫ��ʾ�����--���������������ʱ��������ʾ��ȫ���⡣ 
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
				::MessageBox(NULL,TEXT("�رն�����ʧ��!"),TEXT("��ʾ��Ϣ"), MB_OK | MB_ICONINFORMATION);
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
