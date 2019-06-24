//---------------------------------------------------------------------------

#ifndef UFormaElementaGurPlatH
#define UFormaElementaGurPlatH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IDMGurPlat.h"
#include "IFormaSpiskaSprKlient.h"
#include "IFormaSpiskaSprCodeTel.h"

//-----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <ComCtrls.hpp>
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxCalc.hpp"
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxCalendar.hpp"
#include "cxLabel.hpp"
#include <ActnList.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxDBLabel.hpp"
//---------------------------------------------------------------------------
class TFormaElementaGurPlat : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label8;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBCheckBox *OutcxDBCheckBox;
	TcxDBButtonEdit *NameKlientcxDBButtonEdit;
	TcxDBButtonEdit *NameUsercxDBButtonEdit;
	TcxDBCalcEdit *SummKlientcxDBCalcEdit;
	TcxDBCalcEdit *ProcentcxDBCalcEdit;
	TcxDBCalcEdit *SumcxDBCalcEdit;
	TcxDBTextEdit *NumTelcxDBTextEdit;
	TcxDBTextEdit *CodeTelcxDBTextEdit;
	TcxDBTextEdit *NumKvcxDBTextEdit;
	TcxDBTextEdit *CodeOpercxDBTextEdit;
	TcxDBDateEdit *PoscxDBDateEdit;
	TcxLabel *cxLabel1;
	TActionList *ActionList1;
	TAction *OpenHelp;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBButtonEdit *NameCodeTelcxDBButtonEdit;
	TLabel *Label9;
	TcxDBLabel *CodeOperatorcxDBLabel;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall NameKlientcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall OpenHelpExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall NameCodeTelcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
private:	// User declarations


		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму


		IFormaSpiskaSprKlient * SpisokKlient;
		 void OpenFormSpiskaSprKlient(void);

		enum  {ER_NoRekv,ViborKlient, ViborCodeTel, NO} EditRekvisit;


		IFormaSpiskaSprCodeTel * SpisokCodeTel;
		 void OpenFormSpiskaSprCodeTel(void);

public:		// User declarations
		__fastcall TFormaElementaGurPlat(TComponent* Owner);

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



        void UpdateForm(void);
        IDMGurPlat * DM;


		bool Prosmotr;    //только просмотр
		bool Vibor;       //для выбора
        int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaGurPlat *FormaElementaGurPlat;
//---------------------------------------------------------------------------
#endif
