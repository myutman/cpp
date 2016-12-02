#pragma once

#include "matrix.h"
#include <iostream>

class shared_ptr {
  public:
    shared_ptr(Matrix* obj = 0);
    shared_ptr(const shared_ptr& other);
    shared_ptr& operator=(const shared_ptr &other);
    ~shared_ptr();
	void swap(shared_ptr& other);

    Matrix* ptr() const;
    bool isNull() const;
    void reset(Matrix* obj = 0);

    Matrix* operator->() const;
    Matrix& operator*() const;

  private:
    class Storage {
      public:	
        Storage(Matrix* mtx){
			//std::cerr << "hello\n";
			data_ = mtx;
			ref_count_ = 1;
			//std::cerr << "hello\n";
		}
        ~Storage(){
			delete data_;
		}

        void incr(){
			ref_count_++;
		}
        void decr(){
			ref_count_--;
		}

        int getCounter() const{
			return ref_count_;
		}
        Matrix* getObject() const{
			return data_;
		}

      private:
        Matrix *data_;
        int ref_count_;
    };

  private:
    Storage *storage_;
};
