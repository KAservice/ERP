#include "vcl.h"
#pragma hdrstop


#include "UDMRepDataSetImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMRepDataSetImpl::TDMRepDataSetImpl()           
{                                            
Object=new TDMRepDataSet(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMRepDataSetImpl::~TDMRepDataSetImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMRepDataSetImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMRepDataSetImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
int TDMRepDataSetImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMRepDataSetImpl::kanRelease(void)                                  
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
int  TDMRepDataSetImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMRepDataSetImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMRepDataSetImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMRepDataSetImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMRepDataSetImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMRepDataSetImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMRepDataSetImpl::Done(void)
{
return Object->Done();
}
//---------------------------------------------------------------

//интерфейс IkasDM


//параметры
bool TDMRepDataSetImpl::SetParameterAsInt64 (__int64 value, UnicodeString name_parameter, int index_data_set)
{

return Object->SetParameterAsInt64 (value,name_parameter,index_data_set);
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSetImpl::SetParameterAsInt (int value, UnicodeString name_parameter, int index_data_set)
{

return Object->SetParameterAsInt (value,name_parameter,index_data_set);
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSetImpl::SetParameterAsFloat (double value, UnicodeString name_parameter, int index_data_set)
{

return Object->SetParameterAsFloat (value, name_parameter,index_data_set);
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSetImpl::SetParameterAsString (UnicodeString value, UnicodeString name_parameter, int index_data_set)
{

return Object->SetParameterAsString (value, name_parameter, index_data_set);
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSetImpl::SetParameterAsDateTime (TDateTime value, UnicodeString name_parameter, int index_data_set)
{

return Object->SetParameterAsDateTime (value, name_parameter, index_data_set);
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSetImpl::SetParameterAsBool (bool value, UnicodeString name_parameter, int index_data_set)
{

return Object->SetParameterAsBool (value,  name_parameter, index_data_set);
}
//-----------------------------------------------------------------------------------------------------


bool TDMRepDataSetImpl::OpenDataSet(int index_data_set)
{

 return Object->OpenDataSet(index_data_set);
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSetImpl::CloseDataSet(int index_data_set)
{

return Object->CloseDataSet(index_data_set);
}
//-----------------------------------------------------------------------------------------------------

// значения полей
bool TDMRepDataSetImpl::SetValueFieldAsInt (int value, UnicodeString name_field, int index_data_set)
{

return Object->SetValueFieldAsInt (value, name_field,index_data_set);
}
//-----------------------------------------------------------------------------------------------------
int TDMRepDataSetImpl::GetValueFieldAsInt (UnicodeString name_field, int index_data_set)
{
return Object->GetValueFieldAsInt (name_field, index_data_set);

}
//-----------------------------------------------------------------------------------------------------

bool TDMRepDataSetImpl::SetValueFieldAsInt64 (__int64 value, UnicodeString name_field, int index_data_set)
{
return Object->SetValueFieldAsInt64 (value, name_field, index_data_set);

}
//-----------------------------------------------------------------------------------------------------
__int64 TDMRepDataSetImpl::GetValueFieldAsInt64 (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsInt64 (name_field,index_data_set);
}
//-----------------------------------------------------------------------------------------------------

bool TDMRepDataSetImpl::SetValueFieldAsFloat (double value, UnicodeString name_field, int index_data_set)
{
 return Object->SetValueFieldAsFloat (value, name_field, index_data_set);

}
//-----------------------------------------------------------------------------------------------------
double TDMRepDataSetImpl::GetValueFieldAsFloat (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsFloat (name_field,index_data_set);
}
//-----------------------------------------------------------------------------------------------------

bool TDMRepDataSetImpl::SetValueFieldAsString (UnicodeString value, UnicodeString name_field, int index_data_set)
{
return Object->SetValueFieldAsString (value,  name_field, index_data_set);

}
//-----------------------------------------------------------------------------------------------------
UnicodeString TDMRepDataSetImpl::GetValueFieldAsString (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsString (name_field,index_data_set);
}
//-----------------------------------------------------------------------------------------------------

bool TDMRepDataSetImpl::SetValueFieldAsDateTime (TDateTime value, UnicodeString name_field, int index_data_set)
{

return Object->SetValueFieldAsDateTime (value, name_field, index_data_set);
}
//-----------------------------------------------------------------------------------------------------
TDateTime TDMRepDataSetImpl::GetValueFieldAsDateTime (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsDateTime (name_field, index_data_set);
}
//-----------------------------------------------------------------------------------------------------

bool TDMRepDataSetImpl::SetValueFieldAsBool (bool value, UnicodeString name_field, int index_data_set)
{
return Object->SetValueFieldAsBool (value,  name_field, index_data_set);

}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSetImpl::GetValueFieldAsBool (UnicodeString name_field, int index_data_set)
{

return Object->GetValueFieldAsBool ( name_field,  index_data_set);
}
//-----------------------------------------------------------------------------------------------------


bool TDMRepDataSetImpl::SaveValueFieldToStream(TStream *s,UnicodeString name_field, int index_data_set)
{

return Object->SaveValueFieldToStream(s,name_field, index_data_set);
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSetImpl::SaveValueFieldToFile(UnicodeString file_name, UnicodeString name_field, int index_data_set)
{
return Object->SaveValueFieldToFile(file_name, name_field, index_data_set);

}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSetImpl::LoadValueFieldFromStream(TStream *s,UnicodeString name_field, int index_data_set)
{

return Object->LoadValueFieldFromStream(s,name_field, index_data_set);
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSetImpl::LoadValueFieldFromFile(UnicodeString file_name, UnicodeString name_field, int index_data_set)
{

return Object->LoadValueFieldFromFile(file_name, name_field, index_data_set);
}
//-----------------------------------------------------------------------------------------------------

//навиация
int TDMRepDataSetImpl::GetRecordCount(int index_data_set)
{

return Object->GetRecordCount(index_data_set);
}
//-----------------------------------------------------------------------------------------------------
int TDMRepDataSetImpl::GetIndexTecRecord(int index_data_set)
{
return Object->GetIndexTecRecord(index_data_set);

}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSetImpl::GetEof(int index_data_set)
{
return Object->GetEof(index_data_set);

}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSetImpl::First(int index_data_set)
{

 return Object->First(index_data_set);
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSetImpl::Next(int index_data_set)
{

return Object->Next(index_data_set);
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSetImpl::Last(int index_data_set)
{

return Object->Last(index_data_set);
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSetImpl::MoveBy(int kol_rec,int index_data_set)
{

return Object->MoveBy(kol_rec,index_data_set);
}
//-----------------------------------------------------------------------------------------------------

//сохранение удаление записей
bool TDMRepDataSetImpl::Edit(int index_data_set)
{

return Object->Edit(index_data_set);
}
//-----------------------------------------------------------------------------------------------------
bool TDMRepDataSetImpl::Post(int index_data_set)
{

return Object->Post(index_data_set);
}
//-----------------------------------------------------------------------------------------------------


//интерфейс IkasDMDataSet

TDataSource * TDMRepDataSetImpl::kanGetDataSource(int index_data_source)
{

return Object->kanGetDataSource(index_data_source);
}
//-----------------------------------------------------------------------------------------------------
