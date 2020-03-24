#include <iostream>
using namespace std;

//Да се направи клас Телефон, който в себе си има марка, модел, цена.За този клас трябва да се реализират :

//--по подразбиране
//--конструктор с параметри
//--деструктор
//--оператор за присвояване

class Telephone
{
private:
	char* brand;
	char* model;
	double price;

	void copy(const Telephone& other)
	{
		this->brand = new char[strlen(other.brand) + 1];
		this->model = new char[strlen(other.model) + 1];
		for (int i = 0; i < strlen(other.brand) + 1; i++)
		{
			this->brand[i] = other.brand[i];
		}
		for (int i = 0; i < strlen(other.model) + 1; i++)
		{
			this->model[i] = other.model[i];
		}
		this->price = other.price;
	}

	void erase()
	{
		delete[] this->brand;
		delete[] this->model;
	}
public:
	Telephone()
	{
		this->brand = nullptr;
		this->model = nullptr;
		this->price = 0;
	}
	
	Telephone(const char* brand, const char* model, const double price)
	{
		this->brand = new char[strlen(brand) + 1];
		this->model = new char[strlen(model) + 1];
		for (int i = 0; i < strlen(brand) + 1; i++)
		{
			this->brand[i] = brand[i];
		}
		for (int i = 0; i < strlen(model) + 1; i++)
		{
			this->model[i] = model[i];
		}
		this->price = price;
	}

	Telephone(const Telephone& other)
	{
		this->copy(other);
	}

	Telephone& operator= (const Telephone& other)
	{
		if (this != &other)
		{
			this->erase();
			this->copy(other);
		}
		return *this;
	}

	~Telephone()
	{
		this->erase();
	}

	void print() const
	{
		cout << "Brand: " << this->brand << endl;
		cout << "Model: " << this->model << endl;
		cout << "Price: " << this->price << endl;
	}
};


int main()
{
	Telephone telephone("iPhone", "11", 1699.99);

		telephone.print();
}