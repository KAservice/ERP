#include "vcl.h"
#pragma hdrstop


#include "UREM_DMZayavkaImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMZayavkaImpl::TREM_DMZayavkaImpl()           
{                                            
Object=new TREM_DMZayavka(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMZayavkaImpl::~TREM_DMZayavkaImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMZayavkaImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMZayavka)                        
   {                                                                     
   *ppv=static_cast<IREM_DMZayavka*> (this);                                
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
int TREM_DMZayavkaImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMZayavkaImpl::kanRelease(void)                                  
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
int  TREM_DMZayavkaImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMZayavkaImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMZayavkaImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMZayavkaImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMZayavkaImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMZayavka
TDataSource * TREM_DMZayavkaImpl::get_DataSourceGurZKompl(void)
{
return Object->DataSourceGurZKompl;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DataSourceGurZKompl(TDataSource * DataSourceGurZKompl)
{
Object->DataSourceGurZKompl=DataSourceGurZKompl;
}
//---------------------------------------------------------------
TDataSource * TREM_DMZayavkaImpl::get_DataSourceGurZNeispr(void)
{
return Object->DataSourceGurZNeispr;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DataSourceGurZNeispr(TDataSource * DataSourceGurZNeispr)
{
Object->DataSourceGurZNeispr=DataSourceGurZNeispr;
}
//---------------------------------------------------------------
TDataSource * TREM_DMZayavkaImpl::get_DataSourceGurZ(void)
{
return Object->DataSourceGurZ;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DataSourceGurZ(TDataSource * DataSourceGurZ)
{
Object->DataSourceGurZ=DataSourceGurZ;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMZayavkaImpl::get_GurZ(void)
{
return Object->GurZ;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ(TpFIBDataSet * GurZ)
{
Object->GurZ=GurZ;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMZayavkaImpl::get_GurZKompl(void)
{
return Object->GurZKompl;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZKompl(TpFIBDataSet * GurZKompl)
{
Object->GurZKompl=GurZKompl;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMZayavkaImpl::get_GurZNeispr(void)
{
return Object->GurZNeispr;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNeispr(TpFIBDataSet * GurZNeispr)
{
Object->GurZNeispr=GurZNeispr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMZayavkaImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMZayavkaImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMZayavkaImpl::get_NumDoc(void)
{
return Object->NumDoc;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_NumDoc(TpFIBDataSet * NumDoc)
{
Object->NumDoc=NumDoc;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMZayavkaImpl::get_GurZKomplRECNO(void)
{
return Object->GurZKomplRECNO;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZKomplRECNO(TIntegerField * GurZKomplRECNO)
{
Object->GurZKomplRECNO=GurZKomplRECNO;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMZayavkaImpl::get_GurZNeisprRECNO(void)
{
return Object->GurZNeisprRECNO;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNeisprRECNO(TIntegerField * GurZNeisprRECNO)
{
Object->GurZNeisprRECNO=GurZNeisprRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZID_REM_Z(void)
{
return Object->GurZID_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZID_REM_Z(TFIBLargeIntField * GurZID_REM_Z)
{
Object->GurZID_REM_Z=GurZID_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZGID_REM_Z(void)
{
return Object->GurZGID_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZGID_REM_Z(TFIBWideStringField * GurZGID_REM_Z)
{
Object->GurZGID_REM_Z=GurZGID_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZPREFIKS_REM_Z(void)
{
return Object->GurZPREFIKS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPREFIKS_REM_Z(TFIBWideStringField * GurZPREFIKS_REM_Z)
{
Object->GurZPREFIKS_REM_Z=GurZPREFIKS_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaImpl::get_GurZNUM_REM_Z(void)
{
return Object->GurZNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNUM_REM_Z(TFIBIntegerField * GurZNUM_REM_Z)
{
Object->GurZNUM_REM_Z=GurZNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMZayavkaImpl::get_GurZPOS_REM_Z(void)
{
return Object->GurZPOS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPOS_REM_Z(TFIBDateTimeField * GurZPOS_REM_Z)
{
Object->GurZPOS_REM_Z=GurZPOS_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZIDBASE_REM_Z(void)
{
return Object->GurZIDBASE_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZIDBASE_REM_Z(TFIBLargeIntField * GurZIDBASE_REM_Z)
{
Object->GurZIDBASE_REM_Z=GurZIDBASE_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZIDMODEL_REM_Z(void)
{
return Object->GurZIDMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZIDMODEL_REM_Z(TFIBLargeIntField * GurZIDMODEL_REM_Z)
{
Object->GurZIDMODEL_REM_Z=GurZIDMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZIDSKLPR_REM_Z(void)
{
return Object->GurZIDSKLPR_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZIDSKLPR_REM_Z(TFIBLargeIntField * GurZIDSKLPR_REM_Z)
{
Object->GurZIDSKLPR_REM_Z=GurZIDSKLPR_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZIDKLIENT_REM_Z(void)
{
return Object->GurZIDKLIENT_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZIDKLIENT_REM_Z(TFIBLargeIntField * GurZIDKLIENT_REM_Z)
{
Object->GurZIDKLIENT_REM_Z=GurZIDKLIENT_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZIDDILER_REM_Z(void)
{
return Object->GurZIDDILER_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZIDDILER_REM_Z(TFIBLargeIntField * GurZIDDILER_REM_Z)
{
Object->GurZIDDILER_REM_Z=GurZIDDILER_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNAME_REM_Z(void)
{
return Object->GurZNAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNAME_REM_Z(TFIBWideStringField * GurZNAME_REM_Z)
{
Object->GurZNAME_REM_Z=GurZNAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZDESCR_REM_Z(void)
{
return Object->GurZDESCR_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZDESCR_REM_Z(TFIBWideStringField * GurZDESCR_REM_Z)
{
Object->GurZDESCR_REM_Z=GurZDESCR_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZIDTYPEREM_REM_Z(void)
{
return Object->GurZIDTYPEREM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZIDTYPEREM_REM_Z(TFIBLargeIntField * GurZIDTYPEREM_REM_Z)
{
Object->GurZIDTYPEREM_REM_Z=GurZIDTYPEREM_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZIDSOST_REM_Z(void)
{
return Object->GurZIDSOST_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZIDSOST_REM_Z(TFIBLargeIntField * GurZIDSOST_REM_Z)
{
Object->GurZIDSOST_REM_Z=GurZIDSOST_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZIDTECSKL_REM_Z(void)
{
return Object->GurZIDTECSKL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZIDTECSKL_REM_Z(TFIBLargeIntField * GurZIDTECSKL_REM_Z)
{
Object->GurZIDTECSKL_REM_Z=GurZIDTECSKL_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZIDUSER_REM_Z(void)
{
return Object->GurZIDUSER_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZIDUSER_REM_Z(TFIBLargeIntField * GurZIDUSER_REM_Z)
{
Object->GurZIDUSER_REM_Z=GurZIDUSER_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaImpl::get_GurZOPER_REM_Z(void)
{
return Object->GurZOPER_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZOPER_REM_Z(TFIBIntegerField * GurZOPER_REM_Z)
{
Object->GurZOPER_REM_Z=GurZOPER_REM_Z;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMZayavkaImpl::get_GurZSUM_REM_Z(void)
{
return Object->GurZSUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZSUM_REM_Z(TFIBBCDField * GurZSUM_REM_Z)
{
Object->GurZSUM_REM_Z=GurZSUM_REM_Z;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMZayavkaImpl::get_GurZSROK_REM_Z(void)
{
return Object->GurZSROK_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZSROK_REM_Z(TFIBDateField * GurZSROK_REM_Z)
{
Object->GurZSROK_REM_Z=GurZSROK_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_GurZOUT_REM_Z(void)
{
return Object->GurZOUT_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZOUT_REM_Z(TFIBSmallIntField * GurZOUT_REM_Z)
{
Object->GurZOUT_REM_Z=GurZOUT_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZIDFIRM_REM_Z(void)
{
return Object->GurZIDFIRM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZIDFIRM_REM_Z(TFIBLargeIntField * GurZIDFIRM_REM_Z)
{
Object->GurZIDFIRM_REM_Z=GurZIDFIRM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNAMEFIRM(void)
{
return Object->GurZNAMEFIRM;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNAMEFIRM(TFIBWideStringField * GurZNAMEFIRM)
{
Object->GurZNAMEFIRM=GurZNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNAME_SINFBASE_OBMEN(void)
{
return Object->GurZNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNAME_SINFBASE_OBMEN(TFIBWideStringField * GurZNAME_SINFBASE_OBMEN)
{
Object->GurZNAME_SINFBASE_OBMEN=GurZNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNAME_REM_SMODEL(void)
{
return Object->GurZNAME_REM_SMODEL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNAME_REM_SMODEL(TFIBWideStringField * GurZNAME_REM_SMODEL)
{
Object->GurZNAME_REM_SMODEL=GurZNAME_REM_SMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNAME_SKLAD_PR(void)
{
return Object->GurZNAME_SKLAD_PR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNAME_SKLAD_PR(TFIBWideStringField * GurZNAME_SKLAD_PR)
{
Object->GurZNAME_SKLAD_PR=GurZNAME_SKLAD_PR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNAMEKLIENT(void)
{
return Object->GurZNAMEKLIENT;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNAMEKLIENT(TFIBWideStringField * GurZNAMEKLIENT)
{
Object->GurZNAMEKLIENT=GurZNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNAMEDILER(void)
{
return Object->GurZNAMEDILER;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNAMEDILER(TFIBWideStringField * GurZNAMEDILER)
{
Object->GurZNAMEDILER=GurZNAMEDILER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNAME_STREMONT(void)
{
return Object->GurZNAME_STREMONT;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNAME_STREMONT(TFIBWideStringField * GurZNAME_STREMONT)
{
Object->GurZNAME_STREMONT=GurZNAME_STREMONT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNAME_REMSSOST(void)
{
return Object->GurZNAME_REMSSOST;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNAME_REMSSOST(TFIBWideStringField * GurZNAME_REMSSOST)
{
Object->GurZNAME_REMSSOST=GurZNAME_REMSSOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNAME_SKLAD_TEC(void)
{
return Object->GurZNAME_SKLAD_TEC;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNAME_SKLAD_TEC(TFIBWideStringField * GurZNAME_SKLAD_TEC)
{
Object->GurZNAME_SKLAD_TEC=GurZNAME_SKLAD_TEC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNAME_USER(void)
{
return Object->GurZNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNAME_USER(TFIBWideStringField * GurZNAME_USER)
{
Object->GurZNAME_USER=GurZNAME_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZKomplID_REM_ZKOMPL(void)
{
return Object->GurZKomplID_REM_ZKOMPL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZKomplID_REM_ZKOMPL(TFIBLargeIntField * GurZKomplID_REM_ZKOMPL)
{
Object->GurZKomplID_REM_ZKOMPL=GurZKomplID_REM_ZKOMPL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZKomplGID_REM_ZKOMPL(void)
{
return Object->GurZKomplGID_REM_ZKOMPL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZKomplGID_REM_ZKOMPL(TFIBWideStringField * GurZKomplGID_REM_ZKOMPL)
{
Object->GurZKomplGID_REM_ZKOMPL=GurZKomplGID_REM_ZKOMPL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZKomplPREFIKS_REM_ZKOMPL(void)
{
return Object->GurZKomplPREFIKS_REM_ZKOMPL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZKomplPREFIKS_REM_ZKOMPL(TFIBWideStringField * GurZKomplPREFIKS_REM_ZKOMPL)
{
Object->GurZKomplPREFIKS_REM_ZKOMPL=GurZKomplPREFIKS_REM_ZKOMPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZKomplIDZ_REM_ZKOMPL(void)
{
return Object->GurZKomplIDZ_REM_ZKOMPL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZKomplIDZ_REM_ZKOMPL(TFIBLargeIntField * GurZKomplIDZ_REM_ZKOMPL)
{
Object->GurZKomplIDZ_REM_ZKOMPL=GurZKomplIDZ_REM_ZKOMPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZKomplIDKOMPL_REM_ZKOMPL(void)
{
return Object->GurZKomplIDKOMPL_REM_ZKOMPL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZKomplIDKOMPL_REM_ZKOMPL(TFIBLargeIntField * GurZKomplIDKOMPL_REM_ZKOMPL)
{
Object->GurZKomplIDKOMPL_REM_ZKOMPL=GurZKomplIDKOMPL_REM_ZKOMPL;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMZayavkaImpl::get_GurZKomplKOL_REM_ZKOMPL(void)
{
return Object->GurZKomplKOL_REM_ZKOMPL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZKomplKOL_REM_ZKOMPL(TFIBBCDField * GurZKomplKOL_REM_ZKOMPL)
{
Object->GurZKomplKOL_REM_ZKOMPL=GurZKomplKOL_REM_ZKOMPL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZKomplIDBASE_REM_ZKOMPL(void)
{
return Object->GurZKomplIDBASE_REM_ZKOMPL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZKomplIDBASE_REM_ZKOMPL(TFIBLargeIntField * GurZKomplIDBASE_REM_ZKOMPL)
{
Object->GurZKomplIDBASE_REM_ZKOMPL=GurZKomplIDBASE_REM_ZKOMPL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZKomplNAME_REM_SKOMPLMODEL(void)
{
return Object->GurZKomplNAME_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZKomplNAME_REM_SKOMPLMODEL(TFIBWideStringField * GurZKomplNAME_REM_SKOMPLMODEL)
{
Object->GurZKomplNAME_REM_SKOMPLMODEL=GurZKomplNAME_REM_SKOMPLMODEL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZNeisprID_REM_ZNEISPR(void)
{
return Object->GurZNeisprID_REM_ZNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNeisprID_REM_ZNEISPR(TFIBLargeIntField * GurZNeisprID_REM_ZNEISPR)
{
Object->GurZNeisprID_REM_ZNEISPR=GurZNeisprID_REM_ZNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNeisprGID_REM_ZNEISPR(void)
{
return Object->GurZNeisprGID_REM_ZNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNeisprGID_REM_ZNEISPR(TFIBWideStringField * GurZNeisprGID_REM_ZNEISPR)
{
Object->GurZNeisprGID_REM_ZNEISPR=GurZNeisprGID_REM_ZNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNeisprPREFIKS_REM_ZNEISPR(void)
{
return Object->GurZNeisprPREFIKS_REM_ZNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNeisprPREFIKS_REM_ZNEISPR(TFIBWideStringField * GurZNeisprPREFIKS_REM_ZNEISPR)
{
Object->GurZNeisprPREFIKS_REM_ZNEISPR=GurZNeisprPREFIKS_REM_ZNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZNeisprIDZ_REM_ZNEISPR(void)
{
return Object->GurZNeisprIDZ_REM_ZNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNeisprIDZ_REM_ZNEISPR(TFIBLargeIntField * GurZNeisprIDZ_REM_ZNEISPR)
{
Object->GurZNeisprIDZ_REM_ZNEISPR=GurZNeisprIDZ_REM_ZNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZNeisprIDNEISPR_REM_ZNEISPR(void)
{
return Object->GurZNeisprIDNEISPR_REM_ZNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNeisprIDNEISPR_REM_ZNEISPR(TFIBLargeIntField * GurZNeisprIDNEISPR_REM_ZNEISPR)
{
Object->GurZNeisprIDNEISPR_REM_ZNEISPR=GurZNeisprIDNEISPR_REM_ZNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZNeisprIDBASE_REM_ZNEISPR(void)
{
return Object->GurZNeisprIDBASE_REM_ZNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNeisprIDBASE_REM_ZNEISPR(TFIBLargeIntField * GurZNeisprIDBASE_REM_ZNEISPR)
{
Object->GurZNeisprIDBASE_REM_ZNEISPR=GurZNeisprIDBASE_REM_ZNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNeisprNAME_REM_SNEISPR(void)
{
return Object->GurZNeisprNAME_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNeisprNAME_REM_SNEISPR(TFIBWideStringField * GurZNeisprNAME_REM_SNEISPR)
{
Object->GurZNeisprNAME_REM_SNEISPR=GurZNeisprNAME_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNEISPR_REM_Z(void)
{
return Object->GurZNEISPR_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNEISPR_REM_Z(TFIBWideStringField * GurZNEISPR_REM_Z)
{
Object->GurZNEISPR_REM_Z=GurZNEISPR_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZKLIENT_NAME_REM_Z(void)
{
return Object->GurZKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZKLIENT_NAME_REM_Z(TFIBWideStringField * GurZKLIENT_NAME_REM_Z)
{
Object->GurZKLIENT_NAME_REM_Z=GurZKLIENT_NAME_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZKLIENT_ADR_REM_Z(void)
{
return Object->GurZKLIENT_ADR_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZKLIENT_ADR_REM_Z(TFIBWideStringField * GurZKLIENT_ADR_REM_Z)
{
Object->GurZKLIENT_ADR_REM_Z=GurZKLIENT_ADR_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZKLIENT_PHONE_REM_Z(void)
{
return Object->GurZKLIENT_PHONE_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZKLIENT_PHONE_REM_Z(TFIBWideStringField * GurZKLIENT_PHONE_REM_Z)
{
Object->GurZKLIENT_PHONE_REM_Z=GurZKLIENT_PHONE_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZKOMPLECT_REM_Z(void)
{
return Object->GurZKOMPLECT_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZKOMPLECT_REM_Z(TFIBWideStringField * GurZKOMPLECT_REM_Z)
{
Object->GurZKOMPLECT_REM_Z=GurZKOMPLECT_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZMODEL_REM_Z(void)
{
return Object->GurZMODEL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZMODEL_REM_Z(TFIBWideStringField * GurZMODEL_REM_Z)
{
Object->GurZMODEL_REM_Z=GurZMODEL_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZSOST_REM_Z(void)
{
return Object->GurZSOST_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZSOST_REM_Z(TFIBWideStringField * GurZSOST_REM_Z)
{
Object->GurZSOST_REM_Z=GurZSOST_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZSERNUM2_REM_Z(void)
{
return Object->GurZSERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZSERNUM2_REM_Z(TFIBWideStringField * GurZSERNUM2_REM_Z)
{
Object->GurZSERNUM2_REM_Z=GurZSERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZSERNUM_REM_Z(void)
{
return Object->GurZSERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZSERNUM_REM_Z(TFIBWideStringField * GurZSERNUM_REM_Z)
{
Object->GurZSERNUM_REM_Z=GurZSERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZCOMENTS_REM_Z(void)
{
return Object->GurZCOMENTS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZCOMENTS_REM_Z(TFIBWideStringField * GurZCOMENTS_REM_Z)
{
Object->GurZCOMENTS_REM_Z=GurZCOMENTS_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMZayavkaImpl::get_GurZPOSOUT_REM_Z(void)
{
return Object->GurZPOSOUT_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPOSOUT_REM_Z(TFIBDateTimeField * GurZPOSOUT_REM_Z)
{
Object->GurZPOSOUT_REM_Z=GurZPOSOUT_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMZayavkaImpl::get_GurZPOSREMONT_REM_Z(void)
{
return Object->GurZPOSREMONT_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPOSREMONT_REM_Z(TFIBDateTimeField * GurZPOSREMONT_REM_Z)
{
Object->GurZPOSREMONT_REM_Z=GurZPOSREMONT_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaImpl::get_GurZWARRANTY_REM_Z(void)
{
return Object->GurZWARRANTY_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZWARRANTY_REM_Z(TFIBIntegerField * GurZWARRANTY_REM_Z)
{
Object->GurZWARRANTY_REM_Z=GurZWARRANTY_REM_Z;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMZayavkaImpl::get_DopUsl(void)
{
return Object->DopUsl;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DopUsl(TpFIBDataSet * DopUsl)
{
Object->DopUsl=DopUsl;
}
//---------------------------------------------------------------
TDataSource * TREM_DMZayavkaImpl::get_DataSourceDopUsl(void)
{
return Object->DataSourceDopUsl;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DataSourceDopUsl(TDataSource * DataSourceDopUsl)
{
Object->DataSourceDopUsl=DataSourceDopUsl;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_DopUslID_REM_ZDOPUSL(void)
{
return Object->DopUslID_REM_ZDOPUSL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DopUslID_REM_ZDOPUSL(TFIBLargeIntField * DopUslID_REM_ZDOPUSL)
{
Object->DopUslID_REM_ZDOPUSL=DopUslID_REM_ZDOPUSL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_DopUslGID_REM_ZDOPUSL(void)
{
return Object->DopUslGID_REM_ZDOPUSL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DopUslGID_REM_ZDOPUSL(TFIBWideStringField * DopUslGID_REM_ZDOPUSL)
{
Object->DopUslGID_REM_ZDOPUSL=DopUslGID_REM_ZDOPUSL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_DopUslIDBASE_REM_ZDOPUSL(void)
{
return Object->DopUslIDBASE_REM_ZDOPUSL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DopUslIDBASE_REM_ZDOPUSL(TFIBLargeIntField * DopUslIDBASE_REM_ZDOPUSL)
{
Object->DopUslIDBASE_REM_ZDOPUSL=DopUslIDBASE_REM_ZDOPUSL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_DopUslIDZ_REM_ZDOPUSL(void)
{
return Object->DopUslIDZ_REM_ZDOPUSL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DopUslIDZ_REM_ZDOPUSL(TFIBLargeIntField * DopUslIDZ_REM_ZDOPUSL)
{
Object->DopUslIDZ_REM_ZDOPUSL=DopUslIDZ_REM_ZDOPUSL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_DopUslIDNOM_REM_ZDOPUSL(void)
{
return Object->DopUslIDNOM_REM_ZDOPUSL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DopUslIDNOM_REM_ZDOPUSL(TFIBLargeIntField * DopUslIDNOM_REM_ZDOPUSL)
{
Object->DopUslIDNOM_REM_ZDOPUSL=DopUslIDNOM_REM_ZDOPUSL;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_DopUslIDED_REM_ZDOPUSL(void)
{
return Object->DopUslIDED_REM_ZDOPUSL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DopUslIDED_REM_ZDOPUSL(TFIBLargeIntField * DopUslIDED_REM_ZDOPUSL)
{
Object->DopUslIDED_REM_ZDOPUSL=DopUslIDED_REM_ZDOPUSL;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMZayavkaImpl::get_DopUslKOL_REM_ZDOPUSL(void)
{
return Object->DopUslKOL_REM_ZDOPUSL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DopUslKOL_REM_ZDOPUSL(TFIBBCDField * DopUslKOL_REM_ZDOPUSL)
{
Object->DopUslKOL_REM_ZDOPUSL=DopUslKOL_REM_ZDOPUSL;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMZayavkaImpl::get_DopUslKF_REM_ZDOPUSL(void)
{
return Object->DopUslKF_REM_ZDOPUSL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DopUslKF_REM_ZDOPUSL(TFIBBCDField * DopUslKF_REM_ZDOPUSL)
{
Object->DopUslKF_REM_ZDOPUSL=DopUslKF_REM_ZDOPUSL;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMZayavkaImpl::get_DopUslPRICE_REM_ZDOPUSL(void)
{
return Object->DopUslPRICE_REM_ZDOPUSL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DopUslPRICE_REM_ZDOPUSL(TFIBBCDField * DopUslPRICE_REM_ZDOPUSL)
{
Object->DopUslPRICE_REM_ZDOPUSL=DopUslPRICE_REM_ZDOPUSL;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMZayavkaImpl::get_DopUslSUM_REM_ZDOPUSL(void)
{
return Object->DopUslSUM_REM_ZDOPUSL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DopUslSUM_REM_ZDOPUSL(TFIBBCDField * DopUslSUM_REM_ZDOPUSL)
{
Object->DopUslSUM_REM_ZDOPUSL=DopUslSUM_REM_ZDOPUSL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_DopUslTEXTNOM_REM_ZDOPUSL(void)
{
return Object->DopUslTEXTNOM_REM_ZDOPUSL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DopUslTEXTNOM_REM_ZDOPUSL(TFIBWideStringField * DopUslTEXTNOM_REM_ZDOPUSL)
{
Object->DopUslTEXTNOM_REM_ZDOPUSL=DopUslTEXTNOM_REM_ZDOPUSL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_DopUslNAMENOM(void)
{
return Object->DopUslNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DopUslNAMENOM(TFIBWideStringField * DopUslNAMENOM)
{
Object->DopUslNAMENOM=DopUslNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_DopUslNAMEED(void)
{
return Object->DopUslNAMEED;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DopUslNAMEED(TFIBWideStringField * DopUslNAMEED)
{
Object->DopUslNAMEED=DopUslNAMEED;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMZayavkaImpl::get_PerformedWork(void)
{
return Object->PerformedWork;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWork(TpFIBDataSet * PerformedWork)
{
Object->PerformedWork=PerformedWork;
}
//---------------------------------------------------------------
TDataSource * TREM_DMZayavkaImpl::get_DataSourcePerformedWork(void)
{
return Object->DataSourcePerformedWork;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DataSourcePerformedWork(TDataSource * DataSourcePerformedWork)
{
Object->DataSourcePerformedWork=DataSourcePerformedWork;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_PerformedWorkID_REM_ZPERFWORK(void)
{
return Object->PerformedWorkID_REM_ZPERFWORK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkID_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkID_REM_ZPERFWORK)
{
Object->PerformedWorkID_REM_ZPERFWORK=PerformedWorkID_REM_ZPERFWORK;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_PerformedWorkGID_REM_ZPERFWORK(void)
{
return Object->PerformedWorkGID_REM_ZPERFWORK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkGID_REM_ZPERFWORK(TFIBWideStringField * PerformedWorkGID_REM_ZPERFWORK)
{
Object->PerformedWorkGID_REM_ZPERFWORK=PerformedWorkGID_REM_ZPERFWORK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_PerformedWorkIDBASE_REM_ZPERFWORK(void)
{
return Object->PerformedWorkIDBASE_REM_ZPERFWORK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkIDBASE_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkIDBASE_REM_ZPERFWORK)
{
Object->PerformedWorkIDBASE_REM_ZPERFWORK=PerformedWorkIDBASE_REM_ZPERFWORK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_PerformedWorkIDZ_REM_ZPERFWORK(void)
{
return Object->PerformedWorkIDZ_REM_ZPERFWORK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkIDZ_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkIDZ_REM_ZPERFWORK)
{
Object->PerformedWorkIDZ_REM_ZPERFWORK=PerformedWorkIDZ_REM_ZPERFWORK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_PerformedWorkIDNOM_REM_ZPERFWORK(void)
{
return Object->PerformedWorkIDNOM_REM_ZPERFWORK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkIDNOM_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkIDNOM_REM_ZPERFWORK)
{
Object->PerformedWorkIDNOM_REM_ZPERFWORK=PerformedWorkIDNOM_REM_ZPERFWORK;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_PerformedWorkIDED_REM_ZPERFWORK(void)
{
return Object->PerformedWorkIDED_REM_ZPERFWORK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkIDED_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkIDED_REM_ZPERFWORK)
{
Object->PerformedWorkIDED_REM_ZPERFWORK=PerformedWorkIDED_REM_ZPERFWORK;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMZayavkaImpl::get_PerformedWorkKOL_REM_ZPERFWORK(void)
{
return Object->PerformedWorkKOL_REM_ZPERFWORK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkKOL_REM_ZPERFWORK(TFIBBCDField * PerformedWorkKOL_REM_ZPERFWORK)
{
Object->PerformedWorkKOL_REM_ZPERFWORK=PerformedWorkKOL_REM_ZPERFWORK;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMZayavkaImpl::get_PerformedWorkKF_REM_ZPERFWORK(void)
{
return Object->PerformedWorkKF_REM_ZPERFWORK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkKF_REM_ZPERFWORK(TFIBBCDField * PerformedWorkKF_REM_ZPERFWORK)
{
Object->PerformedWorkKF_REM_ZPERFWORK=PerformedWorkKF_REM_ZPERFWORK;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMZayavkaImpl::get_PerformedWorkPRICE_REM_ZPERFWORK(void)
{
return Object->PerformedWorkPRICE_REM_ZPERFWORK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkPRICE_REM_ZPERFWORK(TFIBBCDField * PerformedWorkPRICE_REM_ZPERFWORK)
{
Object->PerformedWorkPRICE_REM_ZPERFWORK=PerformedWorkPRICE_REM_ZPERFWORK;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMZayavkaImpl::get_PerformedWorkSUM_REM_ZPERFWORK(void)
{
return Object->PerformedWorkSUM_REM_ZPERFWORK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkSUM_REM_ZPERFWORK(TFIBBCDField * PerformedWorkSUM_REM_ZPERFWORK)
{
Object->PerformedWorkSUM_REM_ZPERFWORK=PerformedWorkSUM_REM_ZPERFWORK;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_PerformedWorkTEXTNOM_REM_ZPERFWORK(void)
{
return Object->PerformedWorkTEXTNOM_REM_ZPERFWORK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkTEXTNOM_REM_ZPERFWORK(TFIBWideStringField * PerformedWorkTEXTNOM_REM_ZPERFWORK)
{
Object->PerformedWorkTEXTNOM_REM_ZPERFWORK=PerformedWorkTEXTNOM_REM_ZPERFWORK;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMZayavkaImpl::get_PerformedWorkPOS_REM_ZPERFWORK(void)
{
return Object->PerformedWorkPOS_REM_ZPERFWORK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkPOS_REM_ZPERFWORK(TFIBDateTimeField * PerformedWorkPOS_REM_ZPERFWORK)
{
Object->PerformedWorkPOS_REM_ZPERFWORK=PerformedWorkPOS_REM_ZPERFWORK;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_PerformedWorkRESULT_REM_ZPERFWORK(void)
{
return Object->PerformedWorkRESULT_REM_ZPERFWORK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkRESULT_REM_ZPERFWORK(TFIBSmallIntField * PerformedWorkRESULT_REM_ZPERFWORK)
{
Object->PerformedWorkRESULT_REM_ZPERFWORK=PerformedWorkRESULT_REM_ZPERFWORK;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_PerformedWorkADDACT_REM_ZPERFWORK(void)
{
return Object->PerformedWorkADDACT_REM_ZPERFWORK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkADDACT_REM_ZPERFWORK(TFIBSmallIntField * PerformedWorkADDACT_REM_ZPERFWORK)
{
Object->PerformedWorkADDACT_REM_ZPERFWORK=PerformedWorkADDACT_REM_ZPERFWORK;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_PerformedWorkSHOWFORUSER_REM_ZPERFWORK(void)
{
return Object->PerformedWorkSHOWFORUSER_REM_ZPERFWORK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkSHOWFORUSER_REM_ZPERFWORK(TFIBSmallIntField * PerformedWorkSHOWFORUSER_REM_ZPERFWORK)
{
Object->PerformedWorkSHOWFORUSER_REM_ZPERFWORK=PerformedWorkSHOWFORUSER_REM_ZPERFWORK;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_PerformedWorkNAMENOM(void)
{
return Object->PerformedWorkNAMENOM;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkNAMENOM(TFIBWideStringField * PerformedWorkNAMENOM)
{
Object->PerformedWorkNAMENOM=PerformedWorkNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_PerformedWorkNAMEED(void)
{
return Object->PerformedWorkNAMEED;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkNAMEED(TFIBWideStringField * PerformedWorkNAMEED)
{
Object->PerformedWorkNAMEED=PerformedWorkNAMEED;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_PerformedWorkIDUSER_REM_ZPERFWORK(void)
{
return Object->PerformedWorkIDUSER_REM_ZPERFWORK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkIDUSER_REM_ZPERFWORK(TFIBLargeIntField * PerformedWorkIDUSER_REM_ZPERFWORK)
{
Object->PerformedWorkIDUSER_REM_ZPERFWORK=PerformedWorkIDUSER_REM_ZPERFWORK;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_PerformedWorkNAME_USER(void)
{
return Object->PerformedWorkNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_PerformedWorkNAME_USER(TFIBWideStringField * PerformedWorkNAME_USER)
{
Object->PerformedWorkNAME_USER=PerformedWorkNAME_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZIDMEXANIK_REM_Z(void)
{
return Object->GurZIDMEXANIK_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZIDMEXANIK_REM_Z(TFIBLargeIntField * GurZIDMEXANIK_REM_Z)
{
Object->GurZIDMEXANIK_REM_Z=GurZIDMEXANIK_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZIDBRAND_REM_Z(void)
{
return Object->GurZIDBRAND_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZIDBRAND_REM_Z(TFIBLargeIntField * GurZIDBRAND_REM_Z)
{
Object->GurZIDBRAND_REM_Z=GurZIDBRAND_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZIDACTCAT_REM_Z(void)
{
return Object->GurZIDACTCAT_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZIDACTCAT_REM_Z(TFIBLargeIntField * GurZIDACTCAT_REM_Z)
{
Object->GurZIDACTCAT_REM_Z=GurZIDACTCAT_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZGUID_REM_Z(void)
{
return Object->GurZGUID_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZGUID_REM_Z(TFIBWideStringField * GurZGUID_REM_Z)
{
Object->GurZGUID_REM_Z=GurZGUID_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZIDZOSN_REM_Z(void)
{
return Object->GurZIDZOSN_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZIDZOSN_REM_Z(TFIBLargeIntField * GurZIDZOSN_REM_Z)
{
Object->GurZIDZOSN_REM_Z=GurZIDZOSN_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_GurZFL_POVTOR_REM_Z(void)
{
return Object->GurZFL_POVTOR_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZFL_POVTOR_REM_Z(TFIBSmallIntField * GurZFL_POVTOR_REM_Z)
{
Object->GurZFL_POVTOR_REM_Z=GurZFL_POVTOR_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZDILER_NUMZ_REM_Z(void)
{
return Object->GurZDILER_NUMZ_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZDILER_NUMZ_REM_Z(TFIBWideStringField * GurZDILER_NUMZ_REM_Z)
{
Object->GurZDILER_NUMZ_REM_Z=GurZDILER_NUMZ_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMZayavkaImpl::get_GurZDILER_POSZ_REM_Z(void)
{
return Object->GurZDILER_POSZ_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZDILER_POSZ_REM_Z(TFIBDateTimeField * GurZDILER_POSZ_REM_Z)
{
Object->GurZDILER_POSZ_REM_Z=GurZDILER_POSZ_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZDILER_GUIDZ_REM_Z(void)
{
return Object->GurZDILER_GUIDZ_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZDILER_GUIDZ_REM_Z(TFIBWideStringField * GurZDILER_GUIDZ_REM_Z)
{
Object->GurZDILER_GUIDZ_REM_Z=GurZDILER_GUIDZ_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZSC_NUMZ_REM_Z(void)
{
return Object->GurZSC_NUMZ_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZSC_NUMZ_REM_Z(TFIBWideStringField * GurZSC_NUMZ_REM_Z)
{
Object->GurZSC_NUMZ_REM_Z=GurZSC_NUMZ_REM_Z;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMZayavkaImpl::get_GurZSC_POSZ_REM_Z(void)
{
return Object->GurZSC_POSZ_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZSC_POSZ_REM_Z(TFIBDateTimeField * GurZSC_POSZ_REM_Z)
{
Object->GurZSC_POSZ_REM_Z=GurZSC_POSZ_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZSC_GUIDZ_REM_Z(void)
{
return Object->GurZSC_GUIDZ_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZSC_GUIDZ_REM_Z(TFIBWideStringField * GurZSC_GUIDZ_REM_Z)
{
Object->GurZSC_GUIDZ_REM_Z=GurZSC_GUIDZ_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_GurZFL_ADDREPORT_REM_Z(void)
{
return Object->GurZFL_ADDREPORT_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZFL_ADDREPORT_REM_Z(TFIBSmallIntField * GurZFL_ADDREPORT_REM_Z)
{
Object->GurZFL_ADDREPORT_REM_Z=GurZFL_ADDREPORT_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZSERNUM_STR_REM_Z(void)
{
return Object->GurZSERNUM_STR_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZSERNUM_STR_REM_Z(TFIBWideStringField * GurZSERNUM_STR_REM_Z)
{
Object->GurZSERNUM_STR_REM_Z=GurZSERNUM_STR_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNAME_MEXANIK(void)
{
return Object->GurZNAME_MEXANIK;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNAME_MEXANIK(TFIBWideStringField * GurZNAME_MEXANIK)
{
Object->GurZNAME_MEXANIK=GurZNAME_MEXANIK;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNAME_SBRAND(void)
{
return Object->GurZNAME_SBRAND;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNAME_SBRAND(TFIBWideStringField * GurZNAME_SBRAND)
{
Object->GurZNAME_SBRAND=GurZNAME_SBRAND;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNAME_REM_SACTCATEGORY(void)
{
return Object->GurZNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNAME_REM_SACTCATEGORY(TFIBWideStringField * GurZNAME_REM_SACTCATEGORY)
{
Object->GurZNAME_REM_SACTCATEGORY=GurZNAME_REM_SACTCATEGORY;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZIDHW_REM_Z(void)
{
return Object->GurZIDHW_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZIDHW_REM_Z(TFIBLargeIntField * GurZIDHW_REM_Z)
{
Object->GurZIDHW_REM_Z=GurZIDHW_REM_Z;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZIDKKT_REM_Z(void)
{
return Object->GurZIDKKT_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZIDKKT_REM_Z(TFIBLargeIntField * GurZIDKKT_REM_Z)
{
Object->GurZIDKKT_REM_Z=GurZIDKKT_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNAME_REM_SHARDWARE(void)
{
return Object->GurZNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNAME_REM_SHARDWARE(TFIBWideStringField * GurZNAME_REM_SHARDWARE)
{
Object->GurZNAME_REM_SHARDWARE=GurZNAME_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZSERNUM_REM_SHARDWARE(void)
{
return Object->GurZSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZSERNUM_REM_SHARDWARE(TFIBWideStringField * GurZSERNUM_REM_SHARDWARE)
{
Object->GurZSERNUM_REM_SHARDWARE=GurZSERNUM_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZSERNUM2_REM_SHARDWARE(void)
{
return Object->GurZSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZSERNUM2_REM_SHARDWARE(TFIBWideStringField * GurZSERNUM2_REM_SHARDWARE)
{
Object->GurZSERNUM2_REM_SHARDWARE=GurZSERNUM2_REM_SHARDWARE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNAME_REM_SKKT(void)
{
return Object->GurZNAME_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNAME_REM_SKKT(TFIBWideStringField * GurZNAME_REM_SKKT)
{
Object->GurZNAME_REM_SKKT=GurZNAME_REM_SKKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZSERNUM_REM_SKKT(void)
{
return Object->GurZSERNUM_REM_SKKT;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZSERNUM_REM_SKKT(TFIBWideStringField * GurZSERNUM_REM_SKKT)
{
Object->GurZSERNUM_REM_SKKT=GurZSERNUM_REM_SKKT;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaImpl::get_GurZFL_KLIENT_UVEDOML_REM_Z(void)
{
return Object->GurZFL_KLIENT_UVEDOML_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZFL_KLIENT_UVEDOML_REM_Z(TFIBIntegerField * GurZFL_KLIENT_UVEDOML_REM_Z)
{
Object->GurZFL_KLIENT_UVEDOML_REM_Z=GurZFL_KLIENT_UVEDOML_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaImpl::get_GurZFL_TREB_KONS_KL_REM_Z(void)
{
return Object->GurZFL_TREB_KONS_KL_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZFL_TREB_KONS_KL_REM_Z(TFIBIntegerField * GurZFL_TREB_KONS_KL_REM_Z)
{
Object->GurZFL_TREB_KONS_KL_REM_Z=GurZFL_TREB_KONS_KL_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaImpl::get_GurZFL_KL_OTV_NA_ZAPROS_REM_Z(void)
{
return Object->GurZFL_KL_OTV_NA_ZAPROS_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZFL_KL_OTV_NA_ZAPROS_REM_Z(TFIBIntegerField * GurZFL_KL_OTV_NA_ZAPROS_REM_Z)
{
Object->GurZFL_KL_OTV_NA_ZAPROS_REM_Z=GurZFL_KL_OTV_NA_ZAPROS_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZPREFIKS_NUM_REM_Z(void)
{
return Object->GurZPREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPREFIKS_NUM_REM_Z(TFIBWideStringField * GurZPREFIKS_NUM_REM_Z)
{
Object->GurZPREFIKS_NUM_REM_Z=GurZPREFIKS_NUM_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNUM_GARDOC_REM_Z(void)
{
return Object->GurZNUM_GARDOC_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNUM_GARDOC_REM_Z(TFIBWideStringField * GurZNUM_GARDOC_REM_Z)
{
Object->GurZNUM_GARDOC_REM_Z=GurZNUM_GARDOC_REM_Z;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaImpl::get_GurZFL_FICTIV_REM_Z(void)
{
return Object->GurZFL_FICTIV_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZFL_FICTIV_REM_Z(TFIBIntegerField * GurZFL_FICTIV_REM_Z)
{
Object->GurZFL_FICTIV_REM_Z=GurZFL_FICTIV_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_GurZFL_NE_OTCH_REM_Z(void)
{
return Object->GurZFL_NE_OTCH_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZFL_NE_OTCH_REM_Z(TFIBSmallIntField * GurZFL_NE_OTCH_REM_Z)
{
Object->GurZFL_NE_OTCH_REM_Z=GurZFL_NE_OTCH_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_GurZFL_NADO_OTCH_REM_Z(void)
{
return Object->GurZFL_NADO_OTCH_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZFL_NADO_OTCH_REM_Z(TFIBSmallIntField * GurZFL_NADO_OTCH_REM_Z)
{
Object->GurZFL_NADO_OTCH_REM_Z=GurZFL_NADO_OTCH_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_GurZFL_ISM_GARDOC_REM_Z(void)
{
return Object->GurZFL_ISM_GARDOC_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZFL_ISM_GARDOC_REM_Z(TFIBSmallIntField * GurZFL_ISM_GARDOC_REM_Z)
{
Object->GurZFL_ISM_GARDOC_REM_Z=GurZFL_ISM_GARDOC_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_GurZFL_ISM_SERNUM_REM_Z(void)
{
return Object->GurZFL_ISM_SERNUM_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZFL_ISM_SERNUM_REM_Z(TFIBSmallIntField * GurZFL_ISM_SERNUM_REM_Z)
{
Object->GurZFL_ISM_SERNUM_REM_Z=GurZFL_ISM_SERNUM_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_GurZFL_ISM_SERNUM2_REM_Z(void)
{
return Object->GurZFL_ISM_SERNUM2_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZFL_ISM_SERNUM2_REM_Z(TFIBSmallIntField * GurZFL_ISM_SERNUM2_REM_Z)
{
Object->GurZFL_ISM_SERNUM2_REM_Z=GurZFL_ISM_SERNUM2_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNUM_GARDOC_NEW_REM_Z(void)
{
return Object->GurZNUM_GARDOC_NEW_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNUM_GARDOC_NEW_REM_Z(TFIBWideStringField * GurZNUM_GARDOC_NEW_REM_Z)
{
Object->GurZNUM_GARDOC_NEW_REM_Z=GurZNUM_GARDOC_NEW_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZSERNUM_NEW_REM_Z(void)
{
return Object->GurZSERNUM_NEW_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZSERNUM_NEW_REM_Z(TFIBWideStringField * GurZSERNUM_NEW_REM_Z)
{
Object->GurZSERNUM_NEW_REM_Z=GurZSERNUM_NEW_REM_Z;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZSERNUM2_NEW_REM_Z(void)
{
return Object->GurZSERNUM2_NEW_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZSERNUM2_NEW_REM_Z(TFIBWideStringField * GurZSERNUM2_NEW_REM_Z)
{
Object->GurZSERNUM2_NEW_REM_Z=GurZSERNUM2_NEW_REM_Z;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_GurZGOTOVO_K_VIDACHE_REM_Z(void)
{
return Object->GurZGOTOVO_K_VIDACHE_REM_Z;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZGOTOVO_K_VIDACHE_REM_Z(TFIBSmallIntField * GurZGOTOVO_K_VIDACHE_REM_Z)
{
Object->GurZGOTOVO_K_VIDACHE_REM_Z=GurZGOTOVO_K_VIDACHE_REM_Z;
}
//---------------------------------------------------------------
TDataSource * TREM_DMZayavkaImpl::get_DataSourceGurZ_1(void)
{
return Object->DataSourceGurZ_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DataSourceGurZ_1(TDataSource * DataSourceGurZ_1)
{
Object->DataSourceGurZ_1=DataSourceGurZ_1;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMZayavkaImpl::get_GurZ_1(void)
{
return Object->GurZ_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1(TpFIBDataSet * GurZ_1)
{
Object->GurZ_1=GurZ_1;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZ_1ID_REM_Z_1(void)
{
return Object->GurZ_1ID_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1ID_REM_Z_1(TFIBLargeIntField * GurZ_1ID_REM_Z_1)
{
Object->GurZ_1ID_REM_Z_1=GurZ_1ID_REM_Z_1;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZ_1IDBASE_REM_Z_1(void)
{
return Object->GurZ_1IDBASE_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1IDBASE_REM_Z_1(TFIBLargeIntField * GurZ_1IDBASE_REM_Z_1)
{
Object->GurZ_1IDBASE_REM_Z_1=GurZ_1IDBASE_REM_Z_1;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZ_1IDZ_REM_Z_1(void)
{
return Object->GurZ_1IDZ_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1IDZ_REM_Z_1(TFIBLargeIntField * GurZ_1IDZ_REM_Z_1)
{
Object->GurZ_1IDZ_REM_Z_1=GurZ_1IDZ_REM_Z_1;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZ_1IDPRMODEL_REM_Z_1(void)
{
return Object->GurZ_1IDPRMODEL_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1IDPRMODEL_REM_Z_1(TFIBLargeIntField * GurZ_1IDPRMODEL_REM_Z_1)
{
Object->GurZ_1IDPRMODEL_REM_Z_1=GurZ_1IDPRMODEL_REM_Z_1;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZ_1IDPRODUCER_REM_Z_1(void)
{
return Object->GurZ_1IDPRODUCER_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1IDPRODUCER_REM_Z_1(TFIBLargeIntField * GurZ_1IDPRODUCER_REM_Z_1)
{
Object->GurZ_1IDPRODUCER_REM_Z_1=GurZ_1IDPRODUCER_REM_Z_1;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaImpl::get_GurZ_1FL_VKL_REM_Z_1(void)
{
return Object->GurZ_1FL_VKL_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1FL_VKL_REM_Z_1(TFIBIntegerField * GurZ_1FL_VKL_REM_Z_1)
{
Object->GurZ_1FL_VKL_REM_Z_1=GurZ_1FL_VKL_REM_Z_1;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaImpl::get_GurZ_1FL_ZIP_REM_Z_1(void)
{
return Object->GurZ_1FL_ZIP_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1FL_ZIP_REM_Z_1(TFIBIntegerField * GurZ_1FL_ZIP_REM_Z_1)
{
Object->GurZ_1FL_ZIP_REM_Z_1=GurZ_1FL_ZIP_REM_Z_1;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaImpl::get_GurZ_1FL_DEFECT_DEMO_REM_Z_1(void)
{
return Object->GurZ_1FL_DEFECT_DEMO_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1FL_DEFECT_DEMO_REM_Z_1(TFIBIntegerField * GurZ_1FL_DEFECT_DEMO_REM_Z_1)
{
Object->GurZ_1FL_DEFECT_DEMO_REM_Z_1=GurZ_1FL_DEFECT_DEMO_REM_Z_1;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaImpl::get_GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1(void)
{
return Object->GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1(TFIBIntegerField * GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1)
{
Object->GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1=GurZ_1FL_KL_PREDUPR_NO_GARANT_REM_Z_1;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZ_1IDSELLER_REM_Z_1(void)
{
return Object->GurZ_1IDSELLER_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1IDSELLER_REM_Z_1(TFIBLargeIntField * GurZ_1IDSELLER_REM_Z_1)
{
Object->GurZ_1IDSELLER_REM_Z_1=GurZ_1IDSELLER_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1KLIENT_EMAIL_REM_Z_1(void)
{
return Object->GurZ_1KLIENT_EMAIL_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1KLIENT_EMAIL_REM_Z_1(TFIBWideStringField * GurZ_1KLIENT_EMAIL_REM_Z_1)
{
Object->GurZ_1KLIENT_EMAIL_REM_Z_1=GurZ_1KLIENT_EMAIL_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1KLIENT_DOP_INFO_REM_Z_1(void)
{
return Object->GurZ_1KLIENT_DOP_INFO_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1KLIENT_DOP_INFO_REM_Z_1(TFIBWideStringField * GurZ_1KLIENT_DOP_INFO_REM_Z_1)
{
Object->GurZ_1KLIENT_DOP_INFO_REM_Z_1=GurZ_1KLIENT_DOP_INFO_REM_Z_1;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZ_1IDADRKV_REM_Z_1(void)
{
return Object->GurZ_1IDADRKV_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1IDADRKV_REM_Z_1(TFIBLargeIntField * GurZ_1IDADRKV_REM_Z_1)
{
Object->GurZ_1IDADRKV_REM_Z_1=GurZ_1IDADRKV_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1NAME_SPRODUCER(void)
{
return Object->GurZ_1NAME_SPRODUCER;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1NAME_SPRODUCER(TFIBWideStringField * GurZ_1NAME_SPRODUCER)
{
Object->GurZ_1NAME_SPRODUCER=GurZ_1NAME_SPRODUCER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1NAME_REM_SPRMODEL(void)
{
return Object->GurZ_1NAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1NAME_REM_SPRMODEL(TFIBWideStringField * GurZ_1NAME_REM_SPRMODEL)
{
Object->GurZ_1NAME_REM_SPRMODEL=GurZ_1NAME_REM_SPRMODEL;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1NAME_SSELLER(void)
{
return Object->GurZ_1NAME_SSELLER;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1NAME_SSELLER(TFIBWideStringField * GurZ_1NAME_SSELLER)
{
Object->GurZ_1NAME_SSELLER=GurZ_1NAME_SSELLER;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1NAME_SADR_DOM(void)
{
return Object->GurZ_1NAME_SADR_DOM;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1NAME_SADR_DOM(TFIBWideStringField * GurZ_1NAME_SADR_DOM)
{
Object->GurZ_1NAME_SADR_DOM=GurZ_1NAME_SADR_DOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1NAME_SADR_STREET(void)
{
return Object->GurZ_1NAME_SADR_STREET;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1NAME_SADR_STREET(TFIBWideStringField * GurZ_1NAME_SADR_STREET)
{
Object->GurZ_1NAME_SADR_STREET=GurZ_1NAME_SADR_STREET;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1POSTCODE_SADR_STREET(void)
{
return Object->GurZ_1POSTCODE_SADR_STREET;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1POSTCODE_SADR_STREET(TFIBWideStringField * GurZ_1POSTCODE_SADR_STREET)
{
Object->GurZ_1POSTCODE_SADR_STREET=GurZ_1POSTCODE_SADR_STREET;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1NAME_SADR_NASPUNKT(void)
{
return Object->GurZ_1NAME_SADR_NASPUNKT;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1NAME_SADR_NASPUNKT(TFIBWideStringField * GurZ_1NAME_SADR_NASPUNKT)
{
Object->GurZ_1NAME_SADR_NASPUNKT=GurZ_1NAME_SADR_NASPUNKT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1NAME_SADR_REGION(void)
{
return Object->GurZ_1NAME_SADR_REGION;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1NAME_SADR_REGION(TFIBWideStringField * GurZ_1NAME_SADR_REGION)
{
Object->GurZ_1NAME_SADR_REGION=GurZ_1NAME_SADR_REGION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1CODE_SADR_REGION(void)
{
return Object->GurZ_1CODE_SADR_REGION;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1CODE_SADR_REGION(TFIBWideStringField * GurZ_1CODE_SADR_REGION)
{
Object->GurZ_1CODE_SADR_REGION=GurZ_1CODE_SADR_REGION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1NAME_SADR_KV(void)
{
return Object->GurZ_1NAME_SADR_KV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1NAME_SADR_KV(TFIBWideStringField * GurZ_1NAME_SADR_KV)
{
Object->GurZ_1NAME_SADR_KV=GurZ_1NAME_SADR_KV;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaImpl::get_GurZ_1FL_PLOMBA_SET_REM_Z_1(void)
{
return Object->GurZ_1FL_PLOMBA_SET_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1FL_PLOMBA_SET_REM_Z_1(TFIBIntegerField * GurZ_1FL_PLOMBA_SET_REM_Z_1)
{
Object->GurZ_1FL_PLOMBA_SET_REM_Z_1=GurZ_1FL_PLOMBA_SET_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1TEXT_PLOMBA_REM_Z_1(void)
{
return Object->GurZ_1TEXT_PLOMBA_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1TEXT_PLOMBA_REM_Z_1(TFIBWideStringField * GurZ_1TEXT_PLOMBA_REM_Z_1)
{
Object->GurZ_1TEXT_PLOMBA_REM_Z_1=GurZ_1TEXT_PLOMBA_REM_Z_1;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaImpl::get_GurZ_1FL_PROBLEM_DEVICE_REM_Z_1(void)
{
return Object->GurZ_1FL_PROBLEM_DEVICE_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1FL_PROBLEM_DEVICE_REM_Z_1(TFIBIntegerField * GurZ_1FL_PROBLEM_DEVICE_REM_Z_1)
{
Object->GurZ_1FL_PROBLEM_DEVICE_REM_Z_1=GurZ_1FL_PROBLEM_DEVICE_REM_Z_1;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaImpl::get_GurZ_1FL_PROBLEM_KLIENT_REM_Z_1(void)
{
return Object->GurZ_1FL_PROBLEM_KLIENT_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1FL_PROBLEM_KLIENT_REM_Z_1(TFIBIntegerField * GurZ_1FL_PROBLEM_KLIENT_REM_Z_1)
{
Object->GurZ_1FL_PROBLEM_KLIENT_REM_Z_1=GurZ_1FL_PROBLEM_KLIENT_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1NEISPR_ENG_REM_Z_1(void)
{
return Object->GurZ_1NEISPR_ENG_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1NEISPR_ENG_REM_Z_1(TFIBWideStringField * GurZ_1NEISPR_ENG_REM_Z_1)
{
Object->GurZ_1NEISPR_ENG_REM_Z_1=GurZ_1NEISPR_ENG_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1DEFECT_ENG_REM_Z_1(void)
{
return Object->GurZ_1DEFECT_ENG_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1DEFECT_ENG_REM_Z_1(TFIBWideStringField * GurZ_1DEFECT_ENG_REM_Z_1)
{
Object->GurZ_1DEFECT_ENG_REM_Z_1=GurZ_1DEFECT_ENG_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1SOLUTION_ENG_REM_Z_1(void)
{
return Object->GurZ_1SOLUTION_ENG_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1SOLUTION_ENG_REM_Z_1(TFIBWideStringField * GurZ_1SOLUTION_ENG_REM_Z_1)
{
Object->GurZ_1SOLUTION_ENG_REM_Z_1=GurZ_1SOLUTION_ENG_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1STR_CODE_VIGR_REM_Z_1(void)
{
return Object->GurZ_1STR_CODE_VIGR_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1STR_CODE_VIGR_REM_Z_1(TFIBWideStringField * GurZ_1STR_CODE_VIGR_REM_Z_1)
{
Object->GurZ_1STR_CODE_VIGR_REM_Z_1=GurZ_1STR_CODE_VIGR_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1NAME_SADR_STROEN(void)
{
return Object->GurZ_1NAME_SADR_STROEN;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1NAME_SADR_STROEN(TFIBWideStringField * GurZ_1NAME_SADR_STROEN)
{
Object->GurZ_1NAME_SADR_STROEN=GurZ_1NAME_SADR_STROEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1NAME_SADR_RAYON(void)
{
return Object->GurZ_1NAME_SADR_RAYON;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1NAME_SADR_RAYON(TFIBWideStringField * GurZ_1NAME_SADR_RAYON)
{
Object->GurZ_1NAME_SADR_RAYON=GurZ_1NAME_SADR_RAYON;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaImpl::get_GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1(void)
{
return Object->GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1(TFIBIntegerField * GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1)
{
Object->GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1=GurZ_1FL_ONLY_DAGNOSTIC_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNeisprNAME_ENG_REM_SNEISPR(void)
{
return Object->GurZNeisprNAME_ENG_REM_SNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNeisprNAME_ENG_REM_SNEISPR(TFIBWideStringField * GurZNeisprNAME_ENG_REM_SNEISPR)
{
Object->GurZNeisprNAME_ENG_REM_SNEISPR=GurZNeisprNAME_ENG_REM_SNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNeisprNAME_REM_SGRPNEISPR(void)
{
return Object->GurZNeisprNAME_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNeisprNAME_REM_SGRPNEISPR(TFIBWideStringField * GurZNeisprNAME_REM_SGRPNEISPR)
{
Object->GurZNeisprNAME_REM_SGRPNEISPR=GurZNeisprNAME_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZNeisprNAME_ENG_REM_SGRPNEISPR(void)
{
return Object->GurZNeisprNAME_ENG_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZNeisprNAME_ENG_REM_SGRPNEISPR(TFIBWideStringField * GurZNeisprNAME_ENG_REM_SGRPNEISPR)
{
Object->GurZNeisprNAME_ENG_REM_SGRPNEISPR=GurZNeisprNAME_ENG_REM_SGRPNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1FAMILIYA_REM_Z_1(void)
{
return Object->GurZ_1FAMILIYA_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1FAMILIYA_REM_Z_1(TFIBWideStringField * GurZ_1FAMILIYA_REM_Z_1)
{
Object->GurZ_1FAMILIYA_REM_Z_1=GurZ_1FAMILIYA_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1IMYA_REM_Z_1(void)
{
return Object->GurZ_1IMYA_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1IMYA_REM_Z_1(TFIBWideStringField * GurZ_1IMYA_REM_Z_1)
{
Object->GurZ_1IMYA_REM_Z_1=GurZ_1IMYA_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1OTCHESTVO_REM_Z_1(void)
{
return Object->GurZ_1OTCHESTVO_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1OTCHESTVO_REM_Z_1(TFIBWideStringField * GurZ_1OTCHESTVO_REM_Z_1)
{
Object->GurZ_1OTCHESTVO_REM_Z_1=GurZ_1OTCHESTVO_REM_Z_1;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMZayavkaImpl::get_GurZ_1DATE_VIPUSK_REM_Z_1(void)
{
return Object->GurZ_1DATE_VIPUSK_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1DATE_VIPUSK_REM_Z_1(TFIBDateField * GurZ_1DATE_VIPUSK_REM_Z_1)
{
Object->GurZ_1DATE_VIPUSK_REM_Z_1=GurZ_1DATE_VIPUSK_REM_Z_1;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMZayavkaImpl::get_GurZ_1DATE_PRODAGI_REM_Z_1(void)
{
return Object->GurZ_1DATE_PRODAGI_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1DATE_PRODAGI_REM_Z_1(TFIBDateField * GurZ_1DATE_PRODAGI_REM_Z_1)
{
Object->GurZ_1DATE_PRODAGI_REM_Z_1=GurZ_1DATE_PRODAGI_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1PODO_REM_Z_1(void)
{
return Object->GurZ_1PODO_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1PODO_REM_Z_1(TFIBWideStringField * GurZ_1PODO_REM_Z_1)
{
Object->GurZ_1PODO_REM_Z_1=GurZ_1PODO_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1POPOSLE_REM_Z_1(void)
{
return Object->GurZ_1POPOSLE_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1POPOSLE_REM_Z_1(TFIBWideStringField * GurZ_1POPOSLE_REM_Z_1)
{
Object->GurZ_1POPOSLE_REM_Z_1=GurZ_1POPOSLE_REM_Z_1;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZ_1IDPRNEISPR_REM_Z_1(void)
{
return Object->GurZ_1IDPRNEISPR_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1IDPRNEISPR_REM_Z_1(TFIBLargeIntField * GurZ_1IDPRNEISPR_REM_Z_1)
{
Object->GurZ_1IDPRNEISPR_REM_Z_1=GurZ_1IDPRNEISPR_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1PARTNUM_REM_Z_1(void)
{
return Object->GurZ_1PARTNUM_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1PARTNUM_REM_Z_1(TFIBWideStringField * GurZ_1PARTNUM_REM_Z_1)
{
Object->GurZ_1PARTNUM_REM_Z_1=GurZ_1PARTNUM_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1REFERENCE_REM_Z_1(void)
{
return Object->GurZ_1REFERENCE_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1REFERENCE_REM_Z_1(TFIBWideStringField * GurZ_1REFERENCE_REM_Z_1)
{
Object->GurZ_1REFERENCE_REM_Z_1=GurZ_1REFERENCE_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1SWCODE_REM_Z_1(void)
{
return Object->GurZ_1SWCODE_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1SWCODE_REM_Z_1(TFIBWideStringField * GurZ_1SWCODE_REM_Z_1)
{
Object->GurZ_1SWCODE_REM_Z_1=GurZ_1SWCODE_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1HWCODE_REM_Z_1(void)
{
return Object->GurZ_1HWCODE_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1HWCODE_REM_Z_1(TFIBWideStringField * GurZ_1HWCODE_REM_Z_1)
{
Object->GurZ_1HWCODE_REM_Z_1=GurZ_1HWCODE_REM_Z_1;
}
//---------------------------------------------------------------
TFIBIntegerField * TREM_DMZayavkaImpl::get_GurZ_1KEMSDANO_REM_Z_1(void)
{
return Object->GurZ_1KEMSDANO_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1KEMSDANO_REM_Z_1(TFIBIntegerField * GurZ_1KEMSDANO_REM_Z_1)
{
Object->GurZ_1KEMSDANO_REM_Z_1=GurZ_1KEMSDANO_REM_Z_1;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMZayavkaImpl::get_GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1(void)
{
return Object->GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1(TFIBDateTimeField * GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1)
{
Object->GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1=GurZ_1POS_ZAPROSA_NA_AKT_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1SERNUM3_REM_Z_1(void)
{
return Object->GurZ_1SERNUM3_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1SERNUM3_REM_Z_1(TFIBWideStringField * GurZ_1SERNUM3_REM_Z_1)
{
Object->GurZ_1SERNUM3_REM_Z_1=GurZ_1SERNUM3_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1SERNUM4_REM_Z_1(void)
{
return Object->GurZ_1SERNUM4_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1SERNUM4_REM_Z_1(TFIBWideStringField * GurZ_1SERNUM4_REM_Z_1)
{
Object->GurZ_1SERNUM4_REM_Z_1=GurZ_1SERNUM4_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1NUMBAT_REM_Z_1(void)
{
return Object->GurZ_1NUMBAT_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1NUMBAT_REM_Z_1(TFIBWideStringField * GurZ_1NUMBAT_REM_Z_1)
{
Object->GurZ_1NUMBAT_REM_Z_1=GurZ_1NUMBAT_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1NAME_REM_SPRNEISPR(void)
{
return Object->GurZ_1NAME_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1NAME_REM_SPRNEISPR(TFIBWideStringField * GurZ_1NAME_REM_SPRNEISPR)
{
Object->GurZ_1NAME_REM_SPRNEISPR=GurZ_1NAME_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1NAME_ENG_REM_SPRNEISPR(void)
{
return Object->GurZ_1NAME_ENG_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1NAME_ENG_REM_SPRNEISPR(TFIBWideStringField * GurZ_1NAME_ENG_REM_SPRNEISPR)
{
Object->GurZ_1NAME_ENG_REM_SPRNEISPR=GurZ_1NAME_ENG_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1CODE_REM_SPRNEISPR(void)
{
return Object->GurZ_1CODE_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1CODE_REM_SPRNEISPR(TFIBWideStringField * GurZ_1CODE_REM_SPRNEISPR)
{
Object->GurZ_1CODE_REM_SPRNEISPR=GurZ_1CODE_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1NAME_REM_SPRNEISPR_GRP(void)
{
return Object->GurZ_1NAME_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1NAME_REM_SPRNEISPR_GRP(TFIBWideStringField * GurZ_1NAME_REM_SPRNEISPR_GRP)
{
Object->GurZ_1NAME_REM_SPRNEISPR_GRP=GurZ_1NAME_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1NAME_ENG_REM_SPRNEISPR_GRP(void)
{
return Object->GurZ_1NAME_ENG_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1NAME_ENG_REM_SPRNEISPR_GRP(TFIBWideStringField * GurZ_1NAME_ENG_REM_SPRNEISPR_GRP)
{
Object->GurZ_1NAME_ENG_REM_SPRNEISPR_GRP=GurZ_1NAME_ENG_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_GurZ_1FL_ISM_SERNUM3_REM_Z_1(void)
{
return Object->GurZ_1FL_ISM_SERNUM3_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1FL_ISM_SERNUM3_REM_Z_1(TFIBSmallIntField * GurZ_1FL_ISM_SERNUM3_REM_Z_1)
{
Object->GurZ_1FL_ISM_SERNUM3_REM_Z_1=GurZ_1FL_ISM_SERNUM3_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1SERNUM3_NEW_REM_Z_1(void)
{
return Object->GurZ_1SERNUM3_NEW_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1SERNUM3_NEW_REM_Z_1(TFIBWideStringField * GurZ_1SERNUM3_NEW_REM_Z_1)
{
Object->GurZ_1SERNUM3_NEW_REM_Z_1=GurZ_1SERNUM3_NEW_REM_Z_1;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_GurZ_1FL_ISM_SERNUM4_REM_Z_1(void)
{
return Object->GurZ_1FL_ISM_SERNUM4_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1FL_ISM_SERNUM4_REM_Z_1(TFIBSmallIntField * GurZ_1FL_ISM_SERNUM4_REM_Z_1)
{
Object->GurZ_1FL_ISM_SERNUM4_REM_Z_1=GurZ_1FL_ISM_SERNUM4_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1SERNUM4_NEW_REM_Z_1(void)
{
return Object->GurZ_1SERNUM4_NEW_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1SERNUM4_NEW_REM_Z_1(TFIBWideStringField * GurZ_1SERNUM4_NEW_REM_Z_1)
{
Object->GurZ_1SERNUM4_NEW_REM_Z_1=GurZ_1SERNUM4_NEW_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1FL_ISM_REFERENCE_REM_Z_1(void)
{
return Object->GurZ_1FL_ISM_REFERENCE_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1FL_ISM_REFERENCE_REM_Z_1(TFIBWideStringField * GurZ_1FL_ISM_REFERENCE_REM_Z_1)
{
Object->GurZ_1FL_ISM_REFERENCE_REM_Z_1=GurZ_1FL_ISM_REFERENCE_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1REFERENCE_NEW_REM_Z_1(void)
{
return Object->GurZ_1REFERENCE_NEW_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1REFERENCE_NEW_REM_Z_1(TFIBWideStringField * GurZ_1REFERENCE_NEW_REM_Z_1)
{
Object->GurZ_1REFERENCE_NEW_REM_Z_1=GurZ_1REFERENCE_NEW_REM_Z_1;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_GurZ_1FL_ISM_HWCODE_REM_Z_1(void)
{
return Object->GurZ_1FL_ISM_HWCODE_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1FL_ISM_HWCODE_REM_Z_1(TFIBSmallIntField * GurZ_1FL_ISM_HWCODE_REM_Z_1)
{
Object->GurZ_1FL_ISM_HWCODE_REM_Z_1=GurZ_1FL_ISM_HWCODE_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1HWCODE_NEW_REM_Z_1(void)
{
return Object->GurZ_1HWCODE_NEW_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1HWCODE_NEW_REM_Z_1(TFIBWideStringField * GurZ_1HWCODE_NEW_REM_Z_1)
{
Object->GurZ_1HWCODE_NEW_REM_Z_1=GurZ_1HWCODE_NEW_REM_Z_1;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_GurZ_1FL_ISM_SWCODE_REM_Z_1(void)
{
return Object->GurZ_1FL_ISM_SWCODE_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1FL_ISM_SWCODE_REM_Z_1(TFIBSmallIntField * GurZ_1FL_ISM_SWCODE_REM_Z_1)
{
Object->GurZ_1FL_ISM_SWCODE_REM_Z_1=GurZ_1FL_ISM_SWCODE_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1SWCODE_NEW_REM_Z_1(void)
{
return Object->GurZ_1SWCODE_NEW_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1SWCODE_NEW_REM_Z_1(TFIBWideStringField * GurZ_1SWCODE_NEW_REM_Z_1)
{
Object->GurZ_1SWCODE_NEW_REM_Z_1=GurZ_1SWCODE_NEW_REM_Z_1;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImpl::get_GurZ_1FL_ISM_PARTNUM_REM_Z_1(void)
{
return Object->GurZ_1FL_ISM_PARTNUM_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1FL_ISM_PARTNUM_REM_Z_1(TFIBSmallIntField * GurZ_1FL_ISM_PARTNUM_REM_Z_1)
{
Object->GurZ_1FL_ISM_PARTNUM_REM_Z_1=GurZ_1FL_ISM_PARTNUM_REM_Z_1;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZ_1PARTNUM_NEW_REM_Z_1(void)
{
return Object->GurZ_1PARTNUM_NEW_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1PARTNUM_NEW_REM_Z_1(TFIBWideStringField * GurZ_1PARTNUM_NEW_REM_Z_1)
{
Object->GurZ_1PARTNUM_NEW_REM_Z_1=GurZ_1PARTNUM_NEW_REM_Z_1;
}
//---------------------------------------------------------------
TDataSource * TREM_DMZayavkaImpl::get_DataSourcePrNeispr(void)
{
return Object->DataSourcePrNeispr;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_DataSourcePrNeispr(TDataSource * DataSourcePrNeispr)
{
Object->DataSourcePrNeispr=DataSourcePrNeispr;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMZayavkaImpl::get_GurZPrNeispr(void)
{
return Object->GurZPrNeispr;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeispr(TpFIBDataSet * GurZPrNeispr)
{
Object->GurZPrNeispr=GurZPrNeispr;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZPrNeisprID_REM_ZPRNEISPR(void)
{
return Object->GurZPrNeisprID_REM_ZPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprID_REM_ZPRNEISPR(TFIBLargeIntField * GurZPrNeisprID_REM_ZPRNEISPR)
{
Object->GurZPrNeisprID_REM_ZPRNEISPR=GurZPrNeisprID_REM_ZPRNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZPrNeisprIDBASE_REM_ZPRNEISPR(void)
{
return Object->GurZPrNeisprIDBASE_REM_ZPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprIDBASE_REM_ZPRNEISPR(TFIBLargeIntField * GurZPrNeisprIDBASE_REM_ZPRNEISPR)
{
Object->GurZPrNeisprIDBASE_REM_ZPRNEISPR=GurZPrNeisprIDBASE_REM_ZPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZPrNeisprGID_REM_ZPRNEISPR(void)
{
return Object->GurZPrNeisprGID_REM_ZPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprGID_REM_ZPRNEISPR(TFIBWideStringField * GurZPrNeisprGID_REM_ZPRNEISPR)
{
Object->GurZPrNeisprGID_REM_ZPRNEISPR=GurZPrNeisprGID_REM_ZPRNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZPrNeisprIDPRCOND_REM_ZPRNEISPR(void)
{
return Object->GurZPrNeisprIDPRCOND_REM_ZPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprIDPRCOND_REM_ZPRNEISPR(TFIBLargeIntField * GurZPrNeisprIDPRCOND_REM_ZPRNEISPR)
{
Object->GurZPrNeisprIDPRCOND_REM_ZPRNEISPR=GurZPrNeisprIDPRCOND_REM_ZPRNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR(void)
{
return Object->GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR(TFIBLargeIntField * GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR)
{
Object->GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR=GurZPrNeisprIDPRNEISP_REM_ZPRNEISPR;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImpl::get_GurZPrNeisprIDZ_REM_ZPRNEISPR(void)
{
return Object->GurZPrNeisprIDZ_REM_ZPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprIDZ_REM_ZPRNEISPR(TFIBLargeIntField * GurZPrNeisprIDZ_REM_ZPRNEISPR)
{
Object->GurZPrNeisprIDZ_REM_ZPRNEISPR=GurZPrNeisprIDZ_REM_ZPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZPrNeisprNAME_REM_SPRNEISPR(void)
{
return Object->GurZPrNeisprNAME_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprNAME_REM_SPRNEISPR(TFIBWideStringField * GurZPrNeisprNAME_REM_SPRNEISPR)
{
Object->GurZPrNeisprNAME_REM_SPRNEISPR=GurZPrNeisprNAME_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZPrNeisprCODE_REM_SPRNEISPR(void)
{
return Object->GurZPrNeisprCODE_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprCODE_REM_SPRNEISPR(TFIBWideStringField * GurZPrNeisprCODE_REM_SPRNEISPR)
{
Object->GurZPrNeisprCODE_REM_SPRNEISPR=GurZPrNeisprCODE_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZPrNeisprNAME_ENG_REM_SPRNEISPR(void)
{
return Object->GurZPrNeisprNAME_ENG_REM_SPRNEISPR;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprNAME_ENG_REM_SPRNEISPR(TFIBWideStringField * GurZPrNeisprNAME_ENG_REM_SPRNEISPR)
{
Object->GurZPrNeisprNAME_ENG_REM_SPRNEISPR=GurZPrNeisprNAME_ENG_REM_SPRNEISPR;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZPrNeisprNAME_REM_SPRNEISPR_GRP(void)
{
return Object->GurZPrNeisprNAME_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprNAME_REM_SPRNEISPR_GRP(TFIBWideStringField * GurZPrNeisprNAME_REM_SPRNEISPR_GRP)
{
Object->GurZPrNeisprNAME_REM_SPRNEISPR_GRP=GurZPrNeisprNAME_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP(void)
{
return Object->GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP(TFIBWideStringField * GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP)
{
Object->GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP=GurZPrNeisprNAME_ENG_REM_SPRNEISPR_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZPrNeisprCODE_REM_SPRCONDITION(void)
{
return Object->GurZPrNeisprCODE_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprCODE_REM_SPRCONDITION(TFIBWideStringField * GurZPrNeisprCODE_REM_SPRCONDITION)
{
Object->GurZPrNeisprCODE_REM_SPRCONDITION=GurZPrNeisprCODE_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZPrNeisprNAME_REM_SPRCONDITION(void)
{
return Object->GurZPrNeisprNAME_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprNAME_REM_SPRCONDITION(TFIBWideStringField * GurZPrNeisprNAME_REM_SPRCONDITION)
{
Object->GurZPrNeisprNAME_REM_SPRCONDITION=GurZPrNeisprNAME_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZPrNeisprNAME_ENG_REM_SPRCONDITION(void)
{
return Object->GurZPrNeisprNAME_ENG_REM_SPRCONDITION;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprNAME_ENG_REM_SPRCONDITION(TFIBWideStringField * GurZPrNeisprNAME_ENG_REM_SPRCONDITION)
{
Object->GurZPrNeisprNAME_ENG_REM_SPRCONDITION=GurZPrNeisprNAME_ENG_REM_SPRCONDITION;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZPrNeisprCODE_REM_SPRCOND_GRP(void)
{
return Object->GurZPrNeisprCODE_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprCODE_REM_SPRCOND_GRP(TFIBWideStringField * GurZPrNeisprCODE_REM_SPRCOND_GRP)
{
Object->GurZPrNeisprCODE_REM_SPRCOND_GRP=GurZPrNeisprCODE_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZPrNeisprNAME_REM_SPRCOND_GRP(void)
{
return Object->GurZPrNeisprNAME_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprNAME_REM_SPRCOND_GRP(TFIBWideStringField * GurZPrNeisprNAME_REM_SPRCOND_GRP)
{
Object->GurZPrNeisprNAME_REM_SPRCOND_GRP=GurZPrNeisprNAME_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImpl::get_GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP(void)
{
return Object->GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP(TFIBWideStringField * GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP)
{
Object->GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP=GurZPrNeisprNAME_ENG_REM_SPRCOND_GRP;
}
//---------------------------------------------------------------
TIntegerField * TREM_DMZayavkaImpl::get_GurZPrNeisprRECNO(void)
{
return Object->GurZPrNeisprRECNO;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZPrNeisprRECNO(TIntegerField * GurZPrNeisprRECNO)
{
Object->GurZPrNeisprRECNO=GurZPrNeisprRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMZayavkaImpl::get_GurZ_1PREDOPLATA_REM_Z_1(void)
{
return Object->GurZ_1PREDOPLATA_REM_Z_1;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_GurZ_1PREDOPLATA_REM_Z_1(TFIBBCDField * GurZ_1PREDOPLATA_REM_Z_1)
{
Object->GurZ_1PREDOPLATA_REM_Z_1=GurZ_1PREDOPLATA_REM_Z_1;
}
//---------------------------------------------------------------
bool TREM_DMZayavkaImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TREM_DMZayavkaImpl::get_IdZ(void)
{
return Object->IdZ;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_IdZ(__int64 IdZ)
{
Object->IdZ=IdZ;
}
//---------------------------------------------------------------
bool TREM_DMZayavkaImpl::get_flChangeData(void)
{
return Object->flChangeData;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::set_flChangeData(bool flChangeData)
{
Object->flChangeData=flChangeData;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::NewDoc(void)
{
return Object->NewDoc();
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::OpenDoc(__int64 id)
{
return Object->OpenDoc(id);
}
//---------------------------------------------------------------
bool TREM_DMZayavkaImpl::SaveDoc(void)
{
return Object->SaveDoc();
}
//---------------------------------------------------------------
bool TREM_DMZayavkaImpl::DeleteDoc(__int64 id)
{
return Object->DeleteDoc(id);
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::CloseDoc(void)
{
return Object->CloseDoc();
}
//---------------------------------------------------------------
void TREM_DMZayavkaImpl::AddNewRecordDv(void)
{
return Object->AddNewRecordDv();
}
//---------------------------------------------------------------
