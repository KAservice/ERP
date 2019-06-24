#include "vcl.h"
#pragma hdrstop


#include "UDMSprDiscountCardImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprDiscountCardImpl::TDMSprDiscountCardImpl()           
{                                            
Object=new TDMSprDiscountCard(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprDiscountCardImpl::~TDMSprDiscountCardImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprDiscountCardImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprDiscountCard)                        
   {                                                                     
   *ppv=static_cast<IDMSprDiscountCard*> (this);                                
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
int TDMSprDiscountCardImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprDiscountCardImpl::kanRelease(void)                                  
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
int  TDMSprDiscountCardImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprDiscountCardImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprDiscountCardImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprDiscountCardImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprDiscountCardImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprDiscountCard
TDataSource * TDMSprDiscountCardImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprDiscountCardImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprDiscountCardImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprDiscountCardImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprDiscountCardImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprDiscountCardImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprDiscountCardImpl::get_TableCODE_SDISCOUNT_CARD(void)
{
return Object->TableCODE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableCODE_SDISCOUNT_CARD(TFIBIntegerField * TableCODE_SDISCOUNT_CARD)
{
Object->TableCODE_SDISCOUNT_CARD=TableCODE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprDiscountCardImpl::get_TableTYPE_SDISCOUNT_CARD(void)
{
return Object->TableTYPE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableTYPE_SDISCOUNT_CARD(TFIBIntegerField * TableTYPE_SDISCOUNT_CARD)
{
Object->TableTYPE_SDISCOUNT_CARD=TableTYPE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprDiscountCardImpl::get_TableNACH_SDISCOUNT_CARD(void)
{
return Object->TableNACH_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableNACH_SDISCOUNT_CARD(TFIBDateTimeField * TableNACH_SDISCOUNT_CARD)
{
Object->TableNACH_SDISCOUNT_CARD=TableNACH_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprDiscountCardImpl::get_TableCON_SDISCOUNT_CARD(void)
{
return Object->TableCON_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableCON_SDISCOUNT_CARD(TFIBDateTimeField * TableCON_SDISCOUNT_CARD)
{
Object->TableCON_SDISCOUNT_CARD=TableCON_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDiscountCardImpl::get_TablePRSK_SDISCOUNT_CARD(void)
{
return Object->TablePRSK_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TablePRSK_SDISCOUNT_CARD(TFIBBCDField * TablePRSK_SDISCOUNT_CARD)
{
Object->TablePRSK_SDISCOUNT_CARD=TablePRSK_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TIntegerField * TDMSprDiscountCardImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprDiscountCardImpl::get_ElementCODE_SDISCOUNT_CARD(void)
{
return Object->ElementCODE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementCODE_SDISCOUNT_CARD(TFIBIntegerField * ElementCODE_SDISCOUNT_CARD)
{
Object->ElementCODE_SDISCOUNT_CARD=ElementCODE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprDiscountCardImpl::get_ElementTYPE_SDISCOUNT_CARD(void)
{
return Object->ElementTYPE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementTYPE_SDISCOUNT_CARD(TFIBIntegerField * ElementTYPE_SDISCOUNT_CARD)
{
Object->ElementTYPE_SDISCOUNT_CARD=ElementTYPE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprDiscountCardImpl::get_ElementNACH_SDISCOUNT_CARD(void)
{
return Object->ElementNACH_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementNACH_SDISCOUNT_CARD(TFIBDateTimeField * ElementNACH_SDISCOUNT_CARD)
{
Object->ElementNACH_SDISCOUNT_CARD=ElementNACH_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprDiscountCardImpl::get_ElementCON_SDISCOUNT_CARD(void)
{
return Object->ElementCON_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementCON_SDISCOUNT_CARD(TFIBDateTimeField * ElementCON_SDISCOUNT_CARD)
{
Object->ElementCON_SDISCOUNT_CARD=ElementCON_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDiscountCardImpl::get_ElementPRSK_SDISCOUNT_CARD(void)
{
return Object->ElementPRSK_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementPRSK_SDISCOUNT_CARD(TFIBBCDField * ElementPRSK_SDISCOUNT_CARD)
{
Object->ElementPRSK_SDISCOUNT_CARD=ElementPRSK_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprDiscountCardImpl::get_TableACT_SDISCOUNT_CARD(void)
{
return Object->TableACT_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableACT_SDISCOUNT_CARD(TFIBIntegerField * TableACT_SDISCOUNT_CARD)
{
Object->TableACT_SDISCOUNT_CARD=TableACT_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprDiscountCardImpl::get_ElementACT_SDISCOUNT_CARD(void)
{
return Object->ElementACT_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementACT_SDISCOUNT_CARD(TFIBIntegerField * ElementACT_SDISCOUNT_CARD)
{
Object->ElementACT_SDISCOUNT_CARD=ElementACT_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprDiscountCardImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountCardImpl::get_ElementFL_DISC_SDISCOUNT_CARD(void)
{
return Object->ElementFL_DISC_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementFL_DISC_SDISCOUNT_CARD(TFIBSmallIntField * ElementFL_DISC_SDISCOUNT_CARD)
{
Object->ElementFL_DISC_SDISCOUNT_CARD=ElementFL_DISC_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountCardImpl::get_ElementFL_PLAT_SDISCOUNT_CARD(void)
{
return Object->ElementFL_PLAT_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementFL_PLAT_SDISCOUNT_CARD(TFIBSmallIntField * ElementFL_PLAT_SDISCOUNT_CARD)
{
Object->ElementFL_PLAT_SDISCOUNT_CARD=ElementFL_PLAT_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountCardImpl::get_ElementFL_CREDIT_SDISCOUNT_CARD(void)
{
return Object->ElementFL_CREDIT_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementFL_CREDIT_SDISCOUNT_CARD(TFIBSmallIntField * ElementFL_CREDIT_SDISCOUNT_CARD)
{
Object->ElementFL_CREDIT_SDISCOUNT_CARD=ElementFL_CREDIT_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountCardImpl::get_TableID_SDISCOUNT_CARD(void)
{
return Object->TableID_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableID_SDISCOUNT_CARD(TFIBLargeIntField * TableID_SDISCOUNT_CARD)
{
Object->TableID_SDISCOUNT_CARD=TableID_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountCardImpl::get_TableIDKLIENT_SDISCOUNT_CARD(void)
{
return Object->TableIDKLIENT_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableIDKLIENT_SDISCOUNT_CARD(TFIBLargeIntField * TableIDKLIENT_SDISCOUNT_CARD)
{
Object->TableIDKLIENT_SDISCOUNT_CARD=TableIDKLIENT_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountCardImpl::get_TableIDVID_SDISCOUNT_CARD(void)
{
return Object->TableIDVID_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableIDVID_SDISCOUNT_CARD(TFIBLargeIntField * TableIDVID_SDISCOUNT_CARD)
{
Object->TableIDVID_SDISCOUNT_CARD=TableIDVID_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountCardImpl::get_TableIDBASE_SDISCOUNT_CARD(void)
{
return Object->TableIDBASE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableIDBASE_SDISCOUNT_CARD(TFIBLargeIntField * TableIDBASE_SDISCOUNT_CARD)
{
Object->TableIDBASE_SDISCOUNT_CARD=TableIDBASE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountCardImpl::get_TableFL_DISC_SDISCOUNT_CARD(void)
{
return Object->TableFL_DISC_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableFL_DISC_SDISCOUNT_CARD(TFIBSmallIntField * TableFL_DISC_SDISCOUNT_CARD)
{
Object->TableFL_DISC_SDISCOUNT_CARD=TableFL_DISC_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountCardImpl::get_TableFL_PLAT_SDISCOUNT_CARD(void)
{
return Object->TableFL_PLAT_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableFL_PLAT_SDISCOUNT_CARD(TFIBSmallIntField * TableFL_PLAT_SDISCOUNT_CARD)
{
Object->TableFL_PLAT_SDISCOUNT_CARD=TableFL_PLAT_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountCardImpl::get_TableFL_CREDIT_SDISCOUNT_CARD(void)
{
return Object->TableFL_CREDIT_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableFL_CREDIT_SDISCOUNT_CARD(TFIBSmallIntField * TableFL_CREDIT_SDISCOUNT_CARD)
{
Object->TableFL_CREDIT_SDISCOUNT_CARD=TableFL_CREDIT_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountCardImpl::get_TableIDDOG_SDISCOUNT_CARD(void)
{
return Object->TableIDDOG_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableIDDOG_SDISCOUNT_CARD(TFIBLargeIntField * TableIDDOG_SDISCOUNT_CARD)
{
Object->TableIDDOG_SDISCOUNT_CARD=TableIDDOG_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountCardImpl::get_ElementID_SDISCOUNT_CARD(void)
{
return Object->ElementID_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementID_SDISCOUNT_CARD(TFIBLargeIntField * ElementID_SDISCOUNT_CARD)
{
Object->ElementID_SDISCOUNT_CARD=ElementID_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountCardImpl::get_ElementIDKLIENT_SDISCOUNT_CARD(void)
{
return Object->ElementIDKLIENT_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementIDKLIENT_SDISCOUNT_CARD(TFIBLargeIntField * ElementIDKLIENT_SDISCOUNT_CARD)
{
Object->ElementIDKLIENT_SDISCOUNT_CARD=ElementIDKLIENT_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountCardImpl::get_ElementIDVID_SDISCOUNT_CARD(void)
{
return Object->ElementIDVID_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementIDVID_SDISCOUNT_CARD(TFIBLargeIntField * ElementIDVID_SDISCOUNT_CARD)
{
Object->ElementIDVID_SDISCOUNT_CARD=ElementIDVID_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountCardImpl::get_ElementIDBASE_SDISCOUNT_CARD(void)
{
return Object->ElementIDBASE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementIDBASE_SDISCOUNT_CARD(TFIBLargeIntField * ElementIDBASE_SDISCOUNT_CARD)
{
Object->ElementIDBASE_SDISCOUNT_CARD=ElementIDBASE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprDiscountCardImpl::get_ElementIDDOG_SDISCOUNT_CARD(void)
{
return Object->ElementIDDOG_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementIDDOG_SDISCOUNT_CARD(TFIBLargeIntField * ElementIDDOG_SDISCOUNT_CARD)
{
Object->ElementIDDOG_SDISCOUNT_CARD=ElementIDDOG_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountCardImpl::get_TableNAME_SDISCOUNT_CARD(void)
{
return Object->TableNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableNAME_SDISCOUNT_CARD(TFIBWideStringField * TableNAME_SDISCOUNT_CARD)
{
Object->TableNAME_SDISCOUNT_CARD=TableNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountCardImpl::get_TableNAME_SVID_DCARD(void)
{
return Object->TableNAME_SVID_DCARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableNAME_SVID_DCARD(TFIBWideStringField * TableNAME_SVID_DCARD)
{
Object->TableNAME_SVID_DCARD=TableNAME_SVID_DCARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountCardImpl::get_ElementGID_SDISCOUNT_CARD(void)
{
return Object->ElementGID_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementGID_SDISCOUNT_CARD(TFIBWideStringField * ElementGID_SDISCOUNT_CARD)
{
Object->ElementGID_SDISCOUNT_CARD=ElementGID_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountCardImpl::get_ElementNAME_SDISCOUNT_CARD(void)
{
return Object->ElementNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementNAME_SDISCOUNT_CARD(TFIBWideStringField * ElementNAME_SDISCOUNT_CARD)
{
Object->ElementNAME_SDISCOUNT_CARD=ElementNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountCardImpl::get_ElementNAMEKLIENT(void)
{
return Object->ElementNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)
{
Object->ElementNAMEKLIENT=ElementNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountCardImpl::get_ElementNAME_SVID_DCARD(void)
{
return Object->ElementNAME_SVID_DCARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementNAME_SVID_DCARD(TFIBWideStringField * ElementNAME_SVID_DCARD)
{
Object->ElementNAME_SVID_DCARD=ElementNAME_SVID_DCARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountCardImpl::get_ElementNAME_SDOG(void)
{
return Object->ElementNAME_SDOG;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementNAME_SDOG(TFIBWideStringField * ElementNAME_SDOG)
{
Object->ElementNAME_SDOG=ElementNAME_SDOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountCardImpl::get_TableSHCODE_SDISCOUNT_CARD(void)
{
return Object->TableSHCODE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableSHCODE_SDISCOUNT_CARD(TFIBWideStringField * TableSHCODE_SDISCOUNT_CARD)
{
Object->TableSHCODE_SDISCOUNT_CARD=TableSHCODE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountCardImpl::get_ElementSHCODE_SDISCOUNT_CARD(void)
{
return Object->ElementSHCODE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementSHCODE_SDISCOUNT_CARD(TFIBWideStringField * ElementSHCODE_SDISCOUNT_CARD)
{
Object->ElementSHCODE_SDISCOUNT_CARD=ElementSHCODE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDiscountCardImpl::get_TableGID_SDISCOUNT_CARD(void)
{
return Object->TableGID_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableGID_SDISCOUNT_CARD(TFIBWideStringField * TableGID_SDISCOUNT_CARD)
{
Object->TableGID_SDISCOUNT_CARD=TableGID_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountCardImpl::get_TableSINGLE_SDISCOUNT_CARD(void)
{
return Object->TableSINGLE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_TableSINGLE_SDISCOUNT_CARD(TFIBSmallIntField * TableSINGLE_SDISCOUNT_CARD)
{
Object->TableSINGLE_SDISCOUNT_CARD=TableSINGLE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprDiscountCardImpl::get_ElementSINGLE_SDISCOUNT_CARD(void)
{
return Object->ElementSINGLE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_ElementSINGLE_SDISCOUNT_CARD(TFIBSmallIntField * ElementSINGLE_SDISCOUNT_CARD)
{
Object->ElementSINGLE_SDISCOUNT_CARD=ElementSINGLE_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
__int64 TDMSprDiscountCardImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
bool TDMSprDiscountCardImpl::get_elSave(void)
{
return Object->elSave;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::set_elSave(bool elSave)
{
Object->elSave=elSave;
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::OpenTable(__int64 id_klient)
{
return Object->OpenTable(id_klient);
}
//---------------------------------------------------------------
int TDMSprDiscountCardImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprDiscountCardImpl::NewElement(__int64 id_klient)
{
return Object->NewElement(id_klient);
}
//---------------------------------------------------------------
bool TDMSprDiscountCardImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprDiscountCardImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprDiscountCardImpl::PoiskPoCodu(AnsiString code)
{
return Object->PoiskPoCodu( code);
}
//---------------------------------------------------------------
__int64 TDMSprDiscountCardImpl::PoiskPoShCodu(AnsiString sh_code)
{
return Object->PoiskPoShCodu(sh_code);
}
//---------------------------------------------------------------
int TDMSprDiscountCardImpl::GetCodeCard(void)
{
return Object->GetCodeCard();
}
//---------------------------------------------------------------
bool TDMSprDiscountCardImpl::CheckBarCode(__int64 id_card, AnsiString sh)
{
return Object->CheckBarCode(id_card, sh);
}
//---------------------------------------------------------------
bool TDMSprDiscountCardImpl::CheckCode(__int64 id_card, int code)
{
return Object->CheckCode(id_card,code);
}
//---------------------------------------------------------------
