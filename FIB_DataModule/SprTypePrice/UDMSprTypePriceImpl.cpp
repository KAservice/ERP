#include <vcl.h>
#pragma hdrstop


#include "UDMSprTypePriceImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprTypePriceImpl::TDMSprTypePriceImpl()           
{                                            
Object=new TDMSprTypePrice(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprTypePriceImpl::~TDMSprTypePriceImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprTypePriceImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprTypePriceImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprTypePrice)                        
   {                                                                     
   *ppv=static_cast<IDMSprTypePrice*> (this);                                
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
int TDMSprTypePriceImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprTypePriceImpl::kanRelease(void)                                  
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
int  TDMSprTypePriceImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprTypePriceImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprTypePriceImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprTypePriceImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprTypePriceImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprTypePriceImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprTypePriceImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprTypePriceImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprTypePriceImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprTypePriceImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprTypePriceImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprTypePriceImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprTypePriceImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprTypePriceImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprTypePriceImpl::get_TableID_TPRICE(void)
{
return Object->TableID_TPRICE;
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::set_TableID_TPRICE(TFIBBCDField * TableID_TPRICE)
{
Object->TableID_TPRICE=TableID_TPRICE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprTypePriceImpl::get_ElementID_TPRICE(void)
{
return Object->ElementID_TPRICE;
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::set_ElementID_TPRICE(TFIBBCDField * ElementID_TPRICE)
{
Object->ElementID_TPRICE=ElementID_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprTypePriceImpl::get_TableNAME_TPRICE(void)
{
return Object->TableNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::set_TableNAME_TPRICE(TFIBWideStringField * TableNAME_TPRICE)
{
Object->TableNAME_TPRICE=TableNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprTypePriceImpl::get_TableGID_STPRICE(void)
{
return Object->TableGID_STPRICE;
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::set_TableGID_STPRICE(TFIBWideStringField * TableGID_STPRICE)
{
Object->TableGID_STPRICE=TableGID_STPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprTypePriceImpl::get_ElementNAME_TPRICE(void)
{
return Object->ElementNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::set_ElementNAME_TPRICE(TFIBWideStringField * ElementNAME_TPRICE)
{
Object->ElementNAME_TPRICE=ElementNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprTypePriceImpl::get_ElementGID_STPRICE(void)
{
return Object->ElementGID_STPRICE;
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::set_ElementGID_STPRICE(TFIBWideStringField * ElementGID_STPRICE)
{
Object->ElementGID_STPRICE=ElementGID_STPRICE;
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprTypePriceImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::NewElement()
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprTypePriceImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
void TDMSprTypePriceImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
__int64 TDMSprTypePriceImpl::GetIDTypePrice(String   name)
{
return Object->GetIDTypePrice(name);
}
//---------------------------------------------------------------
int TDMSprTypePriceImpl::GetIndexTypePricePoId(__int64 id_type_price)
{
return Object->GetIndexTypePricePoId(id_type_price);
}
//---------------------------------------------------------------
__int64 TDMSprTypePriceImpl::GetIDElement(String gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
AnsiString TDMSprTypePriceImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
