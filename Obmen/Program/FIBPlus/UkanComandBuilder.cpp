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
//удаляет команду из первоисточника
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
{  //удаляем файл обмена из каталога обмена
	//не копируем файл в локальный каталог
	//файл в команде находится в папке каталога обмена
bool result=true;

	UnicodeString file_name=comand->FileList->Strings[0];
	if(FileExists(file_name)==true)
		{
		//ShowMessage("Удаляем файл " + file_name);
		if (DeleteFile(file_name)==false)
			{
			result=false;
			TextError=TextError+" Ошибка при удалении входящего файла в каталоге обмена!";
			}
		}


	UnicodeString file_name_run=ExtractFileDir(comand->FileList->Strings[0])+"\\Run"+IntToStr(IdTecBase)+".kas";
	//ShowMessage("Удаляем файл " + file_name_run);
	if(FileExists(file_name_run)==true)
		{

		if (DeleteFile(file_name_run)==false)
			{
			result=false;
			TextError=TextError+" Ошибка при удалении  файла Run в каталоге обмена!";
			}
		}

return result;

}
//------------------------------------------------------------------------------
bool TkanComandBuilder::DeleteComandFromMAPI(TkanComandExchange * comand)
{ //удаляем письмо из папки Входящие
bool result=false;

TkanMAPI * mapi=new TkanMAPI();
mapi->Init();
//задаем настройки MAPI для получения сообщений
AnsiString otpr_email=GetStringParameter(GC_NameIniParameter_EMail);

mapi->DeleteComandFromSource(comand->ID,otpr_email);
delete mapi;

return result;

}
//-----------------------------------------------------------------------------


//посылает команду в первоисточник
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
{ //копируем файл из локального каталога в каталог обмена
bool result=false;

	// проверим если есть указанный файл в каталоге обмена то его удалим

	UnicodeString file_name=GetCatalogObmena(IdTecBase,IdBaseForObmen)+"\\"+ExtractFileName(comand->FileList->Strings[0]);

	if(FileExists(file_name)==true)
		{
		DeleteFile(file_name);
		}
	//копируем файл
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
			TextError=TextError+" Ошибка копирования файла в каталог обмена! Не скопировался файл в каталог обмена";
			}

		result=true;
		}
	else
		{
		result=false;
		TextError=TextError+" Ошибка копирования файла в каталог обмена!";
		}

return result;

}
//---------------------------------------------------------------------------
bool TkanComandBuilder::SendComandForMAPI(TkanComandExchange * comand)
{//создаем письмо и помещаем в папку Исходящие
bool result=false;

//создаем из команды сообщение
//упаковать команду в сообщение
TkanMapiMessage * mes=new TkanMapiMessage();
if (CreateKanMessageFromComand(mes,comand)==true)
	{
	//отправляем сообщение через MAPI
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

//ОБМЕН ЧЕРЕЗ КАТАЛОГ ОБМЕНА
if (TypeExchange==TypeExchange_ForCatalogObmena)
	{
	result=GetListForObmenCatalog(comand_list);
	}

//ОБМЕН ЧЕРЕЗ MAPI
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
	//ShowMessage("Входящий файл обмена "+in_file_name);

	comand_list->ComandCount=0;

	UnicodeString file_name_run=catalog_obmena+"\\Run"+IntToStr(IdTecBase)+".kas";
	//ShowMessage("Входящий файл Run "+file_name_run);
	if (FileExists(file_name_run)==true)
		{
		if (FileExists(in_file_name)==true)
			{ //добавляем команду только если файл существует
			//ShowMessage("Создаем команду");
			TkanComandExchange *comand = new TkanComandExchange();
			comand->RunComand=true;
			comand->TypeComandExchange=comand->TypeComandExchange_UpdateBase;
			comand->IdTecBase=IdTecBase;
			comand->IdBaseForObmen=IdBaseForObmen;
			comand->FileList_AddString(in_file_name); //каталог обмена + имя файла

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
//задаем настройки MAPI для получения сообщений
//как минимум адрес почты от кого приходят команды
//получаем список сообщений
AnsiString otpr_email=GetStringParameter(GC_NameIniParameter_EMail);

TkanMapiMessageList * mes_list=new TkanMapiMessageList();
if (mapi->GetListMessage(mes_list,otpr_email, 0)==true)
	{
	//проходим по списку преобразуем сообщения в команды
	//проходим по списку команд
	for (int i=0; i<mes_list->List->Count;i++)
		{
		TkanMapiMessage* el = mes_list->GetElement(i);
		TkanComandExchange * com=new TkanComandExchange();
		if (CreateComandFromMailMessage(el,com)==true)
			{//добавляем только команды
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












//ОБМЕН ЧЕРЕЗ EMAIL
bool TkanComandBuilder::CreateComandFromMailMessage(TkanMapiMessage *mapi_message, TkanComandExchange * comand)
{//из сообщения создаем команду
bool result=false;


UnicodeString str1=mapi_message->TextMessageList->Strings[0];
if (str1==GC_NameMAPIParameter_Comand)
	{ //это команда
	comand->ID=mapi_message->TextMessageList->Strings[1];

	//тип команды
	UnicodeString type_comand=mapi_message->TextMessageList->Strings[2] ;
	if(type_comand==GC_TypeComand_UpdateBase)
		{//команда обновить базу
        comand->TypeComandExchange=comand->TypeComandExchange_UpdateBase;
		}


	//добавляем файлы
    //проходим по списку файлов
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
{//из команды создаем сообщение
//которое затем будет отправлено через mapi
bool result=false;

mapi_message->NameOtpravitel=GetStringParameter(GC_NameIniParameter_EMail);

mapi_message->EMail=GetStringParameter(GC_NameIniParameter_EMail);  //адрес от кого или куда посылать письмо
mapi_message->UchRecord=""; //учетная запись для работы с почтовой программой
mapi_message->TemaEmailMessage="Команда обмена "+DateTimeToStr(Now()); //
mapi_message->TextMessageList->Add(GC_NameMAPIParameter_Comand);  //  команда
mapi_message->TextMessageList->Add(comand->ID);  // ИД команды
mapi_message->TextMessageList->Add(GC_TypeComand_UpdateBase);  //  тип команды

//добавляем файлы
    //проходим по списку файлов
	for (int i=0; i<comand->FileList->Count;i++)
		{
		mapi_message->FileList->Add(comand->FileList_GetString(i));
		}
result=true;


return result;
}
//-----------------------------------------------------------------------------
