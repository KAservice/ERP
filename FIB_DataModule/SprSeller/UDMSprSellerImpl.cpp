#include "vcl.h"
#pragma hdrstop


#include "UDMSprSellerImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprSellerImpl::TDMSprSellerImpl()           
{                                            
Object=new TDMSprSeller(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprSellerImpl::~TDMSprSellerImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprSellerImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprSellerImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprSeller)                        
   {                                                                     
   *ppv=static_cast<IDMSprSeller*> (this);                                
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
int TDMSprSellerImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprSellerImpl::kanRelease(void)                                  
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
int  TDMSprSellerImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprSellerImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprSellerImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprSellerImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprSellerImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprSellerImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprSellerImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprSeller
TDataSource * TDMSprSellerImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprSellerImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprSellerImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprSellerImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprSellerImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprSellerImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprSellerImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprSellerImpl::get_TableID_SSELLER(void)
{
return Object->TableID_SSELLER;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_TableID_SSELLER(TFIBLargeIntField * TableID_SSELLER)
{
Object->TableID_SSELLER=TableID_SSELLER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprSellerImpl::get_TableIDBASE_SSELLER(void)
{
return Object->TableIDBASE_SSELLER;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_TableIDBASE_SSELLER(TFIBLargeIntField * TableIDBASE_SSELLER)
{
Object->TableIDBASE_SSELLER=TableIDBASE_SSELLER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSellerImpl::get_TableNAME_SSELLER(void)
{
return Object->TableNAME_SSELLER;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_TableNAME_SSELLER(TFIBWideStringField * TableNAME_SSELLER)
{
Object->TableNAME_SSELLER=TableNAME_SSELLER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSellerImpl::get_TableADR_SSELLER(void)
{
return Object->TableADR_SSELLER;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_TableADR_SSELLER(TFIBWideStringField * TableADR_SSELLER)
{
Object->TableADR_SSELLER=TableADR_SSELLER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSellerImpl::get_TablePHONE_SSELLER(void)
{
return Object->TablePHONE_SSELLER;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_TablePHONE_SSELLER(TFIBWideStringField * TablePHONE_SSELLER)
{
Object->TablePHONE_SSELLER=TablePHONE_SSELLER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprSellerImpl::get_TableIDKLIENT_SSELLER(void)
{
return Object->TableIDKLIENT_SSELLER;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_TableIDKLIENT_SSELLER(TFIBLargeIntField * TableIDKLIENT_SSELLER)
{
Object->TableIDKLIENT_SSELLER=TableIDKLIENT_SSELLER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSellerImpl::get_TableNAME_FOR_PRINT_SSELLER(void)
{
return Object->TableNAME_FOR_PRINT_SSELLER;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_TableNAME_FOR_PRINT_SSELLER(TFIBWideStringField * TableNAME_FOR_PRINT_SSELLER)
{
Object->TableNAME_FOR_PRINT_SSELLER=TableNAME_FOR_PRINT_SSELLER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSellerImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSellerImpl::get_TableINNKLIENT(void)
{
return Object->TableINNKLIENT;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_TableINNKLIENT(TFIBWideStringField * TableINNKLIENT)
{
Object->TableINNKLIENT=TableINNKLIENT;
}
//---------------------------------------------------------------
TIntegerField * TDMSprSellerImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprSellerImpl::get_ElementID_SSELLER(void)
{
return Object->ElementID_SSELLER;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_ElementID_SSELLER(TFIBLargeIntField * ElementID_SSELLER)
{
Object->ElementID_SSELLER=ElementID_SSELLER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprSellerImpl::get_ElementIDBASE_SSELLER(void)
{
return Object->ElementIDBASE_SSELLER;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_ElementIDBASE_SSELLER(TFIBLargeIntField * ElementIDBASE_SSELLER)
{
Object->ElementIDBASE_SSELLER=ElementIDBASE_SSELLER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSellerImpl::get_ElementNAME_SSELLER(void)
{
return Object->ElementNAME_SSELLER;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_ElementNAME_SSELLER(TFIBWideStringField * ElementNAME_SSELLER)
{
Object->ElementNAME_SSELLER=ElementNAME_SSELLER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSellerImpl::get_ElementADR_SSELLER(void)
{
return Object->ElementADR_SSELLER;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_ElementADR_SSELLER(TFIBWideStringField * ElementADR_SSELLER)
{
Object->ElementADR_SSELLER=ElementADR_SSELLER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSellerImpl::get_ElementPHONE_SSELLER(void)
{
return Object->ElementPHONE_SSELLER;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_ElementPHONE_SSELLER(TFIBWideStringField * ElementPHONE_SSELLER)
{
Object->ElementPHONE_SSELLER=ElementPHONE_SSELLER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprSellerImpl::get_ElementIDKLIENT_SSELLER(void)
{
return Object->ElementIDKLIENT_SSELLER;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_ElementIDKLIENT_SSELLER(TFIBLargeIntField * ElementIDKLIENT_SSELLER)
{
Object->ElementIDKLIENT_SSELLER=ElementIDKLIENT_SSELLER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSellerImpl::get_ElementNAME_FOR_PRINT_SSELLER(void)
{
return Object->ElementNAME_FOR_PRINT_SSELLER;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_ElementNAME_FOR_PRINT_SSELLER(TFIBWideStringField * ElementNAME_FOR_PRINT_SSELLER)
{
Object->ElementNAME_FOR_PRINT_SSELLER=ElementNAME_FOR_PRINT_SSELLER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprSellerImpl::get_ElementNAMEKLIENT(void)
{
return Object->ElementNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprSellerImpl::set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)
{
Object->ElementNAMEKLIENT=ElementNAMEKLIENT;
}
//---------------------------------------------------------------
bool TDMSprSellerImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
bool TDMSprSellerImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprSellerImpl::NewElement()
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprSellerImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprSellerImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool TDMSprSellerImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprSellerImpl::GetIdElementPoName(UnicodeString   name)
{
return Object->GetIdElementPoName(name);
}
//---------------------------------------------------------------
int TDMSprSellerImpl::GetIndexInTablePoId(__int64 id_element)
{
return Object->GetIndexInTablePoId(id_element);
}
//---------------------------------------------------------------
__int64 TDMSprSellerImpl::GetIdElementPoGid(UnicodeString gid)
{
return Object->GetIdElementPoGid(gid);
}
//---------------------------------------------------------------
UnicodeString TDMSprSellerImpl::GetGidElementPoId(__int64 id)
{
return Object->GetGidElementPoId(id);
}
//---------------------------------------------------------------
