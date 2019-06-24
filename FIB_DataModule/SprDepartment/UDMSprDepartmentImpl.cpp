#include "vcl.h"
#pragma hdrstop


#include "UDMSprDepartmentImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprDepartmentImpl::TDMSprDepartmentImpl()
{                                            
Object=new TDMSprDepartment(Application);
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprDepartmentImpl::~TDMSprDepartmentImpl()
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprDepartmentImpl::DeleteImpl(void)
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprDepartmentImpl::kanQueryInterface(REFIID id_interface, void ** ppv)
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
int TDMSprDepartmentImpl::kanAddRef(void)
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprDepartmentImpl::kanRelease(void)
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
int  TDMSprDepartmentImpl::get_CodeError(void)
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprDepartmentImpl::set_CodeError(int CodeError)
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprDepartmentImpl::get_TextError(void)
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprDepartmentImpl::set_TextError(UnicodeString  TextError)
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprDepartmentImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprDepartmentImpl;
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprDepartmentImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

       //IkasDM
	//параметры
bool TDMSprDepartmentImpl::SetParameterAsInt64 (__int64 value, UnicodeString name_parameter, int index_data_set)
{

return Object->SetParameterAsInt64 ( value,  name_parameter,  index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::SetParameterAsInt (int value, UnicodeString name_parameter, int index_data_set)
{

return Object->SetParameterAsInt ( value, name_parameter, index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::SetParameterAsFloat (double value, UnicodeString name_parameter, int index_data_set)
{
return Object->SetParameterAsFloat ( value,  name_parameter, index_data_set);

}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::SetParameterAsString (UnicodeString value, UnicodeString name_parameter, int index_data_set)
{

return Object->SetParameterAsString ( value,  name_parameter, index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::SetParameterAsDateTime (TDateTime value, UnicodeString name_parameter, int index_data_set)
{

return Object->SetParameterAsDateTime ( value,  name_parameter,  index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::SetParameterAsBool (bool value, UnicodeString name_parameter, int index_data_set)
{

return Object->SetParameterAsBool ( value,  name_parameter,  index_data_set);
}
//------------------------------------------------------------------------------------------


bool TDMSprDepartmentImpl::OpenDataSet(int index_data_set)
{

return Object->OpenDataSet(index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::CloseDataSet(int index_data_set)
{

return Object->CloseDataSet(index_data_set);
}
//------------------------------------------------------------------------------------------

	// значения полей
bool TDMSprDepartmentImpl::SetValueFieldAsInt (int value, UnicodeString name_field, int index_data_set)
{

return Object->SetValueFieldAsInt ( value,  name_field, index_data_set);
}
//------------------------------------------------------------------------------------------
int TDMSprDepartmentImpl::GetValueFieldAsInt (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsInt ( name_field, index_data_set);
}
//------------------------------------------------------------------------------------------

bool TDMSprDepartmentImpl::SetValueFieldAsInt64 (__int64 value, UnicodeString name_field, int index_data_set)
{

return Object->SetValueFieldAsInt64 (value, name_field, index_data_set);
}
//------------------------------------------------------------------------------------------
__int64 TDMSprDepartmentImpl::GetValueFieldAsInt64 (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsInt64 ( name_field, index_data_set);
}
//------------------------------------------------------------------------------------------

bool TDMSprDepartmentImpl::SetValueFieldAsFloat (double value, UnicodeString name_field, int index_data_set)
{

return Object->SetValueFieldAsFloat ( value,  name_field, index_data_set);
}
//------------------------------------------------------------------------------------------
double TDMSprDepartmentImpl::GetValueFieldAsFloat (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsFloat ( name_field,  index_data_set);
}
//------------------------------------------------------------------------------------------

bool TDMSprDepartmentImpl::SetValueFieldAsString (UnicodeString value, UnicodeString name_field, int index_data_set)
{

return Object->SetValueFieldAsString ( value,  name_field,  index_data_set);
}
//------------------------------------------------------------------------------------------
UnicodeString TDMSprDepartmentImpl::GetValueFieldAsString (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsString (name_field,  index_data_set);
}
//------------------------------------------------------------------------------------------

bool TDMSprDepartmentImpl::SetValueFieldAsDateTime (TDateTime value, UnicodeString name_field, int index_data_set)
{

return Object->SetValueFieldAsDateTime (value, name_field,  index_data_set);
}
//------------------------------------------------------------------------------------------
TDateTime TDMSprDepartmentImpl::GetValueFieldAsDateTime (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsDateTime ( name_field,  index_data_set);
}
//------------------------------------------------------------------------------------------

bool TDMSprDepartmentImpl::SetValueFieldAsBool (bool value, UnicodeString name_field, int index_data_set)
{

return Object->SetValueFieldAsBool ( value,  name_field,  index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::GetValueFieldAsBool (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsBool ( name_field, index_data_set);
}
//------------------------------------------------------------------------------------------


bool TDMSprDepartmentImpl::SaveValueFieldToStream(TStream *s,UnicodeString name_field, int index_data_set)
{

return Object->SaveValueFieldToStream(s, name_field, index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::SaveValueFieldToFile(UnicodeString file_name, UnicodeString name_field, int index_data_set)
{

return Object->SaveValueFieldToFile( file_name,  name_field, index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::LoadValueFieldFromStream(TStream *s,UnicodeString name_field, int index_data_set)
{

return Object->LoadValueFieldFromStream(s, name_field, index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::LoadValueFieldFromFile(UnicodeString file_name, UnicodeString name_field, int index_data_set)
{

return Object->LoadValueFieldFromFile(file_name,  name_field, index_data_set);
}
//------------------------------------------------------------------------------------------

	//навиация
int TDMSprDepartmentImpl::GetRecordCount(int index_data_set)
{

return Object->GetRecordCount(index_data_set);
}
//------------------------------------------------------------------------------------------
int TDMSprDepartmentImpl::GetIndexTecRecord(int index_data_set)
{

return Object->GetIndexTecRecord(index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::GetEof(int index_data_set)
{

return Object->GetEof(index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::First(int index_data_set)
{

return Object->First(index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::Next(int index_data_set)
{

return Object->Next(index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::Last(int index_data_set)
{

return Object->Last(index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::MoveBy(int kol_rec,int index_data_set)
{

return Object->MoveBy(kol_rec, index_data_set);
}
//------------------------------------------------------------------------------------------

	//сохранение удаление записей
bool TDMSprDepartmentImpl::Edit(int index_data_set)
{

return Object->Edit(index_data_set);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::Post(int index_data_set)
{

return Object->Post(index_data_set);
}
//------------------------------------------------------------------------------------------


		 //IkasDMSpr


__int64 TDMSprDepartmentImpl::get_IdGroupEl1(void)
{

return Object->IdGroupEl1;
}
//------------------------------------------------------------------------------------------
void TDMSprDepartmentImpl::set_IdGroupEl1(__int64 IdGroupEl1)
{

Object->IdGroupEl1=IdGroupEl1;
}
//------------------------------------------------------------------------------------------
__int64 TDMSprDepartmentImpl::get_IdGroupEl2(void)
{

return Object->IdGroupEl2;
}
//------------------------------------------------------------------------------------------
void TDMSprDepartmentImpl::set_IdGroupEl2(__int64 IdGroupEl2)
{

Object->IdGroupEl2=IdGroupEl2;
}
//------------------------------------------------------------------------------------------
__int64 TDMSprDepartmentImpl::get_IdOwner(void)
{

return Object->IdOwner;
}
//------------------------------------------------------------------------------------------
void TDMSprDepartmentImpl::set_IdOwner(__int64 IdOwner)
{

Object->IdOwner=IdOwner;
}
//------------------------------------------------------------------------------------------
__int64 TDMSprDepartmentImpl::get_IdGrp(void)
{

return Object->IdGrp;
}
//------------------------------------------------------------------------------------------
void TDMSprDepartmentImpl::set_IdGrp(__int64 IdGrp)
{

Object->IdGrp=IdGrp;
}
//------------------------------------------------------------------------------------------
__int64 TDMSprDepartmentImpl::get_IdEl(void)
{

return Object->IdEl;
}
//------------------------------------------------------------------------------------------
void TDMSprDepartmentImpl::set_IdEl(__int64 IdEl)
{

Object->IdEl=IdEl;
}
//------------------------------------------------------------------------------------------

bool TDMSprDepartmentImpl::get_All(void)
{

return Object->All;
}
//------------------------------------------------------------------------------------------
void TDMSprDepartmentImpl::set_All(bool All)
{

Object->All=All;
}
//------------------------------------------------------------------------------------------


	//таблица
bool TDMSprDepartmentImpl::OpenTable(int type_search)  //0 без поиска, 1 по наименованию, 2 по реквизиту
{

return Object->OpenTable(type_search);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::CloseTable(void)
{

return Object->CloseTable();
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::DeleteString(void)
{

return Object->DeleteString();
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::AppendString(void)
{

return Object->AppendString();
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::SaveChanges(void)
{

return Object->SaveChanges();
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::CancelChanges(void)
{

return Object->CancelChanges();
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::SetStringParameterForSearch(UnicodeString name_parameter, UnicodeString value_parameter)
{

return Object->SetStringParameterForSearch(name_parameter,value_parameter);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::SetDateTimeParameterForSearch(UnicodeString name_parameter, TDateTime value_parameter)
{

return Object->SetDateTimeParameterForSearch(name_parameter, value_parameter);
}
//------------------------------------------------------------------------------------------

	//элемент
bool TDMSprDepartmentImpl::NewElement()
{

return Object->NewElement();
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::OpenElement(__int64 id)
{

return Object->OpenElement(id);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::DeleteElement(__int64 id)
{

return Object->DeleteElement(id);
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::SaveElement(void)
{

return Object->SaveElement();
}
//------------------------------------------------------------------------------------------
bool TDMSprDepartmentImpl::ChangeGrp(__int64 new_id_grp, __int64 id_el)
{

return Object->ChangeGrp(new_id_grp,id_el);
}
//------------------------------------------------------------------------------------------


	//интерфейс IkasDMDataSet

TDataSource * TDMSprDepartmentImpl::kanGetDataSource(int index_data_source)
{

return  Object->kanGetDataSource(index_data_source);

}
//----------------------------------------------------------------------------------
