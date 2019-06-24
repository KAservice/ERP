#include <vcl.h>
#pragma hdrstop


#include "UDMSprVesNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprVesNomImpl::TDMSprVesNomImpl()           
{                                            
Object=new TDMSprVesNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprVesNomImpl::~TDMSprVesNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprVesNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprVesNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprVesNom)                        
   {                                                                     
   *ppv=static_cast<IDMSprVesNom*> (this);                                
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
int TDMSprVesNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprVesNomImpl::kanRelease(void)                                  
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
int  TDMSprVesNomImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprVesNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprVesNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprVesNomImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprVesNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprVesNomImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprVesNomImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprVesNomImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprVesNomImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprVesNomImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprVesNomImpl::get_TableCODE_SVESNOM(void)
{
return Object->TableCODE_SVESNOM;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_TableCODE_SVESNOM(TFIBIntegerField * TableCODE_SVESNOM)
{
Object->TableCODE_SVESNOM=TableCODE_SVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprVesNomImpl::get_TableZNACH_PRICE(void)
{
return Object->TableZNACH_PRICE;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE)
{
Object->TableZNACH_PRICE=TableZNACH_PRICE;
}
//---------------------------------------------------------------
TIntegerField * TDMSprVesNomImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprVesNomImpl::get_ElementCODE_SVESNOM(void)
{
return Object->ElementCODE_SVESNOM;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_ElementCODE_SVESNOM(TFIBIntegerField * ElementCODE_SVESNOM)
{
Object->ElementCODE_SVESNOM=ElementCODE_SVESNOM;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprVesNomImpl::get_MaxCode(void)
{
return Object->MaxCode;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_MaxCode(TpFIBDataSet * MaxCode)
{
Object->MaxCode=MaxCode;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprVesNomImpl::get_SpTPrice(void)
{
return Object->SpTPrice;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_SpTPrice(TpFIBDataSet * SpTPrice)
{
Object->SpTPrice=SpTPrice;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprVesNomImpl::get_MaxCodeMAXCODE(void)
{
return Object->MaxCodeMAXCODE;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_MaxCodeMAXCODE(TFIBIntegerField * MaxCodeMAXCODE)
{
Object->MaxCodeMAXCODE=MaxCodeMAXCODE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprVesNomImpl::get_SpTPriceID_TPRICE(void)
{
return Object->SpTPriceID_TPRICE;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_SpTPriceID_TPRICE(TFIBBCDField * SpTPriceID_TPRICE)
{
Object->SpTPriceID_TPRICE=SpTPriceID_TPRICE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprVesNomImpl::get_ElementID_SVESNOM(void)
{
return Object->ElementID_SVESNOM;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_ElementID_SVESNOM(TFIBBCDField * ElementID_SVESNOM)
{
Object->ElementID_SVESNOM=ElementID_SVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprVesNomImpl::get_ElementIDSCALE_SVESNOM(void)
{
return Object->ElementIDSCALE_SVESNOM;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_ElementIDSCALE_SVESNOM(TFIBBCDField * ElementIDSCALE_SVESNOM)
{
Object->ElementIDSCALE_SVESNOM=ElementIDSCALE_SVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprVesNomImpl::get_ElementIDNOM_SVESNOM(void)
{
return Object->ElementIDNOM_SVESNOM;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_ElementIDNOM_SVESNOM(TFIBBCDField * ElementIDNOM_SVESNOM)
{
Object->ElementIDNOM_SVESNOM=ElementIDNOM_SVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprVesNomImpl::get_TableID_SVESNOM(void)
{
return Object->TableID_SVESNOM;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_TableID_SVESNOM(TFIBBCDField * TableID_SVESNOM)
{
Object->TableID_SVESNOM=TableID_SVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprVesNomImpl::get_TableIDNOM_SVESNOM(void)
{
return Object->TableIDNOM_SVESNOM;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_TableIDNOM_SVESNOM(TFIBBCDField * TableIDNOM_SVESNOM)
{
Object->TableIDNOM_SVESNOM=TableIDNOM_SVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprVesNomImpl::get_TableIDSCALE_SVESNOM(void)
{
return Object->TableIDSCALE_SVESNOM;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_TableIDSCALE_SVESNOM(TFIBBCDField * TableIDSCALE_SVESNOM)
{
Object->TableIDSCALE_SVESNOM=TableIDSCALE_SVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprVesNomImpl::get_TableIDGRP_SVESNOM(void)
{
return Object->TableIDGRP_SVESNOM;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_TableIDGRP_SVESNOM(TFIBBCDField * TableIDGRP_SVESNOM)
{
Object->TableIDGRP_SVESNOM=TableIDGRP_SVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprVesNomImpl::get_ElementIDGRP_SVESNOM(void)
{
return Object->ElementIDGRP_SVESNOM;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_ElementIDGRP_SVESNOM(TFIBBCDField * ElementIDGRP_SVESNOM)
{
Object->ElementIDGRP_SVESNOM=ElementIDGRP_SVESNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVesNomImpl::get_TableGID_SVESNOM(void)
{
return Object->TableGID_SVESNOM;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_TableGID_SVESNOM(TFIBWideStringField * TableGID_SVESNOM)
{
Object->TableGID_SVESNOM=TableGID_SVESNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprVesNomImpl::get_TableIDBASE_SVESNOM(void)
{
return Object->TableIDBASE_SVESNOM;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_TableIDBASE_SVESNOM(TFIBBCDField * TableIDBASE_SVESNOM)
{
Object->TableIDBASE_SVESNOM=TableIDBASE_SVESNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVesNomImpl::get_TableNAMENOM(void)
{
return Object->TableNAMENOM;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)
{
Object->TableNAMENOM=TableNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVesNomImpl::get_TableNAMEED(void)
{
return Object->TableNAMEED;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_TableNAMEED(TFIBWideStringField * TableNAMEED)
{
Object->TableNAMEED=TableNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVesNomImpl::get_ElementGID_SVESNOM(void)
{
return Object->ElementGID_SVESNOM;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_ElementGID_SVESNOM(TFIBWideStringField * ElementGID_SVESNOM)
{
Object->ElementGID_SVESNOM=ElementGID_SVESNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVesNomImpl::get_SpTPriceNAME_TPRICE(void)
{
return Object->SpTPriceNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_SpTPriceNAME_TPRICE(TFIBWideStringField * SpTPriceNAME_TPRICE)
{
Object->SpTPriceNAME_TPRICE=SpTPriceNAME_TPRICE;
}
//---------------------------------------------------------------
__int64 TDMSprVesNomImpl::get_IdScale(void)
{
return Object->IdScale;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_IdScale(__int64 IdScale)
{
Object->IdScale=IdScale;
}
//---------------------------------------------------------------
__int64 TDMSprVesNomImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprVesNomImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMSprVesNomImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
int TDMSprVesNomImpl::get_NumberAddElement(void)
{
return Object->NumberAddElement;
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::set_NumberAddElement(int NumberAddElement)
{
Object->NumberAddElement=NumberAddElement;
}

//---------------------------------------------------------------
void TDMSprVesNomImpl::OpenTable(__int64 id_scale, __int64 id_grp, __int64 id_type_price, bool all)
{
return Object->OpenTable(id_scale, id_grp, id_type_price,all);
}
//---------------------------------------------------------------
bool TDMSprVesNomImpl::SaveIsmen()
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::CancelIsmen()
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::NewElement(__int64 id_scale, __int64 id_grp)
{
return Object->NewElement(id_scale,id_grp);
}
//---------------------------------------------------------------
bool TDMSprVesNomImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::DeleteElement()
{
return Object->DeleteElement();
}
//---------------------------------------------------------------
bool TDMSprVesNomImpl::InsertElement(__int64 id_scale, __int64 id_grp, __int64 id_nom)
{
return Object->InsertElement(id_scale, id_grp,id_nom);
}
//---------------------------------------------------------------
void TDMSprVesNomImpl::ChancheGrp(__int64 id_new_grp)
{
return Object->ChancheGrp(id_new_grp);
}
//---------------------------------------------------------------
__int64 TDMSprVesNomImpl::FindElementPoScaleAndNom(__int64 id_scale, __int64 id_nom)
{
return Object->FindElementPoScaleAndNom(id_scale, id_nom);
}
//---------------------------------------------------------------
