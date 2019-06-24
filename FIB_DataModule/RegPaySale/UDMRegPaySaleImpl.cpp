#include "vcl.h"
#pragma hdrstop


#include "UDMRegPaySaleImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMRegPaySaleImpl::TDMRegPaySaleImpl()           
{                                            
Object=new TDMRegPaySale(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMRegPaySaleImpl::~TDMRegPaySaleImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMRegPaySaleImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMRegPaySaleImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMRegPaySale)                        
   {                                                                     
   *ppv=static_cast<IDMRegPaySale*> (this);                                
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
int TDMRegPaySaleImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMRegPaySaleImpl::kanRelease(void)                                  
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
int  TDMRegPaySaleImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMRegPaySaleImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMRegPaySaleImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMRegPaySaleImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMRegPaySaleImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMRegPaySale
TpFIBDataSet * TDMRegPaySaleImpl::get_DvRegOst(void)
{
return Object->DvRegOst;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_DvRegOst(TpFIBDataSet * DvRegOst)
{
Object->DvRegOst=DvRegOst;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegPaySaleImpl::get_RegOst(void)
{
return Object->RegOst;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_RegOst(TpFIBDataSet * RegOst)
{
Object->RegOst=RegOst;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMRegPaySaleImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMRegPaySaleImpl::get_DvRegOstPOS_RGPAYSALE_DV(void)
{
return Object->DvRegOstPOS_RGPAYSALE_DV;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_DvRegOstPOS_RGPAYSALE_DV(TFIBDateTimeField * DvRegOstPOS_RGPAYSALE_DV)
{
Object->DvRegOstPOS_RGPAYSALE_DV=DvRegOstPOS_RGPAYSALE_DV;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMRegPaySaleImpl::get_DvRegOstTDV_RGPAYSALE_DV(void)
{
return Object->DvRegOstTDV_RGPAYSALE_DV;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_DvRegOstTDV_RGPAYSALE_DV(TFIBIntegerField * DvRegOstTDV_RGPAYSALE_DV)
{
Object->DvRegOstTDV_RGPAYSALE_DV=DvRegOstTDV_RGPAYSALE_DV;
}
//---------------------------------------------------------------
TFIBDateField * TDMRegPaySaleImpl::get_DvRegOstDATE_RGPAYSALE_DV(void)
{
return Object->DvRegOstDATE_RGPAYSALE_DV;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_DvRegOstDATE_RGPAYSALE_DV(TFIBDateField * DvRegOstDATE_RGPAYSALE_DV)
{
Object->DvRegOstDATE_RGPAYSALE_DV=DvRegOstDATE_RGPAYSALE_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegPaySaleImpl::get_DvRegOstSUM_RGPAYSALE_DV(void)
{
return Object->DvRegOstSUM_RGPAYSALE_DV;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_DvRegOstSUM_RGPAYSALE_DV(TFIBBCDField * DvRegOstSUM_RGPAYSALE_DV)
{
Object->DvRegOstSUM_RGPAYSALE_DV=DvRegOstSUM_RGPAYSALE_DV;
}
//---------------------------------------------------------------
TFIBDateField * TDMRegPaySaleImpl::get_RegOstDATE_RGPAYSALE(void)
{
return Object->RegOstDATE_RGPAYSALE;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_RegOstDATE_RGPAYSALE(TFIBDateField * RegOstDATE_RGPAYSALE)
{
Object->RegOstDATE_RGPAYSALE=RegOstDATE_RGPAYSALE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegPaySaleImpl::get_RegOstSUM_RGPAYSALE(void)
{
return Object->RegOstSUM_RGPAYSALE;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_RegOstSUM_RGPAYSALE(TFIBBCDField * RegOstSUM_RGPAYSALE)
{
Object->RegOstSUM_RGPAYSALE=RegOstSUM_RGPAYSALE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegPaySaleImpl::get_RegOstID_RGPAYSALE(void)
{
return Object->RegOstID_RGPAYSALE;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_RegOstID_RGPAYSALE(TFIBBCDField * RegOstID_RGPAYSALE)
{
Object->RegOstID_RGPAYSALE=RegOstID_RGPAYSALE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegPaySaleImpl::get_RegOstIDFIRM_RGPAYSALE(void)
{
return Object->RegOstIDFIRM_RGPAYSALE;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_RegOstIDFIRM_RGPAYSALE(TFIBBCDField * RegOstIDFIRM_RGPAYSALE)
{
Object->RegOstIDFIRM_RGPAYSALE=RegOstIDFIRM_RGPAYSALE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegPaySaleImpl::get_RegOstIDKLIENT_RGPAYSALE(void)
{
return Object->RegOstIDKLIENT_RGPAYSALE;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_RegOstIDKLIENT_RGPAYSALE(TFIBBCDField * RegOstIDKLIENT_RGPAYSALE)
{
Object->RegOstIDKLIENT_RGPAYSALE=RegOstIDKLIENT_RGPAYSALE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegPaySaleImpl::get_RegOstIDDOG_RGPAYSALE(void)
{
return Object->RegOstIDDOG_RGPAYSALE;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_RegOstIDDOG_RGPAYSALE(TFIBBCDField * RegOstIDDOG_RGPAYSALE)
{
Object->RegOstIDDOG_RGPAYSALE=RegOstIDDOG_RGPAYSALE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegPaySaleImpl::get_RegOstIDDOCSALE_RGPAYSALE(void)
{
return Object->RegOstIDDOCSALE_RGPAYSALE;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_RegOstIDDOCSALE_RGPAYSALE(TFIBBCDField * RegOstIDDOCSALE_RGPAYSALE)
{
Object->RegOstIDDOCSALE_RGPAYSALE=RegOstIDDOCSALE_RGPAYSALE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegPaySaleImpl::get_DvRegOstID_RGPAYSALE_DV(void)
{
return Object->DvRegOstID_RGPAYSALE_DV;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_DvRegOstID_RGPAYSALE_DV(TFIBBCDField * DvRegOstID_RGPAYSALE_DV)
{
Object->DvRegOstID_RGPAYSALE_DV=DvRegOstID_RGPAYSALE_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegPaySaleImpl::get_DvRegOstIDDOC_RGPAYSALE_DV(void)
{
return Object->DvRegOstIDDOC_RGPAYSALE_DV;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_DvRegOstIDDOC_RGPAYSALE_DV(TFIBBCDField * DvRegOstIDDOC_RGPAYSALE_DV)
{
Object->DvRegOstIDDOC_RGPAYSALE_DV=DvRegOstIDDOC_RGPAYSALE_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegPaySaleImpl::get_DvRegOstIDFIRM_RGPAYSALE_DV(void)
{
return Object->DvRegOstIDFIRM_RGPAYSALE_DV;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_DvRegOstIDFIRM_RGPAYSALE_DV(TFIBBCDField * DvRegOstIDFIRM_RGPAYSALE_DV)
{
Object->DvRegOstIDFIRM_RGPAYSALE_DV=DvRegOstIDFIRM_RGPAYSALE_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegPaySaleImpl::get_DvRegOstIDKLIENT_RGPAYSALE_DV(void)
{
return Object->DvRegOstIDKLIENT_RGPAYSALE_DV;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_DvRegOstIDKLIENT_RGPAYSALE_DV(TFIBBCDField * DvRegOstIDKLIENT_RGPAYSALE_DV)
{
Object->DvRegOstIDKLIENT_RGPAYSALE_DV=DvRegOstIDKLIENT_RGPAYSALE_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegPaySaleImpl::get_DvRegOstIDDOG_RGPAYSALE_DV(void)
{
return Object->DvRegOstIDDOG_RGPAYSALE_DV;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_DvRegOstIDDOG_RGPAYSALE_DV(TFIBBCDField * DvRegOstIDDOG_RGPAYSALE_DV)
{
Object->DvRegOstIDDOG_RGPAYSALE_DV=DvRegOstIDDOG_RGPAYSALE_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegPaySaleImpl::get_DvRegOstIDDOCSALE_RGPAYSALE_DV(void)
{
return Object->DvRegOstIDDOCSALE_RGPAYSALE_DV;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_DvRegOstIDDOCSALE_RGPAYSALE_DV(TFIBBCDField * DvRegOstIDDOCSALE_RGPAYSALE_DV)
{
Object->DvRegOstIDDOCSALE_RGPAYSALE_DV=DvRegOstIDDOCSALE_RGPAYSALE_DV;
}
//---------------------------------------------------------------
__int64 TDMRegPaySaleImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
TDateTime TDMRegPaySaleImpl::get_PosDoc(void)
{
return Object->PosDoc;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_PosDoc(TDateTime PosDoc)
{
Object->PosDoc=PosDoc;
}
//---------------------------------------------------------------
__int64 TDMRegPaySaleImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
__int64 TDMRegPaySaleImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
__int64 TDMRegPaySaleImpl::get_IdDogovor(void)
{
return Object->IdDogovor;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_IdDogovor(__int64 IdDogovor)
{
Object->IdDogovor=IdDogovor;
}
//---------------------------------------------------------------
__int64 TDMRegPaySaleImpl::get_IdDocSale(void)
{
return Object->IdDocSale;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_IdDocSale(__int64 IdDocSale)
{
Object->IdDocSale=IdDocSale;
}
//---------------------------------------------------------------
TDate TDMRegPaySaleImpl::get_DatePay(void)
{
return Object->DatePay;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_DatePay(TDate DatePay)
{
Object->DatePay=DatePay;
}
//---------------------------------------------------------------
float TDMRegPaySaleImpl::get_Sum(void)
{
return Object->Sum;
}
//---------------------------------------------------------------
void TDMRegPaySaleImpl::set_Sum(float Sum)
{
Object->Sum=Sum;
}
//---------------------------------------------------------------
bool TDMRegPaySaleImpl::AddRecordPrihod(void)
{
return Object->AddRecordPrihod();
}
//---------------------------------------------------------------
bool TDMRegPaySaleImpl::AddRecordRashod(void)
{
return Object->AddRecordRashod();
}
//---------------------------------------------------------------
bool TDMRegPaySaleImpl::UpdateTableOst(void)
{
return Object->UpdateTableOst();
}
//---------------------------------------------------------------
bool TDMRegPaySaleImpl::CancelDvReg(void)
{
return Object->CancelDvReg();
}
//---------------------------------------------------------------
