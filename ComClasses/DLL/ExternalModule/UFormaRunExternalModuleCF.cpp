//---------------------------------------------------------------------------


#pragma hdrstop

#include "UFormaRunExternalModuleCF.h"
#include "UFormaRunExternalModuleImpl.h"
#include "IFormaRunExternalModule.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

extern int NumObject;
//---------------------------------------------------------------------------
TFormaRunExternalModuleCF::TFormaRunExternalModuleCF()
{


NumRefs=0;
++NumObject;
}
//----------------------------------------------------------------------------
TFormaRunExternalModuleCF::~TFormaRunExternalModuleCF()
{


--NumObject;
}
//----------------------------------------------------------------------------

int TFormaRunExternalModuleCF::kanQueryInterface(REFIID id_interface, void**ppv)
{
int result=0;

if (id_interface==IID_IkanUnknown)
	{
	*ppv=static_cast<IkanUnknown*> (this);
	result=-1;
	}
else if (id_interface==IID_IkanClassFactory)
	{
	*ppv=static_cast<IkanClassFactory*> (this);
	result=-1;
	}
else
	{
	*ppv=NULL;
	result=0;
	return result;
	}

reinterpret_cast<IkanUnknown*>(*ppv)->kanAddRef();

return result;
}
//-----------------------------------------------------------------------------
int TFormaRunExternalModuleCF::kanAddRef(void)
{

return (++NumRefs);
}
//----------------------------------------------------------------------------
int TFormaRunExternalModuleCF::kanRelease(void)
{
if (--NumRefs==0)
	{
	delete this;
	}
return NumRefs;
}
//------------------------------------------------------------------------------
int TFormaRunExternalModuleCF::kanCreateInstance(REFIID id_interface, void ** ppv)
{
int result=0;


		TFormaRunExternalModuleImpl * ob=new TFormaRunExternalModuleImpl();
		if (ob->kanQueryInterface(id_interface, ppv)==-1)
			{
			result=-1;
			}
		else
			{
			delete ob;
            result=0;
			}


return result;
}
//------------------------------------------------------------------------