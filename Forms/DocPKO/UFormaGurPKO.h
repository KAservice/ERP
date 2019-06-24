//---------------------------------------------------------------------------

#ifndef UFormaGurPKOH
#define UFormaGurPKOH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TFormaGurPKO : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TDBGrid *DBGrid1;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TIBQuery *IBQGurnal;
        TIBTransaction *IBTr;
        TDataSource *DataSource1;
        TIntegerField *IBQGurnalIDDOC;
        TDateTimeField *IBQGurnalPOSDOC;
        TSmallintField *IBQGurnalPRDOC;
        TIBStringField *IBQGurnalTDOC;
        TIntegerField *IBQGurnalNUMDOC;
        TIntegerField *IBQGurnalIDFIRMDOC;
        TIntegerField *IBQGurnalIDSKLDOC;
        TIntegerField *IBQGurnalIDKLDOC;
        TIBBCDField *IBQGurnalSUMDOC;
        TIntegerField *IBQGurnalIDUSERDOC;
        TIBStringField *IBQGurnalNAMEKKM;
        TIBStringField *IBQGurnalNAMEKLIENT;
        TIBStringField *IBQGurnalNAMEFIRM;
        TIBQuery *IBQDoc;
        TIntegerField *IBQDocIDDOC;
        TDateTimeField *IBQDocPOSDOC;
        TSmallintField *IBQDocPRDOC;
        TIBStringField *IBQDocTDOC;
        TIntegerField *IBQDocNUMDOC;
        TIntegerField *IBQDocIDFIRMDOC;
        TIntegerField *IBQDocIDSKLDOC;
        TIntegerField *IBQDocIDKLDOC;
        TIBBCDField *IBQDocSUMDOC;
        TIntegerField *IBQDocIDUSERDOC;
        TIBStringField *IBQDocOSNPKO;
        TIBStringField *IBQDocNAMEKKM;
        TIBStringField *IBQDocNAMEKLIENT;
        TIBStringField *IBQDocNAMEFIRM;
        void __fastcall FormResize(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaGurPKO(TComponent* Owner);
        void UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaGurPKO *FormaGurPKO;
//---------------------------------------------------------------------------
#endif
