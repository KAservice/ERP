#include <vcl.h>
#pragma hdrstop


#include "UDMSprPartImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprPartImpl::TDMSprPartImpl()           
{                                            
Object=new TDMSprPart(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprPartImpl::~TDMSprPartImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprPartImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprPartImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprPart)                        
   {                                                                     
   *ppv=static_cast<IDMSprPart*> (this);                                
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
int TDMSprPartImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprPartImpl::kanRelease(void)                                  
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
int  TDMSprPartImpl::get_CodeError(void)                      
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPartImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprPartImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprPartImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprPartImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TDMSprPartImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//---------------------------------------------------------------
int TDMSprPartImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//INameModulEdit->Text
TDataSource * TDMSprPartImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprPartImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPartImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprPartImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPartImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprPartImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_TablePRICEZPART(void)
{
return Object->TablePRICEZPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TablePRICEZPART(TFIBBCDField * TablePRICEZPART)
{
Object->TablePRICEZPART=TablePRICEZPART;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_TableKOLOSTNOM(void)
{
return Object->TableKOLOSTNOM;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableKOLOSTNOM(TFIBBCDField * TableKOLOSTNOM)
{
Object->TableKOLOSTNOM=TableKOLOSTNOM;
}
//---------------------------------------------------------------
TIntegerField * TDMSprPartImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_ElementPRICEZPART(void)
{
return Object->ElementPRICEZPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_ElementPRICEZPART(TFIBBCDField * ElementPRICEZPART)
{
Object->ElementPRICEZPART=ElementPRICEZPART;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprPartImpl::get_pFIBQ(void)
{
return Object->pFIBQ;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_pFIBQ(TpFIBQuery * pFIBQ)
{
Object->pFIBQ=pFIBQ;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_TableIDPART(void)
{
return Object->TableIDPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableIDPART(TFIBBCDField * TableIDPART)
{
Object->TableIDPART=TableIDPART;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_TableIDKLPART(void)
{
return Object->TableIDKLPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableIDKLPART(TFIBBCDField * TableIDKLPART)
{
Object->TableIDKLPART=TableIDKLPART;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_TableIDFIRMPART(void)
{
return Object->TableIDFIRMPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableIDFIRMPART(TFIBBCDField * TableIDFIRMPART)
{
Object->TableIDFIRMPART=TableIDFIRMPART;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_TableIDNOMPART(void)
{
return Object->TableIDNOMPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableIDNOMPART(TFIBBCDField * TableIDNOMPART)
{
Object->TableIDNOMPART=TableIDNOMPART;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_ElementIDKLPART(void)
{
return Object->ElementIDKLPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_ElementIDKLPART(TFIBBCDField * ElementIDKLPART)
{
Object->ElementIDKLPART=ElementIDKLPART;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_ElementIDFIRMPART(void)
{
return Object->ElementIDFIRMPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_ElementIDFIRMPART(TFIBBCDField * ElementIDFIRMPART)
{
Object->ElementIDFIRMPART=ElementIDFIRMPART;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_ElementIDNOMPART(void)
{
return Object->ElementIDNOMPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_ElementIDNOMPART(TFIBBCDField * ElementIDNOMPART)
{
Object->ElementIDNOMPART=ElementIDNOMPART;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_TableIDDOCPART(void)
{
return Object->TableIDDOCPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableIDDOCPART(TFIBBCDField * TableIDDOCPART)
{
Object->TableIDDOCPART=TableIDDOCPART;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_ElementIDDOCPART(void)
{
return Object->ElementIDDOCPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_ElementIDDOCPART(TFIBBCDField * ElementIDDOCPART)
{
Object->ElementIDDOCPART=ElementIDDOCPART;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_ElementIDPART(void)
{
return Object->ElementIDPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_ElementIDPART(TFIBBCDField * ElementIDPART)
{
Object->ElementIDPART=ElementIDPART;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprPartImpl::get_TableSRGODNPART(void)
{
return Object->TableSRGODNPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableSRGODNPART(TFIBDateTimeField * TableSRGODNPART)
{
Object->TableSRGODNPART=TableSRGODNPART;
}
//---------------------------------------------------------------
TFIBDateTimeField * TDMSprPartImpl::get_ElementSRGODNPART(void)
{
return Object->ElementSRGODNPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_ElementSRGODNPART(TFIBDateTimeField * ElementSRGODNPART)
{
Object->ElementSRGODNPART=ElementSRGODNPART;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprPartImpl::get_TableCODEPART(void)
{
return Object->TableCODEPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableCODEPART(TFIBIntegerField * TableCODEPART)
{
Object->TableCODEPART=TableCODEPART;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPartImpl::get_TableDOCPART(void)
{
return Object->TableDOCPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableDOCPART(TFIBWideStringField * TableDOCPART)
{
Object->TableDOCPART=TableDOCPART;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPartImpl::get_TableGTDPART(void)
{
return Object->TableGTDPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableGTDPART(TFIBWideStringField * TableGTDPART)
{
Object->TableGTDPART=TableGTDPART;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPartImpl::get_TableSERTPART(void)
{
return Object->TableSERTPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableSERTPART(TFIBWideStringField * TableSERTPART)
{
Object->TableSERTPART=TableSERTPART;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPartImpl::get_TableGID_SPART(void)
{
return Object->TableGID_SPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableGID_SPART(TFIBWideStringField * TableGID_SPART)
{
Object->TableGID_SPART=TableGID_SPART;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_TableIDBASE_SPART(void)
{
return Object->TableIDBASE_SPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableIDBASE_SPART(TFIBBCDField * TableIDBASE_SPART)
{
Object->TableIDBASE_SPART=TableIDBASE_SPART;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_TableIDEXT_DOUT_SPART(void)
{
return Object->TableIDEXT_DOUT_SPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableIDEXT_DOUT_SPART(TFIBBCDField * TableIDEXT_DOUT_SPART)
{
Object->TableIDEXT_DOUT_SPART=TableIDEXT_DOUT_SPART;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_TableIDEXT_BASE_SPART(void)
{
return Object->TableIDEXT_BASE_SPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableIDEXT_BASE_SPART(TFIBBCDField * TableIDEXT_BASE_SPART)
{
Object->TableIDEXT_BASE_SPART=TableIDEXT_BASE_SPART;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPartImpl::get_TableNAMEFIRM(void)
{
return Object->TableNAMEFIRM;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableNAMEFIRM(TFIBWideStringField * TableNAMEFIRM)
{
Object->TableNAMEFIRM=TableNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPartImpl::get_TableNAMEKLIENT(void)
{
return Object->TableNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_TableNAMEKLIENT(TFIBWideStringField * TableNAMEKLIENT)
{
Object->TableNAMEKLIENT=TableNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprPartImpl::get_ElementCODEPART(void)
{
return Object->ElementCODEPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_ElementCODEPART(TFIBIntegerField * ElementCODEPART)
{
Object->ElementCODEPART=ElementCODEPART;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPartImpl::get_ElementDOCPART(void)
{
return Object->ElementDOCPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_ElementDOCPART(TFIBWideStringField * ElementDOCPART)
{
Object->ElementDOCPART=ElementDOCPART;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPartImpl::get_ElementGTDPART(void)
{
return Object->ElementGTDPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_ElementGTDPART(TFIBWideStringField * ElementGTDPART)
{
Object->ElementGTDPART=ElementGTDPART;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPartImpl::get_ElementGID_SPART(void)
{
return Object->ElementGID_SPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_ElementGID_SPART(TFIBWideStringField * ElementGID_SPART)
{
Object->ElementGID_SPART=ElementGID_SPART;
}
//---------------------------------------------------------------
TFIBBCDField * TDMSprPartImpl::get_ElementIDBASE_SPART(void)
{
return Object->ElementIDBASE_SPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_ElementIDBASE_SPART(TFIBBCDField * ElementIDBASE_SPART)
{
Object->ElementIDBASE_SPART=ElementIDBASE_SPART;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPartImpl::get_ElementNAMEKLIENT(void)
{
return Object->ElementNAMEKLIENT;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_ElementNAMEKLIENT(TFIBWideStringField * ElementNAMEKLIENT)
{
Object->ElementNAMEKLIENT=ElementNAMEKLIENT;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPartImpl::get_ElementNAMENOM(void)
{
return Object->ElementNAMENOM;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_ElementNAMENOM(TFIBWideStringField * ElementNAMENOM)
{
Object->ElementNAMENOM=ElementNAMENOM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPartImpl::get_ElementNAMEFIRM(void)
{
return Object->ElementNAMEFIRM;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_ElementNAMEFIRM(TFIBWideStringField * ElementNAMEFIRM)
{
Object->ElementNAMEFIRM=ElementNAMEFIRM;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprPartImpl::get_ElementSERTPART(void)
{
return Object->ElementSERTPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::set_ElementSERTPART(TFIBWideStringField * ElementSERTPART)
{
Object->ElementSERTPART=ElementSERTPART;
}
//---------------------------------------------------------------
void TDMSprPartImpl::OpenTable(__int64 IdNom)
{
return Object->OpenTable(IdNom);
}
//---------------------------------------------------------------
int TDMSprPartImpl::OpenElement(__int64 Id)
{
return Object->OpenElement(Id);
}
//---------------------------------------------------------------
void TDMSprPartImpl::NewElement(__int64 IdNom)
{
return Object->NewElement(IdNom);
}
//---------------------------------------------------------------
bool TDMSprPartImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
void TDMSprPartImpl::DeleteElement(__int64 Id)
{
return Object->DeleteElement( Id);
}
//---------------------------------------------------------------
