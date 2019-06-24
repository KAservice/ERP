//---------------------------------------------------------------------------

#ifndef UGurZakRestH
#define UGurZakRestH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFormaGurZakRest : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TDBGrid *DBGrid1;
        TLabel *Label1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TFormaGurZakRest(TComponent* Owner);



        void UpdateForm(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaGurZakRest *FormaGurZakRest;
//---------------------------------------------------------------------------
#endif
