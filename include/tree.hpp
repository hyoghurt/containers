#ifndef TREE_HPP
# define TREE_HPP

# define	RED 1
# define	BLACK 0

# include <iostream>

template < typename _T >
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
		template < typename _T >
		friend class tree;

		node(node* parent, const __T& date)
		{
			std::cout << "construct node date" << std::endl;
			this->date = date;
			this->parent = parent;
			left = nullptr;
			right = nullptr;
			color = RED;
		};

		~node()
		{
			std::cout << "destructor nod" << std::endl;
		};
};

//template < typename _T, typename Allocator = std::allocator<_T> >
template < typename _T >
class	tree
{
	public:
		typedef std::allocator< node<_T> >					allocator_type;
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


		tree()
		{
			std::cout << "construct tree" << std::endl;
			root = nullptr;
			//alloc = allocator_type();
		};

		~tree()
		{
			std::cout << "destructor tree" << std::endl;
			if (root)
			{
				alloc.destroy(root);
				alloc.deallocate(root, 1);
			}
		}

		void	rotate_left(pointer x)
		{
			pointer	pivot = x->right;

			pivot->parent = x->parent;
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
				/*
				pointer	save_p = g->left;
				pointer	save_left_x = x->left;
				g->left = x;
				x->left = save_p;
				save_p->right = save_left_x;
				*/
				x = x->left;
			}
			else if ((x == x->parent->left) && (x->parent == g->right))
			{
				rotate_right(x->parent);
				/*
				pointer	save_p = g->right;
				pointer	save_right_x = x->right;
				g->right = x;
				x->right = save_p;
				save_p->left = save_right_x;
				*/
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

		void	fixed_tree(pointer x)
		{
			case_1(x);
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

		void	prin(pointer x)
		{

			if (x->left)
			{
				std::cout << "___LEFT_" << std::endl;
				if (x->left->color)
					std::cout << "color = RED" << std::endl;
				else
					std::cout << "color = BLACK" << std::endl;
				std::cout << "date.key = " << x->left->date.first << std::endl;
				if (x->left)
					prin(x->left);
			}
			if (x->right)
			{
				std::cout << "___RIGHT_" << std::endl;
				if (x->right->color)
					std::cout << "color = RED" << std::endl;
				else
					std::cout << "color = BLACK" << std::endl;
				std::cout << "date.key = " << x->right->date.first << std::endl;
				if (x->right)
					prin(x->right);
			}
			
		}

		void	show()
		{
			pointer	x = root;

			std::cout << "___X_" << std::endl;
			if (x->color)
				std::cout << "color = RED" << std::endl;
			else
				std::cout << "color = BLACK" << std::endl;
			std::cout << "date.key = " << x->date.first << std::endl;

			prin(root);
		};

		void	insert_node(_T date)
		{
			pointer	current;
			pointer	parent;
			pointer	x;

			std::cout << "insert tree" << std::endl;
			current = root;
			parent = nullptr;

			while (current != nullptr)
			{
				if (date.first == current->date.first)
					return;
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

			fixed_tree(x);

			show();
			/*
			std::cout << "date.value = " << x->date.second << std::endl;
			std::cout << "point = " << x << std::endl;
			std::cout << "paren = " << x->parent << std::endl;
			if (parent)
			{
				std::cout << "paren left = " << parent->left << std::endl;
				std::cout << "paren right = " << parent->right << std::endl;
			}
			*/
			std::cout << std::endl;
		}

	private:
		pointer			root;
		allocator_type	alloc;		
};

#endif
