#include <iostream>
using namespace std;

struct Student
{
	char name[20];
	int EGN[10];
	int facultyNumber;
	double grades[5];

};

void initialize(Student& student)
{
	cout << "EGN - ";
	for (int i = 0; i < 10; i++)
	{
		cin >> student.EGN[i];
	}
	
	cout << "Faculty number - ";
	cin >> student.facultyNumber;

	cout << "Grades - ";
	for (int i = 0; i < 5; i++)
	{
		cin >> student.grades[i];
	}
}

int main()
{
	Student pesho;
	char name[20];
	cin.get(name, 20);
	initialize(pesho);
}