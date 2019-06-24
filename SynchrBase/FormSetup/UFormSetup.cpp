//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormSetup.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDBEdit"
#pragma link "cxEdit"
#pragma link "cxGroupBox"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxTextEdit"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxButtons"
#pragma link "cxDBLookupComboBox"
#pragma link "cxCheckBox"
#pragma link "cxPC"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"
TFormSetup *FormSetup;
extern TIniFile * glIni;
//---------------------------------------------------------------------------
__fastcall TFormSetup::TFormSetup(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormSetup::FormCreate(TObject *Sender)
{
UnicodeString file_ini=ExtractFileDir(Application->ExeName)+L"\\Connect.ini";
TIniFile * ini=new TIniFile(file_ini);

ConnectStringcxTextEdit->Text=ini->ReadString("Base1","ConnectString","");
NameUsercxTextEdit->Text=ini->ReadString("Base1","NameUser","");
PasswordUsercxTextEdit->Text=ini->ReadString("Base1","PasswordUser","");

ConnectString2cxTextEdit->Text=ini->ReadString("Base2","ConnectString","");
NameUser2cxTextEdit->Text=ini->ReadString("Base2","NameUser","");
PasswordUser2cxTextEdit->Text=ini->ReadString("Base2","PasswordUser","");


if (ini->ReadString("Base2","UpdateUser","")=="1")
	{
	UpdateUsercxCheckBox->Checked=true;
	}
else
	{
	UpdateUsercxCheckBox->Checked=false;
	}

delete ini;

}
//---------------------------------------------------------------------------
void __fastcall TFormSetup::FormClose(TObject *Sender, TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TFormSetup::cxButtonConnectClick(TObject *Sender)
{
DM->Database1->DatabaseName=ConnectStringcxTextEdit->Text;
DM->Database1->ConnectParams->UserName=NameUsercxTextEdit->Text;
DM->Database1->ConnectParams->Password=PasswordUsercxTextEdit->Text;
DM->Database1->Connected=true;
DM->Tables->Active=true;
DM->Fields->Active=true;
}
//---------------------------------------------------------------------------
void __fastcall TFormSetup::cxButton1Click(TObject *Sender)
{
TcxCustomDataController *dc = cxGridTablesTableView1->DataController;
dc->AppendRecord();
dc->Values[dc->RowCount-1][cxGridTablesTableView1Number->Index] = dc->RowCount+1;
dc->Values[dc->RowCount-1][cxGridTablesTableView1NameTable->Index] = " ";
dc->Values[dc->RowCount-1][cxGridTablesTableView1NameFieldId->Index] = " ";
}
//---------------------------------------------------------------------------
void __fastcall TFormSetup::cxButtonUpdateFieldsClick(TObject *Sender)
{
UpdateFields();
}
//---------------------------------------------------------------------------
void TFormSetup::UpdateForm(void)
{
TcxCustomDataController *dc_table = cxGridTablesTableView1->DataController;

dc_table->BeginUpdate();
	for (int i=dc_table->RecordCount;i>0;i--)
		{
		dc_table->DeleteRecord(i-1);
		}
dc_table->EndUpdate();


TStringList * str_list=new TStringList;

glIni->ReadSections(str_list);

for (int i=0;i<str_list->Count;i++)
	{

	dc_table->AppendRecord();
	dc_table->Values[dc_table->RowCount-1][cxGridTablesTableView1NameTable->Index] =
										glIni->ReadString(str_list->Strings[i],"NameTable","");
	dc_table->Values[dc_table->RowCount-1][cxGridTablesTableView1NameFieldId->Index] =
										glIni->ReadString(str_list->Strings[i],"NameFieldIdTable","");
	dc_table->Values[dc_table->RowCount-1][cxGridTablesTableView1Number->Index] = str_list->Strings[i];


	}

delete str_list;

}
//--------------------------------------------------------------------------
void TFormSetup::SaveInfoTable(void)
{
TcxCustomDataController *dc_table = cxGridTablesTableView1->DataController;
TcxCustomDataController *dc_field = cxGridFieldsTableView1->DataController;
int row=cxGridTablesTableView1->Controller->FocusedRowIndex;

UnicodeString name_table=dc_table->Values[row][cxGridTablesTableView1NameTable->Index];
UnicodeString section=dc_table->Values[row][cxGridTablesTableView1Number->Index];
UnicodeString name_field_id=dc_table->Values[row][cxGridTablesTableView1NameFieldId->Index];

glIni->EraseSection(section);

glIni->WriteString(section,L"NameTable",name_table);
glIni->WriteString(section,L"NameFieldIdTable",name_field_id);

for (int i=0; i<dc_field->RowCount; i++)
	{
	int out = dc_field->Values[i][cxGridFieldsTableView1Out->Index];
	UnicodeString name_field=dc_field->Values[i][cxGridFieldsTableView1NameField->Index];
	if (out==1)
		{
		glIni->WriteString(section,name_field,"1");
		}
	}

}
//---------------------------------------------------------------------------
void __fastcall TFormSetup::cxButton3Click(TObject *Sender)
{
SaveInfoTable();
}
//---------------------------------------------------------------------------

void __fastcall TFormSetup::cxButton4Click(TObject *Sender)
{
UpdateForm();	
}
//---------------------------------------------------------------------------

void __fastcall TFormSetup::cxButtonDisconnectClick(TObject *Sender)
{
DM->Database1->Connected=false;	
}
//---------------------------------------------------------------------------

void __fastcall TFormSetup::cxButton5Click(TObject *Sender)
{
UnicodeString file_ini=ExtractFileDir(Application->ExeName)+L"\\Connect.ini";
TIniFile * ini=new TIniFile(file_ini);

ini->WriteString("Base1","ConnectString",ConnectStringcxTextEdit->Text);
ini->WriteString("Base1","NameUser",NameUsercxTextEdit->Text);
ini->WriteString("Base1","PasswordUser",PasswordUsercxTextEdit->Text);

ini->WriteString("Base2","ConnectString",ConnectString2cxTextEdit->Text);
ini->WriteString("Base2","NameUser",NameUser2cxTextEdit->Text);
ini->WriteString("Base2","PasswordUser",PasswordUser2cxTextEdit->Text);

if (UpdateUsercxCheckBox->Checked==true)
	{
	ini->WriteString("Base2","UpdateUser","1");
	}
else
	{
	ini->WriteString("Base2","UpdateUser","1");
	}

delete ini;
}
//---------------------------------------------------------------------------


void TFormSetup::UpdateFields(void)
{
 TcxCustomDataController *dc = cxGridFieldsTableView1->DataController;

int row=cxGridTablesTableView1->Controller->FocusedRowIndex;
UnicodeString name_table=cxGridTablesTableView1->DataController->Values[row][cxGridTablesTableView1NameTable->Index];
UnicodeString number=cxGridTablesTableView1->DataController->Values[row][cxGridTablesTableView1Number->Index];
TLocateOptions SearchOptions;
DM->Tables->Locate("TABLE_NAME", name_table,SearchOptions);

cxGridTablesTableView1->DataController->Values[row][cxGridTablesTableView1NameFieldId->Index]=
		DM->TablesFIELD_NAME->AsString;


dc->BeginUpdate();
	for (int i=dc->RecordCount;i>0;i--)
		{
		dc->DeleteRecord(i-1);
		}
dc->EndUpdate();

DM->Fields->First();
while(!DM->Fields->Eof)
	{
	dc->AppendRecord();
	dc->Values[dc->RowCount-1][cxGridFieldsTableView1NameField->Index] = DM->FieldsRDBFIELD_NAME->AsString;

	UnicodeString str_out=glIni->ReadString(number,
									DM->FieldsRDBFIELD_NAME->AsString,"");

	if (str_out=="1")
		{
		 dc->Values[dc->RowCount-1][cxGridFieldsTableView1Out->Index] = 1;
		}
	else
		{
		 dc->Values[dc->RowCount-1][cxGridFieldsTableView1Out->Index] = 0;
		}


	DM->Fields->Next();
	}


}
//---------------------------------------------------------------------------


