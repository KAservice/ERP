#include <vcl.h>
#pragma hdrstop


#include "UDMSprPodrImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprPodrImpl::TDMSprPodrImpl()           
{                                            
Object=new TDMSprPodr(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprPodrImpl::~TDMSprPodrImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprPodrImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprPodrImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprPodr)                        
   {                                                                     
   *ppv=static_cast<IDMSprPodr*> (this);                                
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
int TDMSprPodrImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprPodrImpl::kanRelease(void)                                  
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
int  TDMSprPodrImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPodrImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprPodrImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPodrImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprPodrImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprPodrImpl::Done(void)
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprPodrImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprPodrImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPodrImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPodrImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPodrImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPodrImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprPodrImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPodrImpl::get_TableIDPOD(void)
{
return Object->TableIDPOD;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_TableIDPOD(TFIBBCDField * TableIDPOD)
{
Object->TableIDPOD=TableIDPOD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPodrImpl::get_TableIDTPRICEPOD(void)
{
return Object->TableIDTPRICEPOD;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_TableIDTPRICEPOD(TFIBBCDField * TableIDTPRICEPOD)
{
Object->TableIDTPRICEPOD=TableIDTPRICEPOD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPodrImpl::get_ElementIDPOD(void)
{
return Object->ElementIDPOD;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_ElementIDPOD(TFIBBCDField * ElementIDPOD)
{
Object->ElementIDPOD=ElementIDPOD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPodrImpl::get_ElementIDTPRICEPOD(void)
{
return Object->ElementIDTPRICEPOD;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_ElementIDTPRICEPOD(TFIBBCDField * ElementIDTPRICEPOD)
{
Object->ElementIDTPRICEPOD=ElementIDTPRICEPOD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPodrImpl::get_TableNAMEPOD(void)
{
return Object->TableNAMEPOD;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_TableNAMEPOD(TFIBWideStringField * TableNAMEPOD)
{
Object->TableNAMEPOD=TableNAMEPOD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPodrImpl::get_TableGID_SPOD(void)
{
return Object->TableGID_SPOD;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_TableGID_SPOD(TFIBWideStringField * TableGID_SPOD)
{
Object->TableGID_SPOD=TableGID_SPOD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPodrImpl::get_TableIDBASE_SPOD(void)
{
return Object->TableIDBASE_SPOD;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_TableIDBASE_SPOD(TFIBBCDField * TableIDBASE_SPOD)
{
Object->TableIDBASE_SPOD=TableIDBASE_SPOD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPodrImpl::get_TableNAME_TPRICE(void)
{
return Object->TableNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_TableNAME_TPRICE(TFIBWideStringField * TableNAME_TPRICE)
{
Object->TableNAME_TPRICE=TableNAME_TPRICE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPodrImpl::get_ElementNAMEPOD(void)
{
return Object->ElementNAMEPOD;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_ElementNAMEPOD(TFIBWideStringField * ElementNAMEPOD)
{
Object->ElementNAMEPOD=ElementNAMEPOD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPodrImpl::get_ElementGID_SPOD(void)
{
return Object->ElementGID_SPOD;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_ElementGID_SPOD(TFIBWideStringField * ElementGID_SPOD)
{
Object->ElementGID_SPOD=ElementGID_SPOD;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPodrImpl::get_ElementIDBASE_SPOD(void)
{
return Object->ElementIDBASE_SPOD;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_ElementIDBASE_SPOD(TFIBBCDField * ElementIDBASE_SPOD)
{
Object->ElementIDBASE_SPOD=ElementIDBASE_SPOD;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPodrImpl::get_ElementNAME_TPRICE(void)
{
return Object->ElementNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::set_ElementNAME_TPRICE(TFIBWideStringField * ElementNAME_TPRICE)
{
Object->ElementNAME_TPRICE=ElementNAME_TPRICE;
}
//---------------------------------------------------------------
void TDMSprPodrImpl::OpenTable(void)
{
return Object->OpenTable();
}
//---------------------------------------------------------------
int TDMSprPodrImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprPodrImpl::NewElement(void)
{
return Object->NewElement();
}
//---------------------------------------------------------------
bool TDMSprPodrImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprPodrImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement(Id);
}
//---------------------------------------------------------------
