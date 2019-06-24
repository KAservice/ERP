//---------------------------------------------------------------------------


#pragma hdrstop

#include "UkanXmlFile.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//-------------------------------------------------------------------
TkanXmlFile::TkanXmlFile()
{
//InFile=0;
}
//-----------------------------------------------------------------------------
TkanXmlFile::~TkanXmlFile()
{
//
}
//-----------------------------------------------------------------------------
UnicodeString TkanXmlFile::FormatForXML(UnicodeString str)
{
UnicodeString s=str;
UnicodeString S1=s;
UnicodeString S2="&";
UnicodeString S3="&amp;";

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
bool TkanXmlFile::AddFileAnsiString(UnicodeString file_name, AnsiString str)
{
bool result=false;
str=str+"\n";
const wchar_t *fileName=file_name.c_str();
ofstream outfile(fileName,ios::out|ios::app);

if (!outfile)
		{
		 return result;
		}

outfile<<str.c_str();
outfile.close();
result=true;
return result;
}
//-----------------------------------------------------------------------------
//PUBLIC
//-----------------------------------------------------------------------------

//----------------------------------------------------------------------------
bool TkanXmlFile::GreateHeader(UnicodeString file_name)
{
bool result;
//AnsiString s="<?xml version=\""+AnsiString(version)+"\" encoding=\""+AnsiString(encoding)+"\"?>";
AnsiString s="<?xml version=\"1.0\" encoding=\"windows-1251\"?>";
result=AddFileAnsiString(file_name, s);
return result;
}
//----------------------------------------------------------------------------
bool TkanXmlFile::AddString(UnicodeString file_name,UnicodeString str)
{
bool result=false;
AnsiString s=str;
result=AddFileAnsiString (file_name,s);
return result;
}
//----------------------------------------------------------------------------


//if (FileExists(full_name_file_xml)!=true)
//		{
//		glDM->glSaveProtocol("Не найден файл для загрузки: "+full_name_file_xml);
//		return;
//		}
//
//const char *fileName=full_name_file_xml.c_str();
//ifstream infile(fileName);
//
//if (!infile) {OutProtocol("Не удалось открыть xml файл!");}
//char s[1000];
//
//
//AnsiString str_1="";
//AnsiString str_2="";
//AnsiString str_end="</data>";
//
////1 строка Заголовок
//if (!infile.eof())
//        {
//        infile.getline(s,1000);
//        str_1=s;
//		}
//
////2 строка стартовый блок
//if (!infile.eof())
//        {
//		infile.getline(s,1000);
//        str_2=s;
//        }
//
//kol_rec=0;
//int kol_tec_record=0;
//*lpKolRecord=0;
//if(EventFirstRecord) EventFirstRecord(this);
//
//while(!infile.eof())
//		{
//        infile.getline(s,1000);
//        AnsiString text_xml=s;
//        if (Trim(text_xml)==str_end)  {break;}
//        //получим завершающий элемент
//		AnsiString end_element=Trim(text_xml);
//        end_element=Trim(end_element.SetLength(end_element.AnsiPos(" ")));
//        end_element=Trim(end_element.Delete(1,1));
//        end_element="</"+end_element+">";
//
//		bool end=false;
//        while((!infile.eof()) && end==false)
//                {
//                infile.getline(s,1000);
//                AnsiString tec_str=Trim(AnsiString(s));
//				if (tec_str==end_element)
//                        {
//                        end=true;
//
//						}
//				text_xml=text_xml+" "+tec_str;
//				}
//
//		text_xml=str_1+" "+str_2+" "+text_xml+" "+str_end;
//
//		UpdateInfBase(text_xml);
//		//kol_rec++;
//
//
//
//		if (kol_tec_record==10000)
//			{
//			kol_tec_record=0;
//			glSaveProtocol("Загружено изменений: "+IntToStr(kol_rec));
//			}
//		else
//			{
//			kol_tec_record++;
//			}
//
//		text_xml="";
//		if(EventFirstRecord) EventNextRecord(this);
//		}
//
//
//infile.close();
//
//
//glSaveProtocol("Загружено изменений: "+IntToStr(kol_rec));

//---------------------------------------------------------------------------
bool TkanXmlFile::OpenFile(UnicodeString file_name)
{
bool result=false;
AnsiString ansi_file_name=file_name;

//InFile=In_File;
if ((InFile=fopen(ansi_file_name.c_str(),"rt"))==NULL)
	{
	result=false;
	}
else
	{
	result=true;
	}
result=true;
return result;
}
//-----------------------------------------------------------------------------
UnicodeString TkanXmlFile::ReadString(void)  //читаем текущую строку
{ //читаем строку и переводим указатаель положения
UnicodeString result="";
char s[1000];
fgets(s,1000,InFile);
result=s;
return result;
}
//-----------------------------------------------------------------------------
bool TkanXmlFile::Eof(void)
{ //если конец файла то true
bool result;
result=feof(InFile);
return result;
}
//----------------------------------------------------------------------------
bool TkanXmlFile::CloseFile(void)
{
bool result=true;
fclose(InFile);
return result;
}
//-----------------------------------------------------------------------------
