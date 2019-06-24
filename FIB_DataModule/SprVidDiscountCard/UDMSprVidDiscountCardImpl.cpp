#include <vcl.h>
#pragma hdrstop


#include "UDMSprVidDiscountCardImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprVidDiscountCardImpl::TDMSprVidDiscountCardImpl()           
{                                            
Object=new TDMSprVidDiscountCard(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprVidDiscountCardImpl::~TDMSprVidDiscountCardImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprVidDiscountCardImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprVidDiscountCard)                        
   {                                                                     
   *ppv=static_cast<IDMSprVidDiscountCard*> (this);                                
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
int TDMSprVidDiscountCardImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprVidDiscountCardImpl::kanRelease(void)                                  
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
int  TDMSprVidDiscountCardImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprVidDiscountCardImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprVidDiscountCardImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprVidDiscountCardImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprVidDiscountCardImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprVidDiscountCardImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprVidDiscountCardImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprVidDiscountCardImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprVidDiscountCardImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprVidDiscountCardImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprVidDiscountCardImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprVidDiscountCardImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprVidDiscountCardImpl::get_TableID_SVID_DCARD(void)
{
return Object->TableID_SVID_DCARD;
}
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::set_TableID_SVID_DCARD(TFIBBCDField * TableID_SVID_DCARD)
{
Object->TableID_SVID_DCARD=TableID_SVID_DCARD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprVidDiscountCardImpl::get_ElementID_SVID_DCARD(void)
{
return Object->ElementID_SVID_DCARD;
}
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::set_ElementID_SVID_DCARD(TFIBBCDField * ElementID_SVID_DCARD)
{
Object->ElementID_SVID_DCARD=ElementID_SVID_DCARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVidDiscountCardImpl::get_TableGID_SVID_DCARD(void)
{
return Object->TableGID_SVID_DCARD;
}
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::set_TableGID_SVID_DCARD(TFIBWideStringField * TableGID_SVID_DCARD)
{
Object->TableGID_SVID_DCARD=TableGID_SVID_DCARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVidDiscountCardImpl::get_TableNAME_SVID_DCARD(void)
{
return Object->TableNAME_SVID_DCARD;
}
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::set_TableNAME_SVID_DCARD(TFIBWideStringField * TableNAME_SVID_DCARD)
{
Object->TableNAME_SVID_DCARD=TableNAME_SVID_DCARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVidDiscountCardImpl::get_ElementGID_SVID_DCARD(void)
{
return Object->ElementGID_SVID_DCARD;
}
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::set_ElementGID_SVID_DCARD(TFIBWideStringField * ElementGID_SVID_DCARD)
{
Object->ElementGID_SVID_DCARD=ElementGID_SVID_DCARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVidDiscountCardImpl::get_ElementNAME_SVID_DCARD(void)
{
return Object->ElementNAME_SVID_DCARD;
}
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::set_ElementNAME_SVID_DCARD(TFIBWideStringField * ElementNAME_SVID_DCARD)
{
Object->ElementNAME_SVID_DCARD=ElementNAME_SVID_DCARD;
}
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprVidDiscountCardImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
bool TDMSprVidDiscountCardImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprVidDiscountCardImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprVidDiscountCardImpl::CloseElement(void)
{
return Object->CloseElement();
}
//---------------------------------------------------------------
bool TDMSprVidDiscountCardImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
__int64 TDMSprVidDiscountCardImpl::GetIDElement(String gid)
{
return Object->GetIDElement(gid);
}
//---------------------------------------------------------------
AnsiString TDMSprVidDiscountCardImpl::GetGIDElement(__int64 id)
{
return Object->GetGIDElement(id);
}
//---------------------------------------------------------------
int TDMSprVidDiscountCardImpl::GetIndexElementaPoID(__int64 id)
{
return Object->GetIndexElementaPoID(id);
}
//---------------------------------------------------------------
