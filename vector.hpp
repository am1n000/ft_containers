//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-rhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:19:40 by ael-rhai          #+#    #+#             */
/*   Updated: 2022/08/23 09:19:41 by ael-rhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR

#define FT_VECTOR

#include <iostream>
#include <iostream>
#include <vector>
#include "ft_iterators.hpp"
#include "utility.hpp"


namespace ft
{

	template <class T, class Alloc = std::allocator<T> >
	class vector
	{

		public:
			typedef T                                        	value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference       	reference;
			typedef typename allocator_type::const_reference 	const_reference;
			typedef typename allocator_type::pointer         	pointer;
			typedef typename allocator_type::const_pointer   	const_pointer;
			typedef typename allocator_type::difference_type 	difference_type;
			typedef typename allocator_type::size_type       	size_type;
			typedef ft::vec_iterator<pointer>			        iterator;
			typedef ft::vec_iterator<const_pointer>          	const_iterator;
			typedef ft::reverse_iterator<iterator>          	reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>    	const_reverse_iterator;

		private :
			pointer 			_data;
			size_t				_size;
			size_t				_capacity;
			allocator_type		_alloc;
			typedef struct t_data
			{
				value_type content;
				struct t_data *next;
			}				s_data;
			
			s_data	*lstnew(value_type content)
			{
				s_data	*new_node;

				new_node = new s_data;
				if (!new_node)
					return (0);
				new_node->content = content;
				new_node->next = 0;
				return (new_node);
			}
			s_data	*lstlast(s_data *lst)
			{
				if (!lst)
					return (0);
				while (lst->next)
				{
					lst = lst->next;
				}
				return (lst);
			}
			void	lstadd_back(s_data **lst, s_data *new_node)
			{
				s_data	*last;

				if (!*lst)
					*lst = new_node;
				else
				{
					last = lstlast(*lst);
					last->next = new_node;
				}
			}

		public :
		//constructors
			explicit vector (const allocator_type& alloc = allocator_type())
			: _data(NULL), _size(0), _capacity(0), _alloc(alloc) {};

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _data(NULL), _size(n), _capacity(n), _alloc(alloc)
			{
				if (n > 0)
				{
					_data = _alloc.allocate(n);
					for (size_type i = 0; i < n; ++i)
						_alloc.construct(_data + i, val);
				}
			};
			template <class InputIterator>
			vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last,
				const allocator_type& alloc = allocator_type())
				: _data(NULL), _size(0), _capacity(0), _alloc(alloc)
			{
				
				if (typeid(typename ft::iterator_traits<InputIterator>::iterator_category) == typeid(std::input_iterator_tag))
				{
					if (first != last)
					{
						vector temp;
						for (;first != last; first++)
							temp.push_back(*first);
						_size = temp.size();
						_capacity = temp.size();
						_data = _alloc.allocate(_size);
						for (size_type i = 0; i < _size; i++)
							_alloc.construct(_data + i, temp[i]);
					}
				}
				else
				{
					size_t n = std::distance(first, last);
					this->_data = this->_alloc.allocate(n);
					for (;first != last; first++)
					{
						this->_alloc.construct(_data + _size, *first);
						_size++;
					}
					_capacity = n;
				}
			};

			vector (const vector& x)
			{
				_size = 0;
				_capacity = 0;
				_data = nullptr;
				_alloc = x.get_allocator();
				this->assign(x.begin(), x.end());

			};

		//operator =
			vector &operator=(const vector& x) 
			{
				if (*this == x)
					return (*this);
				this->clear();
				if (this->_data)
					this->_alloc.deallocate(_data, _capacity);
				this->_data = this->_alloc.allocate(x.size());
				for (size_t i = 0; i < x.size(); i++)
					this->_alloc.construct(this->_data + i, x[i]);
				this->_size = x.size();
				this->_capacity = x.size();
				return (*this);
			};
		//destructor
			~vector()
			{
				this->clear();
				if (this->_capacity)
					_alloc.deallocate(_data, _capacity);
			};


			//iterators
			iterator begin()
			{
				return (iterator(_data));
			};
			const_iterator begin() const
			{
				return (const_iterator(_data));
			};

			iterator end()
			{
				return (iterator(_data + _size));
			};
			const_iterator end() const
			{
				return (const_iterator(_data + _size));
			};

			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			};
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			};

			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			};
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			};

			//_capacity
			size_type size() const
			{
				return (_size);
			};
			size_type max_size() const
			{
            return (std::min<size_type>(this->_alloc.max_size(),
                std::numeric_limits<difference_type >::max()));
			};
			void resize (size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					for (size_t i = n; i < _size; i++)
						_alloc.destroy(_data + i);
					_size = n;
				}
				else if (n > _size)
				{
					if (n > _capacity)
					{
						if (_capacity == 0 || n > _capacity * 2)
							reserve(n);
						else
							reserve(_capacity * 2);
					}
					for (size_t i = _size; i < n; i++)
						push_back(val);
				}
			};
			size_type capacity() const
			{
				return (_capacity);
			};
			bool empty() const
			{
				return (_size == 0 ? 1 : 0);
			};
			void reserve (size_type n)
			{
				if (_size + n >= this->max_size())
					std::__throw_length_error("vector");
				if (n <= _capacity)
					return;
				if (this->_data)
				{
					pointer new_data = this->_alloc.allocate(n);
					size_t i = 0;
					for (; i < _size; i++)
					{
						this->_alloc.construct(new_data + i, *(_data + i));
						this->_alloc.destroy(_data + i);
					}
					this->_alloc.deallocate(_data, _capacity);
					_data = new_data;
					_capacity = n;
					_size = i;
				}
				else
				{
					this->_data = this->_alloc.allocate(n);
					_capacity = n;
				}

			};


	// 		//element access

			reference operator[] (size_type n)
			{
				return (*(_data + n));
			};
			const_reference operator[] (size_type n) const
			{
				return (*(_data + n));
			};
			
			reference at (size_type n)
			{
				if (n >= _size)
					std::__throw_out_of_range("out of range");
				return (*(_data + n));
			};
			const_reference at (size_type n) const
			{
				if (n >= _size)
					std::__throw_out_of_range("out of range");
				return (*(_data + n));
			};;
			
			reference front()
			{
				return (*_data);
			};
			const_reference front() const
			{
				return (*_data);
			};
			
			reference back()
			{
				return (*(_data + _size - 1));
			};
			const_reference back() const
			{
				return (*(_data + _size - 1));
			};


	// 		//modifiers

			template <class InputIterator>
			void assign (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
			{

				this->clear();
				if (first == last)
					return;
				if (typeid(typename ft::iterator_traits<InputIterator>::iterator_category) == typeid(std::input_iterator_tag))
				{
					s_data *lst = NULL;
					size_t n = 0;
					for (; first != last; first++)
					{
						lstadd_back(&lst, lstnew(*first));
						n++;
					}
					if (n > _capacity)
					{
						if (_data)
							this->_alloc.deallocate(_data, _capacity);
						_capacity = n;
						this->_data = this->_alloc.allocate(_capacity);
					}
					for (size_type i = 0; i < n; i++)
					{
						_alloc.construct(this->_data + i, lst->content);
						s_data	*ptr = lst->next;
						delete (lst);
						lst = ptr;
					}
					_size = n;
				}
				else
				{
					size_t n = std::distance(first, last);
					if (n > _capacity)
					{
						if (_data)
							this->_alloc.deallocate(_data, _capacity);
						_capacity = n;
						this->_data = this->_alloc.allocate(n);
					}
					for (;first != last; first++)
					{
						this->_alloc.construct(_data + _size, *first);
						_size++;
					}
				}
			};
			void assign (typename ft::enable_if<ft::is_integral<size_type>::value, size_type>::type n, const value_type& val)
			{
				this->clear();
				if (n > _capacity)
				{
					if (_data)
						this->_alloc.deallocate(_data, _capacity);
					_capacity = n;
					this->_data = this->_alloc.allocate(n);
				}
				for (size_type i = 0 ;i != n; i++)
				{
					this->_alloc.construct(_data + _size, val);
					_size++;
				}
			};
			
			void push_back (const value_type& val)
			{
				if (_size == _capacity)
				{
					if (_capacity == 0)
						reserve(1);
					else
						reserve(_capacity * 2);
				}
				_alloc.construct(_data + _size, val);
				this->_size++;
			};
			void pop_back()
			{
				_alloc.destroy(_data + _size - 1);
				_size--;
			};
			
			iterator insert (iterator position, const value_type& val)
			{
				size_t n = position - this->begin();
				this->insert(position, 1, val);
				return (iterator(_data + n));
			};
			void insert (iterator position, typename ft::enable_if<std::is_integral<size_type>::value, size_type>::type n, const value_type& val)
			{
				if (n == 0)
					return;
				if (_size + n >= this->max_size())
					std::__throw_length_error("vector");
				size_t dist = position - this->begin();
				size_t move = this->end() - position;
				if (_size + n > _capacity)
				{
					if (n <= _size)
						reserve (_capacity * 2);
					else
						reserve (_size + n);
				}
				for (size_t i = _size - 1; move > 0; move--)
				{
					value_type temp = *(this->_data + i);
					this->_alloc.destroy(this->_data + i);
					this->_alloc.construct(this->_data + n + i, temp);
					i--;
				}
				size_t nn = n;
				for (size_t i = dist; nn > 0; nn--)
				{
					this->_alloc.construct(_data + i, val);
					i++;
				}
				_size += n;
			};
			template <class InputIterator>
			void insert (iterator position, typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first,
				InputIterator last)
			{

				if (typeid(typename ft::iterator_traits<InputIterator>::iterator_category) == typeid(std::input_iterator_tag))
				{
					s_data *lst = NULL;
					size_t count = position - this->begin();
					size_t n = 0;
					for (size_t i = 0; i < count; i++)
						lstadd_back(&lst, lstnew(*(_data + i)));
					for (; first != last; first++)
					{
						lstadd_back(&lst, lstnew(*first));
						n++;
					}
					for (size_t i = count; i < _size; i++)
						lstadd_back(&lst, lstnew(*(_data + i)));
					size_t s = _size + n;
					this->clear();
					if (s >= _capacity)
					{
						if (_data)
							this->_alloc.deallocate(_data, _capacity);
						this->_data = this->_alloc.allocate(s);
					}
					for (size_type i = 0; i < s; i++)
					{
						_alloc.construct(this->_data + i, lst->content);
						s_data	*ptr = lst->next;
						delete (lst);
						lst = ptr;
					}
					_size = s;
					_capacity = s;
				}
				else
				{
					
					size_t n = 0;
					for (InputIterator temp = first;temp != last; temp++)
						n++;
					if (n == 0)
						return;
					size_t dist = position - this->begin();
					size_t move = this->end() - position;
					if (_size + n > _capacity)
					{
						if (n <= _size)
							reserve (_capacity * 2);
						else
							reserve (_size + n);
					}
					for (size_t i = _size - 1; move > 0; move--)
					{
						value_type temp = *(this->_data + i);
						this->_alloc.destroy(this->_data + i);
						this->_alloc.construct(this->_data + n + i, temp);
						i--;
					}
					for (size_t i = dist; first != last; first++)
					{
						this->_alloc.construct(_data + i, *first);
						i++;
					}
					_size += n;
				}
			};
			
			iterator erase (iterator position)
			{
				size_type count = position - this->begin();
				_size--;
				for (;count < _size; count++)
					*(_data + count) = *(_data + count + 1);
				this->_alloc.destroy(_data + count);
				return (position);
			};
			iterator erase (iterator first, iterator last)
			{
				iterator temp = first;
				size_t count = first - this->begin();
				size_t n = last - first;
				if (n == 0)
					return (first);
				for (;count + n < _size; count++)
					*(_data + count) =  *(_data + count + n);
				for (; first != last; first++)
					_alloc.destroy(_data + count++);
				_size -= n;
				return (temp);
			};
			
			void swap (vector& x)
			{
				size_t temp_size = this->size();
				size_t temp_capacity = this->capacity();
				pointer temp_data = this->_data;

				this->_size = x.size();
				x._size = temp_size;
				this->_capacity = x.capacity();
				x._capacity = temp_capacity;
				this->_data = x._data;
				x._data = temp_data;
			}
			void clear()
			{
				for (;_size; _size--)
					_alloc.destroy(_data + _size - 1);
			};

			// allocator
			allocator_type get_allocator() const
			{
				return (this->_alloc);
			};

	};
		// // relational operators
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);

		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	};
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (true);
			return (!(ft::equal(lhs.begin(), lhs.end(), rhs.begin())));
	};
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs == rhs || lhs < rhs);
	};
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs <= rhs));
	};
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lhs == rhs || lhs > rhs);
	};

	//swap
	template <class T, class Alloc> 
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	};
}

#endif
