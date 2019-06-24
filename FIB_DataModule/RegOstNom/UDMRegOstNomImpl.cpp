#include "vcl.h"
#pragma hdrstop


#include "UDMRegOstNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMRegOstNomImpl::TDMRegOstNomImpl()           
{                                            
Object=new TDMRegOstNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMRegOstNomImpl::~TDMRegOstNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMRegOstNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMRegOstNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMRegOstNom)                        
   {                                                                     
   *ppv=static_cast<IDMRegOstNom*> (this);                                
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
int TDMRegOstNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMRegOstNomImpl::kanRelease(void)                                  
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
int  TDMRegOstNomImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMRegOstNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMRegOstNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMRegOstNomImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMRegOstNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMRegOstNom
TpFIBDataSet * TDMRegOstNomImpl::get_DvRegOst(void)
{
return Object->DvRegOst;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvRegOst(TpFIBDataSet * DvRegOst)
{
Object->DvRegOst=DvRegOst;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegOstNomImpl::get_RegOst(void)
{
return Object->RegOst;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_RegOst(TpFIBDataSet * RegOst)
{
Object->RegOst=RegOst;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegOstNomImpl::get_DvNom(void)
{
return Object->DvNom;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvNom(TpFIBDataSet * DvNom)
{
Object->DvNom=DvNom;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegOstNomImpl::get_Ostatok(void)
{
return Object->Ostatok;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_Ostatok(TpFIBDataSet * Ostatok)
{
Object->Ostatok=Ostatok;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMRegOstNomImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMRegOstNomImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMRegOstNomImpl::get_DvRegOstPOSDOC_OSTNOMDV(void)
{
return Object->DvRegOstPOSDOC_OSTNOMDV;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvRegOstPOSDOC_OSTNOMDV(TFIBDateTimeField * DvRegOstPOSDOC_OSTNOMDV)
{
Object->DvRegOstPOSDOC_OSTNOMDV=DvRegOstPOSDOC_OSTNOMDV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMRegOstNomImpl::get_DvRegOstTDV_OSTNOMDV(void)
{
return Object->DvRegOstTDV_OSTNOMDV;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvRegOstTDV_OSTNOMDV(TFIBSmallIntField * DvRegOstTDV_OSTNOMDV)
{
Object->DvRegOstTDV_OSTNOMDV=DvRegOstTDV_OSTNOMDV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_DvRegOstSUM_OSTNOMDV(void)
{
return Object->DvRegOstSUM_OSTNOMDV;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvRegOstSUM_OSTNOMDV(TFIBBCDField * DvRegOstSUM_OSTNOMDV)
{
Object->DvRegOstSUM_OSTNOMDV=DvRegOstSUM_OSTNOMDV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_DvRegOstKOL_OSTNOMDV(void)
{
return Object->DvRegOstKOL_OSTNOMDV;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvRegOstKOL_OSTNOMDV(TFIBBCDField * DvRegOstKOL_OSTNOMDV)
{
Object->DvRegOstKOL_OSTNOMDV=DvRegOstKOL_OSTNOMDV;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMRegOstNomImpl::get_DvRegOstOPER_OSTNOMDV(void)
{
return Object->DvRegOstOPER_OSTNOMDV;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvRegOstOPER_OSTNOMDV(TFIBIntegerField * DvRegOstOPER_OSTNOMDV)
{
Object->DvRegOstOPER_OSTNOMDV=DvRegOstOPER_OSTNOMDV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_DvRegOstSUM2_OSTNOMDV(void)
{
return Object->DvRegOstSUM2_OSTNOMDV;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvRegOstSUM2_OSTNOMDV(TFIBBCDField * DvRegOstSUM2_OSTNOMDV)
{
Object->DvRegOstSUM2_OSTNOMDV=DvRegOstSUM2_OSTNOMDV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_RegOstSUMOSTNOM(void)
{
return Object->RegOstSUMOSTNOM;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_RegOstSUMOSTNOM(TFIBBCDField * RegOstSUMOSTNOM)
{
Object->RegOstSUMOSTNOM=RegOstSUMOSTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_RegOstKOLOSTNOM(void)
{
return Object->RegOstKOLOSTNOM;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_RegOstKOLOSTNOM(TFIBBCDField * RegOstKOLOSTNOM)
{
Object->RegOstKOLOSTNOM=RegOstKOLOSTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_DvNomKOLDV(void)
{
return Object->DvNomKOLDV;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvNomKOLDV(TFIBBCDField * DvNomKOLDV)
{
Object->DvNomKOLDV=DvNomKOLDV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_DvNomSUMDV(void)
{
return Object->DvNomSUMDV;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvNomSUMDV(TFIBBCDField * DvNomSUMDV)
{
Object->DvNomSUMDV=DvNomSUMDV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_OstatokKOLOST(void)
{
return Object->OstatokKOLOST;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_OstatokKOLOST(TFIBBCDField * OstatokKOLOST)
{
Object->OstatokKOLOST=OstatokKOLOST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_OstatokSUMOST(void)
{
return Object->OstatokSUMOST;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_OstatokSUMOST(TFIBBCDField * OstatokSUMOST)
{
Object->OstatokSUMOST=OstatokSUMOST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_RegOstIDOSTNOM(void)
{
return Object->RegOstIDOSTNOM;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_RegOstIDOSTNOM(TFIBBCDField * RegOstIDOSTNOM)
{
Object->RegOstIDOSTNOM=RegOstIDOSTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_RegOstIDFIRMOSTNOM(void)
{
return Object->RegOstIDFIRMOSTNOM;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_RegOstIDFIRMOSTNOM(TFIBBCDField * RegOstIDFIRMOSTNOM)
{
Object->RegOstIDFIRMOSTNOM=RegOstIDFIRMOSTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_RegOstIDSKLOSTNOM(void)
{
return Object->RegOstIDSKLOSTNOM;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_RegOstIDSKLOSTNOM(TFIBBCDField * RegOstIDSKLOSTNOM)
{
Object->RegOstIDSKLOSTNOM=RegOstIDSKLOSTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_RegOstIDNOMOSTNOM(void)
{
return Object->RegOstIDNOMOSTNOM;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_RegOstIDNOMOSTNOM(TFIBBCDField * RegOstIDNOMOSTNOM)
{
Object->RegOstIDNOMOSTNOM=RegOstIDNOMOSTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_RegOstIDPARTOSTNOM(void)
{
return Object->RegOstIDPARTOSTNOM;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_RegOstIDPARTOSTNOM(TFIBBCDField * RegOstIDPARTOSTNOM)
{
Object->RegOstIDPARTOSTNOM=RegOstIDPARTOSTNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_DvRegOstID_OSTNOMDV(void)
{
return Object->DvRegOstID_OSTNOMDV;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvRegOstID_OSTNOMDV(TFIBBCDField * DvRegOstID_OSTNOMDV)
{
Object->DvRegOstID_OSTNOMDV=DvRegOstID_OSTNOMDV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_DvRegOstIDDOC_OSTNOMDV(void)
{
return Object->DvRegOstIDDOC_OSTNOMDV;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvRegOstIDDOC_OSTNOMDV(TFIBBCDField * DvRegOstIDDOC_OSTNOMDV)
{
Object->DvRegOstIDDOC_OSTNOMDV=DvRegOstIDDOC_OSTNOMDV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_DvRegOstIDFIRM_OSTNOMDV(void)
{
return Object->DvRegOstIDFIRM_OSTNOMDV;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvRegOstIDFIRM_OSTNOMDV(TFIBBCDField * DvRegOstIDFIRM_OSTNOMDV)
{
Object->DvRegOstIDFIRM_OSTNOMDV=DvRegOstIDFIRM_OSTNOMDV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_DvRegOstIDSKL_OSTNOMDV(void)
{
return Object->DvRegOstIDSKL_OSTNOMDV;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvRegOstIDSKL_OSTNOMDV(TFIBBCDField * DvRegOstIDSKL_OSTNOMDV)
{
Object->DvRegOstIDSKL_OSTNOMDV=DvRegOstIDSKL_OSTNOMDV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_DvRegOstIDNOM_OSTNOMDV(void)
{
return Object->DvRegOstIDNOM_OSTNOMDV;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvRegOstIDNOM_OSTNOMDV(TFIBBCDField * DvRegOstIDNOM_OSTNOMDV)
{
Object->DvRegOstIDNOM_OSTNOMDV=DvRegOstIDNOM_OSTNOMDV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_DvRegOstIDPART_OSTNOMDV(void)
{
return Object->DvRegOstIDPART_OSTNOMDV;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvRegOstIDPART_OSTNOMDV(TFIBBCDField * DvRegOstIDPART_OSTNOMDV)
{
Object->DvRegOstIDPART_OSTNOMDV=DvRegOstIDPART_OSTNOMDV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegOstNomImpl::get_DvRegOstIDSTRDOC_OSTNOMDV(void)
{
return Object->DvRegOstIDSTRDOC_OSTNOMDV;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_DvRegOstIDSTRDOC_OSTNOMDV(TFIBBCDField * DvRegOstIDSTRDOC_OSTNOMDV)
{
Object->DvRegOstIDSTRDOC_OSTNOMDV=DvRegOstIDSTRDOC_OSTNOMDV;
}
//---------------------------------------------------------------
__int64 TDMRegOstNomImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
__int64 TDMRegOstNomImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TDMRegOstNomImpl::get_IdNom(void)
{
return Object->IdNom;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_IdNom(__int64 IdNom)
{
Object->IdNom=IdNom;
}
//---------------------------------------------------------------
float TDMRegOstNomImpl::get_SumOst(void)
{
return Object->SumOst;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_SumOst(float SumOst)
{
Object->SumOst=SumOst;
}
//---------------------------------------------------------------
float TDMRegOstNomImpl::get_KolOst(void)
{
return Object->KolOst;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_KolOst(float KolOst)
{
Object->KolOst=KolOst;
}
//---------------------------------------------------------------
__int64 TDMRegOstNomImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
TDateTime TDMRegOstNomImpl::get_PosDoc(void)
{
return Object->PosDoc;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_PosDoc(TDateTime PosDoc)
{
Object->PosDoc=PosDoc;
}
//---------------------------------------------------------------
__int64 TDMRegOstNomImpl::get_IdPart(void)
{
return Object->IdPart;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_IdPart(__int64 IdPart)
{
Object->IdPart=IdPart;
}
//---------------------------------------------------------------
__int64 TDMRegOstNomImpl::get_IdStr(void)
{
return Object->IdStr;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_IdStr(__int64 IdStr)
{
Object->IdStr=IdStr;
}
//---------------------------------------------------------------
float TDMRegOstNomImpl::get_Kol(void)
{
return Object->Kol;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_Kol(float Kol)
{
Object->Kol=Kol;
}
//---------------------------------------------------------------
float TDMRegOstNomImpl::get_Sum(void)
{
return Object->Sum;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_Sum(float Sum)
{
Object->Sum=Sum;
}
//---------------------------------------------------------------
int TDMRegOstNomImpl::get_Operation(void)
{
return Object->Operation;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_Operation(int Operation)
{
Object->Operation=Operation;
}
//---------------------------------------------------------------
float TDMRegOstNomImpl::get_Sum2(void)
{
return Object->Sum2;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_Sum2(float Sum2)
{
Object->Sum2=Sum2;
}
//---------------------------------------------------------------
float TDMRegOstNomImpl::get_SumOstNa(void)
{
return Object->SumOstNa;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_SumOstNa(float SumOstNa)
{
Object->SumOstNa=SumOstNa;
}
//---------------------------------------------------------------
float TDMRegOstNomImpl::get_KolOstNa(void)
{
return Object->KolOstNa;
}
//---------------------------------------------------------------
void TDMRegOstNomImpl::set_KolOstNa(float KolOstNa)
{
Object->KolOstNa=KolOstNa;
}
//---------------------------------------------------------------
int TDMRegOstNomImpl::GetOstatok(void)
{
return Object->GetOstatok();
}
//---------------------------------------------------------------
bool TDMRegOstNomImpl::AddRecordPrihod(void)
{
return Object->AddRecordPrihod();
}
//---------------------------------------------------------------
bool TDMRegOstNomImpl::AddRecordRashod(void)
{
return Object->AddRecordRashod();
}
//---------------------------------------------------------------
bool TDMRegOstNomImpl::UpdateTableOst(void)
{
return Object->UpdateTableOst();
}
//---------------------------------------------------------------
bool TDMRegOstNomImpl::CancelDvReg(void)
{
return Object->CancelDvReg();
}
//---------------------------------------------------------------
bool TDMRegOstNomImpl::GetOstatokNa(TDateTime Pos, __int64 idFirm, __int64 idSklad, __int64 idNom)
{
return Object->GetOstatokNa(Pos, idFirm, idSklad, idNom);
}
//---------------------------------------------------------------
