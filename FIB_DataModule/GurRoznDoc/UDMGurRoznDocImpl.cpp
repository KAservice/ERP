#include "vcl.h"
#pragma hdrstop


#include "UDMGurRoznDocImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMGurRoznDocImpl::TDMGurRoznDocImpl()           
{                                            
Object=new TDMGurRoznDoc(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMGurRoznDocImpl::~TDMGurRoznDocImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMGurRoznDocImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMGurRoznDocImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMGurRoznDoc)                        
   {                                                                     
   *ppv=static_cast<IDMGurRoznDoc*> (this);                                
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
int TDMGurRoznDocImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMGurRoznDocImpl::kanRelease(void)                                  
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
int  TDMGurRoznDocImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMGurRoznDocImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMGurRoznDocImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMGurRoznDocImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMGurRoznDocImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMGurRoznDoc
TDataSource * TDMGurRoznDocImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMGurRoznDocImpl::get_IBQ(void)
{
return Object->IBQ;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_IBQ(TpFIBDataSet * IBQ)
{
Object->IBQ=IBQ;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMGurRoznDocImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMGurRoznDocImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMGurRoznDocImpl::get_TablePOSDOC(void)
{
return Object->TablePOSDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TablePOSDOC(TFIBDateTimeField * TablePOSDOC)
{
Object->TablePOSDOC=TablePOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMGurRoznDocImpl::get_TablePRDOC(void)
{
return Object->TablePRDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TablePRDOC(TFIBSmallIntField * TablePRDOC)
{
Object->TablePRDOC=TablePRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurRoznDocImpl::get_TableNUMDOC(void)
{
return Object->TableNUMDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableNUMDOC(TFIBIntegerField * TableNUMDOC)
{
Object->TableNUMDOC=TableNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurRoznDocImpl::get_TableSUMDOC(void)
{
return Object->TableSUMDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableSUMDOC(TFIBBCDField * TableSUMDOC)
{
Object->TableSUMDOC=TableSUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurRoznDocImpl::get_TableIDDOC(void)
{
return Object->TableIDDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableIDDOC(TFIBBCDField * TableIDDOC)
{
Object->TableIDDOC=TableIDDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurRoznDocImpl::get_TableIDFIRMDOC(void)
{
return Object->TableIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableIDFIRMDOC(TFIBBCDField * TableIDFIRMDOC)
{
Object->TableIDFIRMDOC=TableIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurRoznDocImpl::get_TableIDSKLDOC(void)
{
return Object->TableIDSKLDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableIDSKLDOC(TFIBBCDField * TableIDSKLDOC)
{
Object->TableIDSKLDOC=TableIDSKLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurRoznDocImpl::get_TableIDKLDOC(void)
{
return Object->TableIDKLDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableIDKLDOC(TFIBBCDField * TableIDKLDOC)
{
Object->TableIDKLDOC=TableIDKLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurRoznDocImpl::get_TableIDDOGDOC(void)
{
return Object->TableIDDOGDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableIDDOGDOC(TFIBBCDField * TableIDDOGDOC)
{
Object->TableIDDOGDOC=TableIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurRoznDocImpl::get_TableIDUSERDOC(void)
{
return Object->TableIDUSERDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableIDUSERDOC(TFIBBCDField * TableIDUSERDOC)
{
Object->TableIDUSERDOC=TableIDUSERDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurRoznDocImpl::get_TableIDDOCOSNDOC(void)
{
return Object->TableIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableIDDOCOSNDOC(TFIBBCDField * TableIDDOCOSNDOC)
{
Object->TableIDDOCOSNDOC=TableIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurRoznDocImpl::get_TableIDEXTDOC(void)
{
return Object->TableIDEXTDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableIDEXTDOC(TFIBBCDField * TableIDEXTDOC)
{
Object->TableIDEXTDOC=TableIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurRoznDocImpl::get_TableTYPEEXTDOC(void)
{
return Object->TableTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableTYPEEXTDOC(TFIBIntegerField * TableTYPEEXTDOC)
{
Object->TableTYPEEXTDOC=TableTYPEEXTDOC;
}
//---------------------------------------------------------------
TpFIBQuery * TDMGurRoznDocImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurRoznDocImpl::get_TableIDBASE_GALLDOC(void)
{
return Object->TableIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableIDBASE_GALLDOC(TFIBBCDField * TableIDBASE_GALLDOC)
{
Object->TableIDBASE_GALLDOC=TableIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurRoznDocImpl::get_TableTDOC(void)
{
return Object->TableTDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableTDOC(TFIBWideStringField * TableTDOC)
{
Object->TableTDOC=TableTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurRoznDocImpl::get_TableGID_DOC(void)
{
return Object->TableGID_DOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableGID_DOC(TFIBWideStringField * TableGID_DOC)
{
Object->TableGID_DOC=TableGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurRoznDocImpl::get_TablePREFIKSDOC(void)
{
return Object->TablePREFIKSDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TablePREFIKSDOC(TFIBWideStringField * TablePREFIKSDOC)
{
Object->TablePREFIKSDOC=TablePREFIKSDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurRoznDocImpl::get_TableIDPROJECT_GALLDOC(void)
{
return Object->TableIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableIDPROJECT_GALLDOC(TFIBBCDField * TableIDPROJECT_GALLDOC)
{
Object->TableIDPROJECT_GALLDOC=TableIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurRoznDocImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurRoznDocImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurRoznDocImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurRoznDocImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
__int64 TDMGurRoznDocImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TDMGurRoznDocImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
__int64 TDMGurRoznDocImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TDMGurRoznDocImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
UnicodeString TDMGurRoznDocImpl::get_StringTypeDoc(void)
{
return Object->StringTypeDoc;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_StringTypeDoc(UnicodeString StringTypeDoc)
{
Object->StringTypeDoc=StringTypeDoc;
}
//---------------------------------------------------------------
UnicodeString TDMGurRoznDocImpl::get_StringFullTypeDoc(void)
{
return Object->StringFullTypeDoc;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_StringFullTypeDoc(UnicodeString StringFullTypeDoc)
{
Object->StringFullTypeDoc=StringFullTypeDoc;
}
//---------------------------------------------------------------
bool TDMGurRoznDocImpl::get_OtborVkl(void)
{
return Object->OtborVkl;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_OtborVkl(bool OtborVkl)
{
Object->OtborVkl=OtborVkl;
}
//---------------------------------------------------------------
bool TDMGurRoznDocImpl::get_OtborPoKlient(void)
{
return Object->OtborPoKlient;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_OtborPoKlient(bool OtborPoKlient)
{
Object->OtborPoKlient=OtborPoKlient;
}
//---------------------------------------------------------------
bool TDMGurRoznDocImpl::get_OtborPoFirm(void)
{
return Object->OtborPoFirm;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_OtborPoFirm(bool OtborPoFirm)
{
Object->OtborPoFirm=OtborPoFirm;
}
//---------------------------------------------------------------
bool TDMGurRoznDocImpl::get_OtborPoSklad(void)
{
return Object->OtborPoSklad;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_OtborPoSklad(bool OtborPoSklad)
{
Object->OtborPoSklad=OtborPoSklad;
}
//---------------------------------------------------------------
bool TDMGurRoznDocImpl::get_OtborPoTypeDoc(void)
{
return Object->OtborPoTypeDoc;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_OtborPoTypeDoc(bool OtborPoTypeDoc)
{
Object->OtborPoTypeDoc=OtborPoTypeDoc;
}
//---------------------------------------------------------------
TDateTime TDMGurRoznDocImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TDMGurRoznDocImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
__int64 TDMGurRoznDocImpl::get_IdBase(void)
{
return Object->IdBase;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::set_IdBase(__int64 IdBase)
{
Object->IdBase=IdBase;
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TDMGurRoznDocImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
int TDMGurRoznDocImpl::FindDocPoIdDog(__int64 iddogovor)
{
return Object->FindDocPoIdDog(iddogovor);
}
//---------------------------------------------------------------
