#pragma once
#include <iostream>
#include <Windows.h>
#include <ctype.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////    Class declaration - ќбъ€вление класса     //////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////



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

	int get_size()const;
	char* get_line();
	const char* get_line()const;

	explicit String();
	explicit String(int size);
	String(const char* line);
	String(const String& line);
	String(String&& other);
	~String();

	void print()const;

	String& operator= (const String& line);
	char& operator[] (int i)const;
	String& operator+= (const String& line);
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
	String& to_upper();
	String& to_lower();

};