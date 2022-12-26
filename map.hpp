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
#include <iostream>
#include <map>
#include "ft_iterators.hpp"
#include "utility.hpp"


namespace ft
{
    // template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > > 
    // class map
    // {
    //     public:

    //         typedef Key                                                         key_type;
    //         typedef T                                                           mapped_type;
    //         typedef pair<const key_type, mapped_type>                           value_type;
    //         typedef Compare                                                     key_compare;

    //         typedef ft::AVL<key_type, mapped_type, value_type, Allocator>       tree_type;
    //         typedef tree_type::allocator_type                          allocator_type;
    //         typedef tree_type::reference                               reference;
    //         typedef tree_type::const_reference                         const_reference;
    //         typedef tree_type::pointer                                 pointer;
    //         typedef tree_type::const_pointer                           const_pointer;
    //         typedef tree_type::size_type                               size_type;
    //         typedef tree_type::difference_type                         difference_type;
    //         typedef tree_type::iterator                                iterator;
    //         typedef tree_type::const_iterator                          const_iterator;
    //         typedef ft::reverse_iterator<iterator>                              reverse_iterator;
    //         typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;


    //         // constructors
    //             //empty constructor
    //         explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
    //         {};
    //             // range constructor
    //         template <class InputIterator>
    //         map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
    //         {};
    //             // copy constructor
    //         map (const map& x)
    //         {};
            
    //         // assignement operator =
    //         map& operator= (const map& x)
    //         {};

    //         // destructor
    //         ~map()
    //         {};

    //         // iterators
    //             // begin
    //         iterator begin()
    //         {};
    //         const_iterator begin() const
    //         {};
    //             // end
    //         iterator end()
    //         {};
    //         const_iterator end() const
    //         {};
    //             // rbegin
    //         reverse_iterator rbegin()
    //         {};
    //         const_reverse_iterator rbegin() const
    //         {};
    //             // rend
    //         reverse_iterator rend()
    //         {};
    //         const_reverse_iterator rend() const
    //         {};

    //         // capacity
    //         bool empty() const
    //         {};
    //         size_type size() const
    //         {};
    //         size_type max_size() const
    //         {};

    //         // element access
    //         mapped_type& operator[] (const key_type& k)
    //         {};

    //         // modifiers
    //             // insert(single element)
    //         pair<iterator,bool> insert (const value_type& val)
    //         {};
    //             // insert(with position)
    //         iterator insert (iterator position, const value_type& val)
    //         {};
    //             // insert(range)
    //         template <class InputIterator>  void insert (InputIterator first, InputIterator last)
    //         {};
    //             // erase(position)
    //         void erase (iterator position)
    //         {};
    //             // erase(key)
    //         size_type erase (const key_type& k)
    //         {};
    //             // erase(range)
    //         void erase (iterator first, iterator last)
    //         {};
    //             // swap
    //         void swap (map& x)
    //         {};
    //             // clear
    //         void clear()
    //         {};

    //         // observers
    //         key_compare key_comp() const
    //         {};
    //         value_compare value_comp() const
    //         {};

    //         // operations
    //             // find
    //         iterator find (const key_type& k)
    //         {};
    //         const_iterator find (const key_type& k) const
    //         {};
    //             // count
    //         size_type count (const key_type& k) const;
    //             // lower_bound
    //         iterator lower_bound (const key_type& k)
    //         {};
    //         const_iterator lower_bound (const key_type& k) const
    //         {};
    //             // upper_bound
    //         iterator upper_bound (const key_type& k)
    //         {};
    //         const_iterator upper_bound (const key_type& k) const
    //         {};
    //             // equal_range
    //         pair<iterator,iterator> equal_range (const key_type& k)
    //         {};
    //         pair<const_iterator,const_iterator> equal_range (const key_type& k) const
    //         {};

    //         // allocator
    //         allocator_type get_allocator() const
    //         {};



























    // }
    













}

#endif

