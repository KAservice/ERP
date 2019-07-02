//---------------------------------------------------------------------------

#ifndef UScriptDMQueryReadH
#define UScriptDMQueryReadH
//---------------------------------------------------------------------------
#include "UDMQueryRead.h"
#include "fs_ibasic.hpp"
#include "IDMFibConnection.h"
//---------------------------------------------------------------------------
class TScriptDMQueryRead : public TObject
{
private:

public:
	TScriptDMQueryRead();

	IDMFibConnection * DM_Connection;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	TDMQueryRead * DM;
	AnsiString TextError;

	void AddClassesInScript(TfsScript * fs_script);

	Variant __fastcall CallMetod_NewObject(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_DeleteObject(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_GetRekvisit(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_First(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_Next(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_Eof(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_SetSQLText(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_ExecQuery(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_Close(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_GetTextError(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

};
#endif
