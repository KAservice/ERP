//---------------------------------------------------------------------------

#ifndef UFiskRegH
#define UFiskRegH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UShtrihFRK.h"
#include "UMercuryMSK.h"
//---------------------------------------------------------------------------
class TFiskReg : public TForm
{
__published:	// IDE-managed Components
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFiskReg(TComponent* Owner);

        TShtrihFRK * ShtrihFRK;
        TMercuryMSK *MSK;

        String ComName;
        String BaudRate;
        String Password;
        int TypeKKM;
        //0 не использовать
        //1 Штрих-ФР-К
        //2 Меркурий-MS-K
        //3 Штрих-Комбо-ФР-К

        int Department;
        float SumCheck;
        float OplataNal;
        float OplataPlatCard;

        String Str;
        bool Girn;
        int Alignment;  //0- лево 1-право

        enum {Sale, ReturnSale} Operation;


        bool Connect(void);
        bool Disconnect(void);
        bool PrintString(String str);
        bool PrintFiscalCheck(void);
        bool PrintNoFiscalCheck(void);
        bool PrintXReport(void);
        bool PrintZReport(void);
        bool PrintPoOtdelamReport(void);

        bool Cut(int TypeCut);
        bool Vnesenie(float sum);
        bool Snatie(float sum);

        bool PrintLine(void);

        void OpenNoFiscalCheck(void);
        void CloseNoFiscalCheck(void);

        void GetSostKKM(void);
        bool ProvVosmPrintCheck(void);
        int NumberCheck;
        int NumberKL;
        String SerialNumberKKM;

        bool UseJournalRibbon;
        bool UseReceiptRibbon;

        int Number;
        AnsiString Modul;
        AnsiString NameScaner;
        bool Init();

};
//---------------------------------------------------------------------------
extern PACKAGE TFiskReg *FiskReg;
//---------------------------------------------------------------------------
#endif
