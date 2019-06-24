#ifndef UHOT_RaschetStoimProgImplH
#define UHOT_RaschetStoimProgImplH
#include "IHOT_RaschetStoimProg.h"
#include "UHOT_RaschetStoimProg.h"
#include "UHOT_StringDoc.h"
//---------------------------------------------------------------
class __declspec(uuid("{B8396AC2-813D-4D05-9967-056DA2B6E2B6}")) THOT_RaschetStoimProgImpl : public IHOT_RaschetStoimProg
{
public:
   THOT_RaschetStoimProgImpl();
   ~THOT_RaschetStoimProgImpl();
   TRaschetStoimProg * Object;
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

//IHOT_RaschetStoimProg
   virtual bool get_AddBron(void);
   virtual void set_AddBron(bool AddBron);

   virtual TDateTime get_PosNach(void);
   virtual void set_PosNach(TDateTime PosNach);

   virtual TDateTime get_PosCon(void);
   virtual void set_PosCon(TDateTime PosCon);

   virtual TDateTime get_PosNachBron(void);
   virtual void set_PosNachBron(TDateTime PosNachBron);

   virtual TDateTime get_PosConBron(void);
   virtual void set_PosConBron(TDateTime PosConBron);

   virtual __int64 get_IdNomer(void);
   virtual void set_IdNomer(__int64 IdNomer);

   virtual __int64 get_IdTypePos(void);
   virtual void set_IdTypePos(__int64 IdTypePos);

   virtual AnsiString get_NameTypePos(void);
   virtual void set_NameTypePos(AnsiString NameTypePos);

   virtual __int64 get_IdTypePrice(void);
   virtual void set_IdTypePrice(__int64 IdTypePrice);

   virtual int get_NumberTecString(void);
   virtual void set_NumberTecString(int NumberTecString);

   virtual TList * get_ResultList(void);
   virtual void set_ResultList(TList * ResultList);

   virtual TStringDoc * get_StringDoc(void);
   virtual void set_StringDoc(TStringDoc * StringDoc);

   virtual void GetTableDoc(void);
   virtual bool GetString(void);
   virtual void AddStringNewReal( TDateTime pos_nach, TDateTime pos_con,	__int64 id_nom, AnsiString name_nom,__int64 id_ed, double kf, AnsiString name_ed,double price,double kol,int type_usl);
};
#define CLSID_THOT_RaschetStoimProgImpl __uuidof(THOT_RaschetStoimProgImpl)
#endif
