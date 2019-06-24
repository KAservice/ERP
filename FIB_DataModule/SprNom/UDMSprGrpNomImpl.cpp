#include "vcl.h"
#pragma hdrstop


#include "UDMSprGrpNomImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprGrpNomImpl::TDMSprGrpNomImpl()           
{                                            
Object=new TDMSprGrpNom(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprGrpNomImpl::~TDMSprGrpNomImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprGrpNomImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprGrpNomImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprGrpNom)                        
   {                                                                     
   *ppv=static_cast<IDMSprGrpNom*> (this);                                
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
int TDMSprGrpNomImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprGrpNomImpl::kanRelease(void)                                  
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
int  TDMSprGrpNomImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprGrpNomImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprGrpNomImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprGrpNomImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprGrpNomImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprGrpNom
TDataSource * TDMSprGrpNomImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprGrpNomImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpNomImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprGrpNomImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpNomImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprGrpNomImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprGrpNomImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprGrpNomImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpNomImpl::get_TableIDGN(void)
{
return Object->TableIDGN;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_TableIDGN(TFIBBCDField * TableIDGN)
{
Object->TableIDGN=TableIDGN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpNomImpl::get_TableIDGRPGN(void)
{
return Object->TableIDGRPGN;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_TableIDGRPGN(TFIBBCDField * TableIDGRPGN)
{
Object->TableIDGRPGN=TableIDGRPGN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpNomImpl::get_ElementIDGN(void)
{
return Object->ElementIDGN;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_ElementIDGN(TFIBBCDField * ElementIDGN)
{
Object->ElementIDGN=ElementIDGN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpNomImpl::get_ElementIDGRPGN(void)
{
return Object->ElementIDGRPGN;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_ElementIDGRPGN(TFIBBCDField * ElementIDGRPGN)
{
Object->ElementIDGRPGN=ElementIDGRPGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpNomImpl::get_TableNAMEGN(void)
{
return Object->TableNAMEGN;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_TableNAMEGN(TFIBWideStringField * TableNAMEGN)
{
Object->TableNAMEGN=TableNAMEGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpNomImpl::get_TableGID_SGRPNOM(void)
{
return Object->TableGID_SGRPNOM;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_TableGID_SGRPNOM(TFIBWideStringField * TableGID_SGRPNOM)
{
Object->TableGID_SGRPNOM=TableGID_SGRPNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpNomImpl::get_ElementNAMEGN(void)
{
return Object->ElementNAMEGN;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_ElementNAMEGN(TFIBWideStringField * ElementNAMEGN)
{
Object->ElementNAMEGN=ElementNAMEGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpNomImpl::get_ElementGID_SGRPNOM(void)
{
return Object->ElementGID_SGRPNOM;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_ElementGID_SGRPNOM(TFIBWideStringField * ElementGID_SGRPNOM)
{
Object->ElementGID_SGRPNOM=ElementGID_SGRPNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpNomImpl::get_ElementIDVIDIMAGENABOR_SGRPNOM(void)
{
return Object->ElementIDVIDIMAGENABOR_SGRPNOM;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_ElementIDVIDIMAGENABOR_SGRPNOM(TFIBBCDField * ElementIDVIDIMAGENABOR_SGRPNOM)
{
Object->ElementIDVIDIMAGENABOR_SGRPNOM=ElementIDVIDIMAGENABOR_SGRPNOM;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprGrpNomImpl::get_ElementIDPROPNABOR_SGRPNOM(void)
{
return Object->ElementIDPROPNABOR_SGRPNOM;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_ElementIDPROPNABOR_SGRPNOM(TFIBBCDField * ElementIDPROPNABOR_SGRPNOM)
{
Object->ElementIDPROPNABOR_SGRPNOM=ElementIDPROPNABOR_SGRPNOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpNomImpl::get_ElementNAME_SPROPNABOR(void)
{
return Object->ElementNAME_SPROPNABOR;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_ElementNAME_SPROPNABOR(TFIBWideStringField * ElementNAME_SPROPNABOR)
{
Object->ElementNAME_SPROPNABOR=ElementNAME_SPROPNABOR;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprGrpNomImpl::get_ElementNAME_SVIDIMAGE_NABOR(void)
{
return Object->ElementNAME_SVIDIMAGE_NABOR;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::set_ElementNAME_SVIDIMAGE_NABOR(TFIBWideStringField * ElementNAME_SVIDIMAGE_NABOR)
{
Object->ElementNAME_SVIDIMAGE_NABOR=ElementNAME_SVIDIMAGE_NABOR;
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprGrpNomImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprGrpNomImpl::NewElement(__int64 IdGrp)
{
return Object->NewElement(IdGrp);
}
//---------------------------------------------------------------
bool TDMSprGrpNomImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprGrpNomImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
__int64 TDMSprGrpNomImpl::GetIDElement(String gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
AnsiString TDMSprGrpNomImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprGrpNomImpl::FindPoName(AnsiString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
