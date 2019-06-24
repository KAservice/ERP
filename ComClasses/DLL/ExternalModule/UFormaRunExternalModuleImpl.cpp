//---------------------------------------------------------------------------


#pragma hdrstop

#include "UFormaRunExternalModuleImpl.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

extern int NumObject;


//---------------------------------------------------------------------------
TFormaRunExternalModuleImpl::TFormaRunExternalModuleImpl()
{

Object=new TFormaRunExternalModule(Application);
Object->FunctionDeleteImpl=DeleteImpl;
NumRefs=0;
++NumObject;

flDeleteObject=true;
}
//----------------------------------------------------------------------------
TFormaRunExternalModuleImpl::~TFormaRunExternalModuleImpl()
{
if (flDeleteObject==true)
	{
	Object->flDeleteImpl=false;
	delete Object;
	}
--NumObject;
}
//--------------------------------------------------------------------------
void TFormaRunExternalModuleImpl::DeleteImpl(void)
{
flDeleteObject=false;
delete this;
}
//----------------------------------------------------------------------------
int TFormaRunExternalModuleImpl::kanQueryInterface(REFIID id_interface, void ** ppv)
{
int result=0;

if (id_interface==IID_IkanUnknown)
	{
	//*ppv=static_cast<IkanUnknown*> (this);
	result=-1;
	}
else if (id_interface==IID_IMainInterface)
	{
	*ppv=static_cast<IMainInterface*> (this);
	result=-1;
	}
else if (id_interface==IID_IFormaRunExternalModule)
	{
	*ppv=static_cast<IFormaRunExternalModule*> (this);
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
//----------------------------------------------------------------------------
int TFormaRunExternalModuleImpl::kanAddRef(void)
{

return (++NumRefs);
}
//-----------------------------------------------------------------------------
int TFormaRunExternalModuleImpl::kanRelease(void)
{
if (--NumRefs==0)
	{
	delete this;
	return 0;
	}
return NumRefs;
}
//----------------------------------------------------------------------------
//IMainInterface

//----------------------------------------------------------------------------

int  TFormaRunExternalModuleImpl::get_CodeError(void)
{

return -1;
}
//----------------------------------------------------------------------------
void TFormaRunExternalModuleImpl::set_CodeError(int CodeError)
{


}
//----------------------------------------------------------------------------

UnicodeString  TFormaRunExternalModuleImpl::get_TextError(void)
{

return "";
}
//----------------------------------------------------------------------------
void TFormaRunExternalModuleImpl::set_TextError(UnicodeString  TextError)
{


}

//-----------------------------------------------------------------------------
int TFormaRunExternalModuleImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
Object->ClsIdImpl=CLSID_TFormaRunExternalModuleImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//----------------------------------------------------------------------------
int TFormaRunExternalModuleImpl::Done(void)
{

return -1;
}

//IkanCallBack
int TFormaRunExternalModuleImpl::kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end)
{
return Object->ExternalEvent(pUnk,   //интерфейс на дочерний объект
									id_object,      //тип дочернего объекта
									type_event,     //тип события в дочернем объекте
									number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									);
}
//---------------------------------------------------------------

//-----------------------------------------------------------------------------
void TFormaRunExternalModuleImpl::ClearModule(void)
{

Object->ClearModule();
}
//-----------------------------------------------------------------------------
void TFormaRunExternalModuleImpl::LoadModule(void)
{

Object->LoadModule();
}
//-----------------------------------------------------------------------------
void TFormaRunExternalModuleImpl::ExecuteModule(void)
{

Object->ExecuteModule();
}
//-----------------------------------------------------------------------------

void TFormaRunExternalModuleImpl::SetIntegerVariables(UnicodeString name_variables, int value)
{

Object->SetIntegerVariables(name_variables,value);
}
//-----------------------------------------------------------------------------
void TFormaRunExternalModuleImpl::SetStringVariables(UnicodeString name_variables, UnicodeString value)
{

Object->SetStringVariables(name_variables,value);
}
//-----------------------------------------------------------------------------
void TFormaRunExternalModuleImpl::SetInt64Variables(UnicodeString name_variables, __int64 value)
{

Object->SetInt64Variables(name_variables, value);
}
//-----------------------------------------------------------------------------
void TFormaRunExternalModuleImpl::SetDateTimeVariables(UnicodeString name_variables, TDateTime value)
{

Object->SetDateTimeVariables(name_variables,value);
}
//-----------------------------------------------------------------------------

void TFormaRunExternalModuleImpl::ListAddElement(UnicodeString id1, UnicodeString id2, UnicodeString id3, int int_value1)
{

Object->ListAddElement(id1, id2, id3, int_value1);
}
//-----------------------------------------------------------------------------

void TFormaRunExternalModuleImpl::AddClassesInScript_SheetEditor(void)
{

Object->AddClassesInScript_SheetEditor();
}
//-----------------------------------------------------------------------------
void TFormaRunExternalModuleImpl::AddClassesInScript_ReportGrid(void)
{

Object->AddClassesInScript_ReportGrid();
}
//-----------------------------------------------------------------------------
void TFormaRunExternalModuleImpl::AddClassesInScript_DMQueryRead(void)
{

Object->AddClassesInScript_DMQueryRead();
}
//-----------------------------------------------------------------------------
void TFormaRunExternalModuleImpl::OpenDesignerFastReport(void)
{
Object->frxReport1->Clear();
Object->frxReport1->DesignReport(false, false);

}
//-----------------------------------------------------------------------------
	//свойства

int  TFormaRunExternalModuleImpl::get_TypeTable(void)
{

return  Object->TypeTable;
}
//-----------------------------------------------------------------------------
void TFormaRunExternalModuleImpl::set_TypeTable(int TypeTable)
{

Object->TypeTable=TypeTable;
}
//-----------------------------------------------------------------------------

__int64  TFormaRunExternalModuleImpl::get_IdModule(void)
{

return Object->IdModule;
}
//-----------------------------------------------------------------------------
void TFormaRunExternalModuleImpl::set_IdModule(__int64 IdModule)
{

Object->IdModule=IdModule;
}
//-----------------------------------------------------------------------------
