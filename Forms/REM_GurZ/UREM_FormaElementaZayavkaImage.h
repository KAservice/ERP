//---------------------------------------------------------------------------

#ifndef UREM_FormaElementaZayavkaImageH
#define UREM_FormaElementaZayavkaImageH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IREM_DMZayavkaImage.h"

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <ActnList.hpp>
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDBEdit.hpp"
#include "cxEdit.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxLabel.hpp"
#include "cxButtonEdit.hpp"
#include "cxCheckBox.hpp"
#include "cxDropDownEdit.hpp"
#include "cxGraphics.hpp"
#include "cxImageComboBox.hpp"
#include "cxMaskEdit.hpp"
#include <Dialogs.hpp>
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
#include "cxDBLookupComboBox.hpp"
#include "cxGroupBox.hpp"
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include "cxRadioGroup.hpp"
#include "cxLookAndFeels.hpp"
#include "cxImage.hpp"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TREM_FormaElementaZayavkaImage : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList;
	TAction *ActionOpenHelp;
	TOpenDialog *OpenDialog1;
	TAction *ActionClose;
	TAction *ActionOK;
	TcxDBImage *ImagecxDBImage;
	TPanel *Panel1;
	TcxDBTextEdit *NamecxDBTextEdit;
	TcxDBCheckBox *ShowUsercxDBCheckBox;
	TLabel *Label1;
	TPanel *Panel2;
	TcxButton *cxButtonFileInBlob;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall NamecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall CodecxDBTextEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
	void __fastcall cxButtonFileInBlobClick(TObject *Sender);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
public:		// User declarations
        __fastcall TREM_FormaElementaZayavkaImage(TComponent* Owner);
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




		IREM_DMZayavkaImage* DM;


		void UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TREM_FormaElementaZayavkaImage *REM_FormaElementaZayavkaImage;
//---------------------------------------------------------------------------
#endif
