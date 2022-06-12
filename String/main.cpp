#include <iostream>
using namespace std;


class String
{
	int size;
	char* line = new char[size];
public:
	explicit String()
	{
		cout << 1;
		this->line[88]={};
	}
	explicit String(int size)
	{
		cout << 2;
		this->line[size]={};
	}
	~String()
	{
		cout << 0;
		delete[] line;
	}
	String operator= ()
	{

	}
};

void main()
{
	setlocale(LC_ALL, "RU");
	String Hello;
}