//---------------------------------------------------------------------------


#pragma hdrstop

#include "Ukas1CSystemCOM.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
Tkas1CSystemCOM::Tkas1CSystemCOM()
{

}
//-----------------------------------------------------------------------------
Tkas1CSystemCOM::~Tkas1CSystemCOM()
{
//FreeLibrary(dllIn);
}
//---------------------------------------------------------------------------

		//IUnknown
		//*************

HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::QueryInterface(
				/* [in] */ REFIID riid,
				/* [iid_is][out] */ __RPC__deref_out void __RPC_FAR *__RPC_FAR *ppvObject)
{
//IDispatch,
//								IPropertyProfile,
//								IErrorLog,
//								IMsgBox,
//								IPlatformInfo,
//								IAsyncEvent,
//								IStatusLine,
//								IExtWndsSupport

if (riid==__uuidof(IUnknown))
   {
   //*ppvObject=static_cast<IUnknown*> (this);
   }
else if (riid==IID_IDispatch)
   {
   *ppvObject=static_cast<IDispatch*> (this);
   }
else if (riid==__uuidof(IPropertyProfile))
   {
   *ppvObject=static_cast<IPropertyProfile*> (this);
   }
else if (riid==__uuidof(IErrorLog))
   {
   *ppvObject=static_cast<IErrorLog*> (this);
   }
else if (riid==__uuidof(IMsgBox))
   {
   *ppvObject=static_cast<IMsgBox*> (this);
   }
else if (riid==__uuidof(IPlatformInfo))
   {
   *ppvObject=static_cast<IPlatformInfo*> (this);
   }
else if (riid==__uuidof(IAsyncEvent))
   {
   *ppvObject=static_cast<IAsyncEvent*> (this);
   }
else if (riid==__uuidof(IStatusLine))
   {
   *ppvObject=static_cast<IStatusLine*> (this);
   }
else if (riid==__uuidof(IExtWndsSupport))
   {
   *ppvObject=static_cast<IExtWndsSupport*> (this);
   }
else
   {
   ppvObject=0;
   }

return S_OK;
}
//---------------------------------------------------------------------------

ULONG STDMETHODCALLTYPE Tkas1CSystemCOM::AddRef( void)
{

}
//---------------------------------------------------------------------------

ULONG STDMETHODCALLTYPE Tkas1CSystemCOM::Release( void)
{


}
//-----------------------------------------------------------------------------


		//IDispatch
		//***************

HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::GetTypeInfoCount(
			/* [out] */ __RPC__out UINT *pctinfo)
{

return S_OK;
}
//---------------------------------------------------------------------------

HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::GetTypeInfo(
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
			/* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo)
{

return S_OK;
}
//---------------------------------------------------------------------------

HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::GetIDsOfNames(
            /* [in] */ __RPC__in REFIID riid,
            /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
            /* [range][in] */ __RPC__in_range(0,16384) UINT cNames,
			/* [in] */ LCID lcid,
			/* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId)
{

return S_OK;
}
//---------------------------------------------------------------------------

HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::Invoke(
            /* [in] */ DISPID dispIdMember,
			/* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
			/* [out] */ EXCEPINFO *pExcepInfo,
			/* [out] */ UINT *puArgErr)
{

return S_OK;
}
//---------------------------------------------------------------------------



		//IPropertyProfile
		//***************
HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::RegisterProfileAs(
			BSTR bstrProfileName)
{

return S_OK;
}
//---------------------------------------------------------------------------

		//IPropertyBag
		//***************


HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::Read(
			/* [in] */ LPCOLESTR pszPropName,
            /* [out][in] */ VARIANT *pVar,
			/* [unique][in] */ IErrorLog *pErrorLog)
{

return S_OK;
}
//---------------------------------------------------------------------------

HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::Write(
			/* [in] */ __RPC__in LPCOLESTR pszPropName,
			/* [in] */ __RPC__in VARIANT *pVar)
{

return S_OK;
}
//---------------------------------------------------------------------------




	   //IErrorLog
	   //***********

HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::AddError(
			/* [in] */ __RPC__in LPCOLESTR pszPropName,
			/* [in] */ __RPC__in EXCEPINFO *pExcepInfo)
{

return S_OK;
}
//---------------------------------------------------------------------------



	   //IMsgBox
	   //********
HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::QueryBox(
            /* [in] */ BSTR queryText,
            /* [in] */ Button *buttons,
			/* [in] */ UINT sizeButtons,
            /* [out][in] */ VARIANT *retVal,
			/* [defaultvalue][in] */ ULONG timeout,
			/* [defaultvalue][in] */ UINT defButton,
			/* [defaultvalue][in] */ BSTR caption,
			/* [defaultvalue][in] */ UINT timeoutButton)
{

return S_OK;
}
//---------------------------------------------------------------------------

HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::MessageBox(
            /* [in] */ BSTR text,
            /* [out][in] */ VARIANT *retVal,
			/* [defaultvalue][in] */ ULONG timeout,
			/* [defaultvalue][in] */ BSTR caption)
{

return S_OK;
}
//---------------------------------------------------------------------------



		//IPlatformInfo
		//******************

HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::GetPlatformInfo(
			/* [retval][out] */ AppInfo **info)
{

return S_OK;
}
//---------------------------------------------------------------------------





	   //IAsyncEvent
	   //****************
HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::SetEventBufferDepth(
			long lDepth)
{

return S_OK;
}
//---------------------------------------------------------------------------

HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::GetEventBufferDepth(
			long *plDepth)
{

return S_OK;
}
//---------------------------------------------------------------------------

HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::ExternalEvent(
            BSTR bstrSource,
			BSTR bstrMessage,
			BSTR bstrData)
{

return S_OK;
}
//---------------------------------------------------------------------------

HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::CleanBuffer( void)
{

return S_OK;
}
//---------------------------------------------------------------------------


		//IStatusLine.
		//******************
HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::SetStatusLine(
			BSTR bstrStatusLine)
{

return S_OK;
}
//---------------------------------------------------------------------------

HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::ResetStatusLine( void)
{

return S_OK;
}
//---------------------------------------------------------------------------


		//IExtWndsSupport
		//******************
HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::GetAppMainFrame(
			/* [out][in] */ HWND *hwnd)
{

return S_OK;
}
//---------------------------------------------------------------------------

HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::GetAppMDIFrame(
			/* [out][in] */ HWND *hwnd)
{

return S_OK;
}
//---------------------------------------------------------------------------

HRESULT STDMETHODCALLTYPE Tkas1CSystemCOM::CreateAddInWindow(
			/* [in] */ BSTR bstrProgID,
            /* [in] */ BSTR bstrWindowName,
            /* [in] */ long dwStyles,
            /* [in] */ long dwExStyles,
			/* [in] */ RECT *rctl,
			/* [in] */ long Flags,
			/* [out][in] */ HWND *pHwnd,
			/* [out][in] */ IDispatch **pDisp)
{

return S_OK;
}
//---------------------------------------------------------------------------
