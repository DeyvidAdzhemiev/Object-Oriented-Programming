#pragma once
#include<iostream>
#include<cassert>
#include "Vector.h"

template <class T>
Vector<T>::Vector()
{
	size = 0;
	data = nullptr;
}

template <class T>
Vector<T>::Vector(const Vector<T>& vector)
{
	this->data = new T[vector.size];
	for (size_t i = 0; i < size; i++)
	{
		this->data[i] = vector.data[i];
	}
	this->size = vector.size;
}

template <class T>
Vector<T>::Vector(size_t initial_size)
{
	size = initial_size;
	data = new T[size];
}

template <class T>
template <class InitType>
Vector<T>::Vector(size_t initial_size, const InitType& initValue)
{
	data = nullptr;
	size = 0;
	for (size_t i = 0; i < initial_size; i++)
	{
		push_back(T(initValue));
	}
}

template <class T>
void Vector<T>::push_back(const T& x)
{
	T* biggerBuffer = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		biggerBuffer[i] = data[i];
	}
	biggerBuffer[size] = x;
	++size;

	delete[]data;
	data = biggerBuffer;
}

template <class T>
void Vector<T>::push(const T& x)
{
	T* biggerBuffer = new T[size + 1];
	for (size_t i = 0; i < size; ++i)
	{
		biggerBuffer[i + 1] = data[i];
	}
	biggerBuffer[0] = x;
	++size;

	delete[]data;
	data = biggerBuffer;
}

template <class T>
Vector<T>& Vector<T>::operator+=(const T& x)
{
	this->push_back(x);
	return *this;
}

template <class T>
Vector<T> Vector<T>::operator+ (const T& x) const
{
	Vector<T> result(*this);
	result += x;
	return result;
}

template <class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other)
{
	T* newBuffer = new T[this->size + other.size];
	for (size_t i = 0; i < this->size; i++)
	{
		newBuffer[i] = this->data[i];
	}
	for (size_t i = 0; i < other.size; i++)
	{
		newBuffer[this->size + i] = other.data[i];
	}

	delete[]this->data;
	this->data = newBuffer;
	this->size = this->size + other.size;

	return *this;
}

template <class T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const
{
	Vector<T> result;

	result.data = new T[this->size + other.size];
	for (size_t i = 0; i < this->size; ++i)
	{
		result.data[i] = this->data[i];
	}
	for (size_t i = 0; i < other.size; ++i)
	{
		result.data[this->size + i] = other.data[i];
	}

	result.size = this->size + other.size;

	return result;
}

template <class T>
T& Vector<T>::operator[](size_t i)
{
	asseert[i >= 0];
	assert[i < size];
	return data[i];
}

template <class T>
T Vector<T>::operator[] (size_t i) const
{
	assert(i >= 0);
	assert(i < size);
	return data[i];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vector)
{
	if (this != &vector)
	{
		delete[]data;

		this->size = vector.size;
		this->data = new T[vector.size];
		for (size_t i = 0; i < size; i++)
		{
			this->data[i] = vector.data[i];
		}
	}
	return *this;
}

template <class T>
size_t Vector<T>::length() const
{
	return size;
}

template <class T>
Vector<T>::~Vector()
{
	delete[] data;
}

template <class T>
std::ostream& operator<< (std::ostream& stream, const Vector<T>& vector)
{
	stream << "[";
	for (size_t i = 0; i < vector.length(); i++)
	{
		std::cout << vector[i] << " ";
	}
	stream << "]";

	return stream;
}
