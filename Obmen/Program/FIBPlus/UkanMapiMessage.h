//---------------------------------------------------------------------------

#ifndef UkanMapiMessageH
#define UkanMapiMessageH
//---------------------------------------------------------------------------
#include <Classes.hpp>


class TkanMapiMessage
{
private:


public:
		TkanMapiMessage();
		~TkanMapiMessage();


	UnicodeString NameOtpravitel;
	UnicodeString EMail;  //адрес от кого или куда посылать письмо
	UnicodeString UchRecord; //учетная запись для работы с почтовой программой
	UnicodeString TemaEmailMessage;
	TStringList * TextMessageList;


	//список вложенных (присоединенных) файлов
	TStringList * FileList;
	int FileList_GetCount(void);
	UnicodeString FileList_GetString(int index_string);
	void FileList_AddString(UnicodeString file_name);
};
#endif
