//---------------------------------------------------------------------------

#ifndef UFormaDialogaReportPoProjectH
#define UFormaDialogaReportPoProjectH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprGrpNom.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprProject.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <Buttons.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <ActnList.hpp>
#include "cxButtonEdit.hpp"
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxGraphics.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxLabel.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaDialogaReportPoProject : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TcxButtonEdit *NameFirmEdit;
	TcxButtonEdit *NameSkladEdit;
	TcxButtonEdit *NameGrpNomEdit;
	TcxButtonEdit *NameNomEdit;
	TcxCheckBox *OnlyCheckBox;
	TcxComboBox *TypeNomComboBox;
	TcxCheckBox *OnlyOperationCheckBox;
	TcxComboBox *OperationComboBox;
	TcxComboBox *TypePriceComboBox;
	TcxCheckBox *DocCheckBox;
	TcxButton *cxButtonCreateReport;
	TcxButton *cxButtonClose;
	TcxCheckBox *cxCheckBoxVisibleOtrOst;
	TcxButtonEdit *NameProjectcxButtonEdit;
	TcxLabel *cxLabel1;
	TAction *ActionClose;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameFirmEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameGrpNomEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameNomEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall DateNachKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall DateConKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall OnlyCheckBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall OnlyOperationCheckBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall DocCheckBoxKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall TypeNomComboBoxPropertiesChange(TObject *Sender);
	void __fastcall OperationComboBoxPropertiesChange(TObject *Sender);
	void __fastcall TypePriceComboBoxPropertiesChange(TObject *Sender);
	void __fastcall cxCheckBoxVisibleOtrOstKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall cxButtonCreateReportClick(TObject *Sender);
	void __fastcall NameProjectcxButtonEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall NameProjectcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
public:		// User declarations
        __fastcall TFormaDialogaReportPoProject(TComponent* Owner);


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

		__int64 IdFirm;
		__int64 IdSkl;
		__int64 IdGrpNom;
		__int64 IdNom;
		__int64 IdProject;


		enum  {ER_NoRekv,ViborFirm,ViborSklad,ViborGrpNom,ViborNom, ViborProject, NO} EditRekvisit;


		IFormaSpiskaSprSklad * SpisokSklad;
        void OpenFormSpiskaSprSklad(void);

        int numRow;
        int numCol;
        int porNumStr;
        int porNumStrGrp;
        double SumRealReport;
        double SebRealReport;
        double ResRealReport;
        double OtrSebRealReport;

		__int64 IdTypePrice;

        double SumOtrSebRealGrp;
        int NumStrGrp;

		IFormaSpiskaSprFirm *SpisokFirm;
		IFormaSpiskaSprGrpNom * SpisokGrpNom;
		IFormaSpiskaSprNom *SpisokNom;

		void OpenFormSpiskaSprNom(void);
        void OpenFormSpiskaSprFirm(void);
        void OpenFormSpiskaSprGrpNom(void);

        AnsiString GetTextQuery(void);

		IFormaSpiskaSprProject *SpisokProject;
		void OpenFormSpiskaSprProject(void);
		void __fastcall EndViborProject(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDialogaReportPoProject *FormaDialogaReportPoProject;
//---------------------------------------------------------------------------
#endif
