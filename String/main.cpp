#include "String.h"

void main()
{
	setlocale(LC_ALL, "RU");
	String Ded;
	//���� ����� ������������� ��
	String str1(); //��� �� ������ ������� � �� ������!!!
	String str2{}; //� ��� ��� ��������� ���
	//��� ������ �������� ������ ����� ������� ����� ����������� 
	String str3 = "����";
	str3.print();
	String str4 = str3;
	str4.to_lower();
	str4.print();
}
