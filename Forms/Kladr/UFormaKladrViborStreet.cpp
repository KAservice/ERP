//---------------------------------------------------------------------------

#include "glPCH.h"
#pragma hdrstop

#include "UFormaKladrViborStreet.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
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
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxContainer"
#pragma link "cxLabel"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaKladrViborStreet::TFormaKladrViborStreet(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaKladrViborStreet::FormCreate(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TFormaKladrViborStreet::FormClose(TObject *Sender,
      TCloseAction &Action)
{
try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
Table->Active=false;
ADODataSet1->Active=false;
Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaKladrViborStreet::UpdateForm(void)
{
AnsiString name_object;
AnsiString code;
if (NameNasPunkt=="")
	{
	if (NameGorod=="")
		{//используем район
		if (NameRayon=="")
			{//используем регион
			name_object=NameRegion;
			}
		else
			{ //используем район
			name_object=NameRayon;
			}
		}
	else
		{ //используем город
		name_object=NameGorod;
		}
	}
else
	{ //используем населенный пункт
	name_object=NameNasPunkt;
	}

	
ADODataSet1->CommandText="select CODE from KLADR where NAME='"
						+name_object+"'";
ADODataSet1->Active=true;
code=ADODataSet1CODE->AsString;
ADODataSet1->Active=false;

AnsiString zapros="";
zapros=zapros+" select * from STREET";
zapros=zapros+" where CODE LIKE '";
zapros=zapros+code.SetLength(11)+"%%%%%%'";
zapros=zapros+" order by NAME";

Table->CommandText=zapros;
Table->Active=true;

}

//-----------------------------------------------------------------------------
void __fastcall TFormaKladrViborStreet::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------
void __fastcall TFormaKladrViborStreet::cxGrid1DBTableView1CellDblClick(
      TcxCustomGridTableView *Sender,
      TcxGridTableDataCellViewInfo *ACellViewInfo, TMouseButton AButton,
      TShiftState AShift, bool &AHandled)
{
OutReady=true;
Close();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaKladrViborStreet::ActionCloseExecute(TObject *Sender)
{
OutReady=false;
Close();
}
//---------------------------------------------------------------------------

