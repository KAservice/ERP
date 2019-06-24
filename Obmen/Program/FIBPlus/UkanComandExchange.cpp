//---------------------------------------------------------------------------


#pragma hdrstop

#include "UkanComandExchange.h"
#include <Classes.hpp>
#include <IdFTP.hpp>
#include "UkanIniFile.h"


//---------------------------------------------------------------------------

#pragma package(smart_init)

TkanComandExchange::TkanComandExchange()
{
FileList=new TStringList();
}
//-----------------------------------------------------------------------------
TkanComandExchange::~TkanComandExchange()
{

delete FileList;
}
//----------------------------------------------------------------------------
int TkanComandExchange::FileList_GetCount(void)
{
return FileList->Count;
}
//----------------------------------------------------------------------------
UnicodeString TkanComandExchange::FileList_GetString(int index_string)
{
return FileList->Strings[index_string];

}
//----------------------------------------------------------------------------
void TkanComandExchange::FileList_AddString(UnicodeString file_name)
{
FileList->Add(file_name);
}
//----------------------------------------------------------------------------
bool TkanComandExchange::NewComand(void)
{
bool result=false;
GUID guid;
CoCreateGuid(&guid);
ID=GUIDToString(guid);
return result;
}

//----------------------------------------------------------------------------
UnicodeString TkanComandExchange::GetCatalogObmena(__int64 id_tec_base,__int64 id_base_for_obmen)
{
UnicodeString result="";
UnicodeString file_ini=LocalCatalog;
file_ini=LocalCatalog+"\\"+GC_FileNameIni;
TkanIniFile * ini=new TkanIniFile(file_ini);


result=ini->ReadString(IntToStr(id_base_for_obmen),"CatalogObmenaPatch", "");

delete ini;

return result;
}
//-----------------------------------------------------------------------------
UnicodeString TkanComandExchange::GetStringParameter(UnicodeString name_parameter)
{
UnicodeString result="";
UnicodeString file_ini=LocalCatalog;
file_ini=LocalCatalog+"\\"+GC_FileNameIni;
TkanIniFile * ini=new TkanIniFile(file_ini);
result=ini->ReadString(IntToStr(IdBaseForObmen),name_parameter, "");
delete ini;

return result;
}
//----------------------------------------------------------------------------

