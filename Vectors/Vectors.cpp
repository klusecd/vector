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
		push_back(data[size - 1]);
		for (int i = size - 1; i > index; i--)
			data[i] = data[i - 1];
		data[index] = elem;
	}

	void erase(int index)
	{
		for (int i = index; i < size; i++)
			data[i] = data[i + 1];
		size--;
	}

	void push_front(T elem) { 
		insert(elem, 0);
	}

	void pop_front() { 
		erase(0);
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