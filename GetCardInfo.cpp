// GetCardInfo.cpp : Implementation of CGetCardInfo

#include "stdafx.h"
#include "GetCardInfo.h"
#include <stdio.h>

// #define DEBUG

// CGetCardInfo Class Interface Realization


STDMETHODIMP CGetCardInfo::GetCardNo(SHORT cr_type, LONG port_num, LONG baud_rate, LONG* card_no)
{
	// TODO: 在此添加实现代码
	int m_ret = -1;
	unsigned int card_number;
	wchar_t err_msg[256];		//Note： VC++ 2005/2008/2010 缺省使用Unicode字符集
	
	//wchar_t buf[256];

	if(bDllInitFlag)		 // DLL接口文件已经初始化
	{
		if(!bCRInitFlag)	// 读卡器尚未初始化
		 m_ret = this->CRInitFunc(static_cast<short>(cr_type),static_cast<long>(port_num),static_cast<long>(baud_rate));

		if (m_ret!=0 && bCRInitFlag==false) 
		{		
			wsprintf(err_msg,L"读卡器初始化失败! 出错代码：%d\n",m_ret);
			//MultiBytesToWideChar(
			::MessageBox(NULL,err_msg, TEXT("提示信息"),MB_OK | MB_ICONINFORMATION);
			*card_no = static_cast<LONG>(-1);
		}
		else
		{
			bCRInitFlag = true;
			m_ret = this->FastGetCardNoFunc(&card_number);
			this ->CRBeepFunc(beep_seconds);

			if(m_ret!=0)
			{			
				wsprintf(err_msg,L"快速读取卡片序列号失败! 出错代码：%d\n",m_ret);
				::MessageBox(NULL,err_msg, TEXT("提示信息"),MB_OK | MB_ICONINFORMATION);
				*card_no = static_cast<LONG>(0);
			}
			else
			{
#ifdef	DEBUG
				wsprintf(err_msg,L"快速读取卡片序列号成功! 卡片序列号：%d\n",card_number);
				::MessageBox(NULL,err_msg,TEXT("提示信息"),MB_OK | MB_ICONINFORMATION);
#endif

				*card_no = static_cast<LONG>(card_number);
			}
		}
	}
	else
	{	
		wsprintf(err_msg,L"DLL接口文件初始化失败!\n");
		::MessageBox(NULL,err_msg,TEXT("提示信息"),MB_OK | MB_ICONINFORMATION);
   }

   this->_AtlFinalRelease(); 
   
   return S_OK;
}

