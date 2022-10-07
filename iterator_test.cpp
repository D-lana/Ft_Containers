//#include "vector.hpp"
#include "iterator.hpp"

#include <vector>
#include <list>

int main() {
	std::list<int> s;
	for (int i = 0; i < 100; ++i) {
		s.push_back(i);
	}
	std::list<int>::iterator it = s.begin();
	std::list<int>::iterator end = s.end();
	ft::advance(it, 25);
	std::cout << *it << std::endl;
	std::cout <<  "distance: " << std::distance(it, end) << std::endl;
	std::cout <<  "distance: " << ft::distance(it, end) << std::endl;
	
	// ft::vector<int> x(4, 100);
	// std::cout << x[100] << std::endl;
	// std::vector<int> y(5, 150);
	// std::cout << y[100] << std::endl;
	// std::vector<int> y2(10, 150);
	// std::cout << y2[1] << std::endl;
	// std::cout << y.capacity() << std::endl;
	// std::cout << y2.capacity() << std::endl;
	// y2.push_back(10);
	// std::cout << y2.capacity() << std::endl;
	// std::cout << x.capacity() << std::endl;
	// std::cout << x.size() << std::endl;
}
