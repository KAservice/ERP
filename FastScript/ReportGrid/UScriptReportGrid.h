//---------------------------------------------------------------------------

#ifndef UScriptReportGridH
#define UScriptReportGridH
//---------------------------------------------------------------------------
#include "fs_ibasic.hpp"
#include "UFormaReportGrid.h"
//----------------------------------------------------------------------------
class TScriptReportGrid : public TObject
{
private:

public:
	TScriptReportGrid();

	IDMFibConnection * DM_Connection;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	TFormaReportGrid * ReportGrid;

	void AddClassesInScript(TfsScript * fs_script);

	Variant __fastcall CallMetod_NewObject(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_DeleteObject(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_SetTextQuery(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_AddColumn(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_CreateSeries(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_AddDataGroups(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
	Variant __fastcall CallMetod_OpenReport(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);

};
//-----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
