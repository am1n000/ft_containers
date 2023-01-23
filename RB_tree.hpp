/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RB.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-rhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:01:42 by ael-rhai          #+#    #+#             */
/*   Updated: 2023/01/03 16:01:45 by ael-rhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_RB_TREE

#define FT_RB_TREE

#include <iostream>
#include <iostream>
#include <map>
#include "ft_iterators.hpp"
#include "utility.hpp"

namespace ft
{

	template<typename value_type>
	class node
	{
		enum color{RED = 1, BLACK = 2 };
		public:
			value_type      *value;
			int             color;
			bool			is_nil;
			bool			is_end;
			node            *left;
			node            *right;
			node            *parent;

			node(node *p, node *l, node *r, int c, bool n, bool e)
			: color(c), is_nil(n), is_end(e), left(l), right(r), parent(p) {};
			~node() {};
	};



	template< typename key_type, typename value_type, class Compare, class Allocator> 
	class RB_tree
	{
            
		public:
			typedef typename Allocator::template rebind<node<value_type> >::other	    		node_allocator;
			typedef typename node_allocator::reference      									reference;
			typedef typename node_allocator::const_reference									const_reference;
			typedef typename node_allocator::pointer        									pointer;
			typedef typename node_allocator::const_pointer  									const_pointer;
			typedef typename node_allocator::size_type      									size_type;
			typedef typename node_allocator::difference_type									difference_type;
			typedef typename ft::tree_iterator<value_type*, pointer, Compare>	   				iterator;
			typedef typename ft::tree_iterator<value_type*, const_pointer, Compare>				const_iterator;
			typedef	Compare																		key_compare;

		private:

				node<value_type>	*_root;
				node<value_type>	*_nil;
				node<value_type>	*_begin;
				Allocator			_alloc;
				node_allocator		_node_alloc;
				key_compare 		_comp;
				size_type	 		_size;

		public:
			enum color{RED = 1, BLACK = 2 };
			// constructors
				//empty constructor
			RB_tree (const Compare& c, const Allocator& alloc)
			:_root(nullptr), _nil(NULL), _alloc(alloc), _comp(c), _size(0)
			{
				this->_nil = this->_node_alloc.allocate(1);
				this->_node_alloc.construct(this->_nil, node<value_type>(this->_nil, this->_nil, this->_nil, BLACK, 1, 0));
				this->_nil->value = this->_alloc.allocate(1);
				this->_alloc.construct(this->_nil->value, value_type());
                this->_begin = this->_nil;
			};
			RB_tree (const RB_tree& x)
			: _alloc(x.value_alloc()),_comp(x.value_comp()), _size(0)
			{
				this->_alloc = x.value_alloc();
				this->_comp = x.value_comp();
				this->_nil = this->_node_alloc.allocate(1);
				this->_node_alloc.construct(this->_nil, node<value_type>(this->_nil, this->_nil, this->_nil, BLACK, 1, 0));
				this->_nil->value = this->_alloc.allocate(1);
				this->_alloc.construct(this->_nil->value, value_type());
				this->_root = nullptr;
                this->_begin = this->_nil;

				iterator it_end = x.end();
				for (iterator it = x.begin(); it != it_end; it++)
					insert(this->_root, *it);
			};
			
			RB_tree &operator=(const RB_tree& x) 
			{
				if (this->_size)
					this->clear();
				if (this->_nil)
					destroy(this->_nil);
				this->_alloc = x.value_alloc();
				this->_comp = x.value_comp();
				this->_nil = this->_node_alloc.allocate(1);
				this->_node_alloc.construct(this->_nil, node<value_type>(this->_nil, this->_nil, this->_nil, BLACK, 1, 0));
				this->_nil->value = this->_alloc.allocate(1);
				this->_alloc.construct(this->_nil->value, value_type());
				this->_root = nullptr;
                this->_begin = this->_nil;

				iterator it_end = x.end();
				for (iterator it = x.begin(); it != it_end; it++)
					insert(this->_root, *it);
				return (*this);
			};

			// destructor 
			~RB_tree()
			{
				this->clear();
				this->_alloc.destroy(this->_nil->value);
				this->_alloc.deallocate(this->_nil->value, 1);
				this->_node_alloc.destroy(this->_nil);
				this->_node_alloc.deallocate(this->_nil, 1);
			};

			//base
			iterator base()
			{
				return (iterator(this->_root));
			}
			// iterators
				// begin
			iterator begin()
			{
				return (iterator(_begin));
			};
			const_iterator begin() const
			{
				return (const_iterator(_begin));
			};
				// end
			iterator end()
			{
				return (iterator(this->_nil));
			};
			const_iterator end() const
			{
				return (const_iterator(this->_nil));
			};

			// capacity
			bool empty() const
			{};
			size_type size() const
			{
				return (this->_size);
			};
			size_type max_size() const
			{
				return (std::min<size_type>(this->_node_alloc.max_size(),
					std::numeric_limits<difference_type >::max()));
			};

			// modifiers
				// insert(single element)

			void left_rotate(node<value_type> *upper, node<value_type> *lower)
			{
				upper->right = lower->left;     		//1 upper->right = lower->left
				if (lower->left != this->_nil)  		//1
					lower->left->parent = upper;		//1
				lower->parent = upper->parent;			//2 lower->parent = upper->parent
				if (upper->parent->is_nil)		//3 if upper is root make lower the new root
					this->_root = lower;				//3
				else if (upper == upper->parent->left)	//4 if upper was a left child then make lower a left child
					upper->parent->left = lower;		//4
				else									//5 otherwise make lower a right child
					upper->parent->right = lower;		//5	
				lower->left = upper;					//6	make upper child of lower 
				upper->parent = lower;					//6
			}
			void right_rotate(node<value_type> *upper, node<value_type> *lower)
			{
				upper->left = lower->right;				//1 upper->left = lower->right
				if (lower->right != this->_nil)			//1
					lower->right->parent = upper;		//1
				lower->parent = upper->parent;			//2 lower->parent = upper->parent
				if (upper->parent->is_nil)		//3 if uppper is root make lower the new root
					this->_root = lower;				//3
				else if (upper == upper->parent->left)	//4 if upper was left child make lower a left child
					upper->parent->left = lower;		//4
				else									//5 otherwise make lower right child
					upper->parent->right = lower;		//5 make upper child of lower
				lower->right = upper;					//6 
				upper->parent = lower;
			}

			// . node operation.................................................................
			node<value_type> *tree_min(node<value_type> *nod)
			{
				while (nod->left->is_nil == 0)
					nod = nod->left;
				return (nod);
			}

			node<value_type> *tree_max(node<value_type> *nod)
			{
				while (nod->right->is_nil == 0)
					nod = nod->right;
				return (nod);
			}

			void node_exchange(node<value_type> *nod1, node<value_type> *nod2)
			{
				if (nod1->parent->is_nil == 1)
					this->_root = nod2;
				else if (nod1 == nod1->parent->left)
					nod1->parent->left = nod2;
				else
					nod1->parent->right = nod2;
				nod2->parent = nod1->parent;
			}

			iterator lower_bound (const key_type& k)
			{				
				node<value_type> 	*found = this->_nil;
				node<value_type>	*temp = this->_root;
				while (temp && temp->is_nil == 0)
				{
					if (!this->_comp(*temp->value, k))
					{
						found = temp;
						temp = temp->left;
					}
					else
						temp = temp->right;
				}
				if (found != this->_nil)
					return (found);
				return (this->_nil);
			};			
			const_iterator lower_bound (const key_type& k) const
			{				
				node<value_type> 	*found = this->_nil;
				node<value_type>	*temp = this->_root;
				while (temp && temp->is_nil == 0)
				{
					if (!this->_comp(*temp->value, k))
					{
						found = temp;
						temp = temp->left;
					}
					else
						temp = temp->right;
				}
				if (found != this->_nil)
					return (found);
				return (this->_nil);
			};			

			iterator upper_bound (const key_type& k)
			{				
				node<value_type> 	*found = this->_nil;
				node<value_type>	*temp = this->_root;

				while (temp && temp->is_nil == 0)
				{
					if (!this->_comp(*temp->value, k))
					{
						found = temp;
						temp = temp->left;
					}
					else
						temp = temp->right;
				}
				if (found != this->_nil && !this->_comp(k, *found->value))
					return (++(iterator(found)));
				else if (found != this->_nil)
					return (iterator(found));
				return (this->_nil);

			};
			const_iterator upper_bound (const key_type& k) const
			{				
				node<value_type> 	*found = this->_nil;
				node<value_type>	*temp = this->_root;

				while (temp && temp->is_nil == 0)
				{
					if (!this->_comp(*temp->value, k))
					{
						found = temp;
						temp = temp->left;
					}
					else
						temp = temp->right;
				}
				if (found != this->_nil && !this->_comp(k, *found->value))
					return (++(iterator(found)));
				else if (found != this->_nil)
					return (iterator(found));
				return (this->_nil);

			};
			
			// .Insertion. .................................................................................

            void    check_insertion(node<value_type> *n_node)
            {
                while (n_node->parent->color == RED)
                {
                    node<value_type> *uncle;
                    if (n_node->parent == n_node->parent->parent->left)		//the inserted node's parent  is left node
                    {
                        uncle = n_node->parent->parent->right;
                        if (uncle->color == RED)                            //first case (uncle is red)
                        {
                            n_node->parent->color = BLACK;
                            uncle->color = BLACK;
                            n_node->parent->parent->color = RED;
                            n_node = n_node->parent->parent;
                        }
                        else                                            	//second case (uncle is black)
                        {
                            if (n_node == n_node->parent->right)			// left rotate if node is right child to make it a 
                            {												// right right situation
                                n_node = n_node->parent;
                                this->left_rotate(n_node, n_node->right);
                            }
							n_node->parent->color = BLACK;
							n_node->parent->parent->color = RED;
							right_rotate(n_node->parent->parent, n_node->parent);
                        }
                    }
					else													//the inserted node's parent  is right node
					{
						uncle = n_node->parent->parent->left;
						if (uncle->color == RED)
						{
                            n_node->parent->color = BLACK;
                            uncle->color = BLACK;
                            n_node->parent->parent->color = RED;
                            n_node = n_node->parent->parent;
						}
						else
						{
							if (n_node == n_node->parent->left)
							{
								n_node = n_node->parent;
								right_rotate(n_node, n_node->left);
							}
							n_node->parent->color = BLACK;
							n_node->parent->parent->color = RED;
							left_rotate(n_node->parent->parent, n_node->parent);
						}
					}
                }
				this->_root->color = BLACK;
            }
			//insertion
			pair<iterator,bool> insert (iterator pos, const value_type& val)
			{
				iterator temp_pos = pos;
                node<value_type> *element = this->_root;
				if (!this->_root)
					element = this->_nil;
                node<value_type> *position = this->_nil;
                node<value_type> *new_node = this->_node_alloc.allocate(1);
                this->_node_alloc.construct(new_node, node<value_type>(this->_nil, this->_nil, this->_nil, RED, 0, 0));
                new_node->value = this->_alloc.allocate(1);
				this->_alloc.construct(new_node->value, val);
				// ?checking pos..................
				if (this->_root != NULL && pos != this->end())
				{
					iterator after = ++pos;
					pos = temp_pos;
					iterator before = --pos;
					if ((this->_comp(*temp_pos, val) && (this->_comp(val, *after) || temp_pos.base() == this->_nil) && temp_pos.base()->right->is_nil)
						|| (this->_comp(val, *temp_pos) && (this->_comp(*before, val) || temp_pos.base() == this->_begin) && temp_pos.base()->left->is_nil))// ? to check if the given position is the right position to insert 
						element = temp_pos.base();
				}

				// ? ..........................................................
                while (element != this->_nil) // find where to insert
                {
                    position = element;
                    if (!this->_comp(*new_node->value, *element->value) && !this->_comp(*element->value, *new_node->value))
                    {
						this->destroy(new_node);
                        return(pair<iterator,bool> (iterator(element), false));//element already exists
                    }
                    if (this->_comp(*new_node->value, *element->value))
                        element = element->left;
                    else
                        element = element->right;
                }
                new_node->parent = position;    // inserting the new node
                if (position == this->_nil)      // if tree is empty 
                {
                    this->_root = new_node;     //new node is root
                    this->_root->is_end = 1;
                    this->_root->parent = this->_nil;
                    this->_begin = new_node;
                    this->_nil->parent = new_node;
                    this->_root->color = BLACK;
                }
                else if (this->_comp(*new_node->value, *position->value)) // now we just modify the parent
                    position->left = new_node;
                else
                    position->right = new_node;
                if (this->_comp(*new_node->value, *this->_begin->value))
                    this->_begin = new_node;
                if (!this->_comp(*new_node->value, *this->_nil->parent->value))
				{
                    this->_nil->parent->is_end = 0; // ! si end is not necessary
                    this->_nil->parent = new_node;
                    new_node->is_end = 1;
				}
                check_insertion(new_node);
				this->_size++;
				return (pair<iterator,bool> (iterator(new_node), 1));
			};

			// .search......................................................................................
			node<value_type> *find (const key_type& k)
			{
				node<value_type> 	*found = this->_nil;
				node<value_type>	*temp = this->_root;
				while (temp && temp->is_nil == 0)
				{
					if (!this->_comp(*temp->value, k)) // ? if it the value is lower
					{
						found = temp;
						if(!this->_comp(k, *temp->value))
							return (found);
						temp = temp->left;
					}
					else							// ? if the value is greater
						temp = temp->right;
				}
				return (this->_nil);
			};
			const node<value_type> *find (const key_type& k) const
			{
				node<value_type> 	*found = this->_nil;
				node<value_type>	*temp = this->_root;
				while (temp && temp->is_nil == 0)
				{
					if (!this->_comp(*temp->value, k)) // ? if it the value is lower
					{
						found = temp;
						if(!this->_comp(k, *temp->value))
							return (found);
						temp = temp->left;
					}
					else							// ? if the value is greater
						temp = temp->right;
				}
				return (this->_nil);
			};

			iterator at (const key_type& k) const
			{
				node<value_type> 	*found = this->_nil;
				node<value_type>	*temp = this->_root;
				while (temp && temp->is_nil == 0)
				{
					if (!this->_comp(*temp->value, k)) // ? if it the value is lower
					{
						found = temp;
						if(!this->_comp(k, *temp->value))
							return (iterator(found));
						temp = temp->left;
					}
					else							// ? if the value is greater
						temp = temp->right;
				}
        		throw (std::out_of_range("map::at:  key not found"));
				return (this->_nil);
			};

			// .count......................................................................................

			size_type count (const key_type& k) const
			{
				node<value_type>	*temp = this->_root;
				while (temp && temp->is_nil == 0)
				{
					if (!this->_comp(*temp->value, k)) // ? if it the value is lower
					{
						if(!this->_comp(k, *temp->value))
							return (1);
						temp = temp->left;
					}
					else							// ? if the value is greater
						temp = temp->right;
				}
				return (0);
			};

			// . deletion...................................................

			void	delete_node(node<value_type> *nd)
			{
				this->_alloc.destroy(nd->value);
				this->_alloc.deallocate(nd->value, 1);
				this->_node_alloc.destroy(nd);
				this->_node_alloc.deallocate(nd, 1);
			}
			void destroy(node<value_type> *nd)
			{
				if (nd != NULL)
				{
					if (nd->left->is_nil)
						nd->left = nullptr;
					if (nd->right->is_nil)
						nd->right = nullptr;
					destroy(static_cast< node<value_type>* >(nd->left)); // ! remove this
					destroy(static_cast< node<value_type>* >(nd->right));
					delete_node(nd);
				}
			}

			// clear
			void clear()
			{
				if (this->_root)
				{
					if (this->_root->is_nil == 0)
						destroy(this->_root);
				}
				this->_begin = this->_nil;
				this->_root = nullptr;
				this->_size = 0;
			}
			void fix_deletion(node<value_type> *child) // ? based on lenny's lecture
			{
				node<value_type> *sibling;
				while (child != this->_root && child->color == BLACK)
				{
					if (child == child->parent->left) // ? if its a left child
					{
						sibling = child->parent->right;
						if (sibling->color == RED) // case 4, //? which will always be followed by other cases
						{
							// std::cout << " case01" <<std::endl;
							sibling->color = BLACK;		// ? swapping colors of sibling
							child->parent->color = RED; // ? and parent
							this->left_rotate(child->parent, sibling); // ? rotate to the direction of DB
							sibling = child->parent->right; // ? which is the old child parent
						}
						if (sibling->left->color == BLACK && sibling->right->color == BLACK) // case 3 
						{
							// std::cout << " case02" <<std::endl;
							sibling->color = RED; // ? make the sibling RED (angry)
							child = child->parent;
						} // ? if the parent is red exit the loop and <<<make it black>>>. if not reloop because the child now is DB
						else // ? one of the children is red
						{
							if (sibling->right->color == BLACK) // case 5 // ? which will be always followed by case 6
							{
							// std::cout << " case03" <<std::endl;
								sibling->left->color = BLACK; // ? come down the angry child
								sibling->color = RED; // ? make the parent angry
								this->right_rotate(sibling, sibling->left); // ? rotate in opposite direction of DB
								sibling = child->parent->right; // ? there is a new sibling because we rotated 
							}
							// case 6
							// std::cout << " case04" <<std::endl;
							sibling->color = child->parent->color; // ? give parent color to sibling
							child->parent->color = BLACK; // ? make parent black 
							sibling->right->color = BLACK; // ? give the extra black to the angry child
							this->left_rotate(child->parent, sibling);
							child = this->_root; // ? to exit the loop
						}
					}
					else // ? if its a right child
					{
						sibling = child->parent->left;
						if (sibling->color == RED) // case 4, //? which will always be followed by other cases
						{
							// std::cout << " case1" <<std::endl;
							sibling->color = BLACK;		// ? swapping colors of sibling
							child->parent->color = RED; // ? and parent
							this->right_rotate(child->parent, sibling); // ? rotate to the direction of DB
							sibling = child->parent->left; // ? which is the old child parent
						}
						if (sibling->right->color == BLACK && sibling->left->color == BLACK) // case 3 
						{
							// std::cout << " case2" <<std::endl;
							sibling->color = RED; // ? make the sibling RED (angry)
							child = child->parent;
						} // ? if the parent is red exit the loop and <<<make it black>>>. if not reloop because the child now is DB
						else // ? one of the children is red
						{
							if (sibling->left->color == BLACK) // case 5 // ? which will be always followed by case 6
							{
							// std::cout << " case3" <<std::endl;
								sibling->right->color = BLACK; // ? come down the angry child
								sibling->color = RED; // ? make the parent angry
								this->left_rotate(sibling, sibling->right); // ? rotate in opposite direction of DB
								sibling = child->parent->left; // ? there is a new sibling because we rotated 
							}
							// std::cout << " case4" <<std::endl;
							//case 6
							sibling->color = child->parent->color; // ? give parent color to sibling 
							child->parent->color = BLACK; // ? make parent black
							sibling->left->color = BLACK; // ? give the extra black to the angry child
							this->right_rotate(child->parent, sibling);
							child = this->_root; // ? to exit the loop
						}
					}
				}
				child->color = BLACK; // ? for many reasons
													// ? if the child is was red before the while, just make it black because the deleted node was black
													// ? for case 3
													// ? if its root and was made red in the while it should be black
													// ? in all cases the left child from the while is either gonna be black or should be turned into black
			}

			size_type erase (const key_type& k)
			{
				node<value_type>	*x = this->find(k);
				if (x == this->_nil)
					return (0);
				node<value_type>	*temp1 = x;
				int temp1_original_color = temp1->color;
				node<value_type>	*temp2;
				node<value_type>	*store_end = this->_node_alloc.allocate(1);
				this->_node_alloc.construct(store_end, node<value_type>(this->_nil->parent, this->_nil, this->_nil, BLACK, 1, 0));
				if (x == this->_nil->parent) // ? x is the end node , its parent will be the end  node
				{
					store_end->parent = (--(--(this->end()))).base();
				}
				if (x->left->is_nil) // if x has at most one child replace it with that child
				{
					if (x == this->_begin)
						this->_begin = (++(this->begin())).base();
					temp2 = x->right;
					this->node_exchange(x, x->right);
				}
				else if (x->right->is_nil)
				{
					temp2 = x->left;
					this->node_exchange(x, x->left);
				}
				else // ? it has two children
				{
					temp1 = this->tree_min(x->right);
					temp1_original_color = temp1->color;
					temp2 = temp1->right;
					if (temp1 != x->right) // ? temp1 is not x's direct right child
					{
						this->node_exchange(temp1, temp1->right);// ? we moved temp1 to x' place so we need to move temp1'right child to its'place also
						temp1->right = x->right;			// ? we fix temp1 new right
						temp1->right->parent = temp1;
					}
					else // ? in case temp2 is nil ... will need it in fix_deletion to know its parent even if its nil
						temp2->parent = temp1;
					this->node_exchange(x, temp1); // ? replace x with it successor
					temp1->left = x->left;			// ? fix left child
					temp1->left->parent = temp1;
					temp1->color = x->color;		// ? fix color
				}
				if (temp1_original_color == BLACK) //? case 1: if the deleted node is red just exit
					fix_deletion(temp2);
				this->_nil->parent = store_end->parent;
				this->_node_alloc.destroy(store_end);
				this->_node_alloc.deallocate(store_end, 1);
				delete_node(x);
				this->_size--;
				if (_size == 0)
					this->_begin = this->_nil;
				return(1);
			};

			//. swap..........................................................................................
			
			template< typename key_typ, typename value_typ, class Compar, class Allocato> 
			void swap(RB_tree<key_typ, value_typ, Compar, Allocato>& __t)
			{
				node<value_type>	*temp_root = this->_root;
				node<value_type>	*temp_nil = this->_nil;
				node<value_type>	*temp_begin = this->_begin;
				Allocator			temp_alloc = this->_alloc;
				node_allocator		temp_node_alloc = this->_node_alloc;
				key_compare 		temp_comp = this->_comp;
				size_type	 		temp_size = this->_size;
				
				this->_root = __t._root;
				this->_nil = __t._nil;
				this->_begin = __t._begin;
				this->_alloc = __t._alloc;
				this->_node_alloc = __t._node_alloc;
				this->_comp = __t._comp;
				this->_size = __t._size;

				__t._root = temp_root;
				__t._nil = temp_nil;
				__t._begin = temp_begin;
				__t._alloc = temp_alloc;
				__t._node_alloc = temp_node_alloc;
				__t._comp = temp_comp;
				__t._size = temp_size;

			}
			
			//. comp && alloc..................................................................................

			Compare value_comp() const
			{
				return (this->_comp);
			};
			node_allocator value_alloc() const
			{
				return (this->_alloc);
			};
    };
}

#endif