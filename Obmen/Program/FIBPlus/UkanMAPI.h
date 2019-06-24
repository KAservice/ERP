//---------------------------------------------------------------------------

#ifndef UkanMAPIH
#define UkanMAPIH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "UkanComandExchange.h"
//#include <windows.h>
//#include <windowsx.h>
#include <mapi.h>
#include "UkanComandBuilder.h"
#include "UkanMapiMessage.h"
#include "UkanMapiMessageList.h"
//#include <winbase.h>
//#include <vector>


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

class TkanMAPI
{
private:
HINSTANCE hMAPILib;

LPMAPIADDRESS lpfnMAPIAddress;
LPMAPIDELETEMAIL lpfnMAPIDeleteMail;
LPMAPIDETAILS lpfnMAPIDetails;
LPMAPIFINDNEXT lpfnMAPIFindNext;
LPMAPIFREEBUFFER lpfnMAPIFreeBuffer;
LPMAPILOGOFF lpfnMAPILogoff;
LPMAPILOGON lpfnMAPILogon;
LPMAPIREADMAIL lpfnMAPIReadMail;
LPMAPIRESOLVENAME lpfnMAPIResolveName;
LPMAPISAVEMAIL lpfnMAPISaveMail;
LPMAPISENDDOCUMENTS lpfnMAPISendDocuments;
LPMAPISENDMAIL lpfnMAPISendMail;




public:
	TkanMAPI();
	~TkanMAPI();

	bool Init(void);

	UnicodeString TextError;

	bool ErrorLoadDll;

	bool SendMessage(TkanMapiMessage *mes);

	bool GetListMessage(TkanMapiMessageList * mes_list, UnicodeString otpr_email, int test);
	bool CreateKanMessageFromMailMessage(MapiMessage *mapi_message,TkanMapiMessage * mes);

	bool DeleteComandFromSource(UnicodeString guid_comand, UnicodeString email);

	bool flTestMapi;
	void TestReadMessage(void);

	void SaveProtocol(UnicodeString str);

};
#endif
