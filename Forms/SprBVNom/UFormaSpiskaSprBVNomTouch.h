//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprBVNomTouchH
#define UFormaSpiskaSprBVNomTouchH
//---------------------------------------------------------------------------

#include "IFormaSpiskaSprEdTouch.h"
#include "UDM.h"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
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
class TFormaSpiskaSprBVNomTouch : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BitBtnClose;
        TPanel *Panel1;
        TSpeedButton *g3;
        TSpeedButton *g5;
        TSpeedButton *g4;
        TSpeedButton *g1;
        TSpeedButton *g2;
        TSpeedButton *g28;
        TSpeedButton *g25;
        TSpeedButton *g22;
        TSpeedButton *g19;
        TSpeedButton *g16;
        TSpeedButton *g13;
        TSpeedButton *g10;
        TSpeedButton *g7;
        TSpeedButton *g29;
        TSpeedButton *g26;
        TSpeedButton *g23;
        TSpeedButton *g20;
        TSpeedButton *g17;
        TSpeedButton *g14;
        TSpeedButton *g11;
        TSpeedButton *g8;
        TSpeedButton *g30;
        TSpeedButton *g27;
        TSpeedButton *g24;
        TSpeedButton *g21;
        TSpeedButton *g18;
        TSpeedButton *g15;
        TSpeedButton *g12;
        TSpeedButton *g9;
        TSpeedButton *g6;
        TLabel *Label1;
        TPanel *Panel2;
        TLabel *Label2;
        TBitBtn *b2;
        TBitBtn *b3;
        TBitBtn *b1;
        TBitBtn *b8;
        TBitBtn *b9;
        TBitBtn *b12;
        TBitBtn *b11;
        TBitBtn *b10;
        TBitBtn *b15;
        TBitBtn *b14;
        TBitBtn *b13;
        TBitBtn *b4;
        TBitBtn *b5;
        TBitBtn *b6;
        TBitBtn *b7;
        TBitBtn *b25;
        TBitBtn *b28;
        TBitBtn *b29;
        TBitBtn *b30;
        TBitBtn *b27;
        TBitBtn *b24;
        TBitBtn *b21;
        TBitBtn *b18;
        TBitBtn *b19;
        TBitBtn *b20;
        TBitBtn *b22;
        TBitBtn *b23;
        TBitBtn *b26;
        TBitBtn *b16;
        TBitBtn *b17;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *Grp;
	TpFIBDataSet *El;
	TFIBIntegerField *ElCODE_BVNOM;
	TFIBIntegerField *ElTNOM;
	TFIBBCDField *GrpID_GBVNOM;
	TFIBBCDField *GrpIDGRP_GBVNOM;
	TFIBBCDField *GrpIDPOD_GBVNOM;
	TFIBBCDField *ElID_BVNOM;
	TFIBBCDField *ElIDPOD_BVNOM;
	TFIBBCDField *ElIDNOM_BVNOM;
	TFIBBCDField *ElIDGRP_BVNOM;
	TFIBBCDField *ElIDBASEDNOM;
	TFIBWideStringField *ElNAMENOM;
	TFIBWideStringField *ElKRNAMENOM;
	TFIBWideStringField *GrpNAME_GBVNOM;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BitBtnCloseClick(TObject *Sender);
        void __fastcall g1Click(TObject *Sender);
        void __fastcall g2Click(TObject *Sender);
        void __fastcall g3Click(TObject *Sender);
        void __fastcall g4Click(TObject *Sender);
        void __fastcall g5Click(TObject *Sender);
        void __fastcall g6Click(TObject *Sender);
        void __fastcall g7Click(TObject *Sender);
        void __fastcall g8Click(TObject *Sender);
        void __fastcall g9Click(TObject *Sender);
        void __fastcall g10Click(TObject *Sender);
        void __fastcall g11Click(TObject *Sender);
        void __fastcall g12Click(TObject *Sender);
        void __fastcall g13Click(TObject *Sender);
        void __fastcall g14Click(TObject *Sender);
        void __fastcall g15Click(TObject *Sender);
        void __fastcall g16Click(TObject *Sender);
        void __fastcall g17Click(TObject *Sender);
        void __fastcall g18Click(TObject *Sender);
        void __fastcall g19Click(TObject *Sender);
        void __fastcall g20Click(TObject *Sender);
        void __fastcall g21Click(TObject *Sender);
        void __fastcall g22Click(TObject *Sender);
        void __fastcall g23Click(TObject *Sender);
        void __fastcall g24Click(TObject *Sender);
        void __fastcall g25Click(TObject *Sender);
        void __fastcall g26Click(TObject *Sender);
        void __fastcall g27Click(TObject *Sender);
        void __fastcall g28Click(TObject *Sender);
        void __fastcall g29Click(TObject *Sender);
        void __fastcall g30Click(TObject *Sender);
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
        void __fastcall b11Click(TObject *Sender);
        void __fastcall b12Click(TObject *Sender);
        void __fastcall b13Click(TObject *Sender);
        void __fastcall b14Click(TObject *Sender);
        void __fastcall b15Click(TObject *Sender);
        void __fastcall b16Click(TObject *Sender);
        void __fastcall b17Click(TObject *Sender);
        void __fastcall b18Click(TObject *Sender);
        void __fastcall b19Click(TObject *Sender);
        void __fastcall b20Click(TObject *Sender);
        void __fastcall b21Click(TObject *Sender);
        void __fastcall b22Click(TObject *Sender);
        void __fastcall b23Click(TObject *Sender);
        void __fastcall b24Click(TObject *Sender);
        void __fastcall b25Click(TObject *Sender);
        void __fastcall b26Click(TObject *Sender);
        void __fastcall b27Click(TObject *Sender);
        void __fastcall b28Click(TObject *Sender);
        void __fastcall b29Click(TObject *Sender);
        void __fastcall b30Click(TObject *Sender);
private:	// User declarations

		bool ExecPriv, InsertPriv, EditPriv, DeletePriv;
		int TypeEvent; // тип события выбора в текущей форме для передачи в вызывающую форму

        void OpenNameGrp(void);
        void OpenNameElement(void);
        void OpenFormInKol(void);
        void OpenElement(int Num);
        void OpenGrp(int Num);

        bool GetColor(void);
        void UpdateButtonGRP(TSpeedButton * but);
		void UpdateButtonEl(TBitBtn * but);

        IFormaSpiskaSprEdTouch * FormaSpiskaSprEdTouch;
		void OpenFormSpiskaSprEd(void);


		enum  {ER_NoRekv,ViborEdinica, NO} EditRekvisit;
public:		// User declarations
		__fastcall TFormaSpiskaSprBVNomTouch(TComponent* Owner);

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


        bool MnVibor;
        bool ZaprosEd;


		__int64 IdFirm;
		__int64 IdSklad;
		__int64 IdNom;
		__int64 IdEd;
        UnicodeString NameEd;
        double KFEd;
        double Kol;


		__int64 IdPod;
        __int64 IdGrp;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprBVNomTouch *FormaSpiskaSprBVNomTouch;
//---------------------------------------------------------------------------
#endif
