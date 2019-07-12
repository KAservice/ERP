#define MESSAGE_END_DLL WM_USER+1
//---------------------------------------------------------------------------

#ifndef UFormaRunExternalModuleH
#define UFormaRunExternalModuleH
//---------------------------------------------------------------------------
#include "UScriptReportGrid.h"
#include "UScriptDMQueryRead.h"
#include "UScriptSheetEditor.h"
#include "IDMFibConnection.h"
#include "IFiskReg.h"
#include "IFormaViborOborud.h"
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
#include "frxExportRTF.hpp"
#include "frxExportXLS.hpp"
#include "frxExportImage.hpp"
#include "frxExportMail.hpp"
#include "frxExportODF.hpp"
#include "frxExportText.hpp"
#include "frxExportXML.hpp"

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
	TTimer *Timer1;
	TfrxFIBComponents *frxFIBComponents1;
	TfrxXLSExport *frxXLSExport1;
	TfrxRTFExport *frxRTFExport1;
	TfrxJPEGExport *frxJPEGExport1;
	TfrxTIFFExport *frxTIFFExport1;
	TfrxBMPExport *frxBMPExport1;
	TfrxMailExport *frxMailExport1;
	TfrxODSExport *frxODSExport1;
	TfrxODTExport *frxODTExport1;
	TfrxGIFExport *frxGIFExport1;
	TMemo *Memo1;
	TPanel *Panel1;
	TPanel *Panel2;
	TButton *Button1;
	TfrxSimpleTextExport *frxSimpleTextExport1;
	TfrxJPEGExport *frxJPEGExport2;
	TfrxXMLExport *frxXMLExport1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall frxReport1ClosePreview(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall frxUserDataSet1GetValue(const UnicodeString VarName, Variant &Value);
	Variant __fastcall frxReport1UserFunction(const UnicodeString MethodName, Variant &Params);


private:	// User declarations


	bool ExecPriv, InsertPriv, EditPriv, DeletePriv;

	IFiskReg * FR;
	bool ConnectFR;
	bool CreateObjectFR (void);
	bool DeleteObjectFR (void);
	void AddFunctionFRInFastReport(void);
	bool FR_Error;

	IFormaViborOborud *FormaViborOborud;
	void OpenFormViborOborud(void);
	void __fastcall EndViborOborud(void);


	enum  {ER_NoRekv,ER_ViborFR} EditRekvisit;

	__int64 IdOborud;


	bool SetParameterCheckInDoc(__int64 id_doc);
	int GetParameterCheckInDoc(__int64 id_doc);



    void InitKasVariant(TkasVariant * kv);

public:		// User declarations
	__fastcall TFormaRunExternalModule(TComponent* Owner);

		typedef  void (__closure * TFunctionDeleteImplType)(void);
		TFunctionDeleteImplType FunctionDeleteImpl; //функция удаления реализации интерфейса
		bool flDeleteImpl;   //надо ли удалять реализацию при удалении текущего модуля

		IDMFibConnection * DM_Connection;
		IkanCom *InterfaceGlobalCom;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //интерфейс класса реализации
		GUID ClsIdImpl;				 //GUID класса реализации

		//из этой формы открыта другая для выбора
		//обработка события выбора в другой форме (которая была открыта из этой для выбора чего-то)
		int ExternalEvent(IkanUnknown * pUnk,   //интерфейс на дочерний объект (форму в которой производится выбор)
									REFIID id_object,      //тип дочернего объекта
									int type_event,     //тип события в дочернем объекте
									int number_procedure_end  //номер процедуры в род. форме, обрабатывающей событие выбора
									);


		//IMainInterface

		int CodeError;
		UnicodeString TextError;

		bool Init(void);
		int  Done(void);

	UnicodeString FileNameModule;
	int TypeModule;	//		1 script_SpreadSheet
					//		2 script_Grid
					//		3 FastReport
					//      4 DLL
					//		5 fastreport с оборудованием

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

	void AddMyGlobalFunctionInFastReport(void);


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
