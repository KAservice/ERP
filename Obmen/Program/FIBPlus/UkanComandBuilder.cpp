//---------------------------------------------------------------------------


#pragma hdrstop

#include "UkanComandBuilder.h"
#include "vcl.h"
#include <Classes.hpp>
#include <IdFTP.hpp>
#include "UkanIniFile.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
extern bool glPodrProtokol;
//-------------------------------------------------------------------
TkanComandBuilder::TkanComandBuilder()
{
//
}
//-----------------------------------------------------------------------------
TkanComandBuilder::~TkanComandBuilder()
{
//

}
//----------------------------------------------------------------------------
//������� ������� �� ��������������
bool TkanComandBuilder::DeleteComandFromSource(TkanComandExchange * comand)
{
bool result=false;

GetTypeObmen();


if (TypeExchange==TypeExchange_ForCatalogObmena)
	{
	result=DeleteComandFromCatalogObmena(comand);
	}

if (TypeExchange==TypeExchange_ForMAPI)
	{
	result=DeleteComandFromMAPI(comand);
	}

return result;
}
//-----------------------------------------------------------------------------
bool TkanComandBuilder::DeleteComandFromCatalogObmena(TkanComandExchange * comand)
{  //������� ���� ������ �� �������� ������
	//�� �������� ���� � ��������� �������
	//���� � ������� ��������� � ����� �������� ������
bool result=true;

	UnicodeString file_name=comand->FileList->Strings[0];
	if(FileExists(file_name)==true)
		{
		//ShowMessage("������� ���� " + file_name);
		if (DeleteFile(file_name)==false)
			{
			result=false;
			TextError=TextError+" ������ ��� �������� ��������� ����� � �������� ������!";
			}
		}


	UnicodeString file_name_run=ExtractFileDir(comand->FileList->Strings[0])+"\\Run"+IntToStr(IdTecBase)+".kas";
	//ShowMessage("������� ���� " + file_name_run);
	if(FileExists(file_name_run)==true)
		{

		if (DeleteFile(file_name_run)==false)
			{
			result=false;
			TextError=TextError+" ������ ��� ��������  ����� Run � �������� ������!";
			}
		}

return result;

}
//------------------------------------------------------------------------------
bool TkanComandBuilder::DeleteComandFromMAPI(TkanComandExchange * comand)
{ //������� ������ �� ����� ��������
bool result=false;

TkanMAPI * mapi=new TkanMAPI();
mapi->Init();
//������ ��������� MAPI ��� ��������� ���������
AnsiString otpr_email=GetStringParameter(GC_NameIniParameter_EMail);

mapi->DeleteComandFromSource(comand->ID,otpr_email);
delete mapi;

return result;

}
//-----------------------------------------------------------------------------


//�������� ������� � �������������
bool TkanComandBuilder::SendComandFromSource(TkanComandExchange * comand)
{
bool result=false;

GetTypeObmen();


if (TypeExchange==TypeExchange_ForCatalogObmena)
	{
	result=SendComandForCatalogObmena(comand);
	}

if (TypeExchange==TypeExchange_ForMAPI)
	{
	result=SendComandForMAPI(comand);
	}

return result;
}
//---------------------------------------------------------------------------
bool TkanComandBuilder::SendComandForCatalogObmena(TkanComandExchange * comand)
{ //�������� ���� �� ���������� �������� � ������� ������
bool result=false;

	// �������� ���� ���� ��������� ���� � �������� ������ �� ��� ������

	UnicodeString file_name=GetCatalogObmena(IdTecBase,IdBaseForObmen)+"\\"+ExtractFileName(comand->FileList->Strings[0]);

	if(FileExists(file_name)==true)
		{
		DeleteFile(file_name);
		}
	//�������� ����
	//ShowMessage(comand->FileList->Strings[0]);
	//ShowMessage(file_name);

	if (CopyFileTo(comand->FileList->Strings[0],file_name)==true)
		{

		Sleep(10000);

		if(FileExists(file_name)==true)
			{
			TStringList  * l=new TStringList();
			UnicodeString file_name_run=GetCatalogObmena(IdTecBase,IdBaseForObmen)+"\\Run"+IntToStr(IdBaseForObmen)+".kas";
			l->SaveToFile(file_name_run);
			delete l;
			}
		else
			{
			result=false;
			TextError=TextError+" ������ ����������� ����� � ������� ������! �� ������������ ���� � ������� ������";
			}

		result=true;
		}
	else
		{
		result=false;
		TextError=TextError+" ������ ����������� ����� � ������� ������!";
		}

return result;

}
//---------------------------------------------------------------------------
bool TkanComandBuilder::SendComandForMAPI(TkanComandExchange * comand)
{//������� ������ � �������� � ����� ���������
bool result=false;

//������� �� ������� ���������
//��������� ������� � ���������
TkanMapiMessage * mes=new TkanMapiMessage();
if (CreateKanMessageFromComand(mes,comand)==true)
	{
	//���������� ��������� ����� MAPI
	TkanMAPI * mapi=new TkanMAPI();
	mapi->Init();
	if (mapi->SendMessage(mes)==true)
		{

		}
	else
		{

		}
	delete mapi;
	}
delete mes;

return result;
}
//----------------------------------------------------------------------------

bool TkanComandBuilder::GetListComand(TkanComandExchangeList * comand_list)
{
bool result=false;

GetTypeObmen();

//����� ����� ������� ������
if (TypeExchange==TypeExchange_ForCatalogObmena)
	{
	result=GetListForObmenCatalog(comand_list);
	}

//����� ����� MAPI
if (TypeExchange==TypeExchange_ForMAPI)
	{
	result=GetListForObmenMAPI(comand_list);
	}

return result;
}
//---------------------------------------------------------------------------
bool TkanComandBuilder::GetListForObmenCatalog(TkanComandExchangeList * comand_list)

{
bool result=false;

	UnicodeString catalog_obmena=GetCatalogObmena(IdTecBase,IdBaseForObmen);
	UnicodeString in_file_name=catalog_obmena+"\\DataFor"+IntToStr(IdTecBase)+".kas";
	//ShowMessage("�������� ���� ������ "+in_file_name);

	comand_list->ComandCount=0;

	UnicodeString file_name_run=catalog_obmena+"\\Run"+IntToStr(IdTecBase)+".kas";
	//ShowMessage("�������� ���� Run "+file_name_run);
	if (FileExists(file_name_run)==true)
		{
		if (FileExists(in_file_name)==true)
			{ //��������� ������� ������ ���� ���� ����������
			//ShowMessage("������� �������");
			TkanComandExchange *comand = new TkanComandExchange();
			comand->RunComand=true;
			comand->TypeComandExchange=comand->TypeComandExchange_UpdateBase;
			comand->IdTecBase=IdTecBase;
			comand->IdBaseForObmen=IdBaseForObmen;
			comand->FileList_AddString(in_file_name); //������� ������ + ��� �����

			comand_list->List->Add(comand);
			comand_list->ComandCount++;
			result=true;
			}
		}


return result;
}
//------------------------------------------------------------------------------
bool TkanComandBuilder::GetListForObmenMAPI(TkanComandExchangeList * comand_list)
{
bool result=false;

TkanMAPI * mapi=new TkanMAPI();
mapi->Init();
//������ ��������� MAPI ��� ��������� ���������
//��� ������� ����� ����� �� ���� �������� �������
//�������� ������ ���������
AnsiString otpr_email=GetStringParameter(GC_NameIniParameter_EMail);

TkanMapiMessageList * mes_list=new TkanMapiMessageList();
if (mapi->GetListMessage(mes_list,otpr_email, 0)==true)
	{
	//�������� �� ������ ����������� ��������� � �������
	//�������� �� ������ ������
	for (int i=0; i<mes_list->List->Count;i++)
		{
		TkanMapiMessage* el = mes_list->GetElement(i);
		TkanComandExchange * com=new TkanComandExchange();
		if (CreateComandFromMailMessage(el,com)==true)
			{//��������� ������ �������
			comand_list->List->Add(com);
			}
		else
			{

			}
		}
	result=true;
	}
else
	{
	result=false;
    TextError=TextError+mapi->TextError;
	}

delete mapi;



delete mes_list;
return result;
}
//---------------------------------------------------------------------------
UnicodeString TkanComandBuilder::GetStringParameter(UnicodeString name_parameter)
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
void TkanComandBuilder::GetTypeObmen(void)
{

if (GetStringParameter(GC_NameIniParameter_TypeObmen)=="1")
		{
		TypeExchange=TypeExchange_ForCatalogObmena;
		}
	else
		{
		TypeExchange=TypeExchange_ForMAPI;
		}

}

//-----------------------------------------------------------------------------
UnicodeString TkanComandBuilder::GetCatalogObmena(__int64 id_tec_base,__int64 id_base_for_obmen)
{
UnicodeString result=GetStringParameter(GC_NameIniParameter_CatalogObmena);

return result;
}
////----------------------------------------------------------------------------












//����� ����� EMAIL
bool TkanComandBuilder::CreateComandFromMailMessage(TkanMapiMessage *mapi_message, TkanComandExchange * comand)
{//�� ��������� ������� �������
bool result=false;


UnicodeString str1=mapi_message->TextMessageList->Strings[0];
if (str1==GC_NameMAPIParameter_Comand)
	{ //��� �������
	comand->ID=mapi_message->TextMessageList->Strings[1];

	//��� �������
	UnicodeString type_comand=mapi_message->TextMessageList->Strings[2] ;
	if(type_comand==GC_TypeComand_UpdateBase)
		{//������� �������� ����
        comand->TypeComandExchange=comand->TypeComandExchange_UpdateBase;
		}


	//��������� �����
    //�������� �� ������ ������
	for (int i=0; i<mapi_message->FileList->Count;i++)
		{
		comand->FileList->Add(mapi_message->FileList_GetString(i));
		}



	result=true;
	}
return result;
}
//-----------------------------------------------------------------------------
bool TkanComandBuilder::CreateKanMessageFromComand(TkanMapiMessage *mapi_message,TkanComandExchange * comand)
{//�� ������� ������� ���������
//������� ����� ����� ���������� ����� mapi
bool result=false;

mapi_message->NameOtpravitel=GetStringParameter(GC_NameIniParameter_EMail);

mapi_message->EMail=GetStringParameter(GC_NameIniParameter_EMail);  //����� �� ���� ��� ���� �������� ������
mapi_message->UchRecord=""; //������� ������ ��� ������ � �������� ����������
mapi_message->TemaEmailMessage="������� ������ "+DateTimeToStr(Now()); //
mapi_message->TextMessageList->Add(GC_NameMAPIParameter_Comand);  //  �������
mapi_message->TextMessageList->Add(comand->ID);  // �� �������
mapi_message->TextMessageList->Add(GC_TypeComand_UpdateBase);  //  ��� �������

//��������� �����
    //�������� �� ������ ������
	for (int i=0; i<comand->FileList->Count;i++)
		{
		mapi_message->FileList->Add(comand->FileList_GetString(i));
		}
result=true;


return result;
}
//-----------------------------------------------------------------------------
