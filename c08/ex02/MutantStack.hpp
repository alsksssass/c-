#pragma once 
#include <stack>
#include <iterator>
#include <deque>
template<typename T, typename DQ = std::deque<T> >
class MutantStack : public std::stack<T, DQ>{
	private:
	public:
		typedef typename DQ::iterator iterator;
		typedef typename DQ::const_iterator const_iterator;
		typedef typename DQ::const_reverse_iterator const_reverse_iterator;
		typedef typename DQ::reverse_iterator reverse_iterator;
		MutantStack() : std::stack<T,DQ> (){};
		~MutantStack(){}
		MutantStack(MutantStack const &) : std::stack<T,DQ> () {};
		MutantStack& operator=(MutantStack const &a){
			if(this == &a) return *this;
			*this = a;
			return *this;
		};
		iterator begin(){
			return this->c.begin();
		};
		iterator end(){
			return this->c.end();
		};
		const_iterator begin() const {
			return this->c.begin();
		};
		const_iterator end() const {
			return this->c.end();
		};
		const_reverse_iterator rbegin() const {
			return this->c.rbegin();
		}
		const_reverse_iterator rend() const {
			return this->c.rend();
		}
		reverse_iterator rbegin(){
			return this->c.rbegin();
		}
		reverse_iterator rend(){
			return this->c.rend();
		}
};