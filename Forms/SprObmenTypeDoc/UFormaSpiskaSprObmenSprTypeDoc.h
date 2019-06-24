//---------------------------------------------------------------------------

#ifndef UFormaSpiskaSprObmenSprTypeDocH
#define UFormaSpiskaSprObmenSprTypeDocH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ToolWin.hpp>
#include "UDM.h"
#include "UDMSprObmenTypeDoc.h"
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class TFormaSpiskaSprObmenTypeDoc : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TDBGrid *DBGrid1;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonDelete;
        TButton *ButtonClose;
        TToolButton *ToolButton4;
        TButton *ButtonOK;
        TLabel *HintLabel;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall ToolButtonDeleteClick(TObject *Sender);
        void __fastcall ButtonCloseClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall ButtonOKClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaSpiskaSprObmenTypeDoc(TComponent* Owner);

        HANDLE IdRodForm;
        HANDLE IdDochForm;

        TDMSprObmenTypeDoc* DM;


        bool Vibor;
        bool OutReady;

        int IdBase;   

        int ViborIdNom;  //��������� ������������
        bool AllElement;//������� �������� ��� �������� ��� ���
        bool Prosmotr;

        BEGIN_MESSAGE_MAP
                MESSAGE_HANDLER(MESSAGE_READY, TMessage,EndEdit)
        END_MESSAGE_MAP(TComponent)
        void __fastcall EndEdit(TMessage&Message);





        void DeleteElement();


        void UpdateForm(void);

        enum{NO} ViborRekvisit;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSpiskaSprObmenTypeDoc *FormaSpiskaSprObmenTypeDoc;
//---------------------------------------------------------------------------
#endif
