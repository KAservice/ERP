#ifndef UIFormaSpiskaSprEdTouchH
#define UIFormaSpiskaSprEdTouchH
#include "IMainInterface.h"
#include "FIBDatabase.hpp"
#include "FIBDataSet.hpp"
#include "FIBQuery.hpp"
#include "pFIBDatabase.hpp"
#include "pFIBDataSet.hpp"
#include "pFIBQuery.hpp"
#include <Classes.hpp>
class __declspec(uuid("{8130A1C9-F202-496F-8986-854904556135}")) IFormaSpiskaSprEdTouch : public IMainInterface
{
public:
   __property TpFIBDataSet * El = {read = get_El , write = set_El};
   virtual TpFIBDataSet * get_El(void)=0;
   virtual void set_El(TpFIBDataSet * El)=0;

   __property TFIBBCDField * ElKFED = {read = get_ElKFED , write = set_ElKFED};
   virtual TFIBBCDField * get_ElKFED(void)=0;
   virtual void set_ElKFED(TFIBBCDField * ElKFED)=0;

   __property TFIBIntegerField * ElTSHED = {read = get_ElTSHED , write = set_ElTSHED};
   virtual TFIBIntegerField * get_ElTSHED(void)=0;
   virtual void set_ElTSHED(TFIBIntegerField * ElTSHED)=0;

   __property TFIBSmallIntField * ElNEISPED = {read = get_ElNEISPED , write = set_ElNEISPED};
   virtual TFIBSmallIntField * get_ElNEISPED(void)=0;
   virtual void set_ElNEISPED(TFIBSmallIntField * ElNEISPED)=0;

   __property TFIBBCDField * ElZNACH_PRICE = {read = get_ElZNACH_PRICE , write = set_ElZNACH_PRICE};
   virtual TFIBBCDField * get_ElZNACH_PRICE(void)=0;
   virtual void set_ElZNACH_PRICE(TFIBBCDField * ElZNACH_PRICE)=0;

   __property TFIBBCDField * ElIDED = {read = get_ElIDED , write = set_ElIDED};
   virtual TFIBBCDField * get_ElIDED(void)=0;
   virtual void set_ElIDED(TFIBBCDField * ElIDED)=0;

   __property TFIBBCDField * ElIDNOMED = {read = get_ElIDNOMED , write = set_ElIDNOMED};
   virtual TFIBBCDField * get_ElIDNOMED(void)=0;
   virtual void set_ElIDNOMED(TFIBBCDField * ElIDNOMED)=0;

   __property TFIBBCDField * ElIDOKEIED = {read = get_ElIDOKEIED , write = set_ElIDOKEIED};
   virtual TFIBBCDField * get_ElIDOKEIED(void)=0;
   virtual void set_ElIDOKEIED(TFIBBCDField * ElIDOKEIED)=0;

   __property TFIBWideStringField * ElNAMEED = {read = get_ElNAMEED , write = set_ElNAMEED};
   virtual TFIBWideStringField * get_ElNAMEED(void)=0;
   virtual void set_ElNAMEED(TFIBWideStringField * ElNAMEED)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property int NumberProcVibor = {read = get_NumberProcVibor , write = set_NumberProcVibor};
   virtual int get_NumberProcVibor(void)=0;
   virtual void set_NumberProcVibor(int NumberProcVibor)=0;

   __property UnicodeString NameNom = {read = get_NameNom , write = set_NameNom};
   virtual UnicodeString get_NameNom(void)=0;
   virtual void set_NameNom(UnicodeString NameNom)=0;

   __property bool MnVibor = {read = get_MnVibor , write = set_MnVibor};
   virtual bool get_MnVibor(void)=0;
   virtual void set_MnVibor(bool MnVibor)=0;

   __property __int64 IdFirm = {read = get_IdFirm , write = set_IdFirm};
   virtual __int64 get_IdFirm(void)=0;
   virtual void set_IdFirm(__int64 IdFirm)=0;

   __property __int64 IdSklad = {read = get_IdSklad , write = set_IdSklad};
   virtual __int64 get_IdSklad(void)=0;
   virtual void set_IdSklad(__int64 IdSklad)=0;

   __property __int64 IdNom = {read = get_IdNom , write = set_IdNom};
   virtual __int64 get_IdNom(void)=0;
   virtual void set_IdNom(__int64 IdNom)=0;

   __property __int64 IdBasEd = {read = get_IdBasEd , write = set_IdBasEd};
   virtual __int64 get_IdBasEd(void)=0;
   virtual void set_IdBasEd(__int64 IdBasEd)=0;

   __property __int64 IdEd = {read = get_IdEd , write = set_IdEd};
   virtual __int64 get_IdEd(void)=0;
   virtual void set_IdEd(__int64 IdEd)=0;

   __property int TypeNom = {read = get_TypeNom , write = set_TypeNom};
   virtual int get_TypeNom(void)=0;
   virtual void set_TypeNom(int TypeNom)=0;

   __property double Kol = {read = get_Kol , write = set_Kol};
   virtual double get_Kol(void)=0;
   virtual void set_Kol(double Kol)=0;

   __property __int64 IdPod = {read = get_IdPod , write = set_IdPod};
   virtual __int64 get_IdPod(void)=0;
   virtual void set_IdPod(__int64 IdPod)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   virtual void UpdateForm(void)=0;
   virtual void OpenSpisokEd(void)=0;
   virtual void OpenElement(int Num)=0;
};
#define IID_IFormaSpiskaSprEdTouch __uuidof(IFormaSpiskaSprEdTouch)
#endif
