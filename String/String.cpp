#include"String.h"

//////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////   Class definition - определение класса     //////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////





int String::get_size()const
{
	return size;
}
char* String::get_line()
{
	return line;
}
const char* String::get_line()const
{
	return line;
}

String::String() :size(size), line(new char[size] {})
{
	//this->size = 80;
	//this->line = new char[80] {};
}
String::String(int size)
{
	this->size = size;
	this->line = new char[size] {};
}
String::String(const char* line) :String(strlen(line) + 1)
{
	//this->size = strlen(line) + 1;
	//this->line = new char[size] {};
	for (int i = 0; i < size; i++) this->line[i] = line[i];
}
String::String(const String& line) :String(line.line)
{
	//this->size = line.size;
	//Выполняет Deep Copy
	//this->line = new char[size] {};
	for (int i = 0; i < size; i++) this->line[i] = line.line[i];
}
String::String(String&& other)
{
	this->size = other.size;
	this->line = other.line;
	other.line = nullptr;//указатель на ноль
}
String::~String()
{
	delete[] line;
}

void String::print()const
{
	cout << size << endl;
	cout << line << endl;
}

String& String::operator= (const String& line)
{
	if (this == &line) return *this;
	delete[] this->line;
	this->size = line.size;
	//Как и CopyConstractor выполняет Deep Copy
	this->line = new char[size] {};
	for (int i = 0; i < size; i++) this->line[i] = line.line[i];
	return *this;
}
String& String::operator= (String&& other)
{
	delete line;
	line = other.line;
	other.line = nullptr;
	return *this;
}
char& String::operator[] (int i)const
{
	return line[i];
}
String& String::operator+= (const String& line)
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
String& String::to_upper()
{
	for (int i = 0; i < size; i++)
	{
		//if (line[i] >= 'a' and line[i] <= 'z')line[i] -= ' ';//или 32 по аске таблице. т.к.32 это пробел
		//if (line[i] >= 'а' and line[i] <= 'я')line[i] -= ' ';
		line[i] = toupper(line[i]);
	}
	return *this;
}
String& String::to_lower()
{
	for (int i = 0; i < size; i++)
	{
		//if (line[i] >= 'A' and line[i] <= 'Z')line[i] += ' ';//или 32 по аске таблице. т.к.32 это пробел
		//if (line[i] >= 'А' and line[i] <= 'Я')line[i] += ' ';
		line[i] = tolower(line[i]);
	}
	return *this;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////   Class definition end - конец определения класса     ////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

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