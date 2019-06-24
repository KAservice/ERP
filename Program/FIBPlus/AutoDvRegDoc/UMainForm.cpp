//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

//---------------------------------------------------------------------------

#include "UMainForm.h"
#include "UGlobalFunction.h"
#include "UkanTxtFile.h"
#include "UkanFile.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "pFIBDatabase"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"
TMainForm *MainForm;
extern UnicodeString glGetVersionProgramFile();
extern UnicodeString glGetNameProcedureCancelDvReg(UnicodeString type_doc);
extern UnicodeString glGetNameProcedureDvReg(UnicodeString type_doc);
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
Zapusk=true;
AnsiString FileIni=Application->ExeName;
FileIni=FileIni.SetLength(FileIni.Length()-4)+".ini";
Ini=new TIniFile(FileIni);


//������� ������� ����������
AnsiString ProgramCatalog=ExtractFileDir(Application->ExeName);
if (DirectoryExists(ProgramCatalog+"\\Log")==false)
        {
        CreateDir(ProgramCatalog+"\\Log");
        }

if (DirectoryExists(ProgramCatalog+"\\Log")==true)
        {
        CatalogProtocol=ProgramCatalog+"\\Log";
        }

glSaveProtocol("������ ��������� �������������� ����������!");
Database->Connected=false;
UnicodeString connect_string=Ini->ReadString("InfBase","ConnectString","");
UnicodeString name_user=Ini->ReadString("User","NameUser","");
UnicodeString password_user=Ini->ReadString("User","Password","");

glSaveProtocol("������ �����������: "+Ini->ReadString("InfBase","ConnectString",""));
UnicodeString text_error="";
bool error=false;
try
		{
		Database->DBName=connect_string;
		if (name_user=="SYSDBA")
			{

			Database->DBParams->Clear();
			Database->DBParams->Add(" user_name="+name_user);
			Database->DBParams->Add(" lc_ctype=UTF8");
			Database->DBParams->Add(" password="+password_user);
			Database->Connected=true;
			}
		else
			{//������������ � ���. �������, �������� ���� � ��� ������������
			Database->DBParams->Clear();
			Database->DBParams->Add(" user_name=USERINFO");
			Database->DBParams->Add(" lc_ctype=UTF8");
			Database->DBParams->Add(" sql_role_name=ROLE_USERINFO");
			Database->DBParams->Add(" password=123");
			Database->Connected=true;

			Query->Close();
			Query->SQL->Clear();
			Query->SQL->Add(" select NAME2_USER, IDGRP_USER from SUSER where NAME_USER='"+name_user+"'");
			Query->ExecQuery();

			UnicodeString name_user2=Query->FieldByName("NAME2_USER")->AsString;
			__int64 idgrp_user=Query->FieldByName("IDGRP_USER")->AsInt64;
			Query->Close();
			Query->SQL->Clear();
			Query->SQL->Add(" select ROLE_SGRPUSER from SGRPUSER where ID_SGRPUSER="+IntToStr(idgrp_user));
			Query->ExecQuery();

			UnicodeString role_user=Query->FieldByName("ROLE_SGRPUSER")->AsString;
			Query->Close();

			Database->Connected=false;

			Database->DBParams->Clear();
			Database->DBParams->Add(" user_name="+name_user2);
			Database->DBParams->Add(" lc_ctype=UTF8");
			Database->DBParams->Add(" sql_role_name="+role_user);
			Database->DBParams->Add(" password="+password_user);
			Database->Connected=true;
			}

        }
catch (Exception &exception)
		{
		error=true;
		text_error=exception.Message;
		Database->Connected=false;
		}


if (error==true)
        {
		glSaveProtocol("�� ������� ������������ � �������������� ����! ������ :"+text_error);
		Memo1->Lines->Add("�� ������� ������������ � �������������� ����! ������: "+text_error);
		return;
        }

StatusBar1->Panels->Items[0]->Text=Ini->ReadString("User","NameUser","");
StatusBar1->Panels->Items[1]->Text=Ini->ReadString("InfBase","ConnectString","");

glSaveProtocol("������ ���������: "+glGetVersionProgramFile());
Memo1->Lines->Add("������ ���������: "+glGetVersionProgramFile());
//-------------------------
PosGrPosled=0;
PosFirstNoDvRegDoc=0;
PosZapretaRedakt=0;
PosStart=0;
PosNull=EncodeDate(2000,1,1);

//��������� ������� ������ �� ���� ������� ��������������
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(" select VALUE_TIMESTAMP_SETUP from SETUP where ID_SETUP=13");
Query->ExecQuery();

if (Query->FieldByName("VALUE_TIMESTAMP_SETUP")->AsString=="")
		{
		}
else
		{
		PosZapretaRedakt=Query->FieldByName("VALUE_TIMESTAMP_SETUP")->AsDateTime;
		}
Query->Close();
//���������� ��������� ���� �� ������� ������������������

Query->SQL->Clear();
Query->SQL->Add(" select VALUE_TIMESTAMP_SETUP from SETUP where ID_SETUP=15");
Query->ExecQuery();
if (Query->FieldByName("VALUE_TIMESTAMP_SETUP")->AsString=="" )
        {
        }
else
        {
		PosGrPosled=Query->FieldByName("VALUE_TIMESTAMP_SETUP")->AsDateTime;
        }
Query->Close();

//���������� ��������� ���� �� ������� �� ������������ ���������

AnsiString zapros="select IDDOC, POSDOC from GALLDOC where";
zapros=zapros+" (PRDOC=0 or PRDOC IS NULL)";

if (PosZapretaRedakt > PosNull)
        {
		zapros=zapros+" and POSDOC>'"+DateTimeToStr(PosZapretaRedakt)+"'";
        }
zapros=zapros+" order by POSDOC";
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(zapros);
Query->ExecQuery();
if (!Query->Eof)
        {
		PosFirstNoDvRegDoc=Query->FieldByName("POSDOC")->AsDateTime;
        }
Query->Close();

glSaveProtocol("������� ������� ��������������:"+DateTimeToStr(PosZapretaRedakt));
glSaveProtocol("������� ������� ������������������:"+DateTimeToStr(PosGrPosled));
glSaveProtocol("������� ������� �������������� ���������:"+DateTimeToStr(PosFirstNoDvRegDoc));

Memo1->Lines->Add("������� ������� ��������������:"+DateTimeToStr(PosZapretaRedakt));
Memo1->Lines->Add("������� ������� ������������������:"+DateTimeToStr(PosGrPosled));
Memo1->Lines->Add("������� ������� �������������� ���������:"+DateTimeToStr(PosFirstNoDvRegDoc));

if (PosGrPosled < PosNull &&  PosFirstNoDvRegDoc < PosNull)
	{ //��������� ��������� �� ����
	Zapusk=false;
	glSaveProtocol("������������������ ���������� ���������� �� ��������!");
	Memo1->Lines->Add("������������������ ���������� ���������� �� ��������!");
	Memo1->Lines->Add("��������� ����� ������� ����� 60 ������!");
	return;
	}

if(PosGrPosled>PosNull)
	{
	if (PosFirstNoDvRegDoc>PosNull)
		{
		if (PosGrPosled>PosFirstNoDvRegDoc)
			{
			PosStart=PosFirstNoDvRegDoc;
			}
		else
			{
			PosStart=PosGrPosled;
			}
		}
	else
		{
		PosStart=PosGrPosled;
		}
	}
else  //��� ��. ��������
	{
	if (PosFirstNoDvRegDoc>PosNull)
		{
		 PosStart=PosFirstNoDvRegDoc;
		}
	else  //��� ��. ��������, ��� ��� ������� ���
		{

		}
	}

//������ ������� � ����� �������
if (PosZapretaRedakt>PosNull)//������ ������� �������
	{
	if(PosStart<PosZapretaRedakt)
		{
		PosStart=PosZapretaRedakt;
		glSaveProtocol("������� ������ ���������� ������ ���� ������� ��������������! �������� � ���� �������");
		Memo1->Lines->Add("������� ������ ���������� ������ ���� ������� ��������������!");
		}
	}

glSaveProtocol("������� ������ ��������� ����������:"+DateTimeToStr(PosStart));
Memo1->Lines->Add("������� ������ ��������� ����������:"+DateTimeToStr(PosStart));

if (Zapusk==true)
		{
        Memo1->Lines->Add("�������������� ���������� ����� �������� ����� 60 ������!");
		}

AnsiString regime=Ini->ReadString("Setup","Regime","");
if (regime=="OnlyDvReg")
	{
	glSaveProtocol("�������� ������ ������������� ��������� ��� �������������� ������������������.");
	Memo1->Lines->Add("�������� ������ ������������� ��������� ��� �������������� ������������������");
	Query->Close();
	Query->SQL->Clear();

	AnsiString zapros="select count(IDDOC) as COUNTREC from GALLDOC ";
	zapros=zapros+" where (PRDOC=0 or PRDOC IS NULL)  and POSDOC>=:PARAM_POSDOC";
	Query->SQL->Add(zapros);

	Query->ParamByName("PARAM_POSDOC")->AsDateTime=PosStart;
	Query->ExecQuery();
	glSaveProtocol("���������� ��������  "+Query->FieldByName("COUNTREC")->AsString+" ����������");
	Memo1->Lines->Add("���������� ��������  "+Query->FieldByName("COUNTREC")->AsString+" ����������");
	Query->Close();
	}


}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
glSaveProtocol("��������� ������!");
delete Ini;

}
//---------------------------------------------------------------------------
bool TMainForm::SetZapretProved (void)
{
bool result=false;

		QueryUpdate->Close();
		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(" update setup set VALUE_SETUP=1 where ID_SETUP=14");
		try
			{
			QueryUpdate->ExecQuery();
			TransactionUpdate->Commit();
			glSaveProtocol("���������� ������ ���������� ����������!");
			result=true;
			}
		catch (Exception &exception)
				{
				result=false;
				TransactionUpdate->Rollback();
				glSaveProtocol("������ ��������� ������� ����������! "+exception.Message);
				}
		QueryUpdate->Close();

return result;
}
//---------------------------------------------------------------------------
bool TMainForm::DeleteZapretProved (void)
{
bool result=false;

		QueryUpdate->Close();
		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(" update setup set VALUE_SETUP=null where ID_SETUP=14");
		try
			{
			QueryUpdate->ExecQuery();
			TransactionUpdate->Commit();
			glSaveProtocol("����� ������ ���������� ����������!");
			result=true;
			}
		catch (Exception &exception)
				{
				result=false;
				TransactionUpdate->Rollback();
				glSaveProtocol("������ ������ ������� ����������! "+exception.Message);
				}
		QueryUpdate->Close();

return result;
}
//---------------------------------------------------------------------------
bool TMainForm::DeleteGrPosled (void)
{
bool result=false;

		QueryUpdate->Close();
		QueryUpdate->SQL->Clear();
		QueryUpdate->SQL->Add(" update setup set VALUE_TIMESTAMP_SETUP=null where ID_SETUP=15");
		try
			{
			QueryUpdate->ExecQuery();
			TransactionUpdate->Commit();
			glSaveProtocol("������� ������� ������������������!");
			result=true;
			}
		catch (Exception &exception)
				{
				result=false;
				TransactionUpdate->Rollback();
				glSaveProtocol("������ �������� ������� ������������������! "+exception.Message);
				}
		QueryUpdate->Close();

return result;
}
//---------------------------------------------------------------------------
void TMainForm::DvRegAllDoc(void)
{
//��������� ������ ���������� ����������
SetZapretProved ();

GurAllDoc->Active=false;
GurAllDoc->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosStart;
GurAllDoc->ParamByName("PARAM_DATE_CON")->AsDateTime=Now()+1;
GurAllDoc->Active=true;


Memo1->Lines->Add("�������� ���������� ����������!");
if (CanceDvRegAllDoc()==false)
        {
		glSaveProtocol("���������� �������������� ������������������! ��������� ������ ���������� ��������� � �������!");
        Memo1->Lines->Add("���������� �������������� ������������������!");
        }


Memo1->Lines->Add("�������� ���������!");
GurAllDoc->Last();
ProgressBar1->Max=GurAllDoc->RecordCount;
ProgressBar1->Step=1;

AnsiString message;
int num=0;
int num_out=0;
GurAllDoc->First();
while (!GurAllDoc->Eof)
		{
				try
                        {
						if (RunComandDvRegDoc(Trim(GurAllDocTDOC->AsString),
								GurAllDocIDDOC->AsInt64)!=true)
                                {
								message="�� ������� �������� �������� "+
								glGetNameDoc(GurAllDocTDOC->AsString)+
								"  �"+GurAllDocNUMDOC->AsString+
								" �� "+GurAllDocPOSDOC->AsString;
								glSaveProtocol(message);
								Memo1->Lines->Add(message);
                                }
						}
                catch (Exception &exception)
                        {

						message="������ ���  ���������� ��������� \n"+
						glGetNameDoc(GurAllDocTDOC->AsString)+"  �"+GurAllDocNUMDOC->AsString+
						" �� "+GurAllDocPOSDOC->AsString+
                        "  "+exception.Message;
                        glSaveProtocol(message);
						Memo1->Lines->Add(message);

                        }



		GurAllDoc->Next();
		num++;
		num_out++;
		ProgressBar1->StepIt();
		if (num_out==500)
			{
			glSaveProtocol("���������� ����������:"+IntToStr(num));
			num_out=0;
			}
		}
glSaveProtocol("��������� "+IntToStr(num)+" ����������");


//������ ���������� ������������ ����� ��������� ���������
//���������� ��������� ���� �� ������� �� ������������ ���������
Query->Close();
Query->SQL->Clear();
AnsiString zapros="select IDDOC, POSDOC from GALLDOC where";
zapros=zapros+" (PRDOC=0 or PRDOC IS NULL)";
zapros=zapros+" and POSDOC>'"+DateTimeToStr(Now()-1)+"'";
//zapros=zapros+" AND TDOC in ("+glStringFullTypeDoc+" ) ";
zapros=zapros+" order by POSDOC";
Query->SQL->Add(zapros);
Query->ExecQuery();

PosStart=0;

if (!Query->Eof)
		{
		PosStart=Query->FieldByName("POSDOC")->AsDateTime;
		}

Query->Close();

glSaveProtocol("������� ������ ��� ��������� ������� ����������:"+DateTimeToStr(PosStart));
Memo1->Lines->Add("������� ������ ��� ��������� ������� ����������:"+DateTimeToStr(PosStart));

if (PosStart > PosNull && PosStart >= PosZapretaRedakt )
		{
		GurAllDoc->Active=false;
		GurAllDoc->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosStart;
		GurAllDoc->ParamByName("PARAM_DATE_CON")->AsDateTime=Now()+1;
		GurAllDoc->Active=true;

        Memo1->Lines->Add("�������� ���������� ������� ����������!");
        glSaveProtocol("�������� ���������� ������� ����������!");
        CanceDvRegAllDoc();

        Memo1->Lines->Add("������������� �������� ����� ��������������  ���������!");
		glSaveProtocol("������������� �������� ����� ��������������  ���������!");
        num=0;
		GurAllDoc->First();
		while (!GurAllDoc->Eof)
                {
				RunComandDvRegDoc(Trim(GurAllDocTDOC->AsString),
								GurAllDocIDDOC->AsInt64);

				GurAllDoc->Next();
                num++;
                }

        glSaveProtocol("��������� �������������"+IntToStr(num)+" ����������");
		}

GurAllDoc->Active=false;


//������� ������ ���������� ����������
DeleteZapretProved ();
glSaveProtocol("�������� ������ ���������� ����������!");
glSaveProtocol("��������� ���������� ���������!");


}
//-------------------------------------------------------------
bool TMainForm::CanceDvRegAllDoc(void)
{
bool result=true;

GurAllDoc->Last();
ProgressBar1->Max=GurAllDoc->RecordCount;
ProgressBar1->Step=1;

int num=0;
int num_out=0;
AnsiString message="";
GurAllDoc->First();
while (!GurAllDoc->Eof)
		{


		try
                {
				if (RunComandCancelDvRegDoc(Trim(GurAllDocTDOC->AsString),
								GurAllDocIDDOC->AsInt64)!=true)
						{

						message="�� ������� �������� ���������� ��������� "+
								glGetNameDoc(GurAllDocTDOC->AsString)+
								"  �"+GurAllDocNUMDOC->AsString+
								" �� "+GurAllDocPOSDOC->AsString;
						glSaveProtocol(message);
						Memo1->Lines->Add(message);
                        result=false;
                        }
                }
		catch (Exception &exception)
                {

                message="������ ���  ������ ���������� ��������� \n"+
				glGetNameDoc(GurAllDocTDOC->AsString)+"  �"+GurAllDocNUMDOC->AsString+
                " �� "+GurAllDocPOSDOC->AsString+
                "  "+exception.Message;
                glSaveProtocol(message);
                Memo1->Lines->Add(message);
                result=false;
                }




        GurAllDoc->Next();
		num++;
		num_out++;
		ProgressBar1->StepIt();
		if (num_out==500)
			{
			glSaveProtocol("���������� ����������:"+IntToStr(num));
			num_out=0;
			}
        }

glSaveProtocol("�������� ���������� "+IntToStr(num)+" ����������");
Memo1->Lines->Add("�������� ���������� "+IntToStr(num)+" ����������");

//�������� ����� �� ������ ������� ������������������
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(" select VALUE_TIMESTAMP_SETUP from SETUP where ID_SETUP=15");
Query->ExecQuery();
if (Query->FieldByName("VALUE_TIMESTAMP_SETUP")->AsString=="")
		{
		Query->Close();
        }
else
		{
		 TDateTime gr_posled=Query->FieldByName("VALUE_TIMESTAMP_SETUP")->AsDateTime;
		 Query->Close();

		UnicodeString zapros="select count(IDDOC) AS KOLPRDOC   from GALLDOC";
		zapros=zapros+" where  (PRDOC>0)  AND  (POSDOC-CAST('"+DateTimeToStr(gr_posled)+"' AS TIMESTAMP)>0.0001)";
		Query->SQL->Clear();
		Query->SQL->Add(zapros);
		Query->ExecQuery();
		int KolProvDoc=Query->FieldByName("KOLPRDOC")->AsInteger;
		Query->Close();


				if (KolProvDoc==0)
						{
						DeleteGrPosled ();
						result=true;
						}
				else
						{ //������� ������� ������� ������������ ���������
						result=false;

                                glSaveProtocol("���������� ����� ������� ����������� ���������!!! ���������� "+IntToStr(KolProvDoc));
								glSaveProtocol("������������������ ������������� �� ����� !!!");
                                Query->Close();
								Query->SQL->Clear();
								Query->SQL->Add("select TDOC, NUMDOC, POSDOC from GALLDOC where PRDOC>0  AND POSDOC>:PARAM_POSDOC");
								Query->ParamByName("PARAM_POSDOC")->AsDateTime=PosStart;
								Query->ExecQuery();
								int kol=0;


								message="";
								while(!Query->Eof && kol<5)
										{
										message=message+glGetNameDoc(Trim(Query->FieldByName("TDOC")->AsString))
										+" �"+Query->FieldByName("NUMDOC")->AsString
										+" �� "+Query->FieldByName("POSDOC")->AsString+"\n";
										Query->Next(); kol++;
										}
								Query->Close();
								glSaveProtocol(message);
								Memo1->Lines->Add(message);
								result=false;
						}

		}




return result;

}
//--------------------------------------------------------------------------
void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
Timer1->Interval=0;
Timer1->Enabled=false;
//�������� ������� ������

if (PosStart < Now()-100)
	{

	glSaveProtocol("������� ������ ��������� ���������� ����� 100 ����!");
	Memo1->Lines->Add("������� ������ ��������� ���������� ����� 100 ����!");

	Query->Close();
	Query->SQL->Clear();
	Query->SQL->Add(" select VALUE_SETUP from SETUP where ID_SETUP=43");
	Query->ExecQuery();
	if (Query->FieldByName("VALUE_SETUP")->AsString=="1")
		{
		glSaveProtocol("���� ������������� ����������.");
		Memo1->Lines->Add("���� ������������� ����������");
		glSaveProtocol("�������� ��������� ����������!");
		Memo1->Lines->Add("�������� ��������� ����������!");
		RunObrabDoc();
		}
	else
		{
		glSaveProtocol("���� ������������� �� ���������� ��������� 43");
		Memo1->Lines->Add("���� ������������� �� ���������� ��������� 43");
		glSaveProtocol("�� ��������� ���������� ����������!");
		Memo1->Lines->Add("�� ��������� ���������� ����������!");
		}
	Query->Close();
	}
else
	{
	RunObrabDoc();
	}

Close();
}
//---------------------------------------------------------------------------
void TMainForm::RunObrabDoc(void)
{
		AnsiString regime=Ini->ReadString("Setup","Regime","");
		if (regime=="OnlyDvReg")
			{
			RunOnlyDvReg();
			}
		else if(regime=="OnlyCancelDvReg")
		{
		SetZapretProved ();

			GurAllDoc->Active=false;
			GurAllDoc->ParamByName("PARAM_DATE_NACH")->AsDateTime=PosStart;
			GurAllDoc->ParamByName("PARAM_DATE_CON")->AsDateTime=Now()+1;
			GurAllDoc->Active=true;


			Memo1->Lines->Add("�������� ���������� ����������!");
		 CanceDvRegAllDoc();
		}
		else
			{
			if (Zapusk==true)
				{
				DvRegAllDoc();
				}
			}
}
//---------------------------------------------------------------------------
void TMainForm::RunOnlyDvReg(void)
{

}
//--------------------------------------------------------------------------
bool TMainForm::RunComandCancelDvRegDoc(UnicodeString type_doc,__int64 id_doc)
{
bool result=false;
UnicodeString name_procedure=glGetNameProcedureCancelDvReg(type_doc);


UnicodeString zapros="EXECUTE PROCEDURE ";
zapros=zapros+name_procedure;
zapros=zapros+" ("+IntToStr(id_doc)+",0,0,0)";

QueryUpdate->Close();
QueryUpdate->SQL->Clear();
QueryUpdate->SQL->Add(zapros);
	try
		{
		QueryUpdate->ExecQuery();
		TransactionUpdate->Commit();
		result=true;
		}

	catch (Exception &exception)
		{
		TransactionUpdate->Rollback();
		result=false;
		}

QueryUpdate->Close();
return result;
}
//----------------------------------------------------------------------------
bool TMainForm::RunComandDvRegDoc(UnicodeString type_doc,__int64 id_doc)
{
bool result=false;
UnicodeString name_procedure=glGetNameProcedureDvReg(type_doc);


UnicodeString zapros="EXECUTE PROCEDURE ";
zapros=zapros+name_procedure;
zapros=zapros+" ("+IntToStr(id_doc)+",1,0,0)";

QueryUpdate->Close();
QueryUpdate->SQL->Clear();
QueryUpdate->SQL->Add(zapros);
	try
		{
		QueryUpdate->ExecQuery();
		TransactionUpdate->Commit();
		result=true;
		}

	catch (Exception &exception)
		{
		TransactionUpdate->Rollback();
		result=false;
		}

QueryUpdate->Close();
return result;
}
//----------------------------------------------------------------------------

void TMainForm::glSaveProtocol(UnicodeString str)
{
UnicodeString FileNameProtocol="";
if (CatalogProtocol=="")
		{
		FileNameProtocol=ExtractFileDir(Application->ExeName)+"\\"+ DateToStr(Date())+".txt";
		}
else
		{
		FileNameProtocol=CatalogProtocol+"\\"+ DateToStr(Date())+".txt";
		}

str=TimeToStr(Time())+" "+str;

TkanTxtFile * f=new TkanTxtFile;
f->AddString(FileNameProtocol,str);
delete f;
}
//---------------------------------------------------------------------------
