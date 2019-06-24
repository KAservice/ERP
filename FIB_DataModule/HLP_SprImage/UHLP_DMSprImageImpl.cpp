#include "vcl.h"
#pragma hdrstop


#include "UHLP_DMSprImageImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THLP_DMSprImageImpl::THLP_DMSprImageImpl()           
{                                            
Object=new THLP_DMSprImage(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THLP_DMSprImageImpl::~THLP_DMSprImageImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THLP_DMSprImageImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THLP_DMSprImageImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHLP_DMSprImage)                        
   {                                                                     
   *ppv=static_cast<IHLP_DMSprImage*> (this);                                
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
int THLP_DMSprImageImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THLP_DMSprImageImpl::kanRelease(void)                                  
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
int  THLP_DMSprImageImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THLP_DMSprImageImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THLP_DMSprImageImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THLP_DMSprImageImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THLP_DMSprImageImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHLP_DMSprImage
TDataSource * THLP_DMSprImageImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * THLP_DMSprImageImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprImageImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * THLP_DMSprImageImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprImageImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * THLP_DMSprImageImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * THLP_DMSprImageImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageImpl::get_TableID_HLP_IMG(void)
{
return Object->TableID_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableID_HLP_IMG(TFIBLargeIntField * TableID_HLP_IMG)
{
Object->TableID_HLP_IMG=TableID_HLP_IMG;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageImpl::get_TableIDBASE_HLP_IMG(void)
{
return Object->TableIDBASE_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableIDBASE_HLP_IMG(TFIBLargeIntField * TableIDBASE_HLP_IMG)
{
Object->TableIDBASE_HLP_IMG=TableIDBASE_HLP_IMG;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_TableGUID_HLP_IMG(void)
{
return Object->TableGUID_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableGUID_HLP_IMG(TFIBWideStringField * TableGUID_HLP_IMG)
{
Object->TableGUID_HLP_IMG=TableGUID_HLP_IMG;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprImageImpl::get_TablePOS_ISM_HLP_IMG(void)
{
return Object->TablePOS_ISM_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TablePOS_ISM_HLP_IMG(TFIBDateTimeField * TablePOS_ISM_HLP_IMG)
{
Object->TablePOS_ISM_HLP_IMG=TablePOS_ISM_HLP_IMG;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageImpl::get_TableIDGRP_HLP_IMG(void)
{
return Object->TableIDGRP_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableIDGRP_HLP_IMG(TFIBLargeIntField * TableIDGRP_HLP_IMG)
{
Object->TableIDGRP_HLP_IMG=TableIDGRP_HLP_IMG;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_TableGUIDGRP_HLP_IMG(void)
{
return Object->TableGUIDGRP_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableGUIDGRP_HLP_IMG(TFIBWideStringField * TableGUIDGRP_HLP_IMG)
{
Object->TableGUIDGRP_HLP_IMG=TableGUIDGRP_HLP_IMG;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_TableNAME_HLP_IMG(void)
{
return Object->TableNAME_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableNAME_HLP_IMG(TFIBWideStringField * TableNAME_HLP_IMG)
{
Object->TableNAME_HLP_IMG=TableNAME_HLP_IMG;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_TableTEXT_HLP_IMG(void)
{
return Object->TableTEXT_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableTEXT_HLP_IMG(TFIBWideStringField * TableTEXT_HLP_IMG)
{
Object->TableTEXT_HLP_IMG=TableTEXT_HLP_IMG;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprImageImpl::get_TableHEIGHT_HLP_IMG(void)
{
return Object->TableHEIGHT_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableHEIGHT_HLP_IMG(TFIBIntegerField * TableHEIGHT_HLP_IMG)
{
Object->TableHEIGHT_HLP_IMG=TableHEIGHT_HLP_IMG;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprImageImpl::get_TableWIDTH_HLP_IMG(void)
{
return Object->TableWIDTH_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableWIDTH_HLP_IMG(TFIBIntegerField * TableWIDTH_HLP_IMG)
{
Object->TableWIDTH_HLP_IMG=TableWIDTH_HLP_IMG;
}
//---------------------------------------------------------------
TFIBBlobField * THLP_DMSprImageImpl::get_TableIMAGE_HLP_IMG(void)
{
return Object->TableIMAGE_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableIMAGE_HLP_IMG(TFIBBlobField * TableIMAGE_HLP_IMG)
{
Object->TableIMAGE_HLP_IMG=TableIMAGE_HLP_IMG;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprImageImpl::get_TableINDEX_HLP_IMG(void)
{
return Object->TableINDEX_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableINDEX_HLP_IMG(TFIBIntegerField * TableINDEX_HLP_IMG)
{
Object->TableINDEX_HLP_IMG=TableINDEX_HLP_IMG;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageImpl::get_ElementID_HLP_IMG(void)
{
return Object->ElementID_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementID_HLP_IMG(TFIBLargeIntField * ElementID_HLP_IMG)
{
Object->ElementID_HLP_IMG=ElementID_HLP_IMG;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageImpl::get_ElementIDBASE_HLP_IMG(void)
{
return Object->ElementIDBASE_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementIDBASE_HLP_IMG(TFIBLargeIntField * ElementIDBASE_HLP_IMG)
{
Object->ElementIDBASE_HLP_IMG=ElementIDBASE_HLP_IMG;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_ElementGUID_HLP_IMG(void)
{
return Object->ElementGUID_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementGUID_HLP_IMG(TFIBWideStringField * ElementGUID_HLP_IMG)
{
Object->ElementGUID_HLP_IMG=ElementGUID_HLP_IMG;
}
//---------------------------------------------------------------
TFIBDateTimeField * THLP_DMSprImageImpl::get_ElementPOS_ISM_HLP_IMG(void)
{
return Object->ElementPOS_ISM_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementPOS_ISM_HLP_IMG(TFIBDateTimeField * ElementPOS_ISM_HLP_IMG)
{
Object->ElementPOS_ISM_HLP_IMG=ElementPOS_ISM_HLP_IMG;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageImpl::get_ElementIDGRP_HLP_IMG(void)
{
return Object->ElementIDGRP_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementIDGRP_HLP_IMG(TFIBLargeIntField * ElementIDGRP_HLP_IMG)
{
Object->ElementIDGRP_HLP_IMG=ElementIDGRP_HLP_IMG;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_ElementGUIDGRP_HLP_IMG(void)
{
return Object->ElementGUIDGRP_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementGUIDGRP_HLP_IMG(TFIBWideStringField * ElementGUIDGRP_HLP_IMG)
{
Object->ElementGUIDGRP_HLP_IMG=ElementGUIDGRP_HLP_IMG;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_ElementNAME_HLP_IMG(void)
{
return Object->ElementNAME_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementNAME_HLP_IMG(TFIBWideStringField * ElementNAME_HLP_IMG)
{
Object->ElementNAME_HLP_IMG=ElementNAME_HLP_IMG;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_ElementTEXT_HLP_IMG(void)
{
return Object->ElementTEXT_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementTEXT_HLP_IMG(TFIBWideStringField * ElementTEXT_HLP_IMG)
{
Object->ElementTEXT_HLP_IMG=ElementTEXT_HLP_IMG;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprImageImpl::get_ElementHEIGHT_HLP_IMG(void)
{
return Object->ElementHEIGHT_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementHEIGHT_HLP_IMG(TFIBIntegerField * ElementHEIGHT_HLP_IMG)
{
Object->ElementHEIGHT_HLP_IMG=ElementHEIGHT_HLP_IMG;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprImageImpl::get_ElementWIDTH_HLP_IMG(void)
{
return Object->ElementWIDTH_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementWIDTH_HLP_IMG(TFIBIntegerField * ElementWIDTH_HLP_IMG)
{
Object->ElementWIDTH_HLP_IMG=ElementWIDTH_HLP_IMG;
}
//---------------------------------------------------------------
TFIBBlobField * THLP_DMSprImageImpl::get_ElementIMAGE_HLP_IMG(void)
{
return Object->ElementIMAGE_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementIMAGE_HLP_IMG(TFIBBlobField * ElementIMAGE_HLP_IMG)
{
Object->ElementIMAGE_HLP_IMG=ElementIMAGE_HLP_IMG;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprImageImpl::get_ElementINDEX_HLP_IMG(void)
{
return Object->ElementINDEX_HLP_IMG;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementINDEX_HLP_IMG(TFIBIntegerField * ElementINDEX_HLP_IMG)
{
Object->ElementINDEX_HLP_IMG=ElementINDEX_HLP_IMG;
}
//---------------------------------------------------------------
__int64 THLP_DMSprImageImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool THLP_DMSprImageImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 THLP_DMSprImageImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
UnicodeString THLP_DMSprImageImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp, all);
}
//---------------------------------------------------------------
int THLP_DMSprImageImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool THLP_DMSprImageImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool THLP_DMSprImageImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool THLP_DMSprImageImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::ChancheGrp(__int64 id_new_grp,__int64 id_prop)
{
return Object->ChancheGrp(id_new_grp,id_prop);
}
//---------------------------------------------------------------
__int64 THLP_DMSprImageImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 THLP_DMSprImageImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
