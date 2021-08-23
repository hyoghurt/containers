#ifndef FT_HPP
# define FT_HPP

# include <iterator>

namespace ft
{

#ifndef EQUAL_HPP
# define EQUAL_HPP
template <typename InputIterator1, typename InputIterator2>
bool	equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
	while (first1 != last1)
	{
		if (!(*first1 == *first2))
			return false;
		++first1;
		++first2;
	}
	return true;
}
#endif


#ifndef LEXICOGRAPHICAL_HPP
# define LEXICOGRAPHICAL_HPP
template <typename InputIterator1, typename InputIterator2>
bool	lexicographical_compare( InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, InputIterator2 last2 )
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2)
			return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}
#endif


#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP
template < bool condition, typename Type = void >
struct	enable_if;
template < typename Type >
struct	enable_if<true, Type>	{ typedef Type	type; };
#endif


#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP
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
#endif


#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
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
	typedef _Iter															iterator_type;
	typedef typename std::iterator_traits<_Iter>::difference_type			difference_type;
	typedef typename std::iterator_traits<_Iter>::reference					reference;
	typedef typename std::iterator_traits<_Iter>::pointer					pointer;

	reverse_iterator () : current()												{ return; };
	reverse_iterator (_Iter __x) : current(__x)									{ return; };
	template <typename _Up>
	reverse_iterator (const reverse_iterator<_Up>& __u) : current(__u.base())	{ return; };

	template <typename _Up>
	reverse_iterator&	operator= (const reverse_iterator<_Up>& __u)	{ current = __u.base(); return *this; };
	iterator_type		base() const									{ return current; };
	reference			operator* () const								{ _Iter __tmp = current; return *--__tmp; };
	pointer				operator->() const								{ return &(operator*()); };
	reverse_iterator&	operator++()									{ --current; return (*this); };
	reverse_iterator	operator++(int)									{ reverse_iterator tmp(*this); --current; return (tmp); };
	reverse_iterator&	operator--()									{ ++current; return (*this); };
	reverse_iterator	operator--(int)									{ reverse_iterator tmp(*this); ++current; return (tmp); };
	reverse_iterator 	operator+ (difference_type n)					{ return reverse_iterator(current - n); };
	reverse_iterator&	operator+=(difference_type n)					{ current -= n; return (*this); };
	reverse_iterator 	operator- (difference_type n)					{ return reverse_iterator(current + n); };
	reverse_iterator&	operator-=(difference_type n)					{ current += n; return (*this); };
	reference			operator[](difference_type n)					{ return *(*this + n); };
};

template <typename _Iter>
bool	operator==(const reverse_iterator<_Iter>& a, const reverse_iterator<_Iter>& b)
{ return a.base() == b.base(); }

template <typename _Iter>
bool	operator!=(const reverse_iterator<_Iter>& a, const reverse_iterator<_Iter>& b)
{ return !(a == b); }

template <typename _Iter>
bool	operator< (const reverse_iterator<_Iter>& a, const reverse_iterator<_Iter>& b)
{ return b.base() < a.base(); }

template <typename _Iter>
bool	operator<=(const reverse_iterator<_Iter>& a, const reverse_iterator<_Iter>& b)
{ return !(b < a); }

template <typename _Iter>
bool	operator> (const reverse_iterator<_Iter>& a, const reverse_iterator<_Iter>& b)
{ return b < a; }

template <typename _Iter>
bool	operator>=(const reverse_iterator<_Iter>& a, const reverse_iterator<_Iter>& b)
{ return !(a < b); }

template <typename _Iter>
typename std::iterator_traits<_Iter>::difference_type
operator- (const reverse_iterator<_Iter>& a, const reverse_iterator<_Iter>& b)
{ return b.base() - a.base(); }

template <typename _Iter>
reverse_iterator<_Iter>
operator+ (typename reverse_iterator<_Iter>::difference_type n, const reverse_iterator<_Iter>& a)
{ return reverse_iterator<_Iter>(a.base() - n); }

template <typename IterA, typename IterB>
bool	operator==(const reverse_iterator<IterA>& a, const reverse_iterator<IterB>& b)
{ return a.base() == b.base(); }

template <typename IterA, typename IterB>
bool	operator!=(const reverse_iterator<IterA>& a, const reverse_iterator<IterB>& b)
{ return !(a == b); }

template <typename IterA, typename IterB>
bool	operator< (const reverse_iterator<IterA>& a, const reverse_iterator<IterB>& b)
{ return b.base < a.base; }

template <typename IterA, typename IterB>
bool	operator<=(const reverse_iterator<IterA>& a, const reverse_iterator<IterB>& b)
{ return !(b < a); }

template <typename IterA, typename IterB>
bool	operator> (const reverse_iterator<IterA>& a, const reverse_iterator<IterB>& b)
{ return (b < a); }

template <typename IterA, typename IterB>
bool	operator>=(const reverse_iterator<IterA>& a, const reverse_iterator<IterB>& b)
{ return !(a < b); }

template <typename IterA, typename IterB>
typename std::iterator_traits<IterA>::difference_type
operator- (const reverse_iterator<IterA>& a, const reverse_iterator<IterB>& b)
{ return b.base() - a.base(); }


#endif


#ifndef PAIR_HPP
# define PAIR_HPP
template < class T1, class T2 >
struct	pair
{
	typedef	T1		first_type;
	typedef T2		second_type;

	T1				first;
	T2				second;

	pair() : first(), second()	{}
	pair(const first_type& a, const second_type& b) : first(a), second(b)	{}

	template < class U1, class U2 >
	pair (const pair<U1, U2>& pr) : first(pr.first), second(pr.second)		{};

	template <class U1, class U2>
	pair&	operator= (const pair<U1, U2>& pr)
	{
		first = pr.first;
		second = pr.second;
		return *this;
	}

	~pair()	{};
};

template <class T1, class T2>
bool	operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first==rhs.first && lhs.second==rhs.second; }

template <class T1, class T2>
bool	operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs==rhs); }

template <class T1, class T2>
bool	operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

template <class T1, class T2>
bool	operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(rhs<lhs); }

template <class T1, class T2>
bool	operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs<lhs; }

template <class T1, class T2>
bool	operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs<rhs); }


template <class T1, class T2>
pair<T1,T2> make_pair (T1 x, T2 y)
{
	return ( pair<T1,T2>(x,y) );
}

#endif



}
#endif
