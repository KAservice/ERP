//---------------------------------------------------------------------------

#ifndef UFormaExportDocH
#define UFormaExportDocH
//---------------------------------------------------------------------------
#include "UDMExportDoc.h"

//-----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxButtonEdit.hpp"
#include "cxCalendar.hpp"
#include "cxCheckBox.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Dialogs.hpp>
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
//---------------------------------------------------------------------------
class TFormaExportDoc : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TcxDateEdit *NachcxDateEdit;
	TLabel *Label4;
	TcxDateEdit *ConcxDateEdit;
	TcxButtonEdit *PatchcxButtonEdit;
	TLabel *Label6;
	TcxCheckBox *PoDatecxCheckBox;
	TSaveDialog *SaveDialog1;
	TcxButton *ExportAllDoccxButton;
	TcxButton *SprcxButton;
	TcxButton *cxButtonClose;
	TLabel *Label7;
	TcxButtonEdit *FileNamecxButtonEdit;
	TLabel *Label8;
	TOpenDialog *OpenDialog1;
	TcxButton *cxButtonImport;
	void __fastcall PatchcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ExportAllDoccxButtonClick(TObject *Sender);
	void __fastcall SprcxButtonClick(TObject *Sender);
	void __fastcall cxButtonCloseClick(TObject *Sender);
	void __fastcall FileNamecxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall cxButtonImportClick(TObject *Sender);
private:	// User declarations



		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму


public:		// User declarations
	__fastcall TFormaExportDoc(TComponent* Owner);


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

	   void UpdateForm(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaExportDoc *FormaExportDoc;
//---------------------------------------------------------------------------
#endif
