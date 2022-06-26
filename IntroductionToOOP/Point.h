#pragma once
#include <iostream>
using namespace std;

class Point
{
	double x;
	double y;

public:

	Point& operator= (const Point& other);

	double get_x()const;
	double get_y()const;

	void set_x(double x);
	void set_y(double y);

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
	Point(double x = 0, double y = 0);
	Point(const Point& other);
	~Point();

	double distance(const Point& other);
	void print();

};


double distance(const Point A, const Point B);
