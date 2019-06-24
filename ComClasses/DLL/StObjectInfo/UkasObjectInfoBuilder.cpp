//---------------------------------------------------------------------------


#pragma hdrstop

#include "UkasObjectInfoBuilder.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------
TkasObjectInfoBuilder::TkasObjectInfoBuilder()
{
//
Error=false;
TextError="";
List=new TStringList;
}

//-----------------------------------------------------------------------------
TkasObjectInfoBuilder::~TkasObjectInfoBuilder()
{
delete List;
}
//---------------------------------------------------------------------------
TkasObjectInfo * TkasObjectInfoBuilder::GetObjectInfo(UnicodeString name_object)
{
TkasObjectInfo * res;
UnicodeString file_name="";
UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
file_name=ProgramCatalog+"\\ModuleInfo\\"+name_object+".kas";
NumberString=0;

if (FileExists(file_name)==true)
	{


	UnicodeString ProgramCatalog=ExtractFileDir(Application->ExeName);
	List->LoadFromFile(file_name);

	res=GetInfo(0);

	}
else
	{
	Error=true;

	TextError="�� ������� �������� ������!" + name_object;
	}


return res;
}
//----------------------------------------------------------------------------
TkasObjectInfo * TkasObjectInfoBuilder::GetInfo(TkasObjectInfo * ob_roditel)
{
//���� ����� ������ ������� ����� ������ ������� ��� �������
TkasObjectInfo * tec_object;

			tec_object=new TkasObjectInfo();
				//�������� ��� ������� � ��� �������
				//������� �� ������ object
UnicodeString str=Trim(List->Strings[NumberString]);
			str=Trim(str);
			str=str.Delete(1,7);
			//���� ���������
			int index1=str.Pos(':');
			if (index1 !=0)
				{
				UnicodeString name_object = str.SubString(1,index1-1);
				UnicodeString type_object = str.Delete(1,index1);
				tec_object->NameObject=Trim(name_object);
				tec_object->TypeObject=Trim(type_object);
				}

			if (ob_roditel !=0)
				{
				ob_roditel->ListObject->Add(tec_object);
				}
    NumberString++;


    //�������� ���������� ������ ����� �������� ������ ����������
	while (NumberString < List->Count)
		{
		UnicodeString str=Trim(List->Strings[NumberString]);

		//��������� �� object
		int index=str.Pos("object");
		if (index !=0)
			{ //������ ������
			//��������� �������� ������ ����������� ��������
			GetInfo(tec_object);
			}
		else
			{
			//��������� �� end
			int index1=str.Pos("end");
			if (index1 !=0)
				{ //������ �����
				break;
				}
			else
				{  //������ ������ ��������

				//���� =
				int index2=str.Pos('=');
				if (index2 !=0)
					{
					UnicodeString name_parameter = Trim(str.SubString(1,index2-1));
					UnicodeString value_parameter = GetValueStringParameter();
					TkasObjectInfoProperties * pr= new TkasObjectInfoProperties;
					pr->NameParameter = Trim(name_parameter);
					pr->ValueParameter = Trim(value_parameter);
					tec_object->ListProperties->Add(pr);
					}
				}
			}

        NumberString++;
		}


return tec_object;
}
//--------------------------------------------------------------------------------
UnicodeString TkasObjectInfoBuilder::GetValueStringParameter(void)
{
UnicodeString result="";
UnicodeString str=Trim(List->Strings[NumberString]);



int index2=str.Pos('=');
if (index2 !=0)
	{
	UnicodeString name_parameter = Trim(str.SubString(1,index2-1));
	UnicodeString value_parameter = Trim(str.Delete(1,index2));

	//1 ������ (
	UnicodeString symb=value_parameter[1];

	if (symb == "(")
		{ //�������� ������ �� )
		NumberString++;
		value_parameter="";

		bool fl=true;

		while (fl==true)
			{
			UnicodeString str1=Trim(List->Strings[NumberString]);
			if (str1 == ")")
				{
				fl=false;
				}
			else
				{
				value_parameter=value_parameter+"\n"+str1;
				NumberString++;
				}


			}

		}

	result = Trim(value_parameter);
	}



return result;
}
//------------------------------------------------------------------------------
