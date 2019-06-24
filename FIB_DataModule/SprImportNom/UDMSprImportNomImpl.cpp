#include <vcl.h>
#pragma hdrstop


#include "UDMSprImportNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprImportNomImpl::TDMSprImportNomImpl()           
{                                            
Object=new TDMSprImportNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprImportNomImpl::~TDMSprImportNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprImportNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprImportNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprImportNom)                        
   {                                                                     
   *ppv=static_cast<IDMSprImportNom*> (this);                                
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
int TDMSprImportNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprImportNomImpl::kanRelease(void)
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
int  TDMSprImportNomImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprImportNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprImportNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprImportNomImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprImportNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprImportNomImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprImportNomImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprImportNomImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprImportNomImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprImportNomImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprImportNomImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprImportNomImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportNomImpl::get_TableID_SIMPORTNOM(void)
{
return Object->TableID_SIMPORTNOM;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_TableID_SIMPORTNOM(TFIBBCDField * TableID_SIMPORTNOM)
{
Object->TableID_SIMPORTNOM=TableID_SIMPORTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportNomImpl::get_TableIDBASE_SIMPORTNOM(void)
{
return Object->TableIDBASE_SIMPORTNOM;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_TableIDBASE_SIMPORTNOM(TFIBBCDField * TableIDBASE_SIMPORTNOM)
{
Object->TableIDBASE_SIMPORTNOM=TableIDBASE_SIMPORTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportNomImpl::get_TableIDNOM_SIMPORTNOM(void)
{
return Object->TableIDNOM_SIMPORTNOM;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_TableIDNOM_SIMPORTNOM(TFIBBCDField * TableIDNOM_SIMPORTNOM)
{
Object->TableIDNOM_SIMPORTNOM=TableIDNOM_SIMPORTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportNomImpl::get_TableIDKLIENT_SIMPORTNOM(void)
{
return Object->TableIDKLIENT_SIMPORTNOM;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_TableIDKLIENT_SIMPORTNOM(TFIBBCDField * TableIDKLIENT_SIMPORTNOM)
{
Object->TableIDKLIENT_SIMPORTNOM=TableIDKLIENT_SIMPORTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportNomImpl::get_ElementID_SIMPORTNOM(void)
{
return Object->ElementID_SIMPORTNOM;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_ElementID_SIMPORTNOM(TFIBBCDField * ElementID_SIMPORTNOM)
{
Object->ElementID_SIMPORTNOM=ElementID_SIMPORTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportNomImpl::get_ElementIDBASE_SIMPORTNOM(void)
{
return Object->ElementIDBASE_SIMPORTNOM;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_ElementIDBASE_SIMPORTNOM(TFIBBCDField * ElementIDBASE_SIMPORTNOM)
{
Object->ElementIDBASE_SIMPORTNOM=ElementIDBASE_SIMPORTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportNomImpl::get_ElementIDNOM_SIMPORTNOM(void)
{
return Object->ElementIDNOM_SIMPORTNOM;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_ElementIDNOM_SIMPORTNOM(TFIBBCDField * ElementIDNOM_SIMPORTNOM)
{
Object->ElementIDNOM_SIMPORTNOM=ElementIDNOM_SIMPORTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprImportNomImpl::get_ElementIDKLIENT_SIMPORTNOM(void)
{
return Object->ElementIDKLIENT_SIMPORTNOM;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_ElementIDKLIENT_SIMPORTNOM(TFIBBCDField * ElementIDKLIENT_SIMPORTNOM)
{
Object->ElementIDKLIENT_SIMPORTNOM=ElementIDKLIENT_SIMPORTNOM;
}
//---------------------------------------------------------------
TIntegerField * TDMSprImportNomImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportNomImpl::get_TableCODE_SIMPORTNOM(void)
{
return Object->TableCODE_SIMPORTNOM;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_TableCODE_SIMPORTNOM(TFIBWideStringField * TableCODE_SIMPORTNOM)
{
Object->TableCODE_SIMPORTNOM=TableCODE_SIMPORTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportNomImpl::get_TableART_SIMPORTNOM(void)
{
return Object->TableART_SIMPORTNOM;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_TableART_SIMPORTNOM(TFIBWideStringField * TableART_SIMPORTNOM)
{
Object->TableART_SIMPORTNOM=TableART_SIMPORTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportNomImpl::get_TableNAME_SIMPORTNOM(void)
{
return Object->TableNAME_SIMPORTNOM;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_TableNAME_SIMPORTNOM(TFIBWideStringField * TableNAME_SIMPORTNOM)
{
Object->TableNAME_SIMPORTNOM=TableNAME_SIMPORTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportNomImpl::get_ElementCODE_SIMPORTNOM(void)
{
return Object->ElementCODE_SIMPORTNOM;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_ElementCODE_SIMPORTNOM(TFIBWideStringField * ElementCODE_SIMPORTNOM)
{
Object->ElementCODE_SIMPORTNOM=ElementCODE_SIMPORTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportNomImpl::get_ElementART_SIMPORTNOM(void)
{
return Object->ElementART_SIMPORTNOM;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_ElementART_SIMPORTNOM(TFIBWideStringField * ElementART_SIMPORTNOM)
{
Object->ElementART_SIMPORTNOM=ElementART_SIMPORTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportNomImpl::get_ElementNAME_SIMPORTNOM(void)
{
return Object->ElementNAME_SIMPORTNOM;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_ElementNAME_SIMPORTNOM(TFIBWideStringField * ElementNAME_SIMPORTNOM)
{
Object->ElementNAME_SIMPORTNOM=ElementNAME_SIMPORTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprImportNomImpl::get_ElementNAMEKLIENT(void)
{
return Object->ElementNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)
{
Object->ElementNAMEKLIENT=ElementNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprImportNomImpl::OpenTable(__int64 id_nom)
{
return Object->OpenTable(id_nom);
}
//---------------------------------------------------------------
int TDMSprImportNomImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprImportNomImpl::NewElement(__int64 id_nom)
{
return Object->NewElement(id_nom);
}
//---------------------------------------------------------------
bool TDMSprImportNomImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprImportNomImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprImportNomImpl::FindNomPoArtikulu(__int64 id_post, UnicodeString artikul)
{
return Object->FindNomPoArtikulu(id_post, artikul);
}
//---------------------------------------------------------------
__int64 TDMSprImportNomImpl::FindNomPoCodu(__int64 id_post, UnicodeString code)
{
return Object->FindNomPoCodu(id_post, code);
}
//---------------------------------------------------------------
__int64 TDMSprImportNomImpl::FindNomPoName(__int64 id_post, UnicodeString name)
{
return Object->FindNomPoName(id_post,name);
}
//---------------------------------------------------------------
__int64 TDMSprImportNomImpl::FindElementPoArtikulu(__int64 id_post, UnicodeString artikul)
{
return Object->FindElementPoArtikulu(id_post,artikul);
}
//---------------------------------------------------------------
__int64 TDMSprImportNomImpl::FindElementPoCodu(__int64 id_post, UnicodeString code)
{
return Object->FindElementPoCodu(id_post, code);
}
//---------------------------------------------------------------
__int64 TDMSprImportNomImpl::FindElementPoName(__int64 id_post, UnicodeString name)
{
return Object->FindElementPoName(id_post, name);
}
//---------------------------------------------------------------
