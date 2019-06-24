#ifndef UObject1CVnCompImplH
#define UObject1CVnCompImplH
#include "IObject1CVnComp.h"
#include "UObject1CVnComp.h"

//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TObject1CVnCompImpl)) TObject1CVnCompImpl : public IObject1CVnComp
{
public:
   TObject1CVnCompImpl();
   ~TObject1CVnCompImpl();
   TObject1CVnComp * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
   virtual int kanAddRef(void);
   virtual int kanRelease(void);


//IObject1CVnComp
   virtual char* get_NameDllVnComp(void);
   virtual void set_NameDllVnComp(char* NameDllVnComp);

   virtual bool InitVC();
   virtual void DoneVC();



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
	virtual bool Init(void* disp);
    /// Sets the memory manager
    /*
     * @param mem - pointer to memory manager interface.
     *  @return the result of
	 */
	virtual bool setMemManager(void* mem);

    /// Returns component version
    /**
     *  @return - component version (2000 - version 2)
	 */
	virtual long  GetInfo();

    /// Uninitializes component
    /**
     *  Component here should release all consumed resources.
     */
	virtual void  Done();


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
	virtual bool  RegisterExtensionAs(WCHAR_T** wsExtensionName);

    /// Returns number of component properties
	/**
     *  @return number of properties
     */
	virtual long  GetNProps();

    /// Finds property by name
    /**
     *  @param wsPropName - property name
     *  @return property index or -1, if it is not found
     */
	virtual long  FindProp(const WCHAR_T* wsPropName);

    /// Returns property name
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @param lPropAlias - 0 - international alias,
     *      1 - russian alias. (International alias is required)
     *  @return proeprty name or 0 if it is not found
	 */
	virtual const WCHAR_T*  GetPropName(long lPropNum,
						 long lPropAlias);

    /// Returns property value
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @param pvarPropVal - the pointer to a variable for property value
     *  @return the result of
     */
	virtual bool  GetPropVal(const long lPropNum,
					  TkasVariant* pvarPropVal);

    /// Sets the property value
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @param varPropVal - the pointer to a variable for property value
     *  @return the result of
     */
	virtual bool  SetPropVal(const long lPropNum,
					  TkasVariant* varPropVal);

    /// Is property readable?
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @return true if property is readable
	 */
	virtual bool  IsPropReadable(const long lPropNum);

    /// Is property writable?
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @return true if property is writable
     */
	virtual bool  IsPropWritable(const long lPropNum);

    /// Returns number of component methods
    /**
     *  @return number of component  methods
     */
	virtual long  GetNMethods();

    /// Finds a method by name
    /**
     *  @param wsMethodName - method name
     *  @return - method index
     */
	virtual long  FindMethod(const WCHAR_T* wsMethodName);

    /// Returns method name
    /**
     *  @param lMethodNum - method index(starting with 0)
     *  @param lMethodAlias - 0 - international alias,
     *      1 - russian alias. (International alias is required)
     *  @return method name or 0 if method is not found
     */
	virtual const WCHAR_T*  GetMethodName(const long lMethodNum,
						   const long lMethodAlias);

    /// Returns number of method parameters
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @return number of parameters
     */
	virtual long GetNParams(const long lMethodNum);

    /// Returns default value of method parameter
    /**
     *  @param lMethodNum - method index(starting with 0)
     *  @param lParamNum - parameter index (starting with 0)
     *  @param pvarParamDefValue - the pointer to a variable for default value
     *  @return the result of
	 */
	virtual bool  GetParamDefValue(const long lMethodNum,
					    const long lParamNum,
						TkasVariant *pvarParamDefValue);

    /// Does the method have a return value?
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @return true if the method has a return value
     */
	virtual bool  HasRetVal(const long lMethodNum);

    /// Calls the method as a procedure
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @param paParams - the pointer to array of method parameters
     *  @param lSizeArray - the size of array
     *  @return the result of
	 */
	virtual bool  CallAsProc(const long lMethodNum,
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
	virtual bool  CallAsFunc(const long lMethodNum,
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
	virtual void  SetLocale(const WCHAR_T* loc);








};
#define CLSID_TObject1CVnCompImpl __uuidof(TObject1CVnCompImpl)
#endif
