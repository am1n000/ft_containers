#ifndef FT_ITERATORS

#define FT_ITERATORS

#include <iostream>

namespace ft
{
    //iterator_traits****************************
	template <class T>
	struct iterator_traits
	{
		typedef	typename T::difference_type  	difference_type; 
		typedef	typename T::value_type			value_type; 
		typedef	typename T::pointer				pointer; 
		typedef	typename T::reference			reference; 
		typedef	typename T::iterator_category	iterator_category; 
	};
    
    template <class T> 
    struct iterator_traits<T*>
    {
        typedef std::ptrdiff_t                      difference_type;
        typedef T                                   value_type;
        typedef T*                                  pointer;
        typedef T&                                  reference;
        typedef std::random_access_iterator_tag     iterator_category;
    };
    
    template<typename  T>
    struct iterator_traits<const T*>
    {
        typedef std::ptrdiff_t                      difference_type;
        typedef T                                   value_type;
        typedef const T*                            pointer;
        typedef const T&                            reference;
        typedef std::random_access_iterator_tag     iterator_category;
    };



    template < class T >
    class vec_iterator
    {
        public :
            typedef T                                                                       iterator_type;
            typedef typename ft::iterator_traits<iterator_type>::value_type                 value_type;
            typedef typename ft::iterator_traits<iterator_type>::difference_type            difference_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer                    pointer;
            typedef typename ft::iterator_traits<iterator_type>::reference                  reference;
            typedef typename ft::iterator_traits<iterator_type>::iterator_category          iterator_category;
            
        private:
            pointer _data;

        public:
            // default constructor
            vec_iterator(): _data(nullptr) {};
            //constructor        
            vec_iterator(iterator_type x): _data(x) {};
            
            //copy constructor
            template <class Iter>
            vec_iterator (const ft::vec_iterator<Iter>& obj) : _data(obj.base())
            {
            };

            template <class Iter>
            const vec_iterator &operator=(const vec_iterator<Iter>& obj)
            {
                _data = obj.base();
                return (*this);
            }


            // destructor
            ~vec_iterator() {}
            //dereference iterator
            reference operator*() const 
            {
                iterator_type   tmp;
                
                tmp = _data;
                return (*tmp);
            }
            iterator_type base() const
            {
                return (_data);
            };

            //operator +
            //increment operators
            vec_iterator& operator++() //pre increment
            {
                ++this->_data;
                return (*this);
            }
            vec_iterator operator++(int) //post increment
            {
                vec_iterator  plus;

                plus = *this;
                this->_data++;
                return (plus);
            }
            vec_iterator operator+(difference_type n) const
            {
                return (this->_data + n);
            }
            //operator +=
            vec_iterator &operator+=(difference_type n)
            {

                _data = this->_data + n;
                return (*this);
            }
            //decrement operators
            vec_iterator& operator--() //pre decrement
            {
                --this->_data;
                return (*this);
            }
            vec_iterator operator--(int) //post decrement
            {
                vec_iterator  plus;

                plus = *this;
                this->_data--;
                return (plus);
            }
            //operator -
            vec_iterator operator-(difference_type n) const
            {
                return (this->_data - n);
            }
            //operator -=
            vec_iterator &operator-=(difference_type n)
            {
                this->_data = this->_data - n;
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
                return (this->_data[n]);
            }

            // Comparison////////////////
            friend vec_iterator operator+(difference_type n, vec_iterator obj)
            {
                return (obj._data + n);
            }
            template<typename Iterat>
            friend int operator-(const vec_iterator<Iterat>& obj1, const vec_iterator<Iterat>& obj2)
            {
                return (obj1._data -obj2._data);
            }
            template<typename Iterat1, typename Iterat2>
            friend bool operator==(const vec_iterator<Iterat1>& obj1, const vec_iterator<Iterat2>& obj2)
            {
                return (obj1.base() == obj2.base());
            }	
            template<typename Iterat1, typename Iterat2>
            friend bool operator!=(const vec_iterator<Iterat1>& obj1, const vec_iterator<Iterat2>& obj2)
            {
                return (obj1.base() != obj2.base());
            }
            template<typename Iterat1, typename Iterat2>
            friend bool operator< (const vec_iterator<Iterat1>& obj1, const vec_iterator<Iterat2>& obj2)
            {
                return (obj1.base() < obj2.base());
            }
            template<typename Iterat1, typename Iterat2>
            friend bool operator<=(const vec_iterator<Iterat1>& obj1, const vec_iterator<Iterat2>& obj2)
            {
                return (obj1.base() <= obj2.base());
            }
            template<typename Iterat1, typename Iterat2>
            friend bool operator> (const vec_iterator<Iterat1>& obj1, const vec_iterator<Iterat2>& obj2)
            {
                return (obj1.base() > obj2.base());
            }
            template<typename Iterat1, typename Iterat2>
            friend bool operator>=(const vec_iterator<Iterat1>& obj1, const vec_iterator<Iterat2>& obj2)
            {
                return (obj1.base() >= obj2.base());
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
            typedef typename ft::iterator_traits<_Iter>::iterator_category          iterator_category;
            
        private:
            iterator_type _it;

        public:
            // default constructor
            reverse_iterator(): _it() {};
            
            //constructor                    
            explicit reverse_iterator (iterator_type it)
            {
                this->_it = it;
            };

            //copy constructor
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& obj)
            {
                _it = obj.base();
            };

            template <class Iter>
            reverse_iterator &operator=(const reverse_iterator<Iter>& obj)
            {
                this->_it = obj.base();
                return (*this);
            }

            // destructor
            ~reverse_iterator() {}


            iterator_type base() const
            {
                return (this->_it);
            };

            //operator +
            //increment operators
            reverse_iterator& operator++() //pre increment
            {
                --this->_it;
                return (*this);
            }
            reverse_iterator operator++(int) //post increment
            {
                reverse_iterator  plus;

                plus = *this;
                this->_it--;
                return (plus);
            }
            reverse_iterator operator+(difference_type n) const
            {
                return (reverse_iterator(_it - n));
            }
            //operator +=
            reverse_iterator &operator+=(difference_type n)
            {

                _it -= n;
                return (*this);
            }
            //decrement operators
            reverse_iterator& operator--() //pre decrement
            {
                ++this->_it;
                return (*this);
            }
            reverse_iterator operator--(int) //post decrement
            {
                reverse_iterator  plus;

                plus = *this;
                this->_it++;
                return (plus);
            }
            //operator -
            reverse_iterator operator-(difference_type n) const
            {
                return (reverse_iterator(_it + n));
            }
            //operator -=
            reverse_iterator &operator-=(difference_type n)
            {
                this->_it += n;
                return (*this);
            }
            //dereference iterator
            reference operator*() const 
            {
                iterator_type   tmp;
                
                tmp = _it;
                return (*tmp);
            }
            //operator ->
            pointer operator->() const
            {
                return &(operator*());
            }
            //operator []
            reference operator[](difference_type n) const
            {
                return (this->_it[-n - 1]);
            }

            friend reverse_iterator operator+(difference_type n, reverse_iterator obj)
            {
                return (obj + n);
            }
            template<typename Iterat>
            friend int operator-(const reverse_iterator<Iterat>& obj1, const reverse_iterator<Iterat>& obj2)
            {
                return (obj2._it - obj1._it);
            }
            //relational operators
            template<typename Iterat1, typename Iterat2>
            friend bool operator==(const reverse_iterator<Iterat1>& obj1, const reverse_iterator<Iterat2>& obj2)
            {
                return (obj1._it == obj2._it);
            }	
            template<typename Iterat1, typename Iterat2>
            friend bool operator!=(const reverse_iterator<Iterat1>& obj1, const reverse_iterator<Iterat2>& obj2)
            {
                return (obj1._it != obj2._it);
            }
            template<typename Iterat1, typename Iterat2>
            friend bool operator< (const reverse_iterator<Iterat1>& obj1, const reverse_iterator<Iterat2>& obj2)
            {
                return (obj1._it > obj2._it);
            }
            template<typename Iterat1, typename Iterat2>
            friend bool operator<=(const reverse_iterator<Iterat1>& obj1, const reverse_iterator<Iterat2>& obj2)
            {
                return (obj1._it >= obj2._it);
            }
            template<typename Iterat1, typename Iterat2>
            friend bool operator> (const reverse_iterator<Iterat1>& obj1, const reverse_iterator<Iterat2>& obj2)
            {
                return (obj1._it < obj2._it);
            }
            template<typename Iterat1, typename Iterat2>
            friend bool operator>=(const reverse_iterator<Iterat1>& obj1, const reverse_iterator<Iterat2>& obj2)
            {
                return (obj1._it <= obj2._it);
            }
    };

    template < class T >
    class map_iterator
    {
        public :
            typedef T                                                                       iterator_type;
            typedef typename ft::iterator_traits<iterator_type>::value_type                 value_type;
            typedef typename ft::iterator_traits<iterator_type>::difference_type            difference_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer                    pointer;
            typedef typename ft::iterator_traits<iterator_type>::reference                  reference;
            typedef typename ft::iterator_traits<iterator_type>::iterator_category          iterator_category;
            
        private:
            pointer _data;

        public:
            // default constructor
            map_iterator(): _data(nullptr) {};
            //constructor        
            map_iterator(iterator_type x): _data(x) {};
            
            //copy constructor
            template <class Iter>
            map_iterator (const ft::map_iterator<Iter>& obj) : _data(obj.base())
            {
            };

            template <class Iter>
            const map_iterator &operator=(const map_iterator<Iter>& obj)
            {
                _data = obj.base();
                return (*this);
            }


            // destructor
            ~map_iterator() {}
            //dereference iterator
            reference operator*() const 
            {
                iterator_type   tmp;
                
                tmp = _data;
                return (*tmp);
            }
            iterator_type base() const
            {
                return (_data);
            };

            //operator +
            //increment operators
            map_iterator& operator++() //pre increment
            {
                ++this->_data;
                return (*this);
            }
            map_iterator operator++(int) //post increment
            {
                map_iterator  plus;

                plus = *this;
                this->_data++;
                return (plus);
            }
            map_iterator operator+(difference_type n) const
            {
                return (this->_data + n);
            }
            //operator +=
            map_iterator &operator+=(difference_type n)
            {

                _data = this->_data + n;
                return (*this);
            }
            //decrement operators
            map_iterator& operator--() //pre decrement
            {
                --this->_data;
                return (*this);
            }
            map_iterator operator--(int) //post decrement
            {
                map_iterator  plus;

                plus = *this;
                this->_data--;
                return (plus);
            }
            //operator -
            map_iterator operator-(difference_type n) const
            {
                return (this->_data - n);
            }
            //operator -=
            map_iterator &operator-=(difference_type n)
            {
                this->_data = this->_data - n;
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
                return (this->_data[n]);
            }

            // Comparison////////////////
            friend map_iterator operator+(difference_type n, map_iterator obj)
            {
                return (obj._data + n);
            }
            template<typename Iterat>
            friend int operator-(const map_iterator<Iterat>& obj1, const map_iterator<Iterat>& obj2)
            {
                return (obj1._data -obj2._data);
            }
            template<typename Iterat1, typename Iterat2>
            friend bool operator==(const map_iterator<Iterat1>& obj1, const map_iterator<Iterat2>& obj2)
            {
                return (obj1.base() == obj2.base());
            }	
            template<typename Iterat1, typename Iterat2>
            friend bool operator!=(const map_iterator<Iterat1>& obj1, const map_iterator<Iterat2>& obj2)
            {
                return (obj1.base() != obj2.base());
            }
            template<typename Iterat1, typename Iterat2>
            friend bool operator< (const map_iterator<Iterat1>& obj1, const map_iterator<Iterat2>& obj2)
            {
                return (obj1.base() < obj2.base());
            }
            template<typename Iterat1, typename Iterat2>
            friend bool operator<=(const map_iterator<Iterat1>& obj1, const map_iterator<Iterat2>& obj2)
            {
                return (obj1.base() <= obj2.base());
            }
            template<typename Iterat1, typename Iterat2>
            friend bool operator> (const map_iterator<Iterat1>& obj1, const map_iterator<Iterat2>& obj2)
            {
                return (obj1.base() > obj2.base());
            }
            template<typename Iterat1, typename Iterat2>
            friend bool operator>=(const map_iterator<Iterat1>& obj1, const map_iterator<Iterat2>& obj2)
            {
                return (obj1.base() >= obj2.base());
            }
    };

}



#endif