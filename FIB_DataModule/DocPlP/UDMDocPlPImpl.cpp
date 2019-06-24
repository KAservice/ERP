#include "vcl.h"
#pragma hdrstop


#include "UDMDocPlPImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocPlPImpl::TDMDocPlPImpl()           
{                                            
Object=new TDMDocPLP(Application);
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocPlPImpl::~TDMDocPlPImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocPlPImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocPlPImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocPlP)                        
   {                                                                     
   *ppv=static_cast<IDMDocPlP*> (this);                                
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
int TDMDocPlPImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocPlPImpl::kanRelease(void)                                  
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
int  TDMDocPlPImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocPlPImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocPlPImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocPlPImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocPlPImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocPlPImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocPlPImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocPlP
TDataSource * TDMDocPlPImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocPlPImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPlPImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPlPImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocPlPImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocPlPImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocPlPImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocPlPImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPlPImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPlPImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocPlPImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocPlPImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocPlPImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocPlPImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPlPImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPlPImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPlPImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPlPImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPlPImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPlPImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPlPImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPlPImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPlPImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPlPImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPlPImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPlPImpl::get_DocIDPLP(void)
{
return Object->DocIDPLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocIDPLP(TFIBLargeIntField * DocIDPLP)
{
Object->DocIDPLP=DocIDPLP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPlPImpl::get_DocIDDOCPLP(void)
{
return Object->DocIDDOCPLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocIDDOCPLP(TFIBLargeIntField * DocIDDOCPLP)
{
Object->DocIDDOCPLP=DocIDDOCPLP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPlPImpl::get_DocIDBSCHPLP(void)
{
return Object->DocIDBSCHPLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocIDBSCHPLP(TFIBLargeIntField * DocIDBSCHPLP)
{
Object->DocIDBSCHPLP=DocIDBSCHPLP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPlPImpl::get_DocIDRSCHPLP(void)
{
return Object->DocIDRSCHPLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocIDRSCHPLP(TFIBLargeIntField * DocIDRSCHPLP)
{
Object->DocIDRSCHPLP=DocIDRSCHPLP;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPlPImpl::get_DocVIDPLP(void)
{
return Object->DocVIDPLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocVIDPLP(TFIBIntegerField * DocVIDPLP)
{
Object->DocVIDPLP=DocVIDPLP;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPlPImpl::get_DocOCHPLP(void)
{
return Object->DocOCHPLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocOCHPLP(TFIBIntegerField * DocOCHPLP)
{
Object->DocOCHPLP=DocOCHPLP;
}
//---------------------------------------------------------------
TFIBDateField * TDMDocPlPImpl::get_DocSROKPLP(void)
{
return Object->DocSROKPLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocSROKPLP(TFIBDateField * DocSROKPLP)
{
Object->DocSROKPLP=DocSROKPLP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocNASNPLP(void)
{
return Object->DocNASNPLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocNASNPLP(TFIBWideStringField * DocNASNPLP)
{
Object->DocNASNPLP=DocNASNPLP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocGID_DPLP(void)
{
return Object->DocGID_DPLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocGID_DPLP(TFIBWideStringField * DocGID_DPLP)
{
Object->DocGID_DPLP=DocGID_DPLP;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPlPImpl::get_DocADDKDRPLP(void)
{
return Object->DocADDKDRPLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocADDKDRPLP(TFIBIntegerField * DocADDKDRPLP)
{
Object->DocADDKDRPLP=DocADDKDRPLP;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPlPImpl::get_DocOPERATIONPLP(void)
{
return Object->DocOPERATIONPLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocOPERATIONPLP(TFIBIntegerField * DocOPERATIONPLP)
{
Object->DocOPERATIONPLP=DocOPERATIONPLP;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPlPImpl::get_DocSUMUSNPLP(void)
{
return Object->DocSUMUSNPLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocSUMUSNPLP(TFIBBCDField * DocSUMUSNPLP)
{
Object->DocSUMUSNPLP=DocSUMUSNPLP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocNALOG_STATUS_PLP(void)
{
return Object->DocNALOG_STATUS_PLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocNALOG_STATUS_PLP(TFIBWideStringField * DocNALOG_STATUS_PLP)
{
Object->DocNALOG_STATUS_PLP=DocNALOG_STATUS_PLP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocNALOG_OSN_PLP(void)
{
return Object->DocNALOG_OSN_PLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocNALOG_OSN_PLP(TFIBWideStringField * DocNALOG_OSN_PLP)
{
Object->DocNALOG_OSN_PLP=DocNALOG_OSN_PLP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocNALOG_NUM_PLP(void)
{
return Object->DocNALOG_NUM_PLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocNALOG_NUM_PLP(TFIBWideStringField * DocNALOG_NUM_PLP)
{
Object->DocNALOG_NUM_PLP=DocNALOG_NUM_PLP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocNALOG_TPLAT_PLP(void)
{
return Object->DocNALOG_TPLAT_PLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocNALOG_TPLAT_PLP(TFIBWideStringField * DocNALOG_TPLAT_PLP)
{
Object->DocNALOG_TPLAT_PLP=DocNALOG_TPLAT_PLP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocNALOG_KBK_PLP(void)
{
return Object->DocNALOG_KBK_PLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocNALOG_KBK_PLP(TFIBWideStringField * DocNALOG_KBK_PLP)
{
Object->DocNALOG_KBK_PLP=DocNALOG_KBK_PLP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocNALOG_OKATO_PLP(void)
{
return Object->DocNALOG_OKATO_PLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocNALOG_OKATO_PLP(TFIBWideStringField * DocNALOG_OKATO_PLP)
{
Object->DocNALOG_OKATO_PLP=DocNALOG_OKATO_PLP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocNALOG_PERIOD_PLP(void)
{
return Object->DocNALOG_PERIOD_PLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocNALOG_PERIOD_PLP(TFIBWideStringField * DocNALOG_PERIOD_PLP)
{
Object->DocNALOG_PERIOD_PLP=DocNALOG_PERIOD_PLP;
}
//---------------------------------------------------------------
TFIBDateField * TDMDocPlPImpl::get_DocNALOG_DATE_PLP(void)
{
return Object->DocNALOG_DATE_PLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocNALOG_DATE_PLP(TFIBDateField * DocNALOG_DATE_PLP)
{
Object->DocNALOG_DATE_PLP=DocNALOG_DATE_PLP;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPlPImpl::get_DocIDBASE_DPLP(void)
{
return Object->DocIDBASE_DPLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocIDBASE_DPLP(TFIBLargeIntField * DocIDBASE_DPLP)
{
Object->DocIDBASE_DPLP=DocIDBASE_DPLP;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocPlPImpl::get_DocNDS_DPLP(void)
{
return Object->DocNDS_DPLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocNDS_DPLP(TFIBIntegerField * DocNDS_DPLP)
{
Object->DocNDS_DPLP=DocNDS_DPLP;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocPlPImpl::get_DocSUMNDS_DPLP(void)
{
return Object->DocSUMNDS_DPLP;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocSUMNDS_DPLP(TFIBBCDField * DocSUMNDS_DPLP)
{
Object->DocSUMNDS_DPLP=DocSUMNDS_DPLP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocNAMEBSCHET(void)
{
return Object->DocNAMEBSCHET;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocNAMEBSCHET(TFIBWideStringField * DocNAMEBSCHET)
{
Object->DocNAMEBSCHET=DocNAMEBSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocNAMERSCHET(void)
{
return Object->DocNAMERSCHET;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocNAMERSCHET(TFIBWideStringField * DocNAMERSCHET)
{
Object->DocNAMERSCHET=DocNAMERSCHET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocPlPImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocPlPImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
bool TDMDocPlPImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocPlPImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TDMDocPlPImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocPlPImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocPlPImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocPlPImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TDMDocPlPImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocPlPImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocPlPImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocPlPImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool TDMDocPlPImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
int TDMDocPlPImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
