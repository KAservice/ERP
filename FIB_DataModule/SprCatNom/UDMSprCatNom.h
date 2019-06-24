//---------------------------------------------------------------------------

#ifndef UDMSprCatNomH
#define UDMSprCatNomH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBQuery.hpp>
//---------------------------------------------------------------------------
class TDMSprCatNom : public TDataModule
{
__published:	// IDE-managed Components
        TIBQuery *Table;
        TIBTransaction *IBTr;
        TIBDataSet *Element;
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
        TIntegerField *ElementID_CATNOM;
        TIntegerField *ElementIDNOM_CATNOM;
        TIBStringField *ElementNAME_CATNOM;
        TIntegerField *ElementKOL_CATNOM;
        TIBStringField *ElementNAMENOM;
        TIntegerField *TableID_CATNOM;
        TIntegerField *TableKOL_CATNOM;
        TIBStringField *TableNAME_CATNOM;
        TIntegerField *TableRECNO;
        TIBStringField *ElementGID_SCATNOM;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall ElementCalcFields(TDataSet *DataSet);
        void __fastcall TableCalcFields(TDataSet *DataSet);
        void __fastcall ElementNewRecord(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprCatNom(TComponent* Owner);

        void OpenTable(void);
        int OpenElement(int Id);
        void NewElement(void);
        void SaveElement(void);
        void DeleteElement(int Id);

        bool Error;
        String TextError;

};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprCatNom *DMSprCatNom;
//---------------------------------------------------------------------------
#endif
