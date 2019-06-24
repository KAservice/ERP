//---------------------------------------------------------------------------

#pragma hdrstop

#include "UArmKas2CF.h"
#include "UArmKas2Impl.h"

#pragma package(smart_init)
extern int NumObject;
//----------------------------------------------------------------------------
TArmKas2CF::TArmKas2CF()
{


NumRefs=0;
++NumObject;
}
//----------------------------------------------------------------------------
TArmKas2CF::~TArmKas2CF()
{


--NumObject;
}
//----------------------------------------------------------------------------

int TArmKas2CF::kanQueryInterface(REFIID id_interface, void**ppv)
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
int TArmKas2CF::kanAddRef(void)
{

return (++NumRefs);
}
//----------------------------------------------------------------------------
int TArmKas2CF::kanRelease(void)
{
if (--NumRefs==0)
	{
	delete this;
	}
return NumRefs;
}
//------------------------------------------------------------------------------
int TArmKas2CF::kanCreateInstance(REFIID id_interface, void ** ppv)
{
int result=0;


		TArmKas2Impl * ob=new TArmKas2Impl();

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
