//---------------------------------------------------------------------------
#pragma hdrstop

#include "UkanBaseGuid.h"
#include <fstream.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)
//----------------------------------------------------------------------------
extern int NumObject;

TkanBaseGuid::TkanBaseGuid()
{


++NumObject;
}
//----------------------------------------------------------------------------
TkanBaseGuid::~TkanBaseGuid()
{


--NumObject;
}
//----------------------------------------------------------------------------
UnicodeString TkanBaseGuid::GetProgIDFromCLSID(GUID guid)
{
UnicodeString result="";
//int max=0;
//char s[200];
//�� �������� �� �������� �������, ���� ��������� ����������� � ������� ������� ��� � ���������
//UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
//ifstream infile((ProgramCatalog+"\\kanGUID.dat").c_str());
//if ( infile)
//	{
//	while (!infile.eof())
//		{
//		infile.getline(s,200);
//		AnsiString str=s; str=Trim(str);
//		AnsiString guid_file=Trim(str.SubString(1,40));
//		AnsiString prog_id_file=Trim(str.SubString(41,40));
//		AnsiString modul=Trim(str.SubString(81,str.Length()-80));
//		if (GUIDToString(guid)==guid_file)
//			{
//			result=prog_id_file;
//			break;
//			}
//
//		max++;
//		if (max > 1000000)
//			{
//			OutputDebugStringW(("����������� ���� �  TkanBaseGuid::GetProgIDFromCLSID "+
//						GUIDToString(guid)).c_str());
//			break;
//			}
//		}
//	}
//else
//	{
//	OutputDebugStringA("�� ������� ������� ���� �  TkanBaseGuid::GetProgIDFromCLSID ");
//	}
//infile.close();


TStringList * list=new TStringList;
UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
list->LoadFromFile(ProgramCatalog+"\\kanGUID.dat");

for (int i=0; i<list->Count;i++)
		{
		AnsiString str=Trim(list->Strings[i]);
		AnsiString guid_file=Trim(str.SubString(1,40));
		AnsiString prog_id_file=Trim(str.SubString(41,40));
		AnsiString modul=Trim(str.SubString(81,str.Length()-80));
		if (GUIDToString(guid)==guid_file)
			{
			result=prog_id_file;
			break;
			}
		}

delete list;


return result;
}
//---------------------------------------------------------------------------
GUID TkanBaseGuid::GetCLSIDFromProgID(UnicodeString prog_id)
{
GUID result;
AnsiString pi=prog_id;
result=StringToGUID(L"{00000000-0000-0000-0000-000000000000}");

//char s[200];
//�� �������� �� �������� �������, ���� ��������� ����������� � ������� ������� ��� � ���������
//UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
//ifstream infile((ProgramCatalog+"\\kanGUID.dat").c_str());
//int max=0;
//if ( infile)
//	{
//	while (!infile.eof())
//		{
//		infile.getline(s,200);
//		AnsiString str=s; str=Trim(str);
//		AnsiString guid=Trim(str.SubString(1,40));
//		AnsiString prog_id_file=Trim(str.SubString(41,40));
//		AnsiString modul=Trim(str.SubString(81,str.Length()-80));
//		if (pi==prog_id_file)
//			{
//			result=StringToGUID(guid);
//			break;
//			}
//		max++;
//		if (max > 1000000)
//			{
//			OutputDebugStringA(("����������� ���� �  TkanBaseGuid::GetCLSIDFromProgID "+
//						AnsiString(prog_id)).c_str());
//			break;
//			}
//		}
//	}
//else
//	{
//	OutputDebugStringA("�� ������� ������� ���� �  TkanBaseGuid::GetCLSIDFromProgID ");
//	}
//infile.close();


TStringList * list=new TStringList;
UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
list->LoadFromFile(ProgramCatalog+"\\kanGUID.dat");

for (int i=0; i<list->Count;i++)
		{
		AnsiString str=Trim(list->Strings[i]);
		AnsiString guid=Trim(str.SubString(1,40));
		AnsiString prog_id_file=Trim(str.SubString(41,40));
		AnsiString modul=Trim(str.SubString(81,str.Length()-80));
		if (pi==prog_id_file)
			{
			result=StringToGUID(guid);
			break;
			}
		}

delete list;

return result;
}
//---------------------------------------------------------------------------
UnicodeString TkanBaseGuid::GetNameModul(REFIID id_class)
{
UnicodeString result="";
//int max=0;
//char s[200];
//�� ��������, �� �������� ������� ������� ��� � ���������
//UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
//ifstream infile((ProgramCatalog+"\\kanGUID.dat").c_str());
//if ( infile)
//	{
//	while (!infile.eof())
//		{
//		infile.getline(s,200);
//		AnsiString str=s; str=Trim(str);
//		AnsiString guid=Trim(str.SubString(1,40));
//		AnsiString prog_id=Trim(str.SubString(41,40));
//		AnsiString modul=Trim(str.SubString(81,str.Length()-80));
//		if (GUIDToString(id_class)==guid)
//			{
//			result=modul;
//			break;
//			}
//
//		max++;
//		if (max > 1000000)
//			{
//			OutputDebugStringW(("����������� ���� �  TkanBaseGuid::GetNameModul "+
//						GUIDToString(id_class)).c_str());
//			break;
//			}
//		}
//	}
//else
//	{
//	OutputDebugStringA("�� ������� ������� ���� �  TkanBaseGuid::GetCLSIDFromProgID ");
//	}
//infile.close();


TStringList * list=new TStringList;
UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
list->LoadFromFile(ProgramCatalog+"\\kanGUID.dat");
//���� ����������� ��������� ������ ����
//���� ������� ��������, �� ����� ������������� �������� ������ ������, ������ ������� ��������
//��������� ���� ���� ��� �� ������� ����
for (int i=0; i<list->Count;i++)
		{
		AnsiString str=Trim(list->Strings[i]);
		AnsiString guid=Trim(str.SubString(1,40));
		AnsiString prog_id=Trim(str.SubString(41,40));
		AnsiString modul=Trim(str.SubString(81,str.Length()-80));
		if (GUIDToString(id_class)==guid)
			{
			result=modul;
			break;
			}
		}

delete list;

return result;

}
//---------------------------------------------------------------------------
bool TkanBaseGuid::AddClass(REFIID id_class, UnicodeString prog_id, UnicodeString file_name_modul)
{
bool result=false;
//ProgId - 39 ��������
//GUID - 39 ��������
//��� ����� - ������������

AnsiString str="";
str=DopStrR(GUIDToString(id_class)," ",40);
str=str+DopStrR(prog_id," ",40);
str=str+file_name_modul+"\n";

//�� �������� �� �������� �������, ���� ��������� ����������� � ������� ������� ��� � ���������
//UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
//ofstream outfile((ProgramCatalog+"\\kanGUID.dat").c_str(),ios::out|ios::app);

ofstream outfile("kanGUID.dat",ios::out|ios::app);

if (outfile)
	{
	outfile<<str.c_str();
	outfile.close();
	result=true;
	}

return result;
}
//---------------------------------------------------------------------------
bool TkanBaseGuid::RemoveClass(REFIID id_class)
{
bool result=true;


return result;
}
//---------------------------------------------------------------------------


//��������� ������ Str ����� ��������� Symbol �� Len
AnsiString TkanBaseGuid::DopStrL(AnsiString Str, AnsiString Symbol, int Len)
{
while(Str.Length()<Len)
        {
        Str=Symbol+Str;
        }
return Str;
}
//---------------------------------------------------------------------------
//��������� ������ Str ������ ��������� Symbol �� Len
AnsiString TkanBaseGuid::DopStrR(AnsiString Str, AnsiString Symbol, int Len)
{
while(Str.Length()<Len)
		{
		Str=Str+Symbol;
		}
return Str;
}
//----------------------------------------------------------------------------
