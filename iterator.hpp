#ifndef iterator_HPP
#define iterator_HPP

#include <memory>
#include <iterator>
#include <iostream>

namespace ft {

template <class T>
class iterator_1 : public std::iterator<std::input_iterator_tag, T>
	{
	T* p;
	public:
	iterator_1(T* x) :p(x) {
	}
	~iterator_1() {
	}

	iterator_1(const iterator_1& copy) : p(copy.p) {

	}

	iterator_1 &operator=(const iterator_1& copy) {
		p = copy.p;
		return *this;
	}

	iterator_1 &operator++() {
		//std::cout << "Iter 1\n";
		this->p++;
		return *this;
	}

	iterator_1 operator++(int) {
		//std::cout << "Iter 2\n";
		iterator_1 tmp(*this);
		this->p++;
		//std::cout << "Iter 3\n";
		return tmp;
	}

	iterator_1& operator--() {
		--p;
		return *this;
	}
	iterator_1 operator--(int) {
		iterator_1 tmp(*this);
		operator--();
		return tmp;
	}

	bool operator==(const iterator_1& rhs) const {
		return p==rhs.p;
	}
	bool operator!=(const iterator_1& rhs) const {
		return p!=rhs.p;
	}
	T& operator*() {
		return *p;
	}
	T* operator->() {
		return p;
	}

	iterator_1& operator-=(int i) const {
		p -= i;
		return p;
	}

	iterator_1& operator+=(int i) const {
		p += i;
		return p;
	}

	iterator_1& operator-(int i) const {
		iterator_1 tmp = *this;
		tmp -= i;
		return tmp;
	}

	iterator_1 operator+(int i) {
		iterator_1 tmp(*this);
		tmp.p += i;
		return tmp;
	}

	int operator-(const iterator_1& rhs) {
		iterator_1 tmp = *this;
		int i;
		for (i = 0; rhs != tmp; ++i) {
			tmp++;
		}
		return i;
	}

	// iterator_1& operator<(const iterator_1& rhs) const {
	// 	//iterator_1 tmp = *this;


	// 	return tmp;
	// }

};


struct Category {
	struct input_iterator_tag : public std::input_iterator_tag {};
	struct output_iterator_tag : public std::output_iterator_tag {};
	struct forward_iterator_tag : public std::forward_iterator_tag {};
	struct bidirectional_iterator_tag : public std::bidirectional_iterator_tag {};
	struct random_access_iterator_tag : public std::random_access_iterator_tag {};
};

template <class Category, class T, class Distance = ptrdiff_t,
		class Pointer = T*, class Reference = T&>
struct Iterator {
	typedef T         value_type;
	typedef Distance  difference_type;
	typedef Pointer   pointer;
	typedef Reference reference;
	typedef Category  iterator_category;
};

template <class Iterator >
struct iterator_traits {
	typedef typename Iterator::difference_type difference_type;
	typedef typename Iterator::value_type value_type;
	typedef typename Iterator::pointer pointer;
	typedef typename Iterator::reference reference;
	typedef typename Iterator::iterator_category iterator_category;
};


template <class Iterator, class Distance>
void	advance_category(Iterator &it, Distance n,
	std::random_access_iterator_tag) {
	it += n;
}

template <class Iterator, class Distance, class IterCategory>
void	advance_category(Iterator &it, Distance n, IterCategory) {
	for (int i = 0; i < n; ++i) {
		++it;
	}
}

template <class Iterator, class Distance>
void	advance(Iterator& it, Distance n) {
	advance_category(it, n,
		typename ft::iterator_traits<Iterator>::iterator_category());
}

template <class Iterator, class IterCategory>
typename iterator_traits<Iterator>::difference_type
	distance_category(Iterator first, Iterator last, IterCategory) {
	int tmp = 0;
	Iterator it = first;
	while (it != last) {
		++tmp;
		++it;
	}
	return(tmp);
}

template <class Iterator>
typename iterator_traits<Iterator>::difference_type
	distance_category(Iterator first, Iterator last, std::random_access_iterator_tag) {
	return(last - first);
}

template <class Iterator>
typename iterator_traits<Iterator>::difference_type
	distance (Iterator first, Iterator last) {
		return(distance_category(first, last,
			typename ft::iterator_traits<Iterator>::iterator_category()));
}


} // namespace ft

#endif
