//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMUribAllSpr.h"
#include <fstream.h>
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBQuery"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"
extern void glSaveProtocol(AnsiString str);
extern String glFormatForXML(String s);
extern String glFloatToStringComma(double value);
extern double glStringToFloatComma(String value);
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
//-----------------------------------------------------------------------------
void TDMUribAllSpr::SaveFileXML(AnsiString str)
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
//-----------------------------------------------------
bool TDMUribAllSpr::CheckRecordForOutput(AnsiString name_table)
{
bool result=true;

if (name_table=="SPRICE")
        {
        //надо проверить а нужно ли выгружать указанный тип цен
		TableTypePrice->First();
		result=false;
		while (!TableTypePrice->Eof)
                {
				if (Query->FieldByName("IDTYPE_PRICE")->AsInt64==
						TableTypePriceIDTPRICE_XTPRICE_FOR_OBMEN->AsInt64)
						{
						result=true;
						break;
                        }
				TableTypePrice->Next();
				}
		}

return result;
}
//-----------------------------------------------------------------------------
bool TDMUribAllSpr::CheckFieldForOutput(String name_field, String name_table)
{
bool result=false;

//не выгружаем поля IDEXT_BASE и IDEXT_DOUT
if(name_field=="IDEXT_BASE_"+Trim(name_table)) return result;
if(name_field=="IDEXT_DOUT_"+Trim(name_table)) return result;


if (name_field=="PRDOC") return result;
if (name_field=="FL_CHANGE_NOM") return result;//  не надо выгружать флаг изменения цен


//не выгружаем закупочные цены
	//Справочник партии
	if (name_field=="PRICEZPART") return result;
	//Документ Ввод остатков
	if (name_field=="PRICEOSNT") return result;
	if (name_field=="SUMOSNT") return result;
	//Документ Акт списания
	if (name_field=="PRICESPNT") return result;
	if (name_field=="SUMSPNT") return result;


if (name_field=="KOLPRODNOM") return result;
if (name_field=="IDEDPRODNOM") return result;
if (name_field=="IDMPRIGNOM") return result;

if (NoOutputEd==true)
        {
		if (name_field=="IDBASEDNOM") return result;
		if (name_field=="IDOSNEDNOM") return result;
        if (name_field=="IDFISED_SNOM") return result;
        }
else
		{
		//чтобы выгрузить только базовую и основную единицы
        if (name_field=="IDGRPNOM") return result;
        if (name_field=="NAMENOM") return result;
		if (name_field=="FNAMENOM") return result;
		if (name_field=="KRNAMENOM") return result;
        if (name_field=="CODENOM") return result;
		if (name_field=="TNOM") return result;
        if (name_field=="ARTNOM") return result;
        }

 //Документы
 //Ввод остатков
if (name_field=="PRICEOSNT") return result;
if (name_field=="SUMOSNT") return result;
//Акт списания
if (name_field=="PRICESPNT") return result;
if (name_field=="SUMSPNT") return result;
//Возврат от покупателя
if (name_field=="PRICE_DVPOKT") return result;
if (name_field=="SUM_DVPOKT") return result;
if (name_field=="SUM_DVPOK") return result;

if (name_table=="GALLDOC")
        {
		String type_doc=Trim(Query->FieldByName("TDOC")->AsString);

        if (type_doc=="OSN")
                {
				if (name_field=="SUMDOC")return result;
                }
		if (type_doc=="SPN")
                {
                if (name_field=="SUMDOC")return result;
                }
		if (type_doc=="PER")
                {
				if (name_field=="SUMDOC")return result;
                }
        } 






result=true;
return result;

}

//----------------------------------------------------------------------

bool TDMUribAllSpr::CreateXMLDocAllSpr(__int64 id_base)
{
bool result=false;
IdBaseForObmen=id_base;
if (IdBaseForObmen==0)
	{
	TextError="Не задан идентификатор базы для обмена!";
	return result;
	}

BaseForObmen->Active=false;
BaseForObmen->ParamByName("PARAM_IDBASE_FOR_OBMEN")->AsInt64=id_base;
BaseForObmen->Active=true;
if (BaseForObmen->RecordCount!=1)
	{
	TextError="Не заданы или задано несколько настроек обмена с выбранной базой!";
	return result;
	}

TableTypePrice->Active=false;
TableTypePrice->ParamByName("PARAM_IDBASE")->AsInt64=id_base;
TableTypePrice->Active=true;

FileNameOut=ExtractFileDir(Application->ExeName)+"\\Files\\AllSprFor"+IntToStr(id_base)+".xml";

// проверим если есть указанный файл то его удалим
if(FileExists(FileNameOut)==true)
        {
         DeleteFile(FileNameOut);
        }

//сохраняем в файл
SaveFileXML("<?xml version=\"1.0\" encoding=\"windows-1251\"?>");
SaveFileXML("<data>");
NumRecord=1;

TablesBase->Active=false;
TablesBase->Active=true;

glSaveProtocol("Выгружаем справочник SCOUNTRY");
OutputTableInXMLFile("SCOUNTRY");
glSaveProtocol("Выгружаем справочник SGRPPROJECT");
OutputTableInXMLFile("SGRPPROJECT");
glSaveProtocol("Выгружаем справочник SPROJECT");
OutputTableInXMLFile("SPROJECT");
glSaveProtocol("Выгружаем справочник SVIDDEYAT");
OutputTableInXMLFile("SVIDDEYAT");


glSaveProtocol("Выгружаем справочник SFIRM");
OutputTableInXMLFile("SFIRM");
glSaveProtocol("Выгружаем справочник SSKLAD");
OutputTableInXMLFile("SSKLAD");
glSaveProtocol("Выгружаем справочник SBANK");
OutputTableInXMLFile("SBANK");
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
glSaveProtocol("Выгружаем справочник SINFBASE_OBMEN");
OutputTableInXMLFile("SINFBASE_OBMEN");
glSaveProtocol("Выгружаем справочник SKKM");
OutputTableInXMLFile("SKKM");


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

glSaveProtocol("Выгружаем справочник SNACENKA");
OutputTableInXMLFile("SNACENKA");

glSaveProtocol("Выгружаем справочник SNAK_SKIDOK");
OutputTableInXMLFile("SNAK_SKIDOK");
glSaveProtocol("Выгружаем справочник SDISCOUNT_AUTO");
OutputTableInXMLFile("SDISCOUNT_AUTO");
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

glSaveProtocol("Файл сформирован!");


//ShowMessage("выгрузка данных завершена!");
BaseForObmen->Active=false;
TablesBase->Active=false;
result=true;
return result;
}

//----------------------------------------------------------------------------
void TDMUribAllSpr::OutputTableInXMLFile(String table_name)
{

TLocateOptions opt;
TablesBase->Locate("TABLE_NAME",table_name,opt);
String name_pk=Trim(TablesBase->FieldByName("FIELD_NAME")->AsString); //наименование первичного ключа

FieldsTable->Active=false;
FieldsTable->ParamByName("TABLE_NAME")->AsString=table_name;
FieldsTable->Active=true;


AnsiString zapros="select * from "+table_name;
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(zapros);

		try
				{
				Query->ExecQuery();
				}
		catch (Exception &exception)
				{
				glSaveProtocol("Ошибка в модуле DMUribAllSpr->OutputTableInXMLFile при открытии таблицы справочника \n"
				+exception.Message+"  \n Запрос:"+zapros
				+"\n"+"Имя таблицы:"+table_name);
				}

//IBQ->Last();

int kol_rec=0;

//IBQ->First();
while(!Query->Eof)
		{

		if (CheckRecordForOutput(table_name)==false)      //проверим нужно ли выгружать
                {                                         //текущую запись
				Query->Next();
				continue;
                }

		//создаем узел с названием таблицы
		String S="  ";
		S=S+"<"+table_name+" num=\""+IntToStr(NumRecord)+"\""
		+" oper=\""+Trim(1)+"\"";        //вставка
		S=S+" type=\"1\""; // вставка записи 1, подтверждение 2
		S=S+" name_pk=\""+name_pk+"\"";
		S=S+" value_pk=\""+Query->FieldByName(name_pk)->AsString+"\"";
		S=S+" idext_base=\"0\"";
		S=S+" idext_data_out=\"0\"";
		S=S+">";
		SaveFileXML(S);
		NumRecord++;

		for(int i=0; i<Query->FieldsCount();i++)
			{
			String name_field=Trim(Query->Fields[i]->Name);
			String value_field=Trim(Query->Fields[i]->AsString);

			//проверим надо ли выгружать поле
			if (CheckFieldForOutput(name_field, table_name)==false)
				{
				continue;
				}

			FieldsTable->Locate("FIELD_NAME",name_field,opt);

			int type_field=FieldsTable->FieldByName("FIELD_TYPE")->AsInteger;
			int scale_field=FieldsTable->FieldByName("FIELD_SCALE")->AsInteger;

			if(type_field==35)//TIMESTAMP
				{
				DateTimeToString(value_field,"dd.mm.yyyy h\":\"nn\":\"ss",Query->Fields[i]->AsDateTime);
				}

			//заменить запятую на точку
			if(scale_field<0)
				{
				value_field=glFloatToStringComma(Query->Fields[i]->AsFloat);
				}


			if (Trim(value_field)!="")
				{
				String S="    ";
				S=S+"<"+name_field+" v=\""+glFormatForXML(value_field)+"\"";
				S=S+"/>";
				SaveFileXML(S);
				}
			}


		S="  ";
		S=S+"</"+table_name+">";
		SaveFileXML(S);

		Query->Next();

		kol_rec++;
		}


Query->Close();
FieldsTable->Active=false;


}
//------------------------------------------------------------------------------
