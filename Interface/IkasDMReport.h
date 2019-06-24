#ifndef IkasDMReportH
#define IkasDMReportH

#include <guiddef.h>
#include <IkasDataModule.h>
#include <DB.hpp>



class __declspec(uuid("{CEFF95DB-76B3-4047-8B80-72360DEFEF19}")) IkasDMReport : public IkasDataModule
{
public:

  virtual	void SetSQL(UnicodeString zapros)=0;

  virtual	bool SetAsStringValueField(UnicodeString name_field, UnicodeString value)=0;
  virtual	bool SetAsDateTmeValueField(UnicodeString name_field, TDateTime value)=0;

  virtual	UnicodeString GetAsStringValueField(UnicodeString name_field)=0;
  virtual	TDateTime GetAsDateTmeValueField(UnicodeString name_field)=0;


  virtual	bool SetAsStringValueParameter(UnicodeString name_parameter, UnicodeString value)=0;
  virtual	bool SetAsDateTmeValueParameter(UnicodeString name_parameter, TDateTime value)=0;

  virtual	bool RunReport(void)=0;
  virtual	bool UpdateReport(void)=0;

  __property TDataSource * DataSourceTable = {read = get_DataSourceTable , write = set_DataSourceTable};
   virtual TDataSource * get_DataSourceTable(void)=0;
   virtual void set_DataSourceTable(TDataSource * DataSourceTable)=0;

};
#define IID_IkasDMReport __uuidof(IkasDMReport)







#endif
