//---------------------------------------------------------------------------


#pragma hdrstop

#include "USheetEditorCF.h"
#include "USheetEditorImpl.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
extern int NumObject;
//----------------------------------------------------------------------------
TSheetEditorCF::TSheetEditorCF()
{


NumRefs=0;
++NumObject;
}
//----------------------------------------------------------------------------
TSheetEditorCF::~TSheetEditorCF()
{


--NumObject;
}
//----------------------------------------------------------------------------

int TSheetEditorCF::kanQueryInterface(REFIID id_interface, void**ppv)
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
int TSheetEditorCF::kanAddRef(void)
{

return (++NumRefs);
}
//----------------------------------------------------------------------------
int TSheetEditorCF::kanRelease(void)
{
if (--NumRefs==0)
	{
	delete this;
	}
return NumRefs;
}
//------------------------------------------------------------------------------
int TSheetEditorCF::kanCreateInstance(REFIID id_interface, void ** ppv)
{
int result=0;


		TSheetEditorImpl * ob=new TSheetEditorImpl();

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