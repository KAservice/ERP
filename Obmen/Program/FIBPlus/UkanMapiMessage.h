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
	UnicodeString EMail;  //����� �� ���� ��� ���� �������� ������
	UnicodeString UchRecord; //������� ������ ��� ������ � �������� ����������
	UnicodeString TemaEmailMessage;
	TStringList * TextMessageList;


	//������ ��������� (��������������) ������
	TStringList * FileList;
	int FileList_GetCount(void);
	UnicodeString FileList_GetString(int index_string);
	void FileList_AddString(UnicodeString file_name);
};
#endif
