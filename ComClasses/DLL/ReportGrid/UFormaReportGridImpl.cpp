#include "vcl.h"
#pragma hdrstop


#include "UFormaReportGridImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TFormaReportGridImpl::TFormaReportGridImpl()           
{                                            
Object=new TFormaReportGrid(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TFormaReportGridImpl::~TFormaReportGridImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TFormaReportGridImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TFormaReportGridImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
 {                                                                         
int result=0;                                                             
if (id_interface==IID_IkanUnknown)                                        
   {                                                                     
   *ppv=static_cast<IkanUnknown*> (static_cast<IMainInterface*>(this)); 
   result=-1;                                                             
   }                                                                      
else if (id_interface==IID_IMainInterface)                        
   {                                                                     
   *ppv=static_cast<IMainInterface*> (this);                                
   result=-1;                                                            
   }  
else if (id_interface==IID_IkanCallBack) 
   {                                        
   *ppv=static_cast<IkanCallBack*> (this);  
   result=-1;                               
   }                                        
else if (id_interface==IID_IFormaReportGrid)                        
   {                                                                     
   *ppv=static_cast<IFormaReportGrid*> (this);                                
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
int TFormaReportGridImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TFormaReportGridImpl::kanRelease(void)                                  
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
int  TFormaReportGridImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TFormaReportGridImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TFormaReportGridImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TFormaReportGridImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TFormaReportGridImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TFormaReportGridImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TFormaReportGridImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IkanCallBack 
int TFormaReportGridImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)    
{   
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект 
									id_object,      //тип дочернего объекта  
									type_event,     //тип события в дочернем объекте 
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора 
									); 
}   
//---------------------------------------------------------------

//IFormaReportGrid
bool TFormaReportGridImpl::get_Vibor(void)
{
return Object->Vibor;
}
//---------------------------------------------------------------
void TFormaReportGridImpl::set_Vibor(bool Vibor)
{
Object->Vibor=Vibor;
}
//---------------------------------------------------------------
int TFormaReportGridImpl::get_NumberProcVibor(void)
{
return Object->NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaReportGridImpl::set_NumberProcVibor(int NumberProcVibor)
{
Object->NumberProcVibor=NumberProcVibor;
}
//---------------------------------------------------------------
void TFormaReportGridImpl::OpenReport(void)
{
return Object->OpenReport();
}
//---------------------------------------------------------------
void TFormaReportGridImpl::SetTextQuery(AnsiString zapros)
{
return Object->SetTextQuery(zapros);
}
//---------------------------------------------------------------
void TFormaReportGridImpl::AddColumn(AnsiString field_name,AnsiString caption,int width,int group_index,bool group_sum,AnsiString format_group_sum,bool footer_sum,AnsiString format_footer_sum)
{
return Object->AddColumn(field_name,caption, width,group_index,group_sum,format_group_sum,footer_sum,format_footer_sum);
}
//---------------------------------------------------------------
void TFormaReportGridImpl::CreateSeries(AnsiString name_field, AnsiString display_text)
{
return Object->CreateSeries(name_field,display_text);
}
//---------------------------------------------------------------
void TFormaReportGridImpl::AddDataGroups(AnsiString name_field, AnsiString display_text)
{
return Object->AddDataGroups(name_field, display_text);
}
//---------------------------------------------------------------
void TFormaReportGridImpl::SetCaptionReport(AnsiString text)
{
return Object->SetCaptionReport(text);
}
//---------------------------------------------------------------
void TFormaReportGridImpl::SetFontColorContentTecColumn(int style)
{
return Object->SetFontColorContentTecColumn(style);
}
//---------------------------------------------------------------
