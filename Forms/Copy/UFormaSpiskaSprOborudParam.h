//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprOborudParamH
#define UFormaSpiskaSprOborudParamH
//---------------------------------------------------------------------------
#include "IDMInterfMainMenuPar.h"
#include "UDM.h"
#include "IDMFibConnection.h"
#include "IkasDMSpr.h"
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
#include "cxCalc.hpp"
#include "cxCalendar.hpp"
#include "cxCheckBox.hpp"
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include "cxImageComboBox.hpp"

//---------------------------------------------------------------------------
class TFormaSpiskaSprOborudParam : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonDelete;
	TLabel *LabelHeader;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxGridDBColumn *cxGrid1DBTableView1ID_SOBORUD_PAR;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SOBORUD_PAR;
	TcxGridDBColumn *cxGrid1DBTableView1VALUE_SOBORUD_PAR;
	TcxGridDBColumn *cxGrid1DBTableView1VALUE_TIMESTAMP_SOBORUD_PAR;
	TcxGridDBColumn *cxGrid1DBTableView1INDEX_SOBORUD_PAR;
	TcxGridDBColumn *cxGrid1DBTableView1BEFORE_CONNECT_SOBORUD_PAR;
	TcxGridDBColumn *cxGrid1DBTableView1AFTER_CONNECT_SOBORUD_PAR;
	TcxGridDBColumn *cxGrid1DBTableView1ON_CONNECT_SOBORUD_PAR;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_GRP_SOBORUD_PAR;
	TToolButton *ToolButtonGetParameterIsFiskRegSaveInFile;
	TToolButton *ToolButtonSaveInFileDopAction;
	TSaveTextFileDialog *SaveTextFileDialog1;
	TToolButton *ToolButtonGetSpisokMetod;
	TcxGridDBColumn *cxGrid1DBTableView1TYPE_PARAMETER_SOBORUD_PAR;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ToolButtonGetParameterIsFiskRegSaveInFileClick(TObject *Sender);
	void __fastcall ToolButtonSaveInFileDopActionClick(TObject *Sender);
	void __fastcall ToolButtonGetSpisokMetodClick(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
public:		// User declarations
		__fastcall TFormaSpiskaSprOborudParam(TComponent* Owner);

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
	   // IDMInterfMainMenuPar* DM;
	   //	__int64 IdOwner;
	   //	UnicodeString TextHeader;
	  //	bool Vibor;                        //форма открыта для выбора
	   //	int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме
	   // void UpdateForm(void);
	   //	void DeleteElement();




       //IkasForm
	void UpdateForm(void);
	bool Vibor;
	int NumberProcVibor;
	   //IkasFormSpr

	__int64 IdGroupEl1;
	UnicodeString NameGroupEl1;

	__int64 IdGroupEl2;
	UnicodeString NameGroupEl2;

	__int64 IdOwner;
	UnicodeString NameOwner;

	__int64 IdGrp;
	UnicodeString NameGrp;

	__int64 IdEl;
	UnicodeString NameEl;

	bool All;


	IkasDMSpr * DM;





};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprOborudParam *FormaSpiskaSprOborudParam;
//---------------------------------------------------------------------------
#endif
