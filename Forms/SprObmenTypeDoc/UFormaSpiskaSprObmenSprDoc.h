//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprObmenSprDocH
#define UFormaSpiskaSprObmenSprDocH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp>
#include "UDM.h"
#include "UDMSprObmenSklad.h"
#include <DBCtrls.hpp>
#include "UFormaSpiskaSprSklad.h"
//---------------------------------------------------------------------------
class TFormaSpiskaSprObmenTypeDoc : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TDBGrid *DBGrid1;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonEdit;
        TToolButton *ToolButtonDelete;
        TButton *ButtonClose;
        TToolButton *ToolButton4;
        TButton *ButtonOK;
        TLabel *HintLabel;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall DBGrid1EditButtonClick(TObject *Sender);
        void __fastcall ButtonOKClick(TObject *Sender);
        void __fastcall ToolButtonEditClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaSpiskaSprObmenTypeDoc(TComponent* Owner);

        HANDLE IdRodForm;
        HANDLE IdDochForm;

        TDMSprObmenSklad* DM;


        bool Vibor;
        bool OutReady;

        int IdBase;   

        int ViborIdNom;  //выбранная номенклатура
        bool AllElement;//текущее значение все элементы или нет
        bool Prosmotr;

        BEGIN_MESSAGE_MAP
                MESSAGE_HANDLER(MESSAGE_READY, TMessage,EndEdit)
        END_MESSAGE_MAP(TComponent)
        void __fastcall EndEdit(TMessage&Message);

        TFormaSpiskaSprSklad* SpisokSklad;

        void OpenFormSpiskaSprSklad();

        void DeleteElement();


        void UpdateForm(void);

        enum{NO,ViborSklad} ViborRekvisit;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprObmenTypeDoc *FormaSpiskaSprObmenTypeDoc;
//---------------------------------------------------------------------------
#endif
