#include <iostream>
using namespace std;

//#define STRUCT_POINT
//#define Distance
//#define ConstructorsCheck
//#define Copy_Assigment1
//#define Copy_Assigment2


class Point
{
	double x;
	double y;

public:

	Point& operator= (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssigment: " << this << endl;
		return *this;
	}

	double get_x()const
	{
		return x;
	}//
	double get_y()const
	{
		return y;
	}

	void set_x(double x)
	{
		this->x = x;
	}//
	void set_y(double y)
	{
		this->y = y;
	}

	/*
	Point()
	{
		x = y = double();
		cout << "DefaultConstructor:\t" << this << endl;
	}//
	Point(double x)
	{
		this->x = x;
		this->y = double();
		cout << "1argKonstructor: " << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor: " << this << endl;
	}
	*/
	Point(double x = 0, double y = 0)//есть возможность заменить все конструкторы выше на такой. но с ним нужно быть аккуратным!
	{
		this->x = x;
		this->y = y;
		cout << "Constructor: " << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: " << this << endl;
	}
	~Point()
	{
		cout << "Destructor: " << this << endl;
	}//

	double distance(const Point& other)
	{
		double distance_x = this->x - other.x;
		double distance_y = this->y - other.y;
		double distance = sqrt(distance_x * distance_x + distance_y * distance_y);
		return distance;
	}
	void print()
	{
		cout << "X = " << x << "\t" << "Y = " << y << endl;
	}

};


double distance(const Point A, const Point B);


void main()
{
	setlocale(LC_ALL, "RU");

#ifdef STRUCT_POINT

	Point a; //объявление переменной "а" типа "Point" 
//или объявление объекта "а" структуры "Point" 
//или объявление экземпляр "а" структуры "Point" 

	cout << a.y << "\t" << a.x << endl;

	Point* pa = &a;
	cout << pa->x << "\t" << pa->y << endl;

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y();
#endif

#ifdef Distance 
	Point A;
	Point B;
	double x, y;

	cout << "Введите х и у 1 точки "; cin >> x >> y;
	A.set_x(x); A.set_y(y);
	cout << "\n-------------------------------------------------------------------------------\n";

	cout << "Введите х и у 2 точки "; cin >> x >> y;
	cout << "\n-------------------------------------------------------------------------------\n";

	B.set_x(x); B.set_y(y);
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




double distance(const Point A,const Point B)
{
	double distance_x = A.get_x() - B.get_x();
	double distance_y = A.get_y() - B.get_y();
	double distance = sqrt(pow(distance_x,2) + pow(distance_y,2));
	return distance;
}
