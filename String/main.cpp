#include <iostream>
using namespace std;

class String;

String operator+ (const String& L, const String& R);
std::ostream& operator<< (std::ostream& os, const String& line);
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

	explicit String()
	{
		this->size = 80;
		this->line = new char[80] {};
	}
	explicit String(int size)
	{
		this->size = size;
		this->line = new char[size] {};
	}
	String(const char* line)
	{
		this->size = strlen(line) + 1;
		this->line = new char[size] {};
		for (int i = 0; i < size; i++) this->line[i] = line[i];
	}
	String (const String& line)
	{
		this->size = line.size;
		//Выполняет Deep Copy
		this->line = new char[size] {};
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
	void to_upper()
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
	}
};

void main()
{
	setlocale(LC_ALL, "RU");
	String World = "World";
	String Hello = "Hello";
	Hello += World;
	cout << Hello << endl;
	cout << (int)'v' << "\t" << (int)'V' << endl;
	cout << (int)'d' << "\t" << (int)'D' << endl;
	cout << (int)'i' << "\t" << (int)'I' << endl;
	cout << (int)'l' << "\t" << (int)'L' << endl;
	Hello.to_upper();
	cout << Hello << endl;
	Hello.to_lower();
	cout << Hello << endl;
	String Ded = "bOoB";
	if (is_palindrome(Ded))
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
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
/*std::istream& operator>> (std::istream& is, String& obj)
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
	return is;
}*/
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