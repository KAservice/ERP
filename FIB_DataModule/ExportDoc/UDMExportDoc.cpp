//---------------------------------------------------------------------------

#include "vcl.h"
#pragma hdrstop

#include "UDMExportDoc.h"
#include "UGlobalConstant.h"
#include "UGlobalFunction.h"

//#include <fstream.h>
#include "IDMDocCheck.h"
#include "IDMSprEd.h"
#include "IDMSprNom.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"


//---------------------------------------------------------------------------
__fastcall TDMExportDoc::TDMExportDoc(TComponent* Owner)
	: TDataModule(Owner)
{

InterfaceMainObject=0;
InterfaceOwnerObject=0;
DM_Connection=0;
InterfaceGlobalCom=0;

}
//---------------------------------------------------------------------------
void __fastcall TDMExportDoc::DataModuleCreate(TObject *Sender)
{
OutFile=new TkanFile;
}
//---------------------------------------------------------------------------
bool TDMExportDoc::Init(void)
{
bool result=false;

pFIBTr->DefaultDatabase=DM_Connection->pFIBData;

GurAllDoc->Database=DM_Connection->pFIBData;

Check_Doc->Database=DM_Connection->pFIBData;
Check_DocT->Database=DM_Connection->pFIBData;
TableFirm->Database=DM_Connection->pFIBData;
Per_Doc->Database=DM_Connection->pFIBData;
Per_DocT->Database=DM_Connection->pFIBData;
PrihNakl_Doc->Database=DM_Connection->pFIBData;
PrihNakl_DocT->Database=DM_Connection->pFIBData;
VPO_Doc->Database=DM_Connection->pFIBData;
VPO_DocT->Database=DM_Connection->pFIBData;
IsmPrice_Doc->Database=DM_Connection->pFIBData;
IsmPrice_DocT->Database=DM_Connection->pFIBData;
Inv_Doc->Database=DM_Connection->pFIBData;
Inv_DocT->Database=DM_Connection->pFIBData;
Rev_Doc->Database=DM_Connection->pFIBData;
Rev_DocT->Database=DM_Connection->pFIBData;


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
void __fastcall TDMExportDoc::DataModuleDestroy(TObject *Sender)
{
GurAllDoc->Active=true;
delete OutFile;
}
//---------------------------------------------------------------------------
void TDMExportDoc::SaveFileXML(UnicodeString str)
{
OutFile->XML_AddString(FileNameOut, str);
}

//-----------------------------------------------------------------------------
void TDMExportDoc::ExportXMLAllDoc(TDateTime pos_nach, TDateTime pos_con)
{
Num=0;
GurAllDoc->Active=false;
GurAllDoc->ParamByName("PARAM_DATE_NACH")->AsDateTime=pos_nach;
GurAllDoc->ParamByName("PARAM_DATE_CON")->AsDateTime=pos_con;
GurAllDoc->Active=true;

if (GurAllDoc->RecordCount==0)
	{
	return;
	}

FileNameOut=CatalogObmena+"\\AllDoc "+GetTextDataTime(pos_nach)+" "+GetTextDataTime(pos_con)+".xml";
if (FileExists(FileNameOut)==true)
	{  //если файл существует то его удалим
	DeleteFile(FileNameOut);
	}

SaveFileXML("<?xml version=\"1.0\" encoding=\"windows-1251\"?>");
SaveFileXML("<data>");

GurAllDoc->First();
while(!GurAllDoc->Eof)
	{
	//чеки ККМ
	if (GurAllDocTDOC->AsString=="CHK")
		{
		ExportXMLDocCheck(glStrToInt64(GurAllDocIDDOC->AsString));
		}
	//Перемещения
	if (GurAllDocTDOC->AsString=="PER")
		{
		ExportXMLDocPer(glStrToInt64(GurAllDocIDDOC->AsString));
		}
	//Приходные накладные
	if (GurAllDocTDOC->AsString=="PRN")
		{
		ExportXMLDocPrihNakl(glStrToInt64(GurAllDocIDDOC->AsString));
		}
	//Возврат поставщику
	if (GurAllDocTDOC->AsString=="VPO")
		{
		ExportXMLDocVosvratPost(glStrToInt64(GurAllDocIDDOC->AsString));
		}
	//Переоценка
	if (GurAllDocTDOC->AsString=="ISMPRICE")
		{
		ExportXMLDocIsmPrice(glStrToInt64(GurAllDocIDDOC->AsString));
		}

	//инвентаризация
	if (GurAllDocTDOC->AsString=="INV")
		{
		ExportXMLDocInv(glStrToInt64(GurAllDocIDDOC->AsString));
		}
	//	ревизия
	if (GurAllDocTDOC->AsString=="REV")
		{
		ExportXMLDocRev(glStrToInt64(GurAllDocIDDOC->AsString));
		}
	GurAllDoc->Next();
	Num++;
	}

SaveFileXML("</data>");
}
//-----------------------------------------------------------------------------
void TDMExportDoc::ExportXMLDocCheck(__int64 id_doc)
{
//заголовок
////создаем узел документа
String S="  ";
S=S+"<doc" ;
S=S+" TDOC=\"CHK\"";
S=S+" N=\""+IntToStr(Num)+"\""; //
S=S+" IDDOC=\""+OutFile->XML_FormatForXML(GurAllDocIDDOC->AsString)+"\""; //
S=S+" Номер=\""+OutFile->XML_FormatForXML(GurAllDocNUMDOC->AsString)+"\""; //
S=S+" Дата=\""+OutFile->XML_FormatForXML(GurAllDocPOSDOC->AsString)+"\"";
S=S+" Фирма=\""+OutFile->XML_FormatForXML(GurAllDocNAMEFIRM->AsString)+"\"";
S=S+" IDFIRM=\""+OutFile->XML_FormatForXML(GurAllDocIDFIRMDOC->AsString)+"\"";
S=S+" Склад=\""+OutFile->XML_FormatForXML(GurAllDocNAMESKLAD->AsString)+"\"";
S=S+" IDSKLAD=\""+OutFile->XML_FormatForXML(GurAllDocIDSKLDOC->AsString)+"\"";
S=S+" Пок=\""+OutFile->XML_FormatForXML(GurAllDocNAMEKLIENT->AsString)+"\"";
S=S+" СуммаДок=\""+OutFile->XML_FormatForXML(GurAllDocSUMDOC->AsString)+"\"";
//шапка
Check_Doc->Active=false;
Check_Doc->ParamByName("PARAM_ID")->AsString=id_doc;
Check_Doc->Active=true;
S=S+" НомерЧека=\""+OutFile->XML_FormatForXML(Check_DocNCHECKCHK->AsString)+"\""; //
S=S+" КЛ=\""+OutFile->XML_FormatForXML(Check_DocNKLCHK->AsString)+"\"";
S=S+" Опер=\""+OutFile->XML_FormatForXML(Check_DocOPERCHK->AsString)+"\"";
S=S+" Касса=\""+OutFile->XML_FormatForXML(Check_DocNAMEKKM->AsString)+"\"";
S=S+" IDKASSA=\""+OutFile->XML_FormatForXML(Check_DocIDKKM->AsString)+"\"";
S=S+" ТипЦен=\""+OutFile->XML_FormatForXML(Check_DocNAME_TPRICE->AsString)+"\"";
S=S+" IDTPRICE=\""+OutFile->XML_FormatForXML(Check_DocID_TPRICE->AsString)+"\"";
S=S+" Карта=\""+OutFile->XML_FormatForXML(Check_DocNAME_SDISCOUNT_CARD->AsString)+"\"";
S=S+" КодКарты=\""+OutFile->XML_FormatForXML(Check_DocCODE_SDISCOUNT_CARD->AsString)+"\"";
S=S+" ШККарты=\""+OutFile->XML_FormatForXML(Check_DocSHCODE_SDISCOUNT_CARD->AsString)+"\"";
S=S+">";
SaveFileXML(S);

//табличная часть
Check_DocT->Active=false;
Check_DocT->ParamByName("PARAM_ID")->AsString=id_doc;
Check_DocT->Active=true;
Check_DocT->First();
while(!Check_DocT->Eof)
	{
		////создаем узел документа
		S="  ";
		S=S+"<table" ;
		S=S+" Ном=\""+OutFile->XML_FormatForXML(Check_DocTNAMENOM->AsString)+"\""; //
		S=S+" Код=\""+OutFile->XML_FormatForXML(Check_DocTCODENOM->AsString)+"\"";
		S=S+" Кол=\""+OutFile->XML_FormatForXML(Check_DocTKOLCHKT->AsString)+"\"";
		S=S+" КФ=\""+OutFile->XML_FormatForXML(Check_DocTKFCHKT->AsString)+"\"";
		S=S+" Ед=\""+OutFile->XML_FormatForXML(Check_DocTNAMEED->AsString)+"\"";

		S=S+" КодЕд=\""+OutFile->XML_FormatForXML(Check_DocTCODE_SED->AsString)+"\""; //
		S=S+" ШКЕд=\""+OutFile->XML_FormatForXML(Check_DocTSHED->AsString)+"\"";
		S=S+" Цена=\""+OutFile->XML_FormatForXML(Check_DocTPRICECHKT->AsString)+"\"";
		S=S+" Сумма=\""+OutFile->XML_FormatForXML(Check_DocTSUMCHKT->AsString)+"\"";
		S=S+" Скидка=\""+OutFile->XML_FormatForXML(Check_DocTSKCHKT->AsString)+"\"";
		S=S+" ПрСкидки=\""+OutFile->XML_FormatForXML(Check_DocTPRSKCHKT->AsString)+"\"";
		S=S+">";
		SaveFileXML(S);


		S="  ";
		S=S+"</table>";
		SaveFileXML(S);

	Check_DocT->Next();
	}

S="  ";
S=S+"</doc>";
SaveFileXML(S);

Check_DocT->Active=false;
Check_Doc->Active=false;
}
//-----------------------------------------------------------------------------
AnsiString TDMExportDoc::GetTextDataTime(TDateTime pos)
{
AnsiString result="";

unsigned short year,month,day;
pos.DecodeDate (&year,&month,&day);

result=glDopStrL(IntToStr(day),"0",2)
			+glDopStrL(IntToStr(month),"0",2)
			+IntToStr(year);
return result;
}
//------------------------------------------------------------------------------
void TDMExportDoc::ExportXMLSpr(void)
{

FileNameOut=CatalogObmena+"AllSpr.xml";
if (FileExists(FileNameOut)==true)
	{  //если файл существует то его удалим
	DeleteFile(FileNameOut);
	}

SaveFileXML("<?xml version=\"1.0\" encoding=\"windows-1251\"?>");
SaveFileXML("<data>");

OutputSprFirm();
OutputSprSklad();
OutputSprKassa();

SaveFileXML("</data>"); 
}
//-----------------------------------------------------------------------------
void TDMExportDoc::OutputSprFirm(void)
{
//заголовок
////создаем узел документа
String S="  ";
S=S+"<SprFirm" ;
S=S+">";
SaveFileXML(S);

//табличная часть
TableFirm->Active=false;
TableFirm->Active=true;
TableFirm->First();
while(!TableFirm->Eof)
	{
		////создаем узел документа
		S="  ";
		S=S+"<elem" ;
		S=S+" ID=\""+OutFile->XML_FormatForXML(TableFirmIDFIRM->AsString)+"\""; //
		S=S+" Наим=\""+OutFile->XML_FormatForXML(TableFirmNAMEFIRM->AsString)+"\"";
		S=S+">";
		SaveFileXML(S); 

		S="  ";
		S=S+"</elem>";
		SaveFileXML(S);

	TableFirm->Next();
	}

S="  ";
S=S+"</SprFirm>";
SaveFileXML(S);

TableFirm->Active=false;

}
//---------------------------------------------------------------------------
void TDMExportDoc::OutputSprSklad(void)
{
//заголовок
////создаем узел документа
String S="  ";
S=S+"<SprSklad" ;
S=S+">";
SaveFileXML(S);

//табличная часть
TableSklad->Active=false;
TableSklad->Active=true;
TableSklad->First();
while(!TableSklad->Eof)
	{
		////создаем узел документа
		S="  ";
		S=S+"<elem" ;
		S=S+" ID=\""+OutFile->XML_FormatForXML(TableSkladIDSKLAD->AsString)+"\""; //
		S=S+" Наим=\""+OutFile->XML_FormatForXML(TableSkladNAMESKLAD->AsString)+"\"";
		S=S+">";
		SaveFileXML(S); 

		S="  ";
		S=S+"</elem>";
		SaveFileXML(S);

	TableSklad->Next();
	}

S="  ";
S=S+"</SprSklad>";
SaveFileXML(S);

TableSklad->Active=false;


}
//----------------------------------------------------------------------------
void TDMExportDoc::OutputSprKassa(void)
{
//заголовок
////создаем узел документа
String S="  ";
S=S+"<SprKassa" ;
S=S+">";
SaveFileXML(S);

//табличная часть
TableKassa->Active=false;
TableKassa->Active=true;
TableKassa->First();
while(!TableKassa->Eof)
	{
		////создаем узел документа
		S="  ";
		S=S+"<elem" ;
		S=S+" ID=\""+OutFile->XML_FormatForXML(TableKassaIDKKM->AsString)+"\""; //
		S=S+" Наим=\""+OutFile->XML_FormatForXML(TableKassaNAMEKKM->AsString)+"\"";
		S=S+">";
		SaveFileXML(S); 

		S="  ";
		S=S+"</elem>";
		SaveFileXML(S);

	TableKassa->Next();
	}

S="  ";
S=S+"</SprKassa>";
SaveFileXML(S);

TableKassa->Active=false;
}
//-----------------------------------------------------------------------------
void TDMExportDoc::ExportXMLDocPer(__int64 id_doc)
{
//заголовок
////создаем узел документа
String S="  ";
S=S+"<doc" ;
S=S+" TDOC=\"PER\"";
S=S+" N=\""+IntToStr(Num)+"\""; //
S=S+" IDDOC=\""+OutFile->XML_FormatForXML(GurAllDocIDDOC->AsString)+"\""; //
S=S+" Номер=\""+OutFile->XML_FormatForXML(GurAllDocNUMDOC->AsString)+"\""; //
S=S+" Дата=\""+OutFile->XML_FormatForXML(GurAllDocPOSDOC->AsString)+"\"";
S=S+" Фирма=\""+OutFile->XML_FormatForXML(GurAllDocNAMEFIRM->AsString)+"\"";
S=S+" IDFIRM=\""+OutFile->XML_FormatForXML(GurAllDocIDFIRMDOC->AsString)+"\"";
S=S+" Склад=\""+OutFile->XML_FormatForXML(GurAllDocNAMESKLAD->AsString)+"\"";
S=S+" IDSKLAD=\""+OutFile->XML_FormatForXML(GurAllDocIDSKLDOC->AsString)+"\"";
S=S+" Пок=\""+OutFile->XML_FormatForXML(GurAllDocNAMEKLIENT->AsString)+"\"";
S=S+" СуммаДок=\""+OutFile->XML_FormatForXML(GurAllDocSUMDOC->AsString)+"\"";

//шапка
Per_Doc->Active=false;
Per_Doc->ParamByName("PARAM_ID")->AsString=id_doc;
Per_Doc->Active=true;
S=S+" СкладПол=\""+OutFile->XML_FormatForXML(Per_DocNAMESKLAD->AsString)+"\"";
S=S+" IDSKLADPOL=\""+OutFile->XML_FormatForXML(Per_DocIDSKLPOLPER->AsString)+"\"";
S=S+" ТипЦен=\""+OutFile->XML_FormatForXML(Per_DocNAME_TPRICE->AsString)+"\"";
S=S+" IDTPRICE=\""+OutFile->XML_FormatForXML(Per_DocIDRTPRICE_DPER->AsString)+"\"";
S=S+">";
SaveFileXML(S);

//табличная часть
Per_DocT->Active=false;
Per_DocT->ParamByName("PARAM_ID")->AsString=id_doc;
Per_DocT->Active=true;
Per_DocT->First();
while(!Per_DocT->Eof)
	{
		////создаем узел документа
		S="  ";
		S=S+"<table" ;
		S=S+" Ном=\""+OutFile->XML_FormatForXML(Per_DocTNAMENOM->AsString)+"\""; //
		S=S+" Код=\""+OutFile->XML_FormatForXML(Per_DocTCODENOM->AsString)+"\"";
		S=S+" Кол=\""+OutFile->XML_FormatForXML(Per_DocTKOLPERT->AsString)+"\"";
		S=S+" КФ=\""+OutFile->XML_FormatForXML(Per_DocTKFPERT->AsString)+"\"";
		S=S+" Ед=\""+OutFile->XML_FormatForXML(Per_DocTNAMEED->AsString)+"\"";

		S=S+" КодЕд=\""+OutFile->XML_FormatForXML(Per_DocTCODE_SED->AsString)+"\""; //
		S=S+" ШКЕд=\""+OutFile->XML_FormatForXML(Per_DocTSHED->AsString)+"\"";
		S=S+" Цена=\""+OutFile->XML_FormatForXML(Per_DocTPRICEPERT->AsString)+"\"";
		S=S+" Сумма=\""+OutFile->XML_FormatForXML(Per_DocTSUMPERT->AsString)+"\"";
		S=S+">";
		SaveFileXML(S);


		S="  ";
		S=S+"</table>";
		SaveFileXML(S);

	Per_DocT->Next();
	}

S="  ";
S=S+"</doc>";
SaveFileXML(S);

Per_DocT->Active=false;
Per_Doc->Active=false;
}
//-----------------------------------------------------------------------------
void TDMExportDoc::ExportXMLDocPrihNakl(__int64 id_doc)
{
//заголовок
////создаем узел документа
String S="  ";
S=S+"<doc" ;
S=S+" TDOC=\"PRN\"";
S=S+" N=\""+IntToStr(Num)+"\""; //
S=S+" IDDOC=\""+OutFile->XML_FormatForXML(GurAllDocIDDOC->AsString)+"\""; //
S=S+" Номер=\""+OutFile->XML_FormatForXML(GurAllDocNUMDOC->AsString)+"\""; //
S=S+" Дата=\""+OutFile->XML_FormatForXML(GurAllDocPOSDOC->AsString)+"\"";
S=S+" Фирма=\""+OutFile->XML_FormatForXML(GurAllDocNAMEFIRM->AsString)+"\"";
S=S+" IDFIRM=\""+OutFile->XML_FormatForXML(GurAllDocIDFIRMDOC->AsString)+"\"";
S=S+" Склад=\""+OutFile->XML_FormatForXML(GurAllDocNAMESKLAD->AsString)+"\"";
S=S+" IDSKLAD=\""+OutFile->XML_FormatForXML(GurAllDocIDSKLDOC->AsString)+"\"";
S=S+" Пок=\""+OutFile->XML_FormatForXML(GurAllDocNAMEKLIENT->AsString)+"\"";
S=S+" ПокИНН=\""+OutFile->XML_FormatForXML(GurAllDocINNKLIENT->AsString)+"\"";
S=S+" СуммаДок=\""+OutFile->XML_FormatForXML(GurAllDocSUMDOC->AsString)+"\"";

//шапка
PrihNakl_Doc->Active=false;
PrihNakl_Doc->ParamByName("PARAM_ID")->AsString=id_doc;
PrihNakl_Doc->Active=true;
S=S+" ТипЦен=\""+OutFile->XML_FormatForXML(PrihNakl_DocNAME_ZAKTPRICE->AsString)+"\"";
S=S+" IDTPRICE=\""+OutFile->XML_FormatForXML(PrihNakl_DocIDTPRICE->AsString)+"\"";
S=S+" ТипРознЦен=\""+OutFile->XML_FormatForXML(PrihNakl_DocNAME_ROZNTPRICE->AsString)+"\"";
S=S+" IDRTPRICE=\""+OutFile->XML_FormatForXML(PrihNakl_DocIDRTPRICE_DPRN->AsString)+"\"";
S=S+" РознСумма=\""+OutFile->XML_FormatForXML(PrihNakl_DocRSUM_DPRN->AsString)+"\"";
S=S+" НомерДокПост=\""+OutFile->XML_FormatForXML(PrihNakl_DocNUMDOCPOST_DPRN->AsString)+"\"";
S=S+" ПозицияДокПост=\""+OutFile->XML_FormatForXML(PrihNakl_DocPOSDOCPOST_DPRN->AsString)+"\"";
S=S+">";
SaveFileXML(S);

//табличная часть
PrihNakl_DocT->Active=false;
PrihNakl_DocT->ParamByName("PARAM_ID")->AsString=id_doc;
PrihNakl_DocT->Active=true;
PrihNakl_DocT->First();
while(!PrihNakl_DocT->Eof)
	{
		////создаем узел документа
		S="  ";
		S=S+"<table" ;
		S=S+" Ном=\""+OutFile->XML_FormatForXML(PrihNakl_DocTNAMENOM->AsString)+"\""; //
		S=S+" Код=\""+OutFile->XML_FormatForXML(PrihNakl_DocTCODENOM->AsString)+"\"";
		S=S+" Кол=\""+OutFile->XML_FormatForXML(PrihNakl_DocTKOLPRNT->AsString)+"\"";
		S=S+" КФ=\""+OutFile->XML_FormatForXML(PrihNakl_DocTKFPRNT->AsString)+"\"";
		S=S+" Ед=\""+OutFile->XML_FormatForXML(PrihNakl_DocTNAMEED->AsString)+"\"";

		S=S+" КодЕд=\""+OutFile->XML_FormatForXML(PrihNakl_DocTCODE_SED->AsString)+"\""; //
		S=S+" ШКЕд=\""+OutFile->XML_FormatForXML(PrihNakl_DocTSHED->AsString)+"\"";
		S=S+" Цена=\""+OutFile->XML_FormatForXML(PrihNakl_DocTPRICEPRNT->AsString)+"\"";
		S=S+" Сумма=\""+OutFile->XML_FormatForXML(PrihNakl_DocTSUMPRNT->AsString)+"\"";
		S=S+" РознЦена=\""+OutFile->XML_FormatForXML(PrihNakl_DocTRPRICE_DPRNT->AsString)+"\"";
		S=S+" РознСумма=\""+OutFile->XML_FormatForXML(PrihNakl_DocTRSUM_DPRNT->AsString)+"\"";
		S=S+">";
		SaveFileXML(S);


		S="  ";
		S=S+"</table>";
		SaveFileXML(S);

	PrihNakl_DocT->Next();
	}

S="  ";
S=S+"</doc>";
SaveFileXML(S);

PrihNakl_DocT->Active=false;
PrihNakl_Doc->Active=false;
}
//-----------------------------------------------------------------------------
void TDMExportDoc::ExportXMLDocVosvratPost(__int64 id_doc)
{
//заголовок
////создаем узел документа
String S="  ";
S=S+"<doc" ;
S=S+" TDOC=\"VPO\"";
S=S+" N=\""+IntToStr(Num)+"\""; //
S=S+" IDDOC=\""+OutFile->XML_FormatForXML(GurAllDocIDDOC->AsString)+"\""; //
S=S+" Номер=\""+OutFile->XML_FormatForXML(GurAllDocNUMDOC->AsString)+"\""; //
S=S+" Дата=\""+OutFile->XML_FormatForXML(GurAllDocPOSDOC->AsString)+"\"";
S=S+" Фирма=\""+OutFile->XML_FormatForXML(GurAllDocNAMEFIRM->AsString)+"\"";
S=S+" IDFIRM=\""+OutFile->XML_FormatForXML(GurAllDocIDFIRMDOC->AsString)+"\"";
S=S+" Склад=\""+OutFile->XML_FormatForXML(GurAllDocNAMESKLAD->AsString)+"\"";
S=S+" IDSKLAD=\""+OutFile->XML_FormatForXML(GurAllDocIDSKLDOC->AsString)+"\"";
S=S+" Пок=\""+OutFile->XML_FormatForXML(GurAllDocNAMEKLIENT->AsString)+"\"";
S=S+" ПокИНН=\""+OutFile->XML_FormatForXML(GurAllDocINNKLIENT->AsString)+"\"";
S=S+" СуммаДок=\""+OutFile->XML_FormatForXML(GurAllDocSUMDOC->AsString)+"\"";

//шапка
VPO_Doc->Active=false;
VPO_Doc->ParamByName("PARAM_ID")->AsString=id_doc;
VPO_Doc->Active=true;
S=S+" ТипЦен=\""+OutFile->XML_FormatForXML(VPO_DocNAME_ZAKTPRICE->AsString)+"\"";
S=S+" IDTPRICE=\""+OutFile->XML_FormatForXML(VPO_DocIDTPRICE_DVPO->AsString)+"\"";
S=S+" ТипРознЦен=\""+OutFile->XML_FormatForXML(VPO_DocNAME_ROZNTPRICE->AsString)+"\"";
S=S+" IDRTPRICE=\""+OutFile->XML_FormatForXML(VPO_DocIDRTPRICE_DVPO->AsString)+"\"";
S=S+" НомерДокПост=\""+OutFile->XML_FormatForXML(VPO_DocNUMDOCPOST_DVPO->AsString)+"\"";
S=S+" ПозицияДокПост=\""+OutFile->XML_FormatForXML(VPO_DocPOSDOCPOST_DVPO->AsString)+"\"";
S=S+">";
SaveFileXML(S);

//табличная часть
VPO_DocT->Active=false;
VPO_DocT->ParamByName("PARAM_ID")->AsString=id_doc;
VPO_DocT->Active=true;
VPO_DocT->First();
while(!VPO_DocT->Eof)
	{
		////создаем узел документа
		S="  ";
		S=S+"<table" ;
		S=S+" Ном=\""+OutFile->XML_FormatForXML(VPO_DocTNAMENOM->AsString)+"\""; //
		S=S+" Код=\""+OutFile->XML_FormatForXML(VPO_DocTCODENOM->AsString)+"\"";
		S=S+" Кол=\""+OutFile->XML_FormatForXML(VPO_DocTKOLVPOT->AsString)+"\"";
		S=S+" КФ=\""+OutFile->XML_FormatForXML(VPO_DocTKFVPOT->AsString)+"\"";
		S=S+" Ед=\""+OutFile->XML_FormatForXML(VPO_DocTNAMEED->AsString)+"\"";

		S=S+" КодЕд=\""+OutFile->XML_FormatForXML(VPO_DocTCODE_SED->AsString)+"\""; //
		S=S+" ШКЕд=\""+OutFile->XML_FormatForXML(VPO_DocTSHED->AsString)+"\"";
		S=S+" Цена=\""+OutFile->XML_FormatForXML(VPO_DocTPRICEVPOT->AsString)+"\"";
		S=S+" Сумма=\""+OutFile->XML_FormatForXML(VPO_DocTSUMVPOT->AsString)+"\"";
		S=S+" РознЦена=\""+OutFile->XML_FormatForXML(VPO_DocTRPRICE_DVPOT->AsString)+"\"";
		S=S+" РознСумма=\""+OutFile->XML_FormatForXML(VPO_DocTRSUM_DVPOT->AsString)+"\"";
		S=S+">";
		SaveFileXML(S);


		S="  ";
		S=S+"</table>";
		SaveFileXML(S);

	VPO_DocT->Next();
	}

S="  ";
S=S+"</doc>";
SaveFileXML(S);

VPO_DocT->Active=false;
VPO_Doc->Active=false;
}
//-----------------------------------------------------------------------------
void TDMExportDoc::ExportXMLDocIsmPrice(__int64 id_doc)
{
//заголовок
////создаем узел документа
String S="  ";
S=S+"<doc" ;
S=S+" TDOC=\"ISMPRICE\"";
S=S+" N=\""+IntToStr(Num)+"\""; //
S=S+" IDDOC=\""+OutFile->XML_FormatForXML(GurAllDocIDDOC->AsString)+"\""; //
S=S+" Номер=\""+OutFile->XML_FormatForXML(GurAllDocNUMDOC->AsString)+"\""; //
S=S+" Дата=\""+OutFile->XML_FormatForXML(GurAllDocPOSDOC->AsString)+"\"";
S=S+" Фирма=\""+OutFile->XML_FormatForXML(GurAllDocNAMEFIRM->AsString)+"\"";
S=S+" IDFIRM=\""+OutFile->XML_FormatForXML(GurAllDocIDFIRMDOC->AsString)+"\"";
S=S+" Склад=\""+OutFile->XML_FormatForXML(GurAllDocNAMESKLAD->AsString)+"\"";
S=S+" IDSKLAD=\""+OutFile->XML_FormatForXML(GurAllDocIDSKLDOC->AsString)+"\"";
S=S+" Пок=\""+OutFile->XML_FormatForXML(GurAllDocNAMEKLIENT->AsString)+"\"";
S=S+" СуммаДок=\""+OutFile->XML_FormatForXML(GurAllDocSUMDOC->AsString)+"\"";

//шапка
IsmPrice_Doc->Active=false;
IsmPrice_Doc->ParamByName("PARAM_ID")->AsString=id_doc;
IsmPrice_Doc->Active=true;
S=S+" Опис=\""+OutFile->XML_FormatForXML(IsmPrice_DocDESCR_DISMPRICE->AsString)+"\"";
S=S+" СтарТипЦен=\""+OutFile->XML_FormatForXML(IsmPrice_DocNAME_OLDTPRICE->AsString)+"\"";
S=S+" IDOLDTPRICE=\""+OutFile->XML_FormatForXML(IsmPrice_DocIDOLDTPRICE_DISMPRICE->AsString)+"\"";
S=S+" НовТипЦен=\""+OutFile->XML_FormatForXML(IsmPrice_DocNAME_NEWTPRICE->AsString)+"\"";
S=S+" IDNEWTPRICE=\""+OutFile->XML_FormatForXML(IsmPrice_DocIDNEWTPRICE_DISMPRICE->AsString)+"\"";
S=S+">";
SaveFileXML(S);

//табличная часть
IsmPrice_DocT->Active=false;
IsmPrice_DocT->ParamByName("PARAM_ID")->AsString=id_doc;
IsmPrice_DocT->Active=true;
IsmPrice_DocT->First();
while(!IsmPrice_DocT->Eof)
	{
		////создаем узел документа
		S="  ";
		S=S+"<table" ;
		S=S+" Ном=\""+OutFile->XML_FormatForXML(IsmPrice_DocTNAMENOM->AsString)+"\""; //
		S=S+" Код=\""+OutFile->XML_FormatForXML(IsmPrice_DocTCODENOM->AsString)+"\"";
		S=S+" Кол=\""+OutFile->XML_FormatForXML(IsmPrice_DocTKOL_DISMPRICET->AsString)+"\"";
		S=S+" КФ=\""+OutFile->XML_FormatForXML(IsmPrice_DocTKF_DISMPRICET->AsString)+"\"";
		S=S+" Ед=\""+OutFile->XML_FormatForXML(IsmPrice_DocTNAMEED->AsString)+"\"";

		S=S+" КодЕд=\""+OutFile->XML_FormatForXML(IsmPrice_DocTCODE_SED->AsString)+"\""; //
		S=S+" ШКЕд=\""+OutFile->XML_FormatForXML(IsmPrice_DocTSHED->AsString)+"\"";
		S=S+" СтарЦена=\""+OutFile->XML_FormatForXML(IsmPrice_DocTOLDPRICE_DISMPRICET->AsString)+"\"";
		S=S+" НовЦена=\""+OutFile->XML_FormatForXML(IsmPrice_DocTNEWPRICE_DISMPRICET->AsString)+"\"";
		S=S+">";
		SaveFileXML(S);


		S="  ";
		S=S+"</table>";
		SaveFileXML(S);

	IsmPrice_DocT->Next();
	}

S="  ";
S=S+"</doc>";
SaveFileXML(S);

IsmPrice_DocT->Active=false;
IsmPrice_Doc->Active=false;
}
//-----------------------------------------------------------------------------
void TDMExportDoc::ExportXMLDocInv(__int64 id_doc)
{
//заголовок
////создаем узел документа
String S="  ";
S=S+"<doc" ;
S=S+" TDOC=\"INV\"";
S=S+" N=\""+IntToStr(Num)+"\""; //
S=S+" IDDOC=\""+OutFile->XML_FormatForXML(GurAllDocIDDOC->AsString)+"\""; //
S=S+" Номер=\""+OutFile->XML_FormatForXML(GurAllDocNUMDOC->AsString)+"\""; //
S=S+" Дата=\""+OutFile->XML_FormatForXML(GurAllDocPOSDOC->AsString)+"\"";
S=S+" Фирма=\""+OutFile->XML_FormatForXML(GurAllDocNAMEFIRM->AsString)+"\"";
S=S+" IDFIRM=\""+OutFile->XML_FormatForXML(GurAllDocIDFIRMDOC->AsString)+"\"";
S=S+" Склад=\""+OutFile->XML_FormatForXML(GurAllDocNAMESKLAD->AsString)+"\"";
S=S+" IDSKLAD=\""+OutFile->XML_FormatForXML(GurAllDocIDSKLDOC->AsString)+"\"";
S=S+" Пок=\""+OutFile->XML_FormatForXML(GurAllDocNAMEKLIENT->AsString)+"\"";
S=S+" СуммаДок=\""+OutFile->XML_FormatForXML(GurAllDocSUMDOC->AsString)+"\"";

//шапка
Inv_Doc->Active=false;
Inv_Doc->ParamByName("PARAM_ID")->AsString=id_doc;
Inv_Doc->Active=true;
S=S+" ТипЦен=\""+OutFile->XML_FormatForXML(Inv_DocNAME_TPRICE->AsString)+"\"";
S=S+" IDTPRICE=\""+OutFile->XML_FormatForXML(Inv_DocIDTPRICE_INV->AsString)+"\"";
S=S+" Примечание=\""+OutFile->XML_FormatForXML(Inv_DocPRIM_INV->AsString)+"\"";
S=S+" ТипИнвентаризации=\""+OutFile->XML_FormatForXML(Inv_DocTYPE_INV->AsString)+"\"";
S=S+" Инвентаризация=\""+OutFile->XML_FormatForXML(Inv_DocNAME_SINV->AsString)+"\"";
S=S+">";
SaveFileXML(S);

//табличная часть
Inv_DocT->Active=false;
Inv_DocT->ParamByName("PARAM_ID")->AsString=id_doc;
Inv_DocT->Active=true;
Inv_DocT->First();
while(!Inv_DocT->Eof)
	{
		////создаем узел документа
		S="  ";
		S=S+"<table" ;
		S=S+" Ном=\""+OutFile->XML_FormatForXML(Inv_DocTNAMENOM->AsString)+"\""; //
		S=S+" Код=\""+OutFile->XML_FormatForXML(Inv_DocTCODENOM->AsString)+"\"";
		S=S+" КолУч=\""+OutFile->XML_FormatForXML(Inv_DocTKOLUCH_INVT->AsString)+"\"";
		S=S+" КолФакт=\""+OutFile->XML_FormatForXML(Inv_DocTKOLFAKT_INVT->AsString)+"\"";
		S=S+" КФ=\""+OutFile->XML_FormatForXML(Inv_DocTKF_INVT->AsString)+"\"";
		S=S+" Ед=\""+OutFile->XML_FormatForXML(Inv_DocTNAMEED->AsString)+"\"";

		S=S+" КодЕд=\""+OutFile->XML_FormatForXML(Inv_DocTCODE_SED->AsString)+"\""; //
		S=S+" ШКЕд=\""+OutFile->XML_FormatForXML(Inv_DocTSHED->AsString)+"\"";
		S=S+" Цена=\""+OutFile->XML_FormatForXML(Inv_DocTPRICE_INVT->AsString)+"\"";
		S=S+" Сумма=\""+OutFile->XML_FormatForXML(Inv_DocTSUMF_INVT->AsString)+"\"";
		S=S+">";
		SaveFileXML(S);


		S="  ";
		S=S+"</table>";
		SaveFileXML(S);

	Inv_DocT->Next();
	}

S="  ";
S=S+"</doc>";
SaveFileXML(S);

Inv_DocT->Active=false;
Inv_Doc->Active=false;
}
//-----------------------------------------------------------------------------
void TDMExportDoc::ExportXMLDocRev(__int64 id_doc)
{
//заголовок
////создаем узел документа
String S="  ";
S=S+"<doc" ;
S=S+" TDOC=\"REV\"";
S=S+" N=\""+IntToStr(Num)+"\""; //
S=S+" IDDOC=\""+OutFile->XML_FormatForXML(GurAllDocIDDOC->AsString)+"\""; //
S=S+" Номер=\""+OutFile->XML_FormatForXML(GurAllDocNUMDOC->AsString)+"\""; //
S=S+" Дата=\""+OutFile->XML_FormatForXML(GurAllDocPOSDOC->AsString)+"\"";
S=S+" Фирма=\""+OutFile->XML_FormatForXML(GurAllDocNAMEFIRM->AsString)+"\"";
S=S+" IDFIRM=\""+OutFile->XML_FormatForXML(GurAllDocIDFIRMDOC->AsString)+"\"";
S=S+" Склад=\""+OutFile->XML_FormatForXML(GurAllDocNAMESKLAD->AsString)+"\"";
S=S+" IDSKLAD=\""+OutFile->XML_FormatForXML(GurAllDocIDSKLDOC->AsString)+"\"";
S=S+" Пок=\""+OutFile->XML_FormatForXML(GurAllDocNAMEKLIENT->AsString)+"\"";
S=S+" СуммаДок=\""+OutFile->XML_FormatForXML(GurAllDocSUMDOC->AsString)+"\"";

//шапка
Rev_Doc->Active=false;
Rev_Doc->ParamByName("PARAM_ID")->AsString=id_doc;
Rev_Doc->Active=true;
S=S+" ТипЦен=\""+OutFile->XML_FormatForXML(Rev_DocNAME_TPRICE->AsString)+"\"";
S=S+" IDTPRICE=\""+OutFile->XML_FormatForXML(Rev_DocIDRTPRICE_DREV->AsString)+"\"";
S=S+" Примечание=\""+OutFile->XML_FormatForXML(Rev_DocDESCR_DREV->AsString)+"\"";
S=S+" Инвентаризация=\""+OutFile->XML_FormatForXML(Rev_DocNAME_SINV->AsString)+"\"";
S=S+">";
SaveFileXML(S);

//табличная часть
Rev_DocT->Active=false;
Rev_DocT->ParamByName("PARAM_ID")->AsString=id_doc;
Rev_DocT->Active=true;
Rev_DocT->First();
while(!Rev_DocT->Eof)
	{
		////создаем узел документа
		S="  ";
		S=S+"<table" ;
		S=S+" Ном=\""+OutFile->XML_FormatForXML(Rev_DocTNAMENOM->AsString)+"\""; //
		S=S+" Код=\""+OutFile->XML_FormatForXML(Rev_DocTCODENOM->AsString)+"\"";
		S=S+" Кол=\""+OutFile->XML_FormatForXML(Rev_DocTKOL_DREVT->AsString)+"\"";
		S=S+" КФ=\""+OutFile->XML_FormatForXML(Rev_DocTKF_DREVT->AsString)+"\"";

		S=S+" Ед=\""+OutFile->XML_FormatForXML(Rev_DocTNAMEED->AsString)+"\"";
		S=S+" КодЕд=\""+OutFile->XML_FormatForXML(Rev_DocTCODE_SED->AsString)+"\""; //
		S=S+" ШКЕд=\""+OutFile->XML_FormatForXML(Rev_DocTSHED->AsString)+"\"";
		S=S+" РознЦена=\""+OutFile->XML_FormatForXML(Rev_DocTRPRICE_DREVT->AsString)+"\"";
		S=S+" РознСумма=\""+OutFile->XML_FormatForXML(Rev_DocTRSUM_DREVT->AsString)+"\"";
		S=S+">";
		SaveFileXML(S);


		S="  ";
		S=S+"</table>";
		SaveFileXML(S);

	Rev_DocT->Next();
	}

S="  ";
S=S+"</doc>";
SaveFileXML(S);

Rev_DocT->Active=false;
Rev_Doc->Active=false;
}
//-----------------------------------------------------------------------------
void TDMExportDoc::ImportDoc(AnsiString file_name)
{
XML->LoadFromFile(file_name);

_di_IXMLNode  xml_base=XML->DocumentElement;

  for (int i=0; i<xml_base->ChildNodes->Count; i++)    //1 уровень типов документов
		{
		_di_IXMLNode xml_doc=xml_base->ChildNodes->Get(i);
		AnsiString type_doc=xml_doc->GetAttribute("TDOC");

		if (type_doc=="CHK")
			{
			ImportDocCHK(xml_doc);
			}  

		}
XML->Active = false;
}
//-----------------------------------------------------------------------------
void TDMExportDoc::ImportDocCHK(_di_IXMLNode  xml_doc)
{

IDMDocCheck *check;
InterfaceGlobalCom->kanCreateObject("Oberon.DMDocCheck.1",IID_IDMDocCheck,
									 (void**)&check);
check->Init(InterfaceMainObject,0);
check->NewDoc();

check->DocAll->Edit();
__int64 id_firm=glStrToInt64(xml_doc->GetAttribute("IDFIRM"));
if(id_firm!=0)
	{
	check->DocAllIDFIRMDOC->AsString=IntToStr(id_firm);
	}

__int64 id_sklad=glStrToInt64(xml_doc->GetAttribute("IDSKLAD"));
if(id_sklad!=0)
	{
	check->DocAllIDSKLDOC->AsString=IntToStr(id_sklad);
	}
if (xml_doc->GetAttribute("Номер")!="")
	{
	check->DocAllNUMDOC->AsInteger=StrToInt(xml_doc->GetAttribute("Номер"));
	}

if (xml_doc->GetAttribute("Дата")!="")
	{
	check->DocAllPOSDOC->AsDateTime=StrToDateTime(xml_doc->GetAttribute("Дата"));
	}

check->DocAll->Post();

check->Doc->Edit();

__int64 id_kassa=glStrToInt64(xml_doc->GetAttribute("IDKASSA"));
if(id_kassa!=0)
	{
	check->DocIDKKMCHK->AsString=IntToStr(id_kassa);
	}

__int64 id_type_price=glStrToInt64(xml_doc->GetAttribute("IDTPRICE"));
if(id_type_price!=0)
	{
	check->DocIDTPRICE->AsString=IntToStr(id_type_price);
	}

if(xml_doc->GetAttribute("Опер")!="")
	{
	check->DocOPERCHK->AsInteger=StrToInt(xml_doc->GetAttribute("Опер"));
	}

check->DocPRIMCHK->AsString="Восстановлено из файла";
check->Doc->Post();

for (int i=0; i<xml_doc->ChildNodes->Count; i++)    //1 уровень типов документов
	{
	_di_IXMLNode xml_table=xml_doc->ChildNodes->Get(i);

	int code_ed=0;
	if (xml_table->GetAttribute("КодЕд")!="")
		{
		IDMSprEd *ed;
		InterfaceGlobalCom->kanCreateObject("Oberon.DMSprEd.1",IID_IDMSprEd,
									 (void**)&ed);
		ed->Init(InterfaceMainObject,0);
		code_ed=StrToInt(xml_table->GetAttribute("КодЕд"));
		__int64 id_ed=ed->FindEdPoCodu(code_ed);
		if (id_ed>0)
			{
			ed->OpenElement(id_ed);
			check->AddDocNewString();
			check->DocT->Edit();
			check->DocTIDNOMCHKT->AsString=ed->ElementIDNOMED->AsString;
            check->DocTIDEDCHKT->AsString=ed->ElementIDED->AsString;
			check->DocTKOLCHKT->AsFloat=StrToFloat(xml_table->GetAttribute("Кол"));
			check->DocTKFCHKT->AsFloat=StrToFloat(xml_table->GetAttribute("КФ"));
			check->DocTPRICECHKT->AsFloat=StrToFloat(xml_table->GetAttribute("Цена"));
			check->DocTSKCHKT->AsFloat=StrToFloat(xml_table->GetAttribute("Скидка"));
            check->DocT->Post();
			}
		ed->kanRelease();
		}
	}

if(check->SaveDoc()==false)
	{
	ShowMessage("Ошибка при записи чека №"+xml_doc->GetAttribute("Номер")+"  "+check->TextError); 
	}

check->kanRelease();
}
//----------------------------------------------------------------------------
