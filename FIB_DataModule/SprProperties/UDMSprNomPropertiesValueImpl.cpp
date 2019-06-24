#include "vcl.h"
#pragma hdrstop


#include "UDMSprNomPropertiesValueImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprNomPropertiesValueImpl::TDMSprNomPropertiesValueImpl()           
{                                            
Object=new TDMSprNomPropertiesValue(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprNomPropertiesValueImpl::~TDMSprNomPropertiesValueImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprNomPropertiesValueImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprNomPropertiesValue)                        
   {                                                                     
   *ppv=static_cast<IDMSprNomPropertiesValue*> (this);                                
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
int TDMSprNomPropertiesValueImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprNomPropertiesValueImpl::kanRelease(void)                                  
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
int  TDMSprNomPropertiesValueImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprNomPropertiesValueImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprNomPropertiesValueImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprNomPropertiesValueImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprNomPropertiesValueImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprNomPropertiesValue
TDataSource * TDMSprNomPropertiesValueImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomPropertiesValueImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNomPropertiesValueImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNomPropertiesValueImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomPropertiesValueImpl::get_TableID_SNOMPROPVALUE(void)
{
return Object->TableID_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableID_SNOMPROPVALUE(TFIBLargeIntField * TableID_SNOMPROPVALUE)
{
Object->TableID_SNOMPROPVALUE=TableID_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomPropertiesValueImpl::get_TableIDBASE_SNOMPROPVALUE(void)
{
return Object->TableIDBASE_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableIDBASE_SNOMPROPVALUE(TFIBLargeIntField * TableIDBASE_SNOMPROPVALUE)
{
Object->TableIDBASE_SNOMPROPVALUE=TableIDBASE_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomPropertiesValueImpl::get_TableGID_SNOMPROPVALUE(void)
{
return Object->TableGID_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableGID_SNOMPROPVALUE(TFIBWideStringField * TableGID_SNOMPROPVALUE)
{
Object->TableGID_SNOMPROPVALUE=TableGID_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomPropertiesValueImpl::get_TableIDNOM_SNOMPROPVALUE(void)
{
return Object->TableIDNOM_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableIDNOM_SNOMPROPVALUE(TFIBLargeIntField * TableIDNOM_SNOMPROPVALUE)
{
Object->TableIDNOM_SNOMPROPVALUE=TableIDNOM_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomPropertiesValueImpl::get_TableIDPROP_SNOMPROPVALUE(void)
{
return Object->TableIDPROP_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableIDPROP_SNOMPROPVALUE(TFIBLargeIntField * TableIDPROP_SNOMPROPVALUE)
{
Object->TableIDPROP_SNOMPROPVALUE=TableIDPROP_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomPropertiesValueImpl::get_TableIDPROPVALLIST_SNOMPROPVALUE(void)
{
return Object->TableIDPROPVALLIST_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableIDPROPVALLIST_SNOMPROPVALUE(TFIBLargeIntField * TableIDPROPVALLIST_SNOMPROPVALUE)
{
Object->TableIDPROPVALLIST_SNOMPROPVALUE=TableIDPROPVALLIST_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomPropertiesValueImpl::get_TableVALTEXT_SNOMPROPVALUE(void)
{
return Object->TableVALTEXT_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableVALTEXT_SNOMPROPVALUE(TFIBWideStringField * TableVALTEXT_SNOMPROPVALUE)
{
Object->TableVALTEXT_SNOMPROPVALUE=TableVALTEXT_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomPropertiesValueImpl::get_TableNAME_SPROP(void)
{
return Object->TableNAME_SPROP;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableNAME_SPROP(TFIBWideStringField * TableNAME_SPROP)
{
Object->TableNAME_SPROP=TableNAME_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomPropertiesValueImpl::get_TableNAME_SPROPVALUELIST(void)
{
return Object->TableNAME_SPROPVALUELIST;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableNAME_SPROPVALUELIST(TFIBWideStringField * TableNAME_SPROPVALUELIST)
{
Object->TableNAME_SPROPVALUELIST=TableNAME_SPROPVALUELIST;
}
//---------------------------------------------------------------
TDataSource * TDMSprNomPropertiesValueImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomPropertiesValueImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomPropertiesValueImpl::get_ElementID_SNOMPROPVALUE(void)
{
return Object->ElementID_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_ElementID_SNOMPROPVALUE(TFIBLargeIntField * ElementID_SNOMPROPVALUE)
{
Object->ElementID_SNOMPROPVALUE=ElementID_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomPropertiesValueImpl::get_ElementIDBASE_SNOMPROPVALUE(void)
{
return Object->ElementIDBASE_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_ElementIDBASE_SNOMPROPVALUE(TFIBLargeIntField * ElementIDBASE_SNOMPROPVALUE)
{
Object->ElementIDBASE_SNOMPROPVALUE=ElementIDBASE_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomPropertiesValueImpl::get_ElementGID_SNOMPROPVALUE(void)
{
return Object->ElementGID_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_ElementGID_SNOMPROPVALUE(TFIBWideStringField * ElementGID_SNOMPROPVALUE)
{
Object->ElementGID_SNOMPROPVALUE=ElementGID_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomPropertiesValueImpl::get_ElementIDNOM_SNOMPROPVALUE(void)
{
return Object->ElementIDNOM_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_ElementIDNOM_SNOMPROPVALUE(TFIBLargeIntField * ElementIDNOM_SNOMPROPVALUE)
{
Object->ElementIDNOM_SNOMPROPVALUE=ElementIDNOM_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomPropertiesValueImpl::get_ElementIDPROP_SNOMPROPVALUE(void)
{
return Object->ElementIDPROP_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_ElementIDPROP_SNOMPROPVALUE(TFIBLargeIntField * ElementIDPROP_SNOMPROPVALUE)
{
Object->ElementIDPROP_SNOMPROPVALUE=ElementIDPROP_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomPropertiesValueImpl::get_ElementIDPROPVALLIST_SNOMPROPVALUE(void)
{
return Object->ElementIDPROPVALLIST_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_ElementIDPROPVALLIST_SNOMPROPVALUE(TFIBLargeIntField * ElementIDPROPVALLIST_SNOMPROPVALUE)
{
Object->ElementIDPROPVALLIST_SNOMPROPVALUE=ElementIDPROPVALLIST_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomPropertiesValueImpl::get_ElementVALTEXT_SNOMPROPVALUE(void)
{
return Object->ElementVALTEXT_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_ElementVALTEXT_SNOMPROPVALUE(TFIBWideStringField * ElementVALTEXT_SNOMPROPVALUE)
{
Object->ElementVALTEXT_SNOMPROPVALUE=ElementVALTEXT_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomPropertiesValueImpl::get_ElementNAME_SPROP(void)
{
return Object->ElementNAME_SPROP;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_ElementNAME_SPROP(TFIBWideStringField * ElementNAME_SPROP)
{
Object->ElementNAME_SPROP=ElementNAME_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomPropertiesValueImpl::get_ElementNAME_SPROPVALUELIST(void)
{
return Object->ElementNAME_SPROPVALUELIST;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_ElementNAME_SPROPVALUELIST(TFIBWideStringField * ElementNAME_SPROPVALUELIST)
{
Object->ElementNAME_SPROPVALUELIST=ElementNAME_SPROPVALUELIST;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomPropertiesValueImpl::get_TableINDEX_SNOMPROPVALUE(void)
{
return Object->TableINDEX_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableINDEX_SNOMPROPVALUE(TFIBIntegerField * TableINDEX_SNOMPROPVALUE)
{
Object->TableINDEX_SNOMPROPVALUE=TableINDEX_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomPropertiesValueImpl::get_ElementINDEX_SNOMPROPVALUE(void)
{
return Object->ElementINDEX_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_ElementINDEX_SNOMPROPVALUE(TFIBIntegerField * ElementINDEX_SNOMPROPVALUE)
{
Object->ElementINDEX_SNOMPROPVALUE=ElementINDEX_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomPropertiesValueImpl::get_TableNAME_FOR_PRINT_SPROP(void)
{
return Object->TableNAME_FOR_PRINT_SPROP;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableNAME_FOR_PRINT_SPROP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP)
{
Object->TableNAME_FOR_PRINT_SPROP=TableNAME_FOR_PRINT_SPROP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomPropertiesValueImpl::get_TableNAME_SPROP_GRP(void)
{
return Object->TableNAME_SPROP_GRP;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableNAME_SPROP_GRP(TFIBWideStringField * TableNAME_SPROP_GRP)
{
Object->TableNAME_SPROP_GRP=TableNAME_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomPropertiesValueImpl::get_TableNAME_FOR_PRINT_SPROP_GRP(void)
{
return Object->TableNAME_FOR_PRINT_SPROP_GRP;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableNAME_FOR_PRINT_SPROP_GRP(TFIBWideStringField * TableNAME_FOR_PRINT_SPROP_GRP)
{
Object->TableNAME_FOR_PRINT_SPROP_GRP=TableNAME_FOR_PRINT_SPROP_GRP;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomPropertiesValueImpl::get_TableADD1_SNOMPROPVALUE(void)
{
return Object->TableADD1_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableADD1_SNOMPROPVALUE(TFIBSmallIntField * TableADD1_SNOMPROPVALUE)
{
Object->TableADD1_SNOMPROPVALUE=TableADD1_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomPropertiesValueImpl::get_TableADD2_SNOMPROPVALUE(void)
{
return Object->TableADD2_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableADD2_SNOMPROPVALUE(TFIBSmallIntField * TableADD2_SNOMPROPVALUE)
{
Object->TableADD2_SNOMPROPVALUE=TableADD2_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomPropertiesValueImpl::get_TableADD3_SNOMPROPVALUE(void)
{
return Object->TableADD3_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableADD3_SNOMPROPVALUE(TFIBSmallIntField * TableADD3_SNOMPROPVALUE)
{
Object->TableADD3_SNOMPROPVALUE=TableADD3_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomPropertiesValueImpl::get_TableADD4_SNOMPROPVALUE(void)
{
return Object->TableADD4_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableADD4_SNOMPROPVALUE(TFIBSmallIntField * TableADD4_SNOMPROPVALUE)
{
Object->TableADD4_SNOMPROPVALUE=TableADD4_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomPropertiesValueImpl::get_TableADD5_SNOMPROPVALUE(void)
{
return Object->TableADD5_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_TableADD5_SNOMPROPVALUE(TFIBSmallIntField * TableADD5_SNOMPROPVALUE)
{
Object->TableADD5_SNOMPROPVALUE=TableADD5_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomPropertiesValueImpl::get_ElementADD1_SNOMPROPVALUE(void)
{
return Object->ElementADD1_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_ElementADD1_SNOMPROPVALUE(TFIBSmallIntField * ElementADD1_SNOMPROPVALUE)
{
Object->ElementADD1_SNOMPROPVALUE=ElementADD1_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomPropertiesValueImpl::get_ElementADD2_SNOMPROPVALUE(void)
{
return Object->ElementADD2_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_ElementADD2_SNOMPROPVALUE(TFIBSmallIntField * ElementADD2_SNOMPROPVALUE)
{
Object->ElementADD2_SNOMPROPVALUE=ElementADD2_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomPropertiesValueImpl::get_ElementADD3_SNOMPROPVALUE(void)
{
return Object->ElementADD3_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_ElementADD3_SNOMPROPVALUE(TFIBSmallIntField * ElementADD3_SNOMPROPVALUE)
{
Object->ElementADD3_SNOMPROPVALUE=ElementADD3_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomPropertiesValueImpl::get_ElementADD4_SNOMPROPVALUE(void)
{
return Object->ElementADD4_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_ElementADD4_SNOMPROPVALUE(TFIBSmallIntField * ElementADD4_SNOMPROPVALUE)
{
Object->ElementADD4_SNOMPROPVALUE=ElementADD4_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TDMSprNomPropertiesValueImpl::get_ElementADD5_SNOMPROPVALUE(void)
{
return Object->ElementADD5_SNOMPROPVALUE;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_ElementADD5_SNOMPROPVALUE(TFIBSmallIntField * ElementADD5_SNOMPROPVALUE)
{
Object->ElementADD5_SNOMPROPVALUE=ElementADD5_SNOMPROPVALUE;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprNomPropertiesValueImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
__int64 TDMSprNomPropertiesValueImpl::get_IdNom(void)
{
return Object->IdNom;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_IdNom(__int64 IdNom)
{
Object->IdNom=IdNom;
}
//---------------------------------------------------------------
__int64 TDMSprNomPropertiesValueImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprNomPropertiesValueImpl::OpenTable(__int64 id_nom)
{
return Object->OpenTable(id_nom);
}
//---------------------------------------------------------------
bool TDMSprNomPropertiesValueImpl::NewElement(__int64 id_nom)
{
return Object->NewElement(id_nom);
}
//---------------------------------------------------------------
int TDMSprNomPropertiesValueImpl::OpenElement(__int64 id )
{
return Object->OpenElement( id );
}
//---------------------------------------------------------------
bool TDMSprNomPropertiesValueImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprNomPropertiesValueImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
__int64 TDMSprNomPropertiesValueImpl::GetIdPoIdNomIdProp(__int64 id_nom, __int64 id_prop)
{
return Object->GetIdPoIdNomIdProp(id_nom,id_prop);
}
//---------------------------------------------------------------
