//---------------------------------------------------------------------------

#ifndef UREM_FormaElementaSprKKTH
#define UREM_FormaElementaSprKKTH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprCountry.h"
#include "IREM_DMSprKKT.h"
#include "IFormaSpiskaSprKlient.h"
#include "IREM_FormaSpiskaSprModel.h"
#include "IDMSprEd.h"
#include "IDMSprPrice.h"
#include "IFormaSpiskaSprOKEI.h"
//----------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include "cxCalc.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxLabel.hpp"
#include "cxPC.hpp"
#include "cxButtonEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxGraphics.hpp"
#include "cxButtons.hpp"
#include "cxMemo.hpp"
#include "cxImageComboBox.hpp"
#include "cxDBLookupComboBox.hpp"
#include "cxDBLookupEdit.hpp"
#include "cxLookupEdit.hpp"
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
#include "cxDBLabel.hpp"
#include "cxCalendar.hpp"
#include "cxSpinEdit.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TREM_FormaElementaSprKKT : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TAction *ActionSaveElement;
	TcxButton *cxButtonSave;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TAction *ActionCloseElement;
	TPanel *Panel1;
	TcxPageControl *cxPageControl1;
	TcxTabSheet *cxTabSheet1;
	TcxTabSheet *cxTabSheet2;
	TLabel *Label2;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel3;
	TcxDBButtonEdit *NameModelcxDBButtonEdit;
	TcxDBTextEdit *SerNumbercxDBTextEdit;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxLabel *cxLabel2;
	TcxGroupBox *cxGroupBox1;
	TcxGroupBox *cxGroupBox2;
	TcxGroupBox *cxGroupBox3;
	TcxDBTextEdit *SvkGRcxDBTextEdit;
	TcxDBTextEdit *SvkSOcxDBTextEdit;
	TcxDBTextEdit *NumContractcxDBTextEdit;
	TcxDBDateEdit *DateContractcxDBDateEdit;
	TcxDBCalcEdit *SumContractcxDBCalcEdit;
	TcxDBTextEdit *EklzSerNumcxDBTextEdit;
	TcxDBTextEdit *EklzRegNumcxDBTextEdit;
	TcxDBDateEdit *EklzActcxDBDateEdit;
	TcxDBTextEdit *RegNumcxDBTextEdit;
	TcxDBDateEdit *ReleasecxDBDateEdit;
	TcxDBDateEdit *VvodcxDBDateEdit;
	TcxDBTextEdit *PasNumVercxDBTextEdit;
	TcxDBTextEdit *PasNumPascxDBTextEdit;
	TcxGroupBox *cxGroupBox4;
	TcxGroupBox *cxGroupBox5;
	TcxGroupBox *cxGroupBox6;
	TcxDBSpinEdit *PasNumPUcxDBSpinEdit;
	TcxDBSpinEdit *PasNumSPcxDBSpinEdit;
	TcxDBSpinEdit *PasNumSPPOcxDBSpinEdit;
	TcxDBSpinEdit *PasNumFPcxDBSpinEdit;
	TcxDBSpinEdit *PasNumFPPOcxDBSpinEdit;
	TcxDBTextEdit *PasPrimcxDBTextEdit;
	TcxDBTextEdit *PasDorcxDBTextEdit;
	TcxGroupBox *cxGroupBox7;
	TcxDBSpinEdit *PasNumDocxDBSpinEdit;
	TcxDBSpinEdit *PasNumDoPocxDBSpinEdit;
	TcxGroupBox *cxGroupBox8;
	TcxDBSpinEdit *PasPppcxDBSpinEdit;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel5;
	TcxLabel *cxLabel6;
	TcxLabel *cxLabel7;
	TcxLabel *cxLabel8;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel10;
	TcxLabel *cxLabel11;
	TcxLabel *cxLabel12;
	TcxLabel *cxLabel13;
	TcxLabel *cxLabel14;
	TcxLabel *cxLabel15;
	TcxLabel *cxLabel16;
	TcxLabel *cxLabel17;
	TcxLabel *cxLabel18;
	TcxLabel *cxLabel19;
	TcxLabel *cxLabel20;
	TcxLabel *cxLabel21;
	TcxLabel *cxLabel22;
	TcxLabel *cxLabel23;
	TcxLabel *cxLabel24;
	TcxLabel *cxLabel25;
	TcxLabel *cxLabel26;
	TcxDBMemo *PrimcxDBMemo;
	TLabel *Label1;
	TAction *ActionOK;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseElementExecute(TObject *Sender);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameModelcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionSaveElementExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму


		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;
		void ViborOwner(void);
		void __fastcall EndViborOwner(void);

		IREM_FormaSpiskaSprModel * REM_FormaSpiskaSprModel;
		void ViborModel(void);
		void __fastcall EndViborModel(void);

		enum {ER_NoRekv, ER_Klient,ER_Model,ER_No} EditRekvisit;
public:		// User declarations
		__fastcall TREM_FormaElementaSprKKT(TComponent* Owner);

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


		IREM_DMSprKKT * DM;

        void UpdateForm(void); 


};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaElementaSprKKT *REM_FormaElementaSprKKT;
//---------------------------------------------------------------------------
#endif
