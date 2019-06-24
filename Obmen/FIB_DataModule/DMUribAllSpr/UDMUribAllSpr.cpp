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
        //���� ��������� � ����� �� ��������� ��������� ��� ���
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

//�� ��������� ���� IDEXT_BASE � IDEXT_DOUT
if(name_field=="IDEXT_BASE_"+Trim(name_table)) return result;
if(name_field=="IDEXT_DOUT_"+Trim(name_table)) return result;


if (name_field=="PRDOC") return result;
if (name_field=="FL_CHANGE_NOM") return result;//  �� ���� ��������� ���� ��������� ���


//�� ��������� ���������� ����
	//���������� ������
	if (name_field=="PRICEZPART") return result;
	//�������� ���� ��������
	if (name_field=="PRICEOSNT") return result;
	if (name_field=="SUMOSNT") return result;
	//�������� ��� ��������
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
		//����� ��������� ������ ������� � �������� �������
        if (name_field=="IDGRPNOM") return result;
        if (name_field=="NAMENOM") return result;
		if (name_field=="FNAMENOM") return result;
		if (name_field=="KRNAMENOM") return result;
        if (name_field=="CODENOM") return result;
		if (name_field=="TNOM") return result;
        if (name_field=="ARTNOM") return result;
        }

 //���������
 //���� ��������
if (name_field=="PRICEOSNT") return result;
if (name_field=="SUMOSNT") return result;
//��� ��������
if (name_field=="PRICESPNT") return result;
if (name_field=="SUMSPNT") return result;
//������� �� ����������
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
	TextError="�� ����� ������������� ���� ��� ������!";
	return result;
	}

BaseForObmen->Active=false;
BaseForObmen->ParamByName("PARAM_IDBASE_FOR_OBMEN")->AsInt64=id_base;
BaseForObmen->Active=true;
if (BaseForObmen->RecordCount!=1)
	{
	TextError="�� ������ ��� ������ ��������� �������� ������ � ��������� �����!";
	return result;
	}

TableTypePrice->Active=false;
TableTypePrice->ParamByName("PARAM_IDBASE")->AsInt64=id_base;
TableTypePrice->Active=true;

FileNameOut=ExtractFileDir(Application->ExeName)+"\\Files\\AllSprFor"+IntToStr(id_base)+".xml";

// �������� ���� ���� ��������� ���� �� ��� ������
if(FileExists(FileNameOut)==true)
        {
         DeleteFile(FileNameOut);
        }

//��������� � ����
SaveFileXML("<?xml version=\"1.0\" encoding=\"windows-1251\"?>");
SaveFileXML("<data>");
NumRecord=1;

TablesBase->Active=false;
TablesBase->Active=true;

glSaveProtocol("��������� ���������� SCOUNTRY");
OutputTableInXMLFile("SCOUNTRY");
glSaveProtocol("��������� ���������� SGRPPROJECT");
OutputTableInXMLFile("SGRPPROJECT");
glSaveProtocol("��������� ���������� SPROJECT");
OutputTableInXMLFile("SPROJECT");
glSaveProtocol("��������� ���������� SVIDDEYAT");
OutputTableInXMLFile("SVIDDEYAT");


glSaveProtocol("��������� ���������� SFIRM");
OutputTableInXMLFile("SFIRM");
glSaveProtocol("��������� ���������� SSKLAD");
OutputTableInXMLFile("SSKLAD");
glSaveProtocol("��������� ���������� SBANK");
OutputTableInXMLFile("SBANK");
glSaveProtocol("��������� ���������� SOKEI");
OutputTableInXMLFile("SOKEI");
glSaveProtocol("��������� ���������� STPRICE");
OutputTableInXMLFile("STPRICE");
glSaveProtocol("��������� ���������� SSTROB");
OutputTableInXMLFile("SSTROB");
glSaveProtocol("��������� ���������� SGRPKL");
OutputTableInXMLFile("SGRPKL");
glSaveProtocol("��������� ���������� SGRPNOM");
OutputTableInXMLFile("SGRPNOM");
glSaveProtocol("��������� ���������� SBSCHET");
OutputTableInXMLFile("SBSCHET");
glSaveProtocol("��������� ���������� SVIDNOM");
OutputTableInXMLFile("SVIDNOM");
glSaveProtocol("��������� ���������� SVIDKLIENT");
OutputTableInXMLFile("SVIDKLIENT");
glSaveProtocol("��������� ���������� SVID_DCARD");
OutputTableInXMLFile("SVID_DCARD");
glSaveProtocol("��������� ���������� SINV");
OutputTableInXMLFile("SINV");
glSaveProtocol("��������� ���������� SINFBASE_OBMEN");
OutputTableInXMLFile("SINFBASE_OBMEN");
glSaveProtocol("��������� ���������� SKKM");
OutputTableInXMLFile("SKKM");


glSaveProtocol("��������� ���������� SKLIENT");
OutputTableInXMLFile("SKLIENT");
glSaveProtocol("��������� ���������� SKLIENT_DOPFISL");
OutputTableInXMLFile("SKLIENT_DOPFISL");
glSaveProtocol("��������� ���������� SKLIENT_DOPURL");
OutputTableInXMLFile("SKLIENT_DOPURL");
glSaveProtocol("��������� ���������� SRSCHET");
OutputTableInXMLFile("SRSCHET");
glSaveProtocol("��������� ���������� SDOG");
OutputTableInXMLFile("SDOG");
glSaveProtocol("��������� ���������� SDOCKLIENT");
OutputTableInXMLFile("SDOCKLIENT");
glSaveProtocol("��������� ���������� SNUMTEL");
OutputTableInXMLFile("SNUMTEL");
glSaveProtocol("��������� ���������� SGRPLAT");
OutputTableInXMLFile("SGRPLAT");
glSaveProtocol("��������� ���������� SDISCOUNT_CARD");
OutputTableInXMLFile("SDISCOUNT_CARD");

NoOutputEd=true;
glSaveProtocol("��������� ���������� SNOM");
OutputTableInXMLFile("SNOM");
NoOutputEd=false;
glSaveProtocol("��������� ���������� SED");
OutputTableInXMLFile("SED");
glSaveProtocol("��������� �������� ���������� SNOM");
OutputTableInXMLFile("SNOM");
glSaveProtocol("��������� ���������� SMOD");
OutputTableInXMLFile("SMOD");
glSaveProtocol("��������� ���������� SPART");
OutputTableInXMLFile("SPART");
glSaveProtocol("��������� ���������� SNOMREST");
OutputTableInXMLFile("SNOMREST");
glSaveProtocol("��������� ���������� SPRICE");
OutputTableInXMLFile("SPRICE");
glSaveProtocol("��������� ���������� SSPROD");
OutputTableInXMLFile("SSPROD");
glSaveProtocol("��������� ���������� SSEZKF");
OutputTableInXMLFile("SSEZKF");
glSaveProtocol("��������� ���������� SSEZKF_SPROD");
OutputTableInXMLFile("SSEZKF_SPROD");
glSaveProtocol("��������� ���������� SMPRIG");
OutputTableInXMLFile("SMPRIG");
glSaveProtocol("��������� ���������� SPOD");
OutputTableInXMLFile("SPOD");
glSaveProtocol("��������� ���������� SGBVNOM");
OutputTableInXMLFile("SGBVNOM");
glSaveProtocol("��������� ���������� SCODETEL");
OutputTableInXMLFile("SCODETEL");
glSaveProtocol("��������� ���������� SGRPUSER");
OutputTableInXMLFile("SGRPUSER");
glSaveProtocol("��������� ���������� SUSER");
OutputTableInXMLFile("SUSER");
glSaveProtocol("��������� ���������� SBVNOM");
OutputTableInXMLFile("SBVNOM");

glSaveProtocol("��������� ���������� SNACENKA");
OutputTableInXMLFile("SNACENKA");

glSaveProtocol("��������� ���������� SNAK_SKIDOK");
OutputTableInXMLFile("SNAK_SKIDOK");
glSaveProtocol("��������� ���������� SDISCOUNT_AUTO");
OutputTableInXMLFile("SDISCOUNT_AUTO");
glSaveProtocol("��������� ���������� GUROPER_DCARD");
OutputTableInXMLFile("GUROPER_DCARD");

glSaveProtocol("��������� ���������� ��������� �����");
glSaveProtocol("��������� ���������� REM_SGRPNEISPR");
OutputTableInXMLFile("REM_SGRPNEISPR");
glSaveProtocol("��������� ���������� REM_SNEISPR");
OutputTableInXMLFile("REM_SNEISPR");
glSaveProtocol("��������� ���������� REM_SGRPMODEL");
OutputTableInXMLFile("REM_SGRPMODEL");
glSaveProtocol("��������� ���������� REM_SMODEL");
OutputTableInXMLFile("REM_SMODEL");
glSaveProtocol("��������� ���������� REM_SKOMPLMODEL");
OutputTableInXMLFile("REM_SKOMPLMODEL");
glSaveProtocol("��������� ���������� REM_SSOST");
OutputTableInXMLFile("REM_SSOST");
glSaveProtocol("��������� ���������� REM_TREMONT");
OutputTableInXMLFile("REM_STREMONT");


SaveFileXML("</data>");

glSaveProtocol("���� �����������!");


//ShowMessage("�������� ������ ���������!");
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
String name_pk=Trim(TablesBase->FieldByName("FIELD_NAME")->AsString); //������������ ���������� �����

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
				glSaveProtocol("������ � ������ DMUribAllSpr->OutputTableInXMLFile ��� �������� ������� ����������� \n"
				+exception.Message+"  \n ������:"+zapros
				+"\n"+"��� �������:"+table_name);
				}

//IBQ->Last();

int kol_rec=0;

//IBQ->First();
while(!Query->Eof)
		{

		if (CheckRecordForOutput(table_name)==false)      //�������� ����� �� ���������
                {                                         //������� ������
				Query->Next();
				continue;
                }

		//������� ���� � ��������� �������
		String S="  ";
		S=S+"<"+table_name+" num=\""+IntToStr(NumRecord)+"\""
		+" oper=\""+Trim(1)+"\"";        //�������
		S=S+" type=\"1\""; // ������� ������ 1, ������������� 2
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

			//�������� ���� �� ��������� ����
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

			//�������� ������� �� �����
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
