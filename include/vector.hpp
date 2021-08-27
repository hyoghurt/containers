#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "ft.hpp"
# include <iostream>
# include <iterator>

namespace ft
{

template < typename T, typename Allocator = std::allocator<T> >
class vector
{
public:
	template <typename Pointer>
	class	my_iterator
	{
	private:
		Pointer	p;
		typedef ft::iterator_traits<Pointer>	_iter_traits;

	public:
		typedef typename _iter_traits::difference_type		difference_type;
		typedef typename _iter_traits::value_type			value_type;
		typedef typename _iter_traits::pointer				pointer;
		typedef typename _iter_traits::reference			reference;
		typedef typename _iter_traits::iterator_category	iterator_category;

		my_iterator ()												{}
		~my_iterator ()												{}
		my_iterator (const Pointer& p) : p(p)						{}
		template <typename U>
		my_iterator (const my_iterator<U>& oth) : p(oth.base())		{}

		reference		operator* () const							{ return *p; }
		pointer			operator->() const							{ return p; }
		my_iterator&	operator++()								{ ++p; return (*this); }
		my_iterator		operator++(int)								{ my_iterator tmp(*this); ++p; return (tmp); }
		my_iterator&	operator--()								{ --p; return (*this); }
		my_iterator		operator--(int)								{ my_iterator tmp(*this); --p; return (tmp); }
		my_iterator 	operator+ (const difference_type& n)		{ return my_iterator(p + n); }
		my_iterator 	operator- (const difference_type& n)		{ return my_iterator(p - n); }
		template <typename U>
		difference_type	operator- (const my_iterator<U>& oth)		{ return (base() - oth.base()); }
		my_iterator&	operator+=(const difference_type& n)		{ this->p += n; return (*this); }
		my_iterator&	operator-=(const difference_type& n)		{ this->p -= n; return (*this); }
		reference		operator[](const difference_type& n)		{ return *(p + n); }
		const Pointer&	base() const								{ return p; }

		template <typename U>
		bool			operator==(const my_iterator<U>& b)			{ return base() == b.base(); }
		template <typename U>
		bool			operator!=(const my_iterator<U>& b)			{ return !(*this == b); }
		template <typename U>
		bool			operator< (const my_iterator<U>& b)			{ return base() < b.base(); }
		template <typename U>
		bool			operator<=(const my_iterator<U>& b)			{ return !(base() > b.base()); }
		template <typename U>
		bool			operator> (const my_iterator<U>& b)			{ return base() > b.base(); }
		template <typename U>
		bool			operator>=(const my_iterator<U>& b)			{ return !(base() < b.base()); }
	};

	typedef T											value_type;
	typedef Allocator									allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::size_type			size_type;
	typedef typename allocator_type::difference_type	difference_type;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef my_iterator<pointer>						iterator;
	typedef my_iterator<const_pointer>					const_iterator;
	typedef ft::reverse_iterator< iterator >			reverse_iterator;
	typedef ft::reverse_iterator< const_iterator >		const_reverse_iterator;

    explicit vector(const allocator_type& _alloc = allocator_type());

	template < typename InputIterator >
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type* = nullptr);

	explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type());

	vector (const vector& x)					{ *this = x; }
	~vector ();
	vector&					operator= (const vector& x);
	iterator				begin()				{ return iterator(_begin); }
	const_iterator			begin() const		{ return const_iterator(_begin); }
	iterator				end()				{ return iterator(_end); }
	const_iterator			end() const			{ return const_iterator(_end); }
	reverse_iterator		rbegin()			{ return reverse_iterator(end()); }
	const_reverse_iterator	rbegin() const		{ return const_reverse_iterator(end()); }
	reverse_iterator		rend()				{ return reverse_iterator(begin()); }
	const_reverse_iterator	rend() const		{ return const_reverse_iterator(begin()); }
	size_type				size() const		{ return static_cast<size_type>(_end - _begin); }
	size_type				max_size() const	{ return _alloc.max_size(); }
	void					resize(size_type n, value_type val = value_type());
	size_type				capacity() const	{ return static_cast<size_type>(_end_capacity - _begin); }
	bool					empty() const		{ return (this->_begin == this->_end); }
	void					reserve(size_type n);
	reference				operator[] (size_type n)		{ return *(_begin + n); }
	const_reference			operator[] (size_type n) const	{ return *(_begin + n); }
	reference				at (size_type n);
	const_reference			at (size_type n) const;
	reference				front()				{ return (*this->_begin); }
	const_reference			front() const		{ return (*this->_begin); }
	reference				back()				{ return *(this->_end - 1); }
	const_reference			back() const		{ return *(this->_end - 1); }
	void					assign(size_type n, const value_type& val);

	template <typename InputIterator>
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
	assign(InputIterator first, InputIterator last);

	void					push_back(const value_type& val);
	void					pop_back()			{ --_end; _alloc.destroy(_end); }
	iterator				insert(iterator position, const value_type& val);
	void					insert(iterator position, size_type n, const value_type& val);

	template <typename InputIterator>
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
	insert(iterator position, InputIterator first, InputIterator last);

	iterator				erase(iterator position);
	iterator				erase(iterator first, iterator last);
	void					swap(vector& x);
	void					clear();
	allocator_type			get_allocator() const		{ return allocator_type(_alloc); }

	template <typename U, typename Alloc_>
	friend bool	operator== (const vector<U, Alloc_>& rhs, const vector<U, Alloc_>& lhs);
	template <typename U, typename Alloc_>
	friend bool	operator< (const vector<U, Alloc_>& rhs, const vector<U, Alloc_>& lhs);

private:
	pointer					_begin;
	pointer					_end;
	pointer					_end_capacity;
	allocator_type			_alloc;

	pointer					copy_value( pointer begin, pointer end, pointer new_begin );
	void					destroy_value( pointer begin, pointer end, size_t capacity_ );
	iterator				copy_for_insert(iterator position, size_type n, const value_type& val);
	iterator				copy_for_insert_no_alloc(iterator position, size_type n, const value_type& val);
	template < typename InputIterator >
	size_t					len_input_iterator(InputIterator first, InputIterator last);
};
//CONSTRUCT_DEFAULT______________________________________________________________________________
template <typename T, typename Allocator>
vector<T,Allocator>::vector (const allocator_type& _alloc)
	: _begin(nullptr), _end(nullptr), _end_capacity(nullptr), _alloc(_alloc)	{}
//CONSTRUCT_______________________________________________________________________________________
template <typename T, typename Allocator>
template < typename InputIterator >
vector<T,Allocator>::vector (InputIterator first, InputIterator last, const allocator_type& alloc,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type*)
{
	size_t		len = len_input_iterator(first, last);
	if (len > 0)
	{
		_begin = _alloc.allocate(len);
		_end = _begin;;
		_end_capacity = _begin + len;
		while (first != last)
			_alloc.construct(_end++, *first++);
	}
}
//CONSTRUCT_______________________________________________________________________________________
template <typename T, typename Allocator>
vector<T,Allocator>::vector (size_type n, const value_type& val,
					const allocator_type& alloc)
{
	if (n > 0)
	{
		_begin = _alloc.allocate(n);
		_end = _begin;
		_end_capacity = _begin + n;
		while (n--)
			_alloc.construct(_end++, val);
	}
}
//DESTRUCT_______________________________________________________________________________________
template <typename T, typename Allocator>
vector<T,Allocator>::~vector<T,Allocator> ()
{
	//std::cout << "distructor vector" << std::endl;
	if (_begin != nullptr)
	{
		for (pointer tmp = _begin; tmp != _end; ++tmp)
			_alloc.destroy(tmp);
		_alloc.deallocate(_begin, capacity());
	}
}
//OPERATOR=_______________________________________________________________________________________
template <typename T, typename Allocator>
vector<T,Allocator>&
vector<T,Allocator>::operator= (const vector<T,Allocator>& x)
{
	if (this != &x)
	{
		for (pointer tmp = _begin; tmp != _end; ++tmp)
			_alloc.destroy(tmp);
		if (capacity() < x.capacity())
		{
			_alloc.deallocate(_begin, capacity());
			_begin = _alloc.allocate(x.capacity());
			_end_capacity = _begin + x.capacity();
		}
		else
			_end = _begin;
		_end = copy_value(x._begin, x._end, _begin);
	}
	return *this;
}
//RESIZE__________________________________________________________________________________________
template <typename T, typename Allocator>
void	vector<T,Allocator>::resize(size_type n, value_type val)
{
	while (size() > n)
		_alloc.destroy(--_end);
	if (n > capacity())
	{
		reserve(n);
		while (_end != _end_capacity)
			_alloc.construct(_end++, val);
	}
}
//RESERVE__________________________________________________________________________________________
template <typename T, typename Allocator>
void	vector<T,Allocator>::reserve(size_type n)
{
	size_type	capacity_ = capacity();
	if (n > capacity_)
	{
		pointer	_new_begin = _alloc.allocate(n);
		pointer	_new_end = copy_value(_begin, _end, _new_begin);

		for (pointer tmp = _begin; tmp != _end; ++tmp)
			_alloc.destroy(tmp);
		_alloc.deallocate(_begin, capacity_);
		_begin = _new_begin;
		_end = _new_end;
		_end_capacity = _begin + n;
	}
}
//AT____________________________________________________________________________
template <typename T, typename Allocator>
typename vector<T,Allocator>::reference
vector<T,Allocator>::at (size_type n)
{
	if (n > size())
		throw std::out_of_range("vector");
	return *(_begin + n);
}
template <typename T, typename Allocator>
typename vector<T,Allocator>::const_reference
vector<T,Allocator>::at (size_type n) const
{
	if (n > size())
		throw std::out_of_range("vector");
	return *(_begin + n);
}
//ASSIGN________________________________________________________________________
template <typename T, typename Allocator>
void
vector<T,Allocator>::assign(size_type n, const value_type& val)
{
	for (pointer tmp = _begin; tmp != _end; ++tmp)
		_alloc.destroy(tmp);
	if (n > capacity())
	{
		_alloc.deallocate(_begin, capacity());
		_begin = _alloc.allocate(n);
		_end = _begin;
		_end_capacity = _begin + n;
	}
	else
		_end = _begin;
	while (n--)
		_alloc.construct(_end++, val);
}
//ASSIGN________________________________________________________________________
template <typename T, typename Allocator>
template <typename InputIterator>
typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
vector<T,Allocator>::assign(InputIterator first, InputIterator last)
{
	size_t		n = len_input_iterator(first, last);

	for (pointer tmp = _begin; tmp != _end; ++tmp)
		_alloc.destroy(tmp);
	if (n > capacity())
	{
		_alloc.deallocate(_begin, capacity());
		_begin = _alloc.allocate(n);
		_end = _begin;
		_end_capacity = _begin + n;
	}
	else
		_end = _begin;
	while (first != last)
		_alloc.construct(_end++, *first++);
}
//PUSH_BACK______________________________________________________________________
template <typename T, typename Allocator>
void			vector<T,Allocator>::push_back(const value_type& val)
{
	if (_begin == nullptr)
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

		for (pointer tmp = _begin; tmp != _end; ++tmp)
			_alloc.destroy(tmp);
		_alloc.deallocate(_begin, capacity());

		_begin = _new_begin;
		_end = _new_end;
		_end_capacity = _begin + capacity_;
	}
	_alloc.construct(_end, val);
	++_end;
}
//INSERT______________________________________________________________________
template <typename T, typename Allocator>
typename vector<T,Allocator>::iterator
vector<T,Allocator>::insert(iterator position, const value_type& val)
{
	if (capacity() < size() + 1)
		return (copy_for_insert(position, 1, val));
	return (copy_for_insert_no_alloc(position, 1, val));
}
//INSERT______________________________________________________________________
template <typename T, typename Allocator>
void
vector<T,Allocator>::insert(iterator position, size_type n, const value_type& val)
{
	if (capacity() < size() + n)
		copy_for_insert(position, n, val);
	else
		copy_for_insert_no_alloc(position, n, val);
}
//INSERT______________________________________________________________________
template <typename T, typename Allocator>
template <typename InputIterator>
typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
vector<T,Allocator>::insert(iterator position, InputIterator first, InputIterator last)
{
	iterator		tmp_first = first;
	iterator		begin = vector<T>::begin();
	iterator		end = vector<T>::end();
	size_t			len = 0;

	while (tmp_first++ != last)
		++len;

	if (len + size() > capacity())
	{
		size_t				old_capacity = capacity();
		size_t				new_capacity = capacity();

		new_capacity *= 2;
		if (new_capacity < size() + len)
			new_capacity = size() + len;

		pointer	_new_begin = _alloc.allocate(new_capacity);
		pointer	new_begin = _new_begin;

		while (begin != position)
		{
			_alloc.construct(new_begin, *begin);
			++new_begin;
			++begin;
		}
		while (first != last)
		{
			_alloc.construct(new_begin, *first);
			++first;
			++new_begin;
		}
		while (begin != end)
		{
			_alloc.construct(new_begin, *begin);
			++new_begin;
			++begin;
		}
		if (_begin != nullptr)
			destroy_value( _begin, _end, old_capacity);
		_begin = _new_begin;
		_end = new_begin;
		_end_capacity = _begin + new_capacity;
	}
	else
	{
		pointer		p_end_dap = _end - 1;
		_end = _end + len;
		pointer		p_end = _end - 1;

		while (end != position)
		{
			_alloc.construct(p_end, *p_end_dap);
			_alloc.destroy(p_end_dap);
			--p_end_dap;
			--p_end;
			--end;
		}
		while (first != last--)
		{
			_alloc.construct(p_end, *last);
			--p_end;
		}
		while (end != begin)
		{
			_alloc.construct(p_end, *p_end_dap);
			_alloc.destroy(p_end_dap);
			--p_end_dap;
			--p_end;
			--end;
		}
	}
}
//ERASE________________________________________________________________________
template <typename T, typename Allocator>
typename vector<T,Allocator>::iterator
vector<T,Allocator>::erase(iterator position)
{
	iterator		new_position = position;
	iterator		ret = position;

	_alloc.destroy(&*position);
	++new_position;
	while (new_position != end())
	{
		_alloc.destroy(&*new_position);
		_alloc.construct(&*position, *new_position);
		++new_position;
		++position;
	}
	--_end;
	return (ret);
}
//ERASE________________________________________________________________________
template <typename T, typename Allocator>
typename vector<T,Allocator>::iterator
vector<T,Allocator>::erase(iterator first, iterator last)
{
	iterator		new_position = first;
	iterator		ret = first;
	size_t								len = 0;

	while (first != last)
	{
		_alloc.destroy(&*first);
		++first;
		++len;
	}

	while (first != end())
	{
		_alloc.destroy(&*first);
		_alloc.construct(&*new_position, *first);
		++new_position;
		++first;
	}
	_end -= len;
	return (ret);
}
//SWAP_________________________________________________________________________
template <typename T, typename Allocator>
void	vector<T,Allocator>::swap(vector<T,Allocator>& x)
{
	ft::swap(_begin, x._begin);
	ft::swap(_end, x._end);
	ft::swap(_end_capacity, x._end_capacity);
	ft::swap(_alloc, x._alloc);
}
//CLEAR_________________________________________________________________________
template <typename T, typename Allocator>
void	vector<T,Allocator>::clear()
{
	for (pointer tmp = _begin; tmp != _end; ++tmp)
		_alloc.destroy(tmp);
	_end = _begin;
}
//COPY_VALUE______________________________________________________________________
template <typename T, typename Allocator>
typename vector<T,Allocator>::pointer
vector<T,Allocator>::copy_value( pointer begin, pointer end, pointer new_begin )
{
	while (begin != end)
	{
		_alloc.construct(new_begin, *begin);
		++new_begin;
		++begin;
	}
	return (new_begin);
}
//MY_FUNCT______________________________________________________________________
template <typename T, typename Allocator>
void
vector<T,Allocator>::destroy_value( pointer begin, pointer end, size_t capacity_ )
{
	pointer	tmp = begin;

	while (tmp != end)
	{
		_alloc.destroy(tmp);
		tmp++;
	}
	_alloc.deallocate(begin, capacity_);
}
template <typename T, typename Allocator>
typename vector<T,Allocator>::iterator
vector<T,Allocator>::copy_for_insert(iterator position, size_type n, const value_type& val)
{
	iterator		new_position;
	iterator		begin = vector::begin();
	iterator		end = vector::end();
	size_t			old_capacity = capacity();
	size_t			new_capacity = capacity();

	while (new_capacity < capacity() + n)
		new_capacity *= 2;
	pointer	new_begin = _alloc.allocate(new_capacity);
	pointer	new_end = new_begin;
	while (begin != position)
	{
		_alloc.construct(new_end, *begin);
		++new_end;
		++begin;
	}
	new_position = iterator(new_end);
	while (n--)
	{
		_alloc.construct(new_end, val);
		++new_end;
	}
	while (begin != end)
	{
		_alloc.construct(new_end, *begin);
		++new_end;
		++begin;
	}
	if (_begin != nullptr)
		destroy_value( _begin, _end, old_capacity);
	_begin = new_begin;
	_end = new_end;
	_end_capacity = _begin + new_capacity;
	return new_position;
}
template <typename T, typename Allocator>
typename vector<T,Allocator>::iterator
vector<T,Allocator>::copy_for_insert_no_alloc(iterator position, size_type n, const value_type& val)
{
	iterator	begin = vector::begin();
	iterator	end = vector::end();
	pointer		p_end_dap = _end - 1;
	_end = _end + n;
	pointer		p_end = _end - 1;

	while (end != position)
	{
		_alloc.construct(p_end, *p_end_dap);
		_alloc.destroy(p_end_dap);
		--p_end_dap;
		--p_end;
		--end;
	}
	while (n--)
	{
		_alloc.construct(p_end, val);
		--p_end;
	}
	while (end != begin)
	{
		_alloc.construct(p_end, *p_end_dap);
		_alloc.destroy(p_end_dap);
		--p_end_dap;
		--p_end;
		--end;
	}
	return position;
}
template <typename T, typename Allocator>
template < typename InputIterator >
size_t
vector<T,Allocator>::len_input_iterator(InputIterator first, InputIterator last)
{
	size_t			len = 0;
	while (first++ != last)
		++len;
	return (len);
}
//OPERATOR______________________________________________________________________
template <typename U, typename Alloc_>
bool	operator== (const vector<U, Alloc_>& rhs, const vector<U, Alloc_>& lhs)
{
	if (rhs.size() != lhs.size())
		return false;
	return ( equal(rhs.begin(), rhs.end(), lhs.begin()) );
}
template <typename U, typename Alloc_>
bool	operator!= (const vector<U, Alloc_>& rhs, const vector<U, Alloc_>& lhs)
{ return !(rhs == lhs); }

template <typename U, typename Alloc_>
bool	operator<  (const vector<U, Alloc_>& rhs, const vector<U, Alloc_>& lhs)
{ return (lexicographical_compare( rhs.begin(), rhs.end(), lhs.begin(), lhs.end() )); }

template <typename U, typename Alloc_>
bool	operator>  (const vector<U, Alloc_>& rhs, const vector<U, Alloc_>& lhs)
{ return (lhs < rhs); }

template <typename U, typename Alloc_>
bool	operator<= (const vector<U, Alloc_>& rhs, const vector<U, Alloc_>& lhs)
{ return !(lhs < rhs); }

template <typename U, typename Alloc_>
bool	operator>= (const vector<U, Alloc_>& rhs, const vector<U, Alloc_>& lhs)
{ return !(rhs < lhs); }

template <typename U, typename Alloc_>
void	swap (vector<U, Alloc_>& rhs, vector<U, Alloc_>& lhs)
{
	ft::swap(rhs.front(), lhs.front());
	ft::swap((rhs.back() + 1), (lhs.back() + 1));
	ft::swap((rhs.front() + rhs.capacity()), (lhs.front() + lhs.capacity()));
	ft::swap(rhs.get_allocator(), lhs.get_allocator());
}

}

#endif
