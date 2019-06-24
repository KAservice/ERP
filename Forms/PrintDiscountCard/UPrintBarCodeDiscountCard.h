//---------------------------------------------------------------------------

#ifndef UPrintBarCodeDiscountCardH
#define UPrintBarCodeDiscountCardH
#include "UImageEditor.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class TPrintBarCodeDiscountCard
{
private:

public:
		TPrintBarCodeDiscountCard();
		~TPrintBarCodeDiscountCard();
        void CreateBarCode(void);
		AnsiString BarCodeValue;
        int x, y;
        int LineWidth;
        int LineHeight;
        AnsiString TopString;
		AnsiString BottomString;

};
//-------------------------------------------------------------------------
#endif
