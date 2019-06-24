//---------------------------------------------------------------------------

#ifndef Ukas1CSystemCOMH
#define Ukas1CSystemCOMH
//---------------------------------------------------------------------------


//#include "vcl.h"
//#include <windows.h>
//#include <Classes.hpp>
//#include "unknwn.h"
#include "AddIn_i.h"
//это интерфейс нашей программы, подменяющий интерфейс 1С

class Tkas1CSystemCOM : public IDispatch,
								IPropertyProfile,
								IErrorLog,
								IMsgBox,
								IPlatformInfo,
								IAsyncEvent,
								IStatusLine,
								IExtWndsSupport

{
private:
public:
		Tkas1CSystemCOM();
		~Tkas1CSystemCOM();

		//IUnknown
		//*************

		HRESULT STDMETHODCALLTYPE QueryInterface(
				/* [in] */ REFIID riid,
				/* [iid_is][out] */ __RPC__deref_out void __RPC_FAR *__RPC_FAR *ppvObject);

		ULONG STDMETHODCALLTYPE AddRef( void);

		ULONG STDMETHODCALLTYPE Release( void);


		//IDispatch
		//***************

		HRESULT STDMETHODCALLTYPE GetTypeInfoCount(
			/* [out] */ __RPC__out UINT *pctinfo);

		HRESULT STDMETHODCALLTYPE GetTypeInfo(
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
			/* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);

		HRESULT STDMETHODCALLTYPE GetIDsOfNames(
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
			/* [in] */ LCID lcid,
			/* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);

		 /* [local] */ HRESULT STDMETHODCALLTYPE Invoke(
            /* [in] */ DISPID dispIdMember,
			/* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
			/* [out] */ EXCEPINFO *pExcepInfo,
			/* [out] */ UINT *puArgErr);



		//IPropertyProfile
		//***************
		/* [helpstring] */ HRESULT STDMETHODCALLTYPE RegisterProfileAs(
			BSTR bstrProfileName);

		//IPropertyBag
		//***************


		 /* [local] */ HRESULT STDMETHODCALLTYPE Read(
			/* [in] */ LPCOLESTR pszPropName,
            /* [out][in] */ VARIANT *pVar,
			/* [unique][in] */ IErrorLog *pErrorLog) ;

		HRESULT STDMETHODCALLTYPE Write(
			/* [in] */ __RPC__in LPCOLESTR pszPropName,
			/* [in] */ __RPC__in VARIANT *pVar);




	   //IErrorLog
	   //***********

		HRESULT STDMETHODCALLTYPE AddError(
			/* [in] */ __RPC__in LPCOLESTR pszPropName,
			/* [in] */ __RPC__in EXCEPINFO *pExcepInfo) ;



	   //IMsgBox
	   //********
		 /* [helpstring] */ HRESULT STDMETHODCALLTYPE QueryBox(
            /* [in] */ BSTR queryText,
            /* [in] */ Button *buttons,
			/* [in] */ UINT sizeButtons,
            /* [out][in] */ VARIANT *retVal,
            /* [defaultvalue][in] */ ULONG timeout = 0,
            /* [defaultvalue][in] */ UINT defButton = 0,
            /* [defaultvalue][in] */ BSTR caption = 0,
			/* [defaultvalue][in] */ UINT timeoutButton = 0);

		/* [helpstring] */ HRESULT STDMETHODCALLTYPE MessageBox(
            /* [in] */ BSTR text,
            /* [out][in] */ VARIANT *retVal,
			/* [defaultvalue][in] */ ULONG timeout = 0,
			/* [defaultvalue][in] */ BSTR caption = 0);



		//IPlatformInfo
		//******************

		 /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPlatformInfo(
			/* [retval][out] */ AppInfo **info) ;





	   //IAsyncEvent
	   //****************
		 /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetEventBufferDepth(
			long lDepth);

		/* [helpstring] */ HRESULT STDMETHODCALLTYPE GetEventBufferDepth(
			long *plDepth) ;

		 /* [helpstring] */ HRESULT STDMETHODCALLTYPE ExternalEvent(
            BSTR bstrSource,
			BSTR bstrMessage,
			BSTR bstrData) ;

	 /* [helpstring] */ HRESULT STDMETHODCALLTYPE CleanBuffer( void);


		//IStatusLine.
		//******************
		 /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetStatusLine(
			BSTR bstrStatusLine);

		/* [helpstring] */ HRESULT STDMETHODCALLTYPE ResetStatusLine( void);


		//IExtWndsSupport
		//******************
		 /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAppMainFrame(
			/* [out][in] */ HWND *hwnd);

		/* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAppMDIFrame(
			/* [out][in] */ HWND *hwnd);

		 /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateAddInWindow(
			/* [in] */ BSTR bstrProgID,
            /* [in] */ BSTR bstrWindowName,
            /* [in] */ long dwStyles,
            /* [in] */ long dwExStyles,
			/* [in] */ RECT *rctl,
			/* [in] */ long Flags,
			/* [out][in] */ HWND *pHwnd,
			/* [out][in] */ IDispatch **pDisp) ;

};

#endif
