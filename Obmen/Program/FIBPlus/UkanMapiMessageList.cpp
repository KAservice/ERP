//---------------------------------------------------------------------------


#pragma hdrstop

#include "UkanMapiMessageList.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//-------------------------------------------------------------------
TkanMapiMessageList::TkanMapiMessageList()
{
List=new TList();
}
//-----------------------------------------------------------------------------
TkanMapiMessageList::~TkanMapiMessageList()
{
//удалить команды и сам список
for (int i=0;i<List->Count;i++)
	{
	TkanMapiMessage * comand=(TkanMapiMessage*)List->Items[i];
	delete comand;
	}
delete List;
}
//----------------------------------------------------------------------------

bool TkanMapiMessageList::GetFirstComand(void)
{
bool result=false;


return result;
}
//-----------------------------------------------------------------------------

TkanMapiMessage* TkanMapiMessageList::GetElement(int index)
{
return (TkanMapiMessage*)List->Items[index];
}
//---------------------------------------------------------------------------