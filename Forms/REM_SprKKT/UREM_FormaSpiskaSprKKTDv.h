//---------------------------------------------------------------------------

#ifndef UREM_FormaSpiskaSprKKTDvH
#define UREM_FormaSpiskaSprKKTDvH
//---------------------------------------------------------------------------
#include "IREM_DMSprKKTDv.h"
#include "UDM.h"
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
//---------------------------------------------------------------------------
class TREM_FormaSpiskaSprKKTDv : public TForm
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
	TLabel *LabelZayavka;
        TToolButton *ToolButton2;
        TLabel *HintLabel;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxButton *cxButtonClose;
	TcxGridDBColumn *cxGrid1DBTableView1POS_REM_SKKT_DV;
	TcxGridDBColumn *cxGrid1DBTableView1MESTOUST_REM_SKKT_DV;
	TcxGridDBColumn *cxGrid1DBTableView1REGNUM_REM_SKKT_DV;
	TcxGridDBColumn *cxGrid1DBTableView1CBKGR_REM_SKKT_DV;
	TcxGridDBColumn *cxGrid1DBTableView1CBKCO_REM_SKKT_DV;
	TcxGridDBColumn *cxGrid1DBTableView1NUMCONTRACT_REM_SKKT_DV;
	TcxGridDBColumn *cxGrid1DBTableView1DATECONTRACT_REM_SKKT_DV;
	TcxGridDBColumn *cxGrid1DBTableView1SUMCONTRACT_REM_SKKT_DV;
	TcxGridDBColumn *cxGrid1DBTableView1EKLZ_SERNUM_REM_SKKT_DV;
	TcxGridDBColumn *cxGrid1DBTableView1EKLZ_REGNUM_REM_SKKT_DV;
	TcxGridDBColumn *cxGrid1DBTableView1EKLZ_ACT_REM_SKKT_DV;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_USER;
	TAction *ActionClose;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
        void OpenFormElement();
		void OpenFormNewElement();
		void DeleteElement();

public:		// User declarations
		__fastcall TREM_FormaSpiskaSprKKTDv(TComponent* Owner);


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
        bool Prosmotr;    //только просмотр
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме
		UnicodeString TextMessage;
		UnicodeString TextZayavka;

		IREM_DMSprKKTDv * DM;

        __int64 IdOwner;



        void UpdateForm();
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaSpiskaSprKKTDv *REM_FormaSpiskaSprKKTDv;
//---------------------------------------------------------------------------
#endif
