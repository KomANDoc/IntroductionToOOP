#include <iostream>
using namespace std;

class Point
{
	double x;
	double y;

public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
};

//#define STRUCT_POINT


void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT

	Point a; //объявление переменной "а" типа "Point" 
//или объявление объекта "а" структуры "Point" 
//или объявление экземпляр "а" структуры "Point" 
	cout << a.y << "\t" << a.x << endl;

	Point* pa = &a;
	cout << pa->x << "\t" << pa->y << endl;

#endif

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y();
}