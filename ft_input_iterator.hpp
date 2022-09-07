#ifndef fT_INPUT_ITERATOR

#define FT_INPUT_ITERATOR

#include <iostream>


namespace ft
{

    template < typename T>

    class input_iterator
    {
        private:
            T   *pointer;

        private :
            iterator(): pointer(nullptr) {};
        
        public:

            input_iterator(T const *p): pointer(p) {};
            
            input_iterator(input_iterator const &obj)
            {
                *this = obj;
            }

            input_iterator &operator=(input_iterator const &obj)
            {
                this->pointer = obj.pointer;
                return (*this);
            };
            
            ~input_iterator() {};

            //increment decrement operators
            input_iterator& operator++() //pre increment
            {
                ++this->pointer;
                return (*this);
            }

            input_iterator operator++(T) //post increment
            {
                input_iterator  plus;

                plus = *this;
                this->pointer++;
                return (plus);
            }

            bool operator!=(const input_iterator &obj) //post decrement
            {
                return (this->pointer != obj.pointer);
            }

            bool operator==(const input_iterator &obj) //post decrement
            {
                return (this->pointer == obj.pointer);
            }

            T   const &operator*() //post decrement
            {
                return (*this->pointer);
            }
    }
}


#endif