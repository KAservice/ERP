#include "vcl.h"
#pragma hdrstop


#include "UDMXSetupObmenImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMXSetupObmenImpl::TDMXSetupObmenImpl()           
{                                            
Object=new TDMXSetupObmen(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMXSetupObmenImpl::~TDMXSetupObmenImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMXSetupObmenImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMXSetupObmenImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMXSetupObmen)                        
   {                                                                     
   *ppv=static_cast<IDMXSetupObmen*> (this);                                
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
int TDMXSetupObmenImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMXSetupObmenImpl::kanRelease(void)                                  
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
int  TDMXSetupObmenImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMXSetupObmenImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMXSetupObmenImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMXSetupObmenImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMXSetupObmenImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMXSetupObmen
TDataSource * TDMXSetupObmenImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMXSetupObmenImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMXSetupObmenImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMXSetupObmenImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_TableID_XSETUP_OBMEN(void)
{
return Object->TableID_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TableID_XSETUP_OBMEN(TFIBBCDField * TableID_XSETUP_OBMEN)
{
Object->TableID_XSETUP_OBMEN=TableID_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_TableIDBASE_OBMEN_XSETUP_OBMEN(void)
{
return Object->TableIDBASE_OBMEN_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TableIDBASE_OBMEN_XSETUP_OBMEN(TFIBBCDField * TableIDBASE_OBMEN_XSETUP_OBMEN)
{
Object->TableIDBASE_OBMEN_XSETUP_OBMEN=TableIDBASE_OBMEN_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_TableIDTISM_XSETUP_OBMEN(void)
{
return Object->TableIDTISM_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TableIDTISM_XSETUP_OBMEN(TFIBBCDField * TableIDTISM_XSETUP_OBMEN)
{
Object->TableIDTISM_XSETUP_OBMEN=TableIDTISM_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMXSetupObmenImpl::get_TableALLDOC_XSETUP_OBMEN(void)
{
return Object->TableALLDOC_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TableALLDOC_XSETUP_OBMEN(TFIBSmallIntField * TableALLDOC_XSETUP_OBMEN)
{
Object->TableALLDOC_XSETUP_OBMEN=TableALLDOC_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMXSetupObmenImpl::get_TableOUTNAC_XSETUP_OBMEN(void)
{
return Object->TableOUTNAC_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TableOUTNAC_XSETUP_OBMEN(TFIBSmallIntField * TableOUTNAC_XSETUP_OBMEN)
{
Object->TableOUTNAC_XSETUP_OBMEN=TableOUTNAC_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMXSetupObmenImpl::get_TableOUTZPRICE_XSETUP_OBMEN(void)
{
return Object->TableOUTZPRICE_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TableOUTZPRICE_XSETUP_OBMEN(TFIBSmallIntField * TableOUTZPRICE_XSETUP_OBMEN)
{
Object->TableOUTZPRICE_XSETUP_OBMEN=TableOUTZPRICE_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMXSetupObmenImpl::get_TableNOEDIT_XSETUP_OBMEN(void)
{
return Object->TableNOEDIT_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TableNOEDIT_XSETUP_OBMEN(TFIBSmallIntField * TableNOEDIT_XSETUP_OBMEN)
{
Object->TableNOEDIT_XSETUP_OBMEN=TableNOEDIT_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_TableIDBASE_XSETUP_OBMEN(void)
{
return Object->TableIDBASE_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TableIDBASE_XSETUP_OBMEN(TFIBBCDField * TableIDBASE_XSETUP_OBMEN)
{
Object->TableIDBASE_XSETUP_OBMEN=TableIDBASE_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMXSetupObmenImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_ElementID_XSETUP_OBMEN(void)
{
return Object->ElementID_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_ElementID_XSETUP_OBMEN(TFIBBCDField * ElementID_XSETUP_OBMEN)
{
Object->ElementID_XSETUP_OBMEN=ElementID_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_ElementIDBASE_OBMEN_XSETUP_OBMEN(void)
{
return Object->ElementIDBASE_OBMEN_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_ElementIDBASE_OBMEN_XSETUP_OBMEN(TFIBBCDField * ElementIDBASE_OBMEN_XSETUP_OBMEN)
{
Object->ElementIDBASE_OBMEN_XSETUP_OBMEN=ElementIDBASE_OBMEN_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_ElementIDTISM_XSETUP_OBMEN(void)
{
return Object->ElementIDTISM_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_ElementIDTISM_XSETUP_OBMEN(TFIBBCDField * ElementIDTISM_XSETUP_OBMEN)
{
Object->ElementIDTISM_XSETUP_OBMEN=ElementIDTISM_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMXSetupObmenImpl::get_ElementALLDOC_XSETUP_OBMEN(void)
{
return Object->ElementALLDOC_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_ElementALLDOC_XSETUP_OBMEN(TFIBSmallIntField * ElementALLDOC_XSETUP_OBMEN)
{
Object->ElementALLDOC_XSETUP_OBMEN=ElementALLDOC_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMXSetupObmenImpl::get_ElementOUTNAC_XSETUP_OBMEN(void)
{
return Object->ElementOUTNAC_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_ElementOUTNAC_XSETUP_OBMEN(TFIBSmallIntField * ElementOUTNAC_XSETUP_OBMEN)
{
Object->ElementOUTNAC_XSETUP_OBMEN=ElementOUTNAC_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMXSetupObmenImpl::get_ElementOUTZPRICE_XSETUP_OBMEN(void)
{
return Object->ElementOUTZPRICE_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_ElementOUTZPRICE_XSETUP_OBMEN(TFIBSmallIntField * ElementOUTZPRICE_XSETUP_OBMEN)
{
Object->ElementOUTZPRICE_XSETUP_OBMEN=ElementOUTZPRICE_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMXSetupObmenImpl::get_ElementNOEDIT_XSETUP_OBMEN(void)
{
return Object->ElementNOEDIT_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_ElementNOEDIT_XSETUP_OBMEN(TFIBSmallIntField * ElementNOEDIT_XSETUP_OBMEN)
{
Object->ElementNOEDIT_XSETUP_OBMEN=ElementNOEDIT_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_ElementIDBASE_XSETUP_OBMEN(void)
{
return Object->ElementIDBASE_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_ElementIDBASE_XSETUP_OBMEN(TFIBBCDField * ElementIDBASE_XSETUP_OBMEN)
{
Object->ElementIDBASE_XSETUP_OBMEN=ElementIDBASE_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TDataSource * TDMXSetupObmenImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMXSetupObmenImpl::get_BaseForObmen(void)
{
return Object->BaseForObmen;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_BaseForObmen(TpFIBDataSet * BaseForObmen)
{
Object->BaseForObmen=BaseForObmen;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMXSetupObmenImpl::get_TypePriceForObmen(void)
{
return Object->TypePriceForObmen;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TypePriceForObmen(TpFIBDataSet * TypePriceForObmen)
{
Object->TypePriceForObmen=TypePriceForObmen;
}
//---------------------------------------------------------------
TDataSource * TDMXSetupObmenImpl::get_DataSourceBaseForObmen(void)
{
return Object->DataSourceBaseForObmen;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_DataSourceBaseForObmen(TDataSource * DataSourceBaseForObmen)
{
Object->DataSourceBaseForObmen=DataSourceBaseForObmen;
}
//---------------------------------------------------------------
TDataSource * TDMXSetupObmenImpl::get_DataSourceTypePriceForObmen(void)
{
return Object->DataSourceTypePriceForObmen;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_DataSourceTypePriceForObmen(TDataSource * DataSourceTypePriceForObmen)
{
Object->DataSourceTypePriceForObmen=DataSourceTypePriceForObmen;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_BaseForObmenID_XBASE_FOR_OBMEN(void)
{
return Object->BaseForObmenID_XBASE_FOR_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_BaseForObmenID_XBASE_FOR_OBMEN(TFIBBCDField * BaseForObmenID_XBASE_FOR_OBMEN)
{
Object->BaseForObmenID_XBASE_FOR_OBMEN=BaseForObmenID_XBASE_FOR_OBMEN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN(void)
{
return Object->BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN(TFIBBCDField * BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN)
{
Object->BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN=BaseForObmenIDBASE_OBMEN_XBASE_FOR_OBMEN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN(void)
{
return Object->BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN(TFIBBCDField * BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN)
{
Object->BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN=BaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_BaseForObmenIDBASE_XBASE_FOR_OBMEN(void)
{
return Object->BaseForObmenIDBASE_XBASE_FOR_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_BaseForObmenIDBASE_XBASE_FOR_OBMEN(TFIBBCDField * BaseForObmenIDBASE_XBASE_FOR_OBMEN)
{
Object->BaseForObmenIDBASE_XBASE_FOR_OBMEN=BaseForObmenIDBASE_XBASE_FOR_OBMEN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_TypePriceForObmenID_XTPRICE_FOR_OBMEN(void)
{
return Object->TypePriceForObmenID_XTPRICE_FOR_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TypePriceForObmenID_XTPRICE_FOR_OBMEN(TFIBBCDField * TypePriceForObmenID_XTPRICE_FOR_OBMEN)
{
Object->TypePriceForObmenID_XTPRICE_FOR_OBMEN=TypePriceForObmenID_XTPRICE_FOR_OBMEN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN(void)
{
return Object->TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN(TFIBBCDField * TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN)
{
Object->TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN=TypePriceForObmenIDBASE_OBMEN_XTPRICE_FOR_OBMEN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN(void)
{
return Object->TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN(TFIBBCDField * TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN)
{
Object->TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN=TypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN(void)
{
return Object->TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN(TFIBBCDField * TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN)
{
Object->TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN=TypePriceForObmenIDBASE_XTPRICE_FOR_OBMEN;
}
//---------------------------------------------------------------
TIntegerField * TDMXSetupObmenImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMXSetupObmenImpl::get_ElementIDFIRST_DO_XSETUP_OBMEN(void)
{
return Object->ElementIDFIRST_DO_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_ElementIDFIRST_DO_XSETUP_OBMEN(TFIBBCDField * ElementIDFIRST_DO_XSETUP_OBMEN)
{
Object->ElementIDFIRST_DO_XSETUP_OBMEN=ElementIDFIRST_DO_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMXSetupObmenImpl::get_ElementOPER_XSETUP_OBMEN(void)
{
return Object->ElementOPER_XSETUP_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_ElementOPER_XSETUP_OBMEN(TFIBIntegerField * ElementOPER_XSETUP_OBMEN)
{
Object->ElementOPER_XSETUP_OBMEN=ElementOPER_XSETUP_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMXSetupObmenImpl::get_TableNAME_SINFBASE_OBMEN(void)
{
return Object->TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TableNAME_SINFBASE_OBMEN(TFIBWideStringField * TableNAME_SINFBASE_OBMEN)
{
Object->TableNAME_SINFBASE_OBMEN=TableNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMXSetupObmenImpl::get_ElementNAME_SINFBASE_OBMEN(void)
{
return Object->ElementNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_ElementNAME_SINFBASE_OBMEN(TFIBWideStringField * ElementNAME_SINFBASE_OBMEN)
{
Object->ElementNAME_SINFBASE_OBMEN=ElementNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMXSetupObmenImpl::get_BaseForObmenNAME_SINFBASE_OBMEN(void)
{
return Object->BaseForObmenNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_BaseForObmenNAME_SINFBASE_OBMEN(TFIBWideStringField * BaseForObmenNAME_SINFBASE_OBMEN)
{
Object->BaseForObmenNAME_SINFBASE_OBMEN=BaseForObmenNAME_SINFBASE_OBMEN;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMXSetupObmenImpl::get_TypePriceForObmenNAME_TPRICE(void)
{
return Object->TypePriceForObmenNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_TypePriceForObmenNAME_TPRICE(TFIBWideStringField * TypePriceForObmenNAME_TPRICE)
{
Object->TypePriceForObmenNAME_TPRICE=TypePriceForObmenNAME_TPRICE;
}
//---------------------------------------------------------------
__int64 TDMXSetupObmenImpl::get_IdBase(void)
{
return Object->IdBase;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_IdBase(__int64 IdBase)
{
Object->IdBase=IdBase;
}
//---------------------------------------------------------------
bool TDMXSetupObmenImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
bool TDMXSetupObmenImpl::OpenElement(__int64 id_base)
{
return Object->OpenElement(id_base);
}
//---------------------------------------------------------------
void TDMXSetupObmenImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMXSetupObmenImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMXSetupObmenImpl::DeleteElement(__int64 id_base)
{
return Object->DeleteElement(id_base);
}
//---------------------------------------------------------------
bool TDMXSetupObmenImpl::AddBase(__int64 id_base, AnsiString name_base)
{
return Object->AddBase(id_base, name_base);
}
//---------------------------------------------------------------
bool TDMXSetupObmenImpl::AddTypePrice(__int64 id_type_price, AnsiString name_type_price)
{
return Object->AddTypePrice(id_type_price,name_type_price);
}
//---------------------------------------------------------------
bool TDMXSetupObmenImpl::DeleteBase(void)
{
return Object->DeleteBase();
}
//---------------------------------------------------------------
bool TDMXSetupObmenImpl::DeleteTypePrice(void)
{
return Object->DeleteTypePrice();
}
//---------------------------------------------------------------
