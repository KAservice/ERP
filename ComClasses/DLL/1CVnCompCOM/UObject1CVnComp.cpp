//---------------------------------------------------------------------------


#pragma hdrstop

#include "UObject1CVnComp.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
TObject1CVnComp::TObject1CVnComp()
{
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
VC=0; //без этого не создается класс, видимо получается не нулевой указатель, а в библиотеке проверка

	My1CSystem = new Tkas1CSystem();
	MyMemoryManager = new TkasMemoryManager();
}
//-----------------------------------------------------------------------------
TObject1CVnComp::~TObject1CVnComp()
{
	delete My1CSystem;
	delete MyMemoryManager;
}
//---------------------------------------------------------------------------

bool TObject1CVnComp::InitVC()
{
bool result=false;
////TextError="";

try
	{
	dllIn=LoadLibrary(NameDllVnComp);
	if(dllIn)
		{
		DllGetClassNames=(DllGetClassNamesType*)GetProcAddress(dllIn,"GetClassNames");
		DllGetClassObject=(DllGetClassObjectType*)GetProcAddress(dllIn,"GetClassObject");
		DllDestroyObject=(DllDestroyObjectType*)GetProcAddress(dllIn,"DestroyObject");
		DllSetPlatformCapabilities=(DllSetPlatformCapabilitiesType*)GetProcAddress(dllIn,"SetPlatformCapabilities");
		result=true;
		}
	else
	   {
	   CodeError=1;
	   TextError=L"Не удалось загрузить компоненту DKViki_1C8.dll!";
	   return result;
	   }
   }
catch (...)
		{
		result=false;
		CodeError=1;
		TextError=L"Ошибка загрузки библиотеки или получения экспортируемых функций!";
		}



if (result==true && DllGetClassObject!=0)
	{
	long rep=0;
	rep=DllGetClassObject(L"AddIn.DemoVK.SomeName", &VC);

	if (rep!=0)
		{
		VC->Init(My1CSystem);
		VC->setMemManager(MyMemoryManager);
		result=true;
		CodeError=0;
		}
	else
		{
		result=false;
		CodeError=1;
		TextError=L"Ошибка создания объекта (класса) в компоненте!";
		}

	}
//WCHAR_T* name=DllGetClassNames();

//int res=DllSetPlatformCapabilities(eAppCapabilities1);


//
//
//
//
//
////int   kol_prop=0;
////kol_prop=VC->GetNProps();
////const WCHAR_T* name_param=L"";
////for(int i = 0; i < kol_prop; i++)
////	{
////	name_param=VC->GetPropName(i, 0);
////	}
////
//int   kol_met=0;
//kol_met=VC->GetNMethods();
//const WCHAR_T* name_metod=L"";
//
//for(int j = 0; j < kol_met; j++)
//	{
//	name_metod=VC->GetMethodName(j, 1);
//	}
//
////В возвращаемое значение помещается имя свойства с порядковым номером lPropNum;
////если свойство с таким номером отсутствует, возвращается NULL.
////Память для строки выделяется объектом компоненты функцией AllocMemory менеджера памяти.
////"1С:Предприятие" освобождает эту память вызовом FreeMemory.
//
//
////подключимся к кассе
//
////int num_metod=j;
//int num_metod=FindMethod(L"ПолучитьОписание");
//
////tVariant  par [9];         //если указатель, надо выделять память, а так не надо
//////par.t=new tVariant;
////
////par[0].vt=VTYPE_PSTR;
////par[0].pstrVal="COM3";
////par[0].strLen=4;
////
////par[1].vt=VTYPE_I4;
////par[1].intVal=57600;
//
//bool res=false;
//
//int kol_parameter_metoda=GetNParams(num_metod);    //количество параметров метода
//
//tVariant * variant_defaul_value_parameter_metoda=new tVariant;
//Init_tVariant(variant_defaul_value_parameter_metoda, 0);
//
//for(int i = 0; i < kol_parameter_metoda; i++)
//	{
//	bool defaul_value_parameter_metoda=GetParamDefValue(num_metod, 0, variant_defaul_value_parameter_metoda);
//	}
////В переменную pvarParamDefValue помещается значение по умолчанию параметра с номером lParamNum метода с порядковым номером lMethodNum.
////В pvarParamDefValue помещается тип VTYPE_EMPTY, если метод с таким номером отсутствует, не имеет параметра с номером или параметр не имеет значения по умолчанию.
////В случае, если значение по умолчанию имеет тип VTYPE_PSTR, VTYPE_PWSTR или VTYPE_BLOB, компонента выделяет память функцией AllocMemory менеджера памяти,
////записывает туда данные и сохраняет этот адрес в соответствующем поле структуры. "1С:Предприятие" освободит эту память вызовом FreeMemory.
//
//
//
//res=HasRetVal(num_metod);  ///Возвращается флаг наличия у метода с порядковым номером lMethodNum возвращаемого значения: true для методов с возвращаемым значением и false в противном случае.
//
//
//
//
//tVariant * variant_result=new tVariant;
//Init_tVariant(variant_result, 0);
//
//tVariant * in_parameter;
//in_parameter=new tVariant[kol_parameter_metoda];
//
//for(int i = 0; i < kol_parameter_metoda; i++)
//	{
//	Init_tVariant(&in_parameter[i], 0);
//	}
//
//
//
////variant_result.vt=VTYPE_EMPTY;
//
////tVariant   par1 [10];
////par1[1].vt=VTYPE_EMPTY;
////par1[2].vt=VTYPE_EMPTY;
////par1[3].vt=VTYPE_EMPTY;
////par1[4].vt=VTYPE_EMPTY;
////par1[5].vt=VTYPE_EMPTY;
//
//const WCHAR_T* name_metod1=GetMethodName(num_metod, 1) ;
//try
//		{
//			if (res=true)
//			{
//				res=VC->CallAsFunc(num_metod,
//								  variant_result,
//								  in_parameter,
//								  kol_parameter_metoda);
//			}
//			else
//				{
//				res=VC->CallAsProc(num_metod,
//								  in_parameter,
//								  kol_parameter_metoda);
//				}
//       }
//catch(...)
//		{
//
//		}

//res=GetPropVal(0, variant_result);
//
//Init_tVariant(variant_result, 0);
//res=GetPropVal(1, variant_result);
//	}

return result;
}
//---------------------------------------------------------------------------
void TObject1CVnComp::DoneVC()
{
if (DllDestroyObject!=0)
	{
    DllDestroyObject(&VC);
	}

FreeLibrary(dllIn);
}
 //*****************-----------------------------------------------------------
 ////////////////////////////////////////////////////////////////////////////////
/**
 *  The given interface is intended for initialization and
 *  uninitialization of component and its adjustments
 */
/// Interface of component initialization.
//class IInitDoneBase
//{
//public:
//	virtual ~IInitDoneBase() {}
//	/// Initializes component
//    /**
//     *  @param disp - 1C:Enterpise interface
//	 *  @return the result of
//	 */
bool TObject1CVnComp::Init(void* disp)
{


return VC->Init(disp);
}
//-------------------------------------------------------------------------------
    /// Sets the memory manager
    /*
     * @param mem - pointer to memory manager interface.
     *  @return the result of
     */
bool TObject1CVnComp::setMemManager(void* mem)
{


return VC->setMemManager(mem);
}
//-------------------------------------------------------------------------------

    /// Returns component version
    /**
     *  @return - component version (2000 - version 2)
     */
long TObject1CVnComp::GetInfo()
{

return VC->GetInfo();

}
//-------------------------------------------------------------------------------

    /// Uninitializes component
    /**
     *  Component here should release all consumed resources.
     */
void TObject1CVnComp::Done()
{

VC->Done();
}
//-------------------------------------------------------------------------------


///////////////////////////////////////////////////////////////////////////
/**
 *  The given interface defines methods that are intented to be used by the Platform
 */
/// Interface describing extension of language.
//class ILanguageExtenderBase
//{
//public:
//	virtual ~ILanguageExtenderBase(){}
    /// Registers language extension
    /**
     *  @param wsExtensionName - extension name
     *  @return the result of
	 */
bool TObject1CVnComp::RegisterExtensionAs(WCHAR_T** wsExtensionName)
{
return VC->RegisterExtensionAs(wsExtensionName);
}
//-------------------------------------------------------------------------------

    /// Returns number of component properties
    /**
     *  @return number of properties
     */
long TObject1CVnComp::GetNProps()
{
return VC->GetNProps();
}
//-------------------------------------------------------------------------------

    /// Finds property by name
    /**
     *  @param wsPropName - property name
     *  @return property index or -1, if it is not found
     */
long TObject1CVnComp::FindProp(const WCHAR_T* wsPropName)
{
return VC->FindProp(wsPropName);
}
//-------------------------------------------------------------------------------

    /// Returns property name
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @param lPropAlias - 0 - international alias,
     *      1 - russian alias. (International alias is required)
     *  @return proeprty name or 0 if it is not found
     */
const WCHAR_T* TObject1CVnComp::GetPropName(long lPropNum,
						 long lPropAlias)
{
return VC->GetPropName(lPropNum,
						 lPropAlias);

}
//-------------------------------------------------------------------------------

    /// Returns property value
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @param pvarPropVal - the pointer to a variable for property value
     *  @return the result of
     */
bool TObject1CVnComp::GetPropVal(const long lPropNum,
					  TkasVariant* pvarPropVal)
{

bool result=true;
tVariant * variant_result=new tVariant;
Init_tVariant(variant_result, 0);

VC->GetPropVal(lPropNum,
					  variant_result);

//надо заполнить tVariant и TkasVariant
*pvarPropVal=*ConvertTVariantInKasVariant(variant_result);

return result;
}
//-------------------------------------------------------------------------------

    /// Sets the property value
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @param varPropVal - the pointer to a variable for property value
     *  @return the result of
     */
bool TObject1CVnComp::SetPropVal(const long lPropNum,
					  TkasVariant* varPropVal)
{

tVariant * in_parameter=new tVariant;
Init_tVariant(in_parameter, 0);

//надо заполнить tVariant из TkasVariant

in_parameter = ConvertKasVariantInTVariant(varPropVal);

return VC->SetPropVal(lPropNum,
					  in_parameter);

}
//-------------------------------------------------------------------------------

    /// Is property readable?
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @return true if property is readable
     */
bool TObject1CVnComp::IsPropReadable(const long lPropNum)
{
return VC->IsPropReadable(lPropNum);

}
//-------------------------------------------------------------------------------

    /// Is property writable?
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @return true if property is writable
     */
bool TObject1CVnComp::IsPropWritable(const long lPropNum)
{
return VC->IsPropWritable(lPropNum);

}
//-------------------------------------------------------------------------------

    /// Returns number of component methods
    /**
     *  @return number of component  methods
     */
long TObject1CVnComp::GetNMethods()
{
return VC->GetNMethods();
}
//-------------------------------------------------------------------------------

    /// Finds a method by name
    /**
     *  @param wsMethodName - method name
     *  @return - method index
	 */
//	 Параметры:

//<wsMethodName> Тип: const WCHAR_T*. Имя метода
//Возвращаемое значение:

//long — порядковый номер метода
//Описание:

//Возвращается порядковый номер метода с именем wsMethodName; -1 — при отсутствии

long TObject1CVnComp::FindMethod(const WCHAR_T* wsMethodName)
{
return VC->FindMethod(wsMethodName);
}
//-------------------------------------------------------------------------------

    /// Returns method name
    /**
     *  @param lMethodNum - method index(starting with 0)
     *  @param lMethodAlias - 0 - international alias,
     *      1 - russian alias. (International alias is required)
     *  @return method name or 0 if method is not found
     */
const WCHAR_T* TObject1CVnComp::GetMethodName(const long lMethodNum,
						   const long lMethodAlias)
{
return VC->GetMethodName(lMethodNum,
						   lMethodAlias);

//0 — английское наименование;
//1 — локальное наименование.

}
//-------------------------------------------------------------------------------

    /// Returns number of method parameters
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @return number of parameters
     */
long TObject1CVnComp::GetNParams(const long lMethodNum)
{
return VC->GetNParams(lMethodNum);

}
//-------------------------------------------------------------------------------

    /// Returns default value of method parameter
    /**
     *  @param lMethodNum - method index(starting with 0)
     *  @param lParamNum - parameter index (starting with 0)
     *  @param pvarParamDefValue - the pointer to a variable for default value
     *  @return the result of
     */
bool TObject1CVnComp::GetParamDefValue(const long lMethodNum,
						const long lParamNum,
						TkasVariant *pvarParamDefValue)
{
bool result=true;
tVariant * variant_result=new tVariant;
Init_tVariant(variant_result, 0);

VC->GetParamDefValue(lMethodNum,
						lParamNum,
						variant_result);

//надо заполнить tVariant и TkasVariant
pvarParamDefValue=ConvertTVariantInKasVariant(variant_result);

return result;
}
//-------------------------------------------------------------------------------

    /// Does the method have a return value?
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @return true if the method has a return value
     */
bool TObject1CVnComp::HasRetVal(const long lMethodNum)
{
return VC->HasRetVal(lMethodNum);

}
//-------------------------------------------------------------------------------

    /// Calls the method as a procedure
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @param paParams - the pointer to array of method parameters
     *  @param lSizeArray - the size of array
     *  @return the result of
	 */
//	 Возвращаемое значение:

//true – соответствующий метод вызван, ошибок не произошло.
//false – отсутствует метод или произошла ошибка времени исполнения (runtime error).
bool TObject1CVnComp::CallAsProc(const long lMethodNum,
					  TkasVariant* paParams,
					  const long lSizeArray)
{
bool result=false;

tVariant * variant_result=new tVariant;
Init_tVariant(variant_result, 0);

tVariant * in_parameter;
in_parameter=new tVariant[lSizeArray];

for(int i = 0; i < lSizeArray; i++)
	{
	Init_tVariant(&in_parameter[i], 0);
	}


for(int i = 0; i < lSizeArray; i++)
	{
	Init_tVariant(&in_parameter[i], 0);
	in_parameter[i] = *ConvertKasVariantInTVariant(&paParams[i]);
	}


result=VC->CallAsProc(lMethodNum,
					  in_parameter,
					  lSizeArray);



for(int i = 0; i < lSizeArray; i++)
	{
	paParams[i] = *ConvertTVariantInKasVariant(&in_parameter[i]);
	}

return result;


}
//-------------------------------------------------------------------------------

    /// Calls the method as a function
    /**
     *  @param lMethodNum - method index (starting with 0)
	 *  @param pvarRetValue - the pointer to returned value
     *  @param paParams - the pointer to array of method parameters
     *  @param lSizeArray - the size of array
     *  @return the result of
     */
bool TObject1CVnComp::CallAsFunc(const long lMethodNum,
					  TkasVariant* pvarRetValue,
					  TkasVariant* paParams,
					  const long lSizeArray)
{
bool result=true;
tVariant * variant_result=new tVariant;
Init_tVariant(variant_result, 0);

tVariant * in_parameter;
in_parameter=new tVariant[lSizeArray];

for(int i = 0; i < lSizeArray; i++)
	{
	Init_tVariant(&in_parameter[i], 0);
	in_parameter[i] = *ConvertKasVariantInTVariant(&paParams[i]);
	}


result=VC->CallAsFunc(lMethodNum,
					  variant_result,
					  in_parameter,
					  lSizeArray);

*pvarRetValue=*ConvertTVariantInKasVariant(variant_result);

for(int i = 0; i < lSizeArray; i++)
	{
	paParams[i] = *ConvertTVariantInKasVariant(&in_parameter[i]);
	}

return result;
}
//-------------------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////////
/**
 *  This interface is used to change component locale
 */
/// Base interface for component localization.
//class LocaleBase
//{
//public:
//	virtual ~LocaleBase(){}
    /// Changes component locale
    /**
     *  @param loc - new locale (for Windows - rus_RUS,
     *      for Linux - ru_RU, etc...)
	 */
void TObject1CVnComp::SetLocale(const WCHAR_T* loc)
{

VC->SetLocale(loc);
}
//-------------------------------------------------------------------------------
void TObject1CVnComp::Init_tVariant(tVariant * st, int type_value)
{

st->i8Val=0;
st->shortVal=0;
st->lVal=0;
st->intVal=0;
st->uintVal=0;
st->llVal=0;
st->ui8Val=0;
st->ushortVal=0;
st->ulVal=0;
st->ullVal=0;
st->errCode=0;
st->hRes=0;
st->fltVal=0;
st->dblVal=0;
st->bVal=false;
st->chVal=0;
st->wchVal=0;
st->date=0;
//st->IDVal=0;
st->pvarVal=0;
//st->tmVal=0;

st->pInterfaceVal=0;
//st->InterfaceID=0;

st->pstrVal=0;
st->strLen=0; //count of bytes

st->pwstrVal=0;
st->wstrLen=0; //count of symbol

st->cbElements=0;
st->vt=VTYPE_EMPTY;
}
//--------------------------------------------------------------------------
tVariant * TObject1CVnComp::ConvertKasVariantInTVariant(TkasVariant * kas_variant)
{
tVariant * variant_result=new tVariant;
Init_tVariant(variant_result, 0);
// 0 не задан 1 int, 2 строка, 3 double, 4 дата, 5 время, 6 датаВремя
if (kas_variant->type==0)
	{

	}


if (kas_variant->type==1)    //int
	{
	TV_VT(variant_result) = VTYPE_I4;
	variant_result->lVal=kas_variant->int_value;

//	variant_result->i8Val=0;
//	variant_result->shortVal=0;
//	variant_result->lVal=0;
//	variant_result->intVal=0;
//	variant_result->uintVal=0;
//	variant_result->llVal=0;
//	variant_result->ui8Val=0;
//	variant_result->ushortVal=0;
//	variant_result->ulVal=0;
//	variant_result->ullVal=0;
//	variant_result->errCode=0;
//	variant_result->hRes=0;
//	variant_result->fltVal=0;
//	variant_result->dblVal=0;
//	variant_result->bVal=false;
//	variant_result->chVal=0;
//	variant_result->wchVal=0;
//	variant_result->date=0;
//	//st->IDVal=0;
//	variant_result->pvarVal=0;
//	//st->tmVal=0;
//
//	variant_result->pInterfaceVal=0;
//	//st->InterfaceID=0;
//
//	variant_result->pstrVal=0;
//	variant_result->strLen=0; //count of bytes
//
//	variant_result->pwstrVal=0;
//	variant_result->wstrLen=0; //count of symbol
//
//	variant_result->cbElements=0;
//	variant_result->vt=VTYPE_EMPTY;
	}

if (kas_variant->type==2)    //строка
	{
	TV_VT(variant_result) = VTYPE_PWSTR;
	variant_result->pwstrVal=kas_variant->string_value;
	variant_result->wstrLen=kas_variant->len_string; //count of symbol
	}

if (kas_variant->type==3)    //double
	{
	TV_VT(variant_result) = VTYPE_R8;
	variant_result->dblVal=kas_variant->dbl_value;
	}

if (kas_variant->type==4)    //bool
	{
	TV_VT(variant_result) = VTYPE_BOOL;
	variant_result->bVal=kas_variant->bool_value;
	}

return  variant_result;
}
//--------------------------------------------------------------------------
TkasVariant * TObject1CVnComp::ConvertTVariantInKasVariant(tVariant * t_variant)
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

// 0 не задан 1 int, 2 строка, 3 double, 4 дата, 5 время, 6 датаВремя


if (t_variant->vt==VTYPE_I4)    //int
	{
	result->type=1;
	result->int_value=t_variant->lVal;
	}

if (t_variant->vt==VTYPE_PWSTR)    //строка
	{
	result->type=2;
	result->string_value=t_variant->pwstrVal;
	}

if (t_variant->vt==VTYPE_R8)    //double
	{
	result->type=3;
	result->dbl_value=t_variant->dblVal;
	}

if (t_variant->vt==VTYPE_BOOL)    //double
	{
	result->type=4;
	result->bool_value=t_variant->bVal;
	}


return  result;

}
//--------------------------------------------------------------------------
