//---------------------------------------------------------------------------

#ifndef UHLP_FormaElementaSprImageH
#define UHLP_FormaElementaSprImageH
//---------------------------------------------------------------------------
#include "IHLP_DMSprImage.h"
#include "UDM.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxButtonEdit.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "cxCalc.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxImageComboBox.hpp"
#include "cxLookAndFeels.hpp"
#include "cxDBRichEdit.hpp"
#include "cxMemo.hpp"
#include "cxRichEdit.hpp"
#include "cxImage.hpp"
#include "cxSpinEdit.hpp"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class THLP_FormaElementaSprImage : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBImage *ImagecxDBImage;
	TPanel *Panel1;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TPanel *Panel2;
	TLabel *NameGrpLabel;
	TLabel *Label1;
	TcxDBTextEdit *NamecxDBTextEdit;
	TLabel *Label2;
	TcxDBTextEdit *GuidcxDBTextEdit;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations

	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

	enum  {ER_NoRekv, ER_ViborVidImage} ER_Rekvisit;


public:		// User declarations
		__fastcall THLP_FormaElementaSprImage(TComponent* Owner);

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

         void __fastcall ReadShtrihCodEvent(int number, UnicodeString sh);
		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);

		//Текущий интерфейс
		IHLP_DMSprImage * DM;
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме

	   void UpdateForm(void);

		__int64 IdGrpPage;
		UnicodeString NameGrp;
};
//---------------------------------------------------------------------------
extern PACKAGE THLP_FormaElementaSprImage *HLP_FormaElementaSprImage;
//---------------------------------------------------------------------------
#endif
