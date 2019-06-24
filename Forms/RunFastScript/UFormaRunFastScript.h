//---------------------------------------------------------------------------

#ifndef UFormaRunFastScriptH
#define UFormaRunFastScriptH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "fs_iinterpreter.hpp"
#include "fs_icpp.hpp"
#include "fs_ibasic.hpp"
#include "fs_ijs.hpp"
#include "fs_ipascal.hpp"
#include "fs_iclassesrtti.hpp"
#include "fs_iformsrtti.hpp"
//---------------------------------------------------------------------------
class TFormaRunFastScript : public TForm
{
__published:	// IDE-managed Components
	TfsScript *fsScript1;
	TLabel *FileNameScriptLabel;
	TfsCPP *fsCPP1;
	TfsPascal *fsPascal1;
	TfsJScript *fsJScript1;
	TfsBasic *fsBasic1;
	TfsFormsRTTI *fsFormsRTTI1;
	TfsClassesRTTI *fsClassesRTTI1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaRunFastScript(TComponent* Owner);

	AnsiString FileNameScript;

	void ClearScript(void);
	void RunScript(void);

Variant __fastcall ObrabotchikCreateFormSheetEditor(System::TObject* Instance,
										 TMetaClass* ClassType,
										  const AnsiString MethodName,
										   Variant &Params);
	

};
//---------------------------------------------------------------------------
extern PACKAGE TFormaRunFastScript *FormaRunFastScript;
//---------------------------------------------------------------------------
#endif
