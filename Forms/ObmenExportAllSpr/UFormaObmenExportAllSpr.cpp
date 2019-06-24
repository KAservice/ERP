//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormaObmenExportAllSpr.h"
#include "UDM.h"
#include "UDMSetup.h"
#include "UDMXMessageObmen.h"
#include <fstream.h>
#include "UDMSprObmenTypePrice.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
extern String gl_prefiks_ib;
//---------------------------------------------------------------------------
__fastcall TFormaObmenExportAllSpr::TFormaObmenExportAllSpr(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TFormaObmenExportAllSpr::FormCreate(TObject *Sender)
{
RichEdit1->Clear();


}
//---------------------------------------------------------------------------
void __fastcall TFormaObmenExportAllSpr::FormClose(TObject *Sender, TCloseAction &Action)
{

Action=caFree;
}
//----------------------------------------------------------------------------
void __fastcall TFormaObmenExportAllSpr::EndEdit(TObject *Sender)
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
                }
        }
ViborRekvisit=NO;
IdDochForm=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TFormaObmenExportAllSpr::ButtonOpenFileClick(TObject *Sender)
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
String TFormaObmenExportAllSpr::FloatToStringComma(double value)
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
double TFormaObmenExportAllSpr::StringToFloatComma(String value)
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

void __fastcall TFormaObmenExportAllSpr::ButtonVigrClick(TObject *Sender)
{

CreateXMLDoc(IdBase);

}

//-------------------------------------------------------------------------------------
void __fastcall TFormaObmenExportAllSpr::ButtonViborBaseClick(TObject *Sender)
{
OpenFormSpiskaSprInfBase();
}
//---------------------------------------------------------------------------
void TFormaObmenExportAllSpr::OpenFormSpiskaSprInfBase(void)
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

void __fastcall TFormaObmenExportAllSpr::ButtonCloseClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------
void TFormaObmenExportAllSpr::OutputSpr(String name_table)
{



}
//----------------------------------------------------------------------------
void TFormaObmenExportAllSpr::CreateXMLDoc(int id_base)
{
IdBase=id_base;
if (IdBase==0) return;

//сохраняем в файл
FileNameOut=CatalogObmena+"\\"+PrefiksBase+"_"+gl_prefiks_ib+"_AllSpr"+".xml";
SaveFileXML("<?xml version=\"1.0\" encoding=\"windows-1251\"?>");
SaveFileXML("<data>");
DMXTableBase=new TDMXTableBase(Application);
DMXFieldBase=new TDMXFieldBase(Application);



OutputTableInXMLFile("SFIRM");
OutputTableInXMLFile("SBANK");
OutputTableInXMLFile("SOBORUD");
OutputTableInXMLFile("SOKEI");
OutputTableInXMLFile("STPRICE");
OutputTableInXMLFile("SSTROB");
OutputTableInXMLFile("SGRPKL");
OutputTableInXMLFile("SGRPNOM");
OutputTableInXMLFile("SBSCHET");
OutputTableInXMLFile("SKLIENT");
OutputTableInXMLFile("SKLIENT_DOPFISL");
OutputTableInXMLFile("SKLIENT_DOPURL");
OutputTableInXMLFile("SRSCHET");
OutputTableInXMLFile("SDOG");
OutputTableInXMLFile("SDOCKLIENT");
OutputTableInXMLFile("SNUMTEL");
OutputTableInXMLFile("SGRPLAT");

NoOutputEd=true;
OutputTableInXMLFile("SNOM");
NoOutputEd=false;
OutputTableInXMLFile("SED");
OutputTableInXMLFile("SNOM");

OutputTableInXMLFile("SMOD");
OutputTableInXMLFile("SPART");
OutputTableInXMLFile("SNOMREST");
OutputTableInXMLFile("SPRICE");
OutputTableInXMLFile("SSPROD");
OutputTableInXMLFile("SSEZKF");
OutputTableInXMLFile("SSEZKF_SPROD");
OutputTableInXMLFile("SMPRIG");
OutputTableInXMLFile("SPOD");
OutputTableInXMLFile("SGBVNOM");
OutputTableInXMLFile("SCODETEL");
OutputTableInXMLFile("SUSER");
OutputTableInXMLFile("SBVNOM");
OutputTableInXMLFile("SKKM");

SaveFileXML("</data>");
delete DMXTableBase;
delete DMXFieldBase;


ShowMessage("выгрузка данных завершена!");
}

//----------------------------------------------------------------------------
void TFormaObmenExportAllSpr::OutputTableInXMLFile(String table_name)
{

DMXTableBase->GetElementPoName(table_name);
DMXFieldBase->OpenTable(DMXTableBase->ElementID_XTABLE_BASE->AsInteger);

String name_pk=Trim(DMXTableBase->ElementNAMEPK_XTABLE_BASE->AsString); //наименование первичного ключа

//открываем запись
String zapros="";
IBQ->Active=false;
IBQ->SQL->Clear();
zapros=zapros+"select * from "+table_name;
IBQ->SQL->Add(zapros);
IBQ->Active=true;


LabelNameTable->Caption=table_name;
LabelNameTable->Update();
IBQ->Last();
LabelTotalIsm->Caption="Всего записей: "+IntToStr(IBQ->RecordCount);
LabelTotalIsm->Update();
int kol_rec=0;

IBQ->First();
while(!IBQ->Eof)
        {

String name_gid=Trim(DMXTableBase->ElementNAMEGID_XTABLE_BASE->AsString);
String value_gid=Trim(IBQ->FieldByName(name_gid)->AsString);//получим значение Gid

//создаем узел с названием таблицы
String S="  ";
S=S+"<"+table_name+" oper=\""+Trim(1)+"\"";
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

        IBQ->Next();
        LabelZagrIsm->Caption="Выгружено записей: "+IntToStr(kol_rec);
        LabelZagrIsm->Update();
        kol_rec++;
        }


IBQ->Active=false;

}
//------------------------------------------------------------------------------
bool TFormaObmenExportAllSpr::CheckFieldForOutput(String name_field, String name_table)
{
bool result=false;
if (name_field=="PRDOC") return result;
if (name_field=="PRICEZPART") return result;

if (name_field=="PRICEOSNT") return result;
if (name_field=="SUMOSNT") return result;

if (name_field=="PRICESPNT") return result;
if (name_field=="SUMSPNT") return result;

if (name_field=="KOLPRODNOM") return result;
if (name_field=="IDEDPRODNOM") return result;
if (name_field=="IDMPRIGNOM") return result;

if (NoOutputEd==true)
        {
        if (name_field=="IDBASEDNOM") return result;
        if (name_field=="IDOSNEDNOM") return result;
        }
else
        {
        if (name_field=="IDGRPNOM") return result;
        if (name_field=="NAMENOM") return result;
        if (name_field=="FNAMENOM") return result;
        if (name_field=="KRNAMENOM") return result;
        if (name_field=="CODENOM") return result;
        if (name_field=="TNOM") return result;
        if (name_field=="ARTNOM") return result;
        }
        
result=true;
return result;

}

//----------------------------------------------------------------------
void TFormaObmenExportAllSpr::OutputFKInXMLFile(String name_field, int value_field)
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
void __fastcall TFormaObmenExportAllSpr::FormResize(TObject *Sender)
{
 ProgressBar1->Width=PageControl1->Width;          
}
//---------------------------------------------------------------------------
void TFormaObmenExportAllSpr::SaveFileXML(String str)
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
String TFormaObmenExportAllSpr::FormatForXML(String s)
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
String TFormaObmenExportAllSpr::GetNameGid(String name_table)
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
void TFormaObmenExportAllSpr::OutProtocol(String str)
{
if (CheckBoxOutProtocol->Checked==true)
        {
        RichEdit1->Lines->Add(str);

        }
}
//----------------------------------------------------------------------------

