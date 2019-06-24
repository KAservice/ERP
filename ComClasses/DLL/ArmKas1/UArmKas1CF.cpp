//---------------------------------------------------------------------------

#pragma hdrstop

#include "UArmKas1CF.h"
#include "UArmKas1Impl.h"

#pragma package(smart_init)
extern int NumObject;
//----------------------------------------------------------------------------
TArmKas1CF::TArmKas1CF()
{


NumRefs=0;
++NumObject;
}
//----------------------------------------------------------------------------
TArmKas1CF::~TArmKas1CF()
{


--NumObject;
}
//----------------------------------------------------------------------------

int TArmKas1CF::kanQueryInterface(REFIID id_interface, void**ppv)
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
int TArmKas1CF::kanAddRef(void)
{

return (++NumRefs);
}
//----------------------------------------------------------------------------
int TArmKas1CF::kanRelease(void)
{
if (--NumRefs==0)
	{
	delete this;
	return 0;
	}
return NumRefs;
}
//------------------------------------------------------------------------------
int TArmKas1CF::kanCreateInstance(REFIID id_interface, void ** ppv)
{
int result=0;


		TArmKas1Impl * ob=new TArmKas1Impl();

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
