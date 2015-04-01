

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Tue Sep 13 17:50:37 2011
 */
/* Compiler settings for .\ReadCardX.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ReadCardX_i_h__
#define __ReadCardX_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IGetCardInfo_FWD_DEFINED__
#define __IGetCardInfo_FWD_DEFINED__
typedef interface IGetCardInfo IGetCardInfo;
#endif 	/* __IGetCardInfo_FWD_DEFINED__ */


#ifndef ___IGetCardInfoEvents_FWD_DEFINED__
#define ___IGetCardInfoEvents_FWD_DEFINED__
typedef interface _IGetCardInfoEvents _IGetCardInfoEvents;
#endif 	/* ___IGetCardInfoEvents_FWD_DEFINED__ */


#ifndef __GetCardInfo_FWD_DEFINED__
#define __GetCardInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class GetCardInfo GetCardInfo;
#else
typedef struct GetCardInfo GetCardInfo;
#endif /* __cplusplus */

#endif 	/* __GetCardInfo_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IGetCardInfo_INTERFACE_DEFINED__
#define __IGetCardInfo_INTERFACE_DEFINED__

/* interface IGetCardInfo */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IGetCardInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("50646DBE-557E-47AD-96EC-6E4EA38DF12F")
    IGetCardInfo : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCardNo( 
            /* [in] */ SHORT cr_type,
            /* [in] */ LONG port_num,
            LONG baud_rate,
            /* [retval][out] */ LONG *card_no) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGetCardInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGetCardInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGetCardInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGetCardInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGetCardInfo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGetCardInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGetCardInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGetCardInfo * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCardNo )( 
            IGetCardInfo * This,
            /* [in] */ SHORT cr_type,
            /* [in] */ LONG port_num,
            LONG baud_rate,
            /* [retval][out] */ LONG *card_no);
        
        END_INTERFACE
    } IGetCardInfoVtbl;

    interface IGetCardInfo
    {
        CONST_VTBL struct IGetCardInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGetCardInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGetCardInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGetCardInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGetCardInfo_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGetCardInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGetCardInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGetCardInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGetCardInfo_GetCardNo(This,cr_type,port_num,baud_rate,card_no)	\
    ( (This)->lpVtbl -> GetCardNo(This,cr_type,port_num,baud_rate,card_no) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGetCardInfo_INTERFACE_DEFINED__ */



#ifndef __ReadCardXLib_LIBRARY_DEFINED__
#define __ReadCardXLib_LIBRARY_DEFINED__

/* library ReadCardXLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ReadCardXLib;

#ifndef ___IGetCardInfoEvents_DISPINTERFACE_DEFINED__
#define ___IGetCardInfoEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IGetCardInfoEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IGetCardInfoEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B3DCBAB2-7327-4707-9627-079DADC771AE")
    _IGetCardInfoEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IGetCardInfoEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IGetCardInfoEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IGetCardInfoEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IGetCardInfoEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IGetCardInfoEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IGetCardInfoEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IGetCardInfoEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IGetCardInfoEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IGetCardInfoEventsVtbl;

    interface _IGetCardInfoEvents
    {
        CONST_VTBL struct _IGetCardInfoEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IGetCardInfoEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IGetCardInfoEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IGetCardInfoEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IGetCardInfoEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IGetCardInfoEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IGetCardInfoEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IGetCardInfoEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IGetCardInfoEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_GetCardInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("D54DAD92-CB31-44A2-AA87-B0092F97CE90")
GetCardInfo;
#endif
#endif /* __ReadCardXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


