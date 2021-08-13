#ifndef TREE_HPP
# define TREE_HPP


# define	RED 1
# define	BLACK 0

# define	CL "\033[1;44;1m"
# define	NC "\033[0m"

# include "ft.hpp"
# include <iostream>

template < typename T >
class	tree;

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

	public:

		template < typename T >
		friend class tree;

		node(pointer parent, const __T& date)
		{
			this->date = date;
			this->parent = parent;
			left = nullptr;
			right = nullptr;
			color = RED;
			//std::cout << date.first << ": construct node" << std::endl;
		};

		~node()
		{
			//std::cout << date.first << ": destructor node" << std::endl;
		};
};

//template < typename _T, typename Allocator = std::allocator<_T> >
template < typename T >
class	tree
{
	public:
		//typedef	ft::pair<T, U>								_T;
		typedef std::allocator< node<T> >					allocator_type;
		/*
		typedef _T											value_type;
		typedef Allocator									allocator_type;
		*/
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		typedef T*											tree_iterator;


		tree()
		{
			//std::cout << "construct tree" << std::endl;
			root = nullptr;
		};

		~tree()
		{
			//std::cout << "destructor tree" << std::endl;
			destroy_node(root);
		};

		size_t	max_size() const
		{
			return alloc.max_size();
		}

		void	destroy_node(pointer x)
		{
			if (x)
			{
				destroy_node(x->left);
				destroy_node(x->right);
				alloc.destroy(x);
				alloc.deallocate(x, 1);
			}
		};

		ft::pair<tree_iterator, bool>	insert_node(T date)
		{
			pointer	current;
			pointer	parent;
			pointer	x;

			current = root;
			parent = nullptr;

			while (current != nullptr)
			{
				if (date.first == current->date.first)
					return (ft::pair<tree_iterator, bool>( &(current->date), false));
				parent = current;
				if (date.first < parent->date.first)
					current = parent->left;
				else
					current = parent->right;
			}
			x = alloc.allocate(1);
			alloc.construct(x, parent, date);
			if (parent)
			{
				if (date.first < parent->date.first)
					parent->left = x;
				else
					parent->right = x;
			}
			else
				root = x;

			case_1(x);

			return (ft::pair<tree_iterator, bool>( &(x->date), true));
		};

		void	delete_node(typename T::first_type key)
		{
			pointer	del = find_node_key(key);
			delete_one_child(del);
		}

		pointer	sibling(pointer x)
		{
			if (x == x->parent->left)
				return (x->parent->right);
			else
				return (x->parent->left);
		};

		void	replace_node(pointer x, pointer child)
		{
			if (child != nullptr)
				child->parent = x->parent;
			if (x->parent != nullptr)
			{
				if (x == x->parent->left)
					x->parent->left = child;
				else
					x->parent->right = child;
			}
		};

		void	delete_one_child(pointer x)
		{
			pointer	child;

			//find child to na chto menat
			//
			if ((x->left != nullptr) && (x->right != nullptr))
			{
				child = x->left;
				while(child->right != nullptr)
					child = child->right;
			}
			else if (x->left == nullptr)
				child = x->right;
			else
				child = x->left;

			if (child == nullptr)
			{
				std::cout << "child == nullptr" << std::endl;
				return;
			}
			//case for child == root

			replace_node(x, child);

			if (x->color == BLACK)
			{
				if (child->color == RED)
					child->color = BLACK;
				else
					delete_case_1(child);
			}
			alloc.destroy(x);
			alloc.deallocate(x, 1);
		};

		void	delete_case_1(pointer x)
		{
			if (x->parent != nullptr)
				delete_case_2(x);
		};

		void	delete_case_2(pointer x)
		{
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


		pointer	find_node_key(typename T::first_type key)
		{
			pointer	current = root;

			while(current)
			{
				if (current->date.first == key)
					return (current);
				if (key < current->date.first)
					current = current->left;
				else
					current = current->right;
			}
			return (nullptr);
		};

		pointer	find_node(T date)
		{
			pointer	current = root;

			while(current)
			{
				if (current->date.first == date.first)
					return (current);
				if (date.first < current->date.first)
					current = current->left;
				else
					current = current->right;
			}
			return (nullptr);
		};


		void	case_1(pointer x)
		{
			if (x->parent == nullptr)
				x->color = BLACK;
			else
				case_2(x);
		};

		void	case_2(pointer x)
		{
			if (x->parent->color == BLACK)
				return;
			else
				case_3(x);
		};

		void	case_3(pointer x)
		{
			pointer	u = unlce(x);
			pointer	g;

			if ((u != nullptr) && (u->color == RED))
			{
				x->parent->color = BLACK;
				u->color = BLACK;
				g = grandparent(x);
				g->color = RED;
				case_1(g);
			}
			else
				case_4(x);
		};

		void	case_4(pointer x)
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
			case_5(x);
		};

		void	case_5(pointer x)
		{
			pointer	g = grandparent(x);

			x->parent->color = BLACK;
			g->color = RED;
			if ((x == x->parent->left) && (x->parent == g->left))
				rotate_right(g);
			else
				rotate_left(g);
		};

		pointer	grandparent(pointer x)
		{
			if ((x != nullptr) && (x->parent != nullptr))
				return x->parent->parent;
			else
				return (nullptr);
		};

		pointer	unlce(pointer x)
		{
			pointer	g = grandparent(x);
			if (g == nullptr)
				return (nullptr);
			if (x->parent == g->left)
				return (g->right);
			else
				return (g->left);
		};

		void	rotate_left(pointer x)
		{
			pointer	pivot = x->right;

			pivot->parent = x->parent;
			if (pivot->parent == nullptr)
				root = pivot;
			if (x->parent != nullptr)
			{
				if (x->parent->left == x)
					x->parent->left = pivot;
				else
					x->parent->right = pivot;
			}
			x->right = pivot->left;
			if (pivot->left != nullptr)
				pivot->left->parent = x;
			x->parent = pivot;
			pivot->left = x;
		};

		void	rotate_right(pointer x)
		{
			pointer	pivot = x->left;

			pivot->parent = x->parent;
			if (pivot->parent == nullptr)
				root = pivot;
			if (x->parent != nullptr)
			{
				if (x->parent->left == x)
					x->parent->left = pivot;
				else
					x->parent->right = pivot;
			}
			x->left = pivot->right;
			if (pivot->right != nullptr)
				pivot->right->parent = x;
			x->parent = pivot;
			pivot->right = x;
		};

		void	show_debag()
		{
			pointer	x = root;

			std::cout << CL << "___ROOT_" << x << NC << std::endl;
			if (x->color)
				std::cout << "color = RED" << std::endl;
			else
				std::cout << "color = BLACK" << std::endl;
			std::cout << "date.key = " << x->date.first << std::endl;

			print_debag(root);
		};

		void	print_debag(pointer x)
		{
			if (x->left)
			{
				std::cout << CL << "___LEFT_" << x << NC << std::endl;
				if (x->left->color)
					std::cout << "color = RED" << std::endl;
				else
					std::cout << "color = BLACK" << std::endl;
				std::cout << "date.key = " << x->left->date.first << std::endl;
				if (x->left)
					print_debag(x->left);
			}
			if (x->right)
			{
				std::cout << CL << "___RGHT_" << x << NC << std::endl;
				if (x->right->color)
					std::cout << "color = RED" << std::endl;
				else
					std::cout << "color = BLACK" << std::endl;
				std::cout << "date.key = " << x->right->date.first << std::endl;
				if (x->right)
					print_debag(x->right);
			}
		};

	private:
		pointer			root;
		allocator_type	alloc;
};

#endif
