#include "vcl.h"
#pragma hdrstop


#include "UDMRegKassaImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMRegKassaImpl::TDMRegKassaImpl()           
{                                            
Object=new TDMRegKassa(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMRegKassaImpl::~TDMRegKassaImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMRegKassaImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMRegKassaImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMRegKassa)                        
   {                                                                     
   *ppv=static_cast<IDMRegKassa*> (this);                                
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
int TDMRegKassaImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMRegKassaImpl::kanRelease(void)                                  
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
int  TDMRegKassaImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMRegKassaImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMRegKassaImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMRegKassaImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMRegKassaImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMRegKassaImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMRegKassaImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMRegKassa
TpFIBDataSet * TDMRegKassaImpl::get_DvRegOst(void)
{
return Object->DvRegOst;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_DvRegOst(TpFIBDataSet * DvRegOst)
{
Object->DvRegOst=DvRegOst;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegKassaImpl::get_RegOst(void)
{
return Object->RegOst;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_RegOst(TpFIBDataSet * RegOst)
{
Object->RegOst=RegOst;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegKassaImpl::get_Dv(void)
{
return Object->Dv;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_Dv(TpFIBDataSet * Dv)
{
Object->Dv=Dv;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegKassaImpl::get_Ostatok(void)
{
return Object->Ostatok;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_Ostatok(TpFIBDataSet * Ostatok)
{
Object->Ostatok=Ostatok;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMRegKassaImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMRegKassaImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMRegKassaImpl::get_DvRegOstPOSDOC_RGKASSA_DV(void)
{
return Object->DvRegOstPOSDOC_RGKASSA_DV;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_DvRegOstPOSDOC_RGKASSA_DV(TFIBDateTimeField * DvRegOstPOSDOC_RGKASSA_DV)
{
Object->DvRegOstPOSDOC_RGKASSA_DV=DvRegOstPOSDOC_RGKASSA_DV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMRegKassaImpl::get_DvRegOstTDV_RGKASSA_DV(void)
{
return Object->DvRegOstTDV_RGKASSA_DV;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_DvRegOstTDV_RGKASSA_DV(TFIBSmallIntField * DvRegOstTDV_RGKASSA_DV)
{
Object->DvRegOstTDV_RGKASSA_DV=DvRegOstTDV_RGKASSA_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegKassaImpl::get_DvRegOstSUM_RGKASSA_DV(void)
{
return Object->DvRegOstSUM_RGKASSA_DV;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_DvRegOstSUM_RGKASSA_DV(TFIBBCDField * DvRegOstSUM_RGKASSA_DV)
{
Object->DvRegOstSUM_RGKASSA_DV=DvRegOstSUM_RGKASSA_DV;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMRegKassaImpl::get_DvRegOstOPER_RGKASSA_DV(void)
{
return Object->DvRegOstOPER_RGKASSA_DV;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_DvRegOstOPER_RGKASSA_DV(TFIBIntegerField * DvRegOstOPER_RGKASSA_DV)
{
Object->DvRegOstOPER_RGKASSA_DV=DvRegOstOPER_RGKASSA_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegKassaImpl::get_RegOstSUM_RGKASSA(void)
{
return Object->RegOstSUM_RGKASSA;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_RegOstSUM_RGKASSA(TFIBBCDField * RegOstSUM_RGKASSA)
{
Object->RegOstSUM_RGKASSA=RegOstSUM_RGKASSA;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegKassaImpl::get_DvSUMDV(void)
{
return Object->DvSUMDV;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_DvSUMDV(TFIBBCDField * DvSUMDV)
{
Object->DvSUMDV=DvSUMDV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegKassaImpl::get_OstatokSUMOST(void)
{
return Object->OstatokSUMOST;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_OstatokSUMOST(TFIBBCDField * OstatokSUMOST)
{
Object->OstatokSUMOST=OstatokSUMOST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegKassaImpl::get_RegOstID_RGKASSA(void)
{
return Object->RegOstID_RGKASSA;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_RegOstID_RGKASSA(TFIBBCDField * RegOstID_RGKASSA)
{
Object->RegOstID_RGKASSA=RegOstID_RGKASSA;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegKassaImpl::get_RegOstIDFIRM_RGKASSA(void)
{
return Object->RegOstIDFIRM_RGKASSA;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_RegOstIDFIRM_RGKASSA(TFIBBCDField * RegOstIDFIRM_RGKASSA)
{
Object->RegOstIDFIRM_RGKASSA=RegOstIDFIRM_RGKASSA;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegKassaImpl::get_RegOstIDKKM_RGKASSA(void)
{
return Object->RegOstIDKKM_RGKASSA;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_RegOstIDKKM_RGKASSA(TFIBBCDField * RegOstIDKKM_RGKASSA)
{
Object->RegOstIDKKM_RGKASSA=RegOstIDKKM_RGKASSA;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegKassaImpl::get_DvRegOstID_RGKASSA_DV(void)
{
return Object->DvRegOstID_RGKASSA_DV;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_DvRegOstID_RGKASSA_DV(TFIBBCDField * DvRegOstID_RGKASSA_DV)
{
Object->DvRegOstID_RGKASSA_DV=DvRegOstID_RGKASSA_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegKassaImpl::get_DvRegOstIDDOC_RGKASSA_DV(void)
{
return Object->DvRegOstIDDOC_RGKASSA_DV;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_DvRegOstIDDOC_RGKASSA_DV(TFIBBCDField * DvRegOstIDDOC_RGKASSA_DV)
{
Object->DvRegOstIDDOC_RGKASSA_DV=DvRegOstIDDOC_RGKASSA_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegKassaImpl::get_DvRegOstIDFIRM_RGKASSA_DV(void)
{
return Object->DvRegOstIDFIRM_RGKASSA_DV;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_DvRegOstIDFIRM_RGKASSA_DV(TFIBBCDField * DvRegOstIDFIRM_RGKASSA_DV)
{
Object->DvRegOstIDFIRM_RGKASSA_DV=DvRegOstIDFIRM_RGKASSA_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegKassaImpl::get_DvRegOstIDKKM_RGKASSA_DV(void)
{
return Object->DvRegOstIDKKM_RGKASSA_DV;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_DvRegOstIDKKM_RGKASSA_DV(TFIBBCDField * DvRegOstIDKKM_RGKASSA_DV)
{
Object->DvRegOstIDKKM_RGKASSA_DV=DvRegOstIDKKM_RGKASSA_DV;
}
//---------------------------------------------------------------
__int64 TDMRegKassaImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
TDateTime TDMRegKassaImpl::get_PosDoc(void)
{
return Object->PosDoc;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_PosDoc(TDateTime PosDoc)
{
Object->PosDoc=PosDoc;
}
//---------------------------------------------------------------
__int64 TDMRegKassaImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
__int64 TDMRegKassaImpl::get_IdKKM(void)
{
return Object->IdKKM;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_IdKKM(__int64 IdKKM)
{
Object->IdKKM=IdKKM;
}
//---------------------------------------------------------------
double TDMRegKassaImpl::get_Sum(void)
{
return Object->Sum;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_Sum(double Sum)
{
Object->Sum=Sum;
}
//---------------------------------------------------------------
int TDMRegKassaImpl::get_Operation(void)
{
return Object->Operation;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_Operation(int Operation)
{
Object->Operation=Operation;
}
//---------------------------------------------------------------
double TDMRegKassaImpl::get_SumOstNa(void)
{
return Object->SumOstNa;
}
//---------------------------------------------------------------
void TDMRegKassaImpl::set_SumOstNa(double SumOstNa)
{
Object->SumOstNa=SumOstNa;
}
//---------------------------------------------------------------
int TDMRegKassaImpl::GetOstatok(void)
{
return Object->GetOstatok();
}
//---------------------------------------------------------------
bool TDMRegKassaImpl::AddRecordPrihod(void)
{
return Object->AddRecordPrihod();
}
//---------------------------------------------------------------
bool TDMRegKassaImpl::AddRecordRashod(void)
{
return Object->AddRecordRashod();
}
//---------------------------------------------------------------
bool TDMRegKassaImpl::UpdateTableOst(void)
{
return Object->UpdateTableOst();
}
//---------------------------------------------------------------
bool TDMRegKassaImpl::CancelDvReg(void)
{
return Object->CancelDvReg();
}
//---------------------------------------------------------------
bool TDMRegKassaImpl::GetOstatokNa(TDateTime Pos, __int64 id_firm, __int64 id_kassa)
{
return Object->GetOstatokNa(Pos, id_firm, id_kassa);
}
//---------------------------------------------------------------
