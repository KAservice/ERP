#include <vcl.h>
#pragma hdrstop


#include "UDMSprNakSkidokImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprNakSkidokImpl::TDMSprNakSkidokImpl()           
{                                            
Object=new TDMSprNakSkidok(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprNakSkidokImpl::~TDMSprNakSkidokImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprNakSkidokImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprNakSkidok)                        
   {                                                                     
   *ppv=static_cast<IDMSprNakSkidok*> (this);                                
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
int TDMSprNakSkidokImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprNakSkidokImpl::kanRelease(void)                                  
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

//---------------------------------------------------------------
int  TDMSprNakSkidokImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprNakSkidokImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprNakSkidokImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprNakSkidokImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprNakSkidokImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprNakSkidokImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNakSkidokImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNakSkidokImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNakSkidokImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNakSkidokImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprNakSkidokImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNakSkidokImpl::get_TableSUM_SNAK_SKIDOK(void)
{
return Object->TableSUM_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TableSUM_SNAK_SKIDOK(TFIBBCDField * TableSUM_SNAK_SKIDOK)
{
Object->TableSUM_SNAK_SKIDOK=TableSUM_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNakSkidokImpl::get_TablePROCENT_SNAK_SKIDOK(void)
{
return Object->TablePROCENT_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TablePROCENT_SNAK_SKIDOK(TFIBBCDField * TablePROCENT_SNAK_SKIDOK)
{
Object->TablePROCENT_SNAK_SKIDOK=TablePROCENT_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNakSkidokImpl::get_TablePERIOD_SNAK_SKIDOK(void)
{
return Object->TablePERIOD_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TablePERIOD_SNAK_SKIDOK(TFIBSmallIntField * TablePERIOD_SNAK_SKIDOK)
{
Object->TablePERIOD_SNAK_SKIDOK=TablePERIOD_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNakSkidokImpl::get_ElementSUM_SNAK_SKIDOK(void)
{
return Object->ElementSUM_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_ElementSUM_SNAK_SKIDOK(TFIBBCDField * ElementSUM_SNAK_SKIDOK)
{
Object->ElementSUM_SNAK_SKIDOK=ElementSUM_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNakSkidokImpl::get_ElementPROCENT_SNAK_SKIDOK(void)
{
return Object->ElementPROCENT_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_ElementPROCENT_SNAK_SKIDOK(TFIBBCDField * ElementPROCENT_SNAK_SKIDOK)
{
Object->ElementPROCENT_SNAK_SKIDOK=ElementPROCENT_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNakSkidokImpl::get_ElementPERIOD_SNAK_SKIDOK(void)
{
return Object->ElementPERIOD_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_ElementPERIOD_SNAK_SKIDOK(TFIBSmallIntField * ElementPERIOD_SNAK_SKIDOK)
{
Object->ElementPERIOD_SNAK_SKIDOK=ElementPERIOD_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprNakSkidokImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNakSkidokImpl::get_TableID_SNAK_SKIDOK(void)
{
return Object->TableID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TableID_SNAK_SKIDOK(TFIBBCDField * TableID_SNAK_SKIDOK)
{
Object->TableID_SNAK_SKIDOK=TableID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNakSkidokImpl::get_TableIDSKLAD_SNAK_SKIDOK(void)
{
return Object->TableIDSKLAD_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TableIDSKLAD_SNAK_SKIDOK(TFIBBCDField * TableIDSKLAD_SNAK_SKIDOK)
{
Object->TableIDSKLAD_SNAK_SKIDOK=TableIDSKLAD_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNakSkidokImpl::get_TableIDVID_SNAK_SKIDOK(void)
{
return Object->TableIDVID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TableIDVID_SNAK_SKIDOK(TFIBBCDField * TableIDVID_SNAK_SKIDOK)
{
Object->TableIDVID_SNAK_SKIDOK=TableIDVID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNakSkidokImpl::get_ElementID_SNAK_SKIDOK(void)
{
return Object->ElementID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_ElementID_SNAK_SKIDOK(TFIBBCDField * ElementID_SNAK_SKIDOK)
{
Object->ElementID_SNAK_SKIDOK=ElementID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNakSkidokImpl::get_ElementIDSKLAD_SNAK_SKIDOK(void)
{
return Object->ElementIDSKLAD_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_ElementIDSKLAD_SNAK_SKIDOK(TFIBBCDField * ElementIDSKLAD_SNAK_SKIDOK)
{
Object->ElementIDSKLAD_SNAK_SKIDOK=ElementIDSKLAD_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNakSkidokImpl::get_ElementIDVID_SNAK_SKIDOK(void)
{
return Object->ElementIDVID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_ElementIDVID_SNAK_SKIDOK(TFIBBCDField * ElementIDVID_SNAK_SKIDOK)
{
Object->ElementIDVID_SNAK_SKIDOK=ElementIDVID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNakSkidokImpl::get_TableNakSkidok(void)
{
return Object->TableNakSkidok;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TableNakSkidok(TpFIBDataSet * TableNakSkidok)
{
Object->TableNakSkidok=TableNakSkidok;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNakSkidokImpl::get_TableNakSkidokID_SNAK_SKIDOK(void)
{
return Object->TableNakSkidokID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TableNakSkidokID_SNAK_SKIDOK(TFIBBCDField * TableNakSkidokID_SNAK_SKIDOK)
{
Object->TableNakSkidokID_SNAK_SKIDOK=TableNakSkidokID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNakSkidokImpl::get_TableNakSkidokIDSKLAD_SNAK_SKIDOK(void)
{
return Object->TableNakSkidokIDSKLAD_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TableNakSkidokIDSKLAD_SNAK_SKIDOK(TFIBBCDField * TableNakSkidokIDSKLAD_SNAK_SKIDOK)
{
Object->TableNakSkidokIDSKLAD_SNAK_SKIDOK=TableNakSkidokIDSKLAD_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNakSkidokImpl::get_TableNakSkidokIDVID_SNAK_SKIDOK(void)
{
return Object->TableNakSkidokIDVID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TableNakSkidokIDVID_SNAK_SKIDOK(TFIBBCDField * TableNakSkidokIDVID_SNAK_SKIDOK)
{
Object->TableNakSkidokIDVID_SNAK_SKIDOK=TableNakSkidokIDVID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNakSkidokImpl::get_TableNakSkidokSUM_SNAK_SKIDOK(void)
{
return Object->TableNakSkidokSUM_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TableNakSkidokSUM_SNAK_SKIDOK(TFIBBCDField * TableNakSkidokSUM_SNAK_SKIDOK)
{
Object->TableNakSkidokSUM_SNAK_SKIDOK=TableNakSkidokSUM_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprNakSkidokImpl::get_TableNakSkidokPROCENT_SNAK_SKIDOK(void)
{
return Object->TableNakSkidokPROCENT_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TableNakSkidokPROCENT_SNAK_SKIDOK(TFIBBCDField * TableNakSkidokPROCENT_SNAK_SKIDOK)
{
Object->TableNakSkidokPROCENT_SNAK_SKIDOK=TableNakSkidokPROCENT_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNakSkidokImpl::get_TableNakSkidokPERIOD_SNAK_SKIDOK(void)
{
return Object->TableNakSkidokPERIOD_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TableNakSkidokPERIOD_SNAK_SKIDOK(TFIBSmallIntField * TableNakSkidokPERIOD_SNAK_SKIDOK)
{
Object->TableNakSkidokPERIOD_SNAK_SKIDOK=TableNakSkidokPERIOD_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNakSkidokImpl::get_TableGID_SNAK_SKIDOK(void)
{
return Object->TableGID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TableGID_SNAK_SKIDOK(TFIBWideStringField * TableGID_SNAK_SKIDOK)
{
Object->TableGID_SNAK_SKIDOK=TableGID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNakSkidokImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNakSkidokImpl::get_TableNAME_SVID_DCARD(void)
{
return Object->TableNAME_SVID_DCARD;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TableNAME_SVID_DCARD(TFIBWideStringField * TableNAME_SVID_DCARD)
{
Object->TableNAME_SVID_DCARD=TableNAME_SVID_DCARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNakSkidokImpl::get_ElementGID_SNAK_SKIDOK(void)
{
return Object->ElementGID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_ElementGID_SNAK_SKIDOK(TFIBWideStringField * ElementGID_SNAK_SKIDOK)
{
Object->ElementGID_SNAK_SKIDOK=ElementGID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNakSkidokImpl::get_ElementNAMESKLAD(void)
{
return Object->ElementNAMESKLAD;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)
{
Object->ElementNAMESKLAD=ElementNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNakSkidokImpl::get_ElementNAME_SVID_DCARD(void)
{
return Object->ElementNAME_SVID_DCARD;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_ElementNAME_SVID_DCARD(TFIBWideStringField * ElementNAME_SVID_DCARD)
{
Object->ElementNAME_SVID_DCARD=ElementNAME_SVID_DCARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNakSkidokImpl::get_TableNakSkidokGID_SNAK_SKIDOK(void)
{
return Object->TableNakSkidokGID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::set_TableNakSkidokGID_SNAK_SKIDOK(TFIBWideStringField * TableNakSkidokGID_SNAK_SKIDOK)
{
Object->TableNakSkidokGID_SNAK_SKIDOK=TableNakSkidokGID_SNAK_SKIDOK;
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprNakSkidokImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprNakSkidokImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::GetSpisokSkidok(__int64 id_vid, __int64 id_sklad)
{
return Object->GetSpisokSkidok(id_vid,id_sklad);
}
//---------------------------------------------------------------
void TDMSprNakSkidokImpl::OpenTableNakSkidok(__int64 id_vid,__int64 id_sklad)
{
return Object->OpenTableNakSkidok(id_vid,id_sklad);
}
//---------------------------------------------------------------
