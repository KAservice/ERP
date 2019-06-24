//---------------------------------------------------------------------------

#ifndef UScaleH
#define UScaleH
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TScale : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall TScale(bool CreateSuspended);

	void __fastcall GenerateExternalEvent(void);
	enum    {
				MessageEvent,
				FirstEvent,
				NextEvent,
				EndObmenEvent} EventScale;//סמבûעטו מע ÊÊּ

   AnsiString TextMessage;
   int MaxProgressBar;

   AnsiString IP;
   int Port;
   int IdScale;
   int IdTypePrice;

   void CreateFile(void);
   void AddRecordTovar(int plu,
							int status_plu,
							int number_etiketki,
							int number_shtrih_coda,
							int prefiks_shtrih_coda,
							double price,
							double massa_tary,
							int code_tovar,
							TDateTime date_real,
							int srok_godn,
							AnsiString code_sertif,
							int number_osn_group,
							int number_font_name_tovar,
							AnsiString name_tovar);

   void AddCRC16(void);
   WORD CRC16(BYTE *buf, WORD len);



   void SendMessageVPM(void);
   void __fastcall EndSocketOperation(TObject *Sender);

};
//---------------------------------------------------------------------------
#endif
