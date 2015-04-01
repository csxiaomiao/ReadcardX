

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IGetCardInfo,0x50646DBE,0x557E,0x47AD,0x96,0xEC,0x6E,0x4E,0xA3,0x8D,0xF1,0x2F);


MIDL_DEFINE_GUID(IID, LIBID_ReadCardXLib,0x5AFC8815,0x9AC1,0x4D8F,0x9E,0xCB,0x0E,0xC3,0xA4,0x7E,0x70,0x3F);


MIDL_DEFINE_GUID(IID, DIID__IGetCardInfoEvents,0xB3DCBAB2,0x7327,0x4707,0x96,0x27,0x07,0x9D,0xAD,0xC7,0x71,0xAE);


MIDL_DEFINE_GUID(CLSID, CLSID_GetCardInfo,0xD54DAD92,0xCB31,0x44A2,0xAA,0x87,0xB0,0x09,0x2F,0x97,0xCE,0x90);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



