#ifndef UIHOT_RaschetStoimProgH
#define UIHOT_RaschetStoimProgH
#include "IMainInterface.h"
#include "UHOT_StringDoc.h"

class __declspec(uuid("{A30224BB-D6CF-464A-8B24-A99E64B81EDA}")) IHOT_RaschetStoimProg : public IMainInterface
{
public:


   __property bool AddBron = {read = get_AddBron , write = set_AddBron};
   virtual bool get_AddBron(void)=0;
   virtual void set_AddBron(bool AddBron)=0;

   __property TDateTime PosNach = {read = get_PosNach , write = set_PosNach};
   virtual TDateTime get_PosNach(void)=0;
   virtual void set_PosNach(TDateTime PosNach)=0;

   __property TDateTime PosCon = {read = get_PosCon , write = set_PosCon};
   virtual TDateTime get_PosCon(void)=0;
   virtual void set_PosCon(TDateTime PosCon)=0;

   __property TDateTime PosNachBron = {read = get_PosNachBron , write = set_PosNachBron};
   virtual TDateTime get_PosNachBron(void)=0;
   virtual void set_PosNachBron(TDateTime PosNachBron)=0;

   __property TDateTime PosConBron = {read = get_PosConBron , write = set_PosConBron};
   virtual TDateTime get_PosConBron(void)=0;
   virtual void set_PosConBron(TDateTime PosConBron)=0;

   __property __int64 IdNomer = {read = get_IdNomer , write = set_IdNomer};
   virtual __int64 get_IdNomer(void)=0;
   virtual void set_IdNomer(__int64 IdNomer)=0;

   __property __int64 IdTypePos = {read = get_IdTypePos , write = set_IdTypePos};
   virtual __int64 get_IdTypePos(void)=0;
   virtual void set_IdTypePos(__int64 IdTypePos)=0;

   __property AnsiString NameTypePos = {read = get_NameTypePos , write = set_NameTypePos};
   virtual AnsiString get_NameTypePos(void)=0;
   virtual void set_NameTypePos(AnsiString NameTypePos)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property int NumberTecString = {read = get_NumberTecString , write = set_NumberTecString};
   virtual int get_NumberTecString(void)=0;
   virtual void set_NumberTecString(int NumberTecString)=0;

   __property TList * ResultList = {read = get_ResultList , write = set_ResultList};
   virtual TList * get_ResultList(void)=0;
   virtual void set_ResultList(TList * ResultList)=0;

   __property TStringDoc * StringDoc = {read = get_StringDoc , write = set_StringDoc};
   virtual TStringDoc * get_StringDoc(void)=0;
   virtual void set_StringDoc(TStringDoc * StringDoc)=0;

   virtual void GetTableDoc(void)=0;
   virtual bool GetString(void)=0;
   virtual void AddStringNewReal( TDateTime pos_nach, TDateTime pos_con,	__int64 id_nom, AnsiString name_nom,__int64 id_ed, double kf, AnsiString name_ed,double price,double kol,int type_usl)=0;
};
#define IID_IHOT_RaschetStoimProg __uuidof(IHOT_RaschetStoimProg)
#endif
