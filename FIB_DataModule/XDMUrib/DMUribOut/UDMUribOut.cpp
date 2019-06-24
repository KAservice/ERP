//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMUribOut.h"


#include "UDM.h"
#include "UDMSetup.h"
#include "UDMXMessageObmen.h"
#include <fstream.h>
#include "UDMSprObmenTypePrice.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"
extern void glSaveProtocol(String str);
//---------------------------------------------------------------------------
__fastcall TDMUribOut::TDMUribOut(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMUribOut::DataModuleCreate(TObject *Sender)
{
////
lpKolRecord=new int;
}
//---------------------------------------------------------------------------
void __fastcall TDMUribOut::DataModuleDestroy(TObject *Sender)
{
////
delete lpKolRecord;
}
//---------------------------------------------------------------------------

String TDMUribOut::FloatToStringComma(double value)
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
double TDMUribOut::StringToFloatComma(String value)
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

//---------------------------------------------------------------------------
int TDMUribOut::CreateDataOutTable(int id_base)
{
IdBase=id_base;
AllDoc=0;
if (IdBase==0) return 0;

TableIsm=new TDMXTableIsm(Application);
DataOut=new TDMXDataOut(Application);

DMTypeDoc=new  TDMSprObmenTypeDoc(Application);
DMTypeDoc->OpenTable(id_base);

DMXTableBase=new TDMXTableBase(Application);

OutPrefikss="";
TDMSprInfBase * DMSprInfBase=new TDMSprInfBase(Application);
DMSprInfBase->OpenElement(id_base);
OutPrefikss=Trim(DMSprInfBase->ElementPREFDOC_SINFBASE_OBMEN->AsString);
AllDoc=DMSprInfBase->ElementALLDOC_SINFBASE_OBMEN->AsInteger;
OutSprNacenka=DMSprInfBase->ElementOUTNAC_SINFBASE_OBMEN->AsInteger;
OutZakPrice=DMSprInfBase->ElementOUTZPRICE_SINFBASE_OBMEN->AsInteger;
StartIDTableIsm=DMSprInfBase->ElementIDTIZM_SINFBASE_OBMEN->AsInteger;
delete DMSprInfBase;

//�������� ����� ���������
TDMXMessageObmen *DMMessage=new TDMXMessageObmen(Application);
if(DMMessage->OpenElement(IdMessage)==0)
        {
        DMMessage->NewElement(IdBase);
        }

DMMessage->Element->Edit();
DMMessage->ElementOUT_XMESSAGE_OBMEN->AsInteger=1;
DMMessage->Element->Post();
DMMessage->SaveElement(); 
IdMessage=DMMessage->ElementID_XMESSAGE_OBMEN->AsInteger;
GIDMessage=DMMessage->ElementGID_XMESSAGE_OBMEN->AsString;
delete DMMessage;


int max_id=DataOut->GetMaxIdTableIsm(id_base);
if (max_id<StartIDTableIsm)
        {
        max_id=StartIDTableIsm;
        }

TableIsm->OpenTable(max_id);
TableIsm->Table->Last();
*lpKolRecord=TableIsm->Table->RecNo;
//ShowMessage(IntToStr(TableDataOut->RecordCount));
//ProgressBar1->Step=1;
if(EventFirstRecord) EventFirstRecord(this);

TableIsm->Table->First();
while(!TableIsm->Table->Eof)
        {
        if(TableIsm->TableTYPEOB_XTISM->AsInteger==1)//����������
                {
                AddSprInDataTable();
                }

        if(TableIsm->TableTYPEOB_XTISM->AsInteger==2) //��������
                {
                AddDocInDataTable();
                }
        TableIsm->Table->Next();
        //ProgressBar1->StepIt();
        if(EventNextRecord) EventNextRecord(this);
        }

delete DMTypeDoc;
delete DMXTableBase;
delete TableIsm;
delete DataOut;

return IdMessage;

}
//-----------------------------------------------------------------------------
void TDMUribOut::AddSprInDataTable(void)
{
bool AddDataOut=true;
//����� �������� - ���� �� ��������� � ��������� ���� ������ ����������
//���������� ����
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
//���������� �������
if (Trim(TableIsm->TableNAMETAB_XTISM->AsString)=="SNACENKA")
	{
	if (OutSprNacenka==1)
		{
		AddDataOut=true;
		}
	else
		{
		AddDataOut=false;
		}
	}

//�������� ������ �� ��������
if (CheckRecordPoPrefiksu()==false) return;

if(DataOut->GetIdElement(IdBase,TableIsm->TableID_XTISM->AsInteger)==0 && AddDataOut==true)
        {
        DataOut->AddRecordDataOut(IdBase,TableIsm->TableID_XTISM->AsInteger,IdMessage);
        } 
}
//-----------------------------------------------------------------------------
void TDMUribOut::AddDocInDataTable(void)
{
//����� �������� - ���� �� ��������� �������� � ��������� ���� ������ ��������
//
String name_table=Trim(TableIsm->TableNAMETAB_XTISM->AsString);
AnsiString type_doc="";
AnsiString prefiks_doc="";

if (name_table=="GALLDOC")
        {
		DocAll->Close();
        DocAll->ParamByName("PARAM_IDDOC")->AsInteger=TableIsm->TableIDREC_XTISM->AsInteger;
		DocAll->ExecQuery();
        if(DocAll->RecordCount==1)
                {
				type_doc=Trim(DocAll->FieldByName("TDOC")->AsString);
				prefiks_doc=Trim(DocAll->FieldByName("PREFIKSDOC")->AsString);
                }
		}
else
        {
		//���� �������� IDDOC
		DMXTableBase->GetElementPoName(name_table);

        AnsiString zapros="";
		IBQ->Close();
        IBQ->SQL->Clear();
		zapros=zapros+"select "+Trim(DMXTableBase->ElementNAMEIDDOC_XTABLE_BASE->AsString);
        zapros=zapros+" from "+name_table;
        zapros=zapros+" where "+Trim(DMXTableBase->ElementNAMEPK_XTABLE_BASE->AsString);
        zapros=zapros+"="+IntToStr(TableIsm->TableIDREC_XTISM->AsInteger);
        IBQ->SQL->Add(zapros);
        try
                {
				IBQ->ExecQuery();
                }
        catch (Exception &exception)
                {
                glSaveProtocol("������ � ������ DMUribOut->AddDocInDataTable ��� ������ IDDOC \n"
                +exception.Message+"  \n ������:"+zapros
                +"\n"+"ID ������� ���������:"+IntToStr(TableIsm->TableID_XTISM->AsInteger));
                }



        try
                {
				DocAll->Close();
                DocAll->ParamByName("PARAM_IDDOC")->AsInteger=
                IBQ->FieldByName(Trim(DMXTableBase->ElementNAMEIDDOC_XTABLE_BASE->AsString))->AsInteger;
				DocAll->ExecQuery();
                }
        catch (Exception &exception)
                {
                glSaveProtocol("������ � ������ DMUribOut->AddDocInDataTable ��� �������� DocAll \n"
                +exception.Message+"  \n "
                +"\n"+"ID ������� ���������:"+IntToStr(TableIsm->TableID_XTISM->AsInteger));
                }

        if(DocAll->RecordCount==1)
                {
				type_doc=Trim(DocAll->FieldByName("TDOC")->AsString);
				prefiks_doc=Trim(DocAll->FieldByName("PREFIKSDOC")->AsString);
                }
        }

if (TableIsm->TableOPER_XTISM->AsInteger!=3)  //��� �������� �� ��������� �.�. ������� ��� ������ ���
	{                                         // � ������ ���������
	if (type_doc=="") return;
	if (prefiks_doc=="") return;

	if(CheckDocForTypeDoc(type_doc)==false) return;
	if(CheckDocForPrefiks(prefiks_doc)==false) return;



	if(DataOut->GetIdElement(IdBase,TableIsm->TableID_XTISM->AsInteger)!=0) return;     //�������� �� ��������� ��� � ��� ���������

	//�������� ������ �� ��������
	if (CheckRecordPoPrefiksu()==false) return;
	}

DataOut->AddRecordDataOut(IdBase,TableIsm->TableID_XTISM->AsInteger,IdMessage);


}

//-----------------------------------------------------------------------------
bool TDMUribOut::CheckDocForTypeDoc(String type_doc)
{
bool result=false;
if (AllDoc>0)
        {
        result=true;
        return result;
        }
         
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
bool TDMUribOut::CheckDocForPrefiks(AnsiString prefiks)
{
bool result=false;

if (OutPrefikss.AnsiPos(prefiks)>0)
        {
         result=true;
        }

return result;
}
//------------------------------------------------------------------------------
bool TDMUribOut::CheckRecordPoPrefiksu(void)
{
bool result=true;
String name_table=Trim(TableIsm->TableNAMETAB_XTISM->AsString);

//�������� ��������� �������
DMXTableBase->GetElementPoName(name_table);

//���� �� ������ ���� ��������, ������ ������ ������� ������������� ����� ������ ���������
if (Trim(DMXTableBase->ElementNAMEPREFIKS_XTABLE_BASE->AsString)=="") return result;

        AnsiString zapros="";
		IBQ->Close();
        IBQ->SQL->Clear();
		zapros=zapros+"select "+Trim(DMXTableBase->ElementNAMEPREFIKS_XTABLE_BASE->AsString);
        zapros=zapros+" from "+name_table;
		zapros=zapros+" where "+Trim(DMXTableBase->ElementNAMEGID_XTABLE_BASE->AsString);
		zapros=zapros+"='"+TableIsm->TableGIDREC_XTISM->AsString+"'";
        IBQ->SQL->Add(zapros);
        try
                {
				IBQ->ExecQuery();
                }
        catch (Exception &exception)
                {
				glSaveProtocol("������ � ������ DMUribOut->CheckRecordPoPrefiksu ��� ������ �������� �������� \n"
                +exception.Message+"  \n ������:"+zapros
                +"\n"+"ID ������� ���������:"+IntToStr(TableIsm->TableID_XTISM->AsInteger));
				}

AnsiString prefiks_rec=Trim(IBQ->FieldByName(Trim(DMXTableBase->ElementNAMEPREFIKS_XTABLE_BASE->AsString))->AsString);

if(CheckDocForPrefiks(prefiks_rec)==true)
	{
	result=true;
	}
else
	{
    result=false;
	}

return result;
}
//-----------------------------------------------------------------------------
//*****************************************************************************
//            ���������� ���������
//-----------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TDMUribOut::CreateXMLDoc(int id_message)
{
if (id_message==0) return;


//������� GID ���������
TDMXMessageObmen *DMMess=new TDMXMessageObmen(Application);
DMMess->OpenElement(id_message); 

//������� ������� � ������� ������� ����
TDMSprInfBase *DMSprBase=new TDMSprInfBase(Application);
DMSprBase->OpenElement(DMMess->ElementIDBASE_XMESSAGE_OBMEN->AsInteger);
//��������� � ����
FileNameOut=Trim(CatalogObmena)
                        +"\\"+Trim(DMSprBase->ElementPREFIKS_SINFBASE_OBMEN->AsString)
                        +"_"+Trim(DMMess->ElementGID_XMESSAGE_OBMEN->AsString)+".xml";
delete DMSprBase;
delete DMMess;
// �������� ���� ���� ��������� ���� �� ��� ������
if(FileExists(FileNameOut)==true)
        {
         DeleteFile(FileNameOut);
        }

SaveFileXML("<?xml version=\"1.0\" encoding=\"windows-1251\"?>");
SaveFileXML("<data>");
TableDataOut->Active=false;
TableDataOut->ParamByName("PARAM_IDMESSAGE")->AsInteger=id_message;
TableDataOut->Active=true;

TableDataOut->Last();

*lpKolRecord=TableDataOut->RecNo;
if(EventFirstRecord) EventFirstRecord(this);

int kol_rec=0;

DMXTableBase=new TDMXTableBase(Application);
DMXFieldBase=new TDMXFieldBase(Application);


TableDataOut->First();
while(!TableDataOut->Eof)
        { 

        if ( TableDataOutTYPEOB_XTISM->AsInteger==1)//����������
                {
                OutputSprInXMLFile(Trim(TableDataOutNAMETAB_XTISM->AsString),
                                TableDataOutIDREC_XTISM->AsInteger);
                }

        if ( TableDataOutTYPEOB_XTISM->AsInteger==2)//��������
                {
                OutputDocInXMLFile(Trim(TableDataOutNAMETAB_XTISM->AsString),
                                TableDataOutIDREC_XTISM->AsInteger);
                }

        TableDataOut->Next();

        kol_rec++;
        //LabelZagrIsm->Caption="��������� ���������: "+IntToStr(kol_rec);
        //LabelZagrIsm->Update();
        //ProgressBar1->StepIt();
        if(EventFirstRecord) EventNextRecord(this);
        }


SaveFileXML("</data>");

TableDataOut->Active=false;

delete DMXTableBase;
delete DMXFieldBase;


//TableFields->Active=false;
//TableFK->Active=false;
//TablePK->Active=false;
//ShowMessage("�������� ������ ���������!");
}
//-----------------------------------------------------------------------------
void TDMUribOut::OutputSprInXMLFile(String table_name, int id_record)
{
OutputTableInXMLFile(table_name, id_record);
}
//----------------------------------------------------------------------------
void TDMUribOut::OutputDocInXMLFile(String table_name, int id_record)
{
///���������� ��������� �� ������ ��������� ���������
//�� ����� ����� � ��������� �����

OutputTableInXMLFile(table_name, id_record);
}
//----------------------------------------------------------------------------
void TDMUribOut::OutputTableInXMLFile(String table_name, int id_record)
{
if (TableDataOutOPER_XTISM->AsInteger==3)     //�������� ������
	{
	OutputDeleteRecordInXMLFile(table_name);
	return;
	}

DMXTableBase->GetElementPoName(table_name);
DMXFieldBase->OpenTable(DMXTableBase->ElementID_XTABLE_BASE->AsInteger);

String name_pk=Trim(DMXTableBase->ElementNAMEPK_XTABLE_BASE->AsString); //������������ ���������� �����

//��������� ������
String zapros="";
IBQ->Close();
IBQ->SQL->Clear();
zapros=zapros+"select * from "+table_name;
zapros=zapros+" where "+name_pk+"="+IntToStr(id_record);
IBQ->SQL->Add(zapros);


//-------------------------------------------------
        try
				{
				IBQ->ExecQuery();
				}
		catch (Exception &exception)
				{
                glSaveProtocol("������ � ������ DMUribOut->OutputTableInXMLFile ��� �������� ���������� ������ \n"
				+exception.Message+"  \n "
                +"\n"+"ID ������� ���������:"+IntToStr(TableDataOutIDREC_XTISM->AsInteger)
				+"\n �������: "+TableDataOutNAMETAB_XTISM->AsString
                +"������:"+zapros);
				throw;
                }
//-------------------------------------------------
if (IBQ->RecordCount!=1) return;


String name_gid=Trim(DMXTableBase->ElementNAMEGID_XTABLE_BASE->AsString);
String value_gid=Trim(IBQ->FieldByName(name_gid)->AsString);//������� �������� Gid

//������� ���� � ��������� �������
String S="  ";
S=S+"<"+table_name+" num=\""+IntToStr(TableDataOut->RecNo)+"\""
		+" oper=\""+Trim(TableDataOutOPER_XTISM->AsString)+"\"";
S=S+" name_gid=\""+name_gid+"\""+" value_gid=\""+value_gid+"\"";
S=S+" name_pk=\""+name_pk+"\"";
S=S+">";
SaveFileXML(S);

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
IBQ->Close();
//IBQ2->Active=false;
}
//------------------------------------------------------------------------------
bool TDMUribOut::CheckFieldForOutput(String name_field, String name_table)
{
bool result=false;
if (name_field=="PRDOC") return result;
if (name_field=="IDPARTPERT") return result;//������ � ��� �����������  ������ ���� ���
if (name_field=="FL_CHANGE_NOM") return result;//  �� ���� ��������� ���� ��������� ���


//�������� ���� �� ��������� ���������� ����  
if (OutZakPrice==1)
	{ //��������� ���������� ����
	result=true;
	return result;
	}

//�� ���� ��������� ���������� ����
//������
if (name_field=="PRICEZPART") return result;

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
        String type_doc=Trim(IBQ->FieldByName("TDOC")->AsString);

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
void TDMUribOut::OutputFKInXMLFile(String name_field, int value_field)
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
               // RichEdit1->Lines->Add("zapros "+ zapros );

//-------------------------------------------------
                try
                        {
						IBQ2->ExecQuery();
                        }
                catch (Exception &exception)
                        {
                        glSaveProtocol("������ � ������ DMUribOut->OutputFKInXMLFile ��� ��������� �������� GID �������� ����� \n"
                        +exception.Message+"  \n "
                        +"\n"+"ID ������� ���������:"+IntToStr(TableDataOutIDREC_XTISM->AsInteger)
                        +"\n �������: "+TableDataOutNAMETAB_XTISM->AsString
                        +"\n ��� ����:"+ name_field
                        +"\n ������:"+zapros);
                        throw;
                        }
//-------------------------------------------------

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
void TDMUribOut::SaveFileXML(String str)
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
String TDMUribOut::FormatForXML(String s)
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
void  TDMUribOut::CreateStrBase(void)
{
TDMXTableBase *DMXTableBase=new TDMXTableBase(Application);
TDMXFieldBase *DMXFieldBase=new TDMXFieldBase(Application);
TableFK->Active=true;


//������ ���������� ���������
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


//������� ������ ������
TablePK->Active=true;

TablePK->Last();
//ProgressBar1->Max=TablePK->RecNo;
//ProgressBar1->Step=1;

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
                if (Trim(TableFieldsRDBFIELD_SOURCE->AsString)=="DOMAIN_IDDOC")
                        {  //��� ������� ���������
                        DMXTableBase->Element->Edit();
                        DMXTableBase->ElementNAMEIDDOC_XTABLE_BASE->AsString=Trim(TableFieldsRDBFIELD_NAME->AsString);
                        DMXTableBase->Element->Post();
                        DMXTableBase->SaveElement();
						}

				if (Trim(TableFieldsRDBFIELD_SOURCE->AsString)=="DOMAIN_PREFIKS")
                        {  //� ������� ������������ �������
                        DMXTableBase->Element->Edit();
						DMXTableBase->ElementNAMEPREFIKS_XTABLE_BASE->AsString=Trim(TableFieldsRDBFIELD_NAME->AsString);
                        DMXTableBase->Element->Post();
                        DMXTableBase->SaveElement();
						}



                DMXFieldBase->NewElement(DMXTableBase->ElementID_XTABLE_BASE->AsInteger);
                DMXFieldBase->Element->Edit();
                DMXFieldBase->ElementNAME_XFIELD_BASE->AsString=Trim(TableFieldsRDBFIELD_NAME->AsString);
                //����� ��� ���
                DMXFieldBase->ElementTYPE_XFIELD_BASE->AsInteger=TableFieldsRDBFIELD_TYPE->AsInteger;
                DMXFieldBase->ElementSCALE_XFIELD_BASE->AsInteger=TableFieldsRDBFIELD_SCALE->AsInteger;

                //������� ����
                if (Trim(TableFieldsRDBFIELD_SOURCE->AsString)=="DOMAIN_FK_KEY" ||
                        Trim(TableFieldsRDBFIELD_SOURCE->AsString)=="DOMAIN_IDDOC" )
                        {
                        DMXFieldBase->ElementFK_XFIELD_BASE->AsInteger=1;

                        TableFK->First();
                        while (!TableFK->Eof)
                                {
                                if (Trim(TableFKFIELD_NAME->AsString )==
                                              Trim(TableFieldsRDBFIELD_NAME->AsString))
                                        {
                                        DMXFieldBase->ElementFIELDFK_XFIELD_BASE->AsString=Trim(TableFKFIELD_FK->AsString);
                                        DMXFieldBase->ElementTABLEFK_XFIELD_BASE->AsString=Trim(TableFKTABLE_FK->AsString);
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
        //ProgressBar1->StepIt();
        }


TableFK->Active=false;
delete DMXTableBase;
delete DMXFieldBase;
//ShowMessage("��������� ���� ���������");
}
//-----------------------------------------------------------------------------
String TDMUribOut::GetNameGid(String name_table)
{
String result="";
				IBQ2->Close();
                IBQ2->SQL->Clear();
                String zapros="";
                zapros=zapros+"select RDB$FIELD_NAME from RDB$RELATION_FIELDS";
                zapros=zapros+" where RDB$RELATION_NAME='"+Trim(name_table);
                zapros=zapros+"' and RDB$FIELD_SOURCE='DOMAIN_GID'";
                IBQ2->SQL->Add(zapros);

//-------------------------------------------------
                try
                        {
                        IBQ2->ExecQuery();
                        }
                catch (Exception &exception)
                        {
                        glSaveProtocol("������ � ������ DMUribOut->GetNameGid ��� ��������� ����� ���� GID ������� \n"
                        +exception.Message+"  \n "
                        +"\n"+"ID ������� ���������:"+IntToStr(TableDataOutIDREC_XTISM->AsInteger)
                        +"������:"+zapros);
                        throw;
                        }
//-------------------------------------------------

                if (IBQ2->RecordCount==1)
                       {
                        result=Trim(IBQ2->FieldByName("RDB$FIELD_NAME")->AsString);
                        }


return result;
}
//-------------------------------------------------------------------------------
void  TDMUribOut::DeleteAllDataOut(void)
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
void TDMUribOut::OutProtocol(String str)
{
if (EnableOutProtocol==true)
        {
        //RichEdit1->Lines->Add(str);

        }
}
//----------------------------------------------------------------------------
void TDMUribOut::OutputDeleteRecordInXMLFile(AnsiString table_name)
{
DMXTableBase->GetElementPoName(table_name);
DMXFieldBase->OpenTable(DMXTableBase->ElementID_XTABLE_BASE->AsInteger);

String name_pk=Trim(DMXTableBase->ElementNAMEPK_XTABLE_BASE->AsString); //������������ ���������� �����


String name_gid=Trim(DMXTableBase->ElementNAMEGID_XTABLE_BASE->AsString);
String value_gid=Trim(TableDataOutGIDREC_XTISM->AsString);//������� �������� Gid

//������� ���� � ��������� �������
String S="  ";
S=S+"<"+table_name+" num=\""+IntToStr(TableDataOut->RecNo)+"\""
		+" oper=\""+Trim(TableDataOutOPER_XTISM->AsString)+"\"";
S=S+" name_gid=\""+name_gid+"\""+" value_gid=\""+value_gid+"\"";
S=S+" name_pk=\""+name_pk+"\"";
S=S+">";
SaveFileXML(S);

S="  ";
S=S+"</"+table_name+">";
SaveFileXML(S);

//IBQ2->Active=false;



}
//----------------------------------------------------------------------------
