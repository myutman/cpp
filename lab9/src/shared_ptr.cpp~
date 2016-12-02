#include "shared_ptr.h"
#include <algorithm>

shared_ptr::shared_ptr(Matrix* obj){
	//std::cerr << "hello1\n";	
	storage_ = new Storage(obj);
	//std::cerr << "hello1\n";
}

shared_ptr::shared_ptr(const shared_ptr& other){
	storage_ = other.storage_;
	storage_->incr();
}

void shared_ptr::swap(shared_ptr& other){
	std::swap(storage_, other.storage_);
}

shared_ptr& shared_ptr::operator=(const shared_ptr &other){	
	if (this != &other){	
		shared_ptr tmp(other);
		(*this).swap(tmp);
	}
	return *this;
}

shared_ptr::~shared_ptr(){
	storage_->decr();
	if (!storage_->getCounter()){
		delete storage_;
	}
}

Matrix* shared_ptr::ptr() const{
	return storage_->getObject();
}

bool shared_ptr::isNull() const{
	return storage_->getObject() == NULL;
}

void shared_ptr::reset(Matrix* obj){
	storage_->decr();
	if (!storage_->getCounter()){
		delete storage_;
	}
	storage_ = new Storage(obj);
}

Matrix* shared_ptr::operator->() const{
	return ptr();
}

Matrix& shared_ptr::operator*() const{
	return *ptr();
}
