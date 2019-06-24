//---------------------------------------------------------------------------

#ifndef UkanXmlFileH
#define UkanXmlFileH

#include "SYSUtils.hpp"
#include <fstream.h>

class TkanXmlFile
	{
private:
	FILE * InFile;
	bool AddFileAnsiString(UnicodeString file_name,AnsiString str);
public:
	TkanXmlFile();
	~TkanXmlFile();

	//void AddString(UnicodeString file_name, UnicodeString str);


	bool GreateHeader(UnicodeString file_name);
	bool AddString(UnicodeString file_name,UnicodeString str);
	UnicodeString FormatForXML(UnicodeString str);


	bool OpenFile(UnicodeString file_name);
	UnicodeString ReadString(void);  //читаем текущую строку
	bool Eof(void);
	bool CloseFile(void);




	};
//---------------------------------------------------------------------------
#endif
