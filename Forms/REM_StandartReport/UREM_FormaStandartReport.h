//---------------------------------------------------------------------------

#ifndef UREM_FormaStandartReportH
#define UREM_FormaStandartReportH
//---------------------------------------------------------------------------

#include "IDMFibConnection.h"
#include "IFormaRunExternalModule.h"
#include "IDMTableExtPrintForm.h"
#include "UDM.h"
#include "IFormaSpiskaSprSklad.h"
#include "IFormaSpiskaSprFirm.h"
#include "IFormaSpiskaSprGrpNom.h"
#include "IFormaSpiskaSprNom.h"
#include "IFormaSpiskaSprUser.h"
#include "IFormaSpiskaSprTypePrice.h"
#include "IFormaSpiskaSprTypeNachisl.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprProducer.h"
#include "IFormaSpiskaSprProject.h"
#include "IFormaSpiskaSprBusinessOper.h"
#include "IFormaGurAllDoc.h"

#include "IFormaSpiskaSprBrand.h"
#include "IREM_FormaSpiskaSprModel.h"
#include "IREM_FormaSpiskaSprProducerModel.h"
#include "IREM_FormaSpiskaSprTypUslov.h"
#include "IREM_FormaSpiskaSprTypeRemont.h"
#include "IFormaSpiskaTableExtPrintForm.h"
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
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxButtonEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxCalendar.hpp"
#include "cxLookAndFeels.hpp"
#include "cxDBEdit.hpp"
#include "cxLabel.hpp"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TREM_FormaStandartReport : public TForm
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
	TcxButton *cxButtonClose;
	TcxButtonEdit *NameNomEdit;
	TcxButtonEdit *NameGrpNomEdit;
	TcxButtonEdit *NameSkladEdit;
	TcxButtonEdit *NameFirmEdit;
	TcxDateEdit *DateNach;
	TcxDateEdit *DateCon;
	TcxCheckBox *DocDvcxCheckBox;
	TcxButton *cxButton1;
	TPopupMenu *PopupMenuExtModule;
	TAction *ActionClose;
	TcxButtonEdit *NameUsercxButtonEdit;
	TLabel *Label5;
	TcxButtonEdit *NameTypePricecxButtonEdit;
	TcxButtonEdit *NameTypeNachislcxButtonEdit;
	TcxButtonEdit *NameKlientcxButtonEdit;
	TcxButtonEdit *NameProducercxButtonEdit;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TcxLabel *cxLabel9;
	TcxLabel *cxLabel4;
	TcxButtonEdit *NameBusinessOpercxButtonEdit;
	TcxButtonEdit *NameProjectcxButtonEdit;
	TcxButton *cxButton2;
	TcxButton *cxButtonZapolnitOtchetPost;
	TcxButton *cxButtonCreateAktSpisNom;
	TcxButton *cxButtonProvGarTalon;
	TcxButton *cxButtonProvAktPoTalonam;
	TOpenDialog *OpenDialog1;
	TLabel *Label16;
	TLabel *Label14;
	TcxLabel *cxLabel1;
	TcxButtonEdit *NameBrandcxButtonEdit;
	TcxButtonEdit *NameModelcxButtonEdit;
	TcxButtonEdit *NameProducerModelcxButtonEdit;
	TcxButtonEdit *NameTypUselcxButtonEdit;
	TLabel *Label15;
	TcxButtonEdit *NameTypeRemontcxButtonEdit;
	TLabel *Label17;
	TcxButton *cxButtonViborExtPrintForm;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall NameNomEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameGrpNomEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameSkladEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameFirmEditPropertiesButtonClick(TObject *Sender,
		  int AButtonIndex);

 		  		//внешние формы и скрипты
		void __fastcall PopupMenuExtModuleClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall NameUsercxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NameTypePricecxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameTypeNachislcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameKlientcxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NameProducercxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NameBusinessOpercxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameProjectcxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall cxButton2Click(TObject *Sender);
	void __fastcall cxButtonZapolnitOtchetPostClick(TObject *Sender);
	void __fastcall cxButtonCreateAktSpisNomClick(TObject *Sender);
	void __fastcall cxButtonProvGarTalonClick(TObject *Sender);
	void __fastcall cxButtonProvAktPoTalonamClick(TObject *Sender);
	void __fastcall NameBrandcxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NameModelcxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NameProducerModelcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameTypUselcxButtonEditPropertiesButtonClick(TObject *Sender, int AButtonIndex);
	void __fastcall NameTypeRemontcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonViborExtPrintFormClick(TObject *Sender);







				  
private:	// User declarations

    bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	IDMTableExtPrintForm * DMTableExtPrintForm;
	void RunExternalModule(__int64 id_module, int type_module);



	IFormaGurAllDoc * FormaGurAllDoc;
		void ViborDocReal(void);
		void EndViborDocReal(void);

		void ViborDocOtchetPost(void);
		void EndViborDocOtchetPost(void);


		IREM_FormaSpiskaSprProducerModel * REM_FormaSpiskaSprProducerModel;
		void EventEndEditProducerModel(void);
		void ViborProducerModel(void);

		IREM_FormaSpiskaSprModel * REM_FormaSpiskaSprModel;
		void EventEndEditModel(void);
		void ViborModel(void);

		IREM_FormaSpiskaSprTypUslov * REM_FormaSpiskaSprTypUslov;
		void EventEndEditTypUslov(void);
		void ViborTypUsla(void);

		IFormaSpiskaSprBrand * FormaSpiskaSprBrand;
		void EventEndEditBrand(void);
		void ViborBrand(void);

		IREM_FormaSpiskaSprTypeRemont * REM_FormaSpiskaSprTypeRemont;
		void EventEndEditTypeRemont(void);
		void ViborTypeRemont(void);

		IFormaSpiskaTableExtPrintForm * FormaSpiskaTableExtPrintForm;
		void EventEndViborExtPrintForm(void);
		void ViborExtPrintForm(void);

public:		// User declarations
		__fastcall TREM_FormaStandartReport(TComponent* Owner);

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
		__int64 IdUser;
		__int64 IdTypePrice;
		__int64 IdTypeNachisl;
		__int64 IdKlient;
		__int64 IdProducer;
		__int64 IdBusinessOper;
		__int64 IdProject;

		__int64 IdProducerModel;
		__int64 IdModel;
		__int64 IdTypUsla;
		__int64 IdBrand;

		__int64 IdTypeRemont;

		void __fastcall EndEdit(TObject *Sender);

		enum  {ER_NoRekv,ViborFirm,ViborSklad,ViborGrpNom,ViborNom,ViborUser,
					ViborTypePrice,ViborTypeNachisl,
					ViborKlient,ViborProducer,ER_BusinessOper, ER_Project,
					ER_ViborDocReal,
					ER_ViborOtchetPost,
					ER_ViborModel,
					ER_ViborProducerModel,
					ER_ViborTypUsla,
					ER_ViborBrand,
					ER_ViborTypeRemont,
					ER_ViborExtPrintForm,
					 NO} EditRekvisit;


		IFormaSpiskaSprSklad * SpisokSklad;
		void OpenFormSpiskaSprSklad(void);


		IFormaSpiskaSprFirm *SpisokFirm;
		IFormaSpiskaSprGrpNom * SpisokGrpNom;
		IFormaSpiskaSprNom *SpisokNom;

		void OpenFormSpiskaSprNom(void);
		void OpenFormSpiskaSprFirm(void);
		void OpenFormSpiskaSprGrpNom(void);

		IFormaSpiskaSprUser * SpisokUser;
		void OpenFormSpiskaSprUser(void);

		IFormaSpiskaSprTypePrice * SpisokTypePrice;
		void OpenFormSpiskaSprTypePrice(void);

		IFormaSpiskaSprTypeNachisl * SpisokTypeNachisl;
		void OpenFormSpiskaSprTypeNachisl(void);

		IFormaSpiskaSprKlient * SpisokKlient;
		void OpenFormSpiskaSprKlient(void);

		IFormaSpiskaSprProducer * SpisokProducer;
		void OpenFormSpiskaSprProducer(void);


		IFormaSpiskaSprBusinessOper *SpisokBusinessOper;
	void OpenFormSpiskaSprBusinessOper(void);
	void EndViborBusinessOper(void);

	IFormaSpiskaSprProject *SpisokProject;
	void OpenFormSpiskaSprProject(void);
	void EndViborProject(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaStandartReport *REM_FormaStandartReport;
//---------------------------------------------------------------------------
#endif
