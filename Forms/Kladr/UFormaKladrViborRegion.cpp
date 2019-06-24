//---------------------------------------------------------------------------
#include "glPCH.h"
#pragma hdrstop

#include "UFormaKladrViborRegion.h"

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
__fastcall TFormaKladrViborRegion::TFormaKladrViborRegion(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaKladrViborRegion::FormCreate(TObject *Sender)
{
// 
}
//---------------------------------------------------------------------------
void __fastcall TFormaKladrViborRegion::FormClose(TObject *Sender,
      TCloseAction &Action)
{
try {if(FOnCloseForm) FOnCloseForm(this); } catch (...){}
Table->Active=false;
ADODataSet1->Active=false;
Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaKladrViborRegion::UpdateForm(void)
{
switch (Object)
	{
	case 1:
		{
		NameObjectcxLabel->Caption="Регионы: ";
		OpenTableRegion();
		}break;
	case 2:
		{
		//NameObjectcxLabel->Caption="Районы: "+NameObject;
		OpenTableRayon();
		}break;
	case 3:
		{
		//NameObjectcxLabel->Caption="Города: "+NameObject;
		OpenTableGorod();
		}break;
	case 4:
		{
		//NameObjectcxLabel->Caption="Населенные пункты: "+NameObject;
        OpenTableNasPunkt();
		}break;
	}

}
//----------------------------------------------------------------------------
void TFormaKladrViborRegion::OpenTableRegion(void)
{

UnicodeString zapros="";
zapros=zapros+" select * from KLADR";
zapros=zapros+" where CODE LIKE '%%00000000000'";
zapros=zapros+" order by NAME";

Table->CommandText=zapros;
Table->Active=true;
}
//----------------------------------------------------------------------------
void TFormaKladrViborRegion::OpenTableRayon(void)
{
UnicodeString name_object;
UnicodeString code;
name_object=NameRegion;

ADODataSet1->CommandText="select CODE from KLADR where NAME='"
						+name_object+"'";
ADODataSet1->Active=true;
code=ADODataSet1CODE->AsString;
ADODataSet1->Active=false;

UnicodeString zapros="";
zapros=zapros+" select * from KLADR";
zapros=zapros+" where CODE LIKE '";
zapros=zapros+code.SetLength(2)+"%%%00000000'";
zapros=zapros+" order by NAME";

Table->CommandText=zapros;
Table->Active=true;

}
//-----------------------------------------------------------------------------
void TFormaKladrViborRegion::OpenTableGorod(void)
{
UnicodeString name_object;
UnicodeString code;
if (NameRayon=="")
	{//используем регион
	name_object=NameRegion;
	ADODataSet1->CommandText="select CODE from KLADR where NAME='"
						+name_object+"'";
	ADODataSet1->Active=true;
	code=ADODataSet1CODE->AsString;
	ADODataSet1->Active=false;

	UnicodeString zapros="";
	zapros=zapros+" select * from KLADR";
	zapros=zapros+" where CODE LIKE '";
	zapros=zapros+code.SetLength(2)+"%%%%%%00000'";
	zapros=zapros+" order by NAME";

	Table->CommandText=zapros;
	Table->Active=true;

	}
else
	{ //используем район
	name_object=NameRayon;
	ADODataSet1->CommandText="select CODE from KLADR where NAME='"
						+name_object+"'";
	ADODataSet1->Active=true;
	code=ADODataSet1CODE->AsString;
	ADODataSet1->Active=false;

	UnicodeString zapros="";
	zapros=zapros+" select * from KLADR";
	zapros=zapros+" where CODE LIKE '";
	zapros=zapros+code.SetLength(5)+"%%%00000'";
	zapros=zapros+" order by NAME";

	Table->CommandText=zapros;
	Table->Active=true;

	}



}
//-----------------------------------------------------------------------------
void TFormaKladrViborRegion::OpenTableNasPunkt(void)
{
UnicodeString name_object;
UnicodeString code;
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

ADODataSet1->CommandText="select CODE from KLADR where NAME='"
						+name_object+"'";
ADODataSet1->Active=true;
code=ADODataSet1CODE->AsString;
ADODataSet1->Active=false;

UnicodeString zapros="";
zapros=zapros+" select * from KLADR";
zapros=zapros+" where CODE LIKE '";
zapros=zapros+code.SetLength(8)+"%%%%%'";
zapros=zapros+" order by NAME";

Table->CommandText=zapros;
Table->Active=true;


}
//-----------------------------------------------------------------------------
UnicodeString TFormaKladrViborRegion::GetCodeObjectPoName(void)
{
UnicodeString result="";

return result;
}
//-----------------------------------------------------------------------------
void __fastcall TFormaKladrViborRegion::TableCalcFields(TDataSet *DataSet)
{
TableRECNO->AsInteger=Table->RecNo;
}
//---------------------------------------------------------------------------
void __fastcall TFormaKladrViborRegion::cxGrid1DBTableView1CellDblClick(
      TcxCustomGridTableView *Sender,
      TcxGridTableDataCellViewInfo *ACellViewInfo, TMouseButton AButton,
      TShiftState AShift, bool &AHandled)
{
OutReady=true;
Close();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaKladrViborRegion::ActionCloseExecute(TObject *Sender)
{
OutReady=false;
Close();
}
//---------------------------------------------------------------------------

