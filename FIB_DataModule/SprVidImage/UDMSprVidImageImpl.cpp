#include "vcl.h"
#pragma hdrstop


#include "UDMSprVidImageImpl.h"
#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TDMSprVidImageImpl::TDMSprVidImageImpl()           
{                                            
Object=new TDMSprVidImage(Application);         
Object->FunctionDeleteImpl=DeleteImpl;       
NumRefs=0;                                   
++NumObject;                                 
flDeleteObject=true;                         
}                                            
//---------------------------------------------------------------
TDMSprVidImageImpl::~TDMSprVidImageImpl()          
{                                            
if (flDeleteObject==true)                    
	{                                           
	Object->flDeleteImpl=false;                 
	delete Object;                              
	}                                           
--NumObject;                                 
}                                            
//---------------------------------------------------------------
void TDMSprVidImageImpl::DeleteImpl(void) 
{                                                   
flDeleteObject=false;                               
delete this;                                        
}                                                   
//---------------------------------------------------------------
int TDMSprVidImageImpl::kanQueryInterface(REFIID id_interface, void ** ppv)  
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
else if (id_interface==IID_IDMSprVidImage)                        
   {                                                                     
   *ppv=static_cast<IDMSprVidImage*> (this);                                
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
int TDMSprVidImageImpl::kanAddRef(void)                                    
{                                                                       
return (++NumRefs);                                                     
}                                                                       
//---------------------------------------------------------------
int TDMSprVidImageImpl::kanRelease(void)                                  
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
int  TDMSprVidImageImpl::get_CodeError(void)            
{                                                              
return Object->CodeError;                                                      
}                                                              
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_CodeError(int CodeError)             
{                                                              
}                                                              
//---------------------------------------------------------------
UnicodeString  TDMSprVidImageImpl::get_TextError(void)            
{                                                              
return Object->TextError;                                      
}                                                              
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_TextError(UnicodeString  TextError)  
{                                                              
}                                                              
//---------------------------------------------------------------
int TDMSprVidImageImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object) 
{  															
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl); 
Object->ClsIdImpl=CLSID_TDMSprVidImageImpl;                  
Object->InterfaceMainObject=i_main_object;           
Object->InterfaceOwnerObject=i_owner_object;          
return Object->Init();                                         
}                                                              
//---------------------------------------------------------------
int TDMSprVidImageImpl::Done(void)                                
{                                                              
return Object->Done();                                                     
}                                                              
//---------------------------------------------------------------

//IDMSprVidImage
TDataSource * TDMSprVidImageImpl::get_DataSourceTable(void)
{
return Object->DataSourceTable;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_DataSourceTable(TDataSource * DataSourceTable)
{
Object->DataSourceTable=DataSourceTable;
}
//---------------------------------------------------------------
TDataSource * TDMSprVidImageImpl::get_DataSourceElement(void)
{
return Object->DataSourceElement;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_DataSourceElement(TDataSource * DataSourceElement)
{
Object->DataSourceElement=DataSourceElement;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprVidImageImpl::get_Table(void)
{
return Object->Table;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_Table(TpFIBDataSet * Table)
{
Object->Table=Table;
}
//---------------------------------------------------------------
TpFIBDataSet * TDMSprVidImageImpl::get_Element(void)
{
return Object->Element;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_Element(TpFIBDataSet * Element)
{
Object->Element=Element;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprVidImageImpl::get_IBTr(void)
{
return Object->IBTr;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_IBTr(TpFIBTransaction * IBTr)
{
Object->IBTr=IBTr;
}
//---------------------------------------------------------------
TpFIBTransaction * TDMSprVidImageImpl::get_IBTrUpdate(void)
{
return Object->IBTrUpdate;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_IBTrUpdate(TpFIBTransaction * IBTrUpdate)
{
Object->IBTrUpdate=IBTrUpdate;
}
//---------------------------------------------------------------
TIntegerField * TDMSprVidImageImpl::get_TableRECNO(void)
{
return Object->TableRECNO;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_TableRECNO(TIntegerField * TableRECNO)
{
Object->TableRECNO=TableRECNO;
}
//---------------------------------------------------------------
TpFIBQuery * TDMSprVidImageImpl::get_Query(void)
{
return Object->Query;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_Query(TpFIBQuery * Query)
{
Object->Query=Query;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprVidImageImpl::get_TableID_SVIDIMAGE(void)
{
return Object->TableID_SVIDIMAGE;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_TableID_SVIDIMAGE(TFIBLargeIntField * TableID_SVIDIMAGE)
{
Object->TableID_SVIDIMAGE=TableID_SVIDIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprVidImageImpl::get_TableIDBASE_SVIDIMAGE(void)
{
return Object->TableIDBASE_SVIDIMAGE;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_TableIDBASE_SVIDIMAGE(TFIBLargeIntField * TableIDBASE_SVIDIMAGE)
{
Object->TableIDBASE_SVIDIMAGE=TableIDBASE_SVIDIMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVidImageImpl::get_TableGID_SVIDIMAGE(void)
{
return Object->TableGID_SVIDIMAGE;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_TableGID_SVIDIMAGE(TFIBWideStringField * TableGID_SVIDIMAGE)
{
Object->TableGID_SVIDIMAGE=TableGID_SVIDIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprVidImageImpl::get_TableIDGRP_SVIDIMAGE(void)
{
return Object->TableIDGRP_SVIDIMAGE;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_TableIDGRP_SVIDIMAGE(TFIBLargeIntField * TableIDGRP_SVIDIMAGE)
{
Object->TableIDGRP_SVIDIMAGE=TableIDGRP_SVIDIMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVidImageImpl::get_TableNAME_SVIDIMAGE(void)
{
return Object->TableNAME_SVIDIMAGE;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_TableNAME_SVIDIMAGE(TFIBWideStringField * TableNAME_SVIDIMAGE)
{
Object->TableNAME_SVIDIMAGE=TableNAME_SVIDIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprVidImageImpl::get_ElementID_SVIDIMAGE(void)
{
return Object->ElementID_SVIDIMAGE;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_ElementID_SVIDIMAGE(TFIBLargeIntField * ElementID_SVIDIMAGE)
{
Object->ElementID_SVIDIMAGE=ElementID_SVIDIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprVidImageImpl::get_ElementIDBASE_SVIDIMAGE(void)
{
return Object->ElementIDBASE_SVIDIMAGE;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_ElementIDBASE_SVIDIMAGE(TFIBLargeIntField * ElementIDBASE_SVIDIMAGE)
{
Object->ElementIDBASE_SVIDIMAGE=ElementIDBASE_SVIDIMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVidImageImpl::get_ElementGID_SVIDIMAGE(void)
{
return Object->ElementGID_SVIDIMAGE;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_ElementGID_SVIDIMAGE(TFIBWideStringField * ElementGID_SVIDIMAGE)
{
Object->ElementGID_SVIDIMAGE=ElementGID_SVIDIMAGE;
}
//---------------------------------------------------------------
TFIBLargeIntField * TDMSprVidImageImpl::get_ElementIDGRP_SVIDIMAGE(void)
{
return Object->ElementIDGRP_SVIDIMAGE;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_ElementIDGRP_SVIDIMAGE(TFIBLargeIntField * ElementIDGRP_SVIDIMAGE)
{
Object->ElementIDGRP_SVIDIMAGE=ElementIDGRP_SVIDIMAGE;
}
//---------------------------------------------------------------
TFIBWideStringField * TDMSprVidImageImpl::get_ElementNAME_SVIDIMAGE(void)
{
return Object->ElementNAME_SVIDIMAGE;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_ElementNAME_SVIDIMAGE(TFIBWideStringField * ElementNAME_SVIDIMAGE)
{
Object->ElementNAME_SVIDIMAGE=ElementNAME_SVIDIMAGE;
}
//---------------------------------------------------------------
__int64 TDMSprVidImageImpl::get_IdGrp(void)
{
return Object->IdGrp;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_IdGrp(__int64 IdGrp)
{
Object->IdGrp=IdGrp;
}
//---------------------------------------------------------------
bool TDMSprVidImageImpl::get_AllElement(void)
{
return Object->AllElement;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_AllElement(bool AllElement)
{
Object->AllElement=AllElement;
}
//---------------------------------------------------------------
__int64 TDMSprVidImageImpl::get_IdElement(void)
{
return Object->IdElement;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::set_IdElement(__int64 IdElement)
{
Object->IdElement=IdElement;
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::OpenTable(__int64 id_grp, bool all)
{
return Object->OpenTable(id_grp,all);
}
//---------------------------------------------------------------
UnicodeString TDMSprVidImageImpl::GetTextQuery(__int64 id_grp, bool all)
{
return Object->GetTextQuery(id_grp,all);
}
//---------------------------------------------------------------
int TDMSprVidImageImpl::OpenElement(__int64 id )
{
return Object->OpenElement(id );
}
//---------------------------------------------------------------
bool TDMSprVidImageImpl::NewElement(__int64 id_grp)
{
return Object->NewElement(id_grp);
}
//---------------------------------------------------------------
bool TDMSprVidImageImpl::SaveElement(void)
{
return Object->SaveElement();
}
//---------------------------------------------------------------
bool TDMSprVidImageImpl::DeleteElement(__int64 id)
{
return Object->DeleteElement(id);
}
//---------------------------------------------------------------
void TDMSprVidImageImpl::ChancheGrp(__int64 id_new_grp,__int64 id_prop)
{
return Object->ChancheGrp(id_new_grp,id_prop);
}
//---------------------------------------------------------------
__int64 TDMSprVidImageImpl::FindPoName(UnicodeString name)
{
return Object->FindPoName(name);
}
//---------------------------------------------------------------
__int64 TDMSprVidImageImpl::GetIdGrp(__int64 id_el)
{
return Object->GetIdGrp(id_el);
}
//---------------------------------------------------------------
