//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprEdTouchH
#define UFormaSpiskaSprEdTouchH
//---------------------------------------------------------------------------
#include "UDM.h"

#include "IDMFibConnection.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
//---------------------------------------------------------------------------
class TFormaSpiskaSprEdTouch : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BitBtnClose;
        TPanel *Panel2;
        TBitBtn *el9;
        TBitBtn *el8;
        TBitBtn *el7;
        TBitBtn *el6;
        TBitBtn *el5;
        TBitBtn *el4;
        TBitBtn *el3;
        TBitBtn *el2;
        TBitBtn *el1;
        TLabel *LabelNom;
        TBitBtn *b1;
        TBitBtn *b2;
        TBitBtn *b3;
        TBitBtn *b4;
        TBitBtn *b5;
        TBitBtn *b6;
        TBitBtn *b7;
        TBitBtn *b8;
        TBitBtn *b9;
        TBitBtn *b10;
        TLabel *LabelKol;
        TLabel *p1;
        TLabel *p2;
        TLabel *p3;
        TLabel *p4;
        TLabel *p5;
        TLabel *p6;
        TLabel *p7;
        TLabel *p8;
        TLabel *p9;
        TLabel *OstatokLabel;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *El;
	TFIBBCDField *ElKFED;
	TFIBIntegerField *ElTSHED;
	TFIBSmallIntField *ElNEISPED;
	TFIBBCDField *ElZNACH_PRICE;
	TFIBBCDField *ElIDED;
	TFIBBCDField *ElIDNOMED;
	TFIBBCDField *ElIDOKEIED;
	TFIBWideStringField *ElNAMEED;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BitBtnCloseClick(TObject *Sender);
        void __fastcall el1Click(TObject *Sender);
        void __fastcall el2Click(TObject *Sender);
        void __fastcall el3Click(TObject *Sender);
        void __fastcall el4Click(TObject *Sender);
        void __fastcall el5Click(TObject *Sender);
        void __fastcall el6Click(TObject *Sender);
        void __fastcall el7Click(TObject *Sender);
        void __fastcall el8Click(TObject *Sender);
        void __fastcall el9Click(TObject *Sender);
        void __fastcall b1Click(TObject *Sender);
        void __fastcall b2Click(TObject *Sender);
        void __fastcall b3Click(TObject *Sender);
        void __fastcall b4Click(TObject *Sender);
        void __fastcall b5Click(TObject *Sender);
        void __fastcall b6Click(TObject *Sender);
        void __fastcall b7Click(TObject *Sender);
        void __fastcall b8Click(TObject *Sender);
        void __fastcall b9Click(TObject *Sender);
        void __fastcall b10Click(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму




public:		// User declarations
		__fastcall TFormaSpiskaSprEdTouch(TComponent* Owner);

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
        UnicodeString NameNom;
		bool MnVibor;
		__int64 IdFirm;
		__int64 IdSklad;
		__int64 IdNom;
		__int64 IdBasEd;
		__int64 IdEd;
		int TypeNom;
		double Kol;
		__int64 IdPod;
		__int64 IdGrp;

		void UpdateForm(void);
		void OpenSpisokEd(void);
		void OpenElement(int Num);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprEdTouch *FormaSpiskaSprEdTouch;
//---------------------------------------------------------------------------
#endif
