#include "Point.h"

//#define STRUCT_POINT
//#define Distance
//#define ConstructorsCheck
//#define Copy_Assigment1
//#define Copy_Assigment2


void main()
{
	setlocale(LC_ALL, "RU");

#ifdef STRUCT_POINT

	Point a; //объявление переменной "а" типа "Point" 
//или объявление объекта "а" структуры "Point" 
//или объявление экземпляр "а" структуры "Point" 

	cout << a.get_y() << "\t" << a.get_x() << endl;

	Point* pa = &a;
	cout << pa->get_x() << "\t" << pa->get_y() << endl;

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y();
#endif

#ifdef Distance 
	Point A;
	Point B;
	double get_x(), get_y();

	cout << "Введите х и у 1 точки "; cin >> get_x() >> get_y();
	A.set_x(get_x()); A.set_y(get_y());
	cout << "\n-------------------------------------------------------------------------------\n";

	cout << "Введите х и у 2 точки "; cin >> get_x() >> get_y();
	cout << "\n-------------------------------------------------------------------------------\n";

	B.set_x(get_x()); B.set_y(get_y());
	A.print();
	cout << "\n-------------------------------------------------------------------------------\n";
	B.print();
	cout << "\n-------------------------------------------------------------------------------\n";

	cout << "Расстояние между А и В: " << A.distance(B) << endl;
	cout << "\n-------------------------------------------------------------------------------\n";

	cout << "Расстояние между В и А: " << distance(A, B) << endl;
	cout << "\n-------------------------------------------------------------------------------\n";

#endif 

#ifdef ConstructorsCheck
	Point A;//DefoultConstructor
	A.print();

	Point B = 3;//Singl-Argumeny Constructor
	B.print();

	Point C(5,2);//Singl-Argumeny Constructor
	C.print();

	Point D = C;
	D.print();
#endif 

#ifdef Copy_Assigment1
	Point A(3, 2);
	A.print();
	Point B;
	B = A;
	B.print();
#endif

#ifdef Copy_Assigment2
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << "\n-------------------------------------------------------------------------------\n";

	A = B = C = Point(2, 5);
	cout << "\n-------------------------------------------------------------------------------\n";

	A.print();
	cout << "\n-------------------------------------------------------------------------------\n";

	B.print();
	cout << "\n-------------------------------------------------------------------------------\n";

	C.print();
	cout << "\n-------------------------------------------------------------------------------\n";
#endif


}

