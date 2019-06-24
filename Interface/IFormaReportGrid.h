#ifndef UIFormaReportGridH
#define UIFormaReportGridH
#include "IMainInterface.h"
class __declspec(uuid("{7B50B26A-4A67-4435-84E8-79A8A34EE612}")) IFormaReportGrid : public IMainInterface
{
public:
   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   virtual void OpenReport(void)=0;
   virtual void SetTextQuery(AnsiString zapros)=0;
   virtual void AddColumn(AnsiString field_name,AnsiString caption,int width,int group_index,bool group_sum,AnsiString format_group_sum,bool footer_sum,AnsiString format_footer_sum)=0;
   virtual void CreateSeries(AnsiString name_field, AnsiString display_text)=0;
   virtual void AddDataGroups(AnsiString name_field, AnsiString display_text)=0;
   virtual void SetCaptionReport(AnsiString text)=0;
   virtual void SetFontColorContentTecColumn(int style)=0;
};
#define IID_IFormaReportGrid __uuidof(IFormaReportGrid)
#endif
