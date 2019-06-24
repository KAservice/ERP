//---------------------------------------------------------------------------

#ifndef UPrintPriceNumber1H
#define UPrintPriceNumber1H
#include "IDMFibConnection.h"
#include "USheetEditor.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
//---------------------------------------------------------------------------
class TPrintPriceNumber1
{
private:
        void PrintPriceNumber1_OutputGrp(void);
        void PrintPriceNumber1_OutputZagolovok(void);
        void PrintPriceNumber1_OutputElement(AnsiString name,
                                                AnsiString code,
                                                AnsiString price,
                                                AnsiString name_ed);

public:
        TPrintPriceNumber1();
		~TPrintPriceNumber1();

	IDMFibConnection * DM_Connection;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        void CreatePrice1(void);
        TList * List;

        TElementSpiskaPrintPrice * ElementSpiska;

        TSheetEditor * SE;
        int x, y;
        int KolNaString;
		int KolNaPage;
		__int64 IdTypePrice;
		AnsiString NameFirm;
		int NumberPage;
};
#endif


