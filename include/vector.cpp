#ifdef VECTOR_HPP

namespace	ft
{
	//default
	template < typename T, typename Allocator >
	vector<T, Allocator>::iterator::iterator ( void ) { return; }

	//consturct pointer
	template < typename T, typename Allocator >
	vector<T, Allocator>::iterator::iterator (T* p) : p(p) { return; }

	//copy
	template < typename T, typename Allocator >
	vector<T, Allocator>::iterator::iterator (vector<T, Allocator>::iterator const& oth)
	{ *this = oth; }

	//a = b
	template < typename T, typename Allocator >
	typename vector<T, Allocator>::iterator&	vector<T, Allocator>::iterator::operator= (typename vector<T, Allocator>::iterator const& oth)
	{ 
		if (this != &oth)
			this->p = oth.p;
		return (*this);
	}

	//a == b
	template < typename T, typename Allocator >
	bool										vector<T, Allocator>::iterator::operator== (typename vector<T, Allocator>::iterator const& oth) const
	{ return (p == oth.p); }

	//a != b
	template < typename T, typename Allocator >
	bool										vector<T, Allocator>::iterator::operator!= (typename vector<T, Allocator>::iterator const& oth) const
	{ return (p != oth.p); }

	//a*
	template < typename T, typename Allocator >
	T&											vector<T, Allocator>::iterator::operator* ( void ) const
	{ return *p; }

	//a->
	template < typename T, typename Allocator >
	T*											vector<T, Allocator>::iterator::operator-> ( void ) const
	{ return p; }

	//++a
	template < typename T, typename Allocator >
	typename vector<T, Allocator>::iterator&	vector<T, Allocator>::iterator::operator++ ( void )
	{ ++(this->p); return (*this); }

	//a++
	template < typename T, typename Allocator >
	typename vector<T, Allocator>::iterator		vector<T, Allocator>::iterator::operator++ (int)
	{
		vector<T, Allocator>::iterator	tmp(*this);
		++(this->p);
		return (tmp);
	}

	//--a
	template < typename T, typename Allocator >
	typename vector<T, Allocator>::iterator&	vector<T, Allocator>::iterator::operator-- ( void )
	{ --(this->p); return (*this); }

	//a--
	template < typename T, typename Allocator >
	typename vector<T, Allocator>::iterator		vector<T, Allocator>::iterator::operator-- (int)
	{
		vector<T, Allocator>::iterator	tmp(*this);
		--(this->p);
		return (tmp);
	}

	//a + n
	template < typename T, typename Allocator >
	typename vector<T, Allocator>::iterator 	vector<T, Allocator>::iterator::operator+ (size_t const& n)
	{ this->p += n; return (*this); }

	//n + a
	//!!!!!!!!!!!!!!!!write
	//
	//a - n
	template < typename T, typename Allocator >
	typename vector<T, Allocator>::iterator 	vector<T, Allocator>::iterator::operator- (size_t const& n)
	{ this->p -= n; return (*this); }

	//a - b
	template < typename T, typename Allocator >
	size_t										vector<T, Allocator>::iterator::operator- (vector<T, Allocator>::iterator const& oth)
	{ return (this->p - oth.p); }

	//a < b
	template < typename T, typename Allocator >
	bool										vector<T, Allocator>::iterator::operator< (vector<T, Allocator>::iterator const& oth) const
	{ return (this->p < oth.p); }

	//a > b
	template < typename T, typename Allocator >
	bool										vector<T, Allocator>::iterator::operator> (vector<T, Allocator>::iterator const& oth) const
	{ return (this->p > oth.p); }

	//a <= b
	template < typename T, typename Allocator >
	bool										vector<T, Allocator>::iterator::operator<=(vector<T, Allocator>::iterator const& oth) const
	{ return (this->p <= oth.p); }

	//a >= b
	template < typename T, typename Allocator >
	bool										vector<T, Allocator>::iterator::operator>=(vector<T, Allocator>::iterator const& oth) const
	{ return (this->p >= oth.p); }

	//a += n
	template < typename T, typename Allocator >
	typename vector<T, Allocator>::iterator&	vector<T, Allocator>::iterator::operator+=(size_t const& n)
	{ this->p += n; return (*this); }

	//a -= n
	template < typename T, typename Allocator >
	typename vector<T, Allocator>::iterator&	vector<T, Allocator>::iterator::operator-=(size_t const& n)
	{ this->p -= n; return (*this); }

	//a[n]
	template < typename T, typename Allocator >
	T&											vector<T, Allocator>::iterator::operator[](size_t const& n)
	{ return *(this->p + n); }
}


					/*

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
			{
				this->_begin = nullptr;
				this->_end = nullptr;
				this->_end_capacity = nullptr;
				this->_alloc = _alloc;
			};
			explicit vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()) {};
			template <typename InputIterator>
				vector (InputIterator first, InputIterator last,
						const allocator_type& alloc = allocator_type()) {};
			vector (const vector& x) {};

			~vector () {};

			iterator				begin() { return iterator(_begin); };
			//const_iterator			begin() const {};

			iterator				end() { return iterator(_end); };
			//const_iterator			end() const {};

			reverse_iterator		rbegin() {};
			//const_reverse_iterator	rbegin() const {};

			reverse_iterator		rend() {};
			//const_reverse_iterator	rend() const {};

			size_type				size() const
			{
				return static_cast<size_type>(this->_end - this->_begin);
			};

			size_type				max_size() const
			{
				return _alloc.max_size();
			};

			void					resize(size_type n, value_type val = value_type()) {};

			size_type				capacity() const
			{
				return static_cast<size_type>(_end_capacity - _begin);
			};

			bool					empty() const
			{
				return (this->_begin == this->_end);
			};

			void					reserve(size_type n) {};

			reference				operator[] (size_type n)
			{
				return *(_begin + n);
			};

			const_reference			operator[] (size_type n) const
			{
				return *(_begin + n);
			};

			reference				at (size_type n) {};
			const_reference			at (size_type n) const {};

			reference				front()
			{
				return (*this->_begin);
			};

			const_reference			front() const
			{
				return (*this->_begin);
			};
			
			reference				back()
			{
				return *(this->_end - 1);
			};

			const_reference			back() const
			{
				return *(this->_end - 1);
			};

			template <typename InputIterator>
				void				assign(InputIterator first, InputIterator last) {};
			void					assign(size_type n, const value_type& val) {};

			void					push_back(const value_type& val)
			{
				if (_end_capacity == nullptr)
				{
					_begin = _alloc.allocate(1);
					_end_capacity = _begin + 1;
					_end = _begin;
				}
				else if (_end == _end_capacity)
				{
					size_t	capac = capacity();
					pointer	_new_begin = _alloc.allocate(capac * 2);
					{
						pointer	tmp = _begin;
						pointer	tmp_n = _new_begin;

						while (tmp != _end)
						{
							*tmp_n = *tmp;
							++tmp_n;
							++tmp;
						}
						_end = tmp_n;

					}
					_alloc.deallocate(_begin, capac);
					_begin = _new_begin;
					_end_capacity = _begin + (capac * 2);
				}
				_alloc.construct(_end, val);
				++_end;
			};

			void					pop_back()
			{
				--_end;
			};

			iterator				insert(iterator position, const value_type& val) {};
			void					insert(iterator position, size_type n, const value_type& val) {};
			template <typename InputIterator>
				void				insert(iterator position, InputIterator first, InputIterator last) {};

			iterator				erase(iterator position) {};
			iterator				erase(iterator first, iterator last) {};

			void					swap(vector& x) {};
			void					clear() {};

			allocator_type			get_allocator() const {};

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

			//swap
    };
}
*/

#endif
