#include "vcl.h"
#pragma hdrstop


#include "UDMSprPropertiesNaborSostavImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprPropertiesNaborSostavImpl::TDMSprPropertiesNaborSostavImpl()           
{                                            
Object=new TDMSprPropertiesNaborSostav(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprPropertiesNaborSostavImpl::~TDMSprPropertiesNaborSostavImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprPropertiesNaborSostavImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprPropertiesNaborSostav)                        
   {                                                                     
   *ppv=static_cast<IDMSprPropertiesNaborSostav*> (this);                                
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
int TDMSprPropertiesNaborSostavImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprPropertiesNaborSostavImpl::kanRelease(void)                                  
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
int  TDMSprPropertiesNaborSostavImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprPropertiesNaborSostavImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprPropertiesNaborSostavImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprPropertiesNaborSostavImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprPropertiesNaborSostavImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprPropertiesNaborSostav
TDataSource * TDMSprPropertiesNaborSostavImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprPropertiesNaborSostavImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPropertiesNaborSostavImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPropertiesNaborSostavImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPropertiesNaborSostavImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPropertiesNaborSostavImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprPropertiesNaborSostavImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TIntegerField * TDMSprPropertiesNaborSostavImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborSostavImpl::get_TableID_SPROPNABOR_SOST(void)
{
return Object->TableID_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TableID_SPROPNABOR_SOST(TFIBLargeIntField * TableID_SPROPNABOR_SOST)
{
Object->TableID_SPROPNABOR_SOST=TableID_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborSostavImpl::get_TableIDBASE_SPROPNABOR_SOST(void)
{
return Object->TableIDBASE_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TableIDBASE_SPROPNABOR_SOST(TFIBLargeIntField * TableIDBASE_SPROPNABOR_SOST)
{
Object->TableIDBASE_SPROPNABOR_SOST=TableIDBASE_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesNaborSostavImpl::get_TableGID_SPROPNABOR_SOST(void)
{
return Object->TableGID_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TableGID_SPROPNABOR_SOST(TFIBWideStringField * TableGID_SPROPNABOR_SOST)
{
Object->TableGID_SPROPNABOR_SOST=TableGID_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborSostavImpl::get_TableIDPROPNABOR_SPROPNABOR_SOST(void)
{
return Object->TableIDPROPNABOR_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TableIDPROPNABOR_SPROPNABOR_SOST(TFIBLargeIntField * TableIDPROPNABOR_SPROPNABOR_SOST)
{
Object->TableIDPROPNABOR_SPROPNABOR_SOST=TableIDPROPNABOR_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborSostavImpl::get_TableIDPROP_SPROPNABOR_SOST(void)
{
return Object->TableIDPROP_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TableIDPROP_SPROPNABOR_SOST(TFIBLargeIntField * TableIDPROP_SPROPNABOR_SOST)
{
Object->TableIDPROP_SPROPNABOR_SOST=TableIDPROP_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprPropertiesNaborSostavImpl::get_TableINDEXSORT_SPROPNABOR_SOST(void)
{
return Object->TableINDEXSORT_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TableINDEXSORT_SPROPNABOR_SOST(TFIBIntegerField * TableINDEXSORT_SPROPNABOR_SOST)
{
Object->TableINDEXSORT_SPROPNABOR_SOST=TableINDEXSORT_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborSostavImpl::get_ElementID_SPROPNABOR_SOST(void)
{
return Object->ElementID_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_ElementID_SPROPNABOR_SOST(TFIBLargeIntField * ElementID_SPROPNABOR_SOST)
{
Object->ElementID_SPROPNABOR_SOST=ElementID_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborSostavImpl::get_ElementIDBASE_SPROPNABOR_SOST(void)
{
return Object->ElementIDBASE_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_ElementIDBASE_SPROPNABOR_SOST(TFIBLargeIntField * ElementIDBASE_SPROPNABOR_SOST)
{
Object->ElementIDBASE_SPROPNABOR_SOST=ElementIDBASE_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesNaborSostavImpl::get_ElementGID_SPROPNABOR_SOST(void)
{
return Object->ElementGID_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_ElementGID_SPROPNABOR_SOST(TFIBWideStringField * ElementGID_SPROPNABOR_SOST)
{
Object->ElementGID_SPROPNABOR_SOST=ElementGID_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborSostavImpl::get_ElementIDPROPNABOR_SPROPNABOR_SOST(void)
{
return Object->ElementIDPROPNABOR_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_ElementIDPROPNABOR_SPROPNABOR_SOST(TFIBLargeIntField * ElementIDPROPNABOR_SPROPNABOR_SOST)
{
Object->ElementIDPROPNABOR_SPROPNABOR_SOST=ElementIDPROPNABOR_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprPropertiesNaborSostavImpl::get_ElementIDPROP_SPROPNABOR_SOST(void)
{
return Object->ElementIDPROP_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_ElementIDPROP_SPROPNABOR_SOST(TFIBLargeIntField * ElementIDPROP_SPROPNABOR_SOST)
{
Object->ElementIDPROP_SPROPNABOR_SOST=ElementIDPROP_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprPropertiesNaborSostavImpl::get_ElementINDEXSORT_SPROPNABOR_SOST(void)
{
return Object->ElementINDEXSORT_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_ElementINDEXSORT_SPROPNABOR_SOST(TFIBIntegerField * ElementINDEXSORT_SPROPNABOR_SOST)
{
Object->ElementINDEXSORT_SPROPNABOR_SOST=ElementINDEXSORT_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesNaborSostavImpl::get_TableNAME_SPROP(void)
{
return Object->TableNAME_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TableNAME_SPROP(TFIBWideStringField * TableNAME_SPROP)
{
Object->TableNAME_SPROP=TableNAME_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesNaborSostavImpl::get_ElementNAME_SPROP(void)
{
return Object->ElementNAME_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_ElementNAME_SPROP(TFIBWideStringField * ElementNAME_SPROP)
{
Object->ElementNAME_SPROP=ElementNAME_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesNaborSostavImpl::get_TableNAME_FOR_PRINT_SPROP(void)
{
return Object->TableNAME_FOR_PRINT_SPROP;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TableNAME_FOR_PRINT_SPROP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP)
{
Object->TableNAME_FOR_PRINT_SPROP=TableNAME_FOR_PRINT_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesNaborSostavImpl::get_TableNAME_SPROP_GRP(void)
{
return Object->TableNAME_SPROP_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TableNAME_SPROP_GRP(TFIBWideStringField * TableNAME_SPROP_GRP)
{
Object->TableNAME_SPROP_GRP=TableNAME_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPropertiesNaborSostavImpl::get_TableNAME_FOR_PRINT_SPROP_GRP(void)
{
return Object->TableNAME_FOR_PRINT_SPROP_GRP;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TableNAME_FOR_PRINT_SPROP_GRP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP_GRP)
{
Object->TableNAME_FOR_PRINT_SPROP_GRP=TableNAME_FOR_PRINT_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprPropertiesNaborSostavImpl::get_TableADD1_SPROPNABOR_SOST(void)
{
return Object->TableADD1_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TableADD1_SPROPNABOR_SOST(TFIBSmallIntField * TableADD1_SPROPNABOR_SOST)
{
Object->TableADD1_SPROPNABOR_SOST=TableADD1_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprPropertiesNaborSostavImpl::get_TableADD2_SPROPNABOR_SOST(void)
{
return Object->TableADD2_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TableADD2_SPROPNABOR_SOST(TFIBSmallIntField * TableADD2_SPROPNABOR_SOST)
{
Object->TableADD2_SPROPNABOR_SOST=TableADD2_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprPropertiesNaborSostavImpl::get_TableADD3_SPROPNABOR_SOST(void)
{
return Object->TableADD3_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TableADD3_SPROPNABOR_SOST(TFIBSmallIntField * TableADD3_SPROPNABOR_SOST)
{
Object->TableADD3_SPROPNABOR_SOST=TableADD3_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprPropertiesNaborSostavImpl::get_TableADD4_SPROPNABOR_SOST(void)
{
return Object->TableADD4_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TableADD4_SPROPNABOR_SOST(TFIBSmallIntField * TableADD4_SPROPNABOR_SOST)
{
Object->TableADD4_SPROPNABOR_SOST=TableADD4_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprPropertiesNaborSostavImpl::get_TableADD5_SPROPNABOR_SOST(void)
{
return Object->TableADD5_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_TableADD5_SPROPNABOR_SOST(TFIBSmallIntField * TableADD5_SPROPNABOR_SOST)
{
Object->TableADD5_SPROPNABOR_SOST=TableADD5_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprPropertiesNaborSostavImpl::get_ElementADD1_SPROPNABOR_SOST(void)
{
return Object->ElementADD1_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_ElementADD1_SPROPNABOR_SOST(TFIBSmallIntField * ElementADD1_SPROPNABOR_SOST)
{
Object->ElementADD1_SPROPNABOR_SOST=ElementADD1_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprPropertiesNaborSostavImpl::get_ElementADD2_SPROPNABOR_SOST(void)
{
return Object->ElementADD2_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_ElementADD2_SPROPNABOR_SOST(TFIBSmallIntField * ElementADD2_SPROPNABOR_SOST)
{
Object->ElementADD2_SPROPNABOR_SOST=ElementADD2_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprPropertiesNaborSostavImpl::get_ElementADD3_SPROPNABOR_SOST(void)
{
return Object->ElementADD3_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_ElementADD3_SPROPNABOR_SOST(TFIBSmallIntField * ElementADD3_SPROPNABOR_SOST)
{
Object->ElementADD3_SPROPNABOR_SOST=ElementADD3_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprPropertiesNaborSostavImpl::get_ElementADD4_SPROPNABOR_SOST(void)
{
return Object->ElementADD4_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_ElementADD4_SPROPNABOR_SOST(TFIBSmallIntField * ElementADD4_SPROPNABOR_SOST)
{
Object->ElementADD4_SPROPNABOR_SOST=ElementADD4_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprPropertiesNaborSostavImpl::get_ElementADD5_SPROPNABOR_SOST(void)
{
return Object->ElementADD5_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::set_ElementADD5_SPROPNABOR_SOST(TFIBSmallIntField * ElementADD5_SPROPNABOR_SOST)
{
Object->ElementADD5_SPROPNABOR_SOST=ElementADD5_SPROPNABOR_SOST;
}
//---------------------------------------------------------------
void TDMSprPropertiesNaborSostavImpl::OpenTable(__int64 id_nabor)
{
return Object->OpenTable(id_nabor);
}
//---------------------------------------------------------------
int TDMSprPropertiesNaborSostavImpl::OpenElement(__int64 id)
{
return Object->OpenElement(id);
}
//---------------------------------------------------------------
bool TDMSprPropertiesNaborSostavImpl::NewElement(__int64 id_nabor)
{
return Object->NewElement(id_nabor);
}
//---------------------------------------------------------------
bool TDMSprPropertiesNaborSostavImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprPropertiesNaborSostavImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
