//---------------------------------------------------------------------------

#ifndef UFormaElementaSprDepartmentH
#define UFormaElementaSprDepartmentH
//---------------------------------------------------------------------------
#include "IDMInterfMainMenuPar.h"
#include "UDM.h"
#include "IDMFibConnection.h"
#include "IkasDMSpr.h"

//----------------------------------------------------------------------------
#include "cxButtons.hpp"
#include "cxCalc.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <ActnList.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
class TFormaElementaSprDepartment : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
	TLabel *LabelHeader;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TcxButton *cxButtonClose;
	TcxButton *cxButtonOK;
	TAction *ActionClose;
	TAction *ActionOK;
	TPanel *Panel5;
	TcxDBTextEdit *cxDBTextEditNAME_SDEPARTMENT;
	TcxDBCalcEdit *cxDBCalcEditNUMOTDKKT_SDEPARTMENT;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
public:		// User declarations
		__fastcall TFormaElementaSprDepartment(TComponent* Owner);

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
	   // IDMInterfMainMenuPar* DM;
	   //	__int64 IdOwner;
	   //	UnicodeString TextHeader;
	  //	bool Vibor;                        //форма открыта для выбора
	   //	int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме
	   // void UpdateForm(void);
	   //	void DeleteElement();




       //IkasForm
	void UpdateForm(void);
	bool Vibor;
	int NumberProcVibor;
	   //IkasFormSpr

	__int64 IdGroupEl1;
	UnicodeString NameGroupEl1;

	__int64 IdGroupEl2;
	UnicodeString NameGroupEl2;

	__int64 IdOwner;
	UnicodeString NameOwner;

	__int64 IdGrp;
	UnicodeString NameGrp;

	__int64 IdEl;
	UnicodeString NameEl;

	bool All;


	IkasDMSpr * DM;





};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprDepartment *FormaElementaSprDepartment;
//---------------------------------------------------------------------------
#endif
