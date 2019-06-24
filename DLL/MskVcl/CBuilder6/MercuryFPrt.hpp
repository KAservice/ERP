// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MercuryFPrt.pas' rev: 6.00

#ifndef MercuryFPrtHPP
#define MercuryFPrtHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mercuryfprt
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EMercError;
class PASCALIMPLEMENTATION EMercError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
private:
	int FCode;
	int FCodeEx;
	
public:
	__property int Code = {read=FCode, write=FCode, nodefault};
	__property int CodeEx = {read=FCodeEx, write=FCodeEx, nodefault};
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EMercError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercConnection;
class PASCALIMPLEMENTATION EMercConnection : public EMercError 
{
	typedef EMercError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EMercConnection(const AnsiString Msg) : EMercError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercConnection(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercConnection(int Ident)/* overload */ : EMercError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercConnection(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercConnection(const AnsiString Msg, int AHelpContext) : EMercError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercConnection(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercConnection(int Ident, int AHelpContext)/* overload */ : EMercError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercConnection(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercConnection(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercRequestAborted;
class PASCALIMPLEMENTATION EMercRequestAborted : public EMercConnection 
{
	typedef EMercConnection inherited;
	
public:
	__fastcall EMercRequestAborted(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercRequestAborted(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercConnection(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercRequestAborted(int Ident)/* overload */ : EMercConnection(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercRequestAborted(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercConnection(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercRequestAborted(const AnsiString Msg, int AHelpContext) : EMercConnection(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercRequestAborted(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercConnection(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercRequestAborted(int Ident, int AHelpContext)/* overload */ : EMercConnection(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercRequestAborted(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercConnection(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercRequestAborted(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercConnOpened;
class PASCALIMPLEMENTATION EMercConnOpened : public EMercConnection 
{
	typedef EMercConnection inherited;
	
public:
	__fastcall EMercConnOpened(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercConnOpened(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercConnection(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercConnOpened(int Ident)/* overload */ : EMercConnection(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercConnOpened(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercConnection(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercConnOpened(const AnsiString Msg, int AHelpContext) : EMercConnection(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercConnOpened(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercConnection(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercConnOpened(int Ident, int AHelpContext)/* overload */ : EMercConnection(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercConnOpened(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercConnection(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercConnOpened(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercConnClosed;
class PASCALIMPLEMENTATION EMercConnClosed : public EMercConnection 
{
	typedef EMercConnection inherited;
	
public:
	__fastcall EMercConnClosed(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercConnClosed(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercConnection(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercConnClosed(int Ident)/* overload */ : EMercConnection(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercConnClosed(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercConnection(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercConnClosed(const AnsiString Msg, int AHelpContext) : EMercConnection(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercConnClosed(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercConnection(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercConnClosed(int Ident, int AHelpContext)/* overload */ : EMercConnection(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercConnClosed(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercConnection(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercConnClosed(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercNoResponse;
class PASCALIMPLEMENTATION EMercNoResponse : public EMercConnection 
{
	typedef EMercConnection inherited;
	
public:
	__fastcall EMercNoResponse(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercNoResponse(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercConnection(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercNoResponse(int Ident)/* overload */ : EMercConnection(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercNoResponse(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercConnection(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercNoResponse(const AnsiString Msg, int AHelpContext) : EMercConnection(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercNoResponse(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercConnection(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercNoResponse(int Ident, int AHelpContext)/* overload */ : EMercConnection(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercNoResponse(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercConnection(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercNoResponse(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercUnknownDevice;
class PASCALIMPLEMENTATION EMercUnknownDevice : public EMercConnection 
{
	typedef EMercConnection inherited;
	
public:
	__fastcall EMercUnknownDevice(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercUnknownDevice(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercConnection(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercUnknownDevice(int Ident)/* overload */ : EMercConnection(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercUnknownDevice(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercConnection(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercUnknownDevice(const AnsiString Msg, int AHelpContext) : EMercConnection(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercUnknownDevice(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercConnection(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercUnknownDevice(int Ident, int AHelpContext)/* overload */ : EMercConnection(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercUnknownDevice(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercConnection(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercUnknownDevice(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercNoLicence;
class PASCALIMPLEMENTATION EMercNoLicence : public EMercError 
{
	typedef EMercError inherited;
	
public:
	__fastcall EMercNoLicence(int ACodeEx, const AnsiString AddMsg);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercNoLicence(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercNoLicence(int Ident)/* overload */ : EMercError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercNoLicence(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercNoLicence(const AnsiString Msg, int AHelpContext) : EMercError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercNoLicence(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercNoLicence(int Ident, int AHelpContext)/* overload */ : EMercError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercNoLicence(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercNoLicence(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercOperationCancelled;
class PASCALIMPLEMENTATION EMercOperationCancelled : public EMercError 
{
	typedef EMercError inherited;
	
public:
	__fastcall EMercOperationCancelled(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercOperationCancelled(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercOperationCancelled(int Ident)/* overload */ : EMercError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercOperationCancelled(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercOperationCancelled(const AnsiString Msg, int AHelpContext) : EMercError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercOperationCancelled(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercOperationCancelled(int Ident, int AHelpContext)/* overload */ : EMercError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercOperationCancelled(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercOperationCancelled(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercNoConversion;
class PASCALIMPLEMENTATION EMercNoConversion : public EMercError 
{
	typedef EMercError inherited;
	
public:
	__fastcall EMercNoConversion(int ACodeEx, const AnsiString AddMsg);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercNoConversion(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercNoConversion(int Ident)/* overload */ : EMercError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercNoConversion(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercNoConversion(const AnsiString Msg, int AHelpContext) : EMercError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercNoConversion(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercNoConversion(int Ident, int AHelpContext)/* overload */ : EMercError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercNoConversion(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercNoConversion(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercUnsupported;
class PASCALIMPLEMENTATION EMercUnsupported : public EMercError 
{
	typedef EMercError inherited;
	
public:
	__fastcall EMercUnsupported(const AnsiString AddMsg);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercUnsupported(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercUnsupported(int Ident)/* overload */ : EMercError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercUnsupported(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercUnsupported(const AnsiString Msg, int AHelpContext) : EMercError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercUnsupported(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercUnsupported(int Ident, int AHelpContext)/* overload */ : EMercError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercUnsupported(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercUnsupported(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercDocError;
class PASCALIMPLEMENTATION EMercDocError : public EMercError 
{
	typedef EMercError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EMercDocError(const AnsiString Msg) : EMercError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercDocError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercDocError(int Ident)/* overload */ : EMercError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercDocError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercDocError(const AnsiString Msg, int AHelpContext) : EMercError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercDocError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercDocError(int Ident, int AHelpContext)/* overload */ : EMercError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercDocError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercDocError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercDocOverflow;
class PASCALIMPLEMENTATION EMercDocOverflow : public EMercDocError 
{
	typedef EMercDocError inherited;
	
public:
	__fastcall EMercDocOverflow(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercDocOverflow(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercDocError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercDocOverflow(int Ident)/* overload */ : EMercDocError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercDocOverflow(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercDocError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercDocOverflow(const AnsiString Msg, int AHelpContext) : EMercDocError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercDocOverflow(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercDocError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercDocOverflow(int Ident, int AHelpContext)/* overload */ : EMercDocError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercDocOverflow(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercDocError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercDocOverflow(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercNoDocument;
class PASCALIMPLEMENTATION EMercNoDocument : public EMercDocError 
{
	typedef EMercDocError inherited;
	
public:
	__fastcall EMercNoDocument(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercNoDocument(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercDocError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercNoDocument(int Ident)/* overload */ : EMercDocError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercNoDocument(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercDocError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercNoDocument(const AnsiString Msg, int AHelpContext) : EMercDocError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercNoDocument(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercDocError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercNoDocument(int Ident, int AHelpContext)/* overload */ : EMercDocError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercNoDocument(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercDocError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercNoDocument(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercDocOpened;
class PASCALIMPLEMENTATION EMercDocOpened : public EMercDocError 
{
	typedef EMercDocError inherited;
	
public:
	__fastcall EMercDocOpened(void);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercDocOpened(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercDocError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercDocOpened(int Ident)/* overload */ : EMercDocError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercDocOpened(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercDocError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercDocOpened(const AnsiString Msg, int AHelpContext) : EMercDocError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercDocOpened(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercDocError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercDocOpened(int Ident, int AHelpContext)/* overload */ : EMercDocError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercDocOpened(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercDocError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercDocOpened(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercForbidden;
class PASCALIMPLEMENTATION EMercForbidden : public EMercDocError 
{
	typedef EMercDocError inherited;
	
public:
	__fastcall EMercForbidden(const AnsiString AddMsg);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercForbidden(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercDocError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercForbidden(int Ident)/* overload */ : EMercDocError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercForbidden(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercDocError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercForbidden(const AnsiString Msg, int AHelpContext) : EMercDocError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercForbidden(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercDocError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercForbidden(int Ident, int AHelpContext)/* overload */ : EMercDocError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercForbidden(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercDocError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercForbidden(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercForbiddenVersion;
class PASCALIMPLEMENTATION EMercForbiddenVersion : public EMercDocError 
{
	typedef EMercDocError inherited;
	
public:
	__fastcall EMercForbiddenVersion(const AnsiString AddMsg);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercForbiddenVersion(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercDocError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercForbiddenVersion(int Ident)/* overload */ : EMercDocError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercForbiddenVersion(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercDocError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercForbiddenVersion(const AnsiString Msg, int AHelpContext) : EMercDocError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercForbiddenVersion(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercDocError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercForbiddenVersion(int Ident, int AHelpContext)/* overload */ : EMercDocError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercForbiddenVersion(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercDocError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercForbiddenVersion(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercDuplication;
class PASCALIMPLEMENTATION EMercDuplication : public EMercDocError 
{
	typedef EMercDocError inherited;
	
public:
	__fastcall EMercDuplication(int ACodeEx, const AnsiString AddMsg);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercDuplication(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercDocError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercDuplication(int Ident)/* overload */ : EMercDocError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercDuplication(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercDocError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercDuplication(const AnsiString Msg, int AHelpContext) : EMercDocError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercDuplication(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercDocError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercDuplication(int Ident, int AHelpContext)/* overload */ : EMercDocError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercDuplication(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercDocError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercDuplication(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercNoProperty;
class PASCALIMPLEMENTATION EMercNoProperty : public EMercDocError 
{
	typedef EMercDocError inherited;
	
public:
	__fastcall EMercNoProperty(int ACodeEx, const AnsiString AddMsg);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercNoProperty(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercDocError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercNoProperty(int Ident)/* overload */ : EMercDocError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercNoProperty(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercDocError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercNoProperty(const AnsiString Msg, int AHelpContext) : EMercDocError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercNoProperty(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercDocError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercNoProperty(int Ident, int AHelpContext)/* overload */ : EMercDocError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercNoProperty(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercDocError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercNoProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercInvalidArg;
class PASCALIMPLEMENTATION EMercInvalidArg : public EMercError 
{
	typedef EMercError inherited;
	
public:
	__fastcall EMercInvalidArg(int ACodeEx, const AnsiString AddMsg);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercInvalidArg(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercInvalidArg(int Ident)/* overload */ : EMercError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercInvalidArg(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercInvalidArg(const AnsiString Msg, int AHelpContext) : EMercError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercInvalidArg(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercInvalidArg(int Ident, int AHelpContext)/* overload */ : EMercError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercInvalidArg(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercInvalidArg(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercBadResponse;
class PASCALIMPLEMENTATION EMercBadResponse : public EMercError 
{
	typedef EMercError inherited;
	
public:
	__fastcall EMercBadResponse(int ACodeEx, const AnsiString AddMsg);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercBadResponse(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercBadResponse(int Ident)/* overload */ : EMercError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercBadResponse(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercBadResponse(const AnsiString Msg, int AHelpContext) : EMercError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercBadResponse(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercBadResponse(int Ident, int AHelpContext)/* overload */ : EMercError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercBadResponse(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercBadResponse(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMercEcrError;
class PASCALIMPLEMENTATION EMercEcrError : public EMercError 
{
	typedef EMercError inherited;
	
public:
	__fastcall EMercEcrError(int ACodeEx, const AnsiString AddMsg);
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMercEcrError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EMercError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMercEcrError(int Ident)/* overload */ : EMercError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMercEcrError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EMercError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMercEcrError(const AnsiString Msg, int AHelpContext) : EMercError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMercEcrError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EMercError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMercEcrError(int Ident, int AHelpContext)/* overload */ : EMercError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMercEcrError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EMercError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMercEcrError(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TMercEcrModel { memUnknown, mem114_1F, memSystemF, memMSK, mem114_1K, mem114_1FMD, memSystemK, mem118K, mem119K, mem119FAZ, memNTSF, memMStarFKZ, memMSFAZ, mem118FAZ };
#pragma option pop

#pragma option push -b-
enum TMercProtocol { mprUnknown, mprBS, mprXOnXoff };
#pragma option pop

#pragma option push -b-
enum TMercDocStatus { mdsUnknown, mdsClosed, mdsCached, mdsOpened, mdsTotal, mdsCompleted, mdsReceipt, mdsCustom, mdsForm };
#pragma option pop

#pragma option push -b-
enum TMercOperType { motUnknown, motSale, motRefund, motRefundCashless, motVoid, motCashIn, motCashOut, motBuying, motBuyingRefund, motBuyingVoid, motDayOpening, motXReport, motZReport };
#pragma option pop

#pragma option push -b-
enum TMercPayType { mptCash, mptCredit, mptCard, mptCashCredit, mptCashCard };
#pragma option pop

#pragma option push -b-
enum TMercOperInfo { moiNumber, moiName, moiNumberName };
#pragma option pop

#pragma option push -b-
enum TMercItemType { mitItem, mitPercentAdj, mitAmountAdj, mitVoidItem, mitVoidPercentAdj, mitVoidAmountAdj };
#pragma option pop

#pragma option push -b-
enum TMercConnState { mcsNone, mcsIdle, mcsWriting, mcsReading, mcsNoResponse, mcsPrinterError, mcsDisplayError };
#pragma option pop

#pragma option push -b-
enum TMercCmdType { mctInternal, mctProtocol, mctExternal };
#pragma option pop

#pragma option push -b-
enum TMercLicenceType { mltLocal, mltUser, mltAllUsers };
#pragma option pop

#pragma option push -b-
enum TMercCodingType { mctGeneral, mctMoldavian, mctAzerbaijani, mctBelarussian };
#pragma option pop

#pragma option push -b-
enum TMercEKLState { meklEmpty, meklNonEmpty, meklAttention, meklFull };
#pragma option pop

#pragma pack(push, 1)
struct TMercPriceData
{
	char Department[2];
	char Sep1;
	char Code[4];
	char Sep2;
	char Adjustment[5];
	char Sep3;
	char Quantity[11];
	char Sep4;
	char Price[11];
	char Sep5;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TMercItemData
{
	char Desc[40];
	char Sep1;
	char Flags[2];
	char Sep2;
	TMercPriceData PriceData;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TMercReceiptHeader
{
	char Oper;
	char Sep1;
	char Flags[2];
	char Sep2;
	char CopiesNum;
	char Sep3;
	char PayType;
	char Sep4;
	char PayInfo[20];
	char Sep5;
	char Account[40];
	char Sep6;
	char ItemsCount[3];
	char Sep7;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TMercDocPropertyData
{
	char PropType[2];
	char Sep1;
	char Flags[2];
	char Sep2;
	char HOffset[2];
	char Sep3;
	char VOffset[3];
	char Data[40];
	char Sep4;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TMercCustomDocHeader
{
	char Oper;
	char Sep1;
	char Flags[2];
	char Sep2;
	char HCopiesNum;
	char Sep3;
	char VCopiesNum;
	char Sep4;
	char VOrigOffset[2];
	char Sep5;
	char HCopyOffset[2];
	char Sep6;
	char VCopyOffset[2];
	char Sep7;
	char PayType;
	char Sep8;
	char PropsCount[3];
	char Sep9;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TMercPriceDataV03
{
	char Department[2];
	char Sep1;
	char Code[6];
	char Sep2;
	char Adjustment[5];
	char Sep3;
	char Quantity[11];
	char Sep4;
	char Price[11];
	char Sep5;
	char UnitName[5];
	char Sep6;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TMercDocPropertyDataV03
{
	char PropType[2];
	char Sep1;
	char Flags[4];
	char Sep2;
	char HOffset[2];
	char Sep3;
	char VOffset[3];
	char Sep4;
	char Reserved[5];
	char Data[40];
	char Sep5;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TMercCountersValues
{
	char TotalSum[15];
	char Sep1;
	char CashSum[15];
	char Sep2;
	char SaleCount[5];
	char Sep3;
	char SaleSum[15];
	char Sep4;
	char SaleTareCount[5];
	char Sep5;
	char SaleTareSum[15];
	char Sep6;
	char CreditCount[5];
	char Sep7;
	char CreditSum[15];
	char Sep8;
	char DiscountCount[5];
	char Sep9;
	char DiscountSum[15];
	char Sep10;
	char SurchargeCount[5];
	char Sep11;
	char SurchargeSum[15];
	char Sep12;
	char RefundCount[5];
	char Sep13;
	char RefundSum[15];
	char Sep14;
	char VoidCount[5];
	char Sep15;
	char VoidSum[15];
	char Sep16;
	char CashInCount[5];
	char Sep17;
	char CashInSum[15];
	char Sep18;
	char CashOutCount[5];
	char Sep19;
	char CashOutSum[15];
	char Sep20;
	char CardCount[5];
	char Sep21;
	char CardSum[15];
	char Sep22;
	char Reserved1[15];
	char Sep23;
	char Reserved2[15];
	char Sep24;
	char Reserved3[15];
	char Sep25;
	char Reserved4[15];
	char Sep26;
	char Reserved5[15];
	char Sep27;
} ;
#pragma pack(pop)

typedef void __fastcall (__closure *TMercDataEvent)(System::TObject* Sender, const void *Data, int DataSize);

class DELPHICLASS TMercuryFPrt;
class PASCALIMPLEMENTATION TMercuryFPrt : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
protected:
	/*         class method */ static int __fastcall EncodeNumber(TMetaClass* vmt, __int64 Value, int Digits, bool ForceDigits, /* out */ void *Buffer);
	/*         class method */ static __int64 __fastcall DecodeNumber(TMetaClass* vmt, const void *Buffer, int MaxDigits, /* out */ int &Digits);
	/*         class method */ static __int64 __fastcall DecodeFixedNumber(TMetaClass* vmt, const void *Buffer, int Digits);
	/*         class method */ static void __fastcall HalfByteToHex(TMetaClass* vmt, Byte Value, /* out */ void *Buffer);
	/*         class method */ static Byte __fastcall HexToHalfByte(TMetaClass* vmt, const void *Buffer);
	/*         class method */ static void __fastcall ByteToHex(TMetaClass* vmt, Byte Value, /* out */ void *Buffer);
	/*         class method */ static Byte __fastcall HexToByte(TMetaClass* vmt, const void *Buffer);
	/*         class method */ static void __fastcall WordToHex(TMetaClass* vmt, Word Value, /* out */ void *Buffer);
	/*         class method */ static Word __fastcall HexToWord(TMetaClass* vmt, const void *Buffer);
	/*         class method */ static void __fastcall EncodeDate(TMetaClass* vmt, System::TDateTime ADate, /* out */ void *Buffer);
	/*         class method */ static System::TDateTime __fastcall DecodeDate(TMetaClass* vmt, const void *Buffer);
	/*         class method */ static void __fastcall EncodeTime(TMetaClass* vmt, System::TDateTime ATime, /* out */ void *Buffer);
	/*         class method */ static System::TDateTime __fastcall DecodeTime(TMetaClass* vmt, const void *Buffer);
	/*         class method */ static Byte __fastcall CountBCC(TMetaClass* vmt, const void *Data, int DataSize);
	/*         class method */ static void __fastcall CheckSeparators(TMetaClass* vmt, const char * Values, const int Values_Size);
	
private:
	AnsiString FVersion;
	AnsiString FStubStr;
	int FVersionNumber;
	int FBuildNumber;
	TMercConnState FConnState;
	unsigned FPortHandle;
	TMercEcrModel FEcrModel;
	int FEcrVersion;
	int FEcrSubVersion;
	TMercCodingType FCodingType;
	int FGeneration;
	bool FEKLZSupported;
	TMercProtocol FProtocol;
	Word FEcrCoreStatus;
	int FEcrStatus;
	int FEcrStatusMask;
	Byte FDevCoreStatus;
	int FDevStatus;
	int FDevStatusMask;
	TMercDocStatus FDocStatus;
	TMercOperType FCurrentOper;
	bool FNoDevStatusEvent;
	bool FMultiPassword;
	TMercDataEvent FOnDataSend;
	TMercDataEvent FOnDataReceive;
	Classes::TNotifyEvent FOnNoResponse;
	Classes::TNotifyEvent FOnPrinterError;
	Classes::TNotifyEvent FOnDisplayError;
	Classes::TNotifyEvent FOnStatusUpdate;
	Classes::TNotifyEvent FOnConnStateUpdate;
	bool FRetryOperation;
	bool FOperationCancelled;
	int FDevErrCount;
	bool FActive;
	int FPortNum;
	int FBaudRate;
	WideString FPassword;
	int FInternalTimeout;
	bool FInternalUsing;
	int FExternalTimeout;
	bool FExternalUsing;
	bool FUnescapingDisabled;
	bool FCancelException;
	bool FCtrlCharsDisabled;
	bool FSpecialDecoding;
	#pragma pack(push, 1)
	TMercReceiptHeader FRecHeader;
	#pragma pack(pop)
	
	int FRecItemsCount;
	TMercItemData FRecItems[196];
	#pragma pack(push, 1)
	TMercCustomDocHeader FCustomDocHeader;
	#pragma pack(pop)
	
	TMercOperType FFiscalCacheOper;
	int FDocPropsCount;
	TMercDocPropertyData FDocProps[300];
	TMercDocPropertyDataV03 FDocPropsV03[300];
	System::Set<Byte, 0, 255>  FDocPropTypes;
	TMercPayType FDocPayType;
	int FFiscalHOffset;
	int FFiscalVOffset;
	int FEKLZVOffset;
	int FMaxVOffset;
	System::Currency FSaleSum;
	System::Currency FBuyingSum;
	WideString FSerialNumber;
	WideString FRegNumber;
	WideString FTaxPayerNumber;
	WideString FHeaderLine1;
	WideString FHeaderLine2;
	WideString FHeaderLine3;
	WideString FHeaderLine4;
	System::TDateTime FStartDate;
	System::TDateTime FEndDate;
	int FStartNumber;
	int FEndNumber;
	System::TDateTime FReportDateTime;
	WideString FModelName;
	WideString FManufacturer;
	WideString FFirmwareVersion;
	WideString FTaxName;
	System::TDateTime FTaxDate;
	int FCounterCount;
	int FRewritesRemain;
	int FDaysRemain;
	int FLastFiscalReport;
	int FLastDayClosing;
	System::TDateTime FDayDateTime;
	int FLastDocOper;
	int FLastDocNumber;
	int FLastRecNumber;
	int FLastRepNumber;
	TMercOperType FLastDocType;
	System::Currency FLastDocSum;
	System::Currency FLastBuyingSum;
	System::TDateTime FLastDocDateTime;
	System::TDateTime FEcrDateTime;
	bool FEKLZActivated;
	TMercOperType FEKLZOper;
	bool FEKLZArchiving;
	bool FEKLZReporting;
	bool FEKLZDayOpened;
	bool FEKLZFatalError;
	bool FEKLZAttention;
	int FEKLZRest;
	bool FCountersPresent;
	#pragma pack(push, 1)
	TMercCountersValues FCountersValues;
	#pragma pack(pop)
	
	Classes::TStringList* FLocalLicList;
	_RTL_CRITICAL_SECTION FRequestCS;
	bool FRequestProcessing;
	bool FRequestAborted;
	unsigned FCmdFinishEvent;
	bool __fastcall GetConnected(void);
	TMercDocStatus __fastcall GetDocStatus(void);
	TMercOperType __fastcall GetCurrentOper(void);
	int __fastcall GetEcrHour(void);
	int __fastcall GetEcrMin(void);
	int __fastcall GetReportHour(void);
	int __fastcall GetReportMin(void);
	int __fastcall GetDayHour(void);
	int __fastcall GetDayMin(void);
	int __fastcall GetLastDocHour(void);
	int __fastcall GetLastDocMin(void);
	void __fastcall SetRetryOperation(bool Value);
	void __fastcall SetActive(bool Value);
	void __fastcall SetPortNum(int Value);
	void __fastcall SetBaudRate(int Value);
	void __fastcall SetPassword(const WideString Value);
	void __fastcall SetInternalTimeout(int Value);
	void __fastcall SetExternalTimeout(int Value);
	
protected:
	int FErrCode;
	int FErrCodeEx;
	WideString FErrMessage;
	bool __fastcall CheckVersion(TMercEcrModel AModel, int AVersion, int ASubVersion = 0x0);
	virtual void __fastcall Loaded(void);
	void __fastcall ChangeConnState(TMercConnState Value);
	void __fastcall UpdateEcrStatus(void);
	void __fastcall UpdateDevStatus(void)/* overload */;
	void __fastcall UpdateDevStatus(const Byte * CoreExStatus, const int CoreExStatus_Size)/* overload */;
	Byte __fastcall StartRequest(Byte Cmd);
	void __fastcall DataRequest(const void *Data, int DataSize, Byte &BCC);
	void __fastcall FinishRequest(Byte BCC);
	void __fastcall SendRequest(Byte Cmd, const void *Data, int DataSize);
	bool __fastcall WaitResponse(Byte Cmd);
	void __fastcall ReceiveResponse(Byte Cmd, /* out */ void *Data, int DataSize);
	void __fastcall WaitAndReceiveResponse(Byte Cmd, /* out */ void *Data, int DataSize, TMercCmdType CmdType);
	void __fastcall CorrectTimeouts(Byte Cmd, TMercCmdType CmdType);
	void __fastcall Transfer(Byte Cmd, TMercCmdType CmdType, const void *OutData, int OutDataSize, /* out */ void *InData, int InDataSize);
	void __fastcall TransferOut(Byte Cmd, TMercCmdType CmdType, const void *OutData, int OutDataSize);
	void __fastcall TransferIn(Byte Cmd, TMercCmdType CmdType, /* out */ void *InData, int InDataSize);
	void __fastcall TransferSimple(Byte Cmd, TMercCmdType CmdType);
	void __fastcall StartConnection(void);
	int __fastcall EncodeString(const WideString S, /* out */ void *Buffer, int MaxSize, TMercCodingType ACodingType, bool Unescape = false);
	WideString __fastcall DecodeString(const void *Buffer, TMercCodingType ACodingType);
	char __fastcall ConvertOperType(TMercOperType Oper);
	Word __fastcall FillPriceData(TMercItemType ItemType, System::Currency Price, bool ItemIsTare, int Department, int Code, int Adjustment, int Quantity, int QuantityPrec, int TaxIndex, const WideString UnitName, /* out */ void *PriceData);
	char __fastcall FillPayInfo(TMercPayType PayType, System::Currency PayCash, System::Currency PayCashless, const WideString PayInfo, /* out */ void *CorePayInfo, int InfoSize);
	Word __fastcall ConvertFlagsV03(int Flags);
	void __fastcall AddDocProperty(Byte PropType, Word Flags, const void *Data, int DataSize, int HOffset, int VOffset, int RightOffset = 0x0, bool UseRightOffset = false)/* overload */;
	void __fastcall AddDocProperty(Byte PropType, Word Flags, int HOffset, int VOffset, int RightOffset = 0x0, bool UseRightOffset = false)/* overload */;
	void __fastcall SendFiscalData(bool CloseDoc, bool CancelDoc);
	void __fastcall SendDevData(Byte Cmd, const WideString Data, bool OpenDev, bool CloseDev);
	int __fastcall FiscalReport(const WideString InspPswd, char RepType, const void *RepStart, const void *RepEnd);
	void __fastcall InternalQueryParameter(int Index, /* out */ void *Data);
	WideString __fastcall InternalQueryParameterStr(int Index);
	int __fastcall InternalQueryParameterInt(int Index);
	void __fastcall InternalSetParameter(Word Index, int Value);
	int __fastcall PrintReport(bool AZReport, bool ShortReport);
	int __fastcall PrintReportV03(char RepType, bool ShortReport, bool AccumulateOper, bool AccumulateDep, int OperDepNum);
	void __fastcall DocInfoResponse(Byte Cmd, TMercCmdType CmdType, /* out */ TMercOperType &ADocType, /* out */ System::TDateTime &ADocDateTime, /* out */ int &AOperNum, /* out */ int &ADocNum, /* out */ int &ARecNum, /* out */ int &ARepNum, /* out */ System::Currency &ADocSum, /* out */ System::Currency &ABuyingSum)/* overload */;
	void __fastcall DocInfoResponse(Byte Cmd, TMercCmdType CmdType)/* overload */;
	void __fastcall DocInfoCommand(Byte Cmd, TMercCmdType CmdType, const void *OutData, int OutDataSize, /* out */ TMercOperType &ADocType, /* out */ System::TDateTime &ADocDateTime, /* out */ int &AOperNum, /* out */ int &ADocNum, /* out */ int &ARecNum, /* out */ int &ARepNum, /* out */ System::Currency &ADocSum, /* out */ System::Currency &ABuyingSum)/* overload */;
	void __fastcall DocInfoCommand(Byte Cmd, TMercCmdType CmdType, const void *OutData, int OutDataSize)/* overload */;
	void __fastcall InternalLastDocInfo(/* out */ TMercOperType &ADocType, /* out */ System::TDateTime &ADocDateTime, /* out */ int &AOperNum, /* out */ int &ADocNum, /* out */ int &ARecNum, /* out */ int &ARepNum, /* out */ System::Currency &ADocSum, /* out */ System::Currency &ABuyingSum);
	int __fastcall InternalDocNumber(void)/* overload */;
	int __fastcall InternalDocNumber(/* out */ TMercOperType &ADocType)/* overload */;
	void __fastcall SetEcrDateTime(const System::TDateTime ADateTime);
	int __fastcall FiscalRewriteDate(const WideString InspPswd, const WideString RegNum, const WideString TaxPayerNum, const WideString NewInspPswd, const System::TDateTime ADate);
	void __fastcall SetTaxDate(int Index, const WideString TaxName, int TaxRate, const System::TDateTime ADate);
	int __fastcall EncodeSum(System::Currency Value, /* out */ void *Buffer);
	DYNAMIC void __fastcall StartCmd(void);
	DYNAMIC void __fastcall SetError(int AErrCode, int AErrCodeEx, const WideString AErrMessage);
	DYNAMIC void __fastcall ClearError(void);
	DYNAMIC void __fastcall HandleError(void);
	DYNAMIC void __fastcall FinishCmd(void);
	DYNAMIC void __fastcall OpenPort(void);
	DYNAMIC void __fastcall ClosePort(bool ForceAbort);
	DYNAMIC void __fastcall ClearPort(void);
	DYNAMIC void __fastcall SendData(const void *Data, int DataSize);
	DYNAMIC int __fastcall ReceiveData(/* out */ void *Data, int DataSize, bool ForceSize = true);
	virtual void __fastcall DoDataSend(const void *Data, int DataSize);
	virtual void __fastcall DoDataReceive(const void *Data, int DataSize);
	virtual void __fastcall DoNoResponse(void);
	virtual void __fastcall DoPrinterError(void);
	virtual void __fastcall DoDisplayError(void);
	virtual void __fastcall DoStatusUpdate(void);
	virtual void __fastcall DoConnStateUpdate(void);
	__property bool Connected = {read=GetConnected, nodefault};
	__property bool UnescapingDisabled = {read=FUnescapingDisabled, write=FUnescapingDisabled, nodefault};
	__property bool CtrlCharsDisabled = {read=FCtrlCharsDisabled, write=FCtrlCharsDisabled, nodefault};
	
public:
	bool __fastcall CapHeaderPrePrinting(void);
	bool __fastcall CapQuickInfoQuering(void);
	bool __fastcall CapDocInfoPreLoading(void);
	bool __fastcall CapEKLSupporting(void);
	bool __fastcall CapDocReprinting(void);
	__fastcall virtual TMercuryFPrt(Classes::TComponent* AOwner);
	__fastcall virtual ~TMercuryFPrt(void);
	void __fastcall AddLicence(TMercLicenceType LicType, const WideString Licence);
	virtual void __fastcall AbortRequest(void);
	virtual void __fastcall TestConnection(void);
	virtual void __fastcall Open(void);
	virtual void __fastcall Close(bool ForceAbort);
	int __fastcall CheckEcrStatus(int Flag);
	int __fastcall CheckDevStatus(int Flag);
	void __fastcall OpenReceipt(TMercOperType Oper);
	void __fastcall AddReceiptItem(const WideString Desc, System::Currency Price, bool ItemIsTare, int Department, int Code, int Adjustment, int Quantity, int QuantityPrec, int TaxIndex, const WideString UnitName, int Flags);
	void __fastcall CancelReceipt(void);
	void __fastcall CloseReceipt(const WideString Account, TMercPayType PayType, System::Currency PayCash, System::Currency PayCashless, const WideString PayInfo, int CopiesNum, TMercOperInfo OperInfo);
	void __fastcall OpenCustomDoc(bool UseForm, TMercOperType Oper);
	void __fastcall CancelCustomDoc(void);
	void __fastcall CloseCustomDoc(TMercPayType PayType, int Flags, int HCopiesNum, int VCopiesNum, int VOrigOffset, int HCopyOffset, int VCopyOffset, int FiscalCopy);
	void __fastcall OpenFiscalDoc(TMercOperType Oper);
	void __fastcall CancelFiscalDoc(bool BufferOnly);
	void __fastcall PrintFiscalDocBuffer(void);
	void __fastcall CloseFiscalDoc(void);
	void __fastcall CopyFiscalDoc(void);
	void __fastcall AddSerialNumber(int Flags, int HOffset, int VOffset);
	void __fastcall AddHeaderLine(int LineNum, int Flags, int HOffset, int VOffset);
	void __fastcall AddDateTime(int Flags, int HOffset, int VOffset);
	void __fastcall AddOperInfo(TMercOperInfo OperInfo, int Flags, int HOffset, int VOffset);
	void __fastcall AddDocNumber(int Flags, int HOffset, int VOffset);
	void __fastcall AddReceiptNumber(int Flags, int HOffset, int VOffset);
	void __fastcall AddAccount(const WideString Account, int Flags, int HOffset, int VOffset);
	void __fastcall AddTaxPayerNumber(int Flags, int HOffset, int VOffset);
	void __fastcall AddItem(TMercItemType ItemType, System::Currency Price, bool ItemIsTare, int Department, int Code, int Adjustment, int Quantity, int QuantityPrec, int TaxIndex, const WideString UnitName, int Flags, int HOffset, int VOffset, int RightOffset);
	void __fastcall AddDocPercentAdj(int Value, int TaxIndex, int Flags, int HOffset, int VOffset, int RightOffset);
	void __fastcall AddDocAmountAdj(System::Currency Value, int TaxIndex, int Flags, int HOffset, int VOffset, int RightOffset);
	void __fastcall AddTotal(int Flags, int HOffset, int VOffset, int RightOffset);
	void __fastcall AddPay(TMercPayType PayType, System::Currency PayCash, System::Currency PayCashless, const WideString PayInfo, int Flags, int HOffset, int VOffset, int RightOffset);
	void __fastcall AddChange(int Flags, int HOffset, int VOffset, int RightOffset);
	void __fastcall AddTaxSum(int TaxIndex, int Flags, int HOffset, int VOffset, int RightOffset);
	void __fastcall AddFiscalSign(int Flags, int HOffset, int VOffset);
	void __fastcall AddEKLZData(int Flags, int HOffset, int VOffset);
	void __fastcall AddRegNumber(int Flags, int HOffset, int VOffset);
	void __fastcall AddGraphicHeader(int Flags, int HOffset, int VOffset);
	void __fastcall AddBarcode(int Mask1, int Mask2, int Mask3, int Mask4, int Mask5, bool DoubleDensity, int Flags, int HOffset, int VOffset);
	void __fastcall AddCustom(const WideString Text, int Flags, int HOffset, int VOffset);
	void __fastcall RepeatOperation(void);
	void __fastcall OpenDay(int OperNum, const WideString OperName, bool FullJournal, TMercProtocol AProtocol);
	int __fastcall XReport(int Flags);
	int __fastcall XReportByDep(int DepartNum, int Flags);
	int __fastcall XReportByOper(int OperNum, int Flags);
	int __fastcall ZReport(int Flags);
	int __fastcall PrintEKL(int Flags);
	void __fastcall ReprintDocument(void);
	int __fastcall FiscalRewrite(const WideString InspPswd, const WideString RegNum, const WideString TaxPayerNum, const WideString NewInspPswd);
	int __fastcall FiscalReportByNum(const WideString InspPswd, bool PrintFull, int AStartNum, int AEndNum);
	int __fastcall FiscalReportByDate(const WideString InspPswd, bool PrintFull, System::TDateTime AStartDate, System::TDateTime AEndDate);
	int __fastcall FiscalReportAll(const WideString InspPswd);
	void __fastcall FeedAndCut(int LineCount, bool CutAfterFeed);
	void __fastcall PrintNonFiscal(const WideString Data, bool OpenDoc, bool CloseDoc);
	void __fastcall ShowDisplay(const WideString Data, bool OpenMode, bool CloseMode);
	void __fastcall SetDisplayBaudRate(int BaudRate);
	void __fastcall ExternalPulse(int Channel, int TimeOn, int TimeOff, int Count);
	void __fastcall QueryDevExStatus(void);
	void __fastcall PrintHeader(void);
	void __fastcall QueryFirmwareInfo(void);
	int __fastcall QueryTax(int Index);
	System::Currency __fastcall QueryCounter(int Index, bool NoRequest);
	void __fastcall QueryResourceInfo(bool PrintInfo);
	void __fastcall QueryLastDocInfo(void);
	WideString __fastcall QuerySerialNumber();
	WideString __fastcall QueryTaxPayerNumber();
	WideString __fastcall QueryRegNumber();
	WideString __fastcall QueryHeaderLine(int LineNum);
	WideString __fastcall QueryDepartName(int DepartNum);
	WideString __fastcall QueryTitle(int TitleNum);
	System::TDateTime __fastcall QueryEcrDateTime(void);
	int __fastcall QueryPrinterTimeout(void);
	int __fastcall QueryDisplayTimeout(void);
	int __fastcall QueryPrinterContrast(void);
	int __fastcall QueryLeading(void);
	bool __fastcall QueryHeaderAlignment(void);
	int __fastcall QueryOperNumber(void);
	WideString __fastcall QueryOperName(int OperNum);
	bool __fastcall QueryAutocut(void);
	bool __fastcall QueryEconomicMode(void);
	bool __fastcall QueryPaperJournal(void);
	bool __fastcall QueryFullJournal(void);
	bool __fastcall QueryParameterBool(int ParamCode);
	int __fastcall QueryParameterInt(int ParamCode);
	TMercEKLState __fastcall QueryEKLState(void);
	void __fastcall SetParameters(TMercProtocol Protocol, int PrnTimeout);
	void __fastcall SetProtocol(TMercProtocol Protocol);
	void __fastcall SetPrinterTimeout(int Timeout);
	void __fastcall SetDisplayTimeout(int Timeout);
	void __fastcall SetPrinterContrast(int Contrast);
	void __fastcall SetLeading(int Leading);
	void __fastcall SetCutterDisabled(bool Disabled);
	void __fastcall SetNarrowPaper(bool Narrow);
	void __fastcall SetHeaderAlignment(bool Aligned);
	void __fastcall SetAutocut(bool Autocut);
	void __fastcall SetEconomicMode(bool EconomicMode);
	void __fastcall SetPaperJournal(bool PaperJournal);
	void __fastcall SetFullJournal(bool FullJournal);
	void __fastcall SetParameterBool(int ParamCode, bool ParamValue);
	void __fastcall SetParameterInt(int ParamCode, int ParamValue);
	void __fastcall SetTax(int Index, const WideString TaxName, int TaxRate);
	void __fastcall SetSerialNumber(const WideString Value);
	void __fastcall SetHeader(const WideString Line1, const WideString Line2, const WideString Line3, const WideString Line4);
	void __fastcall SetDepartName(int DepartNum, const WideString Value);
	void __fastcall SetTitle(int TitleNum, const WideString Value);
	void __fastcall SetOperPassword(int OperNum, const WideString OperName, const WideString OperPassword);
	void __fastcall SynchronizeEcrDateTime(void);
	void __fastcall EnableGraphicHeader(int Width, int Height, void * Data)/* overload */;
	void __fastcall EnableGraphicHeader(int Width, int Height, const WideString Data)/* overload */;
	void __fastcall DisableGraphicHeader(void);
	void __fastcall WriteGraphic(int Number, int Width, int Height, void * Data)/* overload */;
	void __fastcall WriteGraphic(int Number, int Width, int Height, const WideString Data)/* overload */;
	void __fastcall PrintGraphic(int Width, int Height, void * Data)/* overload */;
	void __fastcall PrintGraphic(int Width, int Height, const WideString Data)/* overload */;
	void __fastcall EKLZActivate(void);
	void __fastcall EKLZActivationReport(void);
	void __fastcall EKLZDayReport(int DayNumber);
	void __fastcall EKLZReportByNum(bool IsFull, int AStartNum, int AEndNum);
	void __fastcall EKLZReportByDate(bool IsFull, System::TDateTime AStartDate, System::TDateTime AEndDate);
	void __fastcall EKLZDocByNum(int Number);
	void __fastcall EKLZControlByNum(int DayNumber);
	void __fastcall EKLZCloseArchive(void);
	void __fastcall EKLZQueryStatus(void);
	__property TMercConnState ConnState = {read=FConnState, nodefault};
	__property TMercEcrModel EcrModel = {read=FEcrModel, nodefault};
	__property int EcrVersion = {read=FEcrVersion, nodefault};
	__property int EcrSubVersion = {read=FEcrSubVersion, nodefault};
	__property int Generation = {read=FGeneration, nodefault};
	__property bool EKLZSupported = {read=FEKLZSupported, nodefault};
	__property TMercProtocol Protocol = {read=FProtocol, nodefault};
	__property int EcrStatus = {read=FEcrStatus, nodefault};
	__property int EcrStatusMask = {read=FEcrStatusMask, nodefault};
	__property int DevStatus = {read=FDevStatus, nodefault};
	__property int DevStatusMask = {read=FDevStatusMask, nodefault};
	__property TMercDocStatus DocStatus = {read=GetDocStatus, nodefault};
	__property TMercOperType CurrentOper = {read=GetCurrentOper, nodefault};
	__property System::Currency SaleSum = {read=FSaleSum};
	__property System::Currency BuyingSum = {read=FBuyingSum};
	__property WideString SerialNumber = {read=FSerialNumber};
	__property WideString RegNumber = {read=FRegNumber};
	__property WideString TaxPayerNumber = {read=FTaxPayerNumber};
	__property WideString HeaderLine1 = {read=FHeaderLine1};
	__property WideString HeaderLine2 = {read=FHeaderLine2};
	__property WideString HeaderLine3 = {read=FHeaderLine3};
	__property WideString HeaderLine4 = {read=FHeaderLine4};
	__property System::TDateTime StartDate = {read=FStartDate};
	__property System::TDateTime EndDate = {read=FEndDate};
	__property int StartNumber = {read=FStartNumber, nodefault};
	__property int EndNumber = {read=FEndNumber, nodefault};
	__property WideString ModelName = {read=FModelName};
	__property WideString Manufacturer = {read=FManufacturer};
	__property WideString FirmwareVersion = {read=FFirmwareVersion};
	__property WideString TaxName = {read=FTaxName};
	__property System::TDateTime TaxDate = {read=FTaxDate};
	__property int CounterCount = {read=FCounterCount, nodefault};
	__property int RewritesRemain = {read=FRewritesRemain, nodefault};
	__property int DaysRemain = {read=FDaysRemain, nodefault};
	__property int LastFiscalReport = {read=FLastFiscalReport, nodefault};
	__property int LastDayClosing = {read=FLastDayClosing, nodefault};
	__property int LastDocOper = {read=FLastDocOper, nodefault};
	__property int LastDocNumber = {read=FLastDocNumber, nodefault};
	__property int LastRecNumber = {read=FLastRecNumber, nodefault};
	__property int LastRepNumber = {read=FLastRepNumber, nodefault};
	__property TMercOperType LastDocType = {read=FLastDocType, nodefault};
	__property System::Currency LastDocSum = {read=FLastDocSum};
	__property System::Currency LastBuyingSum = {read=FLastBuyingSum};
	__property int EcrHour = {read=GetEcrHour, nodefault};
	__property int EcrMin = {read=GetEcrMin, nodefault};
	__property System::TDateTime ReportDate = {read=FReportDateTime};
	__property int ReportHour = {read=GetReportHour, nodefault};
	__property int ReportMin = {read=GetReportMin, nodefault};
	__property System::TDateTime DayDate = {read=FDayDateTime};
	__property int DayHour = {read=GetDayHour, nodefault};
	__property int DayMin = {read=GetDayMin, nodefault};
	__property System::TDateTime LastDocDate = {read=FLastDocDateTime};
	__property int LastDocHour = {read=GetLastDocHour, nodefault};
	__property int LastDocMin = {read=GetLastDocMin, nodefault};
	__property bool EKLZActivated = {read=FEKLZActivated, nodefault};
	__property TMercOperType EKLZOper = {read=FEKLZOper, nodefault};
	__property bool EKLZArchiving = {read=FEKLZArchiving, nodefault};
	__property bool EKLZReporting = {read=FEKLZReporting, nodefault};
	__property bool EKLZDayOpened = {read=FEKLZDayOpened, nodefault};
	__property bool EKLZFatalError = {read=FEKLZFatalError, nodefault};
	__property bool EKLZAttention = {read=FEKLZAttention, nodefault};
	__property int EKLZRest = {read=FEKLZRest, nodefault};
	__property int ErrCode = {read=FErrCode, nodefault};
	__property int ErrCodeEx = {read=FErrCodeEx, nodefault};
	__property WideString ErrMessage = {read=FErrMessage};
	__property int VersionNumber = {read=FVersionNumber, nodefault};
	__property int BuildNumber = {read=FBuildNumber, nodefault};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property int PortNum = {read=FPortNum, write=SetPortNum, default=1};
	__property int BaudRate = {read=FBaudRate, write=SetBaudRate, default=9600};
	__property WideString Password = {read=FPassword, write=SetPassword};
	__property int InternalTimeout = {read=FInternalTimeout, write=SetInternalTimeout, default=1000};
	__property int ExternalTimeout = {read=FExternalTimeout, write=SetExternalTimeout, default=30000};
	__property AnsiString Version = {read=FVersion, write=FStubStr};
	__property bool RetryOperation = {read=FRetryOperation, write=SetRetryOperation, default=0};
	__property TMercDataEvent OnDataSend = {read=FOnDataSend, write=FOnDataSend};
	__property TMercDataEvent OnDataReceive = {read=FOnDataReceive, write=FOnDataReceive};
	__property Classes::TNotifyEvent OnNoResponse = {read=FOnNoResponse, write=FOnNoResponse};
	__property Classes::TNotifyEvent OnPrinterError = {read=FOnPrinterError, write=FOnPrinterError};
	__property Classes::TNotifyEvent OnDisplayError = {read=FOnDisplayError, write=FOnDisplayError};
	__property Classes::TNotifyEvent OnStatusUpdate = {read=FOnStatusUpdate, write=FOnStatusUpdate};
	__property Classes::TNotifyEvent OnConnStateUpdate = {read=FOnConnStateUpdate, write=FOnConnStateUpdate};
	__property TMercCodingType CodingType = {read=FCodingType, nodefault};
	__property bool CancelException = {read=FCancelException, write=FCancelException, nodefault};
	__property bool MultiPassword = {read=FMultiPassword, nodefault};
	__property bool SpecialDecoding = {read=FSpecialDecoding, write=FSpecialDecoding, nodefault};
};


class DELPHICLASS TMercuryFPrtCtrl;
class PASCALIMPLEMENTATION TMercuryFPrtCtrl : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
private:
	TMercuryFPrt* FMercuryFPrt;
	Graphics::TGraphic* FImageNone;
	Graphics::TGraphic* FImageUnknown;
	Graphics::TGraphic* FImage114F;
	Graphics::TGraphic* FImage114F03;
	Graphics::TGraphic* FImageSystemF;
	Graphics::TGraphic* FImage118K;
	Graphics::TGraphic* FImage119K;
	Graphics::TGraphic* FImageMStar;
	unsigned FMainThreadId;
	bool FActive;
	int FBorderSize;
	bool FShowState;
	TMercDataEvent FOnDataSend;
	TMercDataEvent FOnDataReceive;
	Classes::TNotifyEvent FOnNoResponse;
	Classes::TNotifyEvent FOnPrinterError;
	Classes::TNotifyEvent FOnDisplayError;
	Classes::TNotifyEvent FOnStatusUpdate;
	Classes::TNotifyEvent FOnConnStateUpdate;
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(void *Message);
	MESSAGE void __fastcall WMMercDrawState(Messages::TMessage &Message);
	void __fastcall DrawConnState(TMercConnState AState);
	TMercConnState __fastcall GetConnState(void);
	TMercEcrModel __fastcall GetEcrModel(void);
	int __fastcall GetEcrVersion(void);
	int __fastcall GetEcrSubVersion(void);
	int __fastcall GetGeneration(void);
	bool __fastcall GetEKLZSupported(void);
	TMercProtocol __fastcall GetProtocol(void);
	int __fastcall GetEcrStatus(void);
	int __fastcall GetEcrStatusMask(void);
	int __fastcall GetDevStatus(void);
	int __fastcall GetDevStatusMask(void);
	TMercDocStatus __fastcall GetDocStatus(void);
	TMercOperType __fastcall GetCurrentOper(void);
	int __fastcall GetPortNum(void);
	int __fastcall GetBaudRate(void);
	WideString __fastcall GetPassword();
	int __fastcall GetInternalTimeout(void);
	int __fastcall GetExternalTimeout(void);
	System::Currency __fastcall GetSaleSum(void);
	System::Currency __fastcall GetBuyingSum(void);
	WideString __fastcall GetSerialNumber();
	WideString __fastcall GetRegNumber();
	WideString __fastcall GetTaxPayerNumber();
	WideString __fastcall GetHeaderLine1();
	WideString __fastcall GetHeaderLine2();
	WideString __fastcall GetHeaderLine3();
	WideString __fastcall GetHeaderLine4();
	System::TDateTime __fastcall GetStartDate(void);
	System::TDateTime __fastcall GetEndDate(void);
	int __fastcall GetStartNumber(void);
	int __fastcall GetEndNumber(void);
	WideString __fastcall GetModelName();
	WideString __fastcall GetManufacturer();
	WideString __fastcall GetFirmwareVersion();
	WideString __fastcall GetTaxName();
	System::TDateTime __fastcall GetTaxDate(void);
	int __fastcall GetCounterCount(void);
	int __fastcall GetRewritesRemain(void);
	int __fastcall GetDaysRemain(void);
	int __fastcall GetLastFiscalReport(void);
	int __fastcall GetLastDayClosing(void);
	int __fastcall GetLastDocOper(void);
	int __fastcall GetLastDocNumber(void);
	int __fastcall GetLastRecNumber(void);
	int __fastcall GetLastRepNumber(void);
	TMercOperType __fastcall GetLastDocType(void);
	System::Currency __fastcall GetLastDocSum(void);
	System::Currency __fastcall GetLastBuyingSum(void);
	int __fastcall GetEcrHour(void);
	int __fastcall GetEcrMin(void);
	System::TDateTime __fastcall GetReportDate(void);
	int __fastcall GetReportHour(void);
	int __fastcall GetReportMin(void);
	System::TDateTime __fastcall GetDayDate(void);
	int __fastcall GetDayHour(void);
	int __fastcall GetDayMin(void);
	System::TDateTime __fastcall GetLastDocDate(void);
	int __fastcall GetLastDocHour(void);
	int __fastcall GetLastDocMin(void);
	bool __fastcall GetEKLZActivated(void);
	TMercOperType __fastcall GetEKLZOper(void);
	bool __fastcall GetEKLZArchiving(void);
	bool __fastcall GetEKLZReporting(void);
	bool __fastcall GetEKLZDayOpened(void);
	bool __fastcall GetEKLZFatalError(void);
	bool __fastcall GetEKLZAttention(void);
	int __fastcall GetEKLZRest(void);
	int __fastcall GetErrCode(void);
	int __fastcall GetErrCodeEx(void);
	WideString __fastcall GetErrMessage();
	int __fastcall GetVersionNumber(void);
	int __fastcall GetBuildNumber(void);
	AnsiString __fastcall GetVersion();
	bool __fastcall GetRetryOperation(void);
	TMercCodingType __fastcall GetCodingType(void);
	bool __fastcall GetCancelException(void);
	bool __fastcall GetMultiPassword(void);
	void __fastcall SetRetryOperation(bool Value);
	void __fastcall SetVersion(const AnsiString Value);
	void __fastcall SetActive(bool Value);
	void __fastcall SetPortNum(int Value);
	void __fastcall SetBaudRate(int Value);
	void __fastcall SetPassword(const WideString Value);
	void __fastcall SetInternalTimeout(int Value);
	void __fastcall SetExternalTimeout(int Value);
	void __fastcall SetBorderSize(int Value);
	void __fastcall SetShowState(bool Value);
	void __fastcall SetCancelException(bool Value);
	
protected:
	DYNAMIC void __fastcall Click(void);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall DoDataSend(const void *Data, int DataSize);
	DYNAMIC void __fastcall DoDataReceive(const void *Data, int DataSize);
	DYNAMIC void __fastcall DoNoResponse(void);
	DYNAMIC void __fastcall DoPrinterError(void);
	DYNAMIC void __fastcall DoDisplayError(void);
	DYNAMIC void __fastcall DoStatusUpdate(void);
	DYNAMIC void __fastcall DoConnStateUpdate(void);
	
public:
	__fastcall virtual TMercuryFPrtCtrl(Classes::TComponent* AOwner);
	__fastcall virtual ~TMercuryFPrtCtrl(void);
	__property TMercuryFPrt* MercuryFPrt = {read=FMercuryFPrt};
	void __fastcall AddLicence(TMercLicenceType LicType, const WideString Licence);
	virtual void __fastcall AbortRequest(void);
	virtual void __fastcall TestConnection(void);
	virtual void __fastcall Open(void);
	virtual void __fastcall Close(bool ForceAbort);
	int __fastcall CheckEcrStatus(int Flag);
	int __fastcall CheckDevStatus(int Flag);
	void __fastcall OpenReceipt(TMercOperType Oper);
	void __fastcall AddReceiptItem(const WideString Desc, System::Currency Price, bool ItemIsTare, int Department, int Code, int Adjustment, int Quantity, int QuantityPrec, int TaxIndex, const WideString UnitName, int Flags);
	void __fastcall CancelReceipt(void);
	void __fastcall CloseReceipt(const WideString Account, TMercPayType PayType, System::Currency PayCash, System::Currency PayCashless, const WideString PayInfo, int CopiesNum, TMercOperInfo OperInfo);
	void __fastcall OpenCustomDoc(bool UseForm, TMercOperType Oper);
	void __fastcall CancelCustomDoc(void);
	void __fastcall CloseCustomDoc(TMercPayType PayType, int Flags, int HCopiesNum, int VCopiesNum, int VOrigOffset, int HCopyOffset, int VCopyOffset, int FiscalCopy);
	void __fastcall OpenFiscalDoc(TMercOperType Oper);
	void __fastcall CancelFiscalDoc(bool BufferOnly);
	void __fastcall PrintFiscalDocBuffer(void);
	void __fastcall CloseFiscalDoc(void);
	void __fastcall CopyFiscalDoc(void);
	void __fastcall AddSerialNumber(int Flags, int HOffset, int VOffset);
	void __fastcall AddHeaderLine(int LineNum, int Flags, int HOffset, int VOffset);
	void __fastcall AddDateTime(int Flags, int HOffset, int VOffset);
	void __fastcall AddOperInfo(TMercOperInfo OperInfo, int Flags, int HOffset, int VOffset);
	void __fastcall AddDocNumber(int Flags, int HOffset, int VOffset);
	void __fastcall AddReceiptNumber(int Flags, int HOffset, int VOffset);
	void __fastcall AddAccount(const WideString Account, int Flags, int HOffset, int VOffset);
	void __fastcall AddTaxPayerNumber(int Flags, int HOffset, int VOffset);
	void __fastcall AddItem(TMercItemType ItemType, System::Currency Price, bool ItemIsTare, int Department, int Code, int Adjustment, int Quantity, int QuantityPrec, int TaxIndex, const WideString UnitName, int Flags, int HOffset, int VOffset, int RightOffset);
	void __fastcall AddDocPercentAdj(int Value, int TaxIndex, int Flags, int HOffset, int VOffset, int RightOffset);
	void __fastcall AddDocAmountAdj(System::Currency Value, int TaxIndex, int Flags, int HOffset, int VOffset, int RightOffset);
	void __fastcall AddTotal(int Flags, int HOffset, int VOffset, int RightOffset);
	void __fastcall AddPay(TMercPayType PayType, System::Currency PayCash, System::Currency PayCashless, const WideString PayInfo, int Flags, int HOffset, int VOffset, int RightOffset);
	void __fastcall AddChange(int Flags, int HOffset, int VOffset, int RightOffset);
	void __fastcall AddTaxSum(int TaxIndex, int Flags, int HOffset, int VOffset, int RightOffset);
	void __fastcall AddFiscalSign(int Flags, int HOffset, int VOffset);
	void __fastcall AddEKLZData(int Flags, int HOffset, int VOffset);
	void __fastcall AddRegNumber(int Flags, int HOffset, int VOffset);
	void __fastcall AddGraphicHeader(int Flags, int HOffset, int VOffset);
	void __fastcall AddBarcode(int Mask1, int Mask2, int Mask3, int Mask4, int Mask5, bool DoubleDensity, int Flags, int HOffset, int VOffset);
	void __fastcall AddCustom(const WideString Text, int Flags, int HOffset, int VOffset);
	void __fastcall RepeatOperation(void);
	void __fastcall OpenDay(int OperNum, const WideString OperName, bool FullJournal, TMercProtocol AProtocol);
	int __fastcall XReport(int Flags);
	int __fastcall XReportByDep(int DepartNum, int Flags);
	int __fastcall XReportByOper(int OperNum, int Flags);
	int __fastcall ZReport(int Flags);
	int __fastcall PrintEKL(int Flags);
	void __fastcall ReprintDocument(void);
	int __fastcall FiscalRewrite(const WideString InspPswd, const WideString ARegNum, const WideString ATaxPayerNum, const WideString NewInspPswd);
	int __fastcall FiscalReportByNum(const WideString InspPswd, bool PrintFull, int AStartNum, int AEndNum);
	int __fastcall FiscalReportByDate(const WideString InspPswd, bool PrintFull, System::TDateTime AStartDate, System::TDateTime AEndDate);
	int __fastcall FiscalReportAll(const WideString InspPswd);
	void __fastcall FeedAndCut(int LineCount, bool CutAfterFeed);
	void __fastcall PrintNonFiscal(const WideString Data, bool OpenDoc, bool CloseDoc);
	void __fastcall ShowDisplay(const WideString Data, bool OpenMode, bool CloseMode);
	void __fastcall SetDisplayBaudRate(int ABaudRate);
	void __fastcall ExternalPulse(int Channel, int TimeOn, int TimeOff, int Count);
	void __fastcall QueryDevExStatus(void);
	void __fastcall PrintHeader(void);
	void __fastcall QueryFirmwareInfo(void);
	int __fastcall QueryTax(int Index);
	System::Currency __fastcall QueryCounter(int Index, bool NoRequest);
	void __fastcall QueryResourceInfo(bool PrintInfo);
	void __fastcall QueryLastDocInfo(void);
	WideString __fastcall QuerySerialNumber();
	WideString __fastcall QueryTaxPayerNumber();
	WideString __fastcall QueryRegNumber();
	WideString __fastcall QueryHeaderLine(int LineNum);
	WideString __fastcall QueryDepartName(int DepartNum);
	WideString __fastcall QueryTitle(int TitleNum);
	System::TDateTime __fastcall QueryEcrDateTime(void);
	int __fastcall QueryPrinterTimeout(void);
	int __fastcall QueryDisplayTimeout(void);
	int __fastcall QueryPrinterContrast(void);
	int __fastcall QueryLeading(void);
	bool __fastcall QueryHeaderAlignment(void);
	int __fastcall QueryOperNumber(void);
	WideString __fastcall QueryOperName(int OperNum);
	bool __fastcall QueryAutocut(void);
	bool __fastcall QueryEconomicMode(void);
	bool __fastcall QueryPaperJournal(void);
	bool __fastcall QueryFullJournal(void);
	bool __fastcall QueryParameterBool(int ParamCode);
	int __fastcall QueryParameterInt(int ParamCode);
	TMercEKLState __fastcall QueryEKLState(void);
	void __fastcall SetParameters(TMercProtocol AProtocol, int PrnTimeout);
	void __fastcall SetProtocol(TMercProtocol AProtocol);
	void __fastcall SetPrinterTimeout(int Timeout);
	void __fastcall SetDisplayTimeout(int Timeout);
	void __fastcall SetPrinterContrast(int Contrast);
	void __fastcall SetLeading(int Leading);
	void __fastcall SetCutterDisabled(bool Disabled);
	void __fastcall SetNarrowPaper(bool Narrow);
	void __fastcall SetHeaderAlignment(bool Aligned);
	void __fastcall SetAutocut(bool Autocut);
	void __fastcall SetEconomicMode(bool EconomicMode);
	void __fastcall SetPaperJournal(bool PaperJournal);
	void __fastcall SetFullJournal(bool FullJournal);
	void __fastcall SetParameterBool(int ParamCode, bool ParamValue);
	void __fastcall SetParameterInt(int ParamCode, int ParamValue);
	void __fastcall SetTax(int Index, const WideString ATaxName, int TaxRate);
	void __fastcall SetSerialNumber(const WideString Value);
	void __fastcall SetHeader(const WideString Line1, const WideString Line2, const WideString Line3, const WideString Line4);
	void __fastcall SetDepartName(int DepartNum, const WideString Value);
	void __fastcall SetTitle(int TitleNum, const WideString Value);
	void __fastcall SetOperPassword(int OperNum, const WideString OperName, const WideString OperPassword);
	void __fastcall SynchronizeEcrDateTime(void);
	void __fastcall EnableGraphicHeader(int Width, int Height, void * Data)/* overload */;
	void __fastcall EnableGraphicHeader(int Width, int Height, const WideString Data)/* overload */;
	void __fastcall DisableGraphicHeader(void);
	void __fastcall WriteGraphic(int Number, int Width, int Height, void * Data)/* overload */;
	void __fastcall WriteGraphic(int Number, int Width, int Height, const WideString Data)/* overload */;
	void __fastcall PrintGraphic(int Width, int Height, void * Data)/* overload */;
	void __fastcall PrintGraphic(int Width, int Height, const WideString Data)/* overload */;
	void __fastcall EKLZActivate(void);
	void __fastcall EKLZActivationReport(void);
	void __fastcall EKLZDayReport(int DayNumber);
	void __fastcall EKLZReportByNum(bool IsFull, int AStartNum, int AEndNum);
	void __fastcall EKLZReportByDate(bool IsFull, System::TDateTime AStartDate, System::TDateTime AEndDate);
	void __fastcall EKLZDocByNum(int Number);
	void __fastcall EKLZControlByNum(int Number);
	void __fastcall EKLZCloseArchive(void);
	void __fastcall EKLZQueryStatus(void);
	__property TMercConnState ConnState = {read=GetConnState, nodefault};
	__property TMercEcrModel EcrModel = {read=GetEcrModel, nodefault};
	__property int EcrVersion = {read=GetEcrVersion, nodefault};
	__property int EcrSubVersion = {read=GetEcrSubVersion, nodefault};
	__property int Generation = {read=GetGeneration, nodefault};
	__property bool EKLZSupported = {read=GetEKLZSupported, nodefault};
	__property TMercProtocol Protocol = {read=GetProtocol, nodefault};
	__property int EcrStatus = {read=GetEcrStatus, nodefault};
	__property int EcrStatusMask = {read=GetEcrStatusMask, nodefault};
	__property int DevStatus = {read=GetDevStatus, nodefault};
	__property int DevStatusMask = {read=GetDevStatusMask, nodefault};
	__property TMercDocStatus DocStatus = {read=GetDocStatus, nodefault};
	__property TMercOperType CurrentOper = {read=GetCurrentOper, nodefault};
	__property System::Currency SaleSum = {read=GetSaleSum};
	__property System::Currency BuyingSum = {read=GetBuyingSum};
	__property WideString SerialNumber = {read=GetSerialNumber};
	__property WideString RegNumber = {read=GetRegNumber};
	__property WideString TaxPayerNumber = {read=GetTaxPayerNumber};
	__property WideString HeaderLine1 = {read=GetHeaderLine1};
	__property WideString HeaderLine2 = {read=GetHeaderLine2};
	__property WideString HeaderLine3 = {read=GetHeaderLine3};
	__property WideString HeaderLine4 = {read=GetHeaderLine4};
	__property System::TDateTime StartDate = {read=GetStartDate};
	__property System::TDateTime EndDate = {read=GetEndDate};
	__property int StartNumber = {read=GetStartNumber, nodefault};
	__property int EndNumber = {read=GetEndNumber, nodefault};
	__property WideString ModelName = {read=GetModelName};
	__property WideString Manufacturer = {read=GetManufacturer};
	__property WideString FirmwareVersion = {read=GetFirmwareVersion};
	__property WideString TaxName = {read=GetTaxName};
	__property System::TDateTime TaxDate = {read=GetTaxDate};
	__property int CounterCount = {read=GetCounterCount, nodefault};
	__property int RewritesRemain = {read=GetRewritesRemain, nodefault};
	__property int DaysRemain = {read=GetDaysRemain, nodefault};
	__property int LastFiscalReport = {read=GetLastFiscalReport, nodefault};
	__property int LastDayClosing = {read=GetLastDayClosing, nodefault};
	__property int LastDocOper = {read=GetLastDocOper, nodefault};
	__property int LastDocNumber = {read=GetLastDocNumber, nodefault};
	__property int LastRecNumber = {read=GetLastRecNumber, nodefault};
	__property int LastRepNumber = {read=GetLastRepNumber, nodefault};
	__property TMercOperType LastDocType = {read=GetLastDocType, nodefault};
	__property System::Currency LastDocSum = {read=GetLastDocSum};
	__property System::Currency LastBuyingSum = {read=GetLastBuyingSum};
	__property int EcrHour = {read=GetEcrHour, nodefault};
	__property int EcrMin = {read=GetEcrMin, nodefault};
	__property System::TDateTime ReportDate = {read=GetReportDate};
	__property int ReportHour = {read=GetReportHour, nodefault};
	__property int ReportMin = {read=GetReportMin, nodefault};
	__property System::TDateTime DayDate = {read=GetDayDate};
	__property int DayHour = {read=GetDayHour, nodefault};
	__property int DayMin = {read=GetDayMin, nodefault};
	__property System::TDateTime LastDocDate = {read=GetLastDocDate};
	__property int LastDocHour = {read=GetLastDocHour, nodefault};
	__property int LastDocMin = {read=GetLastDocMin, nodefault};
	__property bool EKLZActivated = {read=GetEKLZActivated, nodefault};
	__property TMercOperType EKLZOper = {read=GetEKLZOper, nodefault};
	__property bool EKLZArchiving = {read=GetEKLZArchiving, nodefault};
	__property bool EKLZReporting = {read=GetEKLZReporting, nodefault};
	__property bool EKLZDayOpened = {read=GetEKLZDayOpened, nodefault};
	__property bool EKLZFatalError = {read=GetEKLZFatalError, nodefault};
	__property bool EKLZAttention = {read=GetEKLZAttention, nodefault};
	__property int EKLZRest = {read=GetEKLZRest, nodefault};
	__property int ErrCode = {read=GetErrCode, nodefault};
	__property int ErrCodeEx = {read=GetErrCodeEx, nodefault};
	__property WideString ErrMessage = {read=GetErrMessage};
	__property int VersionNumber = {read=GetVersionNumber, nodefault};
	__property int BuildNumber = {read=GetBuildNumber, nodefault};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property int PortNum = {read=GetPortNum, write=SetPortNum, default=1};
	__property int BaudRate = {read=GetBaudRate, write=SetBaudRate, default=9600};
	__property WideString Password = {read=GetPassword, write=SetPassword};
	__property int InternalTimeout = {read=GetInternalTimeout, write=SetInternalTimeout, default=1000};
	__property int ExternalTimeout = {read=GetExternalTimeout, write=SetExternalTimeout, default=30000};
	__property AnsiString Version = {read=GetVersion, write=SetVersion};
	__property bool RetryOperation = {read=GetRetryOperation, write=SetRetryOperation, default=0};
	__property int BorderSize = {read=FBorderSize, write=SetBorderSize, default=1};
	__property bool ShowState = {read=FShowState, write=SetShowState, default=1};
	__property TMercDataEvent OnDataSend = {read=FOnDataSend, write=FOnDataSend};
	__property TMercDataEvent OnDataReceive = {read=FOnDataReceive, write=FOnDataReceive};
	__property Classes::TNotifyEvent OnNoResponse = {read=FOnNoResponse, write=FOnNoResponse};
	__property Classes::TNotifyEvent OnPrinterError = {read=FOnPrinterError, write=FOnPrinterError};
	__property Classes::TNotifyEvent OnDisplayError = {read=FOnDisplayError, write=FOnDisplayError};
	__property Classes::TNotifyEvent OnStatusUpdate = {read=FOnStatusUpdate, write=FOnStatusUpdate};
	__property Classes::TNotifyEvent OnConnStateUpdate = {read=FOnConnStateUpdate, write=FOnConnStateUpdate};
	__property TMercCodingType CodingType = {read=GetCodingType, nodefault};
	__property bool CancelException = {read=GetCancelException, write=SetCancelException, nodefault};
	__property bool MultiPassword = {read=GetMultiPassword, nodefault};
	__property Anchors  = {default=3};
	__property Align  = {default=0};
	__property BevelEdges  = {default=15};
	__property BevelInner  = {index=0, default=2};
	__property BevelKind  = {default=0};
	__property BevelOuter  = {index=1, default=1};
	__property DragCursor  = {default=-12};
	__property DragMode  = {default=0};
	__property DragKind  = {default=0};
	__property Constraints ;
	__property Ctl3D ;
	__property Enabled  = {default=1};
	__property Height  = {default=155};
	__property ParentCtl3D  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=0};
	__property Width  = {default=155};
	__property OnClick ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TMercuryFPrtCtrl(HWND ParentWindow) : Controls::TCustomControl(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word MERC_VERSION = 0x107;
static const Shortint MERC_BUILD = 0x65;
static const Shortint MERC_S_DAY_OPENED = 0x1;
static const Shortint MERC_SBIT_DAY_OPENED = 0x0;
static const Shortint MERC_S_BUFFER_ATTENTION = 0x2;
static const Shortint MERC_SBIT_BUFFER_ATTENTION = 0x1;
static const Shortint MERC_S_FISCAL_ECR = 0x4;
static const Shortint MERC_SBIT_FISCAL_ECR = 0x2;
static const Shortint MERC_S_FISCAL_ATTENTION = 0x8;
static const Shortint MERC_SBIT_FISCAL_ATTENTION = 0x3;
static const Shortint MERC_S_FISCAL_FULL = 0x10;
static const Shortint MERC_SBIT_FISCAL_FULL = 0x4;
static const Shortint MERC_S_DOC_COPY = 0x20;
static const Shortint MERC_SBIT_DOC_COPY = 0x5;
static const Shortint MERC_S_NARROW_PAPER = 0x40;
static const Shortint MERC_SBIT_NARROW_PAPER = 0x6;
static const Byte MERC_S_GRAPHIC_HEADER = 0x80;
static const Shortint MERC_SBIT_GRAPHIC_HEADER = 0x7;
static const Shortint MERC_DS_CASH_DRAWER = 0x1;
static const Shortint MERC_DSBIT_CASH_DRAWER = 0x0;
static const Shortint MERC_DS_OFFLINE = 0x2;
static const Shortint MERC_DSBIT_OFFLINE = 0x1;
static const Shortint MERC_DS_OPENED_COVER = 0x4;
static const Shortint MERC_DSBIT_OPENED_COVER = 0x2;
static const Shortint MERC_DS_PAPER_FEEDING = 0x8;
static const Shortint MERC_DSBIT_PAPER_FEEDING = 0x3;
static const Shortint MERC_DS_STOP_ON_PAPER_OUT = 0x10;
static const Shortint MERC_DSBIT_STOP_ON_PAPER_OUT = 0x4;
static const Shortint MERC_DS_PRINTER_ERROR = 0x20;
static const Shortint MERC_DSBIT_PRINTER_ERROR = 0x5;
static const Shortint MERC_DS_MECHANICAL_ERROR = 0x40;
static const Shortint MERC_DSBIT_MECHANICAL_ERROR = 0x6;
static const Byte MERC_DS_CUTTER_ERROR = 0x80;
static const Shortint MERC_DSBIT_CUTTER_ERROR = 0x7;
static const Word MERC_DS_FATAL_ERROR = 0x100;
static const Shortint MERC_DSBIT_FATAL_ERROR = 0x8;
static const Word MERC_DS_OVERHEATING = 0x200;
static const Shortint MERC_DSBIT_OVERHEATING = 0x9;
static const Word MERC_DS_JOURNAL_ATTENTION = 0x400;
static const Shortint MERC_DSBIT_JOURNAL_ATTENTION = 0xa;
static const Word MERC_DS_RECEIPT_ATTENTION = 0x800;
static const Shortint MERC_DSBIT_RECEIPT_ATTENTION = 0xb;
static const Word MERC_DS_JOURNAL_OUT = 0x1000;
static const Shortint MERC_DSBIT_JOURNAL_OUT = 0xc;
static const Word MERC_DS_RECEIPT_OUT = 0x2000;
static const Shortint MERC_DSBIT_RECEIPT_OUT = 0xd;
static const Word MERC_DS_SLIP_SELECTED = 0x4000;
static const Shortint MERC_DSBIT_SLIP_SELECTED = 0xe;
static const Word MERC_DS_SLIP_WAITING = 0x8000;
static const Shortint MERC_DSBIT_SLIP_WAITING = 0xf;
static const int MERC_DS_NO_SLIP_IN = 0x10000;
static const Shortint MERC_DSBIT_NO_SLIP_IN = 0x10;
static const int MERC_DS_NO_SLIP_OUT = 0x20000;
static const Shortint MERC_DSBIT_NO_SLIP_OUT = 0x11;
static const int MERC_DS_DISPLAY_READY = 0x40000;
static const Shortint MERC_DSBIT_DISPLAY_READY = 0x12;
static const int MERC_DS_SERVICE_MODE = 0x80000;
static const Shortint MERC_DSBIT_SERVICE_MODE = 0x13;
static const int MERC_DS_PRINTER_SELECTED = 0x100000;
static const Shortint MERC_DSBIT_PRINTER_SELECTED = 0x14;
static const int MERC_DS_CUT_DISABLED = 0x200000;
static const Shortint MERC_DSBIT_CUT_DISABLED = 0x15;
static const int MERC_DS_PAPER_OUT = 0x400000;
static const Shortint MERC_DSBIT_PAPER_OUT = 0x16;
static const int MERC_DS_PRINTER_READY = 0x800000;
static const Shortint MERC_DSBIT_PRINTER_READY = 0x17;
static const int MERC_DS_PRINTER_BUSY = 0x1000000;
static const Shortint MERC_DSBIT_PRINTER_BUSY = 0x18;
static const int MERC_DS_FACTORY_SETTINGS = 0x2000000;
static const Shortint MERC_DSBIT_FACTORY_SETTINGS = 0x19;
static const int MERC_DS_HARDWARE_RESET = 0x4000000;
static const Shortint MERC_DSBIT_HARDWARE_RESET = 0x1a;
static const int MERC_DS_HEAD_LIFTED = 0x8000000;
static const Shortint MERC_DSBIT_HEAD_LIFTED = 0x1b;
static const int MERC_DS_JRN_HEAD_LIFTED = 0x10000000;
static const Shortint MERC_DSBIT_JRN_HEAD_LIFTED = 0x1c;
static const int MERC_DS_EX_STATUS = 0x40000000;
static const Shortint MERC_DSBIT_EX_STATUS = 0x1e;
static const Shortint MERC_DOCF_PRINT_RECEIPT = 0x1;
static const Shortint MERC_DOCF_REVERSE = 0x2;
static const Shortint MERC_DOCF_BOTTOM_REJ = 0x4;
static const Shortint MERC_PROPF_FONT_14X30 = 0x2;
static const Shortint MERC_PROPF_FONT_10X30 = 0x3;
static const Shortint MERC_PROPF_FONT_9X9 = 0x4;
static const Shortint MERC_PROPF_DOUBLE_WIDTH = 0x8;
static const Shortint MERC_PROPF_DOUBLE_HEIGHT = 0x10;
static const Shortint MERC_PROPF_UNDERLINE = 0x20;
static const Shortint MERC_PROPF_NO_ORIGINAL = 0x40;
static const Byte MERC_PROPF_NO_COPY = 0x80;
static const Word MERC_PROPF_JOURNAL_LINE1 = 0x100;
static const Word MERC_PROPF_JOURNAL_LINE2 = 0x200;
static const Word MERC_PROPF_NO_JOURNAL = 0x400;
static const Word MERC_PROPF_VOIDED = 0x800;
static const Shortint MERC_REPF_NO_ZEROES = 0x1;
static const Shortint MERC_REPF_ACCUMULATE_OPER = 0x2;
static const Shortint MERC_REPF_ACCUMULATE_DEP = 0x4;
static const Shortint MERC_BRE_INVALID_NUMBER = 0x1;
static const Shortint MERC_BRE_INVALID_HEX = 0x2;
static const Shortint MERC_BRE_INVALID_DATE = 0x3;
static const Shortint MERC_BRE_INVALID_TIME = 0x4;
static const Shortint MERC_BRE_PACKET_FORMAT = 0x5;
static const Shortint MERC_BRE_UNEXPECTED_DATA = 0x6;
static const Shortint MERC_BRE_INVALID_BCC = 0x7;
static const Shortint MERC_BRE_INVALID_DOC_TYPE = 0x8;
static const Shortint MERC_BRE_PACKET_SIZE = 0x9;
static const Shortint MERC_IAE_INVALID_PORT_NUM = 0x1;
static const Shortint MERC_IAE_INVALID_BAUD_RATE = 0x2;
static const Shortint MERC_IAE_UNSUPPORTED_BAUD_RATE = 0x3;
static const Shortint MERC_IAE_INVALID_TIMEOUT = 0x4;
static const Shortint MERC_IAE_INVALID_PROTOCOL = 0x5;
static const Shortint MERC_IAE_INVALID_OPER_NUM = 0x6;
static const Shortint MERC_IAE_INVALID_LIC_TYPE = 0x7;
static const Shortint MERC_IAE_INVALID_OPER_TYPE = 0x8;
static const Shortint MERC_IAE_UNSUPPORTED_OPER_TYPE = 0x9;
static const Shortint MERC_IAE_INVALID_COPIES_NUM = 0xa;
static const Shortint MERC_IAE_INVALID_OFFSET = 0xb;
static const Shortint MERC_IAE_INVALID_PROP_OFFSET = 0xc;
static const Shortint MERC_IAE_INVALID_FISCAL_HOFFSET = 0xd;
static const Shortint MERC_IAE_INVALID_FISCAL_VOFFSET = 0xe;
static const Shortint MERC_IAE_INVALID_FISCAL_COPY = 0xf;
static const Shortint MERC_IAE_INVALID_OPER_INFO = 0x10;
static const Shortint MERC_IAE_INVALID_PAY_TYPE = 0x11;
static const Shortint MERC_IAE_UNSUPPORTED_PAY_TYPE = 0x12;
static const Shortint MERC_IAE_FORBIDDEN_PAY_TYPE = 0x13;
static const Shortint MERC_IAE_INVALID_PAY_SUM = 0x14;
static const Shortint MERC_IAE_INVALID_ITEM_SUM = 0x15;
static const Shortint MERC_IAE_INVALID_DEPARTMENT = 0x16;
static const Shortint MERC_IAE_INVALID_ITEM_CODE = 0x17;
static const Shortint MERC_IAE_INVALID_ADJUSTMENT = 0x18;
static const Shortint MERC_IAE_INVALID_QUANTITY = 0x19;
static const Shortint MERC_IAE_INVALID_QUAN_PREC = 0x1a;
static const Shortint MERC_IAE_INVALID_TAX_INDEX = 0x1b;
static const Shortint MERC_IAE_TOTAL_OVERFLOW = 0x1c;
static const Shortint MERC_IAE_INVALID_HEADER_LINE = 0x1d;
static const Shortint MERC_IAE_INVALID_ITEM_TYPE = 0x1e;
static const Shortint MERC_IAE_UNSUPPORTED_ITEM_TYPE = 0x1f;
static const Shortint MERC_IAE_FORBIDDEN_ITEM_TYPE = 0x20;
static const Shortint MERC_IAE_INVALID_DATE = 0x21;
static const Shortint MERC_IAE_INVALID_CHANNEL = 0x22;
static const Shortint MERC_IAE_INVALID_PULSE_TIME = 0x23;
static const Shortint MERC_IAE_INVALID_PULSE_COUNT = 0x24;
static const Shortint MERC_IAE_INVALID_LINE_COUNT = 0x25;
static const Shortint MERC_IAE_UNSUPPORTED_FEED = 0x26;
static const Shortint MERC_IAE_INVALID_TITLE = 0x27;
static const Shortint MERC_IAE_INVALID_SERIAL_NUM = 0x28;
static const Shortint MERC_IAE_INVALID_TAX_RATE = 0x29;
static const Shortint MERC_IAE_INVALID_COUNTER = 0x2a;
static const Shortint MERC_IAE_UNSUPPORTED_COUNTER = 0x2b;
static const Shortint MERC_IAE_INVALID_FISCAL_NUM = 0x2c;
static const Shortint MERC_IAE_INVALID_CONTRAST = 0x2d;
static const Shortint MERC_IAE_INVALID_LEADING = 0x2e;
static const Shortint MERC_IAE_INVALID_LEFT_SPACE = 0x2f;
static const Shortint MERC_IAE_INVALID_HEADER_WIDTH = 0x30;
static const Shortint MERC_IAE_INVALID_HEADER_HEIGHT = 0x31;
static const Shortint MERC_IAE_INVALID_HEADER_DATA = 0x32;
static const Shortint MERC_IAE_INVALID_ACCOUNT = 0x33;
static const Shortint MERC_IAE_INVALID_EKLZ_VOFFSET = 0x34;
static const Shortint MERC_IAE_INVALID_GRAPHIC_NUM = 0x35;
static const Shortint MERC_IAE_INVALID_PARAM_CODE = 0x36;
static const Shortint MERC_IAE_INVALID_ROUNDUP_MODE = 0x37;
static const Shortint MERC_IAE_INVALID_ROUNDUP_UNIT = 0x38;
static const Shortint MERC_IAE_INVALID_FISC_INTERVAL = 0x39;
static const Shortint MERC_IAE_INVALID_I2C_FREQUENCY = 0x3a;
static const Shortint MERC_IAE_INVALID_REP_TOTAL_MODE = 0x3b;
static const Shortint MERC_IAE_INVALID_CUTTER_COUNT = 0x3c;
static const Shortint MERC_PT_SERIAL_NUMBER = 0x0;
static const Shortint MERC_PT_HEADER_LINE1 = 0x1;
static const Shortint MERC_PT_HEADER_LINE2 = 0x2;
static const Shortint MERC_PT_HEADER_LINE3 = 0x3;
static const Shortint MERC_PT_HEADER_LINE4 = 0x4;
static const Shortint MERC_PT_DATE_TIME = 0x5;
static const Shortint MERC_PT_OPER_INFO = 0x6;
static const Shortint MERC_PT_DOC_NUMBER = 0x7;
static const Shortint MERC_PT_RECEIPT_NUMBER = 0x8;
static const Shortint MERC_PT_ACCOUNT = 0x9;
static const Shortint MERC_PT_TAX_PAYER_NUMBER = 0xa;
static const Shortint MERC_PT_ITEM = 0xb;
static const Shortint MERC_PT_TOTAL = 0xc;
static const Shortint MERC_PT_PAY = 0xd;
static const Shortint MERC_PT_CHANGE = 0xe;
static const Shortint MERC_PT_TAX0 = 0xf;
static const Shortint MERC_PT_TAX1 = 0x10;
static const Shortint MERC_PT_TAX2 = 0x11;
static const Shortint MERC_PT_TAX3 = 0x12;
static const Shortint MERC_PT_TAX4 = 0x13;
static const Shortint MERC_PT_FISCAL_SIGN = 0x14;
static const Shortint MERC_PT_ADJUSTMENT = 0x15;
static const Shortint MERC_PT_EKLZ_DATA = 0x16;
static const Shortint MERC_PT_GRAPHIC_HEADER = 0x17;
static const Shortint MERC_PT_REG_NUMBER = 0x18;
static const Shortint MERC_PT_BARCODE = 0x62;
static const Shortint MERC_PT_CUSTOM = 0x63;
static const Shortint MERC_ERR_ECR_FISCAL = 0x1;
static const Shortint MERC_ERR_ECR_OPENED_SESSION = 0x2;
static const Shortint MERC_ERR_ECR_OUT_OF_FISCAL = 0x3;
static const Shortint MERC_ERR_ECR_FIELD_TOO_LONG = 0x4;
static const Shortint MERC_ERR_ECR_BAD_FIELD_FORMAT = 0x5;
static const Shortint MERC_ERR_ECR_TIMER_READ_ERROR = 0x6;
static const Shortint MERC_ERR_ECR_INVALID_DATE = 0x7;
static const Shortint MERC_ERR_ECR_INVALID_TIME = 0x8;
static const Shortint MERC_ERR_ECR_EARLY_DATE = 0x9;
static const Shortint MERC_ERR_ECR_USER_BREAK = 0xa;
static const Shortint MERC_ERR_ECR_FORBIDDEN = 0xb;
static const Shortint MERC_ERR_ECR_CLOSED_SESSION = 0xc;
static const Shortint MERC_ERR_ECR_EMPTY_JOURNAL = 0xfffffff3;
static const Shortint MERC_ERR_ECR_NO_OPERATOR = 0xd;
static const Shortint MERC_ERR_ECR_INPUT_OVERFLOW = 0xe;
static const Shortint MERC_ERR_ECR_FISCAL_WRITE_ERROR = 0xf;
static const Shortint MERC_ERR_ECR_TIMER_SET_ERROR = 0x10;
static const Shortint MERC_ERR_ECR_BAD_INSPECTOR_PSWD = 0x11;
static const Shortint MERC_ERR_ECR_BAD_CONN_PSWD = 0x12;
static const Shortint MERC_ERR_ECR_REG_OVERFLOW = 0x13;
static const Shortint MERC_ERR_ECR_NO_FISCAL = 0x14;
static const Shortint MERC_ERR_ECR_FIELD_OVERFLOW = 0x15;
static const Shortint MERC_ERR_ECR_FISCAL_READ_ERROR = 0x16;
static const Shortint MERC_ERR_ECR_COUNTER_OVERFLOW = 0x17;
static const Shortint MERC_ERR_ECR_ZERO_FIELD = 0x18;
static const Shortint MERC_ERR_ECR_BAD_CMD_FORMAT = 0x19;
static const Shortint MERC_ERR_ECR_EARLY_DOCUMENT = 0x1a;
static const Shortint MERC_ERR_ECR_JOURNAL_OVERFLOW = 0x1b;
static const Shortint MERC_ERR_ECR_BAD_PROPERTIES = 0x1c;
static const Shortint MERC_ERR_ECR_INVALID_CMD = 0x1d;
static const Shortint MERC_ERR_ECR_INVALID_BCC = 0x1e;
static const Shortint MERC_ERR_ECR_EMPTY_FISCAL = 0x1f;
static const Shortint MERC_ERR_ECR_DOC_CANCELED = 0x21;
static const Shortint MERC_ERR_ECR_EMPTY_RESPONSE = 0x24;
static const Shortint MERC_ERR_ECR_SERVICE_ABSENT = 0x25;
static const Shortint MERC_ERR_ECR_NO_SERVICE = 0x27;
static const Shortint MERC_ERR_ECR_BAD_JOURNAL = 0x28;
static const Shortint MERC_ERR_ECR_PROP_DUPLICATION = 0x29;
static const Shortint MERC_ERR_ECR_BAD_STATE = 0x2a;
static const Shortint MERC_ERR_ECR_MEMORY_ERROR = 0x2b;
static const Shortint MERC_ERR_ECR_FM_INITIALIZED = 0x2c;
static const Shortint MERC_ERR_ECR_DISPLAY_TIMEOUT = 0x2d;
static const Shortint MERC_ERR_ECR_FLASH_ERROR = 0x2e;
static const Shortint MERC_ERR_ECR_NO_RECORDS = 0x2f;
static const Shortint MERC_ERR_EKLZ_NO_CONNECTION = 0x30;
static const Shortint MERC_ERR_EKLZ_BAD_COMMAND = 0x31;
static const Shortint MERC_ERR_EKLZ_BAD_STATE = 0x32;
static const Shortint MERC_ERR_EKLZ_FAILURE = 0x33;
static const Shortint MERC_ERR_EKLZ_ENCODER_FAILURE = 0x34;
static const Shortint MERC_ERR_EKLZ_TIME_OVERFLOW = 0x35;
static const Shortint MERC_ERR_EKLZ_FULL = 0x36;
static const Shortint MERC_ERR_EKLZ_BAD_DATE_TIME = 0x37;
static const Shortint MERC_ERR_EKLZ_NO_DATA = 0x38;
static const Shortint MERC_ERR_EKLZ_COUNTER_OVERFLOW = 0x39;
static const Shortint MERC_ERR_EKLZ_ENCODER_ERROR = 0x42;
static const Shortint MERC_ERR_EKLZ_PROTOCOL_ERROR = 0x46;
static const Shortint MERC_ERR_EKLZ_BUFFER_OVERFLOW = 0x47;
static const Shortint MERC_ERR_EKLZ_BAD_CHECKSUM = 0x48;
static const Shortint MERC_ERR_EKLZ_ANOTHER_ECR = 0x49;
static const Shortint MERC_ERR_EKLZ_NOT_ACTIVATED = 0x4a;
static const Shortint MERC_ERR_EKLZ_FATAL_ERROR = 0x4b;
static const Shortint MERC_ERR_EKLZ_NO_ACTIVATIONS = 0x4c;
static const Shortint MERC_ERR_EKLZ_ACTIVATED = 0x4d;
static const Shortint MERC_ERR_EKLZ_DEPART_OVERFLOW = 0x4e;
static const Shortint MERC_ERR_EKLZ_NO_ARCHIVE = 0x4f;
static const Shortint MERC_ERR_EKLZ_FM_CONFLICT = 0x50;
static const Shortint MERC_ERR_ECR_CNT_QUANTITY_ADD = 0x70;
static const Shortint MERC_ERR_ECR_CNT_QUANTITY_SUB = 0x71;
static const Shortint MERC_ERR_ECR_CNT_VOID = 0x72;
static const Shortint MERC_ERR_ECR_CNT_DAY_VOID = 0x73;
static const Shortint MERC_ERR_ECR_CNT_DAY_SALE = 0x74;
static const Shortint MERC_ERR_ECR_CNT_DAY_CASH_ADD = 0x75;
static const Shortint MERC_ERR_ECR_CNT_DAY_PAY_CREDIT = 0x76;
static const Shortint MERC_ERR_ECR_CNT_DAY_PAY_CARD = 0x77;
static const Shortint MERC_ERR_ECR_CNT_DAY_CASH_SUB = 0x78;
static const Shortint MERC_ERR_ECR_CNT_DAY_RFD_CREDIT = 0x79;
static const Shortint MERC_ERR_ECR_CNT_TOTAL_ADD = 0x7a;
static const Shortint MERC_ERR_ECR_CNT_TOTAL_SUB = 0x7b;
static const Shortint MERC_ERR_ECR_CNT_TOTAL_MUL = 0x7c;
static const Shortint MERC_ERR_ECR_CNT_TOTAL_DIS = 0x7d;
static const Shortint MERC_ERR_ECR_CNT_DPT_TOTAL_DIS = 0x7e;
static const Shortint MERC_ERR_ECR_CNT_TARE_DIS = 0x7f;
static const Byte MERC_ERR_ECR_CNT_DISCOUNT = 0x80;
static const Byte MERC_ERR_ECR_CNT_TAX_DIS = 0x81;
static const Byte MERC_ERR_ECR_CNT_NOTAX_DIS = 0x82;
static const Byte MERC_ERR_ECR_CNT_TOTAL_SUR = 0x83;
static const Byte MERC_ERR_ECR_CNT_DPT_TOTAL_SUR = 0x84;
static const Byte MERC_ERR_ECR_CNT_TARE_SUR = 0x85;
static const Byte MERC_ERR_ECR_CNT_SURCHARGE = 0x86;
static const Byte MERC_ERR_ECR_CNT_TAX_SUR = 0x87;
static const Byte MERC_ERR_ECR_CNT_NOTAX_SUR = 0x88;
static const Byte MERC_ERR_ECR_CNT_DPT_TOTAL = 0x89;
static const Byte MERC_ERR_ECR_CNT_TARE_TOTAL = 0x8a;
static const Byte MERC_ERR_ECR_CNT_TAX_TOTAL = 0x8b;
static const Byte MERC_ERR_ECR_CNT_NOTAX_TOTAL = 0x8c;
static const Byte MERC_ERR_ECR_CNT_TOTAL_VOID_DIS = 0x8d;
static const Byte MERC_ERR_ECR_CNT_DPT_VOID_DIS = 0x8e;
static const Byte MERC_ERR_ECR_CNT_TARE_VOID_DIS = 0x8f;
static const Byte MERC_ERR_ECR_CNT_VOID_DISCOUNT = 0x90;
static const Byte MERC_ERR_ECR_CNT_TAX_VOID_DIS = 0x91;
static const Byte MERC_ERR_ECR_CNT_NOTAX_VOID_DIS = 0x92;
static const Byte MERC_ERR_ECR_CNT_TOTAL_VOID_SUR = 0x93;
static const Byte MERC_ERR_ECR_CNT_DPT_VOID_SUR = 0x94;
static const Byte MERC_ERR_ECR_CNT_TARE_VOID_SUR = 0x95;
static const Byte MERC_ERR_ECR_CNT_VOID_SURCHARGE = 0x96;
static const Byte MERC_ERR_ECR_CNT_TAX_VOID_SUR = 0x97;
static const Byte MERC_ERR_ECR_CNT_NOTAX_VOID_SUR = 0x98;
static const Byte MERC_ERR_ECR_INVALID_PAYMENT = 0x99;
static const Byte MERC_ERR_ECR_CNT_PAYMENT = 0x9a;
static const Byte MERC_ERR_ECR_CASHLESS_OVERFLOW = 0x9b;
static const Byte MERC_ERR_ECR_FISC_INTERVAL_OVER = 0x9c;
static const Byte MERC_ERR_ECR_EKL_OVERFLOW = 0xa0;
static const Shortint MERC_ERR_LIC_BAD_KEY = 0x1;
static const Shortint MERC_ERR_LIC_EXPIRED = 0x2;
static const Shortint MERC_ERR_LIC_ECR = 0x3;
static const Shortint MERC_SUCCESS = 0x0;
static const Shortint MERC_ERR_REQUEST_ABORTED = 0xffffffff;
static const Shortint MERC_ERR_CONN_OPENED = 0x1;
static const Shortint MERC_ERR_CONN_CLOSED = 0x2;
static const Shortint MERC_ERR_NO_RESPONSE = 0x3;
static const Shortint MERC_ERR_UNKNOWN_DEVICE = 0x4;
static const Shortint MERC_ERR_NO_CONVERSION = 0x5;
static const Shortint MERC_ERR_UNSUPPORTED = 0x6;
static const Shortint MERC_ERR_DOC_OVERFLOW = 0x7;
static const Shortint MERC_ERR_NO_DOCUMENT = 0x8;
static const Shortint MERC_ERR_DOC_OPENED = 0x9;
static const Shortint MERC_ERR_DOC_FORBIDDEN = 0xa;
static const Shortint MERC_ERR_DOC_FORBIDDEN_VERSION = 0xb;
static const Shortint MERC_ERR_DUPLICATION = 0xc;
static const Shortint MERC_ERR_NO_PROPERTY = 0xd;
static const Shortint MERC_ERR_INVALID_ARG = 0xe;
static const Shortint MERC_ERR_BAD_RESPONSE = 0xf;
static const Shortint MERC_ERR_OUT_OF_MEMORY = 0x10;
static const Shortint MERC_ERR_OS_ERROR = 0x11;
static const Shortint MERC_ERR_ECR_ERROR = 0x12;
static const Shortint MERC_ERR_MERC_NO_LICENCE = 0x13;
static const Shortint MERC_ERR_OPERATION_CANCELLED = 0x14;
static const Word MERC_ERR_UNKNOWN = 0x3e7;
static const Shortint MERC_PARAM_PRN_TIMEOUT = 0x1;
static const Shortint MERC_PARAM_DSP_TIMEOUT = 0x2;
static const Shortint MERC_PARAM_PRN_CONTRAST = 0x3;
static const Shortint MERC_PARAM_LEADING = 0x4;
static const Shortint MERC_PARAM_HEADER_ALIGN = 0x5;
static const Shortint MERC_PARAM_AUTOCUT = 0x6;
static const Shortint MERC_PARAM_ECONOMIC_MODE = 0x7;
static const Shortint MERC_PARAM_PAPER_JOURNAL = 0x8;
static const Shortint MERC_PARAM_FULL_JOURNAL = 0x9;
static const Shortint MERC_PARAM_AUTO_CASHOUT = 0xa;
static const Shortint MERC_PARAM_DECIMAL_POINT = 0xb;
static const Shortint MERC_PARAM_ROUNDUP_MODE = 0xc;
static const Shortint MERC_PARAM_ROUNDUP_UNIT = 0xd;
static const Shortint MERC_PARAM_RESTART_COUNT = 0xe;
static const Shortint MERC_PARAM_AUTOHEADER = 0xf;
static const Shortint MERC_PARAM_AUTOHEADER_LINE1 = 0x10;
static const Shortint MERC_PARAM_AUTOHEADER_LINE2 = 0x11;
static const Shortint MERC_PARAM_AUTOHEADER_LINE3 = 0x12;
static const Shortint MERC_PARAM_AUTOHEADER_LINE4 = 0x13;
static const Shortint MERC_PARAM_HEADER_PRINTED_LINE1 = 0x14;
static const Shortint MERC_PARAM_HEADER_PRINTED_LINE2 = 0x15;
static const Shortint MERC_PARAM_HEADER_PRINTED_LINE3 = 0x16;
static const Shortint MERC_PARAM_HEADER_PRINTED_LINE4 = 0x17;
static const Shortint MERC_PARAM_CURRENT_DOC_NUMBER = 0x18;
static const Shortint MERC_PARAM_CURRENT_REC_NUMBER = 0x19;
static const Shortint MERC_PARAM_PAPER_AUTOLOAD = 0x1a;
static const Shortint MERC_PARAM_FISCAL_TIME_INTERVAL = 0x1b;
static const Shortint MERC_PARAM_NON_FISCAL_HEADER = 0x1c;
static const Shortint MERC_PARAM_DAY_ELAPSED = 0x1d;
static const Shortint MERC_PARAM_EKL_ENABLED = 0x1e;
static const Shortint MERC_PARAM_I2C_FREQUENCY = 0x1f;
static const Shortint MERC_PARAM_EKLZ_AUTOTESTING = 0x20;
static const Shortint MERC_PARAM_REPORT_TOTAL_MODE = 0x21;
static const Shortint MERC_PARAM_DOCUMENT_REPRINTING = 0x22;
static const Shortint MERC_PARAM_CUTTER_TESTING = 0x23;
static const Shortint MERC_RTM_NONE = 0x0;
static const Shortint MERC_RTM_ALL_RECORDS = 0x1;
static const Shortint MERC_RTM_LAST_REGISTRATION = 0x2;
static const Word MERC_DEF_INTERNAL_TIMEOUT = 0x3e8;
static const Word MERC_DEF_EXTERNAL_TIMEOUT = 0x7530;
static const Byte MERC_DEF_WIDTH = 0x9b;
static const Byte MERC_DEF_HEIGHT = 0x9b;
static const Byte MERC_REC_ITEM_COUNT = 0xc4;
static const Word MERC_DOC_PROP_COUNT = 0x12c;
static const Word WM_MERC_DRAW_STATE = 0x400;
extern PACKAGE void __fastcall Register(void);
extern PACKAGE Word __fastcall AZEncoder(Word C);
extern PACKAGE Word __fastcall AZDecoder(Word C);

}	/* namespace Mercuryfprt */
using namespace Mercuryfprt;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MercuryFPrt
