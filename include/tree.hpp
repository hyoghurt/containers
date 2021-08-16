#ifndef TREE_HPP
# define TREE_HPP

# define	RED 1
# define	BLACK 0
# define	CL "\033[1;44;1m"
# define	NC "\033[0m"

# include "ft.hpp"
# include <iostream>

/*
template < typename _TreeItrator >
struct	map_iterator
{
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef std::bidirectional_iterator_tag	iterator_category;

	map_iterator ()											{ return; };
	~map_iterator ()										{ return; };
	map_iterator (node p) : p(p.date)						{ return; };
	map_iterator (map_iterator const& oth)					{ *this = oth; };

	map_iterator&	operator= (map_iterator const& oth)			{ this->p = oth.p; return (*this); };
	bool			operator==(map_iterator const& oth) const	{ return (p == oth.p); };
	bool			operator!=(map_iterator const& oth) const	{ return (p != oth.p); };
	reference		operator* () const							{ return *(p->date); };
	pointer			operator->() const							{ return (p->date); };
	map_iterator&	operator++()
	{
	}

	protected:
		pointer	p;
};
*/


/*
template <class _Tp, class _NodePtr, class _DiffType>
class __tree_iterator
{
private:
    typedef __tree_node_types<_NodePtr>                     _NodeTypes;
    typedef _NodePtr                                        __node_pointer;
    typedef typename _NodeTypes::__node_base_pointer        __node_base_pointer;
    typedef typename _NodeTypes::__end_node_pointer         __end_node_pointer;
    typedef typename _NodeTypes::__iter_pointer             __iter_pointer;
    typedef pointer_traits<__node_pointer> __pointer_traits;

    __iter_pointer __ptr_;

public:
    typedef bidirectional_iterator_tag                     iterator_category;
    typedef _Tp                                            value_type;
    typedef _DiffType                                      difference_type;
    typedef value_type&                                    reference;
    typedef typename _NodeTypes::__node_value_type_pointer pointer;

	__tree_iterator()			{}

    reference			operator*() const		{return __get_np()->__value_;}
    pointer				operator->() const		{return pointer_traits<pointer>::pointer_to(__get_np()->__value_);}
    __tree_iterator&	operator++()
	{
      __ptr_ = static_cast<__iter_pointer>(
          __tree_next_iter<__end_node_pointer>(static_cast<__node_base_pointer>(__ptr_)));
      return *this;
    }
    __tree_iterator		operator++(int)	{__tree_iterator __t(*this); ++(*this); return __t;}
    __tree_iterator&	operator--()
	{
      __ptr_ = static_cast<__iter_pointer>(__tree_prev_iter<__node_base_pointer>(
          static_cast<__end_node_pointer>(__ptr_)));
      return *this;
    }
    __tree_iterator		operator--(int)	{__tree_iterator __t(*this); --(*this); return __t;}
    bool				operator==(const __tree_iterator& __x, const __tree_iterator& __y)
        {return __x.__ptr_ == __y.__ptr_;}
    bool				operator!=(const __tree_iterator& __x, const __tree_iterator& __y)
        {return !(__x == __y);}

private:
    __tree_iterator(__node_pointer __p) : __ptr_(__p) {}
    __tree_iterator(__end_node_pointer __p) : __ptr_(__p) {}
    __node_pointer __get_np() const { return static_cast<__node_pointer>(__ptr_); }
    template <class, class, class> friend class __tree;
    template <class, class, class> friend class __tree_const_iterator;
    template <class> friend class __map_iterator;
    template <class, class, class, class> friend class map;
};

template <class _EndNodePtr, class _NodePtr>
__tree_next_iter(_NodePtr __x)
{
    if (__x->__right_ != nullptr)
        return static_cast<_EndNodePtr>(__tree_min(__x->__right_));
    while (!__tree_is_left_child(__x))
        __x = __x->__parent_unsafe();
    return static_cast<_EndNodePtr>(__x->__parent_);
}
*/

template < typename T >
class	tree;

template < typename Pr, typename Node >
struct	tree_iterator;

template < typename __T >
class	node
{
	public:
		typedef __T				date_type;
		typedef	node<__T>*		pointer;

	private:
		date_type		date;
		pointer			parent;
		pointer			left;
		pointer			right;
		bool			color;
		pointer			_null_node;

	public:

		template < typename Pr, typename Node >
		friend struct	tree_iterator;
		template < typename T >
		friend class tree;

		node() : date(), parent(this), left(this), right(this), color(BLACK), _null_node(this)
		{ /*std::cout << date.first << ": node construct default" << std::endl;*/ };

		node(const date_type& date, pointer parent, pointer left, pointer right, bool color, pointer _null_node) : date(date),
			parent(parent), left(left), right(right), color(color), _null_node(_null_node)
		{ /*std::cout << date.first << ": node construct full" << std::endl;*/ };

		node(const date_type& date, pointer parent) : date(date), parent(parent)
		{ /*std::cout << date.first << ": node construct node" << std::endl;*/ };

		template < typename U >
		node(const node<U>& oth)	{ *this = oth; }

		~node()
		{ /*std::cout << date.first << ": destructor node" << std::endl;*/ };

		template < typename U >
		node&		operator= (const node<U>& oth)
		{
			if (this != &oth)
			{
				date = oth.date;
				parent = oth.parent;
				left = oth.left;
				right = oth.right;
				color = oth.color;
				_null_node = oth._null_node;
			}
			return *this;
		}
};

template < typename Pr, typename Node >
struct	tree_iterator
{
	template < typename T >
	friend class	tree;

    typedef std::bidirectional_iterator_tag	iterator_category;
    typedef Pr								value_type;
	typedef std::ptrdiff_t					difference_type;
    typedef value_type&						reference;
    typedef value_type*						pointer;

	typedef Node							value_node;
	typedef Node*							pointer_node;
	typedef Node&							reference_node;

	tree_iterator ()											{ return; };
	~tree_iterator ()											{ return; };

	tree_iterator (pointer_node p) : p(p)						{ return; };

	tree_iterator (tree_iterator const& oth)					{ *this = oth; };

	tree_iterator&	operator= (tree_iterator const& oth)		{ this->p = oth.p; return (*this); };
	bool			operator==(tree_iterator const& oth) const	{ return (p == oth.p); };
	bool			operator!=(tree_iterator const& oth) const	{ return (p != oth.p); };
	reference		operator* () const							{ return p->date; };
	pointer			operator->() const							{ return &(p->date); };
	tree_iterator&	operator++()
	{
		if (p->right != p->_null_node)
		{
			p = p->right;
			while (p->left != p->_null_node)
				p = p->left;
		}
		else
		{
			while (p != p->parent->left)
				p = p->parent;
			p = p->parent;
		}
		return (*this);
	}

	pointer_node	p;

};


//template < typename _T, typename Allocator = std::allocator<_T> >
template < typename T >
class	tree
{
	public:

		template < typename Pr, typename Node >
		friend  struct	tree_iterator;

		typedef typename T::first_type						key_type;
		typedef typename T::second_type						mapped_type;
		typedef std::allocator< node<T> >					allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef T											date_type;
		typedef tree_iterator< T, node<T> >					tree_iterator;

//CONSTRUCTOR________________________________________________________________________________
		tree() : _null_node(), root(&_null_node), _size_tree(0)
		{ /*std::cout << "construct tree" << std::endl;*/ };
//DISTRUCTOR________________________________________________________________________________
		~tree()
		{ /*std::cout << "destructor tree" << std::endl;*/ destroy_node(root); };
//MAX_SIZE________________________________________________________________________________
		size_t			max_size() const						{ return alloc.max_size(); };
//IS_NULL_NODE________________________________________________________________________________
		bool			is_null_node(pointer x)
		{
			if (x == x->_null_node)
				return true;
			return false;
		}
//BEGIN________________________________________________________________________________
		tree_iterator	begin()
		{
			if (is_null_node(root))
				return (root);

			pointer	current = root;

			while (current->left != current->_null_node)
				current = current->left;
			return (tree_iterator(current));
		}
//END________________________________________________________________________________
		tree_iterator	end()									{ return (tree_iterator(&_null_node)); }
//SIZE________________________________________________________________________________
		size_t			size() const							{ return this->_size_tree; }
//EMPTY________________________________________________________________________________
		bool			empty() const							{ return root == &_null_node; }
//DESTROY_NODE________________________________________________________________________________
		void	destroy_node(pointer x)
		{
			if (!is_null_node(x))
			{
				destroy_node(x->left);
				destroy_node(x->right);
				alloc.destroy(x);
				alloc.deallocate(x, 1);
			}
		}
//INSERT_NODE________________________________________________________________________________
		ft::pair<tree_iterator, bool>	insert_node(const T& date)
		{
			pointer	current;
			pointer	parent;
			pointer	x;

			current = root;
			parent = &_null_node;
			while (!is_null_node(current))
			{
				if (date.first == current->date.first)
					return (ft::pair<tree_iterator, bool>( tree_iterator(current), false));
				parent = current;
				if (date.first < parent->date.first)
					current = parent->left;
				else
					current = parent->right;
			}

			x = alloc.allocate(1);
			alloc.construct(x, date, parent);
			x->left = &_null_node;
			x->right = &_null_node;
			x->color = RED;
			x->_null_node = &_null_node;

			if (!is_null_node(parent))
			{
				if (date.first < parent->date.first)
					parent->left = x;
				else
					parent->right = x;
			}
			else
				root = x;
			insert_case_1(x);
			++_size_tree;


			return (ft::pair<tree_iterator, bool>( tree_iterator(x), true));
		}
//INSERT_ITERATOR________________________________________________________________________________
		tree_iterator			insert_node(tree_iterator position, const T& date)
		{

			pointer	parent;
			pointer	x;
			pointer	current;

			current = position.p;
			parent = &_null_node;
			while (!is_null_node(current))
			{
				if (date.first == current->date.first)
					return ( tree_iterator(current) );
				parent = current;
				if (date.first < parent->date.first)
					current = parent->left;
				else
					current = parent->right;
			}

			x = alloc.allocate(1);
			alloc.construct(x, date, parent);
			x->left = &_null_node;
			x->right = &_null_node;
			x->color = RED;
			x->_null_node = &_null_node;

			if (!is_null_node(parent))
			{
				if (date.first < parent->date.first)
					parent->left = x;
				else
					parent->right = x;
			}
			else
				root = x;
			insert_case_1(x);
			++_size_tree;

			return ( tree_iterator(x) );
		}
//INSERT_CASE________________________________________________________________________________
		void	insert_case_1(pointer x)
		{
			if (is_null_node(x->parent))
				x->color = BLACK;
			else
				insert_case_2(x);
		};
//INSERT_CASE________________________________________________________________________________
		void	insert_case_2(pointer x)
		{
			if (x->parent->color == BLACK)
				return;
			else
				insert_case_3(x);
		};
//INSERT_CASE________________________________________________________________________________
		void	insert_case_3(pointer x)
		{
			pointer	u = unlce(x);
			pointer	g;

			if (!is_null_node(u) && (u->color == RED))
			{
				x->parent->color = BLACK;
				u->color = BLACK;
				g = grandparent(x);
				g->color = RED;
				insert_case_1(g);
			}
			else
				insert_case_4(x);
		};
//INSERT_CASE________________________________________________________________________________
		void	insert_case_4(pointer x)
		{
			pointer	g = grandparent(x);

			if ((x == x->parent->right) && (x->parent == g->left))
			{
				rotate_left(x->parent);
				x = x->left;
			}
			else if ((x == x->parent->left) && (x->parent == g->right))
			{
				rotate_right(x->parent);
				x = x->right;
			}
			insert_case_5(x);
		};
//INSERT_CASE________________________________________________________________________________
		void	insert_case_5(pointer x)
		{
			pointer	g = grandparent(x);

			x->parent->color = BLACK;
			g->color = RED;
			if ((x == x->parent->left) && (x->parent == g->left))
				rotate_right(g);
			else
				rotate_left(g);
		};
//GRANDPARENT________________________________________________________________________________
		pointer	grandparent(pointer x)
		{
			if (!is_null_node(x) && !is_null_node(x->parent))
				return x->parent->parent;
			else
				return (&_null_node);
		};
//UNLCE_______________________________________________________________________________________
		pointer	unlce(pointer x)
		{
			pointer	g = grandparent(x);
			if (is_null_node(g))
				return (&_null_node);
			if (x->parent == g->left)
				return (g->right);
			else
				return (g->left);
		};
//ROTATE_LEFT_______________________________________________________________________________________
		void	rotate_left(pointer x)
		{
			pointer	pivot = x->right;

			pivot->parent = x->parent;
			if (is_null_node(pivot->parent))
				root = pivot;
			if (!is_null_node(x->parent))
			{
				if (x->parent->left == x)
					x->parent->left = pivot;
				else
					x->parent->right = pivot;
			}
			x->right = pivot->left;
			if (!is_null_node(pivot->left))
				pivot->left->parent = x;
			x->parent = pivot;
			pivot->left = x;
		};
//ROTATE_RIGHT_______________________________________________________________________________________
		void	rotate_right(pointer x)
		{
			pointer	pivot = x->left;

			pivot->parent = x->parent;
			if (is_null_node(pivot->parent))
				root = pivot;
			if (!is_null_node(x->parent))
			{
				if (x->parent->left == x)
					x->parent->left = pivot;
				else
					x->parent->right = pivot;
			}
			x->left = pivot->right;
			if (!is_null_node(pivot->right))
				pivot->right->parent = x;
			x->parent = pivot;
			pivot->right = x;
		};
//FIND______________________________________________________________________________________
		tree_iterator			find(const key_type& key)
			{ return ( tree_iterator( find_node_key(key) ) ); }
//ERASE_______________________________________________________________________________________________________________________
		void					erase (tree_iterator position)
		{
			delete_node_tmp(position.p);
		}
//DELETE_NODE_TMP
		void	delete_node_tmp(pointer z)
		{
			pointer	x, y;

			if (!z || is_null_node(z))
				return;

			if (!is_null_node(z->left) && !is_null_node(z->right))
			{
				y = z->left;
				while (!is_null_node(y->right))
					y = y->right;
			}
			else if (is_null_node(z->left))
				y = z->right;
			else
				y = z->left;

			/*
			if (is_null_node(z->left) || is_null_node(z->right))
				y = z;
			else
			{
    		    y = z->right;
    		    while (!is_null_node(y->left))
					y = y->left;
    		}
			*/

    		if (!is_null_node(y->left))
    		    x = y->left;
    		else
    		    x = y->right;

			if (!is_null_node(x))
				x->parent = y->parent;

    		if (!is_null_node(y->parent))
			{
    		    if (y == y->parent->left)
    		        y->parent->left = x;
    		    else
    		        y->parent->right = x;
			}
    		else
    		    root = x;

    		if (y != z)
			{
				y->parent = z->parent;
				y->left = z->left;
				y->right = z->right;

				if (is_null_node(z->parent))
					root = y;
				//z->date = ft::make_pair(y->date.first, y->date.second);
			}
			//show_debag();

    		if (y->color == BLACK)
    		    deleteFixup (x);

			/*
			--_size_tree;
			alloc.destroy(z);
			alloc.deallocate(z, 1);
			*/
		}

		void deleteFixup(pointer x)
		{
		    while (x != root && x->color == BLACK)
			{
		        if (x == x->parent->left)
				{
		            pointer w = x->parent->right;
		            if (w->color == RED)
					{
		                w->color = BLACK;
		                x->parent->color = RED;
		                rotate_left(x->parent);
		                w = x->parent->right;
		            }
		            if (w->left->color == BLACK && w->right->color == BLACK)
					{
		                w->color = RED;
		                x = x->parent;
		            }
					else
					{
		                if (w->right->color == BLACK)
						{
		                    w->left->color = BLACK;
		                    w->color = RED;
		                    rotate_right(w);
		                    w = x->parent->right;
		                }
		                w->color = x->parent->color;
		                x->parent->color = BLACK;
		                w->right->color = BLACK;
		                rotate_left(x->parent);
		                x = root;
		            }
		        }
				else
				{
		            pointer w = x->parent->left;
		            if (w->color == RED)
					{
		                w->color = BLACK;
		                x->parent->color = RED;
		                rotate_right(x->parent);
		                w = x->parent->left;
		            }
		            if (w->right->color == BLACK && w->left->color == BLACK)
					{
		                w->color = RED;
		                x = x->parent;
		            }
					else
					{
		                if (w->left->color == BLACK)
						{
		                    w->right->color = BLACK;
		                    w->color = RED;
		                    rotate_left(w);
		                    w = x->parent->left;
		                }
		                w->color = x->parent->color;
		                x->parent->color = BLACK;
		                w->left->color = BLACK;
		                rotate_right(x->parent);
		                x = root;
		            }
		        }
		    }
		    x->color = BLACK;
		}
//DELETE_NODE________________________________________________________________________________
		size_t	delete_node(const key_type& key)
		{
			pointer	del = find_node_key(key);
			if (!is_null_node(del))
			{
				delete_one_child(del);
				return (1);
			}
			return (0);
			//show_debag();
		}
//SUBLING________________________________________________________________________________
		pointer	sibling(pointer x)
		{
			if (x == x->parent->left)
				return (x->parent->right);
			else
				return (x->parent->left);
		};
//REPLACE_NODE________________________________________________________________________________
		void	replace_node(pointer x, pointer child)
		{
			if (!is_null_node(child))
				child->parent = x->parent;
			if (!is_null_node(x->parent))
			{
				if (x == x->parent->left)
					x->parent->left = child;
				else
					x->parent->right = child;
			}
			else
				root = x;
		};
//DELETE_________________________________________________________________________________
		void	delete_one_child(pointer x)
		{
			pointer	child;

			//find child to na chto menat
			//
			if (!is_null_node(x->left) && !is_null_node(x->right))
			{
				child = x->left;
				while (!is_null_node(child->right))
					child = child->right;
			}
			else if (is_null_node(x->left))
				child = x->right;
			else
				child = x->left;

			//std::cout << "child = " << child->date.first << std::endl;

			/*
			if (child == nullptr)
			{
				std::cout << "child == nullptr" << std::endl;
				return;
			}
			*/
			//case for child == root

			replace_node(x, child);

			if (x->color == BLACK)
			{
				if (child->color == RED)
					child->color = BLACK;
				else
					delete_case_1(child);
			}

			--_size_tree;
			alloc.destroy(x);
			alloc.deallocate(x, 1);
		};
//DELETE_CASE________________________________________________________________________________
		void	delete_case_1(pointer x)
		{
			//std::cout << "______________del_1" << std::endl;
			if (!is_null_node(x->parent))
				delete_case_2(x);
		};
//DELETE_CASE________________________________________________________________________________
		void	delete_case_2(pointer x)
		{
			//std::cout << "______________del_2" << std::endl;
			pointer	s = sibling(x);

			if (s->color == RED)
			{
				x->parent->color = RED;
				s->color = BLACK;
				if (x == x->parent->left)
					rotate_left(x->parent);
				else
					rotate_right(x->parent);
			}
			delete_case_3(x);
		};
//DELETE_CASE________________________________________________________________________________
		void	delete_case_3(pointer x)
		{
			pointer	s = sibling(x);

			if ((x->parent->color == BLACK) &&
				(s->color == BLACK) &&
				(s->left->color == BLACK) &&
				(s->right->color == BLACK))
			{
				s->color = RED;
				delete_case_1(x->parent);
			}
			else
				delete_case_4(x);
		};
//DELETE_CASE________________________________________________________________________________
		void	delete_case_4(pointer x)
		{
			pointer	s = sibling(x);

			if ((x->parent->color == RED) &&
				(s->color == BLACK) &&
				(s->left->color == BLACK) &&
				(s->right->color == BLACK))
			{
				s->color = RED;
				x->parent->color = BLACK;
			}
			else
				delete_case_5(x);
		};
//DELETE_CASE________________________________________________________________________________
		void	delete_case_5(pointer x)
		{
			pointer	s = sibling(x);

			if (s->color == BLACK)
			{
				if ((x == x->parent->left) &&
					(s->right->color == BLACK) &&
					(s->left->color == RED))
				{
					s->color = RED;
					s->left->color = BLACK;
					rotate_right(s);
				}
				else if ((x == x->parent->right) &&
						(s->left->color == BLACK) &&
						(s->right->color == RED))
				{
					s->color = RED;
					s->right->color = BLACK;
					rotate_left(s);
				}
			}
			delete_case_6(x);
		};
//DELETE_CASE________________________________________________________________________________
		void	delete_case_6(pointer x)
		{
			pointer	s = sibling(x);

			s->color = x->parent->color;
			x->parent->color = BLACK;

			if (x == x->parent->left)
			{
				s->right->color = BLACK;
				rotate_left(x->parent);
			}
			else
			{
				s->left->color = BLACK;
				rotate_right(x->parent);
			}
		};
//FIND_NODE________________________________________________________________________________
		pointer	find_node_key(typename T::first_type key)
		{
			pointer	current = root;

			while (!is_null_node(current))
			{
				if (current->date.first == key)
					return (current);
				if (key < current->date.first)
					current = current->left;
				else
					current = current->right;
			}
			return (current);
		};
//FIND_NODE________________________________________________________________________________
		pointer	find_node(T date)
		{
			pointer	current = root;

			while (!is_null_node(current))
			{
				if (current->date.first == date.first)
					return (current);
				if (date.first < current->date.first)
					current = current->left;
				else
					current = current->right;
			}
			return (current);
		};
//DEBAG________________________________________________________________________________
		void	show_debag()
		{
			pointer	x = root;

			if (!is_null_node(x))
			{
				std::cout << CL << "___ROOT_" << x << NC << std::endl;
				if (x->color)
					std::cout << "color = RED" << std::endl;
				else
					std::cout << "color = BLACK" << std::endl;
				std::cout << "date.key = " << x->date.first << std::endl;
			}
			print_debag(x);
		};
//DEBAG________________________________________________________________________________
		void	print_debag(pointer x)
		{
			if (!is_null_node(x->left))
			{
				std::cout << CL << "___LEFT_" << x << NC << std::endl;
				if (x->left->color)
					std::cout << "color = RED" << std::endl;
				else
					std::cout << "color = BLACK" << std::endl;
				std::cout << "date.key = " << x->left->date.first << std::endl;
				if (!is_null_node(x->left))
					print_debag(x->left);
			}
			if (!is_null_node(x->right))
			{
				std::cout << CL << "___RGHT_" << x << NC << std::endl;
				if (x->right->color)
					std::cout << "color = RED" << std::endl;
				else
					std::cout << "color = BLACK" << std::endl;
				std::cout << "date.key = " << x->right->date.first << std::endl;
				if (!is_null_node(x->right))
					print_debag(x->right);
			}
		};
//DEBAG________________________________________________________________________________

//HEDER_STD
//TREE_NEXT________________________________________________________________________________
		pointer		tree_next(pointer x)
		{
			if (!is_null_node(x->right))
				return tree_min(x->right);
			while (!tree_is_left_child(x))
				x = x->parent;
			return x->parent;
		};
		
		pointer		tree_min(pointer x)
		{
			while (!is_null_node(x->left))
				x = x->left;
			return x;
		};
		
		pointer		tree_max(pointer x)
		{
			while (!is_null_node(x->right))
		        x = x->right;
		    return x;
		};
		
		bool		tree_is_left_child(pointer x)
		{
		    return x == x->parent->left;
		};

// Returns:  pointer to a node which has no children
// Precondition:  __x != nullptr.
		pointer		tree_leaf(pointer x)
		{
		    while (true)
		    {
				if(!is_null_node(x->left))
		        {
		            x = x->left;
		            continue;
		        }
				if(!is_null_node(x->right))
		        {
		            x = x->right;
		            continue;
		        }
		        break;
		    }
		    return x;
		};



	protected:
		node<T>			_null_node;
		pointer			root;
		size_t			_size_tree;
		allocator_type	alloc;
};

#endif
