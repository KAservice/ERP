//---------------------------------------------------------------------------

#ifndef UObject1CVnCompCOMH
#define UObject1CVnCompCOMH


#include "GlobalInterface.h"

#include <Ukas1CSystemCOM.h>
#include <UkasVariant.h>
#include <AddIn_i.h>

class TObject1CVnCompCOM
		{
private:


Tkas1CSystemCOM * My1CSystem;
ILanguageExtender * VC;





void Init_VARIANT(VARIANT * st, int type_value);

//#define KAS_IID_ILanguageExtender "AB634003-F13D-11d0-A459-004095E1DAEA"    // ILanguageExtender
//#define KAS_IID_IInitDone "AB634001-F13D-11d0-A459-004095E1DAEA"


 public:
		TObject1CVnCompCOM();
		~TObject1CVnCompCOM();


		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функци€ удалени€ реализации интерфейса
		bool flDeleteImpl;   //надо ли удал€ть реализацию при удалении текущего модул€

		bool Error;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации



		int CodeError;
		wchar_t* TextError;
		bool InitVC();
		void DoneVC();

		wchar_t  * ProgIdCOMObject;

		VARIANT* ConvertKasVariantIn1CVARIANT(TkasVariant * kas_variant);
		TkasVariant * Convert1CVARIANTInKasVariant(VARIANT * variant_1c);

  //     IInitDone : public IUnknown


//      ILanguageExtender : public IUnknown

		bool RegisterExtensionAs(
			/* [out][in] */ wchar_t *bstrExtensionName);

		bool GetNProps(
			/* [out][in] */ long *plProps);

		bool FindProp(
			/* [in] */ wchar_t * bstrPropName,
			/* [out][in] */ long *plPropNum);

		bool GetPropName(
            /* [in] */ long lPropNum,
            /* [in] */ long lPropAlias,
			/* [out][in] */ wchar_t *pbstrPropName);

		bool GetPropVal(
            /* [in] */ long lPropNum,
			/* [out][in] */ TkasVariant *pvarPropVal);

		bool SetPropVal(
            /* [in] */ long lPropNum,
			/* [in] */ TkasVariant *varPropVal);

		bool IsPropReadable(
            /* [in] */ long lPropNum,
			/* [out][in] */ bool *pboolPropRead);

		bool IsPropWritable(
            /* [in] */ long lPropNum,
			/* [out][in] */ bool *pboolPropWrite);

		bool GetNMethods(
			/* [out][in] */ long *plMethods);

		bool FindMethod(
			wchar_t * bstrMethodName,
			/* [out][in] */ long *plMethodNum);

		bool GetMethodName(
            /* [in] */ long lMethodNum,
            /* [in] */ long lMethodAlias,
			/* [out][in] */ wchar_t *pbstrMethodName);

		bool GetNParams(
            /* [in] */ long lMethodNum,
			/* [out][in] */ long *plParams);

		bool GetParamDefValue(
            /* [in] */ long lMethodNum,
            /* [in] */ long lParamNum,
			/* [out][in] */ TkasVariant *pvarParamDefValue);

		bool HasRetVal(
            /* [in] */ long lMethodNum,
			/* [out][in] */ bool *pboolRetValue);

		bool CallAsProc(
			/* [in] */ long lMethodNum,
			/* [out][in] */ TkasVariant *paParams, int lSizeArray);

        bool CallAsFunc(
			/* [in] */ long lMethodNum,
			/* [out][in] */ TkasVariant *pvarRetValue,
			/* [out][in] */ TkasVariant *paParams, int lSizeArray);


		};


//---------------------------------------------------------------------------
#endif


//значение пол€ ->vt в типе VARIANT
/*
 * VARENUM usage key,
 *
 * * [V] - may appear in a VARIANT
 * * [T] - may appear in a TYPEDESC
 * * [P] - may appear in an OLE property set
 * * [S] - may appear in a Safe Array
 *
 *
 *  VT_EMPTY            [V]   [P]     nothing          ничего
 *  VT_NULL             [V]   [P]     SQL style Null
 *  VT_I2               [V][T][P][S]  2 byte signed int
 *  VT_I4               [V][T][P][S]  4 byte signed int
 *  VT_R4               [V][T][P][S]  4 byte real
 *  VT_R8               [V][T][P][S]  8 byte real
 *  VT_CY               [V][T][P][S]  currency
 *  VT_DATE             [V][T][P][S]  date
 *  VT_BSTR             [V][T][P][S]  OLE Automation string
 *  VT_DISPATCH         [V][T]   [S]  IDispatch *
 *  VT_ERROR            [V][T][P][S]  SCODE
 *  VT_BOOL             [V][T][P][S]  True=-1, False=0
 *  VT_VARIANT          [V][T][P][S]  VARIANT *
 *  VT_UNKNOWN          [V][T]   [S]  IUnknown *
 *  VT_DECIMAL          [V][T]   [S]  16 byte fixed point
 *  VT_RECORD           [V]   [P][S]  user defined type
 *  VT_I1               [V][T][P][s]  signed char
 *  VT_UI1              [V][T][P][S]  unsigned char
 *  VT_UI2              [V][T][P][S]  unsigned short
 *  VT_UI4              [V][T][P][S]  unsigned long
 *  VT_I8                  [T][P]     signed 64-bit int
 *  VT_UI8                 [T][P]     unsigned 64-bit int
 *  VT_INT              [V][T][P][S]  signed machine int
 *  VT_UINT             [V][T]   [S]  unsigned machine int
 *  VT_INT_PTR             [T]        signed machine register size width
 *  VT_UINT_PTR            [T]        unsigned machine register size width
 *  VT_VOID                [T]        C style void
 *  VT_HRESULT             [T]        Standard return type
 *  VT_PTR                 [T]        pointer type
 *  VT_SAFEARRAY           [T]        (use VT_ARRAY in VARIANT)
 *  VT_CARRAY              [T]        C style array
 *  VT_USERDEFINED         [T]        user defined type
 *  VT_LPSTR               [T][P]     null terminated string
 *  VT_LPWSTR              [T][P]     wide null terminated string
 *  VT_FILETIME               [P]     FILETIME
 *  VT_BLOB                   [P]     Length prefixed bytes
 *  VT_STREAM                 [P]     Name of the stream follows
 *  VT_STORAGE                [P]     Name of the storage follows
 *  VT_STREAMED_OBJECT        [P]     Stream contains an object
 *  VT_STORED_OBJECT          [P]     Storage contains an object
 *  VT_VERSIONED_STREAM       [P]     Stream with a GUID version
 *  VT_BLOB_OBJECT            [P]     Blob contains an object
 *  VT_CF                     [P]     Clipboard format
 *  VT_CLSID                  [P]     A Class ID
 *  VT_VECTOR                 [P]     simple counted array
 *  VT_ARRAY            [V]           SAFEARRAY*
 *  VT_BYREF            [V]           void* for local use
 *  VT_BSTR_BLOB                      Reserved for system use
 */



// —оответствие между типами 1—:ѕредпри€ти€ и COM:

//VT_EMPTY соответствует неопределенному значению. ѕри передаче в качестве параметра метода подставл€етс€ значение параметра по умолчанию;
//значени€ типа VT_I2, VT_I4, VT_BOOL, VT_ERROR, VT_UI1 соответствуют целочисленному значению и наход€тс€ в lVal;
//значени€ типа VT_R4, VT_R8, VT_CY соответствуют дробному значению и наход€тс€ в dblVal;
//значение типа VT_DATE соответствует значению даты и находитс€ в date;
//значение типа VT_BSTR соответствует строковому значению и находитс€ в bstrVal;
//значение типа VT_ARRAY соответствует массиву и находитс€ в parray (только дл€ "1—:ѕредпри€ти€ 8");
//значение типа VT_DISPATCH соответствует значению объекта и находитс€ в pdispVal.
//“ипы VT_DECIMAL, VT_VARIANT и VT_UNKNOWN не поддерживаютс€.

