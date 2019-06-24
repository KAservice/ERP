#include "vcl.h"
#pragma hdrstop


#include "UDMObjectBasePrivImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMObjectBasePrivImpl::TDMObjectBasePrivImpl()           
{                                            
Object=new TDMObjectBasePriv(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMObjectBasePrivImpl::~TDMObjectBasePrivImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMObjectBasePrivImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMObjectBasePriv)                        
   {                                                                     
   *ppv=static_cast<IDMObjectBasePriv*> (this);                                
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
int TDMObjectBasePrivImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMObjectBasePrivImpl::kanRelease(void)                                  
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
int  TDMObjectBasePrivImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMObjectBasePrivImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMObjectBasePrivImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMObjectBasePrivImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMObjectBasePrivImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMObjectBasePriv
TDataSource * TDMObjectBasePrivImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMObjectBasePrivImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMObjectBasePrivImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMObjectBasePrivImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMObjectBasePrivImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TIntegerField * TDMObjectBasePrivImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMObjectBasePrivImpl::get_TableID_OBJECT_BASE_PRIV(void)
{
return Object->TableID_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_TableID_OBJECT_BASE_PRIV(TFIBLargeIntField * TableID_OBJECT_BASE_PRIV)
{
Object->TableID_OBJECT_BASE_PRIV=TableID_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMObjectBasePrivImpl::get_TableIDBASE_OBJECT_BASE_PRIV(void)
{
return Object->TableIDBASE_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_TableIDBASE_OBJECT_BASE_PRIV(TFIBLargeIntField * TableIDBASE_OBJECT_BASE_PRIV)
{
Object->TableIDBASE_OBJECT_BASE_PRIV=TableIDBASE_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMObjectBasePrivImpl::get_TableIDGRPUSER_OBJECT_BASE_PRIV(void)
{
return Object->TableIDGRPUSER_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_TableIDGRPUSER_OBJECT_BASE_PRIV(TFIBLargeIntField * TableIDGRPUSER_OBJECT_BASE_PRIV)
{
Object->TableIDGRPUSER_OBJECT_BASE_PRIV=TableIDGRPUSER_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMObjectBasePrivImpl::get_TableINS_OBJECT_BASE_PRIV(void)
{
return Object->TableINS_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_TableINS_OBJECT_BASE_PRIV(TFIBSmallIntField * TableINS_OBJECT_BASE_PRIV)
{
Object->TableINS_OBJECT_BASE_PRIV=TableINS_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMObjectBasePrivImpl::get_TableEDIT_OBJECT_BASE_PRIV(void)
{
return Object->TableEDIT_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_TableEDIT_OBJECT_BASE_PRIV(TFIBSmallIntField * TableEDIT_OBJECT_BASE_PRIV)
{
Object->TableEDIT_OBJECT_BASE_PRIV=TableEDIT_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMObjectBasePrivImpl::get_TableDEL_OBJECT_BASE_PRIV(void)
{
return Object->TableDEL_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_TableDEL_OBJECT_BASE_PRIV(TFIBSmallIntField * TableDEL_OBJECT_BASE_PRIV)
{
Object->TableDEL_OBJECT_BASE_PRIV=TableDEL_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMObjectBasePrivImpl::get_TableEXEC_OBJECT_BASE_PRIV(void)
{
return Object->TableEXEC_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_TableEXEC_OBJECT_BASE_PRIV(TFIBSmallIntField * TableEXEC_OBJECT_BASE_PRIV)
{
Object->TableEXEC_OBJECT_BASE_PRIV=TableEXEC_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMObjectBasePrivImpl::get_TableNUMBER_OBJECT_BASE_PRIV(void)
{
return Object->TableNUMBER_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_TableNUMBER_OBJECT_BASE_PRIV(TFIBIntegerField * TableNUMBER_OBJECT_BASE_PRIV)
{
Object->TableNUMBER_OBJECT_BASE_PRIV=TableNUMBER_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMObjectBasePrivImpl::get_TableIDGRP_OBJECT_BASE_PRIV(void)
{
return Object->TableIDGRP_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_TableIDGRP_OBJECT_BASE_PRIV(TFIBLargeIntField * TableIDGRP_OBJECT_BASE_PRIV)
{
Object->TableIDGRP_OBJECT_BASE_PRIV=TableIDGRP_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMObjectBasePrivImpl::get_ElementID_OBJECT_BASE_PRIV(void)
{
return Object->ElementID_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_ElementID_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementID_OBJECT_BASE_PRIV)
{
Object->ElementID_OBJECT_BASE_PRIV=ElementID_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMObjectBasePrivImpl::get_ElementIDBASE_OBJECT_BASE_PRIV(void)
{
return Object->ElementIDBASE_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_ElementIDBASE_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementIDBASE_OBJECT_BASE_PRIV)
{
Object->ElementIDBASE_OBJECT_BASE_PRIV=ElementIDBASE_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMObjectBasePrivImpl::get_ElementIDEXT_DOUT_OBJECT_BASE_PRIV(void)
{
return Object->ElementIDEXT_DOUT_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_ElementIDEXT_DOUT_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementIDEXT_DOUT_OBJECT_BASE_PRIV)
{
Object->ElementIDEXT_DOUT_OBJECT_BASE_PRIV=ElementIDEXT_DOUT_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMObjectBasePrivImpl::get_ElementIDEXT_BASE_OBJECT_BASE_PRIV(void)
{
return Object->ElementIDEXT_BASE_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_ElementIDEXT_BASE_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementIDEXT_BASE_OBJECT_BASE_PRIV)
{
Object->ElementIDEXT_BASE_OBJECT_BASE_PRIV=ElementIDEXT_BASE_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMObjectBasePrivImpl::get_ElementIDGRPUSER_OBJECT_BASE_PRIV(void)
{
return Object->ElementIDGRPUSER_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_ElementIDGRPUSER_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementIDGRPUSER_OBJECT_BASE_PRIV)
{
Object->ElementIDGRPUSER_OBJECT_BASE_PRIV=ElementIDGRPUSER_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMObjectBasePrivImpl::get_ElementINS_OBJECT_BASE_PRIV(void)
{
return Object->ElementINS_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_ElementINS_OBJECT_BASE_PRIV(TFIBSmallIntField * ElementINS_OBJECT_BASE_PRIV)
{
Object->ElementINS_OBJECT_BASE_PRIV=ElementINS_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMObjectBasePrivImpl::get_ElementEDIT_OBJECT_BASE_PRIV(void)
{
return Object->ElementEDIT_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_ElementEDIT_OBJECT_BASE_PRIV(TFIBSmallIntField * ElementEDIT_OBJECT_BASE_PRIV)
{
Object->ElementEDIT_OBJECT_BASE_PRIV=ElementEDIT_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMObjectBasePrivImpl::get_ElementDEL_OBJECT_BASE_PRIV(void)
{
return Object->ElementDEL_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_ElementDEL_OBJECT_BASE_PRIV(TFIBSmallIntField * ElementDEL_OBJECT_BASE_PRIV)
{
Object->ElementDEL_OBJECT_BASE_PRIV=ElementDEL_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMObjectBasePrivImpl::get_ElementEXEC_OBJECT_BASE_PRIV(void)
{
return Object->ElementEXEC_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_ElementEXEC_OBJECT_BASE_PRIV(TFIBSmallIntField * ElementEXEC_OBJECT_BASE_PRIV)
{
Object->ElementEXEC_OBJECT_BASE_PRIV=ElementEXEC_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMObjectBasePrivImpl::get_ElementNUMBER_OBJECT_BASE_PRIV(void)
{
return Object->ElementNUMBER_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_ElementNUMBER_OBJECT_BASE_PRIV(TFIBIntegerField * ElementNUMBER_OBJECT_BASE_PRIV)
{
Object->ElementNUMBER_OBJECT_BASE_PRIV=ElementNUMBER_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMObjectBasePrivImpl::get_ElementIDGRP_OBJECT_BASE_PRIV(void)
{
return Object->ElementIDGRP_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_ElementIDGRP_OBJECT_BASE_PRIV(TFIBLargeIntField * ElementIDGRP_OBJECT_BASE_PRIV)
{
Object->ElementIDGRP_OBJECT_BASE_PRIV=ElementIDGRP_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMObjectBasePrivImpl::get_TableAPPLICATION_OBJECT_BASE_PRIV(void)
{
return Object->TableAPPLICATION_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_TableAPPLICATION_OBJECT_BASE_PRIV(TFIBIntegerField * TableAPPLICATION_OBJECT_BASE_PRIV)
{
Object->TableAPPLICATION_OBJECT_BASE_PRIV=TableAPPLICATION_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMObjectBasePrivImpl::get_ElementAPPLICATION_OBJECT_BASE_PRIV(void)
{
return Object->ElementAPPLICATION_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_ElementAPPLICATION_OBJECT_BASE_PRIV(TFIBIntegerField * ElementAPPLICATION_OBJECT_BASE_PRIV)
{
Object->ElementAPPLICATION_OBJECT_BASE_PRIV=ElementAPPLICATION_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TpFIBQuery * TDMObjectBasePrivImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMObjectBasePrivImpl::get_ElementGUID_OBJECT_BASE_PRIV(void)
{
return Object->ElementGUID_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_ElementGUID_OBJECT_BASE_PRIV(TFIBWideStringField * ElementGUID_OBJECT_BASE_PRIV)
{
Object->ElementGUID_OBJECT_BASE_PRIV=ElementGUID_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMObjectBasePrivImpl::get_TableGUID_OBJECT_BASE_PRIV(void)
{
return Object->TableGUID_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_TableGUID_OBJECT_BASE_PRIV(TFIBWideStringField * TableGUID_OBJECT_BASE_PRIV)
{
Object->TableGUID_OBJECT_BASE_PRIV=TableGUID_OBJECT_BASE_PRIV;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMObjectBasePrivImpl::get_TableNAME_PROGRAM_MODULE(void)
{
return Object->TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_TableNAME_PROGRAM_MODULE(TFIBWideStringField * TableNAME_PROGRAM_MODULE)
{
Object->TableNAME_PROGRAM_MODULE=TableNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMObjectBasePrivImpl::get_TablePROGID_PROGRAM_MODULE(void)
{
return Object->TablePROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_TablePROGID_PROGRAM_MODULE(TFIBWideStringField * TablePROGID_PROGRAM_MODULE)
{
Object->TablePROGID_PROGRAM_MODULE=TablePROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMObjectBasePrivImpl::get_TablePATCH_PROGRAM_MODULE(void)
{
return Object->TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_TablePATCH_PROGRAM_MODULE(TFIBWideStringField * TablePATCH_PROGRAM_MODULE)
{
Object->TablePATCH_PROGRAM_MODULE=TablePATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMObjectBasePrivImpl::get_ElementNAME_PROGRAM_MODULE(void)
{
return Object->ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_ElementNAME_PROGRAM_MODULE(TFIBWideStringField * ElementNAME_PROGRAM_MODULE)
{
Object->ElementNAME_PROGRAM_MODULE=ElementNAME_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMObjectBasePrivImpl::get_ElementPROGID_PROGRAM_MODULE(void)
{
return Object->ElementPROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_ElementPROGID_PROGRAM_MODULE(TFIBWideStringField * ElementPROGID_PROGRAM_MODULE)
{
Object->ElementPROGID_PROGRAM_MODULE=ElementPROGID_PROGRAM_MODULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMObjectBasePrivImpl::get_ElementPATCH_PROGRAM_MODULE(void)
{
return Object->ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_ElementPATCH_PROGRAM_MODULE(TFIBWideStringField * ElementPATCH_PROGRAM_MODULE)
{
Object->ElementPATCH_PROGRAM_MODULE=ElementPATCH_PROGRAM_MODULE;
}
//---------------------------------------------------------------
__int64 TDMObjectBasePrivImpl::get_IdGrpUser(void)
{
return Object->IdGrpUser;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_IdGrpUser(__int64 IdGrpUser)
{
Object->IdGrpUser=IdGrpUser;
}
//---------------------------------------------------------------
__int64 TDMObjectBasePrivImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
int TDMObjectBasePrivImpl::get_NumApplication(void)
{
return Object->NumApplication;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_NumApplication(int NumApplication)
{
Object->NumApplication=NumApplication;
}
//---------------------------------------------------------------
bool TDMObjectBasePrivImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::OpenTable(int application, __int64 id_grp_user, __int64 id_grp, bool all)
{
return Object->OpenTable(application, id_grp_user,id_grp,all);
}
//---------------------------------------------------------------
bool TDMObjectBasePrivImpl::SaveIsmen()
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::CancelIsmen()
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
bool TDMObjectBasePrivImpl::Table_Delete(void)
{
return Object->Table_Delete();
}
//---------------------------------------------------------------
bool TDMObjectBasePrivImpl::Table_AppendString(int application, __int64 id_grp_user, __int64 id_grp)
{
return Object->Table_AppendString(application,id_grp_user,id_grp);
}
//---------------------------------------------------------------
bool TDMObjectBasePrivImpl::NewElement(int application, __int64 id_grp_user, __int64 id_grp)
{
return Object->NewElement(application,id_grp_user,id_grp);
}
//---------------------------------------------------------------
bool TDMObjectBasePrivImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMObjectBasePrivImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
bool TDMObjectBasePrivImpl::InsertElement(int application, __int64 id_grp_user, __int64 id_grp)
{
return Object->InsertElement(application,id_grp_user, id_grp);
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::Element_Edit(void)
{
return Object->Element_Edit();
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::Element_Post(void)
{
return Object->Element_Post();
}
//---------------------------------------------------------------
bool TDMObjectBasePrivImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMObjectBasePrivImpl::ChancheGrp(__int64 id_new_grp)
{
return Object->ChancheGrp(id_new_grp);
}
//---------------------------------------------------------------
bool TDMObjectBasePrivImpl::GetPrivDM(int application, __int64 id_grp_user, int object)
{
return Object->GetPrivDM(application, id_grp_user,object);
}
//---------------------------------------------------------------
bool TDMObjectBasePrivImpl::GetPrivForm(__int64 id_grp_user, int object)
{
return Object->GetPrivForm(id_grp_user,object);
}
//---------------------------------------------------------------
