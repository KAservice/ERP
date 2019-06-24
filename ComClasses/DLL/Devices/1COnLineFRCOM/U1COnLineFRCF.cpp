//---------------------------------------------------------------------------


#pragma hdrstop

#include "U1COnLineFRCF.h"
#include "U1COnLineFRImpl.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
T1COnLineFRCF::T1COnLineFRCF()
{
NumRefs=0;
++NumObject;
}
//---------------------------------------------------------------
T1COnLineFRCF::~T1COnLineFRCF()
{
--NumObject;
}
//---------------------------------------------------------------
int T1COnLineFRCF::kanQueryInterface(REFIID id_interface, void**ppv)
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
//---------------------------------------------------------------
int T1COnLineFRCF::kanAddRef(void)
{
return (++NumRefs);
}
//---------------------------------------------------------------
int T1COnLineFRCF::kanRelease(void)
{
if (--NumRefs==0)
	{
	delete this;
	return 0;
	}
return NumRefs;
}
//---------------------------------------------------------------
int T1COnLineFRCF::kanCreateInstance(REFIID id_interface, void ** ppv)
{
int result=0;
		T1COnLineFRImpl * ob=new T1COnLineFRImpl();
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
//---------------------------------------------------------------