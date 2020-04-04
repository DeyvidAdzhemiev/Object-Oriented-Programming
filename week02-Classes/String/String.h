#pragma once
#include <iostream>
#include <cstring>
using namespace std;


class String
{
private:
	char* str;

public:
	String();
	String(const char* str);
	String(char* str);
	String(const String &other);
	void init(const char* str);
	void print();
	String operator+(String other);
	bool operator==(String other);
	bool operator<(String other);
	char& operator[](size_t i);
	String operator=(char c);
	String toString(unsigned int x);
	String toUpper(String s);
	ostream& operator<< (ostream& out, String s);
	istream& operator>> (istream& in, String& s);
};




