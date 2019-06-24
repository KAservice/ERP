//---------------------------------------------------------------------------


#pragma hdrstop

#include "UDMFibConnectionCF.h"
#include "UDMFibConnectionImpl.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
extern int NumObject;
//----------------------------------------------------------------------------
TDMFibConnectionCF::TDMFibConnectionCF()
{


NumRefs=0;
++NumObject;
}
//----------------------------------------------------------------------------
TDMFibConnectionCF::~TDMFibConnectionCF()
{


--NumObject;
}
//----------------------------------------------------------------------------

int TDMFibConnectionCF::kanQueryInterface(REFIID id_interface, void**ppv)
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

kanAddRef();

return result;
}
//----------------------------------------------------------------------------
int TDMFibConnectionCF::kanAddRef(void)
{

return (++NumRefs);
}
//----------------------------------------------------------------------------
int TDMFibConnectionCF::kanRelease(void)
{
if (--NumRefs==0)
	{
	delete this;
	}
return NumRefs;
}
//------------------------------------------------------------------------------
int TDMFibConnectionCF::kanCreateInstance(REFIID id_interface, void ** ppv)
{
int result=0;


		TDMFibConnectionImpl * ob=new TDMFibConnectionImpl();

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