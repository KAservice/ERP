#include "vcl.h"
#pragma hdrstop


#include "UDMGurOperDiscountCardImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMGurOperDiscountCardImpl::TDMGurOperDiscountCardImpl()           
{                                            
Object=new TDMGurOperDiscountCard(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMGurOperDiscountCardImpl::~TDMGurOperDiscountCardImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMGurOperDiscountCardImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMGurOperDiscountCard)                        
   {                                                                     
   *ppv=static_cast<IDMGurOperDiscountCard*> (this);                                
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
int TDMGurOperDiscountCardImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMGurOperDiscountCardImpl::kanRelease(void)                                  
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
int  TDMGurOperDiscountCardImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMGurOperDiscountCardImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMGurOperDiscountCardImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMGurOperDiscountCardImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMGurOperDiscountCard
TDataSource * TDMGurOperDiscountCardImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMGurOperDiscountCardImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMGurOperDiscountCardImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMGurOperDiscountCardImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMGurOperDiscountCardImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMGurOperDiscountCardImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMGurOperDiscountCardImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurOperDiscountCardImpl::get_TableSUM_GUROPER_DCARD(void)
{
return Object->TableSUM_GUROPER_DCARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_TableSUM_GUROPER_DCARD(TFIBBCDField * TableSUM_GUROPER_DCARD)
{
Object->TableSUM_GUROPER_DCARD=TableSUM_GUROPER_DCARD;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMGurOperDiscountCardImpl::get_TablePOS_GUROPER_DCARD(void)
{
return Object->TablePOS_GUROPER_DCARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_TablePOS_GUROPER_DCARD(TFIBDateTimeField * TablePOS_GUROPER_DCARD)
{
Object->TablePOS_GUROPER_DCARD=TablePOS_GUROPER_DCARD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurOperDiscountCardImpl::get_ElementSUM_GUROPER_DCARD(void)
{
return Object->ElementSUM_GUROPER_DCARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_ElementSUM_GUROPER_DCARD(TFIBBCDField * ElementSUM_GUROPER_DCARD)
{
Object->ElementSUM_GUROPER_DCARD=ElementSUM_GUROPER_DCARD;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMGurOperDiscountCardImpl::get_ElementPOS_GUROPER_DCARD(void)
{
return Object->ElementPOS_GUROPER_DCARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_ElementPOS_GUROPER_DCARD(TFIBDateTimeField * ElementPOS_GUROPER_DCARD)
{
Object->ElementPOS_GUROPER_DCARD=ElementPOS_GUROPER_DCARD;
}
//---------------------------------------------------------------
TpFIBQuery * TDMGurOperDiscountCardImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurOperDiscountCardImpl::get_ElementID_GUROPER_DCARD(void)
{
return Object->ElementID_GUROPER_DCARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_ElementID_GUROPER_DCARD(TFIBBCDField * ElementID_GUROPER_DCARD)
{
Object->ElementID_GUROPER_DCARD=ElementID_GUROPER_DCARD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurOperDiscountCardImpl::get_ElementIDKLIENT_GUROPER_DCARD(void)
{
return Object->ElementIDKLIENT_GUROPER_DCARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_ElementIDKLIENT_GUROPER_DCARD(TFIBBCDField * ElementIDKLIENT_GUROPER_DCARD)
{
Object->ElementIDKLIENT_GUROPER_DCARD=ElementIDKLIENT_GUROPER_DCARD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurOperDiscountCardImpl::get_ElementIDSKLAD_GUROPER_DCARD(void)
{
return Object->ElementIDSKLAD_GUROPER_DCARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_ElementIDSKLAD_GUROPER_DCARD(TFIBBCDField * ElementIDSKLAD_GUROPER_DCARD)
{
Object->ElementIDSKLAD_GUROPER_DCARD=ElementIDSKLAD_GUROPER_DCARD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurOperDiscountCardImpl::get_ElementIDCARD_GUROPER_DCARD(void)
{
return Object->ElementIDCARD_GUROPER_DCARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_ElementIDCARD_GUROPER_DCARD(TFIBBCDField * ElementIDCARD_GUROPER_DCARD)
{
Object->ElementIDCARD_GUROPER_DCARD=ElementIDCARD_GUROPER_DCARD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurOperDiscountCardImpl::get_ElementIDDOC_GUROPER_DCARD(void)
{
return Object->ElementIDDOC_GUROPER_DCARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_ElementIDDOC_GUROPER_DCARD(TFIBBCDField * ElementIDDOC_GUROPER_DCARD)
{
Object->ElementIDDOC_GUROPER_DCARD=ElementIDDOC_GUROPER_DCARD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurOperDiscountCardImpl::get_TableID_GUROPER_DCARD(void)
{
return Object->TableID_GUROPER_DCARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_TableID_GUROPER_DCARD(TFIBBCDField * TableID_GUROPER_DCARD)
{
Object->TableID_GUROPER_DCARD=TableID_GUROPER_DCARD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurOperDiscountCardImpl::get_TableIDKLIENT_GUROPER_DCARD(void)
{
return Object->TableIDKLIENT_GUROPER_DCARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_TableIDKLIENT_GUROPER_DCARD(TFIBBCDField * TableIDKLIENT_GUROPER_DCARD)
{
Object->TableIDKLIENT_GUROPER_DCARD=TableIDKLIENT_GUROPER_DCARD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurOperDiscountCardImpl::get_TableIDSKLAD_GUROPER_DCARD(void)
{
return Object->TableIDSKLAD_GUROPER_DCARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_TableIDSKLAD_GUROPER_DCARD(TFIBBCDField * TableIDSKLAD_GUROPER_DCARD)
{
Object->TableIDSKLAD_GUROPER_DCARD=TableIDSKLAD_GUROPER_DCARD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurOperDiscountCardImpl::get_TableIDCARD_GUROPER_DCARD(void)
{
return Object->TableIDCARD_GUROPER_DCARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_TableIDCARD_GUROPER_DCARD(TFIBBCDField * TableIDCARD_GUROPER_DCARD)
{
Object->TableIDCARD_GUROPER_DCARD=TableIDCARD_GUROPER_DCARD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMGurOperDiscountCardImpl::get_TableIDDOC_GUROPER_DCARD(void)
{
return Object->TableIDDOC_GUROPER_DCARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_TableIDDOC_GUROPER_DCARD(TFIBBCDField * TableIDDOC_GUROPER_DCARD)
{
Object->TableIDDOC_GUROPER_DCARD=TableIDDOC_GUROPER_DCARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurOperDiscountCardImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurOperDiscountCardImpl::get_TableNAMESKLAD(void)
{
return Object->TableNAMESKLAD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_TableNAMESKLAD(TFIBWideStringField * TableNAMESKLAD)
{
Object->TableNAMESKLAD=TableNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurOperDiscountCardImpl::get_TableNAME_SDISCOUNT_CARD(void)
{
return Object->TableNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_TableNAME_SDISCOUNT_CARD(TFIBWideStringField * TableNAME_SDISCOUNT_CARD)
{
Object->TableNAME_SDISCOUNT_CARD=TableNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurOperDiscountCardImpl::get_ElementGID_GUROPER_DCARD(void)
{
return Object->ElementGID_GUROPER_DCARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_ElementGID_GUROPER_DCARD(TFIBWideStringField * ElementGID_GUROPER_DCARD)
{
Object->ElementGID_GUROPER_DCARD=ElementGID_GUROPER_DCARD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurOperDiscountCardImpl::get_ElementNAMEKLIENT(void)
{
return Object->ElementNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)
{
Object->ElementNAMEKLIENT=ElementNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurOperDiscountCardImpl::get_ElementNAMESKLAD(void)
{
return Object->ElementNAMESKLAD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_ElementNAMESKLAD(TFIBWideStringField * ElementNAMESKLAD)
{
Object->ElementNAMESKLAD=ElementNAMESKLAD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMGurOperDiscountCardImpl::get_ElementNAME_SDISCOUNT_CARD(void)
{
return Object->ElementNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_ElementNAME_SDISCOUNT_CARD(TFIBWideStringField * ElementNAME_SDISCOUNT_CARD)
{
Object->ElementNAME_SDISCOUNT_CARD=ElementNAME_SDISCOUNT_CARD;
}
//---------------------------------------------------------------
bool TDMGurOperDiscountCardImpl::get_elSave(void)
{
return Object->elSave;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_elSave(bool elSave)
{
Object->elSave=elSave;
}
//---------------------------------------------------------------
TDateTime TDMGurOperDiscountCardImpl::get_PosNach(void)
{
return Object->PosNach;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_PosNach(TDateTime PosNach)
{
Object->PosNach=PosNach;
}
//---------------------------------------------------------------
TDateTime TDMGurOperDiscountCardImpl::get_PosCon(void)
{
return Object->PosCon;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::set_PosCon(TDateTime PosCon)
{
Object->PosCon=PosCon;
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMGurOperDiscountCardImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMGurOperDiscountCardImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMGurOperDiscountCardImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
double TDMGurOperDiscountCardImpl::GetSumPokupok(__int64 id_klient, TDateTime pos_nach)
{
return Object->GetSumPokupok(id_klient,pos_nach);
}
//---------------------------------------------------------------
__int64 TDMGurOperDiscountCardImpl::PoiskPoCoduDoc(__int64 code_doc)
{
return Object->PoiskPoCoduDoc(code_doc);
}
//---------------------------------------------------------------
