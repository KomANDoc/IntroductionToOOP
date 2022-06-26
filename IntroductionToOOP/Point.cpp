#include "Point.h"

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
	}
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

double distance(const Point A, const Point B)
{
	double distance_x = A.get_x() - B.get_x();
	double distance_y = A.get_y() - B.get_y();
	double distance = sqrt(pow(distance_x, 2) + pow(distance_y, 2));
	return distance;
}