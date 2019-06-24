//---------------------------------------------------------------------------

#ifndef UFormaSetNachValuesH
#define UFormaSetNachValuesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include <DB.hpp>
#include "FIBQuery.hpp"
#include "pFIBQuery.hpp"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormaSetNachValues : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *NachValueGenEdit;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TButton *ButtonSetValueGen;
	TEdit *NachCodeNomEdit;
	TEdit *NachCodeEdEdit;
	TEdit *NachCodeDiscountCardEdit;
	TButton *ButtonNachCodeNom;
	TButton *ButtonNachCodeEd;
	TButton *ButtonNachCodeDiscountCard;
	TLabel *Label6;
	TpFIBDataSet *TableGenerators;
	TpFIBTransaction *pFIBTran;
	TpFIBQuery *QueryUpdate;
	TpFIBTransaction *TrUpdate;
	TLabel *Label5;
	TLabel *Label7;
	TpFIBQuery *Query;
	TButton *ButtonSetNulGen;
	TButton *ButtonCheckNullGen;
	TButton *Button1;
	TSaveDialog *SaveDialog1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonSetValueGenClick(TObject *Sender);
	void __fastcall ButtonNachCodeNomClick(TObject *Sender);
	void __fastcall ButtonNachCodeEdClick(TObject *Sender);
	void __fastcall ButtonNachCodeDiscountCardClick(TObject *Sender);
	void __fastcall ButtonSetNulGenClick(TObject *Sender);
	void __fastcall ButtonCheckNullGenClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormaSetNachValues(TComponent* Owner);

	UnicodeString UserName;
	UnicodeString PasswordUser;
	UnicodeString ConnectString;

	void UpdateForm(void);
	
};
//---------------------------------------------------------------------------
extern PACKAGE TFormaSetNachValues *FormaSetNachValues;
//---------------------------------------------------------------------------
#endif
