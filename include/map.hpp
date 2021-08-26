#ifndef MAP_HPP
# define MAP_HPP

# include "tree.hpp"

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator< ft::pair<const Key, T> > >
class	map
{
	public:
		typedef Key												key_type;
    	typedef T												mapped_type;
    	typedef ft::pair<const key_type, mapped_type>			value_type;
    	typedef Compare											key_compare;
    	typedef Allocator										allocator_type;
    	typedef typename allocator_type::reference				reference;
    	typedef typename allocator_type::const_reference		const_reference;
    	typedef typename allocator_type::pointer				pointer;
    	typedef typename allocator_type::const_pointer			const_pointer;
    	typedef typename allocator_type::size_type				size_type;
    	typedef typename allocator_type::difference_type		difference_type;
    	typedef typename tree<value_type>::tree_iterator		iterator;
    	typedef typename tree<value_type>::tree_const_iterator	const_iterator;
    	typedef ft::reverse_iterator<iterator>					reverse_iterator;
    	typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
//VALUE_COMPARE________________________________________________________________________________
		class value_compare : public std::binary_function<value_type, value_type, bool>
    	{
			private:
				friend class map;

    		protected:
				key_compare comp;
    			value_compare(key_compare c) : comp(c)	{};

    		public:
				bool operator()(const value_type& x, const value_type& y) const
				{ return comp(x.first, y.first); }
    	};

		explicit map (const key_compare& _comp = key_compare(),
				const allocator_type& _alloc = allocator_type());
		template < typename InputIterator >
		map (InputIterator first, InputIterator last, const key_compare& _comp = key_compare(),
				const allocator_type& _alloc = allocator_type());
		map (const map& x);
		~map () {}
		map&								operator= (const map& x);
		iterator							begin ();
		const_iterator						begin () const;
		iterator							end ();
		const_iterator						end () const;
		reverse_iterator					rbegin ();
		const_reverse_iterator				rbegin () const;
		reverse_iterator					rend ();
		const_reverse_iterator				rend () const;
		bool								empty () const;
		size_type							size () const;
		size_type							max_size () const;
		mapped_type&						operator[] (const key_type& k);
		ft::pair<iterator, bool>			insert (const value_type& val);
		iterator							insert (iterator position, const value_type& val);
		template <class InputIterator>
		void								insert (InputIterator first, InputIterator last);
		void								erase (iterator position);
		size_type							erase (const key_type& k);
		void								erase (iterator first, iterator last);
		void								swap (map& x);
		void								clear ();
		key_compare							key_comp () const;
		value_compare						value_comp () const;
		iterator							find (const key_type& k);
		const_iterator						find (const key_type& k) const;
		size_type							count (const key_type& k) const;
		iterator							lower_bound (const key_type& k);
		const_iterator						lower_bound (const key_type& k) const;
		iterator							upper_bound (const key_type& k);
		const_iterator						upper_bound (const key_type& k) const;
		ft::pair<iterator, iterator>		equal_range (const key_type& k);
		ft::pair<const_iterator, const_iterator>	equal_range (const key_type& k) const;
		allocator_type								get_allocator () const;

	protected:
		tree<value_type>	_base;
		allocator_type		_alloc;
		key_compare			_comp;
};

//DEFAULT_CONSTRUCTOR________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
map<Key,T,Compare,Allocator>::map (const key_compare& _comp, const allocator_type& _alloc)
{
	this->_comp = _comp;
	this->_alloc = _alloc;
}
//ITERATOR_CONSTRUCTOR________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
template <typename InputIterator>
map<Key,T,Compare,Allocator>::map (InputIterator first, InputIterator last,
		const key_compare& _comp, const allocator_type& _alloc)
{
	this->_comp = _comp;
	this->_alloc = _alloc;
	insert(first, last);
}

//COPY_________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
map<Key,T,Compare,Allocator>::map (const map& x)
{ *this = x; }
//OPERATOR=____________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
map<Key,T,Compare,Allocator>&
map<Key,T,Compare,Allocator>::operator= (const map& x)
{
	if (this != &x)
	{
		_base = x._base;
		_alloc = x.get_allocator();
		_comp = x.key_comp();
	}
	return *this;
}
//BEGIN____________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::iterator
map<Key,T,Compare,Allocator>::begin()
{ return iterator(_base.begin()); }

template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::const_iterator
map<Key,T,Compare,Allocator>::begin() const
{ return const_iterator(_base.begin()); }
//END____________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::iterator
map<Key,T,Compare,Allocator>::end()
{ return iterator(_base.end()); }

template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::const_iterator
map<Key,T,Compare,Allocator>::end() const
{ return const_iterator(_base.end()); }
//RBEGIN____________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::reverse_iterator
map<Key,T,Compare,Allocator>::rbegin()
{ return reverse_iterator(end()); };

template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::const_reverse_iterator
map<Key,T,Compare,Allocator>::rbegin() const
{ return const_reverse_iterator(end()); }
//REND____________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::reverse_iterator
map<Key,T,Compare,Allocator>::rend()
{ return reverse_iterator(begin()); }

template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::const_reverse_iterator
map<Key,T,Compare,Allocator>::rend() const
{ return const_reverse_iterator(begin()); };
//EMTPY____________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
bool		map<Key,T,Compare,Allocator>::empty() const
{ return _base.empty(); }
//SIZE____________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::size_type
map<Key,T,Compare,Allocator>::size() const
{ return _base.size(); }
//MAX_SIZE____________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::size_type
map<Key,T,Compare,Allocator>::max_size() const
{ return _base.max_size(); }
//OPERATOR_[]____________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::mapped_type&
map<Key,T,Compare,Allocator>::operator[] (const key_type& k)
{ return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second; }
//INSERT_________________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
ft::pair<typename map<Key,T,Compare,Allocator>::iterator, bool>
map<Key,T,Compare,Allocator>::insert (const value_type& val)
{ return (_base.insert_node(val)); }
//INSERT_ITERATOR_____________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::iterator
map<Key,T,Compare,Allocator>::insert (iterator position, const value_type& val)
{
	return (_base.insert_node(position, val));
}
//INSERT_RANGE________________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
template <class InputIterator>
void	map<Key,T,Compare,Allocator>::insert (InputIterator first, InputIterator last)
{
	while (first != last)
	{
		_base.insert_node( ft::make_pair(first->first, first->second) );
		++first;
	}
}
//ERASE_ITERATOR____________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
void	map<Key,T,Compare,Allocator>::erase (iterator position)
{ _base.erase(position); }
//ERASE_KEY_________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::size_type
map<Key,T,Compare,Allocator>::erase (const key_type& k)
{ return (_base.delete_node(k)); }
//ERASE_INPUT_ITERATOR_______________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
void	map<Key,T,Compare,Allocator>::erase (iterator first, iterator last)
{
	iterator	tmp;

	while (first != last)
	{
		tmp = first;
		++first;
		erase(tmp);
	}
}
template <class Key, class T, class Compare, class Allocator>
void	map<Key,T,Compare,Allocator>::swap (map<Key,T,Compare,Allocator>& x)
{
	std::swap(_base, x._base);
	std::swap(_alloc, x._alloc);
	std::swap(_comp, x._comp);
}
//CLEAR_______________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
void	map<Key,T,Compare,Allocator>::clear ()
{ erase(begin(), end()); }
//KEY_COMPARE_________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::key_compare
map<Key,T,Compare,Allocator>::key_comp () const
{ return _comp; }
//VALUE_COMPARE_______________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::value_compare
map<Key,T,Compare,Allocator>::value_comp () const
{ return value_compare(_comp); }
//FIND________________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::iterator
map<Key,T,Compare,Allocator>::find (const key_type& k)
{ return iterator(_base.find(k)); }

template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::const_iterator
map<Key,T,Compare,Allocator>::find (const key_type& k) const
{ return const_iterator(_base.find(k)); }
//COUNT________________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::size_type
map<Key,T,Compare,Allocator>::count (const key_type& k) const
{ return _base.count(k); }
//LOWER_BOUND________________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::iterator
map<Key,T,Compare,Allocator>::lower_bound (const key_type& k)
{
	iterator	it = begin();
	while (it != end())
	{
		if (!_comp(it->first, k))
			return it;
		++it;
	}
	return it;
}
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::const_iterator
map<Key,T,Compare,Allocator>::lower_bound (const key_type& k) const
{
	const_iterator	it = begin();
	while (it != end())
	{
		if (!_comp(it->first, k))
			return it;
		++it;
	}
	return it;
}
//UPPER_BOUND________________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::iterator
map<Key,T,Compare,Allocator>::upper_bound (const key_type& k)
{
	iterator	it = begin();
	while (it != end())
	{
		if (_comp(k, it->first))
			return it;
		++it;
	}
	return it;
}
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::const_iterator
map<Key,T,Compare,Allocator>::upper_bound (const key_type& k) const
{
	const_iterator	it = begin();
	while (it != end())
	{
		if (_comp(k, it->first))
			return it;
		++it;
	}
	return it;
}
//EQUAL_BOUND________________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
ft::pair<typename map<Key,T,Compare,Allocator>::iterator,
	typename map<Key,T,Compare,Allocator>::iterator>
map<Key,T,Compare,Allocator>::equal_range (const key_type& k)
{ return (ft::make_pair(lower_bound(k), upper_bound(k))); }

template <class Key, class T, class Compare, class Allocator>
ft::pair<typename map<Key,T,Compare,Allocator>::const_iterator,
	typename map<Key,T,Compare,Allocator>::const_iterator>
map<Key,T,Compare,Allocator>::equal_range (const key_type& k) const
{ return (ft::make_pair(lower_bound(k), upper_bound(k))); }
//GET_ALLOCATOR______________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::allocator_type
map<Key,T,Compare,Allocator>::get_allocator () const
{ return _alloc; }


}

#endif
