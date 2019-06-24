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
		// �������� ������
//        (*lpfnMAPILogoff)(lhSession,        //��� ������
//                      0L,
//                      0L,
//                      0L);

	if (glPodrProtokol==true)
		{
		SaveProtocol("���������: FreeLibrary(hMAPILib)");
		}

		FreeLibrary(hMAPILib);

	if (glPodrProtokol==true)
		{
		SaveProtocol("���������: FreeLibrary(hMAPILib)");
		}
}
//----------------------------------------------------------------------------
bool TkanMAPI::Init(void)
{
bool result=false;

	if (glPodrProtokol==true)
		{
		SaveProtocol("���������: LoadLibrary(MAPI32.DLL");
		}

  hMAPILib = LoadLibrary("MAPI32.DLL");  // ��������� ����������
  if (hMAPILib==0)
	{
	ErrorLoadDll=true;
		if (glPodrProtokol==true)
		{
		SaveProtocol("���������: LoadLibrary(MAPI32.DLL) - ������");
		}
	}
  else
	{
	ErrorLoadDll=false;

		if (glPodrProtokol==true)
		{
		SaveProtocol("���������: LoadLibrary(MAPI32.DLL) - ��");
		}
	}

if (ErrorLoadDll==false)
	{
		if (glPodrProtokol==true)
		{
		SaveProtocol("���������: GetProcAddress");
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
		SaveProtocol("���������: GetProcAddress");
		}

	result=true;
	}
return result;
}
//------------------------------------------------------------------------------

bool TkanMAPI::SendMessage(TkanMapiMessage *mes)
{
bool result=false;
ULONG error;                  // ��� �������� ���� ������
LHANDLE lhSession;            // ������ MAPI
CHAR rgchMsgID[513];          // ������������� ��������� >512


/*--MAPILOGON--------------------------------------------------------------*/
  error=lpfnMAPILogon(0,                     // Handle ����������� ���� ���������� MAPILogon
						NULL,                   // ��������� �� ������, ���������� ���� � ����� ��������
						NULL,                   // ��������� �� ������, ���������� ������ ��� �������
						MAPI_NEW_SESSION,       // �����:
												//   MAPI_FORCE_DOWNLOAD - ������� �������� ��������� ��� ���������
												//   MAPI_LOGON_UI - �������� ������ ��� �������������
												//   MAPI_NEW_SESSION - ������� ����� ������
						0,                      // ���������������
						&lhSession);            // ��������� �� ������

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
		name_otpravitel.c_str(),                  //��� �����������
		mail.c_str(),     //�����
        0,
		NULL

	  };

	// ��������� ��������� ����
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

		// �������� ������
		lpfnMAPILogoff(lhSession,        //��� ������
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
//		SaveProtocol("���������: TkanMAPI::GetListMessage(TkanMapiMessageList * mes_list, UnicodeString otpr_email)");
//		}
//
// ULONG result_func;                  // ��� �������� ���� ������
//  LHANDLE lhSession;            // ������ MAPI
//  MapiMessage *MAPIMessage;     // ��������� ���������
//  MapiRecipDesc *MAPIRecipient; // ��������� ����������
//  MapiFileDesc * MAPIAttach;        //��������
//  CHAR rgchMsgID[513]={0};          // ������������� ��������� >512
//
//
//
//FLAGS flFindM = MAPI_LONG_MSGID;
//
//
///*--MAPILOGON--------------------------------------------------------------*/
//if ( !lhSession )
//	{
//  result_func=lpfnMAPILogon(0,                     // Handle ����������� ���� ���������� MAPILogon
//						NULL,                   // ��������� �� ������, ���������� ���� � ����� ��������
//						NULL,                   // ��������� �� ������, ���������� ������ ��� �������
//						MAPI_NEW_SESSION,       // �����:
//												//   MAPI_FORCE_DOWNLOAD - ������� �������� ��������� ��� ���������
//												//   MAPI_LOGON_UI - �������� ������ ��� �������������
//												//   MAPI_NEW_SESSION - ������� ����� ������
//						0,                      // ���������������
//						&lhSession);            // ��������� �� ������
//	}
//  else
//  {
//  if (glPodrProtokol==true) {SaveProtocol(" ����� ��� �������. lhSession!=0 ");}
//  }
//
//if (lhSession ==0)
//	{
//	if (glPodrProtokol==true) {SaveProtocol(" ����� lpfnMAPILogon. lhSession=0 ");}
//	result=false;
//	return result;
//	}
//
//if (result_func==SUCCESS_SUCCESS)
//	{
//
//
//	// ���� ������ ���������
//M1:	if (glPodrProtokol==true) {SaveProtocol("��������� ���� ������� ���������: lpfnMAPIFindNext(lhSession,0,0,rgchMsgID,flFindM,0,rgchMsgID)");}
//
//	if (glPodrProtokol==true) {SaveProtocol("-------------------------------------------------");}
//	if (glPodrProtokol==true) {SaveProtocol(" ");}
//
//		result_func = lpfnMAPIFindNext(lhSession,0,0,rgchMsgID,flFindM,0,rgchMsgID);
//		//result_func = lpfnMAPIFindNext(lhSession,0,0,rgchMsgID,flFindM,0,rgchMsgID);
//
//
//	if (glPodrProtokol==true) {SaveProtocol("��������� ���� ������� ���������: lpfnMAPIFindNext(lhSession,0,0,rgchMsgID,flFindM,0,rgchMsgID)");}
//	if (glPodrProtokol==true) {SaveProtocol(rgchMsgID);}
//	if (result_func==SUCCESS_SUCCESS)
//		{
//		if (glPodrProtokol==true) {SaveProtocol("���������: SUCCESS_SUCCESS");}
//			// ������ ��������� ���������
//			if (glPodrProtokol==true) {SaveProtocol("���������: lpfnMAPIReadMail(lhSession,0,rgchMsgID,MAPI_PEEK,0,&MAPIMessage)");}
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
//			if (glPodrProtokol==true) {SaveProtocol("���������: lpfnMAPIReadMail(lhSession,0,rgchMsgID,MAPI_PEEK,0,&MAPIMessage)");}
//
//			if (result_func==SUCCESS_SUCCESS)
//				{
//				if (glPodrProtokol==true) {SaveProtocol("���������: SUCCESS_SUCCESS");}
//				try
//					{
//					AnsiString mail=AnsiString(otpr_email);
//					if (glPodrProtokol==true) {SaveProtocol(mail.c_str());}
//
//					if ( MAPIMessage != 0)
//						{
//					AnsiString mail_from_message=AnsiString(MAPIMessage->lpOriginator->lpszAddress);
//					AnsiString s="��������� �����������: mail "+mail+" mail_from_message "+mail_from_message;
//
//					if (glPodrProtokol==true) {SaveProtocol(s.c_str());}
//
//					if ( mail == mail_from_message)
//						{
//						if (glPodrProtokol==true) {SaveProtocol("����������� ���������. ��� ������� ������");}
//						//������� �������� ���������
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
//					TextError=TextError+" ������ ������� ��������� "+exception.Message;
//					AnsiString s=TextError+" ������ ������� ��������� "+exception.Message;
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
//				if (glPodrProtokol==true) {SaveProtocol("���������: lpfnMAPIReadMail �� SUCCESS_SUCCESS");}
//
//				goto M2;  //�� ������ ��������� ���� �� ���� ���������
//				}
//
//
//
//		}
//	else if (result_func==MAPI_E_FAILURE)
//		{
//		if (glPodrProtokol==true) {SaveProtocol("��������� lpfnMAPIFindNext: �� SUCCESS_SUCCESS. ����������� ������");}
//		goto M2;  //�� ������ ����� ��������� ���������
//		}
//	else if (result_func==MAPI_E_INSUFFICIENT_MEMORY)
//		{
//		if (glPodrProtokol==true) {SaveProtocol("��������� lpfnMAPIFindNext: �� SUCCESS_SUCCESS. ������������ ������");}
//		goto M2;  //�� ������ ����� ��������� ���������
//		}
//	else if (result_func==MAPI_E_INVALID_MESSAGE )
//		{
//		if (glPodrProtokol==true) {SaveProtocol("��������� lpfnMAPIFindNext: �� SUCCESS_SUCCESS. �������� ������������� ��������� ��� ������� � �������� lpszMessageID.");}
//		goto M2;  //�� ������ ����� ��������� ���������
//		}
//	else if (result_func==MAPI_E_INVALID_SESSION)
//		{
//		if (glPodrProtokol==true) {SaveProtocol("��������� lpfnMAPIFindNext: �� SUCCESS_SUCCESS. ������������ handle ������ ��� ����������� � lhSession. ");}
//		goto M2;  //�� ������ ����� ��������� ���������
//		}
//	else if (result_func==MAPI_E_NO_MESSAGES)
//		{
//		if (glPodrProtokol==true) {SaveProtocol("��������� lpfnMAPIFindNext: �� SUCCESS_SUCCESS. ��������� �� �������. ");}
//		goto M2;  //�� ������ ����� ��������� ���������
//		}
//
//
//
//	// �������� ������
//M2: if (glPodrProtokol==true) {SaveProtocol("�������� ������");}
//	lpfnMAPILogoff(lhSession,        //��� ������
//					  0L,
//					  0L,
//					  0L);
//
//	}
//else if (result_func==MAPI_E_FAILURE)
//	{
//	result=false;
//	TextError=TextError+" ������ ����������� � MAPI.(LPMAPILOGON)����������� ������";
//	}
//else if (result_func==MAPI_E_INSUFFICIENT_MEMORY)
//	{
//	result=false;
//	TextError=TextError+" ������ ����������� � MAPI.(LPMAPILOGON)������������ ������ ��� ��������.";
//	}
//else if (result_func==MAPI_E_LOGIN_FAILURE)
//	{
//	result=false;
//	TextError=TextError+" ������ ����������� � MAPI.(LPMAPILOGON)��� ����������� �� ������ ��� ������������ ��� ����� � �������..";	}
//else if (result_func==MAPI_E_TOO_MANY_SESSIONS)
//	{
//	result=false;
//	TextError=TextError+" ������ ����������� � MAPI.(LPMAPILOGON)������� ����� ������ ���� ���������  ������������.   ";
//	}
//else if (result_func==MAPI_E_USER_ABORT)
//	{
//	result=false;
//	TextError=TextError+" ������ ����������� � MAPI.(LPMAPILOGON)������������ �������� ������ � ����� �� ���������� ���� (cancel).";
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
				if (glPodrProtokol==true) {SaveProtocol("���������� ������ - "+IntToStr((int)lpMessage -> nFileCount));}
				if ( lpMessage -> nFileCount > 0 )
					{
					for ( int i = 0; i < (int)lpMessage -> nFileCount; i++ )
					if (glPodrProtokol==true) {SaveProtocol( "Attatchments: "+ UnicodeString((LPSTR)lpMessage -> lpFiles[i].lpszFileName));}
					}




					AnsiString mail_from_message=AnsiString(lpMessage->lpOriginator->lpszAddress);
					AnsiString s="��������� �����������: mail "+mail+" mail_from_message "+mail_from_message;

					if (glPodrProtokol==true) {SaveProtocol(s.c_str());}

					if ( mail == mail_from_message)
						{
						if (glPodrProtokol==true) {SaveProtocol("����������� ���������. ��� ������� ������");}
						//������� �������� ���������
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
					TextError=TextError+" ������ ������� ��������� "+exception.Message;
					AnsiString s=TextError+" ������ ������� ��������� "+exception.Message;
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
{//������� ������� ��������� �� ������������ ������
bool result=false;
if (glPodrProtokol==true) {SaveProtocol("���� CreateKanMessageFromMailMessage");}
AnsiString mail_from_message=mapi_message->lpOriginator->lpszAddress;
AnsiString name_otpravitel_from_message=mapi_message->lpOriginator->lpszName;
AnsiString tema_from_message=mapi_message->lpszSubject;
AnsiString text_from_message=mapi_message->lpszNoteText;


mes->NameOtpravitel=name_otpravitel_from_message;
mes->EMail=mail_from_message;  //����� �� ���� ��� ���� �������� ������
mes->UchRecord=""; //������� ������ ��� ������ � �������� ����������
mes->TemaEmailMessage=tema_from_message;
mes->TextMessageList->Text=text_from_message;

if (glPodrProtokol==true) {SaveProtocol("��������� ��������� �����");}
//������� ����� �� mapi
//����� ����������� ���� � ������� Files �������� ��������
//���� ������ ������������� ����, ���� ����� ���� ��������� ������
//� ���� ����� � �� ���� �����
int kol_file=(int)mapi_message->nFileCount;
if (kol_file > 0)
	{
	if (glPodrProtokol==true) {SaveProtocol("� ������� ���� �����");}
	AnsiString file_name=AnsiString(mapi_message->lpFiles[0].lpszPathName);
	mes->FileList_AddString(file_name);
	}
else
	{
	 if (glPodrProtokol==true) {SaveProtocol("� ������� ��� ������");}
	}

if (glPodrProtokol==true) {SaveProtocol("����� CreateKanMessageFromMailMessage");}
result=true;
return result;
}
//-----------------------------------------------------------------------------
bool TkanMAPI::DeleteComandFromSource(UnicodeString guid_comand, UnicodeString email)
{
bool result=false;

 ULONG result_func;                  // ��� �������� ���� ������
  LHANDLE lhSession;            // ������ MAPI
  MapiMessage *MAPIMessage;     // ��������� ���������
  MapiRecipDesc *MAPIRecipient; // ��������� ����������
  MapiFileDesc * MAPIAttach;        //��������
  CHAR rgchMsgID[513]={0};          // ������������� ��������� >512

FLAGS flFindM = MAPI_LONG_MSGID;


/*--MAPILOGON--------------------------------------------------------------*/
  result_func=lpfnMAPILogon(0,                     // Handle ����������� ���� ���������� MAPILogon
						NULL,                   // ��������� �� ������, ���������� ���� � ����� ��������
						NULL,                   // ��������� �� ������, ���������� ������ ��� �������
						MAPI_NEW_SESSION,       // �����:
												//   MAPI_FORCE_DOWNLOAD - ������� �������� ��������� ��� ���������
												//   MAPI_LOGON_UI - �������� ������ ��� �������������
												//   MAPI_NEW_SESSION - ������� ����� ������
						0,                      // ���������������
						&lhSession);            // ��������� �� ������

if (result_func == SUCCESS_SUCCESS)
	{
	TStringList * str_list=new TStringList();

	// ���� ������ ���������
	ULONG FinRes = lpfnMAPIFindNext(lhSession,0,0,0,flFindM,0,rgchMsgID);
	// ������ ��������� ���������
	lpfnMAPIReadMail(lhSession,0,rgchMsgID,MAPI_PEEK,0,&MAPIMessage);
	while (1)
		{
		// ���� ������ ���������
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
					{//������� ������ ���������
					result_func = lpfnMAPIDeleteMail(lhSession,0,rgchMsgID,0,0);
					if (result_func == SUCCESS_SUCCESS)
						{
						result=true;
						}
					else
						{
						result=false;
						TextError=TextError+" ������ �������� ������.(LPMAPIDELETEMAIL)";
						}
					}
				}
			}


		// ���� ��������� ���������
		FinRes = lpfnMAPIFindNext(lhSession,0,0,rgchMsgID,flFindM,0,rgchMsgID);
		if (FinRes != SUCCESS_SUCCESS) break;
		// ������ ��������� ���������
		lpfnMAPIReadMail(lhSession,0,rgchMsgID,MAPI_PEEK,0,&MAPIMessage);

		}

	delete str_list;

        // �������� ������
		lpfnMAPILogoff(lhSession,        //��� ������
					  0L,
					  0L,
					  0L);


	}
else
	{
	result=false;
	TextError=TextError+" ������ ����������� � MAPI.(LPMAPILOGON)";
	}






return result;
}
//-----------------------------------------------------------------------------
void TkanMAPI::TestReadMessage(void)
{

// ULONG result_func;                  // ��� �������� ���� ������
//  LHANDLE lhSession;            // ������ MAPI
//  MapiMessage *MAPIMessage;     // ��������� ���������
//  MapiRecipDesc *MAPIRecipient; // ��������� ����������
//  MapiFileDesc * MAPIAttach;        //��������
//  CHAR rgchMsgID[513]={0};          // ������������� ��������� >512
//
//
//
//FLAGS flFindM = MAPI_LONG_MSGID;
//
//SaveProtocol("���������: lpfnMAPILogon");
///*--MAPILOGON--------------------------------------------------------------*/
//  result_func=lpfnMAPILogon(0,                     // Handle ����������� ���� ���������� MAPILogon
//						NULL,                   // ��������� �� ������, ���������� ���� � ����� ��������
//						NULL,                   // ��������� �� ������, ���������� ������ ��� �������
//						MAPI_NEW_SESSION,       // �����:
//												//   MAPI_FORCE_DOWNLOAD - ������� �������� ��������� ��� ���������
//												//   MAPI_LOGON_UI - �������� ������ ��� �������������
//												//   MAPI_NEW_SESSION - ������� ����� ������
//						0,                      // ���������������
//						&lhSession);            // ��������� �� ������
//
//	if (result_func==SUCCESS_SUCCESS)
//		{
//		SaveProtocol("���������: SUCCESS_SUCCESS");
//		}
//	else
//		{
//		 SaveProtocol("���������: �� SUCCESS_SUCCESS");
//		}
//
//
//	// ���� ������ ���������
//M1: SaveProtocol("-------------------------------------------------");
//	SaveProtocol(" ");
//	SaveProtocol("��������� ���� ������� ���������: lpfnMAPIFindNext(lhSession,0,0,rgchMsgID,flFindM,0,rgchMsgID)");
//
//	result_func = lpfnMAPIFindNext(lhSession,0,0,rgchMsgID,flFindM,0,rgchMsgID);
//
//	SaveProtocol("��������� ���� ������� ���������: lpfnMAPIFindNext(lhSession,0,0,rgchMsgID,flFindM,0,rgchMsgID)");
//	SaveProtocol(rgchMsgID);
//
//	if (result_func==SUCCESS_SUCCESS)
//		{
//		SaveProtocol("���������: SUCCESS_SUCCESS");
//			// ������ ��������� ���������
//			SaveProtocol("���������: lpfnMAPIReadMail(lhSession,0,rgchMsgID,MAPI_PEEK,0,&MAPIMessage)");
//
//			//MAPIMessage=0;
//
//			result_func=lpfnMAPIReadMail(lhSession,0,rgchMsgID,MAPI_PEEK,0,&MAPIMessage);
//
//			SaveProtocol("���������: lpfnMAPIReadMail(lhSession,0,rgchMsgID,MAPI_PEEK,0,&MAPIMessage)");
//
//			if (result_func==SUCCESS_SUCCESS)
//				{
//				SaveProtocol("���������: SUCCESS_SUCCESS");
//				try
//					{
//					AnsiString mail_from_message=AnsiString(MAPIMessage->lpOriginator->lpszAddress);
//					AnsiString s="����������:  "+mail_from_message;
//					SaveProtocol(s);
//					s= "��������� ������ "+ IntToStr((int)MAPIMessage->nFileCount);
//					SaveProtocol(s);
//					}
//				catch (Exception &exception)
//					{
//					TextError=TextError+" ������ ������� ��������� "+exception.Message;
//					AnsiString s=TextError+" ������ ������� ��������� "+exception.Message;
//					SaveProtocol(s.c_str());
//					}
//				goto M1;
//				}
//			else
//				{
//				SaveProtocol("���������: lpfnMAPIReadMail �� SUCCESS_SUCCESS");
//
//				goto M2;  //�� ������ ��������� ���� �� ���� ���������
//				}
//
//
//
//		}
//	else
//		{
//		SaveProtocol("��������� lpfnMAPIFindNext: �� SUCCESS_SUCCESS");
//		goto M2;  //�� ������ ����� ��������� ���������
//		}
//
//	// �������� ������
//M2: SaveProtocol("�������� ������");
//	result_func=lpfnMAPILogoff(lhSession,        //��� ������
//					  0L,
//					  0L,
//					  0L);
//
//
//	if (result_func==SUCCESS_SUCCESS)
//		{
//		SaveProtocol("���������: SUCCESS_SUCCESS");
//		}
//	else
//		{
//		 SaveProtocol("���������: �� SUCCESS_SUCCESS");
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
