//---------------------------------------------------------------------------

#ifndef UPrintBarCode3H
#define UPrintBarCode3H
#include "UImageEditor.h"
//---------------------------------------------------------------------------
class TPrintBarCode3
{
private:

public:
		TPrintBarCode3();
        ~TPrintBarCode3();
        void CreateBarCode(void);
        AnsiString BarCodeValue;
        int x, y;
        int LineWidth;
        int LineHeight;
		AnsiString Zagolovok;
		AnsiString String2;
		AnsiString NameNom;
		AnsiString PriceNom;
		AnsiString StringForPrint;
};
//-------------------------------------------------------------------------
#endif
