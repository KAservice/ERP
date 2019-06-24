//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UFormaExportDoc.h"
#include "UGlobalConstant.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtonEdit"
#pragma link "cxCalendar"
#pragma link "cxCheckBox"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TFormaExportDoc::TFormaExportDoc(TComponent* Owner)
	: TForm(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
TypeEvent=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormaExportDoc::FormCreate(TObject *Sender)
{
PatchcxButtonEdit->Text="";
FileNamecxButtonEdit->Text="";


}
//-----------------------------------------------------------------------
bool TFormaExportDoc::Init(void)
{
bool result=false;


if (InterfaceMainObject>0)
	{
	//получим соединение
	IConnectionInterface * i_connection;
	InterfaceMainObject->kanQueryInterface(IID_IConnectionInterface,(void**)&i_connection);
	DM_Connection=i_connection->GetFibConnection();
	i_connection->kanRelease();

	//получим интерфейс COM системы для создания новых объектов
	IMainCOMInterface * i_com;
	InterfaceMainObject->kanQueryInterface(IID_IMainCOMInterface,(void**)&i_com);
	InterfaceGlobalCom=i_com->GetCOM();
	i_com->kanRelease();
	}



ConcxDateEdit->Date=Date()+EncodeTime(23,59,59,999);
NachcxDateEdit->Date=DM_Connection->GetPosNachReport();

//ПРИВЕЛЕГИИ
DM_Connection->GetPrivDM(GCPRIV_DM_NoModule);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;

result=true;

return result;
}
//---------------------------------------------------------------------------
int TFormaExportDoc::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TFormaExportDoc::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
//получим ICallBack для передачи события в вызывающую форму
if(InterfaceOwnerObject)
	{
	IkanCallBack * i_callback=0;
	InterfaceOwnerObject->kanQueryInterface(IID_IkanCallBack,(void**)&i_callback);
	if (i_callback)
		{
		i_callback->kanExternalEvent(InterfaceImpl,ClsIdImpl,TypeEvent,NumberProcVibor);
		}
	i_callback->kanRelease();
	}

Action=caFree;

if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}
//---------------------------------------------------------------------------
void TFormaExportDoc::UpdateForm(void)
{



}

//---------------------------------------------------------------------------
void __fastcall TFormaExportDoc::PatchcxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{


  if (SaveDialog1->Execute())
	{
	PatchcxButtonEdit->Text=ExtractFileDir(SaveDialog1->FileName);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaExportDoc::ExportAllDoccxButtonClick(TObject *Sender)
{
TDMExportDoc * dm=new TDMExportDoc(Application);

dm->DM_Connection=DM_Connection;
dm->InterfaceGlobalCom=InterfaceGlobalCom;
dm->InterfaceMainObject=InterfaceMainObject;
dm->Init();
dm->CatalogObmena=PatchcxButtonEdit->Text;
if (PoDatecxCheckBox->Checked==true)
	{
	TDateTime tec_date=NachcxDateEdit->Date;
	while (tec_date<=ConcxDateEdit->Date)
		{
		dm->ExportXMLAllDoc(tec_date, tec_date+EncodeTime(23,59,59,999));
		tec_date++;
		}
	}
else
	{
	dm->ExportXMLAllDoc(NachcxDateEdit->Date, ConcxDateEdit->Date);
	}
delete dm;

ShowMessage("Файлы с документами сформированы!");
}
//---------------------------------------------------------------------------

void __fastcall TFormaExportDoc::SprcxButtonClick(TObject *Sender)
{
TDMExportDoc * dm=new TDMExportDoc(Application);
dm->DM_Connection=DM_Connection;
dm->InterfaceGlobalCom=InterfaceGlobalCom;
dm->InterfaceMainObject=InterfaceMainObject;
dm->Init();
dm->CatalogObmena=PatchcxButtonEdit->Text;
dm->ExportXMLSpr();
delete dm;
}
//---------------------------------------------------------------------------

void __fastcall TFormaExportDoc::cxButtonCloseClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------


void __fastcall TFormaExportDoc::FileNamecxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
  if (OpenDialog1->Execute())
	{
	FileNamecxButtonEdit->Text=OpenDialog1->FileName;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFormaExportDoc::cxButtonImportClick(TObject *Sender)
{
TDMExportDoc * dm=new TDMExportDoc(Application);
dm->DM_Connection=DM_Connection;
dm->InterfaceGlobalCom=InterfaceGlobalCom;
dm->InterfaceMainObject=InterfaceMainObject;
dm->Init();
dm->ImportDoc(FileNamecxButtonEdit->Text);

delete dm;

ShowMessage("Документы импортированы!");
}
//---------------------------------------------------------------------------

