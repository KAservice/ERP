//---------------------------------------------------------------------------

#ifndef UFormaDocRecKDRH
#define UFormaDocRecKDRH
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
#include "UDMDocPKO.h"
#include "UDM.h"
#include "UFormaSpiskaSprFirm.h"
#include "UFormaSpiskaSprInfBase.h"
#include "UDMDocRecKDR.h"
#include <Buttons.hpp>
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFormaDocRecKDR : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TDBEdit *NumDoc;
        TDateTimePicker *PosDoc;
        TButton *ButtonEditFirm;
        TLabel *Label12;
        TButton *ButtonProv;
        TButton *ButtonSave;
        TButton *ButtonOK;
        TButton *ButtonClose;
        TLabel *Label3;
        TDBText *DBTextFNameUser;
        TButton *ViborBaseButton;
        TDBText *NameBaseDBText;
        TLabel *ProsmotrLabel;
        TBitBtn *BitBtnDateTime;
        TDBEdit *NameFirmDBEdit;
        TLabel *Label5;
        TDBEdit *OperationDBEdit;
        TLabel *Label6;
        TDBEdit *DohodDBEdit;
        TLabel *Label7;
        TDBEdit *RashodDBEdit;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonSaveClick(TObject *Sender);
        void __fastcall PosDocChange(TObject *Sender);
        void __fastcall ButtonProvClick(TObject *Sender);
        void __fastcall ButtonOKClick(TObject *Sender);
        void __fastcall ButtonEditFirmClick(TObject *Sender);
        void __fastcall ViborBaseButtonClick(TObject *Sender);
        void __fastcall BitBtnDateTimeClick(TObject *Sender);

private:	// User declarations




        TFormaSpiskaSprFirm *SpisokFirm;


        void OpenFormSpiskaSprFirm(void);

        TFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
        void OpenFormSpiskaSprInfBase(void);

        void __fastcall EndEdit(TObject *Sender);

        enum  {ViborFirm,ViborSklad, ViborInfBase, NO} EditRekvisit;

public:		// User declarations
        __fastcall TFormaDocRecKDR(TComponent* Owner);
        TNotifyEvent FOnCloseForm;

        double SumCheck;
        TDMDocRecKDR *DM;

        HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора
        int IdDoc;           //идентификатор текущей записи
        int IdGrp;        // идетификатор группы
        int IdElementaMaster;  //идентификатор внешенго справочника-владельца


        int numRow;
        int numCol;
        void UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocRecKDR *FormaDocRecKDR;
//---------------------------------------------------------------------------
#endif
