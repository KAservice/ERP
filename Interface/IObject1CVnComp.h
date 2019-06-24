#ifndef UIObject1CVnCompH
#define UIObject1CVnCompH


#define ProgId_Object1CVnComp  "Kas.Object1CVnComp.1"
#define Global_CLSID_TObject1CVnCompImpl "{21F51513-B523-4712-8080-2E6DA5D62244}"
#define Global_IID_IObject1CVnComp  "{E686246F-3BB5-4AD3-961E-3B9B3D5C5D0E}"


#include <GlobalInterface.h>
#include <UkasVariant.h>

class __declspec(uuid(Global_IID_IObject1CVnComp)) IObject1CVnComp : public IkanUnknown
{
public:
   __property char* NameDllVnComp = {read = get_NameDllVnComp , write = set_NameDllVnComp};
   virtual char* get_NameDllVnComp(void)=0;
   virtual void set_NameDllVnComp(char* NameDllVnComp)=0;

   virtual bool InitVC()=0;
   virtual void DoneVC()=0;



 //*****************-----------------------------------------------------------
 ////////////////////////////////////////////////////////////////////////////////
/**
 *  The given interface is intended for initialization and
 *  uninitialization of component and its adjustments
 */
/// Interface of component initialization.
//class IInitDoneBase

//public:
//	virtual ~IInitDoneBase() {}
//	/// Initializes component
//    /**
//     *  @param disp - 1C:Enterpise interface
//	 *  @return the result of
//	 */
	virtual bool   Init(void* disp) = 0;
    /// Sets the memory manager
    /*
     * @param mem - pointer to memory manager interface.
     *  @return the result of
	 */
	virtual bool  setMemManager(void* mem) = 0;

    /// Returns component version
    /**
     *  @return - component version (2000 - version 2)
     */
	virtual long  GetInfo() = 0;

    /// Uninitializes component
    /**
     *  Component here should release all consumed resources.
     */
	virtual void  Done() = 0;


///////////////////////////////////////////////////////////////////////////
/**
 *  The given interface defines methods that are intented to be used by the Platform
 */
/// Interface describing extension of language.
//class ILanguageExtenderBase

//public:
//	virtual ~ILanguageExtenderBase(){}
    /// Registers language extension
    /**
     *  @param wsExtensionName - extension name
     *  @return the result of
     */
	virtual  bool  RegisterExtensionAs(wchar_t** wsExtensionName) = 0;

	/// Returns number of component properties
    /**
     *  @return number of properties
     */
	virtual  long  GetNProps() = 0;

    /// Finds property by name
    /**
     *  @param wsPropName - property name
     *  @return property index or -1, if it is not found
     */
	virtual  long  FindProp(const wchar_t* wsPropName) = 0;

    /// Returns property name
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @param lPropAlias - 0 - international alias,
     *      1 - russian alias. (International alias is required)
     *  @return proeprty name or 0 if it is not found
     */
	virtual const wchar_t*  GetPropName(long lPropNum,
						 long lPropAlias) = 0;

    /// Returns property value
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @param pvarPropVal - the pointer to a variable for property value
     *  @return the result of
     */
	virtual  bool  GetPropVal(const long lPropNum,
							 TkasVariant* pvarPropVal) = 0;

	/// Sets the property value
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @param varPropVal - the pointer to a variable for property value
     *  @return the result of
     */
	virtual bool  SetPropVal(const long lPropNum,
					  TkasVariant* varPropVal) = 0;

    /// Is property readable?
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @return true if property is readable
     */
	virtual  bool  IsPropReadable(const long lPropNum) = 0;

    /// Is property writable?
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @return true if property is writable
     */
	virtual  bool  IsPropWritable(const long lPropNum) = 0;

    /// Returns number of component methods
    /**
     *  @return number of component  methods
     */
	virtual  long GetNMethods() = 0;

    /// Finds a method by name
    /**
     *  @param wsMethodName - method name
     *  @return - method index
     */
	virtual  long  FindMethod(const wchar_t* wsMethodName) = 0;

    /// Returns method name
    /**
     *  @param lMethodNum - method index(starting with 0)
     *  @param lMethodAlias - 0 - international alias,
     *      1 - russian alias. (International alias is required)
     *  @return method name or 0 if method is not found
	 */
	virtual  const wchar_t*  GetMethodName(const long lMethodNum,
						   const long lMethodAlias) = 0;

    /// Returns number of method parameters
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @return number of parameters
     */
	virtual long  GetNParams(const long lMethodNum) = 0;

    /// Returns default value of method parameter
    /**
     *  @param lMethodNum - method index(starting with 0)
     *  @param lParamNum - parameter index (starting with 0)
     *  @param pvarParamDefValue - the pointer to a variable for default value
     *  @return the result of
     */
	virtual  bool  GetParamDefValue(const long lMethodNum,
					    const long lParamNum,
						TkasVariant *pvarParamDefValue) = 0;

    /// Does the method have a return value?
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @return true if the method has a return value
     */
	virtual  bool  HasRetVal(const long lMethodNum) = 0;

    /// Calls the method as a procedure
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @param paParams - the pointer to array of method parameters
     *  @param lSizeArray - the size of array
     *  @return the result of
	 */
	virtual  bool CallAsProc(const long lMethodNum,
					  TkasVariant* paParams,
				      const long lSizeArray) = 0;

    /// Calls the method as a function
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @param pvarRetValue - the pointer to returned value
     *  @param paParams - the pointer to array of method parameters
     *  @param lSizeArray - the size of array
     *  @return the result of
     */
	virtual bool CallAsFunc(const long lMethodNum,
					  TkasVariant* pvarRetValue,
					  TkasVariant* paParams,
				      const long lSizeArray) = 0;

///////////////////////////////////////////////////////////////////////////
/**
 *  This interface is used to change component locale
 */
/// Base interface for component localization.
//class LocaleBase

//public:
//	virtual ~LocaleBase(){}
    /// Changes component locale
    /**
     *  @param loc - new locale (for Windows - rus_RUS,
     *      for Linux - ru_RU, etc...)
     */
	virtual  void SetLocale(const wchar_t* loc) = 0;



};
#define IID_IObject1CVnComp __uuidof(IObject1CVnComp)
#endif
