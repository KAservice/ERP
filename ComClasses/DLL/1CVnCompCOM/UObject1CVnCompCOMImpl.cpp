
#pragma hdrstop

#include "guiddef.h"
#include "UObject1CVnCompCOMImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TObject1CVnCompCOMImpl::TObject1CVnCompCOMImpl()
{                                            
Object=new TObject1CVnCompCOM();
Object->FunctionDeleteImpl=DeleteImpl;
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TObject1CVnCompCOMImpl::~TObject1CVnCompCOMImpl()
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TObject1CVnCompCOMImpl::DeleteImpl(void)
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TObject1CVnCompCOMImpl::kanQueryInterface(REFIID id_interface, void ** ppv)
 {                                                                         
int result=0;                                                             
if (id_interface==IID_IkanUnknown)                                        
   {                                                                     
   *ppv=static_cast<IkanUnknown*> (this);                                 
   result=-1;                                                             
   }                                                                      
else if (id_interface==IID_IObject1CVnCompCOM)
   {                                                                     
   *ppv=static_cast<IObject1CVnCompCOM*> (this);
   result=-1;                                                            
   }                                                                     
else                                                                     
   {                                                                     
//   *ppv=NULL;
//   result=1;
	*ppv=static_cast<IObject1CVnCompCOM*> (this);
   result=-1;
   return result;                                                        
   }                                                                     
kanAddRef();                       
return result;                                                           
}                                                                       
//---------------------------------------------------------------
int TObject1CVnCompCOMImpl::kanAddRef(void)
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TObject1CVnCompCOMImpl::kanRelease(void)
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
wchar_t * TObject1CVnCompCOMImpl::get_ProgIdCOMObject(void)
{
return Object->ProgIdCOMObject;
}
//---------------------------------------------------------------
void TObject1CVnCompCOMImpl::set_ProgIdCOMObject(wchar_t * ProgIdCOMObject)
{
Object->ProgIdCOMObject=ProgIdCOMObject;
}
//---------------------------------------------------------------
bool TObject1CVnCompCOMImpl::InitVC()
{
return Object->InitVC();
}
//---------------------------------------------------------------
//---------------------------------------------------------------
void TObject1CVnCompCOMImpl::DoneVC()
{
return Object->DoneVC();
}
//---------------------------------------------------------------
  //     IInitDone : public IUnknown


//      ILanguageExtender : public IUnknown

bool TObject1CVnCompCOMImpl::RegisterExtensionAs(
			/* [out][in] */ wchar_t *bstrExtensionName)
{
return Object->RegisterExtensionAs(bstrExtensionName);
}
//---------------------------------------------------------------

bool TObject1CVnCompCOMImpl::GetNProps(
			/* [out][in] */ long *plProps)
{
return Object->GetNProps(plProps);
}
//---------------------------------------------------------------

bool TObject1CVnCompCOMImpl::FindProp(
			/* [in] */ wchar_t * bstrPropName,
			/* [out][in] */ long *plPropNum)
{
return Object->FindProp(bstrPropName,plPropNum);
}
//---------------------------------------------------------------

bool TObject1CVnCompCOMImpl::GetPropName(
			/* [in] */ long lPropNum,
			/* [in] */ long lPropAlias,
			/* [out][in] */ wchar_t *pbstrPropName)
{
return Object->GetPropName(lPropNum,lPropAlias,pbstrPropName);
}
//---------------------------------------------------------------

bool TObject1CVnCompCOMImpl::GetPropVal(
			/* [in] */ long lPropNum,
			/* [out][in] */ TkasVariant *pvarPropVal)
{
return Object->GetPropVal(lPropNum,pvarPropVal);
}
//---------------------------------------------------------------

bool TObject1CVnCompCOMImpl::SetPropVal(
			/* [in] */ long lPropNum,
			/* [in] */ TkasVariant *varPropVal)
{
return Object->SetPropVal(lPropNum,varPropVal);
}
//---------------------------------------------------------------

bool TObject1CVnCompCOMImpl::IsPropReadable(
			/* [in] */ long lPropNum,
			/* [out][in] */ bool *pboolPropRead)
{
return Object->IsPropReadable(lPropNum,pboolPropRead);
}
//---------------------------------------------------------------

bool TObject1CVnCompCOMImpl::IsPropWritable(
			/* [in] */ long lPropNum,
			/* [out][in] */ bool *pboolPropWrite)
{
return Object->IsPropWritable(lPropNum,pboolPropWrite);
}
//---------------------------------------------------------------

bool TObject1CVnCompCOMImpl::GetNMethods(
			/* [out][in] */ long *plMethods)
{
return Object->GetNMethods(plMethods);
}
//---------------------------------------------------------------

bool TObject1CVnCompCOMImpl::FindMethod(
			wchar_t * bstrMethodName,
			/* [out][in] */ long *plMethodNum)
{
return Object->FindMethod(bstrMethodName,plMethodNum);
}
//---------------------------------------------------------------

bool TObject1CVnCompCOMImpl::GetMethodName(
			/* [in] */ long lMethodNum,
			/* [in] */ long lMethodAlias,
			/* [out][in] */ wchar_t *pbstrMethodName)
{
return Object->GetMethodName(lMethodNum,lMethodAlias,pbstrMethodName);
}
//---------------------------------------------------------------

bool TObject1CVnCompCOMImpl::GetNParams(
			/* [in] */ long lMethodNum,
			/* [out][in] */ long *plParams)
{
return Object->GetNParams(lMethodNum,plParams);
}
//---------------------------------------------------------------

bool TObject1CVnCompCOMImpl::GetParamDefValue(
			/* [in] */ long lMethodNum,
			/* [in] */ long lParamNum,
			/* [out][in] */ TkasVariant *pvarParamDefValue)
{
return Object->GetParamDefValue(lMethodNum,lParamNum,pvarParamDefValue);
}
//---------------------------------------------------------------

bool TObject1CVnCompCOMImpl::HasRetVal(
			/* [in] */ long lMethodNum,
			/* [out][in] */ bool *pboolRetValue)
{
return Object->HasRetVal(lMethodNum,pboolRetValue);
}
//---------------------------------------------------------------

bool TObject1CVnCompCOMImpl::CallAsProc(
			/* [in] */ long lMethodNum,
			/* [out][in] */ TkasVariant *paParams, int lSizeArray)
{
return Object->CallAsProc(lMethodNum,paParams,lSizeArray);
}
//---------------------------------------------------------------

bool TObject1CVnCompCOMImpl::CallAsFunc(
			/* [in] */ long lMethodNum,
			/* [out][in] */ TkasVariant *pvarRetValue,
			/* [out][in] */ TkasVariant *paParams, int lSizeArray)
{
return Object->CallAsFunc(lMethodNum,pvarRetValue,paParams,lSizeArray);
}
//---------------------------------------------------------------






