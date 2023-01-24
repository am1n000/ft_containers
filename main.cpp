#include <iostream>
#include <vector>
#include <map>
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "set.hpp"
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


#define BLUE "\e[0;34m"
#define R "\e[0;31m"
#define G "\e[0;32m"
#define Y "\e[1;33m"
#define RESET "\e[0m"

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}


time_t start1;
time_t start2;
time_t end1;
time_t end2;

void    vector_test()
{        
    std::cout << BLUE << "|-----------------------------------------------------------------------------------|" << std::endl;
    std::cout << "|------------------------------------" << RESET <<" VECTOR " << BLUE << "---------------------------------------|" << std::endl;
    std::cout << "|-----------------------------------------------------------------------------------|" << RESET << std::endl;


    {
        std::cout << "|" << RESET <<"fill constructor       . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        start1 = get_time();
        std::vector<std::string> std_v(1e5, "fill constructor test");
        end1 = get_time();

        start2 = get_time();
        ft::vector<std::string> ft_v(1e5, "fill constructor test");
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"range constructor      . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::vector<std::string> v(1e5, "range constructor test");
        start1 = get_time();
        std::vector<std::string> std_v(v.begin(), v.end());
        end1 = get_time();

        start2 = get_time();
        ft::vector<std::string> ft_v(v.begin(), v.end());
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"copy constructor       . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::vector<std::string> v(1e5, "copy constructor test");
        ft::vector<std::string> v2(1e5, "copy constructor test");
        start1 = get_time();
        std::vector<std::string> std_v(v);
        end1 = get_time();

        start2 = get_time();
        ft::vector<std::string> ft_v(v2);
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"operator=              . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::vector<std::string> v(1e5, "operator= test");
        ft::vector<std::string> v2(1e5, "operator= test");
        start1 = get_time();
        std::vector<std::string> std_v = v;
        end1 = get_time();

        start2 = get_time();
        ft::vector<std::string> ft_v = v2;
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"begin                  . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::vector<std::string> std_v(1000, "begin");
        start1 = get_time();
        std::vector<std::string>::iterator b = std_v.begin();
        std::vector<std::string>::const_iterator cb  = std_v.begin();
        (void)b;
        (void)cb;
        end1 = get_time();

        ft::vector<std::string> ft_v(1000, "begin");
        start2 = get_time();
        ft::vector<std::string>::iterator ft_b  = ft_v.begin();
        ft::vector<std::string>::const_iterator ft_cb  = ft_v.begin();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"end                    . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::vector<std::string> std_v(1000, "end");
        start1 = get_time();
        std::vector<std::string>::iterator b = std_v.end();
        std::vector<std::string>::const_iterator cb  = std_v.end();
        (void)b;
        (void)cb;
        end1 = get_time();

        ft::vector<std::string> ft_v(1000, "end");
        start2 = get_time();
        ft::vector<std::string>::iterator ft_b  = ft_v.end();
        ft::vector<std::string>::const_iterator ft_cb  = ft_v.end();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"size                   . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::vector<std::string> std_v(1000, "size");
        start1 = get_time();
        size_t std_size = std_v.size();
        end1 = get_time();

        ft::vector<std::string> ft_v(1000, "size");
        start2 = get_time();
        size_t ft_size = ft_v.size();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {
            if (std_size != ft_size)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"capacity               . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::vector<std::string> std_v(1000, "capacity");
        start1 = get_time();
        size_t std_capacity = std_v.capacity();
        end1 = get_time();

        ft::vector<std::string> ft_v(1000, "capacity");
        start2 = get_time();
        size_t ft_capacity = ft_v.capacity();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {
            if (std_capacity != ft_capacity)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"max_size               . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::vector<std::string> std_v(1000, "max_size");
        start1 = get_time();
        size_t std_size = std_v.max_size();
        end1 = get_time();

        ft::vector<std::string> ft_v(1000, "max_size");
        start2 = get_time();
        size_t ft_size = ft_v.max_size();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {
            if (std_size != ft_size)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"resize                 . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::vector<std::string> std_v(1000, "resize");
        start1 = get_time();
        std_v.resize(25000);
        end1 = get_time();

        ft::vector<std::string> ft_v(1000, "resize");
        start2 = get_time();
        ft_v.resize(25000);
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {            
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (std_v.capacity() != ft_v.capacity() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"empty                  . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::vector<std::string> std_v(1000, "empty");
        start1 = get_time();
        bool std_empty = std_v.empty();
        end1 = get_time();

        ft::vector<std::string> ft_v(1000, "empty");
        start2 = get_time();
        bool ft_empty =  ft_v.empty();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {            
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (std_empty != ft_empty || std_v.empty() != ft_v.empty() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"[]                     . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::vector<std::string> std_v(1000, "[]");
        start1 = get_time();
        std_v[999] = "test";
        end1 = get_time();

        ft::vector<std::string> ft_v(1000, "[]");
        start2 = get_time();
        ft_v[999] = "test";
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {            
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (std_v.size() != ft_v.size() || std_v.size() != ft_v.size() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"front                  . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::vector<std::string> std_v(1000, "[]");
        start1 = get_time();
        end1 = get_time();

        ft::vector<std::string> ft_v(1000, "[]");
        start2 = get_time();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {            
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (std_v.size() != ft_v.size() || std_v.size() != ft_v.size() || data1 != data2 || std_v.front() != ft_v.front())
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"back                   . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::vector<std::string> std_v(1000, "[]");
        start1 = get_time();
        end1 = get_time();

        ft::vector<std::string> ft_v(1000, "[]");
        start2 = get_time();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {            
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (std_v.size() != ft_v.size() || std_v.size() != ft_v.size() || data1 != data2 || std_v.back() != ft_v.back())
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"assign                 . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::vector<std::string> v(1000, "assign");
        std::vector<std::string> v2(1000, "assign");

        std::vector<std::string> std_v(1000, "assign");
        start1 = get_time();
        std_v.assign(v.begin(), v.end());
        end1 = get_time();

        ft::vector<std::string> ft_v(1000, "assign");
        start2 = get_time();
        ft_v.assign(v2.begin(), v2.end());
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {            
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (std_v.size() != ft_v.size() || std_v.size() != ft_v.size() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"push_back              . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;

        std::vector<std::string> std_v(1000, "push_back");
        start1 = get_time();
        std_v.push_back("test");
        end1 = get_time();

        ft::vector<std::string> ft_v(1000, "push_back");
        start2 = get_time();
        ft_v.push_back("test");
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {            
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (std_v.size() != ft_v.size() || std_v.size() != ft_v.size() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"pop_back               . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;

        std::vector<std::string> std_v(1000, "pop_back");
        start1 = get_time();
        std_v.pop_back();
        end1 = get_time();

        ft::vector<std::string> ft_v(1000, "pop_back");
        start2 = get_time();
        ft_v.pop_back();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {            
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (std_v.size() != ft_v.size() || std_v.size() != ft_v.size() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"insert                 . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::vector<std::string> v(1000, "insert");
        std::vector<std::string> v2(1000, "insert");

        std::vector<std::string> std_v(1000, "insert");
        start1 = get_time();
        std_v.insert(std_v.begin(), v.begin(), v.end());
        end1 = get_time();

        ft::vector<std::string> ft_v(1000, "insert");
        start2 = get_time();
        ft_v.insert(ft_v.begin(), v2.begin(), v2.end());
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {            
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (std_v.size() != ft_v.size() || std_v.size() != ft_v.size() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"erase                  . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;

        std::vector<std::string> std_v(1000, "erase");
        start1 = get_time();
        std_v.erase(std_v.begin(), std_v.end());
        end1 = get_time();

        ft::vector<std::string> ft_v(1000, "erase");
        start2 = get_time();
        ft_v.erase(ft_v.begin(), ft_v.end());
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {            
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (std_v.size() != ft_v.size() || std_v.size() != ft_v.size() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"clear                  . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::vector<std::string> v(1000, "clear");
        std::vector<std::string> v2(1000, "clear");

        std::vector<std::string> std_v(1000, "clear");
        start1 = get_time();
        std_v.clear();
        end1 = get_time();

        ft::vector<std::string> ft_v(1000, "clear");
        start2 = get_time();
        ft_v.clear();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {            
            for (std::vector<std::string>::iterator it = std_v.begin(); it != std_v.end(); ++it)
                data1 += *it;
            for (ft::vector<std::string>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
                data2 += *it;

            if (std_v.size() != ft_v.size() || std_v.size() != ft_v.size() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
};

void    stack_test()
{
    std::cout << BLUE << "|-----------------------------------------------------------------------------------|" << std::endl;
    std::cout << "|------------------------------------" << RESET <<" STACK " << BLUE << "----------------------------------------|" << std::endl;
    std::cout << "|-----------------------------------------------------------------------------------|"  << std::endl;

    {
        std::cout << "|" << RESET <<"default constructor    . . . . . . . . . . . . . . . . . . . .                   ";

		ft::vector<int> myvector (2,200);
		ft::stack<int> ft_s(myvector);

        if (ft_s.size() != 2)
            std::cout << R << "KO" << BLUE << "|" << std::endl;
        else
            std::cout << G << "OK" << BLUE << "|" << std::endl;
    }
    {
        std::cout << "|" << RESET <<"empty                  . . . . . . . . . . . . . . . . . . . .                   ";
		
        ft::stack<int> ft_s;
		int sum = 0;

        sum += ft_s.empty();
		for (int i=1;i<=10;i++) ft_s.push(i);
        sum += ft_s.empty();

		if (sum != 1)
            std::cout << R << "KO" << BLUE << "|" << std::endl;
        else
            std::cout << G << "OK" << BLUE << "|" << std::endl;
    }
    {
        std::cout << "|" << RESET <<"size                   . . . . . . . . . . . . . . . . . . . .                   ";
		
        ft::stack<int> ft_s;
		int sum = 0;

        sum += ft_s.size();
		for (int i=1;i<=10;i++) ft_s.push(i);
        sum += ft_s.size();

		if (sum != 10)
            std::cout << R << "KO" << BLUE << "|" << std::endl;
        else
            std::cout << G << "OK" << BLUE << "|" << std::endl;
    }
    {
        std::cout << "|" << RESET <<"top                    . . . . . . . . . . . . . . . . . . . .                   ";
		
	    ft::stack<int> ft_s;

		ft_s.push(10);
		ft_s.push(20);

		ft_s.top() -= 5;
		ft::vector<int> vec(10, 50);
		vec.push_back(300);
		ft::stack<int> const c_ft_s(vec);

		if(ft_s.top() == 15 && c_ft_s.top() == 300)
            std::cout << G << "OK" << BLUE << "|" << std::endl;
        else
            std::cout << R << "KO" << BLUE << "|" << std::endl;
    }
    {
        std::cout << "|" << RESET <<"push & pop             . . . . . . . . . . . . . . . . . . . .                   ";
		
		int sum(0);
		ft::stack<int> ft_s;

		for (int i=0; i<5; ++i) ft_s.push(i);

		while (!ft_s.empty())
		{
			sum += ft_s.top();
			ft_s.pop();
		}

		if(sum == 10 && ft_s.size() == 0)
            std::cout << G << "OK" << BLUE << "|" << std::endl;
        else
            std::cout << R << "KO" << BLUE << "|" << std::endl;
    }

};

void    map_test()
{
    std::cout << BLUE << "|-----------------------------------------------------------------------------------|" << std::endl;
    std::cout << "|------------------------------------" << RESET <<"  MAP  " << BLUE << "----------------------------------------|" << std::endl;
    std::cout << "|-----------------------------------------------------------------------------------|"  << std::endl;

    {
        std::cout << "|" << RESET <<"range constructor      . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::map<int, std::string> m1;
        ft::map<int, std::string> m2;
        for (size_t i = 0; i < 1000; i++)
        {
            m1.insert(std::make_pair(i, "range constructor test"));
            m2.insert(ft::make_pair(i, "range constructor test"));
        }
        start1 = get_time();
            std::map<int, std::string> std_m(m1.begin(), m1.end());
        end1 = get_time();

        start2 = get_time();
            ft::map<int, std::string> ft_m(m2.begin(), m2.end());
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {
            for ( std::map<int, std::string>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += it->second;
            for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += it->second;

            if (data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }

    {
        std::cout << "|" << RESET <<"copy constructor       . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::map<int, std::string> m1;
        ft::map<int, std::string> m2;
        for (size_t i = 0; i < 1000; i++)
        {
            m1.insert(std::make_pair(i, "copy constructor test"));
            m2.insert(ft::make_pair(i, "copy constructor test"));
        }
        start1 = get_time();
            std::map<int, std::string> std_m(m1);
        end1 = get_time();

        start2 = get_time();
            ft::map<int, std::string> ft_m(m2);
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;

        else
        {
            for ( std::map<int, std::string>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += it->second;
            for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += it->second;

            if (data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"operator=              . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::map<int, std::string> m1;
        ft::map<int, std::string> m2;
        for (size_t i = 0; i < 1000; i++)
        {
            m1.insert(std::make_pair(i, "operator= constructor test"));
            m2.insert(ft::make_pair(i, "operator= constructor test"));
        }
        start1 = get_time();
            std::map<int, std::string> std_m = m1;
        end1 = get_time();

        start2 = get_time();
            ft::map<int, std::string> ft_m = m2;
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;

        else
        {
            for ( std::map<int, std::string>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += it->second;
            for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += it->second;

            if (data1 != data2 || std_m.size() != ft_m.size())
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"begin                  . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::map<int, std::string> std_m;
        ft::map<int, std::string> ft_m;

        for (size_t i = 0; i < 1000; i++)
        {
            std_m.insert(std::make_pair(i, "string2"));
            ft_m.insert(ft::make_pair(i, "string2"));
        }
        start1 = get_time();
        std::map<int, std::string>::iterator b = std_m.begin();
        std::map<int, std::string>::const_iterator cb  = std_m.begin();
        (void)b;
        (void)cb;
        end1 = get_time();

        start2 = get_time();
        ft::map<int, std::string>::iterator ft_b  = ft_m.begin();
        ft::map<int, std::string>::const_iterator ft_cb  = ft_m.begin();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
       else
        {
            for ( std::map<int, std::string>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += it->second;
            for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += it->second;

            if (data1 != data2 || std_m.size() != ft_m.size())
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"end                    . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::map<int, std::string> std_m;
        ft::map<int, std::string> ft_m;

        for (size_t i = 0; i < 1000; i++)
        {
            std_m.insert(std::make_pair(i, "string2"));
            ft_m.insert(ft::make_pair(i, "string2"));
        }
        start1 = get_time();
        std::map<int, std::string>::iterator b = std_m.end();
        std::map<int, std::string>::const_iterator cb  = std_m.end();
        (void)b;
        (void)cb;
        end1 = get_time();

        start2 = get_time();
        ft::map<int, std::string>::iterator ft_b  = ft_m.end();
        ft::map<int, std::string>::const_iterator ft_cb  = ft_m.end();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
       else
        {
            for ( std::map<int, std::string>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += it->second;
            for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += it->second;

            if (data1 != data2 || std_m.size() != ft_m.size())
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }

    {
        std::cout << "|" << RESET <<"size                   . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::map<int, std::string> std_m;
        ft::map<int, std::string> ft_m;
        for (size_t i = 0; i < 1000; i++)
        {
            std_m.insert(std::make_pair(i, "string2"));
            ft_m.insert(ft::make_pair(i, "string2"));
        }
        start1 = get_time();
        size_t std_size = std_m.size();
        end1 = get_time();

        start2 = get_time();
        size_t ft_size = ft_m.size();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {
            if (std_size != ft_size)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }

 
    {
        std::cout << "|" << RESET <<"empty                  . . . . . . . . . . . . . . . . . . . .                   ";
        ft::map<int, std::string> ft_m;
		int sum = 0;
        sum += ft_m.empty();
        for (size_t i = 0; i < 1000; i++)
            ft_m.insert(ft::make_pair(i, "string2"));
        sum += ft_m.empty();

		if (sum != 1)
            std::cout << R << "KO" << BLUE << "|" << std::endl;
        else
            std::cout << G << "OK" << BLUE << "|" << std::endl;
    }
    {
        std::cout << "|" << RESET <<"[]                     . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::map<int, std::string> std_m;
        ft::map<int, std::string> ft_m;
        for (size_t i = 0; i < 1000; i++)
        {
            std_m.insert(std::make_pair(i, "[]"));
            ft_m.insert(ft::make_pair(i, "[]"));
        }
        start1 = get_time();
        std_m[999] = "test";
        end1 = get_time();

        start2 = get_time();
        ft_m[999] = "test";
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;       
        else
        {
            for ( std::map<int, std::string>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += it->second;
            for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += it->second;

            if (std_m.size() != ft_m.size() || std_m.size() != ft_m.size() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"insert                 . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::map<int, std::string> m1;
        ft::map<int, std::string> m2;
        for (size_t i = 0; i < 1000; i++)
        {
            m1.insert(std::make_pair(i, "insert"));
            m2.insert(ft::make_pair(i, "insert"));
        }

        std::map<int, std::string> std_m;
        start1 = get_time();
        std_m.insert(m1.begin(), m1.end());
        end1 = get_time();

        ft::map<int, std::string> ft_m;
        start2 = get_time();
        ft_m.insert(m2.begin(), m2.end());
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;       
        else
        {
            for ( std::map<int, std::string>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += it->second;
            for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += it->second;

            if (std_m.size() != ft_m.size() || std_m.size() != ft_m.size() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"erase                  . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::map<int, std::string> std_m;
        ft::map<int, std::string> ft_m;
        for (size_t i = 0; i < 1000; i++)
        {
            std_m.insert(std::make_pair(i, "erase"));
            ft_m.insert(ft::make_pair(i, "erase"));
        }

        start1 = get_time();
        std_m.erase(std_m.begin(), std_m.end());
        end1 = get_time();

        start2 = get_time();
        ft_m.erase(ft_m.begin(), ft_m.end());
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;       
        else
        {
            for ( std::map<int, std::string>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += it->second;
            for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += it->second;

            if (std_m.size() != ft_m.size() || std_m.size() != ft_m.size() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"swap                   . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::map<int, std::string> m1;
        ft::map<int, std::string> m2;
        for (size_t i = 0; i < 1000; i++)
        {
            m1.insert(std::make_pair(i, "swap"));
            m2.insert(ft::make_pair(i, "swap"));
        }

        std::map<int, std::string> std_m;
        start1 = get_time();
        std_m.swap(m1);
        swap(std_m, m1);
        end1 = get_time();

        ft::map<int, std::string> ft_m;
        start2 = get_time();
        ft_m.swap(m2);
        swap(ft_m, m2);
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;       
        else
        {
            for ( std::map<int, std::string>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += it->second;
            for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += it->second;

            if (std_m.size() != ft_m.size() || std_m.size() != ft_m.size() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }    
    {
        std::cout << "|" << RESET <<"clear                  . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::map<int, std::string> std_m;
        ft::map<int, std::string> ft_m;
        for (size_t i = 0; i < 1000; i++)
        {
            std_m.insert(std::make_pair(i, "erase"));
            ft_m.insert(ft::make_pair(i, "erase"));
        }

        start1 = get_time();
        std_m.clear();
        end1 = get_time();

        start2 = get_time();
        ft_m.clear();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;       
        else
        {
            for ( std::map<int, std::string>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += it->second;
            for (ft::map<int, std::string>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += it->second;

            if (std_m.size() != ft_m.size() || std_m.size() != ft_m.size() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
};

void    set_test()
{
    std::cout << BLUE << "|-----------------------------------------------------------------------------------|" << std::endl;
    std::cout << "|------------------------------------" << RESET <<"  SET  " << BLUE << "----------------------------------------|" << std::endl;
    std::cout << "|-----------------------------------------------------------------------------------|"  << std::endl;

    {
        std::cout << "|" << RESET <<"range constructor      . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::set<int> m1;
        ft::set<int> m2;
        for (size_t i = 0; i < 1000; i++)
        {
            m1.insert(i);
            m2.insert(i);
        }
        start1 = get_time();
            std::set<int> std_m(m1.begin(), m1.end());
        end1 = get_time();

        start2 = get_time();
            ft::set<int> ft_m(m2.begin(), m2.end());
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {
            for ( std::set<int>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += *it;
            for (ft::set<int>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += *it;

            if (data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }

    {
        std::cout << "|" << RESET <<"copy constructor       . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::set<int> m1;
        ft::set<int> m2;
        for (size_t i = 0; i < 1000; i++)
        {
            m1.insert(i);
            m2.insert(i);
        }
        start1 = get_time();
            std::set<int> std_m(m1);
        end1 = get_time();

        start2 = get_time();
            ft::set<int> ft_m(m2);
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;

        else
        {
            for ( std::set<int>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += *it;
            for (ft::set<int>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += *it;

            if (data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"operator=              . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::set<int> m1;
        ft::set<int> m2;
        for (size_t i = 0; i < 1000; i++)
        {
            m1.insert(i);
            m2.insert(i);
        }
        start1 = get_time();
            std::set<int> std_m = m1;
        end1 = get_time();

        start2 = get_time();
            ft::set<int> ft_m = m2;
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;

        else
        {
            for ( std::set<int>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += *it;
            for (ft::set<int>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += *it;

            if (data1 != data2 || std_m.size() != ft_m.size())
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"begin                  . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::set<int> std_m;
        ft::set<int> ft_m;

        for (size_t i = 0; i < 1000; i++)
        {
            std_m.insert(i);
            ft_m.insert(i);
        }
        start1 = get_time();
        std::set<int>::iterator b = std_m.begin();
        std::set<int>::const_iterator cb  = std_m.begin();
        (void)b;
        (void)cb;
        end1 = get_time();

        start2 = get_time();
        ft::set<int>::iterator ft_b  = ft_m.begin();
        ft::set<int>::const_iterator ft_cb  = ft_m.begin();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
       else
        {
            for ( std::set<int>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += *it;
            for (ft::set<int>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += *it;

            if (data1 != data2 || std_m.size() != ft_m.size())
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"end                    . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::set<int> std_m;
        ft::set<int> ft_m;

        for (size_t i = 0; i < 1000; i++)
        {
            std_m.insert(i);
            ft_m.insert(i);
        }
        start1 = get_time();
        std::set<int>::iterator b = std_m.end();
        std::set<int>::const_iterator cb  = std_m.end();
        (void)b;
        (void)cb;
        end1 = get_time();

        start2 = get_time();
        ft::set<int>::iterator ft_b  = ft_m.end();
        ft::set<int>::const_iterator ft_cb  = ft_m.end();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
       else
        {
            for ( std::set<int>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += *it;
            for (ft::set<int>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += *it;

            if (data1 != data2 || std_m.size() != ft_m.size())
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }

    {
        std::cout << "|" << RESET <<"size                   . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::set<int> std_m;
        ft::set<int> ft_m;
        for (size_t i = 0; i < 1000; i++)
        {
            std_m.insert(i);
            ft_m.insert(i);
        }
        start1 = get_time();
        size_t std_size = std_m.size();
        end1 = get_time();

        start2 = get_time();
        size_t ft_size = ft_m.size();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;
        else
        {
            if (std_size != ft_size)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }

 
    {
        std::cout << "|" << RESET <<"empty                  . . . . . . . . . . . . . . . . . . . .                   ";
        ft::set<int> ft_m;
		int sum = 0;
        sum += ft_m.empty();
        for (size_t i = 0; i < 1000; i++)
            ft_m.insert(i);
        sum += ft_m.empty();

		if (sum != 1)
            std::cout << R << "KO" << BLUE << "|" << std::endl;
        else
            std::cout << G << "OK" << BLUE << "|" << std::endl;
    }
    {
        std::cout << "|" << RESET <<"insert                 . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::set<int> m1;
        ft::set<int> m2;
        for (size_t i = 0; i < 1000; i++)
        {
            m1.insert(i);
            m2.insert(i);
        }

        std::set<int> std_m;
        start1 = get_time();
        std_m.insert(m1.begin(), m1.end());
        end1 = get_time();

        ft::set<int> ft_m;
        start2 = get_time();
        ft_m.insert(m2.begin(), m2.end());
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;       
        else
        {
            for ( std::set<int>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += *it;
            for (ft::set<int>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += *it;

            if (std_m.size() != ft_m.size() || std_m.size() != ft_m.size() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"erase                  . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::set<int> std_m;
        ft::set<int> ft_m;
        for (size_t i = 0; i < 1000; i++)
        {
            std_m.insert(i);
            ft_m.insert(i);
        }

        start1 = get_time();
        std_m.erase(std_m.begin(), std_m.end());
        end1 = get_time();

        start2 = get_time();
        ft_m.erase(ft_m.begin(), ft_m.end());
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;       
        else
        {
            for ( std::set<int>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += *it;
            for (ft::set<int>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += *it;

            if (std_m.size() != ft_m.size() || std_m.size() != ft_m.size() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    {
        std::cout << "|" << RESET <<"swap                   . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::set<int> m1;
        ft::set<int> m2;
        for (size_t i = 0; i < 1000; i++)
        {
            m1.insert(i);
            m2.insert(i);
        }

        std::set<int> std_m;
        start1 = get_time();
        std_m.swap(m1);
        swap(std_m, m1);
        end1 = get_time();

        ft::set<int> ft_m;
        start2 = get_time();
        ft_m.swap(m2);
        swap(ft_m, m2);
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;       
        else
        {
            for ( std::set<int>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += *it;
            for (ft::set<int>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += *it;

            if (std_m.size() != ft_m.size() || std_m.size() != ft_m.size() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }    
    {
        std::cout << "|" << RESET <<"clear                  . . . . . . . . . . . . . . . . . . . .                   ";
        std::string data1;
        std::string data2;
        std::set<int> std_m;
        ft::set<int> ft_m;
        for (size_t i = 0; i < 1000; i++)
        {
            std_m.insert(i);
            ft_m.insert(i);
        }

        start1 = get_time();
        std_m.clear();
        end1 = get_time();

        start2 = get_time();
        ft_m.clear();
        end2 = get_time();

        size_t diff1, diff2;
        diff1 = 1 + end1 - start1;
        diff2 = 1 + end2 - start2;
        if (diff2 > 20 * diff1)
            std::cout << Y << "TLE" << RESET <<  std::endl;       
        else
        {
            for ( std::set<int>::iterator it = std_m.begin(); it != std_m.end(); ++it)
                data1 += *it;
            for (ft::set<int>::iterator it = ft_m.begin(); it != ft_m.end(); ++it)
                data2 += *it;

            if (std_m.size() != ft_m.size() || std_m.size() != ft_m.size() || data1 != data2)
                std::cout << R << "KO" << BLUE << "|" << std::endl;
            else
                std::cout << G << "OK" << BLUE << "|" << std::endl;
        }
    }
    std::cout << BLUE << "|-----------------------------------------------------------------------------------|"  << std::endl;

};


int main ()
{    
    vector_test();
    stack_test();
    map_test();
    set_test();
}
