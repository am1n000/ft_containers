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
			int		size;
			int		capacity;

		public :
		//constructors
			explicit vector ()
			{
				size = 0;
				capacity = 0;
				data = nullptr;
			};

			explicit vector (size_type n, const value_type& val = value_type())
			{
				size = n;
				capacity = n;
				data = alloc.allocate(capacity);
				for (size_type i = 0; i < n; ++i)
					alloc.construct(data + i, val);
			};

			template <class InputIterator>
			vector (InputIterator first, InputIterator last)
			{
				size = 0;
				capacity = 0;
				data = nullptr;
				while (first != last)
				{
					push_back(*first);
					first++;
					size++;
				}
				capacity = size; 
			};

			vector (const vector& x)
			{
				return (*this(x.begin(), x.end()));
			};

		//destructor
			~vector()
			{
				alloc.deallocate(data, capacity);
				alloc.destroy(data);
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
				return (iterator(data + size));
			};
			const_iterator end() const
			{
				return (const_iterator(data + size));
			};

			reverse_iterator rbegin()
			{
				return (reverse_iterator(end());
			};
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end());
			};

			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			};
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			};


			//capacity
	// 		size_type size() const {};
			size_type max_size() const
			{
				return (alloc.max_size());
			};
	// 		void resize (size_type n, value_type val = value_type()) {};
	// 		size_type capacity() const {};
	// 		bool empty() const {};
			void reserve (size_type n)
			{
				pointer new_data;
				int		i;
				
				new_data = alloc.allocate(n);
				for (size_type i = 0; i < size; ++i)
					alloc.construct(new_data + i, *(data + i));
				alloc.deallocate(this->data, capacity);
				capacity = n;
				this->data = new_data;
			};


	// 		//element access

	// 		reference operator[] (size_type n) {};
	// 		const_reference operator[] (size_type n) const {};
			
	// 		reference at (size_type n) {};
	// 		const_reference at (size_type n) const {};
			
	// 		reference front() {};
	// 		const_reference front() const {};
			
	// 		reference back() {};
	// 		const_reference back() const {};


	// 		//modifiers

	// 		template <class InputIterator>
	// 		void assign (InputIterator first, InputIterator last) {};
	// 		template <class InputIterator>
	// 		void assign (size_type n, const value_type& val) {};
			
			void push_back (const value_type& val)
			{
				if (size > capacity)
					reserve(capacity * 2);
				*(data + size) = val;
				size++;
			};
	// 		void pop_back() {};
			
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
