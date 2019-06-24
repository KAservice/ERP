#include <vcl.h>
#pragma hdrstop


#include "UDMSprNacenkaImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprNacenkaImpl::TDMSprNacenkaImpl()           
{                                            
Object=new TDMSprNacenka(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprNacenkaImpl::~TDMSprNacenkaImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprNacenkaImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprNacenkaImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprNacenka)                        
   {                                                                     
   *ppv=static_cast<IDMSprNacenka*> (this);                                
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
int TDMSprNacenkaImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprNacenkaImpl::kanRelease(void)                                  
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
int  TDMSprNacenkaImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprNacenkaImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprNacenkaImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprNacenkaImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprNacenkaImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprNacenkaImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNacenkaImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNacenkaImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNacenkaImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNacenkaImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNacenkaImpl::get_TPrice(void)
{
return Object->TPrice;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_TPrice(TpFIBDataSet * TPrice)
{
Object->TPrice=TPrice;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNacenkaImpl::get_TableVALUE_SNACENKA(void)
{
return Object->TableVALUE_SNACENKA;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_TableVALUE_SNACENKA(TFIBBCDField * TableVALUE_SNACENKA)
{
Object->TableVALUE_SNACENKA=TableVALUE_SNACENKA;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNacenkaImpl::get_ElementVALUE_SNACENKA(void)
{
return Object->ElementVALUE_SNACENKA;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_ElementVALUE_SNACENKA(TFIBBCDField * ElementVALUE_SNACENKA)
{
Object->ElementVALUE_SNACENKA=ElementVALUE_SNACENKA;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNacenkaImpl::get_TableOKR_SNACENKA(void)
{
return Object->TableOKR_SNACENKA;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_TableOKR_SNACENKA(TFIBIntegerField * TableOKR_SNACENKA)
{
Object->TableOKR_SNACENKA=TableOKR_SNACENKA;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNacenkaImpl::get_ElementOKR_SNACENKA(void)
{
return Object->ElementOKR_SNACENKA;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_ElementOKR_SNACENKA(TFIBIntegerField * ElementOKR_SNACENKA)
{
Object->ElementOKR_SNACENKA=ElementOKR_SNACENKA;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNacenkaImpl::get_TableID_SNACENKA(void)
{
return Object->TableID_SNACENKA;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_TableID_SNACENKA(TFIBBCDField * TableID_SNACENKA)
{
Object->TableID_SNACENKA=TableID_SNACENKA;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNacenkaImpl::get_TableIDGRPNOM_SNACENKA(void)
{
return Object->TableIDGRPNOM_SNACENKA;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_TableIDGRPNOM_SNACENKA(TFIBBCDField * TableIDGRPNOM_SNACENKA)
{
Object->TableIDGRPNOM_SNACENKA=TableIDGRPNOM_SNACENKA;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNacenkaImpl::get_TableIDTPRICE_SNACENKA(void)
{
return Object->TableIDTPRICE_SNACENKA;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_TableIDTPRICE_SNACENKA(TFIBBCDField * TableIDTPRICE_SNACENKA)
{
Object->TableIDTPRICE_SNACENKA=TableIDTPRICE_SNACENKA;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNacenkaImpl::get_ElementID_SNACENKA(void)
{
return Object->ElementID_SNACENKA;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_ElementID_SNACENKA(TFIBBCDField * ElementID_SNACENKA)
{
Object->ElementID_SNACENKA=ElementID_SNACENKA;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNacenkaImpl::get_ElementIDGRPNOM_SNACENKA(void)
{
return Object->ElementIDGRPNOM_SNACENKA;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_ElementIDGRPNOM_SNACENKA(TFIBBCDField * ElementIDGRPNOM_SNACENKA)
{
Object->ElementIDGRPNOM_SNACENKA=ElementIDGRPNOM_SNACENKA;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNacenkaImpl::get_ElementIDTPRICE_SNACENKA(void)
{
return Object->ElementIDTPRICE_SNACENKA;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_ElementIDTPRICE_SNACENKA(TFIBBCDField * ElementIDTPRICE_SNACENKA)
{
Object->ElementIDTPRICE_SNACENKA=ElementIDTPRICE_SNACENKA;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNacenkaImpl::get_TableGID_SNACENKA(void)
{
return Object->TableGID_SNACENKA;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_TableGID_SNACENKA(TFIBWideStringField * TableGID_SNACENKA)
{
Object->TableGID_SNACENKA=TableGID_SNACENKA;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNacenkaImpl::get_TableIDBASE_SNACENKA(void)
{
return Object->TableIDBASE_SNACENKA;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_TableIDBASE_SNACENKA(TFIBBCDField * TableIDBASE_SNACENKA)
{
Object->TableIDBASE_SNACENKA=TableIDBASE_SNACENKA;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNacenkaImpl::get_TableNAME_TPRICE(void)
{
return Object->TableNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_TableNAME_TPRICE(TFIBWideStringField * TableNAME_TPRICE)
{
Object->TableNAME_TPRICE=TableNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNacenkaImpl::get_ElementGID_SNACENKA(void)
{
return Object->ElementGID_SNACENKA;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_ElementGID_SNACENKA(TFIBWideStringField * ElementGID_SNACENKA)
{
Object->ElementGID_SNACENKA=ElementGID_SNACENKA;
}
//---------------------------------------------------------------
__int64 TDMSprNacenkaImpl::get_IdGrpNom(void)
{
return Object->IdGrpNom;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_IdGrpNom(__int64 IdGrpNom)
{
Object->IdGrpNom=IdGrpNom;
}
//---------------------------------------------------------------
__int64 TDMSprNacenkaImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::OpenTable(__int64 id_grp_nom)
{
return Object->OpenTable(id_grp_nom);
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::SaveIsmen(void)
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
int TDMSprNacenkaImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
int TDMSprNacenkaImpl::FindElement(__int64 id_type_price, __int64 id_grp_nom)
{
return Object->FindElement(id_type_price, id_grp_nom);
}
//---------------------------------------------------------------
void TDMSprNacenkaImpl::CancelIsmen(void)
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
