//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprUserH
#define UFormaSpiskaSprUserH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "IDMSprUser.h"
#include "IDMSprGrpUser.h"
#include "IFormaElementaSprGrpUser.h"
#include "IDMFibConnection.h"
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
#include <ActnList.hpp>
#include "cxClasses.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include "cxTreeView.hpp"
#include <DB.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaSpiskaSprUser : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonEdit;
        TToolButton *ToolButtonDelete;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TPanel *Panel5;
	TToolButton *NewGrpUserToolButton;
	TToolButton *ToolButton3;
	TToolButton *EditGrpUserToolButton;
	TToolButton *DeleteGrpUserToolButton;
	TAction *ActionNewGrpUser;
	TAction *ActionEditGrpUser;
	TAction *ActionDeleteGrpUser;
	TAction *ActionNewElement;
	TAction *ActionEditElement;
	TAction *ActionDeleteElement;
	TLabel *LabelNameGrp;
	TAction *ActionPoGrp;
	TToolButton *ToolButton2;
	TAction *ActionChangeGrp;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TToolButton *ToolButtonNewUserServer;
	TToolButton *ToolButton6;
	TToolButton *ToolButtonUpdate;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_USER;
	TcxGridDBColumn *cxGrid1DBTableView1FNAME_USER;
	TcxGridDBColumn *cxGrid1DBTableView1NAME2_USER;
	TcxGridDBColumn *cxGrid1DBTableView1USERID;
	TcxTreeView *cxTreeView1;
	TcxButton *cxButtonClose;
	TToolButton *ToolButtonNasnRoleAllUser;
	TAction *ActionClose;
	TToolButton *ToolButtonAddStandartGrup;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ActionNewGrpUserExecute(TObject *Sender);
	void __fastcall ActionPoGrpExecute(TObject *Sender);
	void __fastcall ActionNewElementExecute(TObject *Sender);
	void __fastcall ActionEditElementExecute(TObject *Sender);
	void __fastcall ActionDeleteElementExecute(TObject *Sender);
	void __fastcall ActionChangeGrpExecute(TObject *Sender);
	void __fastcall ActionEditGrpUserExecute(TObject *Sender);
	void __fastcall ActionDeleteGrpUserExecute(TObject *Sender);
	void __fastcall ToolButtonNewUserServerClick(TObject *Sender);
	void __fastcall ToolButtonUpdateClick(TObject *Sender);
	void __fastcall cxTreeView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1USERIDCustomDrawCell(
          TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
          TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone);
	void __fastcall cxGrid1DBTableView1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ToolButtonNasnRoleAllUserClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ToolButtonAddStandartGrupClick(TObject *Sender);
private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

        void OpenFormElement();
		void OpenFormNewElement();
		void DeleteElement();
		void UpdateDerevo();
		enum{NO,ViborGrp,ViborElement} ViborRekvisit;
public:		// User declarations
		__fastcall TFormaSpiskaSprUser(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//из этой формы открыта другая для выбора
		//обработка события выбора в другой форме (которая была открыта из этой для выбора чего-то)
		int ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект (форму в которой производится выбор)
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									);


		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);


		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме


		//Текущий интерфейс
		IDMSprUser * DM;
		IDMSprGrpUser * DMGrp;



		__int64 IdGrp;
		__int64 IdUser;
		bool AllElement;
		void UpdateForm(void);


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprUser *FormaSpiskaSprUser;
//---------------------------------------------------------------------------
#endif
