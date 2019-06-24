#include "vcl.h"
#pragma hdrstop


#include "UDMSprNomFindImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprNomFindImpl::TDMSprNomFindImpl()           
{                                            
Object=new TDMSprNomFind(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprNomFindImpl::~TDMSprNomFindImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprNomFindImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprNomFindImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprNomFind)                        
   {                                                                     
   *ppv=static_cast<IDMSprNomFind*> (this);                                
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
int TDMSprNomFindImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprNomFindImpl::kanRelease(void)                                  
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
int  TDMSprNomFindImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprNomFindImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprNomFindImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprNomFindImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprNomFindImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprNomFind
TDataSource * TDMSprNomFindImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomFindImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNomFindImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomFindImpl::get_SpTPrice(void)
{
return Object->SpTPrice;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_SpTPrice(TpFIBDataSet * SpTPrice)
{
Object->SpTPrice=SpTPrice;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomFindImpl::get_TableIDNOM(void)
{
return Object->TableIDNOM;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_TableIDNOM(TFIBLargeIntField * TableIDNOM)
{
Object->TableIDNOM=TableIDNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomFindImpl::get_TableARTNOM(void)
{
return Object->TableARTNOM;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_TableARTNOM(TFIBWideStringField * TableARTNOM)
{
Object->TableARTNOM=TableARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomFindImpl::get_TableCODENOM(void)
{
return Object->TableCODENOM;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_TableCODENOM(TFIBIntegerField * TableCODENOM)
{
Object->TableCODENOM=TableCODENOM;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomFindImpl::get_TableTNOM(void)
{
return Object->TableTNOM;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_TableTNOM(TFIBSmallIntField * TableTNOM)
{
Object->TableTNOM=TableTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomFindImpl::get_TableNAMENOM(void)
{
return Object->TableNAMENOM;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)
{
Object->TableNAMENOM=TableNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomFindImpl::get_TableNAMEED(void)
{
return Object->TableNAMEED;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_TableNAMEED(TFIBWideStringField * TableNAMEED)
{
Object->TableNAMEED=TableNAMEED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomFindImpl::get_TableZNACH_PRICE(void)
{
return Object->TableZNACH_PRICE;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE)
{
Object->TableZNACH_PRICE=TableZNACH_PRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomFindImpl::get_TableIDGRPNOM(void)
{
return Object->TableIDGRPNOM;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_TableIDGRPNOM(TFIBLargeIntField * TableIDGRPNOM)
{
Object->TableIDGRPNOM=TableIDGRPNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomFindImpl::get_TableSUMKOL(void)
{
return Object->TableSUMKOL;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_TableSUMKOL(TFIBBCDField * TableSUMKOL)
{
Object->TableSUMKOL=TableSUMKOL;
}
//---------------------------------------------------------------
TDataSource * TDMSprNomFindImpl::get_DataSourceTPrice(void)
{
return Object->DataSourceTPrice;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_DataSourceTPrice(TDataSource * DataSourceTPrice)
{
Object->DataSourceTPrice=DataSourceTPrice;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomFindImpl::get_SpTPriceID_TPRICE(void)
{
return Object->SpTPriceID_TPRICE;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_SpTPriceID_TPRICE(TFIBLargeIntField * SpTPriceID_TPRICE)
{
Object->SpTPriceID_TPRICE=SpTPriceID_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomFindImpl::get_SpTPriceNAME_TPRICE(void)
{
return Object->SpTPriceNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_SpTPriceNAME_TPRICE(TFIBWideStringField * SpTPriceNAME_TPRICE)
{
Object->SpTPriceNAME_TPRICE=SpTPriceNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomFindImpl::get_TableNAMEGN(void)
{
return Object->TableNAMEGN;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_TableNAMEGN(TFIBWideStringField * TableNAMEGN)
{
Object->TableNAMEGN=TableNAMEGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomFindImpl::get_TableSHED(void)
{
return Object->TableSHED;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_TableSHED(TFIBWideStringField * TableSHED)
{
Object->TableSHED=TableSHED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomFindImpl::get_TableREM_OST(void)
{
return Object->TableREM_OST;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_TableREM_OST(TFIBBCDField * TableREM_OST)
{
Object->TableREM_OST=TableREM_OST;
}
//---------------------------------------------------------------
__int64 TDMSprNomFindImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprNomFindImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMSprNomFindImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
__int64 TDMSprNomFindImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
__int64 TDMSprNomFindImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TDMSprNomFindImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
bool TDMSprNomFindImpl::SetTextQuery(UnicodeString text)
{
return Object->SetTextQuery(text);
}
//---------------------------------------------------------------
bool TDMSprNomFindImpl::SetIntegerParam(UnicodeString name_param, int value_param)
{
return Object->SetIntegerParam(name_param,value_param);
}
//---------------------------------------------------------------
bool TDMSprNomFindImpl::SetInt64Param(UnicodeString name_param, __int64 value_param)
{
return Object->SetInt64Param(name_param, value_param);
}
//---------------------------------------------------------------
bool TDMSprNomFindImpl::SetStringParam(UnicodeString name_param, UnicodeString value_param)
{
return Object->SetStringParam(name_param,value_param);
}
//---------------------------------------------------------------
bool TDMSprNomFindImpl::OpenTableResult(void)
{
return Object->OpenTableResult();
}
//---------------------------------------------------------------
