#include <iostream>
#include <vector>
#include "vector.hpp"
#include <sstream>
#include<string>
#include <vector>
#include <iostream>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define BLUE "\e[0;34m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[1;33m"
#define RESET "\e[0m"


#include "./ft_containers-terminator/tests/tests/vector/vector_prelude.hpp"
#include <stdexcept>

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 3 // the ft::vector methods can be slower up to std::vector methods * TIME_FAC (MAX 20)

void test()
{
	ft::vector<int> t(10, 10);
	ft::vector<int> t2(t);
	system("leaks a.out");
}

int main ()
{
	ft::<T> vector(3, 3);

}