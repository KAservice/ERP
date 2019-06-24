#ifndef UIFormaArmKassirH
#define UIFormaArmKassirH
#include "IMainInterface.h"
#include "UGlobalConstant.h"
#include "IDMDocCheck.h"
class __declspec(uuid(Global_IID_IFormaArmKassir)) IFormaArmKassir : public IMainInterface
{
public:
   __property IDMDocCheck * DM = {read = get_DM , write = set_DM};
   virtual IDMDocCheck * get_DM(void)=0;
   virtual void set_DM(IDMDocCheck * DM)=0;

   __property bool Prosmotr = {read = get_Prosmotr , write = set_Prosmotr};
   virtual bool get_Prosmotr(void)=0;
   virtual void set_Prosmotr(bool Prosmotr)=0;

   __property bool Vibor = {read = get_Vibor , write = set_Vibor};
   virtual bool get_Vibor(void)=0;
   virtual void set_Vibor(bool Vibor)=0;

   __property __int64 IdDoc = {read = get_IdDoc , write = set_IdDoc};
   virtual __int64 get_IdDoc(void)=0;
   virtual void set_IdDoc(__int64 IdDoc)=0;

   __property __int64 IdGrp = {read = get_IdGrp , write = set_IdGrp};
   virtual __int64 get_IdGrp(void)=0;
   virtual void set_IdGrp(__int64 IdGrp)=0;

   __property __int64 IdElementaMaster = {read = get_IdElementaMaster , write = set_IdElementaMaster};
   virtual __int64 get_IdElementaMaster(void)=0;
   virtual void set_IdElementaMaster(__int64 IdElementaMaster)=0;

   __property __int64 VibTovarId = {read = get_VibTovarId , write = set_VibTovarId};
   virtual __int64 get_VibTovarId(void)=0;
   virtual void set_VibTovarId(__int64 VibTovarId)=0;

   __property __int64 VibTovarIdGrp = {read = get_VibTovarIdGrp , write = set_VibTovarIdGrp};
   virtual __int64 get_VibTovarIdGrp(void)=0;
   virtual void set_VibTovarIdGrp(__int64 VibTovarIdGrp)=0;

   __property bool OutReady = {read = get_OutReady , write = set_OutReady};
   virtual bool get_OutReady(void)=0;
   virtual void set_OutReady(bool OutReady)=0;

   __property __int64 IdTypePrice = {read = get_IdTypePrice , write = set_IdTypePrice};
   virtual __int64 get_IdTypePrice(void)=0;
   virtual void set_IdTypePrice(__int64 IdTypePrice)=0;

   __property AnsiString NameTypePrice = {read = get_NameTypePrice , write = set_NameTypePrice};
   virtual AnsiString get_NameTypePrice(void)=0;
   virtual void set_NameTypePrice(AnsiString NameTypePrice)=0;

   __property bool CheckSave = {read = get_CheckSave , write = set_CheckSave};
   virtual bool get_CheckSave(void)=0;
   virtual void set_CheckSave(bool CheckSave)=0;

   __property bool CheckPrint = {read = get_CheckPrint , write = set_CheckPrint};
   virtual bool get_CheckPrint(void)=0;
   virtual void set_CheckPrint(bool CheckPrint)=0;

   __property bool CheckProveden = {read = get_CheckProveden , write = set_CheckProveden};
   virtual bool get_CheckProveden(void)=0;
   virtual void set_CheckProveden(bool CheckProveden)=0;

   __property String StrPrint = {read = get_StrPrint , write = set_StrPrint};
   virtual String get_StrPrint(void)=0;
   virtual void set_StrPrint(String StrPrint)=0;

   __property bool CheckCreate = {read = get_CheckCreate , write = set_CheckCreate};
   virtual bool get_CheckCreate(void)=0;
   virtual void set_CheckCreate(bool CheckCreate)=0;

   __property __int64 IdARM = {read = get_IdARM , write = set_IdARM};
   virtual __int64 get_IdARM(void)=0;
   virtual void set_IdARM(__int64 IdARM)=0;

   __property bool ExternalCreateCheck = {read = get_ExternalCreateCheck , write = set_ExternalCreateCheck};
   virtual bool get_ExternalCreateCheck(void)=0;
   virtual void set_ExternalCreateCheck(bool ExternalCreateCheck)=0;

   __property bool NoOtrOstatok = {read = get_NoOtrOstatok , write = set_NoOtrOstatok};
   virtual bool get_NoOtrOstatok(void)=0;
   virtual void set_NoOtrOstatok(bool NoOtrOstatok)=0;

   virtual bool BeforeEditCheck(void)=0;
   virtual bool BeforeCreateNewCheck(void)=0;
   virtual void CreateNewDocCheck(void)=0;
   virtual void CreateNewDocCheckVosvrat(void)=0;
   virtual bool PrintCheck(bool povtor)=0;
   virtual bool SaveCheck(void)=0;
   virtual void UpdateForm(void)=0;
   virtual void UpdateSetup(void)=0;
   virtual void UpdateParameterFR(void)=0;
   virtual void PrintDocCheck(void)=0;
   virtual void UpdateValuesDiscount(void)=0;
   virtual void ValidateOstatok(double treb_kol)=0;
   virtual bool CreateCheckNaOsnRealRemont(__int64 id_doc_real_remont)=0;
};
#define IID_IFormaArmKassir __uuidof(IFormaArmKassir)
#endif
