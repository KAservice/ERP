//---------------------------------------------------------------------------

#ifndef UkanIniFileH
#define UkanIniFileH

#include "inifiles.hpp"
class TkanIniFile
	{
private:


public:
	TkanIniFile(UnicodeString file_name);
	~TkanIniFile();

	TIniFile * Ini;

	UnicodeString ReadString(UnicodeString section,UnicodeString ident,
													UnicodeString default_value);

	int ReadIntegerValue(UnicodeString section,UnicodeString ident,
													int default_value);

	bool ReadBoolValue(UnicodeString section,UnicodeString ident,
													bool default_value);

	void WriteString(UnicodeString section,UnicodeString ident,
											UnicodeString value);


	void ReadSections(TStrings * str);

	};
//---------------------------------------------------------------------------
#endif
