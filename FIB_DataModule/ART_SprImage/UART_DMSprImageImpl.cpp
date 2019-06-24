#include "vcl.h"
#pragma hdrstop


#include "UART_DMSprImageImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TART_DMSprImageImpl::TART_DMSprImageImpl()           
{                                            
Object=new TART_DMSprImage(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TART_DMSprImageImpl::~TART_DMSprImageImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TART_DMSprImageImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TART_DMSprImageImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IART_DMSprImage)                        
   {                                                                     
   *ppv=static_cast<IART_DMSprImage*> (this);                                
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
int TART_DMSprImageImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TART_DMSprImageImpl::kanRelease(void)                                  
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
int  TART_DMSprImageImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TART_DMSprImageImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TART_DMSprImageImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TART_DMSprImageImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TART_DMSprImageImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IART_DMSprImage
TDataSource * TART_DMSprImageImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TART_DMSprImageImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprImageImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TART_DMSprImageImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprImageImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TART_DMSprImageImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TART_DMSprImageImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprImageImpl::get_ElementID_ART_IMG(void)
{
return Object->ElementID_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_ElementID_ART_IMG(TFIBLargeIntField * ElementID_ART_IMG)
{
Object->ElementID_ART_IMG=ElementID_ART_IMG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprImageImpl::get_ElementIDBASE_ART_IMG(void)
{
return Object->ElementIDBASE_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_ElementIDBASE_ART_IMG(TFIBLargeIntField * ElementIDBASE_ART_IMG)
{
Object->ElementIDBASE_ART_IMG=ElementIDBASE_ART_IMG;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprImageImpl::get_ElementGUID_ART_IMG(void)
{
return Object->ElementGUID_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_ElementGUID_ART_IMG(TFIBWideStringField * ElementGUID_ART_IMG)
{
Object->ElementGUID_ART_IMG=ElementGUID_ART_IMG;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprImageImpl::get_ElementPOS_ISM_ART_IMG(void)
{
return Object->ElementPOS_ISM_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_ElementPOS_ISM_ART_IMG(TFIBDateTimeField * ElementPOS_ISM_ART_IMG)
{
Object->ElementPOS_ISM_ART_IMG=ElementPOS_ISM_ART_IMG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprImageImpl::get_ElementIDGRP_ART_IMG(void)
{
return Object->ElementIDGRP_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_ElementIDGRP_ART_IMG(TFIBLargeIntField * ElementIDGRP_ART_IMG)
{
Object->ElementIDGRP_ART_IMG=ElementIDGRP_ART_IMG;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprImageImpl::get_ElementGUIDGRP_ART_IMG(void)
{
return Object->ElementGUIDGRP_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_ElementGUIDGRP_ART_IMG(TFIBWideStringField * ElementGUIDGRP_ART_IMG)
{
Object->ElementGUIDGRP_ART_IMG=ElementGUIDGRP_ART_IMG;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprImageImpl::get_ElementNAME_ART_IMG(void)
{
return Object->ElementNAME_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_ElementNAME_ART_IMG(TFIBWideStringField * ElementNAME_ART_IMG)
{
Object->ElementNAME_ART_IMG=ElementNAME_ART_IMG;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprImageImpl::get_ElementTEXT_ART_IMG(void)
{
return Object->ElementTEXT_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_ElementTEXT_ART_IMG(TFIBWideStringField * ElementTEXT_ART_IMG)
{
Object->ElementTEXT_ART_IMG=ElementTEXT_ART_IMG;
}
//---------------------------------------------------------------
TFIBIntegerField * TART_DMSprImageImpl::get_ElementHEIGHT_ART_IMG(void)
{
return Object->ElementHEIGHT_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_ElementHEIGHT_ART_IMG(TFIBIntegerField * ElementHEIGHT_ART_IMG)
{
Object->ElementHEIGHT_ART_IMG=ElementHEIGHT_ART_IMG;
}
//---------------------------------------------------------------
TFIBIntegerField * TART_DMSprImageImpl::get_ElementWIDTH_ART_IMG(void)
{
return Object->ElementWIDTH_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_ElementWIDTH_ART_IMG(TFIBIntegerField * ElementWIDTH_ART_IMG)
{
Object->ElementWIDTH_ART_IMG=ElementWIDTH_ART_IMG;
}
//---------------------------------------------------------------
TFIBBlobField * TART_DMSprImageImpl::get_ElementIMAGE_ART_IMG(void)
{
return Object->ElementIMAGE_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_ElementIMAGE_ART_IMG(TFIBBlobField * ElementIMAGE_ART_IMG)
{
Object->ElementIMAGE_ART_IMG=ElementIMAGE_ART_IMG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprImageImpl::get_TableID_ART_IMG(void)
{
return Object->TableID_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_TableID_ART_IMG(TFIBLargeIntField * TableID_ART_IMG)
{
Object->TableID_ART_IMG=TableID_ART_IMG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprImageImpl::get_TableIDBASE_ART_IMG(void)
{
return Object->TableIDBASE_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_TableIDBASE_ART_IMG(TFIBLargeIntField * TableIDBASE_ART_IMG)
{
Object->TableIDBASE_ART_IMG=TableIDBASE_ART_IMG;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprImageImpl::get_TableGUID_ART_IMG(void)
{
return Object->TableGUID_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_TableGUID_ART_IMG(TFIBWideStringField * TableGUID_ART_IMG)
{
Object->TableGUID_ART_IMG=TableGUID_ART_IMG;
}
//---------------------------------------------------------------
TFIBDateTimeField * TART_DMSprImageImpl::get_TablePOS_ISM_ART_IMG(void)
{
return Object->TablePOS_ISM_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_TablePOS_ISM_ART_IMG(TFIBDateTimeField * TablePOS_ISM_ART_IMG)
{
Object->TablePOS_ISM_ART_IMG=TablePOS_ISM_ART_IMG;
}
//---------------------------------------------------------------
TFIBLargeIntField * TART_DMSprImageImpl::get_TableIDGRP_ART_IMG(void)
{
return Object->TableIDGRP_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_TableIDGRP_ART_IMG(TFIBLargeIntField * TableIDGRP_ART_IMG)
{
Object->TableIDGRP_ART_IMG=TableIDGRP_ART_IMG;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprImageImpl::get_TableGUIDGRP_ART_IMG(void)
{
return Object->TableGUIDGRP_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_TableGUIDGRP_ART_IMG(TFIBWideStringField * TableGUIDGRP_ART_IMG)
{
Object->TableGUIDGRP_ART_IMG=TableGUIDGRP_ART_IMG;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprImageImpl::get_TableNAME_ART_IMG(void)
{
return Object->TableNAME_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_TableNAME_ART_IMG(TFIBWideStringField * TableNAME_ART_IMG)
{
Object->TableNAME_ART_IMG=TableNAME_ART_IMG;
}
//---------------------------------------------------------------
TFIBWideStringField * TART_DMSprImageImpl::get_TableTEXT_ART_IMG(void)
{
return Object->TableTEXT_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_TableTEXT_ART_IMG(TFIBWideStringField * TableTEXT_ART_IMG)
{
Object->TableTEXT_ART_IMG=TableTEXT_ART_IMG;
}
//---------------------------------------------------------------
TFIBIntegerField * TART_DMSprImageImpl::get_TableHEIGHT_ART_IMG(void)
{
return Object->TableHEIGHT_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_TableHEIGHT_ART_IMG(TFIBIntegerField * TableHEIGHT_ART_IMG)
{
Object->TableHEIGHT_ART_IMG=TableHEIGHT_ART_IMG;
}
//---------------------------------------------------------------
TFIBIntegerField * TART_DMSprImageImpl::get_TableWIDTH_ART_IMG(void)
{
return Object->TableWIDTH_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_TableWIDTH_ART_IMG(TFIBIntegerField * TableWIDTH_ART_IMG)
{
Object->TableWIDTH_ART_IMG=TableWIDTH_ART_IMG;
}
//---------------------------------------------------------------
TFIBBlobField * TART_DMSprImageImpl::get_TableIMAGE_ART_IMG(void)
{
return Object->TableIMAGE_ART_IMG;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_TableIMAGE_ART_IMG(TFIBBlobField * TableIMAGE_ART_IMG)
{
Object->TableIMAGE_ART_IMG=TableIMAGE_ART_IMG;
}
//---------------------------------------------------------------
__int64 TART_DMSprImageImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TART_DMSprImageImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TART_DMSprImageImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
UnicodeString TART_DMSprImageImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
int TART_DMSprImageImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TART_DMSprImageImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TART_DMSprImageImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TART_DMSprImageImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TART_DMSprImageImpl::ChancheGrp(__int64 id_new_grp,__int64 id_prop)
{
return Object->ChancheGrp(id_new_grp,id_prop);
}
//---------------------------------------------------------------
__int64 TART_DMSprImageImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 TART_DMSprImageImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
