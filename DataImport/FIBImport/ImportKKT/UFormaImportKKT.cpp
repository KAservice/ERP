//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//----------------------------------------------------------------------------
#include "UFormaImportKKT.h"
#include "UDataModuleMain.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxTextEdit"
#pragma link "cxButtonEdit"
#pragma link "cxDropDownEdit"
#pragma link "cxGraphics"
#pragma link "cxPC"
#pragma link "cxSSheet"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxStyles"
#pragma link "cxGridBandedTableView"
#pragma link "cxCalc"
#pragma link "cxCheckBox"
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBQuery"
#pragma link "cxGroupBox"
#pragma link "cxLookAndFeels"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TFormaImportKKT::TFormaImportKKT(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportKKT::FormCreate(TObject *Sender)
{

FileNamecxButtonEdit->Text="";

}
//---------------------------------------------------------------------------
void __fastcall TFormaImportKKT::FormClose(TObject *Sender,
      TCloseAction &Action)
{

Action=caFree;
}
//---------------------------------------------------------------------------
void TFormaImportKKT::UpdateForm(void)
{


}
//---------------------------------------------------------------------------
void __fastcall TFormaImportKKT::cxButtonCloseClick(TObject *Sender)
{
Close();	
}
//---------------------------------------------------------------------------
void __fastcall TFormaImportKKT::FileNamecxButtonEditPropertiesButtonClick(
      TObject *Sender, int AButtonIndex)
{
  if (OpenDialog1->Execute())
  {
    //NewSheet(OpenDialog->FileName);
	try {
		FileNamecxButtonEdit->Text=OpenDialog1->FileName;
		cxSpreadSheet1->LoadFromFile(OpenDialog1->FileName);
		cxSpreadSheet1->R1C1ReferenceStyle=true;
		}
	catch (Exception &err)
	  {
        Application->ShowException(&err);
		//ActiveMDIChild->Close();
	  }
  }	
}

//---------------------------------------------------------------------------
void TFormaImportKKT::UpdateSetup(void)
{

}
//----------------------------------------------------------------------------
void TFormaImportKKT::SaveSetup(void)
{

}
//----------------------------------------------------------------------------


void __fastcall TFormaImportKKT::cxButtonImportClick(TObject *Sender)
{
if (StartStringcxSpinEdit->Text=="" ||
			StartStringcxSpinEdit->Text=="0")
	{
	ShowMessage("Необходимо задать настройки импорта!");
	return;
	}


int number_string_excel=StrToInt(StartStringcxSpinEdit->Text);
int number_con_string_excel=StrToInt(ConStringcxSpinEdit->Text);

//родительская группа
int num_name_grp=StrToInt(NameOwnerGrpcxSpinEdit->Text);
AnsiString name_grp="";

//наименование
int num_name=StrToInt(NameKKTcxSpinEdit->Text);
AnsiString name="";  

int num_name_klient=StrToInt(NumKlientcxSpinEdit->Text);
AnsiString name_klient="";

int num_model=StrToInt(ModelcxSpinEdit->Text);
AnsiString model="";

int num_mesto_ust=StrToInt(MestoUstcxSpinEdit->Text);
AnsiString mesto_ust="";

int num_sav_num=StrToInt(SavNumcxSpinEdit->Text);
AnsiString sav_num="";

int num_reg_num=StrToInt(RegNumcxSpinEdit->Text);
AnsiString reg_num="";

int num_svk_gr=StrToInt(SvkGRcxSpinEdit->Text);
AnsiString svk_gr="";

int num_svk_co=StrToInt(SvkSOcxSpinEdit->Text);
AnsiString svk_so="";

int num_data_vip=StrToInt(DataVipcxSpinEdit->Text);
AnsiString data_vip="";

int num_vvod=StrToInt(VvodcxSpinEdit->Text);
AnsiString vvod="";

int num_num_dogovor=StrToInt(NumDogovorcxSpinEdit->Text);
AnsiString num_dogovor="";

int num_date_dogovor=StrToInt(DateDogovorcxSpinEdit->Text);
AnsiString date_dogovor="";

int num_price_dogovor=StrToInt(PriceDogovorcxSpinEdit->Text);
AnsiString price_dogovor="";

int num_eklz_sav_num=StrToInt(EKLZSavNumcxSpinEdit->Text);
AnsiString eklz_sav_num="";

int num_eklz_reg_num=StrToInt(EKLZRegNumcxSpinEdit->Text);
AnsiString eklz_reg_num="";

int num_eklz_act=StrToInt(EKLZDateActcxSpinEdit->Text);
AnsiString eklz_act="";

int num_num_pasp=StrToInt(NumPaspcxSpinEdit->Text);
AnsiString num_pasp="";

int num_num_ver=StrToInt(NumVercxSpinEdit->Text);
AnsiString num_ver="";

int num_num_pu=StrToInt(NumPUcxSpinEdit->Text);
AnsiString num_pu="";

int num_num_sp=StrToInt(NumSPcxSpinEdit->Text);
AnsiString num_sp="";

int num_num_po_sp=StrToInt(NumPOSPcxSpinEdit->Text);
AnsiString num_po_sp="";

int num_num_fp=StrToInt(NumFPcxSpinEdit->Text);
AnsiString num_fp="";

int num_num_po_fp=StrToInt(NumPOFPcxSpinEdit->Text);
AnsiString num_po_fp="";

int num_num_do=StrToInt(numDOcxSpinEdit->Text);
AnsiString num_do="";

int num_num_po_do=StrToInt(NumPODOcxSpinEdit->Text);
AnsiString num_po_do="";

int num_num_ppp=StrToInt(NumPPPcxSpinEdit->Text);
AnsiString num_ppp="";

int num_sved=StrToInt(SvedODorcxSpinEdit->Text);
AnsiString sved="";

int num_prim=StrToInt(PrimcxSpinEdit->Text);
AnsiString prim="";



TcxSSCellObject *cell;
bool error=false;

while(number_string_excel<=number_con_string_excel)
	{
	try
		{
		//родительская группа
		if (num_name_grp!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_grp-1,number_string_excel-1);
			name_grp=Trim(cell->Text);
			delete cell;
			}
		else {name_grp="";}

		//наименование
		if (num_name!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_klient-1,number_string_excel-1);
			name=Trim(cell->Text);
			delete cell;
			}
		else {name_klient="";}


		if (num_name_klient!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_name_klient-1,number_string_excel-1);
			name_klient=Trim(cell->Text);
			delete cell;
			}
		else {name_klient="";}


		if (num_mesto_ust!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_mesto_ust-1,number_string_excel-1);
			mesto_ust=Trim(cell->Text);
			delete cell;
			}
		else {mesto_ust="";}


		if (num_model!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_model-1,number_string_excel-1);
			model=Trim(cell->Text);
			delete cell;
			}
		else {model="";}

		if (num_sav_num!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_sav_num-1,number_string_excel-1);
			sav_num=Trim(cell->Text);
			delete cell;
			}
		else {sav_num="";}

		if (num_reg_num!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_reg_num-1,number_string_excel-1);
			reg_num=Trim(cell->Text);
			delete cell;
			}
		else {reg_num="";}

		if (num_svk_gr!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_svk_gr-1,number_string_excel-1);
			svk_gr=Trim(cell->Text);
			delete cell;
			}
		else {svk_gr="";}

		if (num_svk_co!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_svk_co-1,number_string_excel-1);
			svk_so=Trim(cell->Text);
			delete cell;
			}
		else {svk_so="";}

		if (num_data_vip!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_data_vip-1,number_string_excel-1);
			data_vip=Trim(cell->Text);
			delete cell;
			}
		else {data_vip="";}

		if (num_vvod!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_vvod-1,number_string_excel-1);
			vvod=Trim(cell->Text);
			delete cell;
			}
		else {vvod="";}

		if (num_num_dogovor!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_num_dogovor-1,number_string_excel-1);
			num_dogovor=Trim(cell->Text);
			delete cell;
			}
		else {num_dogovor="";}

		if (num_date_dogovor!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_date_dogovor-1,number_string_excel-1);
			date_dogovor=Trim(cell->Text);
			delete cell;
			}
		else {date_dogovor="";}

		if (num_price_dogovor!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_price_dogovor-1,number_string_excel-1);
			price_dogovor=Trim(cell->Text);
			delete cell;
			}
		else {price_dogovor="";}

		if (num_eklz_sav_num!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_eklz_sav_num-1,number_string_excel-1);
			eklz_sav_num=Trim(cell->Text);
			delete cell;
			}
		else {eklz_sav_num="";}

		if (num_eklz_reg_num!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_eklz_reg_num-1,number_string_excel-1);
			eklz_reg_num=Trim(cell->Text);
			delete cell;
			}
		else {eklz_reg_num="";}

		if (num_eklz_act!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_eklz_act-1,number_string_excel-1);
			eklz_act=Trim(cell->Text);
			delete cell;
			}
		else {eklz_act="";}

		if (num_num_pasp!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_num_pasp-1,number_string_excel-1);
			num_pasp=Trim(cell->Text);
			delete cell;
			}
		else {num_pasp="";}

		if (num_num_ver!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_num_ver-1,number_string_excel-1);
			num_ver=Trim(cell->Text);
			delete cell;
			}
		else {num_ver="";}

		if (num_num_pu!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_num_pu-1,number_string_excel-1);
			num_pu=Trim(cell->Text);
			delete cell;
			}
		else {num_pu="";}

		if (num_num_sp!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_num_sp-1,number_string_excel-1);
			num_sp=Trim(cell->Text);
			delete cell;
			}
		else {num_sp="";}

		if (num_num_po_sp!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_num_po_sp-1,number_string_excel-1);
			num_po_sp=Trim(cell->Text);
			delete cell;
			}
		else {num_po_sp="";}

		if (num_num_fp!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_num_fp-1,number_string_excel-1);
			num_fp=Trim(cell->Text);
			delete cell;
			}
		else {num_fp="";}

		if (num_num_po_fp!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_num_po_fp-1,number_string_excel-1);
			num_po_fp=Trim(cell->Text);
			delete cell;
			}
		else {num_po_fp="";}

		if (num_num_do!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_num_do-1,number_string_excel-1);
			num_do=Trim(cell->Text);
			delete cell;
			}
		else {num_do="";}

		if (num_num_po_do!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_num_po_do-1,number_string_excel-1);
			num_po_do=Trim(cell->Text);
			delete cell;
			}
		else {num_po_do="";}

		if (num_num_ppp!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_num_ppp-1,number_string_excel-1);
			num_ppp=Trim(cell->Text);
			delete cell;
			}
		else {num_ppp="";}

		if (num_sved!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_sved-1,number_string_excel-1);
			sved=Trim(cell->Text);
			delete cell;
			}
		else {sved="";}

		if (num_prim!=0)
			{
			cell = cxSpreadSheet1->Sheet->GetCellObject(num_prim-1,number_string_excel-1);
			prim=Trim(cell->Text);
			delete cell;
			}
		else {prim="";}


		__int64 id_grp=0;
		if (name_grp!="")
			{
			QueryOwnerGrp->Close();
			QueryOwnerGrp->ParamByName("PARAM_NAME")->AsString=name_grp;
			QueryOwnerGrp->ExecQuery();
			id_grp=QueryOwnerGrp->FieldByName("ID_REM_SGRPKKT")->AsInt64;
			QueryOwnerGrp->Close();
			}

		__int64 id_klient=0;
		if (name_klient!="")
			{
			QueryKlient->Close();
			QueryKlient->ParamByName("PARAM_NAME")->AsString=name_klient;
			QueryKlient->ExecQuery();
			id_klient=QueryKlient->FieldByName("IDKLIENT")->AsInt64;
			QueryKlient->Close();
			}

		__int64 id_model=0;
		if (model!="")
			{
			QueryModel->Close();
			QueryModel->ParamByName("PARAM_NAME")->AsString=model;
			QueryModel->ExecQuery();
			id_model=QueryModel->FieldByName("ID_REM_SMODEL")->AsInt64;
			QueryModel->Close();
			}


			if(name!="")
				{
				DataSet->Close();
				DataSet->Active=true;
				DataSet->Insert();
				DataSetDv->Close();
				DataSetDv->Active=true;
				DataSetDv->Insert();
				DataSetDvIDKKT_REM_SKKT_DV->AsInt64=DataSetID_REM_SKKT->AsInt64;

				if (id_grp!=0)
					{
					DataSetIDGRP_REM_SKKT->AsInt64=id_grp;
					}
				if (id_klient!=0)
					{
					DataSetIDKLIENT_REM_SKKT->AsInt64=id_klient;
					DataSetDvIDKLIENT_REM_SKKT_DV->AsInt64=id_klient;
					}
				if (id_model!=0)
					{
					DataSetIDMODEL_REM_SKKT->AsInt64=id_model;
					}


				DataSetNAME_REM_SKKT->AsString=name_klient;
				DataSetMESTOUST_REM_SKKT->AsString=mesto_ust;
				DataSetSERNUM_REM_SKKT->AsString=sav_num;
				DataSetREGNUM_REM_SKKT->AsString=reg_num;
				DataSetCBKGR_REM_SKKT->AsString=svk_gr;
				DataSetCBKCO_REM_SKKT->AsString=svk_so;
				try {DataSetRELEASE_REM_SKKT->AsString=data_vip;} catch(...){}
				try {DataSetVVOD_REM_SKKT->AsDateTime=StrToDateTime(vvod);} catch(...){}
				DataSetNUMCONTRACT_REM_SKKT->AsString=num_dogovor;
				try {DataSetDATECONTRACT_REM_SKKT->AsDateTime=StrToDateTime(date_dogovor);} catch(...){}
				try {DataSetSUMCONTRACT_REM_SKKT->AsString=price_dogovor;} catch(...){}
				DataSetEKLZ_SERNUM_REM_SKKT->AsString=eklz_sav_num;
				DataSetEKLZ_REGNUM_REM_SKKT->AsString=eklz_reg_num;
				try {DataSetEKLZ_ACT_REM_SKKT->AsDateTime=StrToDateTime(eklz_act);} catch(...){}

				//движения

				DataSetDvMESTOUST_REM_SKKT_DV->AsString=mesto_ust;
				DataSetDvREGNUM_REM_SKKT_DV->AsString=reg_num;
				DataSetDvCBKGR_REM_SKKT_DV->AsString=svk_gr;
				DataSetDvCBKCO_REM_SKKT_DV->AsString=svk_so;
				DataSetDvNUMCONTRACT_REM_SKKT_DV->AsString=num_dogovor;
				try {DataSetDvDATECONTRACT_REM_SKKT_DV->AsDateTime=StrToDateTime(date_dogovor);} catch(...){}
				try {DataSetDvSUMCONTRACT_REM_SKKT_DV->AsString=price_dogovor;} catch(...){}
				DataSetDvEKLZ_SERNUM_REM_SKKT_DV->AsString=eklz_sav_num;
				DataSetDvEKLZ_REGNUM_REM_SKKT_DV->AsString=eklz_reg_num;
				try {DataSetDvEKLZ_ACT_REM_SKKT_DV->AsDateTime=StrToDateTime(eklz_act);} catch(...){}
			
				DataSetPAS_NUMPAS_REM_SKKT->AsString=num_pasp;
				DataSetPAS_NUMVER_REM_SKKT->AsString=num_ver;
				DataSetPAS_NUMPU_REM_SKKT->AsString=num_pu;
				DataSetPAS_NUMSP_REM_SKKT->AsString=num_sp;
				DataSetPAS_NUMSPPO_REM_SKKT->AsString=num_po_sp;
				DataSetPAS_NUMFP_REM_SKKT->AsString=num_fp;
				DataSetPAS_NUMFPPO_REM_SKKT->AsString=num_po_fp;
				DataSetPAS_NUMDO_REM_SKKT->AsString=num_do;
				DataSetPAS_NUMDOPO_REM_SKKT->AsString=num_po_do;
				DataSetPAS_NUMPPP_REM_SKKT->AsString=num_ppp;
				DataSetPAS_DOR_REM_SKKT->AsString=sved;
				DataSetPAS_PRIM_REM_SKKT->AsString=prim;


				try
					{
					DataSet->Post();
					DataSetDv->Post();
					TrUpdate->Commit();
					}
				catch(Exception &exception)
					{
					TrUpdate->Rollback();
					ShowMessage("Ошибка в строке:"+IntToStr(number_string_excel)+" "+exception.Message);
					}
				DataSet->Active=false;
				}
			}
		catch(Exception &exception)
			{
			error=true;
			LabelError->Caption="Ошибка в строке:"+IntToStr(number_string_excel)+" "+exception.Message;
			}

	number_string_excel++;
	}

}
//-------------------------------------------------------------------------


