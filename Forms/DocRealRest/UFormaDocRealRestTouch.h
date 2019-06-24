//---------------------------------------------------------------------------

#ifndef UFormaDocRealRestTouchH
#define UFormaDocRealRestTouchH
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
#include "UDMDocRealRest.h"
//---------------------------------------------------------------------------
class TFormaDocRealRestTouch : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TPanel *Panel3;
        TButton *ButtonClose;
        TPanel *Panel4;
        TDBGrid *DBGrid1;
        TLabel *FSummaCheck;
        TPanel *Panel1;
        TLabel *LabelNameDoc;
        TLabel *LabelPrim;
        TButton *ButtonOK;
        TLabel *LabelFirm;
        TLabel *LabelSklad;
        TDBText *DBTextFNameUser;
        TDBText *SumDocDBText;
        TLabel *LabelKlient;
        TButton *ButtonPrint;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonSaveClick(TObject *Sender);
        void __fastcall ButtonOKClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall ButtonPrintClick(TObject *Sender);

private:	// User declarations




        void __fastcall EndEdit(TObject *Sender);

        enum  {ViborTovar,ViborEdinica,ViborFirm,ViborSklad,ViborKlient, NO} EditRekvisit;

public:		// User declarations
        __fastcall TFormaDocRealRestTouch(TComponent* Owner);
         double SumCheck;
         TDMDocRealRest *DM;
         void UpdateForm(void);
         TNotifyEvent FOnCloseForm;

         HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора
        int IdDoc;           //идентификатор текущей записи
        int IdGrp;        // идетификатор группы
        int IdElementaMaster;  //идентификатор внешенго справочника-владельца
        bool OutReady;
        bool PrintDocFR(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaDocRealRestTouch *FormaDocRealRestTouch;
//---------------------------------------------------------------------------
#endif
