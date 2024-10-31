#include <iostream>
#include "polynom.h"
#include "function.h"

int main() {
	try 
	{
		int array[] = { 1, 2, 3, 4, 5 };
		double array_d[] = { 2.45, 6.46, 3.29 };

		Polynom<int> p1(array, 4);
		Polynom<double> p2(array_d, 2);


		std::cout << p1;
		std::cout << p2;

		double* result = find_real_roots(p2);
		std::cout << result;
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