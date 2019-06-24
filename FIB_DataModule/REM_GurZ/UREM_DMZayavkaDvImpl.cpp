#include "vcl.h"
#pragma hdrstop


#include "UREM_DMZayavkaDvImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMZayavkaDvImpl::TREM_DMZayavkaDvImpl()           
{                                            
Object=new TREM_DMZayavkaDv(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMZayavkaDvImpl::~TREM_DMZayavkaDvImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMZayavkaDvImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMZayavkaDv)                        
   {                                                                     
   *ppv=static_cast<IREM_DMZayavkaDv*> (this);                                
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
int TREM_DMZayavkaDvImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMZayavkaDvImpl::kanRelease(void)                                  
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
int  TREM_DMZayavkaDvImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMZayavkaDvImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMZayavkaDvImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMZayavkaDvImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMZayavkaDvImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMZayavkaDv
TDataSource * TREM_DMZayavkaDvImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMZayavkaDvImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMZayavkaDvImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMZayavkaDvImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMZayavkaDvImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMZayavkaDvImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TREM_DMZayavkaDvImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaDvImpl::get_TableID_REM_Z_DV(void)
{
return Object->TableID_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TableID_REM_Z_DV(TFIBLargeIntField * TableID_REM_Z_DV)
{
Object->TableID_REM_Z_DV=TableID_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaDvImpl::get_TableGID_REM_Z_DV(void)
{
return Object->TableGID_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TableGID_REM_Z_DV(TFIBWideStringField * TableGID_REM_Z_DV)
{
Object->TableGID_REM_Z_DV=TableGID_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMZayavkaDvImpl::get_TablePOS_REM_Z_DV(void)
{
return Object->TablePOS_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TablePOS_REM_Z_DV(TFIBDateTimeField * TablePOS_REM_Z_DV)
{
Object->TablePOS_REM_Z_DV=TablePOS_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaDvImpl::get_TableIDZ_REM_Z_DV(void)
{
return Object->TableIDZ_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TableIDZ_REM_Z_DV(TFIBLargeIntField * TableIDZ_REM_Z_DV)
{
Object->TableIDZ_REM_Z_DV=TableIDZ_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaDvImpl::get_TableOPER_REM_Z_DV(void)
{
return Object->TableOPER_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TableOPER_REM_Z_DV(TFIBSmallIntField * TableOPER_REM_Z_DV)
{
Object->TableOPER_REM_Z_DV=TableOPER_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaDvImpl::get_TableIDSOST_REM_Z_DV(void)
{
return Object->TableIDSOST_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TableIDSOST_REM_Z_DV(TFIBLargeIntField * TableIDSOST_REM_Z_DV)
{
Object->TableIDSOST_REM_Z_DV=TableIDSOST_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaDvImpl::get_TableIDTREMONT_REM_Z_DV(void)
{
return Object->TableIDTREMONT_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TableIDTREMONT_REM_Z_DV(TFIBLargeIntField * TableIDTREMONT_REM_Z_DV)
{
Object->TableIDTREMONT_REM_Z_DV=TableIDTREMONT_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaDvImpl::get_TableIDUSER_REM_Z_DV(void)
{
return Object->TableIDUSER_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TableIDUSER_REM_Z_DV(TFIBLargeIntField * TableIDUSER_REM_Z_DV)
{
Object->TableIDUSER_REM_Z_DV=TableIDUSER_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMZayavkaDvImpl::get_TableSUM_REM_Z_DV(void)
{
return Object->TableSUM_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TableSUM_REM_Z_DV(TFIBBCDField * TableSUM_REM_Z_DV)
{
Object->TableSUM_REM_Z_DV=TableSUM_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMZayavkaDvImpl::get_TableSROK_REM_Z_DV(void)
{
return Object->TableSROK_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TableSROK_REM_Z_DV(TFIBDateField * TableSROK_REM_Z_DV)
{
Object->TableSROK_REM_Z_DV=TableSROK_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaDvImpl::get_TableOUT_REM_Z_DV(void)
{
return Object->TableOUT_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TableOUT_REM_Z_DV(TFIBSmallIntField * TableOUT_REM_Z_DV)
{
Object->TableOUT_REM_Z_DV=TableOUT_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaDvImpl::get_TableIDTECSKL_REM_Z_DV(void)
{
return Object->TableIDTECSKL_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TableIDTECSKL_REM_Z_DV(TFIBLargeIntField * TableIDTECSKL_REM_Z_DV)
{
Object->TableIDTECSKL_REM_Z_DV=TableIDTECSKL_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaDvImpl::get_TableIDBASE_REM_Z_DV(void)
{
return Object->TableIDBASE_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TableIDBASE_REM_Z_DV(TFIBLargeIntField * TableIDBASE_REM_Z_DV)
{
Object->TableIDBASE_REM_Z_DV=TableIDBASE_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaDvImpl::get_TableNAME_STREMONT(void)
{
return Object->TableNAME_STREMONT;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TableNAME_STREMONT(TFIBWideStringField * TableNAME_STREMONT)
{
Object->TableNAME_STREMONT=TableNAME_STREMONT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaDvImpl::get_TableNAME_REMSSOST(void)
{
return Object->TableNAME_REMSSOST;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TableNAME_REMSSOST(TFIBWideStringField * TableNAME_REMSSOST)
{
Object->TableNAME_REMSSOST=TableNAME_REMSSOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaDvImpl::get_TableNAME_SKLAD_TEC(void)
{
return Object->TableNAME_SKLAD_TEC;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TableNAME_SKLAD_TEC(TFIBWideStringField * TableNAME_SKLAD_TEC)
{
Object->TableNAME_SKLAD_TEC=TableNAME_SKLAD_TEC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaDvImpl::get_TableNAME_USER(void)
{
return Object->TableNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_TableNAME_USER(TFIBWideStringField * TableNAME_USER)
{
Object->TableNAME_USER=TableNAME_USER;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaDvImpl::get_ElementID_REM_Z_DV(void)
{
return Object->ElementID_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementID_REM_Z_DV(TFIBLargeIntField * ElementID_REM_Z_DV)
{
Object->ElementID_REM_Z_DV=ElementID_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaDvImpl::get_ElementGID_REM_Z_DV(void)
{
return Object->ElementGID_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementGID_REM_Z_DV(TFIBWideStringField * ElementGID_REM_Z_DV)
{
Object->ElementGID_REM_Z_DV=ElementGID_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBDateTimeField * TREM_DMZayavkaDvImpl::get_ElementPOS_REM_Z_DV(void)
{
return Object->ElementPOS_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementPOS_REM_Z_DV(TFIBDateTimeField * ElementPOS_REM_Z_DV)
{
Object->ElementPOS_REM_Z_DV=ElementPOS_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaDvImpl::get_ElementIDZ_REM_Z_DV(void)
{
return Object->ElementIDZ_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementIDZ_REM_Z_DV(TFIBLargeIntField * ElementIDZ_REM_Z_DV)
{
Object->ElementIDZ_REM_Z_DV=ElementIDZ_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaDvImpl::get_ElementOPER_REM_Z_DV(void)
{
return Object->ElementOPER_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementOPER_REM_Z_DV(TFIBSmallIntField * ElementOPER_REM_Z_DV)
{
Object->ElementOPER_REM_Z_DV=ElementOPER_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaDvImpl::get_ElementIDSOST_REM_Z_DV(void)
{
return Object->ElementIDSOST_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementIDSOST_REM_Z_DV(TFIBLargeIntField * ElementIDSOST_REM_Z_DV)
{
Object->ElementIDSOST_REM_Z_DV=ElementIDSOST_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaDvImpl::get_ElementIDTREMONT_REM_Z_DV(void)
{
return Object->ElementIDTREMONT_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementIDTREMONT_REM_Z_DV(TFIBLargeIntField * ElementIDTREMONT_REM_Z_DV)
{
Object->ElementIDTREMONT_REM_Z_DV=ElementIDTREMONT_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaDvImpl::get_ElementIDUSER_REM_Z_DV(void)
{
return Object->ElementIDUSER_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementIDUSER_REM_Z_DV(TFIBLargeIntField * ElementIDUSER_REM_Z_DV)
{
Object->ElementIDUSER_REM_Z_DV=ElementIDUSER_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBBCDField * TREM_DMZayavkaDvImpl::get_ElementSUM_REM_Z_DV(void)
{
return Object->ElementSUM_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementSUM_REM_Z_DV(TFIBBCDField * ElementSUM_REM_Z_DV)
{
Object->ElementSUM_REM_Z_DV=ElementSUM_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBDateField * TREM_DMZayavkaDvImpl::get_ElementSROK_REM_Z_DV(void)
{
return Object->ElementSROK_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementSROK_REM_Z_DV(TFIBDateField * ElementSROK_REM_Z_DV)
{
Object->ElementSROK_REM_Z_DV=ElementSROK_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaDvImpl::get_ElementOUT_REM_Z_DV(void)
{
return Object->ElementOUT_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementOUT_REM_Z_DV(TFIBSmallIntField * ElementOUT_REM_Z_DV)
{
Object->ElementOUT_REM_Z_DV=ElementOUT_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaDvImpl::get_ElementIDTECSKL_REM_Z_DV(void)
{
return Object->ElementIDTECSKL_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementIDTECSKL_REM_Z_DV(TFIBLargeIntField * ElementIDTECSKL_REM_Z_DV)
{
Object->ElementIDTECSKL_REM_Z_DV=ElementIDTECSKL_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaDvImpl::get_ElementIDBASE_REM_Z_DV(void)
{
return Object->ElementIDBASE_REM_Z_DV;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementIDBASE_REM_Z_DV(TFIBLargeIntField * ElementIDBASE_REM_Z_DV)
{
Object->ElementIDBASE_REM_Z_DV=ElementIDBASE_REM_Z_DV;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaDvImpl::get_ElementNAME_STREMONT(void)
{
return Object->ElementNAME_STREMONT;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementNAME_STREMONT(TFIBWideStringField * ElementNAME_STREMONT)
{
Object->ElementNAME_STREMONT=ElementNAME_STREMONT;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaDvImpl::get_ElementNAME_REMSSOST(void)
{
return Object->ElementNAME_REMSSOST;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementNAME_REMSSOST(TFIBWideStringField * ElementNAME_REMSSOST)
{
Object->ElementNAME_REMSSOST=ElementNAME_REMSSOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaDvImpl::get_ElementNAME_SKLAD_TEC(void)
{
return Object->ElementNAME_SKLAD_TEC;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementNAME_SKLAD_TEC(TFIBWideStringField * ElementNAME_SKLAD_TEC)
{
Object->ElementNAME_SKLAD_TEC=ElementNAME_SKLAD_TEC;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaDvImpl::get_ElementNAME_USER(void)
{
return Object->ElementNAME_USER;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_ElementNAME_USER(TFIBWideStringField * ElementNAME_USER)
{
Object->ElementNAME_USER=ElementNAME_USER;
}
//---------------------------------------------------------------
bool TREM_DMZayavkaDvImpl::get_Prosmotr(void)
{
return Object->Prosmotr;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_Prosmotr(bool Prosmotr)
{
Object->Prosmotr=Prosmotr;
}
//---------------------------------------------------------------
__int64 TREM_DMZayavkaDvImpl::get_IdZ(void)
{
return Object->IdZ;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_IdZ(__int64 IdZ)
{
Object->IdZ=IdZ;
}
//---------------------------------------------------------------
__int64 TREM_DMZayavkaDvImpl::get_IdBaseZayavki(void)
{
return Object->IdBaseZayavki;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::set_IdBaseZayavki(__int64 IdBaseZayavki)
{
Object->IdBaseZayavki=IdBaseZayavki;
}
//---------------------------------------------------------------
void TREM_DMZayavkaDvImpl::OpenTable(__int64 id_z)
{
return Object->OpenTable(id_z);
}
//---------------------------------------------------------------
int TREM_DMZayavkaDvImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TREM_DMZayavkaDvImpl::NewElement(__int64 id_z)
{
return Object->NewElement(id_z);
}
//---------------------------------------------------------------
bool TREM_DMZayavkaDvImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMZayavkaDvImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TREM_DMZayavkaDvImpl::GetIDElement(UnicodeString gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
UnicodeString TREM_DMZayavkaDvImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
bool TREM_DMZayavkaDvImpl::AddRecordDv(TDateTime pos,	__int64 id_z,int oper,	__int64 id_sost,__int64 id_type_remont,	__int64 id_user,__int64 id_tec_sklad,double sum,TDate date,int out)
{
return Object->AddRecordDv(pos,id_z,oper,id_sost,id_type_remont,id_user,id_tec_sklad,sum,date,out);
}
//---------------------------------------------------------------
