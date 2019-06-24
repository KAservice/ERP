
#ifndef IFormaRunExternalModuleH
#define IFormaRunExternalModuleH
//---------------------------------------------------------------------------
#include "GlobalInterface.h"
#include "IMainInterface.h"
//----------------------------------------------------------------------------




//---------------------------------------------------------------------------
class __declspec(uuid("{E0876217-94D8-4E6A-A9BC-F13348BB9DBC}")) IFormaRunExternalModule : public IMainInterface
{
public:


//IFormaRunExternalModule
	virtual void ClearModule(void)=0;
	virtual void LoadModule(void)=0;
	virtual void ExecuteModule(void)=0;

	virtual void SetIntegerVariables(UnicodeString name_variables, int value)=0;
	virtual void SetStringVariables(UnicodeString name_variables, UnicodeString value)=0;
	virtual void SetInt64Variables(UnicodeString name_variables, __int64 value)=0;
	virtual void SetDateTimeVariables(UnicodeString name_variables, TDateTime value)=0;

	virtual void ListAddElement(UnicodeString id1, UnicodeString id2, UnicodeString id3, int int_value1)=0;


	virtual void AddClassesInScript_SheetEditor(void)=0;
	virtual void AddClassesInScript_ReportGrid(void)=0;
	virtual void AddClassesInScript_DMQueryRead(void)=0;

	virtual void OpenDesignerFastReport(void)=0;

	virtual int  get_TypeTable(void)=0;
	virtual void set_TypeTable(int TypeTable)=0;

	virtual __int64  get_IdModule(void)=0;
	virtual void set_IdModule(__int64 IdModule)=0;

//	TScriptSheetEditor * ScriptSheetEditor;
//	TScriptReportGrid * ScriptReportGrid;
//	TScriptDMQueryRead * ScriptDMQueryRead;
//	TScriptDMDocRealRozn * ScriptDMDocRealRozn;

	__property int TypeTable = {read = get_TypeTable,
												 write = set_TypeTable};
//	1 - модуль объекта
//  2 - внешний модуль из списка внешних модулей

	__property __int64 IdModule = {read = get_IdModule,
												 write = set_IdModule};


};

#define IID_IFormaRunExternalModule __uuidof(IFormaRunExternalModule)
#endif
