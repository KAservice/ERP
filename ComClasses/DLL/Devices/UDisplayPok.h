//---------------------------------------------------------------------------

#ifndef UDisplayPokH
#define UDisplayPokH
//---------------------------------------------------------------------------
#include <vcl.h>
#include "GlobalInterface.h"
class TDisplayPok
        {
private:

       HINSTANCE dllIn;

		typedef WideString (__import  DllGetTextErrorType(void));
		DllGetTextErrorType * DllGetTextError;

		typedef bool (__import  DllConnectType(int,   //����,  1,2,3,
												int));//�������� 57600,9600 � ��.
		DllConnectType * DllConnect;

		typedef void (__import  DllDisconnectType(void));
		DllDisconnectType * DllDisconnect;

		typedef bool (__import  DllShowString1Type(WideString, 	//������,
													int,    //������ ������ 1,2,3,4
													int,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
													int    //������������,  0 ���� 1 ����� 2 �����
													));
		DllShowString1Type * DllShowString1;
		typedef bool (__import  DllShowString2Type(WideString, 	//������,
													int,    //������ ������ 1,2,3,4
													int,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
													int    //������������,  0 ���� 1 ����� 2 �����
													));

		DllShowString2Type * DllShowString2;

		typedef bool (__import  DllShowTextType(WideString, 	//������,
													int,    //������ ������ 1,2,3,4
													int,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
													int,    //������������,  0 ���� 1 ����� 2 �����
													bool)); //������ �� ������

		DllShowTextType * DllShowText;



 public:
		TDisplayPok();
		~TDisplayPok();

		bool Error;
		IkanUnknown * InterfaceMainObject;
		IkanUnknown * InterfaceOwnerObject;
		IkanUnknown * InterfaceImpl; //��������� ������ ����������
		GUID ClsIdImpl;				 //GUID ������ ����������


		//IMainInterface
		int CodeError;
		UnicodeString TextError;

		int Init();
		int Done();

		//������� ���������
		AnsiString Modul;

        bool InitDevice();

		bool Connect(int port,   //����,  1,2,3,
							int baud_rate);//�������� 57600,9600 � ��.
		void Disconnect(void);


		bool ShowString1(UnicodeString str, 	//������,
							int size_font,    //������ ������ 1,2,3,4
							int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
							int alignment    //������������,  0 ���� 1 ����� 2 �����
							);

		bool ShowString2(UnicodeString str, 	//������,
							int size_font,    //������ ������ 1,2,3,4
							int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
							int alignment    //������������,  0 ���� 1 ����� 2 �����
							);

		bool ShowText(UnicodeString str, 	//������,
							int size_font,    //������ ������ 1,2,3,4
							int style_font,    // �����, 0 �������, 1 ������, 2 ������, 3 ������ ������
							int alignment,    //������������,  0 ���� 1 ����� 2 �����
							bool word_wrap); //������ �� ������
        };
//---------------------------------------------------------------------------
#endif
