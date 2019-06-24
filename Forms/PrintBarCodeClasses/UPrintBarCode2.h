//---------------------------------------------------------------------------

#ifndef UPrintBarCode2H
#define UPrintBarCode2H
#include "UDM.h"
#include "UImageEditor.h"
//---------------------------------------------------------------------------

class TclPrintBarCode2
{
private:
        void PrintBarCode_OutputGrp(void);
        void PrintBarCode_OutputZagolovok(void);
        void PrintBarCode_OutputElement(AnsiString name,
                                                AnsiString code,
                                                AnsiString price,
                                                AnsiString name_ed,
                                                int kol,
                                                AnsiString bar_code);

public:
        TclPrintBarCode2();
        ~TclPrintBarCode2();
        void CreatePrintBarCode(void);
        TList * List;

        TElementSpiskaPrintPrice * ElementSpiska;
        TImageEditor *ImageEditor;
        int x, y;
        int start_x,start_y;
        int KolNaString;
        int KolNaPage;
		int Col,Row;
		__int64 IdTypePrice;
};

#endif
