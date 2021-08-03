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
			/*
			struct	InputIterator : std::iterator<std::input_iterator_tag, T, T, const T*, T>
			{
				InputIterator () {};
				~InputIterator () {};
				InputIterator (T* p) : p(p) {};
				InputIterator (InputIterator const& oth) { *this = oth; };
				InputIterator&	operator= (InputIterator const& oth)
				{
					if (this != &oth)
						this->p = oth.p;
					return (*this);
				};
				bool			operator== (InputIterator const& oth) const { return (p == oth.p); };
				bool			operator!= (InputIterator const& oth) const { return (p != oth.p); };
				T&				operator*  () const { return *p; };
				T*				operator-> () const { return p; };
				InputIterator&	operator++ () { ++(this->p); return (*this); };
				InputIterator	operator++ (int)
				{
					vector<T, Allocator>::InputIterator	tmp(*this);
					++(this->p);
					return (tmp);
				}

				protected:
					T*	p;
			};
			*/
			struct	iterator
			{
				typedef ptrdiff_t						difference_type;
				typedef T								value_type;
				typedef T*								pointer;
				typedef T&								reference;
				typedef std::random_access_iterator_tag	iterator_category;

				iterator ();
				~iterator () {};
				iterator (T* p);
				iterator (iterator const& oth);
				//a = b
				iterator&	operator= (iterator const& oth);
				//a == b
				bool		operator==(iterator const& oth) const;
				//a != b
				bool		operator!=(iterator const& oth) const;
				//a*
				T&			operator* () const;
				//a->
				T*			operator->() const;
				//++a
				iterator&	operator++();
				//a++
				iterator	operator++(int);
				//--a
				iterator&	operator--();
				//a--
				iterator	operator--(int);
				//a + n
				iterator 	operator+ (size_t const& n);
				//a - n
				iterator 	operator- (size_t const& n);
				//a - b
				size_t		operator- (iterator const& oth);
				//a < b
				bool		operator< (iterator const& oth) const;
				//a > b
				bool		operator> (iterator const& oth) const;
				//a <= b
				bool		operator<=(iterator const& oth) const;
				//a >= b
				bool		operator>=(iterator const& oth) const;
				//a += n
				iterator&	operator+=(size_t const& n);
				//a -= n
				iterator&	operator-=(size_t const& n);
				//a[n]
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

        private:
            pointer			_begin;
            pointer			_end;
			pointer			_end_capacity;
            allocator_type	_alloc;

        public:
            explicit vector(const allocator_type& _alloc = allocator_type())
				: _begin(nullptr), _end(nullptr), _end_capacity(nullptr), _alloc(_alloc)
			{
				return;
			};

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				_begin = _alloc.allocate(n);
				_end = _begin + n;
				_end_capacity = _end;

				pointer		tmp = _begin;

				while (tmp != _end)
				{
					_alloc.construct(tmp, val);
					++tmp;
				}
				return;
			};

			template <typename InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			{
				/*
				size_t	n = last - first;
				std::cout << "n = " << n << std::endl;

				//std::cout << first << std::endl;
				_begin = _alloc.allocate(n);
				_end = _begin + n;
				_end_capacity = _end;

				pointer		tmp = _begin;

				while (tmp != _end)
				{
					//_alloc.construct(tmp, ky(*first));
					//std::cout << *first << std::endl;
					first++;
					++tmp;
				}
				return;
				*/
			};

			vector (const vector& x) {};

			~vector () { destroy_value(_begin, _end, capacity()); };

			iterator				begin()		{ return iterator(_begin); };
			//const_iterator			begin() const {};

			iterator				end()		{ return iterator(_end); };
			//const_iterator			end() const {};

			reverse_iterator		rbegin() {};
			//const_reverse_iterator	rbegin() const {};

			reverse_iterator		rend() {};
			//const_reverse_iterator	rend() const {};

			size_type				size() const		{ return static_cast<size_type>(this->_end - this->_begin); };
			size_type				max_size() const	{ return _alloc.max_size(); };

			void					resize(size_type n, value_type val = value_type()) {};

			size_type				capacity() const	{ return static_cast<size_type>(_end_capacity - _begin); };
			bool					empty() const		{ return (this->_begin == this->_end); };

			void					reserve(size_type n) {};

			reference				operator[] (size_type n)		{ return *(_begin + n); };
			const_reference			operator[] (size_type n) const	{ return *(_begin + n); };

			reference				at (size_type n) {};
			const_reference			at (size_type n) const {};

			reference				front()			{ return (*this->_begin); };
			const_reference			front() const	{ return (*this->_begin); };
			reference				back()			{ return *(this->_end - 1); };
			const_reference			back() const	{ return *(this->_end - 1); };

			template <typename InputIterator>
				void				assign(InputIterator first, InputIterator last) {};
			void					assign(size_type n, const value_type& val) {};

			pointer					copy_value( pointer new_begin )
			{
				pointer	tmp = _begin;

				while (tmp != _end)
				{
					_alloc.construct(new_begin, *tmp);
					++new_begin;
					++tmp;
				}
				return (new_begin);
			}

			void					destroy_value( pointer begin, pointer end, size_t capacity_ )
			{
				pointer	tmp = begin;

				while (tmp != end)
				{
					_alloc.destroy(tmp);
					tmp++;
				}
				_alloc.deallocate(begin, capacity_);
			}

			void					push_back(const value_type& val)
			{
				if (_end_capacity == nullptr)
				{
					_begin = _alloc.allocate(1);
					_end_capacity = _begin + 1;
					_end = _begin;
				}
				else if (capacity() != max_size())
				{
					if (_end == _end_capacity)
					{
						size_t	capacity_ = capacity() * 2;

						pointer	_new_begin = _alloc.allocate(capacity_);
						pointer	_new_end = copy_value(_new_begin);

						destroy_value( _begin, _end, capacity_ / 2);

						_begin = _new_begin;
						_end = _new_end;
						_end_capacity = _begin + capacity_;
					}
					_alloc.construct(_end, val);
					++_end;
				}
			};

			void					pop_back()	{ --_end; };

			iterator				insert(iterator position, const value_type& val) {};
			void					insert(iterator position, size_type n, const value_type& val) {};
			template <typename InputIterator>
				void				insert(iterator position, InputIterator first, InputIterator last) {};

			iterator				erase(iterator position) {};
			iterator				erase(iterator first, iterator last) {};

			void					swap(vector& x) {};
			void					clear() {};

			allocator_type			get_allocator() const {};

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

#include "vector.cpp"

#endif
