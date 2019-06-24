#include "vcl.h"
#pragma hdrstop


#include "UDMDocRegGoodsImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMDocRegGoodsImpl::TDMDocRegGoodsImpl()           
{                                            
Object=new TDMDocRegGoods(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMDocRegGoodsImpl::~TDMDocRegGoodsImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMDocRegGoodsImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMDocRegGoods)                        
   {                                                                     
   *ppv=static_cast<IDMDocRegGoods*> (this);                                
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
int TDMDocRegGoodsImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMDocRegGoodsImpl::kanRelease(void)                                  
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
int  TDMDocRegGoodsImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMDocRegGoodsImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMDocRegGoodsImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMDocRegGoodsImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMDocRegGoodsImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMDocRegGoods
TDataSource * TDMDocRegGoodsImpl::get_DataSourceDoc(void)
{
return Object->DataSourceDoc;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DataSourceDoc(TDataSource * DataSourceDoc)
{
Object->DataSourceDoc=DataSourceDoc;
}
//---------------------------------------------------------------
TDataSource * TDMDocRegGoodsImpl::get_DataSourceDocT(void)
{
return Object->DataSourceDocT;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DataSourceDocT(TDataSource * DataSourceDocT)
{
Object->DataSourceDocT=DataSourceDocT;
}
//---------------------------------------------------------------
TDataSource * TDMDocRegGoodsImpl::get_DataSourceDocAll(void)
{
return Object->DataSourceDocAll;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DataSourceDocAll(TDataSource * DataSourceDocAll)
{
Object->DataSourceDocAll=DataSourceDocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegGoodsImpl::get_DocAll(void)
{
return Object->DocAll;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAll(TpFIBDataSet * DocAll)
{
Object->DocAll=DocAll;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegGoodsImpl::get_Doc(void)
{
return Object->Doc;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_Doc(TpFIBDataSet * Doc)
{
Object->Doc=Doc;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegGoodsImpl::get_DocT(void)
{
return Object->DocT;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocT(TpFIBDataSet * DocT)
{
Object->DocT=DocT;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegGoodsImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegGoodsImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMDocRegGoodsImpl::get_IBTrDvReg(void)
{
return Object->IBTrDvReg;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_IBTrDvReg(TpFIBTransaction * IBTrDvReg)
{
Object->IBTrDvReg=IBTrDvReg;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMDocRegGoodsImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegGoodsImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegGoodsImpl::get_QueryCancelDvReg(void)
{
return Object->QueryCancelDvReg;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_QueryCancelDvReg(TpFIBQuery * QueryCancelDvReg)
{
Object->QueryCancelDvReg=QueryCancelDvReg;
}
//---------------------------------------------------------------
TpFIBQuery * TDMDocRegGoodsImpl::get_QueryDvReg(void)
{
return Object->QueryDvReg;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_QueryDvReg(TpFIBQuery * QueryDvReg)
{
Object->QueryDvReg=QueryDvReg;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMDocRegGoodsImpl::get_DocAllPOSDOC(void)
{
return Object->DocAllPOSDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllPOSDOC(TFIBDateTimeField * DocAllPOSDOC)
{
Object->DocAllPOSDOC=DocAllPOSDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRegGoodsImpl::get_DocAllPRDOC(void)
{
return Object->DocAllPRDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllPRDOC(TFIBSmallIntField * DocAllPRDOC)
{
Object->DocAllPRDOC=DocAllPRDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegGoodsImpl::get_DocAllNUMDOC(void)
{
return Object->DocAllNUMDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllNUMDOC(TFIBIntegerField * DocAllNUMDOC)
{
Object->DocAllNUMDOC=DocAllNUMDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegGoodsImpl::get_DocAllSUMDOC(void)
{
return Object->DocAllSUMDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllSUMDOC(TFIBBCDField * DocAllSUMDOC)
{
Object->DocAllSUMDOC=DocAllSUMDOC;
}
//---------------------------------------------------------------
TIntegerField * TDMDocRegGoodsImpl::get_DocTRECNO(void)
{
return Object->DocTRECNO;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocTRECNO(TIntegerField * DocTRECNO)
{
Object->DocTRECNO=DocTRECNO;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMDocRegGoodsImpl::get_DocTTDV_DRG_GOODST(void)
{
return Object->DocTTDV_DRG_GOODST;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocTTDV_DRG_GOODST(TFIBSmallIntField * DocTTDV_DRG_GOODST)
{
Object->DocTTDV_DRG_GOODST=DocTTDV_DRG_GOODST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegGoodsImpl::get_DocTRPRICE_DRG_GOODST(void)
{
return Object->DocTRPRICE_DRG_GOODST;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocTRPRICE_DRG_GOODST(TFIBBCDField * DocTRPRICE_DRG_GOODST)
{
Object->DocTRPRICE_DRG_GOODST=DocTRPRICE_DRG_GOODST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMDocRegGoodsImpl::get_DocTKOL_DRG_GOODST(void)
{
return Object->DocTKOL_DRG_GOODST;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocTKOL_DRG_GOODST(TFIBBCDField * DocTKOL_DRG_GOODST)
{
Object->DocTKOL_DRG_GOODST=DocTKOL_DRG_GOODST;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegGoodsImpl::get_DocTOPER_DRG_GOODST(void)
{
return Object->DocTOPER_DRG_GOODST;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocTOPER_DRG_GOODST(TFIBIntegerField * DocTOPER_DRG_GOODST)
{
Object->DocTOPER_DRG_GOODST=DocTOPER_DRG_GOODST;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegGoodsImpl::get_DocTTYPE_DRG_GOODST(void)
{
return Object->DocTTYPE_DRG_GOODST;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocTTYPE_DRG_GOODST(TFIBIntegerField * DocTTYPE_DRG_GOODST)
{
Object->DocTTYPE_DRG_GOODST=DocTTYPE_DRG_GOODST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocAllIDDOC(void)
{
return Object->DocAllIDDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllIDDOC(TFIBLargeIntField * DocAllIDDOC)
{
Object->DocAllIDDOC=DocAllIDDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocAllIDFIRMDOC(void)
{
return Object->DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllIDFIRMDOC(TFIBLargeIntField * DocAllIDFIRMDOC)
{
Object->DocAllIDFIRMDOC=DocAllIDFIRMDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocAllIDSKLDOC(void)
{
return Object->DocAllIDSKLDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllIDSKLDOC(TFIBLargeIntField * DocAllIDSKLDOC)
{
Object->DocAllIDSKLDOC=DocAllIDSKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocAllIDKLDOC(void)
{
return Object->DocAllIDKLDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllIDKLDOC(TFIBLargeIntField * DocAllIDKLDOC)
{
Object->DocAllIDKLDOC=DocAllIDKLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocAllIDDOGDOC(void)
{
return Object->DocAllIDDOGDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllIDDOGDOC(TFIBLargeIntField * DocAllIDDOGDOC)
{
Object->DocAllIDDOGDOC=DocAllIDDOGDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocAllIDUSERDOC(void)
{
return Object->DocAllIDUSERDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllIDUSERDOC(TFIBLargeIntField * DocAllIDUSERDOC)
{
Object->DocAllIDUSERDOC=DocAllIDUSERDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegGoodsImpl::get_DocAllGID_DOC(void)
{
return Object->DocAllGID_DOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllGID_DOC(TFIBWideStringField * DocAllGID_DOC)
{
Object->DocAllGID_DOC=DocAllGID_DOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegGoodsImpl::get_DocAllPREFIKSDOC(void)
{
return Object->DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllPREFIKSDOC(TFIBWideStringField * DocAllPREFIKSDOC)
{
Object->DocAllPREFIKSDOC=DocAllPREFIKSDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocAllIDDOCOSNDOC(void)
{
return Object->DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllIDDOCOSNDOC(TFIBLargeIntField * DocAllIDDOCOSNDOC)
{
Object->DocAllIDDOCOSNDOC=DocAllIDDOCOSNDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocAllIDEXTDOC(void)
{
return Object->DocAllIDEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllIDEXTDOC(TFIBLargeIntField * DocAllIDEXTDOC)
{
Object->DocAllIDEXTDOC=DocAllIDEXTDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMDocRegGoodsImpl::get_DocAllTYPEEXTDOC(void)
{
return Object->DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllTYPEEXTDOC(TFIBIntegerField * DocAllTYPEEXTDOC)
{
Object->DocAllTYPEEXTDOC=DocAllTYPEEXTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocAllIDBASE_GALLDOC(void)
{
return Object->DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllIDBASE_GALLDOC(TFIBLargeIntField * DocAllIDBASE_GALLDOC)
{
Object->DocAllIDBASE_GALLDOC=DocAllIDBASE_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocAllIDPROJECT_GALLDOC(void)
{
return Object->DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllIDPROJECT_GALLDOC(TFIBLargeIntField * DocAllIDPROJECT_GALLDOC)
{
Object->DocAllIDPROJECT_GALLDOC=DocAllIDPROJECT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegGoodsImpl::get_DocAllFNAME_USER(void)
{
return Object->DocAllFNAME_USER;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllFNAME_USER(TFIBWideStringField * DocAllFNAME_USER)
{
Object->DocAllFNAME_USER=DocAllFNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegGoodsImpl::get_DocAllNAME_SINFBASE_OBMEN(void)
{
return Object->DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllNAME_SINFBASE_OBMEN(TFIBWideStringField * DocAllNAME_SINFBASE_OBMEN)
{
Object->DocAllNAME_SINFBASE_OBMEN=DocAllNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocID_DRG_GOODS(void)
{
return Object->DocID_DRG_GOODS;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocID_DRG_GOODS(TFIBLargeIntField * DocID_DRG_GOODS)
{
Object->DocID_DRG_GOODS=DocID_DRG_GOODS;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocIDBASE_DRG_GOODS(void)
{
return Object->DocIDBASE_DRG_GOODS;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocIDBASE_DRG_GOODS(TFIBLargeIntField * DocIDBASE_DRG_GOODS)
{
Object->DocIDBASE_DRG_GOODS=DocIDBASE_DRG_GOODS;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocIDDOC_DRG_GOODS(void)
{
return Object->DocIDDOC_DRG_GOODS;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocIDDOC_DRG_GOODS(TFIBLargeIntField * DocIDDOC_DRG_GOODS)
{
Object->DocIDDOC_DRG_GOODS=DocIDDOC_DRG_GOODS;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegGoodsImpl::get_DocDESCR_DRG_GOODS(void)
{
return Object->DocDESCR_DRG_GOODS;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocDESCR_DRG_GOODS(TFIBWideStringField * DocDESCR_DRG_GOODS)
{
Object->DocDESCR_DRG_GOODS=DocDESCR_DRG_GOODS;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocTID_DRG_GOODST(void)
{
return Object->DocTID_DRG_GOODST;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocTID_DRG_GOODST(TFIBLargeIntField * DocTID_DRG_GOODST)
{
Object->DocTID_DRG_GOODST=DocTID_DRG_GOODST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocTIDBASE_DRG_GOODST(void)
{
return Object->DocTIDBASE_DRG_GOODST;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocTIDBASE_DRG_GOODST(TFIBLargeIntField * DocTIDBASE_DRG_GOODST)
{
Object->DocTIDBASE_DRG_GOODST=DocTIDBASE_DRG_GOODST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocTIDDOC_DRG_GOODST(void)
{
return Object->DocTIDDOC_DRG_GOODST;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocTIDDOC_DRG_GOODST(TFIBLargeIntField * DocTIDDOC_DRG_GOODST)
{
Object->DocTIDDOC_DRG_GOODST=DocTIDDOC_DRG_GOODST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocTIDFIRM_DRG_GOODST(void)
{
return Object->DocTIDFIRM_DRG_GOODST;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocTIDFIRM_DRG_GOODST(TFIBLargeIntField * DocTIDFIRM_DRG_GOODST)
{
Object->DocTIDFIRM_DRG_GOODST=DocTIDFIRM_DRG_GOODST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocTIDSKLAD_DRG_GOODST(void)
{
return Object->DocTIDSKLAD_DRG_GOODST;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocTIDSKLAD_DRG_GOODST(TFIBLargeIntField * DocTIDSKLAD_DRG_GOODST)
{
Object->DocTIDSKLAD_DRG_GOODST=DocTIDSKLAD_DRG_GOODST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocTIDNOM_DRG_GOODST(void)
{
return Object->DocTIDNOM_DRG_GOODST;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocTIDNOM_DRG_GOODST(TFIBLargeIntField * DocTIDNOM_DRG_GOODST)
{
Object->DocTIDNOM_DRG_GOODST=DocTIDNOM_DRG_GOODST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegGoodsImpl::get_DocTNAMEFIRM(void)
{
return Object->DocTNAMEFIRM;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocTNAMEFIRM(TFIBWideStringField * DocTNAMEFIRM)
{
Object->DocTNAMEFIRM=DocTNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegGoodsImpl::get_DocTNAMESKLAD(void)
{
return Object->DocTNAMESKLAD;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocTNAMESKLAD(TFIBWideStringField * DocTNAMESKLAD)
{
Object->DocTNAMESKLAD=DocTNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegGoodsImpl::get_DocTNAMENOM(void)
{
return Object->DocTNAMENOM;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocTNAMENOM(TFIBWideStringField * DocTNAMENOM)
{
Object->DocTNAMENOM=DocTNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegGoodsImpl::get_DocAllTDOC(void)
{
return Object->DocAllTDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllTDOC(TFIBWideStringField * DocAllTDOC)
{
Object->DocAllTDOC=DocAllTDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMDocRegGoodsImpl::get_DocAllIDBUSINOP_GALLDOC(void)
{
return Object->DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllIDBUSINOP_GALLDOC(TFIBLargeIntField * DocAllIDBUSINOP_GALLDOC)
{
Object->DocAllIDBUSINOP_GALLDOC=DocAllIDBUSINOP_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegGoodsImpl::get_DocAllNAME_SPROJECT(void)
{
return Object->DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllNAME_SPROJECT(TFIBWideStringField * DocAllNAME_SPROJECT)
{
Object->DocAllNAME_SPROJECT=DocAllNAME_SPROJECT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegGoodsImpl::get_DocAllNAME_SBUSINESS_OPER(void)
{
return Object->DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllNAME_SBUSINESS_OPER(TFIBWideStringField * DocAllNAME_SBUSINESS_OPER)
{
Object->DocAllNAME_SBUSINESS_OPER=DocAllNAME_SBUSINESS_OPER;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMDocRegGoodsImpl::get_DocAllPREFIKS_NUM_GALLDOC(void)
{
return Object->DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_DocAllPREFIKS_NUM_GALLDOC(TFIBWideStringField * DocAllPREFIKS_NUM_GALLDOC)
{
Object->DocAllPREFIKS_NUM_GALLDOC=DocAllPREFIKS_NUM_GALLDOC;
}
//---------------------------------------------------------------
__int64 TDMDocRegGoodsImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
bool TDMDocRegGoodsImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
bool TDMDocRegGoodsImpl::get_EnableDvReg(void)
{
return Object->EnableDvReg;
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::set_EnableDvReg(bool EnableDvReg)
{
Object->EnableDvReg=EnableDvReg;
}
//---------------------------------------------------------------
bool TDMDocRegGoodsImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
bool TDMDocRegGoodsImpl::OpenDoc(__int64 IdDoc)
{
return Object->OpenDoc(IdDoc);
}
//---------------------------------------------------------------
bool TDMDocRegGoodsImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TDMDocRegGoodsImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
bool TDMDocRegGoodsImpl::DvRegDoc(void)
{
return Object->DvRegDoc();
}
//---------------------------------------------------------------
bool TDMDocRegGoodsImpl::CancelDvRegDoc(void)
{
return Object->CancelDvRegDoc();
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::TableAppend(void)
{
return Object->TableAppend();
}
//---------------------------------------------------------------
void TDMDocRegGoodsImpl::TableDelete(void)
{
return Object->TableDelete();
}
//---------------------------------------------------------------
int TDMDocRegGoodsImpl::GetNumberNewDoc(void)
{
return Object->GetNumberNewDoc();
}
//---------------------------------------------------------------
