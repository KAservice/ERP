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
TIntegerField * THLP_DMSprImageImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
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
TFIBLargeIntField * THLP_DMSprImageImpl::get_ElementID_HLP_IMAGE(void)
{
return Object->ElementID_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementID_HLP_IMAGE(TFIBLargeIntField * ElementID_HLP_IMAGE)
{
Object->ElementID_HLP_IMAGE=ElementID_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageImpl::get_ElementIDBASE_HLP_IMAGE(void)
{
return Object->ElementIDBASE_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementIDBASE_HLP_IMAGE(TFIBLargeIntField * ElementIDBASE_HLP_IMAGE)
{
Object->ElementIDBASE_HLP_IMAGE=ElementIDBASE_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_ElementGID_HLP_IMAGE(void)
{
return Object->ElementGID_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementGID_HLP_IMAGE(TFIBWideStringField * ElementGID_HLP_IMAGE)
{
Object->ElementGID_HLP_IMAGE=ElementGID_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_ElementGUID_HLP_IMAGE(void)
{
return Object->ElementGUID_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementGUID_HLP_IMAGE(TFIBWideStringField * ElementGUID_HLP_IMAGE)
{
Object->ElementGUID_HLP_IMAGE=ElementGUID_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_ElementGUIDELEMENT_HLP_IMAGE(void)
{
return Object->ElementGUIDELEMENT_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementGUIDELEMENT_HLP_IMAGE(TFIBWideStringField * ElementGUIDELEMENT_HLP_IMAGE)
{
Object->ElementGUIDELEMENT_HLP_IMAGE=ElementGUIDELEMENT_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_ElementTEXT_HLP_IMAGE(void)
{
return Object->ElementTEXT_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementTEXT_HLP_IMAGE(TFIBWideStringField * ElementTEXT_HLP_IMAGE)
{
Object->ElementTEXT_HLP_IMAGE=ElementTEXT_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprImageImpl::get_ElementTYPE_HLP_IMAGE(void)
{
return Object->ElementTYPE_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementTYPE_HLP_IMAGE(TFIBSmallIntField * ElementTYPE_HLP_IMAGE)
{
Object->ElementTYPE_HLP_IMAGE=ElementTYPE_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_ElementNAME_HLP_IMAGE(void)
{
return Object->ElementNAME_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementNAME_HLP_IMAGE(TFIBWideStringField * ElementNAME_HLP_IMAGE)
{
Object->ElementNAME_HLP_IMAGE=ElementNAME_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBBlobField * THLP_DMSprImageImpl::get_ElementIMAGE_HLP_IMAGE(void)
{
return Object->ElementIMAGE_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementIMAGE_HLP_IMAGE(TFIBBlobField * ElementIMAGE_HLP_IMAGE)
{
Object->ElementIMAGE_HLP_IMAGE=ElementIMAGE_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_ElementGUIDGRP_HLP_IMAGE(void)
{
return Object->ElementGUIDGRP_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementGUIDGRP_HLP_IMAGE(TFIBWideStringField * ElementGUIDGRP_HLP_IMAGE)
{
Object->ElementGUIDGRP_HLP_IMAGE=ElementGUIDGRP_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageImpl::get_ElementIDGRP_HLP_IMAGE(void)
{
return Object->ElementIDGRP_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementIDGRP_HLP_IMAGE(TFIBLargeIntField * ElementIDGRP_HLP_IMAGE)
{
Object->ElementIDGRP_HLP_IMAGE=ElementIDGRP_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageImpl::get_TableID_HLP_IMAGE(void)
{
return Object->TableID_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableID_HLP_IMAGE(TFIBLargeIntField * TableID_HLP_IMAGE)
{
Object->TableID_HLP_IMAGE=TableID_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageImpl::get_TableIDBASE_HLP_IMAGE(void)
{
return Object->TableIDBASE_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableIDBASE_HLP_IMAGE(TFIBLargeIntField * TableIDBASE_HLP_IMAGE)
{
Object->TableIDBASE_HLP_IMAGE=TableIDBASE_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_TableGID_HLP_IMAGE(void)
{
return Object->TableGID_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableGID_HLP_IMAGE(TFIBWideStringField * TableGID_HLP_IMAGE)
{
Object->TableGID_HLP_IMAGE=TableGID_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_TableGUID_HLP_IMAGE(void)
{
return Object->TableGUID_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableGUID_HLP_IMAGE(TFIBWideStringField * TableGUID_HLP_IMAGE)
{
Object->TableGUID_HLP_IMAGE=TableGUID_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_TableGUIDELEMENT_HLP_IMAGE(void)
{
return Object->TableGUIDELEMENT_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableGUIDELEMENT_HLP_IMAGE(TFIBWideStringField * TableGUIDELEMENT_HLP_IMAGE)
{
Object->TableGUIDELEMENT_HLP_IMAGE=TableGUIDELEMENT_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_TableTEXT_HLP_IMAGE(void)
{
return Object->TableTEXT_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableTEXT_HLP_IMAGE(TFIBWideStringField * TableTEXT_HLP_IMAGE)
{
Object->TableTEXT_HLP_IMAGE=TableTEXT_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBSmallIntField * THLP_DMSprImageImpl::get_TableTYPE_HLP_IMAGE(void)
{
return Object->TableTYPE_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableTYPE_HLP_IMAGE(TFIBSmallIntField * TableTYPE_HLP_IMAGE)
{
Object->TableTYPE_HLP_IMAGE=TableTYPE_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_TableNAME_HLP_IMAGE(void)
{
return Object->TableNAME_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableNAME_HLP_IMAGE(TFIBWideStringField * TableNAME_HLP_IMAGE)
{
Object->TableNAME_HLP_IMAGE=TableNAME_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBBlobField * THLP_DMSprImageImpl::get_TableIMAGE_HLP_IMAGE(void)
{
return Object->TableIMAGE_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableIMAGE_HLP_IMAGE(TFIBBlobField * TableIMAGE_HLP_IMAGE)
{
Object->TableIMAGE_HLP_IMAGE=TableIMAGE_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * THLP_DMSprImageImpl::get_TableGUIDGRP_HLP_IMAGE(void)
{
return Object->TableGUIDGRP_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableGUIDGRP_HLP_IMAGE(TFIBWideStringField * TableGUIDGRP_HLP_IMAGE)
{
Object->TableGUIDGRP_HLP_IMAGE=TableGUIDGRP_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * THLP_DMSprImageImpl::get_TableIDGRP_HLP_IMAGE(void)
{
return Object->TableIDGRP_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableIDGRP_HLP_IMAGE(TFIBLargeIntField * TableIDGRP_HLP_IMAGE)
{
Object->TableIDGRP_HLP_IMAGE=TableIDGRP_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprImageImpl::get_TableHEIGHT_HLP_IMAGE(void)
{
return Object->TableHEIGHT_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableHEIGHT_HLP_IMAGE(TFIBIntegerField * TableHEIGHT_HLP_IMAGE)
{
Object->TableHEIGHT_HLP_IMAGE=TableHEIGHT_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprImageImpl::get_TableWIDTH_HLP_IMAGE(void)
{
return Object->TableWIDTH_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_TableWIDTH_HLP_IMAGE(TFIBIntegerField * TableWIDTH_HLP_IMAGE)
{
Object->TableWIDTH_HLP_IMAGE=TableWIDTH_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprImageImpl::get_ElementHEIGHT_HLP_IMAGE(void)
{
return Object->ElementHEIGHT_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementHEIGHT_HLP_IMAGE(TFIBIntegerField * ElementHEIGHT_HLP_IMAGE)
{
Object->ElementHEIGHT_HLP_IMAGE=ElementHEIGHT_HLP_IMAGE;
}
//---------------------------------------------------------------
TFIBIntegerField * THLP_DMSprImageImpl::get_ElementWIDTH_HLP_IMAGE(void)
{
return Object->ElementWIDTH_HLP_IMAGE;
}
//---------------------------------------------------------------
void THLP_DMSprImageImpl::set_ElementWIDTH_HLP_IMAGE(TFIBIntegerField * ElementWIDTH_HLP_IMAGE)
{
Object->ElementWIDTH_HLP_IMAGE=ElementWIDTH_HLP_IMAGE;
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
return Object->GetTextQuery(id_grp,all);
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
