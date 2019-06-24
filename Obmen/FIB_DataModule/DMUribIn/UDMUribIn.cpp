//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMUribIn.h"
#include "UDM.h"
#include "UkanTxtFile.h"
#include "UkanXmlFile.h"
#include "encddecd.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBQuery"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"


extern UnicodeString glGetNameProcedureCancelDvReg(UnicodeString type_doc);
extern UnicodeString glGetNameProcedureDvReg(UnicodeString type_doc);

extern UnicodeString glGetNameProcedureCancelDvRegHotelSystem(UnicodeString type_doc);
extern UnicodeString glGetNameProcedureDvRegHotelSystem(UnicodeString type_doc);

extern UnicodeString glGetNameProcedureCancelDvRegRemontSystem(UnicodeString type_doc);
extern UnicodeString glGetNameProcedureDvRegRemontSystem(UnicodeString type_doc);

extern TDM * glDM;
//---------------------------------------------------------------------------
__fastcall TDMUribIn::TDMUribIn(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMUribIn::DataModuleCreate(TObject *Sender)
{
lpKolRecord=new int;

OutputPodrProtokol=false;
}
//---------------------------------------------------------------------------
void __fastcall TDMUribIn::DataModuleDestroy(TObject *Sender)
{
delete lpKolRecord;

}
//---------------------------------------------------------------------------
void TDMUribIn::UpdateDataInfBase(UnicodeString full_name_file_xml)
{

if (FileExists(full_name_file_xml)!=true)
		{
		glDM->glSaveProtocol("�� ������ ���� ��� ��������: "+full_name_file_xml);
		return;
		}

TkanXmlFile * file=new TkanXmlFile();
if (file->OpenFile(full_name_file_xml)==false)
	{
    OutProtocol("�� ������� ������� xml ����!");
	}


UnicodeString str_1="";
UnicodeString str_2="";
UnicodeString str_end="</data>";

//1 ������ ���������
if (!file->Eof())
		{
		str_1=file->ReadString();
		}

//2 ������ ��������� ����
if (!file->Eof())
		{
		str_2=file->ReadString();
		}
        
kol_rec=0;
int kol_tec_record=0;
*lpKolRecord=0;
if(EventFirstRecord) EventFirstRecord(this);

while(!file->Eof())
		{
		UnicodeString text_xml=file->ReadString();
        if (Trim(text_xml)==str_end)  {break;}
        //������� ����������� �������
		UnicodeString end_element=Trim(text_xml);
        end_element=Trim(end_element.SetLength(end_element.Pos(" ")));
        end_element=Trim(end_element.Delete(1,1));
        end_element="</"+end_element+">";

        bool end=false;
		while((!file->Eof()) && end==false)
                {
				AnsiString tec_str=Trim(file->ReadString());
                if (tec_str==end_element)
                        {
                        end=true;

                        }
                text_xml=text_xml+" "+tec_str;
                } 

		text_xml=str_1+" "+str_2+" "+text_xml+" "+str_end;


		UpdateInfBase(text_xml);
		//kol_rec++;



		if (kol_tec_record==10000)
			{
			kol_tec_record=0;
			glDM->glSaveProtocol("��������� ���������: "+IntToStr(kol_rec));
			}
		else
			{
			kol_tec_record++;

			}

		text_xml="";
		if(EventFirstRecord) EventNextRecord(this);			
		}


file->CloseFile();


glDM->glSaveProtocol("��������� ���������: "+IntToStr(kol_rec));



}
//-----------------------------------------------------------------------------
void TDMUribIn::UpdateInfBase(UnicodeString text_xml)
{

//ShowMessage(text_xml);

xml->LoadFromXML(text_xml);

_di_IXMLNode  xml_base=xml->DocumentElement;

  for (int i=0; i<xml_base->ChildNodes->Count; i++)    //1 ������� ����� ����������
        {


        _di_IXMLNode xml_rec=xml_base->ChildNodes->Get(i);
        NumberRecord=xml_rec->GetAttribute("num");

			if (OutputPodrProtokol==true)
				{
				glDM->glSaveProtocol("����� ������: "+IntToStr(NumberRecord));
				}


		int type=(int)StrToFloat(xml_rec->GetAttribute("type"));

		switch (type)
			{
			case 1:  //���������� ������
				{
				int operation=(int)StrToFloat(xml_rec->GetAttribute("oper"));
					switch (operation)
						{

						case 1 :  //�������
							{
							InsertRecord(xml_rec);
							} break;
						case 2 :  //��������������
							{
							EditRecord(xml_rec);
							} break;
						case 3 :  //��������
							{
							DeleteRecord(xml_rec);
							} break;
						case 4 :  //������ ���������� ���������
							{
							RunComandCancelDvRegDoc(xml_rec);
							} break;
						case 5 :  //���������� ���������
							{
							RunComandDvRegDoc(xml_rec);
							} break;


						default :
							{

							} break;
						}
				} break;
			case 2:   //��������� �� �������� ��������
                {
				InputKvitan(xml_rec);
				} break;
			}
        OutProtocol("");

        //xml_base->ChildNodes->Delete(0);
        kol_rec++;

        }
xml->Active = false;
}
//------------------------------------------------------------------------------
void TDMUribIn::InsertRecord(_di_IXMLNode xml_rec)
{
UnicodeString name_table=Trim(xml_rec->NodeName);
UnicodeString name_field_id=xml_rec->GetAttribute("name_pk");
UnicodeString value_field_id=xml_rec->GetAttribute("value_pk");

OutProtocol("table_name "+ name_table);
OutProtocol("name_field_gid "+ name_field_id);
OutProtocol("value_gid "+ value_field_id);


QueryRecord->Close();
QueryRecord->SQL->Clear();
UnicodeString zapros="";
zapros=zapros+"select * from "+name_table;
zapros=zapros+" where "+name_field_id+"='"+value_field_id+"'";
QueryRecord->SQL->Add(zapros);

        try
                {
				QueryRecord->ExecQuery();
                }
        catch (Exception &exception)
                {
				glDM->glSaveProtocol("������ � ������ DMUribIn->InsertRecord ��� ��������� �������� �� ID \n"
                +exception.Message+"  \n ������:"+zapros
                +"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
                }

        ///�������� ����� ������� �������
zapros="";
if (QueryRecord->RecordCount==0)  //������ �� �������
	{
	zapros=CreateTextZaprosInsert(xml_rec);
	}
else
	{
	zapros=CreateTextZaprosEdit(xml_rec);
	}

QueryUpdateRecord->Close();
QueryUpdateRecord->SQL->Clear();
QueryUpdateRecord->SQL->Add(zapros);

		UnicodeString str_parameter=" �������� ����������: ";
		try
				{
				//��������� ��������� ����� ������� �� �������� ����
				for (int i=0;i<xml_rec->ChildNodes->Count;i++)
					{
					_di_IXMLNode xml_field=xml_rec->ChildNodes->Get(i);
					UnicodeString name_field=xml_field->NodeName;

					if (CheckFieldForInsert(name_field)==false) continue; //�������� ����

					UnicodeString value_field="";
					if (xml_field->GetAttribute("v").IsNull() == false)
						{value_field=xml_field->GetAttribute("v");}

					UnicodeString str_type_field="";
					if (xml_field->GetAttribute("t").IsNull()==false)
						{str_type_field=xml_field->GetAttribute("t"); }


					int type_field=0;
					if (str_type_field != "")
						{
                        type_field=StrToInt(str_type_field);
						}
				   //������ �� ��������� ������ �������� ""
				   //��� ��� ���� ����� ���� ������ �������, ������� ��������

						if (type_field == 2)
							{//������� ������
							 QueryUpdateRecord->ParamByName("PARAM_"+name_field)->AsString=value_field;
							 str_parameter=" PARAM_"+name_field+" = "+value_field;
							}
						else if (type_field == 3)
							{//BLOB
							AnsiString ansi_str=value_field;
							TBytes buf;
							buf=DecodeBase64(ansi_str);
							if (buf.Length > 0)
								{
								TMemoryStream *m=new TMemoryStream();
								m->WriteBuffer(&buf[0],buf.Length);
								m->Position=0;
								QueryUpdateRecord->ParamByName("PARAM_"+name_field)->LoadFromStream(m);
								delete m;
								}
							else
								{
								QueryUpdateRecord->ParamByName("PARAM_"+name_field)->Clear();
								}
							}
						else
							{
							 QueryUpdateRecord->ParamByName("PARAM_"+name_field)->AsString=value_field;
							 str_parameter=" PARAM_"+name_field+" = "+value_field;
							}
					}


				QueryUpdateRecord->ExecQuery();
				TrUpdateRecord->Commit();
				}

		catch (Exception &exception)
				{
				glDM->glSaveProtocol("\n������ � ������ DMUribIn->InsertRecord ��� ������� ������ \n"
						+exception.Message
						+"\n ������:"+zapros
						+"\n ������ ����������:"+str_parameter
						+"\n ����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
				TrUpdateRecord->Rollback();
				}
QueryUpdateRecord->Close();

//ProveritPosledProvDoc(xml_rec);
}
//-----------------------------------------------------------------------------
void TDMUribIn::EditRecord(_di_IXMLNode xml_rec)
{
UnicodeString name_table=Trim(xml_rec->NodeName);

//�������� ������������ ID
UnicodeString name_field_id=xml_rec->GetAttribute("name_pk");
UnicodeString value_field_id=xml_rec->GetAttribute("value_pk");

OutProtocol("table_name "+ name_table);
OutProtocol("name_field_gid "+ name_field_id);
OutProtocol("value_gid "+ value_field_id);

//������� ������� �� ��� ID
QueryRecord->Close();
QueryRecord->SQL->Clear();
UnicodeString zapros="";
zapros=zapros+"select * from "+name_table;
zapros=zapros+" where "+name_field_id+"='"+value_field_id+"'";
QueryRecord->SQL->Add(zapros);
QueryRecord->ExecQuery();

///�������� ����� ������� �������
zapros="";
if (QueryRecord->RecordCount==0)  //������ �� �������
	{
	zapros=CreateTextZaprosInsert(xml_rec);
	}
else
	{
	zapros=CreateTextZaprosEdit(xml_rec);
	}

QueryUpdateRecord->Close();
QueryUpdateRecord->SQL->Clear();
QueryUpdateRecord->SQL->Add(zapros);

			UnicodeString str_parameter=" �������� ����������: ";
			try
				{
				//��������� ��������� ����� ������� �� �������� ����
				for (int i=0;i<xml_rec->ChildNodes->Count;i++)
					{
					_di_IXMLNode xml_field=xml_rec->ChildNodes->Get(i);
					UnicodeString name_field=xml_field->NodeName;

					if (CheckFieldForEdit(name_field)==false) continue; //�������� ����

					UnicodeString value_field="";
					if (xml_field->GetAttribute("v").IsNull()==false)
						{value_field=xml_field->GetAttribute("v");}


					UnicodeString str_type_field="";
					if (xml_field->GetAttribute("t").IsNull()==false)
						{str_type_field=xml_field->GetAttribute("t");}



					int type_field=0;
					if (str_type_field != "")
						{
                        type_field=StrToInt(str_type_field);
						}


						if (type_field == 2)
							{//������� ������
							 QueryUpdateRecord->ParamByName("PARAM_"+name_field)->AsString=value_field;
							 str_parameter=" PARAM_"+name_field+" = "+value_field;
							}
						else if (type_field == 3)
							{//BLOB
							AnsiString ansi_str=value_field;
							TBytes buf;
							buf=DecodeBase64(ansi_str);
							if (buf.Length > 0)
								{
								TMemoryStream *m=new TMemoryStream();
								m->WriteBuffer(&buf[0],buf.Length);
								m->Position=0;
								QueryUpdateRecord->ParamByName("PARAM_"+name_field)->LoadFromStream(m);
								delete m;
								}
							else
								{
								QueryUpdateRecord->ParamByName("PARAM_"+name_field)->Clear();
								}


							}
						else
							{
							 QueryUpdateRecord->ParamByName("PARAM_"+name_field)->AsString=value_field;
							 str_parameter=" PARAM_"+name_field+" = "+value_field;
							}
					}




				QueryUpdateRecord->ExecQuery();
				TrUpdateRecord->Commit();
				}

			catch (Exception &exception)
				{
						glDM->glSaveProtocol("\n������ � ������ DMUribIn->EditRecord ��� ������� ������ \n"
						+exception.Message
						+"\n ������:"+zapros
						+"\n ������ ����������:"+str_parameter
						+"\n ����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
						TrUpdateRecord->Rollback();
				}

QueryUpdateRecord->Close();

//ProveritPosledProvDoc(xml_rec);
}
//---------------------------------------------------------------------------
void TDMUribIn::DeleteRecord(_di_IXMLNode xml_rec)
{
glDM->glSaveProtocol(" ------- \n ��������� ��������� �������� ������! \n ����� ������:"
			+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));

UnicodeString name_table=Trim(xml_rec->NodeName);

//�������� ������������ ID
UnicodeString name_field_id=xml_rec->GetAttribute("name_pk");
UnicodeString value_field_id=xml_rec->GetAttribute("value_pk");

UnicodeString name_field_idext_base="IDEXT_BASE_"+name_table;
UnicodeString value_field_idext_base=xml_rec->GetAttribute("idext_base");

UnicodeString name_field_idext_dataout="IDEXT_DOUT_"+name_table;
UnicodeString value_field_idext_dataout=xml_rec->GetAttribute("idext_data_out");

QueryRecord->Close();
QueryRecord->SQL->Clear();
UnicodeString zapros="";
zapros=zapros+"select * from "+name_table;
zapros=zapros+" where "+name_field_id+"='"+value_field_id+"'";
QueryRecord->SQL->Add(zapros);
//glSaveProtocol(" ������ ���������� ������� ������ ��������� ������! ");
QueryRecord->ExecQuery();
//glSaveProtocol(" ������ ��������! ");
if (QueryRecord->RecordCount==0)  //������ �� �������
		{
		//glSaveProtocol("��������� ������ � ���� ������ �� �������! \n");
		//������ ������� ������ � ������� ���������
		//����� ����� ����� ���� ����������� ��������� 
		try
			{
			AddDelRecordInXTism->Close();
			AddDelRecordInXTism->ParamByName("PARAM_NAME_TABLE")->AsString=name_table;
			AddDelRecordInXTism->ParamByName("PARAM_NAME_FIELD_ID")->AsString=name_field_id;
			AddDelRecordInXTism->ParamByName("PARAM_VALUE_FIELD_ID")->AsString=value_field_id;
			AddDelRecordInXTism->ParamByName("PARAM_IDEXT_BASE")->AsString=value_field_idext_base;
			AddDelRecordInXTism->ParamByName("PARAM_IDEXT_DATAOUT")->AsString=value_field_idext_dataout;
		  //	glSaveProtocol(" ��������� ������ ���������� ������ � ������� ���������, ����� ����� ������������ ��������� ");
			AddDelRecordInXTism->ExecQuery();
			TrXTism->Commit();
			AddDelRecordInXTism->Close();
			//glSaveProtocol(" ������ ��������! ");
			}
		catch (Exception &exception)
			{
			glDM->glSaveProtocol("\������ � ������ DMUribIn->DeleteRecord ��� ���������� ������ � XTISM ����� ������ �� �������\n"
			+exception.Message+"  \n"
			+"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
			TrXTism->Rollback();
			}
		}
else
		{
		//glSaveProtocol("��������� ������ � ���� ������ �������! \n");
		UnicodeString zapros=" DELETE FROM "+ name_table+" WHERE "+name_field_id+"='"+value_field_id+"'";
		glDM->glSaveProtocol("������� ������� ������ �� ����! \n"+zapros);
		QueryUpdateRecord->Close();
		QueryUpdateRecord->SQL->Clear();
		QueryUpdateRecord->SQL->Add(zapros);
		try
			{
			//glSaveProtocol("��������� ������ �������� ������! ");
			QueryUpdateRecord->ExecQuery();
			TrUpdateRecord->Commit();
			//glSaveProtocol("������ ��������. ������ �������! ");
			}
		catch (Exception &exception)
			{
			glDM->glSaveProtocol("\n������ � ������ DMUribIn->DeleteRecord ��� �������� ������ \n"
			+exception.Message+"  \n ������:"+zapros
			+"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
			TrUpdateRecord->Rollback();
			}

		try
			{
			//������ � ������� ��������� ������� ������ �������� ����������
			zapros="update xtism set xtism.idext_base_xtism="+value_field_idext_base;
			zapros=zapros+", xtism.idext_dataout_xtism="+value_field_idext_dataout;
			zapros=zapros+"	 where  xtism.name_table_xtism='"+name_table+"'";
			zapros=zapros+"	    and xtism.operation_xtism=3" ;
			zapros=zapros+"	    and xtism.value_field_id_xtism="+value_field_id;
			QueryUpdateRecord->Close();
			QueryUpdateRecord->SQL->Clear();
			QueryUpdateRecord->SQL->Add(zapros);
			//glSaveProtocol("��������� ������. ��������� � ������� ��������� ������ �������� ����������! ");
			QueryUpdateRecord->ExecQuery();
			TrUpdateRecord->Commit();
			//glSaveProtocol("������ ��������! ");
			}
		catch (Exception &exception)
			{
			glDM->glSaveProtocol("\n������ � ������ DMUribIn->DeleteRecord ��� ���������� ����� idext_data_out � xtism \n"
			+exception.Message+"  \n ������:"+zapros
			+"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
			TrUpdateRecord->Rollback();
			}
		QueryUpdateRecord->Close();
		}

//glSaveProtocol(" ++++++++ ����� ��������� �������� ������! ");
}

//---------------------------------------------------------------------------
UnicodeString TDMUribIn::CreateTextZaprosInsert(_di_IXMLNode xml_rec)
{


UnicodeString name_table=Trim(xml_rec->NodeName);

UnicodeString name_field_idext_base="IDEXT_BASE_"+name_table;
UnicodeString value_field_idext_base=xml_rec->GetAttribute("idext_base");

UnicodeString name_field_idext_dataout="IDEXT_DOUT_"+name_table;
UnicodeString value_field_idext_dataout=xml_rec->GetAttribute("idext_data_out");

UnicodeString fields=name_field_idext_base+","+name_field_idext_dataout;
UnicodeString values="'"+value_field_idext_base+"'"+",'"+value_field_idext_dataout+"'";

UnicodeString result="";

for (int i=0;i<xml_rec->ChildNodes->Count;i++)
	{
	_di_IXMLNode xml_field=xml_rec->ChildNodes->Get(i);
	UnicodeString name_field=xml_field->NodeName;
	if (CheckFieldForInsert(name_field)==false) continue; //�������� ����

		fields=fields+", "+name_field;
		values=values+", "+":PARAM_"+name_field;

	}

// ���� �������� idext_base � idext_dataout
result="insert into "+name_table+" ("+fields+")";
result=result+" values ("+values+")";

return result;


}
//---------------------------------------------------------------------------
UnicodeString TDMUribIn::CreateTextZaprosEdit(_di_IXMLNode xml_rec)
{

UnicodeString name_table=Trim(xml_rec->NodeName);

//�������� ������������ ID
UnicodeString name_field_id=xml_rec->GetAttribute("name_pk");
UnicodeString value_field_id=xml_rec->GetAttribute("value_pk");

UnicodeString name_field_idext_base="IDEXT_BASE_"+name_table;
UnicodeString value_field_idext_base=xml_rec->GetAttribute("idext_base");

UnicodeString name_field_idext_dataout="IDEXT_DOUT_"+name_table;
UnicodeString value_field_idext_dataout=xml_rec->GetAttribute("idext_data_out");

UnicodeString result="";
UnicodeString fields=name_field_idext_base+"='"+value_field_idext_base+"'";
fields=fields+","+name_field_idext_dataout+"='"+value_field_idext_dataout+"'";

for (int i=0;i<xml_rec->ChildNodes->Count;i++)
	{
	_di_IXMLNode xml_field=xml_rec->ChildNodes->Get(i);
	UnicodeString name_field=xml_field->NodeName;
	if(CheckFieldForEdit(name_field)==false) continue;   //���� �� ��������� ������ ����


		fields=fields+", "+name_field+"=:PARAM_"+name_field;

	}

result=" update "+name_table+" set "+fields+" where "+
		name_field_id+"='"+value_field_id+"'";

return result;


}
//----------------------------------------------------------------------------
void TDMUribIn::InputKvitan(_di_IXMLNode xml_rec)
{
UnicodeString value_field_idext_dataout=xml_rec->GetAttribute("idext_data_out");

//������� ������� �� ��� ID
QueryRecord->Close();
QueryRecord->SQL->Clear();
UnicodeString zapros="";
zapros=zapros+"select * from XDATA_OUT where ID_XDATA_OUT="+value_field_idext_dataout;
QueryRecord->SQL->Add(zapros);
try
	{
	QueryRecord->ExecQuery();
	}
catch (Exception &exception)
	{
	glDM->glSaveProtocol("������ � ������ DMUribIn->InputKvitan ��� ��������� ������ ��������� \n"
	+exception.Message+"  \n ������:"+zapros
	+"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
	}

if (QueryRecord->RecordCount==1)
	{
	///�������� ����� ������� ���������� ���������
	zapros=" UPDATE XDATA_OUT set RESULT_XDATA_OUT=1 ";
	zapros=zapros+"  where ID_XDATA_OUT="+value_field_idext_dataout;
	QueryUpdateRecord->Close();
	QueryUpdateRecord->SQL->Clear();
	QueryUpdateRecord->SQL->Add(zapros);

	try
		{
		QueryUpdateRecord->ExecQuery();
		TrUpdateRecord->Commit();
		}

	catch (Exception &exception)
		{
		glDM->glSaveProtocol("\n������ � ������ DMUribIn->InputKvitan ��� ���������� ���������� ��������� \n"
		+exception.Message+"  \n ������:"+zapros
		+"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
		TrUpdateRecord->Rollback();
		}
	QueryUpdateRecord->Close();
	}
QueryRecord->Close();
}

//----------------------------------------------------------------------------
bool TDMUribIn::CheckFieldForEdit(UnicodeString name_field)
{
bool result=false;
//if (name_field==Trim(DMXTableBase->ElementNAMEPK_XTABLE_BASE->AsString)) return result;
//if (name_field==Trim(DMXTableBase->ElementNAMEGID_XTABLE_BASE->AsString))return result;
if (name_field=="PRDOC") return result;

result=true;
return result;
}
//----------------------------------------------------------------------------
bool TDMUribIn::CheckFieldForInsert(UnicodeString name_field)
{
bool result=false;
//if (name_field==Trim(DMXTableBase->ElementNAMEPK_XTABLE_BASE->AsString)) return result;
if (name_field=="PRDOC") return result;
//if (name_field=="PRICEZPART") return result;
if (name_field=="IDPARTPERT") return result;  //������ ���� ���
result=true;
return result;
}
//----------------------------------------------------------------------------
bool TDMUribIn::CheckDrob(UnicodeString name_field)
{
bool result=false;


//if(DMXFieldBase->TableSCALE_XFIELD_BASE->AsInteger<0)
//        {
//        result=true;
//        }

return result;


}
//---------------------------------------------------------------------------
void TDMUribIn::OutProtocol(UnicodeString str)
{
if (EnableOutProtocol==true)
        {
       // RichEdit1->Lines->Add(str);

        }
}
//----------------------------------------------------------------------------
void TDMUribIn::RunComandCancelDvRegDoc(_di_IXMLNode xml_rec)
{
//�������� ������������ ID
UnicodeString name_field_id=xml_rec->GetAttribute("name_pk");
UnicodeString value_field_id=xml_rec->GetAttribute("value_pk");
UnicodeString value_field_idext_base=xml_rec->GetAttribute("idext_base");
UnicodeString value_field_idext_dataout=xml_rec->GetAttribute("idext_data_out");

UnicodeString type_doc="";
UnicodeString name_procedure="";

if (name_field_id=="IDDOC")
	{
	type_doc=GetTypeDoc(xml_rec);
	name_procedure=GetNameProcedureCancelDvReg(type_doc);
	}

if (name_field_id=="ID_REM_GALLDOC")
	{
	type_doc=GetTypeDocRemontSystem(xml_rec);
	name_procedure=GetNameProcedureCancelDvRegRemontSystem(type_doc);
	}

if (name_field_id=="ID_HOT_GALLDOC")
	{
	type_doc=GetTypeDocHotelSystem(xml_rec);
	name_procedure=GetNameProcedureCancelDvRegHotelSystem(type_doc);
	}


//� ���� ��� ��������� ��� ������ ����������
if (Trim(name_procedure)=="")
	{
	glDM->glSaveProtocol("������ � ������ DMUribIn->RunComandCancelDvRegDoc ��� ������ ���������� ��������� \n  �� ������ �������� ��� ������ ����������! ��� ���������: "
		+type_doc
		+" name_field_id="+name_field_id+" value_field_id="+value_field_id
		+" value_field_idext_base="+value_field_idext_base+" value_field_idext_dataout="+value_field_idext_dataout
		+"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
	// ���� � ������� ��������� �������� ���������
	//����� �� ������������� �� ��������� ������� ������ ����������
		try
			{
			AddRecordInXTism->Close();
			UnicodeString zapros="EXECUTE PROCEDURE GLPROC_ADD_DVREGDOC_IN_TISM ";
			zapros=zapros+" ("+value_field_id+",0,4";
			zapros=zapros+","+value_field_idext_base;
			zapros=zapros+","+value_field_idext_dataout+")";
			AddRecordInXTism->Close();
			AddRecordInXTism->SQL->Clear();
			AddRecordInXTism->SQL->Add(zapros);
			//glSaveProtocol(" ��������� ������ ���������� ������ � ������� ���������, ����� ����� ������������ ��������� ");
			AddRecordInXTism->ExecQuery();
			TrXTism->Commit();
			AddRecordInXTism->Close();
			//glSaveProtocol(" ������ ��������! ");
			}
		catch (Exception &exception)
			{
			glDM->glSaveProtocol("\n������ � ������ DMUribIn->RunComandCancelDvRegDoc ��� ���������� ������ � XTISM ����� �������� ��� ������ ���������� �� ������\n"
			+exception.Message+"  \n"
			+"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
			TrXTism->Rollback();
			}

	return;
	}

UnicodeString zapros="EXECUTE PROCEDURE ";
zapros=zapros+name_procedure;
zapros=zapros+" ("+value_field_id+",0";
zapros=zapros+","+value_field_idext_base;
zapros=zapros+","+value_field_idext_dataout+")";

QueryUpdateRecord->Close();
QueryUpdateRecord->SQL->Clear();
QueryUpdateRecord->SQL->Add(zapros);
	try
		{
		QueryUpdateRecord->ExecQuery();
		TrUpdateRecord->Commit();
		}

	catch (Exception &exception)
		{
		glDM->glSaveProtocol("������ � ������ DMUribIn->RunComandCancelDvRegDoc ��� ������ ���������� ��������� \n"
		+exception.Message+"  \n ������:"+zapros
		+"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
		TrUpdateRecord->Rollback();
		}

}
//----------------------------------------------------------------------------
void TDMUribIn::RunComandDvRegDoc(_di_IXMLNode xml_rec)
{
//�������� ������������ ID
UnicodeString name_field_id=xml_rec->GetAttribute("name_pk");
UnicodeString value_field_id=xml_rec->GetAttribute("value_pk");
UnicodeString value_field_idext_base=xml_rec->GetAttribute("idext_base");
UnicodeString value_field_idext_dataout=xml_rec->GetAttribute("idext_data_out");

UnicodeString type_doc="";
UnicodeString name_procedure="";

if (name_field_id=="IDDOC")
	{
	type_doc=GetTypeDoc(xml_rec);
	name_procedure=GetNameProcedureDvReg(type_doc);
	}

if (name_field_id=="ID_REM_GALLDOC")
	{
	type_doc=GetTypeDocRemontSystem(xml_rec);
	name_procedure=GetNameProcedureDvRegRemontSystem(type_doc);
	}

if (name_field_id=="ID_HOT_GALLDOC")
	{
	type_doc=GetTypeDocHotelSystem(xml_rec);
	name_procedure=GetNameProcedureDvRegHotelSystem(type_doc);
	}

//� ���� ��� ��������� ���  ����������
if (Trim(name_procedure)=="")
	{
	glDM->glSaveProtocol("������ � ������ DMUribIn->RunComandDvRegDoc ��� ���������� ��������� \n  �� ������ �������� ��� ����������! ��� ���������: "
		+type_doc
		+" name_field_id="+name_field_id+" value_field_id="+value_field_id
		+" value_field_idext_base="+value_field_idext_base+" value_field_idext_dataout="+value_field_idext_dataout
		+"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
	// ���� � ������� ��������� �������� ���������
	//����� �� ������������� �� ��������� ������� ����������
		try
			{
			AddRecordInXTism->Close();
			UnicodeString zapros="EXECUTE PROCEDURE GLPROC_ADD_DVREGDOC_IN_TISM ";
			zapros=zapros+" ("+value_field_id+",0,5";
			zapros=zapros+","+value_field_idext_base;
			zapros=zapros+","+value_field_idext_dataout+")";
			AddRecordInXTism->Close();
			AddRecordInXTism->SQL->Clear();
			AddRecordInXTism->SQL->Add(zapros);
			//glSaveProtocol(" ��������� ������ ���������� ������ � ������� ���������, ����� ����� ������������ ��������� ");
			AddRecordInXTism->ExecQuery();
			TrXTism->Commit();
			AddRecordInXTism->Close();
			//glSaveProtocol(" ������ ��������! ");
			}
		catch (Exception &exception)
			{
			glDM->glSaveProtocol("\n������ � ������ DMUribIn->RunComandCancelDvRegDoc ��� ���������� ������ � XTISM ����� �������� ��� ���������� �� ������\n"
			+exception.Message+"  \n"
			+"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
			TrXTism->Rollback();
			}

	
	return;
	}
	
UnicodeString zapros="EXECUTE PROCEDURE ";
zapros=zapros+name_procedure;
zapros=zapros+" ("+value_field_id+",0";
zapros=zapros+","+value_field_idext_base;
zapros=zapros+","+value_field_idext_dataout+")";

QueryUpdateRecord->Close();
QueryUpdateRecord->SQL->Clear();
QueryUpdateRecord->SQL->Add(zapros);
	try
		{
		QueryUpdateRecord->ExecQuery();
		TrUpdateRecord->Commit();
		}

	catch (Exception &exception)
		{
		glDM->glSaveProtocol("������ � ������ DMUribIn->RunComandDvRegDoc ��� ���������� ��������� \n"
		+exception.Message+"  \n ������:"+zapros
		+"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
		TrUpdateRecord->Rollback();
		}


}
//----------------------------------------------------------------------------
UnicodeString TDMUribIn::GetTypeDoc(_di_IXMLNode xml_rec)
{
UnicodeString result="";
UnicodeString name_field_id=xml_rec->GetAttribute("name_pk");
UnicodeString value_field_id=xml_rec->GetAttribute("value_pk");

UnicodeString zapros="";
if (name_field_id=="IDDOC")
	{
	zapros=" select TDOC AS TYPEDOC from GALLDOC where IDDOC="+value_field_id;
	}

QueryRecord->Close();
if (zapros!="")
	{
	QueryRecord->SQL->Clear();
	QueryRecord->SQL->Add(zapros);
	try
		{
		QueryRecord->ExecQuery();
		}

	catch (Exception &exception)
		{
		glDM->glSaveProtocol("\n������ � ������ DMUribIn->GetTypeDoc ��� ��������� ���� ��������� \n"
		+exception.Message+"  \n ������:"+zapros
		+"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
		}
	}

result=QueryRecord->FieldByName("TYPEDOC")->AsString;
QueryRecord->Close();
return result;
}
//----------------------------------------------------------------------------
UnicodeString TDMUribIn::GetTypeDocRemontSystem(_di_IXMLNode xml_rec)
{
UnicodeString result="";
UnicodeString name_field_id=xml_rec->GetAttribute("name_pk");
UnicodeString value_field_id=xml_rec->GetAttribute("value_pk");

UnicodeString zapros="";
if (name_field_id=="ID_REM_GALLDOC")
	{
	zapros=" select TDOC_REM_GALLDOC AS TYPEDOC from REM_GALLDOC where ID_REM_GALLDOC="+value_field_id;
	}

QueryRecord->Close();
if (zapros!="")
	{
	QueryRecord->SQL->Clear();
	QueryRecord->SQL->Add(zapros);
	try
		{
		QueryRecord->ExecQuery();
		}

	catch (Exception &exception)
		{
		glDM->glSaveProtocol("\n������ � ������ DMUribIn->GetTypeDocRemontSystem ��� ��������� ���� ��������� \n"
		+exception.Message+"  \n ������:"+zapros
		+"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
		}
	}

result=QueryRecord->FieldByName("TYPEDOC")->AsString;
QueryRecord->Close();
return result;
}
//----------------------------------------------------------------------------
UnicodeString TDMUribIn::GetTypeDocHotelSystem(_di_IXMLNode xml_rec)
{
UnicodeString result="";
UnicodeString name_field_id=xml_rec->GetAttribute("name_pk");
UnicodeString value_field_id=xml_rec->GetAttribute("value_pk");

UnicodeString zapros="";
if (name_field_id=="ID_HOT_GALLDOC")
	{
	zapros=" select TDOC_HOT_GALLDOC AS TYPEDOC from HOT_GALLDOC where ID_HOT_GALLDOC="+value_field_id;
	}

QueryRecord->Close();
if (zapros!="")
	{
	QueryRecord->SQL->Clear();
	QueryRecord->SQL->Add(zapros);
	try
		{
		QueryRecord->ExecQuery();
		}

	catch (Exception &exception)
		{
		glDM->glSaveProtocol("\n������ � ������ DMUribIn->GetTypeDocHotelSystem ��� ��������� ���� ��������� \n"
		+exception.Message+"  \n ������:"+zapros
		+"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
		}
	}

result=QueryRecord->FieldByName("TYPEDOC")->AsString;
QueryRecord->Close();
return result;
}
//----------------------------------------------------------------------------
UnicodeString TDMUribIn::GetNameProcedureCancelDvReg(UnicodeString type_doc)
{
UnicodeString result=glGetNameProcedureCancelDvReg(type_doc);

//if (type_doc=="CHK"){result="DOC_CHK_CANCEL_DVREG";}
//if (type_doc=="PRN"){result="DOC_PRN_CANCEL_DVREG";}//{Text="����. ����.";}
//if (type_doc=="SCH"){result="DOC_SCH_CANCEL_DVREG";}//{Text="���� �� ������";}
//if (type_doc=="OSN"){result="DOC_OSN_CANCEL_DVREG";}//{Text="������� �������.";}
//if (type_doc=="PER"){result="DOC_PER_CANCEL_DVREG";}//{Text="�����������";}
//if (type_doc=="REA"){result="DOC_REA_CANCEL_DVREG";}//{Text="����������";}
//if (type_doc=="SPN"){result="DOC_SPN_CANCEL_DVREG";}//{Text="��� ��������";}
//if (type_doc=="VPO"){result="DOC_VPO_CANCEL_DVREG";}//{Text="������� ����������";}
//if (type_doc=="PKO"){result="DOC_PKO_CANCEL_DVREG";}//{Text="����. ����. �����";}
//if (type_doc=="RKO"){result="DOC_RKO_CANCEL_DVREG";}//{Text="����. ����. �����";}
//if (type_doc=="PLP"){result="DOC_PLP_CANCEL_DVREG";}//{Text="��������� ���������";}
//if (type_doc=="PNS"){result="DOC_PNS_CANCEL_DVREG";}//{Text="����������� �� ����";}
//if (type_doc=="INV"){result="DOC_INV_CANCEL_DVREG";}//{Text="��������������";}
//if (type_doc=="REPKKM"){result="DOC_REPKKM_CANCEL_DVREG";}//{Text="����� ���";}
//if (type_doc=="OSTVS"){result="DOC_OSTVS_CANCEL_DVREG";}//{Text="����. ��������������";}
//if (type_doc=="SCHFACT"){result="DOC_SCHFACT_CANCEL_DVREG";}//{Text="����-�������";}
//if (type_doc=="REALROZN"){result="DOC_REALROZN_CANCEL_DVREG";}//{Text="���������� ����.";}
//if (type_doc=="PKOROZN"){result="DOC_PKOROZN_CANCEL_DVREG";}//{Text="������ ���.";}
//if (type_doc=="RKOROZN"){result="DOC_RKOROZN_CANCEL_DVREG";}//{Text="������ ���.";}
//if (type_doc=="VPOK"){result="DOC_VPOK_CANCEL_DVREG";}//{Text="������� ����������";}
//if (type_doc=="ISMPRICE"){result="DOC_ISMPRICE_CANCEL_DVREG";}//{Text="����������";}
//if (type_doc=="SPOTROST"){result="DOC_SPOTROST_CANCEL_DVREG";}//{Text="�������� ���. ��������";}
//if (type_doc=="REV"){result="DOC_REV_CANCEL_DVREG";}//{Text="�������";}
//
//if (type_doc=="SBKOMPL"){result="DOC_SBKOMPL_CANCEL_DVREG";}//
//if (type_doc=="RASBKOMPL"){result="DOC_RASBKOMPL_CANCEL_DVREG";}//
//if (type_doc=="ZAMENA"){result="DOC_ZAMENA_CANCEL_DVREG";}//
//
//if (type_doc=="KORRVS"){result="DOC_KORRVS_CANCEL_DVREG";}
//if (type_doc=="VIPBANK"){result="DOC_VIPBANK_CANCEL_DVREG";}
//
////��������� ���������
//if (type_doc=="RG_ADVCUST"){result="DOC_RGADVCUST_CANCEL_DVREG";}
//if (type_doc=="RG_BANK"){result="DOC_RGBANK_CANCEL_DVREG";}
//if (type_doc=="RG_CARDBAL"){result="DOC_RGCARD_BALANCE_CANCEL_DVREG";}
//if (type_doc=="RG_OSTNOM"){result="DOC_RGGOODS_CANCEL_DVREG";}
//if (type_doc=="RG_KASSA"){result="DOC_RGKASSA_CANCEL_DVREG";}
//if (type_doc=="RG_OSTNOM"){result="DOC_RGOSTNOM_CANCEL_DVREG";}
//if (type_doc=="RG_PAYSALE"){result="DOC_RGPAYSALE_CANCEL_DVREG";}
//if (type_doc=="RG_VSRASCH"){result="DOC_RGVSRASCH_CANCEL_DVREG";}



return result;
}
//-----------------------------------------------------------------------------
UnicodeString TDMUribIn::GetNameProcedureCancelDvRegRemontSystem(UnicodeString type_doc)
{
UnicodeString result=glGetNameProcedureCancelDvRegRemontSystem(type_doc);

//if (type_doc=="KM1"){result="REM_DOC_KM1_CANCEL_DVREG";}
//if (type_doc=="KM2"){result="REM_DOC_KM2_CANCEL_DVREG";}
//if (type_doc=="REMONTHW"){result="REM_DOC_REMONTHW_CANCEL_DVREG";}
//if (type_doc=="REMONTKKT"){result="REM_DOC_REMONTKKT_CANCEL_DVREG";}
//if (type_doc=="REMONT"){result="REM_DOC_REMONT_CANCEL_DVREG";}
//if (type_doc=="SETSERVHW"){result="REM_DOC_SETSERVHW_CANCEL_DVREG";}
//if (type_doc=="SETSERVKKT"){result="REM_DOC_SETSERVKKT_CANCEL_DVREG";}
//
//
//if (type_doc=="REMPRN"){result="REM_DOC_PRN_CANCEL_DVREG";}
//if (type_doc=="REMREAL"){result="REM_DOC_REAL_CANCEL_DVREG";}
//if (type_doc=="REMOSN"){result="REM_DOC_OSN_CANCEL_DVREG";}
//if (type_doc=="REMSBKOMPL"){result="REM_DOC_SBKOMPL_CANCEL_DVREG";}
//if (type_doc=="POSTOTDIL"){result="REM_DOC_DILPOST_CANCEL_DVREG";}
//if (type_doc=="VOSDILERU"){result="REM_DOC_DILRET_CANCEL_DVREG";}
//if (type_doc=="PERSC"){result="REM_DOC_SCPER_CANCEL_DVREG";}
//if (type_doc=="VOSVISSC"){result="REM_DOC_SCRET_CANCEL_DVREG";}
//if (type_doc=="REMVPOK"){result="REM_DOC_VPOK_CANCEL_DVREG";}

return result;
}
//-----------------------------------------------------------------------------
UnicodeString TDMUribIn::GetNameProcedureCancelDvRegHotelSystem(UnicodeString type_doc)
{
UnicodeString result=glGetNameProcedureCancelDvRegHotelSystem(type_doc);

//if (type_doc=="BRON"){result="HOT_DOC_BRON_CANCEL_DVREG";}
//if (type_doc=="OTMBRON"){result="HOT_DOC_OTMBRON_CANCEL_DVREG";}
//if (type_doc=="RASCHET"){result="HOT_DOC_RASCHET_CANCEL_DVREG";}
//if (type_doc=="RASM"){result="HOT_DOC_RASM_CANCEL_DVREG";}
//if (type_doc=="REAL"){result="HOT_DOC_REAL_CANCEL_DVREG";}
//if (type_doc=="VIEZD"){result="HOT_DOC_VIESD_CANCEL_DVREG";}


return result;
}
//-----------------------------------------------------------------------------
UnicodeString TDMUribIn::GetNameProcedureDvReg(UnicodeString type_doc)
{
UnicodeString result=glGetNameProcedureDvReg(type_doc);

//if (type_doc=="CHK"){result="DOC_CHK_DVREG";}
//if (type_doc=="PRN"){result="DOC_PRN_DVREG";}//{Text="����. ����.";}
//if (type_doc=="SCH"){result="DOC_SCH_DVREG";}//{Text="���� �� ������";}
//if (type_doc=="OSN"){result="DOC_OSN_DVREG";}//{Text="������� �������.";}
//if (type_doc=="PER"){result="DOC_PER_DVREG";}//{Text="�����������";}
//if (type_doc=="REA"){result="DOC_REA_DVREG";}//{Text="����������";}
//if (type_doc=="SPN"){result="DOC_SPN_DVREG";}//{Text="��� ��������";}
//if (type_doc=="VPO"){result="DOC_VPO_DVREG";}//{Text="������� ����������";}
//if (type_doc=="PKO"){result="DOC_PKO_DVREG";}//{Text="����. ����. �����";}
//if (type_doc=="RKO"){result="DOC_RKO_DVREG";}//{Text="����. ����. �����";}
//if (type_doc=="PLP"){result="DOC_PLP_DVREG";}//{Text="��������� ���������";}
//if (type_doc=="PNS"){result="DOC_PNS_DVREG";}//{Text="����������� �� ����";}
//if (type_doc=="INV"){result="DOC_INV_DVREG";}//{Text="��������������";}
//if (type_doc=="REPKKM"){result="DOC_REPKKM_DVREG";}//{Text="����� ���";}
//if (type_doc=="OSTVS"){result="DOC_OSTVS_DVREG";}//{Text="����. ��������������";}
//if (type_doc=="SCHFACT"){result="DOC_SCHFACT_DVREG";}//{Text="����-�������";}
//if (type_doc=="REALROZN"){result="DOC_REALROZN_DVREG";}//{Text="���������� ����.";}
//if (type_doc=="PKOROZN"){result="DOC_PKOROZN_DVREG";}//{Text="������ ���.";}
//if (type_doc=="RKOROZN"){result="DOC_RKOROZN_DVREG";}//{Text="������ ���.";}
//if (type_doc=="VPOK"){result="DOC_VPOK_DVREG";}//{Text="������� ����������";}
//if (type_doc=="ISMPRICE"){result="DOC_ISMPRICE_DVREG";}//{Text="����������";}
//if (type_doc=="SPOTROST"){result="DOC_SPOTROST_DVREG";}//{Text="�������� ���. ��������";}
//if (type_doc=="REV"){result="DOC_REV_DVREG";}//{Text="�������";}
//
//if (type_doc=="SBKOMPL"){result="DOC_SBKOMPL_DVREG";}//{Text="����������";}
//if (type_doc=="RASBKOMPL"){result="DOC_RASBKOMPL_DVREG";}//{Text="�������� ���. ��������";}
//if (type_doc=="ZAMENA"){result="DOC_ZAMENA_DVREG";}//{Text="�������";}
//
//if (type_doc=="KORRVS"){result="DOC_KORRVS_DVREG";}
//if (type_doc=="VIPBANK"){result="DOC_VIPBANK_DVREG";}
//
////��������� ���������
//if (type_doc=="RG_ADVCUST"){result="DOC_RGADVCUST_DVREG";}
//if (type_doc=="RG_BANK"){result="DOC_RGBANK_DVREG";}
//if (type_doc=="RG_CARDBAL"){result="DOC_RGCARD_BALANCE_DVREG";}
//if (type_doc=="RG_OSTNOM"){result="DOC_RGGOODS_DVREG";}
//if (type_doc=="RG_KASSA"){result="DOC_RGKASSA_DVREG";}
//if (type_doc=="RG_OSTNOM"){result="DOC_RGOSTNOM_DVREG";}
//if (type_doc=="RG_PAYSALE"){result="DOC_RGPAYSALE_DVREG";}
//if (type_doc=="RG_VSRASCH"){result="DOC_RGVSRASCH_DVREG";}

return result;
}
//-----------------------------------------------------------------------------
UnicodeString TDMUribIn::GetNameProcedureDvRegRemontSystem(UnicodeString type_doc)
{
UnicodeString result=glGetNameProcedureDvRegRemontSystem(type_doc);

//if (type_doc=="REMONT"){result="REM_DOC_REMONT_DVREG";}
//if (type_doc=="REMONTHW"){result="REM_DOC_REMONTHW_DVREG";}
//if (type_doc=="REMONTKKT"){result="REM_DOC_REMONTKKT_DVREG";}
//if (type_doc=="KM1"){result="REM_DOC_KM1_DVREG";}
//if (type_doc=="KM2"){result="REM_DOC_KM2_DVREG";}
//if (type_doc=="SETSERVKKT"){result="REM_DOC_SETSERVKKT_DVREG";}
//if (type_doc=="SETSERVHW"){result="REM_DOC_SETSERVHW_DVREG";}
//
//if (type_doc=="REMPRN"){result="REM_DOC_PRN_DVREG";}
//if (type_doc=="REMREAL"){result="REM_DOC_REAL_DVREG";}
//if (type_doc=="REMOSN"){result="REM_DOC_OSN_DVREG";}
//if (type_doc=="REMSBKOMPL"){result="REM_DOC_SBKOMPL_DVREG";}
//if (type_doc=="POSTOTDIL"){result="REM_DOC_DILPOST_DVREG";}
//if (type_doc=="VOSDILERU"){result="REM_DOC_DILRET_DVREG";}
//if (type_doc=="PERSC"){result="REM_DOC_SCPER_DVREG";}
//if (type_doc=="VOSVISSC"){result="REM_DOC_SCRET_DVREG";}
//if (type_doc=="REMVPOK"){result="REM_DOC_VPOK_DVREG";}
return result;
}
//-----------------------------------------------------------------------------
UnicodeString TDMUribIn::GetNameProcedureDvRegHotelSystem(UnicodeString type_doc)
{
UnicodeString result=glGetNameProcedureDvRegHotelSystem(type_doc);

//if (type_doc=="BRON"){result="HOT_DOC_BRON_DVREG";}
//if (type_doc=="OTMBRON"){result="HOT_DOC_OTMBRON_DVREG";}
//if (type_doc=="RASCHET"){result="HOT_DOC_RASCHET_DVREG";}
//if (type_doc=="RASM"){result="HOT_DOC_RASM_DVREG";}
//if (type_doc=="REAL"){result="HOT_DOC_REAL_DVREG";}
//if (type_doc=="VIEZD"){result="HOT_DOC_VIESD_DVREG";}


return result;
}
//-----------------------------------------------------------------------------
