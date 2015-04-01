// GetCardInfo.cpp : Implementation of CGetCardInfo

#include "stdafx.h"
#include "GetCardInfo.h"
#include <stdio.h>

// #define DEBUG

// CGetCardInfo Class Interface Realization


STDMETHODIMP CGetCardInfo::GetCardNo(SHORT cr_type, LONG port_num, LONG baud_rate, LONG* card_no)
{
	// TODO: �ڴ����ʵ�ִ���
	int m_ret = -1;
	unsigned int card_number;
	wchar_t err_msg[256];		//Note�� VC++ 2005/2008/2010 ȱʡʹ��Unicode�ַ���
	
	//wchar_t buf[256];

	if(bDllInitFlag)		 // DLL�ӿ��ļ��Ѿ���ʼ��
	{
		if(!bCRInitFlag)	// ��������δ��ʼ��
		 m_ret = this->CRInitFunc(static_cast<short>(cr_type),static_cast<long>(port_num),static_cast<long>(baud_rate));

		if (m_ret!=0 && bCRInitFlag==false) 
		{		
			wsprintf(err_msg,L"��������ʼ��ʧ��! ������룺%d\n",m_ret);
			//MultiBytesToWideChar(
			::MessageBox(NULL,err_msg, TEXT("��ʾ��Ϣ"),MB_OK | MB_ICONINFORMATION);
			*card_no = static_cast<LONG>(-1);
		}
		else
		{
			bCRInitFlag = true;
			m_ret = this->FastGetCardNoFunc(&card_number);
			this ->CRBeepFunc(beep_seconds);

			if(m_ret!=0)
			{			
				wsprintf(err_msg,L"���ٶ�ȡ��Ƭ���к�ʧ��! ������룺%d\n",m_ret);
				::MessageBox(NULL,err_msg, TEXT("��ʾ��Ϣ"),MB_OK | MB_ICONINFORMATION);
				*card_no = static_cast<LONG>(0);
			}
			else
			{
#ifdef	DEBUG
				wsprintf(err_msg,L"���ٶ�ȡ��Ƭ���кųɹ�! ��Ƭ���кţ�%d\n",card_number);
				::MessageBox(NULL,err_msg,TEXT("��ʾ��Ϣ"),MB_OK | MB_ICONINFORMATION);
#endif

				*card_no = static_cast<LONG>(card_number);
			}
		}
	}
	else
	{	
		wsprintf(err_msg,L"DLL�ӿ��ļ���ʼ��ʧ��!\n");
		::MessageBox(NULL,err_msg,TEXT("��ʾ��Ϣ"),MB_OK | MB_ICONINFORMATION);
   }

   this->_AtlFinalRelease(); 
   
   return S_OK;
}

