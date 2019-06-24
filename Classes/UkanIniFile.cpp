//---------------------------------------------------------------------------


#pragma hdrstop

#include "UkanIniFile.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//-------------------------------------------------------------------
TkanIniFile::TkanIniFile(UnicodeString file_name)
{
Ini=new TIniFile(file_name);
}
//-----------------------------------------------------------------------------
TkanIniFile::~TkanIniFile()
{
delete Ini;
}
//-----------------------------------------------------------------------------
UnicodeString TkanIniFile::ReadString(UnicodeString section,UnicodeString ident,
													UnicodeString default_value)
{
UnicodeString result="";
result=Ini->ReadString(section,ident,default_value);
return result;
}
//-----------------------------------------------------------------------------
void TkanIniFile::WriteString(UnicodeString section,UnicodeString ident,
													UnicodeString value)
{
Ini->WriteString(section,ident,value);
}
//-----------------------------------------------------------------------------
int TkanIniFile::ReadIntegerValue(UnicodeString section,UnicodeString ident,
													int default_value)
{
int result=0;
result=Ini->ReadInteger(section,ident,default_value);
return result;
}
//-----------------------------------------------------------------------------
bool TkanIniFile::ReadBoolValue(UnicodeString section,UnicodeString ident,
													bool default_value)
{

return default_value;
}
//-----------------------------------------------------------------------------
void TkanIniFile::ReadSections(TStrings * str)
{
Ini->ReadSections(str);
}
//-----------------------------------------------------------------------------
