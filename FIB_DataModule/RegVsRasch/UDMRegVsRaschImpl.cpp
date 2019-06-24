#include "vcl.h"
#pragma hdrstop


#include "UDMRegVsRaschImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMRegVsRaschImpl::TDMRegVsRaschImpl()           
{                                            
Object=new TDMRegVsRasch(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMRegVsRaschImpl::~TDMRegVsRaschImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMRegVsRaschImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMRegVsRaschImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMRegVsRasch)                        
   {                                                                     
   *ppv=static_cast<IDMRegVsRasch*> (this);                                
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
int TDMRegVsRaschImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMRegVsRaschImpl::kanRelease(void)                                  
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
int  TDMRegVsRaschImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMRegVsRaschImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMRegVsRaschImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMRegVsRaschImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMRegVsRaschImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMRegVsRasch
TpFIBDataSet * TDMRegVsRaschImpl::get_DvRegOst(void)
{
return Object->DvRegOst;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_DvRegOst(TpFIBDataSet * DvRegOst)
{
Object->DvRegOst=DvRegOst;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegVsRaschImpl::get_RegOst(void)
{
return Object->RegOst;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_RegOst(TpFIBDataSet * RegOst)
{
Object->RegOst=RegOst;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegVsRaschImpl::get_Dv(void)
{
return Object->Dv;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_Dv(TpFIBDataSet * Dv)
{
Object->Dv=Dv;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegVsRaschImpl::get_Ostatok(void)
{
return Object->Ostatok;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_Ostatok(TpFIBDataSet * Ostatok)
{
Object->Ostatok=Ostatok;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMRegVsRaschImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMRegVsRaschImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMRegVsRaschImpl::get_DvRegOstPOSDOC_VSRASCH_DV(void)
{
return Object->DvRegOstPOSDOC_VSRASCH_DV;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_DvRegOstPOSDOC_VSRASCH_DV(TFIBDateTimeField * DvRegOstPOSDOC_VSRASCH_DV)
{
Object->DvRegOstPOSDOC_VSRASCH_DV=DvRegOstPOSDOC_VSRASCH_DV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMRegVsRaschImpl::get_DvRegOstTDV_VSRASCH_DV(void)
{
return Object->DvRegOstTDV_VSRASCH_DV;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_DvRegOstTDV_VSRASCH_DV(TFIBSmallIntField * DvRegOstTDV_VSRASCH_DV)
{
Object->DvRegOstTDV_VSRASCH_DV=DvRegOstTDV_VSRASCH_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegVsRaschImpl::get_DvRegOstSUM_VSRASCH_DV(void)
{
return Object->DvRegOstSUM_VSRASCH_DV;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_DvRegOstSUM_VSRASCH_DV(TFIBBCDField * DvRegOstSUM_VSRASCH_DV)
{
Object->DvRegOstSUM_VSRASCH_DV=DvRegOstSUM_VSRASCH_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegVsRaschImpl::get_RegOstSUM_VSRASCH(void)
{
return Object->RegOstSUM_VSRASCH;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_RegOstSUM_VSRASCH(TFIBBCDField * RegOstSUM_VSRASCH)
{
Object->RegOstSUM_VSRASCH=RegOstSUM_VSRASCH;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegVsRaschImpl::get_DvSUMDV(void)
{
return Object->DvSUMDV;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_DvSUMDV(TFIBBCDField * DvSUMDV)
{
Object->DvSUMDV=DvSUMDV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegVsRaschImpl::get_OstatokSUMOST(void)
{
return Object->OstatokSUMOST;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_OstatokSUMOST(TFIBBCDField * OstatokSUMOST)
{
Object->OstatokSUMOST=OstatokSUMOST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegVsRaschImpl::get_RegOstID_VSRASCH(void)
{
return Object->RegOstID_VSRASCH;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_RegOstID_VSRASCH(TFIBBCDField * RegOstID_VSRASCH)
{
Object->RegOstID_VSRASCH=RegOstID_VSRASCH;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegVsRaschImpl::get_RegOstIDFIRM_VSRASCH(void)
{
return Object->RegOstIDFIRM_VSRASCH;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_RegOstIDFIRM_VSRASCH(TFIBBCDField * RegOstIDFIRM_VSRASCH)
{
Object->RegOstIDFIRM_VSRASCH=RegOstIDFIRM_VSRASCH;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegVsRaschImpl::get_RegOstIDKLIENT_VSRASCH(void)
{
return Object->RegOstIDKLIENT_VSRASCH;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_RegOstIDKLIENT_VSRASCH(TFIBBCDField * RegOstIDKLIENT_VSRASCH)
{
Object->RegOstIDKLIENT_VSRASCH=RegOstIDKLIENT_VSRASCH;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegVsRaschImpl::get_RegOstIDDOG_VSRASCH(void)
{
return Object->RegOstIDDOG_VSRASCH;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_RegOstIDDOG_VSRASCH(TFIBBCDField * RegOstIDDOG_VSRASCH)
{
Object->RegOstIDDOG_VSRASCH=RegOstIDDOG_VSRASCH;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegVsRaschImpl::get_DvRegOstID_VSRASCH_DV(void)
{
return Object->DvRegOstID_VSRASCH_DV;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_DvRegOstID_VSRASCH_DV(TFIBBCDField * DvRegOstID_VSRASCH_DV)
{
Object->DvRegOstID_VSRASCH_DV=DvRegOstID_VSRASCH_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegVsRaschImpl::get_DvRegOstIDDOC_VSRASCH_DV(void)
{
return Object->DvRegOstIDDOC_VSRASCH_DV;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_DvRegOstIDDOC_VSRASCH_DV(TFIBBCDField * DvRegOstIDDOC_VSRASCH_DV)
{
Object->DvRegOstIDDOC_VSRASCH_DV=DvRegOstIDDOC_VSRASCH_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegVsRaschImpl::get_DvRegOstIDFIRM_VSRASCH_DV(void)
{
return Object->DvRegOstIDFIRM_VSRASCH_DV;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_DvRegOstIDFIRM_VSRASCH_DV(TFIBBCDField * DvRegOstIDFIRM_VSRASCH_DV)
{
Object->DvRegOstIDFIRM_VSRASCH_DV=DvRegOstIDFIRM_VSRASCH_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegVsRaschImpl::get_DvRegOstIDKLIENT_VSRASCH_DV(void)
{
return Object->DvRegOstIDKLIENT_VSRASCH_DV;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_DvRegOstIDKLIENT_VSRASCH_DV(TFIBBCDField * DvRegOstIDKLIENT_VSRASCH_DV)
{
Object->DvRegOstIDKLIENT_VSRASCH_DV=DvRegOstIDKLIENT_VSRASCH_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegVsRaschImpl::get_DvRegOstIDDOG_VSRASCH_DV(void)
{
return Object->DvRegOstIDDOG_VSRASCH_DV;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_DvRegOstIDDOG_VSRASCH_DV(TFIBBCDField * DvRegOstIDDOG_VSRASCH_DV)
{
Object->DvRegOstIDDOG_VSRASCH_DV=DvRegOstIDDOG_VSRASCH_DV;
}
//---------------------------------------------------------------
__int64 TDMRegVsRaschImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
TDateTime TDMRegVsRaschImpl::get_PosDoc(void)
{
return Object->PosDoc;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_PosDoc(TDateTime PosDoc)
{
Object->PosDoc=PosDoc;
}
//---------------------------------------------------------------
__int64 TDMRegVsRaschImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
__int64 TDMRegVsRaschImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
float TDMRegVsRaschImpl::get_Sum(void)
{
return Object->Sum;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_Sum(float Sum)
{
Object->Sum=Sum;
}
//---------------------------------------------------------------
float TDMRegVsRaschImpl::get_SumOstNa(void)
{
return Object->SumOstNa;
}
//---------------------------------------------------------------
void TDMRegVsRaschImpl::set_SumOstNa(float SumOstNa)
{
Object->SumOstNa=SumOstNa;
}
//---------------------------------------------------------------
int TDMRegVsRaschImpl::GetOstatok(void)
{
return Object->GetOstatok();
}
//---------------------------------------------------------------
bool TDMRegVsRaschImpl::AddRecordPrihod(void)
{
return Object->AddRecordPrihod();
}
//---------------------------------------------------------------
bool TDMRegVsRaschImpl::AddRecordRashod(void)
{
return Object->AddRecordRashod();
}
//---------------------------------------------------------------
bool TDMRegVsRaschImpl::UpdateTableOst(bool provedenie)
{
return Object->UpdateTableOst(provedenie);
}
//---------------------------------------------------------------
bool TDMRegVsRaschImpl::CancelDvReg(void)
{
return Object->CancelDvReg();
}
//---------------------------------------------------------------
bool TDMRegVsRaschImpl::GetOstatokNa(TDateTime Pos, __int64 idFirm,__int64 idKlient)
{
return Object->GetOstatokNa( Pos, idFirm, idKlient);
}
//---------------------------------------------------------------
