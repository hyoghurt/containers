#ifndef TREE_HPP
# define TREE_HPP

# include "ft.hpp"
# include <iostream>

namespace ft
{

# define	CL "\033[1;44;1m"
# define	NC "\033[0m"
# define	RED 1
# define	BLACK 0

template <class T, class Compare, class Allocator>
class	tree;

template <typename Pr>
class	tree_iterator;

template <typename Pr>
class	tree_const_iterator;

template <typename P>
P	next_node_tree(P p)
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
				return (p);
		}
		p = p->parent;
	}
	return (p);
}
template <typename P>
P	prev_node_tree(P p)
{
	if (p == p->null_node)
	{
		p = *p->begin_node;
		while (p->right != p->null_node)
	        p = p->right;
		return (p);
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
				return (p);
		}
		p = p->parent;
	}
	return (p);
}
//NODE________________________________________________________________
template < typename __T, class allocator_date = std::allocator< __T > >
class	node
{
public:
	typedef __T					value_type;
	typedef value_type*			pointer_date;
	typedef	node<value_type>*	pointer;
	typedef allocator_date		allocator_type;

	node ();
	node (const value_type& date);
	template <typename U, typename Al>
	node (const node<U,Al>& oth);
	~node();
	template <typename U, typename Al>
	node&		operator= (const node<U,Al>& oth);

private:
	pointer_date	date;
	pointer			parent;
	pointer			left;
	pointer			right;
	int				color;
	pointer			null_node;
	pointer			*begin_node;
	allocator_type	_alloc;

	template <typename Pr>
	friend struct	tree_iterator;
	template <typename U>
	friend struct	tree_const_iterator;
	template <class T, class Compare, class Allocator>
	friend class tree;
	template <typename P>
	friend P	next_node_tree(P p);
	template <typename P>
	friend P	prev_node_tree(P p);
};
//NODE_DEFAULT_______________________________________________________
template <typename __T, class allocator_date>
node<__T,allocator_date>::node ()
{
	date = _alloc.allocate(1);
	_alloc.construct(date, value_type());
	parent = nullptr;
	left = nullptr;
	right = nullptr;
	color = BLACK;
	null_node = nullptr;
	begin_node = nullptr;
}
//NODE_CONSTRUCT DATE_________________________________________________
template <typename __T, class allocator_date>
node<__T,allocator_date>::node (const value_type& date)
{
	this->date = _alloc.allocate(1);
	_alloc.construct(this->date, date);
}
//NODE_COPY____________________________________________________________
template <typename __T, class allocator_date>
template <typename U, typename Al >
node<__T,allocator_date>::node (const node<U,Al>& oth)
{ *this = oth; }
//NODE_DESTRUCTOR______________________________________________________
template <typename __T, class allocator_date>
node<__T,allocator_date>::~node()
{
	_alloc.destroy(date);
	_alloc.deallocate(date, 1);
}
//NODE_OPERATOR=______________________________________________________
template <typename __T, class allocator_date>
template <typename U, typename Al >
node<__T,allocator_date>&
node<__T,allocator_date>::operator= (const node<U,Al>& oth)
{
	if (this != &oth)
	{
		if (date != nullptr)
		{
			_alloc.destroy(date);
			_alloc.deallocate(date, 1);
		}
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
//TREE_ITERATOR______________________________________________________
template < typename Pr >
class	tree_iterator
{
public:
    typedef std::bidirectional_iterator_tag	iterator_category;
    typedef Pr								value_type;
	typedef std::ptrdiff_t					difference_type;
    typedef value_type&						reference;
    typedef value_type*						pointer;
	typedef node<Pr>						value_node;
	typedef node<Pr>*						pointer_node;
	typedef node<Pr>&						reference_node;

	tree_iterator ()											{ return; };
	~tree_iterator ()											{ return; };
	tree_iterator (pointer_node p) : p(p)						{ return; };
	tree_iterator (tree_iterator const& oth)					{ *this = oth; };

	tree_iterator&	operator= (const tree_iterator& oth)		{ this->p = oth.p; return (*this); };
	const pointer_node&	base() const							{ return p; }
	bool			operator==(const tree_iterator& oth) const	{ return (p == oth.p); };
	bool			operator!=(const tree_iterator& oth) const	{ return (p != oth.p); };
	reference		operator* () const							{ return *(p->date); };
	pointer			operator->() const							{ return p->date; };
	tree_iterator&	operator++()		{ p = next_node_tree<pointer_node>(p); return *this; }
	tree_iterator	operator++(int)		{ tree_iterator tmp(*this); ++(*this); return (tmp); }
	tree_iterator&	operator--()		{ p = prev_node_tree<pointer_node>(p); return *this; }
	tree_iterator	operator--(int)		{ tree_iterator tmp(*this); --(*this); return (tmp); }
	//swap(a, b)

	template <typename U>
	bool			operator==(const tree_iterator<U>& b)			{ return base() == b.base(); }
	template <typename U>
	bool			operator==(const tree_const_iterator<U>& b)		{ return base() == b.base(); }
	template <typename U>
	bool			operator!=(const tree_iterator<U>& b)			{ return !(*this == b); }
	template <typename U>
	bool			operator!=(const tree_const_iterator<U>& b)		{ return !(*this == b); }

private:
	pointer_node	p;

	template <typename U>
	friend class	tree_const_iterator;
	template <class T, class Compare, class Allocator>
	friend class	tree;
};
//TREE_CONST_ITERATOR____________________________________________________
template <typename Pr>
class	tree_const_iterator
{
private:
	template <typename U>
	friend class	tree_iterator;
	template <class T, class Compare, class Allocator>
	friend class	tree;

public:
    typedef std::bidirectional_iterator_tag	iterator_category;
	typedef std::ptrdiff_t					difference_type;
    typedef Pr								value_type;
    typedef const value_type&				reference;
    typedef const value_type*				pointer;
	typedef node<Pr>						value_node;
	typedef const node<Pr>*					pointer_node;
	typedef const node<Pr>&					reference_node;
	typedef	tree_iterator<Pr>				tree_iterator;

	tree_const_iterator () : p()														{}
	~tree_const_iterator ()																{}
	tree_const_iterator (const pointer_node p) : p(p)									{}
	tree_const_iterator (const tree_iterator& p) : p(p.p)								{}
	tree_const_iterator (const tree_const_iterator& oth) : p(oth.base())				{}
	tree_const_iterator&	operator= (const tree_const_iterator& oth)	{ this->p = oth.base(); return (*this); }
	tree_const_iterator&	operator= (const tree_iterator& oth)		{ this->p = oth.base(); return (*this); }
	const pointer_node&		base() const								{ return p; }

	reference		operator* () const							{ return *(p->date); }
	pointer			operator->() const							{ return p->date; }
	tree_const_iterator&	operator++()		{ p = next_node_tree<pointer_node>(p); return *this; }
	tree_const_iterator		operator++(int)		{ tree_const_iterator tmp(*this); ++(*this); return (tmp); }
	tree_const_iterator&	operator--()		{ p = prev_node_tree<pointer_node>(p); return *this; }
	tree_const_iterator		operator--(int)		{ tree_const_iterator tmp(*this); --(*this); return (tmp); }

	bool	operator== (const tree_const_iterator& oth)	{ return (base() == oth.base()); }
	bool	operator!= (const tree_const_iterator& oth)	{ return !(*this == oth); }

private:
	pointer_node	p;
};
//TREE__________________________________________________________________________________
template <class T, class Compare = std::less<typename T::first_type>, class Allocator = std::allocator<T> >
class	tree
{
	public:
		typedef typename T::first_type						key_type;
		typedef typename T::second_type						mapped_type;
		typedef Compare										key_compare;
		typedef Allocator									allocator_type_val;
//https://gcc.gnu.org/onlinedocs/gcc-4.6.3/libstdc++/api/a01067_source.html
//string 334 ( rewrite alloc for node using rebind ) 
		typedef typename Allocator::
			template rebind< node<T, Allocator> >::other	allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef T											date_type;
		typedef typename allocator_type_val::pointer		pointer_date_type;
		typedef typename allocator_type_val::const_pointer	const_pointer_date_type;
		typedef tree_iterator<T>							tree_iterator;
		typedef tree_const_iterator<T>						tree_const_iterator;

		tree ();
		tree (const tree& oth);
		~tree ();

		tree&							operator= (const tree& oth);
		size_t							max_size () const;
		tree_iterator					begin ();
		tree_const_iterator				begin () const;
		tree_iterator					end ();
		tree_const_iterator				end () const;
		size_t							size () const;
		bool							empty () const;
		void							destroy_node (pointer x);
		pointer							insert_node_p (pointer start, date_type date);
		void							delete_node_p (pointer node);
		ft::pair<tree_iterator, bool>	insert_node (date_type date);
		tree_iterator					insert_node (tree_iterator position, date_type date);
		tree_iterator					find (const key_type& key);
		void							erase (tree_iterator position);
		size_t							delete_node (const key_type& key);
		size_t							count (const key_type& key) const;
		pointer							find_node_key (const key_type& key) const;

	private:
		bool							is_null_node (pointer x) const;
		void							fix_insert (pointer x);
		void							fix_delete (pointer x);
		void							replace_node (pointer x, pointer y);
		void							rotate_left (pointer x);
		void							rotate_right (pointer x);
		pointer							tree_min(pointer x);
		pointer							tree_max(pointer x);
		void							show_debag ();
		void							print_debag (pointer x);

		pointer			null_node;
		pointer			root;
		size_t			_size_tree;
		key_compare		comp;
		allocator_type	alloc;

};
//CONSTRUCT_DEF_____________________________________________________________________________
template <class T, class Compare, class Allocator>
tree<T,Compare,Allocator>::tree()
{
	_size_tree = 0;
	null_node = alloc.allocate(1);
	alloc.construct(null_node);
	root = null_node;
	root->null_node = null_node;
	root->begin_node = &root;
}
//DISTRUCTOR________________________________________________________________________________
template <class T, class Compare, class Allocator>
tree<T,Compare,Allocator>::~tree()
{
	destroy_node(root);
	alloc.destroy(null_node);
	alloc.deallocate(null_node, 1);
}
//COPY_______________________________________________________________________________________
template <class T, class Compare, class Allocator>
tree<T,Compare,Allocator>::tree(const tree& oth)
{ *this = oth; }
//OPERATOR=___________________________________________________________________________________
template <class T, class Compare, class Allocator>
tree<T,Compare,Allocator>&
tree<T,Compare,Allocator>::operator= (const tree& oth)
{
	if (this != &oth)
	{
		destroy_node(root);
		root = null_node;
		_size_tree = 0;
		comp = oth.comp;
		alloc = oth.alloc;
		for (tree_const_iterator it = oth.begin(); it != oth.end(); ++it)
			insert_node_p(this->root, ft::make_pair<key_type, mapped_type>(it->first, it->second));
	}
	return (*this);
}
//MAX_SIZE________________________________________________________________________________
template <class T, class Compare, class Allocator>
size_t			tree<T,Compare,Allocator>::max_size() const
{ return alloc.max_size(); }
//IS_NULL_NODE________________________________________________________________________________
template <class T, class Compare, class Allocator>
bool			tree<T,Compare,Allocator>::is_null_node(pointer x) const
{
	if (x == null_node)
		return true;
	return false;
}
//BEGIN________________________________________________________________________________
template <class T, class Compare, class Allocator>
typename tree<T,Compare,Allocator>::tree_iterator
tree<T,Compare,Allocator>::begin()
{
	if (is_null_node(root))
		return (root);
	return (tree_iterator(tree_min(root)));
}
template <class T, class Compare, class Allocator>
typename tree<T,Compare,Allocator>::tree_const_iterator
tree<T,Compare,Allocator>::begin() const
{
	if (is_null_node(root))
		return (tree_const_iterator(root));
	pointer	x = root;
	while (!is_null_node(x->left))
		x = x->left;
	return (tree_const_iterator(x));
}
//END________________________________________________________________________________
template <class T, class Compare, class Allocator>
typename tree<T,Compare,Allocator>::tree_iterator
tree<T,Compare,Allocator>::end()
{ return (tree_iterator(null_node)); }

template <class T, class Compare, class Allocator>
typename tree<T,Compare,Allocator>::tree_const_iterator
tree<T,Compare,Allocator>::end() const
{ return (tree_const_iterator(null_node)); }
//SIZE________________________________________________________________________________
template <class T, class Compare, class Allocator>
size_t	tree<T,Compare,Allocator>::size() const
{ return this->_size_tree; }
//EMPTY________________________________________________________________________________
template <class T, class Compare, class Allocator>
bool	tree<T,Compare,Allocator>::empty() const
{ return root == null_node; }
//DESTROY_NODE________________________________________________________________________________
template <class T, class Compare, class Allocator>
void	tree<T,Compare,Allocator>::destroy_node (pointer x)
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
template <class T, class Compare, class Allocator>
typename tree<T,Compare,Allocator>::pointer
tree<T,Compare,Allocator>::insert_node_p (pointer start, date_type date)
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
		//if (date.first < parent->date->first)
		if (comp(date.first, parent->date->first))
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
		//if (date.first < parent->date->first)
		if (comp(date.first, parent->date->first))
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
template <class T, class Compare, class Allocator>
void	tree<T,Compare,Allocator>::fix_insert (pointer x)
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
template <class T, class Compare, class Allocator>
void	tree<T,Compare,Allocator>::delete_node_p(pointer node)
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
template <class T, class Compare, class Allocator>
void	tree<T,Compare,Allocator>::fix_delete(pointer x)
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
template <class T, class Compare, class Allocator>
void	tree<T,Compare,Allocator>::replace_node (pointer x, pointer y)
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
template <class T, class Compare, class Allocator>
void	tree<T,Compare,Allocator>::rotate_left (pointer x)
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
template <class T, class Compare, class Allocator>
void	tree<T,Compare,Allocator>::rotate_right (pointer x)
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
template <class T, class Compare, class Allocator>
ft::pair<typename tree<T,Compare,Allocator>::tree_iterator, bool>
tree<T,Compare,Allocator>::insert_node (date_type date)
{
	pointer	x = find_node_key(date.first);

	if (!is_null_node(x))
		return (ft::pair<tree_iterator, bool>( tree_iterator(x), false));
	x = insert_node_p (this->root, date);
	return (ft::pair<tree_iterator, bool>( tree_iterator(x), true));
}
//INSERT_ITERATOR________________________________________________________________________________
template <class T, class Compare, class Allocator>
typename tree<T,Compare,Allocator>::tree_iterator
tree<T,Compare,Allocator>::insert_node(tree_iterator position, date_type date)
{
	pointer	current = position.p;
	pointer x = insert_node_p (this->root, date);
	return ( tree_iterator(x) );
}
//FIND______________________________________________________________________________________
template <class T, class Compare, class Allocator>
typename tree<T,Compare,Allocator>::tree_iterator
tree<T,Compare,Allocator>::find (const key_type& key)
{ return ( tree_iterator( find_node_key(key) ) ); }
//ERASE_______________________________________________________________________________________________________________________
template <class T, class Compare, class Allocator>
void	tree<T,Compare,Allocator>::erase (tree_iterator position)
{ delete_node_p(position.p); }
//DELETE_NODE________________________________________________________________________________
template <class T, class Compare, class Allocator>
size_t	tree<T,Compare,Allocator>::delete_node(const key_type& key)
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
template <class T, class Compare, class Allocator>
size_t	tree<T,Compare,Allocator>::count(const key_type& key) const
{ return (!is_null_node(find_node_key(key))); }
//FIND_NODE________________________________________________________________________________
template <class T, class Compare, class Allocator>
typename tree<T,Compare,Allocator>::pointer
tree<T,Compare,Allocator>::find_node_key(const key_type& key) const
{
	pointer	current = root;

	while (!is_null_node(current))
	{
		if (current->date->first == key)
			return (current);
		if (comp(key, current->date->first))
		//if (key < current->date->first)
			current = current->left;
		else
			current = current->right;
	}
	return (current);
}
//DEBAG________________________________________________________________________________
template <class T, class Compare, class Allocator>
void	tree<T,Compare,Allocator>::show_debag()
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
}
//DEBAG________________________________________________________________________________
template <class T, class Compare, class Allocator>
void	tree<T,Compare,Allocator>::print_debag(pointer x)
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
}
//TREE_MIN________________________________________________________________________________
template <class T, class Compare, class Allocator>
typename tree<T,Compare,Allocator>::pointer
tree<T,Compare,Allocator>::tree_min(pointer x)
{
	while (!is_null_node(x->left))
		x = x->left;
	return x;
}
//TREE_MAX________________________________________________________________________________
template <class T, class Compare, class Allocator>
typename tree<T,Compare,Allocator>::pointer
tree<T,Compare,Allocator>::tree_max(pointer x)
{
	while (!is_null_node(x->right))
        x = x->right;
    return x;
}

}//end namespace

#endif
