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
			typedef typename ft::tree_iterator<value_type*, pointer>	   						iterator;
			typedef typename ft::tree_iterator<value_type*, const_pointer>						const_iterator;
			typedef	Compare																		key_compare;

		private:

				node<value_type>	*_root;
				node<value_type>	*_nil;
				node<value_type>	*_begin;
				node<value_type>	*_end;
				Allocator			_alloc;
				node_allocator		_node_alloc;
				key_compare 		_comp;
				size_type	 		_size;

		public:
			enum color{RED = 1, BLACK = 2 };
			// constructors
				//empty constructor
			RB_tree (const Compare& c, const Allocator& alloc)
			:_nil(NULL), _alloc(alloc), _comp(c), _size(0)
			{
				this->_nil = this->_node_alloc.allocate(1);
				this->_node_alloc.construct(this->_nil, node<value_type>(NULL, NULL, NULL, BLACK, 1, 0)); //! replace NULL with this nil
				this->_alloc.construct(this->_nil->value, value_type());
                this->_root = this->_nil;
                this->_root->parent = this->_nil;
                this->_begin = this->_nil;
				this->_end = this->_nil;
                this->_end->is_end = 1;
			};
			RB_tree (const RB_tree& x)
			: _alloc(x.value_alloc()),_comp(x.value_comp()), _size(0)
			{
				for (iterator it = x.begin(); it != x.end(); it++)
					insert(this->_root, *it);
			};
			
			//.deletion.................................................
			void delete_node(node<value_type> *nd)
			{
				this->_node_alloc.destroy(nd);
				this->_node_alloc.deallocate(nd, 1);
			}

			// destructor
			~RB_tree()
			{
				this->clear();
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
				return (iterator(_end));
			};
			const_iterator end() const
			{
				return (iterator(_end));
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
				node<value_type> 	*found = this->_end;
				node<value_type>	*temp = this->_root;
				while (temp->is_nil == 0)
				{
					if (!this->_comp(temp->value, k))
					{
						found = temp;
						temp = temp->left;
					}
					else
						temp = temp->right;
				}
				if (found != this->_nil)
					return (found);
				return (this->_end);
			};			
			const_iterator lower_bound (const key_type& k) const
			{				
				node<value_type> 	*found = this->_end;
				node<value_type>	*temp = this->_root;
				while (temp->is_nil == 0)
				{
					if (!this->_comp(temp->value, k))
					{
						found = temp;
						temp = temp->left;
					}
					else
						temp = temp->right;
				}
				if (found != this->_nil)
					return (found);
				return (this->_end);
			};			

			iterator upper_bound (const key_type& k)
			{				
				node<value_type> 	*found = this->_end;
				node<value_type>	*temp = this->_root;

				while (temp->is_nil == 0)
				{
					if (!this->_comp(temp->value, k))
					{
						found = temp;
						temp = temp->left;
					}
					else
						temp = temp->right;
				}
				if (found != this->_nil && !this->_comp(k, found->value))
					return (++(iterator(found)));
				else if (found != this->_nil)
					return (iterator(found));
				return (this->_end);

			};
			const_iterator upper_bound (const key_type& k) const
			{				
				node<value_type> 	*found = this->_end;
				node<value_type>	*temp = this->_root;

				while (temp->is_nil == 0)
				{
					if (!this->_comp(temp->value, k))
					{
						found = temp;
						temp = temp->left;
					}
					else
						temp = temp->right;
				}
				if (found != this->_nil && !this->_comp(k, found->value))
					return (++(iterator(found)));
				else if (found != this->_nil)
					return (iterator(found));
				return (this->_end);

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
                node<value_type> *element = this->_root;
                node<value_type> *position = this->_nil;
                node<value_type> *new_node = this->_node_alloc.allocate(1);
                this->_node_alloc.construct(new_node, node<value_type>(this->_nil, this->_nil, this->_nil, RED, 0, 0));
				this->_alloc.construct(new_node->value, val);
				// ?checking pos..................
					iterator after = ++pos;
					--pos;
					iterator before = --pos;
					++pos;
					if (this->_comp(*pos, *after) && !(this->_comp(*pos, *before)) && ((pos.base())->left->is_nil || (pos.base())->right->is_nil))
						element = pos.base();
				// ? ..........................................................
                while (element != this->_nil) // find where to insert
                {
                    position = element;
                    if (new_node->value == element->value)
                    {
                        this->_node_alloc.destroy(new_node);
                        this->_node_alloc.deallocate(new_node, 1);
						std::cout << "already there" << std::endl;
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
                    this->_root->parent = this->_nil;
                    this->_begin = new_node;
                    this->_end->parent = new_node;
                    this->_root->color = BLACK;
                }
                else if (this->_comp(*new_node->value, *position->value)) // now we just modify the parent
                    position->left = new_node;
                else
                    position->right = new_node;
                if (this->_comp(*new_node->value, *this->_begin->value))
                    this->_begin = new_node;
                if (!this->_comp(*new_node->value, *this->_end->parent->value))
                    this->_end->parent = new_node;
                check_insertion(new_node);
				this->_size++;
				return (pair<iterator,bool> (iterator(new_node), 1));
			};

			// .search......................................................................................
			node<value_type> *find (const key_type& k)
			{
				node<value_type> 	*found = this->_nil;
				node<value_type>	*temp = this->_root;

				while (temp->is_nil == 0)
				{
					if (!this->_comp(temp->value, k)) // ? if it the value is lower
					{
						found = temp;
						temp = temp->left;
					}
					else							// ? if the value is greater
						temp = temp->right;
				}
				if (found != this->_nil && !this->_comp(k, found->value))
					return (found);
				return (this->_end);
			};


			// . deletion...................................................

			// clear
			void clear()
			{
				for (iterator it = begin(); it != this->end(); it++)
					this->delete_node(it.base());
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
							sibling->color = BLACK;		// ? swapping colors of sibling
							child->parent->color = RED; // ? and parent
							this->left_rotate(child->parent, sibling); // ? rotate to the direction of DB
							sibling = child->parent->right; // ? which is the old child parent
						}
						if (sibling->left->color == BLACK && sibling->right->color == BLACK) // case 3 
						{
							sibling->color = RED; // ? make the sibling RED (angry)
							child = child->parent;
						} // ? if the parent is red exit the loop and <<<make it black>>>. if not reloop because the child now is DB
						else // ? one of the children is red
						{
							if (sibling->right->color == BLACK) // case 5 // ? which will be always followed by case 6
							{
								sibling->left->color = BLACK; // ? come down the angry child
								sibling->color = RED; // ? make the parent angry
								this->right_rotate(sibling, sibling->left); // ? rotate in opposite direction of DB
								sibling = child->parent->right; // ? there is a new sibling because we rotated 
							}
							sibling->color = child->parent->color; // ? give parent color to sibling
							child ->parent->color = BLACK; // ? make parent black  
							//!      child ->parent->color = BLACK;  needs to be checked(Black or its child's color ?)
							sibling->right->color = BLACK; // ? give the extra black to the angry child
							this->left_rotate(child->parent, sibling);
							child = this->_root; // ? to exit the loop
						}
					}
					else // ? if its a right child
					{
						sibling = child->parent->right;
						if (sibling->color == RED) // case 4, //? which will always be followed by other cases
						{
							sibling->color = BLACK;		// ? swapping colors of sibling
							child->parent->color = RED; // ? and parent
							this->right_rotate(child->parent, sibling); // ? rotate to the direction of DB
							sibling = child->parent->left; // ? which is the old child parent
						}
						if (sibling->right->color == BLACK && sibling->left->color == BLACK) // case 3 
						{
							sibling->color = RED; // ? make the sibling RED (angry)
							child = child->parent;
						} // ? if the parent is red exit the loop and <<<make it black>>>. if not reloop because the child now is DB
						else // ? one of the children is red
						{
							if (sibling->left->color == BLACK) // case 5 // ? which will be always followed by case 6
							{
								sibling->right->color = BLACK; // ? come down the angry child
								sibling->color = RED; // ? make the parent angry
								this->left_rotate(sibling, sibling->left); // ? rotate in opposite direction of DB
								sibling = child->parent->left; // ? there is a new sibling because we rotated 
							}
							sibling->color = child->parent->color; // ? give parent color to sibling
							child->parent->color = BLACK; // ? make parent black  
							//!      child ->parent->color = BLACK;  needs to be checked(Black or its child's color ?)
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
				if (x == this->_end)
					return (0);
				node<value_type>	*temp1 = x;
				int x_original_color = x->color;
				node<value_type>	*temp2;
				if (x->left->is_nil) // if x has at most one child replace it with that child
				{
					if (x == this->_begin)
						this->_begin = (++(this->begin())).base();
					if (x == this->_end->parent)
						this->_end =(--(--(this->end()))).base();
					temp2 = x->right;
					this->node_exchange(x, x->right);
				}
				else if (x->right->is_nil)
				{
					if (x == this->_end->parent)
						this->_end =(--(--(this->end()))).base();
					temp2 = x->left;
					this->node_exchange(x, x->left);
				}
				else // ? it has two children
				{
					temp1 = this->tree_min(x->right);
					x_original_color = x->color;
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
				// remove(x)
				if (x_original_color == BLACK) //? case 1: if the deleted node is red just exit
					fix_deletion(temp2);
				this->_size--;
				return(1);
			};

			// void erase(iterator position)
			// {
			// 	if (*position == this->find(*position))
			// }
			//..................................................................................


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