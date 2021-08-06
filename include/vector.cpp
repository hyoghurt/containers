#ifdef VECTOR_HPP

namespace ft
{
	template < typename T, typename Allocator >
	vector<T, Allocator>::vector (size_type n, const value_type& val, const allocator_type& alloc)
	{
		//std::cout << "construct size_type" << std::endl;
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

	template < typename T, typename Allocator >
	template < typename InputIterator >
	vector<T, Allocator>::vector (InputIterator first, InputIterator last, const allocator_type& alloc,
		typename std::enable_if<
			std::is_constructible<
				typename vector::value_type, 
				typename std::iterator_traits<InputIterator>::reference>::value
			>::type*)
	{
		size_t			len = 0;
		InputIterator	first_ = first;

		while (first_++ != last)
			++len;

		if (len > 0)
		{
			_begin = _alloc.allocate(len);
			_end = _begin;
			_end_capacity = _begin + len;
		}
		while (first != last)
			push_back(*first++);
	};

	template < typename T, typename Allocator >
	vector<T, Allocator>::~vector ()
	{
		if (_begin != nullptr)
			destroy_value(_begin, _end, capacity());
	};

	template < typename T, typename Allocator >
	vector<T, Allocator>&	vector<T, Allocator>::operator= (const vector& x)
	{
		//std::cout << "operator= " << std::endl;
		if (this != &x)
		{
			size_t	size_ = size();

			if (size_ != 0)
			{
				while (size_--)
					pop_back();
			}
			if (capacity() < x.capacity())
			{
				this->_begin = _alloc.allocate(x.capacity());
				this->_end = copy_value(x._begin, x._end, this->_begin);
				this->_end_capacity = this->_begin + x.capacity();
			}
			else if (x._begin != nullptr)
			{
				this->_end = copy_value(x._begin, x._end, this->_begin);
			}
		}
		return *this;
	};

	template < typename T, typename Allocator >
	void					vector<T, Allocator>::resize (size_type n, value_type val)
	{
		if (size() > n)
			_end = _begin + n;
		while (size() < n)
			push_back(val);
	};

	template < typename T, typename Allocator >
	void					vector<T, Allocator>::reserve(size_type n)
	{
		if (_begin == nullptr && capacity() < n)
		{
			_begin = _alloc.allocate(n);
			_end = _begin;
			_end_capacity = _begin + n;
		}
		else if (capacity() < n)
		{
			size_t	capacity_ = capacity();

			pointer	_new_begin = _alloc.allocate(n);
			pointer	_new_end = copy_value(_begin, _end, _new_begin);

			destroy_value(_begin, _end, capacity_);

			_begin = _new_begin;
			_end = _new_end;
			_end_capacity = _begin + n;
		}
		return;
	}

	template < typename T, typename Allocator >
	typename vector<T, Allocator>::reference		vector<T, Allocator>::at (size_type n)
	{
		if (n > size())
			throw std::out_of_range("vector");
		return *(_begin + n);
	}

	template < typename T, typename Allocator >
	void					vector<T, Allocator>::assign(size_type n, const value_type& val)
	{
		if (n > capacity())
		{
			if (_begin == nullptr)
				destroy_value( _begin, _end, capacity() );
			_begin = _alloc.allocate(n);
			_end = _begin;
			_end_capacity = _begin + n;
		}
		else
		{
			pointer	begin_ = _begin;

			while (begin_ != _end)
				_alloc.destroy(begin_++);
			_end = _begin;
		}
		while (n--)
			push_back(val);
	};

	template < typename T, typename Allocator >
	template < typename InputIterator >
	typename std::enable_if
	<
		std::is_constructible<
			typename vector<T, Allocator>::value_type, 
			typename std::iterator_traits<InputIterator>::reference>::value,
		void
	>::type
	vector<T, Allocator>::assign(InputIterator first, InputIterator last)
	{
		size_t			len = 0;
		InputIterator	first_ = first;

		while (first_++ != last)
			++len;

		if (len > capacity())
		{
			if (_begin == nullptr)
				destroy_value( _begin, _end, capacity() );
			_begin = _alloc.allocate(len);
			_end = _begin;
			_end_capacity = _begin + len;
		}
		else
		{
			pointer	begin_ = _begin;

			while (begin_ != _end)
				_alloc.destroy(begin_++);
			_end = _begin;
		}
		while (first != last)
			push_back(*first++);
	};





	template < typename T, typename Allocator >
	typename vector<T, Allocator>::pointer			vector<T, Allocator>::copy_value( pointer begin, pointer end, pointer new_begin )
	{
		while (begin != end)
		{
			_alloc.construct(new_begin, *begin);
			++new_begin;
			++begin;
		}
		return (new_begin);
	}


	template < typename T, typename Allocator >
	void					vector<T, Allocator>::destroy_value( pointer begin, pointer end, size_t capacity_ )
	{
		pointer	tmp = begin;

		while (tmp != end)
		{
			_alloc.destroy(tmp);
			tmp++;
		}
		_alloc.deallocate(begin, capacity_);
	}

	template < typename T, typename Allocator >
	void					vector<T, Allocator>::push_back(const value_type& val)
	{
		if (_end_capacity == nullptr)
		{
			_begin = _alloc.allocate(1);
			_end = _begin;
			_end_capacity = _begin + 1;
		}
		if (_end == _end_capacity)
		{
			size_t	capacity_ = capacity() * 2;

			pointer	_new_begin = _alloc.allocate(capacity_);
			pointer	_new_end = copy_value(_begin, _end, _new_begin);

			destroy_value( _begin, _end, capacity_ / 2);

			_begin = _new_begin;
			_end = _new_end;
			_end_capacity = _begin + capacity_;
		}
		_alloc.construct(_end, val);
		++_end;
	};

	template < typename T, typename Allocator >
	typename vector<T, Allocator>::iterator		vector<T, Allocator>::insert(iterator position, const value_type& val)
	{
		typename vector<T>::iterator		new_position;
		typename vector<T>::iterator		begin = vector<T>::begin();
		typename vector<T>::iterator		end = vector<T>::end();

		if (capacity() < size() + 1)
		{
			size_t	capacity_ = capacity() * 2;

			pointer	_new_begin = _alloc.allocate(capacity_);
			pointer	new_begin = _new_begin;

			while (begin != position)
			{
				_alloc.construct(new_begin, *begin);
				++new_begin;
				++begin;
			}
			_alloc.construct(new_begin, val);
			new_position = new_begin;
			++new_begin;
			while (begin != end)
			{
				_alloc.construct(new_begin, *begin);
				++new_begin;
				++begin;
			}
			if (_begin != nullptr)
				destroy_value( _begin, _end, capacity_ / 2);

			_begin = _new_begin;
			_end = new_begin;
			_end_capacity = _begin + capacity_;
	
			return new_position;
		}
		else
		{
			typename vector<T>::pointer		p_end = _end;
			typename vector<T>::pointer		p_end_dap = _end - 1;

			_end = _end + 1;

			while (end != position)
			{
				_alloc.construct(p_end, *p_end_dap);
				_alloc.destroy(p_end_dap);
				--p_end_dap;
				--end;
			}
			_alloc.construct(p_end, *p_end_dap);
			--p_end_dap;
			--end;

			while (end != begin)
			{
				_alloc.construct(p_end, *p_end_dap);
				_alloc.destroy(p_end_dap);
				--p_end_dap;
				--end;
			}
		}
		return position;
	}
}

#endif

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

			//swap
*/
