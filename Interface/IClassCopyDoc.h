#ifndef UIClassCopyDocH
#define UIClassCopyDocH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
class __declspec(uuid(Global_IID_IClassCopyDoc)) IClassCopyDoc : public IMainInterface
{
public:
   virtual bool CreateNewCopyDoc(__int64 id_doc, UnicodeString type_doc, UnicodeString type_new_doc, bool fl_save_doc, bool fl_open_form_doc, int param1, int param2, int param3)=0;
   virtual __int64 CreateNewDocNaOsn(__int64 id_doc, UnicodeString type_doc, UnicodeString type_new_doc,bool fl_save_doc, bool fl_open_form_doc,int param1, int param2, int param3)=0;
};
#define IID_IClassCopyDoc __uuidof(IClassCopyDoc)
#endif
