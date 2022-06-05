#include <iostream>
using namespace std;


class Fraction;
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
	Fraction(int integer)
	{
		this->numerator = 0;
		this->denominator = 1;
		this->integer = integer;
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
 		return *this = *this*other;
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
	Fraction operator++ (int)//Sufix Inc
	{
		Fraction old = *this;
		integer++;
		return old;
	}

};


//#define CONSTRUCTORS_CHEK


void main()
{
#ifdef CONSTRUCTORS_CHEK
	setlocale(LC_ALL, "RU");
	Fraction A(1, 2, 4);
	Fraction B(0, 5, 2);
	Fraction C;
	A.print();
	B.print();
	C.print();
#endif

	Fraction A(5, 3);
	Fraction B(7, 2);
	A.print();
	B.print();
	A.to_propert();
	B.to_propert();

	if (A > B)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}

	A.print();
	B.print();

	if (A < B)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}

	A.print();
	B.print();

	if (A == B)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}

	A.print();
	B.print();

	if (A != B)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}

	A.print();
	B.print();
}


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