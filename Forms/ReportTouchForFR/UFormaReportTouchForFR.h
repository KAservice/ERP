//---------------------------------------------------------------------------

#ifndef UFormaReportTouchForFRH
#define UFormaReportTouchForFRH
//---------------------------------------------------------------------------
#include "IMainInterface.h"
#include "IDMFibConnection.h"
#include "IFiskReg.h"

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxCalendar.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFormaReportTouchForFR : public TForm
{
__published:	// IDE-managed Components
	TcxDateEdit *PosNachcxDateEdit;
	TcxDateEdit *PosConcxDateEdit;
	TBitBtn *BitBtnReport;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *ButtonClose;
	void __fastcall BitBtnReportClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ButtonCloseClick(TObject *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
	IFiskReg  *glFR;


public:		// User declarations
	__fastcall TFormaReportTouchForFR(TComponent* Owner);

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


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaReportTouchForFR *FormaReportTouchForFR;
//---------------------------------------------------------------------------
#endif
