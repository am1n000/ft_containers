/* ************************************************************************** */
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

#ifndef FT_CONTAINERS

#define FT_CONTAINERS

#include <iostream>
#include <iostream>
#include <vector>
#include "ft_iterators.hpp"


namespace ft
{

	template<bool Condition, typename T = void>
	struct enable_if
	{
	};
	
	template<typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};



	template <class T>
	class vector
	{

		public:
			typedef T                                        	value_type;
			typedef std::allocator<T>							allocator_type;
			typedef typename allocator_type::reference       	reference;
			typedef typename allocator_type::const_reference 	const_reference;
			typedef typename allocator_type::pointer         	pointer;
			typedef typename allocator_type::const_pointer   	const_pointer;
			typedef typename allocator_type::difference_type 	difference_type;
			typedef typename allocator_type::size_type       	size_type;
			typedef ft::iterator<pointer>			            iterator;
			typedef ft::iterator<const_pointer>          		const_iterator;
			typedef ft::reverse_iterator<iterator>          	reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>    	const_reverse_iterator;

		private :
			std::allocator<T> alloc;
			pointer data;
			int		_size;
			int		_capacity;

		public :
		//constructors
			explicit vector ()
			{
				_size = 0;
				_capacity = 0;
				data = nullptr;
			};

			explicit vector (size_type n, const value_type& val = value_type())
			{
				_size = n;
				_capacity = n;
				data = alloc.allocate(_capacity);
				for (size_type i = 0; i < n; ++i)
					alloc.construct(data + i, val);
			};
/*			// template <class InputIterator>
			// vector (InputIterator first, InputIterator last)
			// {
			// 	_size = 0;
			// 	_capacity = 0;
			// 	data = nullptr;
			// 	while (first != last)
			// 	{
			// 		push_back(*first);
			// 		first++;
			// 		_size++;
			// 	}
			// 	_capacity = _size; 
			// };*/

			vector (const vector& x)
			{
				return (*this(x.begin(), x.end()));
			};

		//destructor
			~vector()
			{
				alloc.deallocate(data, _capacity);
				for (size_t i = 0; i < _size ;i++)
					alloc.destroy(data + i);
			};

		//operator =
			vector &operator=(const vector& x) 
			{
				return &(*this(x.begin(), x.end()));
			};

			//iterators
			iterator begin()
			{
				return (iterator(data));
			};
			const_iterator begin() const
			{
				return (const_iterator(data));
			};

			iterator end()
			{
				return (iterator(data + _size));
			};
			const_iterator end() const
			{
				return (const_iterator(data + _size));
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
			size_type max__size() const
			{
				return (alloc.max__size());
			};
			void resize (size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					for (size_t i = n; i < _size; i++)
						alloc.destroy(data + i);
					_size = n;
				}
				else if (n > _size)
				{
					if (n > _capacity)
						reserve(n);
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
				pointer new_data;
				int		i;
				
				new_data = alloc.allocate(n);
				for (size_type i = 0; i < _size; ++i)
					alloc.construct(new_data + i, *(data + i));
				alloc.deallocate(this->data, _capacity);
				_capacity = n;
				this->data = new_data;
			};


	// 		//element access

			reference operator[] (size_type n)
			{
				return (*(data + n));
			};
			const_reference operator[] (size_type n) const
			{
				return (*(data + n));
			};
			
			reference at (size_type n)
			{
				if (n >= _size)
					std::__throw_out_of_range("out of range");
				return (*(data + n));
			};
			const_reference at (size_type n) const
			{
				if (n >= _size)
					std::__throw_out_of_range("out of range");
				return (*(data + n));
			};;
			
			reference front()
			{
				return (*data);
			};
			const_reference front() const
			{
				return (*data);
			};
			
			reference back()
			{
				return (*(data + _size - 1));
			};
			const_reference back() const
			{
				return (*(data + _size - 1));
			};


	// 		//modifiers

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last, 
				typename ft::enable_if<std::__is_input_iterator<InputIterator>::value, InputIterator>::type = nullptr)
			{
				for (size_t i = 0; i < _size ;i++)
					alloc.destroy(data +i);
				for (;first != last; first++)
					push_back(*first);
			};
			void assign (size_type n, const value_type& val)
			{
				for (size_t i = 0; i < _size ;i++)
					alloc.destroy(data + i);
				for (size_type i = 0; i < n; i++)
					push_back(val);
			};
			
			void push_back (const value_type& val)
			{
				if (_size > _capacity)
					reserve(_capacity * 2);
				if (!data)
				{
					_capacity = 1;
					data = alloc.allocate(1);
						alloc.construct(data, val);
				}
				*(data + _size) = val;
				_size++;
			};
			void pop_back()
			{
				alloc.destroy(data + _size - 1);
				_size--;
			};
			
	// 		iterator insert (iterator position, const value_type& val) {};
	// 		void insert (iterator position, size_type n, const value_type& val) {};
	// 		template <class InputIterator>
	// 		void insert (iterator position, InputIterator first, InputIterator last) {};
			
	// 		iterator erase (iterator position) {};
	// 		iterator erase (iterator first, iterator last) {};
			
	// 		void swap (vector& x) {};
	// 		void clear() {};

	// 		//allocator
	// 		allocator_type get_allocator() const {};
	// };
  	// // relational operators
	// template <class T, class Alloc>
	// bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {};
	// template <class T, class Alloc>
	// bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {};
	// template <class T, class Alloc>
	// bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {};
	// template <class T, class Alloc>
	// bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {};
	// template <class T, class Alloc>
	// bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {};
	// template <class T, class Alloc>
	// bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {};

	// //swap
	// template <class T, class Alloc>
	// void swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {};
};
}

#endif
