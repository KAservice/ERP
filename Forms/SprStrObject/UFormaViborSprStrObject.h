//---------------------------------------------------------------------------

#ifndef UFormaViborSprStrObjectH
#define UFormaViborSprStrObjectH
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
#include "UDMSprStrObject.h"
#include "UFormaElementaSprStrObject.h"
//---------------------------------------------------------------------------
class TFormaViborSprStrObject : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TTreeView *TreeView1;
        TButton *ButtonClose;
        TLabel *Label1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall TreeView1CustomDrawItem(TCustomTreeView *Sender,
          TTreeNode *Node, TCustomDrawState State, bool &DefaultDraw);
        void __fastcall TreeView1DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaViborSprStrObject(TComponent* Owner);

        HANDLE IdRodForm;
        HANDLE IdDochForm;
        TDMSprStrObject *DMGrp;
        TFormaElementaSprStrObject * FormaGrpElementa;
        bool Vibor;
        bool OutReady;
        int ViborIdObject;
        int IdGrp;    //текущая группа
        bool AllElement;//текущее значение все элементы или нет

        void __fastcall CloseElementSpr(TObject *Sender);
        TNotifyEvent FOnCloseForm;

        void UpdateDerevo(void);
        enum{NO,ViborGrp,ViborElement} ViborRekvisit;


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaViborSprStrObject *FormaViborSprStrObject;
//---------------------------------------------------------------------------
#endif
