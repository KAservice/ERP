#include <vcl.h>
#pragma hdrstop


#include "UDMSprDogovorImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprDogovorImpl::TDMSprDogovorImpl()           
{                                            
Object=new TDMSprDogovor(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprDogovorImpl::~TDMSprDogovorImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprDogovorImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprDogovorImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprDogovor)                        
   {                                                                     
   *ppv=static_cast<IDMSprDogovor*> (this);                                
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
int TDMSprDogovorImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);
}
//---------------------------------------------------------------
int TDMSprDogovorImpl::kanRelease(void)
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
int  TDMSprDogovorImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprDogovorImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprDogovorImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprDogovorImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprDogovorImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprDogovorImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprDogovorImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprDogovorImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprDogovorImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprDogovorImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBDateField * TDMSprDogovorImpl::get_TableDO_SDOG(void)
{
return Object->TableDO_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_TableDO_SDOG(TFIBDateField * TableDO_SDOG)
{
Object->TableDO_SDOG=TableDO_SDOG;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprDogovorImpl::get_TableWAYPAY_SDOG(void)
{
return Object->TableWAYPAY_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_TableWAYPAY_SDOG(TFIBIntegerField * TableWAYPAY_SDOG)
{
Object->TableWAYPAY_SDOG=TableWAYPAY_SDOG;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDogovorImpl::get_TableMAXSUMCREDIT_SDOG(void)
{
return Object->TableMAXSUMCREDIT_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_TableMAXSUMCREDIT_SDOG(TFIBBCDField * TableMAXSUMCREDIT_SDOG)
{
Object->TableMAXSUMCREDIT_SDOG=TableMAXSUMCREDIT_SDOG;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprDogovorImpl::get_TableSROK_SDOG(void)
{
return Object->TableSROK_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_TableSROK_SDOG(TFIBIntegerField * TableSROK_SDOG)
{
Object->TableSROK_SDOG=TableSROK_SDOG;
}
//---------------------------------------------------------------
TFIBDateField * TDMSprDogovorImpl::get_TableDATE_SDOG(void)
{
return Object->TableDATE_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_TableDATE_SDOG(TFIBDateField * TableDATE_SDOG)
{
Object->TableDATE_SDOG=TableDATE_SDOG;
}
//---------------------------------------------------------------
TIntegerField * TDMSprDogovorImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBDateField * TDMSprDogovorImpl::get_ElementDO_SDOG(void)
{
return Object->ElementDO_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_ElementDO_SDOG(TFIBDateField * ElementDO_SDOG)
{
Object->ElementDO_SDOG=ElementDO_SDOG;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprDogovorImpl::get_ElementWAYPAY_SDOG(void)
{
return Object->ElementWAYPAY_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_ElementWAYPAY_SDOG(TFIBIntegerField * ElementWAYPAY_SDOG)
{
Object->ElementWAYPAY_SDOG=ElementWAYPAY_SDOG;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDogovorImpl::get_ElementMAXSUMCREDIT_SDOG(void)
{
return Object->ElementMAXSUMCREDIT_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_ElementMAXSUMCREDIT_SDOG(TFIBBCDField * ElementMAXSUMCREDIT_SDOG)
{
Object->ElementMAXSUMCREDIT_SDOG=ElementMAXSUMCREDIT_SDOG;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprDogovorImpl::get_ElementSROK_SDOG(void)
{
return Object->ElementSROK_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_ElementSROK_SDOG(TFIBIntegerField * ElementSROK_SDOG)
{
Object->ElementSROK_SDOG=ElementSROK_SDOG;
}
//---------------------------------------------------------------
TFIBDateField * TDMSprDogovorImpl::get_ElementDATE_SDOG(void)
{
return Object->ElementDATE_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_ElementDATE_SDOG(TFIBDateField * ElementDATE_SDOG)
{
Object->ElementDATE_SDOG=ElementDATE_SDOG;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDogovorImpl::get_TableID_SDOG(void)
{
return Object->TableID_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_TableID_SDOG(TFIBBCDField * TableID_SDOG)
{
Object->TableID_SDOG=TableID_SDOG;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDogovorImpl::get_TableIDKLIENT_SDOG(void)
{
return Object->TableIDKLIENT_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_TableIDKLIENT_SDOG(TFIBBCDField * TableIDKLIENT_SDOG)
{
Object->TableIDKLIENT_SDOG=TableIDKLIENT_SDOG;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDogovorImpl::get_TableIDTPRICE_SDOG(void)
{
return Object->TableIDTPRICE_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_TableIDTPRICE_SDOG(TFIBBCDField * TableIDTPRICE_SDOG)
{
Object->TableIDTPRICE_SDOG=TableIDTPRICE_SDOG;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDogovorImpl::get_ElementID_SDOG(void)
{
return Object->ElementID_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_ElementID_SDOG(TFIBBCDField * ElementID_SDOG)
{
Object->ElementID_SDOG=ElementID_SDOG;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDogovorImpl::get_ElementIDKLIENT_SDOG(void)
{
return Object->ElementIDKLIENT_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_ElementIDKLIENT_SDOG(TFIBBCDField * ElementIDKLIENT_SDOG)
{
Object->ElementIDKLIENT_SDOG=ElementIDKLIENT_SDOG;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprDogovorImpl::get_ElementIDTPRICE_SDOG(void)
{
return Object->ElementIDTPRICE_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_ElementIDTPRICE_SDOG(TFIBBCDField * ElementIDTPRICE_SDOG)
{
Object->ElementIDTPRICE_SDOG=ElementIDTPRICE_SDOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDogovorImpl::get_TableNAME_SDOG(void)
{
return Object->TableNAME_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_TableNAME_SDOG(TFIBWideStringField * TableNAME_SDOG)
{
Object->TableNAME_SDOG=TableNAME_SDOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDogovorImpl::get_TableGID_SDOG(void)
{
return Object->TableGID_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_TableGID_SDOG(TFIBWideStringField * TableGID_SDOG)
{
Object->TableGID_SDOG=TableGID_SDOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDogovorImpl::get_TableNUMBER_SDOG(void)
{
return Object->TableNUMBER_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_TableNUMBER_SDOG(TFIBWideStringField * TableNUMBER_SDOG)
{
Object->TableNUMBER_SDOG=TableNUMBER_SDOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDogovorImpl::get_ElementNAME_SDOG(void)
{
return Object->ElementNAME_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_ElementNAME_SDOG(TFIBWideStringField * ElementNAME_SDOG)
{
Object->ElementNAME_SDOG=ElementNAME_SDOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDogovorImpl::get_ElementGID_SDOG(void)
{
return Object->ElementGID_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_ElementGID_SDOG(TFIBWideStringField * ElementGID_SDOG)
{
Object->ElementGID_SDOG=ElementGID_SDOG;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprDogovorImpl::get_ElementNUMBER_SDOG(void)
{
return Object->ElementNUMBER_SDOG;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_ElementNUMBER_SDOG(TFIBWideStringField * ElementNUMBER_SDOG)
{
Object->ElementNUMBER_SDOG=ElementNUMBER_SDOG;
}
//---------------------------------------------------------------
__int64 TDMSprDogovorImpl::get_IdKlient(void)
{
return Object->IdKlient;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::set_IdKlient(__int64 IdKlient)
{
Object->IdKlient=IdKlient;
}
//----------------------------------------------------------------
bool TDMSprDogovorImpl::get_flSaveElement(void)
{
return Object->flSaveElement;
}
//------------------------------------------------------------
void TDMSprDogovorImpl::set_flSaveElement(bool flSaveElement)
{

Object->flSaveElement=flSaveElement;
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::OpenTable(__int64 IdKl)
{
return Object->OpenTable(IdKl);
}
//---------------------------------------------------------------
int TDMSprDogovorImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::NewElement(__int64 IdKl)
{
return Object->NewElement(IdKl);
}
//---------------------------------------------------------------
bool TDMSprDogovorImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprDogovorImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
