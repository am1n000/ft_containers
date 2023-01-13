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
			//dereference vec_iterator
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


	template < class T, class node >
	class tree_iterator
	{
		public :
			typedef T															iterator_type;
			typedef node                                                        node_ptr;
			typedef typename ft::iterator_traits<T>::value_type                 value_type;
			typedef typename ft::iterator_traits<T>::difference_type            difference_type;
			typedef typename ft::iterator_traits<T>::pointer                    pointer;
			typedef typename ft::iterator_traits<T>::reference                  reference;
			typedef typename ft::iterator_traits<T>::iterator_category          iterator_category;
			
		public:
			node_ptr _data;

		public:
			// default constructor
			tree_iterator(): _data(nullptr) {};
			//constructor        
			tree_iterator(node_ptr x): _data(x) {};
			
			//copy constructor
			template <class type, class Iter>
			tree_iterator (const ft::tree_iterator<type, Iter>& obj) : _data(node_ptr(obj.base()))
			{
			};

			template <class type, class Iter>
			tree_iterator &operator=(const tree_iterator<type,Iter>& obj)
			{
				_data = (node_ptr)obj.base();
				return (*this);
			}


			// destructor
			~tree_iterator() {}

			//operator *
			reference operator*() const
			{
				return (*(this->_data->value));
			}
			//operator ->
			pointer operator->() const
			{
				return (this->_data->value);
			}
			node_ptr base() const
			{
				return (_data);
			};

			//operator +
			//increment operators
			tree_iterator& operator++() //pre increment
			{
				if (this->_data->is_nil)
					return (*this);
				if(this->_data->right->is_nil == 0)
					this->_data = this->_data->right;
				else
				{
					while (_data->is_nil == 0)
					{
						if (_data->value < _data->parent->value)
						{
							this->_data = this->_data->parent;
							break;
						}
						this->_data = this->_data->parent;
					}
				}
				return (*this);
			}
			tree_iterator operator++(int) //post increment
			{
				tree_iterator  plus = *this;

				if (this->_data->is_nil || this->_data->right->is_nil == 0)
					this->_data = this->_data->right;
				else
				{
					while (_data->is_nil == 0)
					{
						if (_data->value < _data->parent->value)
						{
							this->_data = this->_data->parent;
							break;
						}
						this->_data = this->_data->parent;
					}
				}
				return (plus);
			}
			//decrement operators
			tree_iterator& operator--() //pre decrement
			{
				if (this->_data->is_end)
					this->_data = this->_data->parent;
				else if (this->_data->is_nil || this->_data->left->is_nil == 0)
					this->_data = this->_data->left;
				else
				{
					while (_data->is_nil == 0)
					{
						if (_data->value > _data->parent->value)
						{
							this->_data = this->_data->parent;
							break;
						}
						this->_data = this->_data->parent;
					}
				}
				return (*this);
			}
			tree_iterator operator--(int) //post decrement
			{
				tree_iterator  plus = *this;

				if (this->_data->is_end)
					this->_data = this->_data->parent;
				else if (this->_data->is_nil || this->_data->left->is_nil == 0)
					this->_data = this->_data->left;
				else
				{
					while (_data->is_nil == 0)
					{
						if (_data->value > _data->parent->value)
						{
							this->_data = this->_data->parent;
							break;
						}
						this->_data = this->_data->parent;
					}
				}
				return (plus);
			}

			template<typename Iterat1, typename Iterat2, class nod>
			friend bool operator==(const tree_iterator<Iterat1, nod>& obj1, const tree_iterator<Iterat2, nod>& obj2)
			{
				return (obj1.base() == obj2.base());
			}	
			template<typename Iterat1, typename Iterat2, class nod>
			friend bool operator!=(const tree_iterator<Iterat1, nod>& obj1, const tree_iterator<Iterat2, nod>& obj2)
			{
				return (obj1.base() != obj2.base());
			}
	};

}



#endif