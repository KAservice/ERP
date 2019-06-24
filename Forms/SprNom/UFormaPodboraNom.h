//---------------------------------------------------------------------------

#ifndef UFormaPodboraNomH
#define UFormaPodboraNomH
//---------------------------------------------------------------------------


#include "IFormaSpiskaSprEd.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxButtonEdit.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalc.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//----------------------------------------------------------------------------
class TFormaPodboraNom : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *NameNomLabel;
        TLabel *LabelKF;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxButtonEdit *NameEdEdit;
	TcxCalcEdit *KolEdit;
	TcxCalcEdit *PriceEdit;
	TcxCalcEdit *SummaEdit;
	TAction *ActionClose;
	TAction *ActionOK;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall NameEdEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NameEdEditKeyPress(TObject *Sender, char &Key);
	void __fastcall KolEditKeyPress(TObject *Sender, char &Key);
	void __fastcall KolEditExit(TObject *Sender);
	void __fastcall PriceEditKeyPress(TObject *Sender, char &Key);
	void __fastcall PriceEditExit(TObject *Sender);
	void __fastcall SummaEditKeyPress(TObject *Sender, char &Key);
	void __fastcall SummaEditExit(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

		IFormaSpiskaSprEd * Ed;
		void  OpenFormSpiskaSprEd(void);
public:		// User declarations
		__fastcall TFormaPodboraNom(TComponent* Owner);

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
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме

        __int64 IdNom;
        double Price;
        double PriceBasEd;
        double Kol;
        double Summa;
        int IdEd;
		UnicodeString NameEd;
		UnicodeString NameNom;
        double KFEd;



        void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaPodboraNom *FormaPodboraNom;
//---------------------------------------------------------------------------
#endif
