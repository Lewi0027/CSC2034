#include <iostream>

template <typename T>
void funct(T first) {
	std::cout << first << std::endl;
}
template <typename T>
void funct(T first, T second) {
	std::cout<< first + second << std::endl;
}
template <typename T>
void funct(T first, T second, T third) {
	std::cout << first - second + third << std::endl;
}
template <>
void funct(int first) {
	std::cout << "Special case for one int: " << first*first << std::endl;
}
template <>
void funct(int first, int second) {
	std::cout << "int case: " << first + second << std::endl;
}
int main() {
	funct<int>(4);
	funct<int>(3, 5);
	funct<char>('2', '1', '3');
	return 0;
}


////