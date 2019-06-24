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

//�������� ����� ���������
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

// �������� ���� ���� ��������� ���� �� ��� ������
if(FileExists(FileNameOut)==true)
        {
         DeleteFile(FileNameOut);
        }


//��������� � ����
SaveFileXML("<?xml version=\"1.0\" encoding=\"windows-1251\"?>");
SaveFileXML("<data>");
NumRecord=1;
DMXTableBase=new TDMXTableBase(Application);
DMXFieldBase=new TDMXFieldBase(Application);


glSaveProtocol("��������� ���������� SFIRM");
OutputTableInXMLFile("SFIRM");
glSaveProtocol("��������� ���������� SSKLAD");
OutputTableInXMLFile("SSKLAD");
glSaveProtocol("��������� ���������� SBANK");
OutputTableInXMLFile("SBANK");
glSaveProtocol("��������� ���������� SOBORUD");
OutputTableInXMLFile("SOBORUD");
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
glSaveProtocol("��������� ���������� SKKM");
OutputTableInXMLFile("SKKM");
glSaveProtocol("��������� ���������� SINV");
OutputTableInXMLFile("SINV");
glSaveProtocol("��������� ���������� SNACENKA");
OutputTableInXMLFile("SNACENKA");

glSaveProtocol("��������� ���������� SNAK_SKIDOK");
OutputTableInXMLFile("SNAK_SKIDOK");
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
delete DMXTableBase;
delete DMXFieldBase;

glSaveProtocol("���� �����������!");
//������� ��������� ��� ��������
glSaveProtocol("������� ��������� �������� ��� ��������");
DMMessage->OpenElement(IdMessage);
DMMessage->Element->Edit();
DMMessage->ElementKOLERR_XMESSAGE_OBMEN->AsInteger=-1;
DMMessage->Element->Post();
DMMessage->SaveElement();
delete DMMessage;
glSaveProtocol("��");
//ShowMessage("�������� ������ ���������!");
}

//----------------------------------------------------------------------------
void TDMUribAllSpr::OutputTableInXMLFile(String table_name)
{

DMXTableBase->GetElementPoName(table_name);
DMXFieldBase->OpenTable(DMXTableBase->ElementID_XTABLE_BASE->AsInteger);


String name_pk=Trim(DMXTableBase->ElementNAMEPK_XTABLE_BASE->AsString); //������������ ���������� �����

//��������� ������
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
				glSaveProtocol("������ � ������ DMUribAllSpr->OutputTableInXMLFile ��� �������� ������ \n"
				+exception.Message+"  \n ������:"+zapros
				+"\n"+"��� �������:"+table_name);
				}

//IBQ->Last();

int kol_rec=0;

//IBQ->First();
while(!IBQ->Eof)
        {

        if (CheckRecordForOutput(table_name)==false)      //�������� ����� �� ���������
                {                                         //������� ������
                IBQ->Next();
                continue;
                }


String name_gid=Trim(DMXTableBase->ElementNAMEGID_XTABLE_BASE->AsString);
String value_gid=Trim(IBQ->FieldByName(name_gid)->AsString);//������� �������� Gid


//������� ���� � ��������� �������
String S="  ";
S=S+"<"+table_name+" num=\""+IntToStr(NumRecord)+"\""
        +" oper=\""+Trim(1)+"\"";
S=S+" name_gid=\""+name_gid+"\""+" value_gid=\""+value_gid+"\"";
S=S+" name_pk=\""+name_pk+"\"";
S=S+">";
SaveFileXML(S);
NumRecord++;
//��������� ������ � ����    �������� ��� ������� ����� �� GID
DMXFieldBase->Table->First();
while(!DMXFieldBase->Table->Eof)
        {
        String name_field=Trim(DMXFieldBase->TableNAME_XFIELD_BASE->AsString);
        String value_field="";
        
        //�������� ���� �� ��������� ����
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
                //� ���� ������� ���� �� ���������� ����� �������� ������� ��
                //������� ������� ���� � ����, � ����� �������� GID ������
                OutputFKInXMLFile(name_field, IBQ->FieldByName(name_field)->AsInteger);

                }
        else
                {
                //���� ���� �� �������� ������� ������ �����
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
        //���� ��������� � ����� �� ��������� ��������� ��� ���
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

//���������� �������
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
if (name_field=="FL_CHANGE_NOM") return result;//  �� ���� ��������� ���� ��������� ���

if (OutZakPrice!=1)
	{ //�� ��������� ���������� ����
	//���������� ������
	if (name_field=="PRICEZPART") return result;
	//�������� ���� ��������
	if (name_field=="PRICEOSNT") return result;
	if (name_field=="SUMOSNT") return result;
	//�������� ��� ��������
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

        String name_table_fk=Trim(DMXFieldBase->TableTABLEFK_XFIELD_BASE->AsString);     //������� �� ������� ��������� ����
        String name_field_fk=Trim(DMXFieldBase->TableFIELDFK_XFIELD_BASE->AsString);      //��� ���� �� ������� ��������� ����
        String name_field_gid_fk=Trim(DMXFieldBase->TableGIDFK_XFIELD_BASE->AsString);  //��� ���� ������� �������� GID ��
        String value_gid_fk="";        //�������� GID ���� �������� �����
        String name_index="";

                //������� �������� GID�
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
				glSaveProtocol("������ � ������ DMUribAllSpr->OutputFKInXMLFile ��� ��������� �������� GID \n"
				+exception.Message+"  \n ������:"+zapros
				+"\n"+"��� ����:"+name_field+" �������� "+value_field);
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

                //�������� ���������� �������� � XML ����

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
				glSaveProtocol("������ � ������ DMUribAllSpr->GetNameGid ��� ��������� ����� GID \n"
				+exception.Message+"  \n ������:"+zapros
				+"\n"+"��� �������:"+name_table);
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