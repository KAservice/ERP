//---------------------------------------------------------------------------

#ifndef UFormaViborNomSprH
#define UFormaViborNomSprH
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
#include "UDMSprNom.h"
#include "UDMSprGrpNom.h"
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class TFormaViborNomSpr : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TTreeView *TreeView1;
        TPanel *Panel5;
        TDBGrid *DBGrid1;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNewGrp;
        TToolButton *ToolButtonEdiGrp;
        TToolButton *ToolButtonDeleteGrp;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonEdit;
        TToolButton *ToolButtonDelete;
        TButton *ButtonClose;
        TLabel *LabelNameGrp;
        TToolButton *ToolButton4;
        TToolButton *ToolButtonAll;
        TToolButton *ToolButtonIsmGrp;
        TComboBox *SpisokTypePrice;
        TLabel *HintLabel;
        TEdit *PoiskEdit;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonAllClick(TObject *Sender);
        void __fastcall TreeView1DblClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall TreeView1CustomDrawItem(TCustomTreeView *Sender,
          TTreeNode *Node, TCustomDrawState State, bool &DefaultDraw);
        void __fastcall DBGrid1DblClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall SpisokTypePriceChange(TObject *Sender);
        void __fastcall TreeView1KeyPress(TObject *Sender, char &Key);
        void __fastcall DBGrid1KeyPress(TObject *Sender, char &Key);
        void __fastcall PoiskEditChange(TObject *Sender);
        void __fastcall PoiskEditExit(TObject *Sender);
        void __fastcall PoiskEditKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaViborNomSpr(TComponent* Owner);

        HANDLE IdRodForm;
        HANDLE IdDochForm;
        TDMSprNom* DM;
        TDMSprGrpNom *DMGrp;

        bool Vibor;
        bool OutReady;
        int IdGrp;    //текущая группа
        bool AllElement;//текущее значение все элементы или нет

        void __fastcall CloseElementSpr(TObject *Sender);
        TNotifyEvent FOnCloseForm;

        void UpdateDerevo(void);
        enum{NO,ViborGrp,ViborElement} ViborRekvisit;
        enum {PoiskPoCodu, PoiskPoName} PolePoiska;
        
        void UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaViborNomSpr *FormaViborNomSpr;
//---------------------------------------------------------------------------
#endif
