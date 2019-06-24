//---------------------------------------------------------------------------

#ifndef UFormaDocPerTouchH
#define UFormaDocPerTouchH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBQuery.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <DBGrids.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "UDMDocPer.h"
#include "UDM.h"
#include "UFormaSpiskaSprBVNomTouch.h"
#include "UFormaSpiskaSprEdTouch.h"
#include "UFormaSpiskaSprSkladTouch.h"
#include <Menus.hpp>
#include <Buttons.hpp>
#include <oleauto.hpp>
#include "UDMSprKKM.h"
#include "UDMSprNom.h"
#include "UKalkulator.h"
//---------------------------------------------------------------------------
class TFormaDocPerTouch : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TPanel *Panel3;
        TButton *ButtonClose;
        TPanel *Panel4;
        TDBGrid *DBGrid1;
        TPanel *Panel1;
        TLabel *Label1;
        TButton *ButtonOK;
        TLabel *LabelNameFirm;
        TLabel *LabelNameSklad;
        TLabel *LabelNameSkladPol;
        TDBText *NameUserDBText;
        TBitBtn *BitBtnNewStr;
        TBitBtn *BitBtnDel;
        TBitBtn *BitBtnViborSklad;
        TBitBtn *BitBtnEditKol;
        TBitBtn *BitBtnViborEd;
        TBitBtn *BitBtnPrint;
        TBitBtn *BitBtnUp;
        TBitBtn *BitBtnDown;
        TDBText *NumDocDBText;
        TDBText *PosDocDBText;
        TLabel *Label2;
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonSaveClick(TObject *Sender);
        void __fastcall ButtonProvClick(TObject *Sender);
        void __fastcall ButtonOKClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall BitBtnNewStrClick(TObject *Sender);
        void __fastcall BitBtnDelClick(TObject *Sender);
        void __fastcall BitBtnEditKolClick(TObject *Sender);
        void __fastcall BitBtnViborEdClick(TObject *Sender);
        void __fastcall BitBtnUpClick(TObject *Sender);
        void __fastcall BitBtnDownClick(TObject *Sender);
        void __fastcall BitBtnViborSkladClick(TObject *Sender);
        void __fastcall BitBtnPrintClick(TObject *Sender);

private:	// User declarations

public:		// User declarations
		__fastcall TFormaDocPerTouch(TComponent* Owner);

	TDM * DM_Connection;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        TDMDocPer * DM;
        TDMSprNom *Nom;
        TDMSprKKM *KKM;

        HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
		__int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца

        bool OutReady;
        TKalkulator *Kalkulator;

        TNotifyEvent FOnCloseForm;

        void __fastcall EndEdit(TObject *Sender);

        enum  {EditNomBVTouch,EditEdinicaTouch,EditKol, EditSkladTouch, NO} EditRekvisit;
        enum  {aoAddNewString, aoNO} ActionOperation;
        
        TFormaSpiskaSprBVNomTouch *SpisokBVTouch;
        void OpenFormSpiskaBVNomTouch(void);


        TFormaSpiskaSprEdTouch  * SpisokEdTouch;
        void OpenFormSpiskaSprEdTouch(void);

        TFormaSpiskaSprSkladTouch *SpisokSkladTouch;
        void OpenFormSpiskaSprSkladTouch(void);

        void UpdateForm(void);
        void NewDoc(void);
        __int64 IdKKM;

        bool PrintDoc(void);



};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocPerTouch *FormaDocPerTouch;
//---------------------------------------------------------------------------
#endif
