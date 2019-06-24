#include <vcl.h>
#pragma hdrstop


#include "UDMSprEdImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprEdImpl::TDMSprEdImpl()           
{                                            
Object=new TDMSprEd(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprEdImpl::~TDMSprEdImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprEdImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprEdImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprEd)                        
   {                                                                     
   *ppv=static_cast<IDMSprEd*> (this);                                
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
int TDMSprEdImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprEdImpl::kanRelease(void)
{                                                                      
if (--NumRefs==0)                                                     
   {                                                                  
   delete this;
   return 0;
   }                                                                  
return -1;
}                                                                     
//---------------------------------------------------------------

//IMainInterface
//---------------------------------------------------------------
int  TDMSprEdImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprEdImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprEdImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprEdImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprEdImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprEdImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprEdImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprEdImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprEdImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprEdImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprEdImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprEdImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprEdImpl::get_TableKFED(void)
{
return Object->TableKFED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_TableKFED(TFIBBCDField * TableKFED)
{
Object->TableKFED=TableKFED;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprEdImpl::get_TableTSHED(void)
{
return Object->TableTSHED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_TableTSHED(TFIBIntegerField * TableTSHED)
{
Object->TableTSHED=TableTSHED;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprEdImpl::get_TableNEISPED(void)
{
return Object->TableNEISPED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_TableNEISPED(TFIBSmallIntField * TableNEISPED)
{
Object->TableNEISPED=TableNEISPED;
}
//---------------------------------------------------------------
TIntegerField * TDMSprEdImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprEdImpl::get_ElementKFED(void)
{
return Object->ElementKFED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_ElementKFED(TFIBBCDField * ElementKFED)
{
Object->ElementKFED=ElementKFED;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprEdImpl::get_ElementTSHED(void)
{
return Object->ElementTSHED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_ElementTSHED(TFIBIntegerField * ElementTSHED)
{
Object->ElementTSHED=ElementTSHED;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprEdImpl::get_ElementNEISPED(void)
{
return Object->ElementNEISPED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_ElementNEISPED(TFIBSmallIntField * ElementNEISPED)
{
Object->ElementNEISPED=ElementNEISPED;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprEdImpl::get_OKEI(void)
{
return Object->OKEI;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_OKEI(TpFIBDataSet * OKEI)
{
Object->OKEI=OKEI;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprEdImpl::get_OKEICODEOKEI(void)
{
return Object->OKEICODEOKEI;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_OKEICODEOKEI(TFIBIntegerField * OKEICODEOKEI)
{
Object->OKEICODEOKEI=OKEICODEOKEI;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprEdImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprEdImpl::get_ElementIDED(void)
{
return Object->ElementIDED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_ElementIDED(TFIBBCDField * ElementIDED)
{
Object->ElementIDED=ElementIDED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprEdImpl::get_ElementIDNOMED(void)
{
return Object->ElementIDNOMED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_ElementIDNOMED(TFIBBCDField * ElementIDNOMED)
{
Object->ElementIDNOMED=ElementIDNOMED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprEdImpl::get_ElementIDOKEIED(void)
{
return Object->ElementIDOKEIED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_ElementIDOKEIED(TFIBBCDField * ElementIDOKEIED)
{
Object->ElementIDOKEIED=ElementIDOKEIED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprEdImpl::get_OKEIIDOKEI(void)
{
return Object->OKEIIDOKEI;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_OKEIIDOKEI(TFIBBCDField * OKEIIDOKEI)
{
Object->OKEIIDOKEI=OKEIIDOKEI;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprEdImpl::get_TableCODE_SED(void)
{
return Object->TableCODE_SED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_TableCODE_SED(TFIBIntegerField * TableCODE_SED)
{
Object->TableCODE_SED=TableCODE_SED;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprEdImpl::get_ElementCODE_SED(void)
{
return Object->ElementCODE_SED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_ElementCODE_SED(TFIBIntegerField * ElementCODE_SED)
{
Object->ElementCODE_SED=ElementCODE_SED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprEdImpl::get_TableKF2_SED(void)
{
return Object->TableKF2_SED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_TableKF2_SED(TFIBBCDField * TableKF2_SED)
{
Object->TableKF2_SED=TableKF2_SED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprEdImpl::get_TableVES_SED(void)
{
return Object->TableVES_SED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_TableVES_SED(TFIBBCDField * TableVES_SED)
{
Object->TableVES_SED=TableVES_SED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprEdImpl::get_ElementKF2_SED(void)
{
return Object->ElementKF2_SED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_ElementKF2_SED(TFIBBCDField * ElementKF2_SED)
{
Object->ElementKF2_SED=ElementKF2_SED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprEdImpl::get_ElementVES_SED(void)
{
return Object->ElementVES_SED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_ElementVES_SED(TFIBBCDField * ElementVES_SED)
{
Object->ElementVES_SED=ElementVES_SED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprEdImpl::get_TableIDED(void)
{
return Object->TableIDED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_TableIDED(TFIBLargeIntField * TableIDED)
{
Object->TableIDED=TableIDED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprEdImpl::get_TableIDNOMED(void)
{
return Object->TableIDNOMED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_TableIDNOMED(TFIBLargeIntField * TableIDNOMED)
{
Object->TableIDNOMED=TableIDNOMED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprEdImpl::get_TableIDOKEIED(void)
{
return Object->TableIDOKEIED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_TableIDOKEIED(TFIBLargeIntField * TableIDOKEIED)
{
Object->TableIDOKEIED=TableIDOKEIED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprEdImpl::get_TableNAMEED(void)
{
return Object->TableNAMEED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_TableNAMEED(TFIBWideStringField * TableNAMEED)
{
Object->TableNAMEED=TableNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprEdImpl::get_TableSHED(void)
{
return Object->TableSHED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_TableSHED(TFIBWideStringField * TableSHED)
{
Object->TableSHED=TableSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprEdImpl::get_TableGID_SED(void)
{
return Object->TableGID_SED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_TableGID_SED(TFIBWideStringField * TableGID_SED)
{
Object->TableGID_SED=TableGID_SED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprEdImpl::get_ElementNAMEED(void)
{
return Object->ElementNAMEED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_ElementNAMEED(TFIBWideStringField * ElementNAMEED)
{
Object->ElementNAMEED=ElementNAMEED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprEdImpl::get_ElementSHED(void)
{
return Object->ElementSHED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_ElementSHED(TFIBWideStringField * ElementSHED)
{
Object->ElementSHED=ElementSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprEdImpl::get_ElementGID_SED(void)
{
return Object->ElementGID_SED;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_ElementGID_SED(TFIBWideStringField * ElementGID_SED)
{
Object->ElementGID_SED=ElementGID_SED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprEdImpl::get_OKEINAMEOKEI(void)
{
return Object->OKEINAMEOKEI;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_OKEINAMEOKEI(TFIBWideStringField * OKEINAMEOKEI)
{
Object->OKEINAMEOKEI=OKEINAMEOKEI;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprEdImpl::get_ElementNAMEOKEI(void)
{
return Object->ElementNAMEOKEI;
}
//---------------------------------------------------------------
void TDMSprEdImpl::set_ElementNAMEOKEI(TFIBWideStringField * ElementNAMEOKEI)
{
Object->ElementNAMEOKEI=ElementNAMEOKEI;
}
//---------------------------------------------------------------
void TDMSprEdImpl::OpenTable(__int64 IdNom)
{
return Object->OpenTable(IdNom);
}
//---------------------------------------------------------------
int TDMSprEdImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);;
}
//---------------------------------------------------------------
bool TDMSprEdImpl::NewElement(__int64 IdNom)
{
return Object->NewElement(IdNom);
}
//---------------------------------------------------------------
bool TDMSprEdImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprEdImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
void TDMSprEdImpl::NewShtrihCod(void)
{
return Object->NewShtrihCod();
}
//---------------------------------------------------------------
__int64 TDMSprEdImpl::FindEdPoSh(String ShtrihCod)
{
return Object->FindEdPoSh(ShtrihCod);
}
//---------------------------------------------------------------
__int64 TDMSprEdImpl::FindEdPoCodu(int code)
{
return Object->FindEdPoCodu(code);
}
//---------------------------------------------------------------
__int64 TDMSprEdImpl::GetIDElement(String gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
AnsiString TDMSprEdImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprEdImpl::GetIdNomPoShtrihCodu(AnsiString shtrih_cod)
{
return Object->GetIdNomPoShtrihCodu(shtrih_cod);
}
//---------------------------------------------------------------
bool TDMSprEdImpl::CheckBarCode(__int64 id_ed, AnsiString sh)
{
return Object->CheckBarCode( id_ed, sh);
}
//---------------------------------------------------------------
bool TDMSprEdImpl::CheckCode(__int64 id_ed, int code)
{
return Object->CheckCode(id_ed, code);
}
//---------------------------------------------------------------
int TDMSprEdImpl::GetCodeEd(void)
{
return Object->GetCodeEd();
}
//---------------------------------------------------------------
