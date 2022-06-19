#include <iostream>
#include <Windows.h>
#include <ctype.h>
using namespace std;

class String;

String operator+ (const String& L, const String& R);
std::ostream& operator<< (std::ostream& os, const String& line);
std::istream& operator>> (std::istream& is, String& obj);
std::istream& getline(std::istream& is, String& obj);
bool is_palindrome(const String& obj);

class String
{
	int size;
	char* line;
public:

	int get_size()const
	{
		return size;
	}
	char* get_line()
	{
		return line;
	}
	const char* get_line()const
	{
		return line;
	}

	explicit String():size(size), line(new char[size]{})
	{
		//this->size = 80;
		//this->line = new char[80] {};
	}
	explicit String(int size)
	{
		this->size = size;
		this->line = new char[size] {};
	}
	String(const char* line) :String(strlen(line) + 1)
	{
		//this->size = strlen(line) + 1;
		//this->line = new char[size] {};
		for (int i = 0; i < size; i++) this->line[i] = line[i];
	}
	String (const String& line):String(line.line)
	{
		//this->size = line.size;
		//Выполняет Deep Copy
		//this->line = new char[size] {};
		for (int i = 0; i < size; i++) this->line[i] = line.line[i];
	}
	~String()
	{
		delete[] line;
	}

	void print()const
	{
		cout << size << endl;
		cout << line << endl;
	}

	String& operator= (const String& line)
	{
		if (this == &line) return *this;
		delete[] this->line;
		this->size = line.size;
		//Как и CopyConstractor выполняет Deep Copy
		this->line = new char[size] {};
		for (int i = 0; i < size; i++) this->line[i] = line.line[i];
		return *this;
	}
	char& operator[] (int i)const
	{
		return line[i];
	}
	String& operator+= (const String& line)
	{
		return*this = *this + line;
	}
	/*void to_upper()
	{
		for (int i = 0; i < this->size; i++)
		{
			if ((int)line[i] > 96 and (int)line[i] < 123)
			{
			this->line[i] = (int)line[i] - 32;
			}
		}
	}
	void to_lower()
	{
		for (int i = 0; i < this->size; i++)
		{
			if ((int)line[i] > 64 and (int)line[i] < 91)
			{
				this->line[i] = (int)line[i] + 32;
			}
		}
	}*/
	//другие аппер и ловер
	String& to_upper()
	{
		for (int i = 0; i < size; i++)
		{
			//if (line[i] >= 'a' and line[i] <= 'z')line[i] -= ' ';//или 32 по аске таблице. т.к.32 это пробел
			//if (line[i] >= 'а' and line[i] <= 'я')line[i] -= ' ';
			line[i] = toupper(line[i]);
		}
		return *this;
	}
	String& to_lower()
	{
		for (int i = 0; i < size; i++)
		{
			//if (line[i] >= 'A' and line[i] <= 'Z')line[i] += ' ';//или 32 по аске таблице. т.к.32 это пробел
			//if (line[i] >= 'А' and line[i] <= 'Я')line[i] += ' ';
			line[i] = tolower(line[i]);
		}
		return *this;
	}

};

void main()
{
	setlocale(LC_ALL, "RU");
	String Ded;
	//Есть много констракторов но
	String str1(); //так мы делаем функцию а не строку!!!
	String str2{}; //А вот так строковый тип
	//при помощи фигурной скобки можно вызвать любой конструктор 
	String str3 = "ОПОП";
	str3.print();
	String str4 = str3;
	str4.to_lower();
	str4.print();
}

String operator+ (const String& L, const String& R)
{
	//Происходит Конкатенация строк
	String cat(L.get_size() + R.get_size() - 1);
	for (int i = 0; i < L.get_size(); i++)
		cat[i] = L[i];
		//cat.get_line()[i] = L.get_line()[i];
	for (int i = 0; i < R.get_size(); i++)
		cat[i + L.get_size() - 1] = R[i];
		//cat.get_line()[i + L.get_size() - 1] = R.get_line()[i];
	return cat;

}
std::ostream& operator<< (std::ostream& os, const String& line)
{
	return os << line.get_line();
}
std::istream& operator>> (std::istream& is, String& obj)
{
	const int SIZE = 8192;
	char sz_buffer[SIZE] = {};
	SetConsoleCP(1251);//для ввода русских букв
	is >> sz_buffer;
	SetConsoleCP(866);
	obj = sz_buffer;
	return is;
}
bool is_palindrome(const String& obj)
{
	String palindrome = obj.get_line();
	int inv_i = (obj.get_size() - 2);
	palindrome.to_lower();
	for (int i = 0; i < obj.get_size() - 1; i++)
	{
		if (palindrome[i] != palindrome[inv_i])
		{
			return 0;
		}
		if (inv_i > 0)
		{
			inv_i--;
		}
	}			
	return 1;
}

std::istream& getline(std::istream& is, String& obj)
{
	SetConsoleCP(1251);
	is.getline(obj.get_line(), obj.get_size());
	SetConsoleCP(866);
	return is;
}