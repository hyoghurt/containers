#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <iterator>
# include <type_traits>
# include <functional>

//# include <cstdder> //std::ptrdiff_t

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator< std::pair<const Key, T> > >
class	map
{
	public:
		typedef Key											key_type;
    	typedef T											mapped_type;
    	typedef std::pair<const key_type, mapped_type>		value_type;
    	typedef Compare										key_compare;
    	typedef Allocator									allocator_type;
    	typedef typename allocator_type::reference			reference;
    	typedef typename allocator_type::const_reference	const_reference;
    	typedef typename allocator_type::pointer			pointer;
    	typedef typename allocator_type::const_pointer		const_pointer;
    	typedef typename allocator_type::size_type			size_type;
    	typedef typename allocator_type::difference_type	difference_type;

    	typedef pointer										iterator;
    	typedef pointer										const_iterator;
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

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			return;
		};

		template < typename InputIterator >
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
		{
			return;
		};

		map (const map& x)
		{
			return;
		};

		~map ()											{};
		map&										operator= (const map& x)				{};

		iterator									begin()									{};
		const_iterator								begin() const							{};
		iterator									end()									{};
		const_iterator								end() const								{};
		reverse_iterator							rbegin()								{};
		const_reverse_iterator						rbegin() const							{};
		reverse_iterator							rend()									{};
		const_reverse_iterator						rend() const							{};
		bool										empty() const							{};
		size_type									size() const							{};
		size_type									max_size() const						{};
		mapped_type&								operator[] (const key_type& k)			{};

		std::pair<iterator, bool>					insert (const value_type& val)						{};
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
		std::pair<const_iterator, const_iterator>	equal_range (const key_type& k) const	{};
		std::pair<iterator, iterator>				equal_range (const key_type& k)			{};
		allocator_type								get_allocator () const					{}; 






	protected:
};


};

#endif
