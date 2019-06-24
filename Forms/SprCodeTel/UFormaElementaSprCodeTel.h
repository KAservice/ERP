//---------------------------------------------------------------------------

#ifndef UFormaElementaSprCodeTelH
#define UFormaElementaSprCodeTelH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "IFormaSpiskaSprNom.h"
#include "IDMSprCodeTel.h"
#include "IDMFibConnection.h"

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "cxCalc.hpp"
#include "cxDropDownEdit.hpp"
//---------------------------------------------------------------------------
class TFormaElementaSprCodeTel : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label11;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxDBButtonEdit *NameComcxDBButtonEdit;
	TcxDBButtonEdit *NameNomcxDBButtonEdit;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxDBTextEdit *CodeOpercxDBTextEdit;
	TcxDBTextEdit *CodecxDBTextEdit;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBCalcEdit *ProcentComissioncxDBCalcEdit;
	TLabel *Label5;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall NameComcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameNomcxDBButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionOKExecute(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

        IFormaSpiskaSprNom * FormaSpiskaSprNom;

		enum {NO,ViborNom, ViborNomCommission} ViborRekv;

		void __fastcall EndVibor(TObject *Sender);
		void OpenFormSpiskaSprNom(void);
		void OpenFormSpiskaSprNomCommission(void);
public:		// User declarations
		__fastcall TFormaElementaSprCodeTel(TComponent* Owner);

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
		IDMSprCodeTel * DM;



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprCodeTel *FormaElementaSprCodeTel;
//---------------------------------------------------------------------------
#endif
