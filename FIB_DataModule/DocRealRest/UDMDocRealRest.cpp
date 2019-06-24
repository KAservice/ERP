//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMDocRealRest.h"
#include "UDM.h"
#include "UDMSprUser.h"
#include "UDMSprNom.h"
#include "UDMSprEd.h"
#include "UDMSprSostProd.h"
#include "UDMSprNomRest.h"
#include "UDMSetup.h"
#include "UDMQueryRead.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"
extern TDMSprUser * glUser;
extern String gl_prefiks_ib;
//---------------------------------------------------------------------------
__fastcall TDMDocRealRest::TDMDocRealRest(TComponent* Owner)
        : TDataModule(Owner)
{
}
//----------------------------------------------------------------------
void __fastcall TDMDocRealRest::DataModuleCreate(TObject *Sender)
{
SummaDoc=0;
OldSummaStr=0;
NewSummaStr=0;
EnableDvReg=false;

DMRegOstNom=new TDMRegOstNom(Application);
DMRegOstNom->DvRegOst->Transaction=IBTrDvReg;
DMRegOstNom->DvRegOst->UpdateTransaction=IBTrDvReg;
DMRegOstNom->RegOst->Transaction=IBTrDvReg;
DMRegOstNom->RegOst->UpdateTransaction=IBTrDvReg;

DMRegGoods=new TDMRegGoods(Application);
DMRegGoods->DvRegOst->Transaction=IBTrDvReg;
DMRegGoods->DvRegOst->UpdateTransaction=IBTrDvReg;
DMRegGoods->RegOst->Transaction=IBTrDvReg;
DMRegGoods->RegOst->UpdateTransaction=IBTrDvReg;

DMRegOtrSpisNom=new TDMRegOtrSpisNom(Application);
DMRegOtrSpisNom->DvRegOst->Transaction=IBTrDvReg;
DMRegOtrSpisNom->DvRegOst->UpdateTransaction=IBTrDvReg;

DMRegReal=new TDMRegReal(Application);
DMRegReal->DvRegOst->Transaction=IBTrDvReg;
DMRegReal->DvRegOst->UpdateTransaction=IBTrDvReg;

DMRegSebProd=new TDMRegSebProd(Application);
DMRegSebProd->DvRegOst->Transaction=IBTrDvReg;
DMRegSebProd->DvRegOst->UpdateTransaction=IBTrDvReg;

DMRegVipuskProd=new TDMRegVipuskProd(Application);
DMRegVipuskProd->DvRegOst->Transaction=IBTrDvReg;
DMRegVipuskProd->DvRegOst->UpdateTransaction=IBTrDvReg;

DMRegVsRasch=new TDMRegVsRasch(Application);
DMRegVsRasch->DvRegOst->Transaction=IBTrDvReg;
DMRegVsRasch->DvRegOst->UpdateTransaction=IBTrDvReg;
DMRegVsRasch->RegOst->Transaction=IBTrDvReg;
DMRegVsRasch->RegOst->UpdateTransaction=IBTrDvReg;
}
//----------------------------------------------------------------------------
void __fastcall TDMDocRealRest::DataModuleDestroy(TObject *Sender)
{
DocAll->Close();
Doc->Close();
DocT->Close();
NumDoc->Close();
Firma->Close();
Klient->Close();
Sklad->Close();
Doc2->Active=false;
TablePart->Active=false;

delete DMRegOstNom;
delete DMRegVipuskProd;
delete DMRegSebProd;
delete DMRegOtrSpisNom;
delete DMRegReal;
delete  DMRegVsRasch;
delete DMRegGoods;
}

//----------------------------------------------------------------------------
void TDMDocRealRest::NewDoc(void)
{
        //OpenDoc(0);
        DocAll->Active=false;
        Doc->Active=false;
        DocT->Active=false;
        Firma->Active=false;
        Klient->Active=false;
        Sklad->Active=false;
        SpisokTypePrice->Active=false;
        NumDoc->Active=false;

        DocAll->Open();
        Doc->Open();
        DocAll->Insert();
        Doc->Insert();

		IdDoc=DocAllIDDOC->AsInt64;
		DocIDDOC_REALREST->AsInt64=IdDoc;
        DocAllPOSDOC->AsDateTime=Now();
        DocAllTDOC->AsString="REAL_REST";
		DocAllIDUSERDOC->AsInt64=glUser->ElementID_USER->AsInt64;
        DocAllNAME_USER->AsString=glUser->ElementNAME_USER->AsString;
		DocAllIDBASE_GALLDOC->AsInt64=glUser->ElementIDBASE_SUSER->AsInt64;
        DocAllNAME_SINFBASE_OBMEN->AsString=glUser->ElementNAME_SINFBASE_OBMEN->AsString;
        //получим номер документа
        NumDoc->Active=false;
        NumDoc->Open();
        DocAllNUMDOC->AsInteger=
                NumDocMAXNUMBER->AsInteger+1;

		DocIDTPRICE_REALREST->AsInt64=IdTypePrice=glUser->ElementIDTPRICE_USER->AsInt64;
        DocAll->Post();
        Doc->Post();
		DocT->ParamByName("ID")->AsInt64=IdDoc;
        DocT->ParamByName("PARAM_ID_TYPE_PRICE")->AsInteger=DocIDTPRICE_REALREST->AsInt64;
        DocT->Open();
}
//----------------------------------------------------------------------------
void TDMDocRealRest::OpenDoc(__int64 Id)
{

        DocAll->Active=false;
        Doc->Active=false;
        DocT->Active=false;
        Firma->Active=false;
        Klient->Active=false;
        Sklad->Active=false;

		DocAll->ParamByName("ID")->AsInt64=Id;
		Doc->ParamByName("ID")->AsInt64=Id;

        DocAll->Open();
        Doc->Open();
		DocT->ParamByName("ID")->AsInt64=Id;
		DocT->ParamByName("PARAM_ID_TYPE_PRICE")->AsInt64=DocIDTPRICE_REALREST->AsInt64;
        DocT->Open();

		Firma->ParamByName("ID")->AsInt64=DocAllIDFIRMDOC->AsInt64;
		Sklad->ParamByName("ID")->AsInt64=DocAllIDSKLDOC->AsInt64;
		Klient->ParamByName("ID")->AsInt64=DocAllIDKLDOC->AsInt64;


        Firma->Open();
        Sklad->Open();
        Klient->Open();

TDMSetup * DMSetup=new TDMSetup(Application);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
delete DMSetup;

DocAllIDBASE_GALLDOC->ReadOnly=true;
}

//----------------------------------------------------------------------------
void TDMDocRealRest::CloseDoc(void)
{
        DocAll->CancelUpdates();
        Doc->CancelUpdates();
        DocT->CancelUpdates();


        DocAll->Active=false;
        Doc->Active=false;
        DocT->Active=false;
        Firma->Active=false;
        Klient->Active=false;
        Sklad->Active=false;
        NumDoc->Active=false;

}
//----------------------------------------------------------------------------
bool TDMDocRealRest::SaveDoc(void)
{

bool Res=false;
TDMSetup * DMSetup=new TDMSetup(Application);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
delete DMSetup;

if (Prosmotr==true)
        {
        Error=true;
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return Res;
		}
if (glUser->ElementID_USER->AsString!=DocAllIDUSERDOC->AsString)
	{
	if (glUser->ElementEDIT_CHUG_DOC_SUSER->AsInteger!=1)
		{
		Error=true;
		TextError="Нельзя редактировать чужие документы!";
		return Res;
		}
	}

DocAll->Edit();
DocAllSUMDOC->AsFloat=Summa();
DocAll->Post();


try
        {
		IdDoc=DocAllIDDOC->AsInt64;
		DocAll->ApplyUpdToBase();
		Doc->ApplyUpdToBase();
		DocT->ApplyUpdToBase();
		IBTrUpdate->Commit();
		DocAll->CommitUpdToCach();
		Doc->CommitUpdToCach();
		DocT->CommitUpdToCach();

        OpenDoc(IdDoc);
        Res=true;
        }
catch(Exception &exception)
				{
			  	IBTrUpdate->Rollback();
				Res=false;
				TextError=exception.Message;
				Error=true;
				}
return Res;
}
//-----------------------------------------------------------------------------
void TDMDocRealRest::AddDocNewString(void)
{
DocT->Append();

}
//-----------------------------------------------------------------------------
void TDMDocRealRest::DeleteStringDoc(void)
{
DocT->Delete();
}
//-----------------------------------------------------------------------------
double TDMDocRealRest::Summa(void)
{

DataSourceDocT->Enabled=false;
TBookmark BM;
SummaDoc=0;

BM=DocT->GetBookmark();

DocT->First();
while (!DocT->Eof)
        {
        SummaDoc=SummaDoc+DocTSUM_REALRESTT->AsFloat;
        DocT->Next();
        }

DocT->GotoBookmark(BM);
DocT->FreeBookmark(BM);
DataSourceDocT->Enabled=true;

return SummaDoc;
}
//----------------------------------------------------------------------------
bool TDMDocRealRest::DvRegDoc(void)
{
bool Res=false;

if (Prosmotr==true)
        {
        Error=true;
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return Res;
        }

if (EnableDvReg==false)
        {
        try
                {
                TDMSetup * DMSetup=new TDMSetup(Application);
                DMSetup->OpenElement(14);
                if (DMSetup->ElementVALUE_SETUP->AsString=="1")
                        {
                        Res=true;
                        return Res;
                        }
                delete DMSetup;
                }
        catch(...)
                {
                }
        }



if (CancelDvRegDoc()!=true)
        {
        Res=false;
        return Res;
		}

TDMQueryRead *q=new TDMQueryRead(Application);
q->pFIBQ->Close();
q->pFIBQ->SQL->Clear();
q->pFIBQ->SQL->Add("select TSKLAD from SSKLAD where IDSKLAD="+DocAllIDSKLDOC->AsString);
q->pFIBQ->ExecQuery();
if (q->pFIBQ->FieldByName("TSKLAD")->AsInteger==1)
	{
	SkladRozn=true;
	}
else
	{
	SkladRozn=false;
	}
delete q;

//проверим запрет на отрицательные остатки
TDMSetup * DMSetup=new TDMSetup(Application);
DMSetup->OpenElement(12);
NoOtrOstatok=false;
if (DMSetup->ElementVALUE_SETUP->AsString=="1")
	{
	NoOtrOstatok=true;
	}
delete DMSetup;

try
        {

       DocT->First();
        while (!DocT->Eof)
                {
                SebReal=0;
                KolOtrSpisNom=0;
                if (DocTTNOM->AsInteger==0)  //товар
                        {
                        Operation=1;
						IdSklad=DocAllIDSKLDOC->AsInt64;
						SpisatNomSoSklada(DocTIDNOM_REALRESTT->AsInt64,
                                        DocTKOL_REALRESTT->AsFloat*DocTKF_REALRESTT->AsFloat);
                        //движение по регистру реализация
						DMRegReal->IdDoc=DocAllIDDOC->AsInt64;
                        DMRegReal->PosDoc=DocAllPOSDOC->AsDateTime;
						DMRegReal->IdFirm=DocAllIDFIRMDOC->AsInt64;
						DMRegReal->IdSklad=DocAllIDSKLDOC->AsInt64;
						DMRegReal->IdNom=DocTIDNOM_REALRESTT->AsInt64;
                        DMRegReal->SumReal=DocTSUM_REALRESTT->AsFloat;
                        DMRegReal->SebReal=SebReal;
                        DMRegReal->ResReal=DocTSUM_REALRESTT->AsFloat-SebReal;
                        DMRegReal->KolReal=DocTKF_REALRESTT->AsFloat*DocTKOL_REALRESTT->AsFloat;
                        DMRegReal->KolOtrReal=KolOtrSpisNom;
                        DMRegReal->AddReal();
                        }

                if (DocTTNOM->AsInteger==1)  //услуга
                        {
                        Operation=0;
                        IdSklad=DocAllIDSKLDOC->AsInteger;
                        //движение по регистру реализация
						DMRegReal->IdDoc=DocAllIDDOC->AsInt64;
                        DMRegReal->PosDoc=DocAllPOSDOC->AsDateTime;
						DMRegReal->IdFirm=DocAllIDFIRMDOC->AsInt64;
						DMRegReal->IdSklad=DocAllIDSKLDOC->AsInt64;
						DMRegReal->IdNom=DocTIDNOM_REALRESTT->AsInt64;
                        DMRegReal->SumReal=DocTSUM_REALRESTT->AsFloat;
                        DMRegReal->SebReal=0;
                        DMRegReal->ResReal=DocTSUM_REALRESTT->AsFloat;
                        DMRegReal->KolReal=DocTKF_REALRESTT->AsFloat*DocTKOL_REALRESTT->AsFloat;
                        DMRegReal->KolOtrReal=0;
                        DMRegReal->AddReal();
                        }

                if (DocTTNOM->AsInteger==2)  //продукция
                        {
                        Operation=3;
                        IdSklad=DocAllIDSKLDOC->AsInteger;
                        SpisatProdSoSklada();
                        //движение по регистру реализация
						DMRegReal->IdDoc=DocAllIDDOC->AsInt64;
                        DMRegReal->PosDoc=DocAllPOSDOC->AsDateTime;
						DMRegReal->IdFirm=DocAllIDFIRMDOC->AsInt64;
						DMRegReal->IdSklad=DocAllIDSKLDOC->AsInt64;
						DMRegReal->IdNom=DocTIDNOM_REALRESTT->AsInt64;
                        DMRegReal->SumReal=DocTSUM_REALRESTT->AsFloat;
                        DMRegReal->SebReal=SebReal;
                        DMRegReal->ResReal=DocTSUM_REALRESTT->AsFloat-SebReal;
                        DMRegReal->KolReal=DocTKF_REALRESTT->AsFloat*DocTKOL_REALRESTT->AsFloat;
                        DMRegReal->KolOtrReal=0;
                        DMRegReal->AddReal();
                        }
                DocT->Next();
                }
                
		IdDoc=DocAllIDDOC->AsInt64;
        DMRegVsRasch->IdDoc=IdDoc;
        DMRegVsRasch->PosDoc=DocAllPOSDOC->AsDateTime;
		DMRegVsRasch->IdFirm=DocAllIDFIRMDOC->AsInt64;
		DMRegVsRasch->IdKlient=DocAllIDKLDOC->AsInt64;
        DMRegVsRasch->Sum=DocAllSUMDOC->AsFloat;
        DMRegVsRasch->AddRecordPrihod();

        Doc2->Active=false;
		Doc2->ParamByName("ID")->AsInt64=DocAllIDDOC->AsInt64;
        Doc2->Active=true;



        Doc2->Edit();
        Doc2PRDOC->AsInteger=1;
        Doc2->Post();

        IBTrDvReg->Commit();

//       TDMSetup * DMSetup=new TDMSetup(Application);
//       DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//       delete DMSetup;
       
       Res=true;
        }
catch(Exception &exception)
				{
				IBTrDvReg->Rollback();
				Res=false;
				TextError=exception.Message;
				Error=true;
				}

return Res;
}
//--------------------------------------------------------------------------
void TDMDocRealRest::SpisatProdSoSklada(void)
{
SebProd=0;

IdSklad=DocAllIDSKLDOC->AsInt64;

//добавим запись в регистр выпуск продукции
DMRegVipuskProd->IdDoc=DocAllIDDOC->AsInt64;
DMRegVipuskProd->PosDoc=DocAllPOSDOC->AsDateTime;
DMRegVipuskProd->IdFirm=DocAllIDFIRMDOC->AsInt64;
DMRegVipuskProd->IdSklad=IdSklad;
DMRegVipuskProd->IdNom=DocTIDNOM_REALRESTT->AsInt64;
DMRegVipuskProd->KolProd=DocTKF_REALRESTT->AsFloat*DocTKOL_REALRESTT->AsFloat;
DMRegVipuskProd->AddRecordPrihod();

SpisatProd(DocTIDNOM_REALRESTT->AsInt64,DocTKOL_REALRESTT->AsFloat*DocTKF_REALRESTT->AsFloat);

//исправим себестоимость продукции
DMRegVipuskProd->DvRegOst->Edit();
DMRegVipuskProd->DvRegOstSEB_RGVIPPROD_DV->AsFloat=SebProd;
DMRegVipuskProd->DvRegOst->Post();
}

//---------------------------------------------------------------------------
void TDMDocRealRest::SpisatProd(__int64 idnom, float kol)
{
float KolEdProd=0;
float KFEdProd=0;
__int64 IdNomRest=0;  //ID_NOMREST


TDMSprNomRest * DMNomRest=new TDMSprNomRest(Application);
DMNomRest->GetTekSostav(idnom,DocAllPOSDOC->AsDateTime);


IdNomRest=DMNomRest->ElementID_NOMREST->AsInt64;

if(DMNomRest->ElementKOLEDPROD_NOMREST->AsFloat==0){KolEdProd=1;}
else {KolEdProd=DMNomRest->ElementKOLEDPROD_NOMREST->AsFloat;}

if (DMNomRest->ElementKFED->AsFloat==0){KFEdProd=1;}
else{KFEdProd=DMNomRest->ElementKFED->AsFloat;}

//ShowMessage("Текущий состав:"+DMNomRest->ElementNAME_NOMREST->AsString);
delete DMNomRest;

//необходимы следущие данные
//- идентификатор состава продукции    IdNomRest
//- КФ единицы на которую задан состав продукции  KFEdProd
//- количество единиц продукции на которое задан состав   KolEdProd
//- позиция, для определения сезонных коэффициентов

TDMSprSostProd *DMSostav=new TDMSprSostProd(Application);
DMSostav->KolEdProd=KolEdProd;
DMSostav->KFEdProd=KFEdProd;
DMSostav->Pos =DocAllPOSDOC->AsDateTime;
DMSostav->OpenTable(IdNomRest);

DMSostav->Table->First();
while (!DMSostav->Table->Eof)
        {
        if (DMSostav->TableTNOM->AsInteger==2)
                {
                //получим склад места приготовления полуфабриката
                int IdTekSklad=IdSklad;
				IdSklad=DocAllIDSKLDOC->AsInt64;
                //-----------------------------------------------------
				SpisatProd(DMSostav->TableIDKOMPL_SPROD->AsInt64,
                                DMSostav->TableNABASED->AsFloat*kol);
                IdSklad=IdTekSklad;
                }

        if (DMSostav->TableTNOM->AsInteger==0)
                {
				if (DMSostav->TableSPIS_SPROD->AsInteger==1)
                        {
						SpisatNomSoSklada(DMSostav->TableIDKOMPL_SPROD->AsInt64,
                                DMSostav->TableNABASED->AsFloat*kol);
                        }
                }

        DMSostav->Table->Next();
        }

delete DMSostav;

}

//--------------------------------------------------------------------------
void TDMDocRealRest::SpisatNomSoSklada(__int64 IdNom,double KolSpis)
{
//по регистру товары
		DMRegGoods->IdDoc=DocAllIDDOC->AsInt64;
		DMRegGoods->PosDoc=DocAllPOSDOC->AsDateTime;
		DMRegGoods->IdFirm=DocAllIDFIRMDOC->AsInt64;
		DMRegGoods->IdSklad=DocAllIDSKLDOC->AsInt64;
		DMRegGoods->IdNom=IdNom;
		DMRegGoods->SkladRozn=SkladRozn;
		if (SkladRozn==true && DocTTNOM->AsInteger==0)
			{
            DMRegGoods->RPrice=DocTPRICE_REALRESTT->AsFloat;
			}
		else
			{
			DMRegGoods->RPrice=0;
			}
		DMRegGoods->Kol=KolSpis;
		DMRegGoods->Operation=1;
		DMRegGoods->Type=0;    //0-внешнеее перемещение , 1- внутреннее
		DMRegGoods->AddRecordRashod();


SebNom=0;
KolOtrSpisNom=0;
KolSpisNom=0;
//получить таблицу партий
TablePart->Active=false;
TablePart->ParamByName("IDFIRM")->AsInt64=DocAllIDFIRMDOC->AsInt64;
TablePart->ParamByName("IDSKL")->AsInt64=IdSklad;
TablePart->ParamByName("IDNOM")->AsInt64=IdNom;
TablePart->Active=true;

TablePart->First();
while ((!TablePart->Eof)&&(KolSpis>0))
        {
        if (TablePartKOLOSTNOM->AsFloat<=KolSpis)
                {
                //полность списывем партию
                SpisatPartSoSklada(TablePartKOLOSTNOM->AsFloat, TablePartSUMOSTNOM->AsFloat);
                KolSpis=KolSpis-TablePartKOLOSTNOM->AsFloat;
                }
        else
                {
                //частично списываем партию
                SpisatPartSoSklada(KolSpis,(TablePartSUMOSTNOM->AsFloat*KolSpis)/TablePartKOLOSTNOM->AsFloat);
                KolSpis=0;
                }

        TablePart->Next();
        }

if (KolSpis>0)
		{
		if (NoOtrOstatok==true)
			{
			AnsiString text_error="Недостаточно товара на  складе (недостаточно ингредиентов для приготовления продукции)!";
			text_error=text_error+" Строка документа №"+IntToStr(DocT->RecNo);
			text_error=text_error+", Номенклатура (продукция) "+DocTNAMENOM->AsString;
			throw Exception(text_error,0);
			}		
		KolOtrSpisNom=KolSpis;
		DMRegOstNom->IdDoc=DocAllIDDOC->AsInt64;
		DMRegOstNom->PosDoc=DocAllPOSDOC->AsDateTime;
		DMRegOstNom->IdFirm=DocAllIDFIRMDOC->AsInt64;
		DMRegOstNom->IdSklad=DocAllIDSKLDOC->AsInt64;
		DMRegOstNom->IdNom=IdNom;
		DMRegOstNom->IdPart=0;
		DMRegOstNom->IdStr=DocTID_REALRESTT->AsInt64;
		DMRegOstNom->Sum=0;
		DMRegOstNom->Kol=KolSpis;
		DMRegOstNom->Operation=Operation;
		if (Operation==1)
			{
			DMRegOstNom->Sum2=(DocTSUM_REALRESTT->AsFloat/
						(DocTKOL_REALRESTT->AsFloat*DocTKF_REALRESTT->AsFloat))*KolSpis;
			}
		DMRegOstNom->AddRecordRashod();
        }

//если списываем номенклатуру для продукции необходимо заполнить регистр себестоимость продукции
if (DocTTNOM->AsInteger==2)  //продукция
        {
		DMRegSebProd->IdDoc=DocAllIDDOC->AsInt64;
        DMRegSebProd->PosDoc=DocAllPOSDOC->AsDateTime;
		DMRegSebProd->IdVipuskProd=DMRegVipuskProd->DvRegOstID_RGVIPPROD_DV->AsInt64;
		DMRegSebProd->IdFirm=DocAllIDFIRMDOC->AsInt64;
        DMRegSebProd->IdSklad=IdSklad;
        DMRegSebProd->IdNom=IdNom;

        DMRegSebProd->SumSeb=SebNom;
        DMRegSebProd->Kol=KolSpisNom;
        DMRegSebProd->KolOtr=KolOtrSpisNom;
        DMRegSebProd->AddRecordPrihod();
        }
}
//---------------------------------------------------------------------------
void TDMDocRealRest::SpisatPartSoSklada(double Kol, double Sum)
{

DMRegOstNom->IdDoc=DocAllIDDOC->AsInt64;
DMRegOstNom->PosDoc=DocAllPOSDOC->AsDateTime;
DMRegOstNom->IdFirm=TablePartIDFIRMOSTNOM->AsInt64;
DMRegOstNom->IdSklad=TablePartIDSKLOSTNOM->AsInt64;
DMRegOstNom->IdNom=TablePartIDNOMOSTNOM->AsInt64;
DMRegOstNom->IdPart=TablePartIDPARTOSTNOM->AsInt64;

DMRegOstNom->IdStr=DocTID_REALRESTT->AsInt64;
DMRegOstNom->Sum=Sum;
DMRegOstNom->Kol=Kol;
DMRegOstNom->Operation=Operation;

if (Operation==1)
        {
        DMRegOstNom->Sum2=(DocTSUM_REALRESTT->AsFloat/
                        (DocTKOL_REALRESTT->AsFloat*DocTKF_REALRESTT->AsFloat))*Kol;
        }
DMRegOstNom->AddRecordRashod();

SebReal=SebReal+Sum;
SebProd=SebProd+Sum;
SebNom=SebNom+Sum;
KolSpisNom=KolSpisNom+Kol;

}

//-----------------------------------------------------------------------------
bool TDMDocRealRest::CancelDvRegDoc(void)
{
bool result=false;
if (Prosmotr==true)
        {
        Error=true;
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return result;
        }

//по регистру остатки товаров
DMRegOstNom->IdDoc=DocAllIDDOC->AsInt64;
//по регистру остатки товаров
DMRegGoods->IdDoc=DocAllIDDOC->AsInt64;
//по регистру отр. списание
DMRegOtrSpisNom->IdDoc=DocAllIDDOC->AsInt64;
//по регистру реализация
DMRegReal->IdDoc=DocAllIDDOC->AsInt64;
//по регистру себестоимость продукции
DMRegSebProd->IdDoc=DocAllIDDOC->AsInt64;
//по регистру выпуск продукции
DMRegVipuskProd->IdDoc=DocAllIDDOC->AsInt64;

DMRegVsRasch->IdDoc=DocAllIDDOC->AsInt64;


try
        {
		if (DMRegOstNom->CancelDvReg()==true &&
				DMRegGoods->CancelDvReg()==true &&
                DMRegOtrSpisNom->CancelDvReg()==true &&
                DMRegReal->CancelDvReg()==true &&                 
                DMRegSebProd->CancelDvReg()==true &&
                DMRegVipuskProd->CancelDvReg()==true &&
                DMRegVsRasch->CancelDvReg()==true)
                {
                Doc2->Active=false;
                Doc2->ParamByName("ID")->AsInt64=DocAllIDDOC->AsInt64;
                Doc2->Active=true;
                Doc2->Edit();
                Doc2PRDOC->AsInteger=0;
                Doc2->Post();
                IBTrDvReg->Commit();

//                TDMSetup * DMSetup=new TDMSetup(Application);
//				DMSetup->ProveritPosled(DocAllPOSDOC->AsDateTime);
//				delete DMSetup;

                result=true;
                }
        }
catch(Exception &exception)
				{
				IBTrDvReg->Rollback();
				result=false;
				TextError=exception.Message;
				Error=true;
				}

return result;
}


//---------------------------------------------------------------------------





//---------------------------------------------------------------------------



bool TDMDocRealRest::DeleteDoc(__int64 id)
{
bool res=false;
OpenDoc(id);

if (Prosmotr==true)
        {
        Error=true;
        TextError="Позиция документа меньше позиции запрета редактирования!";
        return res;
		}

if (glUser->ElementID_USER->AsString!=DocAllIDUSERDOC->AsString)
	{
	if (glUser->ElementDEL_CHUG_DOC_SUSER->AsInteger!=1)
		{
		Error=true;
		TextError="Нельзя удалять чужие документы!";
		return res;
		}
	}
        
try
        {
        if (CancelDvRegDoc()!=true)
                {
                res=false;
                return res;
                }

        DocT->First();
        while(!DocT->Eof)
                {
                //ShowMessage(IntToStr(DocT->RecNo));
                DocT->Delete();
                }

        Doc->Delete();
        DocAll->Delete();

        DocT->ApplyUpdates();
        Doc->ApplyUpdates();
        DocAll->ApplyUpdates();
		IBTrUpdate->Commit();
        res=true;
        }

catch(Exception &exception)
				{
				IBTrUpdate->Rollback();
				res=false;
				TextError=exception.Message;
				Error=true;
				}
return res;

}
//-----------------------------------------------------------------------------

void __fastcall TDMDocRealRest::DocIDTPRICEChange(TField *Sender)
{
DocT->ParamByName("PARAM_ID_TYPE_PRICE")->AsInt64=DocIDTPRICE_REALREST->AsInt64;
}
//---------------------------------------------------------------------------




void __fastcall TDMDocRealRest::DocTCalcFields(TDataSet *DataSet)
{
DocT->FieldByName("RECNO")->AsInteger=DocT->RecNo;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRest::DocAfterDelete(TDataSet *DataSet)
{
NewSummaStr=0;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRest::DocTBeforeDelete(TDataSet *DataSet)
{
OldSummaStr=DocTSUM_REALRESTT->AsFloat;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRest::DocTNewRecord(TDataSet *DataSet)
{
DocTIDDOC_REALRESTT->AsInt64=DocAllIDDOC->AsInt64;

}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRest::DocAllPOSDOCChange(TField *Sender)
{
TDMSetup * DMSetup=new TDMSetup(Application);
Prosmotr=DMSetup->ProveritPosZapretaRed(DocAllPOSDOC->AsDateTime);
delete DMSetup;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRest::DocAllNAME_SINFBASE_OBMENGetText(TField *Sender,
      AnsiString &Text, bool DisplayText)
{
Text="Инф. база: "+DocAllNAME_SINFBASE_OBMEN->AsString; 	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRest::DocTKOL_REALRESTTChange(TField *Sender)
{
OldSummaStr=DocTSUM_REALRESTT->AsFloat;

DocTSUM_REALRESTT->AsFloat=NewSummaStr=DocTKOL_REALRESTT->AsFloat
						*DocTPRICE_REALRESTT->AsFloat;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRest::DocTKF_REALRESTTChange(TField *Sender)
{
DocTPRICE_REALRESTT->AsFloat=DocTZNACH_PRICE->AsFloat* DocTKF_REALRESTT->AsFloat;	
}
//---------------------------------------------------------------------------

void __fastcall TDMDocRealRest::DocTPRICE_REALRESTTChange(TField *Sender)
{
OldSummaStr=DocTSUM_REALRESTT->AsFloat;

DocTSUM_REALRESTT->AsFloat=NewSummaStr=DocTKOL_REALRESTT->AsFloat
				*DocTPRICE_REALRESTT->AsFloat;

DocAll->Edit();
DocAllSUMDOC->AsFloat=DocAllSUMDOC->AsFloat-OldSummaStr+NewSummaStr;
DocAll->Post();	
}
//---------------------------------------------------------------------------



