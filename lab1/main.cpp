#include <iostream>
#include "polynom.h"
#include "function.h"

int main() {
	try 
	{
		int array1[] = { 1, 2, 3, 4, 5 };
		int array2[] = { 10,12,13,14 };
		const int num = 10;

		Polynom<int> p1(array1, 4);
		Polynom<int> p2(array2, 3);

		std::cout << "Polynom 1: " << p1 << std::endl;
		std::cout << "Polynom 2: " << p2 << std::endl;
		std::cout << "Polynom 1 + Polynom 2: " << p1 + p2 << std::endl;
		std::cout << "Polynom 1 - Polynom 2: " << p1 - p2 << std::endl;
		std::cout << "Polynom 1 * num: " << p1 * num << std::endl;
		std::cout << "num * Polynom 1: " << num * p1 << std::endl;

		int result_root = p1.calculate(num);
		std::cout << "Result with root " << num << ": " << result_root << std::endl;

		double array_d[] = { 10, 12, 13, 14 };
		Polynom<double> pol_d(array_d, 3);
		std::cout << "Roots: " << *find_real_roots(pol_d) << std::endl;

		std::complex<double> complex_array[4];

		complex_array[0] = std::complex<double>(1.0, 2.0);
		complex_array[1] = std::complex<double>(3.0, 4.0);
		complex_array[2] = std::complex<double>(5.0, 6.0);
		complex_array[3] = std::complex<double>(7.0, 8.0);

		Polynom<std::complex<double>>pol_complex(complex_array, 3);

		std::cout << "Roots: " << *find_real_roots(pol_complex) << std::endl;
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