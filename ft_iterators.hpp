#ifndef FT_ITERATORS

#define FT_ITERATORS

#include <iostream>

namespace ft
{
    //iterator_traits****************************
	template <class Iter>
	struct iterator_traits
	{
		typedef	typename Iter::difference_type  	difference_type; 
		typedef	typename Iter::value_type			value_type; 
		typedef	typename Iter::pointer				pointer; 
		typedef	typename Iter::reference			reference; 
		typedef	typename Iter::iterator_category	iterator_category; 
	};




    template < class T >
    class iterator
    {
        public :
            typedef T                                                                       iterator_type;
            typedef typename ft::iterator_traits<iterator_type>::value_type                 value_type;
            typedef typename ft::iterator_traits<iterator_type>::difference_type            difference_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer                    pointer;
            typedef typename ft::iterator_traits<iterator_type>::reference                  reference;
            typedef typename ft::iterator_traits<iterator_type>::iterator_categorie         iterator_categorie;
            
        private:
            pointer data;

        public:
            // default constructor
            iterator(): data(nullptr) { std::cout << "ft::iterator default constructor!\n"; };
            //constructor        
            iterator(pointer x): data(x) { std::cout << "ft::iterator constructor !\n"; };
            
            iterator(iterator_type *ptr)
            {
                std::cout << "ft::iterator copy constructor\n";
                *this = obj;
            }
            copy constructor
            iterator &operator=(iterator<T> const &obj)
            {
                this->data = obj.data;
                return (*this);
            };
            // destructor
            ~iterator() {}
            //dereference iterator
            reference operator*() const 
            {
                return (*this->data);
            }
            //operator +
            //increment operators
            iterator& operator++() //pre increment
            {
                ++this->data;
                return (*this);
            }
            iterator operator++(int) //post increment
            {
                iterator  plus;

                plus = *this;
                this->data++;
                return (plus);
            }
            iterator operator+(difference_type n) const
            {
                    data += n;
                return (*this);
            }
            //operator +=
            iterator &operator+=(difference_type n)
            {

                data += n;
                return (*this);
            }
            //decrement operators
            iterator& operator--() //pre decrement
            {
                --this->data;
                return (*this);
            }
            iterator operator--(int) //post decrement
            {
                iterator  plus;

                plus = *this;
                this->data--;
                return (plus);
            }
            //operator -
            iterator operator-(difference_type n) const
            {
                    this->data -= n;
                return (*this);
            }
            //operator -=
            iterator &operator-=(difference_type n)
            {
                this->data -= n;
                return (*this);
            }
            //operator ->
            pointer operator->() const
            {
                return &(operator*());
            }
            //operator []
            reference operator[](difference_type n) const
            {
                return (*this + n);
            }
            template<typename Iterat>
            friend bool operator==(const iterator<Iterat>& obj1, const iterator<Iterat>& obj2)
            {
                return (obj1.data == obj2.data);
            }	
            template<typename Iterat>
            friend bool operator!=(const iterator<Iterat>& obj1, const iterator<Iterat>& obj2)
            {
                return (obj1.data != obj2.data);
            }
            template<typename Iterat>
            friend bool operator< (const iterator<Iterat>& obj1, const iterator<Iterat>& obj2)
            {
                return (obj1.data < obj2.data);
            }
            template<typename Iterat>
            friend bool operator<=(const iterator<Iterat>& obj1, const iterator<Iterat>& obj2)
            {
                return (obj1.data <= obj2.data);
            }
            template<typename Iterat>
            friend bool operator> (const iterator<Iterat>& obj1, const iterator<Iterat>& obj2)
            {
                return (obj1.data > obj2.data);
            }
            template<typename Iterat>
            friend bool operator>=(const iterator<Iterat>& obj1, const iterator<Iterat>& obj2)
            {
                return (obj1.data >= obj2.data);
            }
    };

    template < typename T >
    class reverse_iterator
    {
        public :
            typedef T                                                           iterator_type;
            typedef typename ft::iterator_traits<T>::value_type                 value_type;
            typedef typename ft::iterator_traits<T>::difference_type            difference_type;
            typedef typename ft::iterator_traits<T>::pointer                    pointer;
            typedef typename ft::iterator_traits<T>::reference                  reference;
            typedef typename ft::iterator_traits<T>::iterator_categorie         reverse_iterator_categorie;
            
        private:
            pointer data;

        public:
            // default constructor
            reverse_iterator(): data(nullptr) { std::cout << "reverse_iterator default constructor!\n"; };
            
            //constructor                    
            explicit reverse_iterator (iterator_type it)
            {
                *this = it - 1;
            };

            //copy constructor
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& obj)
            {
                this->data = obj.data;
                return (*this);
            };
            // destructor
            ~reverse_iterator() {}
            //dereference iterator
            reference operator*() const 
            {
                return (*this->data - 1);
            }
            //operator +
            //increment operators
            reverse_iterator& operator++() //pre increment
            {
                --this->data;
                return (*this);
            }
            reverse_iterator operator++(int) //post increment
            {
                reverse_iterator  plus;

                plus = *this;
                this->data--;
                return (plus);
            }
            reverse_iterator operator+(difference_type n) const
            {
                    data -= n;
                return (*this);
            }
            //operator +=
            reverse_iterator &operator+=(difference_type n)
            {

                data -= n;
                return (*this);
            }
            //decrement operators
            reverse_iterator& operator--() //pre decrement
            {
                ++this->data;
                return (*this);
            }
            reverse_iterator operator--(int) //post decrement
            {
                reverse_iterator  plus;

                plus = *this;
                this->data++;
                return (plus);
            }
            //operator -
            reverse_iterator operator-(difference_type n) const
            {
                    this->data += n;
                return (*this);
            }
            //operator -=
            reverse_iterator &operator-=(difference_type n)
            {
                this->data += n;
                return (*this);
            }
            //operator ->
            pointer operator->() const
            {
                return &(operator*());
            }
            //operator []
            reference operator[](difference_type n) const
            {
                return (*this - n);
            }

            //relational operators
            template<typename Iterat>
            friend bool operator==(const reverse_iterator<Iterat>& obj1, const reverse_iterator<Iterat>& obj2)
            {
                return (obj1.data == obj2.data);
            }	
            template<typename Iterat>
            friend bool operator!=(const reverse_iterator<Iterat>& obj1, const reverse_iterator<Iterat>& obj2)
            {
                return (obj1.data != obj2.data);
            }
            template<typename Iterat>
            friend bool operator< (const reverse_iterator<Iterat>& obj1, const reverse_iterator<Iterat>& obj2)
            {
                return (obj1.data > obj2.data);
            }
            template<typename Iterat>
            friend bool operator<=(const reverse_iterator<Iterat>& obj1, const reverse_iterator<Iterat>& obj2)
            {
                return (obj1.data >= obj2.data);
            }
            template<typename Iterat>
            friend bool operator> (const reverse_iterator<Iterat>& obj1, const reverse_iterator<Iterat>& obj2)
            {
                return (obj1.data < obj2.data);
            }
            template<typename Iterat>
            friend bool operator>=(const reverse_iterator<Iterat>& obj1, const reverse_iterator<Iterat>& obj2)
            {
                return (obj1.data <= obj2.data);
            }
    };

}



#endif