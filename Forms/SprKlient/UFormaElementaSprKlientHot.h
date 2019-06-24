//---------------------------------------------------------------------------

#ifndef UFormaElementaSprKlientHotH
#define UFormaElementaSprKlientHotH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UDMSprKlient.h"
#include "UDM.h"
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <ComCtrls.hpp>
#include "UDMSprKlientDopFisL.h"
#include "UDMSprDocKlient.h"
#include "UFormaElementaSprDocKlientMod.h"
//---------------------------------------------------------------------------
class TFormaElementaSprKlientHot : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TEdit *NameEdit;
        TButton *ButtonFind;
        TDBGrid *DBGrid1;
        TButton *ButtonVibrat1;
        TButton *ButtonClose1;
        TButton *ButtonOK2;
        TButton *ButtonClose2;
        TLabel *Label1;
        TLabel *Label3;
        TDBText *AdrDBText;
        TLabel *Label2;
        TDateTimePicker *DateRogDateTimePicker;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TButton *ButtonStep2;
        TDBEdit *MestoRogDBEdit;
        TDBEdit *MestoRabDBEdit;
        TDBEdit *DolRabDBEdit;
        TDBEdit *AdrKlientDBEdit;
        TDBEdit *NameKlientDBEdit;
        TGroupBox *GroupBox1;
        TDBText *VidDBText;
        TLabel *Label11;
        TLabel *Label9;
        TDBText *SerDBText;
        TLabel *Label10;
        TDBText *NumDBText;
        TLabel *Label12;
        TDBText *DateVidDBText;
        TLabel *Label8;
        TComboBox *DocumentComboBox;
        TButton *ButtonIsmdoc;
        TButton *ButtonNewDoc;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonFindClick(TObject *Sender);
        void __fastcall ButtonVibrat1Click(TObject *Sender);
        void __fastcall DBGrid1DblClick(TObject *Sender);
        void __fastcall NameEditKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall DBGrid1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall ButtonClose1Click(TObject *Sender);
        void __fastcall ButtonOK2Click(TObject *Sender);
        void __fastcall ButtonClose2Click(TObject *Sender);
        void __fastcall ButtonStep2Click(TObject *Sender);
        void __fastcall DocumentComboBoxChange(TObject *Sender);
        void __fastcall ButtonIsmdocClick(TObject *Sender);
        void __fastcall ButtonNewDocClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaElementaSprKlientHot(TComponent* Owner);

        TDMSprKlient  * DM;
        TDMSprKlientDopFisL *  DMSprKlientDopFisL;
        TDMSprDocKlient *DMSprDocKlient;

        TFormaElementaSprDocKlientMod *FormaElementaSprDocKlient;

        void UpdateForm(void);

        TNotifyEvent FOnCloseForm;
        void __fastcall EndEdit(TObject *Sender);

        enum  { NO, EditDocKlient} EditRekvisit;


        HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора
        bool OutReady;

        void CreateNewKlient(void);
        void Step2(void);
        bool Nayden;
        void ZapolnitSpisokDoc(void);

        bool NewKlient;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaElementaSprKlientHot *FormaElementaSprKlientHot;
//---------------------------------------------------------------------------
#endif
