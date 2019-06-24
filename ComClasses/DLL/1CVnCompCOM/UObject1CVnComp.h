//---------------------------------------------------------------------------

#ifndef UObject1CVnCompH
#define UObject1CVnCompH


#include "GlobalInterface.h"
#include <ComponentBase.h>
#include <Ukas1CSystem.h>
#include <UkasMemoryManager.h>
#include <UkasVariant.h>


class TObject1CVnComp
		{
private:


Tkas1CSystem * My1CSystem;
TkasMemoryManager *MyMemoryManager;
IComponentBase * VC;


HINSTANCE dllIn;

typedef WCHAR_T* (__import  DllGetClassNamesType(void));
DllGetClassNamesType * DllGetClassNames;

typedef long (__import  DllGetClassObjectType(const WCHAR_T * clsName, IComponentBase** pIntf));
DllGetClassObjectType *DllGetClassObject;

typedef long (__import  DllDestroyObjectType(IComponentBase** pIntf)) ;
DllDestroyObjectType * DllDestroyObject;

typedef AppCapabilities (__import  DllSetPlatformCapabilitiesType(const AppCapabilities capabilities)) ;
DllSetPlatformCapabilitiesType * DllSetPlatformCapabilities;


void Init_tVariant(tVariant * st, int type_value);


 public:
		TObject1CVnComp();
		~TObject1CVnComp();


		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //������� �������� ���������� ����������
		bool flDeleteImpl;   //���� �� ������� ���������� ��� �������� �������� ������

		bool Error;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //��������� ������ ����������
		GUID ClsIdImpl;				 //GUID ������ ����������



		int CodeError;
        WCHAR_T * TextError;
		bool InitVC();
		void DoneVC();

		char* NameDllVnComp;

		tVariant * ConvertKasVariantInTVariant(TkasVariant * kas_variant);
		TkasVariant * ConvertTVariantInKasVariant(tVariant * t_variant);


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
	bool Init(void* disp);
    /// Sets the memory manager
    /*
     * @param mem - pointer to memory manager interface.
     *  @return the result of
     */
	bool setMemManager(void* mem);

    /// Returns component version
    /**
     *  @return - component version (2000 - version 2)
	 */
	long GetInfo();

    /// Uninitializes component
    /**
     *  Component here should release all consumed resources.
     */
	void Done();


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
	bool RegisterExtensionAs(WCHAR_T** wsExtensionName);

    /// Returns number of component properties
    /**
     *  @return number of properties
     */
	long GetNProps();

    /// Finds property by name
    /**
     *  @param wsPropName - property name
     *  @return property index or -1, if it is not found
     */
	long FindProp(const WCHAR_T* wsPropName);

    /// Returns property name
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @param lPropAlias - 0 - international alias,
     *      1 - russian alias. (International alias is required)
     *  @return proeprty name or 0 if it is not found
     */
	const WCHAR_T* GetPropName(long lPropNum,
						 long lPropAlias);

    /// Returns property value
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @param pvarPropVal - the pointer to a variable for property value
     *  @return the result of
     */
	bool GetPropVal(const long lPropNum,
					  TkasVariant* pvarPropVal);

    /// Sets the property value
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @param varPropVal - the pointer to a variable for property value
     *  @return the result of
     */
	bool SetPropVal(const long lPropNum,
					  TkasVariant* varPropVal);

    /// Is property readable?
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @return true if property is readable
     */
	bool IsPropReadable(const long lPropNum);

    /// Is property writable?
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @return true if property is writable
     */
	bool IsPropWritable(const long lPropNum);

    /// Returns number of component methods
    /**
     *  @return number of component  methods
     */
	long GetNMethods();

    /// Finds a method by name
    /**
     *  @param wsMethodName - method name
     *  @return - method index
     */
	long FindMethod(const WCHAR_T* wsMethodName);

    /// Returns method name
    /**
     *  @param lMethodNum - method index(starting with 0)
     *  @param lMethodAlias - 0 - international alias,
     *      1 - russian alias. (International alias is required)
     *  @return method name or 0 if method is not found
     */
	const WCHAR_T* GetMethodName(const long lMethodNum,
						   const long lMethodAlias);

    /// Returns number of method parameters
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @return number of parameters
     */
	long GetNParams(const long lMethodNum);

    /// Returns default value of method parameter
    /**
     *  @param lMethodNum - method index(starting with 0)
     *  @param lParamNum - parameter index (starting with 0)
     *  @param pvarParamDefValue - the pointer to a variable for default value
     *  @return the result of
     */
	bool GetParamDefValue(const long lMethodNum,
					    const long lParamNum,
						TkasVariant *pvarParamDefValue);

    /// Does the method have a return value?
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @return true if the method has a return value
     */
	bool HasRetVal(const long lMethodNum);

    /// Calls the method as a procedure
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @param paParams - the pointer to array of method parameters
     *  @param lSizeArray - the size of array
     *  @return the result of
     */
	bool CallAsProc(const long lMethodNum,
					  TkasVariant* paParams,
					  const long lSizeArray);

    /// Calls the method as a function
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @param pvarRetValue - the pointer to returned value
     *  @param paParams - the pointer to array of method parameters
     *  @param lSizeArray - the size of array
     *  @return the result of
     */
	bool CallAsFunc(const long lMethodNum,
					  TkasVariant* pvarRetValue,
					  TkasVariant* paParams,
					  const long lSizeArray);

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
    void SetLocale(const WCHAR_T* loc);

//*********************-------------------------------------------------

//������������ ����� ������ 1�:����������� � COM:

//VTYPE_EMPTY ������������� ��������������� ��������. ��� �������� � �������� ��������� ������ ������������� �������� ��������� �� ���������;
//�������� ���� VTYPE_I2, VTYPE_I4, VTYPE_ERROR, VTYPE_UI1 ������������� �������������� �������� � ��������� � lVal;
//�������� ���� VTYPE_BOOL, ������������� �������� �������� � ��������� � bVal;
//�������� ���� VTYPE_R4, VTYPE_R8, VTYPE_CY ������������� �������� �������� � ��������� � dblVal;
//�������� ���� VTYPE_DATE ������������� �������� ���� � ��������� � date;
//�������� ���� VTYPE_TM ������������� �������� ���� � ��������� � struct tm tmVal;
//�������� ���� VTYPE_PSTR ������������� ���������� �������� (char*) � ��������� � pstrVal � ��������� ����� � strLen;
//�������� ���� VTYPE_PWSTR ������������� ���������� �������� (WCHAR_T*) � ��������� � pwstrVal � ��������� ����� � wstrLen;
//�������� ���� VTYPE_BLOB ������������� �������� ������ � ��������� � pstrVal � ��������� ����� � strLen;
//���� VTYPE_INTERFACE, VTYPE_VARIANT �� ��������������.

//����������:
//�������� ��������, ���������� � �������� ���������� �� ���-�������, ����� ��������� � ����� �������� �����.
//��� VTYPE_BLOB �� �������������� � ���-�������.


//���� �������� tVarant, ������ �����, �����


//	VTYPE_EMPTY    = 0,
//	VTYPE_NULL,     1
//	VTYPE_I2,       2            //int16_t
//    VTYPE_I4,     3              //int32_t
//    VTYPE_R4,     4              //float
//	VTYPE_R8,       5            //double
//	VTYPE_DATE,     6            //DATE (double)
//	VTYPE_TM,        7           //struct tm
//    VTYPE_PSTR,      8           //struct str    string
//    VTYPE_INTERFACE,   9         //struct iface
//	VTYPE_ERROR,         10       //int32_t errCode
//	VTYPE_BOOL,          11       //bool
//    VTYPE_VARIANT,     12         //struct _tVariant *
//    VTYPE_I1,        13           //int8_t
//	VTYPE_UI1,         14         //uint8_t
//	VTYPE_UI2,          15        //uint16_t
//	VTYPE_UI4,         16         //uint32_t
//	VTYPE_I8,          17         //int64_t
//	VTYPE_UI8,         18         //uint64_t
//	VTYPE_INT,         19         //int   Depends on architecture
//	VTYPE_UINT,        20         //unsigned int  Depends on architecture
//	VTYPE_HRESULT,     21         //long hRes
//    VTYPE_PWSTR,     22           //struct wstr
//	VTYPE_BLOB,        23         //means in struct str binary data contain
//	VTYPE_CLSID,       24         //UUID
//	VTYPE_STR_BLOB    = 0xfff,
//	VTYPE_VECTOR   = 0x1000,
//	VTYPE_ARRAY    = 0x2000,
//	VTYPE_BYREF    = 0x4000,    //Only with struct _tVariant *
//    VTYPE_RESERVED = 0x8000,
//	VTYPE_ILLEGAL  = 0xffff,
//	VTYPE_ILLEGALMASKED    = 0xfff,
//	VTYPE_TYPEMASK = 0xfff










































		};


//---------------------------------------------------------------------------
#endif
