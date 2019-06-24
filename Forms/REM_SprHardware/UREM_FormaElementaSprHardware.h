//---------------------------------------------------------------------------

#ifndef UREM_FormaElementaSprHardwareH
#define UREM_FormaElementaSprHardwareH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMSprHardware.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprCountry.h"
#include "IFormaGurAllDoc.h"
#include "IREM_FormaSpiskaSprModel.h"
#include "IREM_FormaSpiskaSprHardwareIsp.h"
#include "IFormaSpiskaSprProducer.h"
#include "IFormaSpiskaSprBrand.h"
#include "IREM_FormaGurZ.h"
#include "IREM_FormaSpiskaSprProducerModel.h"
#include "UDM.h"
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
#include "cxLookAndFeels.hpp"
#include "cxCheckBox.hpp"
//---------------------------------------------------------------------------
class TREM_FormaElementaSprHardware : public TForm
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
	TcxDBTextEdit *NamecxDBTextEdit;
	TLabel *Label2;
	TcxDBButtonEdit *OwnercxDBButtonEdit;
	TcxDBButtonEdit *SuppliercxDBButtonEdit;
	TcxLabel *cxLabel12;
	TcxLabel *cxLabel13;
	TPanel *Panel1;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel5;
	TcxLabel *cxLabel6;
	TcxLabel *cxLabel7;
	TcxDBButtonEdit *NameModelcxDBButtonEdit;
	TcxDBDateEdit *WarrantycxDBDateEdit;
	TcxDBDateEdit *SalecxDBDateEdit;
	TcxDBTextEdit *SerNumbercxDBTextEdit;
	TcxDBTextEdit *NameVladcxDBTextEdit;
	TAction *ActionOK;
	TcxDBButtonEdit *DocPostcxDBButtonEdit;
	TcxDBButtonEdit *DocSalecxDBButtonEdit;
	TcxDBTextEdit *CodecxDBTextEdit;
	TcxDBTextEdit *SerNum2cxDBTextEdit;
	TcxDBTextEdit *SerNumStrcxDBTextEdit;
	TcxLabel *cxLabel8;
	TcxLabel *cxLabel9;
	TcxDBTextEdit *PrichinacxDBTextEdit;
	TcxDBTextEdit *PrimcxDBTextEdit;
	TcxDBCheckBox *NecondcxDBCheckBox;
	TcxDBCalcEdit *SrokWarrantycxDBCalcEdit;
	TcxDBCalcEdit *PricecxDBCalcEdit;
	TcxLabel *cxLabel10;
	TcxLabel *cxLabel11;
	TcxLabel *cxLabel14;
	TcxLabel *cxLabel15;
	TcxDBCheckBox *FlRemontcxDBCheckBox;
	TcxDBCheckBox *FlFictRemontcxDBCheckBox;
	TcxDBImageComboBox *TypeElementacxDBImageComboBox;
	TcxDBCheckBox *flActcxDBCheckBox;
	TcxDBCheckBox *flUtilizcxDBCheckBox;
	TcxDBButtonEdit *ProducercxDBButtonEdit;
	TcxDBButtonEdit *BrandcxDBButtonEdit;
	TcxDBButtonEdit *ZayavkacxDBButtonEdit;
	TcxDBButtonEdit *ModelProducercxDBButtonEdit;
	TcxDBDateEdit *PostupilocxDBDateEdit;
	TcxDBDateEdit *UtilizirovanocxDBDateEdit;
	TcxDBDateEdit *HranitDocxDBDateEdit;
	TcxDBLabel *ModelZcxDBLabel;
	TcxDBLabel *PosZcxDBLabel;
	TcxDBLabel *PrefikscxDBLabel;
	TcxDBLabel *NumZcxDBLabel;
	TcxDBLabel *SerNumcxDBLabel;
	TcxButton *cxButtonIspZapchasti;
	TcxDBLabel *IDcxDBLabel;
	TcxLabel *cxLabel16;
	TcxLabel *cxLabel17;
	TcxLabel *cxLabel18;
	TcxLabel *cxLabel19;
	TcxLabel *cxLabel20;
	TcxLabel *cxLabel21;
	TcxLabel *cxLabel22;
	TcxLabel *cxLabel23;
	TcxLabel *cxLabel24;
	TcxDBTextEdit *cxDBTextEditSERNUM3_REM_SHARDWARE;
	TcxLabel *cxLabel25;
	TcxDBTextEdit *cxDBTextEditSERNUM4_REM_SHARDWARE;
	TcxLabel *cxLabel26;
	TcxDBTextEdit *cxDBTextEditNUMBAT_REM_SHARDWARE;
	TcxLabel *cxLabel27;
	TcxDBTextEdit *cxDBTextEditNUMGARTALON_REM_SHARDWARE;
	TcxLabel *cxLabel28;
	TcxDBTextEdit *cxDBTextEditSWCODE_REM_SHARDWARE;
	TcxLabel *cxLabel29;
	TcxDBTextEdit *cxDBTextEditHWCODE_REM_SHARDWARE;
	TcxLabel *cxLabel30;
	TcxDBTextEdit *cxDBTextEditVERPO_REM_SHARDWARE;
	TcxLabel *cxLabel31;
	TcxDBTextEdit *cxDBTextEditPARTNUM_REM_SHARDWARE;
	TcxLabel *cxLabel32;
	TcxDBTextEdit *cxDBTextEditMTM_REM_SHARDWARE;
	TcxLabel *cxLabel33;
	TcxDBTextEdit *cxDBTextEditFRU_REM_SHARDWARE;
	TcxLabel *cxLabel34;
	TcxDBTextEdit *cxDBTextEditNAME_ENG_REM_SHARDWARE;
	TcxDBTextEdit *cxDBTextEditCRU_REM_SHARDWARE;
	TcxLabel *cxLabel35;
	TcxDBTextEdit *cxDBTextEditARTIKUL_REM_SHARDWARE;
	TcxLabel *cxLabel36;
	TcxLabel *cxLabel37;
	TcxDBCheckBox *cxDBCheckBoxFL_OTCH_PROIZV_REM_SHARDWARE;
	TcxDBCheckBox *cxDBCheckBoxFL_NO_RAZBOR_REM_SHARDWARE;
	TcxButton *cxButtonOpenZ;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionCloseElementExecute(TObject *Sender);
	void __fastcall SuppliercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionSaveElementExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall DocPostcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall DocSalecxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NameModelcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormDeactivate(TObject *Sender);
	void __fastcall BrandcxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall OwnercxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall ProducercxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall ZayavkacxDBButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall ModelProducercxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonIspZapchastiClick(TObject *Sender);
	void __fastcall cxButtonOpenZClick(TObject *Sender);










private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

		//редактирование Поставщика и производителя
		IFormaSpiskaSprKlient * FormaSpiskaSprKlient;
		void ViborSupplier(void);
		void ViborOwner(void);
		void __fastcall EndViborSupplier(void);
		void __fastcall EndViborOwner(void);


        IFormaGurAllDoc * FormaGurAllDoc;
		void ViborDocPost(void);
		void ViborDocSale(void);
		void __fastcall EndViborDocPost(void);
		void __fastcall EndViborDocSale(void);

		enum{ER_NoRekv,ER_ViborSupplier,ER_ViborOwner,
						ER_ViborDocPost,ER_ViborDocSale,
						ER_ViborModel,
						ER_ViborHardwareIsp,
						ER_ViborBrand,
						ER_ViborProducer,
						ER_ViborZ,
						ER_ViborProducerModel} EditRekvisit;


		IREM_FormaSpiskaSprModel * FormaSpiskaSprModel;
		void ViborModel(void);
		void EndViborModel(void);

		IREM_FormaSpiskaSprProducerModel * FormaSpiskaSprProducerModel;
		void ViborProducerModel(void);
		void EndViborProducerModel(void);

		IFormaSpiskaSprBrand * FormaSpiskaSprBrand;
		void ViborBrand(void);
		void EndViborBrand(void);

		IFormaSpiskaSprProducer * FormaSpiskaSprProducer;
		void ViborProducer(void);
		void EndViborProducer(void);

		IREM_FormaGurZ * FormaGurZ;
		void ViborZ(void);
		void EndViborZ(void);

		void EndViborViborHardwareIsp(void);
		void ViborHardwareIsp(void);

		IREM_FormaSpiskaSprHardwareIsp * FormaSpiskaSprHardwareIsp;

public:		// User declarations
		__fastcall TREM_FormaElementaSprHardware(TComponent* Owner);

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

		//IAsyncExternalEvent
		void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);

		//Текущий интерфейс
        bool Prosmotr;    //только просмотр
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме

		IREM_DMSprHardware * DM;

        void UpdateForm(void); 
        bool SaveElement;


};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaElementaSprHardware *REM_FormaElementaSprHardware;
//---------------------------------------------------------------------------
#endif
