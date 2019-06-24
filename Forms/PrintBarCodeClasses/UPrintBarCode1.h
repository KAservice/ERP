//---------------------------------------------------------------------------

#ifndef UPrintBarCode1H
#define UPrintBarCode1H
#include "UImageEditor.h"
//---------------------------------------------------------------------------
class TPrintBarCode1
{
private:

public:
        TPrintBarCode1();
        ~TPrintBarCode1();
        void CreateBarCode(void);
        AnsiString BarCodeValue;
        int x, y;
        int LineWidth;
        int LineHeight;
        AnsiString TopString;
		AnsiString BottomString;
		AnsiString PriceNom;

};
//-------------------------------------------------------------------------
#endif


