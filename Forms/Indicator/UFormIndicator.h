//---------------------------------------------------------------------------

#ifndef UFormIndicatorH
#define UFormIndicatorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormIndicator : public TForm
{
__published:	// IDE-managed Components
        TProgressBar *ProgressBar1;
        TLabel *LabelInfo;
private:	// User declarations
public:		// User declarations
        __fastcall TFormIndicator(TComponent* Owner);

        int Max;
        int Step;
        void Start(void);
        void StepIt(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormIndicator *FormIndicator;
//---------------------------------------------------------------------------
#endif
