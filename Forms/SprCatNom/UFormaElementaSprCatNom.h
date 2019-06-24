//---------------------------------------------------------------------------

#ifndef UFormaElementaSprCatNomH
#define UFormaElementaSprCatNomH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UDM.h"
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "UFormaSpiskaSprNom.h"
#include "UDMSprCatNom.h"
//---------------------------------------------------------------------------
class TFormaElementaSprCatNom : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TDBEdit *NameCatNom;
        TLabel *Label2;
        TDBEdit *KolCatNom;
        TButton *ButtonClose;
        TButton *ButtonOK;
        TLabel *Label11;
        TDBEdit *NameNom;
        TButton *ButtonVoborNom;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonOKClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall ButtonVoborNomClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaElementaSprCatNom(TComponent* Owner);

        TDMSprCatNom * DM;

        TFormaSpiskaSprNom * FormaSpiskaSprNom;

        HANDLE IdRodForm;
        HANDLE IdDochForm;

        enum {NO,ViborNom} ViborRekv;

        TNotifyEvent FOnCloseForm;
        void __fastcall EndVibor(TObject *Sender);
        void OpenFormSpiskaSprNom(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprCatNom *FormaElementaSprCatNom;
//---------------------------------------------------------------------------
#endif
