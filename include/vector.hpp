#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <iterator>

namespace ft
{

template < bool condition, typename Type = void >
struct	enable_if;

template < typename Type >
struct	enable_if<true, Type>	{ typedef Type	type; };

/*
template < typename _Iterator >
struct	iterator_traits
{
	typedef typename _Iterator::difference_type		difference_type;
	typedef typename _Iterator::value_type			value_type;
	typedef typename _Iterator::pointer				pointer;
	typedef typename _Iterator::reference			reference;
	typedef typename _Iterator::iterator_category	iterator_category;
};

template < typename T >
struct iterator_traits<T*>
{
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef T*								pointer;
	typedef T&								reference;
	typedef std::random_access_iterator_tag	iterator_category;
};

template < typename T >
struct iterator_traits<const T*>
{
	typedef std::ptrdiff_t					difference_type;
	typedef T								value_type;
	typedef const T*						pointer;
	typedef const T&						reference;
	typedef std::random_access_iterator_tag	iterator_category;
};
*/
template < typename _Iter >
class	reverse_iterator : public std::iterator<	typename std::iterator_traits<_Iter>::iterator_category,
													typename std::iterator_traits<_Iter>::value_type,
													typename std::iterator_traits<_Iter>::difference_type,
													typename std::iterator_traits<_Iter>::pointer,
													typename std::iterator_traits<_Iter>::reference>
{
	protected:
		_Iter	current;

	public:
		typedef _Iter												iterator_type;
		typedef typename std::iterator_traits<_Iter>::difference_type	difference_type;
		typedef typename std::iterator_traits<_Iter>::reference			reference;
		typedef typename std::iterator_traits<_Iter>::pointer			pointer;

		reverse_iterator () : current()												{ return; };
		reverse_iterator (_Iter __x) : current(__x)									{ return; };
		template <typename _Up>
		reverse_iterator (const reverse_iterator<_Up>& __u) : current(__u.base())	{ return; };

		template <typename _Up>
		reverse_iterator&	operator= (const reverse_iterator<_Up>& __u)	{ current = __u.base(); return *this; };
		iterator_type		base() const									{ return current; };
		reference			operator* () const								{ _Iter __tmp = current; return *--__tmp; };
		pointer				operator->() const								{ return (operator*()); };
		reverse_iterator&	operator++()									{ --current; return (*this); };
		reverse_iterator	operator++(int)									{ reverse_iterator tmp(*this); --current; return (tmp); };
		reverse_iterator&	operator--()									{ ++current; return (*this); };
		reverse_iterator	operator--(int)									{ reverse_iterator tmp(*this); ++current; return (tmp); };
		reverse_iterator 	operator+ (difference_type n)					{ return reverse_iterator(current - n); };
		reverse_iterator&	operator+=(difference_type n)					{ current -= n; return (*this); };
		reverse_iterator 	operator- (difference_type n)					{ return reverse_iterator(current + n); };
		reverse_iterator&	operator-=(difference_type n)					{ current += n; return (*this); };
		reference			operator[](difference_type n)					{ return *(*this + n); };

		template <typename _Up>
		bool				operator!=(const reverse_iterator<_Up>& __u) const	{ return (base() != __u.base()); };
		template <typename _Up>
		bool				operator==(const reverse_iterator<_Up>& __u) const	{ return (base() == __u.base()); };
		template <typename _Up>
		bool				operator< (const reverse_iterator<_Up>& __u) const	{ return (base() < __u.base()); };
		template <typename _Up>
		bool				operator> (const reverse_iterator<_Up>& __u) const	{ return (base() > __u.base()); };
		template <typename _Up>
		bool				operator<=(const reverse_iterator<_Up>& __u) const	{ return (base() <= __u.base()); };
		template <typename _Up>
		bool				operator>=(const reverse_iterator<_Up>& __u) const	{ return (base() >= __u.base()); };
};

template < typename T, typename Allocator = std::allocator<T> >
class vector
{
    public:
		//struct	iterator : public std::iterator<std::random_access_iterator_tag, T, T, T*, T>
		//struct	iterator : std::iterator<std::random_access_iterator_tag, T>

		template < typename _T >
		struct	my_iterator
		{
			typedef std::ptrdiff_t					difference_type;
			typedef _T								value_type;
			typedef _T*								pointer;
			typedef _T&								reference;
			typedef std::random_access_iterator_tag	iterator_category;

			my_iterator ()										{ return; };
			~my_iterator ()										{ return; };
			my_iterator (pointer p) : p(p)				{ return; };
			my_iterator (my_iterator const& oth)				{ *this = oth; };

			my_iterator&	operator= (my_iterator const& oth)			{ this->p = oth.p; return (*this); };
			bool			operator==(my_iterator const& oth) const	{ return (p == oth.p); };
			bool			operator!=(my_iterator const& oth) const	{ return (p != oth.p); };
			reference		operator* () const							{ return *p; };
			pointer			operator->() const							{ return p; };
			my_iterator&	operator++()								{ ++(this->p); return (*this); };
			my_iterator		operator++(int)								{ my_iterator tmp(*this); ++(this->p); return (tmp); };
			my_iterator&	operator--()								{ --(this->p); return (*this); };
			my_iterator		operator--(int)								{ my_iterator tmp(*this); --(this->p); return (tmp); };
			my_iterator 	operator+ (size_t const& n)					{ return my_iterator(p + n); };
			my_iterator 	operator- (size_t const& n)					{ return my_iterator(p - n); };
			size_t			operator- (my_iterator const& oth)			{ return (this->p - oth.p); };
			bool			operator< (my_iterator const& oth) const	{ return (this->p < oth.p); };
			bool			operator> (my_iterator const& oth) const	{ return (this->p > oth.p); };
			bool			operator<=(my_iterator const& oth) const	{ return (this->p <= oth.p); };
			bool			operator>=(my_iterator const& oth) const	{ return (this->p >= oth.p); };
			my_iterator&	operator+=(size_t const& n)					{ this->p += n; return (*this); };
			my_iterator&	operator-=(size_t const& n)					{ this->p -= n; return (*this); };
			reference		operator[](size_t const& n)					{ return *(this->p + n); };

			friend		struct const_iterator;
			protected:
				pointer	p;
		};

		struct	const_iterator;

		struct	iterator
		{
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::random_access_iterator_tag	iterator_category;

			iterator ()										{ return; };
			~iterator ()										{ return; };
			iterator (pointer p) : p(p)				{ return; };
			iterator (iterator const& oth)				{ *this = oth; };

			iterator&	operator= (iterator const& oth)			{ this->p = oth.p; return (*this); };
			bool		operator==(iterator const& oth) const	{ return (p == oth.p); };
			bool		operator!=(iterator const& oth) const	{ return (p != oth.p); };
			reference	operator* () const						{ return *p; };
			pointer		operator->() const						{ return p; };
			iterator&	operator++()							{ ++(this->p); return (*this); };
			iterator	operator++(int)							{ iterator tmp(*this); ++(this->p); return (tmp); };
			iterator&	operator--()							{ --(this->p); return (*this); };
			iterator	operator--(int)							{ iterator tmp(*this); --(this->p); return (tmp); };
			iterator 	operator+ (size_t const& n)				{ return iterator(p + n); };
			iterator 	operator- (size_t const& n)				{ return iterator(p - n); };
			size_t		operator- (iterator const& oth)			{ return (this->p - oth.p); };
			bool		operator< (iterator const& oth) const	{ return (this->p < oth.p); };
			bool		operator> (iterator const& oth) const	{ return (this->p > oth.p); };
			bool		operator<=(iterator const& oth) const	{ return (this->p <= oth.p); };
			bool		operator>=(iterator const& oth) const	{ return (this->p >= oth.p); };
			iterator&	operator+=(size_t const& n)				{ this->p += n; return (*this); };
			iterator&	operator-=(size_t const& n)				{ this->p -= n; return (*this); };
			reference	operator[](size_t const& n)				{ return *(this->p + n); };

			friend		struct const_iterator;
			protected:
				pointer	p;
		};

		struct	const_iterator : public iterator
		{
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef const T*						pointer;
			typedef const T&						reference;
			typedef std::random_access_iterator_tag	iterator_category;

			const_iterator () {};
			const_iterator (T* p) : iterator(p) {};
			~const_iterator () {};
			const_iterator (const const_iterator& oth)					{ *this = oth; };
			const_iterator (const iterator& oth)						{ this->p = oth.p; };

			const_iterator&	operator= (const_iterator const& oth)		{ this->p = oth.p; return (*this); };
			bool			operator==(const_iterator const& oth) const	{ return (this->p == oth.p); };
			bool			operator!=(const_iterator const& oth) const	{ return (this->p != oth.p); };
			reference		operator* () const							{ return *this->p; };
			pointer			operator->() const							{ return this->p; };
			const_iterator&	operator++()								{ ++(this->p); return (*this); };
			const_iterator	operator++(int)								{ const_iterator tmp(*this); ++(this->p); return (tmp); };
			const_iterator&	operator--()								{ --(this->p); return (*this); };
			const_iterator	operator--(int)								{ const_iterator tmp(*this); --(this->p); return (tmp); };
			const_iterator 	operator+ (size_t const& n)					{ return const_iterator(this->p + n); };
			const_iterator 	operator- (size_t const& n)					{ return const_iterator(this->p - n); };
			size_t			operator- (const_iterator const& oth)		{ return (this->p - oth.p); };
			bool			operator< (const_iterator const& oth) const	{ return (this->p < oth.p); };
			bool			operator> (const_iterator const& oth) const	{ return (this->p > oth.p); };
			bool			operator<=(const_iterator const& oth) const	{ return (this->p <= oth.p); };
			bool			operator>=(const_iterator const& oth) const	{ return (this->p >= oth.p); };
			const_iterator&	operator+=(size_t const& n)					{ this->p += n; return (*this); };
			const_iterator&	operator-=(size_t const& n)					{ this->p -= n; return (*this); };
			reference		operator[](size_t const& n)					{ return *(this->p + n); };
		};

		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		//typedef my_iterator<T>								iterator;
		//typedef my_iterator<T>						const_iterator;
		typedef ft::reverse_iterator< iterator >			reverse_iterator;
		typedef ft::reverse_iterator< const_iterator >		const_reverse_iterator;

    public:

		/*
		iterator		_make_iter(pointer _p)
		{
			return iterator(_p);
		}
		const_iterator	_make_iter(const_pointer _p)
		{
			return const_iterator(_p);
		}
		*/

        explicit vector(const allocator_type& _alloc = allocator_type())
			: _begin(nullptr), _end(nullptr), _end_capacity(nullptr), _alloc(_alloc) {};

		template < typename InputIterator >
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<
				std::is_constructible<
					value_type, 
					typename std::iterator_traits<InputIterator>::reference>::value
				>::type* = nullptr);

		explicit vector (size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type());

		vector (const vector& x)					{ *this = x; };
		~vector ();
		vector&					operator= (const vector& x);
		//iterator				begin()				{ return _make_iter(_begin); };
		//const_iterator		begin() const		{ return _make_iter(_begin); };
		//const_iterator		begin() const		{ return begin(); };
		//const_iterator		end() const			{ return end(); };
		iterator				begin()				{ return iterator(_begin); };
		const_iterator			begin() const		{ return const_iterator(_begin); };
		iterator				end()				{ return iterator(_end); };
		const_iterator			end() const			{ return const_iterator(_end); };
		reverse_iterator		rbegin()			{ return reverse_iterator(end()); };
		const_reverse_iterator	rbegin() const		{ return const_reverse_iterator(end()); };
		reverse_iterator		rend()				{ return reverse_iterator(begin()); };
		const_reverse_iterator	rend() const		{ return const_reverse_iterator(begin()); };
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
		void					assign(size_type n, const value_type& val);

		template <typename InputIterator>
		typename ft::enable_if
		<
			std::is_constructible<
				value_type, 
				typename std::iterator_traits<InputIterator>::reference>::value,
			void
		>::type
		assign(InputIterator first, InputIterator last);

		void					push_back(const value_type& val);
		void					pop_back()			{ --_end; _alloc.destroy(_end); };
		iterator				insert(iterator position, const value_type& val);
		void					insert(iterator position, size_type n, const value_type& val);

		template <typename InputIterator>
		typename ft::enable_if
		<
			std::is_constructible<
				value_type, 
				typename std::iterator_traits<InputIterator>::reference>::value,
			void
		>::type
		insert(iterator position, InputIterator first, InputIterator last);

		iterator				erase(iterator position);
		iterator				erase(iterator first, iterator last);

		void					swap(vector& x);
		void					clear();
		allocator_type			get_allocator() const	{ return allocator_type(); };

		template <typename U, typename Alloc_>
		bool					operator== (const vector<U, Alloc_>& rhs) const {};

    private:
        pointer					_begin;
        pointer					_end;
		pointer					_end_capacity;
        allocator_type			_alloc;

		pointer					copy_value( pointer begin, pointer end, pointer new_begin );
		void					destroy_value( pointer begin, pointer end, size_t capacity_ );
		iterator				copy_for_insert(iterator position, size_type n, const value_type& val);
		iterator				copy_for_insert_no_alloc(iterator position, size_type n, const value_type& val);


		/*
		template <typename U, typename Alloc_>
		bool					operator== (const vector<U, Alloc_>& lhs, const vector<U, Alloc_>& rhs) {};

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
