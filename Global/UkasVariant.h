#ifndef UkasVariantH
#define UkasVariantH


struct TkasVariant
	{
	int type;                                   // 0 �� ����� 1 int, 2 ������, 3 double, 4 ����������,5 ����, 6 �����, 7 ���������
	int int_value;
	wchar_t * string_value;
	double dbl_value;
	bool bool_value;
	int day;
	int month;
	int year;
	int hour;
	int min;
	int sec;
	int len_string;
	};

#endif
