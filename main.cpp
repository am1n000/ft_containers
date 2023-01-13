#include <iostream>
#include <vector>
#include <map>
#include "vector.hpp"
#include "map.hpp"
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
// #include "./ft_containers-terminator/tests/tests/vector/vector_prelude.hpp"


// #define BLUE "\e[0;34m"
// #define RED "\e[0;31m"
// #define GREEN "\e[0;32m"
// #define YELLOW "\e[1;33m"
// #define RESET "\e[0m"
#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 3 // the ft::vector methods can be slower up to std::vector methods * TIME_FAC (MAX 20)

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

namespace ft
{
    template <typename T>
    struct less {
    bool operator()(const T& x, const T& y) const {
        return x < y;
    }
    };
};
struct MyCompare {
    bool operator()(int a, int b) const {
        
        return a < b;
    }
};

int main ()
{
    ft::map<int, char> s;
    s.insert(ft::make_pair(10, 'a'));
    ft::map<int, char> s2(s);
    // s.insert(ft::make_pair(5, 'b'));
    // s[15] = 'c';
    // s[20] = 'd';
    // s[13] = 'e';
    // s[7] = 'f';
    // s[4] = 'g';
    // for (ft::map<int, char>::iterator it = s.begin(); it != s.end(); it++)
    //     std::cout << it->first << std::endl;
    
}
