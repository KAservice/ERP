#include <vcl.h>
#pragma hdrstop


#include "UDMSprPriceImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprPriceImpl::TDMSprPriceImpl()           
{                                            
Object=new TDMSprPrice(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprPriceImpl::~TDMSprPriceImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprPriceImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprPriceImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprPrice)                        
   {                                                                     
   *ppv=static_cast<IDMSprPrice*> (this);                                
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
int TDMSprPriceImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprPriceImpl::kanRelease(void)                                  
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
int  TDMSprPriceImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPriceImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprPriceImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPriceImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprPriceImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprPriceImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprPriceImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPriceImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPriceImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPriceImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPriceImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceImpl::get_TableZNACH_PRICE(void)
{
return Object->TableZNACH_PRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE)
{
Object->TableZNACH_PRICE=TableZNACH_PRICE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceImpl::get_ElementZNACH_PRICE(void)
{
return Object->ElementZNACH_PRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_ElementZNACH_PRICE(TFIBBCDField * ElementZNACH_PRICE)
{
Object->ElementZNACH_PRICE=ElementZNACH_PRICE;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPriceImpl::get_TPrice(void)
{
return Object->TPrice;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_TPrice(TpFIBDataSet * TPrice)
{
Object->TPrice=TPrice;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprPriceImpl::get_TableFL_CHANGE_PRICE(void)
{
return Object->TableFL_CHANGE_PRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_TableFL_CHANGE_PRICE(TFIBSmallIntField * TableFL_CHANGE_PRICE)
{
Object->TableFL_CHANGE_PRICE=TableFL_CHANGE_PRICE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprPriceImpl::get_ElementFL_CHANGE_PRICE(void)
{
return Object->ElementFL_CHANGE_PRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_ElementFL_CHANGE_PRICE(TFIBSmallIntField * ElementFL_CHANGE_PRICE)
{
Object->ElementFL_CHANGE_PRICE=ElementFL_CHANGE_PRICE;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprPriceImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceImpl::get_ElementID_PRICE(void)
{
return Object->ElementID_PRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_ElementID_PRICE(TFIBBCDField * ElementID_PRICE)
{
Object->ElementID_PRICE=ElementID_PRICE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceImpl::get_ElementIDNOM_PRICE(void)
{
return Object->ElementIDNOM_PRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_ElementIDNOM_PRICE(TFIBBCDField * ElementIDNOM_PRICE)
{
Object->ElementIDNOM_PRICE=ElementIDNOM_PRICE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceImpl::get_ElementIDTYPE_PRICE(void)
{
return Object->ElementIDTYPE_PRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_ElementIDTYPE_PRICE(TFIBBCDField * ElementIDTYPE_PRICE)
{
Object->ElementIDTYPE_PRICE=ElementIDTYPE_PRICE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceImpl::get_ElementIDED_SPRICE(void)
{
return Object->ElementIDED_SPRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_ElementIDED_SPRICE(TFIBBCDField * ElementIDED_SPRICE)
{
Object->ElementIDED_SPRICE=ElementIDED_SPRICE;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPriceImpl::get_SpisokEd(void)
{
return Object->SpisokEd;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_SpisokEd(TpFIBDataSet * SpisokEd)
{
Object->SpisokEd=SpisokEd;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPriceImpl::get_SpisokEdKFED(void)
{
return Object->SpisokEdKFED;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_SpisokEdKFED(TFIBBCDField * SpisokEdKFED)
{
Object->SpisokEdKFED=SpisokEdKFED;
}
//---------------------------------------------------------------
TDataSource * TDMSprPriceImpl::get_DataSourceSpisokEd(void)
{
return Object->DataSourceSpisokEd;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_DataSourceSpisokEd(TDataSource * DataSourceSpisokEd)
{
Object->DataSourceSpisokEd=DataSourceSpisokEd;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPriceImpl::get_TPriceID_TPRICE(void)
{
return Object->TPriceID_TPRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_TPriceID_TPRICE(TFIBLargeIntField * TPriceID_TPRICE)
{
Object->TPriceID_TPRICE=TPriceID_TPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPriceImpl::get_TableID_PRICE(void)
{
return Object->TableID_PRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_TableID_PRICE(TFIBLargeIntField * TableID_PRICE)
{
Object->TableID_PRICE=TableID_PRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPriceImpl::get_TableIDNOM_PRICE(void)
{
return Object->TableIDNOM_PRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_TableIDNOM_PRICE(TFIBLargeIntField * TableIDNOM_PRICE)
{
Object->TableIDNOM_PRICE=TableIDNOM_PRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPriceImpl::get_TableIDTYPE_PRICE(void)
{
return Object->TableIDTYPE_PRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_TableIDTYPE_PRICE(TFIBLargeIntField * TableIDTYPE_PRICE)
{
Object->TableIDTYPE_PRICE=TableIDTYPE_PRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPriceImpl::get_TableIDED_SPRICE(void)
{
return Object->TableIDED_SPRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_TableIDED_SPRICE(TFIBLargeIntField * TableIDED_SPRICE)
{
Object->TableIDED_SPRICE=TableIDED_SPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPriceImpl::get_SpisokEdIDED(void)
{
return Object->SpisokEdIDED;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_SpisokEdIDED(TFIBLargeIntField * SpisokEdIDED)
{
Object->SpisokEdIDED=SpisokEdIDED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPriceImpl::get_TableGID_SPRICE(void)
{
return Object->TableGID_SPRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_TableGID_SPRICE(TFIBWideStringField * TableGID_SPRICE)
{
Object->TableGID_SPRICE=TableGID_SPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPriceImpl::get_TableIDBASE_SPRICE(void)
{
return Object->TableIDBASE_SPRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_TableIDBASE_SPRICE(TFIBLargeIntField * TableIDBASE_SPRICE)
{
Object->TableIDBASE_SPRICE=TableIDBASE_SPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPriceImpl::get_TableNAME_TPRICE(void)
{
return Object->TableNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_TableNAME_TPRICE(TFIBWideStringField * TableNAME_TPRICE)
{
Object->TableNAME_TPRICE=TableNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPriceImpl::get_ElementGID_SPRICE(void)
{
return Object->ElementGID_SPRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_ElementGID_SPRICE(TFIBWideStringField * ElementGID_SPRICE)
{
Object->ElementGID_SPRICE=ElementGID_SPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPriceImpl::get_TPriceNAME_TPRICE(void)
{
return Object->TPriceNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_TPriceNAME_TPRICE(TFIBWideStringField * TPriceNAME_TPRICE)
{
Object->TPriceNAME_TPRICE=TPriceNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPriceImpl::get_SpisokEdNAMEED(void)
{
return Object->SpisokEdNAMEED;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_SpisokEdNAMEED(TFIBWideStringField * SpisokEdNAMEED)
{
Object->SpisokEdNAMEED=SpisokEdNAMEED;
}
//---------------------------------------------------------------
TStringField * TDMSprPriceImpl::get_TableNAMETPRICE(void)
{
return Object->TableNAMETPRICE;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_TableNAMETPRICE(TStringField * TableNAMETPRICE)
{
Object->TableNAMETPRICE=TableNAMETPRICE;
}
//---------------------------------------------------------------
__int64 TDMSprPriceImpl::get_IdNom(void)
{
return Object->IdNom;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_IdNom(__int64 IdNom)
{
Object->IdNom=IdNom;
}
//---------------------------------------------------------------
__int64 TDMSprPriceImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
__int64 TDMSprPriceImpl::get_IdBasEd(void)
{
return Object->IdBasEd;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::set_IdBasEd(__int64 IdBasEd)
{
Object->IdBasEd=IdBasEd;
}
//---------------------------------------------------------------
void TDMSprPriceImpl::OpenTable(__int64 IdNom)
{
return Object->OpenTable(IdNom);
}
//---------------------------------------------------------------
bool TDMSprPriceImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMSprPriceImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
int TDMSprPriceImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprPriceImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprPriceImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprPriceImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
__int64 TDMSprPriceImpl::FindElement(__int64 idTypePrice, __int64 idNom)
{
return Object->FindElement(idTypePrice,  idNom);
}
//---------------------------------------------------------------
__int64 TDMSprPriceImpl::FindElementPoEd(__int64 idTypePrice, __int64 idNom, __int64 id_ed)
{
return Object->FindElementPoEd(idTypePrice, idNom, id_ed);
}
//---------------------------------------------------------------
double TDMSprPriceImpl::GetValuePrice(__int64 id_type_price,__int64 id_nom,__int64 id_ed,double kf_ed,__int64 id_bas_ed)
{
return Object->GetValuePrice( id_type_price, id_nom,id_ed, kf_ed, id_bas_ed);
}
//---------------------------------------------------------------
void TDMSprPriceImpl::UpdateSpisokEd(__int64 id_nom)
{
return Object->UpdateSpisokEd( id_nom);
}
//---------------------------------------------------------------
