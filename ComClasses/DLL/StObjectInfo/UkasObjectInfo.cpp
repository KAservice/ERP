//---------------------------------------------------------------------------


#pragma hdrstop

#include "UkasObjectInfo.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//---------------------------------------------------------------------------
TkasObjectInfo::TkasObjectInfo()
{
ListProperties = new TList;
ListObject = new TList; //список подчиненных объектов

}

//-----------------------------------------------------------------------------
TkasObjectInfo::~TkasObjectInfo()
{
//предварительно надо удалить сами объекты !!!!!!

for (int i=0;i<ListProperties->Count;i++)
	{
	TkasObjectInfoProperties * pr=(TkasObjectInfoProperties*) ListProperties->Items[i];
	delete pr;
	}
delete ListProperties;

for (int i=0;i<ListObject->Count;i++)
	{
	TkasObjectInfo * ob=(TkasObjectInfo*) ListObject->Items[i];
	delete ob;
	}
delete ListObject; //список подчиненных объектов
}
//---------------------------------------------------------------------------