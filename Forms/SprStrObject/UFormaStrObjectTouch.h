//---------------------------------------------------------------------------

#ifndef UFormaStrObjectTouchH
#define UFormaStrObjectTouchH
//---------------------------------------------------------------------------
#include "UDM.h"
#include "IDMSprStrObject.h"
#include "IFormaZakazOf.h"
#include "IDMRegZak.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
//---------------------------------------------------------------------------
class TFormaStrObjectTouch : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel6;
        TPanel *Panel7;
        TSpeedButton *g1;
        TLabel *Label1;
        TSpeedButton *g2;
        TSpeedButton *g10;
        TSpeedButton *g3;
        TSpeedButton *g4;
        TSpeedButton *g5;
        TSpeedButton *g6;
        TSpeedButton *g7;
        TSpeedButton *g8;
        TSpeedButton *g9;
        TPanel *Panel8;
        TLabel *Label2;
        TSpeedButton *o1;
        TSpeedButton *o2;
        TSpeedButton *o3;
        TSpeedButton *o17;
        TSpeedButton *o16;
        TSpeedButton *o21;
        TSpeedButton *o20;
        TSpeedButton *o19;
        TSpeedButton *o24;
        TSpeedButton *o23;
        TSpeedButton *o22;
        TSpeedButton *o27;
        TSpeedButton *o26;
        TSpeedButton *o25;
        TSpeedButton *o30;
        TSpeedButton *o29;
        TSpeedButton *o28;
        TSpeedButton *o13;
        TSpeedButton *o5;
        TSpeedButton *o8;
        TSpeedButton *o11;
        TSpeedButton *o14;
        TSpeedButton *o6;
        TSpeedButton *o9;
        TSpeedButton *o12;
        TSpeedButton *o15;
        TSpeedButton *o18;
        TSpeedButton *o4;
        TSpeedButton *o7;
        TSpeedButton *o10;
        TPanel *Panel9;
        TBitBtn *z1;
        TBitBtn *z2;
        TBitBtn *z3;
        TBitBtn *z4;
        TBitBtn *z5;
        TBitBtn *z6;
        TBitBtn *z7;
        TBitBtn *z8;
        TBitBtn *z9;
        TBitBtn *z10;
        TLabel *Label3;
        TBitBtn *BitBtnExit;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *SpisokGrpOb;
	TpFIBDataSet *SpisokOb;
	TpFIBDataSet *SpisokZak;
	TFIBSmallIntField *SpisokGrpObGRP_STROB;
	TFIBIntegerField *SpisokGrpObCODE_STROB;
	TFIBSmallIntField *SpisokObGRP_STROB;
	TFIBIntegerField *SpisokObCODE_STROB;
	TFIBBCDField *SpisokZakSUM_ZAK;
	TFIBSmallIntField *SpisokZakSOST_ZAK;
	TFIBBCDField *SpisokGrpObID_STROB;
	TFIBBCDField *SpisokGrpObIDGRP_STROB;
	TFIBBCDField *SpisokObID_STROB;
	TFIBBCDField *SpisokObIDGRP_STROB;
	TFIBBCDField *SpisokZakID_ZAK;
	TFIBBCDField *SpisokZakIDOB_ZAK;
	TFIBBCDField *SpisokZakIDKLIENT_ZAK;
	TFIBBCDField *SpisokZakIDUSER_ZAK;
	TFIBWideStringField *SpisokGrpObNAME_STROB;
	TFIBWideStringField *SpisokObNAME_STROB;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall BitBtnExitClick(TObject *Sender);
        void __fastcall g1Click(TObject *Sender);
        void __fastcall g2Click(TObject *Sender);
        void __fastcall g3Click(TObject *Sender);
        void __fastcall g4Click(TObject *Sender);
        void __fastcall g5Click(TObject *Sender);
        void __fastcall g7Click(TObject *Sender);
        void __fastcall g8Click(TObject *Sender);
        void __fastcall g9Click(TObject *Sender);
        void __fastcall g10Click(TObject *Sender);
        void __fastcall g6Click(TObject *Sender);
        void __fastcall o1Click(TObject *Sender);
        void __fastcall o2Click(TObject *Sender);
        void __fastcall o3Click(TObject *Sender);
        void __fastcall o4Click(TObject *Sender);
        void __fastcall o5Click(TObject *Sender);
        void __fastcall o6Click(TObject *Sender);
        void __fastcall o7Click(TObject *Sender);
        void __fastcall o8Click(TObject *Sender);
        void __fastcall o9Click(TObject *Sender);
        void __fastcall o10Click(TObject *Sender);
        void __fastcall o11Click(TObject *Sender);
        void __fastcall o12Click(TObject *Sender);
        void __fastcall o13Click(TObject *Sender);
        void __fastcall o14Click(TObject *Sender);
        void __fastcall o15Click(TObject *Sender);
        void __fastcall o16Click(TObject *Sender);
        void __fastcall o17Click(TObject *Sender);
        void __fastcall o18Click(TObject *Sender);
        void __fastcall o19Click(TObject *Sender);
        void __fastcall o20Click(TObject *Sender);
        void __fastcall o21Click(TObject *Sender);
        void __fastcall o22Click(TObject *Sender);
        void __fastcall o23Click(TObject *Sender);
        void __fastcall o24Click(TObject *Sender);
        void __fastcall o25Click(TObject *Sender);
        void __fastcall o26Click(TObject *Sender);
        void __fastcall o28Click(TObject *Sender);
        void __fastcall o29Click(TObject *Sender);
        void __fastcall o30Click(TObject *Sender);
        void __fastcall o27Click(TObject *Sender);
        void __fastcall z1Click(TObject *Sender);
        void __fastcall z2Click(TObject *Sender);
        void __fastcall z3Click(TObject *Sender);
        void __fastcall z4Click(TObject *Sender);
        void __fastcall z5Click(TObject *Sender);
        void __fastcall z6Click(TObject *Sender);
        void __fastcall z7Click(TObject *Sender);
        void __fastcall z8Click(TObject *Sender);
        void __fastcall z9Click(TObject *Sender);
        void __fastcall z10Click(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму


		IFormaZakazOf *FormaZakOf;
		enum  {ER_NoRekv,EditRekvisitZakaz,Edinica,FirmaRekvisit,KlientRekvisit,SkladRekvisit, NO} EditRekvisit;

		void OpenSpisokGrpObject(void);
        void OpenSpisokObject(void);
		void OpenSpisokZak(void);
		void OpenFormZakaz(void);
		void OpenFormNewZakaz(void);
		void OpenVibGrpObject(int Num);
		void OpenZakazVibObject(int Num);
		void OpenVibZakaz(int Num);
		void ClearButtonObject(void);
		int PolKolZakazov(IdOb);

		IDMSprStrObject* DMGrpObject;


		IDMRegZak * RegZak;
		int IdGrp;
		int IdObject;
		int IdZakaz;

		bool Vibor;                        //форма открыта для выбора
		int NumberProcVibor;               //какую процедуру использовать для обработки выбора во внешней форме
public:		// User declarations
		__fastcall TFormaStrObjectTouch(TComponent* Owner);

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







};
//---------------------------------------------------------------------------
extern PACKAGE TFormaStrObjectTouch *FormaStrObjectTouch;
//---------------------------------------------------------------------------
#endif
