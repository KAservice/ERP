//---------------------------------------------------------------------------

#ifndef UFormaPrintExternalReportH
#define UFormaPrintExternalReportH
//---------------------------------------------------------------------------
#include "IDMFibConnection.h"
#include "USheetEditor.h"

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
//---------------------------------------------------------------------------
class TFormaPrintExternalReport : public TForm
{
__published:	// IDE-managed Components
        TTimer *Timer1;
        TLabel *Label1;
	TpFIBDataSet *IBQ;
	TpFIBTransaction *IBTr;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaPrintExternalReport(TComponent* Owner);


	IDMFibConnection * DM_Connection;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

        TSheetEditor  *PrintForm;
        AnsiString template_file_name;
        TcxSSCellObject *cell_template;
        TcxSSCellObject *cell_report;
        int x,y;
        int x1, y1;
        AnsiString GetTextTemplate(AnsiString text);
        TList * List;
        TList * TableList;
        AnsiString FindPerem(AnsiString text);
        AnsiString RunZapros(AnsiString zapros);
        
        void RunTableZapros(AnsiString zapros);
        AnsiString TableGetTextTemplate(AnsiString text);
        AnsiString TableFindPerem(AnsiString text);

        void CopyFormatCell(TcxSSCellObject *cell_templ, TcxSSCellObject *cell_rep);
        void SizeHeader(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaPrintExternalReport *FormaPrintExternalReport;
//---------------------------------------------------------------------------
#endif
