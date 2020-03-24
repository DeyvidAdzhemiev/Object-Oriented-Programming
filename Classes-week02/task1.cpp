#include <iostream>
#include <string>
#include <vector>
using namespace std; 


class Product
{
private:
	string name;
	size_t expiringIn;
	float fats;
	bool isFood;
	double price;
public:
	Product()
	{
		this->name = "NaN";
		this->expiringIn = 0;
		this->fats = 100;
		this->isFood = 0;
		this->price = 0;
	}

	Product(string name, size_t expiringIn, float fats, bool isFood, double price)
	{
		this->name = name;
		this->expiringIn = expiringIn;
		this->fats = fats;
		this->isFood = isFood;
		this->price = price;
	}

	Product(const Product& other)
	{
		this->name = other.name;
		this->expiringIn = other.expiringIn;
		this->fats = other.fats;
		this->isFood = other.isFood;
		this->price = other.price;
	}
	
	//Setters
	void setName(string name)
	{
		this->name = name;
	}
	void setExpiry(size_t expiringIn) 
	{
		this->expiringIn = expiringIn;
	}
	void setFats(float fats) 
	{
		this->fats = fats;
	}
	void setFoodStatus(bool isFood0)
	{
		this->isFood = isFood;
	}
	void setPrice(double price) 
	{
		this->price = price;
	}

	//Getters
	string getName() const
	{
		return this->name;
	}
	size_t getExpiry() const
	{
		return this->expiringIn;
	}
	float getFats() const
	{
		return this->fats;
	}
	bool getFoodStatus()const
	{
		return this->isFood;
	}
	double getPrice() const
	{
		return this->price;
	}
};
		
class Store
{
private: 
	size_t currentProduct;
	vector <Product> products;
	double earnings;
public:
	Store()
	{
		this->currentProduct = this->products.size;
		this->earnings = 0;
	}
	Store(const Store& other)
	{
		this->currentProduct = other.currentProduct;
		this->products = other.products;
		this->earnings = other.earnings;
	}

	//Setters
	void setNumberOfProducts(size_t currentProduct)
	{
		this->currentProduct = currentProduct;
	}
	void setProducts(vector<Product> products)
	{
		this->products = products;
	}
	void setEarning(double earnings)
	{
		this->earnings = earnings;
	}


	//Getters
	size_t getNumberOfPRoducts() const
	{
		return this->currentProduct;
	}
	vector<Product> getProduct() const
	{
		return this->products;
	}
	double getEarnings() const
	{
		return this->earnings;
	}


	bool findByName(string name)
	{
		for (int i = 0; i < this->products.size; i++)
		{
			if (this->products[i].getName() == name)
			{
				return true;
			}
		}
		return false;
	}

	Product lowestFatsProducts()
	{
		Product lowestFats;
		for (int i = 0; i < this->products.size; i++)
		{
			if (this->products[i].getFats < lowestFats.getFats())
			{
				lowestFats.setName = this->products[i].getName();
			}
		}
		return lowestFats;
	}
};

int main()
{

}