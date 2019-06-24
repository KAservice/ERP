//---------------------------------------------------------------------------


#pragma hdrstop

#include "UArmKas2Impl.h"

#pragma package(smart_init)
extern int NumObject;

//---------------------------------------------------------------------------
TArmKas2Impl::TArmKas2Impl()
{

Object=new TFormaARMKassir2(Application);
Object->FunctionDeleteImpl=DeleteImpl;
NumRefs=0;
++NumObject;
flDeleteObject=true;
}
//----------------------------------------------------------------------------
TArmKas2Impl::~TArmKas2Impl()
{
if (flDeleteObject==true)
	{
	Object->flDeleteImpl=false;
	delete Object;
	}
--NumObject;
}
//----------------------------------------------------------------------------
void TArmKas2Impl::DeleteImpl(void)
{
flDeleteObject=false;
delete this;
}
//---------------------------------------------------------------
int TArmKas2Impl::kanQueryInterface(REFIID id_interface, void ** ppv)
{
int result=0;

if (id_interface==IID_IkanUnknown)
	{
	*ppv=static_cast<IkanUnknown*>  ( static_cast<IMainInterface*> (this));
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
int TArmKas2Impl::kanAddRef(void)
{

return (++NumRefs);
}
//----------------------------------------------------------------------------
int TArmKas2Impl::kanRelease(void)
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
int  TArmKas2Impl::get_CodeError(void)
{

return 0;
}
//----------------------------------------------------------------------------
void TArmKas2Impl::set_CodeError(int CodeError)
{



}
//----------------------------------------------------------------------------
UnicodeString  TArmKas2Impl::get_TextError(void)
{

return Object->TextError;
}
//----------------------------------------------------------------------------
void TArmKas2Impl::set_TextError(UnicodeString  TextError)
{


}
//----------------------------------------------------------------------------

int TArmKas2Impl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TArmKas2Impl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//----------------------------------------------------------------------------
int TArmKas2Impl::Done(void)
{


return Object->Done();
}
//----------------------------------------------------------------------------
   //IkanCallBack
int TArmKas2Impl::kanExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									)
{

return Object->ExternalEvent(pUnk,id_object,type_event,number_procedure_end);
}
//------------------------------------------------------------------------------


//IAcyncExternalEvent
int TArmKas2Impl::AsyncExternalEvent(char * object, char* event, char* data)
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
int TArmKas2Impl::SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form)
{

return -1;
}
//------------------------------------------------------------------
