//---------------------------------------------------------------------------
#include "glPCH.h"

#pragma hdrstop
#include "SYSUtils.hpp"
#include "UkanTxtFile.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
//-------------------------------------------------------------------
TkanTxtFile::TkanTxtFile()
{
//
}
//-----------------------------------------------------------------------------
TkanTxtFile::~TkanTxtFile()
{
//
}
//-----------------------------------------------------------------------------
void TkanTxtFile::AddString(UnicodeString file_name, UnicodeString str)
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
//------------------------------------------------------------------------------