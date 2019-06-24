#include "vcl.h"
#pragma hdrstop


#include "UDMTableExtPrintFormImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMTableExtPrintFormImpl::TDMTableExtPrintFormImpl()           
{                                            
Object=new TDMTableExtPrintForm(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMTableExtPrintFormImpl::~TDMTableExtPrintFormImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMTableExtPrintFormImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMTableExtPrintForm)                        
   {                                                                     
   *ppv=static_cast<IDMTableExtPrintForm*> (this);                                
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
int TDMTableExtPrintFormImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMTableExtPrintFormImpl::kanRelease(void)                                  
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
int  TDMTableExtPrintFormImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMTableExtPrintFormImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMTableExtPrintFormImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMTableExtPrintFormImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMTableExtPrintFormImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMTableExtPrintForm
TDataSource * TDMTableExtPrintFormImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMTableExtPrintFormImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMTableExtPrintFormImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMTableExtPrintFormImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMTableExtPrintFormImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMTableExtPrintFormImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMTableExtPrintFormImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMTableExtPrintFormImpl::get_TableID_EXTPRINT_FORM(void)
{
return Object->TableID_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_TableID_EXTPRINT_FORM(TFIBLargeIntField * TableID_EXTPRINT_FORM)
{
Object->TableID_EXTPRINT_FORM=TableID_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableExtPrintFormImpl::get_TableNAME_EXTPRINT_FORM(void)
{
return Object->TableNAME_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_TableNAME_EXTPRINT_FORM(TFIBWideStringField * TableNAME_EXTPRINT_FORM)
{
Object->TableNAME_EXTPRINT_FORM=TableNAME_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableExtPrintFormImpl::get_TableOBJECT_EXTPRINT_FORM(void)
{
return Object->TableOBJECT_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_TableOBJECT_EXTPRINT_FORM(TFIBWideStringField * TableOBJECT_EXTPRINT_FORM)
{
Object->TableOBJECT_EXTPRINT_FORM=TableOBJECT_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableExtPrintFormImpl::get_TableFILE_NAME_EXTPRINT_FORM(void)
{
return Object->TableFILE_NAME_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_TableFILE_NAME_EXTPRINT_FORM(TFIBWideStringField * TableFILE_NAME_EXTPRINT_FORM)
{
Object->TableFILE_NAME_EXTPRINT_FORM=TableFILE_NAME_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMTableExtPrintFormImpl::get_TableISPCONST_EXTPRINT_FORM(void)
{
return Object->TableISPCONST_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_TableISPCONST_EXTPRINT_FORM(TFIBIntegerField * TableISPCONST_EXTPRINT_FORM)
{
Object->TableISPCONST_EXTPRINT_FORM=TableISPCONST_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableExtPrintFormImpl::get_TableGID_EXTPRINT_FORM(void)
{
return Object->TableGID_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_TableGID_EXTPRINT_FORM(TFIBWideStringField * TableGID_EXTPRINT_FORM)
{
Object->TableGID_EXTPRINT_FORM=TableGID_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMTableExtPrintFormImpl::get_TableIDBASE_EXTPRINT_FORM(void)
{
return Object->TableIDBASE_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_TableIDBASE_EXTPRINT_FORM(TFIBLargeIntField * TableIDBASE_EXTPRINT_FORM)
{
Object->TableIDBASE_EXTPRINT_FORM=TableIDBASE_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMTableExtPrintFormImpl::get_TableTYPEMODULE_EXTPRINT_FORM(void)
{
return Object->TableTYPEMODULE_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_TableTYPEMODULE_EXTPRINT_FORM(TFIBIntegerField * TableTYPEMODULE_EXTPRINT_FORM)
{
Object->TableTYPEMODULE_EXTPRINT_FORM=TableTYPEMODULE_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMTableExtPrintFormImpl::get_TableRESIDENCE_EXTPRINT_FORM(void)
{
return Object->TableRESIDENCE_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_TableRESIDENCE_EXTPRINT_FORM(TFIBIntegerField * TableRESIDENCE_EXTPRINT_FORM)
{
Object->TableRESIDENCE_EXTPRINT_FORM=TableRESIDENCE_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBBlobField * TDMTableExtPrintFormImpl::get_TableBODY_EXTPRINT_FORM(void)
{
return Object->TableBODY_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_TableBODY_EXTPRINT_FORM(TFIBBlobField * TableBODY_EXTPRINT_FORM)
{
Object->TableBODY_EXTPRINT_FORM=TableBODY_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableExtPrintFormImpl::get_TableGUID_OB_EXTPRINT_FORM(void)
{
return Object->TableGUID_OB_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_TableGUID_OB_EXTPRINT_FORM(TFIBWideStringField * TableGUID_OB_EXTPRINT_FORM)
{
Object->TableGUID_OB_EXTPRINT_FORM=TableGUID_OB_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableExtPrintFormImpl::get_TableNAME_PROGRAM_MODULE(void)
{
return Object->TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE)
{
Object->TableNAME_PROGRAM_MODULE=TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableExtPrintFormImpl::get_TablePROGID_PROGRAM_MODULE(void)
{
return Object->TablePROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE)
{
Object->TablePROGID_PROGRAM_MODULE=TablePROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableExtPrintFormImpl::get_TablePATCH_PROGRAM_MODULE(void)
{
return Object->TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE)
{
Object->TablePATCH_PROGRAM_MODULE=TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMTableExtPrintFormImpl::get_ElementID_EXTPRINT_FORM(void)
{
return Object->ElementID_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_ElementID_EXTPRINT_FORM(TFIBLargeIntField * ElementID_EXTPRINT_FORM)
{
Object->ElementID_EXTPRINT_FORM=ElementID_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableExtPrintFormImpl::get_ElementNAME_EXTPRINT_FORM(void)
{
return Object->ElementNAME_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_ElementNAME_EXTPRINT_FORM(TFIBWideStringField * ElementNAME_EXTPRINT_FORM)
{
Object->ElementNAME_EXTPRINT_FORM=ElementNAME_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableExtPrintFormImpl::get_ElementOBJECT_EXTPRINT_FORM(void)
{
return Object->ElementOBJECT_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_ElementOBJECT_EXTPRINT_FORM(TFIBWideStringField * ElementOBJECT_EXTPRINT_FORM)
{
Object->ElementOBJECT_EXTPRINT_FORM=ElementOBJECT_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableExtPrintFormImpl::get_ElementFILE_NAME_EXTPRINT_FORM(void)
{
return Object->ElementFILE_NAME_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_ElementFILE_NAME_EXTPRINT_FORM(TFIBWideStringField * ElementFILE_NAME_EXTPRINT_FORM)
{
Object->ElementFILE_NAME_EXTPRINT_FORM=ElementFILE_NAME_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMTableExtPrintFormImpl::get_ElementISPCONST_EXTPRINT_FORM(void)
{
return Object->ElementISPCONST_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_ElementISPCONST_EXTPRINT_FORM(TFIBIntegerField * ElementISPCONST_EXTPRINT_FORM)
{
Object->ElementISPCONST_EXTPRINT_FORM=ElementISPCONST_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableExtPrintFormImpl::get_ElementGID_EXTPRINT_FORM(void)
{
return Object->ElementGID_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_ElementGID_EXTPRINT_FORM(TFIBWideStringField * ElementGID_EXTPRINT_FORM)
{
Object->ElementGID_EXTPRINT_FORM=ElementGID_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMTableExtPrintFormImpl::get_ElementIDBASE_EXTPRINT_FORM(void)
{
return Object->ElementIDBASE_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_ElementIDBASE_EXTPRINT_FORM(TFIBLargeIntField * ElementIDBASE_EXTPRINT_FORM)
{
Object->ElementIDBASE_EXTPRINT_FORM=ElementIDBASE_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMTableExtPrintFormImpl::get_ElementTYPEMODULE_EXTPRINT_FORM(void)
{
return Object->ElementTYPEMODULE_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_ElementTYPEMODULE_EXTPRINT_FORM(TFIBIntegerField * ElementTYPEMODULE_EXTPRINT_FORM)
{
Object->ElementTYPEMODULE_EXTPRINT_FORM=ElementTYPEMODULE_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMTableExtPrintFormImpl::get_ElementRESIDENCE_EXTPRINT_FORM(void)
{
return Object->ElementRESIDENCE_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_ElementRESIDENCE_EXTPRINT_FORM(TFIBIntegerField * ElementRESIDENCE_EXTPRINT_FORM)
{
Object->ElementRESIDENCE_EXTPRINT_FORM=ElementRESIDENCE_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBBlobField * TDMTableExtPrintFormImpl::get_ElementBODY_EXTPRINT_FORM(void)
{
return Object->ElementBODY_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_ElementBODY_EXTPRINT_FORM(TFIBBlobField * ElementBODY_EXTPRINT_FORM)
{
Object->ElementBODY_EXTPRINT_FORM=ElementBODY_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableExtPrintFormImpl::get_ElementGUID_OB_EXTPRINT_FORM(void)
{
return Object->ElementGUID_OB_EXTPRINT_FORM;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_ElementGUID_OB_EXTPRINT_FORM(TFIBWideStringField * ElementGUID_OB_EXTPRINT_FORM)
{
Object->ElementGUID_OB_EXTPRINT_FORM=ElementGUID_OB_EXTPRINT_FORM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableExtPrintFormImpl::get_ElementNAME_PROGRAM_MODULE(void)
{
return Object->ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE)
{
Object->ElementNAME_PROGRAM_MODULE=ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableExtPrintFormImpl::get_ElementPROGID_PROGRAM_MODULE(void)
{
return Object->ElementPROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE)
{
Object->ElementPROGID_PROGRAM_MODULE=ElementPROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMTableExtPrintFormImpl::get_ElementPATCH_PROGRAM_MODULE(void)
{
return Object->ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE)
{
Object->ElementPATCH_PROGRAM_MODULE=ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::OpenTable(REFIID guid, bool all)
{
return Object->OpenTable(guid,all);
}
//---------------------------------------------------------------
int TDMTableExtPrintFormImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMTableExtPrintFormImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
void TDMTableExtPrintFormImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
__int64 TDMTableExtPrintFormImpl::GetIDElement(String gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
AnsiString TDMTableExtPrintFormImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
