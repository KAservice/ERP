#include "vcl.h"
#pragma hdrstop


#include "UDMSprKlientImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprKlientImpl::TDMSprKlientImpl()           
{                                            
Object=new TDMSprKlient(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprKlientImpl::~TDMSprKlientImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprKlientImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprKlientImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprKlient)                        
   {                                                                     
   *ppv=static_cast<IDMSprKlient*> (this);                                
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
int TDMSprKlientImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprKlientImpl::kanRelease(void)                                  
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
int  TDMSprKlientImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprKlientImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprKlientImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprKlientImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprKlientImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprKlientImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprKlientImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprKlient
TDataSource * TDMSprKlientImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprKlientImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprKlientImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprKlientImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprKlientImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprKlientImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprKlientImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKlientImpl::get_TableIDKLIENT(void)
{
return Object->TableIDKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_TableIDKLIENT(TFIBBCDField * TableIDKLIENT)
{
Object->TableIDKLIENT=TableIDKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKlientImpl::get_TableIDGRPKLIENT(void)
{
return Object->TableIDGRPKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_TableIDGRPKLIENT(TFIBBCDField * TableIDGRPKLIENT)
{
Object->TableIDGRPKLIENT=TableIDGRPKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKlientImpl::get_ElementIDKLIENT(void)
{
return Object->ElementIDKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementIDKLIENT(TFIBBCDField * ElementIDKLIENT)
{
Object->ElementIDKLIENT=ElementIDKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKlientImpl::get_ElementIDTPRICEKLIENT(void)
{
return Object->ElementIDTPRICEKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementIDTPRICEKLIENT(TFIBBCDField * ElementIDTPRICEKLIENT)
{
Object->ElementIDTPRICEKLIENT=ElementIDTPRICEKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKlientImpl::get_ElementIDGRPKLIENT(void)
{
return Object->ElementIDGRPKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementIDGRPKLIENT(TFIBBCDField * ElementIDGRPKLIENT)
{
Object->ElementIDGRPKLIENT=ElementIDGRPKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKlientImpl::get_ElementIDVIDKLIENT(void)
{
return Object->ElementIDVIDKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementIDVIDKLIENT(TFIBBCDField * ElementIDVIDKLIENT)
{
Object->ElementIDVIDKLIENT=ElementIDVIDKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKlientImpl::get_ElementIDCOUNTRYKLIENT(void)
{
return Object->ElementIDCOUNTRYKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementIDCOUNTRYKLIENT(TFIBBCDField * ElementIDCOUNTRYKLIENT)
{
Object->ElementIDCOUNTRYKLIENT=ElementIDCOUNTRYKLIENT;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprKlientImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKlientImpl::get_ElementMAXCREDIT_SKLIENT(void)
{
return Object->ElementMAXCREDIT_SKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementMAXCREDIT_SKLIENT(TFIBBCDField * ElementMAXCREDIT_SKLIENT)
{
Object->ElementMAXCREDIT_SKLIENT=ElementMAXCREDIT_SKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_TableINNKLIENT(void)
{
return Object->TableINNKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_TableINNKLIENT(TFIBWideStringField * TableINNKLIENT)
{
Object->TableINNKLIENT=TableINNKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_TableTELKLIENT(void)
{
return Object->TableTELKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_TableTELKLIENT(TFIBWideStringField * TableTELKLIENT)
{
Object->TableTELKLIENT=TableTELKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_TableADRKLIENT(void)
{
return Object->TableADRKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_TableADRKLIENT(TFIBWideStringField * TableADRKLIENT)
{
Object->TableADRKLIENT=TableADRKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementNAMEKLIENT(void)
{
return Object->ElementNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)
{
Object->ElementNAMEKLIENT=ElementNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementFNAME(void)
{
return Object->ElementFNAME;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementFNAME(TFIBWideStringField * ElementFNAME)
{
Object->ElementFNAME=ElementFNAME;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementADRKLIENT(void)
{
return Object->ElementADRKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementADRKLIENT(TFIBWideStringField * ElementADRKLIENT)
{
Object->ElementADRKLIENT=ElementADRKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementTELKLIENT(void)
{
return Object->ElementTELKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementTELKLIENT(TFIBWideStringField * ElementTELKLIENT)
{
Object->ElementTELKLIENT=ElementTELKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementINNKLIENT(void)
{
return Object->ElementINNKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementINNKLIENT(TFIBWideStringField * ElementINNKLIENT)
{
Object->ElementINNKLIENT=ElementINNKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementKPPKLIENT(void)
{
return Object->ElementKPPKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementKPPKLIENT(TFIBWideStringField * ElementKPPKLIENT)
{
Object->ElementKPPKLIENT=ElementKPPKLIENT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprKlientImpl::get_ElementTKLIENT(void)
{
return Object->ElementTKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementTKLIENT(TFIBIntegerField * ElementTKLIENT)
{
Object->ElementTKLIENT=ElementTKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementGID_SKLIENT(void)
{
return Object->ElementGID_SKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementGID_SKLIENT(TFIBWideStringField * ElementGID_SKLIENT)
{
Object->ElementGID_SKLIENT=ElementGID_SKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementOKPOKLIENT(void)
{
return Object->ElementOKPOKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementOKPOKLIENT(TFIBWideStringField * ElementOKPOKLIENT)
{
Object->ElementOKPOKLIENT=ElementOKPOKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKlientImpl::get_ElementIDBASE_SKLIENT(void)
{
return Object->ElementIDBASE_SKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementIDBASE_SKLIENT(TFIBBCDField * ElementIDBASE_SKLIENT)
{
Object->ElementIDBASE_SKLIENT=ElementIDBASE_SKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementKRNAME_SKLIENT(void)
{
return Object->ElementKRNAME_SKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementKRNAME_SKLIENT(TFIBWideStringField * ElementKRNAME_SKLIENT)
{
Object->ElementKRNAME_SKLIENT=ElementKRNAME_SKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementDESCR_SKLIENT(void)
{
return Object->ElementDESCR_SKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementDESCR_SKLIENT(TFIBWideStringField * ElementDESCR_SKLIENT)
{
Object->ElementDESCR_SKLIENT=ElementDESCR_SKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementMESSAGE_SKLIENT(void)
{
return Object->ElementMESSAGE_SKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementMESSAGE_SKLIENT(TFIBWideStringField * ElementMESSAGE_SKLIENT)
{
Object->ElementMESSAGE_SKLIENT=ElementMESSAGE_SKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementEMAIL_SKLIENT(void)
{
return Object->ElementEMAIL_SKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementEMAIL_SKLIENT(TFIBWideStringField * ElementEMAIL_SKLIENT)
{
Object->ElementEMAIL_SKLIENT=ElementEMAIL_SKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementWWW_SKLIENT(void)
{
return Object->ElementWWW_SKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementWWW_SKLIENT(TFIBWideStringField * ElementWWW_SKLIENT)
{
Object->ElementWWW_SKLIENT=ElementWWW_SKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementNAME_SVIDKLIENT(void)
{
return Object->ElementNAME_SVIDKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementNAME_SVIDKLIENT(TFIBWideStringField * ElementNAME_SVIDKLIENT)
{
Object->ElementNAME_SVIDKLIENT=ElementNAME_SVIDKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementNAME_SCOUNTRY(void)
{
return Object->ElementNAME_SCOUNTRY;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementNAME_SCOUNTRY(TFIBWideStringField * ElementNAME_SCOUNTRY)
{
Object->ElementNAME_SCOUNTRY=ElementNAME_SCOUNTRY;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementYUR_ADRESS_SKLIENT(void)
{
return Object->ElementYUR_ADRESS_SKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementYUR_ADRESS_SKLIENT(TFIBWideStringField * ElementYUR_ADRESS_SKLIENT)
{
Object->ElementYUR_ADRESS_SKLIENT=ElementYUR_ADRESS_SKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementPOCHT_ADRRESS_SKLIENT(void)
{
return Object->ElementPOCHT_ADRRESS_SKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementPOCHT_ADRRESS_SKLIENT(TFIBWideStringField * ElementPOCHT_ADRRESS_SKLIENT)
{
Object->ElementPOCHT_ADRRESS_SKLIENT=ElementPOCHT_ADRRESS_SKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementFAMILIYA_SKLIENT(void)
{
return Object->ElementFAMILIYA_SKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementFAMILIYA_SKLIENT(TFIBWideStringField * ElementFAMILIYA_SKLIENT)
{
Object->ElementFAMILIYA_SKLIENT=ElementFAMILIYA_SKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementIMYA_SKLIENT(void)
{
return Object->ElementIMYA_SKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementIMYA_SKLIENT(TFIBWideStringField * ElementIMYA_SKLIENT)
{
Object->ElementIMYA_SKLIENT=ElementIMYA_SKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementOTCHESTVO_SKLIENT(void)
{
return Object->ElementOTCHESTVO_SKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementOTCHESTVO_SKLIENT(TFIBWideStringField * ElementOTCHESTVO_SKLIENT)
{
Object->ElementOTCHESTVO_SKLIENT=ElementOTCHESTVO_SKLIENT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprKlientImpl::get_ElementTYPE_POISK_SKLIENT(void)
{
return Object->ElementTYPE_POISK_SKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementTYPE_POISK_SKLIENT(TFIBIntegerField * ElementTYPE_POISK_SKLIENT)
{
Object->ElementTYPE_POISK_SKLIENT=ElementTYPE_POISK_SKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKlientImpl::get_ElementIDGRPNOM_SKLIENT(void)
{
return Object->ElementIDGRPNOM_SKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementIDGRPNOM_SKLIENT(TFIBBCDField * ElementIDGRPNOM_SKLIENT)
{
Object->ElementIDGRPNOM_SKLIENT=ElementIDGRPNOM_SKLIENT;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprKlientImpl::get_ElementIDGRPHW_SKLIENT(void)
{
return Object->ElementIDGRPHW_SKLIENT;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementIDGRPHW_SKLIENT(TFIBBCDField * ElementIDGRPHW_SKLIENT)
{
Object->ElementIDGRPHW_SKLIENT=ElementIDGRPHW_SKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementNAMEGN(void)
{
return Object->ElementNAMEGN;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementNAMEGN(TFIBWideStringField * ElementNAMEGN)
{
Object->ElementNAMEGN=ElementNAMEGN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprKlientImpl::get_ElementNAME_REM_SGRP_HARDWARE(void)
{
return Object->ElementNAME_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_ElementNAME_REM_SGRP_HARDWARE(TFIBWideStringField * ElementNAME_REM_SGRP_HARDWARE)
{
Object->ElementNAME_REM_SGRP_HARDWARE=ElementNAME_REM_SGRP_HARDWARE;
}
//---------------------------------------------------------------
__int64 TDMSprKlientImpl::get_Id(void)
{
return Object->Id;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_Id(__int64 Id)
{
Object->Id=Id;
}
//---------------------------------------------------------------
__int64 TDMSprKlientImpl::get_IdGroup(void)
{
return Object->IdGroup;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_IdGroup(__int64 IdGroup)
{
Object->IdGroup=IdGroup;
}
//---------------------------------------------------------------
bool TDMSprKlientImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
bool TDMSprKlientImpl::get_elSave(void)
{
return Object->elSave;
}
//---------------------------------------------------------------
void TDMSprKlientImpl::set_elSave(bool elSave)
{
Object->elSave=elSave;
}
//---------------------------------------------------------------
bool TDMSprKlientImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
int TDMSprKlientImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprKlientImpl::NewElement(__int64 id_grp)
{
return Object->NewElement( id_grp);
}
//---------------------------------------------------------------
bool TDMSprKlientImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprKlientImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TDMSprKlientImpl::ChancheGrp(__int64 new_grp)
{
return Object->ChancheGrp(new_grp);
}
//---------------------------------------------------------------
__int64 TDMSprKlientImpl::FindPoName(String Name)
{
return Object->FindPoName( Name);
}
//---------------------------------------------------------------
__int64 TDMSprKlientImpl::GetIDKlientPoName(AnsiString name)
{
return Object->GetIDKlientPoName(name);
}
//---------------------------------------------------------------
__int64 TDMSprKlientImpl::GetIdGrpKlient(__int64 id_klient)
{
return Object->GetIdGrpKlient(id_klient);
}
//---------------------------------------------------------------
