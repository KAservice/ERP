//---------------------------------------------------------------------------


#pragma hdrstop

#include "UkanComandExchangeList.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

//-------------------------------------------------------------------
TkanComandExchangeList::TkanComandExchangeList()
{
List=new TList();
}
//-----------------------------------------------------------------------------
TkanComandExchangeList::~TkanComandExchangeList()
{
//удалить команды и сам список
for (int i=0;i<List->Count;i++)
	{
	TkanComandExchange * comand=(TkanComandExchange*)List->Items[i];
	delete comand;
	}
delete List;
}
//----------------------------------------------------------------------------

bool TkanComandExchangeList::GetFirstComand(void)
{
bool result=false;


return result;
}
//-----------------------------------------------------------------------------

TkanComandExchange* TkanComandExchangeList::GetComand(int index_comand)
{
return (TkanComandExchange*)List->Items[index_comand];
}
//---------------------------------------------------------------------------

