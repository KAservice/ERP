//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UForma1CUSNImport.h"
#include "UFormaDocPrihNakl.h"
#include "UDM.h"
#include "UDMSprGrpNom.h"
#include "UDMSetup.h"
#include "UDMSprSklad.h"
#include "UDMSprNom.h"
#include "UDMSprEd.h"
#include "UDMDocPrihNakl.h"
#include "UDMDocPer.h"
#include "UDMDocInv.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TForma1CUSNImport::TForma1CUSNImport(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TForma1CUSNImport::FormCreate(TObject *Sender)
{
RichEdit1->Clear();

        try
                {

                }
        catch (...)
                {

                }
}
//---------------------------------------------------------------------------
void __fastcall TForma1CUSNImport::FormClose(TObject *Sender, TCloseAction &Action)
{

Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TForma1CUSNImport::ButtonOpenFileClick(TObject *Sender)
{
if (OpenDialog1->Execute())
        {
        try
                {
                FileNameXML=OpenDialog1->FileName;
                LabelFileName->Caption=FileNameXML;

                }
        catch (...)
                {

                }


        }
}


//----------------------------------------------------------------------------------
String TForma1CUSNImport::FloatToStringComma(double value)
{
String result="";
String StrValue=FloatToStr(value);

for(int i=1;i<=StrValue.Length();i++)
        {
        if (StrValue[i]==',')
                {
                result=result+".";

                }
        else
                {
                result=result+StrValue[i];
                }
        }
return result;
}
//----------------------------------------------------------------------------------
double TForma1CUSNImport::StringToFloatComma(String value)
{
double res=0;
String result="";
String StrValue=value;

for(int i=1;i<=StrValue.Length();i++)
        {
        if (StrValue[i]=='.')
                {
                result=result+",";

                }
        else
                {
                result=result+StrValue[i];
                }
        }

res=StrToFloat(result);
return res;
}
//-----------------------------------------------------


void __fastcall TForma1CUSNImport::ButtonZagrClick(TObject *Sender)
{
xml->Active = true;
xml->LoadFromFile(WideString(FileNameXML));
_di_IXMLNode  base=xml->DocumentElement;
_di_IXMLNode usel_spr=base->ChildNodes->Get(0);
_di_IXMLNode usel_document=base->ChildNodes->Get(1);


  for (int i=0;i<usel_spr->ChildNodes->Count;i++)    //1 уровень типов документов
        {
        _di_IXMLNode spr=usel_spr->ChildNodes->Get(i);
        String name_spr=Trim(spr->NodeName);


        if(name_spr=="SGRPNOM")
                {
                ImportSGRPNOM(spr);

                }

        if(name_spr=="STPRICE")
                {
                ImportSTPRICE(spr);

                }

        if(name_spr=="SSKLAD")
                {
                ImportSSKLAD(spr);

                }

        if(name_spr=="SNOM")
                {
                ImportSNOM(spr);

                }
        if(name_spr=="SPRICE")
                {
                ImportSPRICE(spr);

                }

        }

ImportDoc(usel_document);

ShowMessage("Загрузка завершена! ");
xml->Active = false;


}
//---------------------------------------------------------------------------
void TForma1CUSNImport::ImportSGRPNOM(_di_IXMLNode spr)
{
RichEdit1->Lines->Add("Загрузка групп номенклатуры!");
_di_IXMLNode    element;
TDMSprGrpNom *  DMGrp=new TDMSprGrpNom(Application);

  for (int i=0;i<spr->ChildNodes->Count;i++) 
        {
        element=spr->ChildNodes->Get(i);

        String gid=element->GetAttribute("GID_SPRGRPNOM");
        int id=DMGrp->GetIDElement(gid);                                        //элемент
        int idgroup=DMGrp->GetIDElement(element->GetAttribute("_GIDGRPGN"));    //группа элемента

        if(gid=="" || gid==" ") continue;

        if (DMGrp->OpenElement(id)>0 )
                {
                bool save=false;
                String name_gn=element->GetAttribute("NAMEGN");
                //RichEdit1->Lines->Add("Найдена группа "+name_gn);

                if (Trim(DMGrp->ElementNAMEGN->AsString )!=Trim(name_gn))
                        {
                        DMGrp->Element->Edit();
                        DMGrp->ElementNAMEGN->AsString=name_gn;
                        DMGrp->Element->Post();
                        save=true;
                        }

                if (DMGrp->ElementIDGRPGN->AsInteger!=idgroup)
                        {
                        DMGrp->Element->Edit();
                        DMGrp->ElementIDGRPGN->AsInteger=idgroup;
                        DMGrp->Element->Post();
                        save=true;
                        }
                if (save==true)
                        {
                         DMGrp->SaveElement();
                        }


                }
        else
                {
                RichEdit1->Lines->Add("Добавлена новая группа  "+element->GetAttribute("NAMEGN"));
                DMGrp->NewElement(idgroup);
                DMGrp->Element->Edit();
                DMGrp->ElementNAMEGN->AsString=element->GetAttribute("NAMEGN");
//                DMGrp->ElementGID_SGRPNOM->AsString=gid;
                DMGrp->Element->Post();
                DMGrp->SaveElement();
                }

        }


delete DMGrp;
}
//---------------------------------------------------------------------------
void TForma1CUSNImport::ImportSTPRICE(_di_IXMLNode spr)
{
RichEdit1->Lines->Add("Загрузка типов цен!");
_di_IXMLNode    element;
TDMSprTypePrice *  DMSprTypePrice=new TDMSprTypePrice(Application);

  for (int i=0;i<spr->ChildNodes->Count;i++) 
        {
        element=spr->ChildNodes->Get(i);

        String gid=element->GetAttribute("GID_STPRICE");
        int id=DMSprTypePrice->GetIDElement(gid);        //элемент

        if(gid=="" || gid==" ") continue;

        if (DMSprTypePrice->OpenElement(id)>0 )
                {
                bool save=false;
                String name=element->GetAttribute("NAME_TPRICE");
                //RichEdit1->Lines->Add("Найден тип цен "+name);

                if (Trim(DMSprTypePrice->ElementNAME_TPRICE->AsString )!=Trim(name))
                        {
                        DMSprTypePrice->Element->Edit();
                        DMSprTypePrice->ElementNAME_TPRICE->AsString=name;
                        DMSprTypePrice->Element->Post();
                        save=true;
                        }

                if (save==true)
                        {
                         DMSprTypePrice->SaveElement();
                        }


                }
        else
                {
                RichEdit1->Lines->Add("Добавлен новый тип цен  "+element->GetAttribute("NAME_TPRICE"));
                DMSprTypePrice->NewElement();
                DMSprTypePrice->Element->Edit();
                DMSprTypePrice->ElementNAME_TPRICE->AsString=element->GetAttribute("NAME_TPRICE");
//                DMSprTypePrice->ElementGID_STPRICE->AsString=gid;
                DMSprTypePrice->Element->Post();
                DMSprTypePrice->SaveElement();
                }

        }


delete DMSprTypePrice;
}
//---------------------------------------------------------------------------
void TForma1CUSNImport::ImportSSKLAD(_di_IXMLNode spr)
{
RichEdit1->Lines->Add("Загрузка складов!");
_di_IXMLNode    element;
TDMSprSklad *  DMSprSklad=new TDMSprSklad(Application);

  for (int i=0;i<spr->ChildNodes->Count;i++) 
        {
        element=spr->ChildNodes->Get(i);

        String gid=element->GetAttribute("GID_SSKLAD");
        int id=DMSprSklad->GetIDElement(gid);        //элемент

        if(gid=="" || gid==" ") continue;

        if (DMSprSklad->OpenElement(id)>0 )
                {
                bool save=false;
                String name=element->GetAttribute("NAMESKLAD");
                //RichEdit1->Lines->Add("Найден склад "+name);

                if (Trim(DMSprSklad->ElementNAMESKLAD->AsString )!=Trim(name))
                        {
                        DMSprSklad->Element->Edit();
                        DMSprSklad->ElementNAMESKLAD->AsString=name;
                        DMSprSklad->Element->Post();
                        save=true;
                        }

                if (save==true)
                        {
                         DMSprSklad->SaveElement();
                        }


                }
        else
                {
                RichEdit1->Lines->Add("Добавлен новый склад "+element->GetAttribute("NAMESKLAD"));
                DMSprSklad->NewElement();
                DMSprSklad->Element->Edit();
                DMSprSklad->ElementNAMESKLAD->AsString=element->GetAttribute("NAMESKLAD");
//                DMSprSklad->ElementGID_SSKLAD->AsString=gid;
                DMSprSklad->Element->Post();
                DMSprSklad->SaveElement();
                }

        }


delete DMSprSklad;
}
//---------------------------------------------------------------------------
void TForma1CUSNImport::ImportSNOM(_di_IXMLNode spr)
{
RichEdit1->Lines->Add("Загрузка  номенклатуры!");
_di_IXMLNode    element;
TDMSprNom *  DM=new TDMSprNom(Application);
TDMSprGrpNom *  DMGrp=new TDMSprGrpNom(Application);

  for (int i=0;i<spr->ChildNodes->Count;i++) 
        {
        element=spr->ChildNodes->Get(i);

        String gid=element->GetAttribute("GID_SNOM");
        int id=DM->GetIDElement(gid);                                        //элемент
        int idgroup=DMGrp->GetIDElement(element->GetAttribute("_GIDGRP"));    //группа элемента

        if(gid=="" || gid==" ") continue;

        if (DM->OpenElement(id)>0 )
                {
                bool save=false;
                String name=element->GetAttribute("NAMENOM");
                //RichEdit1->Lines->Add("Найдена номенклатура "+name);

                if (Trim(DM->ElementNAMENOM->AsString )!=Trim(name))
                        {
                        DM->Element->Edit();
                        DM->ElementNAMENOM->AsString=name;
                        DM->Element->Post();
                        save=true;
                        }

                if (DM->ElementIDGRPNOM->AsInteger!=idgroup)
                        {
                        DM->Element->Edit();
                        DM->ElementIDGRPNOM->AsInteger=idgroup;
                        DM->Element->Post();
                        save=true;
                        }
                String tnom=element->GetAttribute("TNOM");
                if(tnom!="")
                        {
                        if (DM->ElementTNOM->AsInteger!=tnom)
                                {
                                DM->Element->Edit();
                                DM->ElementTNOM->AsInteger=(int) StrToFloat(tnom);
                                DM->Element->Post();
                                save=true;
                                }
                        }

                if (save==true)
                        {
                         DM->SaveElement();
                        }


                }
        else
                {
                RichEdit1->Lines->Add("Добавлена новая номенклатура  "+element->GetAttribute("NAMENOM"));
                DM->NewElement(idgroup);

                DM->Element->Edit();
                String tnom=element->GetAttribute("TNOM");
                if (tnom!="")
                        {
                        DM->ElementTNOM->AsInteger=(int) StrToFloat(element->GetAttribute("TNOM"));
                        }
                else
                        {
                        DM->ElementTNOM->AsInteger=0;
                        }

                DM->ElementNAMENOM->AsString=element->GetAttribute("NAMENOM");
                DM->ElementKRNAMENOM->AsString=element->GetAttribute("NAMENOM");
                DM->ElementFNAMENOM->AsString=element->GetAttribute("NAMENOM");
//                DM->ElementGID_SNOM->AsString=gid;
                DM->Element->Post();
                DM->SaveElement();

                TDMSprEd *DMSprEd=new TDMSprEd(Application);
                DMSprEd->NewElement(DM->ElementIDNOM->AsInteger);
                DMSprEd->Element->Edit();
                DMSprEd->ElementNAMEED->AsString=element->GetAttribute("NAMEED");
                DMSprEd->Element->Post();
                DMSprEd->SaveElement();

                DM->Element->Edit();
                DM->ElementIDBASEDNOM->AsInteger=DMSprEd->ElementIDED->AsInteger;
                DM->ElementIDOSNEDNOM->AsInteger=DMSprEd->ElementIDED->AsInteger;
                DM->Element->Post();
                DM->SaveElement();

                delete DMSprEd;
                }

        }

delete DM;
delete DMGrp;
}
//-----------------------------------------------------------------------------------

void TForma1CUSNImport::ImportSPRICE(_di_IXMLNode spr)
{
RichEdit1->Lines->Add("Загрузка  цен!");
_di_IXMLNode    element;
TDMSprNom *  DMSprNom=new TDMSprNom(Application);
TDMSprTypePrice *  DMSprTypePrice=new TDMSprTypePrice(Application);
TDMSprPrice  * DMSprPrice =new TDMSprPrice(Application);

  for (int i=0;i<spr->ChildNodes->Count;i++) 
        {
        element=spr->ChildNodes->Get(i);

        String gid_nom=element->GetAttribute("_GIDNOM_PRICE");
        String gid_type_price=element->GetAttribute("_GIDTYPE_PRICE");
        int id_nom=DMSprNom->GetIDElement(gid_nom);
        int id_type_price=DMSprTypePrice->GetIDElement(gid_type_price);

        if (DMSprPrice->FindElement(id_type_price,id_nom)>0 )
                {
                bool save=false;
                float znach=StringToFloatComma(element->GetAttribute("ZNACH_PRICE"));
                //RichEdit1->Lines->Add("Найдена цена");

                if (DMSprPrice->ElementZNACH_PRICE->AsFloat !=znach)
                        {
                        DMSprPrice->Element->Edit();
                        DMSprPrice->ElementZNACH_PRICE->AsFloat=znach;
                        DMSprPrice->Element->Post();
                        save=true;
                        }


                if (save==true)
                        {
                         DMSprPrice->SaveElement();
                        }


                }
        else
                {
                RichEdit1->Lines->Add("Добавлена новая цена ");
                DMSprPrice->IdNom=id_nom;
                DMSprPrice->IdTypePrice=id_type_price;
                DMSprPrice->NewElement();

                DMSprPrice->Element->Edit();
                DMSprPrice->ElementZNACH_PRICE->AsFloat=
                                StringToFloatComma(element->GetAttribute("ZNACH_PRICE"));
                DMSprPrice->Element->Post();
                DMSprPrice->SaveElement();

                }

        }

delete DMSprNom;
delete DMSprTypePrice;
delete DMSprPrice;
}
//-----------------------------------------------------------------------------------
void TForma1CUSNImport::ImportDoc(_di_IXMLNode usel_document)
{

  for (int i=0;i<usel_document->ChildNodes->Count;i++)    //1 уровень типов документов
        {
        _di_IXMLNode usel_doc=usel_document->ChildNodes->Get(i);
        String type_doc=usel_doc->GetAttribute("TDOC");

        if(type_doc=="PRN")
                {
                ImportDocPRN(usel_doc);
                }
        if(type_doc=="PER")
                {
                ImportDocPER(usel_doc);
                }
        if(type_doc=="INV")
                {
                ImportDocINV(usel_doc);
                }
        }
}
///-------------------------------------------------------------------------------

void TForma1CUSNImport::ImportDocPRN(_di_IXMLNode usel_doc)
{
//найдем документ

TDMDocPrihNakl * DM=new TDMDocPrihNakl(Application);
TDMSprSklad * DMSprSklad=new TDMSprSklad(Application);
TDMSprNom * DMSprNom=new TDMSprNom(Application);

TDate date_doc=StrToDate(usel_doc->GetAttribute("_DATEDOC"));
int number_doc=(int)StrToFloat(usel_doc->GetAttribute("NUMDOC"));
int id_doc=DM->GetIDDocPoNomeruDoc(number_doc, date_doc);


if (id_doc==0)
        {
        //-------заголовок-------------------------------------------
        DM->NewDoc();
        DM->DocAll->Edit();
        DM->DocAllNUMDOC->AsInteger=number_doc;
        String date_doc=usel_doc->GetAttribute("_DATEDOC");
        String time_doc=usel_doc->GetAttribute("_TIMEDOC");
        DM->DocAllPOSDOC->AsDateTime=StrToDateTime(date_doc+" "+time_doc);

        String gid_sklad=usel_doc->GetAttribute("_GIDSKLAD");
        int id_sklad=DMSprSklad->GetIDElement(gid_sklad);
        if (id_sklad!=0)
                {
                DM->DocAllIDSKLDOC->AsInteger=id_sklad;
                }
        DM->DocAll->Post();

        ///---------------------шапка---------------------------------
        TDMSprTypePrice * DMSprTypePrice=new TDMSprTypePrice(Application);
        String gid_type_price=usel_doc->GetAttribute("_GIDTYPE_PRICE");
        int id_type_price=DMSprTypePrice->GetIDElement(gid_type_price);
        DM->Doc->Edit();
        if (id_type_price!=0)
                {
                DM->DocIDTPRICE->AsInteger=id_type_price;
                }

         DM->Doc->Post();
        //---------------таблица--------------------------------------
  for (int i=0;i<usel_doc->ChildNodes->Count;i++)    //получим строки
        {
        _di_IXMLNode str_doc=usel_doc->ChildNodes->Get(i);

        String gid_nom=str_doc->GetAttribute("_GID_NOM");
        int id_nom=DMSprNom->GetIDElement(gid_nom);

        if (id_nom!=0)
                {
                DM->AddDocNewString();
                DM->DocT->Edit();
                DM->DocTIDNOMPRNT->AsInteger=id_nom;
                DM->DocTKOLPRNT->AsFloat=StringToFloatComma(str_doc->GetAttribute("KOLPRNT"));
                if (DMSprNom->OpenElement(id_nom)>0)
                        {
                        DM->DocTIDEDPRNT->AsInteger=DMSprNom->ElementIDBASEDNOM->AsInteger;
                        }
                DM->DocTKFPRNT->AsFloat=1;
                DM->DocTPRICEPRNT->AsFloat=StringToFloatComma(str_doc->GetAttribute("PRICEPRNT"));
                DM->DocTSUMPRNT->AsFloat=StringToFloatComma(str_doc->GetAttribute("SUMPRNT"));;
                DM->DocT->Post();
               }
        else
                {
                RichEdit1->Lines->Add("Товар не найден! ");
                }
        }

DM->SaveDoc();
RichEdit1->Lines->Add("Создан документ Приходная накладная № "+IntToStr(DM->DocAllNUMDOC->AsInteger));



        }
else
        {
        RichEdit1->Lines->Add("Найден документ");
        }



delete DMSprSklad;
delete DMSprNom;
delete DM;

}
//---------------------------------------------------------------------------------------

void TForma1CUSNImport::ImportDocPER(_di_IXMLNode usel_doc)
{
//найдем документ

TDMDocPer * DM=new TDMDocPer(Application);
TDMSprSklad * DMSprSklad=new TDMSprSklad(Application);
TDMSprNom * DMSprNom=new TDMSprNom(Application);

TDate date_doc=StrToDate(usel_doc->GetAttribute("_DATEDOC"));
int number_doc=(int) StrToFloat(usel_doc->GetAttribute("NUMDOC"));
int id_doc=DM->GetIDDocPoNomeruDoc(number_doc, date_doc);


if (id_doc==0)
        {
        //-------заголовок-------------------------------------------
        DM->NewDoc();
        DM->DocAll->Edit();
        DM->DocAllNUMDOC->AsInteger=number_doc;
        String date_doc=usel_doc->GetAttribute("_DATEDOC");
        String time_doc=usel_doc->GetAttribute("_TIMEDOC");
        DM->DocAllPOSDOC->AsDateTime=StrToDateTime(date_doc+" "+time_doc);
        DM->DocAllNUMDOC->AsInteger=number_doc;
        
        String gid_sklad=usel_doc->GetAttribute("_GIDSKLAD");
        int id_sklad=DMSprSklad->GetIDElement(gid_sklad);
        if (id_sklad!=0)
                {
                DM->DocAllIDSKLDOC->AsInteger=id_sklad;
                }
        DM->DocAll->Post();

        ///---------------------шапка---------------------------------
        gid_sklad=usel_doc->GetAttribute("_GIDSKLADPOL");
        id_sklad=DMSprSklad->GetIDElement(gid_sklad);

        DM->Doc->Edit();
        if (id_sklad!=0)
                {
                DM->DocIDSKLPOLPER->AsInteger=id_sklad;
                }

         DM->Doc->Post();

        //---------------таблица--------------------------------------
  for (int i=0;i<usel_doc->ChildNodes->Count;i++)    //получим строки
        {
        _di_IXMLNode str_doc=usel_doc->ChildNodes->Get(i);

        String gid_nom=str_doc->GetAttribute("_GID_NOM");
        int id_nom=DMSprNom->GetIDElement(gid_nom);

        if (id_nom!=0)
                {
                DM->AddDocNewString();
                DM->DocT->Edit();
                DM->DocTIDNOMPERT->AsInteger=id_nom;
                DM->DocTKOLPERT->AsFloat=StringToFloatComma(str_doc->GetAttribute("KOLPERT"));

                if (DMSprNom->OpenElement(id_nom)>0)
                        {
                        DM->DocTIDEDPERT->AsInteger=DMSprNom->ElementIDBASEDNOM->AsInteger;
                        }
                        
                DM->DocTKFPERT->AsFloat=1;
                DM->DocT->Post();
               }
        else
                {
                RichEdit1->Lines->Add("Товар не найден! ");
                }
        }

DM->SaveDoc();
RichEdit1->Lines->Add("Создан документ Перемещение № "+IntToStr(DM->DocAllNUMDOC->AsInteger));
 
        }
else
        {
        RichEdit1->Lines->Add("Найден документ");
        }
            
delete DMSprSklad;
delete DMSprNom;
delete DM;

}
//---------------------------------------------------------------------------------------

void TForma1CUSNImport::ImportDocINV(_di_IXMLNode usel_doc)
{
//найдем документ

TDMDocInv * DM=new TDMDocInv(Application);
TDMSprSklad * DMSprSklad=new TDMSprSklad(Application);
TDMSprNom * DMSprNom=new TDMSprNom(Application);

TDate date_doc=StrToDate(usel_doc->GetAttribute("_DATEDOC"));
int number_doc=(int) StrToFloat(usel_doc->GetAttribute("NUMDOC"));
int id_doc=DM->GetIDDocPoNomeruDoc(number_doc, date_doc);


if (id_doc==0)
        {
        //-------заголовок-------------------------------------------
        DM->NewDoc();
        DM->DocAll->Edit();
        DM->DocAllNUMDOC->AsInteger=number_doc;
        String date_doc=usel_doc->GetAttribute("_DATEDOC");
        String time_doc=usel_doc->GetAttribute("_TIMEDOC");
        DM->DocAllPOSDOC->AsDateTime=StrToDateTime(date_doc+" "+time_doc);
        DM->DocAllNUMDOC->AsInteger=number_doc;

        String gid_sklad=usel_doc->GetAttribute("_GID_SKLAD");
        int id_sklad=DMSprSklad->GetIDElement(gid_sklad);
        if (id_sklad!=0)
                {
                DM->DocAllIDSKLDOC->AsInteger=id_sklad;
                }
        DM->DocAll->Post();

        ///---------------------шапка---------------------------------
        //gid_sklad=usel_doc->GetAttribute("_GIDSKLADPOL");
        //id_sklad=DMSprSklad->GetIDElement(gid_sklad);

        //DM->Doc->Edit();
        //if (id_sklad!=0)
        //        {
        //        DM->DocIDSKLPOLPER->AsInteger=id_sklad;
        //        }

        // DM->Doc->Post();

        //---------------таблица--------------------------------------
  for (int i=0;i<usel_doc->ChildNodes->Count;i++)    //получим строки
        {
        _di_IXMLNode str_doc=usel_doc->ChildNodes->Get(i);

        String gid_nom=str_doc->GetAttribute("_GID_NOM");
        int id_nom=DMSprNom->GetIDElement(gid_nom);

        if (id_nom!=0)
                {
                DM->AddDocNewString();
                DM->DocT->Edit();
                DM->DocTIDNOM_INVT->AsInteger=id_nom;
                DM->DocTKOLFAKT_INVT->AsFloat=StringToFloatComma(str_doc->GetAttribute("KOLFAKT_INVT"));

                if (DMSprNom->OpenElement(id_nom)>0)
                        {
                        DM->DocTIDED_INVT->AsInteger=DMSprNom->ElementIDBASEDNOM->AsInteger;
                        }
                        
                DM->DocTKF_INVT->AsFloat=1;
                DM->DocT->Post();
               }
        else
                {
                RichEdit1->Lines->Add("Товар не найден! ");
                }
        }

DM->SaveDoc();
RichEdit1->Lines->Add("Создан документ Инвентаризация № "+IntToStr(DM->DocAllNUMDOC->AsInteger));
 
        }
else
        {
        RichEdit1->Lines->Add("Найден документ");
        }
            
delete DMSprSklad;
delete DMSprNom;
delete DM;

}
//---------------------------------------------------------------------------------------


