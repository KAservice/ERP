#include "vcl.h"
#pragma hdrstop


#include "UDMDocIsmPriceImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocIsmPriceImpl::TDMDocIsmPriceImpl()           
{                                            
Object=new TDMDocIsmPrice(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocIsmPriceImpl::~TDMDocIsmPriceImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocIsmPriceImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocIsmPrice)                        
   {                                                                     
   *ppv=static_cast<IDMDocIsmPrice*> (this);                                
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
int TDMDocIsmPriceImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocIsmPriceImpl::kanRelease(void)                                  
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
int  TDMDocIsmPriceImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocIsmPriceImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocIsmPriceImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocIsmPriceImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocIsmPriceImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocIsmPrice
TDataSource * TDMDocIsmPriceImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocIsmPriceImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocIsmPriceImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocIsmPriceImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocIsmPriceImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocIsmPriceImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocIsmPriceImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocIsmPriceImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocIsmPriceImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TIntegerField * TDMDocIsmPriceImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocIsmPriceImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocIsmPriceImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocIsmPriceImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TFloatField * TDMDocIsmPriceImpl::get_DocTOLDSUM(void)
{
return Object->DocTOLDSUM;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTOLDSUM(TFloatField * DocTOLDSUM)
{
Object->DocTOLDSUM=DocTOLDSUM;
}
//---------------------------------------------------------------
TFloatField * TDMDocIsmPriceImpl::get_DocTNEWSUM(void)
{
return Object->DocTNEWSUM;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTNEWSUM(TFloatField * DocTNEWSUM)
{
Object->DocTNEWSUM=DocTNEWSUM;
}
//---------------------------------------------------------------
TFloatField * TDMDocIsmPriceImpl::get_DocTSUMISM(void)
{
return Object->DocTSUMISM;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTSUMISM(TFloatField * DocTSUMISM)
{
Object->DocTSUMISM=DocTSUMISM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocIsmPriceImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocIsmPriceImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocIsmPriceImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocIsmPriceImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocIsmPriceImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocAllNAMEFIRM(void)
{
return Object->DocAllNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllNAMEFIRM(TFIBWideStringField * DocAllNAMEFIRM)
{
Object->DocAllNAMEFIRM=DocAllNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocAllNAMESKLAD(void)
{
return Object->DocAllNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllNAMESKLAD(TFIBWideStringField * DocAllNAMESKLAD)
{
Object->DocAllNAMESKLAD=DocAllNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocAllNAMEKLIENT(void)
{
return Object->DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllNAMEKLIENT(TFIBWideStringField * DocAllNAMEKLIENT)
{
Object->DocAllNAMEKLIENT=DocAllNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocID_DISMPRICE(void)
{
return Object->DocID_DISMPRICE;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocID_DISMPRICE(TFIBLargeIntField * DocID_DISMPRICE)
{
Object->DocID_DISMPRICE=DocID_DISMPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocGID_DISMPRICE(void)
{
return Object->DocGID_DISMPRICE;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocGID_DISMPRICE(TFIBWideStringField * DocGID_DISMPRICE)
{
Object->DocGID_DISMPRICE=DocGID_DISMPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocIDDOC_DISMPRICE(void)
{
return Object->DocIDDOC_DISMPRICE;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocIDDOC_DISMPRICE(TFIBLargeIntField * DocIDDOC_DISMPRICE)
{
Object->DocIDDOC_DISMPRICE=DocIDDOC_DISMPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocDESCR_DISMPRICE(void)
{
return Object->DocDESCR_DISMPRICE;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocDESCR_DISMPRICE(TFIBWideStringField * DocDESCR_DISMPRICE)
{
Object->DocDESCR_DISMPRICE=DocDESCR_DISMPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocIDNEWTPRICE_DISMPRICE(void)
{
return Object->DocIDNEWTPRICE_DISMPRICE;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocIDNEWTPRICE_DISMPRICE(TFIBLargeIntField * DocIDNEWTPRICE_DISMPRICE)
{
Object->DocIDNEWTPRICE_DISMPRICE=DocIDNEWTPRICE_DISMPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocIDBASE_DISMPRICE(void)
{
return Object->DocIDBASE_DISMPRICE;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocIDBASE_DISMPRICE(TFIBLargeIntField * DocIDBASE_DISMPRICE)
{
Object->DocIDBASE_DISMPRICE=DocIDBASE_DISMPRICE;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocIsmPriceImpl::get_DocOPER_DISMPRICE(void)
{
return Object->DocOPER_DISMPRICE;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocOPER_DISMPRICE(TFIBIntegerField * DocOPER_DISMPRICE)
{
Object->DocOPER_DISMPRICE=DocOPER_DISMPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocIDINV_DISMPRICE(void)
{
return Object->DocIDINV_DISMPRICE;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocIDINV_DISMPRICE(TFIBLargeIntField * DocIDINV_DISMPRICE)
{
Object->DocIDINV_DISMPRICE=DocIDINV_DISMPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocNAME_SINV(void)
{
return Object->DocNAME_SINV;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocNAME_SINV(TFIBWideStringField * DocNAME_SINV)
{
Object->DocNAME_SINV=DocNAME_SINV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocTID_DISMPRICET(void)
{
return Object->DocTID_DISMPRICET;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTID_DISMPRICET(TFIBLargeIntField * DocTID_DISMPRICET)
{
Object->DocTID_DISMPRICET=DocTID_DISMPRICET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocTGID_DISMPRICET(void)
{
return Object->DocTGID_DISMPRICET;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTGID_DISMPRICET(TFIBWideStringField * DocTGID_DISMPRICET)
{
Object->DocTGID_DISMPRICET=DocTGID_DISMPRICET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocTIDDOC_DISMPRICET(void)
{
return Object->DocTIDDOC_DISMPRICET;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTIDDOC_DISMPRICET(TFIBLargeIntField * DocTIDDOC_DISMPRICET)
{
Object->DocTIDDOC_DISMPRICET=DocTIDDOC_DISMPRICET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocTIDNOM_DISMPRICET(void)
{
return Object->DocTIDNOM_DISMPRICET;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTIDNOM_DISMPRICET(TFIBLargeIntField * DocTIDNOM_DISMPRICET)
{
Object->DocTIDNOM_DISMPRICET=DocTIDNOM_DISMPRICET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocTIDED_DISMPRICET(void)
{
return Object->DocTIDED_DISMPRICET;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTIDED_DISMPRICET(TFIBLargeIntField * DocTIDED_DISMPRICET)
{
Object->DocTIDED_DISMPRICET=DocTIDED_DISMPRICET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocIsmPriceImpl::get_DocTKOL_DISMPRICET(void)
{
return Object->DocTKOL_DISMPRICET;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTKOL_DISMPRICET(TFIBBCDField * DocTKOL_DISMPRICET)
{
Object->DocTKOL_DISMPRICET=DocTKOL_DISMPRICET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocIsmPriceImpl::get_DocTKF_DISMPRICET(void)
{
return Object->DocTKF_DISMPRICET;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTKF_DISMPRICET(TFIBBCDField * DocTKF_DISMPRICET)
{
Object->DocTKF_DISMPRICET=DocTKF_DISMPRICET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocIsmPriceImpl::get_DocTOLDPRICE_DISMPRICET(void)
{
return Object->DocTOLDPRICE_DISMPRICET;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTOLDPRICE_DISMPRICET(TFIBBCDField * DocTOLDPRICE_DISMPRICET)
{
Object->DocTOLDPRICE_DISMPRICET=DocTOLDPRICE_DISMPRICET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocIsmPriceImpl::get_DocTNEWPRICE_DISMPRICET(void)
{
return Object->DocTNEWPRICE_DISMPRICET;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTNEWPRICE_DISMPRICET(TFIBBCDField * DocTNEWPRICE_DISMPRICET)
{
Object->DocTNEWPRICE_DISMPRICET=DocTNEWPRICE_DISMPRICET;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocTIDBASE_DISMPRICET(void)
{
return Object->DocTIDBASE_DISMPRICET;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTIDBASE_DISMPRICET(TFIBLargeIntField * DocTIDBASE_DISMPRICET)
{
Object->DocTIDBASE_DISMPRICET=DocTIDBASE_DISMPRICET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocTNAMEED(void)
{
return Object->DocTNAMEED;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTNAMEED(TFIBWideStringField * DocTNAMEED)
{
Object->DocTNAMEED=DocTNAMEED;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocIsmPriceImpl::get_DocTTNOM(void)
{
return Object->DocTTNOM;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTTNOM(TFIBIntegerField * DocTTNOM)
{
Object->DocTTNOM=DocTTNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocIsmPriceImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocIsmPriceImpl::get_DocTSEB_PRICE_DISMPRICET(void)
{
return Object->DocTSEB_PRICE_DISMPRICET;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTSEB_PRICE_DISMPRICET(TFIBBCDField * DocTSEB_PRICE_DISMPRICET)
{
Object->DocTSEB_PRICE_DISMPRICET=DocTSEB_PRICE_DISMPRICET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocIsmPriceImpl::get_DocTSEB_SUM_DISMPRICET(void)
{
return Object->DocTSEB_SUM_DISMPRICET;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTSEB_SUM_DISMPRICET(TFIBBCDField * DocTSEB_SUM_DISMPRICET)
{
Object->DocTSEB_SUM_DISMPRICET=DocTSEB_SUM_DISMPRICET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocIsmPriceImpl::get_DocTNAC_SUM_ED(void)
{
return Object->DocTNAC_SUM_ED;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTNAC_SUM_ED(TFIBBCDField * DocTNAC_SUM_ED)
{
Object->DocTNAC_SUM_ED=DocTNAC_SUM_ED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocIsmPriceImpl::get_DocTNAC_SUM(void)
{
return Object->DocTNAC_SUM;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTNAC_SUM(TFIBBCDField * DocTNAC_SUM)
{
Object->DocTNAC_SUM=DocTNAC_SUM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocIsmPriceImpl::get_DocTNAC_NEW_DISMPRICET(void)
{
return Object->DocTNAC_NEW_DISMPRICET;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTNAC_NEW_DISMPRICET(TFIBBCDField * DocTNAC_NEW_DISMPRICET)
{
Object->DocTNAC_NEW_DISMPRICET=DocTNAC_NEW_DISMPRICET;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocIsmPriceImpl::get_DocTNAC_OLD_DISMPRICET(void)
{
return Object->DocTNAC_OLD_DISMPRICET;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTNAC_OLD_DISMPRICET(TFIBBCDField * DocTNAC_OLD_DISMPRICET)
{
Object->DocTNAC_OLD_DISMPRICET=DocTNAC_OLD_DISMPRICET;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocTSHED(void)
{
return Object->DocTSHED;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTSHED(TFIBWideStringField * DocTSHED)
{
Object->DocTSHED=DocTSHED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocIsmPriceImpl::get_DocTARTNOM(void)
{
return Object->DocTARTNOM;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTARTNOM(TFIBWideStringField * DocTARTNOM)
{
Object->DocTARTNOM=DocTARTNOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocIsmPriceImpl::get_DocTCODENOM(void)
{
return Object->DocTCODENOM;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_DocTCODENOM(TFIBIntegerField * DocTCODENOM)
{
Object->DocTCODENOM=DocTCODENOM;
}
//---------------------------------------------------------------
bool TDMDocIsmPriceImpl::get_NewElement(void)
{
return Object->NewElement;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_NewElement(bool NewElement)
{
Object->NewElement=NewElement;
}
//---------------------------------------------------------------
bool TDMDocIsmPriceImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
UnicodeString TDMDocIsmPriceImpl::get_ProsmotrText(void)
{
return Object->ProsmotrText;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_ProsmotrText(UnicodeString ProsmotrText)
{
Object->ProsmotrText=ProsmotrText;
}
//---------------------------------------------------------------
bool TDMDocIsmPriceImpl::get_NoEdit(void)
{
return Object->NoEdit;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_NoEdit(bool NoEdit)
{
Object->NoEdit=NoEdit;
}
//---------------------------------------------------------------
__int64 TDMDocIsmPriceImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TDMDocIsmPriceImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
__int64 TDMDocIsmPriceImpl::get_IdElementaMaster(void)
{
return Object->IdElementaMaster;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_IdElementaMaster(__int64 IdElementaMaster)
{
Object->IdElementaMaster=IdElementaMaster;
}
//---------------------------------------------------------------
bool TDMDocIsmPriceImpl::get_IsmPrice(void)
{
return Object->IsmPrice;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_IsmPrice(bool IsmPrice)
{
Object->IsmPrice=IsmPrice;
}
//---------------------------------------------------------------
__int64 TDMDocIsmPriceImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
bool TDMDocIsmPriceImpl::get_AutoRaschet(void)
{
return Object->AutoRaschet;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_AutoRaschet(bool AutoRaschet)
{
Object->AutoRaschet=AutoRaschet;
}
//---------------------------------------------------------------
bool TDMDocIsmPriceImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::ValidateProsmotr(void)
{
return Object->ValidateProsmotr();
}
//---------------------------------------------------------------
bool TDMDocIsmPriceImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocIsmPriceImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocIsmPriceImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::AddDocNewString(void)
{
return Object->AddDocNewString();
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::DeleteStringDoc(void)
{
return Object->DeleteStringDoc();
}
//---------------------------------------------------------------
void TDMDocIsmPriceImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
bool TDMDocIsmPriceImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
int TDMDocIsmPriceImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
