//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <fstream.h>
#include "UFormaSetNachValues.h"
#include "UDataModuleMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
extern TDataModuleMain *glDM;
//---------------------------------------------------------------------------
__fastcall TFormaSetNachValues::TFormaSetNachValues(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaSetNachValues::FormCreate(TObject *Sender)
{
NachValueGenEdit->Text="";
NachCodeNomEdit->Text="";
NachCodeEdEdit->Text="";
NachCodeDiscountCardEdit->Text="";

Query->Close();
Query->SQL->Clear();
Query->SQL->Add("select setup.value_setup from setup where setup.id_setup=3");
Query->ExecQuery();
NachValueGenEdit->Text=Query->FieldByName("VALUE_SETUP")->AsString;

Query->Close();

}
//---------------------------------------------------------------------------
void __fastcall TFormaSetNachValues::ButtonSetValueGenClick(TObject *Sender)
{

UnicodeString V="Внимание! Установка значений генераторов может повредить информационную базу! Продолжить? ";
UnicodeString Z="Продолжить?";
if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
	{
	return;
	}

V="Внимание!Будут установлены все генераторы в значение "+
				NachValueGenEdit->Text+"00000000000000  ! Продолжить? ";
Z="Продолжить?";
if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
	{
	return;
	}

V="Внимание!Будут установлены все генераторы в новое значение в базе "+
				glDM->ConnectString+"  ! Продолжить? ";
Z="Продолжить?";
if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
	{
	return;
	}


	TableGenerators->Active=true;
	TableGenerators->First();

	while(!TableGenerators->Eof)
		{
		UnicodeString name_generator=Trim(TableGenerators->FieldByName("RDB$GENERATOR_NAME")->AsString);
		if ( name_generator=="GEN_SDISCOUNT_CARD_CODE" ||
					name_generator=="GEN_SED_CODE"     ||
					name_generator=="GEN_SNOM_CODE"	)
			{
				TableGenerators->Next();
				continue;
			}

		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add("SET GENERATOR "+name_generator
						+" TO "+NachValueGenEdit->Text+"00000000000000");
		try
			{
			QueryUpdate->ExecQuery();
			TrUpdate->Commit();
			}
		catch (Exception &exception)
				{
				TrUpdate->Rollback();
				ShowMessage("Ошибка установки! "+exception.Message);
				}
		QueryUpdate->Close();
		TableGenerators->Next();
		}

	ShowMessage("Выполнено!");
	TableGenerators->Active=false;

}
//---------------------------------------------------------------------------
void __fastcall TFormaSetNachValues::ButtonNachCodeNomClick(TObject *Sender)
{

		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add("SET GENERATOR  GEN_SNOM_CODE TO "+NachCodeNomEdit->Text);
		try
			{
			QueryUpdate->ExecQuery();
			TrUpdate->Commit();
			ShowMessage("Выполнено!");
			}
		catch (Exception &exception)
				{
				TrUpdate->Rollback();
				ShowMessage("Ошибка установки! "+exception.Message);
				}
	QueryUpdate->Close();

}
//---------------------------------------------------------------------------
void __fastcall TFormaSetNachValues::ButtonNachCodeEdClick(TObject *Sender)
{

		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add("SET GENERATOR  GEN_SED_CODE TO "+NachCodeEdEdit->Text);
		try
			{
			QueryUpdate->ExecQuery();
			TrUpdate->Commit();
			ShowMessage("Выполнено!");
			}
		catch (Exception &exception)
				{
				TrUpdate->Rollback();
				ShowMessage("Ошибка установки! "+exception.Message);
				}
	QueryUpdate->Close();

}
//---------------------------------------------------------------------------
void __fastcall TFormaSetNachValues::ButtonNachCodeDiscountCardClick(
      TObject *Sender)
{

		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add("SET GENERATOR  GEN_SDISCOUNT_CARD_CODE TO "+NachCodeDiscountCardEdit->Text);
		try
			{
			QueryUpdate->ExecQuery();
			TrUpdate->Commit();
			ShowMessage("Выполнено!");
			}
		catch (Exception &exception)
				{
				TrUpdate->Rollback();
				ShowMessage("Ошибка установки! "+exception.Message);
				}
	QueryUpdate->Close();


}
//---------------------------------------------------------------------------
void __fastcall TFormaSetNachValues::ButtonSetNulGenClick(TObject *Sender)
{
UnicodeString V="Внимание! Установка значений генераторов может повредить информационную базу! Продолжить? ";
UnicodeString Z="Продолжить?";
if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
	{
	return;
	}

V="Внимание!Будут установлены все генераторы имеющие значение 0 в значение "+
				NachValueGenEdit->Text+"00000000000000  ! Продолжить? ";
Z="Продолжить?";
if (Application->MessageBox(V.c_str(),Z.c_str(),MB_YESNO)==IDNO)
	{
	return;
	}


	TableGenerators->Active=true;
	TableGenerators->First();

	while(!TableGenerators->Eof)
		{
		UnicodeString name_generator=Trim(TableGenerators->FieldByName("RDB$GENERATOR_NAME")->AsString);
		if ( name_generator=="GEN_SDISCOUNT_CARD_CODE" ||
					name_generator=="GEN_SED_CODE"     ||
					name_generator=="GEN_SNOM_CODE"	)
			{
				TableGenerators->Next();
				continue;
			}

		//проверим значение генераторов
		Query->Close();
		Query->SQL->Clear();
		Query->SQL->Add("SELECT GEN_ID("+name_generator+",0) from RDB$DATABASE");
		Query->ExecQuery();
		__int64 value_gen=0;
		if(Query->FieldByName("GEN_ID")->AsString=="")
			{

			}
		else
			{
			value_gen=Query->FieldByName("GEN_ID")->AsInt64;
			}

		if (value_gen==0)
			{ //обновляем значение генератора
			//ShowMessage("Генератор "+name_generator+" значение "+value_gen);
			QueryUpdate->SQL->Clear();
			QueryUpdate->SQL->Add("SET GENERATOR "+name_generator
						+" TO "+NachValueGenEdit->Text+"00000000000000");
			try
				{
				QueryUpdate->ExecQuery();
				TrUpdate->Commit();
				}
			catch (Exception &exception)
				{
				TrUpdate->Rollback();
				ShowMessage("Ошибка установки! "+exception.Message);
				}
			QueryUpdate->Close();
			}
		Query->Close();
		TableGenerators->Next();
		}

	ShowMessage("Выполнено!");
	TableGenerators->Active=false;
}
//---------------------------------------------------------------------------

void __fastcall TFormaSetNachValues::ButtonCheckNullGenClick(TObject *Sender)
{
UnicodeString message="Необходимо обновить следующие значения генераторов: \n";
	TableGenerators->Active=true;
	TableGenerators->First();

	while(!TableGenerators->Eof)
		{
		UnicodeString name_generator=Trim(TableGenerators->FieldByName("RDB$GENERATOR_NAME")->AsString);
		if ( name_generator=="GEN_SDISCOUNT_CARD_CODE" ||
					name_generator=="GEN_SED_CODE"     ||
					name_generator=="GEN_SNOM_CODE"	)
			{
				TableGenerators->Next();
				continue;
			}

		//проверим значение генераторов
		Query->Close();
		Query->SQL->Clear();
		Query->SQL->Add("SELECT GEN_ID("+name_generator+",0) from RDB$DATABASE");
		Query->ExecQuery();
		__int64 value_gen=0;
		if(Query->FieldByName("GEN_ID")->AsString=="")
			{

			}
		else
			{
			value_gen=Query->FieldByName("GEN_ID")->AsInt64;
			}

		if (value_gen==0)
			{ //обновляем значение генератора
			message=message+name_generator+"\n";

			}
		Query->Close();
		TableGenerators->Next();
		}

TableGenerators->Active=false;

ShowMessage(message);

}
//---------------------------------------------------------------------------

void __fastcall TFormaSetNachValues::Button1Click(TObject *Sender)
{
UnicodeString message="Необходимо обновить следующие значения генераторов: \n";
	TableGenerators->Active=true;
	TableGenerators->First();

	while(!TableGenerators->Eof)
		{
		UnicodeString name_generator=Trim(TableGenerators->FieldByName("RDB$GENERATOR_NAME")->AsString);

		//проверим значение генераторов
		Query->Close();
		Query->SQL->Clear();
		Query->SQL->Add("SELECT GEN_ID("+name_generator+",0) from RDB$DATABASE");
		Query->ExecQuery();

		message=message+"SET GENERATOR "+
						name_generator+" TO "+Query->FieldByName("GEN_ID")->AsString+";\n";

		Query->Close();
		TableGenerators->Next();
		}

TableGenerators->Active=false;

if(SaveDialog1->Execute())
		{
		TStringList *sl=new TStringList();
		sl->Text=message;
		sl->SaveToFile(SaveDialog1->FileName);
		delete sl;
		}

}
//---------------------------------------------------------------------------

