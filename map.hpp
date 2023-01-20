/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-rhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 08:44:24 by ael-rhai          #+#    #+#             */
/*   Updated: 2022/12/26 08:46:08 by ael-rhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_MAP

#define FT_MAP

#include <iostream>
#include <map>
#include "ft_iterators.hpp"
#include "utility.hpp"
#include "RB_tree.hpp"

namespace ft
{
	template< class value_type, class Key, class Compare > 
	class map_value_compare
	{
		private:
			Compare _comp;
		public:
			map_value_compare () : _comp(Compare())
			{}
			map_value_compare (Compare c) : _comp(c)
			{}
			bool operator() (const value_type& x, const value_type& y) const
			{
				return (_comp(x.first, y.first));
			}
			bool operator() (const value_type& x, const Key& y) const
			{
				return (_comp(x.first, y));
			}
			bool operator() (const Key& x, const value_type& y) const
			{
				return (_comp(x, y.first));
			}
	};

	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > > 
	class map
	{
		public:
			typedef Key                                                         				key_type;
			typedef T                                                           				mapped_type;
			typedef ft::pair<const key_type, mapped_type>                       				value_type;
			typedef Compare                                                     				key_compare;
			typedef Allocator																	allocator_type;
			typedef typename allocator_type::reference      									reference;
			typedef typename allocator_type::const_reference									const_reference;
			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c)
					{};
				public:
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};
		
		private:

			typedef	ft::map_value_compare<value_type, key_type, key_compare>					map_key_compare;
			typedef typename ft::RB_tree<key_type, value_type, map_key_compare, allocator_type>		tree_type;
			
		public:
			typedef typename tree_type::pointer        											pointer;
			typedef typename tree_type::const_pointer  											const_pointer;
			typedef typename tree_type::size_type      											size_type;
			typedef typename tree_type::difference_type											difference_type;
			typedef typename tree_type::iterator						   						iterator;
			typedef typename tree_type::const_iterator											const_iterator;
			typedef ft::reverse_iterator<iterator>                              				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>                        				const_reverse_iterator;

			
		private:

				tree_type			_data;
				key_compare			_key_comp;

		public:
			// constructors
				//empty constructor
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _data(comp, alloc)
			{};
				// range constructor
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			:_data(comp, alloc)
			{
					this->insert(first, last);
			};
				// copy constructor
			map (const map& x) : _data(x._data)
			{
			};
			
			// assignement operator =
			map& operator= (const map& x)
			{
				if (*this == x)
					return (*this);
				if (!this->empty())
					this->erase(this->begin(), this->end());
				this->_data = x._data;
				return (*this);
			};

			// destructor
			~map()
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

			// element access
			mapped_type& operator[] (const key_type& k)
			{
				return (this->insert(ft::make_pair(k, mapped_type())).first->second);
			};      
			
			mapped_type& at (const key_type& k)
			{
				return ((this->_data.at(k))->second);
			};
			const mapped_type& at (const key_type& k) const
			{
				return ((this->_data.at(k))->second);
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
				this->_data.erase(position->first);
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
			void swap (map& x)
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
	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs == rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (lhs == rhs || lhs < rhs);
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs <= rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (lhs == rhs || lhs > rhs);
	};

	// swap
	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	};


}

#endif

