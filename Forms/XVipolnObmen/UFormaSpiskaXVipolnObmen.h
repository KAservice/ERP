//---------------------------------------------------------------------------

#ifndef UFormaSpiskaXVipolnObmenH
#define UFormaSpiskaXVipolnObmenH
//---------------------------------------------------------------------------

#include "IDMXVipolnObmen.h"
#include "UDM.h"
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMTableExtPrintForm.h"

//-----------------------------------------------------------------------------
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
#include "cxCheckBox.hpp"
#include "cxClasses.hpp"
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
#include <DB.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxLookAndFeels.hpp"
#include "cxGridBandedTableView.hpp"
#include "cxGridDBBandedTableView.hpp"
#include "cxMemo.hpp"
#include "cxSpinEdit.hpp"
#include "cxButtonEdit.hpp"
#include "cxImage.hpp"
#include "cxTextEdit.hpp"
#include "cxGridCardView.hpp"
#include "cxGridDBCardView.hpp"
#include "frxClass.hpp"
#include "frxDesgn.hpp"
#include "frxPreview.hpp"
#include "cxPC.hpp"
#include "cxImageComboBox.hpp"
#include "cxContainer.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
//---------------------------------------------------------------------------
class TFormaSpiskaXVipolnObmen : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TLabel *HintLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TToolButton *ToolButton3;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TAction *ActionSaveIsmen;
	TAction *ActionCancelIsmen;
	TLabel *LabelNom;
	TcxPageControl *cxPageControl1;
	TToolButton *ToolButtonClose;
	TToolButton *ToolButton4;
	TcxGrid *cxGrid1;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SINFBASE_OBMEN;
	TcxGridDBColumn *cxGrid1DBTableView1NOACT_SINFBASE_OBMEN;
	TcxGridDBColumn *cxGrid1DBTableView1POS_ZAGR_XVIPOLN_OBMEN;
	TcxGridDBColumn *cxGrid1DBTableView1POS_VIGR_XVIPOLN_OBMEN;
	TTimer *Timer1;
	TToolButton *ToolButtonUpdateForm;
	TcxSpinEdit *IntrvalcxSpinEdit;
	TcxLabel *cxLabel1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

		  		//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall ToolButtonUpdateFormClick(TObject *Sender);

private:	// User declarations

	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

			bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму



	   enum  {ER_NoRekv, ER_EditImage} ER_Rekvisit;



public:		// User declarations
		__fastcall TFormaSpiskaXVipolnObmen(TComponent* Owner);

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

		//Текущий интерфейс
		IDMXVipolnObmen * DM;
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме
		__int64 IdPage;

		UnicodeString HeaderText;

        void UpdateForm();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaXVipolnObmen *FormaSpiskaXVipolnObmen;
//---------------------------------------------------------------------------
#endif
