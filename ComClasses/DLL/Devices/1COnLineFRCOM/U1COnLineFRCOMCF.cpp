//---------------------------------------------------------------------------


#pragma hdrstop

#include "U1COnLineFRCOMCF.h"
#include "U1COnLineFRCOMImpl.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
T1COnLineFRCOMCF::T1COnLineFRCOMCF()
{
NumRefs=0;
++NumObject;
}
//---------------------------------------------------------------
T1COnLineFRCOMCF::~T1COnLineFRCOMCF()
{
--NumObject;
}
//---------------------------------------------------------------
int T1COnLineFRCOMCF::kanQueryInterface(REFIID id_interface, void**ppv)
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
int T1COnLineFRCOMCF::kanAddRef(void)
{
return (++NumRefs);
}
//---------------------------------------------------------------
int T1COnLineFRCOMCF::kanRelease(void)
{
if (--NumRefs==0)
	{
	delete this;
	return 0;
	}
return NumRefs;
}
//---------------------------------------------------------------
int T1COnLineFRCOMCF::kanCreateInstance(REFIID id_interface, void ** ppv)
{
int result=0;
		T1COnLineFRCOMImpl * ob=new T1COnLineFRCOMImpl();
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