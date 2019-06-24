//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UDMUribIn.h"
#include "UDMXMessageObmen.h"
#include "UDMSprInfBase.h"
#include "UDMSetup.h"
#include <fstream.h>
#include "UDM.h"
//#include "iomanip.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FIBDatabase"
#pragma link "FIBQuery"
#pragma link "pFIBDatabase"
#pragma link "pFIBQuery"
#pragma link "FIBDataSet"
#pragma link "pFIBDataSet"
#pragma resource "*.dfm"
extern String gl_prefiks_ib;
extern void glSaveProtocol(String str);
//---------------------------------------------------------------------------
__fastcall TDMUribIn::TDMUribIn(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDMUribIn::DataModuleCreate(TObject *Sender)
{
lpKolRecord=new int;
TableDoc->Active=true;

}
//---------------------------------------------------------------------------
void __fastcall TDMUribIn::DataModuleDestroy(TObject *Sender)
{
delete lpKolRecord;
TableDoc->Active=false;
}
//---------------------------------------------------------------------------
//----------------------------------------------------------------------------------
String TDMUribIn::CommaToPixel(String value)
{
String result="";
String StrValue=value;

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
double TDMUribIn::StringToFloatComma(String value)
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
void TDMUribIn::UpdateDataInfBase(AnsiString full_name_file_xml)
{

                //�� �������� ����� ������� GID ��������� �  ������� ���� ���������
                String name_file=ExtractFileName(full_name_file_xml);
                String prefiks_priemnik=name_file;
                prefiks_priemnik=Trim(prefiks_priemnik.SetLength(2));
                AnsiString prefiks_istochnik=name_file.SubString(4,2);
                String gid_message=name_file;
                gid_message=Trim(name_file.Delete(1,3));
                int kol=gid_message.Length();
                gid_message=Trim(gid_message.SetLength(kol-4));

                if(prefiks_priemnik!=gl_prefiks_ib)
                        {
                        glSaveProtocol("��������! ��������� ���� �� ������������ ��� �������� � ������� �������������� ����!");

                        }

//***************************
TDMSprInfBase * DMSprInfBase=new TDMSprInfBase(Application);
DMSprInfBase->OpenTable();
DMSprInfBase->Table->First();
while(!DMSprInfBase->Table->Eof)
        {
        if (prefiks_istochnik==Trim(DMSprInfBase->TablePREFIKS_SINFBASE_OBMEN->AsString))
                {
                IdBase=DMSprInfBase->TableID_SINFBASE_OBMEN->AsInteger;
                break;
                }
        DMSprInfBase->Table->Next();
        }

delete DMSprInfBase;


//*******************************
                TDMXMessageObmen *DMMessage=new TDMXMessageObmen(Application);
                IdMessage=DMMessage->GetIDElement(gid_message);
                //�������� ��� �� ��� ������ ���������
                if(IdMessage==0)
                        {
                        DMMessage->NewElement(IdBase);
                        DMMessage->ElementGID_XMESSAGE_OBMEN->AsString=gid_message;
                        DMMessage->ElementOUT_XMESSAGE_OBMEN->AsInteger=2;
                        DMMessage->SaveElement();
                        }
                else
                        {
                        glSaveProtocol("��������! ������ ��������� ���� ��������� �����!");
                        DMMessage->OpenElement(IdMessage);
                        }

                IdMessage=DMMessage->ElementID_XMESSAGE_OBMEN->AsInteger;
                GIDMessage=DMMessage->ElementGID_XMESSAGE_OBMEN->AsString;





DMXTableBase=new TDMXTableBase(Application);
DMXFieldBase=new TDMXFieldBase(Application);

const char *fileName=full_name_file_xml.c_str();
ifstream infile(fileName);

if (!infile) {OutProtocol("�� ������� ������� xml ����!");}
char s[1000];


AnsiString str_1="";
AnsiString str_2="";
AnsiString str_end="</data>";

if (!infile.eof())
        {
        infile.getline(s,1000);
        str_1=s;
        }

if (!infile.eof())
        {
        infile.getline(s,1000);
        str_2=s;
        }
        
kol_rec=0;
if(EventFirstRecord) EventFirstRecord(this);

while(!infile.eof())
        {
        infile.getline(s,1000);
        AnsiString text_xml=s;
        if (Trim(text_xml)==str_end)  {break;}
        //������� ����������� �������
        AnsiString end_element=Trim(text_xml);
        end_element=Trim(end_element.SetLength(end_element.AnsiPos(" ")));
        end_element=Trim(end_element.Delete(1,1));
        end_element="</"+end_element+">";

        bool end=false;
        while((!infile.eof()) && end==false)
                {
                infile.getline(s,1000);
                AnsiString tec_str=Trim(AnsiString(s));
                if (tec_str==end_element)
                        {
                        end=true;

                        }
                text_xml=text_xml+" "+tec_str;
                } 

        text_xml=str_1+" "+str_2+" "+text_xml+" "+str_end; 

        UpdateInfBase(text_xml);
        //kol_rec++;

		text_xml="";
		if(EventFirstRecord) EventNextRecord(this);
        }


infile.close();

//OutProtocol("���������� ���������: "+ IntToStr(xml_base->ChildNodes->Count));
//glSaveProtocol("���������� ���������: "+ IntToStr(xml_base->ChildNodes->Count));


//--------------


//---------------

delete DMXTableBase;
delete DMXFieldBase;
delete DMMessage;
glSaveProtocol("��������� ���������: "+IntToStr(kol_rec));



}
//-----------------------------------------------------------------------------
void TDMUribIn::UpdateInfBase(AnsiString text_xml)
{

//ShowMessage(text_xml);

xml->LoadFromXML(text_xml);

_di_IXMLNode  xml_base=xml->DocumentElement;

  for (int i=0; i<xml_base->ChildNodes->Count; i++)    //1 ������� ����� ����������
        {


        _di_IXMLNode xml_rec=xml_base->ChildNodes->Get(i);
        NumberRecord=xml_rec->GetAttribute("num");
		//if (NumberRecord<37000) continue;
        int operation=(int)StrToFloat(xml_rec->GetAttribute("oper"));
		//glSaveProtocol("��������� ������:" +IntToStr(NumberRecord));
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
                default :
                        {

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
String name_table=Trim(xml_rec->NodeName);
DMXTableBase->GetElementPoName(name_table);
DMXFieldBase->OpenTable(DMXTableBase->ElementID_XTABLE_BASE->AsInteger);

//�������� ������������ GID
String name_field_gid=Trim(DMXTableBase->ElementNAMEGID_XTABLE_BASE->AsString);
String value_field_gid=xml_rec->GetAttribute("value_gid");

OutProtocol("table_name "+ name_table);
OutProtocol("name_field_gid "+ name_field_gid);
OutProtocol("value_gid "+ value_field_gid);

//������� ������� �� ��� GID
IBQ2->Close();
IBQ2->SQL->Clear();
String zapros="";
zapros=zapros+"select * from "+name_table;
zapros=zapros+" where "+name_field_gid+"='"+value_field_gid+"'";
IBQ2->SQL->Add(zapros);
        try
                {
				IBQ2->ExecQuery();
                }
        catch (Exception &exception)
                {
                glSaveProtocol("������ � ������ DMUribIn->InsertRecord ��� ��������� �������� �� GID \n"
                +exception.Message+"  \n ������:"+zapros
                +"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
                }



if (IBQ2->RecordCount==0)  //������ �� �������
        {
        OutProtocol("�� ������� ***********************************");
        //���� �������� ������
        ///�������� ����� ������� �������
		String zapros=CreateTextZaprosInsert(xml_rec);
		IBQ1->Close();
        IBQ1->SQL->Clear();
        IBQ1->SQL->Add(zapros);
        try
                {
                IBQ1->ExecQuery();
				IBTr->Commit();
                }

        catch (Exception &exception)
                {
                glSaveProtocol("������ � ������ DMUribIn->InsertRecord ��� ������� ������ \n"
                +exception.Message+"  \n ������:"+zapros
                +"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
                IBTr->Rollback();
                }


		IBQ1->Close();
		//ProveritPosledProvDoc(xml_rec);
        }
else
        {
        OutProtocol(" �������");
        //���� �������� ������ ������� ��������� ���� �� ���������!!!!!!!!
		String zapros=CreateTextZaprosEdit(xml_rec, name_field_gid, value_field_gid);
		if (zapros!="")
				{
				IBQ1->Close();
				IBQ1->SQL->Clear();
				IBQ1->SQL->Add(zapros);

				try
                        {
						IBQ1->ExecQuery();
						IBTr->Commit();
                        }

                catch (Exception &exception)
                        {
                        glSaveProtocol("������ � ������ DMUribIn->InsertRecord ��� ���������� ������ \n"
                        +exception.Message+"  \n ������:"+zapros
                        +"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
                        IBTr->Rollback();
                        }

                IBQ1->Close();
				//ProveritPosledProvDoc(xml_rec);
                }
        }
//IBQ2->Active=false;
ProveritPosledProvDoc(xml_rec);
}
//-----------------------------------------------------------------------------
void TDMUribIn::EditRecord(_di_IXMLNode xml_rec)
{
String name_table=Trim(xml_rec->NodeName);
DMXTableBase->GetElementPoName(name_table);
DMXFieldBase->OpenTable(DMXTableBase->ElementID_XTABLE_BASE->AsInteger);

//�������� ������������ GID
String name_field_gid=Trim(DMXTableBase->ElementNAMEGID_XTABLE_BASE->AsString);
String value_field_gid=xml_rec->GetAttribute("value_gid");

OutProtocol("table_name "+ name_table);
OutProtocol("name_field_gid "+ name_field_gid);
OutProtocol("value_gid "+ value_field_gid);

//������� ������� �� ��� GID
IBQ2->Close();
IBQ2->SQL->Clear();
String zapros="";
zapros=zapros+"select * from "+name_table;
zapros=zapros+" where "+name_field_gid+"='"+value_field_gid+"'";
IBQ2->SQL->Add(zapros);
IBQ2->ExecQuery();


if (IBQ2->RecordCount==0)  //������ �� �������
        {
        OutProtocol("�� ������� ***********************************");
        //���� �������� ������
        ///�������� ����� ������� �������
        String zapros=CreateTextZaprosInsert(xml_rec);
		IBQ1->Close();
        IBQ1->SQL->Clear();
        IBQ1->SQL->Add(zapros);

                try
                        {
						IBQ1->ExecQuery();
                        IBTr->Commit();
                        }

                catch (Exception &exception)
                        {
                        glSaveProtocol("������ � ������ DMUribIn->EditRecord ��� ������� ������ \n"
                        +exception.Message+"  \n ������:"+zapros
                        +"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
                        IBTr->Rollback();
                        }

		IBQ1->Close();
		//ProveritPosledProvDoc(xml_rec);
        }
else
        {
        OutProtocol(" �������");

        //���� �������� ������ ������� ��������� ���� �� ���������!!!!!!!!
        String zapros=CreateTextZaprosEdit(xml_rec, name_field_gid, value_field_gid);
        if (zapros!="")
                {
				IBQ1->Close();
                IBQ1->SQL->Clear();
                IBQ1->SQL->Add(zapros);
                try
                        {
                        IBQ1->ExecQuery();
                        IBTr->Commit();
                        }

                catch (Exception &exception)
                        {
                        glSaveProtocol("������ � ������ DMUribIn->EditRecord ��� �������������� ������ \n"
                        +exception.Message+"  \n ������:"+zapros
                        +"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
                        IBTr->Rollback();
                        }


				IBQ1->Close();
				//ProveritPosledProvDoc(xml_rec);
                }
		}
//IBQ2->Active=false;
ProveritPosledProvDoc(xml_rec);
}
//---------------------------------------------------------------------------
void TDMUribIn::DeleteRecord(_di_IXMLNode xml_rec)
{
glSaveProtocol("��������� ��������� �������� ������! \n ����� ������:"
			+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));

String name_table=Trim(xml_rec->NodeName);
DMXTableBase->GetElementPoName(name_table);
DMXFieldBase->OpenTable(DMXTableBase->ElementID_XTABLE_BASE->AsInteger); 

//�������� ������������ GID
String name_field_gid=Trim(DMXTableBase->ElementNAMEGID_XTABLE_BASE->AsString);
String value_field_gid=xml_rec->GetAttribute("value_gid");

OutProtocol("table_name "+ name_table);
OutProtocol("name_field_gid "+ name_field_gid);
OutProtocol("value_gid "+ value_field_gid);

//������� ������� �� ��� GID
IBQ2->Close();
IBQ2->SQL->Clear();
String zapros="";
zapros=zapros+"select * from "+name_table;
zapros=zapros+" where "+name_field_gid+"='"+value_field_gid+"'";
IBQ2->SQL->Add(zapros);
IBQ2->ExecQuery();


if (IBQ2->RecordCount==0)  //������ �� �������
		{
		glSaveProtocol("��������� ������ � ���� ������ �� �������! \n");
		}
else
		{
		glSaveProtocol("��������� ������ � ���� ������ �������! \n");

		AnsiString zapros=" DELETE FROM "+ name_table+" WHERE "+name_field_gid+"='"+value_field_gid+"'";
		
		glSaveProtocol("������� ������� ������ �� ����! \n"+zapros);

        if (zapros!="")
				{
				IBQ1->Close();
				IBQ1->SQL->Clear();
				IBQ1->SQL->Add(zapros);
				try
						{
						IBQ1->ExecQuery();
						IBTr->Commit();
						glSaveProtocol("������ �������! ");
						}

				catch (Exception &exception)
						{
						glSaveProtocol("������ � ������ DMUribIn->DeleteRecord ��� �������� ������ \n"
						+exception.Message+"  \n ������:"+zapros
						+"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
						IBTr->Rollback();
						}


				IBQ1->Close();
				//ProveritPosledProvDoc(xml_rec);
				}
		}
//IBQ2->Active=false;
//ProveritPosledProvDoc(xml_rec);

}

//-----------------------------------------------------------------------------
String TDMUribIn::GetIDFK(String name_field, String value_gid, _di_IXMLNode xml_field)
{
//�������� ��������� �������� ID ���� �������� ����� �� ������� �������


String result="";
        String name_table_fk=Trim(DMXFieldBase->TableTABLEFK_XFIELD_BASE->AsString);  //������� �� ������� ��������� ����
        String name_field_fk=Trim(DMXFieldBase->TableFIELDFK_XFIELD_BASE->AsString);    //��� ���� �� ������� ��������� ����
        String name_field_gid_fk=Trim(DMXFieldBase->TableGIDFK_XFIELD_BASE->AsString);   //��� ���� ������� �������� GID ��

                //������� �������� ID

                String name_field_id=name_field_fk;

				IBQ3->Close();
                IBQ3->SQL->Clear();
                String zapros="";
                zapros=zapros+"select "+name_field_id;
                zapros=zapros+" from "+name_table_fk;
                zapros=zapros+" where "+name_field_gid_fk+"='"+value_gid+"'";
                IBQ3->SQL->Add(zapros);


                try
                        {
						IBQ3->ExecQuery();
                        }

                catch (Exception &exception)
                        {
                        glSaveProtocol("������ � ������ DMUribIn->GetIDFK ��� ��������� ID �������� ����� \n"
                        +exception.Message+"  \n ������:"+zapros
                        +"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
                        }




                if (IBQ3->RecordCount==1)
                        {
                        result=Trim(IBQ3->FieldByName(name_field_id)->AsString);
                        }

                OutProtocol("id "+ result);
                //-------------------------------------------------------------------------

return result;

}

//---------------------------------------------------------------------------
String TDMUribIn::CreateTextZaprosInsert(_di_IXMLNode xml_rec)
{
String result="";
String fields="";
String values="";
String name_table=Trim(xml_rec->NodeName);
		bool comma=false;
		for (int i=0;i<xml_rec->ChildNodes->Count;i++)
				{
				_di_IXMLNode xml_field=xml_rec->ChildNodes->Get(i);
                String name_field=xml_field->NodeName;
				if (CheckFieldForInsert(name_field)==false) continue; //�������� ����

                DMXFieldBase->FindNameField(name_field);
                String value_field="";
                //String xml_fk=xml_field->GetAttribute("fk");
                bool fk=false;
                if (DMXFieldBase->TableFK_XFIELD_BASE->AsInteger==1){fk=true;}



                if (fk==true)
                        { //����� �� Gid �������� ID
                        String value_gid=xml_field->GetAttribute("gid_fk");
                        if (value_gid!="" && value_gid!=0)
                                {
                                value_field=GetIDFK(name_field,value_gid, xml_field);
                                }
                        }
                else
                        {
                        value_field=xml_field->GetAttribute("v");
                        //���� ����� � ������� ����������
                        //�������� �� ����� � ������
                        if(CheckDrob(name_field)==true)
                                {
                                value_field=CommaToPixel(value_field);
                                }
                        }

						if(value_field!="")
								{
//								//�������� �������� ��� ���
//								if (Trim(DMXTableBase->ElementNAMEIDDOC_XTABLE_BASE->AsString)!="")
//									{ //��� ��������
//									if( Trim(DMXTableBase->ElementNAMEIDDOC_XTABLE_BASE->AsString)==name_field)
//										{ //�������� ���� ��� IDDOC
//
//										}
//									}
//								if(name_field=="IDDOC")  //����� ���, ������ ����� �������
//									{//�������� ���� ��� �������� IDDOC
//
//									}


                                if (comma==false)
                                        {
										fields=name_field;
                                        values="'"+value_field+"'";
                                        comma=true;
                                        }
                                else
                                        {
                                        fields=fields+", "+name_field;
                                        values=values+", "+"'"+value_field+"'";
                                        }
                                 }
                }
result=result+"insert into "+name_table+" ("+fields+")";
result=result+" values ("+values+")";


OutProtocol("****************������ ���������� ************************");
OutProtocol("");
OutProtocol(result);
OutProtocol("");
OutProtocol("****************������ ���������� ************************");
return result;


}
//---------------------------------------------------------------------------
String TDMUribIn::CreateTextZaprosEdit(_di_IXMLNode xml_rec, String name_field_gid, String value_field_gid)
{
String result="";
String fields="";
String name_table=Trim(xml_rec->NodeName);
bool comma=false;
bool run_query=false;


        for (int i=0;i<xml_rec->ChildNodes->Count;i++)
                {
                _di_IXMLNode xml_field=xml_rec->ChildNodes->Get(i);
                String name_field=xml_field->NodeName;
                if(CheckFieldForEdit(name_field)==false) continue;   //���� �� ��������� ������ ����

                if(DMXFieldBase->FindNameField(name_field)==false)
                        {
                        //ShowMessage("�� ������� ����: '"+name_field+"' !");
                        }
                
                String value_field="";
                bool fk=false;
                if (DMXFieldBase->TableFK_XFIELD_BASE->AsInteger==1){fk=true;}



                if (fk==true)
                        { //����� �� Gid �������� ID
                        String value_gid=xml_field->GetAttribute("gid_fk");
                        OutProtocol("������� ���� value_gid"+value_gid );
                        if (value_gid!="" && value_gid!=0)
                                {
                                value_field=GetIDFK(name_field,value_gid, xml_field);
                                }



                        }
                else
                        {
                        value_field=xml_field->GetAttribute("v");
                        }




                        if (Trim(value_field)!=Trim(IBQ2->FieldByName(name_field)->AsString))
                                {

                                run_query=true;
                                OutProtocol("++++++++++ ��������� ������:"+name_field +", �������� � ����� '"+value_field +"'");
                                OutProtocol(" � ����:  '"+Trim(IBQ2->FieldByName(name_field)->AsString)+"'");
                                }
                                
                        ///���� ����� � �������
                        //�� �������� ������� �� �����
                        if(CheckDrob(name_field)==true)
                                {
                                value_field=CommaToPixel(value_field);
                                }

                        if(value_field!="")
                                {
                                if (comma==false)
                                        {
                                        fields=name_field+"='"+value_field+"'";
                                        comma=true;
                                        }
                                else
                                        {
                                        fields=fields+", "+name_field+"='"+value_field+"'";
                                        }
                                 }

                  OutProtocol("***��� ����"+name_field +": ��������"+value_field);
                  OutProtocol("�� ������� "+Trim(IBQ2->FieldByName(name_field)->AsString));

                }

//if (Trim(value_field_gid)=="AA10480")
//        {
//        ShowMessage("");
//        }

if (Trim(fields)=="")    //��� ���� ����� �������� ������
        {                //�������� ������� ����������� ��� �� ������ �� ���� ����
        run_query=false;
        }

result=result+" update "+name_table+" set "+fields+" where "+
        name_field_gid+"='"+value_field_gid+"'";

if (run_query==false)result="";

OutProtocol("****************������ ���������� ************************");
OutProtocol("");
OutProtocol(result);
OutProtocol("");
OutProtocol("****************������ ���������� ************************");

return result;


}
//----------------------------------------------------------------------------
bool TDMUribIn::CheckFieldForEdit(String name_field)
{
bool result=false;
if (name_field==Trim(DMXTableBase->ElementNAMEPK_XTABLE_BASE->AsString)) return result;
if (name_field==Trim(DMXTableBase->ElementNAMEGID_XTABLE_BASE->AsString))return result;
if (name_field=="PRDOC") return result;

result=true;
return result;
}
//----------------------------------------------------------------------------
bool TDMUribIn::CheckFieldForInsert(String name_field)
{
bool result=false;
if (name_field==Trim(DMXTableBase->ElementNAMEPK_XTABLE_BASE->AsString)) return result;
if (name_field=="PRDOC") return result;
if (name_field=="PRICEZPART") return result;
if (name_field=="IDPARTPERT") return result;
result=true;
return result;
}
//----------------------------------------------------------------------------
bool TDMUribIn::CheckDrob(String name_field)
{
bool result=false;


if(DMXFieldBase->TableSCALE_XFIELD_BASE->AsInteger<0)
        {
        result=true;
        }

return result;


}
//---------------------------------------------------------------------------
void TDMUribIn::OutProtocol(String str)
{
if (EnableOutProtocol==true)
        {
       // RichEdit1->Lines->Add(str);

        }
}
//----------------------------------------------------------------------------
void TDMUribIn::ProveritPosledProvDoc(_di_IXMLNode xml_rec)
{
String name_table=Trim(xml_rec->NodeName);
int id_doc;
AnsiString type_doc;
TDateTime pos_doc;
if (name_table=="GALLDOC")
		{
		id_doc=IBQ2->FieldByName("IDDOC")->AsInteger;
		pos_doc=IBQ2->FieldByName("POSDOC")->AsDateTime;
		type_doc=IBQ2->FieldByName("TDOC")->AsString;
		}
else
		{
//		for (int i=0;i<xml_rec->ChildNodes->Count;i++)
//				{
//				_di_IXMLNode xml_field=xml_rec->ChildNodes->Get(i);
//
//
//				}   


        AnsiString name_field_iddoc=Trim(DMXTableBase->ElementNAMEIDDOC_XTABLE_BASE->AsString );
        if (name_field_iddoc=="")
                {
                return;
                }
        else
				{
				id_doc=IBQ2->FieldByName(name_field_iddoc)->AsInteger;
				IBQ4->Close();
                IBQ4->SQL->Clear();
				IBQ4->SQL->Add("SELECT POSDOC, TDOC FROM GALLDOC WHERE  IDDOC="+IntToStr(id_doc));

                try
                        {
						IBQ4->ExecQuery();
                        }

                catch (Exception &exception)
                        {
						glSaveProtocol("������ � ������ DMUribIn->ProveritPosledProvDoc ��� ��������� ������� ��������� \n"
                        +exception.Message+"  \n "
                        +"\n"+"����� ������:"+IntToStr(kol_rec)+" num="+IntToStr(NumberRecord));
						}

				pos_doc=IBQ4->FieldByName("POSDOC")->AsDateTime;
				type_doc=IBQ4->FieldByName("TDOC")->AsString;
                }
        }


if (id_doc==0) return;
TDMSetup * DMSetup=new TDMSetup(Application);
DMSetup->ProveritPosled(pos_doc);
delete DMSetup;

}
//-----------------------------------------------------------------------------

