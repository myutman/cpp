#include "my_vector.h"
#include <cassert>
#include <algorithm>
#include <iostream>

MyVector::MyVector(){
	_data = new int[2];
	_sz = 0;
	_cp = 2;
}

MyVector::MyVector(std::size_t init_capacity){
	_data = new int[init_capacity];
	_sz = 0;
	_cp = init_capacity;
}

MyVector::~MyVector(){
	delete []_data;
}

void MyVector::set(std::size_t index, int value){
	assert(index < _sz);
	_data[index] = value;
}

int MyVector::get(std::size_t index){
	assert(index < _sz);
	return _data[index];
}

std::size_t MyVector::size(){
	return _sz;
}

std::size_t MyVector::capacity(){
	return _cp;
}

void MyVector::reserve(std::size_t new_capacity){
	if (new_capacity < _cp) return;
	int *temp = new int[new_capacity];
	_cp = new_capacity;
	for (std::size_t i = 0; i < _sz; i++)
		temp[i] = _data[i];
	std::swap(_data, temp);
	delete []temp;
}

void MyVector::resize(std::size_t new_size){
	//std::cerr << "ola\n";	
	if (new_size > _cp){		
		//std::cerr << "hey\n";		
		std::size_t new_capacity = _cp;
		while (new_capacity < new_size)
			new_capacity += new_capacity;
		//std::cerr << "Hello\n";
		reserve(new_capacity);
	}
	//std::cerr << "ola\n";	
	for (std::size_t i = _sz; i < new_size; i++)
		_data[i] = 0;
	_sz = new_size;
}
  
void MyVector::push_back(int value){
	if (_sz >= _cp)
		reserve(2 * _cp);
	_data[_sz++] = value;
}

void MyVector::insert(std::size_t index, int value){	
	std::cerr << index << "\n";
	//std::cerr << "hello\n";
	resize(std::max(_sz + 1, index + 1));
	//std::cerr << "lul\n";
	if (index < _sz)
		for (std::size_t i = (std::size_t)((int)_sz - 1); i > index; i--){
			_data[i] = _data[i - 1];
		}
	//std::cerr << "lal\n";
	_data[index] = value;
}

void MyVector::erase(std::size_t index){
	assert(index < _sz);
	for (std::size_t i = index; i < _sz - 1; i++)
		_data[i] = _data[i + 1];
	_sz--;
}
