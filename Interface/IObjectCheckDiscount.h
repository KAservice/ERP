#ifndef UIObjectCheckDiscountH
#define UIObjectCheckDiscountH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "UCheckDiscount_StringDoc.h"
class __declspec(uuid(Global_IID_IObjectCheckDiscount)) IObjectCheckDiscount : public IMainInterface
{
public:
   __property TStringDoc * StringDoc = {read = get_StringDoc , write = set_StringDoc};
   virtual TStringDoc * get_StringDoc(void)=0;
   virtual void set_StringDoc(TStringDoc * StringDoc)=0;

   __property int NumberTecString = {read = get_NumberTecString , write = set_NumberTecString};
   virtual int get_NumberTecString(void)=0;
   virtual void set_NumberTecString(int NumberTecString)=0;

   __property UnicodeString TextMessage = {read = get_TextMessage , write = set_TextMessage};
   virtual UnicodeString get_TextMessage(void)=0;
   virtual void set_TextMessage(UnicodeString TextMessage)=0;

   __property UnicodeString TextMessageAtention = {read = get_TextMessageAtention , write = set_TextMessageAtention};
   virtual UnicodeString get_TextMessageAtention(void)=0;
   virtual void set_TextMessageAtention(UnicodeString TextMessageAtention)=0;

   __property __int64 IdDiscountCard = {read = get_IdDiscountCard , write = set_IdDiscountCard};
   virtual __int64 get_IdDiscountCard(void)=0;
   virtual void set_IdDiscountCard(__int64 IdDiscountCard)=0;

   __property UnicodeString NameDiscountCard = {read = get_NameDiscountCard , write = set_NameDiscountCard};
   virtual UnicodeString get_NameDiscountCard(void)=0;
   virtual void set_NameDiscountCard(UnicodeString NameDiscountCard)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property UnicodeString NameTypePrice = {read = get_NameTypePrice , write = set_NameTypePrice};
   virtual UnicodeString get_NameTypePrice(void)=0;
   virtual void set_NameTypePrice(UnicodeString NameTypePrice)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property __int64 IdKlient = {read = get_IdKlient , write = set_IdKlient};
   virtual __int64 get_IdKlient(void)=0;
   virtual void set_IdKlient(__int64 IdKlient)=0;

   __property UnicodeString NameKlient = {read = get_NameKlient , write = set_NameKlient};
   virtual UnicodeString get_NameKlient(void)=0;
   virtual void set_NameKlient(UnicodeString NameKlient)=0;

   __property double SummaDoc = {read = get_SummaDoc , write = set_SummaDoc};
   virtual double get_SummaDoc(void)=0;
   virtual void set_SummaDoc(double SummaDoc)=0;

   virtual void CheckDiscount(void)=0;
   virtual bool GetString(void)=0;
   virtual void ClearList(void)=0;
   virtual void AddString(__int64 id_string,__int64 id_nom,__int64 id_ed,__int64 id_grp,	__int64 id_vid_nom,double price,double kol,double kf,double sum,double sum_discount,double procent_discount,double procent_discount_auto,double procent_discount_card,double procent_discount_hand,bool no_discount)=0;
   virtual void GetProcentPoDiscountCard(void)=0;
   virtual void GetProcentAuto(double sum_doc)=0;
   virtual bool FindCardPoCodu(UnicodeString code)=0;
};
#define IID_IObjectCheckDiscount __uuidof(IObjectCheckDiscount)
#endif
