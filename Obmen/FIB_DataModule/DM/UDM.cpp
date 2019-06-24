//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDM.h"
#include <fstream.h>
#include "UkanTxtFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
TDM * glDM;
//---------------------------------------------------------------------------
__fastcall TDM::TDM(TComponent* Owner)
	: TDataModule(Owner)
{
Database->Connected=false;
Database->DBName="";
}
//---------------------------------------------------------------------------
void __fastcall TDM::DataModuleCreate(TObject *Sender)
{
Database->Connected=false;
}
//---------------------------------------------------------------------------
void __fastcall TDM::DataModuleDestroy(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
bool TDM::ConnectInfBase(void)
{
bool result=false;

try
		{
		Database->Connected=false;
		Database->DBName=ConnectString;
		Database->DBParams->Clear();
		if (UserName=="SYSDBA")
			{
			Database->DBParams->Add(" user_name=SYSDBA");
			Database->DBParams->Add(" lc_ctype=UTF8");
			Database->DBParams->Add(" password="+PasswordUser);
			}
		else
			{
			Database->DBParams->Add(" user_name=EXTUSER");
			Database->DBParams->Add(" lc_ctype=UTF8");
			Database->DBParams->Add(" sql_role_name=ROLE_EXTUSER");
			Database->DBParams->Add(" password="+PasswordUser);
			} 
		Database->Connected=true;
		result=true;
		}
catch (Exception &exception)
		{
		Error=true;
		TextError=exception.Message;
		result=false;
		Database->Connected=false;
		}

return result;
}
//---------------------------------------------------------------------------
void TDM::DisconnectInfBase(void)
{
Database->Connected=false;
}
//---------------------------------------------------------------------------
void TDM::glSaveProtocol(UnicodeString str)
{
UnicodeString FileNameProtocol="";
FileNameProtocol=ExtractFileDir(Application->ExeName)+"\\Log\\"+ DateToStr(Date())+".txt";

str=TimeToStr(Time())+" "+str;

TkanTxtFile * f=new TkanTxtFile;
f->AddString(FileNameProtocol,str);
delete f;
}

//----------------------------------------------------------------------------

void TDM::glSetOperation(__int64 id_base_for_obmen, int oper)
{
QueryUpdate->Close();
QueryUpdate->SQL->Clear();
QueryUpdate->SQL->Add(" update XSETUP_OBMEN set OPER_XSETUP_OBMEN="+IntToStr(oper)
					   + "where IDBASE_OBMEN_XSETUP_OBMEN="+IntToStr(id_base_for_obmen));
QueryUpdate->ExecQuery();
TrUpdate->Commit();
QueryUpdate->Close();
}
//---------------------------------------------------------------------------
int TDM::glGetOperation(__int64 id_base_for_obmen)
{
int result=0;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(" select OPER_XSETUP_OBMEN from XSETUP_OBMEN where IDBASE_OBMEN_XSETUP_OBMEN="
											+IntToStr(id_base_for_obmen));
Query->ExecQuery();
result=Query->FieldByName("OPER_XSETUP_OBMEN")->AsInteger;
return result;
}
//-------------------------------------------------------------------------
UnicodeString TDM::GetVersionProgramFile(void)
{
AnsiString result="";
DWORD h;
DWORD Size=GetFileVersionInfoSize(AnsiString(Application->ExeName).c_str(),&h);
if (Size!=0)
	{
	char *buf;
	buf=(char*)GlobalAlloc(GMEM_FIXED,Size);
	if(GetFileVersionInfo(AnsiString(Application->ExeName).c_str(),h,Size,buf)!=0)
		{
		char * ValueBuf;
		UINT Len;
		VerQueryValue(buf,"\\VarFileInfo\\Translation",&(void*) ValueBuf,&Len);
		if(Len==4)
			{
			AnsiString CharSet=IntToHex((int)MAKELONG(*(int*)(ValueBuf+2),*(int*)ValueBuf),8);
			if (VerQueryValue(buf,AnsiString("\\StringFileInfo\\"+CharSet
					+"\\FileVersion").c_str(),&(void *)ValueBuf,&Len)!=0)
						{
						result=AnsiString(ValueBuf);
						}
			}
		}
	GlobalFree(buf);
	}

return result;
}
//----------------------------------------------------------------------------

