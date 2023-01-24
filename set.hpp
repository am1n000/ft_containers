/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-rhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:43:17 by ael-rhai          #+#    #+#             */
/*   Updated: 2023/01/23 14:43:18 by ael-rhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FT_SET

#define FT_SET

#include "RB_tree.hpp"

namespace ft
{
	
	template < class T, class Compare = std::less<T>, class Allocator = std::allocator<T> > 
	class set
	{
		public:
			typedef T                                                         					key_type;
			typedef T                                                         					value_type;
			typedef Compare                                                     				key_compare;
			typedef Compare                                                     				value_compare;
			typedef Allocator																	allocator_type;
			typedef typename allocator_type::reference      									reference;
			typedef typename allocator_type::const_reference									const_reference;
		
		private:
			typedef typename ft::RB_tree<key_type, value_type, value_compare, allocator_type>	tree_type;
			
		public:
			typedef typename tree_type::pointer        											pointer;
			typedef typename tree_type::const_pointer  											const_pointer;
			typedef typename tree_type::iterator						   						iterator;
			typedef typename tree_type::const_iterator											const_iterator;
			typedef ft::reverse_iterator<iterator>                              				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>                        				const_reverse_iterator;
			typedef typename tree_type::difference_type											difference_type;
			typedef typename tree_type::size_type      											size_type;

			
		private:

				tree_type			_data;

		public:
			// constructors
				//empty constructor
			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _data(comp, alloc)
			{};
				// range constructor
			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			:_data(comp, alloc)
			{
					this->insert(first, last);
			};
				// copy constructor
			set (const set& x) : _data(x._data)
			{};
			
			// assignement operator =
			set& operator= (const set& x)
			{
				this->_data = x._data;
				return (*this);
			};

			// destructor
			~set()
			{};

			// iterators
				// begin
			iterator begin()
			{
				return (_data.begin());
			};
			const_iterator begin() const
			{
				return (this->_data.begin());
			};
				// end
			iterator end()
			{
				return (this->_data.end());
			};
			const_iterator end() const
			{
				return (this->_data.end());
			};
				// rbegin
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

			// capacity
			bool empty() const
			{
				return (this->_data.size() == 0);
			};
			size_type size() const
			{
				return(this->_data.size());
			};
			size_type max_size() const
			{
				return(this->_data.max_size());
			};


			// modifiers
				// insert(single element)
			pair<iterator,bool> insert (const value_type& val)
			{
				return (this->_data.insert(this->_data.base(),val));
			};
				// insert(hint)
			iterator insert (iterator position, const value_type& val)
			{
				return ((this->_data.insert(position,val)).first);
			};
				// insert(range)
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					this->_data.insert(this->_data.base(),*first);
					first++;
				}
			};
				// erase(position)
     		void erase (iterator position)
			{
				this->_data.erase(*position);
			};
				// erase(key)
			size_type erase (const key_type& k)
			{
				return(this->_data.erase(k));
			};
				// erase(range)
			void erase (iterator first, iterator last)
			{
				iterator temp;
				while (first != last)
				{
					temp = ++first;
					this->erase(--first);
					first = temp;
				}
			};
				// swap
			void swap (set& x)
			{
				this->_data.swap(x._data);
			};
				// clear
			void clear()
			{
				this->_data.clear();
			};

			// observers
			key_compare key_comp() const
			{
				return(key_compare());
			};
			value_compare value_comp() const
			{
				return (value_compare(key_comp()));
			};


			// operations
				// find
			iterator find (const key_type& k)
			{
				return (iterator(this->_data.find(k)));
			};
			const_iterator find (const key_type& k) const
			{
				return (const_iterator(this->_data.find(k)));
			};
				// count
			size_type count (const key_type& k) const
			{
				return (this->_data.count(k));
			};
				// lower_bound
			iterator lower_bound (const key_type& k)
			{
				return (this->_data.lower_bound(k));
			};
			const_iterator lower_bound (const key_type& k) const
			{
				return (const_iterator(this->_data.lower_bound(k)));
			};
				// upper_bound
			iterator upper_bound (const key_type& k)
			{
				return (this->_data.upper_bound(k));
			};
			const_iterator upper_bound (const key_type& k) const
			{
				return (const_iterator(this->_data.upper_bound(k)));
			};
				// equal_range
			pair<iterator,iterator> equal_range (const key_type& k)
			{
				return(ft::make_pair(this->lower_bound(k), this->upper_bound(k)));};
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				return(ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
			};

			// allocator
			allocator_type get_allocator() const
			{
				return (this->_data.value_alloc());
			};
	};

	template <class T, class Compare, class Alloc>
	bool operator== ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	};
	template <class T, class Compare, class Alloc>
	bool operator!= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
	{
		return (!(lhs == rhs));
	};
	template <class T, class Compare, class Alloc>
	bool operator<  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};
	template <class T, class Compare, class Alloc>
	bool operator<= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
	{
		return (lhs == rhs || lhs < rhs);
	};
	template <class T, class Compare, class Alloc>
	bool operator>  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
	{
		return (!(lhs <= rhs));
	};
	template <class T, class Compare, class Alloc>
	bool operator>= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs )
	{
		return (lhs == rhs || lhs > rhs);
	};

	// swap
	template <class T, class Compare, class Alloc>
	void swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y)
	{
		x.swap(y);
	};


}

#endif

