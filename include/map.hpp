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

		class value_compare : public std::binary_function<value_type, value_type, bool>
    	{
			private:
				friend class map;

    		protected:
				key_compare comp;
    			value_compare(key_compare c) : comp(c)	{};

    		public:
				bool operator()(const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				};
    	};

		explicit map (const key_compare& comp = key_compare(), const allocator_type& _alloc = allocator_type())
		{
			_size = 0;
			return;
		};

		template < typename InputIterator >
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& _alloc = allocator_type())
		{
			return;
		};

		map (const map& x)
		{
			return;
		};

		~map ()																				{};
		map&										operator= (const map& x)				{};

		iterator									begin()									{ return _base.begin(); };
		const_iterator								begin() const							{};
		iterator									end()									{};
		const_iterator								end() const								{};
		reverse_iterator							rbegin()								{};
		const_reverse_iterator						rbegin() const							{};
		reverse_iterator							rend()									{};
		const_reverse_iterator						rend() const							{};
		bool										empty() const							{};
		size_type									size() const							{ return this->_size; };
		size_type									max_size() const						{ return _base.max_size(); };
		mapped_type&								operator[] (const key_type& k)			{};

		ft::pair<iterator, bool>					insert (const value_type& val)
		{
			ft::pair<iterator, bool>	res;

			res = _base.insert_node(val);
			if(res.second)
				++_size;
			return res;
		}

		iterator									insert (iterator position, const value_type& val)	{};
		template <class InputIterator>
		void										insert (InputIterator first, InputIterator last)	{};

		void										erase (iterator position)				{};
		size_type									erase (const key_type& k)				{};
		void										erase (iterator first, iterator last)	{};

		void										swap (map& x)							{};
		void										clear ()								{};
		key_compare									key_comp () const						{};
		value_compare								value_comp () const						{};
		iterator									find (const key_type& k)				{};
		const_iterator								find (const key_type& k) const			{};
		size_type									count (const key_type& k) const			{};
		iterator									lower_bound (const key_type& k)			{};
		const_iterator								lower_bound (const key_type& k) const	{};
		iterator									upper_bound (const key_type& k)			{};
		const_iterator								upper_bound (const key_type& k) const	{};
		ft::pair<const_iterator, const_iterator>	equal_range (const key_type& k) const	{};
		ft::pair<iterator, iterator>				equal_range (const key_type& k)			{};
		allocator_type								get_allocator () const					{}; 

	protected:
		tree<value_type>	_base;
		size_t				_size;
		allocator_type		_alloc;
};


}

#endif
