#ifndef UIFormaSpiskaSprInetCatalogH
#define UIFormaSpiskaSprInetCatalogH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMSprInetCatalog.h"
class __declspec(uuid(Global_IID_IFormaSpiskaSprInetCatalog)) IFormaSpiskaSprInetCatalog : public IMainInterface
{
public:
   __property IDMSprInetCatalog * DM = {read = get_DM , write = set_DM};
   virtual IDMSprInetCatalog * get_DM(void)=0;
   virtual void set_DM(IDMSprInetCatalog * DM)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property UnicodeString TextHeader = {read = get_TextHeader , write = set_TextHeader};
   virtual UnicodeString get_TextHeader(void)=0;
   virtual void set_TextHeader(UnicodeString TextHeader)=0;

   virtual void UpdateForm(void)=0;
};
#define IID_IFormaSpiskaSprInetCatalog __uuidof(IFormaSpiskaSprInetCatalog)
#endif
