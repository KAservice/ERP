//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UMainForm.h"
#include "UFormSetup.h"
#include "inifiles.hpp"
#include "UDM.h"
#include <fstream.h>
#include "UkanFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
TIniFile * glIni;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonOpenFormSetupClick(TObject *Sender)
{
//останавливаем таймер
Timer2->Interval=0;
Timer2->Enabled=false;

Application->CreateForm(__classid(TFormSetup), &FormSetup);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
UnicodeString file_ini=ExtractFileDir(Application->ExeName)+L"\\Tables.ini";
glIni=new TIniFile(file_ini);

UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
if (DirectoryExists(ProgramCatalog+L"\\Log")==false)
        {
		CreateDir(ProgramCatalog+L"\\Log");
        }

if (DirectoryExists(ProgramCatalog+L"\\Log")==true)
        {
		CatalogProtocol=ProgramCatalog+L"\\Log";
		}

LabelStartUpdate->Caption="";
LabelNameTable->Caption="";

		TimerHide->Interval=1;
		TimerHide->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
delete glIni;
}
//---------------------------------------------------------------------------
void TMainForm::UpdateBase(void)
{
SaveProtocol("Старт обновления базы!");

DM->Database1->Connected=false;
DM->Database2->Connected=false;
UnicodeString file_ini=ExtractFileDir(Application->ExeName)+"\\Connect.ini";
TIniFile * ini=new TIniFile(file_ini);

DM->Database1->DatabaseName=ini->ReadString("Base1","ConnectString","");
SaveProtocol("База 1"+DM->Database1->DatabaseName);
DM->Database1->ConnectParams->UserName=ini->ReadString("Base1","NameUser","");
DM->Database1->ConnectParams->Password=ini->ReadString("Base1","PasswordUser","");

DM->Database2->DatabaseName=ini->ReadString("Base2","ConnectString","");
SaveProtocol("База 2"+DM->Database2->DatabaseName);
DM->Database2->ConnectParams->UserName=ini->ReadString("Base2","NameUser","");
DM->Database2->ConnectParams->Password=ini->ReadString("Base2","PasswordUser","");

if (ini->ReadString("Base2","UpdateUser","")=="1")
	{
	UpdUser=true;
	}
else
	{
	UpdUser=false;
	}

NameUser=ini->ReadString("Base2","NameUser","");
PasswordUser=ini->ReadString("Base2","PasswordUser","");
ConnectString=ini->ReadString("Base2","ConnectString","");
delete ini;
DM->Database1->Connected=true;
DM->Database2->Connected=true;

StrListTables=new TStringList;

glIni->ReadSections(StrListTables);


	//обновляем форму
	 IndexStrListTables=0;
	 LabelStartUpdate->Caption=L"Старт обновления: "+DateTimeToStr(Now());

	 ButtonUpdate->Enabled=false;
	 ButtonOpenFormSetup->Enabled=false;
	 UnicodeString n_t=glIni->ReadString(StrListTables->Strings[IndexStrListTables],"NameTable","");


	 DM->QueryRecordCount->Close();
	 DM->QueryRecordCount->SQL->Clear();
	 DM->QueryRecordCount->SQL->Add ("select COUNT(*) from "+n_t);
	 DM->QueryRecordCount->ExecQuery();
	 int kol_rec=DM->QueryRecordCount->FieldByName("COUNT")->AsInteger;
	 DM->QueryRecordCount->Close();
	 
	 LabelNameTable->Caption=L"Обновляем таблицу: "+n_t+L". Количество записей:"+IntToStr(kol_rec);
	//запускаем таймер, ждем
	Timer1->Interval=1000;
	Timer1->Enabled=true;





}
//----------------------------------------------------------------------------
void TMainForm::UpdateTable(UnicodeString name_table, UnicodeString name_field_id, TStringList * list)
{

DM->Table1Base->Close();

DM->Table1Base->SQL->Clear();


DM->Table1Base->SQL->Add(GetZaprosViborTable(name_table,name_field_id, list));


DM->Table1Base->ExecQuery();
while(!DM->Table1Base->Eof)
	{
	DM->Element2Base->Close();
    DM->Element2Base->SQL->Clear();
	DM->Element2Base->SQL->Add(GetZaprosElement(name_table,name_field_id, list));
	DM->Element2Base->ExecQuery();
	//сравниваем поля и генерируем запрос обновления
	if (DM->Element2Base->RecordCount==0)
		{ //  вставляем запись
		AnsiString zapros=GetZaprosInsert(name_table,name_field_id, list);
		DM->Query->Close();
		DM->Query->SQL->Clear();
		DM->Query->SQL->Add(zapros);

				try
						{
						DM->Query->ExecQuery();
						DM->TrUpdate2->Commit();
					}

				catch (Exception &exception)
						{
						SaveProtocol(L"Ошибка в модуле DMUribIn->EditRecord при вставке записи \n"
						+exception.Message+L"  \n Запрос:"+zapros
						+"\n");
						DM->TrUpdate2->Rollback();
						}
		DM->Query->Close();
		}
	else
		{  //редактируем запись
        //надо обновить запись сначала проверить есть ли изменения!!!!!!!!
		AnsiString zapros=GetZaprosUpdate(name_table,name_field_id, list);
		if (zapros!="")
				{
				DM->Query->Close();
				DM->Query->SQL->Clear();
				DM->Query->SQL->Add(zapros);
				try
						{
						DM->Query->ExecQuery();
						DM->TrUpdate2->Commit();
						}

				catch (Exception &exception)
						{
						SaveProtocol(L"Ошибка в модуле DMUribIn->EditRecord при редактировании записи \n"
						+exception.Message+L"  \n Запрос:"+zapros
						+L"\n");
						DM->TrUpdate2->Rollback();
						}


				DM->Query->Close();
				}
		}

	DM->Table1Base->Next();
	}

DM->Element2Base->Close();
DM->Table1Base->Close();
}
//-----------------------------------------------------------------------------
UnicodeString TMainForm::GetZaprosViborTable(UnicodeString name_table, UnicodeString name_field_id, TStringList * list)
{
UnicodeString result="";

result= result+L" select "+name_field_id;

for (int i=0;i<list->Count;i++)
	{
	result= result+", "+list->Strings[i];
	}

result= result+L" from "+name_table;


if (name_table=="SGRPNOM")
	{
	result= result+L" order by IDGRPGN ";
	}

if (name_table=="SUSER")
	{
	result= result+L" order by IDGRP_USER ";
	}

return result;
}
//-----------------------------------------------------------------------------
UnicodeString TMainForm::GetZaprosElement(UnicodeString name_table, UnicodeString name_field_id, TStringList * list)
{
UnicodeString result="";
result= result+L" select ";

for (int i=0;i<list->Count;i++)
	{
	result= result+" "+list->Strings[i]+",";
	}
result.Delete(result.Length(),1);  //удаляем последнюю запятую
result= result+L" from "+name_table;
result= result+L" where "+name_field_id+"='"+DM->Table1Base->FieldByName(name_field_id)->AsString+L"'";
return result;
}
//-----------------------------------------------------------------------------
UnicodeString TMainForm::GetZaprosInsert(UnicodeString name_table, UnicodeString name_field_id, TStringList * list)
{
UnicodeString result;
UnicodeString fields=name_field_id;
UnicodeString values=DM->Table1Base->FieldByName(name_field_id)->AsString;

		for (int i=0;i<list->Count;i++)
				{
				UnicodeString name_field=list->Strings[i];
				UnicodeString value_field="";

				//SaveProtocol(name_field + " тип  "+
				//			GetTextTypeField(DM->Table1Base->FieldByName(name_field)->SQLType));


				if (DM->Table1Base->FieldByName(name_field)->SQLType==580)
					{
					value_field=CommaToStringPixel(DM->Table1Base->FieldByName(name_field)->AsString);
					}
				else
					{
					value_field=DM->Table1Base->FieldByName(name_field)->AsString;
					}

						if(value_field!="")
								{
								fields=fields+", "+name_field;
								values=values+", "+"'"+value_field+"'";
                                 }
				}

result=result+L"insert into "+name_table+" ("+fields+")";
result=result+L" values ("+values+")";

return result;

}
//---------------------------------------------------------------------------
UnicodeString TMainForm::GetZaprosUpdate(UnicodeString name_table, UnicodeString name_field_id, TStringList * list)
{
UnicodeString result="";
UnicodeString fields="";

bool comma=false;
bool run_query=false;


		for (int i=0;i<list->Count;i++)
                {
				UnicodeString name_field=list->Strings[i];
				UnicodeString value_field="";

				value_field=DM->Table1Base->FieldByName(name_field)->AsString;

						if (Trim(value_field)!=Trim(DM->Element2Base->FieldByName(name_field)->AsString))
								{
                                run_query=true;
								}

				//SaveProtocol(name_field + " тип  "+
				//			GetTextTypeField(DM->Table1Base->FieldByName(name_field)->SQLType));


						if (DM->Table1Base->FieldByName(name_field)->SQLType==580)
							{
							value_field=CommaToStringPixel(DM->Table1Base->FieldByName(name_field)->AsString);
							}
						else
							{
							value_field=DM->Table1Base->FieldByName(name_field)->AsString;
							}

                        if(value_field!="")
                                {
                                if (comma==false)
                                        {
										fields=name_field+L"='"+value_field+L"'";
                                        comma=true;
                                        }
                                else
                                        {
										fields=fields+L", "+name_field+L"='"+value_field+L"'";
                                        }
                                 }

                }


if (Trim(fields)=="")    //все поля имеют значение пробел
        {                //например элемент справочника где не задано ни одно поле
        run_query=false;
        }

result=result+L" update "+name_table+L" set "+fields+L" where "+
		name_field_id+L"='"+DM->Table1Base->FieldByName(name_field_id)->AsString+L"'";

if (run_query==false) result="";


return result;


}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonUpdateClick(TObject *Sender)
{
UpdateBase();	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
	//останавливаем таймер
	Timer1->Interval=0;
	Timer1->Enabled=false;


if (IndexStrListTables<StrListTables->Count)
	{
	UnicodeString name_table =glIni->ReadString(StrListTables->Strings[IndexStrListTables],"NameTable","");
	UnicodeString name_field_id =glIni->ReadString(StrListTables->Strings[IndexStrListTables],"NameFieldIdTable","");

	TStringList * str_list_fields=new TStringList;
	glIni->ReadSectionValues(StrListTables->Strings[IndexStrListTables], str_list_fields);

	TStringList * spisok_fields=new TStringList;

	for (int j=0;j<str_list_fields->Count;j++)
		{
		UnicodeString value_key="NameTable="+name_table;
		if (str_list_fields->Strings[j]!=value_key)
			{
			value_key=L"NameFieldIdTable="+name_field_id;
			if (str_list_fields->Strings[j]!=value_key)
				{
				UnicodeString value_field_id=glIni->ReadString(StrListTables->Strings[IndexStrListTables],name_field_id,"");
				value_key=name_field_id+"="+value_field_id;
				if (str_list_fields->Strings[j]!=value_key)
					{
					//получаем поля для запроса
					UnicodeString name=str_list_fields->Strings[j].Delete(str_list_fields->Strings[j].Length()-1,2);  //удаляем последнюю "=1"
					spisok_fields->Add(name);
					}
				}
			}
		}

	delete str_list_fields;

	UpdateTable(name_table, name_field_id, spisok_fields);
	delete spisok_fields;

	IndexStrListTables++;

	//обновляем форму
	if (IndexStrListTables<StrListTables->Count)
		{
		UnicodeString n_t=glIni->ReadString(StrListTables->Strings[IndexStrListTables],"NameTable","");
		SaveProtocol(L"Обновляем таблицу: "+n_t) ;
		DM->QueryRecordCount->Close();
		DM->QueryRecordCount->SQL->Clear();
		DM->QueryRecordCount->SQL->Add (L"select COUNT(*) from "+n_t);
		DM->QueryRecordCount->ExecQuery();
		int kol_rec=DM->QueryRecordCount->FieldByName("COUNT")->AsInteger;
		DM->QueryRecordCount->Close();
	 
		LabelNameTable->Caption=L"Обновляем таблицу: "+n_t+L". Количество записей:"+IntToStr(kol_rec);
		SaveProtocol(L"Количество записей:"+IntToStr(kol_rec));
		}
	else
		{

		}

	//запускаем таймер, ждем
	Timer1->Interval=1000;
	Timer1->Enabled=true;
	}
else
	{
	//останавливаем таймер
	Timer1->Interval=0;
	Timer1->Enabled=false;
	delete StrListTables;

	//зарегистрируем пользователей и назначим им роли
	try {
		UpdateUser();
		}
	catch (Exception &exception)
		{
		SaveProtocol("Не удалось обновить пользователей! Ошибка: "+exception.Message);
		}




	LabelNameTable->Caption="Обновление завершено в "+DateTimeToStr(Now())+"! ";
	ButtonUpdate->Enabled=true;
	ButtonOpenFormSetup->Enabled=true;
	SaveProtocol("Обновление завершено!");
	Close();
	}


}
//---------------------------------------------------------------------------
void TMainForm::SaveProtocol(String str)
{
UnicodeString file_name="";
file_name=CatalogProtocol+"\\"+ DateToStr(Date())+".txt";

TkanFile * f=new TkanFile;

str=TimeToStr(Time())+L"  "+str+L"\n";
f->AddString(file_name, str);
delete f;
}
//-----------------------------------------------------------------------------
void __fastcall TMainForm::Timer2Timer(TObject *Sender)
{
//останавливаем таймер
Timer2->Interval=0;
Timer2->Enabled=false;
UpdateBase();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ShowPopupMenuTrayIconClick(TObject *Sender)
{
  //  Восстановление формы.
  MainForm->Visible = true;
  TrayIcon1->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TimerHideTimer(TObject *Sender)
{
TimerHide->Interval=0;
TimerHide->Enabled=false;
TrayIcon1->Visible=true;
TrayIcon1->Hint=MainForm->Caption;
MainForm->Visible = false;
}
//---------------------------------------------------------------------------
void TMainForm::UpdateUser(void)
{

if (UpdUser==false)	return;
if (NameUser!="SYSDBA") return;

SaveProtocol(L"Обновляем пользователей!");

bool error=false;

	try
		{
		DM->pFIBSecurityService1->Active = false ;
		DM->pFIBSecurityService1->Params->Clear();
		DM->pFIBSecurityService1->Params->Add("user_name="+NameUser);
		DM->pFIBSecurityService1->Params->Add("password="+PasswordUser);
		AnsiString server_name=ConnectString;
		int num=server_name.AnsiPos(":");
		server_name=server_name.SetLength(num-1);
		DM->pFIBSecurityService1->ServerName=server_name;
		DM->pFIBSecurityService1->Protocol=TCP;
		DM->pFIBSecurityService1->Active = true ;
		}
	catch(Exception &exception)
		{
		error=true;
		SaveProtocol("Ошибка! "+exception.Message);
		}

if (error==true)
	{
	return;
	}
		
//устанавливаем пароли 123
//всем кроме SYSDBA
DM->SprUser->Open();
DM->SprUser->First();

while(!DM->SprUser->Eof)
	{
	if (DM->SprUserNAME_USER->AsString!="SYSDBA")
		{
		if (DM->SprUserNAME2_USER->AsString!="")
			{
			int id=0;
			try {
				DM->pFIBSecurityService1->Active = false ;
				DM->pFIBSecurityService1->SecurityAction=ActionDisplayUser;
				DM->pFIBSecurityService1->Active = true ;
				DM->pFIBSecurityService1->DisplayUser(DM->SprUserNAME2_USER->AsString);
				id=DM->pFIBSecurityService1->UserInfoCount;
				}
			catch (Exception &exception)
				{
				SaveProtocol(L"Не удалось получить информацию о пользователе:"+DM->SprUserNAME2_USER->AsString+L" Ошибка: "+exception.Message);
				}

			if (id < 1)
				{ //добавляем пользователя
				SaveProtocol(L"Добавляем пользователя:"+DM->SprUserNAME2_USER->AsString);

				try {
					DM->pFIBSecurityService1->Active = false ;
					DM->pFIBSecurityService1->SecurityAction=ActionAddUser;
					DM->pFIBSecurityService1->Active = true ;
					DM->pFIBSecurityService1->UserName = DM->SprUserNAME2_USER->AsString;
					DM->pFIBSecurityService1->Password = "123";
					DM->pFIBSecurityService1->FirstName = DM->SprUserNAME2_USER->AsString;
					DM->pFIBSecurityService1->MiddleName = DM->SprUserNAME2_USER->AsString;
					DM->pFIBSecurityService1->LastName = DM->SprUserNAME2_USER->AsString;
					DM->pFIBSecurityService1->AddUser();
					}
				catch (Exception &exception)
					{
					SaveProtocol(L"Не удалось добавить пользователя! Ошибка: "+exception.Message);
					}
				}
			else
				{//редактируем пользователя
				SaveProtocol(L"Редактируем пользователя:"+DM->SprUserNAME2_USER->AsString);

				try
					{
					DM->pFIBSecurityService1->Active = false ;
					DM->pFIBSecurityService1->SecurityAction=ActionModifyUser;
					DM->pFIBSecurityService1->Active = true ;
					DM->pFIBSecurityService1->UserName = DM->SprUserNAME2_USER->AsString;
					DM->pFIBSecurityService1->Password = "123";
					DM->pFIBSecurityService1->FirstName = DM->SprUserNAME2_USER->AsString;
					DM->pFIBSecurityService1->MiddleName = DM->SprUserNAME2_USER->AsString;
					DM->pFIBSecurityService1->LastName = DM->SprUserNAME2_USER->AsString;
					DM->pFIBSecurityService1->ModifyUser();
					}
				catch (Exception &exception)
					{
					SaveProtocol(L"Не удалось изменить параметры пользователя! Ошибка: "+exception.Message);
					}
				}
			}
		}
	DM->SprUser->Next();
	}

	
//назначаем роли
int kol=0;
DM->SprUser->First();
while(!DM->SprUser->Eof)
	{
	if (DM->SprUserNAME_USER->AsString!="SYSDBA")
		{
		if (DM->SprUserNAME2_USER->AsString!="")
			{
			AnsiString role_user= Trim(DM->SprUserROLE_SGRPUSER->AsString);
			if (role_user.Length()>0)
				{
				DM->Query->SQL->Clear();
				DM->Query->SQL->Add(L"grant "+role_user+L" to "+Trim(DM->SprUserNAME2_USER->AsString));
				DM->Query->ExecQuery();
				DM->TrUpdate2->Commit();
				kol++;
				}
			}
		}
	DM->SprUser->Next();
	}
SaveProtocol(L"Назначены роли "+IntToStr(kol)+L" пользователям!");
}
//---------------------------------------------------------------------------
UnicodeString TMainForm::CommaToStringPixel(UnicodeString value)
{
UnicodeString result="";

for(int i=1;i<=value.Length();i++)
        {
		if (value[i]==',')
                {
                result=result+".";

                }
        else
                {
				result=result+value[i];
                }
		}
return result;
}
//-----------------------------------------------------------------------------
UnicodeString TMainForm::GetTextTypeField(int type)
{

switch (type)
 {
	case ftUnknown:			return  "ftUnknown";
	case ftString:			return  "ftString";
	case ftSmallint:		return  "ftSmallint";
	case ftInteger:			return  "ftInteger";
	case ftWord:			return  "ftWord";
	case ftBoolean:			return  "ftBoolean";
	case ftFloat:			return  "ftFloat";
	case ftCurrency:		return  "ftCurrency";
	case ftBCD:				return  "ftBCD";
	case ftDate:			return  "ftDate";
	case ftTime:			return  "ftTime";
	case ftDateTime:		return  "ftDateTime";
	case ftBytes:			return  "ftBytes";
	case ftVarBytes:		return  "ftVarBytes";
	case ftAutoInc:			return  "ftAutoInc";
	case ftBlob:			return  "ftBlob";
	case ftMemo:			return  "ftMemo";
	case ftGraphic:			return  "ftGraphic";
	case ftFmtMemo:			return  "ftFmtMemo";
	case ftParadoxOle:		return  "ftParadoxOle";
	case ftDBaseOle:		return  "ftDBaseOle";
	case ftTypedBinary:		return  "ftTypedBinary";
	case ftCursor:			return  "ftCursor";
	case ftFixedChar:		return  "ftFixedChar";
	case ftWideString:		return  "ftWideString";
	case ftLargeint:		return  "ftLargeint";
	case ftADT:				return  "ftADT";
	case ftArray:			return  "ftArray";
	case ftReference:		return  "ftReference";
	case ftDataSet:			return  "ftDataSet";
	case ftOraBlob:			return  "ftOraBlob";
	case ftOraClob:			return  "ftOraClob";
	case ftVariant:			return  "ftVariant";
	case ftInterface:		return  "ftInterface";
	case ftIDispatch:		return  "ftIDispatch";
	case ftGuid:			return  "ftGuid";

	default:	return  "Неизвестный "+IntToStr(type);
 }

}
//---------------------------------------------------------------------------
