#include "vcl.h"
#pragma hdrstop


#include "UHOT_DMGurAllDocImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
THOT_DMGurAllDocImpl::THOT_DMGurAllDocImpl()           
{                                            
Object=new THOT_DMGurAllDoc(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
THOT_DMGurAllDocImpl::~THOT_DMGurAllDocImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int THOT_DMGurAllDocImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IHOT_DMGurAllDoc)                        
   {                                                                     
   *ppv=static_cast<IHOT_DMGurAllDoc*> (this);                                
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
int THOT_DMGurAllDocImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int THOT_DMGurAllDocImpl::kanRelease(void)                                  
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
int  THOT_DMGurAllDocImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  THOT_DMGurAllDocImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int THOT_DMGurAllDocImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_THOT_DMGurAllDocImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int THOT_DMGurAllDocImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IHOT_DMGurAllDoc
TDataSource * THOT_DMGurAllDocImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMGurAllDocImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * THOT_DMGurAllDocImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBQuery * THOT_DMGurAllDocImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBDateTimeField * THOT_DMGurAllDocImpl::get_TablePOS_HOT_GALLDOC(void)
{
return Object->TablePOS_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_TablePOS_HOT_GALLDOC(TFIBDateTimeField * TablePOS_HOT_GALLDOC)
{
Object->TablePOS_HOT_GALLDOC=TablePOS_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBSmallIntField * THOT_DMGurAllDocImpl::get_TablePR_HOT_GALLDOC(void)
{
return Object->TablePR_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_TablePR_HOT_GALLDOC(TFIBSmallIntField * TablePR_HOT_GALLDOC)
{
Object->TablePR_HOT_GALLDOC=TablePR_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMGurAllDocImpl::get_TableSUM_HOT_GALLDOC(void)
{
return Object->TableSUM_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_TableSUM_HOT_GALLDOC(TFIBBCDField * TableSUM_HOT_GALLDOC)
{
Object->TableSUM_HOT_GALLDOC=TableSUM_HOT_GALLDOC;
}
//---------------------------------------------------------------
TpFIBDataSet * THOT_DMGurAllDocImpl::get_IBQ(void)
{
return Object->IBQ;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_IBQ(TpFIBDataSet * IBQ)
{
Object->IBQ=IBQ;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMGurAllDocImpl::get_TableID_HOT_GALLDOC(void)
{
return Object->TableID_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_TableID_HOT_GALLDOC(TFIBBCDField * TableID_HOT_GALLDOC)
{
Object->TableID_HOT_GALLDOC=TableID_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMGurAllDocImpl::get_TableIDFIRM_HOT_GALLDOC(void)
{
return Object->TableIDFIRM_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_TableIDFIRM_HOT_GALLDOC(TFIBBCDField * TableIDFIRM_HOT_GALLDOC)
{
Object->TableIDFIRM_HOT_GALLDOC=TableIDFIRM_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMGurAllDocImpl::get_TableIDKL_HOT_GALLDOC(void)
{
return Object->TableIDKL_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_TableIDKL_HOT_GALLDOC(TFIBBCDField * TableIDKL_HOT_GALLDOC)
{
Object->TableIDKL_HOT_GALLDOC=TableIDKL_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMGurAllDocImpl::get_TableIDUSER_HOT_GALLDOC(void)
{
return Object->TableIDUSER_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_TableIDUSER_HOT_GALLDOC(TFIBBCDField * TableIDUSER_HOT_GALLDOC)
{
Object->TableIDUSER_HOT_GALLDOC=TableIDUSER_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMGurAllDocImpl::get_TableIDDOCOSN_HOT_GALLDOC(void)
{
return Object->TableIDDOCOSN_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_TableIDDOCOSN_HOT_GALLDOC(TFIBBCDField * TableIDDOCOSN_HOT_GALLDOC)
{
Object->TableIDDOCOSN_HOT_GALLDOC=TableIDDOCOSN_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBBCDField * THOT_DMGurAllDocImpl::get_TableIDBASE_HOT_GALLDOC(void)
{
return Object->TableIDBASE_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_TableIDBASE_HOT_GALLDOC(TFIBBCDField * TableIDBASE_HOT_GALLDOC)
{
Object->TableIDBASE_HOT_GALLDOC=TableIDBASE_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMGurAllDocImpl::get_TableTDOC_HOT_GALLDOC(void)
{
return Object->TableTDOC_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_TableTDOC_HOT_GALLDOC(TFIBWideStringField * TableTDOC_HOT_GALLDOC)
{
Object->TableTDOC_HOT_GALLDOC=TableTDOC_HOT_GALLDOC;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMGurAllDocImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMGurAllDocImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * THOT_DMGurAllDocImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBIntegerField * THOT_DMGurAllDocImpl::get_TableNUMBER_HOT_GALLDOC(void)
{
return Object->TableNUMBER_HOT_GALLDOC;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_TableNUMBER_HOT_GALLDOC(TFIBIntegerField * TableNUMBER_HOT_GALLDOC)
{
Object->TableNUMBER_HOT_GALLDOC=TableNUMBER_HOT_GALLDOC;
}
//---------------------------------------------------------------
__int64 THOT_DMGurAllDocImpl::get_IdDocH(void)
{
return Object->IdDocH;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_IdDocH(__int64 IdDocH)
{
Object->IdDocH=IdDocH;
}
//---------------------------------------------------------------
__int64 THOT_DMGurAllDocImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
__int64 THOT_DMGurAllDocImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 THOT_DMGurAllDocImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
UnicodeString THOT_DMGurAllDocImpl::get_StringTypeDoc(void)
{
return Object->StringTypeDoc;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_StringTypeDoc(UnicodeString StringTypeDoc)
{
Object->StringTypeDoc=StringTypeDoc;
}
//---------------------------------------------------------------
bool THOT_DMGurAllDocImpl::get_OtborVkl(void)
{
return Object->OtborVkl;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_OtborVkl(bool OtborVkl)
{
Object->OtborVkl=OtborVkl;
}
//---------------------------------------------------------------
bool THOT_DMGurAllDocImpl::get_OtborPoKlient(void)
{
return Object->OtborPoKlient;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_OtborPoKlient(bool OtborPoKlient)
{
Object->OtborPoKlient=OtborPoKlient;
}
//---------------------------------------------------------------
bool THOT_DMGurAllDocImpl::get_OtborPoFirm(void)
{
return Object->OtborPoFirm;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_OtborPoFirm(bool OtborPoFirm)
{
Object->OtborPoFirm=OtborPoFirm;
}
//---------------------------------------------------------------
bool THOT_DMGurAllDocImpl::get_OtborPoSklad(void)
{
return Object->OtborPoSklad;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_OtborPoSklad(bool OtborPoSklad)
{
Object->OtborPoSklad=OtborPoSklad;
}
//---------------------------------------------------------------
bool THOT_DMGurAllDocImpl::get_OtborPoTypeDoc(void)
{
return Object->OtborPoTypeDoc;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_OtborPoTypeDoc(bool OtborPoTypeDoc)
{
Object->OtborPoTypeDoc=OtborPoTypeDoc;
}
//---------------------------------------------------------------
bool THOT_DMGurAllDocImpl::get_NoCheck(void)
{
return Object->NoCheck;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_NoCheck(bool NoCheck)
{
Object->NoCheck=NoCheck;
}
//---------------------------------------------------------------
TDateTime THOT_DMGurAllDocImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime THOT_DMGurAllDocImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::OpenTable()
{
return Object->OpenTable();
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::UpdateTable(void)
{
return Object->UpdateTable();
}

//---------------------------------------------------------------
bool THOT_DMGurAllDocImpl::CancelDvRegDoc(AnsiString type_doc, __int64 id_doc)
{
return Object->CancelDvRegDoc(type_doc, id_doc);
}
//---------------------------------------------------------------
bool THOT_DMGurAllDocImpl::DvRegDoc(AnsiString type_doc, __int64 id_doc)
{
return Object->DvRegDoc(type_doc, id_doc);
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::AllCancelDvRegDoc(void)
{
return Object->AllCancelDvRegDoc();
}
//---------------------------------------------------------------
void THOT_DMGurAllDocImpl::AllDvRegDoc(void)
{
return Object->AllDvRegDoc();
}
//---------------------------------------------------------------
