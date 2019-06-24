//---------------------------------------------------------------------------


#pragma hdrstop

#include "UFormaPriemPlatImpl.h"

#pragma package(smart_init)
extern int NumObject;

//---------------------------------------------------------------------------
TFormaPriemPlatImpl::TFormaPriemPlatImpl()
{

Object=new TFormaPriemPlat(Application);
NumRefs=0;
++NumObject;
}
//----------------------------------------------------------------------------
TFormaPriemPlatImpl::~TFormaPriemPlatImpl()
{
if (flDeleteObject==true)
	{
	Object->flDeleteImpl=false;
	delete Object;
	}
--NumObject;
}
//----------------------------------------------------------------------------
void TFormaPriemPlatImpl::DeleteImpl(void)
{
flDeleteObject=false;
delete this;
}
//----------------------------------------------------------------------------
int TFormaPriemPlatImpl::kanQueryInterface(REFIID id_interface, void ** ppv)
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
int TFormaPriemPlatImpl::kanAddRef(void)
{

return (++NumRefs);
}
//----------------------------------------------------------------------------
int TFormaPriemPlatImpl::kanRelease(void)
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
int  TFormaPriemPlatImpl::get_CodeError(void)
{

return 0;
}
//----------------------------------------------------------------------------
void TFormaPriemPlatImpl::set_CodeError(int CodeError)
{



}
//----------------------------------------------------------------------------
UnicodeString  TFormaPriemPlatImpl::get_TextError(void)
{

return Object->TextError;
}
//----------------------------------------------------------------------------
void TFormaPriemPlatImpl::set_TextError(UnicodeString  TextError)
{


}
//----------------------------------------------------------------------------

int TFormaPriemPlatImpl::Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object)
{
kanQueryInterface(IID_IkanUnknown,(void**) &Object->InterfaceImpl);
kanRelease();
Object->ClsIdImpl=CLSID_TFormaPriemPlatImpl;
Object->InterfaceMainObject=i_main_object;
Object->InterfaceOwnerObject=i_owner_object;
return Object->Init();
}
//----------------------------------------------------------------------------
int TFormaPriemPlatImpl::Done(void)
{

return Object->Done();
}
//----------------------------------------------------------------------------


