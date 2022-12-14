// Array.cpp: определяет экспортированные функции для приложения DLL.
//

#include "Array.hpp"
#include "cstdio"

template <class T>
int Array<T>::size()
{
	if (p == nullptr) {
		return 0;
	}
	return idx;
}

template <class T>
T* Array<T>::c_array() {
	return p;
}

template <class T>
T Array<T>::at(int index)
{
	if (index >= arr_size) {
		throw(out_of_range);
	}
	return p[index];
}

template <class T>
Array<T>::Array()
{
	p = nullptr;
	arr_size = 0;
}

template <class T>
Array<T>::~Array()
{
	if (p != nullptr) {
		delete[] p;
	}
}

template <class T>
T& Array<T>::operator[](int index)
{
	if (p == nullptr) {
		throw(empty_array);
	}
	if (index >= arr_size) {
		throw(out_of_range);
	}
	return p[index];
}

template <class T>
void Array<T>::push_back(T obj) {
	if (p == nullptr) {
		arr_size = 16;
		p = new T[arr_size];
	}
	if (idx >= arr_size) {
		Resize(idx);
	}
	p[idx++] = obj;
}

template <class T>
bool Array<T>::empty() {
	if (p == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
void Array<T>::Resize(int required_index)
{
	int new_arr_size = arr_size;
	while (new_arr_size <= required_index) {
		new_arr_size *= 2;
	}
	T* new_Arrayay = new T[new_arr_size];
	for (int i = 0; i < arr_size; i++) {
		new_Arrayay[i] = p[i];
	}
	delete[] p;
	p = new_Arrayay;
	arr_size = new_arr_size;
}

template <class T>
void Array<T>::print_Array(void(*f) (T))
{
	if (p == nullptr) {
		throw(empty_array);
	}
	int i = 0;
	while (i<idx) {
		printf("%i: ", i);
		f(p[i]);
		printf("\n");
		i++;
	}
}



