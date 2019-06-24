#include "vcl.h"
#pragma hdrstop


#include "UDMSprNomImageImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprNomImageImpl::TDMSprNomImageImpl()           
{                                            
Object=new TDMSprNomImage(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprNomImageImpl::~TDMSprNomImageImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprNomImageImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprNomImageImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprNomImage)                        
   {                                                                     
   *ppv=static_cast<IDMSprNomImage*> (this);                                
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
int TDMSprNomImageImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprNomImageImpl::kanRelease(void)                                  
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
int  TDMSprNomImageImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprNomImageImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprNomImageImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprNomImageImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprNomImageImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprNomImage
TDataSource * TDMSprNomImageImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprNomImageImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomImageImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprNomImageImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNomImageImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprNomImageImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImageImpl::get_TableID_SNOMIMAGE(void)
{
return Object->TableID_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_TableID_SNOMIMAGE(TFIBLargeIntField * TableID_SNOMIMAGE)
{
Object->TableID_SNOMIMAGE=TableID_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImageImpl::get_TableIDBASE_SNOMIMAGE(void)
{
return Object->TableIDBASE_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_TableIDBASE_SNOMIMAGE(TFIBLargeIntField * TableIDBASE_SNOMIMAGE)
{
Object->TableIDBASE_SNOMIMAGE=TableIDBASE_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImageImpl::get_TableGID_SNOMIMAGE(void)
{
return Object->TableGID_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_TableGID_SNOMIMAGE(TFIBWideStringField * TableGID_SNOMIMAGE)
{
Object->TableGID_SNOMIMAGE=TableGID_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImageImpl::get_TableIDVIDIMAGE_SNOMIMAGE(void)
{
return Object->TableIDVIDIMAGE_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_TableIDVIDIMAGE_SNOMIMAGE(TFIBLargeIntField * TableIDVIDIMAGE_SNOMIMAGE)
{
Object->TableIDVIDIMAGE_SNOMIMAGE=TableIDVIDIMAGE_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImageImpl::get_TableIDNOM_SNOMIMAGE(void)
{
return Object->TableIDNOM_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_TableIDNOM_SNOMIMAGE(TFIBLargeIntField * TableIDNOM_SNOMIMAGE)
{
Object->TableIDNOM_SNOMIMAGE=TableIDNOM_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImageImpl::get_TableNAME_SNOMIMAGE(void)
{
return Object->TableNAME_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_TableNAME_SNOMIMAGE(TFIBWideStringField * TableNAME_SNOMIMAGE)
{
Object->TableNAME_SNOMIMAGE=TableNAME_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBBlobField * TDMSprNomImageImpl::get_TableBODY_SNOMIMAGE(void)
{
return Object->TableBODY_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_TableBODY_SNOMIMAGE(TFIBBlobField * TableBODY_SNOMIMAGE)
{
Object->TableBODY_SNOMIMAGE=TableBODY_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBBlobField * TDMSprNomImageImpl::get_TableBODY_SMALL_SNOMIMAGE(void)
{
return Object->TableBODY_SMALL_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_TableBODY_SMALL_SNOMIMAGE(TFIBBlobField * TableBODY_SMALL_SNOMIMAGE)
{
Object->TableBODY_SMALL_SNOMIMAGE=TableBODY_SMALL_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImageImpl::get_ElementID_SNOMIMAGE(void)
{
return Object->ElementID_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_ElementID_SNOMIMAGE(TFIBLargeIntField * ElementID_SNOMIMAGE)
{
Object->ElementID_SNOMIMAGE=ElementID_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImageImpl::get_ElementIDBASE_SNOMIMAGE(void)
{
return Object->ElementIDBASE_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_ElementIDBASE_SNOMIMAGE(TFIBLargeIntField * ElementIDBASE_SNOMIMAGE)
{
Object->ElementIDBASE_SNOMIMAGE=ElementIDBASE_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImageImpl::get_ElementGID_SNOMIMAGE(void)
{
return Object->ElementGID_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_ElementGID_SNOMIMAGE(TFIBWideStringField * ElementGID_SNOMIMAGE)
{
Object->ElementGID_SNOMIMAGE=ElementGID_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImageImpl::get_ElementIDVIDIMAGE_SNOMIMAGE(void)
{
return Object->ElementIDVIDIMAGE_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_ElementIDVIDIMAGE_SNOMIMAGE(TFIBLargeIntField * ElementIDVIDIMAGE_SNOMIMAGE)
{
Object->ElementIDVIDIMAGE_SNOMIMAGE=ElementIDVIDIMAGE_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprNomImageImpl::get_ElementIDNOM_SNOMIMAGE(void)
{
return Object->ElementIDNOM_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_ElementIDNOM_SNOMIMAGE(TFIBLargeIntField * ElementIDNOM_SNOMIMAGE)
{
Object->ElementIDNOM_SNOMIMAGE=ElementIDNOM_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImageImpl::get_ElementNAME_SNOMIMAGE(void)
{
return Object->ElementNAME_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_ElementNAME_SNOMIMAGE(TFIBWideStringField * ElementNAME_SNOMIMAGE)
{
Object->ElementNAME_SNOMIMAGE=ElementNAME_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBBlobField * TDMSprNomImageImpl::get_ElementBODY_SNOMIMAGE(void)
{
return Object->ElementBODY_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_ElementBODY_SNOMIMAGE(TFIBBlobField * ElementBODY_SNOMIMAGE)
{
Object->ElementBODY_SNOMIMAGE=ElementBODY_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBBlobField * TDMSprNomImageImpl::get_ElementBODY_SMALL_SNOMIMAGE(void)
{
return Object->ElementBODY_SMALL_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_ElementBODY_SMALL_SNOMIMAGE(TFIBBlobField * ElementBODY_SMALL_SNOMIMAGE)
{
Object->ElementBODY_SMALL_SNOMIMAGE=ElementBODY_SMALL_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImageImpl::get_TableNAME_SVIDIMAGE(void)
{
return Object->TableNAME_SVIDIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_TableNAME_SVIDIMAGE(TFIBWideStringField * TableNAME_SVIDIMAGE)
{
Object->TableNAME_SVIDIMAGE=TableNAME_SVIDIMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprNomImageImpl::get_ElementNAME_SVIDIMAGE(void)
{
return Object->ElementNAME_SVIDIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_ElementNAME_SVIDIMAGE(TFIBWideStringField * ElementNAME_SVIDIMAGE)
{
Object->ElementNAME_SVIDIMAGE=ElementNAME_SVIDIMAGE;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomImageImpl::get_TableINDEX_SNOMIMAGE(void)
{
return Object->TableINDEX_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_TableINDEX_SNOMIMAGE(TFIBIntegerField * TableINDEX_SNOMIMAGE)
{
Object->TableINDEX_SNOMIMAGE=TableINDEX_SNOMIMAGE;
}
//---------------------------------------------------------------
TFIBIntegerField * TDMSprNomImageImpl::get_ElementINDEX_SNOMIMAGE(void)
{
return Object->ElementINDEX_SNOMIMAGE;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_ElementINDEX_SNOMIMAGE(TFIBIntegerField * ElementINDEX_SNOMIMAGE)
{
Object->ElementINDEX_SNOMIMAGE=ElementINDEX_SNOMIMAGE;
}
//---------------------------------------------------------------
__int64 TDMSprNomImageImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprNomImageImpl::OpenTable(__int64 id_nom)
{
return Object->OpenTable(id_nom);
}
//---------------------------------------------------------------
int TDMSprNomImageImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMSprNomImageImpl::NewElement(__int64 id_nom)
{
return Object->NewElement(id_nom);
}
//---------------------------------------------------------------
bool TDMSprNomImageImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprNomImageImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
