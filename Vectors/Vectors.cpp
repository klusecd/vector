#pragma once

template<class T>
class Vector
{
private:
	T* data;
	size_t size;
	size_t capacity;
public:
	Vector()
	{
		data = nullptr;
		size = 0;
		capacity = 0;
	}

	~Vector()
	{
		if (data) {
			delete[]data;
			data = nullptr;
		}
	}

	Vector(int n)
	{
		size = n;
		capacity = n;
		data = new T[n];
		for (int i = 0; i < n; i++)
			data[i] = 0;
	}

	Vector(int n, T* arr)
	{
		size = n;
		capacity = n;
		data = new T[size];
		for (size_t i = 0; i < size; i++)
			data[i] = arr[i];
	}

	Vector(const Vector& v) {
		delete[]data;
		size = v.size;
		capacity = v.capacity;
		T* data = new T[size];
		for (size_t i = 0; i < size; i++)
			data[i] = v.data[i];
	}

	void push_back(T elem)
	{
		if (size == capacity)
		{
			capacity *= 2.0;
			T *a = new int[capacity];
			memmove(a, data, sizeof(*data) * size);
			delete[] data;
			data = a;
		}
		data[size++] = elem;
	}

	void pop_back() {
		size--;
	}

	void resize(int capacity_)
	{
		T* a = new T[capacity_];
		if (size >= capacity_)
		{
			for (size_t i = 0; i < capacity_; i++)
				a[i] = data[i];
			size = capacity_;
		}
		else
		{
			for (size_t i = 0; i < size; i++)
				a[i] = data[i];
		}
		delete[] data;
		capacity = capacity_;
		data = a;
		return *this;
	}

	void insert(T Elem, int index)
	{
		T* a = new T[size + 1];
		unsigned int i;
		for (int i = 0; i < index; i++)
			a[i] = data[i];
		a[index] = Elem;
		for (i = index; i < size; i++)
			a[i + 1] = data[i];
		if (data != nullptr)
			delete[] data;
		data = a;
	}

	void erase(int index)
	{
		T* a = new T[capacity];
		for (int i = 0; i < index - 1; i++)
			a[i] = data[i];
		for (int i = index - 1; i < size; i++)
			a[i] = data[i + 1];
		delete[]data;
		data = a;
		size--;
	}

	T& operator[](int index)
	{
		return this->data[index];
	}
	T operator[](int index)const
	{
		return this->data[index];
	}

};