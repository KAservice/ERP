//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaXTableBase.h"
#include "UDataModuleMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGraphics"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxButtons"

//экспорт в Excel
#pragma link "cxExportC14"
#include "cxGridExportLink.hpp"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaXTableBase::TFormaXTableBase(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaXTableBase::FormCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void TFormaXTableBase::UpdateForm()
{
Table->Active=false;
Table->Active=true;


}
//---------------------------------------------------------------------------
void __fastcall TFormaXTableBase::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
Table->Active=false;
}
//---------------------------------------------------------------------------
void __fastcall TFormaXTableBase::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;	
}
//---------------------------------------------------------------------------
void __fastcall TFormaXTableBase::cxButtonSaveIsmClick(TObject *Sender)
{
try
		{
		Table->ApplyUpdates();
		if (pFIBTransactionUpdate->Active==true)
			{
			pFIBTransactionUpdate->Commit();
			}
		UpdateForm();
		}
catch(Exception &exception)
	{
	ShowMessage(exception.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaXTableBase::cxButtonCancelClick(TObject *Sender)
{
try
        {
		Table->CancelUpdates();
		if (pFIBTransactionUpdate->Active==true)
			{
			pFIBTransactionUpdate->Commit();
			}
		UpdateForm();
        }
        catch(Exception &exception)
				{
				pFIBTransactionUpdate->Rollback();
				ShowMessage(exception.Message);
				}
}
//---------------------------------------------------------------------------

void __fastcall TFormaXTableBase::cxButton1Click(TObject *Sender)
{
	SaveDialog1->FileName="Список таблиц.xls";
	if (SaveDialog1->Execute())
		{
		ExportGridToExcel(SaveDialog1->FileName, cxGrid1, true, true,true, "xls");
		}
}
//---------------------------------------------------------------------------

