#ifdef VECTOR_HPP

namespace	ft
{
	//default
	template < typename T, typename Allocator >
	vector<T, Allocator>::iterator::iterator ( void ) { return; }

	//distructor
	template < typename T, typename Allocator >
	vector<T, Allocator>::iterator::~iterator ( void ) { return; }

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
	typename vector<T, Allocator>::iterator::reference	vector<T, Allocator>::iterator::operator* ( void ) const
	{ return *p; }

	//a->
	template < typename T, typename Allocator >
	typename vector<T, Allocator>::iterator::pointer	vector<T, Allocator>::iterator::operator-> ( void ) const
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
	typename vector<T, Allocator>::iterator::reference	vector<T, Allocator>::iterator::operator[](size_t const& n)
	{ return *(this->p + n); }
}

#endif
