//---------------------------------------------------------------------------

#ifndef UFormaReportDiscountDocCheckH
#define UFormaReportDiscountDocCheckH
//---------------------------------------------------------------------------
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprGrpNom.h"
#include "IFormaSpiskaSprNom.h"
#include "USheetEditor.h"
#include "UDM.h"
#include "IFormaSpiskaSprKlient.h"
#include "IDMFibConnection.h"
//----------------------------------------------------------------------------
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
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtonEdit.hpp"
#include "cxCalendar.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaReportDiscountDocCheck : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonCreate;
	TcxButton *cxButtonClose;
	TcxCheckBox *DocCheckBox;
	TcxCheckBox *OnlyCheckBox;
	TcxComboBox *TypeNomComboBox;
	TcxButtonEdit *NameNomEdit;
	TcxButtonEdit *NameGrpNomEdit;
	TcxButtonEdit *NameSkladEdit;
	TcxButtonEdit *NameFirmEdit;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TcxButtonEdit *NameKlientcxButtonEdit;
	TcxLabel *cxLabel1;
	TcxButton *cxButtonCreateReportGrid;
	TLabel *Label5;
	TAction *ActionClose;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall cxButtonCreateClick(TObject *Sender);
	void __fastcall NameNomEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameGrpNomEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameKlientcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonCreateReportGridClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations

bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

public:		// User declarations
		__fastcall TFormaReportDiscountDocCheck(TComponent* Owner);

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
		__int64 IdKlient;


		enum  {ER_NoRekv,ViborFirm,ViborSklad,ViborGrpNom,ViborNom, ViborKlient, NO} EditRekvisit;

		IFormaSpiskaSprSklad * SpisokSklad;
        void OpenFormSpiskaSprSklad(void);

		IFormaSpiskaSprFirm *SpisokFirm;
		IFormaSpiskaSprGrpNom * SpisokGrpNom;
		IFormaSpiskaSprNom *SpisokNom;

		void OpenFormSpiskaSprNom(void);
        void OpenFormSpiskaSprFirm(void);
		void OpenFormSpiskaSprGrpNom(void);



		void OpenFormSpiskaSprKlient(void);
		IFormaSpiskaSprKlient *SpisokKlient;
		void __fastcall EndViborKlient(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportDiscountDocCheck *FormaReportDiscountDocCheck;
//---------------------------------------------------------------------------
#endif
