#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <iterator>
# include <type_traits>
# include <functional>
# include "tree.hpp"

/*
template < class _Tp, class _Compare, class _Allocator >			class	_tree;

template < class _Tp, class _NodePtr, class _DiffType >				class	_tree_iterator;
template < class _Tp, class _constNodePtr, class _DiffType >		class	_tree_const_iterator;

template < class _Pointer >											class	_tree_end_node;

template < class _voidPtr >											class	_tree_node_base;

template < class _Tp, class _VoidPtr >								class	_tree_node;

template < class _Key, class _Value >								class	_value_type;

template < class _TreeIterator >									class _map_iterator;
template < class _TreeIterator >									class _map_const_iterator;
*/

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator< ft::pair<const Key, T> > >
class	map
{
	public:
		typedef Key											key_type;
    	typedef T											mapped_type;
    	typedef ft::pair<const key_type, mapped_type>		value_type;
    	typedef Compare										key_compare;
    	typedef Allocator									allocator_type;
    	typedef typename allocator_type::reference			reference;
    	typedef typename allocator_type::const_reference	const_reference;
    	typedef typename allocator_type::pointer			pointer;
    	typedef typename allocator_type::const_pointer		const_pointer;
    	typedef typename allocator_type::size_type			size_type;
    	typedef typename allocator_type::difference_type	difference_type;

    	typedef typename tree<value_type>::tree_iterator	iterator;
    	typedef typename tree<value_type>::tree_iterator	const_iterator;
    	typedef std::reverse_iterator<iterator>				reverse_iterator;
    	typedef std::reverse_iterator<const_iterator>		const_reverse_iterator;
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
//DEFAULT_CONSTRUCTOR________________________________________________________________________________
		explicit map (const key_compare& _comp = key_compare(), const allocator_type& _alloc = allocator_type())
		{
			this->_comp = _comp;
			this->_alloc = _alloc;
			return;
		}
//ITERATOR_CONSTRUCTOR________________________________________________________________________________
		template < typename InputIterator >
		map (InputIterator first, InputIterator last, const key_compare& _comp = key_compare(),
				const allocator_type& _alloc = allocator_type())
		{
			this->_comp = _comp;
			this->_alloc = _alloc;
			insert(first, last);
			return;
		}
		map (const map& x)																	{}
		~map ()																				{}
		map&										operator= (const map& x)				{};
		iterator									begin()									{ return _base.begin(); }
		const_iterator								begin() const							{};
		iterator									end()									{ return _base.end(); }
		const_iterator								end() const								{};
		reverse_iterator							rbegin()								{ return reverse_iterator(end()); };
		const_reverse_iterator						rbegin() const							{};
		reverse_iterator							rend()									{ return reverse_iterator(begin()); };
		const_reverse_iterator						rend() const							{};
		bool										empty() const							{ return _base.empty(); }
		size_type									size() const							{ return _base.size(); }
		size_type									max_size() const						{ return _base.max_size(); }
		mapped_type&								operator[] (const key_type& k);
		ft::pair<iterator, bool>					insert (const value_type& val);
		iterator									insert (iterator position, const value_type& val);
		template <class InputIterator>
		void										insert (InputIterator first, InputIterator last);
		void										erase (iterator position)				{ _base.erase(position); }
		size_type									erase (const key_type& k)				{ return (_base.delete_node(k)); }
		void										erase (iterator first, iterator last);
		void										swap (map& x)							{};
		void										clear ()								{ erase(begin(), end()); };
		key_compare									key_comp () const						{ return _comp; };
		value_compare								value_comp () const						{ return value_compare(_comp); };
		iterator									find (const key_type& k)				{ return (_base.find(k)); };
		const_iterator								find (const key_type& k) const			{};
		size_type									count (const key_type& k) const			{ return _base.count(k); };
		iterator									lower_bound (const key_type& k);
		const_iterator								lower_bound (const key_type& k) const	{};
		iterator									upper_bound (const key_type& k);
		const_iterator								upper_bound (const key_type& k) const	{};
		ft::pair<iterator, iterator>				equal_range (const key_type& k);
		ft::pair<const_iterator, const_iterator>	equal_range (const key_type& k) const	{};
		allocator_type								get_allocator () const					{ return _alloc; };

	protected:
		tree<value_type>	_base;
		allocator_type		_alloc;
		key_compare			_comp;
};
//OPERATOR_[]_________________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::mapped_type&				map<Key,T,Compare,Allocator>::operator[] (const key_type& k)
{
	return ( *(   (this->insert( ft::make_pair( k, mapped_type() ) ) )  .first ) ).second;
}
//INSERT_________________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
ft::pair<typename map<Key,T,Compare,Allocator>::iterator, bool>	map<Key,T,Compare,Allocator>::insert (const value_type& val)
{
	ft::pair<iterator, bool>	res;

	res = _base.insert_node(val);
	return (res);
}
//INSERT_ITERATOR_____________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::iterator		map<Key,T,Compare,Allocator>::insert (iterator position, const value_type& val)
{
	return (_base.insert_node(position, val));
}
//INSERT_RANGE________________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
template <class InputIterator>
void					map<Key,T,Compare,Allocator>::insert (InputIterator first, InputIterator last)
{
	while (first != last)
	{
		_base.insert_node( ft::make_pair(first->first, first->second) );
		++first;
	}
}
//ERASE_INPUT_ITERATOR_________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
void					map<Key,T,Compare,Allocator>::erase (iterator first, iterator last)
{
	iterator	tmp;

	while (first != last)
	{
		tmp = first;
		++first;
		erase(tmp);
	}
}
//LOWER_BOUND________________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::iterator			map<Key,T,Compare,Allocator>::lower_bound (const key_type& k)
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
//UPPER_BOUND________________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
typename map<Key,T,Compare,Allocator>::iterator			map<Key,T,Compare,Allocator>::upper_bound (const key_type& k)
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
//EQUAL_BOUND________________________________________________________________________________________________________________
template <class Key, class T, class Compare, class Allocator>
ft::pair<typename map<Key,T,Compare,Allocator>::iterator, typename map<Key,T,Compare,Allocator>::iterator>
	map<Key,T,Compare,Allocator>::equal_range (const key_type& k)
{ return (ft::make_pair(lower_bound(k), upper_bound(k))); }


}

#endif
