
#pragma hdrstop

#include "guiddef.h"
#include "UObject1CVnCompImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TObject1CVnCompImpl::TObject1CVnCompImpl()           
{                                            
Object=new TObject1CVnComp();
Object->FunctionDeleteImpl=DeleteImpl;
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TObject1CVnCompImpl::~TObject1CVnCompImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TObject1CVnCompImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TObject1CVnCompImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
 {                                                                         
int result=0;                                                             
if (id_interface==IID_IkanUnknown)                                        
   {                                                                     
   *ppv=static_cast<IkanUnknown*> (this);                                 
   result=-1;                                                             
   }                                                                      
else if (id_interface==IID_IObject1CVnComp)
   {                                                                     
   *ppv=static_cast<IObject1CVnComp*> (this);                                
   result=-1;                                                            
   }                                                                     
else                                                                     
   {                                                                     
//   *ppv=NULL;
//   result=1;
	*ppv=static_cast<IObject1CVnComp*> (this);
   result=-1;
   return result;                                                        
   }                                                                     
kanAddRef();                       
return result;                                                           
}                                                                       
//---------------------------------------------------------------
int TObject1CVnCompImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TObject1CVnCompImpl::kanRelease(void)                                  
{                                                                      
if (--NumRefs==0)                                                     
   {                                                                  
   delete this;                                                       
   return 0;                                                       
   }                                                                  
return NumRefs;                                                       
}
//---------------------------------------------------------------


//IObject1CVnComp
char* TObject1CVnCompImpl::get_NameDllVnComp(void)
{
return Object->NameDllVnComp;
}
//---------------------------------------------------------------
void TObject1CVnCompImpl::set_NameDllVnComp(char* NameDllVnComp)
{
Object->NameDllVnComp=NameDllVnComp;
}
//---------------------------------------------------------------
bool TObject1CVnCompImpl::InitVC()
{
return Object->InitVC();
}
//---------------------------------------------------------------
//---------------------------------------------------------------
void TObject1CVnCompImpl::DoneVC()
{
return Object->DoneVC();
}
//---------------------------------------------------------------





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
bool  TObject1CVnCompImpl::Init(void* disp)
{


return Object->Init(disp);
}
//----------------------------------------------------------------------------
    /// Sets the memory manager
    /*
     * @param mem - pointer to memory manager interface.
     *  @return the result of
	 */
bool  TObject1CVnCompImpl::setMemManager(void* mem)
{


return Object->setMemManager(mem);
}
//----------------------------------------------------------------------------

    /// Returns component version
    /**
     *  @return - component version (2000 - version 2)
	 */
long TObject1CVnCompImpl::GetInfo()
{


return Object->GetInfo();
}
//----------------------------------------------------------------------------

    /// Uninitializes component
    /**
     *  Component here should release all consumed resources.
     */
void  TObject1CVnCompImpl::Done()
{


Object->Done();
}
//----------------------------------------------------------------------------


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
bool  TObject1CVnCompImpl::RegisterExtensionAs(WCHAR_T** wsExtensionName)
{


return Object->RegisterExtensionAs(wsExtensionName);
}
//----------------------------------------------------------------------------

    /// Returns number of component properties
	/**
     *  @return number of properties
     */
long  TObject1CVnCompImpl::GetNProps()
{


return Object->GetNProps();
}
//----------------------------------------------------------------------------

    /// Finds property by name
    /**
     *  @param wsPropName - property name
     *  @return property index or -1, if it is not found
     */
long  TObject1CVnCompImpl::FindProp(const WCHAR_T* wsPropName)
{


return Object->FindProp(wsPropName);
}
//----------------------------------------------------------------------------

    /// Returns property name
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @param lPropAlias - 0 - international alias,
     *      1 - russian alias. (International alias is required)
     *  @return proeprty name or 0 if it is not found
	 */
const WCHAR_T*  TObject1CVnCompImpl::GetPropName(long lPropNum,
						 long lPropAlias)
{

return Object->GetPropName(lPropNum,
						 lPropAlias);


}
//----------------------------------------------------------------------------

    /// Returns property value
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @param pvarPropVal - the pointer to a variable for property value
     *  @return the result of
     */
bool  TObject1CVnCompImpl::GetPropVal(const long lPropNum,
					  TkasVariant* pvarPropVal)
{

return Object->GetPropVal(lPropNum,
					  pvarPropVal);

}
//----------------------------------------------------------------------------

    /// Sets the property value
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @param varPropVal - the pointer to a variable for property value
     *  @return the result of
     */
bool  TObject1CVnCompImpl::SetPropVal(const long lPropNum,
					  TkasVariant* varPropVal)
{


return Object->SetPropVal(lPropNum,
					  varPropVal);
}
//----------------------------------------------------------------------------

    /// Is property readable?
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @return true if property is readable
	 */
bool  TObject1CVnCompImpl::IsPropReadable(const long lPropNum)
{

return Object->IsPropReadable(lPropNum);

}
//----------------------------------------------------------------------------

    /// Is property writable?
    /**
     *  @param lPropNum - property index (starting with 0)
     *  @return true if property is writable
	 */
bool  TObject1CVnCompImpl::IsPropWritable(const long lPropNum)
{

return Object->IsPropWritable(lPropNum);

}
//----------------------------------------------------------------------------

    /// Returns number of component methods
    /**
     *  @return number of component  methods
     */
long  TObject1CVnCompImpl::GetNMethods()
{

return Object->GetNMethods();

}
//----------------------------------------------------------------------------

    /// Finds a method by name
    /**
     *  @param wsMethodName - method name
     *  @return - method index
     */
long  TObject1CVnCompImpl::FindMethod(const WCHAR_T* wsMethodName)
{

return Object->FindMethod(wsMethodName);

}
//----------------------------------------------------------------------------

    /// Returns method name
    /**
     *  @param lMethodNum - method index(starting with 0)
     *  @param lMethodAlias - 0 - international alias,
     *      1 - russian alias. (International alias is required)
     *  @return method name or 0 if method is not found
     */
const WCHAR_T*  TObject1CVnCompImpl::GetMethodName(const long lMethodNum,
						   const long lMethodAlias)
{

return Object->GetMethodName(lMethodNum,
						   lMethodAlias);

}
//----------------------------------------------------------------------------

    /// Returns number of method parameters
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @return number of parameters
     */
long  TObject1CVnCompImpl::GetNParams(const long lMethodNum)
{

return Object->GetNParams(lMethodNum);

}
//----------------------------------------------------------------------------

    /// Returns default value of method parameter
    /**
     *  @param lMethodNum - method index(starting with 0)
     *  @param lParamNum - parameter index (starting with 0)
     *  @param pvarParamDefValue - the pointer to a variable for default value
     *  @return the result of
	 */
bool  TObject1CVnCompImpl::GetParamDefValue(const long lMethodNum,
						const long lParamNum,
						TkasVariant *pvarParamDefValue)
{

return Object->GetParamDefValue(lMethodNum,
						lParamNum,
						pvarParamDefValue);

}
//----------------------------------------------------------------------------

    /// Does the method have a return value?
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @return true if the method has a return value
     */
bool  TObject1CVnCompImpl::HasRetVal(const long lMethodNum)
{

return Object->HasRetVal(lMethodNum);

}
//----------------------------------------------------------------------------

    /// Calls the method as a procedure
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @param paParams - the pointer to array of method parameters
     *  @param lSizeArray - the size of array
     *  @return the result of
     */
bool  TObject1CVnCompImpl::CallAsProc(const long lMethodNum,
					  TkasVariant* paParams,
					  const long lSizeArray)
{
return Object->CallAsProc(lMethodNum,
					  paParams,
					   lSizeArray);

}
//----------------------------------------------------------------------------

    /// Calls the method as a function
    /**
     *  @param lMethodNum - method index (starting with 0)
     *  @param pvarRetValue - the pointer to returned value
     *  @param paParams - the pointer to array of method parameters
     *  @param lSizeArray - the size of array
     *  @return the result of
     */
bool  TObject1CVnCompImpl::CallAsFunc(const long lMethodNum,
					  TkasVariant* pvarRetValue,
					  TkasVariant* paParams,
					  const long lSizeArray)
{


return Object->CallAsFunc(lMethodNum,
					 pvarRetValue,
					  paParams,
					  lSizeArray);
}
//----------------------------------------------------------------------------

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
void  TObject1CVnCompImpl::SetLocale(const WCHAR_T* loc)
{


 return Object->SetLocale(loc);
}
//----------------------------------------------------------------------------




