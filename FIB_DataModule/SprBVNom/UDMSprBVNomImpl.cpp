#include <vcl.h>
#pragma hdrstop


#include "UDMSprBVNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprBVNomImpl::TDMSprBVNomImpl()           
{                                            
Object=new TDMSprBVNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprBVNomImpl::~TDMSprBVNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprBVNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprBVNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprBVNom)                        
   {                                                                     
   *ppv=static_cast<IDMSprBVNom*> (this);                                
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
int TDMSprBVNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprBVNomImpl::kanRelease(void)                                  
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
int  TDMSprBVNomImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprBVNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprBVNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprBVNomImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprBVNomImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprBVNomImpl::get_DataSourcePodr(void)
{
return Object->DataSourcePodr;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_DataSourcePodr(TDataSource * DataSourcePodr)
{
Object->DataSourcePodr=DataSourcePodr;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprBVNomImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprBVNomImpl::get_Podr(void)
{
return Object->Podr;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_Podr(TpFIBDataSet * Podr)
{
Object->Podr=Podr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprBVNomImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprBVNomImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprBVNomImpl::get_TableCODE_BVNOM(void)
{
return Object->TableCODE_BVNOM;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_TableCODE_BVNOM(TFIBIntegerField * TableCODE_BVNOM)
{
Object->TableCODE_BVNOM=TableCODE_BVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBVNomImpl::get_TableZNACH_PRICE(void)
{
return Object->TableZNACH_PRICE;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_TableZNACH_PRICE(TFIBBCDField * TableZNACH_PRICE)
{
Object->TableZNACH_PRICE=TableZNACH_PRICE;
}
//---------------------------------------------------------------
TIntegerField * TDMSprBVNomImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprBVNomImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprBVNomImpl::get_ElementCODE_BVNOM(void)
{
return Object->ElementCODE_BVNOM;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_ElementCODE_BVNOM(TFIBIntegerField * ElementCODE_BVNOM)
{
Object->ElementCODE_BVNOM=ElementCODE_BVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBVNomImpl::get_ElementID_BVNOM(void)
{
return Object->ElementID_BVNOM;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_ElementID_BVNOM(TFIBBCDField * ElementID_BVNOM)
{
Object->ElementID_BVNOM=ElementID_BVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBVNomImpl::get_ElementIDPOD_BVNOM(void)
{
return Object->ElementIDPOD_BVNOM;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_ElementIDPOD_BVNOM(TFIBBCDField * ElementIDPOD_BVNOM)
{
Object->ElementIDPOD_BVNOM=ElementIDPOD_BVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBVNomImpl::get_ElementIDNOM_BVNOM(void)
{
return Object->ElementIDNOM_BVNOM;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_ElementIDNOM_BVNOM(TFIBBCDField * ElementIDNOM_BVNOM)
{
Object->ElementIDNOM_BVNOM=ElementIDNOM_BVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBVNomImpl::get_ElementIDGRP_BVNOM(void)
{
return Object->ElementIDGRP_BVNOM;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_ElementIDGRP_BVNOM(TFIBBCDField * ElementIDGRP_BVNOM)
{
Object->ElementIDGRP_BVNOM=ElementIDGRP_BVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBVNomImpl::get_PodrIDPOD(void)
{
return Object->PodrIDPOD;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_PodrIDPOD(TFIBBCDField * PodrIDPOD)
{
Object->PodrIDPOD=PodrIDPOD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBVNomImpl::get_PodrIDTPRICEPOD(void)
{
return Object->PodrIDTPRICEPOD;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_PodrIDTPRICEPOD(TFIBBCDField * PodrIDTPRICEPOD)
{
Object->PodrIDTPRICEPOD=PodrIDTPRICEPOD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBVNomImpl::get_TableID_BVNOM(void)
{
return Object->TableID_BVNOM;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_TableID_BVNOM(TFIBBCDField * TableID_BVNOM)
{
Object->TableID_BVNOM=TableID_BVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBVNomImpl::get_TableIDPOD_BVNOM(void)
{
return Object->TableIDPOD_BVNOM;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_TableIDPOD_BVNOM(TFIBBCDField * TableIDPOD_BVNOM)
{
Object->TableIDPOD_BVNOM=TableIDPOD_BVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBVNomImpl::get_TableIDNOM_BVNOM(void)
{
return Object->TableIDNOM_BVNOM;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_TableIDNOM_BVNOM(TFIBBCDField * TableIDNOM_BVNOM)
{
Object->TableIDNOM_BVNOM=TableIDNOM_BVNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprBVNomImpl::get_TableIDGRP_BVNOM(void)
{
return Object->TableIDGRP_BVNOM;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_TableIDGRP_BVNOM(TFIBBCDField * TableIDGRP_BVNOM)
{
Object->TableIDGRP_BVNOM=TableIDGRP_BVNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBVNomImpl::get_TableGID_SBVNOM(void)
{
return Object->TableGID_SBVNOM;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_TableGID_SBVNOM(TFIBWideStringField * TableGID_SBVNOM)
{
Object->TableGID_SBVNOM=TableGID_SBVNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBVNomImpl::get_TableNAMENOM(void)
{
return Object->TableNAMENOM;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_TableNAMENOM(TFIBWideStringField * TableNAMENOM)
{
Object->TableNAMENOM=TableNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBVNomImpl::get_TableNAMEED(void)
{
return Object->TableNAMEED;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_TableNAMEED(TFIBWideStringField * TableNAMEED)
{
Object->TableNAMEED=TableNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBVNomImpl::get_PodrNAMEPOD(void)
{
return Object->PodrNAMEPOD;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_PodrNAMEPOD(TFIBWideStringField * PodrNAMEPOD)
{
Object->PodrNAMEPOD=PodrNAMEPOD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBVNomImpl::get_PodrNAME_TPRICE(void)
{
return Object->PodrNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_PodrNAME_TPRICE(TFIBWideStringField * PodrNAME_TPRICE)
{
Object->PodrNAME_TPRICE=PodrNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprBVNomImpl::get_ElementGID_SBVNOM(void)
{
return Object->ElementGID_SBVNOM;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_ElementGID_SBVNOM(TFIBWideStringField * ElementGID_SBVNOM)
{
Object->ElementGID_SBVNOM=ElementGID_SBVNOM;
}
//---------------------------------------------------------------
__int64 TDMSprBVNomImpl::get_IdPod(void)
{
return Object->IdPod;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_IdPod(__int64 IdPod)
{
Object->IdPod=IdPod;
}
//---------------------------------------------------------------
__int64 TDMSprBVNomImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprBVNomImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMSprBVNomImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
__int64 TDMSprBVNomImpl::get_IdNomBV(void)
{
return Object->IdNomBV;
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::set_IdNomBV(__int64 IdNomBV)
{
Object->IdNomBV=IdNomBV;
}

//---------------------------------------------------------------
void TDMSprBVNomImpl::OpenTable(__int64 Pod, __int64 Grp,bool All)
{
return Object->OpenTable(Pod, Grp,All);
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::NewElement(__int64 Pod, __int64 Grp)
{
return Object->NewElement(Pod,  Grp);
}
//---------------------------------------------------------------
bool TDMSprBVNomImpl::OpenElement(__int64 id)
{
return Object->OpenElement( id);
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::InsertElement(__int64 Pod, __int64 Grp, __int64 id_nom)
{
return Object->InsertElement(Pod,Grp, id_nom);
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::DeleteElement()
{
return Object->DeleteElement();
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::SaveIsmen()
{
return Object->SaveIsmen();
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::CancelIsmen()
{
return Object->CancelIsmen();
}
//---------------------------------------------------------------
void TDMSprBVNomImpl::ChancheGrp(__int64 id_new_grp)
{
return Object->ChancheGrp(id_new_grp);
}
//---------------------------------------------------------------
int TDMSprBVNomImpl::FindPoCoduBV(int codeBV)
{
return Object->FindPoCoduBV(codeBV);
}
//---------------------------------------------------------------
bool TDMSprBVNomImpl::FindPoPodrAndNom(__int64 id_podr, __int64 id_nom)
{
return Object->FindPoPodrAndNom(id_podr, id_nom);
}
//---------------------------------------------------------------
