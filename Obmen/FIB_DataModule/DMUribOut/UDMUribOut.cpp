//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMUribOut.h"
#include "UDM.h"
#include "UkanXmlFile.h"
#include "UGlobalFunction.h"
#include "encddecd.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBDataSet"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBDataSet"
#pragma link "pFIBQuery"
#pragma resource "*.dfm"

extern TDM * glDM;
//---------------------------------------------------------------------------
__fastcall TDMUribOut::TDMUribOut(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMUribOut::DataModuleCreate(TObject *Sender)
{
DMXDataOut=new TDMXDataOut(Application);
lpKolRecord=new int;
}
//---------------------------------------------------------------------------
void __fastcall TDMUribOut::DataModuleDestroy(TObject *Sender)
{
delete DMXDataOut;
delete lpKolRecord;
}

//---------------------------------------------------------------------------
bool TDMUribOut::CreateDataOutTable(__int64 id_base)
{
bool result=false;
glDM->glSaveProtocol("TDMUribOut: �������������� ������ ��� ����:"+IntToStr(id_base));

IdBaseForObmen=id_base;
if (IdBaseForObmen==0) return 0;

TableTypePriceForObmen->Active=false;
TableTypePriceForObmen->ParamByName("PARAM_IDBASE")->AsInt64=id_base;
TableTypePriceForObmen->Active=true;

TableBaseForObmen->Active=false;
TableBaseForObmen->ParamByName("PARAM_IDBASE")->AsInt64=id_base;
TableBaseForObmen->Active=true;

__int64 max_id=DMXDataOut->GetMaxIdTableIsm(id_base);
__int64 start_id_table_ism=0;

XSetupObmen->Active=false;
XSetupObmen->ParamByName("PARAM_IDBASE")->AsInt64=id_base;
XSetupObmen->Active=true;
start_id_table_ism=XSetupObmenIDTISM_XSETUP_OBMEN->AsInt64;

if (max_id<start_id_table_ism)
		{ //������ �����, ����� ���� �������� ��� ��������������� �����
        max_id=start_id_table_ism;
		}



glDM->glSaveProtocol("TDMUribOut: ��������� ������� ��������� � id"+IntToStr(max_id));

TableIsm->Close();
TableIsm->ParamByName("PARAM_IDMAX")->AsInt64=max_id;
TableIsm->ExecQuery();
//TableIsm->Active=true;

//������� ���������� ���������
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(" select count (xtism.id_xtism) from  XTISM where  ID_XTISM > :PARAM_IDMAX");
Query->ParamByName("PARAM_IDMAX")->AsInt64=max_id;
Query->ExecQuery();
*lpKolRecord=Query->FieldByName("COUNT")->AsInteger;
Query->Close();
if(EventFirstRecord) EventFirstRecord(this);

//TableIsm->First();
while(!TableIsm->Eof)
		{
		if (TableIsm->FieldByName("OPERATION_XTISM")->AsInteger<4)
			{ //�������� �� ��������� ������
			if (TableIsm->FieldByName("IDEXT_BASE_XTISM")->AsInt64==id_base)
				{  //� DataOut ���������� ���������  ��� ������� ���������
				DMXDataOut->AddRecordDataOut(IdBaseForObmen,
								TableIsm->FieldByName("ID_XTISM")->AsInt64,
								2,  //���������
								0); //���������
				}
			else
				{  //��������� ������
				AddInDataOutTable();
				}
			}

		if (TableIsm->FieldByName("OPERATION_XTISM")->AsInteger==4 ||
					TableIsm->FieldByName("OPERATION_XTISM")->AsInteger==5)
			{//������� ������ ���������� ��� ���������� ���������
			if (TableIsm->FieldByName("IDEXT_BASE_XTISM")->AsInt64==id_base)
				{  //� DataOut ���������� ���������  ��� ������� ���������
				DMXDataOut->AddRecordDataOut(IdBaseForObmen,
								TableIsm->FieldByName("ID_XTISM")->AsInt64,
								2,  //��������� 2 ������� 1
								0); //���������
				}
			else
				{  //��������� ������
				if (CheckBaseRecordForObmen(TableIsm->FieldByName("IDBASE_XTISM")->AsInt64)==true)
					{
					DMXDataOut->AddRecordDataOut(IdBaseForObmen,
								TableIsm->FieldByName("ID_XTISM")->AsInt64,
								1,  //��������� 2 ������� 1
								0); //���������
					}
				}
			}

		if(EventNextRecord) EventNextRecord(this);
		TableIsm->Next();
		}

TableTypePriceForObmen->Active=false;
TableBaseForObmen->Active=false;
TableIsm->Close();
XSetupObmen->Active=false;
result=true;

glDM->glSetOperation(IdBaseForObmen,20);

return result;

}
//-----------------------------------------------------------------------------
void TDMUribOut::AddInDataOutTable(void)
{
bool AddDataOut=true;
//����� �������� - ���� �� ��������� � ��������� ���� ������ ����������
//���������� ����
if (Trim(TableIsm->FieldByName("NAME_TABLE_XTISM")->AsString)=="SPRICE")
		{
		Price->Active=false;
		Price->ParamByName("PARAM_ID")->AsInt64=TableIsm->FieldByName("VALUE_FIELD_ID_XTISM")->AsInt64;
		Price->Active=true;
		AddDataOut=false;
		TableTypePriceForObmen->First();
		while(!TableTypePriceForObmen->Eof)
				{
				if(PriceIDTYPE_PRICE->AsInt64==
						TableTypePriceForObmenIDTPRICE_XTPRICE_FOR_OBMEN->AsInt64)
						{
						AddDataOut=true;
						break;
						}
				TableTypePriceForObmen->Next();
				}
		Price->Active=false;
		}
//���������� �������
if (XSetupObmenOUTZPRICE_XSETUP_OBMEN->AsInteger==1)
	{  //��������� ���������� ����
	}
else
	{//���������� �� ���������� �����, ������ �� ��������� � �������
	if (Trim(TableIsm->FieldByName("NAME_TABLE_XTISM")->AsString)=="SNACENKA"){AddDataOut=false;}
	}


if (Trim(TableIsm->FieldByName("NAME_TABLE_XTISM")->AsString)=="LOG"){AddDataOut=false;}
if (Trim(TableIsm->FieldByName("NAME_TABLE_XTISM")->AsString)=="SETUP"){AddDataOut=false;}
if (Trim(TableIsm->FieldByName("NAME_TABLE_XTISM")->AsString)=="SARM"){AddDataOut=false;}
if (Trim(TableIsm->FieldByName("NAME_TABLE_XTISM")->AsString)=="SOBORUD"){AddDataOut=false;}
if (Trim(TableIsm->FieldByName("NAME_TABLE_XTISM")->AsString)=="SVESNOM"){AddDataOut=false;}
if (Trim(TableIsm->FieldByName("NAME_TABLE_XTISM")->AsString)=="SSCALE"){AddDataOut=false;}
if (Trim(TableIsm->FieldByName("NAME_TABLE_XTISM")->AsString)=="GURNALPLAT"){AddDataOut=false;}

if (Trim(TableIsm->FieldByName("NAME_TABLE_XTISM")->AsString)=="GALLDOC")
	{
	//�������� ����� ���� ��������, ���� ������ PRDOC �� ������ �� ���������
	TableIsmFields->Active=false;
	TableIsmFields->ParamByName("PARAM_IDXTISM")->AsInt64=
										TableIsm->FieldByName("ID_XTISM")->AsInt64;
	TableIsmFields->Active=true;
	if (TableIsmFields->RecordCount==1 &&
					Trim(TableIsmFieldsFIELD_NAME_XTISM_FIELDS->AsString)=="PRDOC")
		{//������ �� ���������
		AddDataOut=false;
		}
    TableIsmFields->Active=false;
	}

if (Trim(TableIsm->FieldByName("NAME_TABLE_XTISM")->AsString)=="REM_GALLDOC")
	{
	//�������� ����� ���� ��������, ���� ������ PRDOC �� ������ �� ���������
	TableIsmFields->Active=false;
	TableIsmFields->ParamByName("PARAM_IDXTISM")->AsInt64=
										TableIsm->FieldByName("ID_XTISM")->AsInt64;
	TableIsmFields->Active=true;
	if (TableIsmFields->RecordCount==1 &&
					Trim(TableIsmFieldsFIELD_NAME_XTISM_FIELDS->AsString)=="PR_REM_GALLDOC")
		{//������ �� ���������
		AddDataOut=false;
		}
	TableIsmFields->Active=false;
	}

if (Trim(TableIsm->FieldByName("NAME_TABLE_XTISM")->AsString)=="HOT_GALLDOC")
	{
	//�������� ����� ���� ��������, ���� ������ PRDOC �� ������ �� ���������
	TableIsmFields->Active=false;
	TableIsmFields->ParamByName("PARAM_IDXTISM")->AsInt64=
										TableIsm->FieldByName("ID_XTISM")->AsInt64;
	TableIsmFields->Active=true;
	if (TableIsmFields->RecordCount==1 &&
					Trim(TableIsmFieldsFIELD_NAME_XTISM_FIELDS->AsString)=="PR_HOT_GALLDOC")
		{//������ �� ���������
		AddDataOut=false;
		}
	TableIsmFields->Active=false;
	}

//�������� ������ �� ����
if (CheckBaseRecordForObmen(TableIsm->FieldByName("IDBASE_XTISM")->AsInt64)==false)return;

if(DMXDataOut->GetIdElement(IdBaseForObmen,TableIsm->FieldByName("ID_XTISM")->AsInt64)==0 && AddDataOut==true)
        {
		if (DMXDataOut->AddRecordDataOut(IdBaseForObmen,TableIsm->FieldByName("ID_XTISM")->AsInt64,1,0)==false)
			{
			glDM->glSaveProtocol(" ������ ��� ���������� ������ � ������� XDATAOUT "+DMXDataOut->TextError);
			}
        } 
}

//-----------------------------------------------------------------------------
bool TDMUribOut::CheckBaseRecordForObmen(__int64 id_base_object)
{
bool result=false;
//�������� AllDoc
if (XSetupObmenALLDOC_XSETUP_OBMEN->AsInteger==1)
	{  //��������� ��� ���������
	result==true;
	}
else
	{//���������� �� ��������� �����
	//����������� ��������� ������ ���� ���� ������ ���� ���� �� ������
	if (TableIsm->FieldByName("TYPE_OBJECT_XTISM")->AsInteger==1)
		{
		result=true;
		}

	//��������� � ������� �� ������ ���� �� ���������
	if (TableIsm->FieldByName("TYPE_OBJECT_XTISM")->AsInteger==2)
		{
		if (id_base_object==0)
			{
			result=false;
			}
		}

	TableBaseForObmen->First();
	while(!TableBaseForObmen->Eof)
		{
		if(id_base_object==TableBaseForObmenIDBASE_OBJECT_XBASE_FOR_OBMEN->AsInt64)
			{
			result=true;
			break;
			}
		TableBaseForObmen->Next();
		}
	}
return result;
}
//------------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//*****************************************************************************
//            ���������� ���������
//-----------------------------------------------------------------------------
//---------------------------------------------------------------------------
bool TDMUribOut::CreateXMLDoc(__int64 id_base, bool povtor)
{
bool result=false;

glDM->glSaveProtocol("��������� ��������� ������������ ����� CreateXMLDoc ��� ���� ID "+IntToStr(id_base)+" \n");


try
	{
IdBaseForObmen=id_base; //���� ��������

//���� ��������, ������� ����
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(" select setup.value_setup from setup where setup.id_setup=3");
Query->ExecQuery();
IdTecBase=StrToInt64(Query->FieldByName("VALUE_SETUP")->AsString);
Query->Close();
glDM->glSaveProtocol("ID ������� ���� - "+IntToStr(IdTecBase)+" \n");

//��������� ������
XSetupObmen->Active=false;
XSetupObmen->ParamByName("PARAM_IDBASE")->AsInt64=id_base;
XSetupObmen->Active=true;


FileNameOut=ExtractFileDir(Application->ExeName)+"\\Files\\DataFor"+IntToStr(id_base)+".kas";
glDM->glSaveProtocol("��� ����� ������"+FileNameOut+" \n");
// �������� ���� ���� ��������� ���� �� ��� ������
if(FileExists(FileNameOut)==true)
		{
		glDM->glSaveProtocol("������� ���������� ���� ������ ��� �����"+FileNameOut+" \n");
		 DeleteFile(FileNameOut);
		}


TkanXmlFile * f=new TkanXmlFile;
f->GreateHeader(FileNameOut);
glDM->glSaveProtocol("������� ���������"+FileNameOut+" \n");
delete f;

if (SaveFileXML("<data>")==false)
	{
	throw Exception("������ ��� ������ ������ � ����");
	}

TableDataOut->Close();

if (povtor==true)  //��� ��������� ������������ ����� �������� ���������
	{              // ������� ��� ����������� � ��
	OutputPovtorKvitan();
	}

TableDataOut->ParamByName("PARAM_IDBASE")->AsInt64=id_base;
TableDataOut->ExecQuery();
//TableDataOut->Active=true;

if (povtor==false)
	{//�������� ��������� �������� ID_XDATA_OUT
	SetFirstId->ParamByName("PARAM_IDFIRST")->AsInt64=
									glStrToInt64(TableDataOut->FieldByName("ID_XDATA_OUT")->AsString);
	SetFirstId->ParamByName("PARAM_IDBASE")->AsInt64=IdBaseForObmen;
	SetFirstId->ExecQuery();
	TrUpdate->Commit();
	SetFirstId->Close();
	}


//������� ���������� ���������
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(" select count(xdata_out.id_xdata_out)");
Query->SQL->Add(" from XDATA_OUT");
Query->SQL->Add(" where  (RESULT_XDATA_OUT is null or RESULT_XDATA_OUT<>1)");
Query->SQL->Add(" and IDBASE_XDATA_OUT=:PARAM_IDBASE");
Query->ParamByName("PARAM_IDBASE")->AsInt64=IdBaseForObmen;
Query->ExecQuery();
*lpKolRecord=Query->FieldByName("COUNT")->AsInteger;
Query->Close();

glDM->glSaveProtocol("���������� ��������� � ����"+IntToStr(*lpKolRecord)+" ������� \n");

if(EventFirstRecord) EventFirstRecord(this);
NumberTecRecord=1;
//TableDataOut->First();
while(!TableDataOut->Eof)
		{
		if (TableDataOut->FieldByName("TYPE_XDATA_OUT")->AsInteger==2)
			{//��������� ���������
			OutputKvitan(glStrToInt64(TableDataOut->FieldByName("IDEXT_DATAOUT_XTISM")->AsString));
			}

		if (TableDataOut->FieldByName("TYPE_XDATA_OUT")->AsInteger==1)
			{//��������� ���������
			//��������� ������
			if (TableDataOut->FieldByName("OPERATION_XTISM")->AsInteger<4)
				{
				OutputTableInXMLFile();
				}
			//������� ���������� ��� ������ ���������� ���������
			if (TableDataOut->FieldByName("OPERATION_XTISM")->AsInteger==4 ||
							TableDataOut->FieldByName("OPERATION_XTISM")->AsInteger==5)
				{
				OutputComandDvReg(); 
				} 
			}

		if(EventFirstRecord) EventNextRecord(this);
		NumberTecRecord++;
        TableDataOut->Next();
        }


SaveFileXML("</data>");

TableDataOut->Close();

SetOKAllKvitan(id_base);

if(FileExists(FileNameOut)==true)
		{
		glDM->glSaveProtocol("���� ����������� ��� �����"+FileNameOut+" \n");
		result=true;
		}
else
	{
	glDM->glSaveProtocol("���� �� ����������� ��� �����"+FileNameOut+" \n");
	result=false;
	}

}
catch (Exception &exception)
		{
		result=false;
		glDM->glSaveProtocol("������ ��� ������������ ����� "+FileNameOut+" \n");
		TextError=exception.Message;
		}

return result;
}

//----------------------------------------------------------------------------
void TDMUribOut::OutputKvitan(__int64 idext_data_out)
{

//������� ���� � ��������� �������
UnicodeString S="  ";
S=S+"<XDATA_OUT num=\""+IntToStr(NumberTecRecord)+"\"" ;
S=S+" type=\"2\""; // ������� ������ 1, ������������� 2
S=S+" id_base_ist=\""+IntToStr(IdTecBase)+"\"";
S=S+" id_base_priem=\""+IntToStr(IdBaseForObmen)+"\"";
S=S+" idext_data_out=\""+IntToStr(idext_data_out)+"\"";

S=S+">";
SaveFileXML(S);

S="  ";
S=S+"</XDATA_OUT>";
SaveFileXML(S);


}
//----------------------------------------------------------------------------
void TDMUribOut::OutputComandDvReg(void)
{

//������� ���� � ��������� �������
UnicodeString S="  ";
S=S+"<"+Trim(TableDataOut->FieldByName("NAME_TABLE_XTISM")->AsString)+" num=\""+IntToStr(NumberTecRecord)+"\"" ;
S=S+" type=\"1\""; // ������� ������ 1, ������������� 2
S=S+" oper=\""+IntToStr(TableDataOut->FieldByName("OPERATION_XTISM")->AsInteger)+"\""; //
S=S+" name_pk=\""+Trim(TableDataOut->FieldByName("NAME_FIELD_ID_XTISM")->AsString)+"\"";
S=S+" value_pk=\""+Trim(TableDataOut->FieldByName("VALUE_FIELD_ID_XTISM")->AsString)+"\"";
S=S+" idext_base=\""+IntToStr(IdTecBase)+"\"";
S=S+" idext_data_out=\""+Trim(TableDataOut->FieldByName("ID_XDATA_OUT")->AsString)+"\"";
S=S+">";
SaveFileXML(S);

S="  ";
S=S+"</"+Trim(TableDataOut->FieldByName("NAME_TABLE_XTISM")->AsString)+">";
SaveFileXML(S);


}
//----------------------------------------------------------------------------
void TDMUribOut::OutputTableInXMLFile(void)
{
if (TableDataOut->FieldByName("OPERATION_XTISM")->AsInteger==3)     //�������� ������
	{
	OutputDeleteRecordInXMLFile();
	return;
	}

//������� ���� � ��������� �������
UnicodeString S="  ";
S=S+"<"+Trim(TableDataOut->FieldByName("NAME_TABLE_XTISM")->AsString)+" num=\""+IntToStr(NumberTecRecord)+"\"";
S=S+" type=\"1\""; // ������� ������ 1, ������������� 2
S=S+" oper=\""+Trim(TableDataOut->FieldByName("OPERATION_XTISM")->AsString)+"\"";
S=S+" name_pk=\""+Trim(TableDataOut->FieldByName("NAME_FIELD_ID_XTISM")->AsString)+"\"";
S=S+" value_pk=\""+Trim(TableDataOut->FieldByName("VALUE_FIELD_ID_XTISM")->AsString)+"\"";
S=S+" idext_base=\""+IntToStr(IdTecBase)+"\"";
S=S+" idext_data_out=\""+Trim(TableDataOut->FieldByName("ID_XDATA_OUT")->AsString)+"\"";
S=S+">";
SaveFileXML(S);

TableIsmFields->Active=false;
TableIsmFields->ParamByName("PARAM_IDXTISM")->AsInt64=
										glStrToInt64(TableDataOut->FieldByName("IDTISM_XDATA_OUT")->AsString);
TableIsmFields->Active=true;

//��������� ������ � ����
TableIsmFields->First();
while(!TableIsmFields->Eof)
		{
		UnicodeString name_field=Trim(TableIsmFieldsFIELD_NAME_XTISM_FIELDS->AsString);
		UnicodeString value_field="";

        //�������� ���� �� ��������� ����
		if (CheckFieldForOutput(name_field, Trim(TableDataOut->FieldByName("NAME_TABLE_XTISM")->AsString))==false)
                {
				TableIsmFields->Next();
                continue;
				}
	   //���������� ��������� ��� ���� ����� ����
	   // ������� ������
	   // BLOB
	   //� ���� ������ ���� �������� ������ ��� ����� � value_field
	   //���� �������� ������������� �����
	   UnicodeString S="    ";
	   S=S+"<"+name_field;
		if (TableIsmFieldsTYPE_XTISM_FIELDS->AsInteger==2)
			{ //������� ������
			S=S+" t=\"2\"";
			value_field=GetTextValueFieldLongString(Trim(TableDataOut->FieldByName("NAME_TABLE_XTISM")->AsString),
													Trim(TableDataOut->FieldByName("NAME_FIELD_ID_XTISM")->AsString),
													glStrToInt64(Trim(TableDataOut->FieldByName("VALUE_FIELD_ID_XTISM")->AsString)),
								 					name_field);
			}
		else if (TableIsmFieldsTYPE_XTISM_FIELDS->AsInteger==3)
			{  //BLOB
			S=S+" t=\"3\"";
			value_field=GetTextValueFieldBlob(Trim(TableDataOut->FieldByName("NAME_TABLE_XTISM")->AsString),
													Trim(TableDataOut->FieldByName("NAME_FIELD_ID_XTISM")->AsString),
													glStrToInt64(Trim(TableDataOut->FieldByName("VALUE_FIELD_ID_XTISM")->AsString)),
								 					name_field);
			}
		else
			{
			S=S+" t=\"1\"";
			value_field=Trim(TableIsmFieldsNEW_VALUE_XTISM_FIELDS->AsString);
			}



		TkanXmlFile * f=new TkanXmlFile;
		S=S+" v=\""+f->FormatForXML(value_field)+"\"";
		delete f;

		S=S+"/>";
		SaveFileXML(S);


		TableIsmFields->Next();
		}

TableIsmFields->Active=false;

S="  ";
S=S+"</"+Trim(TableDataOut->FieldByName("NAME_TABLE_XTISM")->AsString)+">";
SaveFileXML(S);

}
//------------------------------------------------------------------------------
bool TDMUribOut::CheckFieldForOutput(UnicodeString name_field, UnicodeString name_table)
{
bool result=false;
//�� ��������� ���� IDEXT_BASE � IDEXT_DOUT
if(name_field=="IDEXT_BASE_"+Trim(name_table)) return result;
if(name_field=="IDEXT_DOUT_"+Trim(name_table)) return result;

if (name_field=="PRDOC") return result;
if (name_field=="PR_REM_GALLDOC") return result;
if (name_field=="PR_HOT_GALLDOC") return result;
if (name_field=="IDPARTPERT") return result;//������ � ��� �����������  ������ ���� ���
if (name_field=="FL_CHANGE_NOM") return result;//  �� ���� ��������� ���� ��������� ���


//�������� ���� �� ��������� ���������� ����  
if (XSetupObmenOUTZPRICE_XSETUP_OBMEN->AsInteger==1)
	{  //��������� ���������� ����
	}
else
	{//���������� �� ���������� �����,
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
		Query->Close();
		Query->SQL->Clear();
		Query->SQL->Add(" select TDOC from  GALLDOC where IDDOC="+
						Trim(TableDataOut->FieldByName("VALUE_FIELD_ID_XTISM")->AsString));
		Query->ExecQuery();
		UnicodeString type_doc=Trim(Query->FieldByName("TDOC")->AsString);

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
		Query->Close();
        } 
	}
	        
result=true;
return result;

}

//---------------------------------------------------------------------------
bool TDMUribOut::SaveFileXML(UnicodeString str)
{
bool result;
TkanXmlFile * f=new TkanXmlFile;
result=f->AddString(FileNameOut,str);
delete f;
return result;
}
//----------------------------------------------------------------------------
void TDMUribOut::OutputDeleteRecordInXMLFile(void)
{

//������� ���� � ��������� �������
String S="  ";
S=S+"<"+Trim(TableDataOut->FieldByName("NAME_TABLE_XTISM")->AsString)+" num=\""+IntToStr(NumberTecRecord)+"\"" ;
S=S+" type=\"1\""; // ������� ������ 1, ������������� 2
S=S+" oper=\""+Trim(TableDataOut->FieldByName("OPERATION_XTISM")->AsString)+"\"";
S=S+" name_pk=\""+Trim(TableDataOut->FieldByName("NAME_FIELD_ID_XTISM")->AsString)+"\"";
S=S+" value_pk=\""+Trim(TableDataOut->FieldByName("VALUE_FIELD_ID_XTISM")->AsString)+"\"";
S=S+" idext_base=\""+IntToStr(IdTecBase)+"\"";
S=S+" idext_data_out=\""+Trim(TableDataOut->FieldByName("ID_XDATA_OUT")->AsString)+"\"";
S=S+">";
SaveFileXML(S);

S="  ";
S=S+"</"+Trim(TableDataOut->FieldByName("NAME_TABLE_XTISM")->AsString)+">";
SaveFileXML(S);

//IBQ2->Active=false;



}
//----------------------------------------------------------------------------
void TDMUribOut::SetOKAllKvitan(__int64 id_base)
{
KvitanSetOK->Close();
KvitanSetOK->ParamByName("PARAM_IDBASE")->AsInt64=id_base;

	try
		{
		KvitanSetOK->ExecQuery();
		TrUpdate->Commit();
		}

	catch (Exception &exception)
		{
		glDM->glSaveProtocol("������ � ������ DMUribOut->SetOKAllKvitan \n");
		TrUpdate->Rollback();
		}
KvitanSetOK->Close();

}
//---------------------------------------------------------------------------
void TDMUribOut::OutputPovtorKvitan(void)
{

//������� ��������� �����
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(" select IDFIRST_DO_XSETUP_OBMEN from  XSETUP_OBMEN where IDBASE_OBMEN_XSETUP_OBMEN="+
						IntToStr(IdBaseForObmen));
Query->ExecQuery();

TableKvitan->Active=false;
TableKvitan->ParamByName("PARAM_IDFIRST_DATAOUT")->AsInt64=
							Query->FieldByName("IDFIRST_DO_XSETUP_OBMEN")->AsInt64;
glDM->glSaveProtocol("TDMUribOut: �������� ��������� ��������� � :"+IntToStr(Query->FieldByName("IDFIRST_DO_XSETUP_OBMEN")->AsInt64));
Query->Close();

TableKvitan->Active=true;
TableKvitan->First();
while(!TableKvitan->Eof)
	{
	OutputKvitan(TableKvitanIDEXT_DATAOUT_XTISM->AsInt64);
	TableKvitan->Next();
	}
TableKvitan->Active=false;
}
//-----------------------------------------------------------------------------
UnicodeString TDMUribOut::GetTextValueFieldBlob(UnicodeString name_table,
								 UnicodeString name_pk,
								 __int64 value_pk,
								 UnicodeString name_field)
{
UnicodeString result="";

UnicodeString z="select "+name_field+" from "+name_table;
z=z+" where "+name_pk+"='"+value_pk+"'";
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(z);
Query->ExecQuery();

TMemoryStream *m=new TMemoryStream();
Query->FieldByName(name_field)->SaveToStream(m);
Query->Close();

m->Position=0;
char * buf = new char [m->Size];
m->Read(buf,m->Size);


AnsiString ansi_result=EncodeBase64(buf,m->Size);

delete buf;
delete m;


result=ansi_result;





return result;
}
//-----------------------------------------------------------------------------

UnicodeString TDMUribOut::GetTextValueFieldLongString(UnicodeString name_table,
								 UnicodeString name_pk,
								 __int64 value_pk,
								 UnicodeString name_field)
{
UnicodeString result="";

UnicodeString z="select "+name_field+" from "+name_table;
z=z+" where "+name_pk+"='"+value_pk+"'";
Query->Close();
Query->SQL->Clear();
Query->SQL->Add(z);
Query->ExecQuery();
result=Query->FieldByName(name_field)->AsString;
Query->Close();


return result;
}
//-----------------------------------------------------------------------------
