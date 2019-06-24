//---------------------------------------------------------------------------

#ifndef UFormaElementaSprDocKlientModH
#define UFormaElementaSprDocKlientModH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UDM.h"
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ComCtrls.hpp>
#include "UDMSprDocKlient.h"
//---------------------------------------------------------------------------
class TFormaElementaSprDocKlientMod : public TForm
{
__published:	// IDE-managed Components
        TButton *ButtonClose;
        TButton *ButtonOK;
        TLabel *Label3;
        TLabel *Label4;
        TDateTimePicker *DateVid;
        TDBEdit *NameDocDBEdit;
        TLabel *Label2;
        TDBEdit *SerDBEdit;
        TLabel *Label5;
        TDBEdit *NumDBEdit;
        TLabel *Label6;
        TDBEdit *VidDBEdit;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonOKClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall DateVidChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaElementaSprDocKlientMod(TComponent* Owner);

        TDMSprDocKlient * DM;
        HANDLE IdRodForm;
        HANDLE IdDochForm;

        enum {NO} ViborRekv;

        TNotifyEvent FOnCloseForm;
        void __fastcall EndVibor(TObject *Sender);

        bool OutReady;
        void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprDocKlientMod *FormaElementaSprDocKlientMod;
//---------------------------------------------------------------------------
#endif
