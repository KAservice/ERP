//---------------------------------------------------------------------------
#include "vcl.h"

#pragma hdrstop

#include "UMainObject.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------
TMainObject::TMainObject()
{


glFR=0;
glDisplayPok=0;
NumRefs=0;
CodeError=0;
TextError="";

	//Подключение
DM_Connection=0;

	//global COM
InterfaceGlobalCom=0;

	//Внешние события
InterfaceForExternalEvent=0; //куда переправить внешнее событие
}
//---------------------------------------------------------------
TMainObject::~TMainObject()
{

}

//---------------------------------------------------------------
int TMainObject::kanQueryInterface(REFIID id_interface, void ** ppv)
 {
int result=0;
if (id_interface==IID_IkanUnknown)
   {
   *ppv=static_cast<IkanUnknown*> (static_cast<IMainInterface*> (this));
   result=-1;
   }
else if (id_interface==IID_IMainInterface)
   {
   *ppv=static_cast<IMainInterface*> (this);
   result=-1;
   }
else if (id_interface==IID_IConnectionInterface)
   {
   *ppv=static_cast<IConnectionInterface*> (this);
   result=-1;
   }
else if (id_interface==IID_IMainCOMInterface)
   {
   *ppv=static_cast<IMainCOMInterface*> (this);
   result=-1;
   }
else if (id_interface==IID_IAsyncExternalEvent)
   {
   *ppv=static_cast<IAsyncExternalEvent*> (this);
   result=-1;
   }
else if (id_interface==IID_IDevices)
   {
   *ppv=static_cast <IDevices*> (this);
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
int TMainObject::kanAddRef(void)
{
return (++NumRefs);
}
//---------------------------------------------------------------
int TMainObject::kanRelease(void)
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
int TMainObject::get_CodeError(void)
{
return CodeError;
}
//---------------------------------------------------------------
void TMainObject::set_CodeError(int CodeError)
{
}
//---------------------------------------------------------------
UnicodeString  TMainObject::get_TextError(void)
{
return TextError;
}
//---------------------------------------------------------------
void TMainObject::set_TextError(UnicodeString  TextError)
{
}
//---------------------------------------------------------------
int TMainObject::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{


return -1;
}
//---------------------------------------------------------------
int TMainObject::Done(void)
{
return -1;
}
//---------------------------------------------------------------




//IConnectionInterface
IDMFibConnection * TMainObject::GetFibConnection(void)
{


return DM_Connection;
}
//----------------------------------------------------------------

//IMainCOMInterface
IkanCom * TMainObject::GetCOM(void)
{
return InterfaceGlobalCom;
}
//--------------------------------------------------------------------



//IAsyncExternalEvent
int TMainObject::SetInterfaceForAsyncExternalEvent(IkanUnknown * i_act_form)
{
int result=0;
if (i_act_form)
	{
	result=i_act_form->kanQueryInterface(IID_IAsyncExternalEvent, (void**) &InterfaceForExternalEvent);
	}
else
	{
    InterfaceForExternalEvent=0;
	}
return result;
}
//----------------------------------------------------------------
int TMainObject::AsyncExternalEvent(char * object, char* event, char* data)
{
int result=0;
if (InterfaceForExternalEvent)
	{
	result=InterfaceForExternalEvent->AsyncExternalEvent(object,event,data);
	}
return result;
}
//---------------------------------------------------------------



//IDevices
int  TMainObject::GetDeviceObject(int type_interface_device, void** ppv)
{
int result=0;

if (type_interface_device==1)
	{
	if (glFR)
		{
		*ppv=glFR;
		result=-1;
		}
	else
		{
		*ppv=0;
		result=1;
		}
	}

if (type_interface_device==2)
	{
	if (glDisplayPok)
		{
		*ppv=glDisplayPok;
		result=-1;
		}
	else
		{
		*ppv=0;
		result=1;
		}
	}

return result;
}
//----------------------------------------------------------------