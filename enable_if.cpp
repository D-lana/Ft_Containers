// #ifndef VECTOR_HPP
// #define VECTOR_HPP

// #include <memory>
// #include <iterator>
#include <iostream>

#include <vector>
#include <type_traits>

// namespace ft {

template <typename T, typename = std::enable_if<std::is_class<T>::value,bool> >
void f(const T&) {
	std::cout << 1;
}

void f(...) {
	std::cout << 2;
}
// template <bool Cond, class T = void>
// struct enable_if {

// };

// template <class T>
// typename std::enable_if<std::is_integral<T>::value,bool>::type
// is_odd (T i) {
// 	return bool(i%2);
// }

// } // namespace ft

int main() {
	std::string s("abc");
	f(s);
	f(1);
}

// #endif
