#include <vcl.h>
#pragma hdrstop


#include "UDMSprPriceScheduleImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprPriceScheduleImpl::TDMSprPriceScheduleImpl()           
{                                            
Object=new TDMSprPriceSchedule(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprPriceScheduleImpl::~TDMSprPriceScheduleImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprPriceScheduleImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprPriceSchedule)                        
   {                                                                     
   *ppv=static_cast<IDMSprPriceSchedule*> (this);                                
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
int TDMSprPriceScheduleImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprPriceScheduleImpl::kanRelease(void)
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

//---------------------------------------------------------------
int  TDMSprPriceScheduleImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprPriceScheduleImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprPriceScheduleImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprPriceScheduleImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprPriceScheduleImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprPriceScheduleImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPriceScheduleImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPriceScheduleImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPriceScheduleImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPriceScheduleImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPriceScheduleImpl::get_TPrice(void)
{
return Object->TPrice;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_TPrice(TpFIBDataSet * TPrice)
{
Object->TPrice=TPrice;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprPriceScheduleImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPriceScheduleImpl::get_SpisokEd(void)
{
return Object->SpisokEd;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_SpisokEd(TpFIBDataSet * SpisokEd)
{
Object->SpisokEd=SpisokEd;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceScheduleImpl::get_SpisokEdIDED(void)
{
return Object->SpisokEdIDED;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_SpisokEdIDED(TFIBBCDField * SpisokEdIDED)
{
Object->SpisokEdIDED=SpisokEdIDED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceScheduleImpl::get_SpisokEdKFED(void)
{
return Object->SpisokEdKFED;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_SpisokEdKFED(TFIBBCDField * SpisokEdKFED)
{
Object->SpisokEdKFED=SpisokEdKFED;
}
//---------------------------------------------------------------
TDataSource * TDMSprPriceScheduleImpl::get_DataSourceSpisokEd(void)
{
return Object->DataSourceSpisokEd;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_DataSourceSpisokEd(TDataSource * DataSourceSpisokEd)
{
Object->DataSourceSpisokEd=DataSourceSpisokEd;
}
//---------------------------------------------------------------
TDataSource * TDMSprPriceScheduleImpl::get_DataSourceTypePrice(void)
{
return Object->DataSourceTypePrice;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_DataSourceTypePrice(TDataSource * DataSourceTypePrice)
{
Object->DataSourceTypePrice=DataSourceTypePrice;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceScheduleImpl::get_TableID_SPRICE_SCHEDULE(void)
{
return Object->TableID_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_TableID_SPRICE_SCHEDULE(TFIBBCDField * TableID_SPRICE_SCHEDULE)
{
Object->TableID_SPRICE_SCHEDULE=TableID_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceScheduleImpl::get_TableIDBASE_SPRICE_SCHEDULE(void)
{
return Object->TableIDBASE_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_TableIDBASE_SPRICE_SCHEDULE(TFIBBCDField * TableIDBASE_SPRICE_SCHEDULE)
{
Object->TableIDBASE_SPRICE_SCHEDULE=TableIDBASE_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceScheduleImpl::get_TableIDNOM_SPRICE_SCHEDULE(void)
{
return Object->TableIDNOM_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_TableIDNOM_SPRICE_SCHEDULE(TFIBBCDField * TableIDNOM_SPRICE_SCHEDULE)
{
Object->TableIDNOM_SPRICE_SCHEDULE=TableIDNOM_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceScheduleImpl::get_TableIDTYPE_SPRICE_SCHEDULE(void)
{
return Object->TableIDTYPE_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_TableIDTYPE_SPRICE_SCHEDULE(TFIBBCDField * TableIDTYPE_SPRICE_SCHEDULE)
{
Object->TableIDTYPE_SPRICE_SCHEDULE=TableIDTYPE_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceScheduleImpl::get_TableIDED_SPRICE_SCHEDULE(void)
{
return Object->TableIDED_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_TableIDED_SPRICE_SCHEDULE(TFIBBCDField * TableIDED_SPRICE_SCHEDULE)
{
Object->TableIDED_SPRICE_SCHEDULE=TableIDED_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceScheduleImpl::get_TableVALUE_SPRICE_SCHEDULE(void)
{
return Object->TableVALUE_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_TableVALUE_SPRICE_SCHEDULE(TFIBBCDField * TableVALUE_SPRICE_SCHEDULE)
{
Object->TableVALUE_SPRICE_SCHEDULE=TableVALUE_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprPriceScheduleImpl::get_TablePOS_SPRICE_SCHEDULE(void)
{
return Object->TablePOS_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_TablePOS_SPRICE_SCHEDULE(TFIBDateTimeField * TablePOS_SPRICE_SCHEDULE)
{
Object->TablePOS_SPRICE_SCHEDULE=TablePOS_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceScheduleImpl::get_ElementID_SPRICE_SCHEDULE(void)
{
return Object->ElementID_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_ElementID_SPRICE_SCHEDULE(TFIBBCDField * ElementID_SPRICE_SCHEDULE)
{
Object->ElementID_SPRICE_SCHEDULE=ElementID_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceScheduleImpl::get_ElementIDBASE_SPRICE_SCHEDULE(void)
{
return Object->ElementIDBASE_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_ElementIDBASE_SPRICE_SCHEDULE(TFIBBCDField * ElementIDBASE_SPRICE_SCHEDULE)
{
Object->ElementIDBASE_SPRICE_SCHEDULE=ElementIDBASE_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceScheduleImpl::get_ElementIDNOM_SPRICE_SCHEDULE(void)
{
return Object->ElementIDNOM_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_ElementIDNOM_SPRICE_SCHEDULE(TFIBBCDField * ElementIDNOM_SPRICE_SCHEDULE)
{
Object->ElementIDNOM_SPRICE_SCHEDULE=ElementIDNOM_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceScheduleImpl::get_ElementIDTYPE_SPRICE_SCHEDULE(void)
{
return Object->ElementIDTYPE_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_ElementIDTYPE_SPRICE_SCHEDULE(TFIBBCDField * ElementIDTYPE_SPRICE_SCHEDULE)
{
Object->ElementIDTYPE_SPRICE_SCHEDULE=ElementIDTYPE_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceScheduleImpl::get_ElementIDED_SPRICE_SCHEDULE(void)
{
return Object->ElementIDED_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_ElementIDED_SPRICE_SCHEDULE(TFIBBCDField * ElementIDED_SPRICE_SCHEDULE)
{
Object->ElementIDED_SPRICE_SCHEDULE=ElementIDED_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceScheduleImpl::get_ElementVALUE_SPRICE_SCHEDULE(void)
{
return Object->ElementVALUE_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_ElementVALUE_SPRICE_SCHEDULE(TFIBBCDField * ElementVALUE_SPRICE_SCHEDULE)
{
Object->ElementVALUE_SPRICE_SCHEDULE=ElementVALUE_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprPriceScheduleImpl::get_ElementPOS_SPRICE_SCHEDULE(void)
{
return Object->ElementPOS_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_ElementPOS_SPRICE_SCHEDULE(TFIBDateTimeField * ElementPOS_SPRICE_SCHEDULE)
{
Object->ElementPOS_SPRICE_SCHEDULE=ElementPOS_SPRICE_SCHEDULE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPriceScheduleImpl::get_TableNAME_TPRICE(void)
{
return Object->TableNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_TableNAME_TPRICE(TFIBWideStringField * TableNAME_TPRICE)
{
Object->TableNAME_TPRICE=TableNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPriceScheduleImpl::get_SpisokEdNAMEED(void)
{
return Object->SpisokEdNAMEED;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_SpisokEdNAMEED(TFIBWideStringField * SpisokEdNAMEED)
{
Object->SpisokEdNAMEED=SpisokEdNAMEED;
}
//---------------------------------------------------------------
__int64 TDMSprPriceScheduleImpl::get_IdNom(void)
{
return Object->IdNom;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_IdNom(__int64 IdNom)
{
Object->IdNom=IdNom;
}
//---------------------------------------------------------------
__int64 TDMSprPriceScheduleImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
__int64 TDMSprPriceScheduleImpl::get_IdBasEd(void)
{
return Object->IdBasEd;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::set_IdBasEd(__int64 IdBasEd)
{
Object->IdBasEd=IdBasEd;
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::OpenTable(__int64 id_nom)
{
return Object->OpenTable(id_nom);
}
//---------------------------------------------------------------
bool TDMSprPriceScheduleImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
int TDMSprPriceScheduleImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprPriceScheduleImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TDMSprPriceScheduleImpl::UpdateSpisokEd(__int64 id_nom)
{
return Object->UpdateSpisokEd(id_nom);
}
//---------------------------------------------------------------
double TDMSprPriceScheduleImpl::GetValuePrice(__int64 id_nom,	__int64 id_type_price,__int64 id_ed, TDateTime pos)
{
return Object->GetValuePrice(id_nom,id_type_price,id_ed, pos);
}
//---------------------------------------------------------------
