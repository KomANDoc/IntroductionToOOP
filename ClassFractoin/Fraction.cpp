#include "Fractoin.h"

Fraction& operator* (Fraction L, Fraction R)
{
	L.to_impropert();
	R.to_impropert();
	/*Fraction result;
	result.set_numerator(R.get_numerator() * L.get_numerator());
	result.set_denominator(R.get_denominator() * L.get_denominator()); но можно по другому*
	result.to_propert();
	return result*/

	return Fraction
	(L.get_numerator() * R.get_numerator(),
		L.get_denominator() * R.get_denominator()).to_propert();
}
Fraction& operator/ (Fraction L, Fraction R)
{
	L.to_impropert();
	R.to_impropert();
	Fraction result;
	result.set_numerator(L.get_numerator() * R.get_denominator());
	result.set_denominator(L.get_denominator() * R.get_numerator());
	result.to_propert();
	return result;
}
Fraction& operator+ (Fraction L, Fraction R)
{
	L.to_impropert();
	R.to_impropert();
	Fraction result;
	result.set_numerator(L.get_numerator() * R.get_denominator() + R.get_numerator() * L.get_denominator());
	result.set_denominator(L.get_denominator() * R.get_denominator());
	result.to_propert();
	result.reductoin();
	return result;
}
Fraction& operator- (Fraction L, Fraction R)
{
	L.to_impropert();
	R.to_impropert();
	Fraction result;
	result.set_numerator(L.get_numerator() * R.get_denominator() - R.get_numerator() * L.get_denominator());
	result.set_denominator(L.get_denominator() * R.get_denominator());
	result.to_propert();
	result.reductoin();
	return result;
}

int ComDen(Fraction L, Fraction R)
{
	int ComDen;
	return ComDen = L.get_denominator() * R.get_denominator();
}
bool operator> (Fraction L, Fraction R)
{
	L.to_impropert();
	R.to_impropert();
	ComDen(L, R);
	L.set_denominator(L.get_denominator() * ComDen(L, R));
	R.set_denominator(R.get_denominator() * ComDen(L, R));
	L.set_numerator(L.get_numerator() * ComDen(L, R));
	R.set_numerator(R.get_numerator() * ComDen(L, R));
	if (L.get_numerator() > R.get_numerator())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator< (Fraction L, Fraction R)
{
	L.to_impropert();
	R.to_impropert();
	ComDen(L, R);
	L.set_denominator(L.get_denominator() * ComDen(L, R));
	R.set_denominator(R.get_denominator() * ComDen(L, R));
	L.set_numerator(L.get_numerator() * ComDen(L, R));
	R.set_numerator(R.get_numerator() * ComDen(L, R));
	if (L.get_numerator() < R.get_numerator())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator>= (Fraction L, Fraction R)
{
	L.to_impropert();
	R.to_impropert();
	ComDen(L, R);
	L.set_denominator(L.get_denominator() * ComDen(L, R));
	R.set_denominator(R.get_denominator() * ComDen(L, R));
	L.set_numerator(L.get_numerator() * ComDen(L, R));
	R.set_numerator(R.get_numerator() * ComDen(L, R));
	if (L.get_numerator() >= R.get_numerator())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator<= (Fraction L, Fraction R)
{
	L.to_impropert();
	R.to_impropert();
	ComDen(L, R);
	L.set_denominator(L.get_denominator() * ComDen(L, R));
	R.set_denominator(R.get_denominator() * ComDen(L, R));
	L.set_numerator(L.get_numerator() * ComDen(L, R));
	R.set_numerator(R.get_numerator() * ComDen(L, R));
	if (L.get_numerator() <= R.get_numerator())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator== (Fraction L, Fraction R)
{
	L.to_impropert();
	R.to_impropert();
	ComDen(L, R);
	L.set_denominator(L.get_denominator() * ComDen(L, R));
	R.set_denominator(R.get_denominator() * ComDen(L, R));
	L.set_numerator(L.get_numerator() * ComDen(L, R));
	R.set_numerator(R.get_numerator() * ComDen(L, R));
	if (L.get_numerator() == R.get_numerator())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator!= (Fraction L, Fraction R)
{
	L.to_impropert();
	R.to_impropert();
	ComDen(L, R);
	L.set_denominator(L.get_denominator() * ComDen(L, R));
	R.set_denominator(R.get_denominator() * ComDen(L, R));
	L.set_numerator(L.get_numerator() * ComDen(L, R));
	R.set_numerator(R.get_numerator() * ComDen(L, R));
	if (L.get_numerator() != R.get_numerator())
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream& operator<< (std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())cout << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())cout << "(";
		cout << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())cout << ")";
	}
	if (!obj.get_integer() and !obj.get_numerator())cout << 0;
	cout << endl;
	return os;
}
std::istream& operator>> (std::istream& is, Fraction& obj)
{

	//int integer, numerator, denominator;
	//cin >> integer >> numerator >> denominator;
	//obj(integer, numerator, denominator);

	const int SIZE = 256;
	char sz_buffer[SIZE] = {};
	//is >> sz_buffer;
	is.getline(sz_buffer, SIZE);
	char* sz_numbers[3] = {};
	char sz_delimiters[] = "() /";
	int n = 0; //индекс элемента в массиве с подстроками (токенами)
	for (char* pch = strtok(sz_buffer, sz_delimiters);pch; pch = strtok(NULL, sz_delimiters))
	{
		sz_numbers[n++] = pch;
	}
	//for (int i = 0; i < n;i++)cout << sz_numbers[i] << "\t"; cout << endl;
	obj = Fraction();
	switch (n)
	{
		//atoi() - ASCII - string to int (преобразование строки в инт)
	case 1: obj.set_integer(atoi(sz_numbers[0])); break;
	case 2: obj.set_numerator(atoi(sz_numbers[0]));
		obj.set_denominator(atoi(sz_numbers[1]));
		break;
	case 3: obj.set_integer(atoi(sz_numbers[0]));
		obj.set_numerator(atoi(sz_numbers[1]));
		obj.set_denominator(atoi(sz_numbers[2]));
		break;
	default:break;
	}
	return is;
}

class Fraction
{

	int numerator;
	int denominator;
	int integer;

public:
	Fraction()
	{
		this->numerator = 0;
		this->denominator = 1;
		this->integer = 0;
	}
	/*explicit Fraction(int integer)
	{
		this->numerator = 0;
		this->denominator = 1;
		this->integer = integer;
	}Запрещает неявное преобразование*/
	explicit Fraction(int integer)
	{
		this->numerator = 0;
		this->denominator = 1;
		this->integer = integer;
	}
	explicit Fraction(double decimal)
	{
		this->integer = (int)decimal;
		//this->denominator = 1000000;
		this->denominator = 1e+9;
		//this->numerator = int(((decimal - (int)decimal) + 0.0000000001) * denominator);
		this->numerator = int(((decimal - (int)decimal) + 1e-10) * denominator);
		this->reductoin();
		/*this->integer = (int)integer;
		this->numerator = 0;
		this->denominator = 1;
		integer -= (int)integer;
		int t = 1;
		for (int i = 10;  != t; i *= 10)
		{
			double t = integer * i;
			this->denominator = i;
			this->numerator = int(integer * i);
		}
		this->reductoin();*/
		/*double numerator = integer - (int)integer;
		this->integer = (int)integer;
		this->denominator = 1;
		for (int i = 10; numerator != (int)numerator;)
		{
			numerator *= i;
			this->denominator *= i;
		}
		this->numerator = (int)numerator;
		this->reductoin();*/
	}
	Fraction(int numerator, int denominator)
	{
		this->numerator = numerator;
		this->set_denominator(denominator);
		this->integer = 0;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->numerator = numerator;
		this->set_denominator(denominator);
		this->integer = integer;
	}
	Fraction(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		this->integer = other.integer;
	}
	~Fraction() {}

	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	int get_integer()const
	{
		return integer;
	}

	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}

	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		if (!integer and !numerator)cout << 0;
		cout << endl;
	}
	Fraction& to_impropert()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_propert()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& inverted()
	{
		Fraction inverted = *this;
		inverted.to_impropert();
		int buffer;
		buffer = numerator;

	}//!!!
	Fraction& reductoin()
	{
		int nod = 1;
		for (int i = numerator; i > 0; i--)
		{
			if (numerator % i == 0 && denominator % i == 0)
			{
				nod = i; break;
			}
		}
		numerator /= nod;
		denominator /= nod;
		return *this;

	}
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

	Fraction& operator= (const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		this->integer = other.integer;
		return *this;
	}
	Fraction& operator*= (Fraction other)
	{
		/*this->to_impropert();
		other.to_impropert();
		this->numerator = numerator * other.numerator;
		this->denominator = denominator * other.denominator;
		this->to_propert();*/
		return *this = *this * other;
	}
	Fraction& operator/= (Fraction other)
	{
		return *this = *this / other;
	}
	Fraction& operator+= (Fraction other)
	{
		return *this = *this + other;
	}
	Fraction& operator-= (Fraction other)
	{
		return *this = *this - other;
	}
	Fraction& operator++ ()//Prefix Inc
	{
		integer++;
		return *this;
	}
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}
	Fraction operator++ (int)//Sufix Inc
	{
		Fraction old = *this;
		integer++;
		return old;
	}


	explicit operator int()
	{
		return this->integer;
	}
	explicit operator double()
	{
		return this->integer + (double)this->numerator / (double)this->denominator;
	}
};


