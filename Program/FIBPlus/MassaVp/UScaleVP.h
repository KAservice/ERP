//---------------------------------------------------------------------------

#ifndef UScaleVPH
#define UScaleVPH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TScaleVP : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall TScaleVP(bool CreateSuspended);
	__fastcall ~TScaleVP(void);

	bool Error;
	AnsiString TextError;

	int SetNumber;
	

	void __fastcall GenerateExternalEvent(void);

	char * Buf_1;
	char * Buf_3;
//	char * A;
//	char * B;
	HANDLE ComHandle;

	DCB * stDCB;
	COMMTIMEOUTS * stCommtimeouts;
	//OVERLAPPED *stOVR;
    int BaudRate;

	bool  OpenPort(int port, int baud_rate);
	bool  ClosePort();
	void __fastcall WriteBuffer(char  *buf, int len);
	void __fastcall ReadBuffer(char *buf, int len);
    void SetupComPort(AnsiString parity ,int ri,int rm, int rc, int wm, int wc, bool clear_buffer);

	//параметры товара
	int NumberTovar;  		//номер товара 1-999
	int VidTovara;    		//вид товара 0,1
	int GroupCode;          //групповой код 0-99
	int CodeTovar;			//код товара 0-999999
	double Price;           //цена
	double Tara;            //тара
	TDate SrokGodn;          //срок годности
	AnsiString NameTovar;   //наименование

	//формат этикетки
	AnsiString VidLabel;
	int HeightLabel;

	//параметры этикетки
	int  NumberOtdelVes;
	int NumberOtdelSht;
	int TypeBarCode;
	AnsiString CodeSert;
	bool PrintDate;
	bool PrintPrice;
	bool PrintSert;
	AnsiString ReklamaStr1;
	AnsiString ReklamaStr2;
	AnsiString NeZaprogStr1;
    AnsiString NeZaprogStr2;


	bool AddTovarInScale(void);
	bool AddDopStringInScale(void);
	int KolDopString;
	
	char ScaleCodeSimbol(AnsiString StringSimbol);
	bool SetFormatLabel(void);
	bool SetParameteLabel(void);

	enum    {   No,
				ZagrTovar_Operation,
				SetFormatLabel_Operation,
				SetParameterLabel_Operation} Operation;



	bool Run;


	TStringList * DopStrings;
};
//---------------------------------------------------------------------------
#endif
