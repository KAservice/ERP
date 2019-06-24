#ifndef UkasVariantH
#define UkasVariantH


struct TkasVariant
	{
	int type;                                   // 0 не задан 1 int, 2 строка, 3 double, 4 логическое,5 дата, 6 врем€, 7 дата¬рем€
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
