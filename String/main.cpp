#include "String.h"

void main()
{
	setlocale(LC_ALL, "RU");
	String Ded;
	//Есть много констракторов но
	String str1(); //так мы делаем функцию а не строку!!!
	String str2{}; //А вот так строковый тип
	//при помощи фигурной скобки можно вызвать любой конструктор 
	String str3 = "ОПОП";
	str3.print();
	str2 = str3 + str3;
	str2.print();
}
