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
#include <random>
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

template <typename Iter1, typename Iter2>
bool compareMaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    return true;
}


volatile static time_t g_start1;
volatile static time_t g_start2;
volatile static time_t g_end1;
volatile static time_t g_end2;

time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}

    void assign_overload_test() {
        std::vector<int> v;
        ft::map<int, int> mp;
        for (int i = 0, j = 10; i < 20 * 10000; ++i, ++j)
            mp.insert(ft::make_pair(i, j));
        ft::map<int, int> mp2;
        for (int i = 20 * 10000, j = 200010; i < 40 * 10000; ++i, ++j)
            mp2.insert(ft::make_pair(i, j));
        g_start1 = timer();
        mp2 = mp;
        g_end1 = timer();
        ft::map<int, int>::iterator it = mp2.begin();
    }


int main ()
{
    assign_overload_test();
    system ("leaks a.out");
}
