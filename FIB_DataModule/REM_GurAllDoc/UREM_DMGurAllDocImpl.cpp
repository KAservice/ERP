#include "vcl.h"
#pragma hdrstop


#include "UREM_DMGurAllDocImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMGurAllDocImpl::TREM_DMGurAllDocImpl()           
{                                            
Object=new TREM_DMGurAllDoc(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMGurAllDocImpl::~TREM_DMGurAllDocImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMGurAllDocImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMGurAllDoc)                        
   {                                                                     
   *ppv=static_cast<IREM_DMGurAllDoc*> (this);                                
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
int TREM_DMGurAllDocImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMGurAllDocImpl::kanRelease(void)                                  
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
int  TREM_DMGurAllDocImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMGurAllDocImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMGurAllDocImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMGurAllDocImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMGurAllDocImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMGurAllDoc
TDataSource * TREM_DMGurAllDocImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMGurAllDocImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMGurAllDocImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMGurAllDocImpl::get_IBQ(void)
{
return Object->IBQ;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_IBQ(TpFIBDataSet * IBQ)
{
Object->IBQ=IBQ;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMGurAllDocImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurAllDocImpl::get_TableID_REM_GALLDOC(void)
{
return Object->TableID_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableID_REM_GALLDOC(TFIBLargeIntField * TableID_REM_GALLDOC)
{
Object->TableID_REM_GALLDOC=TableID_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurAllDocImpl::get_TableIDBASE_REM_GALLDOC(void)
{
return Object->TableIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableIDBASE_REM_GALLDOC(TFIBLargeIntField * TableIDBASE_REM_GALLDOC)
{
Object->TableIDBASE_REM_GALLDOC=TableIDBASE_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurAllDocImpl::get_TableIDFIRM_REM_GALLDOC(void)
{
return Object->TableIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableIDFIRM_REM_GALLDOC(TFIBLargeIntField * TableIDFIRM_REM_GALLDOC)
{
Object->TableIDFIRM_REM_GALLDOC=TableIDFIRM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurAllDocImpl::get_TableIDSKLAD_REM_GALLDOC(void)
{
return Object->TableIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableIDSKLAD_REM_GALLDOC(TFIBLargeIntField * TableIDSKLAD_REM_GALLDOC)
{
Object->TableIDSKLAD_REM_GALLDOC=TableIDSKLAD_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurAllDocImpl::get_TableIDKLIENT_REM_GALLDOC(void)
{
return Object->TableIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableIDKLIENT_REM_GALLDOC(TFIBLargeIntField * TableIDKLIENT_REM_GALLDOC)
{
Object->TableIDKLIENT_REM_GALLDOC=TableIDKLIENT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurAllDocImpl::get_TableIDUSER_REM_GALLDOC(void)
{
return Object->TableIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableIDUSER_REM_GALLDOC(TFIBLargeIntField * TableIDUSER_REM_GALLDOC)
{
Object->TableIDUSER_REM_GALLDOC=TableIDUSER_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMGurAllDocImpl::get_TablePOS_REM_GALLDOC(void)
{
return Object->TablePOS_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TablePOS_REM_GALLDOC(TFIBDateTimeField * TablePOS_REM_GALLDOC)
{
Object->TablePOS_REM_GALLDOC=TablePOS_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurAllDocImpl::get_TableNUM_REM_GALLDOC(void)
{
return Object->TableNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableNUM_REM_GALLDOC(TFIBIntegerField * TableNUM_REM_GALLDOC)
{
Object->TableNUM_REM_GALLDOC=TableNUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMGurAllDocImpl::get_TablePR_REM_GALLDOC(void)
{
return Object->TablePR_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TablePR_REM_GALLDOC(TFIBSmallIntField * TablePR_REM_GALLDOC)
{
Object->TablePR_REM_GALLDOC=TablePR_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurAllDocImpl::get_TableTDOC_REM_GALLDOC(void)
{
return Object->TableTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableTDOC_REM_GALLDOC(TFIBWideStringField * TableTDOC_REM_GALLDOC)
{
Object->TableTDOC_REM_GALLDOC=TableTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurAllDocImpl::get_TableIDDOCOSN_REM_GALLDOC(void)
{
return Object->TableIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableIDDOCOSN_REM_GALLDOC(TFIBLargeIntField * TableIDDOCOSN_REM_GALLDOC)
{
Object->TableIDDOCOSN_REM_GALLDOC=TableIDDOCOSN_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurAllDocImpl::get_TableTYPEEXTDOC_REM_GALLDOC(void)
{
return Object->TableTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableTYPEEXTDOC_REM_GALLDOC(TFIBIntegerField * TableTYPEEXTDOC_REM_GALLDOC)
{
Object->TableTYPEEXTDOC_REM_GALLDOC=TableTYPEEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurAllDocImpl::get_TableIDEXTDOC_REM_GALLDOC(void)
{
return Object->TableIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableIDEXTDOC_REM_GALLDOC(TFIBLargeIntField * TableIDEXTDOC_REM_GALLDOC)
{
Object->TableIDEXTDOC_REM_GALLDOC=TableIDEXTDOC_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMGurAllDocImpl::get_TableSUM_REM_GALLDOC(void)
{
return Object->TableSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableSUM_REM_GALLDOC(TFIBBCDField * TableSUM_REM_GALLDOC)
{
Object->TableSUM_REM_GALLDOC=TableSUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurAllDocImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurAllDocImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurAllDocImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurAllDocImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurAllDocImpl::get_TablePREFIKS_NUM_REM_GALLDOC(void)
{
return Object->TablePREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TablePREFIKS_NUM_REM_GALLDOC(TFIBWideStringField * TablePREFIKS_NUM_REM_GALLDOC)
{
Object->TablePREFIKS_NUM_REM_GALLDOC=TablePREFIKS_NUM_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMGurAllDocImpl::get_TableNAME_SINFBASE_OBMEN(void)
{
return Object->TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)
{
Object->TableNAME_SINFBASE_OBMEN=TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------

TFIBLargeIntField * TREM_DMGurAllDocImpl::get_TableIDPROJECT_REM_GALLDOC(void)
{
return Object->TableIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableIDPROJECT_REM_GALLDOC(TFIBLargeIntField * TableIDPROJECT_REM_GALLDOC)
{
Object->TableIDPROJECT_REM_GALLDOC=TableIDPROJECT_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurAllDocImpl::get_TableIDBUSINOP_REM_GALLDOC(void)
{
return Object->TableIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableIDBUSINOP_REM_GALLDOC(TFIBLargeIntField * TableIDBUSINOP_REM_GALLDOC)
{
Object->TableIDBUSINOP_REM_GALLDOC=TableIDBUSINOP_REM_GALLDOC;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurAllDocImpl::get_TableID_REM_GUR_PROV(void)
{
return Object->TableID_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableID_REM_GUR_PROV(TFIBLargeIntField * TableID_REM_GUR_PROV)
{
Object->TableID_REM_GUR_PROV=TableID_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMGurAllDocImpl::get_TableRES_REM_GUR_PROV(void)
{
return Object->TableRES_REM_GUR_PROV;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableRES_REM_GUR_PROV(TFIBIntegerField * TableRES_REM_GUR_PROV)
{
Object->TableRES_REM_GUR_PROV=TableRES_REM_GUR_PROV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMGurAllDocImpl::get_TableIDDOC_REM_GUR_VIGRT(void)
{
return Object->TableIDDOC_REM_GUR_VIGRT;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_TableIDDOC_REM_GUR_VIGRT(TFIBLargeIntField * TableIDDOC_REM_GUR_VIGRT)
{
Object->TableIDDOC_REM_GUR_VIGRT=TableIDDOC_REM_GUR_VIGRT;
}
//---------------------------------------------------------------
TDateTime TREM_DMGurAllDocImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TREM_DMGurAllDocImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
__int64 TREM_DMGurAllDocImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
__int64 TREM_DMGurAllDocImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
__int64 TREM_DMGurAllDocImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TREM_DMGurAllDocImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
UnicodeString TREM_DMGurAllDocImpl::get_StringTypeDoc(void)
{
return Object->StringTypeDoc;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_StringTypeDoc(UnicodeString StringTypeDoc)
{
Object->StringTypeDoc=StringTypeDoc;
}
//---------------------------------------------------------------
bool TREM_DMGurAllDocImpl::get_OtborVkl(void)
{
return Object->OtborVkl;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::set_OtborVkl(bool OtborVkl)
{
Object->OtborVkl=OtborVkl;
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::UpdateTable(void)
{
return Object->UpdateTable();
}
//---------------------------------------------------------------
bool TREM_DMGurAllDocImpl::CancelDvRegDoc(UnicodeString type_doc, __int64 id_doc)
{
return Object->CancelDvRegDoc(type_doc,id_doc);
}
//---------------------------------------------------------------
bool TREM_DMGurAllDocImpl::DvRegDoc(UnicodeString type_doc, __int64 id_doc)
{
return Object->DvRegDoc(type_doc, id_doc);
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::AllCancelDvRegDoc(void)
{
return Object->AllCancelDvRegDoc();
}
//---------------------------------------------------------------
void TREM_DMGurAllDocImpl::AllDvRegDoc(void)
{
return Object->AllDvRegDoc();
}
//---------------------------------------------------------------
bool TREM_DMGurAllDocImpl::OpenTableOnlyHardware(__int64 id_hw)
{
return Object->OpenTableOnlyHardware(id_hw);
}
//---------------------------------------------------------------
bool TREM_DMGurAllDocImpl::OpenTableOnlyZayavka(__int64 id_z)
{
return Object->OpenTableOnlyZayavka(id_z);
}
//---------------------------------------------------------------
