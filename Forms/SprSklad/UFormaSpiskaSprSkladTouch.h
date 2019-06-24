//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprSkladTouchH
#define UFormaSpiskaSprSkladTouchH
//---------------------------------------------------------------------------
#include "UDM.h"


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
class TFormaSpiskaSprSkladTouch : public TForm
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
	TpFIBDataSet *El;
	TpFIBTransaction *IBTr;
	TFIBIntegerField *ElTSKLAD;
	TFIBBCDField *ElIDSKLAD;
	TFIBWideStringField *ElNAMESKLAD;
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
private:	// User declarations
public:		// User declarations
		__fastcall TFormaSpiskaSprSkladTouch(TComponent* Owner);

	TDM * DM_Connection;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        TNotifyEvent FOnCloseForm;
        HANDLE IdRodForm;
        bool Vibor;
        bool OutReady;
        double Kol;
        void OpenSpisokSkl(void);
        void OpenNameElement(void);
        void OpenFormInKol(void);
        void OpenElement(int Num);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprSkladTouch *FormaSpiskaSprSkladTouch;
//---------------------------------------------------------------------------
#endif
