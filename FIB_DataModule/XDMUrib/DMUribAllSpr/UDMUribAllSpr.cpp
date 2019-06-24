//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMUribAllSpr.h"
#include <fstream.h>
#include "UDMSprInfBase.h"
#include "UDMXMessageObmen.h"
#include "UDMSprObmenTypePrice.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
extern String gl_prefiks_ib;
extern void glSaveProtocol(String str);
//---------------------------------------------------------------------------
__fastcall TDMUribAllSpr::TDMUribAllSpr(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMUribAllSpr::DataModuleCreate(TObject *Sender)
{
///
}
//---------------------------------------------------------------------------
void __fastcall TDMUribAllSpr::DataModuleDestroy(TObject *Sender)
{
///
}

//----------------------------------------------------------------------------
void TDMUribAllSpr::CreateXMLDoc(int id_base)
{
IdBase=id_base;
if (IdBase==0) return;

TDMSprInfBase *DMSprBase=new TDMSprInfBase(Application);
DMSprBase->OpenElement(id_base);
CatalogObmena=ExtractFileDir(Application->ExeName)+"\\Files";//Trim(DMSprBase->ElementOUTPATCH_SINFBASE_OBMEN->AsString);
PrefiksBase=Trim(DMSprBase->ElementPREFIKS_SINFBASE_OBMEN->AsString);
OutSprNacenka=DMSprBase->ElementOUTNAC_SINFBASE_OBMEN->AsInteger;
OutZakPrice=DMSprBase->ElementOUTZPRICE_SINFBASE_OBMEN->AsInteger;

//создадим новое сообщение
TDMXMessageObmen *DMMessage=new TDMXMessageObmen(Application);
DMMessage->NewElement(IdBase);
DMMessage->Element->Edit();
DMMessage->ElementOUT_XMESSAGE_OBMEN->AsInteger=1;
DMMessage->Element->Post();
DMMessage->SaveElement();
IdMessage=DMMessage->ElementID_XMESSAGE_OBMEN->AsInteger;
GIDMessage=DMMessage->ElementGID_XMESSAGE_OBMEN->AsString;


FileNameOut=CatalogObmena+"\\"+Trim(DMSprBase->ElementPREFIKS_SINFBASE_OBMEN->AsString)
                         +"_"+Trim(DMMessage->ElementGID_XMESSAGE_OBMEN->AsString)+".xml";

delete DMSprBase;

// проверим если есть указанный файл то его удалим
if(FileExists(FileNameOut)==true)
        {
         DeleteFile(FileNameOut);
        }


//сохраняем в файл
SaveFileXML("<?xml version=\"1.0\" encoding=\"windows-1251\"?>");
SaveFileXML("<data>");
NumRecord=1;
DMXTableBase=new TDMXTableBase(Application);
DMXFieldBase=new TDMXFieldBase(Application);


glSaveProtocol("Выгружаем справочник SFIRM");
OutputTableInXMLFile("SFIRM");
glSaveProtocol("Выгружаем справочник SSKLAD");
OutputTableInXMLFile("SSKLAD");
glSaveProtocol("Выгружаем справочник SBANK");
OutputTableInXMLFile("SBANK");
glSaveProtocol("Выгружаем справочник SOBORUD");
OutputTableInXMLFile("SOBORUD");
glSaveProtocol("Выгружаем справочник SOKEI");
OutputTableInXMLFile("SOKEI");
glSaveProtocol("Выгружаем справочник STPRICE");
OutputTableInXMLFile("STPRICE");
glSaveProtocol("Выгружаем справочник SSTROB");
OutputTableInXMLFile("SSTROB");
glSaveProtocol("Выгружаем справочник SGRPKL");
OutputTableInXMLFile("SGRPKL");
glSaveProtocol("Выгружаем справочник SGRPNOM");
OutputTableInXMLFile("SGRPNOM");
glSaveProtocol("Выгружаем справочник SBSCHET");
OutputTableInXMLFile("SBSCHET");
glSaveProtocol("Выгружаем справочник SVIDNOM");
OutputTableInXMLFile("SVIDNOM");
glSaveProtocol("Выгружаем справочник SVIDKLIENT");
OutputTableInXMLFile("SVIDKLIENT");
glSaveProtocol("Выгружаем справочник SVID_DCARD");
OutputTableInXMLFile("SVID_DCARD");
glSaveProtocol("Выгружаем справочник SINV");
OutputTableInXMLFile("SINV");

glSaveProtocol("Выгружаем справочник SKLIENT");
OutputTableInXMLFile("SKLIENT");
glSaveProtocol("Выгружаем справочник SKLIENT_DOPFISL");
OutputTableInXMLFile("SKLIENT_DOPFISL");
glSaveProtocol("Выгружаем справочник SKLIENT_DOPURL");
OutputTableInXMLFile("SKLIENT_DOPURL");
glSaveProtocol("Выгружаем справочник SRSCHET");
OutputTableInXMLFile("SRSCHET");
glSaveProtocol("Выгружаем справочник SDOG");
OutputTableInXMLFile("SDOG");
glSaveProtocol("Выгружаем справочник SDOCKLIENT");
OutputTableInXMLFile("SDOCKLIENT");
glSaveProtocol("Выгружаем справочник SNUMTEL");
OutputTableInXMLFile("SNUMTEL");
glSaveProtocol("Выгружаем справочник SGRPLAT");
OutputTableInXMLFile("SGRPLAT");
glSaveProtocol("Выгружаем справочник SDISCOUNT_CARD");
OutputTableInXMLFile("SDISCOUNT_CARD");

NoOutputEd=true;
glSaveProtocol("Выгружаем справочник SNOM");
OutputTableInXMLFile("SNOM");
NoOutputEd=false;
glSaveProtocol("Выгружаем справочник SED");
OutputTableInXMLFile("SED");
glSaveProtocol("Выгружаем повторно справочник SNOM");
OutputTableInXMLFile("SNOM");
glSaveProtocol("Выгружаем справочник SMOD");
OutputTableInXMLFile("SMOD");
glSaveProtocol("Выгружаем справочник SPART");
OutputTableInXMLFile("SPART");
glSaveProtocol("Выгружаем справочник SNOMREST");
OutputTableInXMLFile("SNOMREST");
glSaveProtocol("Выгружаем справочник SPRICE");
OutputTableInXMLFile("SPRICE");
glSaveProtocol("Выгружаем справочник SSPROD");
OutputTableInXMLFile("SSPROD");
glSaveProtocol("Выгружаем справочник SSEZKF");
OutputTableInXMLFile("SSEZKF");
glSaveProtocol("Выгружаем справочник SSEZKF_SPROD");
OutputTableInXMLFile("SSEZKF_SPROD");
glSaveProtocol("Выгружаем справочник SMPRIG");
OutputTableInXMLFile("SMPRIG");
glSaveProtocol("Выгружаем справочник SPOD");
OutputTableInXMLFile("SPOD");
glSaveProtocol("Выгружаем справочник SGBVNOM");
OutputTableInXMLFile("SGBVNOM");
glSaveProtocol("Выгружаем справочник SCODETEL");
OutputTableInXMLFile("SCODETEL");
glSaveProtocol("Выгружаем справочник SGRPUSER");
OutputTableInXMLFile("SGRPUSER");
glSaveProtocol("Выгружаем справочник SUSER");
OutputTableInXMLFile("SUSER");
glSaveProtocol("Выгружаем справочник SBVNOM");
OutputTableInXMLFile("SBVNOM");
glSaveProtocol("Выгружаем справочник SKKM");
OutputTableInXMLFile("SKKM");
glSaveProtocol("Выгружаем справочник SINV");
OutputTableInXMLFile("SINV");
glSaveProtocol("Выгружаем справочник SNACENKA");
OutputTableInXMLFile("SNACENKA");

glSaveProtocol("Выгружаем справочник SNAK_SKIDOK");
OutputTableInXMLFile("SNAK_SKIDOK");
glSaveProtocol("Выгружаем справочник GUROPER_DCARD");
OutputTableInXMLFile("GUROPER_DCARD");

glSaveProtocol("Выгружаем подсистему Сервисный центр");
glSaveProtocol("Выгружаем справочник REM_SGRPNEISPR");
OutputTableInXMLFile("REM_SGRPNEISPR");
glSaveProtocol("Выгружаем справочник REM_SNEISPR");
OutputTableInXMLFile("REM_SNEISPR");
glSaveProtocol("Выгружаем справочник REM_SGRPMODEL");
OutputTableInXMLFile("REM_SGRPMODEL");
glSaveProtocol("Выгружаем справочник REM_SMODEL");
OutputTableInXMLFile("REM_SMODEL");
glSaveProtocol("Выгружаем справочник REM_SKOMPLMODEL");
OutputTableInXMLFile("REM_SKOMPLMODEL");
glSaveProtocol("Выгружаем справочник REM_SSOST");
OutputTableInXMLFile("REM_SSOST");
glSaveProtocol("Выгружаем справочник REM_TREMONT");
OutputTableInXMLFile("REM_STREMONT");


SaveFileXML("</data>");
delete DMXTableBase;
delete DMXFieldBase;

glSaveProtocol("Файл сформирован!");
//отметим сообщение как успешное
glSaveProtocol("Пометим сообщение выгрузки как успешное");
DMMessage->OpenElement(IdMessage);
DMMessage->Element->Edit();
DMMessage->ElementKOLERR_XMESSAGE_OBMEN->AsInteger=-1;
DMMessage->Element->Post();
DMMessage->SaveElement();
delete DMMessage;
glSaveProtocol("ОК");
//ShowMessage("выгрузка данных завершена!");
}

//----------------------------------------------------------------------------
void TDMUribAllSpr::OutputTableInXMLFile(String table_name)
{

DMXTableBase->GetElementPoName(table_name);
DMXFieldBase->OpenTable(DMXTableBase->ElementID_XTABLE_BASE->AsInteger);


String name_pk=Trim(DMXTableBase->ElementNAMEPK_XTABLE_BASE->AsString); //наименование первичного ключа

//открываем запись
String zapros="";
IBQ->Close();
IBQ->SQL->Clear();
zapros=zapros+"select * from "+table_name;
IBQ->SQL->Add(zapros);
		try
				{
				IBQ->ExecQuery();
				}
		catch (Exception &exception)
				{
				glSaveProtocol("Ошибка в модуле DMUribAllSpr->OutputTableInXMLFile при открытии записи \n"
				+exception.Message+"  \n Запрос:"+zapros
				+"\n"+"Имя таблицы:"+table_name);
				}

//IBQ->Last();

int kol_rec=0;

//IBQ->First();
while(!IBQ->Eof)
        {

        if (CheckRecordForOutput(table_name)==false)      //проверим нужно ли выгружать
                {                                         //текущую запись
                IBQ->Next();
                continue;
                }


String name_gid=Trim(DMXTableBase->ElementNAMEGID_XTABLE_BASE->AsString);
String value_gid=Trim(IBQ->FieldByName(name_gid)->AsString);//получим значение Gid


//создаем узел с названием таблицы
String S="  ";
S=S+"<"+table_name+" num=\""+IntToStr(NumRecord)+"\""
        +" oper=\""+Trim(1)+"\"";
S=S+" name_gid=\""+name_gid+"\""+" value_gid=\""+value_gid+"\"";
S=S+" name_pk=\""+name_pk+"\"";
S=S+">";
SaveFileXML(S);
NumRecord++;
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

        kol_rec++;
        }


IBQ->Close();

}
//------------------------------------------------------------------------------
bool TDMUribAllSpr::CheckRecordForOutput(AnsiString name_table)
{
bool result=true;

if (name_table=="SPRICE")
        {
        //надо проверить а нужно ли выгружать указанный тип цен
        TDMSprObmenTypePrice * TypePriceObmen=new TDMSprObmenTypePrice(Application);
        TypePriceObmen->OpenTable(IdBase);
        TypePriceObmen->Table->First();
        result=false;
        while (!TypePriceObmen->Table->Eof)
                {
                if (IBQ->FieldByName("IDTYPE_PRICE")->AsInteger==
                        TypePriceObmen->TableIDTPRICE_STYPEPRICE_OBMEN->AsInteger)
                        {
                        result=true;
                        break;
                        }
                TypePriceObmen->Table->Next();
                }
        delete TypePriceObmen;
		}

//справочник Наценка
if (name_table=="SNACENKA")
	{
	if (OutSprNacenka==1)
		{
		result=true;
		}
	else
		{
		result=false;
		}
	}


return result;
}
//-----------------------------------------------------------------------------
bool TDMUribAllSpr::CheckFieldForOutput(String name_field, String name_table)
{
bool result=false;
if (name_field=="PRDOC") return result;
if (name_field=="FL_CHANGE_NOM") return result;//  не надо выгружать флаг изменения цен

if (OutZakPrice!=1)
	{ //не выгружаем закупочные цены
	//Справочник партии
	if (name_field=="PRICEZPART") return result;
	//Документ Ввод остатков
	if (name_field=="PRICEOSNT") return result;
	if (name_field=="SUMOSNT") return result;
	//Документ Акт списания
	if (name_field=="PRICESPNT") return result;
	if (name_field=="SUMSPNT") return result;
	}

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
void TDMUribAllSpr::OutputFKInXMLFile(String name_field, int value_field)
{

        String name_table_fk=Trim(DMXFieldBase->TableTABLEFK_XFIELD_BASE->AsString);     //таблица на которую ссылается ключ
        String name_field_fk=Trim(DMXFieldBase->TableFIELDFK_XFIELD_BASE->AsString);      //имя поля на которое ссылается ключ
        String name_field_gid_fk=Trim(DMXFieldBase->TableGIDFK_XFIELD_BASE->AsString);  //имя поля которое является GID ом
        String value_gid_fk="";        //значение GID поля внешнего ключа
        String name_index="";

                //получим значение GIDа
				IBQ2->Close();
                IBQ2->SQL->Clear();
                String zapros="";
                zapros=zapros+"select "+name_field_gid_fk;
                zapros=zapros+" from "+name_table_fk;
                zapros=zapros+" where "+name_field_fk+"="+value_field;
				IBQ2->SQL->Add(zapros);
		try
				{
				IBQ2->ExecQuery();
				}
		catch (Exception &exception)
				{
				glSaveProtocol("Ошибка в модуле DMUribAllSpr->OutputFKInXMLFile при получении значения GID \n"
				+exception.Message+"  \n Запрос:"+zapros
				+"\n"+"Имя поля:"+name_field+" Значение "+value_field);
				}

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

                IBQ2->Close();

}

//---------------------------------------------------------------------------
void TDMUribAllSpr::SaveFileXML(String str)
{
str=str+"\n";
const char *fileName=FileNameOut.c_str();
ofstream outfile(fileName,ios::out|ios::app);

if (!outfile)
        {
         return;
        }

outfile<<str.c_str();
outfile.close();
}
//----------------------------------------------------------------------------
String TDMUribAllSpr::FormatForXML(String s)
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
S3="&gt;";

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
String TDMUribAllSpr::GetNameGid(String name_table)
{
String result="";
				IBQ2->Close();
                IBQ2->SQL->Clear();
                String zapros="";
                zapros=zapros+"select RDB$FIELD_NAME from RDB$RELATION_FIELDS";
                zapros=zapros+" where RDB$RELATION_NAME='"+Trim(name_table);
                zapros=zapros+"' and RDB$FIELD_SOURCE='DOMAIN_GID'";
				IBQ2->SQL->Add(zapros);
		try
				{
				IBQ2->ExecQuery();
				}
		catch (Exception &exception)
				{
				glSaveProtocol("Ошибка в модуле DMUribAllSpr->GetNameGid при получении имени GID \n"
				+exception.Message+"  \n Запрос:"+zapros
				+"\n"+"Имя таблицы:"+name_table);
				}


                if (IBQ2->RecordCount==1)
                       {
                        result=Trim(IBQ2->FieldByName("RDB$FIELD_NAME")->AsString);
                        }


return result;
}
//-------------------------------------------------------------------------------
void TDMUribAllSpr::OutProtocol(String str)
{
///
}

//----------------------------------------------------------------------------------
String TDMUribAllSpr::FloatToStringComma(double value)
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
double TDMUribAllSpr::StringToFloatComma(String value)
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