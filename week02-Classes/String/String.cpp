#include <iostream>
#include <cstring>
#include <fstream>
#include "String.h"
using namespace std;

class String
{
private:
	char *str;

	void copy(const String& other)
	{
		this->str = new char[strlen(other.str) + 1];
		for (size_t i = 0; i < strlen(other.str) + 1; i++)
		{
			this->str[i] = other.str[i];
		}
	}
	void erase()
	{
		delete[] this->str;
	}

	void initialize(const char* s)
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}

	void print()
	{
		cout << str << endl;
	}

public:
	String()
	{
		char* str = nullptr;
	}

	String(const char* s)
	{
		this->str = new char[strlen(str) + 1];
		for (size_t i = 0; i < strlen(str) + 1; i++)
		{
			this->str[i] = str[i];
		}
	}

	String(const String& other)
	{
		this->copy(other);
	}

	String operator+ (String other)
	{
		String result;
		result.str = new char[strlen(str) + strlen(other.str) + 1];
		strcpy(result.str, str);
		strcat(result.str, other.str);

		return result;
	}

	bool operator==(String other)
	{
		return strcmp(str, other.str) == 0;
	}

	bool operator<(String other)
	{
		return strcmp(str, other.str) < 0;
	}
	
	char& operator[](size_t i)
	{
		return str[i];
	}

	String operator=(char c)
	{
		str = new char[2];
		str[0] = c;
		str[1] = 0;
		return *this;
	}

	String toString(unsigned int x)
	{
		String result;

		if (x < 10)
		{
			result = '0' + x;
			return result;
		}
		while (x > 0)
		{
			result = ('0' + x % 10) + result;
			x /= 10;
		}
		return result;
	}

	size_t length() const
	{
		return strlen(str);
	}

	String toUpper(String s)
	{
		String result = s.str;

		for (size_t i = 0; i < result.length(); i++)
		{
			if (result[i] >= 'a' && result[i] <= 'z')
			{
				result[i] = result[i] + ('A' - 'a');
			}
		}
		return result;
	}

	ostream& operator<< (ostream& out, String s)
	{
		out << s.str;
		return out;
	}

	istream& operator>> (istream& in, String& s)
	{
		char c;
		do
		{
			c = in.get();
			if (c != '\n')
			{
				s = s + c;
			}
		} while (c != '\n');

		return in;
	}


};

