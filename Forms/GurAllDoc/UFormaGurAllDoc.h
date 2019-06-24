//---------------------------------------------------------------------------

#ifndef UFormaGurAllDocH
#define UFormaGurAllDocH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDMGurAllDoc.h"
#include "ISheetEditor.h"
#include "IFormaViborPerioda.h"
#include "IFormaSetupOtbor.h"
#include "IDMTableExtPrintForm.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
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
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFormaGurAllDoc : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonDelete;
        TToolButton *ToolButton2;
        TToolButton *ToolButtonOpenDvDoc;
        TToolButton *ToolButton3;
        TToolButton *ToolButtonViborPerioda;
        TLabel *LabelInterval;
        TLabel *Label1;
        TToolButton *ToolButtonOpenDoc;
        TToolButton *ToolButtonAllCancelDvReg;
        TToolButton *ToolButtonDvRegDoc;
        TToolButton *ToolButtonReportOtrSpis;
        TToolButton *ToolButtonDelAllDoc;
        TToolButton *ToolButton4;
        TToolButton *ToolButtonParamOtbor;
        TToolButton *ToolButtonOtbor;
        TLabel *StrOtborLabel;
        TToolButton *ToolButtonNoCheck;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TToolButton *ToolButtonRefresh;
	TToolButton *ToolButton5;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1PRDOC;
	TcxGridDBColumn *cxGrid1DBTableView1TDOC;
	TcxGridDBColumn *cxGrid1DBTableView1NUMDOC;
	TcxGridDBColumn *cxGrid1DBTableView1SUMDOC;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEFIRM;
	TcxGridDBColumn *cxGrid1DBTableView1NAMESKLAD;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_USER;
	TcxGridDBColumn *cxGrid1DBTableView1POSDOC;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SPROJECT;
	TToolButton *ToolButtonExtModule;
	TPopupMenu *PopupMenuExtModule;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SINFBASE_OBMEN;
	TcxGridDBColumn *cxGrid1DBTableView1PREFIKS_NUM_GALLDOC;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButtonOpenDvDocClick(TObject *Sender);
        void __fastcall ToolButton3Click(TObject *Sender);
        void __fastcall ToolButtonViborPeriodaClick(TObject *Sender);
        void __fastcall ToolButtonOpenDocClick(TObject *Sender);
        void __fastcall ToolButtonAllCancelDvRegClick(TObject *Sender);
        void __fastcall ToolButtonDvRegDocClick(TObject *Sender);
        void __fastcall ToolButtonDelAllDocClick(TObject *Sender);
        void __fastcall ToolButtonOtborClick(TObject *Sender);
        void __fastcall ToolButtonParamOtborClick(TObject *Sender);
        void __fastcall ToolButtonNoCheckClick(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ToolButtonRefreshClick(TObject *Sender);
	void __fastcall ToolButton5Click(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1PRDOCCustomDrawCell(
          TcxCustomGridTableView *Sender, TcxCanvas *ACanvas,
          TcxGridTableDataCellViewInfo *AViewInfo, bool &ADone);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);


				//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);

private:	// User declarations

	//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		IkanCallBack * InterfaceCallBackImpl;//интерфейс реализации текущего модуля
											 //для передачи в форму выбора

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму


		void __fastcall EndViborPerioda(void);
		void __fastcall EndViborParameterOtbor(void);
		void __fastcall EndCloseDoc(void);


		IFormaViborPerioda *FormaViborPerioda;
		IFormaSetupOtbor * FormaSetupOtbor;

		//печать реестра
		void OpenPrintForm(void);
		void OutputString(ISheetEditor *prForm);
		void OutputZagolovokReport(ISheetEditor *prForm);
        void OutputPodavalReport(ISheetEditor *prForm);
        int numRow;
        int numCol;
        int porNumStr;


	double SumReport;
	enum  {ER_No,ER_Period, ER_Otbor,ER_Doc} EditRekvisit;
public:		// User declarations
		__fastcall TFormaGurAllDoc(TComponent* Owner);

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
		IDMGurAllDoc * DM;

		__int64 IdDoc;



        void OpenFormDoc();
        void DeleteDoc(void);



        TDateTime PosNach;
        TDateTime PosCon;

        void DeleteAllDoc(void);
        void UpdateForm(void);


		__int64 IdKlient;
		UnicodeString NameKlient;
		__int64 IdSklad;
		UnicodeString NameSklad;
        __int64 IdFirm;
		UnicodeString NameFirm;
		UnicodeString   StringTypeDoc;
        UnicodeString NameTypeDoc;

        bool OtborPoKlientu ;
        bool OtborPoFirm;
        bool OtborPoSklad;
        bool OtborPoTypeDoc;

		bool NoCheck;





};
//---------------------------------------------------------------------------
extern PACKAGE TFormaGurAllDoc *FormaGurAllDoc;
//---------------------------------------------------------------------------
#endif
