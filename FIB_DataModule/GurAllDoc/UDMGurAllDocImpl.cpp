#include "vcl.h"
#pragma hdrstop


#include "UDMGurAllDocImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMGurAllDocImpl::TDMGurAllDocImpl()           
{                                            
Object=new TDMGurAllDoc(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMGurAllDocImpl::~TDMGurAllDocImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMGurAllDocImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMGurAllDocImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMGurAllDoc)                        
   {                                                                     
   *ppv=static_cast<IDMGurAllDoc*> (this);                                
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
int TDMGurAllDocImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMGurAllDocImpl::kanRelease(void)                                  
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
int  TDMGurAllDocImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMGurAllDocImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMGurAllDocImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMGurAllDocImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMGurAllDocImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMGurAllDoc
TDataSource * TDMGurAllDocImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMGurAllDocImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMGurAllDocImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMGurAllDocImpl::get_TablePRDOC(void)
{
return Object->TablePRDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TablePRDOC(TFIBSmallIntField * TablePRDOC)
{
Object->TablePRDOC=TablePRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurAllDocImpl::get_TableNUMDOC(void)
{
return Object->TableNUMDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableNUMDOC(TFIBIntegerField * TableNUMDOC)
{
Object->TableNUMDOC=TableNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurAllDocImpl::get_TableSUMDOC(void)
{
return Object->TableSUMDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableSUMDOC(TFIBBCDField * TableSUMDOC)
{
Object->TableSUMDOC=TableSUMDOC;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMGurAllDocImpl::get_IBQ(void)
{
return Object->IBQ;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_IBQ(TpFIBDataSet * IBQ)
{
Object->IBQ=IBQ;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMGurAllDocImpl::get_TablePOSDOC(void)
{
return Object->TablePOSDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TablePOSDOC(TFIBDateTimeField * TablePOSDOC)
{
Object->TablePOSDOC=TablePOSDOC;
}
//---------------------------------------------------------------
TpFIBQuery * TDMGurAllDocImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurAllDocImpl::get_TableIDDOC(void)
{
return Object->TableIDDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableIDDOC(TFIBBCDField * TableIDDOC)
{
Object->TableIDDOC=TableIDDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurAllDocImpl::get_TableIDFIRMDOC(void)
{
return Object->TableIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableIDFIRMDOC(TFIBBCDField * TableIDFIRMDOC)
{
Object->TableIDFIRMDOC=TableIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurAllDocImpl::get_TableIDSKLDOC(void)
{
return Object->TableIDSKLDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableIDSKLDOC(TFIBBCDField * TableIDSKLDOC)
{
Object->TableIDSKLDOC=TableIDSKLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurAllDocImpl::get_TableIDKLDOC(void)
{
return Object->TableIDKLDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableIDKLDOC(TFIBBCDField * TableIDKLDOC)
{
Object->TableIDKLDOC=TableIDKLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurAllDocImpl::get_TableIDDOGDOC(void)
{
return Object->TableIDDOGDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableIDDOGDOC(TFIBBCDField * TableIDDOGDOC)
{
Object->TableIDDOGDOC=TableIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurAllDocImpl::get_TableIDUSERDOC(void)
{
return Object->TableIDUSERDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableIDUSERDOC(TFIBBCDField * TableIDUSERDOC)
{
Object->TableIDUSERDOC=TableIDUSERDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurAllDocImpl::get_TableIDDOCOSNDOC(void)
{
return Object->TableIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableIDDOCOSNDOC(TFIBBCDField * TableIDDOCOSNDOC)
{
Object->TableIDDOCOSNDOC=TableIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurAllDocImpl::get_TableIDEXTDOC(void)
{
return Object->TableIDEXTDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableIDEXTDOC(TFIBBCDField * TableIDEXTDOC)
{
Object->TableIDEXTDOC=TableIDEXTDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurAllDocImpl::get_TableIDBASE_GALLDOC(void)
{
return Object->TableIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableIDBASE_GALLDOC(TFIBBCDField * TableIDBASE_GALLDOC)
{
Object->TableIDBASE_GALLDOC=TableIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurAllDocImpl::get_TableIDPROJECT_GALLDOC(void)
{
return Object->TableIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableIDPROJECT_GALLDOC(TFIBBCDField * TableIDPROJECT_GALLDOC)
{
Object->TableIDPROJECT_GALLDOC=TableIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurAllDocImpl::get_TableTDOC(void)
{
return Object->TableTDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableTDOC(TFIBWideStringField * TableTDOC)
{
Object->TableTDOC=TableTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurAllDocImpl::get_TableGID_DOC(void)
{
return Object->TableGID_DOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableGID_DOC(TFIBWideStringField * TableGID_DOC)
{
Object->TableGID_DOC=TableGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurAllDocImpl::get_TablePREFIKSDOC(void)
{
return Object->TablePREFIKSDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TablePREFIKSDOC(TFIBWideStringField * TablePREFIKSDOC)
{
Object->TablePREFIKSDOC=TablePREFIKSDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMGurAllDocImpl::get_TableTYPEEXTDOC(void)
{
return Object->TableTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableTYPEEXTDOC(TFIBIntegerField * TableTYPEEXTDOC)
{
Object->TableTYPEEXTDOC=TableTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurAllDocImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurAllDocImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurAllDocImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurAllDocImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurAllDocImpl::get_TableNAME_SPROJECT(void)
{
return Object->TableNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableNAME_SPROJECT(TFIBWideStringField * TableNAME_SPROJECT)
{
Object->TableNAME_SPROJECT=TableNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurAllDocImpl::get_TablePREFIKS_NUM_GALLDOC(void)
{
return Object->TablePREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TablePREFIKS_NUM_GALLDOC(TFIBWideStringField * TablePREFIKS_NUM_GALLDOC)
{
Object->TablePREFIKS_NUM_GALLDOC=TablePREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurAllDocImpl::get_TableIDBUSINOP_GALLDOC(void)
{
return Object->TableIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableIDBUSINOP_GALLDOC(TFIBBCDField * TableIDBUSINOP_GALLDOC)
{
Object->TableIDBUSINOP_GALLDOC=TableIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurAllDocImpl::get_TableNAME_SINFBASE_OBMEN(void)
{
return Object->TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)
{
Object->TableNAME_SINFBASE_OBMEN=TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TDateTime TDMGurAllDocImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TDMGurAllDocImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
__int64 TDMGurAllDocImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TDMGurAllDocImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
__int64 TDMGurAllDocImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TDMGurAllDocImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
UnicodeString TDMGurAllDocImpl::get_StringTypeDoc(void)
{
return Object->StringTypeDoc;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_StringTypeDoc(UnicodeString StringTypeDoc)
{
Object->StringTypeDoc=StringTypeDoc;
}
//---------------------------------------------------------------
bool TDMGurAllDocImpl::get_OtborVkl(void)
{
return Object->OtborVkl;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_OtborVkl(bool OtborVkl)
{
Object->OtborVkl=OtborVkl;
}
//---------------------------------------------------------------
bool TDMGurAllDocImpl::get_NoCheck(void)
{
return Object->NoCheck;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::set_NoCheck(bool NoCheck)
{
Object->NoCheck=NoCheck;
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
__int64 TDMGurAllDocImpl::FindDocPoIdDog(__int64 iddogovor)
{
return Object->FindDocPoIdDog(iddogovor);
}
//---------------------------------------------------------------
bool TDMGurAllDocImpl::CancelDvRegDoc(AnsiString type_doc, __int64 id_doc)
{
return Object->CancelDvRegDoc(type_doc,id_doc);
}
//---------------------------------------------------------------
bool TDMGurAllDocImpl::DvRegDoc(AnsiString type_doc, __int64 id_doc)
{
return Object->DvRegDoc(type_doc,id_doc);
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::AllCancelDvRegDoc(void)
{
return Object->AllCancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMGurAllDocImpl::AllDvRegDoc(void)
{
return Object->AllDvRegDoc();
}
//---------------------------------------------------------------
