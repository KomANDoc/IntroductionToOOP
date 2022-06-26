#pragma once
#include <iostream>
using namespace std;

class Fractoin;

Fraction& operator* (Fraction L, Fraction R);
Fraction& operator/ (Fraction L, Fraction R);
Fraction& operator+ (Fraction L, Fraction R);
Fraction& operator- (Fraction L, Fraction R);
int ComDen(Fraction L, Fraction R);
bool operator> (Fraction L, Fraction R);
bool operator< (Fraction L, Fraction R);
bool operator>= (Fraction L, Fraction R);
bool operator<= (Fraction L, Fraction R);
bool operator== (Fraction L, Fraction R);
bool operator!= (Fraction L, Fraction R);
std::ostream& operator<< (std::ostream& os, const Fraction& obj);
std::istream& operator>> (std::istream& is, Fraction& obj);

class Fraction
{

	int numerator;
	int denominator;
	int integer;

public:
	Fraction();
	/*explicit Fraction(int integer)
	{
		this->numerator = 0;
		this->denominator = 1;
		this->integer = integer;
	}Запрещает неявное преобразование*/
	explicit Fraction(int integer);
	explicit Fraction(double decimal);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	int get_numerator()const;
	int get_denominator()const;
	int get_integer()const;

	void set_numerator(int numerator);
	void set_denominator(int denominator);
	void set_integer(int integer);

	void print()const;
	Fraction& to_impropert();
	Fraction& to_propert();
	Fraction& inverted();
	Fraction& reductoin();
	/*Fraction& reductoin()
	{
		bool T = true;
		do
		{
			if (numerator % 2 == 0 and denominator % 2 == 0)
			{
				numerator /= 2;
				denominator /= 2;
			}
			else if (numerator % 3 == 0 and denominator % 3 == 0)
			{
				numerator /= 3;
				denominator /= 3;
			}
			else if (numerator % 5 == 0 and denominator % 5 == 0)
			{
				numerator /= 5;
				denominator /= 5;
			}
			else if (denominator % numerator == 0)
			{
				numerator /= numerator;
				denominator /= numerator;
			}
			else if (numerator == 1)
			{
				T = false;
			}
			else
			{
				T = false;
			}
		} while (T);
		return *this;
	}*/

	Fraction& operator= (const Fraction& other);
	Fraction& operator*= (Fraction other);
	Fraction& operator/= (Fraction other);
	Fraction& operator+= (Fraction other);
	Fraction& operator-= (Fraction other);
	Fraction& operator++ ();
	Fraction& operator()(int integer, int numerator, int denominator);
	Fraction operator++ (int);


	explicit operator int();
	explicit operator double();
};