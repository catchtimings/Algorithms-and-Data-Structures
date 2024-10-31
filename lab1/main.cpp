#include <iostream>
#include "polynom.h"
#include "function.h"

int main() {
	try 
	{
		int array1[] = { 1, 2, 3, 4, 5 };
		int array2[] = { 10,12,13,14 };
		int num = 10;

		Polynom<int> p1(array1, 4);
		Polynom<int> p2(array2, 3);

		std::cout << "Polynom 1: " << p1 << std::endl;
		std::cout << "Polynom 2: " << p2 << std::endl;
		std::cout << "Polynom 1 + Polynom 2: " << p1 + p2 << std::endl;
		std::cout << "Polynom 1 - Polynom 2: " << p1 - p2 << std::endl;
		std::cout << "Polynom 1 * num: " << p1 * num << std::endl;
		std::cout << "num * Polynom 1: " << num * p1 << std::endl;


		int* roots = find_real_roots(p2);
		std::cout << "Roots: " << *roots << std::endl;
	}
	catch (const std::invalid_argument& ia) {
		std::cerr << ia.what() << std::endl;
	}
	catch (const std::out_of_range& ooa) {
		std::cerr << ooa.what() << std::endl;
	}
	catch (const std::logic_error& le) {
		std::cerr << le.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Something went wrong..." << std::endl;
	}

}