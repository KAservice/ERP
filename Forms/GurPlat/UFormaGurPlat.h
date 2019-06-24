//---------------------------------------------------------------------------

#ifndef UFormaGurPlatH
#define UFormaGurPlatH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDMGurPlat.h"
#include "IFormaViborPerioda.h"
#include "IFormaElementaGurPlat.h"
#include "IFormaInputText.h"

//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <DBCtrls.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
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
#include <ActnList.hpp>
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaGurPlat : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonViborPerioda;
        TLabel *LabelInterval;
        TLabel *Label1;
        TToolButton *ToolButtonAdd;
        TToolButton *ToolButtonEdit;
        TToolButton *ToolButtonDelete;
        TToolButton *ToolButton2;
        TToolButton *ToolButtonCreateFile;
        TLabel *KolStrLabel;
        TLabel *SumNoOutPlatLabel;
        TLabel *SumOutPlatLabel;
        TLabel *SumAllPlatLabel;
        TLabel *KolOutLabel;
        TLabel *KolNoOutLabel;
        TToolButton *ToolButton3;
        TDBText *NameKlientDBText;
	TToolButton *ToolButtonRefresh;
	TcxButton *cxButtonClear;
	TcxButton *cxButtonClose;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1CODE_GURNALPLAT;
	TcxGridDBColumn *cxGrid1DBTableView1NUMTEL_GURNALPLAT;
	TcxGridDBColumn *cxGrid1DBTableView1NUMKV_GURNALPLAT;
	TcxGridDBColumn *cxGrid1DBTableView1POS_GURNALPLAT;
	TcxGridDBColumn *cxGrid1DBTableView1SUM_GURNALPLAT;
	TcxGridDBColumn *cxGrid1DBTableView1OUT_GURNALPLAT;
	TcxGridDBColumn *cxGrid1DBTableView1CODOPER_GURNALPLAT;
	TcxGridDBColumn *cxGrid1DBTableView1SUMKL_GURNALPLAT;
	TcxGridDBColumn *cxGrid1DBTableView1PROCENT_COMMISSION_GURNALPLAT;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_USER;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TActionList *ActionList1;
	TAction *OpenHelp;
	TAction *ActionClose;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonViborPeriodaClick(TObject *Sender);
        void __fastcall ToolButtonEditClick(TObject *Sender);
        void __fastcall ToolButtonAddClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButtonCreateFileClick(TObject *Sender);
        void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall ToolButtonRefreshClick(TObject *Sender);
	void __fastcall cxButtonClearClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1OUT_GURNALPLATCustomDrawCell(
          TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
          TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall OpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
       	enum {NO,ViborPerioda, SetupOtborRekv, ElementRekv, CodMegafonRekv} ViborRekv;
		IFormaViborPerioda *FormaViborPerioda;
		IFormaInputText * FormaInputText;


		void Summa(void);


		void OpenFormElement(void);
		void OpenFormNewElement(void);
		void DeleteElement(void);
		IFormaElementaGurPlat * FormaElementaGurPlat;

		void CreateFileExportMegafon(AnsiString code);
		void CreateFileExportCiberplat(void);
		AnsiString FloatToStringComma(double value);

public:		// User declarations
		__fastcall TFormaGurPlat(TComponent* Owner);

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


		IDMGurPlat * DM;
        bool Vibor;
        int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме
        __int64 IdPlat;



        TDateTime PosNach;
        TDateTime PosCon;

        bool NoOnlyOut;
		AnsiString CodeTel;


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaGurPlat *FormaGurPlat;
//---------------------------------------------------------------------------
#endif
