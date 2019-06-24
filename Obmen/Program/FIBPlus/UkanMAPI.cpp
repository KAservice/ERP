//---------------------------------------------------------------------------


#pragma hdrstop

#include "UkanMAPI.h"
#include "vcl.h"
#include "UkanTxtFile.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
extern bool glPodrProtokol;
//-------------------------------------------------------------------
TkanMAPI::TkanMAPI()
{



flTestMapi=false;


}
//-----------------------------------------------------------------------------
TkanMAPI::~TkanMAPI()
{
		// Закрытие сессии
//        (*lpfnMAPILogoff)(lhSession,        //Без флагов
//                      0L,
//                      0L,
//                      0L);

	if (glPodrProtokol==true)
		{
		SaveProtocol("Выполняем: FreeLibrary(hMAPILib)");
		}

		FreeLibrary(hMAPILib);

	if (glPodrProtokol==true)
		{
		SaveProtocol("Выполнили: FreeLibrary(hMAPILib)");
		}
}
//----------------------------------------------------------------------------
bool TkanMAPI::Init(void)
{
bool result=false;

	if (glPodrProtokol==true)
		{
		SaveProtocol("Выполняем: LoadLibrary(MAPI32.DLL");
		}

  hMAPILib = LoadLibrary("MAPI32.DLL");  // Загружаем библиотеку
  if (hMAPILib==0)
	{
	ErrorLoadDll=true;
		if (glPodrProtokol==true)
		{
		SaveProtocol("Выполняем: LoadLibrary(MAPI32.DLL) - ошибка");
		}
	}
  else
	{
	ErrorLoadDll=false;

		if (glPodrProtokol==true)
		{
		SaveProtocol("Выполняем: LoadLibrary(MAPI32.DLL) - ОК");
		}
	}

if (ErrorLoadDll==false)
	{
		if (glPodrProtokol==true)
		{
		SaveProtocol("Выполняем: GetProcAddress");
		}
	lpfnMAPIAddress = (LPMAPIADDRESS)GetProcAddress(hMAPILib, "MAPIAddress");
	lpfnMAPIDeleteMail= (LPMAPIDELETEMAIL)GetProcAddress(hMAPILib, "MAPIDeleteMail");
	lpfnMAPIDetails = (LPMAPIDETAILS)GetProcAddress(hMAPILib, "MAPIDetails");
	lpfnMAPIFindNext = (LPMAPIFINDNEXT)GetProcAddress(hMAPILib, "MAPIFindNext");
	lpfnMAPIFreeBuffer = (LPMAPIFREEBUFFER)GetProcAddress(hMAPILib, "MAPIFreeBuffer");
	lpfnMAPILogon = (LPMAPILOGON)GetProcAddress(hMAPILib, "MAPILogon");
	lpfnMAPILogoff = (LPMAPILOGOFF)GetProcAddress(hMAPILib, "MAPILogoff");
	lpfnMAPIReadMail = (LPMAPIREADMAIL)GetProcAddress(hMAPILib, "MAPIReadMail");
	lpfnMAPISendDocuments = (LPMAPISENDDOCUMENTS)GetProcAddress(hMAPILib, "MAPISendDocuments");
	lpfnMAPISendMail = (LPMAPISENDMAIL)GetProcAddress(hMAPILib, "MAPISendMail");
	lpfnMAPIResolveName = (LPMAPIRESOLVENAME)GetProcAddress(hMAPILib, "MAPIResolveName");
	lpfnMAPISaveMail = (LPMAPISAVEMAIL)GetProcAddress(hMAPILib, "MAPISaveMail");

	if (glPodrProtokol==true)
		{
		SaveProtocol("Выполнили: GetProcAddress");
		}

	result=true;
	}
return result;
}
//------------------------------------------------------------------------------

bool TkanMAPI::SendMessage(TkanMapiMessage *mes)
{
bool result=false;
ULONG error;                  // Для хранения кода ошибки
LHANDLE lhSession;            // Сессия MAPI
CHAR rgchMsgID[513];          // Идентификатор сообщение >512


/*--MAPILOGON--------------------------------------------------------------*/
  error=lpfnMAPILogon(0,                     // Handle диалогового окна созданного MAPILogon
						NULL,                   // Указатель на строку, содержащей путь к файлу настроек
						NULL,                   // Указатель на строку, содержащую пароль для доступа
						MAPI_NEW_SESSION,       // Флаги:
												//   MAPI_FORCE_DOWNLOAD - функция пытается загрузить все сообщения
												//   MAPI_LOGON_UI - показать диалог для идентификации
												//   MAPI_NEW_SESSION - создать новую сессию
						0,                      // Зарезервировано
						&lhSession);            // Указатель на сессию

	if (error!=SUCCESS_SUCCESS)
	{


	}




/*--MAPISENDMAIL-----------------------------------------------------------*/
AnsiString name_otpravitel=AnsiString(mes->NameOtpravitel);
AnsiString mail=AnsiString(mes->EMail);

      MapiRecipDesc recipient =
      {
        0,
        MAPI_TO,
		name_otpravitel.c_str(),                  //имя отправителя
		mail.c_str(),     //адрес
        0,
		NULL

	  };

	// Указываем вложенный файл
	MapiFileDesc  attach;

	AnsiString file_patch_full=AnsiString(mes->FileList_GetString(0));
	AnsiString file_name=AnsiString(ExtractFileName(mes->FileList_GetString(0)));

	attach.nPosition    = (ULONG)-1;
	attach.lpszPathName = file_patch_full.c_str();
	attach.lpszFileName = file_name.c_str();

	AnsiString tema=AnsiString(mes->TemaEmailMessage);

	AnsiString text_message="";
	for (int i=0; i<mes->TextMessageList->Count;i++)
		{
		text_message=text_message+(mes->TextMessageList->Strings[i])+"\n";
		}




	  MapiMessage message =
	  {
		0,
		tema.c_str(),
		text_message.c_str(),
		NULL,
		NULL,
		NULL,
		0,
		NULL,
		1,
		&recipient,
		1,
		&attach
	  };


	  lpfnMAPISendMail(lhSession, 0, &message, 0, 0);



/*--MAPILOGOFF-------------------------------------------------------------*/

		// Закрытие сессии
		lpfnMAPILogoff(lhSession,        //Без флагов
					  0L,
					  0L,
					  0L);

result=true;
return result;
}
//----------------------------------------------------------------------------
//bool TkanMAPI::GetListMessage(TkanMapiMessageList * mes_list, UnicodeString otpr_email)
//{
//bool result=true;
//
//	if (glPodrProtokol==true)
//		{
//		SaveProtocol("Выполнили: TkanMAPI::GetListMessage(TkanMapiMessageList * mes_list, UnicodeString otpr_email)");
//		}
//
// ULONG result_func;                  // Для хранения кода ошибки
//  LHANDLE lhSession;            // Сессия MAPI
//  MapiMessage *MAPIMessage;     // Структура сообщения
//  MapiRecipDesc *MAPIRecipient; // Структура получателя
//  MapiFileDesc * MAPIAttach;        //вложения
//  CHAR rgchMsgID[513]={0};          // Идентификатор сообщение >512
//
//
//
//FLAGS flFindM = MAPI_LONG_MSGID;
//
//
///*--MAPILOGON--------------------------------------------------------------*/
//if ( !lhSession )
//	{
//  result_func=lpfnMAPILogon(0,                     // Handle диалогового окна созданного MAPILogon
//						NULL,                   // Указатель на строку, содержащей путь к файлу настроек
//						NULL,                   // Указатель на строку, содержащую пароль для доступа
//						MAPI_NEW_SESSION,       // Флаги:
//												//   MAPI_FORCE_DOWNLOAD - функция пытается загрузить все сообщения
//												//   MAPI_LOGON_UI - показать диалог для идентификации
//												//   MAPI_NEW_SESSION - создать новую сессию
//						0,                      // Зарезервировано
//						&lhSession);            // Указатель на сессию
//	}
//  else
//  {
//  if (glPodrProtokol==true) {SaveProtocol(" Сесия уже открыта. lhSession!=0 ");}
//  }
//
//if (lhSession ==0)
//	{
//	if (glPodrProtokol==true) {SaveProtocol(" После lpfnMAPILogon. lhSession=0 ");}
//	result=false;
//	return result;
//	}
//
//if (result_func==SUCCESS_SUCCESS)
//	{
//
//
//	// Ищем второе сообщение
//M1:	if (glPodrProtokol==true) {SaveProtocol("Выполняем Ищем текущее сообщение: lpfnMAPIFindNext(lhSession,0,0,rgchMsgID,flFindM,0,rgchMsgID)");}
//
//	if (glPodrProtokol==true) {SaveProtocol("-------------------------------------------------");}
//	if (glPodrProtokol==true) {SaveProtocol(" ");}
//
//		result_func = lpfnMAPIFindNext(lhSession,0,0,rgchMsgID,flFindM,0,rgchMsgID);
//		//result_func = lpfnMAPIFindNext(lhSession,0,0,rgchMsgID,flFindM,0,rgchMsgID);
//
//
//	if (glPodrProtokol==true) {SaveProtocol("Выполнили Ищем текущее сообщение: lpfnMAPIFindNext(lhSession,0,0,rgchMsgID,flFindM,0,rgchMsgID)");}
//	if (glPodrProtokol==true) {SaveProtocol(rgchMsgID);}
//	if (result_func==SUCCESS_SUCCESS)
//		{
//		if (glPodrProtokol==true) {SaveProtocol("Результат: SUCCESS_SUCCESS");}
//			// Читаем найденное сообщение
//			if (glPodrProtokol==true) {SaveProtocol("Выполняем: lpfnMAPIReadMail(lhSession,0,rgchMsgID,MAPI_PEEK,0,&MAPIMessage)");}
//
//			//MAPIMessage = new MapiMessage;
//			//MAPIFreeBuffer(MAPIMessage);
//			MAPIMessage=0;
//
//				//result_func=lpfnMAPIReadMail(lhSession,0,rgchMsgID,MAPI_PEEK,0,&MAPIMessage);
//			result_func=lpfnMAPIReadMail(lhSession,0,rgchMsgID,0,MAPI_SUPPRESS_ATTACH,&MAPIMessage);
//
//
//
//			if (glPodrProtokol==true) {SaveProtocol("Выполнили: lpfnMAPIReadMail(lhSession,0,rgchMsgID,MAPI_PEEK,0,&MAPIMessage)");}
//
//			if (result_func==SUCCESS_SUCCESS)
//				{
//				if (glPodrProtokol==true) {SaveProtocol("Результат: SUCCESS_SUCCESS");}
//				try
//					{
//					AnsiString mail=AnsiString(otpr_email);
//					if (glPodrProtokol==true) {SaveProtocol(mail.c_str());}
//
//					if ( MAPIMessage != 0)
//						{
//					AnsiString mail_from_message=AnsiString(MAPIMessage->lpOriginator->lpszAddress);
//					AnsiString s="Проверяем отправителя: mail "+mail+" mail_from_message "+mail_from_message;
//
//					if (glPodrProtokol==true) {SaveProtocol(s.c_str());}
//
//					if ( mail == mail_from_message)
//						{
//						if (glPodrProtokol==true) {SaveProtocol("Отправитель совпадает. Это команда обмена");}
//						//создаем входящую сообщение
//						TkanMapiMessage * mes=new TkanMapiMessage();
//						CreateKanMessageFromMailMessage(MAPIMessage,mes);
//						mes_list->List->Add(mes);
//
//						}
//						}
//					else
//						{
//						if (glPodrProtokol==true) {SaveProtocol("MAPIMessage ==0");}
//						}
//					}
//				catch (Exception &exception)
//					{
//					TextError=TextError+" Ошибка выборки сообщения "+exception.Message;
//					AnsiString s=TextError+" Ошибка выборки сообщения "+exception.Message;
//					if (glPodrProtokol==true) {SaveProtocol(s.c_str());}
//					result=false;
//					}
//
//				MAPIFreeBuffer( rgchMsgID );
//				MAPIFreeBuffer(MAPIMessage);
//
//				goto M1;
//				}
//			else
//				{
//				if (glPodrProtokol==true) {SaveProtocol("Результат: lpfnMAPIReadMail не SUCCESS_SUCCESS");}
//
//				goto M2;  //не смогли прочитать хотя бы одно сообщение
//				}
//
//
//
//		}
//	else if (result_func==MAPI_E_FAILURE)
//		{
//		if (glPodrProtokol==true) {SaveProtocol("Результат lpfnMAPIFindNext: не SUCCESS_SUCCESS. неизвестная ошибка");}
//		goto M2;  //не смогли найти следующее сообщение
//		}
//	else if (result_func==MAPI_E_INSUFFICIENT_MEMORY)
//		{
//		if (glPodrProtokol==true) {SaveProtocol("Результат lpfnMAPIFindNext: не SUCCESS_SUCCESS. Недостаточно памяти");}
//		goto M2;  //не смогли найти следующее сообщение
//		}
//	else if (result_func==MAPI_E_INVALID_MESSAGE )
//		{
//		if (glPodrProtokol==true) {SaveProtocol("Результат lpfnMAPIFindNext: не SUCCESS_SUCCESS. Неверный идентификатор сообщения был передан в параметр lpszMessageID.");}
//		goto M2;  //не смогли найти следующее сообщение
//		}
//	else if (result_func==MAPI_E_INVALID_SESSION)
//		{
//		if (glPodrProtokol==true) {SaveProtocol("Результат lpfnMAPIFindNext: не SUCCESS_SUCCESS. Неправильный handle сессии был использован в lhSession. ");}
//		goto M2;  //не смогли найти следующее сообщение
//		}
//	else if (result_func==MAPI_E_NO_MESSAGES)
//		{
//		if (glPodrProtokol==true) {SaveProtocol("Результат lpfnMAPIFindNext: не SUCCESS_SUCCESS. Сообщений не найдено. ");}
//		goto M2;  //не смогли найти следующее сообщение
//		}
//
//
//
//	// Закрытие сессии
//M2: if (glPodrProtokol==true) {SaveProtocol("Закрытие сессии");}
//	lpfnMAPILogoff(lhSession,        //Без флагов
//					  0L,
//					  0L,
//					  0L);
//
//	}
//else if (result_func==MAPI_E_FAILURE)
//	{
//	result=false;
//	TextError=TextError+" Ошибка подключения к MAPI.(LPMAPILOGON)Неизвестная ошибка";
//	}
//else if (result_func==MAPI_E_INSUFFICIENT_MEMORY)
//	{
//	result=false;
//	TextError=TextError+" Ошибка подключения к MAPI.(LPMAPILOGON)Недостаточно памяти для процесса.";
//	}
//else if (result_func==MAPI_E_LOGIN_FAILURE)
//	{
//	result=false;
//	TextError=TextError+" Ошибка подключения к MAPI.(LPMAPILOGON)Был исользованр не верное имя пользователя при входе в систему..";	}
//else if (result_func==MAPI_E_TOO_MANY_SESSIONS)
//	{
//	result=false;
//	TextError=TextError+" Ошибка подключения к MAPI.(LPMAPILOGON)Слишком много сессий было запущенно  одновременно.   ";
//	}
//else if (result_func==MAPI_E_USER_ABORT)
//	{
//	result=false;
//	TextError=TextError+" Ошибка подключения к MAPI.(LPMAPILOGON)Пользователь завершил работу с одним из диалоговых окон (cancel).";
//	}
//
//
//
//
//return result;
//}
//----------------------------------------------------------------------------
bool TkanMAPI::GetListMessage(TkanMapiMessageList * mes_list, UnicodeString otpr_email, int test)
{
bool result=true;


	LHANDLE		m_lhSession=0;			// Used to capture MAPI session handle.


	HRESULT hRes = S_OK;
	FLAGS	flFlags = 0L;
	ULONG	ulReserved = 0L;
	LPSTR	lpszProfileName = NULL;
	LPSTR	lpszPassword = NULL;

	if ( !m_lhSession )	  // Always ask if there is an active session
	{
		flFlags = MAPI_NEW_SESSION;  // Logon with a new session and force display of UI.

		//cCaptureText ( "\r\nEnter a profile name: ", &lpszProfileName );

		//printf ( "Attempting to logon to messaging system.\r\n" );

		lpszProfileName=0;

		hRes = lpfnMAPILogon (
							 0L, 				// Handle to parent window or 0.
							 lpszProfileName,	// Default profile name to use for MAPI session.
							 lpszPassword,		// User password for MAPI session.
							 flFlags,			// Various session settings
							 ulReserved,		// Reserved.  Must be 0L.
							 &m_lhSession		// Return handle to MAPI Session
						   );



		if (hRes == SUCCESS_SUCCESS)
		{
			// Let user know that logon was successful.

		   if (glPodrProtokol==true) {SaveProtocol("Logon successful.\r\n");}
		}
		else
		{
			// If logon attempt fails, inform user that an error occured and report
			// the error number.
		   if (glPodrProtokol==true) {SaveProtocol("Logon attempt failed due to error code");}
		   result=false;
			switch (hRes)
			{
			case MAPI_E_FAILURE:
				if (glPodrProtokol==true) {SaveProtocol("One or more unspecified errors occurred during logon. No session handle was returned.");}
				break;
			case MAPI_E_INSUFFICIENT_MEMORY:
				if (glPodrProtokol==true) {SaveProtocol( "There was insufficient memory to proceed. No session handle was returned.");}
				break;
			case MAPI_E_LOGIN_FAILURE:
				if (glPodrProtokol==true) {SaveProtocol("There was no default logon, and the user failed to log on successfully when the logon dialog box was displayed. No session handle was returned.");}
				break;
			case MAPI_E_TOO_MANY_SESSIONS:
			   if (glPodrProtokol==true) {SaveProtocol( "The user had too many sessions open simultaneously. No session handle was returned.");}
				break;
			case MAPI_E_USER_ABORT:
				if (glPodrProtokol==true) {SaveProtocol( "The user canceled the logon dialog box. No session handle was returned.");}
				break;
			default:
				if (glPodrProtokol==true) {SaveProtocol( "Unknown error code.");}
				break;
			}
		}
	}
	else
	{
		// If we get to this point, the user is already logged on. A new attempt
		// to logon is redundant so inform the user they have a session handle
		// already.
		if (glPodrProtokol==true) {SaveProtocol( "Already logged on to messaging system.");}
	}



	//lpfnMAPIFreeBuffer ( lpszProfileName );
	//lpszProfileName = NULL;




	char szMsgID[512];
    char szSeedMsgID[512];
	lpMapiMessage lpMessage;

	flFlags = 0L;

	if ( m_lhSession )
	{
		/* Populate List Box with all messages in InBox. */
		/* This is a painfully slow process for now.     */

	if (glPodrProtokol==true) {SaveProtocol("-------------------------------------------------");}
	if (glPodrProtokol==true) {SaveProtocol(" ");}

		hRes = lpfnMAPIFindNext ( m_lhSession, 0L, NULL, NULL,
			MAPI_GUARANTEE_FIFO | MAPI_LONG_MSGID, 0, szMsgID);



		while (hRes == SUCCESS_SUCCESS)
		{
			lpMessage=0L;
			if (glPodrProtokol==true) {SaveProtocol(szMsgID);}

			if (test==1)
				{

							hRes = lpfnMAPIReadMail ( m_lhSession,
									0L,
									szMsgID,
									MAPI_PEEK | MAPI_ENVELOPE_ONLY,   /* Only header information      */
									0,
									&lpMessage);
				}
			else if (test==2)
				{

							hRes = lpfnMAPIReadMail ( m_lhSession,
									0L,
									szMsgID,
									MAPI_PEEK | MAPI_SUPPRESS_ATTACH,   /* header + body, no files      */
									0,
									&lpMessage);
				}
			else if (test==3)
				{

							hRes = lpfnMAPIReadMail ( m_lhSession,
									0L,
									szMsgID,
									MAPI_PEEK,
									0,
									&lpMessage);
				}
			else
				{
				hRes = lpfnMAPIReadMail ( m_lhSession,
									0L,
									szMsgID,
									MAPI_PEEK,
									0,
									&lpMessage);
				}

			if (SUCCESS_SUCCESS == hRes)
			{
				//strcat ( lpMessage->lpszSubject, "\r\n" );

				try
					{
					AnsiString mail=AnsiString(otpr_email);
					if (glPodrProtokol==true) {SaveProtocol(mail.c_str());}

					if ( lpMessage != 0)
						{

				if (glPodrProtokol==true) {SaveProtocol( UnicodeString(lpMessage->lpszSubject) );}
				if (glPodrProtokol==true) {SaveProtocol("Количество файлов - "+IntToStr((int)lpMessage -> nFileCount));}
				if ( lpMessage -> nFileCount > 0 )
					{
					for ( int i = 0; i < (int)lpMessage -> nFileCount; i++ )
					if (glPodrProtokol==true) {SaveProtocol( "Attatchments: "+ UnicodeString((LPSTR)lpMessage -> lpFiles[i].lpszFileName));}
					}




					AnsiString mail_from_message=AnsiString(lpMessage->lpOriginator->lpszAddress);
					AnsiString s="Проверяем отправителя: mail "+mail+" mail_from_message "+mail_from_message;

					if (glPodrProtokol==true) {SaveProtocol(s.c_str());}

					if ( mail == mail_from_message)
						{
						if (glPodrProtokol==true) {SaveProtocol("Отправитель совпадает. Это команда обмена");}
						//создаем входящую сообщение
						if (test==0)
							{
							TkanMapiMessage * mes=new TkanMapiMessage();
							CreateKanMessageFromMailMessage(lpMessage,mes);
							mes_list->List->Add(mes);
							}
						}
						}
					else
						{
						if (glPodrProtokol==true) {SaveProtocol("MAPIMessage ==0");}
						}
					}
				catch (Exception &exception)
					{
					TextError=TextError+" Ошибка выборки сообщения "+exception.Message;
					AnsiString s=TextError+" Ошибка выборки сообщения "+exception.Message;
					if (glPodrProtokol==true) {SaveProtocol(s.c_str());}
					result=false;
					}







			}

			MAPIFreeBuffer (lpMessage);
            lpMessage=0L;

			lstrcpy (szSeedMsgID, szMsgID);

			if (glPodrProtokol==true) {SaveProtocol("-------------------------------------------------");}
			if (glPodrProtokol==true) {SaveProtocol(" ");}
			hRes = lpfnMAPIFindNext (m_lhSession, 0L, NULL, szSeedMsgID,
				MAPI_GUARANTEE_FIFO | MAPI_LONG_MSGID, 0, szMsgID);
		}
	}
	else
	{
		hRes = MAPI_E_INVALID_SESSION;
		if (glPodrProtokol==true) {SaveProtocol( "Not logged on to messaging system.");}
		result=false;
	}









	hRes = S_OK;
	flFlags = 0L;
	ulReserved = 0L;

	// Free any buffers created by MAPI.

	// Always check to make sure there is an active session
	if ( m_lhSession )
	{
		//  If there is a valid session handle, attempt to logoff.

		hRes = lpfnMAPILogoff (
								m_lhSession,	// Global session handle.
								0L,				// Parent window.  Set to 0 since console app.
								flFlags,		// Ignored by MAPILogoff.
								ulReserved		// Reserved.  Must be 0L.
		  					   );

		if ( hRes == SUCCESS_SUCCESS )
		{
			// Invalidate session handle and inform user that logoff was successful
			m_lhSession = 0L;
			if (glPodrProtokol==true) {SaveProtocol( "Logoff attempt succeeded.");}
		}
		else
		{
			// Inform user that logoff attempt failed and report cause.
			if (glPodrProtokol==true) {SaveProtocol( "Logoff attempt failed due to error code ");}
			result=false;
			switch ( hRes )
			{
			case MAPI_E_FAILURE:
				if (glPodrProtokol==true) {SaveProtocol( "The flFlags parameter is invalid or one or more unspecified errors occurred.");};
				break;
			case MAPI_E_INSUFFICIENT_MEMORY:
				if (glPodrProtokol==true) {SaveProtocol("There was insufficient memory to proceed. The session was not terminated.");}
				break;
			case MAPI_E_INVALID_SESSION:
				if (glPodrProtokol==true) {SaveProtocol( "An invalid session handle was used for the lhSession parameter. The session was not terminated.");}
				break;
			default:
				if (glPodrProtokol==true) {SaveProtocol( "Unknown error code.");}
				break;
			}
		}
	}
	else
	{
		hRes = MAPI_E_INVALID_SESSION;
		if (glPodrProtokol==true) {SaveProtocol("Not logged on to messaging system.");}
	}





return result;

}

//-----------------------------------------------------------------------------
bool TkanMAPI::CreateKanMessageFromMailMessage(MapiMessage *mapi_message,TkanMapiMessage * mes)
{//сделать обычное сообщение из электронного письма
bool result=false;
if (glPodrProtokol==true) {SaveProtocol("Вход CreateKanMessageFromMailMessage");}
AnsiString mail_from_message=mapi_message->lpOriginator->lpszAddress;
AnsiString name_otpravitel_from_message=mapi_message->lpOriginator->lpszName;
AnsiString tema_from_message=mapi_message->lpszSubject;
AnsiString text_from_message=mapi_message->lpszNoteText;


mes->NameOtpravitel=name_otpravitel_from_message;
mes->EMail=mail_from_message;  //адрес от кого или куда посылать письмо
mes->UchRecord=""; //учетная запись для работы с почтовой программой
mes->TemaEmailMessage=tema_from_message;
mes->TextMessageList->Text=text_from_message;

if (glPodrProtokol==true) {SaveProtocol("Извлекаем вложенные файлы");}
//извлечь файлы из mapi
//можно скопировать файл в каталог Files текущего каталога
//надо только переименовать файл, ведь может быть несколько команд
//а ведь может и не быть файла
int kol_file=(int)mapi_message->nFileCount;
if (kol_file > 0)
	{
	if (glPodrProtokol==true) {SaveProtocol("В команде есть файлы");}
	AnsiString file_name=AnsiString(mapi_message->lpFiles[0].lpszPathName);
	mes->FileList_AddString(file_name);
	}
else
	{
	 if (glPodrProtokol==true) {SaveProtocol("В команде нет файлов");}
	}

if (glPodrProtokol==true) {SaveProtocol("Выход CreateKanMessageFromMailMessage");}
result=true;
return result;
}
//-----------------------------------------------------------------------------
bool TkanMAPI::DeleteComandFromSource(UnicodeString guid_comand, UnicodeString email)
{
bool result=false;

 ULONG result_func;                  // Для хранения кода ошибки
  LHANDLE lhSession;            // Сессия MAPI
  MapiMessage *MAPIMessage;     // Структура сообщения
  MapiRecipDesc *MAPIRecipient; // Структура получателя
  MapiFileDesc * MAPIAttach;        //вложения
  CHAR rgchMsgID[513]={0};          // Идентификатор сообщение >512

FLAGS flFindM = MAPI_LONG_MSGID;


/*--MAPILOGON--------------------------------------------------------------*/
  result_func=lpfnMAPILogon(0,                     // Handle диалогового окна созданного MAPILogon
						NULL,                   // Указатель на строку, содержащей путь к файлу настроек
						NULL,                   // Указатель на строку, содержащую пароль для доступа
						MAPI_NEW_SESSION,       // Флаги:
												//   MAPI_FORCE_DOWNLOAD - функция пытается загрузить все сообщения
												//   MAPI_LOGON_UI - показать диалог для идентификации
												//   MAPI_NEW_SESSION - создать новую сессию
						0,                      // Зарезервировано
						&lhSession);            // Указатель на сессию

if (result_func == SUCCESS_SUCCESS)
	{
	TStringList * str_list=new TStringList();

	// Ищем первое сообщение
	ULONG FinRes = lpfnMAPIFindNext(lhSession,0,0,0,flFindM,0,rgchMsgID);
	// Читаем найденное сообщение
	lpfnMAPIReadMail(lhSession,0,rgchMsgID,MAPI_PEEK,0,&MAPIMessage);
	while (1)
		{
		// Ищем нужное сообщение
		AnsiString mail=email;
		AnsiString mail_from_message=MAPIMessage->lpOriginator->lpszAddress;

		if ( mail == mail_from_message)
			{
			AnsiString text_from_message=MAPIMessage->lpszNoteText;
			str_list->Clear();
			str_list->Text=text_from_message;
			if (str_list->Count>=3)
				{
				AnsiString guid_mapi=str_list->Strings[1];
				if ( guid_mapi == guid_comand)
					{//удаляем данное сообщение
					result_func = lpfnMAPIDeleteMail(lhSession,0,rgchMsgID,0,0);
					if (result_func == SUCCESS_SUCCESS)
						{
						result=true;
						}
					else
						{
						result=false;
						TextError=TextError+" Ошибка удаления письма.(LPMAPIDELETEMAIL)";
						}
					}
				}
			}


		// Ищем очередное сообщение
		FinRes = lpfnMAPIFindNext(lhSession,0,0,rgchMsgID,flFindM,0,rgchMsgID);
		if (FinRes != SUCCESS_SUCCESS) break;
		// Читаем очередное сообщение
		lpfnMAPIReadMail(lhSession,0,rgchMsgID,MAPI_PEEK,0,&MAPIMessage);

		}

	delete str_list;

        // Закрытие сессии
		lpfnMAPILogoff(lhSession,        //Без флагов
					  0L,
					  0L,
					  0L);


	}
else
	{
	result=false;
	TextError=TextError+" Ошибка подключения к MAPI.(LPMAPILOGON)";
	}






return result;
}
//-----------------------------------------------------------------------------
void TkanMAPI::TestReadMessage(void)
{

// ULONG result_func;                  // Для хранения кода ошибки
//  LHANDLE lhSession;            // Сессия MAPI
//  MapiMessage *MAPIMessage;     // Структура сообщения
//  MapiRecipDesc *MAPIRecipient; // Структура получателя
//  MapiFileDesc * MAPIAttach;        //вложения
//  CHAR rgchMsgID[513]={0};          // Идентификатор сообщение >512
//
//
//
//FLAGS flFindM = MAPI_LONG_MSGID;
//
//SaveProtocol("Выполняем: lpfnMAPILogon");
///*--MAPILOGON--------------------------------------------------------------*/
//  result_func=lpfnMAPILogon(0,                     // Handle диалогового окна созданного MAPILogon
//						NULL,                   // Указатель на строку, содержащей путь к файлу настроек
//						NULL,                   // Указатель на строку, содержащую пароль для доступа
//						MAPI_NEW_SESSION,       // Флаги:
//												//   MAPI_FORCE_DOWNLOAD - функция пытается загрузить все сообщения
//												//   MAPI_LOGON_UI - показать диалог для идентификации
//												//   MAPI_NEW_SESSION - создать новую сессию
//						0,                      // Зарезервировано
//						&lhSession);            // Указатель на сессию
//
//	if (result_func==SUCCESS_SUCCESS)
//		{
//		SaveProtocol("Результат: SUCCESS_SUCCESS");
//		}
//	else
//		{
//		 SaveProtocol("Результат: не SUCCESS_SUCCESS");
//		}
//
//
//	// Ищем второе сообщение
//M1: SaveProtocol("-------------------------------------------------");
//	SaveProtocol(" ");
//	SaveProtocol("Выполняем Ищем текущее сообщение: lpfnMAPIFindNext(lhSession,0,0,rgchMsgID,flFindM,0,rgchMsgID)");
//
//	result_func = lpfnMAPIFindNext(lhSession,0,0,rgchMsgID,flFindM,0,rgchMsgID);
//
//	SaveProtocol("Выполнили Ищем текущее сообщение: lpfnMAPIFindNext(lhSession,0,0,rgchMsgID,flFindM,0,rgchMsgID)");
//	SaveProtocol(rgchMsgID);
//
//	if (result_func==SUCCESS_SUCCESS)
//		{
//		SaveProtocol("Результат: SUCCESS_SUCCESS");
//			// Читаем найденное сообщение
//			SaveProtocol("Выполняем: lpfnMAPIReadMail(lhSession,0,rgchMsgID,MAPI_PEEK,0,&MAPIMessage)");
//
//			//MAPIMessage=0;
//
//			result_func=lpfnMAPIReadMail(lhSession,0,rgchMsgID,MAPI_PEEK,0,&MAPIMessage);
//
//			SaveProtocol("Выполнили: lpfnMAPIReadMail(lhSession,0,rgchMsgID,MAPI_PEEK,0,&MAPIMessage)");
//
//			if (result_func==SUCCESS_SUCCESS)
//				{
//				SaveProtocol("Результат: SUCCESS_SUCCESS");
//				try
//					{
//					AnsiString mail_from_message=AnsiString(MAPIMessage->lpOriginator->lpszAddress);
//					AnsiString s="Оправитель:  "+mail_from_message;
//					SaveProtocol(s);
//					s= "Вложенных файлов "+ IntToStr((int)MAPIMessage->nFileCount);
//					SaveProtocol(s);
//					}
//				catch (Exception &exception)
//					{
//					TextError=TextError+" Ошибка выборки сообщения "+exception.Message;
//					AnsiString s=TextError+" Ошибка выборки сообщения "+exception.Message;
//					SaveProtocol(s.c_str());
//					}
//				goto M1;
//				}
//			else
//				{
//				SaveProtocol("Результат: lpfnMAPIReadMail не SUCCESS_SUCCESS");
//
//				goto M2;  //не смогли прочитать хотя бы одно сообщение
//				}
//
//
//
//		}
//	else
//		{
//		SaveProtocol("Результат lpfnMAPIFindNext: не SUCCESS_SUCCESS");
//		goto M2;  //не смогли найти следующее сообщение
//		}
//
//	// Закрытие сессии
//M2: SaveProtocol("Закрытие сессии");
//	result_func=lpfnMAPILogoff(lhSession,        //Без флагов
//					  0L,
//					  0L,
//					  0L);
//
//
//	if (result_func==SUCCESS_SUCCESS)
//		{
//		SaveProtocol("Результат: SUCCESS_SUCCESS");
//		}
//	else
//		{
//		 SaveProtocol("Результат: не SUCCESS_SUCCESS");
//		}

}
//-----------------------------------------------------------------------------
void TkanMAPI::SaveProtocol(UnicodeString str)
{
UnicodeString FileNameProtocol="";
FileNameProtocol=ExtractFileDir(Application->ExeName)+"\\Log\\"+ DateToStr(Date())+".txt";

str=TimeToStr(Time())+" "+str;

TkanTxtFile * f=new TkanTxtFile;
f->AddString(FileNameProtocol,str);
delete f;
}

//----------------------------------------------------------------------------
