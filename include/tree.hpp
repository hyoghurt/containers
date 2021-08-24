#ifndef TREE_HPP
# define TREE_HPP

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

# define	RED 1
# define	BLACK 0

template <class T, class Compare, class Allocator>
class	tree;

template < typename Pr, typename Node >
struct	tree_iterator;

template < typename __T, class node_allocator = std::allocator< __T > >
class	node
{
	public:
		typedef __T					value_type;
		typedef value_type*			pointer_date;
		typedef	node<value_type>*	pointer;
		typedef node_allocator		allocator_type;

	private:
		pointer_date	date;
		pointer			parent;
		pointer			left;
		pointer			right;
		int				color;
		pointer			null_node;
		pointer			*begin_node;
		allocator_type	_alloc;

	public:
		template < typename Pr, typename Node >
		friend struct	tree_iterator;
		template <class T, class Compare, class Allocator>
		friend class tree;

		node ()
		{
			this->date = _alloc.allocate(1);
			_alloc.construct(this->date, value_type());
			parent = nullptr;
			left = nullptr;
			right = nullptr;
			color = BLACK;
			null_node = nullptr;
			begin_node = nullptr;
			/*std::cout << date.first << ": node construct default" << std::endl;*/
		}

		node (const value_type& date)
		{
			this->date = _alloc.allocate(1);
			_alloc.construct(this->date, date);
			/*std::cout << date.first << ": node construct node" << std::endl;*/
		}

		template < typename U >
		node (const node<U>& oth)	{ *this = oth; }

		~node()
		{
			_alloc.destroy(date);
			_alloc.deallocate(date, 1);
			/*std::cout << date.first << ": destructor node" << std::endl;*/
		}

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
				null_node = oth.null_node;
				begin_node = oth.begin_node;
			}
			return *this;
		}
};

template < typename Pr, typename Node >
class	tree_iterator
{
private:
	template <class T, class Compare, class Allocator>
	friend class	tree;

public:
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
	reference		operator* () const							{ return *(p->date); };
	pointer			operator->() const							{ return p->date; };
	tree_iterator&	operator++()
	{
		if (p->right != p->null_node)
		{
			p = p->right;
			while (p->left != p->null_node)
				p = p->left;
		}
		else
		{
			while (p != p->parent->left)
			{
				p = p->parent;
				if (p == p->null_node)
					return (*this);
			}
			p = p->parent;
		}
		return (*this);
	}
	tree_iterator	operator++(int)						{ tree_iterator tmp(*this); ++(*this); return (tmp); }
	tree_iterator&	operator--()
	{
		if (p == p->null_node)
		{
			p = *p->begin_node;
			while (p->right != p->null_node)
		        p = p->right;
			return (*this);
		}
		if (p->left != p->null_node)
		{
			p = p->left;
			while (p->right != p->null_node)
				p = p->right;
		}
		else
		{
			while (p == p->parent->left)
			{
				p = p->parent;
				if (p == p->null_node)
					return (*this);
			}
			p = p->parent;
		}
		return (*this);
	}
	tree_iterator	operator--(int)						{ tree_iterator tmp(*this); --(*this); return (tmp); }

private:
	pointer_node	p;

};

template <class T, class Compare = std::less<typename T::first_type>, class Allocator = std::allocator< node<T> > >
class	tree
{
	public:
//FRIEND_________________________________________________________________________________
		template < typename Pr, typename Node >
		friend  struct	tree_iterator;
//TYPEDEF________________________________________________________________________________
		typedef typename T::first_type						key_type;
		typedef typename T::second_type						mapped_type;
		typedef Compare										key_compare;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef T											date_type;
		typedef T*											pointer_date_type;
		typedef tree_iterator< T, node<T> >					tree_iterator;
		//typedef tree_const_iterator< T, node<T> >			tree_const_iterator;
//CONSTRUCTOR________________________________________________________________________________
		tree(const key_compare& comp = key_compare()) : comp(comp), _size_tree(0)
		{
			/*std::cout << "construct tree" << std::endl;*/
			null_node = alloc.allocate(1);
			alloc.construct(null_node);
			root = null_node;
			root->null_node = null_node;
			root->begin_node = &root;
		}
//DISTRUCTOR________________________________________________________________________________
		~tree()
		{
			/*std::cout << "destructor tree" << std::endl;*/
			destroy_node(root);
			alloc.destroy(null_node);
			alloc.deallocate(null_node, 1);
		}

		tree(const tree& oth)
		{
			*this = oth;
		}

		tree&	operator= (const tree& oth)
		{
			if (this != &oth)
			{
				destroy_node(root);
				root = null_node;
				_size_tree = 0;
				comp = oth.comp;
				alloc = oth.alloc;
				for (tree_iterator it = oth.begin(); it != oth.end(); ++it)
					insert_node_p(this->root, ft::make_pair<key_type, mapped_type>(it->first, it->second));
			}
			return (*this);
		}
//MAX_SIZE________________________________________________________________________________
		size_t			max_size() const						{ return alloc.max_size(); };
//IS_NULL_NODE________________________________________________________________________________
		bool			is_null_node(pointer x) const
		{
			if (x == null_node)
				return true;
			return false;
		}
//BEGIN________________________________________________________________________________
		tree_iterator	begin()
		{
			if (is_null_node(root))
				return (root);
			return (tree_iterator(tree_min(root)));
		}
		tree_iterator	begin() const
		{
			if (is_null_node(root))
				return (root);
			return (tree_iterator(tree_min(root)));
		}
//END________________________________________________________________________________
		tree_iterator	end()									{ return (tree_iterator(null_node)); }
		tree_iterator	end() const								{ return (tree_iterator(null_node)); }
//SIZE________________________________________________________________________________
		size_t			size() const							{ return this->_size_tree; }
//EMPTY________________________________________________________________________________
		bool			empty() const							{ return root == null_node; }
//DESTROY_NODE________________________________________________________________________________
		void	destroy_node (pointer x)
		{
			if (!is_null_node(x))
			{
				//delete(x->date);
				destroy_node(x->left);
				destroy_node(x->right);
				alloc.destroy(x);
				alloc.deallocate(x, 1);
			}
		}
//INSERT_NODE________________________________________________________________________________
		pointer	insert_node_p (pointer start, date_type date)
		{
			pointer	current;
			pointer	parent;
			pointer	x;

			current = start;
			parent = null_node;

			while (!is_null_node(current))
			{
				if (date.first == current->date->first)
					return current;
				parent = current;
				if (date.first < parent->date->first)
					current = parent->left;
				else
					current = parent->right;
			}

			x = alloc.allocate(1);
			alloc.construct(x, date);
			x->parent = parent;
			x->left = null_node;
			x->right = null_node;
			x->color = RED;
			x->null_node = null_node;
			x->begin_node = &root;
			++_size_tree;

			if (!is_null_node(parent))
			{
				if (date.first < parent->date->first)
					parent->left = x;
				else
					parent->right = x;
			}
			else
				root = x;

			if (is_null_node(x->parent))
			{
				x->color = BLACK;
				return x;
			}

			if (is_null_node(x->parent->parent))
				return x;

			fix_insert(x);

			return x;
		}
//FIX_INSERT________________________________________________________________________________
		void	fix_insert (pointer x)
		{
			pointer u;

			while (x->parent->color == RED)
			{
				if (x->parent == x->parent->parent->right)
				{
					u = x->parent->parent->left;
					if (u->color == RED)
					{
						u->color = BLACK;
						x->parent->color = BLACK;
						x->parent->parent->color = RED;
						x = x->parent->parent;
					}
					else
					{
						if (x == x->parent->left)
						{
							x = x->parent;
							rotate_right(x);
						}
						x->parent->color = BLACK;
						x->parent->parent->color = RED;
						rotate_left(x->parent->parent);
					}
				}
				else
				{
					u = x->parent->parent->right;
					if (u->color == RED)
					{
						u->color = BLACK;
						x->parent->color = BLACK;
						x->parent->parent->color = RED;
						x = x->parent->parent;	
					}
					else
					{
						if (x == x->parent->right)
						{
							x = x->parent;
							rotate_left(x);
						}
						x->parent->color = BLACK;
						x->parent->parent->color = RED;
						rotate_right(x->parent->parent);
					}
				}
				if (x == root)
					break;
			}
			root->color = BLACK;
		}
//DELETE_NODE_P_____________________________________________________________________________
		void	delete_node_p(pointer node)
		{
			pointer x;
			pointer y = node;
			int		y_color = y->color;

			if (is_null_node(node->left))
			{
				x = node->right;
				replace_node(node, node->right);
			}
			else if (is_null_node(node->right))
			{
				x = node->left;
				replace_node(node, node->left);
			}
			else
			{
				y = tree_max(node->left);
				y_color = y->color;
				x = y->left;
				if (y->parent == node)
					x->parent = y;
				else
				{
					replace_node(y, y->left);
					y->left = node->left;
					y->left->parent = y;
				}
				replace_node(node, y);
				y->right = node->right;
				y->right->parent = y;
				y->color = node->color;
			}
			alloc.destroy(node);
			alloc.deallocate(node, 1);
			--_size_tree;
			if (y_color == BLACK)
				fix_delete(x);
		}
//FIX_DELETE________________________________________________________________________________
		void	fix_delete(pointer x)
		{
			pointer	s;

			while (x != root && x->color == BLACK)
			{
				if (x == x->parent->left)
				{
					s = x->parent->right;
					if (s->color == RED)
					{
						s->color = BLACK;
						x->parent->color = RED;
						rotate_left(x->parent);
						s = x->parent->right;
					}
					if (s->left->color == BLACK && s->right->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->right->color == BLACK)
						{
							s->left->color = BLACK;
							s->color = RED;
							rotate_right(s);
							s = x->parent->right;
						} 
						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->right->color = BLACK;
						rotate_left(x->parent);
						x = root;
					}
				}
				else
				{
					s = x->parent->left;
					if (s->color == RED)
					{
						s->color = BLACK;
						x->parent->color = RED;
						rotate_right(x->parent);
						s = x->parent->left;
					}
					if (s->right->color == BLACK && s->right->color == BLACK)
					{
						s->color = RED;
						x = x->parent;
					}
					else
					{
						if (s->left->color == BLACK)
						{
							s->right->color = BLACK;
							s->color = RED;
							rotate_left(s);
							s = x->parent->left;
						} 
						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->left->color = BLACK;
						rotate_right(x->parent);
						x = root;
					}
				} 
			}
			x->color = BLACK;
		}
//REPLACE_NODE______________________________________________________________________________
		void	replace_node(pointer x, pointer y)
		{
			if (is_null_node(x->parent))
				root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->parent = x->parent;
		}
//ROTATE_LEFT________________________________________________________________________________
		void	rotate_left (pointer x)
		{
			pointer	y = x->right;
			x->right = y->left;
			if (!is_null_node(y->left))
				y->left->parent = x;
			y->parent = x->parent;
			if (is_null_node(x->parent))
				root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}
//ROTATE_RIGHT________________________________________________________________________________
		void	rotate_right (pointer x)
		{
			pointer y = x->left;
			x->left = y->right;
			if (!is_null_node(y->right))
				y->right->parent = x;
			y->parent = x->parent;
			if (is_null_node(x->parent))
				root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}
//INSERT________________________________________________________________________________________
		ft::pair<tree_iterator, bool>	insert_node(date_type date)
		{
			pointer	x = find_node_key(date.first);

			if (!is_null_node(x))
				return (ft::pair<tree_iterator, bool>( tree_iterator(x), false));
			x = insert_node_p (this->root, date);
			return (ft::pair<tree_iterator, bool>( tree_iterator(x), true));
		}
//INSERT_ITERATOR________________________________________________________________________________
		tree_iterator					insert_node(tree_iterator position, date_type date)
		{
			pointer	current = position.p;
			pointer x = insert_node_p (this->root, date);
			return ( tree_iterator(x) );
		}
//FIND______________________________________________________________________________________
		tree_iterator			find (const key_type& key)
		{ return ( tree_iterator( find_node_key(key) ) ); }
//ERASE_______________________________________________________________________________________________________________________
		void					erase (tree_iterator position)
		{ delete_node_p(position.p); }
//DELETE_NODE________________________________________________________________________________
		size_t	delete_node(const key_type& key)
		{
			pointer	del = find_node_key(key);

			if (!is_null_node(del))
			{
				delete_node_p(del);
				return (1);
			}
			return (0);
		}
//COUT_____________________________________________________________________________________
		size_t	count(const key_type& key) const
		{ return (!is_null_node(find_node_key(key))); }
//FIND_NODE________________________________________________________________________________
		pointer	find_node_key(const key_type& key) const
		{
			pointer	current = root;

			while (!is_null_node(current))
			{
				if (current->date->first == key)
					return (current);
				if (current->date->first > key)
					current = current->left;
				else
					current = current->right;
			}
			return (current);
		};
//FIND_NODE________________________________________________________________________________
		pointer	find_node (date_type date) const
		{
			pointer	current = root;

			while (!is_null_node(current))
			{
				if (current->date->first == date.first)
					return (current);
				if (current->date->first < date.first)
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
				if (is_null_node(x->left))
					std::cout << "left  = " << "null_" << std::endl;
				else
					std::cout << "left  = " << x->left << std::endl;
				if (is_null_node(x->right))
					std::cout << "right = " << "null_" << std::endl;
				else
					std::cout << "right = " << x->right << std::endl;
				if (x->color)
					std::cout << "color = RED" << std::endl;
				else
					std::cout << "color = BLACK" << std::endl;
				std::cout << "date.key = " << x->date->first << std::endl;
				print_debag(x);
			}
		};
//DEBAG________________________________________________________________________________
		void	print_debag(pointer x)
		{
			if (!is_null_node(x->left))
			{
				std::cout << CL << "___LEFT_" << x->left << NC << std::endl;
				if (is_null_node(x->left->left))
					std::cout << "left  = " << "null_" << std::endl;
				else
					std::cout << "left  = " << x->left->left << std::endl;
				if (is_null_node(x->left->right))
					std::cout << "right = " << "null_" << std::endl;
				else
					std::cout << "right = " << x->left->right << std::endl;
				if (x->left->color)
					std::cout << "color = RED" << std::endl;
				else
					std::cout << "color = BLACK" << std::endl;
				std::cout << "date.key = " << x->left->date->first << std::endl;
				if (!is_null_node(x->left))
					print_debag(x->left);
			}
			if (!is_null_node(x->right))
			{
				std::cout << CL << "___RGHT_" << x->right << NC << std::endl;
				if (is_null_node(x->right->left))
					std::cout << "left  = " << "null_" << std::endl;
				else
					std::cout << "left  = " << x->right->left << std::endl;
				if (is_null_node(x->right->right))
					std::cout << "right = " << "null_" << std::endl;
				else
				std::cout << "right = " << x->right->right << std::endl;
				if (x->right->color)
					std::cout << "color = RED" << std::endl;
				else
					std::cout << "color = BLACK" << std::endl;
				std::cout << "date.key = " << x->right->date->first << std::endl;
				if (!is_null_node(x->right))
					print_debag(x->right);
			}
		};
//TREE_NEXT________________________________________________________________________________
		pointer		tree_next(pointer x)
		{
			if (!is_null_node(x->right))
				return tree_min(x->right);
			while (!tree_is_left_child(x))
				x = x->parent;
			return x->parent;
		}
		
		pointer		tree_min(pointer x)
		{
			while (!is_null_node(x->left))
				x = x->left;
			return x;
		}

		const pointer		tree_min(pointer x) const
		{
			while (!is_null_node(x->left))
				x = x->left;
			return x;
		}
		
		pointer		tree_max(pointer x)
		{
			while (!is_null_node(x->right))
		        x = x->right;
		    return x;
		}
		
		bool		tree_is_left_child(pointer x)
		{
		    return x == x->parent->left;
		}

	protected:
		pointer			null_node;
		pointer			root;
		size_t			_size_tree;
		key_compare		comp;
		allocator_type	alloc;
};

#endif
