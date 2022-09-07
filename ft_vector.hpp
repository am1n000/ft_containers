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
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{

		public:

			typedef T                                        value_type;
			typedef Allocator                                allocator_type;
			typedef typename allocator_type::reference       reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer         pointer;
			typedef typename allocator_type::const_pointer   const_pointer;
			typedef typename allocator_type::difference_type difference_type;
			typedef typename allocator_type::size_type       size_type;
			typedef std::__wrap_iter<pointer>                     iterator;
			typedef std::__wrap_iter<const_pointer>               const_iterator;
			typedef std::reverse_iterator<iterator>          reverse_iterator;
			typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

		private:
			size_type	__cap_;
			size_type	__size_;
			pointer	*__array_;
			allocator_type	__alloc_;


		//constructors
		public :

			explicit vector() : __array_(nullptr), __cap_(0), __size_(0) {};

			explicit vector (size_type n, const value_type& val = value_type()) : __size_(n), __cap_(0), __array_(nullptr) // 3 constructs the container with cout copies of elements with value value
			{
				if (n <= 0)
					throw("invalid size");
				for(__cap_ < n; ++__cap_)
					__alloc_()
			}; 
			template < class InputIT >
			vector(InputIT first, InputIT last, const allocator_type &alloc = allocator_type()) // 5 constructs with the contents of the range [first, last]
			{
				(void)first;
				(void)last;
				(void)alloc;
			};
			vector(const vector &other) // 6 copy constructor
			{
				(void)other;
			};


		//iterators

		iterator begin() {return iterator(0);};
		const_iterator begin() const {};
		iterator end() {};
		const_iterator end() const {};
		reverse_iterator rbegin() 
		  {return reverse_iterator(end());}
		const_reverse_iterator rbegin() const {};
		reverse_iterator rend()
		  {return const_reverse_iterator(begin());};
		const_reverse_iterator rend() const {};


		//capacity

		// size_type size() const {};
		// size_type max_size() const {};
		// void resize (size_type n, value_type val = value_type()) {};
		// size_type capacity() const {};
		// bool empty() const {};
		// void reserve (size_type n) {};


		//element access

		// reference operator[] (size_type n) {};
		// const_reference operator[] (size_type n) const {};
		// reference at (size_type n) {};
		// const_reference at (size_type n) const {};
		// reference front() {};
		// const_reference front() const {};
		// reference back() {};
		// const_reference back() const {};


		//modifiers

		// template <class InputIterator>
		// void assign (InputIterator first, InputIterator last) {};
		// template <class InputIterator>
		// void assign (size_type n, const value_type& val) {};
		// void push_back (const value_type& val) {};
		// void pop_back() {};
		// iterator insert (iterator position, const value_type& val) {};
		// void insert (iterator position, size_type n, const value_type& val) {};
		// template <class InputIterator>
		// void insert (iterator position, InputIterator first, InputIterator last) {};
		// iterator erase (iterator position) {};
		// iterator erase (iterator first, iterator last) {};
		// void swap (vector& x) {};
		// void clear() {};

		//allocator

		// allocator_type get_allocator() const {};
	};
  	// relational operators
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
}

#endif
