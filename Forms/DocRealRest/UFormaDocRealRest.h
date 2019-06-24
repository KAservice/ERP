//---------------------------------------------------------------------------

#ifndef UFormaDocRealRestH
#define UFormaDocRealRestH
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
#include "UDM.h"
#include "UFormaSpiskaSprFirm.h"
#include "UFormaSpiskaSprKlient.h"
#include "UFormaSpiskaSprSklad.h"
#include "UFormaSpiskaSprEd.h"
#include "UFormaSpiskaSprNom.h"
#include "UDMDocRealRest.h"
//#include "UPrintFormAll.h"
#include "USheetEditor.h"
#include <Buttons.hpp>
#include "UFormaSpiskaSprInfBase.h"
#include "UDMSprTypePrice.h"
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFormaDocRealRest : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TPanel *Panel3;
        TButton *ButtonClose;
        TPanel *Panel4;
        TDBGrid *DBGrid1;
        TButton *ButtonSave;
        TLabel *FSummaCheck;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label7;
        TDBEdit *PrimChk;
        TDBEdit *NumDoc;
        TDateTimePicker *DateDoc;
        TToolBar *ToolBar2;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonInsert;
        TToolButton *ToolButtonDelete;
        TButton *ButtonOK;
        TButton *ButtonProv;
        TEdit *EditFirm;
        TEdit *EditSklad;
        TEdit *EditKlient;
        TButton *ButtonEditFirm;
        TButton *ButtonEditSklad;
        TButton *ButtonEditKlient;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TDBText *DBTextFNameUser;
        TLabel *Label3;
        TDBText *SumDocDBText;
        TButton *ButtonPrintDoc;
        TBitBtn *BitBtnDateTime;
        TLabel *ProsmotrLabel;
        TButton *ViborBaseButton;
        TDBText *NameBaseDBText;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
	TComboBox *TypePriceComboBox;
	TActionList *ActionList;
	TAction *ActionOpenHelp;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonSaveClick(TObject *Sender);
        void __fastcall ToolButtonInsertClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall DateDocChange(TObject *Sender);
        void __fastcall DBGrid1EditButtonClick(TObject *Sender);
        void __fastcall ButtonProvClick(TObject *Sender);
        void __fastcall ButtonOKClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall ButtonEditFirmClick(TObject *Sender);
        void __fastcall ButtonEditSkladClick(TObject *Sender);
        void __fastcall ButtonEditKlientClick(TObject *Sender);
        void __fastcall ButtonPrintDocClick(TObject *Sender);
        void __fastcall BitBtnDateTimeClick(TObject *Sender);
        void __fastcall ViborBaseButtonClick(TObject *Sender);
	void __fastcall TypePriceComboBoxChange(TObject *Sender);
	void __fastcall ActionOpenHelpExecute(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);

private:	// User declarations




        TFormaSpiskaSprFirm *SpisokFirm;
        TFormaSpiskaSprSklad * SpisokSklad;
        TFormaSpiskaSprKlient * SpisokKlient;
        TFormaSpiskaSprNom *SpisokNom;
        TFormaSpiskaSprEd * SpisokEd;

        void OpenFormSpiskaSprEd(void);
        void OpenFormSpiskaSprNom(void);
        void OpenFormSpiskaSprFirm(void);
        void OpenFormSpiskaSprSklad(void);
        void OpenFormSpiskaSprKlient(void);

                TFormaSpiskaSprInfBase * FormaSpiskaSprInfBase;
        void OpenFormSpiskaSprInfBase(void);

        void __fastcall EndEdit(TObject *Sender);

        enum  {ViborTovar,ViborEdinica,ViborFirm,ViborSklad,ViborKlient, ViborInfBase, NO} EditRekvisit;
        enum  {aoAddNewString, aoNO} ActionOperation;
        
public:		// User declarations
        __fastcall TFormaDocRealRest(TComponent* Owner);
        TNotifyEvent FOnCloseForm;
        double SumCheck;
        TDMDocRealRest *DM;
        void UpdateForm(void);


         HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора
		__int64 IdDoc;           //идентификатор текущей записи
		__int64 IdGrp;        // идетификатор группы
        __int64 IdElementaMaster;  //идентификатор внешенго справочника-владельца

        void OpenPrintForm(void);
        void OutputString(TSheetEditor *prForm);
        void OutputZagolovokReport(TSheetEditor *prForm);
        void OutputPodavalReport(TSheetEditor *prForm);
        int numRow;
        int numCol;
		int porNumStr;

		TDMSprTypePrice *DMSprTypePrice;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocRealRest *FormaDocRealRest;
//---------------------------------------------------------------------------
#endif
