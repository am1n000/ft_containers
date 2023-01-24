/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-rhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:32:33 by ael-rhai          #+#    #+#             */
/*   Updated: 2023/01/23 13:32:35 by ael-rhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_STACK

#define FT_STACK

#include "vector.hpp"

namespace ft
{

	template <class T, class Container = ft::vector<T> >
	class stack
	{

		public:
			typedef Container                                container_type;
			typedef typename container_type::reference       reference;
			typedef typename container_type::const_reference const_reference;
			typedef typename container_type::value_type      value_type;
			typedef typename container_type::size_type       size_type;

		protected:
			container_type _c;

		public:

		//constructor
		explicit stack (const container_type& ctnr = container_type()) : _c(ctnr)
		{};

		bool empty() const
		{
			return(_c.empty());
		};

		size_type size() const
		{
			return (this->_c.size());
		};

		value_type& top()
		{
			return (this->_c.back());
		};
		const value_type& top() const
		{
			return (this->_c.back());
		};

		void push (const value_type& val)
		{
			this->_c.push_back(val);
		};

		void pop()
		{
			this->_c.pop_back();
		};
 
		friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return (lhs._c == rhs._c);
		} 
		friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return (lhs._c != rhs._c);
		} 
		friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return (lhs._c < rhs._c);
		} 
		friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return (lhs._c <= rhs._c);
		} 
		friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return (lhs._c > rhs._c);
		} 
		friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{
			return (lhs._c >= rhs._c);
		};
	};
}

#endif
