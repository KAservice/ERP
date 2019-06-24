#include "vcl.h"
#pragma hdrstop


#include "UDMSprOborudParamImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprOborudParamImpl::TDMSprOborudParamImpl()           
{                                            
Object=new TDMSprOborudParam(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprOborudParamImpl::~TDMSprOborudParamImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprOborudParamImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprOborudParamImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
 {                                                                         
int result=0;                                                             
if (id_interface==IID_IkanUnknown)                                        
   {                                                                     
   *ppv=static_cast<IkanUnknown*> (this);                                 
   result=-1;                                                             
   }                                                                      
else if (id_interface==IID_IMainInterface)                        
   {                                                                     
   *ppv=static_cast<IMainInterface*> (this);                                
   result=-1;                                                            
   }  
else if (id_interface==IID_IkasDM)
   {
   *ppv=static_cast<IkasDM*> (this);
   result=-1;
   }
else if (id_interface==IID_IkasDMSpr)
   {
   *ppv=static_cast<IkasDMSpr*> (this);
   result=-1;
   }
else if (id_interface==IID_IkasDMDataSet)
   {
   *ppv=static_cast<IkasDMDataSet*> (this);
   result=-1;
   }
else                                                                     
   {                                                                     
   *ppv=NULL;                                                            
   result=1;                                                             
   return result;                                                        
   }                                                                     
kanAddRef();                       
return result;                                                           
}                                                                       
//---------------------------------------------------------------
int TDMSprOborudParamImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprOborudParamImpl::kanRelease(void)                                  
{                                                                      
if (--NumRefs==0)                                                     
   {                                                                  
   delete this;                                                       
   return 0;                                                       
   }                                                                  
return NumRefs;                                                       
}                                                                     
//---------------------------------------------------------------

//IMainInterface 
int  TDMSprOborudParamImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprOborudParamImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprOborudParamImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprOborudParamImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprOborudParamImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprOborudParamImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprOborudParamImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

       //IkasDM
	//параметры
bool TDMSprOborudParamImpl::SetParameterAsInt64 (__int64 value, UnicodeString name_parameter, int index_data_set)
{

return Object->SetParameterAsInt64 ( value,  name_parameter,  index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::SetParameterAsInt (int value, UnicodeString name_parameter, int index_data_set)
{

return Object->SetParameterAsInt ( value, name_parameter, index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::SetParameterAsFloat (double value, UnicodeString name_parameter, int index_data_set)
{
return Object->SetParameterAsFloat ( value,  name_parameter, index_data_set);

}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::SetParameterAsString (UnicodeString value, UnicodeString name_parameter, int index_data_set)
{

return Object->SetParameterAsString ( value,  name_parameter, index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::SetParameterAsDateTime (TDateTime value, UnicodeString name_parameter, int index_data_set)
{

return Object->SetParameterAsDateTime ( value,  name_parameter,  index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::SetParameterAsBool (bool value, UnicodeString name_parameter, int index_data_set)
{

return Object->SetParameterAsBool ( value,  name_parameter,  index_data_set);
}
//------------------------------------------------------------------------------------------


bool TDMSprOborudParamImpl::OpenDataSet(int index_data_set)
{

return Object->OpenDataSet(index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::CloseDataSet(int index_data_set)
{

return Object->CloseDataSet(index_data_set);
}
//------------------------------------------------------------------------------------------

	// значения полей
bool TDMSprOborudParamImpl::SetValueFieldAsInt (int value, UnicodeString name_field, int index_data_set)
{

return Object->SetValueFieldAsInt ( value,  name_field, index_data_set);
}
//------------------------------------------------------------------------------------------
int TDMSprOborudParamImpl::GetValueFieldAsInt (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsInt ( name_field, index_data_set);
}
//------------------------------------------------------------------------------------------

bool TDMSprOborudParamImpl::SetValueFieldAsInt64 (__int64 value, UnicodeString name_field, int index_data_set)
{

return Object->SetValueFieldAsInt64 (value, name_field, index_data_set);
}
//------------------------------------------------------------------------------------------
__int64 TDMSprOborudParamImpl::GetValueFieldAsInt64 (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsInt64 ( name_field, index_data_set);
}
//------------------------------------------------------------------------------------------

bool TDMSprOborudParamImpl::SetValueFieldAsFloat (double value, UnicodeString name_field, int index_data_set)
{

return Object->SetValueFieldAsFloat ( value,  name_field, index_data_set);
}
//------------------------------------------------------------------------------------------
double TDMSprOborudParamImpl::GetValueFieldAsFloat (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsFloat ( name_field,  index_data_set);
}
//------------------------------------------------------------------------------------------

bool TDMSprOborudParamImpl::SetValueFieldAsString (UnicodeString value, UnicodeString name_field, int index_data_set)
{

return Object->SetValueFieldAsString ( value,  name_field,  index_data_set);
}
//------------------------------------------------------------------------------------------
UnicodeString TDMSprOborudParamImpl::GetValueFieldAsString (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsString (name_field,  index_data_set);
}
//------------------------------------------------------------------------------------------

bool TDMSprOborudParamImpl::SetValueFieldAsDateTime (TDateTime value, UnicodeString name_field, int index_data_set)
{

return Object->SetValueFieldAsDateTime (value, name_field,  index_data_set);
}
//------------------------------------------------------------------------------------------
TDateTime TDMSprOborudParamImpl::GetValueFieldAsDateTime (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsDateTime ( name_field,  index_data_set);
}
//------------------------------------------------------------------------------------------

bool TDMSprOborudParamImpl::SetValueFieldAsBool (bool value, UnicodeString name_field, int index_data_set)
{

return Object->SetValueFieldAsBool ( value,  name_field,  index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::GetValueFieldAsBool (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsBool ( name_field, index_data_set);
}
//------------------------------------------------------------------------------------------


bool TDMSprOborudParamImpl::SaveValueFieldToStream(TStream *s,UnicodeString name_field, int index_data_set)
{

return Object->SaveValueFieldToStream(s, name_field, index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::SaveValueFieldToFile(UnicodeString file_name, UnicodeString name_field, int index_data_set)
{

return Object->SaveValueFieldToFile( file_name,  name_field, index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::LoadValueFieldFromStream(TStream *s,UnicodeString name_field, int index_data_set)
{

return Object->LoadValueFieldFromStream(s, name_field, index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::LoadValueFieldFromFile(UnicodeString file_name, UnicodeString name_field, int index_data_set)
{

return Object->LoadValueFieldFromFile(file_name,  name_field, index_data_set);
}
//------------------------------------------------------------------------------------------

	//навиация
int TDMSprOborudParamImpl::GetRecordCount(int index_data_set)
{

return Object->GetRecordCount(index_data_set);
}
//------------------------------------------------------------------------------------------
int TDMSprOborudParamImpl::GetIndexTecRecord(int index_data_set)
{

return Object->GetIndexTecRecord(index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::GetEof(int index_data_set)
{

return Object->GetEof(index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::First(int index_data_set)
{

return Object->First(index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::Next(int index_data_set)
{

return Object->Next(index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::Last(int index_data_set)
{

return Object->Last(index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::MoveBy(int kol_rec,int index_data_set)
{

return Object->MoveBy(kol_rec, index_data_set);
}
//------------------------------------------------------------------------------------------

	//сохранение удаление записей
bool TDMSprOborudParamImpl::Edit(int index_data_set)
{

return Object->Edit(index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::Post(int index_data_set)
{

return Object->Post(index_data_set);
}
//------------------------------------------------------------------------------------------


		 //IkasDMSpr


__int64 TDMSprOborudParamImpl::get_IdGroupEl1(void)
{

return Object->IdGroupEl1;
}
//------------------------------------------------------------------------------------------
void TDMSprOborudParamImpl::set_IdGroupEl1(__int64 IdGroupEl1)
{

Object->IdGroupEl1=IdGroupEl1;
}
//------------------------------------------------------------------------------------------
__int64 TDMSprOborudParamImpl::get_IdGroupEl2(void)
{

return Object->IdGroupEl2;
}
//------------------------------------------------------------------------------------------
void TDMSprOborudParamImpl::set_IdGroupEl2(__int64 IdGroupEl2)
{

Object->IdGroupEl2=IdGroupEl2;
}
//------------------------------------------------------------------------------------------
__int64 TDMSprOborudParamImpl::get_IdOwner(void)
{

return Object->IdOwner;
}
//------------------------------------------------------------------------------------------
void TDMSprOborudParamImpl::set_IdOwner(__int64 IdOwner)
{

Object->IdOwner=IdOwner;
}
//------------------------------------------------------------------------------------------
__int64 TDMSprOborudParamImpl::get_IdGrp(void)
{

return Object->IdGrp;
}
//------------------------------------------------------------------------------------------
void TDMSprOborudParamImpl::set_IdGrp(__int64 IdGrp)
{

Object->IdGrp=IdGrp;
}
//------------------------------------------------------------------------------------------
__int64 TDMSprOborudParamImpl::get_IdEl(void)
{

return Object->IdEl;
}
//------------------------------------------------------------------------------------------
void TDMSprOborudParamImpl::set_IdEl(__int64 IdEl)
{

Object->IdEl=IdEl;
}
//------------------------------------------------------------------------------------------

bool TDMSprOborudParamImpl::get_All(void)
{

return Object->All;
}
//------------------------------------------------------------------------------------------
void TDMSprOborudParamImpl::set_All(bool All)
{

Object->All=All;
}
//------------------------------------------------------------------------------------------


	//таблица
bool TDMSprOborudParamImpl::OpenTable(int type_search)  //0 без поиска, 1 по наименованию, 2 по реквизиту
{

return Object->OpenTable(type_search);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::CloseTable(void)
{

return Object->CloseTable();
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::DeleteString(void)
{

return Object->DeleteString();
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::AppendString(void)
{

return Object->AppendString();
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::SaveChanges(void)
{

return Object->SaveChanges();
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::CancelChanges(void)
{

return Object->CancelChanges();
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::SetStringParameterForSearch(UnicodeString name_parameter, UnicodeString value_parameter)
{

return Object->SetStringParameterForSearch(name_parameter,value_parameter);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::SetDateTimeParameterForSearch(UnicodeString name_parameter, TDateTime value_parameter)
{

return Object->SetDateTimeParameterForSearch(name_parameter, value_parameter);
}
//------------------------------------------------------------------------------------------

	//элемент
bool TDMSprOborudParamImpl::NewElement()
{

return Object->NewElement();
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::OpenElement(__int64 id)
{

return Object->OpenElement(id);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::DeleteElement(__int64 id)
{

return Object->DeleteElement(id);
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::SaveElement(void)
{

return Object->SaveElement();
}
//------------------------------------------------------------------------------------------
bool TDMSprOborudParamImpl::ChangeGrp(__int64 new_id_grp, __int64 id_el)
{

return Object->ChangeGrp(new_id_grp,id_el);
}
//------------------------------------------------------------------------------------------


	//интерфейс IkasDMDataSet

TDataSource * TDMSprOborudParamImpl::kanGetDataSource(int index_data_source)
{

return  Object->kanGetDataSource(index_data_source);

}
//----------------------------------------------------------------------------------
