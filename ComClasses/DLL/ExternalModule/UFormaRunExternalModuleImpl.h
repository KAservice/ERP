//---------------------------------------------------------------------------

#ifndef UFormaRunExternalModuleImplH
#define UFormaRunExternalModuleImplH
//---------------------------------------------------------------------------
#include "UFormaRunExternalModule.h"
#include "IFormaRunExternalModule.h"
//---------------------------------------------------------------------------

class __declspec(uuid("{4CD5D3CF-FF2A-4EE2-B58B-7704FD09955C}")) TFormaRunExternalModuleImpl : public IFormaRunExternalModule, IkanCallBack
{
public:
   TFormaRunExternalModuleImpl();
   ~TFormaRunExternalModuleImpl();


   bool flDeleteObject;
   void DeleteImpl(void);

	TFormaRunExternalModule * Object;
	int NumRefs;


//IkanUnknown
	virtual int kanQueryInterface(REFIID id_interface, void ** ppv);
	virtual int kanAddRef(void);
	virtual int kanRelease(void);



//IMainInterface
   virtual int  get_CodeError(void);
   virtual void set_CodeError(int CodeError);
   virtual UnicodeString  get_TextError(void);
   virtual void set_TextError(UnicodeString  TextError);
   virtual int Init(IkanUnknown * i_main_object, IkanUnknown * i_owner_object);
   virtual int Done(void);

      //IkanCallBack
   virtual int kanExternalEvent(IkanUnknown * pUnk, REFIID id_object,int type_event, int number_procedure_end);


//IFormaRunExternalModule
	virtual void ClearModule(void);
	virtual void LoadModule(void);
	virtual void ExecuteModule(void);

	virtual void SetIntegerVariables(UnicodeString name_variables, int value);
	virtual void SetStringVariables(UnicodeString name_variables, UnicodeString value);
	virtual void SetInt64Variables(UnicodeString name_variables, __int64 value);
	virtual void SetDateTimeVariables(UnicodeString name_variables, TDateTime value);

	virtual void ListAddElement(UnicodeString id1, UnicodeString id2, UnicodeString id3, int int_value1);


	virtual void AddClassesInScript_SheetEditor(void);
	virtual void AddClassesInScript_ReportGrid(void);
	virtual void AddClassesInScript_DMQueryRead(void);

    virtual void OpenDesignerFastReport(void);
    //свойства

	virtual int  get_TypeTable(void);
	virtual void set_TypeTable(int TypeTable);

	virtual __int64  get_IdModule(void);
	virtual void set_IdModule(__int64 IdModule);

};

#define CLSID_TFormaRunExternalModuleImpl __uuidof(TFormaRunExternalModuleImpl)
#endif
