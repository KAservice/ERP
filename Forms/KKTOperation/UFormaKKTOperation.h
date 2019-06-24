//---------------------------------------------------------------------------

#ifndef UFormaKKTOperationH
#define UFormaKKTOperationH
//---------------------------------------------------------------------------
#include "IDMViborOborud.h"
#include "IDMFibConnection.h"
#include "IFiskReg.h"
//---------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtons.hpp"
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxTimeEdit.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxGroupBox.hpp"
#include "cxPC.hpp"
#include <ExtCtrls.hpp>
#include "cxCalc.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeels.hpp"
#include "cxClasses.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxStyles.hpp"
#include <DB.hpp>
//---------------------------------------------------------------------------
class TFormaKKTOperation : public TForm
{
__published:	// IDE-managed Components
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TcxTabSheet *cxTabSheet3;
	TPanel *Panel1;
	TLabel *Label3;
	TcxComboBox *cxComboBoxFR;
	TcxButton *cxButtonXReport;
	TcxButton *cxButtonZReport;
	TPanel *Panel2;
	TcxButton *cxButtonClose;
	TcxGroupBox *cxGroupBox1;
	TcxButton *cxButtonSetTimeKKM;
	TcxButton *cxButtonGetTekPCTime;
	TcxButton *cxButtonGetTimeFR;
	TcxTimeEdit *cxTimeEdit;
	TLabel *Label1;
	TcxGroupBox *cxGroupBox2;
	TcxButton *cxButtonGetTekPCDate;
	TcxButton *cxButtonSetDateKKM;
	TcxButton *cxButtonGetDateFR;
	TcxDateEdit *cxDateEdit;
	TLabel *Label2;
	TcxTabSheet *cxTabSheet4;
	TcxButton *cxButtonOpenShift;
	TcxButton *cxButtonCloseShift;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridTableView *cxGrid1TableView1;
	TcxGridColumn *cxGrid1TableView1Department;
	TcxGridColumn *cxGrid1TableView1NameTovar;
	TcxGridColumn *cxGrid1TableView1Kol;
	TcxGridColumn *cxGrid1TableView1Price;
	TcxGridColumn *cxGrid1TableView1Sum;
	TcxLabel *cxLabel1;
	TPanel *Panel3;
	TPanel *Panel4;
	TcxButton *cxButtonSale;
	TcxCalcEdit *OplataNalcxCalcEdit;
	TcxCalcEdit *OplataPlatCardcxCalcEdit;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TGroupBox *GroupBox1;
	TRadioButton *RadioButtonSale;
	TRadioButton *RadioButtonReturnSale;
	void __fastcall cxButtonGetTekPCTimeClick(TObject *Sender);
	void __fastcall cxButtonGetTekPCDateClick(TObject *Sender);
	void __fastcall cxButtonSetTimeKKMClick(TObject *Sender);
	void __fastcall cxButtonGetTimeFRClick(TObject *Sender);
	void __fastcall cxButtonSetDateKKMClick(TObject *Sender);
	void __fastcall cxButtonGetDateFRClick(TObject *Sender);
	void __fastcall cxButtonXReportClick(TObject *Sender);
	void __fastcall cxButtonZReportClick(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall cxButtonSaleClick(TObject *Sender);
	void __fastcall cxButtonReturnSaleClick(TObject *Sender);
	void __fastcall cxButtonOpenShiftClick(TObject *Sender);
	void __fastcall cxButtonCloseShiftClick(TObject *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
	IDMViborOborud * DMViborFR;


	IFiskReg * ConnectFR(void);
	bool DisconnectFR(IFiskReg * fr);

public:		// User declarations
	__fastcall TFormaKKTOperation(TComponent* Owner);

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







};
//---------------------------------------------------------------------------
extern PACKAGE TFormaKKTOperation *FormaKKTOperation;
//---------------------------------------------------------------------------
#endif
