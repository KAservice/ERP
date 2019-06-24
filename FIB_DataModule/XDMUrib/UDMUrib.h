//---------------------------------------------------------------------------

#ifndef UDMUribH
#define UDMUribH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//-------------------------------------------------
#include "UDMSprTypePrice.h"
#include "UDMSprPrice.h"
#include "UDMXTableIsm.h"
#include "UDMXDataOut.h"
#include "UDMXFieldBase.h"
#include "UDMXTableBase.h"
#include "UDMSprObmenTypeDoc.h"
#include "UDMSprObmenSklad.h"
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class TDMUrib : public TDataModule
{
__published:	// IDE-managed Components
        TIBQuery *Doc;
        TIBQuery *IBQ;
        TIBTransaction *IBTr1;
        TIBQuery *DocAll;
        TIBStringField *DocAllTDOC;
        TIntegerField *DocAllIDSKLDOC;
        TIBQuery *DocT;
        void __fastcall DataModuleCreate(TObject *Sender);
        void __fastcall DataModuleDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDMUrib(TComponent* Owner);

        //-----------------------
        int IdBase;
        AnsiString NameBase;
        AnsiString PrefiksBase;

        AnsiString NameUser;
        AnsiString PasswordUser;



        //заполение таблицы выходных данных ----------------------------
        TDMXTableIsm *TableIsm;
        TDMXDataOut * DataOut;
        TDMSprObmenTypeDoc * DMTypeDoc;
        TDMSprObmenSklad  * DMSprObmenSklad;

        int StartIDTableIsm;

        void AddDocInDataTable(void);
        void AddSprInDataTable(void);

        void CreateDataOutTable(int id_base);
        bool CheckDocForTypeDoc(String type_doc);
        bool CheckDocForSklad(int id_sklad);


        bool CheckGALLDOC(void);
        bool CheckDPER(void);
        bool CheckDPERT(void);
        bool CheckDCHK(void);
        bool CheckDCHKT(void);



};
//---------------------------------------------------------------------------
extern PACKAGE TDMUrib *DMUrib;
//---------------------------------------------------------------------------
#endif
