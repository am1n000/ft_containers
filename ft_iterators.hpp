#ifndef FT_ITERATORS

#define FT_ITERATORS

#include <iostream>
#include <iostream>
#include <iostream>
#include <vector>

namespace ft
{
    template < typename T >
    class iterator
    {
        private :
            iterator(): pointer(nullptr) {};


        public :
            T *pointer;

        
            iterator(T*p): pointer(p) {};
        
        iterator(iterator const &obj)
        {
            std::cout << "jawad is right\n";
            *this = obj;
        }

        iterator &operator=(iterator const &obj)
        {
            this->pointer = obj.pointer;
            return (*this);
        };
        
        ~iterator() {};

        //increment decrement operators
        iterator& operator++() //pre increment
        {
            ++this->pointer;
            return (*this);
        }

        iterator operator++(T) //post increment
        {
            iterator  plus;

            plus = *this;
            this->pointer++;
            return (plus);
        }

        iterator& operator--() //pre decrement
        {
            this->pointer--;
            return (*this);
        }

        iterator operator--(T) //post decrement
        {
            iterator  plus;

            plus = *this;
            this->pointer--;
            return (plus);
        }

        bool operator!=(const iterator &obj) //post decrement
        {
            return (this->pointer != obj.pointer);
        }

        bool operator==(const iterator &obj) //post decrement
        {
            return (this->pointer == obj.pointer);
        }

        T& operator*() //post decrement
        {
            return (*this->pointer);
        }
    };

}



#endif