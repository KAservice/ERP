//---------------------------------------------------------------------------

#ifndef UKalkulatorH
#define UKalkulatorH
//---------------------------------------------------------------------------
#include "IMainInterface.h"


//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TKalkulator : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *kn1;
        TEdit *Tablo;
        TBitBtn *kn2;
        TBitBtn *kn3;
        TBitBtn *kn4;
        TBitBtn *kn9;
        TBitBtn *kn5;
        TBitBtn *kn6;
        TBitBtn *kn7;
        TBitBtn *kn8;
        TBitBtn *kn0;
        TBitBtn *knComma;
        TBitBtn *knOK;
        TBitBtn *knC;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall knOKClick(TObject *Sender);
        void __fastcall knCClick(TObject *Sender);
        void __fastcall kn1Click(TObject *Sender);
        void __fastcall kn2Click(TObject *Sender);
        void __fastcall kn3Click(TObject *Sender);
        void __fastcall kn4Click(TObject *Sender);
        void __fastcall kn5Click(TObject *Sender);
        void __fastcall kn6Click(TObject *Sender);
        void __fastcall kn7Click(TObject *Sender);
        void __fastcall kn8Click(TObject *Sender);
        void __fastcall kn9Click(TObject *Sender);
        void __fastcall kn0Click(TObject *Sender);
        void __fastcall knCommaClick(TObject *Sender);
private:	// User declarations
	int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму
public:		// User declarations
		__fastcall TKalkulator(TComponent* Owner);


		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

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


        double Result;

};
//---------------------------------------------------------------------------
extern PACKAGE TKalkulator *Kalkulator;
//---------------------------------------------------------------------------
#endif
