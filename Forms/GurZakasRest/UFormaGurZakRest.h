//---------------------------------------------------------------------------

#ifndef UFormaGurZakRestH
#define UFormaGurZakRestH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "UDMGurZakRest.h"
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Menus.hpp>
#include "UForma_ZakazOf.h"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormaGurZakRest : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel4;
        TDBGrid *DBGrid1;
        TLabel *Label1;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TToolBar *ToolBar1;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn5;
        TBitBtn *BitBtn6;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall BitBtn5Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn6Click(TObject *Sender);
        void __fastcall DBGrid1DblClick(TObject *Sender);
        void __fastcall DBGrid1KeyPress(TObject *Sender, char &Key);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaGurZakRest(TComponent* Owner);

        TDMGurZakRest * DM;
        TForma_ZakazOf  * Forma_ZakazOf;
        void UpdateForm(void);


        HANDLE IdRodForm;
        HANDLE IdDochForm;
        TNotifyEvent FOnCloseForm;
        void __fastcall EndEdit(TObject *Sender);

        enum  {EditZakaz, NO} EditRekvisit;

        void CreateNewZakaz(void);
        void OpenZakaz(void);
        void DeleteZakaz(void);
        void OpenSpisokAllZakaz(void);
        void OpenSpisokMainZakas(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaGurZakRest *FormaGurZakRest;
//---------------------------------------------------------------------------
#endif
