#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <iterator>

namespace ft
{
	template < typename Iterator >
	struct	iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template < typename T >
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

	template < typename T >
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

    template < typename T, typename Allocator = std::allocator<T> >
    class vector
    {
        public:
			//struct	iterator : std::iterator<std::random_access_iterator_tag, T, T, const T*, T>
			//struct	iterator : std::iterator<std::random_access_iterator_tag, T>
			struct	iterator
			{
				typedef ptrdiff_t						difference_type;
				typedef T								value_type;
				typedef T*								pointer;
				typedef T&								reference;
				typedef std::random_access_iterator_tag	iterator_category;

				iterator ();
				~iterator ();
				iterator (T* p);
				iterator (iterator const& oth);

				iterator&	operator= (iterator const& oth);
				bool		operator==(iterator const& oth) const;
				bool		operator!=(iterator const& oth) const;
				T&			operator* () const;
				T*			operator->() const;
				iterator&	operator++();
				iterator	operator++(int);
				iterator&	operator--();
				iterator	operator--(int);
				iterator 	operator+ (size_t const& n);
				iterator 	operator- (size_t const& n);
				size_t		operator- (iterator const& oth);
				bool		operator< (iterator const& oth) const;
				bool		operator> (iterator const& oth) const;
				bool		operator<=(iterator const& oth) const;
				bool		operator>=(iterator const& oth) const;
				iterator&	operator+=(size_t const& n);
				iterator&	operator-=(size_t const& n);
				T&			operator[](size_t const& n);

				protected:
					T*	p;
			};

			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef iterator									const_iterator;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;
            typedef typename allocator_type::pointer			pointer;
            typedef typename allocator_type::const_pointer		const_pointer;
			typedef std::reverse_iterator<iterator>				reverse_iterator;
			typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;

        public:
            explicit vector(const allocator_type& _alloc = allocator_type())
				: _begin(nullptr), _end(nullptr), _end_capacity(nullptr), _alloc(_alloc) {};

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <typename InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			vector (const vector& x)					{ *this = x; };
			~vector ();
			vector&					operator= (const vector& x);
			iterator				begin()				{ return iterator(_begin); };
			//const_iterator			begin() const {};
			iterator				end()				{ return iterator(_end); };
			//const_iterator			end() const {};
			reverse_iterator		rbegin()			{};
			//const_reverse_iterator	rbegin() const {};
			reverse_iterator		rend()				{};
			//const_reverse_iterator	rend() const {};
			size_type				size() const		{ return static_cast<size_type>(this->_end - this->_begin); };
			size_type				max_size() const	{ return _alloc.max_size(); };
			void					resize(size_type n, value_type val = value_type());
			size_type				capacity() const	{ return static_cast<size_type>(_end_capacity - _begin); };
			bool					empty() const		{ return (this->_begin == this->_end); };
			void					reserve(size_type n);
			reference				operator[] (size_type n)		{ return *(_begin + n); };
			const_reference			operator[] (size_type n) const	{ return *(_begin + n); };
			reference				at (size_type n);
			const_reference			at (size_type n) const			{};
			reference				front()				{ return (*this->_begin); };
			const_reference			front() const		{ return (*this->_begin); };
			reference				back()				{ return *(this->_end - 1); };
			const_reference			back() const		{ return *(this->_end - 1); };
			template <typename InputIterator>
			void					assign(InputIterator first, InputIterator last)	{};
			void					assign(size_type n, const value_type& val)		{};
			void					push_back(const value_type& val);
			void					pop_back()			{ --_end; _alloc.destroy(_end); };
			iterator				insert(iterator position, const value_type& val)				{};
			void					insert(iterator position, size_type n, const value_type& val)	{};
			template <typename InputIterator>
			void					insert(iterator position, InputIterator first, InputIterator last)	{};
			iterator				erase(iterator position)											{};
			iterator				erase(iterator first, iterator last)								{};
			void					swap(vector& x)			{};
			void					clear()					{};
			allocator_type			get_allocator() const	{};

        private:
            pointer					_begin;
            pointer					_end;
			pointer					_end_capacity;
            allocator_type			_alloc;

			pointer					copy_value( pointer begin, pointer end, pointer new_begin );
			void					destroy_value( pointer begin, pointer end, size_t capacity_ );
			/*
			template <typename U, typename Alloc>
			bool				operator== (const vector<U, Alloc>& lhs, const vector<U, Alloc>& rhs) {};

			template <typename U, typename Alloc>
			bool				operator!= (const vector<U, Alloc>& lhs, const vector<U, Alloc>& rhs) {};

			template <typename U, typename Alloc>
			bool				operator<  (const vector<U, Alloc>& lhs, const vector<U, Alloc>& rhs) {};

			template <typename U, typename Alloc>
			bool				operator<= (const vector<U, Alloc>& lhs, const vector<U, Alloc>& rhs) {};

			template <typename U, typename Alloc>
			bool				operator>  (const vector<U, Alloc>& lhs, const vector<U, Alloc>& rhs) {};

			template <typename U, typename Alloc>
			bool				operator>= (const vector<U, Alloc>& lhs, const vector<U, Alloc>& rhs) {};
			*/

			//swap
    };
}

#include "iterator.cpp"
#include "vector.cpp"

#endif
