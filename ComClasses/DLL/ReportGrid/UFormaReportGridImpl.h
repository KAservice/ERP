#ifndef UFormaReportGridImplH
#define UFormaReportGridImplH
#include "IFormaReportGrid.h"
#include "UFormaReportGrid.h"
//---------------------------------------------------------------
class __declspec(uuid("{104842C7-411B-4CC9-8C35-9FF1F448D02A}")) TFormaReportGridImpl : public IFormaReportGrid, IkanCallBack
{
public:
   TFormaReportGridImpl();
   ~TFormaReportGridImpl();
   TFormaReportGrid * Object;
   int NumRefs;
   bool flDeleteObject;
   void DeleteImpl(void);

   //IUnknown
   virtual int kanQueryInterface(REFIID id_interface,void ** ppv);
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

//IFormaReportGrid
   virtual bool get_Vibor(void);
   virtual void set_Vibor(bool Vibor);

   virtual int get_NumberProcVibor(void);
   virtual void set_NumberProcVibor(int NumberProcVibor);

   virtual void OpenReport(void);
   virtual void SetTextQuery(AnsiString zapros);
   virtual void AddColumn(AnsiString field_name,AnsiString caption,int width,int group_index,bool group_sum,AnsiString format_group_sum,bool footer_sum,AnsiString format_footer_sum);
   virtual void CreateSeries(AnsiString name_field, AnsiString display_text);
   virtual void AddDataGroups(AnsiString name_field, AnsiString display_text);
   virtual void SetCaptionReport(AnsiString text);
   virtual void SetFontColorContentTecColumn(int style);
};
#define CLSID_TFormaReportGridImpl __uuidof(TFormaReportGridImpl)
#endif
