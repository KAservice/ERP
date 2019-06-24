//---------------------------------------------------------------------------
#include "vcl.h"
#pragma hdrstop

#include "UDMSetup.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"
#include "IConnectionInterface.h"
#include "IMainInterface.h"
#include "IMainCOMInterface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDMSetup::TDMSetup(TComponent* Owner)
        : TDataModule(Owner)
{
FunctionDeleteImpl=0;
flDeleteImpl=true;
InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;
}
//--------------------------------------------------------------------------
void __fastcall TDMSetup::DataModuleCreate(TObject *Sender)
{
ExecPriv=true;
InsertPriv=true;
EditPriv=true;
DeletePriv=true;
}
//--------------------------------------------------------------------------
bool TDMSetup::Init(void)
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

IBTr->DefaultDatabase=DM_Connection->pFIBData;
IBTrUpdate->DefaultDatabase=DM_Connection->pFIBData;

Table->Database=DM_Connection->pFIBData;
Element->Database=DM_Connection->pFIBData;
pFIBQKolPrDoc->Database=DM_Connection->pFIBData;

DM_Connection->GetPrivDM(GCPRIV_DM_Setup);
ExecPriv=DM_Connection->ExecPriv;
InsertPriv=DM_Connection->InsertPriv;
EditPriv=DM_Connection->EditPriv;
DeletePriv=DM_Connection->DeletePriv;
result=true;

return result;
}

//---------------------------------------------------------------------------
int TDMSetup::Done(void)
{

return -1;
}
//---------------------------------------------------------------------------
void __fastcall TDMSetup::DataModuleDestroy(TObject *Sender)
{
Table->Active=false;
Element->Active=false;
if (flDeleteImpl==true)
	{
	if (FunctionDeleteImpl) FunctionDeleteImpl();
	}
}

//---------------------------------------------------------------------------

void  TDMSetup::OpenTable(void)
{

Table->Active=false;
Table->Open();
}

//---------------------------------------------------------------------------

void  TDMSetup::SaveIsmen()
{
try
        {
        Table->ApplyUpdates();
		IBTrUpdate->Commit();
        OpenTable();
        }
        catch(Exception &exception)
				{
			   //	IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------

void  TDMSetup::CancelIsmen()
{
try
        {
        Table->CancelUpdates();
		//IBTrUpdate->Commit();
        OpenTable();
        }
		catch(Exception &exception)
				{
				//IBTrUpdate->Rollback();
				Error=true;
				TextError=exception.Message;
				}
}
//---------------------------------------------------------------------------

void  TDMSetup::NewElement()
{
Element->Active=false;
Element->Open();
Element->Insert();

}
//---------------------------------------------------------------------------

int TDMSetup::OpenElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;
int Res=0;
Res=Element->RecordCount;
return Res;
}
//---------------------------------------------------------------------------

void  TDMSetup::SaveElement()
{
try
        {
        Element->ApplyUpdates();
		IBTrUpdate->Commit();
        }
catch(...)
        {
        Error=true;
        TextError="Не удалось записать элемент!";
        }
}
//---------------------------------------------------------------------------
void TDMSetup::DeleteElement(__int64 Id)
{
Element->Active=false;
Element->ParamByName("PARAM_ID")->AsInt64=Id;
Element->Active=true;
if (Element->RecordCount==1)
        {
        Element->Delete();
        try
                {
                Element->ApplyUpdates();
				IBTrUpdate->Commit();
                }
        catch(...)
                {
                Error=true;
                TextError="Не удалось удалить элемент!";
                }
        }
}

//---------------------------------------------------------------------------
void TDMSetup::ProveritPosled(TDateTime  posDoc)
{
try
        {
        int kol_prov_doc=GetKolProvDoc(posDoc);

        if (kol_prov_doc>0)
                {  //нарушена последовательность проведения документов
                OpenElement(15);
                //ShowMessage( "/"+ElementVALUE_SETUP->AsString+"/");
				if (ElementVALUE_TIMESTAMP_SETUP->AsString=="")
						{

                                Element->Edit();
								ElementVALUE_TIMESTAMP_SETUP->AsDateTime=posDoc;
                                Element->Post();
                                SaveElement();
                        }
                else
                        {
						if (posDoc < ElementVALUE_TIMESTAMP_SETUP->AsDateTime)
                                {
                                Element->Edit();
								ElementVALUE_TIMESTAMP_SETUP->AsDateTime=posDoc;
                                Element->Post();
                                SaveElement();

                                }
                        }
                Element->Active=false;
                }
        }
catch(...)
        {
        }

}
//-----------------------------------------------------------------------------
int  TDMSetup::GetKolProvDoc( TDateTime  posDoc)
{
int result=0;

try {
		UnicodeString zapros="select count(IDDOC) AS KOLPRDOC   from GALLDOC";
		zapros=zapros+" where  (PRDOC>0)  AND  (POSDOC-CAST('"+DateTimeToStr(posDoc)+"' AS TIMESTAMP)>0.0001)";
		zapros=zapros+" AND (TDOC in ("+glGetStringFullTypeDoc()+" )) ";
//		pFIBQKolPrDoc->ParamByName("PARAM_POSDOC")->AsDateTime=posDoc;
//		pFIBQKolPrDoc->ParamByName("PARAM_TYPEDOC")->AsString=glStringFullTypeDoc;
		pFIBQKolPrDoc->SQL->Clear();
		pFIBQKolPrDoc->SQL->Add(zapros);
		pFIBQKolPrDoc->ExecQuery();
		result=pFIBQKolPrDoc->FieldByName("KOLPRDOC")->AsInteger;
		pFIBQKolPrDoc->Close();
	}
catch(...)
	{

	}


return result;
}
//-----------------------------------------------------------------------------

bool TDMSetup::ProveritPosZapretaRed( TDateTime  posDoc)
{
bool prosmotr=false;
OpenElement(13);
AnsiString str_date=ElementVALUE_TIMESTAMP_SETUP->AsString;
if (ElementVALUE_TIMESTAMP_SETUP->AsDateTime > (Now()-10000) )
		{ //позиция запрета задана
        try
				{
				if (posDoc <= ElementVALUE_TIMESTAMP_SETUP->AsDateTime)
                        {
						prosmotr=true;
                        }
                }
        catch(...){}
        }

return prosmotr;
}
 //--------------------------------------------------------------------------


//---------------------------------------------------------------------------
void TDMSetup::ProveritPosledHotel(TDateTime  posDoc)
{
//try
//        {
//		int kol_prov_doc=GetKolProvDocHotel(posDoc);
//
//        if (kol_prov_doc>0)
//                {  //нарушена последовательность проведения документов
//				OpenElement(104);
//                //ShowMessage( "/"+ElementVALUE_SETUP->AsString+"/");
//                if (ElementVALUE_SETUP->AsString=="")
//                        {
//
//                                Element->Edit();
//                                ElementVALUE_SETUP->AsString=DateTimeToStr(posDoc);
//                                Element->Post();
//                                SaveElement();
//                        }
//                else
//                        {
//						if (posDoc < ElementVALUE_SETUP->AsDateTime)
//                                {
//                                Element->Edit();
//                                ElementVALUE_SETUP->AsString=DateTimeToStr(posDoc);
//                                Element->Post();
//								SaveElement();
//
//                                }
//                        }
//                Element->Active=false;
//                }
//        }
//catch(...)
//        {
//        }

}
//-----------------------------------------------------------------------------
int  TDMSetup::GetKolProvDocHotel( TDateTime  posDoc)
{
int result=0;

try {
		AnsiString zapros="select count(ID_HOT_GALLDOC) AS KOLPRDOC   from HOT_GALLDOC";
		zapros=zapros+" where  (PR_HOT_GALLDOC>0)  AND  (POS_HOT_GALLDOC-CAST('"+DateTimeToStr(posDoc)+"' AS TIMESTAMP)>0.0001)";
//		pFIBQKolPrDoc->ParamByName("PARAM_POSDOC")->AsDateTime=posDoc;
//		pFIBQKolPrDoc->ParamByName("PARAM_TYPEDOC")->AsString=glStringFullTypeDoc;
		pFIBQKolPrDoc->SQL->Clear();
		pFIBQKolPrDoc->SQL->Add(zapros);
		pFIBQKolPrDoc->ExecQuery();
		result=pFIBQKolPrDoc->FieldByName("KOLPRDOC")->AsInteger;
		pFIBQKolPrDoc->Close();
	}
catch(...)
	{

	}


return result;
}
//-----------------------------------------------------------------------------

bool TDMSetup::ProveritPosZapretaRedHotel( TDateTime  posDoc)
{
bool result=false;
OpenElement(105);
AnsiString str_date=ElementVALUE_SETUP->AsString;
if (str_date!="" )
        {
        try
                {
                TDateTime PosZapretaRedakt=StrToDateTime(ElementVALUE_SETUP->AsString);
                if (posDoc<=PosZapretaRedakt)
                        {
                        result=true;
                        }
                }
        catch(...){}
        }

return result;
}
//----------------------------------------------------------------------------

void TDMSetup::ProveritPosledRemont(TDateTime  posDoc)
{
try
        {
		int kol_prov_doc=GetKolProvDocRemont(posDoc);

        if (kol_prov_doc>0)
                {  //нарушена последовательность проведения документов
				OpenElement(315);
                //ShowMessage( "/"+ElementVALUE_SETUP->AsString+"/");
				if (ElementVALUE_TIMESTAMP_SETUP->AsString=="")
						{

                                Element->Edit();
								ElementVALUE_TIMESTAMP_SETUP->AsDateTime=posDoc;
                                Element->Post();
                                SaveElement();
                        }
                else
                        {
						if (posDoc < ElementVALUE_TIMESTAMP_SETUP->AsDateTime)
                                {
                                Element->Edit();
								ElementVALUE_TIMESTAMP_SETUP->AsDateTime=posDoc;
                                Element->Post();
                                SaveElement();

                                }
                        }
                Element->Active=false;
                }
        }
catch(...)
        {
        }

}
//-----------------------------------------------------------------------------
int  TDMSetup::GetKolProvDocRemont( TDateTime  posDoc)
{
int result=0;

try {
		AnsiString zapros="select count(ID_REM_GALLDOC) AS KOLPRDOC   from REM_GALLDOC";
		zapros=zapros+" where  (PR_REM_GALLDOC>0)  AND  (POS_REM_GALLDOC-CAST('"+DateTimeToStr(posDoc)+"' AS TIMESTAMP)>0.0001)";
		pFIBQKolPrDoc->SQL->Clear();
		pFIBQKolPrDoc->SQL->Add(zapros);
		pFIBQKolPrDoc->ExecQuery();
		result=pFIBQKolPrDoc->FieldByName("KOLPRDOC")->AsInteger;
		pFIBQKolPrDoc->Close();
	}
catch(...)
	{

	}


return result;
}
//-----------------------------------------------------------------------------

bool TDMSetup::ProveritPosZapretaRedRemont( TDateTime  posDoc)
{
bool prosmotr=false;
OpenElement(313);
AnsiString str_date=ElementVALUE_TIMESTAMP_SETUP->AsString;
if (ElementVALUE_TIMESTAMP_SETUP->AsDateTime > (Now()-10000) )
		{ //позиция запрета задана
        try
				{
				if (posDoc <= ElementVALUE_TIMESTAMP_SETUP->AsDateTime)
                        {
						prosmotr=true;
                        }
                }
        catch(...){}
        }

return prosmotr;
}
//--------------------------------------------------------------------------


void __fastcall TDMSetup::TableTYPE_VALUE_SETUPGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
if (TableTYPE_VALUE_SETUP->AsInteger==0)
		{
		Text="Не задан";
		}
if (TableTYPE_VALUE_SETUP->AsInteger==1)
		{
		Text="Строка";
		}
if (TableTYPE_VALUE_SETUP->AsInteger==2)
		{
		Text="Позиция дата/время";
		}
}
//---------------------------------------------------------------------------

void __fastcall TDMSetup::TableTYPE_VALUE_SETUPSetText(TField *Sender, const UnicodeString Text)

{
if(Text=="Не задан")
		{
		TableTYPE_VALUE_SETUP->AsInteger=0;
		}
if(Text=="Строка")
		{
		TableTYPE_VALUE_SETUP->AsInteger=1;
		}
if(Text=="Позиция дата/время")
		{
		TableTYPE_VALUE_SETUP->AsInteger=2;
		}
}
//---------------------------------------------------------------------------

