//---------------------------------------------------------------------------

#ifndef UkanFileH
#define UkanFileH


class TkanFile
	{
private:

	void AddFileAnsiString(UnicodeString file_name, AnsiString str);
public:
	TkanFile();
	~TkanFile();

	void AddString(UnicodeString file_name, UnicodeString str);


	void XML_GreateHeader(UnicodeString file_name, UnicodeString version, UnicodeString encoding);
	void XML_AddString(UnicodeString file_name, UnicodeString str);
    AnsiString XML_FormatForXML(UnicodeString str);
	};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
