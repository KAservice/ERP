//---------------------------------------------------------------------------

#ifndef UForma_ZakazOfH
#define UForma_ZakazOfH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include "UDMRegZak.h"
#include "UDM.h"
#include "UDMSprKlient.h"
#include "UDMSprKKM.h"
#include "UFormaViborBVNom.h"
#include "UDMSprNom.h"
#include "UFormaViborSprEd.h"
#include "UFormaViborNomSpr.h"
#include "UFormaInputCode.h"
#include "UFormaArmKassir.h"
#include "UFormaDocRealRestTouch.h"
#include <oleauto.hpp>
#include <Menus.hpp>
#include "UPrintFormAll.h"
#include "UFormaInputText.h"
#include "UFormaViborSprStrObject.h"
//---------------------------------------------------------------------------
class TForma_ZakazOf : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TDBGrid *DBGrid1;
        TPanel *Panel1;
        TLabel *Label1;
        TGroupBox *GroupBox1;
        TDBText *SumDoc;
        TDBText *KrNameNomDBText;
        TLabel *Label2;
        TDBText *MPrigDBText;
        TLabel *Label3;
        TLabel *Label4;
        TDBText *NameKlientDBText;
        TDBText *NameUserDBText;
        TLabel *Label5;
        TLabel *ProsmotrLabel;
        TDBText *IDZakDBText;
        TMainMenu *MainMenu;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *N9;
        TMenuItem *N10;
        TMenuItem *N11;
        TMenuItem *N12;
        TMenuItem *N13;
        TMenuItem *N17;
        TMenuItem *N18;
        TMenuItem *N19;
        TMenuItem *N20;
        TMenuItem *N21;
        TMenuItem *N14;
        TGroupBox *GroupBox2;
        TLabel *SostZakaz;
        TMenuItem *N15;
        TMenuItem *N16;
        TDBText *NameStrObDBText;
        TMenuItem *N22;
        TMenuItem *N23;
        TMenuItem *N24;
        TStatusBar *StatusBar;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall N21Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall N19Click(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall N12Click(TObject *Sender);
        void __fastcall N13Click(TObject *Sender);
        void __fastcall N14Click(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall N17Click(TObject *Sender);
        void __fastcall N15Click(TObject *Sender);
        void __fastcall DBGrid1KeyPress(TObject *Sender, char &Key);
        void __fastcall Name_ZakDBEditKeyPress(TObject *Sender, char &Key);
        void __fastcall N11Click(TObject *Sender);
        void __fastcall N16Click(TObject *Sender);
        void __fastcall N24Click(TObject *Sender);
        void __fastcall N23Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForma_ZakazOf(TComponent* Owner);

        TDMRegZak * DM;

        TDMSprNom *Nom;
        TDMSprKlient *DMKlient;



        void VibratKlienta(void);

        void CreateCheckKKM(void);
        TFormaARMKassir * FormaArmKassir;

        void CreateDocRealRest(void);
        //TFormaDocRealRestTouch  * DocReal;

        TFormaViborBVNom *SprBV;
        void OpenFormViborSprBVNom(void);

        TFormaViborSprEd *SpisokEd;
        void OpenFormViborSprEd(void);

        TFormaViborNomSpr  *FormaViborNomSpr;
        void OpenFormViborNomSpr(void);

        TFormaInputCode *FormaInputCode;

        void OpenFormInputCodeNom(void);
        void OpenFormInputCodeNomBV(void);

        TFormaInputText * FormaInputText;
        void OpenFormInputCodeStrOb(void);
        
        TFormaViborSprStrObject   *FormaViborSprStrObject;
        void OpenFormViborObject(void);

        int IdDoc;           //идентификатор текущей записи
        int IdGrp;        // идентификатор группы
        int IdElementaMaster;  //идентификатор внешенго справочника-владельца
        bool OutReady;
        int IdPod;       //подразделение

         int VibTovarId;
         int VibTovarIdGrp;
         double SummaDoc;

        HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора
        bool ObjectSave;
        void UpdateForm(void);
        bool PrintZakaz(void);
        bool PrintSchet(void);


        void __fastcall EndEdit(TObject *Sender);
        TNotifyEvent FOnCloseForm;

        enum  {ViborTovarSprBV,ViborNomSpr,Edinica,ZakazKol,OtpKol,
                                CreateRealRest,ViborKlient, CreateCheck,
                                InputCodeBV, InputCodeNom, InputCodeStrOb,
                                ViborObject, NO} EditRekvisit;

        //работа с кухонным принтером
        Variant  Prn;
        bool PrnOK;
        bool PrinterActive;
        bool ErrorPrint;
        bool ConnectPrinter(void);
        bool DisconnectPrinter(void);
        bool PrintString(void);

        //печать заказа на обычном принтере
        bool PrintPaperZakaz(void);
        bool PrintZagolovokPaperZakaz(TPrintFormAll *prForm, String nameMPrig);
        bool PrintPodvalPaperZakaz(TPrintFormAll *prForm);
        bool PrintStringPaperZakaz(TPrintFormAll *prForm);
        bool PrintZagolovok;

        //печать обычного счета
        void PrintPaperSchet(void);
        void OutputString(TPrintFormAll *prForm);
        void OutputZagolovokReport(TPrintFormAll *prForm);
        void OutputPodavalReport(TPrintFormAll *prForm);
        int numRow;
        int numCol;
        int porNumStr;



        void UpdateSetup(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TForma_ZakazOf *Forma_ZakazOf;
//---------------------------------------------------------------------------
#endif
