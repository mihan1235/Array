#pragma once

template <class T>


class Array
{
	int arr_size;
	int idx = 0;
public:
	T & operator[](int idx);
	void print_Array(void(*f) (T));
	T at(int index);
	int size();
	T* c_array();
	void push_back(T obj);
	bool empty();
	Array();
	~Array();
private:
	void operator=(const Array<T>& ref) {};
	Array(const Array<T>& ref) {};
	void Resize(int required_index);
protected:
	T * p = nullptr;
};

enum error_arr {
	empty_array,
	out_of_range
};

