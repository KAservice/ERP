//---------------------------------------------------------------------------


#pragma hdrstop

#include "UkanMapiMessage.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
TkanMapiMessage::TkanMapiMessage()
{
FileList=new TStringList();
TextMessageList=new TStringList();
}
//-----------------------------------------------------------------------------
TkanMapiMessage::~TkanMapiMessage()
{
delete FileList;
delete TextMessageList;
}
//----------------------------------------------------------------------------
int TkanMapiMessage::FileList_GetCount(void)
{
return FileList->Count;
}
//----------------------------------------------------------------------------
UnicodeString TkanMapiMessage::FileList_GetString(int index_string)
{
return FileList->Strings[index_string];

}
//----------------------------------------------------------------------------
void TkanMapiMessage::FileList_AddString(UnicodeString file_name)
{
FileList->Add(file_name);
}
//----------------------------------------------------------------------------