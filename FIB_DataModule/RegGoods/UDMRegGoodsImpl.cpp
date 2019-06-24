#include "vcl.h"
#pragma hdrstop


#include "UDMRegGoodsImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMRegGoodsImpl::TDMRegGoodsImpl()           
{                                            
Object=new TDMRegGoods(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMRegGoodsImpl::~TDMRegGoodsImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMRegGoodsImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMRegGoodsImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMRegGoods)                        
   {                                                                     
   *ppv=static_cast<IDMRegGoods*> (this);                                
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
int TDMRegGoodsImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMRegGoodsImpl::kanRelease(void)                                  
{                                                                      
if (--NumRefs==0)                                                     
   {                                                                  
   delete this;                                                       
   }                                                                  
return NumRefs;                                                       
}                                                                     
//---------------------------------------------------------------

//IMainInterface 

//---------------------------------------------------------------
int  TDMRegGoodsImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMRegGoodsImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMRegGoodsImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{                                                              
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMRegGoodsImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}                                                              
//---------------------------------------------------------------
int TDMRegGoodsImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMRegGoods
TpFIBDataSet * TDMRegGoodsImpl::get_DvRegOst(void)
{
return Object->DvRegOst;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_DvRegOst(TpFIBDataSet * DvRegOst)
{
Object->DvRegOst=DvRegOst;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegGoodsImpl::get_RegOst(void)
{
return Object->RegOst;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_RegOst(TpFIBDataSet * RegOst)
{
Object->RegOst=RegOst;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegGoodsImpl::get_DvNom(void)
{
return Object->DvNom;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_DvNom(TpFIBDataSet * DvNom)
{
Object->DvNom=DvNom;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegGoodsImpl::get_Ostatok(void)
{
return Object->Ostatok;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_Ostatok(TpFIBDataSet * Ostatok)
{
Object->Ostatok=Ostatok;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMRegGoodsImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMRegGoodsImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMRegGoodsImpl::get_DvRegOstPOSDOC_RGGOODS_DV(void)
{
return Object->DvRegOstPOSDOC_RGGOODS_DV;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_DvRegOstPOSDOC_RGGOODS_DV(TFIBDateTimeField * DvRegOstPOSDOC_RGGOODS_DV)
{
Object->DvRegOstPOSDOC_RGGOODS_DV=DvRegOstPOSDOC_RGGOODS_DV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMRegGoodsImpl::get_DvRegOstTDV_RGGOODS_DV(void)
{
return Object->DvRegOstTDV_RGGOODS_DV;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_DvRegOstTDV_RGGOODS_DV(TFIBSmallIntField * DvRegOstTDV_RGGOODS_DV)
{
Object->DvRegOstTDV_RGGOODS_DV=DvRegOstTDV_RGGOODS_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegGoodsImpl::get_DvRegOstRPRICE_RGGOODS_DV(void)
{
return Object->DvRegOstRPRICE_RGGOODS_DV;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_DvRegOstRPRICE_RGGOODS_DV(TFIBBCDField * DvRegOstRPRICE_RGGOODS_DV)
{
Object->DvRegOstRPRICE_RGGOODS_DV=DvRegOstRPRICE_RGGOODS_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegGoodsImpl::get_DvRegOstKOL_RGGOODS_DV(void)
{
return Object->DvRegOstKOL_RGGOODS_DV;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_DvRegOstKOL_RGGOODS_DV(TFIBBCDField * DvRegOstKOL_RGGOODS_DV)
{
Object->DvRegOstKOL_RGGOODS_DV=DvRegOstKOL_RGGOODS_DV;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMRegGoodsImpl::get_DvRegOstOPER_RGGOODS_DV(void)
{
return Object->DvRegOstOPER_RGGOODS_DV;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_DvRegOstOPER_RGGOODS_DV(TFIBIntegerField * DvRegOstOPER_RGGOODS_DV)
{
Object->DvRegOstOPER_RGGOODS_DV=DvRegOstOPER_RGGOODS_DV;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMRegGoodsImpl::get_DvRegOstTYPE_RGGOODS_DV(void)
{
return Object->DvRegOstTYPE_RGGOODS_DV;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_DvRegOstTYPE_RGGOODS_DV(TFIBIntegerField * DvRegOstTYPE_RGGOODS_DV)
{
Object->DvRegOstTYPE_RGGOODS_DV=DvRegOstTYPE_RGGOODS_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegGoodsImpl::get_RegOstRPRICE_RGGOODS(void)
{
return Object->RegOstRPRICE_RGGOODS;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_RegOstRPRICE_RGGOODS(TFIBBCDField * RegOstRPRICE_RGGOODS)
{
Object->RegOstRPRICE_RGGOODS=RegOstRPRICE_RGGOODS;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegGoodsImpl::get_RegOstKOL_RGGOODS(void)
{
return Object->RegOstKOL_RGGOODS;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_RegOstKOL_RGGOODS(TFIBBCDField * RegOstKOL_RGGOODS)
{
Object->RegOstKOL_RGGOODS=RegOstKOL_RGGOODS;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegGoodsImpl::get_DvNomKOLDV(void)
{
return Object->DvNomKOLDV;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_DvNomKOLDV(TFIBBCDField * DvNomKOLDV)
{
Object->DvNomKOLDV=DvNomKOLDV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegGoodsImpl::get_OstatokKOLOST(void)
{
return Object->OstatokKOLOST;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_OstatokKOLOST(TFIBBCDField * OstatokKOLOST)
{
Object->OstatokKOLOST=OstatokKOLOST;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegGoodsImpl::get_RegOstID_RGGOODS(void)
{
return Object->RegOstID_RGGOODS;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_RegOstID_RGGOODS(TFIBBCDField * RegOstID_RGGOODS)
{
Object->RegOstID_RGGOODS=RegOstID_RGGOODS;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegGoodsImpl::get_RegOstIDFIRM_RGGOODS(void)
{
return Object->RegOstIDFIRM_RGGOODS;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_RegOstIDFIRM_RGGOODS(TFIBBCDField * RegOstIDFIRM_RGGOODS)
{
Object->RegOstIDFIRM_RGGOODS=RegOstIDFIRM_RGGOODS;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegGoodsImpl::get_RegOstIDSKLAD_RGGOODS(void)
{
return Object->RegOstIDSKLAD_RGGOODS;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_RegOstIDSKLAD_RGGOODS(TFIBBCDField * RegOstIDSKLAD_RGGOODS)
{
Object->RegOstIDSKLAD_RGGOODS=RegOstIDSKLAD_RGGOODS;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegGoodsImpl::get_RegOstIDNOM_RGGOODS(void)
{
return Object->RegOstIDNOM_RGGOODS;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_RegOstIDNOM_RGGOODS(TFIBBCDField * RegOstIDNOM_RGGOODS)
{
Object->RegOstIDNOM_RGGOODS=RegOstIDNOM_RGGOODS;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegGoodsImpl::get_DvRegOstID_RGGOODS_DV(void)
{
return Object->DvRegOstID_RGGOODS_DV;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_DvRegOstID_RGGOODS_DV(TFIBBCDField * DvRegOstID_RGGOODS_DV)
{
Object->DvRegOstID_RGGOODS_DV=DvRegOstID_RGGOODS_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegGoodsImpl::get_DvRegOstIDDOC_RGGOODS_DV(void)
{
return Object->DvRegOstIDDOC_RGGOODS_DV;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_DvRegOstIDDOC_RGGOODS_DV(TFIBBCDField * DvRegOstIDDOC_RGGOODS_DV)
{
Object->DvRegOstIDDOC_RGGOODS_DV=DvRegOstIDDOC_RGGOODS_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegGoodsImpl::get_DvRegOstIDFIRM_RGGOODS_DV(void)
{
return Object->DvRegOstIDFIRM_RGGOODS_DV;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_DvRegOstIDFIRM_RGGOODS_DV(TFIBBCDField * DvRegOstIDFIRM_RGGOODS_DV)
{
Object->DvRegOstIDFIRM_RGGOODS_DV=DvRegOstIDFIRM_RGGOODS_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegGoodsImpl::get_DvRegOstIDSKLAD_RGGOODS_DV(void)
{
return Object->DvRegOstIDSKLAD_RGGOODS_DV;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_DvRegOstIDSKLAD_RGGOODS_DV(TFIBBCDField * DvRegOstIDSKLAD_RGGOODS_DV)
{
Object->DvRegOstIDSKLAD_RGGOODS_DV=DvRegOstIDSKLAD_RGGOODS_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TDMRegGoodsImpl::get_DvRegOstIDNOM_RGGOODS_DV(void)
{
return Object->DvRegOstIDNOM_RGGOODS_DV;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_DvRegOstIDNOM_RGGOODS_DV(TFIBBCDField * DvRegOstIDNOM_RGGOODS_DV)
{
Object->DvRegOstIDNOM_RGGOODS_DV=DvRegOstIDNOM_RGGOODS_DV;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegGoodsImpl::get_TableOst(void)
{
return Object->TableOst;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_TableOst(TpFIBDataSet * TableOst)
{
Object->TableOst=TableOst;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMRegGoodsImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_Query(TpFIBDataSet * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
__int64 TDMRegGoodsImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TDMRegGoodsImpl::get_IdNom(void)
{
return Object->IdNom;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_IdNom(__int64 IdNom)
{
Object->IdNom=IdNom;
}
//---------------------------------------------------------------
float TDMRegGoodsImpl::get_SumOst(void)
{
return Object->SumOst;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_SumOst(float SumOst)
{
Object->SumOst=SumOst;
}
//---------------------------------------------------------------
float TDMRegGoodsImpl::get_KolOst(void)
{
return Object->KolOst;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_KolOst(float KolOst)
{
Object->KolOst=KolOst;
}
//---------------------------------------------------------------
__int64 TDMRegGoodsImpl::get_IdDoc(void)
{
return Object->IdDoc;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_IdDoc(__int64 IdDoc)
{
Object->IdDoc=IdDoc;
}
//---------------------------------------------------------------
TDateTime TDMRegGoodsImpl::get_PosDoc(void)
{
return Object->PosDoc;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_PosDoc(TDateTime PosDoc)
{
Object->PosDoc=PosDoc;
}
//---------------------------------------------------------------
__int64 TDMRegGoodsImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
double TDMRegGoodsImpl::get_RPrice(void)
{
return Object->RPrice;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_RPrice(double RPrice)
{
Object->RPrice=RPrice;
}
//---------------------------------------------------------------
__int64 TDMRegGoodsImpl::get_IdStr(void)
{
return Object->IdStr;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_IdStr(__int64 IdStr)
{
Object->IdStr=IdStr;
}
//---------------------------------------------------------------
float TDMRegGoodsImpl::get_Kol(void)
{
return Object->Kol;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_Kol(float Kol)
{
Object->Kol=Kol;
}
//---------------------------------------------------------------
int TDMRegGoodsImpl::get_Operation(void)
{
return Object->Operation;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_Operation(int Operation)
{
Object->Operation=Operation;
}
//---------------------------------------------------------------
int TDMRegGoodsImpl::get_Type(void)
{
return Object->Type;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_Type(int Type)
{
Object->Type=Type;
}
//---------------------------------------------------------------
float TDMRegGoodsImpl::get_Sum2(void)
{
return Object->Sum2;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_Sum2(float Sum2)
{
Object->Sum2=Sum2;
}
//---------------------------------------------------------------
double TDMRegGoodsImpl::get_KolOstNa(void)
{
return Object->KolOstNa;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_KolOstNa(double KolOstNa)
{
Object->KolOstNa=KolOstNa;
}
//---------------------------------------------------------------
bool TDMRegGoodsImpl::get_SkladRozn(void)
{
return Object->SkladRozn;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_SkladRozn(bool SkladRozn)
{
Object->SkladRozn=SkladRozn;
}
//---------------------------------------------------------------
bool TDMRegGoodsImpl::get_NoOtrOstatok(void)
{
return Object->NoOtrOstatok;
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::set_NoOtrOstatok(bool NoOtrOstatok)
{
Object->NoOtrOstatok=NoOtrOstatok;
}
//---------------------------------------------------------------
bool TDMRegGoodsImpl::AddRecordPrihod(void)
{
return Object->AddRecordPrihod();
}
//---------------------------------------------------------------
bool TDMRegGoodsImpl::AddRecordRashod(void)
{
return Object->AddRecordRashod();
}
//---------------------------------------------------------------
bool TDMRegGoodsImpl::UpdateTableOst(void)
{
return Object->UpdateTableOst();
}
//---------------------------------------------------------------
bool TDMRegGoodsImpl::CancelDvReg(void)
{
return Object->CancelDvReg();
}
//---------------------------------------------------------------
double TDMRegGoodsImpl::GetOstatok(__int64 id_firm, __int64 id_sklad, __int64 id_nom)
{
return Object->GetOstatok(id_firm,id_sklad,id_nom);
}
//---------------------------------------------------------------
void TDMRegGoodsImpl::GetOstatokPoPrice(__int64 id_firm, __int64 id_sklad, __int64 id_nom)
{
return Object->GetOstatokPoPrice(id_firm,id_sklad,id_nom);
}
//---------------------------------------------------------------
double TDMRegGoodsImpl::GetOstatokNa(TDateTime pos,__int64 id_firm, __int64 id_sklad, __int64 id_nom)
{
return Object->GetOstatokNa(pos,id_firm, id_sklad, id_nom);
}
//---------------------------------------------------------------
double TDMRegGoodsImpl::GetOstatokNaRoznSkladeNa(TDateTime pos,	__int64 id_firm,__int64 id_sklad,__int64 id_nom,bool rozn_sklad,double rprice)
{
return Object->GetOstatokNaRoznSkladeNa(pos,id_firm,id_sklad,id_nom,rozn_sklad,rprice);
}
//---------------------------------------------------------------
