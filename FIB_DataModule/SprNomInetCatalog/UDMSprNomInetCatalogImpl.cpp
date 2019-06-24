#include "vcl.h"
#pragma hdrstop


#include "UDMSprNomInetCatalogImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprNomInetCatalogImpl::TDMSprNomInetCatalogImpl()           
{                                            
Object=new TDMSprNomInetCatalog(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprNomInetCatalogImpl::~TDMSprNomInetCatalogImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprNomInetCatalogImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprNomInetCatalog)                        
   {                                                                     
   *ppv=static_cast<IDMSprNomInetCatalog*> (this);                                
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
int TDMSprNomInetCatalogImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprNomInetCatalogImpl::kanRelease(void)                                  
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
int  TDMSprNomInetCatalogImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprNomInetCatalogImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprNomInetCatalogImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprNomInetCatalogImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprNomInetCatalogImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprNomInetCatalog
TDataSource * TDMSprNomInetCatalogImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomInetCatalogImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNomInetCatalogImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNomInetCatalogImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomInetCatalogImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomInetCatalogImpl::get_TableID_SNOMINETCAT(void)
{
return Object->TableID_SNOMINETCAT;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_TableID_SNOMINETCAT(TFIBLargeIntField * TableID_SNOMINETCAT)
{
Object->TableID_SNOMINETCAT=TableID_SNOMINETCAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomInetCatalogImpl::get_TableIDBASE_SNOMINETCAT(void)
{
return Object->TableIDBASE_SNOMINETCAT;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_TableIDBASE_SNOMINETCAT(TFIBLargeIntField * TableIDBASE_SNOMINETCAT)
{
Object->TableIDBASE_SNOMINETCAT=TableIDBASE_SNOMINETCAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomInetCatalogImpl::get_TableGID_SNOMINETCAT(void)
{
return Object->TableGID_SNOMINETCAT;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_TableGID_SNOMINETCAT(TFIBWideStringField * TableGID_SNOMINETCAT)
{
Object->TableGID_SNOMINETCAT=TableGID_SNOMINETCAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomInetCatalogImpl::get_TableIDINETCAT_SNOMINETCAT(void)
{
return Object->TableIDINETCAT_SNOMINETCAT;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_TableIDINETCAT_SNOMINETCAT(TFIBLargeIntField * TableIDINETCAT_SNOMINETCAT)
{
Object->TableIDINETCAT_SNOMINETCAT=TableIDINETCAT_SNOMINETCAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomInetCatalogImpl::get_TableIDGRP_SNOMINETCAT(void)
{
return Object->TableIDGRP_SNOMINETCAT;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_TableIDGRP_SNOMINETCAT(TFIBLargeIntField * TableIDGRP_SNOMINETCAT)
{
Object->TableIDGRP_SNOMINETCAT=TableIDGRP_SNOMINETCAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomInetCatalogImpl::get_TableIDNOM_SNOMINETCAT(void)
{
return Object->TableIDNOM_SNOMINETCAT;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_TableIDNOM_SNOMINETCAT(TFIBLargeIntField * TableIDNOM_SNOMINETCAT)
{
Object->TableIDNOM_SNOMINETCAT=TableIDNOM_SNOMINETCAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomInetCatalogImpl::get_TableNAMENOM(void)
{
return Object->TableNAMENOM;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)
{
Object->TableNAMENOM=TableNAMENOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomInetCatalogImpl::get_TableZNACH_PRICE(void)
{
return Object->TableZNACH_PRICE;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE)
{
Object->TableZNACH_PRICE=TableZNACH_PRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomInetCatalogImpl::get_TableNAMEED(void)
{
return Object->TableNAMEED;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_TableNAMEED(TFIBWideStringField * TableNAMEED)
{
Object->TableNAMEED=TableNAMEED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomInetCatalogImpl::get_ElementID_SNOMINETCAT(void)
{
return Object->ElementID_SNOMINETCAT;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_ElementID_SNOMINETCAT(TFIBLargeIntField * ElementID_SNOMINETCAT)
{
Object->ElementID_SNOMINETCAT=ElementID_SNOMINETCAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomInetCatalogImpl::get_ElementIDBASE_SNOMINETCAT(void)
{
return Object->ElementIDBASE_SNOMINETCAT;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_ElementIDBASE_SNOMINETCAT(TFIBLargeIntField * ElementIDBASE_SNOMINETCAT)
{
Object->ElementIDBASE_SNOMINETCAT=ElementIDBASE_SNOMINETCAT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomInetCatalogImpl::get_ElementGID_SNOMINETCAT(void)
{
return Object->ElementGID_SNOMINETCAT;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_ElementGID_SNOMINETCAT(TFIBWideStringField * ElementGID_SNOMINETCAT)
{
Object->ElementGID_SNOMINETCAT=ElementGID_SNOMINETCAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomInetCatalogImpl::get_ElementIDINETCAT_SNOMINETCAT(void)
{
return Object->ElementIDINETCAT_SNOMINETCAT;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_ElementIDINETCAT_SNOMINETCAT(TFIBLargeIntField * ElementIDINETCAT_SNOMINETCAT)
{
Object->ElementIDINETCAT_SNOMINETCAT=ElementIDINETCAT_SNOMINETCAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomInetCatalogImpl::get_ElementIDGRP_SNOMINETCAT(void)
{
return Object->ElementIDGRP_SNOMINETCAT;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_ElementIDGRP_SNOMINETCAT(TFIBLargeIntField * ElementIDGRP_SNOMINETCAT)
{
Object->ElementIDGRP_SNOMINETCAT=ElementIDGRP_SNOMINETCAT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomInetCatalogImpl::get_ElementIDNOM_SNOMINETCAT(void)
{
return Object->ElementIDNOM_SNOMINETCAT;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_ElementIDNOM_SNOMINETCAT(TFIBLargeIntField * ElementIDNOM_SNOMINETCAT)
{
Object->ElementIDNOM_SNOMINETCAT=ElementIDNOM_SNOMINETCAT;
}
//---------------------------------------------------------------
TIntegerField * TDMSprNomInetCatalogImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomInetCatalogImpl::get_TableCODENOM(void)
{
return Object->TableCODENOM;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_TableCODENOM(TFIBIntegerField * TableCODENOM)
{
Object->TableCODENOM=TableCODENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomInetCatalogImpl::get_TableARTNOM(void)
{
return Object->TableARTNOM;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_TableARTNOM(TFIBWideStringField * TableARTNOM)
{
Object->TableARTNOM=TableARTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomInetCatalogImpl::get_TableSHED(void)
{
return Object->TableSHED;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_TableSHED(TFIBWideStringField * TableSHED)
{
Object->TableSHED=TableSHED;
}
//---------------------------------------------------------------
__int64 TDMSprNomInetCatalogImpl::get_IdInetCatalog(void)
{
return Object->IdInetCatalog;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_IdInetCatalog(__int64 IdInetCatalog)
{
Object->IdInetCatalog=IdInetCatalog;
}
//---------------------------------------------------------------
__int64 TDMSprNomInetCatalogImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprNomInetCatalogImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMSprNomInetCatalogImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::OpenTable(__int64 id_inet_catalog, __int64 id_grp,bool all)
{
return Object->OpenTable(id_inet_catalog, id_grp,all);
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::NewElement(__int64 id_inet_catalog, __int64 id_grp)
{
return Object->NewElement(id_inet_catalog, id_grp);
}
//---------------------------------------------------------------
bool TDMSprNomInetCatalogImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::InsertElement(__int64 id_inet_catalog, __int64 id_grp, __int64 id_nom)
{
return Object->InsertElement(id_inet_catalog,id_grp,id_nom);
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::DeleteElement()
{
return Object->DeleteElement();
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::SaveIsmen()
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::CancelIsmen()
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
void TDMSprNomInetCatalogImpl::ChancheGrp(__int64 id_new_grp)
{
return Object->ChancheGrp(id_new_grp);
}
//---------------------------------------------------------------
bool TDMSprNomInetCatalogImpl::FindPoInetCatalogAndNom(__int64 id_inet_catalog, __int64 id_nom)
{
return Object->FindPoInetCatalogAndNom(id_inet_catalog,id_nom);
}
//---------------------------------------------------------------
bool TDMSprNomInetCatalogImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprNomInetCatalogImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
