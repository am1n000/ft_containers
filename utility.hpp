#ifndef FT_TOOLS

#define FT_TOOLS

#include "ft_iterators.hpp"
#include "type_traits.hpp"


namespace ft
{

    // ft::equal
    template <class InputIterator1, class InputIterator2>
    bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
        while (first1!=last1)
        {
            if (!(*first1 == *first2))
            return false;
            ++first1; ++first2;
        }
        return true;
    }
    //////////////////

    // ft::lexicographical_compare       , the first range is less than the second range
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        while (first1!=last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1; ++first2;
        }
        return (first2 != last2);
    }
    ////////////////////////////////



    //ft::pair
    template <class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;
        first_type  first;
        second_type second;

        pair() : first(), second() {};
        
        template <class U, class V>
        pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {};
        
        pair (const first_type & a, const second_type &b) : first(a), second(b) {};
        pair& operator= (const pair& pr)
        {
            this->first = pr.first;
            this->second = pr.second;
            return (*this);
        };


        friend bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        {
            return (lhs.first==rhs.first && lhs.second==rhs.second);
        }
        friend bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        {
            return (!(lhs==rhs));
        }
        friend bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        {
            return (lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second));
        }
        friend bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        {
            return (!(rhs<lhs));
        }
        friend bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        {
            return (rhs<lhs);
        }
        friend bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
        {
            return (!(lhs<rhs));
        }
    };
    ////////////////

    // ft::make_pair
    template <class T1, class T2> 
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return ( pair<T1,T2>(x,y) );
    };


    /////////////////

}

#endif
