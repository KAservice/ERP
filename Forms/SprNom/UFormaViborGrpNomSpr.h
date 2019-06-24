//---------------------------------------------------------------------------

#ifndef UFormaViborGrpNomSprH
#define UFormaViborGrpNomSprH
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
#include "UDMSprNom.h"
#include "UDMSprGrpNom.h"
#include <DBCtrls.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxTreeView.hpp"
#include <Menus.hpp>
#include <ActnList.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaViborGrpNomSpr : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
	TcxButton *cxButtonClose;
	TcxTreeView *cxTreeView1;
	TActionList *ActionList1;
	TAction *OpenHelp;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall cxTreeView1DblClick(TObject *Sender);
	void __fastcall OpenHelpExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
		__fastcall TFormaViborGrpNomSpr(TComponent* Owner);

		IDMFibConnection * DM_Connection;
		bool Init(void);
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


        TNotifyEvent FOnCloseForm;
        HANDLE IdRodForm;
        HANDLE IdDochForm;
        TDMSprNom* DM;
        TDMSprGrpNom *DMGrp;

        bool Vibor;
        bool OutReady;
		__int64 IdGrp;      //текущая группа
        __int64 IdNom;       //текущий элемент
        bool AllElement;//текущее значение все элементы или нет
        bool Podbor;


        void __fastcall CloseElementSpr(TObject *Sender);



        void UpdateDerevo(void);
        enum{NO,ViborGrp,ViborElement, RekvisitPodborNom} ViborRekvisit;

        void UpdateForm(void);
        enum {PoiskPoCodu, PoiskPoName} PolePoiska;


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaViborGrpNomSpr *FormaViborGrpNomSpr;
//---------------------------------------------------------------------------
#endif
