//---------------------------------------------------------------------------

#ifndef UREM_FormaGurVigrusokH
#define UREM_FormaGurVigrusokH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "UDM.h"
#include "IREM_DMGurVigrusok.h"
#include "IFormaViborPerioda.h"
#include "IREM_FormaSetupOtbor.h"
#include "ISheetEditor.h"
#include "UFormIndicator.h"
#include "IDMTableExtPrintForm.h"
//---------------------------------------------------------------------------
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
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
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxLabel.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
//---------------------------------------------------------------------------
class TREM_FormaGurVigrusok : public TForm
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
        TToolButton *ToolButtonNoCheck;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TToolButton *ToolButtonRefresh;
	TToolButton *ToolButton5;
	TcxGridDBTableView *cxGrid1DBTableView1;
	TcxGridLevel *cxGrid1Level1;
	TcxGrid *cxGrid1;
	TcxGridDBColumn *cxGrid1DBTableView1NAMEKLIENT;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SINFBASE_OBMEN;
	TToolButton *ToolButtonOpenExtModule;
	TPopupMenu *PopupMenuExtModule;
	TToolButton *ToolButton6;
	TToolButton *ToolButtonCopyDoc;
	TToolButton *ToolButtonCreateNaOsn;
	TPanel *Panel5;
	TcxGridDBColumn *cxGrid1DBTableView1POS_REM_GUR_VIGR;
	TcxGridDBColumn *cxGrid1DBTableView1NUM_REM_GUR_VIGR;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_SPRODUCER;
	TcxGridDBColumn *cxGrid1DBTableView1NAME_USER;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ToolButton3Click(TObject *Sender);
        void __fastcall ToolButtonViborPeriodaClick(TObject *Sender);
        void __fastcall ToolButtonOpenDocClick(TObject *Sender);
        void __fastcall ToolButtonOtborClick(TObject *Sender);
        void __fastcall ToolButtonParamOtborClick(TObject *Sender);
	void __fastcall ToolButtonRefreshClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1DblClick(TObject *Sender);
	void __fastcall cxGrid1DBTableView1KeyPress(TObject *Sender, char &Key);

				//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ToolButton6Click(TObject *Sender);


private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

			//внешние формы и скрипты
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);

		enum {NO,ViborPerioda, SetupOtborRekv, ER_GurAllDoc,
				ER_ViborHardware, ER_Zayavka} ViborRekv;
		IFormaViborPerioda *FormaViborPerioda;
		IREM_FormaSetupOtbor * FormaSetupOtbor;

		void OpenFormDoc();
		void OpenFormNewDoc();
		void DeleteDoc(void);




	void DeleteAllDoc(void);




public:		// User declarations
		__fastcall TREM_FormaGurVigrusok(TComponent* Owner);

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

		IREM_DMGurVigrusok * DM;

        __int64 IdDoc;


        TDateTime PosNach;
        TDateTime PosCon;





		__int64 IdKlient;
		UnicodeString NameKlient;
		__int64 IdSklad;
		UnicodeString NameSklad;
        __int64 IdFirm;
		UnicodeString NameFirm;
		UnicodeString   StringTypeDoc;
        UnicodeString NameTypeDoc;


        bool OtborPoKlientu;
        bool OtborPoFirm;
        bool OtborPoSklad;
		bool OtborPoTypeDoc;

		void UpdateForm(void);
		void OpenTable(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaGurVigrusok *REM_FormaGurVigrusok;
//---------------------------------------------------------------------------
#endif
