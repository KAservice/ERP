#ifndef UObjectCheckDiscountImplH
#define UObjectCheckDiscountImplH
#include "IObjectCheckDiscount.h"
#include "UObjectCheckDiscount.h"
#include "UGlobalConstant.h"
//---------------------------------------------------------------
class __declspec(uuid(Global_CLSID_TObjectCheckDiscountImpl)) TObjectCheckDiscountImpl : public IObjectCheckDiscount
{
public:
   TObjectCheckDiscountImpl();
   ~TObjectCheckDiscountImpl();
   TObjectCheckDiscount * Object;
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

//IObjectCheckDiscount
   virtual TStringDoc * get_StringDoc(void);
   virtual void set_StringDoc(TStringDoc * StringDoc);

   virtual int get_NumberTecString(void);
   virtual void set_NumberTecString(int NumberTecString);

   virtual UnicodeString get_TextMessage(void);
   virtual void set_TextMessage(UnicodeString TextMessage);

   virtual UnicodeString get_TextMessageAtention(void);
   virtual void set_TextMessageAtention(UnicodeString TextMessageAtention);

   virtual __int64 get_IdDiscountCard(void);
   virtual void set_IdDiscountCard(__int64 IdDiscountCard);

   virtual UnicodeString get_NameDiscountCard(void);
   virtual void set_NameDiscountCard(UnicodeString NameDiscountCard);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual UnicodeString get_NameTypePrice(void);
   virtual void set_NameTypePrice(UnicodeString NameTypePrice);

   virtual __int64 get_IdSklad(void);
   virtual void set_IdSklad(__int64 IdSklad);

   virtual __int64 get_IdKlient(void);
   virtual void set_IdKlient(__int64 IdKlient);

   virtual UnicodeString get_NameKlient(void);
   virtual void set_NameKlient(UnicodeString NameKlient);

   virtual double get_SummaDoc(void);
   virtual void set_SummaDoc(double SummaDoc);

   virtual void CheckDiscount(void);
   virtual bool GetString(void);
   virtual void ClearList(void);
   virtual void AddString(__int64 id_string,__int64 id_nom,__int64 id_ed,__int64 id_grp,	__int64 id_vid_nom,double price,double kol,double kf,double sum,double sum_discount,double procent_discount,double procent_discount_auto,double procent_discount_card,double procent_discount_hand,bool no_discount);
   virtual void GetProcentPoDiscountCard(void);
   virtual void GetProcentAuto(double sum_doc);
   virtual bool FindCardPoCodu(UnicodeString code);
};
#define CLSID_TObjectCheckDiscountImpl __uuidof(TObjectCheckDiscountImpl)
#endif
