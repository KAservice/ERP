//---------------------------------------------------------------------------

#ifndef UHLP_FormaSpiskaSprInfBlockSostavH
#define UHLP_FormaSpiskaSprInfBlockSostavH
//---------------------------------------------------------------------------

#include "IHLP_DMSprInfBlockSostav.h"
#include "UDM.h"
#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMTableExtPrintForm.h"
#include "IHLP_FormaSpiskaSprImage.h"
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
//---------------------------------------------------------------------------
class THLP_FormaSpiskaSprInfBlockSostav : public TForm
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
	TfrxDesigner *frxDesigner1;
	TfrxReport *frxReport1;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TfrxPreview *frxPreview1;
	TMemo *Memo1;
	TcxTabSheet *cxTabSheet3;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TToolButton *ToolButtonUpdateForm;
	TcxGridDBColumn *cxGrid1DBTableView1ID_ART_IB_S;
	TcxGridDBColumn *cxGrid1DBTableView1IDIB_ART_IB_S;
	TcxGridDBColumn *cxGrid1DBTableView1TYPE_ART_IB_S;
	TcxGridDBColumn *cxGrid1DBTableView1TEXT_ART_IB_ST;
	TcxGridDBColumn *cxGrid1DBTableView1IDIMG_ART_IB_S;
	TcxGridDBColumn *cxGrid1DBTableView1INDEX_ART_IB_S;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_ART_IMG;
	TPanel *Panel6;
	TButton *Button3;
	TToolButton *ToolButtonDesinerOpen;
	TToolButton *ToolButtonShowNoBase;
	TToolButton *ToolButtonSaveInBase;
	TPanel *Panel7;
	TToolButton *ToolButtonClose;
	TcxGridDBColumn *cxGrid1DBTableView1TYPE_TEXT_ART_IB_S;
	TToolButton *ToolButton4;
	TToolButton *ToolButtonsaveIsmen;
	TToolButton *ToolButtonAddString;
	TToolButton *ToolButtonDeleteString;
	TToolButton *ToolButtonPrint;
	TcxGridDBColumn *cxGrid1DBTableView1FONT_SIZE_ART_IB_S;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

		  		//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall cxGrid1DBTableView1NAME_HLP_IMAGEPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ToolButtonUpdateFormClick(TObject *Sender);
	void __fastcall ToolButtonDesinerOpenClick(TObject *Sender);
	void __fastcall ToolButtonShowNoBaseClick(TObject *Sender);
	void __fastcall ToolButtonSaveInBaseClick(TObject *Sender);
	void __fastcall ToolButtonsaveIsmenClick(TObject *Sender);
	void __fastcall ToolButtonAddStringClick(TObject *Sender);
	void __fastcall ToolButtonDeleteStringClick(TObject *Sender);
	void __fastcall ToolButtonPrintClick(TObject *Sender);

private:	// User declarations

	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

			bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму


	   IHLP_FormaSpiskaSprImage * FormaSpiskaSprImage;
	   void OpenFormaSpiskaSprImage(void);
	   void EndViborImage(void);

	   enum  {ER_NoRekv, ER_EditImage} ER_Rekvisit;



	   void LoadFromBase(void);

	   void SaveInBase(void);

	   UnicodeString GetZagolovokPage(__int64 id_page);

public:		// User declarations
		__fastcall THLP_FormaSpiskaSprInfBlockSostav(TComponent* Owner);

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
		IHLP_DMSprInfBlockSostav * DM;
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме
		__int64 IdPage;

		UnicodeString HeaderText;

        void UpdateForm();
};
//---------------------------------------------------------------------------
extern PACKAGE THLP_FormaSpiskaSprInfBlockSostav *HLP_FormaSpiskaSprInfBlockSostav;
//---------------------------------------------------------------------------
#endif
