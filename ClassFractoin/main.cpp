#include "Fractoin.h"


#define CONSTRUCTORS_CHEK
//#define CONVERSION_FROM_CLASS

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

#ifdef CONVERSION_FROM_CLASS

	Fraction A = 5;// ������� �������������� 5 � ����� �����
	//Fraction A = Fraction(5) // ����� �������������� 5 � ����� �����
	cout << A << endl;
	Fraction B(1, 2);
	A += B * A;
	cout << A << endl;
	double a = (double)A;
	cout << a << endl;
#endif 
}
