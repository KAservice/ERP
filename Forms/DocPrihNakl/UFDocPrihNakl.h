//---------------------------------------------------------------------------

#ifndef UFDocPrihNaklH
#define UFDocPrihNaklH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <Grids.hpp>
#include <IBCustomDataSet.hpp>
#include <IBQuery.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <IBDatabase.hpp>
#include <Mask.hpp>
#include "UDM.h"
#include "UFormaSpiskaSprEd.h"
#include "UFormaSpiskaSprNom.h"
#include "UDMDocPrihNakl.h"
//---------------------------------------------------------------------------
class TFDocPrihNakl : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TLabel *LabelSumma;
        TButton *ButtonClose;
        TButton *ButtonOK;
        TButton *ButtonDvReg;
        TButton *ButtonSave;
        TPanel *Panel3;
        TPanel *Panel4;
        TDBGrid *DBGrid1;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TDateTimePicker *FDateDoc;
        TToolBar *ToolBar2;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonInsert;
        TToolButton *ToolButtonDelete;
        TDBEdit *DBPrim;
        TDBEdit *DBNumberDoc;
        TButton *ButtonPrint;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall TableDocDblClick(TObject *Sender);
        void __fastcall ToolButtonInsertClick(TObject *Sender);
        void __fastcall ButtonSaveClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ButtonDvRegClick(TObject *Sender);
        void __fastcall ButtonOKClick(TObject *Sender);
        void __fastcall FDateDocChange(TObject *Sender);
        void __fastcall DBGrid1EditButtonClick(TObject *Sender);
        void __fastcall DBGrid1ColExit(TObject *Sender);
        void __fastcall DBGrid1Exit(TObject *Sender);
        void __fastcall DBGrid1KeyPress(TObject *Sender, char &Key);
        void __fastcall FormResize(TObject *Sender);
private:	// User declarations




        void InputNewDoc(void);
        void OpenDoc(void);
        bool SaveNewDoc(void);
        bool SaveDoc(void);
        bool DvRegDoc(void);
        bool CancelDvDoc(void);
        void OpenFSSprNom(void);
        void OpenFSSprEd(void);

        void __fastcall EndEdit(TObject *Sender);

        enum  {Tovar ,Edinica, NO} EditRekvisit;

        
        HANDLE IdRodForm;
        HANDLE IdDochForm;
        bool NewElement;  // новый элемент
        bool Prosmotr;    //только просмотр
        bool Vibor;       //для выбора
        bool ObjectSave;
        
        
public:		// User declarations
        __fastcall TFDocPrihNakl(TComponent* Owner);

        TDMDocPrihNakl * DM;
        TFormaSpiskaSprEd * Ed;
        TFormaSpiskaSprNom * Nom;

        int IdDoc;           //идентификатор текущей записи
        int IdGrp;        // идентификатор группы
        int IdElementaMaster;  //идентификатор внешенго справочника-владельца
        bool OutReady;

         int VibTovarId;
         int VibTovarIdGrp;
         double SummaDoc;
};
//---------------------------------------------------------------------------
extern PACKAGE TFDocPrihNakl *FDocPrihNakl;
//---------------------------------------------------------------------------
#endif
