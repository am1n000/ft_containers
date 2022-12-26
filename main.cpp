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


int main ()
{      
    std::map<int,char> words;
    words.insert(std::make_pair(5, 'a'));        
    words.insert(std::make_pair(6, 'b'));
    words.insert(std::make_pair(4, 'c'));
    words.insert(std::make_pair(7, 'd'));
    words.insert(std::make_pair(3, 'e'));
    words.insert(std::make_pair(8, 'f'));
    words.insert(std::make_pair(1, 'g'));
    // for (std::map<int, char>::iterator it = words.begin(); it != words.end(); it++)
    std::map<int, char>::iterator it = words.end();
        std::cout <<it->first << " :: " << it->second << std::endl;
}