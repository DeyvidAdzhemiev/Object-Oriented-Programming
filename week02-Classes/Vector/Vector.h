#pragma once

template <class T>
class Vector
{
private:
	T* data;
	size_t size;

public:
	Vector();
	Vector(const Vector<T>& vector);
	Vector(size_t initial_size);
	template <class InitType>
	Vector(size_t initial_size, const InitType& initValue);
	void push_back(const T& x);
	void push(const T& x);
	Vector<T>& operator+=(const T& x);
	Vector<T> operator+(const T& x) const;
	Vector<T>& operator+=(const Vector<T>& other);
	Vector<T> operator+(const Vector<T>& other) const;
	T& operator[](size_t i);
	T operator[](size_t i) const;
	Vector<T>& operator= (const Vector<T>& vector);
	size_t length () const;
	~Vector();
};

template <class T>
std::ostream& operator<< (std::ostream& stream, const Vector<T>& vector);