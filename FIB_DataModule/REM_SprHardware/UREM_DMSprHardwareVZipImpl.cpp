#include "vcl.h"
#pragma hdrstop


#include "UREM_DMSprHardwareVZipImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMSprHardwareVZipImpl::TREM_DMSprHardwareVZipImpl()           
{                                            
Object=new TREM_DMSprHardwareVZip(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMSprHardwareVZipImpl::~TREM_DMSprHardwareVZipImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMSprHardwareVZipImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMSprHardwareVZip)                        
   {                                                                     
   *ppv=static_cast<IREM_DMSprHardwareVZip*> (this);                                
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
int TREM_DMSprHardwareVZipImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMSprHardwareVZipImpl::kanRelease(void)                                  
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
int  TREM_DMSprHardwareVZipImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMSprHardwareVZipImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMSprHardwareVZipImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMSprHardwareVZipImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMSprHardwareVZipImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMSprHardwareVZip
TDataSource * TREM_DMSprHardwareVZipImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMSprHardwareVZipImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMSprHardwareVZipImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMSprHardwareVZipImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareVZipImpl::get_TableOUT_IDNOM(void)
{
return Object->TableOUT_IDNOM;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_IDNOM(TFIBLargeIntField * TableOUT_IDNOM)
{
Object->TableOUT_IDNOM=TableOUT_IDNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_NAME_NOM(void)
{
return Object->TableOUT_NAME_NOM;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_NAME_NOM(TFIBWideStringField * TableOUT_NAME_NOM)
{
Object->TableOUT_NAME_NOM=TableOUT_NAME_NOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprHardwareVZipImpl::get_TableOUT_CODE(void)
{
return Object->TableOUT_CODE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_CODE(TFIBIntegerField * TableOUT_CODE)
{
Object->TableOUT_CODE=TableOUT_CODE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_ARTIKUL(void)
{
return Object->TableOUT_ARTIKUL;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_ARTIKUL(TFIBWideStringField * TableOUT_ARTIKUL)
{
Object->TableOUT_ARTIKUL=TableOUT_ARTIKUL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareVZipImpl::get_TableOUT_IDED(void)
{
return Object->TableOUT_IDED;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_IDED(TFIBLargeIntField * TableOUT_IDED)
{
Object->TableOUT_IDED=TableOUT_IDED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_NAME_ED(void)
{
return Object->TableOUT_NAME_ED;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_NAME_ED(TFIBWideStringField * TableOUT_NAME_ED)
{
Object->TableOUT_NAME_ED=TableOUT_NAME_ED;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_SHED(void)
{
return Object->TableOUT_SHED;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_SHED(TFIBWideStringField * TableOUT_SHED)
{
Object->TableOUT_SHED=TableOUT_SHED;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMSprHardwareVZipImpl::get_TableOUT_PRICE(void)
{
return Object->TableOUT_PRICE;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_PRICE(TFIBBCDField * TableOUT_PRICE)
{
Object->TableOUT_PRICE=TableOUT_PRICE;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMSprHardwareVZipImpl::get_TableOUT_OST(void)
{
return Object->TableOUT_OST;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_OST(TFIBBCDField * TableOUT_OST)
{
Object->TableOUT_OST=TableOUT_OST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareVZipImpl::get_TableOUT_IDFIRM(void)
{
return Object->TableOUT_IDFIRM;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_IDFIRM(TFIBLargeIntField * TableOUT_IDFIRM)
{
Object->TableOUT_IDFIRM=TableOUT_IDFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_NAME_FIRM(void)
{
return Object->TableOUT_NAME_FIRM;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_NAME_FIRM(TFIBWideStringField * TableOUT_NAME_FIRM)
{
Object->TableOUT_NAME_FIRM=TableOUT_NAME_FIRM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareVZipImpl::get_TableOUT_IDSKLAD(void)
{
return Object->TableOUT_IDSKLAD;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_IDSKLAD(TFIBLargeIntField * TableOUT_IDSKLAD)
{
Object->TableOUT_IDSKLAD=TableOUT_IDSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_NAME_SKLAD(void)
{
return Object->TableOUT_NAME_SKLAD;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_NAME_SKLAD(TFIBWideStringField * TableOUT_NAME_SKLAD)
{
Object->TableOUT_NAME_SKLAD=TableOUT_NAME_SKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareVZipImpl::get_TableOUT_IDKLIENT(void)
{
return Object->TableOUT_IDKLIENT;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_IDKLIENT(TFIBLargeIntField * TableOUT_IDKLIENT)
{
Object->TableOUT_IDKLIENT=TableOUT_IDKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_NAME_KLIENT(void)
{
return Object->TableOUT_NAME_KLIENT;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_NAME_KLIENT(TFIBWideStringField * TableOUT_NAME_KLIENT)
{
Object->TableOUT_NAME_KLIENT=TableOUT_NAME_KLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareVZipImpl::get_TableOUT_IDTNOM(void)
{
return Object->TableOUT_IDTNOM;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_IDTNOM(TFIBLargeIntField * TableOUT_IDTNOM)
{
Object->TableOUT_IDTNOM=TableOUT_IDTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_NAME_TNOM(void)
{
return Object->TableOUT_NAME_TNOM;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_NAME_TNOM(TFIBWideStringField * TableOUT_NAME_TNOM)
{
Object->TableOUT_NAME_TNOM=TableOUT_NAME_TNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareVZipImpl::get_TableOUT_IDZ(void)
{
return Object->TableOUT_IDZ;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_IDZ(TFIBLargeIntField * TableOUT_IDZ)
{
Object->TableOUT_IDZ=TableOUT_IDZ;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_NAME_Z(void)
{
return Object->TableOUT_NAME_Z;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_NAME_Z(TFIBWideStringField * TableOUT_NAME_Z)
{
Object->TableOUT_NAME_Z=TableOUT_NAME_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareVZipImpl::get_TableOUT_IDGRPNOM(void)
{
return Object->TableOUT_IDGRPNOM;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_IDGRPNOM(TFIBLargeIntField * TableOUT_IDGRPNOM)
{
Object->TableOUT_IDGRPNOM=TableOUT_IDGRPNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareVZipImpl::get_TableOUT_IDHW(void)
{
return Object->TableOUT_IDHW;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_IDHW(TFIBLargeIntField * TableOUT_IDHW)
{
Object->TableOUT_IDHW=TableOUT_IDHW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_NAME_HW(void)
{
return Object->TableOUT_NAME_HW;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_NAME_HW(TFIBWideStringField * TableOUT_NAME_HW)
{
Object->TableOUT_NAME_HW=TableOUT_NAME_HW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_SERNUM1_HW(void)
{
return Object->TableOUT_SERNUM1_HW;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_SERNUM1_HW(TFIBWideStringField * TableOUT_SERNUM1_HW)
{
Object->TableOUT_SERNUM1_HW=TableOUT_SERNUM1_HW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_SERNUM2_HW(void)
{
return Object->TableOUT_SERNUM2_HW;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_SERNUM2_HW(TFIBWideStringField * TableOUT_SERNUM2_HW)
{
Object->TableOUT_SERNUM2_HW=TableOUT_SERNUM2_HW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_MODEL_HW(void)
{
return Object->TableOUT_MODEL_HW;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_MODEL_HW(TFIBWideStringField * TableOUT_MODEL_HW)
{
Object->TableOUT_MODEL_HW=TableOUT_MODEL_HW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_PRMODEL_HW(void)
{
return Object->TableOUT_PRMODEL_HW;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_PRMODEL_HW(TFIBWideStringField * TableOUT_PRMODEL_HW)
{
Object->TableOUT_PRMODEL_HW=TableOUT_PRMODEL_HW;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMSprHardwareVZipImpl::get_TableOUT_CODE_HW(void)
{
return Object->TableOUT_CODE_HW;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_CODE_HW(TFIBIntegerField * TableOUT_CODE_HW)
{
Object->TableOUT_CODE_HW=TableOUT_CODE_HW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_ARTIKUL_HW(void)
{
return Object->TableOUT_ARTIKUL_HW;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_ARTIKUL_HW(TFIBWideStringField * TableOUT_ARTIKUL_HW)
{
Object->TableOUT_ARTIKUL_HW=TableOUT_ARTIKUL_HW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_NAME_ENG_HW(void)
{
return Object->TableOUT_NAME_ENG_HW;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_NAME_ENG_HW(TFIBWideStringField * TableOUT_NAME_ENG_HW)
{
Object->TableOUT_NAME_ENG_HW=TableOUT_NAME_ENG_HW;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareVZipImpl::get_TableOUT_FL_ACT_HW(void)
{
return Object->TableOUT_FL_ACT_HW;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_FL_ACT_HW(TFIBSmallIntField * TableOUT_FL_ACT_HW)
{
Object->TableOUT_FL_ACT_HW=TableOUT_FL_ACT_HW;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareVZipImpl::get_TableOUT_FL_REMONT_HW(void)
{
return Object->TableOUT_FL_REMONT_HW;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_FL_REMONT_HW(TFIBSmallIntField * TableOUT_FL_REMONT_HW)
{
Object->TableOUT_FL_REMONT_HW=TableOUT_FL_REMONT_HW;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareVZipImpl::get_TableOUT_FL_NECOND_HW(void)
{
return Object->TableOUT_FL_NECOND_HW;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_FL_NECOND_HW(TFIBSmallIntField * TableOUT_FL_NECOND_HW)
{
Object->TableOUT_FL_NECOND_HW=TableOUT_FL_NECOND_HW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_NAME_BRAND_HW(void)
{
return Object->TableOUT_NAME_BRAND_HW;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_NAME_BRAND_HW(TFIBWideStringField * TableOUT_NAME_BRAND_HW)
{
Object->TableOUT_NAME_BRAND_HW=TableOUT_NAME_BRAND_HW;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_NAME_PRODUCER_HW(void)
{
return Object->TableOUT_NAME_PRODUCER_HW;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_NAME_PRODUCER_HW(TFIBWideStringField * TableOUT_NAME_PRODUCER_HW)
{
Object->TableOUT_NAME_PRODUCER_HW=TableOUT_NAME_PRODUCER_HW;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareVZipImpl::get_TableOUT_IDGRPHW(void)
{
return Object->TableOUT_IDGRPHW;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_IDGRPHW(TFIBLargeIntField * TableOUT_IDGRPHW)
{
Object->TableOUT_IDGRPHW=TableOUT_IDGRPHW;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMSprHardwareVZipImpl::get_TableOUT_IDMHRAN(void)
{
return Object->TableOUT_IDMHRAN;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_IDMHRAN(TFIBLargeIntField * TableOUT_IDMHRAN)
{
Object->TableOUT_IDMHRAN=TableOUT_IDMHRAN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMSprHardwareVZipImpl::get_TableOUT_NAME_MHRAN(void)
{
return Object->TableOUT_NAME_MHRAN;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_NAME_MHRAN(TFIBWideStringField * TableOUT_NAME_MHRAN)
{
Object->TableOUT_NAME_MHRAN=TableOUT_NAME_MHRAN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareVZipImpl::get_TableOUT_FL_OTCH_PROIZV(void)
{
return Object->TableOUT_FL_OTCH_PROIZV;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_FL_OTCH_PROIZV(TFIBSmallIntField * TableOUT_FL_OTCH_PROIZV)
{
Object->TableOUT_FL_OTCH_PROIZV=TableOUT_FL_OTCH_PROIZV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMSprHardwareVZipImpl::get_TableOUT_FL_NO_RAZBOR(void)
{
return Object->TableOUT_FL_NO_RAZBOR;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_TableOUT_FL_NO_RAZBOR(TFIBSmallIntField * TableOUT_FL_NO_RAZBOR)
{
Object->TableOUT_FL_NO_RAZBOR=TableOUT_FL_NO_RAZBOR;
}
//---------------------------------------------------------------
__int64 TREM_DMSprHardwareVZipImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TREM_DMSprHardwareVZipImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TREM_DMSprHardwareVZipImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
__int64 TREM_DMSprHardwareVZipImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
__int64 TREM_DMSprHardwareVZipImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TREM_DMSprHardwareVZipImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
__int64 TREM_DMSprHardwareVZipImpl::get_IdTNom(void)
{
return Object->IdTNom;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_IdTNom(__int64 IdTNom)
{
Object->IdTNom=IdTNom;
}
//---------------------------------------------------------------
__int64 TREM_DMSprHardwareVZipImpl::get_IdNom(void)
{
return Object->IdNom;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_IdNom(__int64 IdNom)
{
Object->IdNom=IdNom;
}
//---------------------------------------------------------------
__int64 TREM_DMSprHardwareVZipImpl::get_IdZ(void)
{
return Object->IdZ;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::set_IdZ(__int64 IdZ)
{
Object->IdZ=IdZ;
}
//---------------------------------------------------------------
void TREM_DMSprHardwareVZipImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
__int64 TREM_DMSprHardwareVZipImpl::GetIdGrpElementa(__int64 id_element)
{
return Object->GetIdGrpElementa(id_element);
}
//---------------------------------------------------------------
__int64 TREM_DMSprHardwareVZipImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
bool TREM_DMSprHardwareVZipImpl::Table_FindPoSerNum1Like(__int64 id_grp, bool all, UnicodeString ser_num)
{
return Object->Table_FindPoSerNum1Like(id_grp, all, ser_num);
}
//---------------------------------------------------------------
bool TREM_DMSprHardwareVZipImpl::Table_FindPoSerNum2Like(__int64 id_grp, bool all, UnicodeString ser_num)
{
return Object->Table_FindPoSerNum2Like(id_grp, all,  ser_num);
}
//---------------------------------------------------------------
bool TREM_DMSprHardwareVZipImpl::Table_FindPoSerNumStrLike(__int64 id_grp, bool all, UnicodeString ser_num)
{
return Object->Table_FindPoSerNumStrLike(id_grp, all, ser_num);
}
//---------------------------------------------------------------
