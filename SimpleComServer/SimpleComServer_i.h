

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Jun 30 17:01:27 2016
 */
/* Compiler settings for SimpleComServer.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

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

#ifndef __SimpleComServer_i_h__
#define __SimpleComServer_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISmartControl_FWD_DEFINED__
#define __ISmartControl_FWD_DEFINED__
typedef interface ISmartControl ISmartControl;

#endif 	/* __ISmartControl_FWD_DEFINED__ */


#ifndef __SmartControl_FWD_DEFINED__
#define __SmartControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class SmartControl SmartControl;
#else
typedef struct SmartControl SmartControl;
#endif /* __cplusplus */

#endif 	/* __SmartControl_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ISmartControl_INTERFACE_DEFINED__
#define __ISmartControl_INTERFACE_DEFINED__

/* interface ISmartControl */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISmartControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5B93ACD7-21B3-4747-B9E3-45660F1EBC5A")
    ISmartControl : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetServices( 
            /* [out] */ BSTR *str) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServiceStatus( 
            /* [in] */ BSTR *str,
            /* [out] */ DWORD *rstatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopMyService( 
            /* [in] */ BSTR *str) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartMyService( 
            /* [in] */ BSTR *str) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE call( 
            /* [in] */ BSTR c) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISmartControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISmartControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISmartControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISmartControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISmartControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISmartControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISmartControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISmartControl * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetServices )( 
            ISmartControl * This,
            /* [out] */ BSTR *str);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceStatus )( 
            ISmartControl * This,
            /* [in] */ BSTR *str,
            /* [out] */ DWORD *rstatus);
        
        HRESULT ( STDMETHODCALLTYPE *StopMyService )( 
            ISmartControl * This,
            /* [in] */ BSTR *str);
        
        HRESULT ( STDMETHODCALLTYPE *StartMyService )( 
            ISmartControl * This,
            /* [in] */ BSTR *str);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *call )( 
            ISmartControl * This,
            /* [in] */ BSTR c);
        
        END_INTERFACE
    } ISmartControlVtbl;

    interface ISmartControl
    {
        CONST_VTBL struct ISmartControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISmartControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISmartControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISmartControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISmartControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISmartControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISmartControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISmartControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISmartControl_GetServices(This,str)	\
    ( (This)->lpVtbl -> GetServices(This,str) ) 

#define ISmartControl_GetServiceStatus(This,str,rstatus)	\
    ( (This)->lpVtbl -> GetServiceStatus(This,str,rstatus) ) 

#define ISmartControl_StopMyService(This,str)	\
    ( (This)->lpVtbl -> StopMyService(This,str) ) 

#define ISmartControl_StartMyService(This,str)	\
    ( (This)->lpVtbl -> StartMyService(This,str) ) 

#define ISmartControl_call(This,c)	\
    ( (This)->lpVtbl -> call(This,c) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISmartControl_INTERFACE_DEFINED__ */



#ifndef __SimpleComServerLib_LIBRARY_DEFINED__
#define __SimpleComServerLib_LIBRARY_DEFINED__

/* library SimpleComServerLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_SimpleComServerLib;

EXTERN_C const CLSID CLSID_SmartControl;

#ifdef __cplusplus

class DECLSPEC_UUID("7FCEF122-B85D-4477-A2C5-E679FEEA149E")
SmartControl;
#endif
#endif /* __SimpleComServerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


