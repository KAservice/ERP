#include "vcl.h"
#pragma hdrstop


#include "UDMSprNomVZipImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprNomVZipImpl::TDMSprNomVZipImpl()           
{                                            
Object=new TDMSprNomVZip(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprNomVZipImpl::~TDMSprNomVZipImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprNomVZipImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprNomVZipImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprNomVZip)                        
   {                                                                     
   *ppv=static_cast<IDMSprNomVZip*> (this);                                
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
int TDMSprNomVZipImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprNomVZipImpl::kanRelease(void)                                  
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
int  TDMSprNomVZipImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprNomVZipImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprNomVZipImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprNomVZipImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprNomVZipImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprNomVZip
TDataSource * TDMSprNomVZipImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomVZipImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNomVZipImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprNomVZipImpl::get_pFIBQuery(void)
{
return Object->pFIBQuery;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_pFIBQuery(TpFIBQuery * pFIBQuery)
{
Object->pFIBQuery=pFIBQuery;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomVZipImpl::get_TableOUT_IDNOM(void)
{
return Object->TableOUT_IDNOM;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_IDNOM(TFIBLargeIntField * TableOUT_IDNOM)
{
Object->TableOUT_IDNOM=TableOUT_IDNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomVZipImpl::get_TableOUT_NAME_NOM(void)
{
return Object->TableOUT_NAME_NOM;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_NAME_NOM(TFIBWideStringField * TableOUT_NAME_NOM)
{
Object->TableOUT_NAME_NOM=TableOUT_NAME_NOM;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomVZipImpl::get_TableOUT_CODE(void)
{
return Object->TableOUT_CODE;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_CODE(TFIBIntegerField * TableOUT_CODE)
{
Object->TableOUT_CODE=TableOUT_CODE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomVZipImpl::get_TableOUT_ARTIKUL(void)
{
return Object->TableOUT_ARTIKUL;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_ARTIKUL(TFIBWideStringField * TableOUT_ARTIKUL)
{
Object->TableOUT_ARTIKUL=TableOUT_ARTIKUL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomVZipImpl::get_TableOUT_IDED(void)
{
return Object->TableOUT_IDED;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_IDED(TFIBLargeIntField * TableOUT_IDED)
{
Object->TableOUT_IDED=TableOUT_IDED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomVZipImpl::get_TableOUT_NAME_ED(void)
{
return Object->TableOUT_NAME_ED;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_NAME_ED(TFIBWideStringField * TableOUT_NAME_ED)
{
Object->TableOUT_NAME_ED=TableOUT_NAME_ED;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomVZipImpl::get_TableOUT_SHED(void)
{
return Object->TableOUT_SHED;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_SHED(TFIBWideStringField * TableOUT_SHED)
{
Object->TableOUT_SHED=TableOUT_SHED;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomVZipImpl::get_TableOUT_PRICE(void)
{
return Object->TableOUT_PRICE;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_PRICE(TFIBBCDField * TableOUT_PRICE)
{
Object->TableOUT_PRICE=TableOUT_PRICE;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomVZipImpl::get_TableOUT_OST(void)
{
return Object->TableOUT_OST;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_OST(TFIBBCDField * TableOUT_OST)
{
Object->TableOUT_OST=TableOUT_OST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomVZipImpl::get_TableOUT_IDFIRM(void)
{
return Object->TableOUT_IDFIRM;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_IDFIRM(TFIBLargeIntField * TableOUT_IDFIRM)
{
Object->TableOUT_IDFIRM=TableOUT_IDFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomVZipImpl::get_TableOUT_NAME_FIRM(void)
{
return Object->TableOUT_NAME_FIRM;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_NAME_FIRM(TFIBWideStringField * TableOUT_NAME_FIRM)
{
Object->TableOUT_NAME_FIRM=TableOUT_NAME_FIRM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomVZipImpl::get_TableOUT_IDSKLAD(void)
{
return Object->TableOUT_IDSKLAD;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_IDSKLAD(TFIBLargeIntField * TableOUT_IDSKLAD)
{
Object->TableOUT_IDSKLAD=TableOUT_IDSKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomVZipImpl::get_TableOUT_NAME_SKLAD(void)
{
return Object->TableOUT_NAME_SKLAD;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_NAME_SKLAD(TFIBWideStringField * TableOUT_NAME_SKLAD)
{
Object->TableOUT_NAME_SKLAD=TableOUT_NAME_SKLAD;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomVZipImpl::get_TableOUT_IDKLIENT(void)
{
return Object->TableOUT_IDKLIENT;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_IDKLIENT(TFIBLargeIntField * TableOUT_IDKLIENT)
{
Object->TableOUT_IDKLIENT=TableOUT_IDKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomVZipImpl::get_TableOUT_NAME_KLIENT(void)
{
return Object->TableOUT_NAME_KLIENT;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_NAME_KLIENT(TFIBWideStringField * TableOUT_NAME_KLIENT)
{
Object->TableOUT_NAME_KLIENT=TableOUT_NAME_KLIENT;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomVZipImpl::get_TableOUT_IDTNOM(void)
{
return Object->TableOUT_IDTNOM;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_IDTNOM(TFIBLargeIntField * TableOUT_IDTNOM)
{
Object->TableOUT_IDTNOM=TableOUT_IDTNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomVZipImpl::get_TableOUT_NAME_TNOM(void)
{
return Object->TableOUT_NAME_TNOM;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_NAME_TNOM(TFIBWideStringField * TableOUT_NAME_TNOM)
{
Object->TableOUT_NAME_TNOM=TableOUT_NAME_TNOM;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomVZipImpl::get_TableOUT_IDZ(void)
{
return Object->TableOUT_IDZ;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_IDZ(TFIBLargeIntField * TableOUT_IDZ)
{
Object->TableOUT_IDZ=TableOUT_IDZ;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomVZipImpl::get_TableOUT_NAME_Z(void)
{
return Object->TableOUT_NAME_Z;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_NAME_Z(TFIBWideStringField * TableOUT_NAME_Z)
{
Object->TableOUT_NAME_Z=TableOUT_NAME_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomVZipImpl::get_TableOUT_IDGRPNOM(void)
{
return Object->TableOUT_IDGRPNOM;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_IDGRPNOM(TFIBLargeIntField * TableOUT_IDGRPNOM)
{
Object->TableOUT_IDGRPNOM=TableOUT_IDGRPNOM;
}
//---------------------------------------------------------------
TIntegerField * TDMSprNomVZipImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomVZipImpl::get_SpTPrice(void)
{
return Object->SpTPrice;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_SpTPrice(TpFIBDataSet * SpTPrice)
{
Object->SpTPrice=SpTPrice;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNomVZipImpl::get_SpTPriceID_TPRICE(void)
{
return Object->SpTPriceID_TPRICE;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_SpTPriceID_TPRICE(TFIBBCDField * SpTPriceID_TPRICE)
{
Object->SpTPriceID_TPRICE=SpTPriceID_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomVZipImpl::get_SpTPriceNAME_TPRICE(void)
{
return Object->SpTPriceNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_SpTPriceNAME_TPRICE(TFIBWideStringField * SpTPriceNAME_TPRICE)
{
Object->SpTPriceNAME_TPRICE=SpTPriceNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomVZipImpl::get_TableOUT_IDMHRAN(void)
{
return Object->TableOUT_IDMHRAN;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_IDMHRAN(TFIBLargeIntField * TableOUT_IDMHRAN)
{
Object->TableOUT_IDMHRAN=TableOUT_IDMHRAN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomVZipImpl::get_TableOUT_NAME_MHRAN(void)
{
return Object->TableOUT_NAME_MHRAN;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_TableOUT_NAME_MHRAN(TFIBWideStringField * TableOUT_NAME_MHRAN)
{
Object->TableOUT_NAME_MHRAN=TableOUT_NAME_MHRAN;
}
//---------------------------------------------------------------
__int64 TDMSprNomVZipImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprNomVZipImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMSprNomVZipImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
__int64 TDMSprNomVZipImpl::get_IdTypePrice(void)
{
return Object->IdTypePrice;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_IdTypePrice(__int64 IdTypePrice)
{
Object->IdTypePrice=IdTypePrice;
}
//---------------------------------------------------------------
__int64 TDMSprNomVZipImpl::get_IdFirm(void)
{
return Object->IdFirm;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_IdFirm(__int64 IdFirm)
{
Object->IdFirm=IdFirm;
}
//---------------------------------------------------------------
__int64 TDMSprNomVZipImpl::get_IdSklad(void)
{
return Object->IdSklad;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_IdSklad(__int64 IdSklad)
{
Object->IdSklad=IdSklad;
}
//---------------------------------------------------------------
__int64 TDMSprNomVZipImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//---------------------------------------------------------------
__int64 TDMSprNomVZipImpl::get_IdTNom(void)
{
return Object->IdTNom;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_IdTNom(__int64 IdTNom)
{
Object->IdTNom=IdTNom;
}
//---------------------------------------------------------------
__int64 TDMSprNomVZipImpl::get_IdNom(void)
{
return Object->IdNom;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_IdNom(__int64 IdNom)
{
Object->IdNom=IdNom;
}
//---------------------------------------------------------------
__int64 TDMSprNomVZipImpl::get_IdZ(void)
{
return Object->IdZ;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_IdZ(__int64 IdZ)
{
Object->IdZ=IdZ;
}
//---------------------------------------------------------------
bool TDMSprNomVZipImpl::get_CheckOst(void)
{
return Object->CheckOst;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_CheckOst(bool CheckOst)
{
Object->CheckOst=CheckOst;
}
//---------------------------------------------------------------
bool TDMSprNomVZipImpl::get_OnlyChange(void)
{
return Object->OnlyChange;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_OnlyChange(bool OnlyChange)
{
Object->OnlyChange=OnlyChange;
}
//---------------------------------------------------------------
bool TDMSprNomVZipImpl::get_PriceSklad(void)
{
return Object->PriceSklad;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_PriceSklad(bool PriceSklad)
{
Object->PriceSklad=PriceSklad;
}
//---------------------------------------------------------------
bool TDMSprNomVZipImpl::get_OnlyOstatok(void)
{
return Object->OnlyOstatok;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_OnlyOstatok(bool OnlyOstatok)
{
Object->OnlyOstatok=OnlyOstatok;
}
//---------------------------------------------------------------
int TDMSprNomVZipImpl::get_PorNumberString(void)
{
return Object->PorNumberString;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::set_PorNumberString(int PorNumberString)
{
Object->PorNumberString=PorNumberString;
}
//---------------------------------------------------------------
void TDMSprNomVZipImpl::OpenTable(__int64 Grp, bool All)
{
return Object->OpenTable(Grp, All);
}
//---------------------------------------------------------------
__int64 TDMSprNomVZipImpl::FindPoCodu(int Code)
{
return Object->FindPoCodu(Code);
}
//---------------------------------------------------------------
__int64 TDMSprNomVZipImpl::FindPoShtrihCodu(AnsiString shtrih_cod)
{
return Object->FindPoShtrihCodu(shtrih_cod);
}
//---------------------------------------------------------------
__int64 TDMSprNomVZipImpl::FindPoName(AnsiString name)
{
return Object->FindPoName( name);
}
//---------------------------------------------------------------
__int64 TDMSprNomVZipImpl::FindPoArtikulu(UnicodeString artikul)
{
return Object->FindPoArtikulu(artikul);
}
//---------------------------------------------------------------
int TDMSprNomVZipImpl::GetIndexTypePrice(void)
{
return Object->GetIndexTypePrice();
}
//---------------------------------------------------------------
__int64 TDMSprNomVZipImpl::GetIdBasEd(__int64 id_nom)
{
return Object->GetIdBasEd(id_nom);
}
//---------------------------------------------------------------
__int64 TDMSprNomVZipImpl::GetIDElement(String gid)
{
return Object->GetIDElement( gid);
}
//---------------------------------------------------------------
AnsiString TDMSprNomVZipImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprNomVZipImpl::GetIdGrpNom(__int64 id_nom)
{
return Object->GetIdGrpNom(id_nom);
}
//---------------------------------------------------------------
