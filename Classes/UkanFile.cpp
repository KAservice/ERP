//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "SYSUtils.hpp"
#include <fstream.h>
#include "UkanFile.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//-------------------------------------------------------------------
TkanFile::TkanFile()
{
//
}
//-----------------------------------------------------------------------------
TkanFile::~TkanFile()
{
//
}
//-----------------------------------------------------------------------------
//PRIVATE
//-----------------------------------------------------------------------------
AnsiString TkanFile::XML_FormatForXML(UnicodeString str)
{
AnsiString s=str;
AnsiString S1=s;
AnsiString S2="&";
AnsiString S3="&amp;";

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
void TkanFile::AddFileAnsiString(UnicodeString file_name, AnsiString str)
{
str=str+"\n";
const wchar_t *fileName=file_name.c_str();
ofstream outfile(fileName,ios::out|ios::app);

if (!outfile)
		{
		 return;
		}

outfile<<str.c_str();
outfile.close();
}
//-----------------------------------------------------------------------------
//PUBLIC
//-----------------------------------------------------------------------------
void TkanFile::AddString(UnicodeString file_name, UnicodeString str)
{
try
	{
	TFileStream * stream=new TFileStream (file_name, fmOpenWrite);
	stream->Position=stream->Size;
	stream->Write(str.c_str(),str.Length()*2);
	char * s=new char[4];
	s[0]=0x0d;
	s[1]=0x00;
	s[2]=0x0a;
	s[3]=0x00;
	stream->Write(s,4);
	delete s;
	delete stream;
	}
catch(...)
	{
	TFileStream * stream=new TFileStream (file_name, fmCreate);
	char * s=new char[4];
	s[0]=0xff;
	s[1]=0xfe;
	stream->Write(s,2);
	stream->Write(str.c_str(),str.Length()*2);
	s[0]=0x0d;
	s[1]=0x00;
	s[2]=0x0a;
	s[3]=0x00;
	stream->Write(s,4);
	delete s;
	delete stream;
	}
}

//----------------------------------------------------------------------------
void TkanFile::XML_GreateHeader(UnicodeString file_name, UnicodeString version, UnicodeString encoding)
{
AnsiString s="<?xml version=\""+AnsiString(version)+"\" encoding=\""+AnsiString(encoding)+"\"?>";
AddFileAnsiString(file_name, s);
}
//----------------------------------------------------------------------------
void TkanFile::XML_AddString(UnicodeString file_name, UnicodeString str)
{
AnsiString s=str;
AddFileAnsiString (file_name, s);

}
//----------------------------------------------------------------------------

