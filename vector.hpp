#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iterator>
#include <iostream>
#include "iterator.hpp"

//iterator begin();
//const_iterator begin() const;
//iterator end();
//const_iterator end() const;
//reverse_iterator rbegin();
//const_reverse_iterator rbegin() const;
//reverse_iterator rend();
//const_reverse_iterator rend() const;

//size_type size() const;
//size_type max_size() const;

//Element access:
// bool empty() const;
//void reserve (size_type n);
// reference operator[] (size_type n);
// const_reference operator[] (size_type n) const;
// reference front();
// const_reference front() const;






// _LIBCPP_ASSERT(__n < size(), "vector[] index out of bounds"); operator[]

    // _LIBCPP_NORETURN void __throw_length_error() const; // - if (__n > max_size())
    // _LIBCPP_NORETURN void __throw_out_of_range() const; // - at()

namespace ft {

template <class T, class Allocator = std::allocator<T> >
class vector {
	private:
		T											*array;
		std::size_t									size_value;
		std::size_t									capacity_value;
		Allocator									alloc;

	public:

		typedef iterator_1<T> 						iterator;

		typedef T									value_type;
		typedef typename std::size_t				size_type;
		typedef typename std::ptrdiff_t				difference_type;

		typedef Allocator							allocator_type;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef typename Allocator::const_reference	const_reference;
	
	vector(std::size_t n,
		const Allocator& allocate = Allocator()) : alloc(allocate) {
		array = alloc.allocate(n);
		size_value = 0;
		capacity_value = n;
		for (std::size_t i = 0; i < n; ++i) {
			alloc.construct(array + i, &array);
		}
	}

	vector(std::size_t n, const T& val,
		const Allocator& allocate = Allocator()) : alloc(allocate) {
		array = alloc.allocate(n);
		size_value = capacity_value = n;
		for (std::size_t i = 0; i < n; ++i) {
			alloc.construct(array + i, val);
		}
	}

	vector(const Allocator& allocate = Allocator()) : alloc(allocate) {
		array = alloc.allocate(1);
		size_value = capacity_value = 0;
	}

	iterator begin() {
		iterator it(array);
		return it;
	}

	iterator end() {
		return array + size_value;
	}

	size_t size() const {
		return (this->size_value);
	}

	size_t max_size() const {
		return std::numeric_limits<std::ptrdiff_t>::max(); // заменить!!!
		//return std::numeric_limits<typename ft::iterator_traits<ft::vector<T> >::difference_type>::max();
	}

	void resize(size_t n, const T& value = T()) {
		if (capacity_value <= size_value) {
			reserve(2 * size_value);
		}
		for (size_t i = size_value; i < n; ++i) {
			alloc.construct(array + i, value);//new(array + i) T(value);
		}
		if (n < size_value) {
			size_value = n;
		}
	}

	size_t capacity() {
		return (this->capacity_value);
	}

	bool empty() const {
		if (size_value == 0) {
			 return true;
		}
		return false;
	}

	void reserve(size_t n) {
		if (n <= capacity_value) return;
		T *tmp = alloc.allocate(n); //tmp = reinterpret_cast<T*>(new int8_t[n *sizeof(T)]);
		size_t i;
		try {
			for (i = 0; i < size_value; ++i) {
				alloc.construct(tmp + i, array[i]); //new(tmp + i) T(array[i]); // placement new
			}
		} catch (...) {
			for (size_t j = 0; j < i; ++j) {
				alloc.destroy(tmp + j); //(tmp + j)->~T();
			}
			alloc.deallocate(tmp, n); //delete[] reinterpret_cast<int8_t*>(tmp);
			throw;
		}
		for (size_t i = 0; i < size_value; ++i) {
			alloc.destroy(array + i); //(array + i)->~T();
		}
		alloc.deallocate(array, size_value); //delete[] reinterpret_cast<int8_t*>(array);
		array = tmp;
		capacity_value = n;
	}

	T &operator[](unsigned int i) const {
		return array[i];
	}

	T &at(unsigned int i) const {
		if (i >= size_value)
			throw std::out_of_range(" ");
		return array[i];
	}

	T &front() {
		return begin();
	}
	
	void push_back(const T& value) {
		if (capacity_value <= size_value) {
			reserve(2 * size_value);
		}
		alloc.construct(array + size_value, value); //new (array + size_value) T(value);
		++size_value;
	}

	void pop_back() {
		--size_value;
		alloc.destroy(array + size_value); //(array + size_value)->~T();
	}

	iterator insert(iterator position, const value_type& val) {
		T *tmp = alloc.allocate(size_value + 1); 
		int pos;
		iterator it(array);
		pos = position - it;
		std::cout << "pos: " << pos << std::endl;
		int i = 0;
		for (i = 0; i < pos; ++i) {
			tmp[i] = array[i];
		}
		tmp[i] = val;
		for (i = pos + 1; i <= size_value; ++i) {
			tmp[i] = array[i - 1];
		}
		alloc.destroy(array + size_value);
		array = tmp;
		++size_value;
		return array + pos;
	}

	// void insert (iterator position, size_type n, const value_type& val) {

	// }

	// template <class InputIterator>
    // void insert (iterator position, InputIterator first, InputIterator last) {

	// }


	allocator_type get_allocator() const {
			return alloc;
	}

	~vector() {
		alloc.deallocate(array, size_value);
	}

};

// std::ostream &operator << (std::ostream &result, ft::vector<T>::iterator other);

} // namespace ft

#endif
