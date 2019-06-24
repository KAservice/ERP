//---------------------------------------------------------------------------

#ifndef UkanBaseGuidH
#define UkanBaseGuidH
#include "vcl.h"
//---------------------------------------------------------------------------

class  TkanBaseGuid
{
private:


public:
   TkanBaseGuid();
   ~TkanBaseGuid();

   UnicodeString TextError;

   UnicodeString GetProgIDFromCLSID(GUID guid);
   GUID GetCLSIDFromProgID(UnicodeString prog_id);

   bool AddClass(REFIID id_class, UnicodeString prog_id, UnicodeString file_name_modul);
   bool RemoveClass(REFIID id_class);

   UnicodeString GetNameModul(REFIID id_class);

   AnsiString DopStrL(AnsiString Str, AnsiString Symbol, int Len) ;
   AnsiString DopStrR(AnsiString Str, AnsiString Symbol, int Len) ;
};

#endif
