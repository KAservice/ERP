#include "vcl.h"
#pragma hdrstop


#include "UDMRegAdvanceCustomerImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMRegAdvanceCustomerImpl::TDMRegAdvanceCustomerImpl()           
{                                            
Object=new TDMRegAdvanceCustomer(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMRegAdvanceCustomerImpl::~TDMRegAdvanceCustomerImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMRegAdvanceCustomerImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMRegAdvanceCustomer)                        
   {                                                                     
   *ppv=static_cast<IDMRegAdvanceCustomer*> (this);                                
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
int TDMRegAdvanceCustomerImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMRegAdvanceCustomerImpl::kanRelease(void)                                  
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
int  TDMRegAdvanceCustomerImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMRegAdvanceCustomerImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMRegAdvanceCustomerImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMRegAdvanceCustomerImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMRegAdvanceCustomerImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMRegAdvanceCustomer
TpFIBDataSet * TDMRegAdvanceCustomerImpl::get_DvRegOst(void)
{
return Object->DvRegOst;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_DvRegOst(TpFIBDataSet * DvRegOst)
{
Object->DvRegOst=DvRegOst;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMRegAdvanceCustomerImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegAdvanceCustomerImpl::get_RegOst(void)
{
return Object->RegOst;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_RegOst(TpFIBDataSet * RegOst)
{
Object->RegOst=RegOst;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMRegAdvanceCustomerImpl::get_DvRegOstPOS_RGADVCUST_DV(void)
{
return Object->DvRegOstPOS_RGADVCUST_DV;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_DvRegOstPOS_RGADVCUST_DV(TFIBDateTimeField * DvRegOstPOS_RGADVCUST_DV)
{
Object->DvRegOstPOS_RGADVCUST_DV=DvRegOstPOS_RGADVCUST_DV;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMRegAdvanceCustomerImpl::get_DvRegOstTDV_RGADVCUST_DV(void)
{
return Object->DvRegOstTDV_RGADVCUST_DV;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_DvRegOstTDV_RGADVCUST_DV(TFIBIntegerField * DvRegOstTDV_RGADVCUST_DV)
{
Object->DvRegOstTDV_RGADVCUST_DV=DvRegOstTDV_RGADVCUST_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegAdvanceCustomerImpl::get_DvRegOstSUM_RGADVCUST_DV(void)
{
return Object->DvRegOstSUM_RGADVCUST_DV;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_DvRegOstSUM_RGADVCUST_DV(TFIBBCDField * DvRegOstSUM_RGADVCUST_DV)
{
Object->DvRegOstSUM_RGADVCUST_DV=DvRegOstSUM_RGADVCUST_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegAdvanceCustomerImpl::get_RegOstSUM_RGADVCUST(void)
{
return Object->RegOstSUM_RGADVCUST;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_RegOstSUM_RGADVCUST(TFIBBCDField * RegOstSUM_RGADVCUST)
{
Object->RegOstSUM_RGADVCUST=RegOstSUM_RGADVCUST;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMRegAdvanceCustomerImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegAdvanceCustomerImpl::get_DvRegOstID_RGADVCUST_DV(void)
{
return Object->DvRegOstID_RGADVCUST_DV;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_DvRegOstID_RGADVCUST_DV(TFIBBCDField * DvRegOstID_RGADVCUST_DV)
{
Object->DvRegOstID_RGADVCUST_DV=DvRegOstID_RGADVCUST_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegAdvanceCustomerImpl::get_DvRegOstIDDOC_RGADVCUST_DV(void)
{
return Object->DvRegOstIDDOC_RGADVCUST_DV;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_DvRegOstIDDOC_RGADVCUST_DV(TFIBBCDField * DvRegOstIDDOC_RGADVCUST_DV)
{
Object->DvRegOstIDDOC_RGADVCUST_DV=DvRegOstIDDOC_RGADVCUST_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegAdvanceCustomerImpl::get_DvRegOstIDFIRM_RGADVCUST_DV(void)
{
return Object->DvRegOstIDFIRM_RGADVCUST_DV;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_DvRegOstIDFIRM_RGADVCUST_DV(TFIBBCDField * DvRegOstIDFIRM_RGADVCUST_DV)
{
Object->DvRegOstIDFIRM_RGADVCUST_DV=DvRegOstIDFIRM_RGADVCUST_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegAdvanceCustomerImpl::get_DvRegOstIDKLIENT_RGADVCUST_DV(void)
{
return Object->DvRegOstIDKLIENT_RGADVCUST_DV;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_DvRegOstIDKLIENT_RGADVCUST_DV(TFIBBCDField * DvRegOstIDKLIENT_RGADVCUST_DV)
{
Object->DvRegOstIDKLIENT_RGADVCUST_DV=DvRegOstIDKLIENT_RGADVCUST_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegAdvanceCustomerImpl::get_RegOstID_RGADVCUST(void)
{
return Object->RegOstID_RGADVCUST;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_RegOstID_RGADVCUST(TFIBBCDField * RegOstID_RGADVCUST)
{
Object->RegOstID_RGADVCUST=RegOstID_RGADVCUST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegAdvanceCustomerImpl::get_RegOstIDFIRM_RGADVCUST(void)
{
return Object->RegOstIDFIRM_RGADVCUST;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_RegOstIDFIRM_RGADVCUST(TFIBBCDField * RegOstIDFIRM_RGADVCUST)
{
Object->RegOstIDFIRM_RGADVCUST=RegOstIDFIRM_RGADVCUST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegAdvanceCustomerImpl::get_RegOstIDKLIENT_RGADVCUST(void)
{
return Object->RegOstIDKLIENT_RGADVCUST;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_RegOstIDKLIENT_RGADVCUST(TFIBBCDField * RegOstIDKLIENT_RGADVCUST)
{
Object->RegOstIDKLIENT_RGADVCUST=RegOstIDKLIENT_RGADVCUST;
}
//---------------------------------------------------------------
__int64 TDMRegAdvanceCustomerImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
TDateTime TDMRegAdvanceCustomerImpl::get_PosDoc(void)
{
return Object->PosDoc;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_PosDoc(TDateTime PosDoc)
{
Object->PosDoc=PosDoc;
}
//---------------------------------------------------------------
__int64 TDMRegAdvanceCustomerImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
__int64 TDMRegAdvanceCustomerImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
float TDMRegAdvanceCustomerImpl::get_Sum(void)
{
return Object->Sum;
}
//---------------------------------------------------------------
void TDMRegAdvanceCustomerImpl::set_Sum(float Sum)
{
Object->Sum=Sum;
}
//---------------------------------------------------------------
bool TDMRegAdvanceCustomerImpl::AddRecordPrihod(void)
{
return Object->AddRecordPrihod();
}
//---------------------------------------------------------------
bool TDMRegAdvanceCustomerImpl::AddRecordRashod(void)
{
return Object->AddRecordRashod();
}
//---------------------------------------------------------------
bool TDMRegAdvanceCustomerImpl::UpdateTableOst(void)
{
return Object->UpdateTableOst();
}
//---------------------------------------------------------------
bool TDMRegAdvanceCustomerImpl::CancelDvReg(void)
{
return Object->CancelDvReg();
}
//---------------------------------------------------------------
double TDMRegAdvanceCustomerImpl::GetOstatokAdvance(__int64 id_firm, __int64 id_klient)
{
return Object->GetOstatokAdvance(id_firm,id_klient);
}
//---------------------------------------------------------------
