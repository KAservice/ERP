#include "vcl.h"
#pragma hdrstop


#include "UDMRegBankImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMRegBankImpl::TDMRegBankImpl()           
{                                            
Object=new TDMRegBank(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMRegBankImpl::~TDMRegBankImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMRegBankImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMRegBankImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMRegBank)                        
   {                                                                     
   *ppv=static_cast<IDMRegBank*> (this);                                
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
int TDMRegBankImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMRegBankImpl::kanRelease(void)                                  
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
int  TDMRegBankImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMRegBankImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMRegBankImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMRegBankImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMRegBankImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMRegBankImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMRegBankImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMRegBank
TpFIBDataSet * TDMRegBankImpl::get_DvRegOst(void)
{
return Object->DvRegOst;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_DvRegOst(TpFIBDataSet * DvRegOst)
{
Object->DvRegOst=DvRegOst;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegBankImpl::get_RegOst(void)
{
return Object->RegOst;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_RegOst(TpFIBDataSet * RegOst)
{
Object->RegOst=RegOst;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegBankImpl::get_Dv(void)
{
return Object->Dv;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_Dv(TpFIBDataSet * Dv)
{
Object->Dv=Dv;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegBankImpl::get_Ostatok(void)
{
return Object->Ostatok;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_Ostatok(TpFIBDataSet * Ostatok)
{
Object->Ostatok=Ostatok;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMRegBankImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMRegBankImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMRegBankImpl::get_DvRegOstPOSDOC_RGBANK_DV(void)
{
return Object->DvRegOstPOSDOC_RGBANK_DV;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_DvRegOstPOSDOC_RGBANK_DV(TFIBDateTimeField * DvRegOstPOSDOC_RGBANK_DV)
{
Object->DvRegOstPOSDOC_RGBANK_DV=DvRegOstPOSDOC_RGBANK_DV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMRegBankImpl::get_DvRegOstTDV_RGBANK_DV(void)
{
return Object->DvRegOstTDV_RGBANK_DV;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_DvRegOstTDV_RGBANK_DV(TFIBSmallIntField * DvRegOstTDV_RGBANK_DV)
{
Object->DvRegOstTDV_RGBANK_DV=DvRegOstTDV_RGBANK_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegBankImpl::get_DvRegOstSUM_RGBANK_DV(void)
{
return Object->DvRegOstSUM_RGBANK_DV;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_DvRegOstSUM_RGBANK_DV(TFIBBCDField * DvRegOstSUM_RGBANK_DV)
{
Object->DvRegOstSUM_RGBANK_DV=DvRegOstSUM_RGBANK_DV;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMRegBankImpl::get_DvRegOstOPER_RGBANK_DV(void)
{
return Object->DvRegOstOPER_RGBANK_DV;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_DvRegOstOPER_RGBANK_DV(TFIBIntegerField * DvRegOstOPER_RGBANK_DV)
{
Object->DvRegOstOPER_RGBANK_DV=DvRegOstOPER_RGBANK_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegBankImpl::get_RegOstSUM_RGBANK(void)
{
return Object->RegOstSUM_RGBANK;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_RegOstSUM_RGBANK(TFIBBCDField * RegOstSUM_RGBANK)
{
Object->RegOstSUM_RGBANK=RegOstSUM_RGBANK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegBankImpl::get_DvSUMDV(void)
{
return Object->DvSUMDV;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_DvSUMDV(TFIBBCDField * DvSUMDV)
{
Object->DvSUMDV=DvSUMDV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegBankImpl::get_OstatokSUMOST(void)
{
return Object->OstatokSUMOST;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_OstatokSUMOST(TFIBBCDField * OstatokSUMOST)
{
Object->OstatokSUMOST=OstatokSUMOST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegBankImpl::get_RegOstID_RGBANK(void)
{
return Object->RegOstID_RGBANK;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_RegOstID_RGBANK(TFIBBCDField * RegOstID_RGBANK)
{
Object->RegOstID_RGBANK=RegOstID_RGBANK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegBankImpl::get_RegOstIDFIRM_RGBANK(void)
{
return Object->RegOstIDFIRM_RGBANK;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_RegOstIDFIRM_RGBANK(TFIBBCDField * RegOstIDFIRM_RGBANK)
{
Object->RegOstIDFIRM_RGBANK=RegOstIDFIRM_RGBANK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegBankImpl::get_RegOstIDBSCHET_RGBANK(void)
{
return Object->RegOstIDBSCHET_RGBANK;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_RegOstIDBSCHET_RGBANK(TFIBBCDField * RegOstIDBSCHET_RGBANK)
{
Object->RegOstIDBSCHET_RGBANK=RegOstIDBSCHET_RGBANK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegBankImpl::get_DvRegOstID_RGBANK_DV(void)
{
return Object->DvRegOstID_RGBANK_DV;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_DvRegOstID_RGBANK_DV(TFIBBCDField * DvRegOstID_RGBANK_DV)
{
Object->DvRegOstID_RGBANK_DV=DvRegOstID_RGBANK_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegBankImpl::get_DvRegOstIDDOC_RGBANK_DV(void)
{
return Object->DvRegOstIDDOC_RGBANK_DV;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_DvRegOstIDDOC_RGBANK_DV(TFIBBCDField * DvRegOstIDDOC_RGBANK_DV)
{
Object->DvRegOstIDDOC_RGBANK_DV=DvRegOstIDDOC_RGBANK_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegBankImpl::get_DvRegOstIDFIRM_RGBANK_DV(void)
{
return Object->DvRegOstIDFIRM_RGBANK_DV;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_DvRegOstIDFIRM_RGBANK_DV(TFIBBCDField * DvRegOstIDFIRM_RGBANK_DV)
{
Object->DvRegOstIDFIRM_RGBANK_DV=DvRegOstIDFIRM_RGBANK_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegBankImpl::get_DvRegOstIDBSCHET_RGBANK_DV(void)
{
return Object->DvRegOstIDBSCHET_RGBANK_DV;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_DvRegOstIDBSCHET_RGBANK_DV(TFIBBCDField * DvRegOstIDBSCHET_RGBANK_DV)
{
Object->DvRegOstIDBSCHET_RGBANK_DV=DvRegOstIDBSCHET_RGBANK_DV;
}
//---------------------------------------------------------------
__int64 TDMRegBankImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
TDateTime TDMRegBankImpl::get_PosDoc(void)
{
return Object->PosDoc;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_PosDoc(TDateTime PosDoc)
{
Object->PosDoc=PosDoc;
}
//---------------------------------------------------------------
__int64 TDMRegBankImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
__int64 TDMRegBankImpl::get_IdBSchet(void)
{
return Object->IdBSchet;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_IdBSchet(__int64 IdBSchet)
{
Object->IdBSchet=IdBSchet;
}
//---------------------------------------------------------------
float TDMRegBankImpl::get_Sum(void)
{
return Object->Sum;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_Sum(float Sum)
{
Object->Sum=Sum;
}
//---------------------------------------------------------------
int TDMRegBankImpl::get_Operation(void)
{
return Object->Operation;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_Operation(int Operation)
{
Object->Operation=Operation;
}
//---------------------------------------------------------------
double TDMRegBankImpl::get_SumOstNa(void)
{
return Object->SumOstNa;
}
//---------------------------------------------------------------
void TDMRegBankImpl::set_SumOstNa(double SumOstNa)
{
Object->SumOstNa=SumOstNa;
}
//---------------------------------------------------------------
int TDMRegBankImpl::GetOstatok(void)
{
return Object->GetOstatok();
}
//---------------------------------------------------------------
bool TDMRegBankImpl::AddRecordPrihod(void)
{
return Object->AddRecordPrihod();
}
//---------------------------------------------------------------
bool TDMRegBankImpl::AddRecordRashod(void)
{
return Object->AddRecordRashod();
}
//---------------------------------------------------------------
bool TDMRegBankImpl::UpdateTableOst(void)
{
return Object->UpdateTableOst();
}
//---------------------------------------------------------------
bool TDMRegBankImpl::CancelDvReg(void)
{
return Object->CancelDvReg();
}
//---------------------------------------------------------------
bool TDMRegBankImpl::GetOstatokNa(TDateTime Pos, __int64 id_firm, __int64 id_bschet)
{
return Object->GetOstatokNa(Pos, id_firm, id_bschet);
}
//---------------------------------------------------------------
