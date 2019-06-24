//---------------------------------------------------------------------------

#ifndef USprOKEIH
#define USprOKEIH
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
class TDMSprOKEI : public TDataModule
{
__published:	// IDE-managed Components
        TIBQuery *Table;
        TIBDataSet *Element;
        TIBTransaction *IBTr;
        TDataSource *DataSourceTable;
        TDataSource *DataSourceElement;
        TIntegerField *TableIDOKEI;
        TIBStringField *TableNAMEOKEI;
        TIntegerField *TableCODEOKEI;
        TIntegerField *TableRECNO;
        void __fastcall DataModuleDestroy(TObject *Sender);
        void __fastcall TableCalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TDMSprOKEI(TComponent* Owner);

        void OpenTable();
        int  OpenElement(int Id);  //возвращает количество элементов
        void NewElement();
        void SaveElement(void);
        void DeleteElement(int Id);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMSprOKEI *DMSprOKEI;
//---------------------------------------------------------------------------
#endif
