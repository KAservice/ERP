//---------------------------------------------------------------------------


#pragma hdrstop

#include "UkasVikiFRCF.h"
#include "UkasVikiFRImpl.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
extern int NumObject;
//---------------------------------------------------------------
TkasVikiFRCF::TkasVikiFRCF()
{
NumRefs=0;
++NumObject;
}
//---------------------------------------------------------------
TkasVikiFRCF::~TkasVikiFRCF()
{
--NumObject;
}
//---------------------------------------------------------------
int TkasVikiFRCF::kanQueryInterface(REFIID id_interface, void**ppv)
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
int TkasVikiFRCF::kanAddRef(void)
{
return (++NumRefs);
}
//---------------------------------------------------------------
int TkasVikiFRCF::kanRelease(void)
{
if (--NumRefs==0)
	{
	delete this;
	return 0;
	}
return NumRefs;
}
//---------------------------------------------------------------
int TkasVikiFRCF::kanCreateInstance(REFIID id_interface, void ** ppv)
{
int result=0;
		TkasVikiFRImpl * ob=new TkasVikiFRImpl();
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