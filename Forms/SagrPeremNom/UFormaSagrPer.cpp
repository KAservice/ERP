//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaSagrPer.h"
#include "UFormaDocPrihNakl.h"
#include "UDM.h"
#include "UDMSprGrpNom.h"
#include "UDMSetup.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaSagrPer::TFormaSagrPer(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TFormaSagrPer::FormCreate(TObject *Sender)
{
RichEdit1->Clear();
DMSprTypePrice=new TDMSprTypePrice(Application);
DMSprTypePrice->OpenTable();
DMSprPrice=new TDMSprPrice(Application);



        try
                {
                TDMSetup * DMSetup=new TDMSetup(Application);
                if(DMSetup->OpenElement(16)==0)
                        {
                        return;
                        }

                CatalogFile=DMSetup->ElementVALUE_SETUP->AsString+"\\"; 
                LabelFileName->Caption=CatalogFile+"Tovar.dbf";
                ADOTable1->Active=false;
                ADOTable3->Active=false;
                ADOTable2->Active=false;

                ADOTable1->ConnectionString="Provider=MSDASQL.1;Persist Security Info=False;Data Source=����� dBASE;Initial Catalog="+
                                        CatalogFile;
                ShowMessage(ADOTable1->ConnectionString);
                ADOTable1->TableName="Tovar.dbf";

                ADOTable2->ConnectionString="Provider=MSDASQL.1;Persist Security Info=False;Data Source=����� dBASE;Initial Catalog="+
                                        CatalogFile;
                ADOTable2->TableName="Ed.dbf";

                ADOTable3->ConnectionString="Provider=MSDASQL.1;Persist Security Info=False;Data Source=����� dBASE;Initial Catalog="+
                                        CatalogFile;
                ADOTable3->TableName="Price.dbf";

                ADOTable4->ConnectionString="Provider=MSDASQL.1;Persist Security Info=False;Data Source=����� dBASE;Initial Catalog="+
                                        CatalogFile;
                ADOTable4->TableName="Grp.dbf";


                ADOTable1->Open();
                ADOTable2->Open();
                ADOTable3->Open();
                ADOTable4->Open();
                }
        catch (...)
                {

                }
}
//---------------------------------------------------------------------------
void __fastcall TFormaSagrPer::FormClose(TObject *Sender, TCloseAction &Action)
{
ADOTable1->Active=false;
Nom->Active=false;
Ed->Active=false;
Price->Active=false;
delete DMSprTypePrice;
delete DMSprPrice;
Action=caFree;        
}
//---------------------------------------------------------------------------
void __fastcall TFormaSagrPer::ButtonOpenFileClick(TObject *Sender)
{
if (OpenDialog1->Execute())
        {
        try
                {
                FileName=OpenDialog1->FileName;
                LabelFileName->Caption=FileName;
                ADOTable1->Active=false;
                ADOTable3->Active=false;
                ADOTable2->Active=false;

                ADOTable1->ConnectionString="Provider=MSDASQL.1;Persist Security Info=False;Data Source=����� dBASE;Initial Catalog="+
                                        ExtractFilePath(FileName);
                ShowMessage(ADOTable1->ConnectionString);
                ADOTable1->TableName=ExtractFileName(FileName);     

                ADOTable2->ConnectionString="Provider=MSDASQL.1;Persist Security Info=False;Data Source=����� dBASE;Initial Catalog="+
                                        ExtractFilePath(FileName);
                ADOTable2->TableName="Ed.dbf";

                ADOTable3->ConnectionString="Provider=MSDASQL.1;Persist Security Info=False;Data Source=����� dBASE;Initial Catalog="+
                                        ExtractFilePath(FileName);
                ADOTable3->TableName="Price.dbf";

                ADOTable4->ConnectionString="Provider=MSDASQL.1;Persist Security Info=False;Data Source=����� dBASE;Initial Catalog="+
                                        ExtractFilePath(FileName);
                ADOTable4->TableName="Grp.dbf";


                ADOTable1->Open();
                ADOTable2->Open();
                ADOTable3->Open();
                ADOTable4->Open();
                }
        catch (...)
                {

                }


        }
}

//---------------------------------------------------------------------------

void __fastcall TFormaSagrPer::ButtonZagrClick(TObject *Sender)
{
ErrorUpdateSpr=false;
KolError=0;

DataSource1->Enabled=false;
DataSource2->Enabled=false;
DataSource3->Enabled=false;

RichEdit1->Lines->Add("  ");
RichEdit1->Lines->Add("������  �������� ��������� "+Date()+" " +Time());
RichEdit1->Lines->Add("���� ���������:"+FileName);
RichEdit1->Lines->Add("  ");
RichEdit1->Lines->Add("���������� ����������� ������� � ����������� ������!");

        ProgressBar1->Max=ADOTable1->RecordCount;
        ProgressBar1->Step=1;
        //IBTrNom->StartTransaction();
        NoUpdate=false;
        ADOTable1->First();
        ADOTable2->First();
        ADOTable3->First();

        while (!ADOTable1->Eof)
                {
                ProgressBar1->StepIt();
              //  RichEdit1->Lines->Add("  ");
              //  RichEdit1->Lines->Add("C����� �"+IntToStr(ADOTable1->RecNo)
              //   +" ���: "+ADOTable1->FieldByName("CODE")->AsInteger
              //  +"  ������������:"+ADOTable1->FieldByName("NAME")->AsString);

                //        IBTr->Commit();

               try
                        {

						IBTrUpdate->StartTransaction();
                        SprTPrice->Active=true;
                        Nom->Active=false;
                        Nom->ParamByName("PARAM_CODENOM")->AsInteger=ADOTable1->FieldByName("CODE")->AsInteger;
                        Nom->Open();
            //    RichEdit1->Lines->Add("����� ������ � ����! ");
                        if (Nom->RecordCount==0)    //�� ������ �����
                                {
               //         RichEdit1->Lines->Add("����� �� ������! ");
               //         RichEdit1->Lines->Add("��������� ����� ������� ������������! ");
                                AddNewTovar();
                                }
                        else
                                {
                        // ������ �����
                                if (Nom->RecordCount==1)
                                        {
                 //               RichEdit1->Lines->Add("����� ������ � ����! ");
                                //��������� ��������� ������
                                        EditTovar();

                                        }
                                else     //��������� ������� � ���������� �����
                                        {
                                        ErrorUpdateSpr=true;
                                        NoUpdate=true;
                                        KolError++;
                                        RichEdit1->Lines->Add("������! ��������� ������� � ���������� �����!");
                                        }
                                }

                //��������� �������
              //  RichEdit1->Lines->Add("������������ ������� ������!");
                        UpdateEd();

                //��������� ����
            //    RichEdit1->Lines->Add("������������ ������� ���!");
                        UpdatePrice();

						IBTrUpdate->Commit();
                        }

                catch(...)
                        {
						IBTrUpdate->Rollback();
                        }




                ADOTable1->Next();
                NoUpdate=false;
                }


RichEdit1->Lines->Add("�������� ���������! ");
//RichEdit1->Lines->Add("������: "+IntToStr(KolError));

DataSource1->Enabled=true;
DataSource2->Enabled=true;
DataSource3->Enabled=true;

}

//---------------------------------------------------------------------------
void TFormaSagrPer::AddNewTovar()
{
if (ADOTable1->FieldByName("SHBASED")->AsString=="")  return;
if(ADOTable1->FieldByName("SHOSNED")->AsString=="" ) return;
if(ADOTable1->FieldByName("CODE")->AsInteger==0 ) return;
if(NoUpdate==true ) return;
Nom->Insert();
NomNAMENOM->AsString=ADOTable1->FieldByName("NAME")->AsString;
NomFNAMENOM->AsString=ADOTable1->FieldByName("NAME")->AsString;
NomKRNAMENOM->AsString=ADOTable1->FieldByName("NAME")->AsString;
NomCODENOM->AsInteger=ADOTable1->FieldByName("CODE")->AsInteger;
Nom->FieldByName("TNOM")->AsInteger=0;
Nom->Post();


}

//---------------------------------------------------------------------------
void TFormaSagrPer::EditTovar()
{
if(NomNAMENOM->AsString!=ADOTable1->FieldByName("NAME")->AsString)
        {
        Nom->Edit();
        NomNAMENOM->AsString=ADOTable1->FieldByName("NAME")->AsString;
        NomKRNAMENOM->AsString=ADOTable1->FieldByName("NAME")->AsString;
        Nom->Post();
   //     RichEdit1->Lines->Add("��������� ���� ������������!");
        }

if(NomFNAMENOM->AsString!=ADOTable1->FieldByName("NAME")->AsString)
        {
        Nom->Edit();
        NomFNAMENOM->AsString=ADOTable1->FieldByName("NAME")->AsString;
        Nom->Post();
    //    RichEdit1->Lines->Add("��������� ���� ������ ������������!");
        }

if(NomCODENOM->AsInteger!=ADOTable1->FieldByName("CODE")->AsInteger)
        {
        Nom->Edit();
        NomCODENOM->AsInteger=ADOTable1->FieldByName("CODE")->AsInteger;
        Nom->Post();
     //   RichEdit1->Lines->Add("��������!��������� ���� ��� ������!!!");
        }


if(NomTNOM->AsInteger!=0)
        {
        Nom->Edit();
        NomTNOM->AsInteger=0;
        Nom->Post();
    //    RichEdit1->Lines->Add("��������� ���� ��� ������������!");
        }

///UpdateEd();
//UpdatePrice();
}

//-------------------------------------------------------------------------
void TFormaSagrPer::UpdateEd(void)
{

while (!ADOTable2->Eof  && ADOTable2->FieldByName("IDTOVAR")->AsInteger==
                                        ADOTable1->FieldByName("ID")->AsInteger)
        {
        if(ADOTable2->FieldByName("BARCODE")->AsString==""
                || ADOTable1->FieldByName("CODE")->AsInteger==0
                || NomIDNOM->AsInteger==0
                || NoUpdate==true)
        {
        }
        else
        {
    //    RichEdit1->Lines->Add("����� ������� ���������!");
        Ed->Active=false;
        Ed->ParamByName("PARAM_SHED")->AsString=ADOTable2->FieldByName("BARCODE")->AsString;
        Ed->Open();

        if(Ed->RecordCount==0)   //������� �� �������
                {
         //       RichEdit1->Lines->Add("�� ������� ������� ���������! ");
                if (ADOTable2->FieldByName("BARCODE")->AsString!="")
                        {
        //                RichEdit1->Lines->Add("��������� �����  �������");
                        Ed->Insert();
                        EdIDNOMED->AsInteger=NomIDNOM->AsInteger;
                        EdNAMEED->AsString=ADOTable2->FieldByName("NAME")->AsString;
                        EdKFED->AsFloat=ADOTable2->FieldByName("K")->AsFloat;
                        EdTSHED->AsInteger=0;
                        EdSHED->AsString=ADOTable2->FieldByName("BARCODE")->AsString;
                        Ed->Post();
                        }
                }
        else     //������� �������
                {
       //         RichEdit1->Lines->Add("������� ������� ���������! ");
                if (NomIDNOM->AsInteger==EdIDNOMED->AsInteger)   //��������� �������������
                        {

                        if(EdNAMEED->AsString!=ADOTable2->FieldByName("NAME")->AsString )
                                {
                                Ed->Edit();
                                EdNAMEED->AsString=ADOTable2->FieldByName("NAME")->AsString;
                                Ed->Post();
                          //      RichEdit1->Lines->Add("�������� ������������  �������!");
                                }

                        if(EdKFED->AsFloat!=ADOTable2->FieldByName("K")->AsFloat)
                                {
                                Ed->Edit();
                                Ed->FieldByName("KFED")->AsFloat=ADOTable2->FieldByName("K")->AsFloat;
                                Ed->Post();
                              //  RichEdit1->Lines->Add("������� �����������  �������!");
                                }

                     //   if(EdTSHED")->AsInteger!=ADOTable1->FieldByName("TYPE_SH_E")->AsInteger)
                     //           {
                     //           Ed->Edit();
                     //           Ed->FieldByName("TSHED")->AsInteger=ADOTable1->FieldByName("TYPE_SH_E")->AsInteger;
                     //           Ed->Post();
                     //           RichEdit1->Lines->Add("������� ��� ����� ����  �������!");
                     //           }

                        if(EdSHED->AsString!=ADOTable2->FieldByName("BARCODE")->AsString )
                                {
                                Ed->Edit();
                                EdSHED->AsString=ADOTable2->FieldByName("BARCODE")->AsString;
                                Ed->Post();
                            //    RichEdit1->Lines->Add("������� ����� ���  �������!");
                                }

                        }
                else
                        {
                        ErrorUpdateSpr=true;
                        KolError++;
                        RichEdit1->Lines->Add("������! ����� ������� ����������� ������� ������!");
                        }
                }

        if (ADOTable1->FieldByName("SHBASED")->AsString==
                                ADOTable2->FieldByName("BARCODE")->AsString)
                {
                Nom->Edit();
                NomIDBASEDNOM->AsInteger=EdIDED->AsInteger;
                Nom->Post();
                }

        if (ADOTable1->FieldByName("SHOSNED")->AsString==
                                ADOTable2->FieldByName("BARCODE")->AsString)
                {
                Nom->Edit();
                NomIDOSNEDNOM->AsInteger=EdIDED->AsInteger;
                Nom->Post();
                }
        }
        ADOTable2->Next();
        }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void TFormaSagrPer::UpdatePrice(void)
{
int IdTypePrice=0;

while(!ADOTable3->Eof && ADOTable3->FieldByName("IDTOVAR")->AsInteger==
                                        ADOTable1->FieldByName("ID")->AsInteger)
        {

        if(ADOTable1->FieldByName("CODE")->AsInteger==0
                || NomIDNOM->AsInteger==0
                || NoUpdate==true)
        {
        }
        else
        {
        IdTypePrice=0;
     //   RichEdit1->Lines->Add("�������� �������� ����������� ���! "
     //                   +ADOTable3->FieldByName("NAME")->AsString);
        IdTypePrice=DMSprTypePrice->GetIDTypePrice(ADOTable3->FieldByName("NAME")->AsString);

        if (IdTypePrice>0)
                {     //��� ��� ������
                if(DMSprPrice->FindElement(IdTypePrice,Nom->FieldByName("IDNOM")->AsInteger)>0)
                        {
                        if(DMSprPrice->ElementZNACH_PRICE->AsFloat!=
                                 ADOTable3->FieldByName("ZNACH")->AsFloat)
                                {
                             //   RichEdit1->Lines->Add("�������� ����! "
                             //           +ADOTable3->FieldByName("NAME")->AsString);

                                Price->Active=false;
                                Price->ParamByName("PARAM_ID_PRICE")->AsInteger=
                                                DMSprPrice->ElementID_PRICE->AsInteger;
                                Price->Active=true;
                                Price->Edit();
                                PriceZNACH_PRICE->AsFloat=ADOTable3->FieldByName("ZNACH")->AsFloat;
                                Price->Post();
                                }

                        }
                else
                        {
                      //  RichEdit1->Lines->Add("��������� ����� ����! "
                      //                  +ADOTable3->FieldByName("NAME")->AsString);

                        Price->Active=false;
                        Price->ParamByName("PARAM_ID_PRICE")->AsInteger=0;
                        Price->Active=true;
                        Price->Insert();
                        PriceIDNOM_PRICE->AsInteger=NomIDNOM->AsInteger;
                        PriceIDTYPE_PRICE->AsInteger=IdTypePrice;
                        PriceZNACH_PRICE->AsFloat=ADOTable3->FieldByName("ZNACH")->AsFloat;
                        Price->Post();

                        }
                }
        else
                { //��� ��� �� ������
              //  RichEdit1->Lines->Add("�� ������ �������� ��� ���!");
                }
        }
        ADOTable3->Next();
        }

}
//----------------------------------------------------------------------------------


void TFormaSagrPer::CreateDocPrihNAkl(void)
{
RichEdit1->Lines->Add("  ");
RichEdit1->Lines->Add("�������  �������� ��������� ��������� "+Date()+" " +Time());
RichEdit1->Lines->Add("  ");
TFormaDocPrihNakl * PrNakl=new TFormaDocPrihNakl(Application);

PrNakl->DM->NewDoc();
PrNakl->DM->Doc->Edit();
PrNakl->DM->DocPRIMDOC->AsString=FileName;
PrNakl->DM->Doc->Post();
ADOTable1->First();
while (!ADOTable1->Eof)
        {


        Nom->Active=false;
        Nom->ParamByName("CODE")->AsInteger=ADOTable1->FieldByName("CODE_TOVAR")->AsInteger;
        Nom->Open();


        Ed->Active=false;
        Ed->ParamByName("SH")->AsString=ADOTable1->FieldByName("CODE_SH_E")->AsString;
        Ed->Open();


        if (Nom->RecordCount==1)    //������ �����
                {
                PrNakl->DM->AddDocNewString();
                PrNakl->DM->DocT->Edit();
                PrNakl->DM->DocT->FieldByName("IDNOMPRNT")->AsInteger=Nom->FieldByName("IDNOM")->AsInteger;
                PrNakl->DM->DocTNAMENOM->AsString=Nom->FieldByName("NAMENOM")->AsString;
                PrNakl->DM->DocTKOLPRNT->AsFloat=ADOTable1->FieldByName("KOL")->AsFloat;
                PrNakl->DM->DocTIDEDPRNT->AsInteger=Ed->FieldByName("IDED")->AsInteger;
                PrNakl->DM->DocTNAMEED->AsString=Ed->FieldByName("NAMEED")->AsString;
                PrNakl->DM->DocTKFPRNT->AsFloat=ADOTable1->FieldByName("KF")->AsFloat;
                PrNakl->DM->DocTPRICEPRNT->AsFloat=ADOTable1->FieldByName("PRICE")->AsFloat;
                PrNakl->DM->DocTSUMPRNT->AsFloat=ADOTable1->FieldByName("KOL")->AsFloat*
                        ADOTable1->FieldByName("PRICE")->AsFloat;
                PrNakl->DM->DocTTNOM->AsInteger=Nom->FieldByName("TNOM")->AsInteger;


                PrNakl->DM->DocT->Post();
                }
        else
                {
                RichEdit1->Lines->Add("����� �� ������! ");
                }

        ADOTable1->Next();
        }

Nom->Close();
Ed->Close();


RichEdit1->Lines->Add("������ �������� ��������� ��������� � "+IntToStr(PrNakl->DM->DocAllNUMDOC->AsInteger));



}
//---------------------------------------------------------------------------------
void __fastcall TFormaSagrPer::ButtonTestClick(TObject *Sender)
{
KolError=0;

DataSource1->Enabled=false;
DataSource2->Enabled=false;
DataSource3->Enabled=false;

IBTr->StartTransaction();
SprTPrice->Close();
SprTPrice->Active=true;

RichEdit1->Lines->Add("������ ������������ ����������� �������� ��������� "+Date()+" " +Time());
RichEdit1->Lines->Add("���� ���������:"+FileName);

ADOTable1->First();
ADOTable2->First();
ADOTable3->First();

ProgressBar1->Max=ADOTable1->RecordCount;
ProgressBar1->Step=1;

while (!ADOTable1->Eof)
        {
        ProgressBar1->StepIt();
        RichEdit1->Lines->Add("  ");
        RichEdit1->Lines->Add("������ ������ �"+IntToStr(ADOTable1->RecNo)
        +" ���: "+ADOTable1->FieldByName("CODE")->AsInteger
        +"  ������������:"+ADOTable1->FieldByName("NAME")->AsString);

        NomR->Close();
        NomR->ParamByName("PARAM_CODENOM")->AsInteger=ADOTable1->FieldByName("CODE")->AsInteger;
        NomR->ExecQuery();
        if (NomR->RecordCount==0)    //�� ������ �����
                {
                RichEdit1->Lines->Add("���������� ������ ������������! ");

                //�������� ��� �� ������ � ����� ����� ����� � ����
                while(!ADOTable2->Eof && ADOTable2->FieldByName("IDTOVAR")->AsInteger==
                                        ADOTable1->FieldByName("ID")->AsInteger)
                        {
                        RichEdit1->Lines->Add("��������  �������:"+
                                        ADOTable2->FieldByName("NAME")->AsString+
                                        ADOTable2->FieldByName("BARCODE")->AsString);
                                        
                        EdR->Close();
                        EdR->ParamByName("PARAM_SHED")->AsString=ADOTable2->FieldByName("BARCODE")->AsString;
                        EdR->ExecQuery();

                        if(EdR->RecordCount>0)   //������� �������
                                {
                                RichEdit1->Lines->Add("������! ����� ����� ��� ��� ���� � ����!!!");
                                }
                        RichEdit1->Lines->Add("��������  ������� ���������!");
                        ADOTable2->Next();
                        }

                }
        else
                {
                if (NomR->RecordCount==1)
                        {
                        //��������� ��������� ������
                        if(NomR->FieldByName("NAMENOM")->AsString!=ADOTable1->FieldByName("NAME")->AsString)
                                {
                                RichEdit1->Lines->Add("��������� ���� ������������!");
                                }

                       // if(Nom->FieldByName("FNAMENOM")->AsString!=ADOTable1->FieldByName("NAME_FULL")->AsString)
                       //         {
                       //         RichEdit1->Lines->Add("��������� ���� ������ ������������!");
                       //         }

                        if(NomR->FieldByName("CODENOM")->AsInteger!=ADOTable1->FieldByName("CODE")->AsInteger)
                                {
                                RichEdit1->Lines->Add("��������� ���� ��� ������!!!");
                                }

                        //if(Nom->FieldByName("PRICE1NOM")->AsFloat!=ADOTable1->FieldByName("PRICE_1")->AsFloat)
                        //        {
                        //        RichEdit1->Lines->Add("��������� ���� ��������� ����!");
                        //        }

                        //if(Nom->FieldByName("PRICEZNOM")->AsFloat!=ADOTable1->FieldByName("PRICE_ZAK")->AsFloat)
                        //        {
                         //       RichEdit1->Lines->Add("��������� ���� ���� �������!");
                         //       }

                        //if(Nom->FieldByName("TNOM")->AsInteger!=ADOTable1->FieldByName("TYPE_TOVAR")->AsInteger)
                       //         {
                       ///         RichEdit1->Lines->Add("��������� ���� ��� ������������!");
                       //         }

                         //��������� �������

                        }
                else     //��������� ������� � ���������� �����
                        {
                        KolError++;
                        RichEdit1->Lines->Add("������! ��������� ������� � ���������� �����!");
                        }


                }

        ProveritSprEd();
        ProveritSprPrice();
        ADOTable1->Next();
        }

Nom->Close();
Ed->Close();

RichEdit1->Lines->Add("������������ ���������: "+Date()+" " +Time());
RichEdit1->Lines->Add("������: "+IntToStr(KolError));

IBTr->Rollback();

DataSource1->Enabled=true;
DataSource2->Enabled=true;
DataSource3->Enabled=true;
}
//---------------------------------------------------------------------------
void TFormaSagrPer::ProveritSprEd(void)
{

while(!ADOTable2->Eof  && ADOTable2->FieldByName("IDTOVAR")->AsInteger==
                                        ADOTable1->FieldByName("ID")->AsInteger )
        {
        RichEdit1->Lines->Add("��������  �������:"+
                ADOTable2->FieldByName("NAME")->AsString+
                ADOTable2->FieldByName("BARCODE")->AsString);
        RichEdit1->Lines->Add("�������� ������� �������!");
        EdR->Close();
        EdR->ParamByName("PARAM_SHED")->AsString=ADOTable2->FieldByName("BARCODE")->AsString;
        EdR->ExecQuery();

        if(EdR->RecordCount==0)   //������� �� �������
                {
                RichEdit1->Lines->Add("����� ��������� ����� ������� �������");
                }
        else     //������� �������
                {
                if (NomR->FieldByName("IDNOM")->AsInteger==EdR->FieldByName("IDNOMED")->AsInteger)
                        {

                        if(EdR->FieldByName("NAMEED")->AsString!=ADOTable2->FieldByName("NAME")->AsString )
                                {
                                RichEdit1->Lines->Add("�������� ������������ �������!");
                                }

                        if(EdR->FieldByName("KFED")->AsFloat!=ADOTable2->FieldByName("K")->AsFloat)
                                {
                                RichEdit1->Lines->Add("������� �����������  �������!");
                                }

                        //if(Ed->FieldByName("TSHED")->AsInteger!=ADOTable1->FieldByName("TYPE_SH_BE")->AsInteger)
                        //        {
                        //        RichEdit1->Lines->Add("�������� ��� ����� ����  �������!");
                        //        }

                        if(EdR->FieldByName("SHED")->AsString!=ADOTable2->FieldByName("BARCODE")->AsString )
                                {
                                RichEdit1->Lines->Add("������� ����� ���  �������!");
                                }

                        if(NomR->FieldByName("IDBASEDNOM")->AsInteger!=EdR ->FieldByName("IDED")->AsInteger)
                                {
                                RichEdit1->Lines->Add("��������! ��������  ������� �������!");
                                }

                        }
                else
                        {
                        KolError++;
                        RichEdit1->Lines->Add("������! ����� ������� ����������� ������� ������!");
                        }

                }

        RichEdit1->Lines->Add("��������  ������� ���������!");
        ADOTable2->Next();
        }
}
//------------------------------------------------------------------------------
void TFormaSagrPer::ProveritSprPrice(void)
{


while(!ADOTable3->Eof  && ADOTable3->FieldByName("IDTOVAR")->AsInteger==
                                        ADOTable1->FieldByName("ID")->AsInteger )
        {
        
        RichEdit1->Lines->Add("�������� �������� ����������� ���! "
                        +ADOTable3->FieldByName("NAME")->AsString);
        int IdTypePrice=0;
        IdTypePrice=GetIdTypePrice(ADOTable3->FieldByName("NAME")->AsString);
        if (IdTypePrice>0)
                {     //��� ��� ������

                PriceR->Close();
                PriceR->ParamByName("PARAM_IDNOM")->AsInteger=
                        NomR->FieldByName("IDNOM")->AsInteger;
                PriceR->ParamByName("PARAM_IDTYPE_PRICE")->AsInteger=IdTypePrice;
                PriceR->ExecQuery();

                if(PriceR->RecordCount>0)
                        {
                        if(PriceR->FieldByName("ZNACH_PRICE")->AsFloat!=
                                 ADOTable3->FieldByName("ZNACH")->AsFloat)
                                {
                                RichEdit1->Lines->Add("����� �������� ����! "
                                        +ADOTable3->FieldByName("NAME")->AsString);
                                }

                        }
                else
                        {
                        RichEdit1->Lines->Add("����� ��������� ����� ����! "
                                        +ADOTable3->FieldByName("NAME")->AsString);
                        }
                }
        else
                { //��� ��� �� ������
                RichEdit1->Lines->Add("�� ������ �������� ��� ���!");
                }

        RichEdit1->Lines->Add("�������� �������� ����������� ���������! " );
        ADOTable3->Next();
        }
}
//-----------------------------------------------------------------------------
void __fastcall TFormaSagrPer::FormResize(TObject *Sender)
{
ProgressBar1->Width=PageControl1->Width;        
}
//---------------------------------------------------------------------------
int TFormaSagrPer::GetIdTypePrice(String name)
{
int result=0;
SprTPrice->First();
while(!SprTPrice->Eof)
        {
        if (SprTPrice->FieldByName("NAME_TPRICE")->AsString==name)
                {
                result=SprTPrice->FieldByName("ID_TPRICE")->AsInteger;
                }
        SprTPrice->Next();
        }
return result;
}
//----------------------------------------------------------------------------


void __fastcall TFormaSagrPer::ButtonBistrZagrClick(TObject *Sender)
{
Zagruska();
}
//---------------------------------------------------------------------------
//****************************************************************************
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void TFormaSagrPer::Zagruska(void)
{
ErrorUpdateSpr=false;
KolError=0;

DataSource1->Enabled=false;
DataSource2->Enabled=false;
DataSource3->Enabled=false;

RichEdit1->Lines->Add("  ");
RichEdit1->Lines->Add("������  �������� ��������� "+Date()+" " +Time());
RichEdit1->Lines->Add("���� ���������:"+FileName);

if(UpdateGrpCheckBox->Checked==true)
        {
        RichEdit1->Lines->Add("  ");
        RichEdit1->Lines->Add("���������� ����� ����������� ������������!");
        UpdateGrp();
        }

RichEdit1->Lines->Add("  ");
RichEdit1->Lines->Add("���������� ����������� ������� � ����������� ������!");
        ProgressBar1->Max=ADOTable1->RecordCount;
        ProgressBar1->Step=1;
        NoUpdate=false;
        ADOTable1->First();
        ADOTable2->First();
        ADOTable3->First();

        while (!ADOTable1->Eof)
                {
                ProgressBar1->StepIt();
               // RichEdit1->Lines->Add("  ");
               // RichEdit1->Lines->Add("C����� �"+IntToStr(ADOTable1->RecNo)
               //  +" ���: "+ADOTable1->FieldByName("CODE")->AsInteger
              //  +"  ������������:"+ADOTable1->FieldByName("NAME")->AsString);

try
        {


			   IBTrUpdate->StartTransaction();
               SprTPrice->Active=true;

                NomR->Close();
                NomR->ParamByName("PARAM_CODENOM")->AsInteger=ADOTable1->FieldByName("CODE")->AsInteger;
                NomR->ExecQuery();
                IdNom=NomR->FieldByName("IDNOM")->AsInteger;

           //     RichEdit1->Lines->Add("����� ������ � ����! ");
                if (NomR->RecordCount==0)    //�� ������ �����
                        {
                    //    RichEdit1->Lines->Add("����� �� ������! ");
                    //    RichEdit1->Lines->Add("��������� ����� ������� ������������! ");
                        AddNewTovar1();
                        }
                else
                        {
                        // ������ �����
                        if (NomR->RecordCount==1)
                                {
                      //          RichEdit1->Lines->Add("����� ������ � ����! ");
                                //��������� ��������� ������
                                EditTovar1();

                                }
                        else     //��������� ������� � ���������� �����
                                {
                                ErrorUpdateSpr=true;
                                NoUpdate=true;
                                KolError++;
                                RichEdit1->Lines->Add("������! ��������� ������� � ���������� �����!");
                                }
                        }

                //��������� �������
          //      RichEdit1->Lines->Add("������������ ������� ������!");
                UpdateEd1();

                //��������� ����
          //      RichEdit1->Lines->Add("������������ ������� ���!");
                UpdatePrice1();
               

		IBTrUpdate->Commit();

        }

catch(...)
       {
       IBTrUpdate->Rollback();
       }


                ADOTable1->Next();
                NoUpdate=false;
                }

RichEdit1->Lines->Add("�������� ���������! ");
//RichEdit1->Lines->Add("������: "+IntToStr(KolError));

DataSource1->Enabled=true;
DataSource2->Enabled=true;
DataSource3->Enabled=true;

}

//---------------------------------------------------------------------------
void TFormaSagrPer::AddNewTovar1()
{
if (ADOTable1->FieldByName("SHBASED")->AsString=="")  return;
if(ADOTable1->FieldByName("SHOSNED")->AsString=="" ) return;
if(ADOTable1->FieldByName("CODE")->AsInteger==0 ) return;
if(NoUpdate==true ) return;

//������� �������� ����������
IdNom=0;

Zapros=" select GEN_ID(GEN_SNOM_ID,1) from RDB$DATABASE";
IBSQL->Close();
IBSQL->SQL->Clear();
IBSQL->SQL->Add(Zapros);
IBSQL->ExecQuery();

IdNom=IBSQL->FieldByName("GEN_ID")->AsInteger;

Zapros="";
Zapros=Zapros+" insert into SNOM   ";

if ( ADOTable1->FieldByName("CODEGRP")->AsInteger>0 && UpdateGrpCheckBox->Checked==true)
        {
        Zapros=Zapros+" (IDNOM,TNOM, CODENOM, IDGRPNOM, NAMENOM, FNAMENOM, KRNAMENOM )  ";
        }
else
        {
        Zapros=Zapros+" (IDNOM,TNOM, CODENOM, NAMENOM, FNAMENOM, KRNAMENOM )  ";
        }

Zapros=Zapros+" values (  ";
Zapros=Zapros+" '"+IntToStr(IdNom)+"',";
Zapros=Zapros+" '0',";
Zapros=Zapros+" '"+ IntToStr(ADOTable1->FieldByName("CODE")->AsInteger)+"',";

if ( ADOTable1->FieldByName("CODEGRP")->AsInteger>0 && UpdateGrpCheckBox->Checked==true)
        {
        Zapros=Zapros+" '"+ IntToStr(ADOTable1->FieldByName("CODEGRP")->AsInteger)+"',";
        }

Zapros=Zapros+" '"+ ADOTable1->FieldByName("NAME")->AsString+"',";
Zapros=Zapros+" '"+ ADOTable1->FieldByName("NAME")->AsString+"',";
Zapros=Zapros+" '"+ ADOTable1->FieldByName("NAME")->AsString+"'";
Zapros=Zapros+" )  ";

IBSQL->Close();
IBSQL->SQL->Clear();
IBSQL->SQL->Add(Zapros);
IBSQL->ExecQuery();


}

//---------------------------------------------------------------------------
void TFormaSagrPer::EditTovar1()
{

Zapros="";
Zapros=Zapros+" update SNOM set   ";
Zapros=Zapros+" CODENOM = '"+ IntToStr(ADOTable1->FieldByName("CODE")->AsInteger)+"',";

if(ADOTable1->FieldByName("CODEGRP")->AsInteger>0 && UpdateGrpCheckBox->Checked==true)
        {
        Zapros=Zapros+" IDGRPNOM = '"+ IntToStr(ADOTable1->FieldByName("CODEGRP")->AsInteger)+"',";
        }

Zapros=Zapros+" NAMENOM = '"+ ADOTable1->FieldByName("NAME")->AsString+"',";
Zapros=Zapros+" FNAMENOM = '"+ ADOTable1->FieldByName("NAME")->AsString+"',";
Zapros=Zapros+" KRNAMENOM = '"+ ADOTable1->FieldByName("NAME")->AsString+"'";
Zapros=Zapros+" where IDNOM ='"+IntToStr(IdNom)+"'";

IBSQL->Close();
IBSQL->SQL->Clear();
IBSQL->SQL->Add(Zapros);
IBSQL->ExecQuery();

}

//-------------------------------------------------------------------------
void TFormaSagrPer::UpdateEd1(void)
{

while (!ADOTable2->Eof  && ADOTable2->FieldByName("IDTOVAR")->AsInteger==
                                        ADOTable1->FieldByName("ID")->AsInteger)
        {
        if(ADOTable2->FieldByName("BARCODE")->AsString==""
                || ADOTable1->FieldByName("CODE")->AsInteger==0
                || IdNom==0
                || NoUpdate==true)
        {
        }
        else
        {

      //  RichEdit1->Lines->Add("����� ������� ���������!");
        EdR->Close();
        EdR->ParamByName("PARAM_SHED")->AsString=ADOTable2->FieldByName("BARCODE")->AsString;
        EdR->ExecQuery();
        IdEd=EdR->FieldByName("IDED")->AsInteger;

        if(EdR->RecordCount==0)   //������� �� �������
                {
           //     RichEdit1->Lines->Add("�� ������� ������� ���������! ");
                if (ADOTable2->FieldByName("BARCODE")->AsString!="")
                        {
                  //      RichEdit1->Lines->Add("��������� �����  �������");

                        IdEd=0;
                        Zapros=" select GEN_ID(GEN_SED_ID,1) from RDB$DATABASE";
                        IBSQL->Close();
                        IBSQL->SQL->Clear();
                        IBSQL->SQL->Add(Zapros);
                        IBSQL->ExecQuery();
                        IdEd=IBSQL->FieldByName("GEN_ID")->AsInteger;

                        Zapros="";
                        Zapros=Zapros+" insert into SED   ";
                        Zapros=Zapros+" (IDED,IDNOMED, NAMEED, KFED, TSHED, SHED )  ";
                        Zapros=Zapros+" values (  ";
                        Zapros=Zapros+" '"+IntToStr(IdEd)+"',";
                        Zapros=Zapros+" '"+ IntToStr(IdNom)+"',";
                        Zapros=Zapros+" '"+ ADOTable2->FieldByName("NAME")->AsString+"',";
                        Zapros=Zapros+" '"+ ADOTable2->FieldByName("K")->AsString+"',";
                        Zapros=Zapros+" '0',";
                        Zapros=Zapros+" '"+ ADOTable2->FieldByName("BARCODE")->AsString+"'";
                        Zapros=Zapros+" )  ";

                        IBSQL->Close();
                        IBSQL->SQL->Clear();
                        IBSQL->SQL->Add(Zapros);
                        IBSQL->ExecQuery();
                        }
                }
        else     //������� �������
                {
             //   RichEdit1->Lines->Add("������� ������� ���������! ");
                if (IdNom==EdR->FieldByName("IDNOMED")->AsInteger)   //��������� �������������
                        {
                        Zapros="";
                        Zapros=Zapros+" update SED set   ";
                        Zapros=Zapros+" NAMEED = '"+ ADOTable2->FieldByName("NAME")->AsString+"',";
                        Zapros=Zapros+" KFED = '"+ ADOTable2->FieldByName("K")->AsFloat+"'";
                        Zapros=Zapros+" where IDED ='"+IntToStr(IdEd)+"'";

                        IBSQL->Close();
                        IBSQL->SQL->Clear();
                        IBSQL->SQL->Add(Zapros);
                        IBSQL->ExecQuery();
                        }
                else
                        {
                        ErrorUpdateSpr=true;
                        KolError++;
                        RichEdit1->Lines->Add("������! ����� ������� ����������� ������� ������!");
                        }
                }

        if (ADOTable1->FieldByName("SHBASED")->AsString==
                                ADOTable2->FieldByName("BARCODE")->AsString)
                {
                Zapros="";
                Zapros=Zapros+" update SNOM set   ";
                Zapros=Zapros+" IDBASEDNOM = '"+ IntToStr(IdEd)+"'";
                Zapros=Zapros+" where IDNOM ='"+IntToStr(IdNom)+"'";

                IBSQL->Close();
                IBSQL->SQL->Clear();
                IBSQL->SQL->Add(Zapros);
                IBSQL->ExecQuery();
                }

        if (ADOTable1->FieldByName("SHOSNED")->AsString==
                                ADOTable2->FieldByName("BARCODE")->AsString)
                {
                Zapros="";
                Zapros=Zapros+" update SNOM set   ";
                Zapros=Zapros+" IDOSNEDNOM = '"+ IntToStr(IdEd)+"'";
                Zapros=Zapros+" where IDNOM ='"+IntToStr(IdNom)+"'";

                IBSQL->Close();
                IBSQL->SQL->Clear();
                IBSQL->SQL->Add(Zapros);
                IBSQL->ExecQuery();
                }
        }
        ADOTable2->Next();
        }
}
//---------------------------------------------------------------------------
void TFormaSagrPer::UpdatePrice1(void)
{
int IdTypePrice=0;

while(!ADOTable3->Eof && ADOTable3->FieldByName("IDTOVAR")->AsInteger==
                                        ADOTable1->FieldByName("ID")->AsInteger)
        {

        if(ADOTable1->FieldByName("CODE")->AsInteger==0
                || IdNom==0
                || NoUpdate==true)
        {
        }
        else
        {
        IdTypePrice=0;
     //   RichEdit1->Lines->Add("�������� �������� ����������� ���! "
     //                   +ADOTable3->FieldByName("NAME")->AsString);
        IdTypePrice=IdTypePrice=GetIdTypePrice(ADOTable3->FieldByName("NAME")->AsString);

        if (IdTypePrice>0)
                {     //��� ��� ������
                PriceR->Close();
                PriceR->ParamByName("PARAM_IDNOM")->AsInteger=IdNom;
                PriceR->ParamByName("PARAM_IDTYPE_PRICE")->AsInteger=IdTypePrice;
                PriceR->ExecQuery();
                IdPrice=0;
                IdPrice=PriceR->FieldByName("ID_PRICE")->AsInteger;
                if(PriceR->RecordCount>0)
                        {
                        if(PriceR->FieldByName("ZNACH_PRICE")->AsFloat!=
                                 ADOTable3->FieldByName("ZNACH")->AsFloat)
                                {
                            //    RichEdit1->Lines->Add("�������� ����! "
                            //            +ADOTable3->FieldByName("NAME")->AsString);

                                Zapros="";
                                Zapros=Zapros+" update SPRICE set   ";
                                Zapros=Zapros+" ZNACH_PRICE ="+ FloatToStringComma(ADOTable3->FieldByName("ZNACH")->AsFloat);
                                Zapros=Zapros+" where ID_PRICE ='"+IntToStr(IdPrice)+"'";
                                //ShowMessage(Zapros);
                                IBSQL->Close();
                                IBSQL->SQL->Clear();
                                IBSQL->SQL->Add(Zapros);
                                IBSQL->ExecQuery();
                                }

                        }
                else
                        {
                   //     RichEdit1->Lines->Add("��������� ����� ����! "
                   //                     +ADOTable3->FieldByName("NAME")->AsString);

                        Zapros="";
                        Zapros=Zapros+" insert into SPRICE   ";
                        Zapros=Zapros+" (IDNOM_PRICE, IDTYPE_PRICE, ZNACH_PRICE )  ";
                        Zapros=Zapros+" values (  ";
                        Zapros=Zapros+" '"+IntToStr(IdNom)+"',";
                        Zapros=Zapros+" '"+ IntToStr(IdTypePrice)+"', ";
                        Zapros=Zapros+ FloatToStringComma(ADOTable3->FieldByName("ZNACH")->AsFloat);
                        Zapros=Zapros+" )  ";

                        IBSQL->Close();
                        IBSQL->SQL->Clear();
                        IBSQL->SQL->Add(Zapros);
                        IBSQL->ExecQuery();
                        }
                }
        else
                { //��� ��� �� ������
             //   RichEdit1->Lines->Add("�� ������ �������� ��� ���!");
                }
        }
        ADOTable3->Next();
        }

}
//-------------------------------------------------------------------------
void TFormaSagrPer::UpdateGrp(void)
{
TDMSprGrpNom * DMGrp=new TDMSprGrpNom(Application);
ADOTable4->First();
while (!ADOTable4->Eof  && UpdateGrpCheckBox->Checked==true)
        {
        String S="";

        if(DMGrp->OpenElement(ADOTable4->FieldByName("CODE")->AsInteger)>0)
                {
                DMGrp->Element->Edit();
                S=S+" ����������: ";
                }
        else
                {
                S=S+" ����� ������: ";
                DMGrp->Element->Insert();
                DMGrp->ElementIDGN->AsInteger=ADOTable4->FieldByName("CODE")->AsInteger;
                }
        S=S+" ������ "+ADOTable4->FieldByName("CODE")->AsString
                        +" "+ADOTable4->FieldByName("NAME")->AsString
                        +" ���. ������: "+ADOTable4->FieldByName("CODEGRP")->AsString;
        DMGrp->ElementNAMEGN->AsString=ADOTable4->FieldByName("NAME")->AsString;
        if (ADOTable4->FieldByName("CODEGRP")->AsInteger>0)
                {
                DMGrp->ElementIDGRPGN->AsInteger=ADOTable4->FieldByName("CODEGRP")->AsInteger;
                }
        DMGrp->Element->Post();
        DMGrp->SaveElement();
        RichEdit1->Lines->Add(S);
       // ShowMessage(S);
        ADOTable4->Next();
        }
delete DMGrp;
}
//----------------------------------------------------------------------------------
String TFormaSagrPer::FloatToStringComma(double value)
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
//-----------------------------------------------------



