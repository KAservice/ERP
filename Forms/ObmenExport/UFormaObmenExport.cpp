//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaObmenExport.h"
#include "UDM.h"
#include "UDMSetup.h"
#include "UDMXMessageObmen.h"
#include <fstream.h>
#include "UDMSprObmenTypePrice.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TFormaObmenExport::TFormaObmenExport(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TFormaObmenExport::FormCreate(TObject *Sender)
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
void __fastcall TFormaObmenExport::FormClose(TObject *Sender, TCloseAction &Action)
{

Action=caFree;
}
//----------------------------------------------------------------------------
void __fastcall TFormaObmenExport::EndEdit(TObject *Sender)
{
if (ViborRekvisit==ViborBase)
        {

        if (SpisokBase->OutReady==true)
                {
                IdBase=SpisokBase->DM->TableID_SINFBASE_OBMEN->AsInteger;
                PrefiksBase=SpisokBase->DM->TablePREFIKS_SINFBASE_OBMEN->AsString;
                NameBaseLabel->Caption=PrefiksBase+" - "+SpisokBase->DM->TableNAME_SINFBASE_OBMEN->AsString;
                CatalogObmena=SpisokBase->DM->TableOUTPATCH_SINFBASE_OBMEN->AsString;
                LabelFileNameOut->Caption=CatalogObmena;
                StartIDTableIsm=SpisokBase->DM->TableIDTIZM_SINFBASE_OBMEN->AsInteger;
                }
        }
ViborRekvisit=NO;
IdDochForm=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormaObmenExport::ButtonOpenFileClick(TObject *Sender)
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
String TFormaObmenExport::FloatToStringComma(double value)
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
double TFormaObmenExport::StringToFloatComma(String value)
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

void __fastcall TFormaObmenExport::ButtonVigrClick(TObject *Sender)
{

CreateXMLDoc(IdBase);

}

//-------------------------------------------------------------------------------------
void __fastcall TFormaObmenExport::ButtonViborBaseClick(TObject *Sender)
{
OpenFormSpiskaSprInfBase();
}
//---------------------------------------------------------------------------
void TFormaObmenExport::OpenFormSpiskaSprInfBase(void)
{
if (IdDochForm==NULL)
        {
        SpisokBase=new TFormaSpiskaSprInfBase(Application);
        if (!SpisokBase) return;
        SpisokBase->IdRodForm=Handle;
        SpisokBase->Vibor=true;
        IdDochForm=SpisokBase->Handle;
        ViborRekvisit=ViborBase;
        SpisokBase->Show();
        SpisokBase->FOnCloseForm=EndEdit;
        }  
}
//-------------------------------------------------------------------------
void __fastcall TFormaObmenExport::ButtonCreateDataClick(TObject *Sender)
{
CreateDataOutTable(IdBase);
}
//---------------------------------------------------------------------------

void TFormaObmenExport::CreateDataOutTable(int id_base)
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
ProgressBar1->Max=TableIsm->Table->RecNo;
//ShowMessage(IntToStr(TableDataOut->RecordCount));
ProgressBar1->Step=1;


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
        ProgressBar1->StepIt();
        }
delete DMTypeDoc;
delete DMSprObmenSklad;
delete TableIsm;
delete DataOut;
ShowMessage("Подготовка данных завершена!");
}
//-----------------------------------------------------------------------------
void TFormaObmenExport::AddSprInDataTable(void)
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
void TFormaObmenExport::AddDocInDataTable(void)
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
bool TFormaObmenExport::CheckGALLDOC(void)
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
bool TFormaObmenExport::CheckDPER(void)
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
bool TFormaObmenExport::CheckDPERT(void)
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
bool TFormaObmenExport::CheckDCHK(void)
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
bool TFormaObmenExport::CheckDCHKT(void)
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
bool TFormaObmenExport::CheckDocForTypeDoc(String type_doc)
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
bool TFormaObmenExport::CheckDocForSklad(int id_sklad)
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


void __fastcall TFormaObmenExport::ButtonCloseClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------
void TFormaObmenExport::CreateXMLDoc(int id_base)
{
IdBase=id_base;
if (IdBase==0) return;


TDMXMessageObmen *DMMessage=new TDMXMessageObmen(Application);
DMMessage->NewElement(IdBase);
DMMessage->ElementOUT_XMESSAGE_OBMEN->AsInteger=1;
DMMessage->SaveElement();
int id_message=DMMessage->ElementID_XMESSAGE_OBMEN->AsInteger;

//сохраняем в файл
FileNameOut=CatalogObmena+"\\"+PrefiksBase+"_"+
                Trim(DMMessage->ElementGID_XMESSAGE_OBMEN->AsString)+".xml";

SaveFileXML("<?xml version=\"1.0\" encoding=\"windows-1251\"?>");
SaveFileXML("<data>");
TableDataOut->Active=false;
TableDataOut->ParamByName("PARAM_IDBASE")->AsInteger=IdBase;
TableDataOut->Active=true;

TableFields->Active=true;
TableFK->Active=true;
TablePK->Active=true;

TableDataOut->Last();
ProgressBar1->Max=TableDataOut->RecNo;
LabelTotalIsm->Caption="Всего изменений: "+IntToStr(TableDataOut->RecNo);
LabelTotalIsm->Update();
ProgressBar1->Step=1;
int kol_rec=0;

DMXTableBase=new TDMXTableBase(Application);
DMXFieldBase=new TDMXFieldBase(Application);


TableDataOut->First();
while(!TableDataOut->Eof)
        { 

        if ( TableDataOutTYPEOB_XTISM->AsInteger==1)//справочник
                {
                OutputSprInXMLFile(Trim(TableDataOutNAMETAB_XTISM->AsString),
                                TableDataOutIDREC_XTISM->AsInteger);
                }

        if ( TableDataOutTYPEOB_XTISM->AsInteger==2)//документ
                {
                OutputDocInXMLFile(Trim(TableDataOutNAMETAB_XTISM->AsString),
                                TableDataOutIDREC_XTISM->AsInteger);
                }

        TableDataOut->Next();

        kol_rec++;
        LabelZagrIsm->Caption="выгружено изменений: "+IntToStr(kol_rec);
        LabelZagrIsm->Update();
        ProgressBar1->StepIt();

        }


SaveFileXML("</data>");


TableDataOut->First();
while(!TableDataOut->Eof)
        {
        TableDataOut->Edit();
        TableDataOutIDMESSAGE_XDATA_OUT->AsInteger=id_message;
        TableDataOut->Post();

        TableDataOut->Next();
        }
TableDataOut->ApplyUpdates();
IBTr->Commit();

LabelFileNameOut->Caption=FileNameOut;
delete DMMessage;


TableDataOut->Active=false;

delete DMXTableBase;
delete DMXFieldBase;



TableFields->Active=false;
TableFK->Active=false;
TablePK->Active=false;
ShowMessage("выгрузка данных завершена!");
}
//-----------------------------------------------------------------------------
void TFormaObmenExport::OutputSprInXMLFile(String table_name, int id_record)
{
OutputTableInXMLFile(table_name, id_record);
}
//----------------------------------------------------------------------------
void TFormaObmenExport::OutputDocInXMLFile(String table_name, int id_record)
{
///необходимо выгрузить не только заголовок документа
//но также шапку и табличную часть

OutputTableInXMLFile(table_name, id_record);
}
//----------------------------------------------------------------------------
void TFormaObmenExport::OutputTableInXMLFile(String table_name, int id_record)
{

DMXTableBase->GetElementPoName(table_name);
DMXFieldBase->OpenTable(DMXTableBase->ElementID_XTABLE_BASE->AsInteger);

String name_pk=Trim(DMXTableBase->ElementNAMEPK_XTABLE_BASE->AsString); //наименование первичного ключа

//открываем запись
String zapros="";
IBQ->Active=false;
IBQ->SQL->Clear();
zapros=zapros+"select * from "+table_name;
zapros=zapros+" where "+name_pk+"="+IntToStr(id_record);
IBQ->SQL->Add(zapros);
IBQ->Active=true;

if (IBQ->RecordCount!=1) return;


String name_gid=Trim(DMXTableBase->ElementNAMEGID_XTABLE_BASE->AsString);
String value_gid=Trim(IBQ->FieldByName(name_gid)->AsString);//получим значение Gid

//создаем узел с названием таблицы
String S="  ";
S=S+"<"+table_name+" oper=\""+Trim(TableDataOutOPER_XTISM->AsString)+"\"";
S=S+" name_gid=\""+name_gid+"\""+" value_gid=\""+value_gid+"\"";
S=S+" name_pk=\""+name_pk+"\"";
S=S+">";
SaveFileXML(S);

//выгрузить запись в файл    заменить все внешние ключи на GID
DMXFieldBase->Table->First();
while(!DMXFieldBase->Table->Eof)
        {
        String name_field=Trim(DMXFieldBase->TableNAME_XFIELD_BASE->AsString);
        String value_field="";
        
        //проверим надо ли выгружать поле
        if (CheckFieldForOutput(name_field, table_name)==false)
                {
                DMXFieldBase->Table->Next();
                continue;
                }

        int type_field=DMXFieldBase->TableTYPE_XFIELD_BASE->AsInteger;

        switch (type_field)
                {  
                case 35 :  //TIMESTAMP
                        {
                        DateTimeToString(value_field,"dd.mm.yyyy h\":\"nn\":\"ss",IBQ->FieldByName(name_field)->AsDateTime);
                        } break;

                default :
                        {
                        value_field=IBQ->FieldByName(name_field)->AsString;
                        } break;
                }



        if (DMXFieldBase->TableFK_XFIELD_BASE->AsInteger==1)
                {
                //а если внешний ключ то необходимо найти название таблицы на
                //которую внешний ключ и поле, а затем получить GID записи
                OutputFKInXMLFile(name_field, IBQ->FieldByName(name_field)->AsInteger);

                }
        else
                {
                //если поле не является внешним ключем тогда
                String S="    ";
                S=S+"<"+name_field+" v=\""+FormatForXML(value_field)+"\"";
                S=S+" fk=\"\"";
                S=S+"/>";
                SaveFileXML(S);
                }

        DMXFieldBase->Table->Next();
        }


S="  ";
S=S+"</"+table_name+">";
SaveFileXML(S);
IBQ->Active=false;
//IBQ2->Active=false;
}
//------------------------------------------------------------------------------
bool TFormaObmenExport::CheckFieldForOutput(String name_field, String name_table)
{
bool result=false;
if (name_field=="PRDOC") return result;
if (name_field=="PRICEZPART") return result;
if (name_field=="IDPARTPERT") return result;

if (name_field=="PRICEOSNT") return result;
if (name_field=="SUMOSNT") return result;

if (name_field=="PRICESPNT") return result;
if (name_field=="SUMSPNT") return result;

if (name_table=="GALLDOC")
        {
        String type_doc=Trim(IBQ->FieldByName("TDOC")->AsString);

        if (type_doc=="OSN")
                {
                if (name_field=="SUMDOC")return result;
                }
        if (type_doc=="SPN")
                {
                if (name_field=="SUMDOC")return result;
                }
        } 
        
result=true;
return result;

}

//----------------------------------------------------------------------
void TFormaObmenExport::OutputFKInXMLFile(String name_field, int value_field)
{

        String name_table_fk=Trim(DMXFieldBase->TableTABLEFK_XFIELD_BASE->AsString);     //таблица на которую ссылается ключ
        String name_field_fk=Trim(DMXFieldBase->TableFIELDFK_XFIELD_BASE->AsString);      //имя поля на которое ссылается ключ
        String name_field_gid_fk=Trim(DMXFieldBase->TableGIDFK_XFIELD_BASE->AsString);  //имя поля которое является GID ом
        String value_gid_fk="";        //значение GID поля внешнего ключа
        String name_index="";

                //получим значение GIDа
                IBQ2->Active=false;
                IBQ2->SQL->Clear();
                String zapros="";
                zapros=zapros+"select "+name_field_gid_fk;
                zapros=zapros+" from "+name_table_fk;
                zapros=zapros+" where "+name_field_fk+"="+value_field;
                IBQ2->SQL->Add(zapros);
               // RichEdit1->Lines->Add("zapros "+ zapros );
                IBQ2->Active=true;
                if (IBQ2->RecordCount==1)
                        {
                        value_gid_fk=Trim(IBQ2->FieldByName(name_field_gid_fk)->AsString);
                        }
               // RichEdit1->Lines->Add("gid_fk "+ value_gid_fk);
                //-------------------------------------------------------------------------
                String S="    ";
                S=S+"<"+name_field+" v=\""+value_field+"\"";
                //S=S+"fk=\"fk\"";
               // S=S+" table_fk=\""+name_table_fk+"\"";
               // S=S+" field_fk=\""+name_field_fk+"\"";
               // S=S+" name_gid=\""+name_field_gid_fk+"\"";
                S=S+" gid_fk=\""+value_gid_fk+"\"";
                S=S+"/>";
                SaveFileXML(S);

                //выгрузим полученные значения в XML файл

                IBQ2->Active=false;

}
//----------------------------------------------------------------------
void __fastcall TFormaObmenExport::FormResize(TObject *Sender)
{
 ProgressBar1->Width=PageControl1->Width;          
}
//---------------------------------------------------------------------------
void TFormaObmenExport::SaveFileXML(String str)
{
str=str+"\n";
const char *fileName=FileNameOut.c_str();
ofstream outfile(fileName,ios::out||ios::app);

if (!outfile)
        {
         return;
        }

outfile<<str.c_str();
outfile.close();
}
//----------------------------------------------------------------------------
String TFormaObmenExport::FormatForXML(String s)
{
String S1=s;
String S2="&";
String S3="&amp;";

int i0=0,i=S1.Pos(S2);
while(i)
        {
        S1=S1.SubString(1,i+i0-1)+S3+
                S1.SubString(i+i0+S2.Length(),255);
        i0+=i-1+S3.Length();
        i=S1.SubString(i0+1,255).Pos(S2);
        }


S2=">";
S3="&qt;";

i0=0,i=S1.Pos(S2);
while(i)
        {
        S1=S1.SubString(1,i+i0-1)+S3+
                S1.SubString(i+i0+S2.Length(),255);
        i0+=i-1+S3.Length();
        i=S1.SubString(i0+1,255).Pos(S2);
        }

S2="<";
S3="&lt;";

i0=0,i=S1.Pos(S2);
while(i)
        {
        S1=S1.SubString(1,i+i0-1)+S3+
                S1.SubString(i+i0+S2.Length(),255);
        i0+=i-1+S3.Length();
        i=S1.SubString(i0+1,255).Pos(S2);
        }

S2="\"";
S3="&quot;";

i0=0,i=S1.Pos(S2);
while(i)
        {
        S1=S1.SubString(1,i+i0-1)+S3+
                S1.SubString(i+i0+S2.Length(),255);
        i0+=i-1+S3.Length();
        i=S1.SubString(i0+1,255).Pos(S2);
        }

S2="\'";
S3="&apos;";

i0=0,i=S1.Pos(S2);
while(i)
        {
        S1=S1.SubString(1,i+i0-1)+S3+
                S1.SubString(i+i0+S2.Length(),255);
        i0+=i-1+S3.Length();
        i=S1.SubString(i0+1,255).Pos(S2);
        }


return S1;
}

//---------------------------------------------------------------------------
void __fastcall TFormaObmenExport::ButtonStrBaseClick(TObject *Sender)
{
TDMXTableBase *DMXTableBase=new TDMXTableBase(Application);
TDMXFieldBase *DMXFieldBase=new TDMXFieldBase(Application);
TableFK->Active=true;


//удалим предыдущую структуру
DMXTableBase->OpenTable();
DMXTableBase->Table->First();
while(!DMXTableBase->Table->Eof)
        {
        DMXFieldBase->OpenTable(DMXTableBase->TableID_XTABLE_BASE->AsInteger);
        DMXFieldBase->Table->First();
        while(!DMXFieldBase->Table->Eof)
                {
                TDMXFieldBase *Field=new TDMXFieldBase(Application);
                Field->DeleteElement(DMXFieldBase->TableID_XFIELD_BASE->AsInteger);
                delete Field;
                DMXFieldBase->Table->Next();
                }
        TDMXTableBase *Table=new TDMXTableBase(Application);
        Table->DeleteElement(DMXTableBase->TableID_XTABLE_BASE->AsInteger);
        delete Table;
        DMXTableBase->Table->Next();
        }


//получим список таблиц
TablePK->Active=true;

TablePK->Last();
ProgressBar1->Max=TablePK->RecNo;
ProgressBar1->Step=1;

TablePK->First();

while(!TablePK->Eof)
        {
        DMXTableBase->NewElement();
        DMXTableBase->Element->Edit();
        DMXTableBase->ElementNAMETAB_XTABLE_BASE->AsString=Trim(TablePKTABLE_NAME->AsString);
        DMXTableBase->ElementNAMEPK_XTABLE_BASE->AsString=Trim(TablePKFIELD_NAME->AsString);
        DMXTableBase->ElementNAMEGID_XTABLE_BASE->AsString=
                                Trim(GetNameGid(Trim(TablePKTABLE_NAME->AsString)));
        DMXTableBase->Element->Post();
        DMXTableBase->SaveElement();

        TableFields->Active=false;
        TableFields->ParamByName("PARAM_NAMETABLE")->AsString=
                                  Trim(TablePKTABLE_NAME->AsString);
        TableFields->Active=true;

        TableFields->First();
        while(!TableFields->Eof)
                {
                DMXFieldBase->NewElement(DMXTableBase->ElementID_XTABLE_BASE->AsInteger);
                DMXFieldBase->Element->Edit();
                DMXFieldBase->ElementNAME_XFIELD_BASE->AsString=Trim(TableFieldsRDBFIELD_NAME->AsString);
                //число или нет
                DMXFieldBase->ElementTYPE_XFIELD_BASE->AsInteger=TableFieldsRDBFIELD_TYPE->AsInteger;
                DMXFieldBase->ElementSCALE_XFIELD_BASE->AsInteger=TableFieldsRDBFIELD_SCALE->AsInteger;

                //внешний ключ
                if (Trim(TableFieldsRDBFIELD_SOURCE->AsString)=="DOMAIN_FK_KEY")
                        {
                        DMXFieldBase->ElementFK_XFIELD_BASE->AsInteger=1;

                        TableFK->First();
                        while (!TableFK->Eof)
                                {
                                if (Trim(TableFKRDBFIELD_NAME->AsString )==
                                              Trim(TableFieldsRDBFIELD_NAME->AsString))
                                        {
                                        DMXFieldBase->ElementFIELDFK_XFIELD_BASE->AsString=Trim(TableFKRDBFIELD_NAME3->AsString);
                                        DMXFieldBase->ElementTABLEFK_XFIELD_BASE->AsString=Trim(TableFKRDBRELATION_NAME2->AsString);
                                        break;
                                        }
                                TableFK->Next();
                                }



                        DMXFieldBase->ElementGIDFK_XFIELD_BASE->AsString=
                                        Trim(GetNameGid(Trim(DMXFieldBase->ElementTABLEFK_XFIELD_BASE->AsString)));

                        }
                else
                        {
                        DMXFieldBase->ElementFK_XFIELD_BASE->AsInteger=0;
                        }

                DMXFieldBase->Element->Post();
                DMXFieldBase->SaveElement();

                TableFields->Next();
                }

        TablePK->Next();
        ProgressBar1->StepIt();
        }


TableFK->Active=false;
delete DMXTableBase;
delete DMXFieldBase;
ShowMessage("Структура базы заполнена");
}
//-----------------------------------------------------------------------------
String TFormaObmenExport::GetNameGid(String name_table)
{
String result="";
                IBQ2->Active=false;
                IBQ2->SQL->Clear();
                String zapros="";
                zapros=zapros+"select RDB$FIELD_NAME from RDB$RELATION_FIELDS";
                zapros=zapros+" where RDB$RELATION_NAME='"+Trim(name_table);
                zapros=zapros+"' and RDB$FIELD_SOURCE='DOMAIN_GID'";
                IBQ2->SQL->Add(zapros);
                IBQ2->Active=true;
                if (IBQ2->RecordCount==1)
                       {
                        result=Trim(IBQ2->FieldByName("RDB$FIELD_NAME")->AsString);
                        }


return result;
}
//-------------------------------------------------------------------------------
void __fastcall TFormaObmenExport::Button1Click(TObject *Sender)
{
TDMXDataOut * DataO=new TDMXDataOut(Application);

DataO->OpenTable(IdBase);
DataO->Table->First();
while (!DataO->Table->Eof)
        {
        TDMXDataOut * D=new TDMXDataOut(Application);
        D->DeleteElement(DataO->TableID_XDATA_OUT->AsInteger);
        delete D;
        DataO->Table->Next();
        }
delete  DataO;
}
//---------------------------------------------------------------------------
void TFormaObmenExport::OutProtocol(String str)
{
if (CheckBoxOutProtocol->Checked==true)
        {
        RichEdit1->Lines->Add(str);

        }
}
//----------------------------------------------------------------------------
