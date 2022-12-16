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
    
    template <class T> 
    struct iterator_traits<T*>
    {
        typedef T                                   value_type;
        typedef ptrdiff_t                           difference_type;
        typedef T*                                  pointer;
        typedef T&                                  reference;
        typedef std::random_access_iterator_tag     iterator_category;
    };
    
    template<typename  T>
    struct iterator_traits<const T*>
    {
        typedef ptrdiff_t                           difference_type;
        typedef T                                   value_type;
        typedef const T*                            pointer;
        typedef const T&                            reference;
        typedef std::random_access_iterator_tag     iterator_category;
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
            typedef typename ft::iterator_traits<iterator_type>::iterator_category         iterator_category;
            
        private:
            pointer data;

        public:
            // default constructor
            iterator(): data(nullptr) {};
            //constructor        
            iterator(pointer x): data(x) {};
            
            //copy constructor
            template <class Iter>
            iterator (const iterator<Iter>& obj)
            {
                *data = obj;
            };

            template <class Iter>
            iterator &operator=(const iterator<Iter>& obj)
            {
                this->data = obj.data;
                return (*this);
            }


            // destructor
            ~iterator() {}
            //dereference iterator
            reference operator*() const 
            {
                iterator_type   tmp;
                
                tmp = data;
                return (*tmp);
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
                return (this->data + n);
            }
            //operator +=
            iterator &operator+=(difference_type n)
            {

                data = this->data + n;
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
                return (this->data - n);
            }
            //operator -=
            iterator &operator-=(difference_type n)
            {
                this->data = this->data - n;
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

    template < typename _Iter >
    class reverse_iterator
    {
        public :
            typedef _Iter                                                           iterator_type;
            typedef typename ft::iterator_traits<_Iter>::value_type                 value_type;
            typedef typename ft::iterator_traits<_Iter>::difference_type            difference_type;
            typedef typename ft::iterator_traits<_Iter>::pointer                    pointer;
            typedef typename ft::iterator_traits<_Iter>::reference                  reference;
            typedef typename ft::iterator_traits<_Iter>::iterator_category          reverse_iterator_category;
            
        public:
            iterator_type _data;

        public:
            // default constructor
            reverse_iterator(): _data(nullptr) {};
            
            //constructor                    
            explicit reverse_iterator (iterator_type it)
            {
                this->_data = it;
            };

            //copy constructor
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& obj)
            {
                *_data = obj;
            };

            template <class Iter>
            reverse_iterator &operator=(const reverse_iterator<Iter>& obj)
            {
                this->_data = obj._data;
                return (*this);
            }

            // destructor
            ~reverse_iterator() {}
            //operator +
            //increment operators
            reverse_iterator& operator++() //pre increment
            {
                --this->_data;
                return (*this);
            }
            reverse_iterator operator++(int) //post increment
            {
                reverse_iterator  plus;

                plus = *this;
                this->_data--;
                return (plus);
            }
            reverse_iterator operator+(difference_type n) const
            {
                    _data -= n;
                return (*this);
            }
            //operator +=
            reverse_iterator &operator+=(difference_type n)
            {

                _data -= n;
                return (*this);
            }
            //decrement operators
            reverse_iterator& operator--() //pre decrement
            {
                ++this->_data;
                return (*this);
            }
            reverse_iterator operator--(int) //post decrement
            {
                reverse_iterator  plus;

                plus = *this;
                this->_data++;
                return (plus);
            }
            //operator -
            reverse_iterator operator-(difference_type n) const
            {
                    this->_data += n;
                return (*this);
            }
            //operator -=
            reverse_iterator &operator-=(difference_type n)
            {
                this->_data += n;
                return (*this);
            }
            //dereference iterator
            reference operator*() const 
            {
                iterator_type   tmp;
                
                tmp = _data;
                return (*--tmp);
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
                return (obj1._data == obj2._data);
            }	
            template<typename Iterat>
            friend bool operator!=(const reverse_iterator<Iterat>& obj1, const reverse_iterator<Iterat>& obj2)
            {
                return (obj1._data != obj2._data);
            }
            template<typename Iterat>
            friend bool operator< (const reverse_iterator<Iterat>& obj1, const reverse_iterator<Iterat>& obj2)
            {
                return (obj1._data > obj2._data);
            }
            template<typename Iterat>
            friend bool operator<=(const reverse_iterator<Iterat>& obj1, const reverse_iterator<Iterat>& obj2)
            {
                return (obj1._data >= obj2._data);
            }
            template<typename Iterat>
            friend bool operator> (const reverse_iterator<Iterat>& obj1, const reverse_iterator<Iterat>& obj2)
            {
                return (obj1._data < obj2._data);
            }
            template<typename Iterat>
            friend bool operator>=(const reverse_iterator<Iterat>& obj1, const reverse_iterator<Iterat>& obj2)
            {
                return (obj1._data <= obj2._data);
            }
    };

}



#endif