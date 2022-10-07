#ifndef STACK_HPP
#define STACK_HPP

#include <memory>
#include <iterator>
#include <iostream>
#include <vector>

namespace ft {

template <class T, class Container = std::vector<T> >
class stack {
	private:
		Container c;

	public:

	typedef Container							container_type;
	typedef typename Container::value_type		value_type;
	typedef typename Container::size_type		size_type;
	typedef typename Container::reference		reference;
	typedef typename Container::const_reference	const_reference;
	
	explicit stack(const container_type& ctnr = container_type()) {
		c = ctnr;
	}

	stack(const stack& copy) {
		c = copy.c;
	}

	stack &operator=(const stack& copy) {
		c = copy.c;
		return *this;
	}

	bool empty() const {
		return c.empty();
	}

	size_t size() const { 
		return c.size();
	}

	T& top() {
		return c.back();
	}

	void push(const T& val) {
		c.push_back(val);
	}

	void pop() {
		c.pop_back();
	}
	
	friend bool operator==(const stack& lhs, const stack& rhs) {
		return lhs.c == rhs.c;
	}

	friend bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c != rhs.c;
	}

	friend bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c < rhs.c;
	}

	friend bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c <= rhs.c;
	}

	friend bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c > rhs.c;
	}

	friend bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs.c >= rhs.c;
	}

};

} // namespace ft

#endif
