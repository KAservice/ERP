//---------------------------------------------------------------------------


#pragma hdrstop

#include "UArmKas1Impl.h"

#pragma package(smart_init)
extern int NumObject;

//---------------------------------------------------------------------------
TArmKas1Impl::TArmKas1Impl()
{

Object=new TFormaARMKassir(Application);
Object->FunctionDeleteImpl=DeleteImpl;
NumRefs=0;
++NumObject;
flDeleteObject=true;
}
//----------------------------------------------------------------------------
TArmKas1Impl::~TArmKas1Impl()
{
if (flDeleteObject==true)
	{
	Object->flDeleteImpl=false;
	delete Object;
	}
--NumObject;
}
//----------------------------------------------------------------------------
void TArmKas1Impl::DeleteImpl(void)
{
flDeleteObject=false;
delete this;
}
//---------------------------------------------------------------
int TArmKas1Impl::kanQueryInterface(REFIID id_interface, void ** ppv)
{
int result=0;

if (id_interface==IID_IkanUnknown)
	{
	*ppv=static_cast<IkanUnknown*> ( static_cast<IMainInterface*> (this));
	result=-1;
	}
else if (id_interface==IID_IMainInterface)
	{
	*ppv=static_cast<IMainInterface*> (this);
	result=-1;
	}
else if (id_interface==IID_IkanCallBack)
	{
	*ppv=static_cast<IkanCallBack*> (this);
	result=-1;
	}
else if (id_interface==IID_IAsyncExternalEvent)
   {
   *ppv=static_cast<IAsyncExternalEvent*> (this);
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
//---------------------------------------------------------------------------
int TArmKas1Impl::kanAddRef(void)
{

return (++NumRefs);
}
//----------------------------------------------------------------------------
int TArmKas1Impl::kanRelease(void)
{

if (--NumRefs==0)
	{
	delete this;
	return 0;
	}
return NumRefs;
}
//-----------------------------------------------------------------------------
	//IMainInterface

//----------------------------------------------------------------------------
int  TArmKas1Impl::get_CodeError(void)
{

return 0;
}
//----------------------------------------------------------------------------
void TArmKas1Impl::set_CodeError(int CodeError)
{



}
//----------------------------------------------------------------------------
UnicodeString  TArmKas1Impl::get_TextError(void)
{

return Object->TextError;
}
//----------------------------------------------------------------------------
void TArmKas1Impl::set_TextError(UnicodeString  TextError)
{


}
//----------------------------------------------------------------------------

int TArmKas1Impl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TArmKas1Impl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//----------------------------------------------------------------------------
int TArmKas1Impl::Done(void)
{


return Object->Done();
}
//----------------------------------------------------------------------------
   //IkanCallBack
int TArmKas1Impl::kanExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

return Object->ExternalEvent(pUnk,id_object,type_event,number_procedure_end);
}
//------------------------------------------------------------------------------


//IAcyncExternalEvent
int TArmKas1Impl::AsyncExternalEvent(char * object, char* event, char* data)
{
AnsiString ansi_object=object;
AnsiString ansi_event=event;
AnsiString ansi_data=data;

if (Trim(ansi_object)=="scaner")
	{
	Object->ReadShtrihCodEvent(0,ansi_data);
	}
return -1;
}
//-----------------------------------------------------------------
int TArmKas1Impl::SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form)
{

return -1;
}
//------------------------------------------------------------------
