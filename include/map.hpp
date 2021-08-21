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
		explicit map (const key_compare& comp = key_compare(), const allocator_type& _alloc = allocator_type())		{}
//ITERATOR_CONSTRUCTOR________________________________________________________________________________
		template < typename InputIterator >
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& _alloc = allocator_type())
		{
			return;
		};
//COPY_CONSTRUCTOR________________________________________________________________________________
		map (const map& x)																	{}
//DISTRUCTOR___________________________________________________________________________________________________________
		~map ()																				{}
//OPERATOR_=___________________________________________________________________________________________________________
		map&										operator= (const map& x)				{};
//BEGIN_________________________________________________________________________________________________________________
		iterator									begin()									{ return _base.begin(); }
		const_iterator								begin() const							{};
//END____________________________________________________________________________________________________________________
		iterator									end()									{ return _base.end(); }
		const_iterator								end() const								{};
		reverse_iterator							rbegin()								{};
		const_reverse_iterator						rbegin() const							{};
		reverse_iterator							rend()									{};
		const_reverse_iterator						rend() const							{};
//EMPTY_________________________________________________________________________________________________________________
		bool										empty() const							{ return _base.empty(); }
//SIZE_________________________________________________________________________________________________________________
		size_type									size() const							{ return _base.size(); }
//MAX_SIZE_________________________________________________________________________________________________________________
		size_type									max_size() const						{ return _base.max_size(); }
//OPERATOR_[]_________________________________________________________________________________________________________________
		mapped_type&								operator[] (const key_type& k)
		{ return ( *(   (this->insert( ft::make_pair( k, mapped_type() ) ) )  .first ) ).second ; }
//INSERT_________________________________________________________________________________________________________________
		ft::pair<iterator, bool>					insert (const value_type& val)
		{
			pointer						x;
			ft::pair<iterator, bool>	res;

			x = _alloc.allocate(1);
			_alloc.construct(x, val);

			res = _base.insert_node(x);
			if (!res.second)
			{
				_alloc.destroy(x);
				_alloc.deallocate(x, 1);
			}
			return (res);
		}
//INSERT_ITERATOR_____________________________________________________________________________________________________________
		iterator									insert (iterator position, const value_type& val)
		{
			pointer						x;

			x = _alloc.allocate(1);
			_alloc.construct(x, val);

			return (_base.insert_node(position, x));
		}
//INSERT_RANGE________________________________________________________________________________________________________________
		template <class InputIterator>
		void										insert (InputIterator first, InputIterator last)
		{
			pointer						x;
			ft::pair<iterator, bool>	res;

			while (first != last)
			{
				x = _alloc.allocate(1);
				_alloc.construct(x, ft::make_pair(first->first, first->second) );

				res = _base.insert_node(x);
				if (!res.second)
				{
					_alloc.destroy(x);
					_alloc.deallocate(x, 1);
				}
				++first;
			}
		}
//ERASE_______________________________________________________________________________________________________________________
		void										erase (iterator position)				{ _base.erase(position); }
//ERASE_KEY___________________________________________________________________________________________________________________
		size_type									erase (const key_type& k)				{ return (_base.delete_node(k)); }
//ERASE_INPUT_________________________________________________________________________________________________________________
		void										erase (iterator first, iterator last)
		{
			while (first != last)
			{
				_base.delete_node(first->first);
				++first;
			}
		}

		void										swap (map& x)							{};
		void										clear ()								{};
//KET_COMPARE________________________________________________________________________________________________________________
		key_compare									key_comp () const						{ return Compare(); };
//VALUE_COMPARE_______________________________________________________________________________________________________________
		value_compare								value_comp () const						{ return value_compare(key_compare()); };
//FIND_______________________________________________________________________________________________________________________
		iterator									find (const key_type& k)				{ return (_base.find(k)); };
		const_iterator								find (const key_type& k) const			{};
//COUNT_______________________________________________________________________________________________________________________
		size_type									count (const key_type& k) const			{ return _base.count(k); };
		iterator									lower_bound (const key_type& k)			{};
		const_iterator								lower_bound (const key_type& k) const	{};
		iterator									upper_bound (const key_type& k)			{};
		const_iterator								upper_bound (const key_type& k) const	{};
		ft::pair<const_iterator, const_iterator>	equal_range (const key_type& k) const	{};
		ft::pair<iterator, iterator>				equal_range (const key_type& k)			{};
		allocator_type								get_allocator () const					{}; 

	protected:
		tree<value_type>	_base;
		allocator_type		_alloc;
};


}

#endif
