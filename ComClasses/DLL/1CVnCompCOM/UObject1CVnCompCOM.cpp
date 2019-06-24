//---------------------------------------------------------------------------


#pragma hdrstop

#include "UObject1CVnCompCOM.h"
//#include <vcl.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)


TObject1CVnCompCOM::TObject1CVnCompCOM()
{
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
VC=0; //без этого не создается класс, видимо получается не нулевой указатель, а в библиотеке проверка

	My1CSystem = new Tkas1CSystemCOM();

}
//-----------------------------------------------------------------------------
TObject1CVnCompCOM::~TObject1CVnCompCOM()
{
	delete My1CSystem;

}
//---------------------------------------------------------------------------

bool TObject1CVnCompCOM::InitVC()
{
bool result=false;


		CLSID clsid;
        IClassFactory* pCF;
        IUnknown* pUnk;


		CoInitialize(0);
		wchar_t * prog_id=ProgIdCOMObject;

		HRESULT hr = ::CLSIDFromProgID(prog_id, &clsid );

		if ( FAILED( hr ))
			{
			TextError=L"Не Получили CLSID заданного ProgId = ";
			return result;
			}

        hr = CoGetClassObject( clsid, CLSCTX_INPROC, NULL,IID_IClassFactory, (void**) &pCF );
        if ( FAILED( hr ))
			{
			TextError=L"Не получили фабрику классов";
			return result;
			}

		hr = pCF->CreateInstance( NULL, IID_IUnknown, (void**) &pUnk );
		pCF->Release();
        if ( FAILED( hr ))
			{
			TextError=L"Не создали класс внешней компоненты";
			return result;
			}

		IInitDone *  i;
		hr = pUnk->QueryInterface(__uuidof(IInitDone), (void**) &i);

		if ( FAILED( hr ))
			{
			TextError=L"Не Создали рабочий интерфейс IInitDone";
			pUnk->Release();
			return result;
			}

				IDispatch * disp=0;
				disp=static_cast<IDispatch*> (My1CSystem);
		hr = i->Init(disp);
		if ( FAILED( hr ))
			{
			TextError=L"Не удалось выполнить метод Init интерфейса IInitDone";
			pUnk->Release();
			return result;
			}



		hr = pUnk->QueryInterface(__uuidof(ILanguageExtender), (void**) &VC);

		if ( FAILED( hr ))
			{
			TextError=L"Не Создали рабочий интерфейс ILanguageExtender";
			return result;
			}


	   result=true;
	   pUnk->Release();

return result;
}
//---------------------------------------------------------------------------
void TObject1CVnCompCOM::DoneVC()
{
IInitDone *  i;
VC->QueryInterface(__uuidof(IInitDone), (void**) &i);
i->Done();
VC->Release();
}
 //*****************-----------------------------------------------------------

//-------------------------------------------------------------------------------
void TObject1CVnCompCOM::Init_VARIANT(VARIANT * st, int type_value)
{

st->vt=VT_EMPTY;
st->wReserved1=0;
st->wReserved1=0;
st->wReserved3=0;
				/*LONGLONG */          	st->llVal=0;
				/*LONG */ 				st->lVal=0;
				/*BYTE      */			st->bVal=0;
				/*SHORT       */		st->iVal=0;
				/*FLOAT       */		st->fltVal=0;
				/*DOUBLE       */		st->dblVal=0;
				/*VARIANT_BOOL       */	st->boolVal=0;
				/*_VARIANT_BOOL       *///st->bool=0;
				/*SCODE       */		st->scode;
				/*CY       */			st->cyVal;
				/*DATE       */			st->date=0;
				/*BSTR       */			st->bstrVal=SysAllocString(L"");
				/*IUnknown *      */	st->punkVal=0;
				/*IDispatch *      */	st->pdispVal=0;
				/*SAFEARRAY *      */	st->parray=0;
				/*BYTE *      */		st->pbVal=0;
				/*SHORT *      */		st->piVal=0;
				/*LONG *      */		st->plVal=0;
				/*LONGLONG *      */	st->pllVal=0;
				/*FLOAT *      */		st->pfltVal=0;
				/*DOUBLE *      */		st->pdblVal=0;
				/*VARIANT_BOOL *      */st->pboolVal=0;
				/*_VARIANT_BOOL *      *///st->pbool=0;
				/*SCODE *      */		st->pscode;
				/*CY *      */			st->pcyVal;
				/*DATE *      */		st->pdate=0;
				/*BSTR *      */		st->pbstrVal=0;
				/*IUnknown **      */	st->ppunkVal=0;
				/*IDispatch **      */	st->ppdispVal=0;
				/*SAFEARRAY **      */	st->pparray=0;
				/*VARIANT *      */		st->pvarVal=0;
				/*PVOID       */		st->byref=0;
				/*CHAR       */			st->cVal=0;
				/*USHORT       */		st->uiVal=0;
				/*ULONG       */		st->ulVal=0;
				/*ULONGLONG       */	st->ullVal=0;
				/*INT       */			st->intVal=0;
				/*UINT       */			st->uintVal=0;
				/*DECIMAL *      */		st->pdecVal=0;
				/*CHAR *      */		st->pcVal=0;
				/*USHORT *      */		st->puiVal=0;
				/*ULONG *      */		st->pulVal=0;
				/*ULONGLONG *      */	st->pullVal=0;
				/*INT *      */			st->pintVal=0;
				/*UINT *      */		st->puintVal=0;
				/*PVOID       */		st->pvRecord=0;
				/*IRecordInfo *      */	st->pRecInfo=0;
		/*DECIMAL       */				//st->decVal=0;

}
//--------------------------------------------------------------------------


VARIANT* TObject1CVnCompCOM::ConvertKasVariantIn1CVARIANT(TkasVariant * kas_variant)
{
VARIANT * variant_result=new VARIANT;
Init_VARIANT(variant_result, 0);
//// 0 не задан 1 int, 2 строка, 3 double, 4 дата, 5 время, 6 датаВремя
if (kas_variant->type==0)
	{

	}


if (kas_variant->type==1)    //int
	{
	variant_result->vt = VT_I4;
	variant_result->lVal=kas_variant->int_value;
	}

if (kas_variant->type==2)    //строка
	{
	variant_result->vt = VT_BSTR;
	variant_result->bstrVal=SysAllocString(kas_variant->string_value);
	//variant_result->wstrLen=kas_variant->len_string; //count of symbol
	}

if (kas_variant->type==3)    //double
	{
	variant_result->vt = VT_R8;
	variant_result->dblVal=kas_variant->dbl_value;
	}

if (kas_variant->type==4)    //bool
	{
	variant_result->vt = VT_I4;
	variant_result->iVal=kas_variant->bool_value;
	}

return  variant_result;
}
////--------------------------------------------------------------------------

TkasVariant * TObject1CVnCompCOM::Convert1CVARIANTInKasVariant(VARIANT * variant_1c)
{
TkasVariant * result=new TkasVariant;
result->type=0;
result->int_value=0;
result->string_value=L"";
result->dbl_value=0;
result->bool_value=0;
result->day=0;
result->month=0;
result->year=0;
result->hour=0;
result->min=0;
result->sec=0;
//
//// 0 не задан 1 int, 2 строка, 3 double, 4 дата, 5 время, 6 датаВремя


if (variant_1c->vt==VT_I4)    //int
	{
	result->type=1;
	result->int_value=variant_1c->lVal;
	}

if (variant_1c->vt==VT_I2)    //int
	{
	result->type=1;
	result->int_value=variant_1c->lVal;
	}

if (variant_1c->vt==VT_BSTR)    //строка
	{
	result->type=2;


		UINT length = SysStringLen(variant_1c->bstrVal);
		// определяем длину BSTR

		if (length>0)
		{
			result->string_value = new wchar_t[(length+1)]; // используем "+1" т.к. SysStringLen не учел nul в конце строки
			wcscpy(result->string_value,variant_1c->bstrVal); // копируем, используя безопасную wcscpy_s вместо wcscpy, помеченной как "deprecated"
			//SysFreeString(name_metod); // скопированную уже BSTR-строку теперь можно корректно удалить
		result->len_string=length;
		}
	}

if (variant_1c->vt==VT_R8)    //double
	{
	result->type=3;
	result->dbl_value=variant_1c->dblVal;
	}

if (variant_1c->vt==VT_BOOL)    //нет такого
	{
	result->type=4;
	if (variant_1c->lVal == 0)
		{
		result->bool_value=false;
		}
	else
		{
        result->bool_value=true;
		}
	}


return  result;
//
}
////--------------------------------------------------------------------------

  //     IInitDone : public IUnknown


//      ILanguageExtender : public IUnknown

bool TObject1CVnCompCOM::RegisterExtensionAs(
			/* [out][in] */ wchar_t *bstrExtensionName)
{
bool result=false;


return result;
}
//---------------------------------------------------------------------------

bool TObject1CVnCompCOM::GetNProps(
			/* [out][in] */ long *plProps)
{
bool result=true;

HRESULT	hr = VC->GetNProps(plProps);

if ( FAILED( hr ))
	{
	TextError=L"Не удалось выполнить метод GetNProps";
	result=false;
	}

return result;
}
//---------------------------------------------------------------------------

bool TObject1CVnCompCOM::FindProp(
			/* [in] */ wchar_t * bstrPropName,
			/* [out][in] */ long *plPropNum)
{
bool result=false;


return result;
}
//---------------------------------------------------------------------------

bool TObject1CVnCompCOM::GetPropName(
            /* [in] */ long lPropNum,
            /* [in] */ long lPropAlias,
			/* [out][in] */ wchar_t *pbstrPropName)
{
bool result=false;


return result;
}
//---------------------------------------------------------------------------

bool TObject1CVnCompCOM::GetPropVal(
            /* [in] */ long lPropNum,
			/* [out][in] */ TkasVariant *pvarPropVal)
{
bool result=false;


return result;
}
//---------------------------------------------------------------------------

bool TObject1CVnCompCOM::SetPropVal(
            /* [in] */ long lPropNum,
			/* [in] */ TkasVariant *varPropVal)
{
bool result=false;


return result;
}
//---------------------------------------------------------------------------

bool TObject1CVnCompCOM::IsPropReadable(
            /* [in] */ long lPropNum,
			/* [out][in] */ bool *pboolPropRead)
{
bool result=false;


return result;
}
//---------------------------------------------------------------------------

bool TObject1CVnCompCOM::IsPropWritable(
            /* [in] */ long lPropNum,
			/* [out][in] */ bool *pboolPropWrite)
{
bool result=false;


return result;
}
//---------------------------------------------------------------------------

bool TObject1CVnCompCOM::GetNMethods(
			/* [out][in] */ long *plMethods)
{
bool result=true;

HRESULT	hr = VC->GetNMethods(plMethods);

if ( FAILED( hr ))
	{
	TextError=L"Не удалось выполнить метод GetNMethods";
	result=false;
	}

return result;
}
//---------------------------------------------------------------------------

bool TObject1CVnCompCOM::FindMethod(
			wchar_t * bstrMethodName,
			/* [out][in] */ long *plMethodNum)
{
bool result=true;

BSTR name_metod=SysAllocString(bstrMethodName);


HRESULT	hr = VC->FindMethod(name_metod,plMethodNum);

if ( FAILED( hr ))
	{
	TextError=L"Не удалось выполнить метод GetNMethods";
	result=false;
	}



return result;
}
//---------------------------------------------------------------------------

bool TObject1CVnCompCOM::GetMethodName(
			/* [in] */ long lMethodNum,
			/* [in] */ long lMethodAlias,
			/* [out][in] */ wchar_t *pbstrMethodName)
{
bool result=false;

BSTR name_metod=SysAllocString(L"");


HRESULT	hr = VC->GetMethodName(lMethodNum, lMethodAlias, &name_metod);

if ( FAILED( hr ))
	{
	TextError=L"Не удалось выполнить метод GetNMethods";
	result=false;
	}
// определяем длину BSTR
UINT length = SysStringLen(name_metod);

if (length>0)
{
	*pbstrMethodName = * new wchar_t[(length+1)]; // используем "+1" т.к. SysStringLen не учел nul в конце строки
	wcscpy(pbstrMethodName,name_metod); // копируем, используя безопасную wcscpy_s вместо wcscpy, помеченной как "deprecated"
	SysFreeString(name_metod); // скопированную уже BSTR-строку теперь можно корректно удалить
}
return result;
}
//---------------------------------------------------------------------------

bool TObject1CVnCompCOM::GetNParams(
			/* [in] */ long lMethodNum,
			/* [out][in] */ long *plParams)
{
bool result=true;

HRESULT	hr = VC->GetNParams(lMethodNum,plParams);

if ( FAILED( hr ))
	{
	TextError=L"Не удалось выполнить метод GetNMethods";
	result=false;
	}
return result;
}
//---------------------------------------------------------------------------

bool TObject1CVnCompCOM::GetParamDefValue(
            /* [in] */ long lMethodNum,
            /* [in] */ long lParamNum,
			/* [out][in] */ TkasVariant *pvarParamDefValue)
{
bool result=false;


return result;
}
//---------------------------------------------------------------------------

bool TObject1CVnCompCOM::HasRetVal(
			/* [in] */ long lMethodNum,
			/* [out][in] */ bool *pboolRetValue)
{
bool result=false;

int result_int=0;


HRESULT	hr = VC->HasRetVal(lMethodNum,&result_int);

if ( FAILED( hr ))
	{
	TextError=L"Не удалось выполнить метод GetNMethods";
	result=false;
	}

if (result_int==0)
	{
	*pboolRetValue=false;
	}
else
	{    //если больше нуля то true
	*pboolRetValue=true;
	}

return result;
}
//---------------------------------------------------------------------------

bool TObject1CVnCompCOM::CallAsProc(
			/* [in] */ long lMethodNum,
			/* [out][in] */ TkasVariant *paParams, int lSizeArray)
{
bool result=false;

HRESULT	hr;
long max_index=lSizeArray;
SAFEARRAY * sa=0;

VARIANT * in_parameter;
in_parameter=new VARIANT[lSizeArray];

sa=SafeArrayCreateVector(VT_VARIANT ,0,	lSizeArray);

for (long i=0;i<max_index;i++)
	{
	in_parameter[i]=*ConvertKasVariantIn1CVARIANT(&paParams[i]);
	hr=SafeArrayPutElement(sa, &i, &in_parameter[i]);
	}



hr = VC->CallAsProc(lMethodNum, &sa) ;

if ( FAILED( hr ))
	{
	TextError=L"Не удалось выполнить метод CallAsFunc";
	result=false;
	}

for (long i=0;i<max_index;i++)
	{
	hr=SafeArrayGetElement(sa, &i, &in_parameter[i]);
	paParams[i]=*Convert1CVARIANTInKasVariant(&in_parameter[i]);
	}

return result;
}
//---------------------------------------------------------------------------

bool TObject1CVnCompCOM::CallAsFunc(
			/* [in] */ long lMethodNum,
			/* [out][in] */ TkasVariant *pvarRetValue,
			/* [out][in] */ TkasVariant *paParams, int lSizeArray)
{
bool result=true;
HRESULT	hr;
long max_index=lSizeArray;
SAFEARRAY * sa=0;

VARIANT * variant_result=new VARIANT;
Init_VARIANT(variant_result, 0);

VARIANT * in_parameter;
in_parameter=new VARIANT[lSizeArray];


sa=SafeArrayCreateVector(VT_VARIANT ,0,	lSizeArray);



for (long i=0;i<max_index;i++)
	{
	in_parameter[i]=*ConvertKasVariantIn1CVARIANT(&paParams[i]);
	hr=SafeArrayPutElement(sa, &i, &in_parameter[i]);
	}

hr = VC->CallAsFunc(lMethodNum,variant_result, &sa) ;

if ( FAILED( hr ))
	{
	TextError=L"Не удалось выполнить метод CallAsFunc";
	result=false;
	}

for (long i=0;i<max_index;i++)
	{
	hr=SafeArrayGetElement(sa, &i, &in_parameter[i]);
	paParams[i]=*Convert1CVARIANTInKasVariant(&in_parameter[i]);
	}

*pvarRetValue=*Convert1CVARIANTInKasVariant(variant_result);

return result;
}
//---------------------------------------------------------------------------
