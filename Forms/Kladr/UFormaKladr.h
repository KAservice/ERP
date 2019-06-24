//---------------------------------------------------------------------------

#ifndef UFormaKladrH
#define UFormaKladrH
//---------------------------------------------------------------------------
#include "UFormaKladrViborRegion.h"
#include "UFormaKladrViborStreet.h"
#include "IDMFibConnection.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "cxButtonEdit.hpp"
#include "cxButtons.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include <Menus.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFormaKladr : public TForm
{
__published:	// IDE-managed Components
	TcxButtonEdit *RegioncxButtonEdit;
	TcxButtonEdit *RayoncxButtonEdit;
	TcxButtonEdit *GorodcxButtonEdit;
	TcxButtonEdit *NasPunktcxButtonEdit;
	TcxButtonEdit *StreetcxButtonEdit;
	TcxTextEdit *DomcxTextEdit;
	TcxTextEdit *KorpuscxTextEdit;
	TcxTextEdit *KvartcxTextEdit;
	TcxTextEdit *IndexcxTextEdit;
	TcxLabel *cxLabel1;
	TcxLabel *cxLabel2;
	TcxLabel *cxLabel3;
	TcxLabel *cxLabel4;
	TcxLabel *cxLabel5;
	TcxLabel *cxLabel6;
	TcxLabel *cxLabel7;
	TcxLabel *cxLabel8;
	TcxLabel *cxLabel9;
	TcxButton *cxButtonOK;
	TcxButton *cxButtonClose;
	TActionList *ActionList;
	TAction *ActionClose;
	TAction *ActionOK;
	void __fastcall RegioncxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall RayoncxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall GorodcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall NasPunktcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall StreetcxButtonEditPropertiesButtonClick(TObject *Sender,
          int AButtonIndex);
	void __fastcall ActionCloseExecute(TObject *Sender);
	void __fastcall ActionOKExecute(TObject *Sender);
private:	// User declarations
		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

		IkanCallBack * InterfaceCallBackImpl;//интерфейс реализации текущего модуля
											 //для передачи в форму выбора

		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

	TFormaKladrViborRegion *FormaKladrViborRegion;
	void ViborRegion(void);
	void __fastcall EndViborRegion(TObject *Sender);

	void ViborRayon(void);
	void __fastcall EndViborRayon(TObject *Sender);

	void ViborGorod(void);
	void __fastcall EndViborGorod(TObject *Sender);

	void ViborNasPunkt(void);
	void __fastcall EndViborNasPunkt(TObject *Sender);

	TFormaKladrViborStreet *FormaKladrViborStreet;
	void ViborStreet(void);
	void __fastcall EndViborStreet(TObject *Sender);
	bool NoKladr;
public:		// User declarations
	__fastcall TFormaKladr(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

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
		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);

		//Текущий интерфейс
		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме
		IkanCallBack * InterfaceCallBack;  //куда надо послать событие выбора

	AnsiString KladrPatch;
	AnsiString NameRegion;
	AnsiString NameRayon;
	AnsiString NameGorod;
	AnsiString NameNasPunkt;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaKladr *FormaKladr;
//---------------------------------------------------------------------------
#endif
