#pragma once
#include <exception>
template<typename T>
class Array {
	private:
		T *arr;
		unsigned int idx;
	public:
		Array() : arr(new T[0]), idx(0){
		}
		Array(const unsigned int &_idx) : arr(new T[_idx]), idx(_idx){}
		~Array(){
			delete []arr;
		};
		Array(Array const &a): arr(new T[a.size()]) , idx(a.size()){
			for(unsigned int i = 0; i < idx; i++)
				arr[i] = a[i];
		}
		Array& operator = (Array const &a){
			if(this == &a)	return *this;
			T *temp = new T [a.size()];
			delete []arr;
			arr = temp;
			idx = a.size;
			for(unsigned int i = 0; i < a.size(); i++)
				arr[i] = a[i];
		}
		unsigned int size() const {return idx;}
		T &operator [](int a){
			if(a >= (int)idx) throw std::out_of_range("range over");
			else if(a < 0) throw std::range_error("range error");
			return arr[a];
		}
		const T &operator [](const int a) const{			
			if(a >= (int)idx) throw std::out_of_range("const range over");
			else if(a < 0) throw std::range_error("const range error");
			return arr[a];
		}
};