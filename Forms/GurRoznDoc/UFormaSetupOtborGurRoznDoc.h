//---------------------------------------------------------------------------

#ifndef UFormaSetupOtborGurRoznDocH
#define UFormaSetupOtborGurRoznDocH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "IFormaSpiskaSprKlient.h"


//----------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxDropDownEdit.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxButtonEdit.hpp"
#include "cxLookAndFeels.hpp"
#include <ActnList.hpp>

//---------------------------------------------------------------------------
class TFormaSetupOtborGurRoznDoc : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label4;
        TLabel *Label5;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TcxComboBox *TypeDocComboBox;
	TcxButtonEdit *NameKlientEdit;
	TActionList *ActionList;
	TAction *ActionClose;
	TAction *ActionOK;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall TypeDocComboBoxPropertiesChange(TObject *Sender);
	void __fastcall NameKlientEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

	   IFormaSpiskaSprKlient * SpisokKlient;

	   enum  { ER_NoRekv,ViborKlient, NO} EditRekvisit;
public:		// User declarations
		__fastcall TFormaSetupOtborGurRoznDoc(TComponent* Owner);

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






		__int64 IdKlient;
		UnicodeString NameKlient;
		__int64 IdSklad;
		UnicodeString NameSklad;
        __int64 IdFirm;
		UnicodeString NameFirm;
		UnicodeString   StringTypeDoc;
        UnicodeString NameTypeDoc;
		UnicodeString   StringFullTypeDoc;

        bool OtborPoKlient;
        bool OtborPoFirm;
        bool OtborPoSklad;
        bool OtborPoTypeDoc;


};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSetupOtborGurRoznDoc *FormaSetupOtborGurRoznDoc;
//---------------------------------------------------------------------------
#endif
