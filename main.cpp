#include "vector.hpp"
#include "iterator.hpp"
#include "stack.hpp"

#include <vector>

int main() {
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
	std::vector<int> y2(10, 150);
	ft::vector<int> x2;
	x2.push_back(777);
	x2.push_back(2);
	x2.push_back(8);
	std::cout << x2.at(0) << std::endl;
	std::cout << x2.size() << std::endl;
	//ft::vector<int>::iterator it_1 = x2.begin();
	ft::vector<int>::iterator it_2 = x2.end();
	//std::cout << *++it << std::endl;
	std::cout << *it_2 << std::endl;
	ft::vector<int>::iterator it_3 = x2.begin();
	++it_3;
	std::cout << "My vec: " << *x2.insert(it_3, 888) << std::endl;
	++it_3;
	std::cout << "My vec contains:";
	ft::vector<int>::iterator it_1 = x2.begin();
	for (it_1 = x2.begin(); it_1 != x2.end(); it_1++)
	std::cout << ' ' << *it_1;
	std::cout << '\n';
	++it_3;
	std::cout << "ffff" << *it_3 << std::endl;
	std::cout << "My vec: " << *x2.insert(it_3, 888) << std::endl;
	std::cout << "My vec contains:";
	ft::vector<int>::iterator it_4 = x2.begin();
	for (it_4 = x2.begin(); it_4 != x2.end(); it_4++)
	std::cout << ' ' << *it_4;
	std::cout << '\n';
	// ft::stack<int> st_1;
	// st_1.push(5);
	// st_1.push(10);
	// std::cout << st_1.size() << std::endl;
	std::vector<int> myvector (3,100);
	std::vector<int>::iterator it;
	std::cout << myvector.size() << std::endl;
	it = myvector.begin();
	it = myvector.insert ( it , 200 );
	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
	std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << myvector.size() << std::endl;
	std::cout << *myvector.insert(myvector.begin(), 555) << std::endl;
	// myvector.insert(it,2,300);

	// // "it" no longer valid, get a new one:
	// it = myvector.begin();

	// std::vector<int> anothervector (2,400);
	// myvector.insert (it+2,anothervector.begin(),anothervector.end());

	// int myarray [] = { 501,502,503 };
	// myvector.insert (myvector.begin(), myarray, myarray+3);

	// std::cout << "myvector contains:";
	// for (it=myvector.begin(); it<myvector.end(); it++)
	// std::cout << ' ' << *it;
	// std::cout << '\n';

}
