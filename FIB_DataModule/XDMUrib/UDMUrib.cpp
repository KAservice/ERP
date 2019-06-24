//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMUrib.h"


#include "UDM.h"
#include "UDMSetup.h"
#include "UDMXMessageObmen.h"
#include <fstream.h>
#include "UDMSprObmenTypePrice.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TDMUrib::TDMUrib(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMUrib::DataModuleCreate(TObject *Sender)
{
////
}
//---------------------------------------------------------------------------
void __fastcall TDMUrib::DataModuleDestroy(TObject *Sender)
{
////
}
//---------------------------------------------------------------------------
void TDMUrib::CreateDataOutTable(int id_base)
{
IdBase=id_base;
if (IdBase==0) return;

TableIsm=new TDMXTableIsm(Application);
DataOut=new TDMXDataOut(Application);
DMTypeDoc=new  TDMSprObmenTypeDoc(Application);
DMTypeDoc->OpenTable(id_base);
DMSprObmenSklad=new TDMSprObmenSklad(Application);
DMSprObmenSklad->OpenTable(id_base);

int max_id=DataOut->GetMaxIdTableIsm(id_base);
if (max_id<StartIDTableIsm)
        {
        max_id=StartIDTableIsm;
        }   

TableIsm->OpenTable(max_id);
TableIsm->Table->Last();
//ProgressBar1->Max=TableIsm->Table->RecNo;
//ShowMessage(IntToStr(TableDataOut->RecordCount));
//ProgressBar1->Step=1;


TableIsm->Table->First();
while(!TableIsm->Table->Eof)
        {
        if(TableIsm->TableTYPEOB_XTISM->AsInteger==1)//справочник
                {
                AddSprInDataTable();
                }

        if(TableIsm->TableTYPEOB_XTISM->AsInteger==2) //документ
                {
                AddDocInDataTable();
                }
        TableIsm->Table->Next();
        //ProgressBar1->StepIt();
        }
delete DMTypeDoc;
delete DMSprObmenSklad;
delete TableIsm;
delete DataOut;
ShowMessage("Подготовка данных завершена!");
}
//-----------------------------------------------------------------------------
void TDMUrib::AddSprInDataTable(void)
{
bool AddDataOut=true;
//после проверки - надо ли выгружать в указанную базу данный справочник
if (Trim(TableIsm->TableNAMETAB_XTISM->AsString)=="SPRICE")
        {
        TDMSprObmenTypePrice * DMSprObmenTypePrice=new TDMSprObmenTypePrice(Application);
        DMSprObmenTypePrice->OpenTable(IdBase);

        TDMSprPrice * DMSprPrice=new TDMSprPrice(Application);
        DMSprPrice->OpenElement(TableIsm->TableIDREC_XTISM->AsInteger);
        AddDataOut=false;
        DMSprObmenTypePrice->Table->First();
        while(!DMSprObmenTypePrice->Table->Eof)
                {
                if(DMSprPrice->ElementIDTYPE_PRICE->AsInteger==
                        DMSprObmenTypePrice->TableIDTPRICE_STYPEPRICE_OBMEN->AsInteger)
                        {
                        AddDataOut=true;
                        break;
                        }
                DMSprObmenTypePrice->Table->Next();
                }



        delete DMSprPrice;
        delete DMSprObmenTypePrice;
        }

if(DataOut->GetIdElement(IdBase,TableIsm->TableID_XTISM->AsInteger)==0 && AddDataOut==true)
        {
        DataOut->AddRecordDataOut(IdBase,TableIsm->TableID_XTISM->AsInteger);
        } 
}
//-----------------------------------------------------------------------------
void TDMUrib::AddDocInDataTable(void)
{
//после проверки - надо ли выгружать документ в указанную базу данный документ
//
String name_table=Trim(TableIsm->TableNAMETAB_XTISM->AsString);
//String name_doc="";
//int id_doc=0;
bool exit=true;

if (name_table=="GALLDOC") {exit=false; if(CheckGALLDOC()==false) return;}
if (name_table=="DPER")    {exit=false;   if(CheckDPER()==false) return;}
if (name_table=="DPERT")   { exit=false; if(CheckDPERT()==false) return;}
if (name_table=="DCHK")    { exit=false;  if(CheckDCHK()==false) return;}
if (name_table=="DCHKT")   {exit=false;  if(CheckDCHKT()==false) return;}

if(exit==true) return;


if(DataOut->GetIdElement(IdBase,TableIsm->TableID_XTISM->AsInteger)!=0) return;

DataOut->AddRecordDataOut(IdBase,TableIsm->TableID_XTISM->AsInteger);


}
//------------------------------------------------------------------------------
bool TDMUrib::CheckGALLDOC(void)
{
bool result=false;
DocAll->Active=false;
DocAll->ParamByName("PARAM_IDDOC")->AsInteger=TableIsm->TableIDREC_XTISM->AsInteger;
DocAll->Active=true;
if(DocAll->RecordCount!=1)  return result;

String type_doc=Trim(DocAllTDOC->AsString);
if(CheckDocForTypeDoc(type_doc)==false) return result;

// далее в зависимости от типа документа
if (type_doc=="PER")
        {
        //проверить склад источник и склад получатель
        int id_sklad=DocAllIDSKLDOC->AsInteger;
        Doc->Active=false;
        String zapros=" select  IDSKLPOLPER from DPER where IDDOCPER='"+
                        IntToStr(TableIsm->TableIDREC_XTISM->AsInteger)+"'";
        Doc->SQL->Clear();
        Doc->SQL->Add(zapros);
        Doc->Active=true;
        int id_sklad_pol=Doc->FieldByName("IDSKLPOLPER")->AsInteger;
        if (CheckDocForSklad(id_sklad)==false && CheckDocForSklad(id_sklad_pol)==false) return result;
        }

if(type_doc=="CHK")
        {
        int id_sklad=DocAllIDSKLDOC->AsInteger;
        if (CheckDocForSklad(id_sklad)==false) return result;
        }


result=true;
DocAll->Active=false;
Doc->Active=false;
return result;
}
//-----------------------------------------------------------------------------
bool TDMUrib::CheckDPER(void)
{
bool result=false;

//проверить склад источник и склад получатель
Doc->Active=false;
String zapros=" select  IDSKLPOLPER, IDDOCPER from DPER where IDPER='"+
                        IntToStr(TableIsm->TableIDREC_XTISM->AsInteger)+"'";
Doc->SQL->Clear();
Doc->SQL->Add(zapros);
Doc->Active=true;
int id_sklad_pol=Doc->FieldByName("IDSKLPOLPER")->AsInteger;

DocAll->Active=false;
DocAll->ParamByName("PARAM_IDDOC")->AsInteger=Doc->FieldByName("IDDOCPER")->AsInteger;
DocAll->Active=true;

String type_doc=Trim(DocAllTDOC->AsString);
if(CheckDocForTypeDoc(type_doc)==false) return result;

int id_sklad=DocAllIDSKLDOC->AsInteger;
if (CheckDocForSklad(id_sklad)==false && CheckDocForSklad(id_sklad_pol)==false) return result;

result=true;
return result;
}
//-----------------------------------------------------------------------------
bool TDMUrib::CheckDPERT(void)
{
bool result=false;
//проверить склад источник и склад получатель
DocT->Active=false;
String zapros=" select  IDDOCPERT from DPERT where IDPERT='"+
                        IntToStr(TableIsm->TableIDREC_XTISM->AsInteger)+"'";
DocT->SQL->Clear();
DocT->SQL->Add(zapros);
DocT->Active=true;

Doc->Active=false;
zapros=" select  IDSKLPOLPER from DPER where IDDOCPER='"+
                        IntToStr(DocT->FieldByName("IDDOCPERT")->AsInteger)+"'";
Doc->SQL->Clear();
Doc->SQL->Add(zapros);
Doc->Active=true;
int id_sklad_pol=Doc->FieldByName("IDSKLPOLPER")->AsInteger;

DocAll->Active=false;
DocAll->ParamByName("PARAM_IDDOC")->AsInteger=DocT->FieldByName("IDDOCPERT")->AsInteger;
DocAll->Active=true;

String type_doc=Trim(DocAllTDOC->AsString);
if(CheckDocForTypeDoc(type_doc)==false) return result;

int id_sklad=DocAllIDSKLDOC->AsInteger;
if (CheckDocForSklad(id_sklad)==false && CheckDocForSklad(id_sklad_pol)==false) return result;

result=true;

return result;
}
//-----------------------------------------------------------------------------
bool TDMUrib::CheckDCHK(void)
{
bool result=false;

//проверить склад
Doc->Active=false;
String zapros=" select  IDDOCCHK from DCHK where IDCHK='"+
                        IntToStr(TableIsm->TableIDREC_XTISM->AsInteger)+"'";
Doc->SQL->Clear();
Doc->SQL->Add(zapros);
Doc->Active=true;

DocAll->Active=false;
DocAll->ParamByName("PARAM_IDDOC")->AsInteger=Doc->FieldByName("IDDOCCHK")->AsInteger;
DocAll->Active=true;

String type_doc=Trim(DocAllTDOC->AsString);
if(CheckDocForTypeDoc(type_doc)==false) return result;

int id_sklad=DocAllIDSKLDOC->AsInteger;
if (CheckDocForSklad(id_sklad)==false) return result;

result=true;


return result;
}
//-----------------------------------------------------------------------------
bool TDMUrib::CheckDCHKT(void)
{
bool result=false;
//проверить
DocT->Active=false;
String zapros=" select  IDDOCCHKT from DCHKT where IDCHKT='"+
                        IntToStr(TableIsm->TableIDREC_XTISM->AsInteger)+"'";
DocT->SQL->Clear();
DocT->SQL->Add(zapros);
DocT->Active=true;

DocAll->Active=false;
DocAll->ParamByName("PARAM_IDDOC")->AsInteger=DocT->FieldByName("IDDOCCHKT")->AsInteger;
DocAll->Active=true;

String type_doc=Trim(DocAllTDOC->AsString);
if(CheckDocForTypeDoc(type_doc)==false) return result;

int id_sklad=DocAllIDSKLDOC->AsInteger;
if (CheckDocForSklad(id_sklad)==false) return result;

result=true;

return result;
}

//-----------------------------------------------------------------------------
bool TDMUrib::CheckDocForTypeDoc(String type_doc)
{
bool result=false;
DMTypeDoc->Table->First();
while(!DMTypeDoc->Table->Eof)
        {
        if (type_doc==Trim(DMTypeDoc->TableNAME_STYPEDOC_OBMEN->AsString))
                {
                result=true;
                break;
                }
        DMTypeDoc->Table->Next();
        }
return result;
}
//------------------------------------------------------------------------------
bool TDMUrib::CheckDocForSklad(int id_sklad)
{
bool result=false;

DMSprObmenSklad->Table->First();
while(!DMSprObmenSklad->Table->Eof)
        {
        if (id_sklad == DMSprObmenSklad->TableIDSKLAD_SSKLAD_OBMEN->AsInteger)
                {
                result=true;
                break;
                }
        DMSprObmenSklad->Table->Next();
        }
return result;
}
//-----------------------------------------------------------------------------
//*****************************************************************************
//            подготовка завершена
//-----------------------------------------------------------------------------