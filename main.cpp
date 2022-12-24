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


#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 3 // the ft::vector methods can be slower up to std::vector methods * TIME_FAC (MAX 20)

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

// #include "./ft_containers-terminator/tests/tests/vector/vector_prelude.hpp"

int main ()
{              
        time_t start1, start2, end1, end2, diff1, diff2;

        ft::vector<int> v(11000000, 1);
        v.push_back(1);
        v.push_back(1);
        v.push_back(1);
        v.push_back(1);
        v.push_back(1);
        ft::vector<int> vv(10000000, 10);
            start1 = get_time();
            std::swap(v, vv);
            end1 = get_time();
            diff1 = end1 - start1;

        
        std::vector<int> v2(11000000, 1);
        std::vector<int> vv2(10000000, 10);
            start2 = get_time();
            ft::swap(vv2, v2);
            end2 = get_time();
            diff2 = end2 - start2;


        std::cout << diff1 << std::endl;
        std::cout << diff2 << std::endl;
}