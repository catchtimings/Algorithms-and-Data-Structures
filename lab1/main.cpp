#include <iostream>
#include "polynom.h"
#include "function.h"

int main() 
{
	try 
	{
		{
			int array1[] = { 1, 2, 3, 4, 5 };
			int array2[] = { 10,12,13,14 };
			int array3[] = { 10,11,12,13, 14 };
			const int num = 10;

			Polynom<int> p1(array1, 4);
			Polynom<int> p2(array2, 3);
			Polynom<int> p3(array3, 4);

			std::cout << "Polynom 1: " << p1 << std::endl;
			std::cout << "Polynom 2: " << p2 << std::endl;
			std::cout << "Polynom 3: " << p3 << std::endl;

			std::cout << "Polynom 1 + Polynom 3: " << p1 + p3 << std::endl;
			std::cout << "Polynom 1 - Polynom 3: " << p1 - p3 << std::endl;
			std::cout << "Polynom 1 * num: " << p1 * num << std::endl;
			std::cout << "num * Polynom 1: " << num * p1 << std::endl;

			int result_root = p1.calculate(num);
			std::cout << "Result with root " << num << ": " << result_root << std::endl;
		}
		
		std::cout << std::endl;

		{
			double array_d[] = { 10, 12, 13, 14 };
			Polynom<double> pol_d(array_d, 3);
			pol_d.expand(10);
			std::cout << "Expand double polynom: " << pol_d << std::endl;
			pol_d.shrink_to_fit();
			std::cout << "Original double polynom: " << pol_d << std::endl;
			std::cout << "Roots: " << *find_real_roots(pol_d) << std::endl;

		}

		std::cout << std::endl;

		{
			std::complex<double> complex_array[4];

			complex_array[0] = std::complex<double>(1.0, 2.0);
			complex_array[1] = std::complex<double>(3.0, 4.0);
			complex_array[2] = std::complex<double>(5.0, 6.0);
			complex_array[3] = std::complex<double>(7.0, 8.0);

			Polynom<std::complex<double>>pol_complex(complex_array, 3);

			std::cout << "Roots: " << *find_real_roots(pol_complex) << std::endl;
		}

	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Something went wrong..." << std::endl;
	}

	return 0;
}