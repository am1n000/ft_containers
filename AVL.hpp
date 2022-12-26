/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-rhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:52:11 by ael-rhai          #+#    #+#             */
/*   Updated: 2022/12/26 10:52:13 by ael-rhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_AVL

#define FT_AVL

#include <iostream>
#include <iostream>
#include <map>
#include "ft_iterators.hpp"
#include "utility.hpp"


namespace ft
{
    template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>> >
    class AVL
    {
        public:     
                //types    
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef pair<const key_type, mapped_type>           value_type;
            typedef Compare                                     key_compare;
            typedef Allocator                                   allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::difference_type    difference_type;

            typedef ft::map_iterator<>                            iterator;
            typedef ft::map_iterator                            const_iterator;



                // struct
            typedef sturct element
            {
                value_type  _value;
                node        *_left;
                node        *_right;
                node        *_parent;
            }               node;
    };
}

#endif

