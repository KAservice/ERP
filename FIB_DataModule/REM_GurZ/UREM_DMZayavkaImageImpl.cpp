#include "vcl.h"
#pragma hdrstop


#include "UREM_DMZayavkaImageImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TREM_DMZayavkaImageImpl::TREM_DMZayavkaImageImpl()           
{                                            
Object=new TREM_DMZayavkaImage(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TREM_DMZayavkaImageImpl::~TREM_DMZayavkaImageImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TREM_DMZayavkaImageImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IREM_DMZayavkaImage)                        
   {                                                                     
   *ppv=static_cast<IREM_DMZayavkaImage*> (this);                                
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
int TREM_DMZayavkaImageImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TREM_DMZayavkaImageImpl::kanRelease(void)                                  
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
int  TREM_DMZayavkaImageImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TREM_DMZayavkaImageImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TREM_DMZayavkaImageImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TREM_DMZayavkaImageImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TREM_DMZayavkaImageImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IREM_DMZayavkaImage
TDataSource * TREM_DMZayavkaImageImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TREM_DMZayavkaImageImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMZayavkaImageImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TREM_DMZayavkaImageImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMZayavkaImageImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TREM_DMZayavkaImageImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImageImpl::get_TableID_REM_ZIMAGE(void)
{
return Object->TableID_REM_ZIMAGE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_TableID_REM_ZIMAGE(TFIBLargeIntField * TableID_REM_ZIMAGE)
{
Object->TableID_REM_ZIMAGE=TableID_REM_ZIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImageImpl::get_TableIDBASE_REM_ZIMAGE(void)
{
return Object->TableIDBASE_REM_ZIMAGE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_TableIDBASE_REM_ZIMAGE(TFIBLargeIntField * TableIDBASE_REM_ZIMAGE)
{
Object->TableIDBASE_REM_ZIMAGE=TableIDBASE_REM_ZIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImageImpl::get_TableIDZ_REM_ZIMAGE(void)
{
return Object->TableIDZ_REM_ZIMAGE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_TableIDZ_REM_ZIMAGE(TFIBLargeIntField * TableIDZ_REM_ZIMAGE)
{
Object->TableIDZ_REM_ZIMAGE=TableIDZ_REM_ZIMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImageImpl::get_TableNAME_REM_ZIMAGE(void)
{
return Object->TableNAME_REM_ZIMAGE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_TableNAME_REM_ZIMAGE(TFIBWideStringField * TableNAME_REM_ZIMAGE)
{
Object->TableNAME_REM_ZIMAGE=TableNAME_REM_ZIMAGE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImageImpl::get_TableSHOWUSER_REM_ZIMAGE(void)
{
return Object->TableSHOWUSER_REM_ZIMAGE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_TableSHOWUSER_REM_ZIMAGE(TFIBSmallIntField * TableSHOWUSER_REM_ZIMAGE)
{
Object->TableSHOWUSER_REM_ZIMAGE=TableSHOWUSER_REM_ZIMAGE;
}
//---------------------------------------------------------------
TFIBBlobField * TREM_DMZayavkaImageImpl::get_TableIMAGE_REM_ZIMAGE(void)
{
return Object->TableIMAGE_REM_ZIMAGE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_TableIMAGE_REM_ZIMAGE(TFIBBlobField * TableIMAGE_REM_ZIMAGE)
{
Object->TableIMAGE_REM_ZIMAGE=TableIMAGE_REM_ZIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImageImpl::get_ElementID_REM_ZIMAGE(void)
{
return Object->ElementID_REM_ZIMAGE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_ElementID_REM_ZIMAGE(TFIBLargeIntField * ElementID_REM_ZIMAGE)
{
Object->ElementID_REM_ZIMAGE=ElementID_REM_ZIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImageImpl::get_ElementIDBASE_REM_ZIMAGE(void)
{
return Object->ElementIDBASE_REM_ZIMAGE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_ElementIDBASE_REM_ZIMAGE(TFIBLargeIntField * ElementIDBASE_REM_ZIMAGE)
{
Object->ElementIDBASE_REM_ZIMAGE=ElementIDBASE_REM_ZIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TREM_DMZayavkaImageImpl::get_ElementIDZ_REM_ZIMAGE(void)
{
return Object->ElementIDZ_REM_ZIMAGE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_ElementIDZ_REM_ZIMAGE(TFIBLargeIntField * ElementIDZ_REM_ZIMAGE)
{
Object->ElementIDZ_REM_ZIMAGE=ElementIDZ_REM_ZIMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * TREM_DMZayavkaImageImpl::get_ElementNAME_REM_ZIMAGE(void)
{
return Object->ElementNAME_REM_ZIMAGE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_ElementNAME_REM_ZIMAGE(TFIBWideStringField * ElementNAME_REM_ZIMAGE)
{
Object->ElementNAME_REM_ZIMAGE=ElementNAME_REM_ZIMAGE;
}
//---------------------------------------------------------------
TFIBSmallIntField * TREM_DMZayavkaImageImpl::get_ElementSHOWUSER_REM_ZIMAGE(void)
{
return Object->ElementSHOWUSER_REM_ZIMAGE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_ElementSHOWUSER_REM_ZIMAGE(TFIBSmallIntField * ElementSHOWUSER_REM_ZIMAGE)
{
Object->ElementSHOWUSER_REM_ZIMAGE=ElementSHOWUSER_REM_ZIMAGE;
}
//---------------------------------------------------------------
TFIBBlobField * TREM_DMZayavkaImageImpl::get_ElementIMAGE_REM_ZIMAGE(void)
{
return Object->ElementIMAGE_REM_ZIMAGE;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_ElementIMAGE_REM_ZIMAGE(TFIBBlobField * ElementIMAGE_REM_ZIMAGE)
{
Object->ElementIMAGE_REM_ZIMAGE=ElementIMAGE_REM_ZIMAGE;
}
//---------------------------------------------------------------
__int64 TREM_DMZayavkaImageImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TREM_DMZayavkaImageImpl::OpenTable(__int64 id_z)
{
return Object->OpenTable(id_z);
}
//---------------------------------------------------------------
int TREM_DMZayavkaImageImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TREM_DMZayavkaImageImpl::NewElement(__int64 id_z)
{
return Object->NewElement(id_z);
}
//---------------------------------------------------------------
bool TREM_DMZayavkaImageImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TREM_DMZayavkaImageImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
