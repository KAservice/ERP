//---------------------------------------------------------------------------

#ifndef UScriptDMDocRealRoznH
#define UScriptDMDocRealRoznH
//---------------------------------------------------------------------------
#include "fs_ibasic.hpp"
#include "UDMDocRealRozn.h"
//---------------------------------------------------------------------------
class TScriptDMDocRealRozn : public TObject
{
private:

public:
	TScriptDMDocRealRozn();

	IDMFibConnection * DM_Connection;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	TDMDocRealRozn * DM;

	void AddClassesInScript(TfsScript * fs_script);

	Variant __fastcall CallMetod_DocAllGetRekvisit(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

	Variant __fastcall CallMetod_DocGetRekvisit(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

	Variant __fastcall CallMetod_DocTGetRekvisit(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

	Variant __fastcall CallMetod_PayGetRekvisit(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

	Variant __fastcall CallMetod_DocTFirst(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

	Variant __fastcall CallMetod_DocTNext(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

	Variant __fastcall CallMetod_DocTEof(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

	Variant __fastcall CallMetod_PayFirst(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

	Variant __fastcall CallMetod_PayNext(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

	Variant __fastcall CallMetod_PayEof(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
};
//-----------------------------------------------------------------------------

#endif
