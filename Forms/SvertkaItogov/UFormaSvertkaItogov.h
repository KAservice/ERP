//---------------------------------------------------------------------------

#ifndef UFormaSvertkaItogovH
#define UFormaSvertkaItogovH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "UDM.h"
#include "UFormaSpiskaSprSklad.h"
#include "UFormaSpiskaSprFirm.h"
#include "UPrintFormAll.h"
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFormaSvertkaItogov : public TForm
{
__published:	// IDE-managed Components
        TButton *ButtonCreateDocOstNom;
        TLabel *Label1;
        TDateTimePicker *DateCon;
        TButton *ButtonClose;
        TEdit *NameSkladEdit;
        TButton *ButtonViborSklad;
        TLabel *Label4;
        TBitBtn *BitBtnDateTime;
        TDateTimePicker *DateNach;
        TEdit *NameFirmaEdit;
        TButton *ButtonVibFirm;
        TLabel *Label5;
	TpFIBTransaction *IBTr;
	TpFIBDataSet *IBQEl;
	TFIBStringField *IBQElNAMENOM;
	TFIBIntegerField *IBQElIDNOM;
	TFIBStringField *IBQElNAMEED;
	TFIBIntegerField *IBQElIDED;
	TFIBBCDField *IBQElSUMKOL;
	TFIBBCDField *IBQElSUM;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall ButtonViborSkladClick(TObject *Sender);
        void __fastcall ButtonCreateDocOstNomClick(TObject *Sender);
        void __fastcall BitBtnDateTimeClick(TObject *Sender);
        void __fastcall ButtonVibFirmClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaSvertkaItogov(TComponent* Owner);
       int IdSkl;

        void __fastcall EndEdit(TObject *Sender);

        enum  {ViborSklad, ViborFirm, NO} EditRekvisit;

        HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора
        int IdDoc;           //идентификатор текущей записи
        int IdGrp;        // идетификатор группы
        int IdElementaMaster;  //идентификатор внешенго справочника-владельца
        int IdFirm;


        TFormaSpiskaSprSklad * SpisokSklad;
        void OpenFormSpiskaSprSklad(void);
        TFormaSpiskaSprFirm * SpisokFirm;

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSvertkaItogov *FormaSvertkaItogov;
//---------------------------------------------------------------------------
#endif
