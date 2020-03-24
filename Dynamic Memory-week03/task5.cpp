#include <iostream>
using namespace std;

//Да се направи клас Песен, който в себе си има изпълнител, име на песента, продължителност и жанр.За този клас трябва да се реализират :
//
//--конструктор по подразбиране
//--конструктор с параметри
//--деструктор
//--оператор за присвояване

class Song
{
private:
	char* singer;
	char* nameOfTheSong;
	char* genre;
	double duration;

	void copy(const Song& other)
	{
		this->singer = new char[strlen(other.singer) + 1];
		this->nameOfTheSong = new char[strlen(other.nameOfTheSong) + 1];
		this->genre = new char[strlen(other.genre) + 1];
		for (int i = 0; i < strlen(other.singer) + 1; i++)
		{
			this->singer[i] = other.singer[i];
		}
		for (int i = 0; i < strlen(other.nameOfTheSong) + 1; i++)
		{
			this->nameOfTheSong[i] = other.nameOfTheSong[i];
		}
		for (int i = 0; i < strlen(other.genre) + 1; i++)
		{
			this->genre[i] = other.genre[i];
		}
		this->duration = other.duration;
	}

	void erase()
	{
		delete[] this->singer;
		delete[] this->nameOfTheSong;
		delete[] this->genre;
	}
public:
	Song()
	{
		this->singer = nullptr;
		this->nameOfTheSong = nullptr;
		this->genre = nullptr;
		this->duration = 0;
	}

	Song(const char* singer, const char* nameOfTheSong, const char* genre, const int duration)
	{
		this->singer = new char[strlen(singer) + 1];
		this->nameOfTheSong = new char[strlen(nameOfTheSong) + 1];
		this->genre = new char[strlen(genre) + 1];
		for (int i = 0; i < strlen(singer) + 1; i++)
		{
			this->singer[i] = singer[i];
		}
		for (int i = 0; i < strlen(nameOfTheSong) + 1; i++)
		{
			this->nameOfTheSong[i] = nameOfTheSong[i];
		}
		for (int i = 0; i < strlen(genre) + 1; i++)
		{
			this->genre[i] = genre[i];
		}
		this->duration = duration;
	}

	Song(const Song& other)
	{
		this->copy(other);
	}

	Song& operator= (const Song& other)
	{
		if (this != &other)
		{
			this->erase();
			this->copy(other);
		}
		return *this;
	}

	~Song()
	{
		this->erase();
	}

	void print() const
	{
		cout << "Singer: " << this->singer << endl;
		cout << "Name of the song: " << this->nameOfTheSong << endl;
		cout << "Genre: " << this->genre << endl;
		cout << "Duration: " << this->duration << endl;
	}
};

int main()
{
	Song song1("Kameliq", "Luda po tebe", "chalga", 126);
	Song song2("Kameliq", "Ti si", "chalga", 117);

		song1.print();
		song2.print();
}
