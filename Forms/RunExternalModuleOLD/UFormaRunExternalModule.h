#define MESSAGE_END_DLL WM_USER+1
//---------------------------------------------------------------------------

#ifndef UFormaRunExternalModuleH
#define UFormaRunExternalModuleH
//---------------------------------------------------------------------------
#include "UScriptReportGrid.h"
#include "UScriptDMQueryRead.h"
#include "UScriptSheetEditor.h"
#include "UScriptDMDocRealRozn.h"
#include "IDMFibConnection.h"
//----------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "fs_ibasic.hpp"
#include "fs_iclassesrtti.hpp"
#include "fs_icpp.hpp"
#include "fs_iformsrtti.hpp"
#include "fs_iinterpreter.hpp"
#include "fs_ijs.hpp"
#include "fs_ipascal.hpp"
#include "frxClass.hpp"
#include "frxDesgn.hpp"
#include "cxButtons.hpp"
#include "cxLookAndFeelPainters.hpp"
#include <Menus.hpp>
#include "frxBarcode.hpp"
#include "frxChart.hpp"
#include "frxChBox.hpp"
#include "frxCross.hpp"
#include "frxCrypt.hpp"
#include "frxDBSet.hpp"
#include "frxDCtrl.hpp"
#include "frxGradient.hpp"
#include "frxGZip.hpp"
#include "frxOLE.hpp"
#include "frxRich.hpp"

#include "frxExportPDF.hpp"
#include "fs_ichartrtti.hpp"
#include "fs_idialogsrtti.hpp"
#include "fs_iextctrlsrtti.hpp"
#include "fs_igraphicsrtti.hpp"
#include "fs_iinirtti.hpp"
#include "fs_imenusrtti.hpp"
#include <ExtCtrls.hpp>
#include "frxFIBComponents.hpp"

//---------------------------------------------------------------------------
class TFormaRunExternalModule : public TForm
{
__published:	// IDE-managed Components
	TfsScript *fsScript1;
	TfsCPP *fsCPP1;
	TfsPascal *fsPascal1;
	TfsJScript *fsJScript1;
	TfsBasic *fsBasic1;
	TfsFormsRTTI *fsFormsRTTI1;
	TfsClassesRTTI *fsClassesRTTI1;
	TLabel *FileNameModuleLabel;
	TfrxReport *frxReport1;
	TfrxDesigner *frxDesigner1;
	TfrxBarCodeObject *frxBarCodeObject1;
	TfrxOLEObject *frxOLEObject1;
	TfrxRichObject *frxRichObject1;
	TfrxCrossObject *frxCrossObject1;
	TfrxCheckBoxObject *frxCheckBoxObject1;
	TfrxGradientObject *frxGradientObject1;
	TfrxDialogControls *frxDialogControls1;
	TfrxGZipCompressor *frxGZipCompressor1;
	TfrxDBDataset *frxDBDataset1;
	TfrxCrypt *frxCrypt1;
	TfrxChartObject *frxChartObject1;
	TfrxUserDataSet *frxUserDataSet1;
	TfrxPDFExport *frxPDFExport1;
	TfsGraphicsRTTI *fsGraphicsRTTI1;
	TfsExtCtrlsRTTI *fsExtCtrlsRTTI1;
	TfsDialogsRTTI *fsDialogsRTTI1;
	TfsMenusRTTI *fsMenusRTTI1;
	TfsIniRTTI *fsIniRTTI1;
	TfsChartRTTI *fsChartRTTI1;
	TButton *Button1;
	TTimer *Timer1;
	TfrxFIBComponents *frxFIBComponents1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall frxReport1ClosePreview(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall frxUserDataSet1GetValue(const UnicodeString VarName, Variant &Value);

private:	// User declarations




public:		// User declarations
	__fastcall TFormaRunExternalModule(TComponent* Owner);

	IDMFibConnection * DM_Connection;
	bool Init(void);
	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;


	UnicodeString FileNameModule;
	int TypeModule;	//		1 script_SpreadSheet
					//		2 script_Grid
					//		3 FastReport
					//      4 DLL

	int Residence;	 // 0- file
					 // 1- BLOB

	int TypeTable;  //	1 - модуль объекта
					//  2 - внешний модуль из списка внешних модулей
	__int64   IdModule;


	void ClearModule(void);
	void LoadModule(void);
	void LoadExtModule(__int64 id);
	void LoadExtModuleObject(__int64 id);
	//добавляем переменные в отчет
	void ExecuteModule(void);

	void RunScript(void);
	void OpenFastReport(void);


	void SetIntegerVariables(UnicodeString name_variables, int value);
	void SetStringVariables(UnicodeString name_variables, UnicodeString value);
	void SetInt64Variables(UnicodeString name_variables, __int64 value);
	void SetDateTimeVariables(UnicodeString name_variables, TDateTime value);

	TList * List;
	struct TElementList
		{
		UnicodeString Id1;
		UnicodeString Id2;
		UnicodeString Id3;
		int IntValue1;
		};

	void ListNew(void);
	void ListDelete(void);
	void ListAddElement(UnicodeString id1, UnicodeString id2, UnicodeString id3, int int_value1);


	void DeleteAllModuleClassesScript(void);

   	TScriptSheetEditor * ScriptSheetEditor;
	void AddClassesInScript_SheetEditor(void);

	TScriptReportGrid * ScriptReportGrid;
	void AddClassesInScript_ReportGrid(void);

	TScriptDMQueryRead * ScriptDMQueryRead;
	void AddClassesInScript_DMQueryRead(void);

   	TScriptDMDocRealRozn * ScriptDMDocRealRozn;
	void AddClassesInScript_DMDocRealRozn(void);

	void RunDllModule(void);
	HINSTANCE dllIn;

	typedef __fastcall void (__closure * TEventEndType)( void); //тип завершения работы с библиотекой

	typedef bool (__import  DllInitPluginType(HANDLE app_handle,
											Ibase::TISC_DB_HANDLE db_handle,
											HANDLE handle_form_ext_module));
	typedef void (__import * DllDonePluginType(void));
	typedef char * (__import  DllGetTextErrorType(void));

	DllInitPluginType * DllInitPlugin;
	DllDonePluginType * DllDonePlugin;
	DllGetTextErrorType * DllGetTextError;

	BEGIN_MESSAGE_MAP
                MESSAGE_HANDLER(MESSAGE_END_DLL, TMessage,EndDLL)
	END_MESSAGE_MAP(TComponent)
	void __fastcall EndDLL(TMessage&Message);


	Variant __fastcall CallMetod_DestroyForm(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const UnicodeString MethodName,
										   Variant &Params);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaRunExternalModule *FormaRunExternalModule;
//---------------------------------------------------------------------------
#endif
