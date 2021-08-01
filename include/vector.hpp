#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <iterator>

namespace ft
{
    template < typename T >
	class	_iterator : std::iterator<std::input_iterator_tag, T, T, const T*, T>
	{
		public:
			_iterator&	begin() {}; //check _iterator&
			_iterator&	end() {}; //chech _iterator&
	};

    template < typename T, typename Allocator = std::allocator<T> >
    class vector
    {
        public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef ft::_iterator<value_type>					iterator;
			typedef ft::_iterator<value_type>					const_iterator;
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

			iterator				begin() {};
			const_iterator			begin() const {};

			iterator				end() {};
			const_iterator			end() const {};

			reverse_iterator		rbegin() {};
			const_reverse_iterator	rbegin() const {};

			reverse_iterator		rend() {};
			const_reverse_iterator	rend() const {};

			size_type				size() const { return static_cast<size_type>(this->_end - this->_begin); };
			size_type				max_size() const { return _alloc.max_size(); };
			void					resize(size_type n, value_type val = value_type()) {};
			size_type				capacity() const { return static_cast<size_type>(_end_capacity - _begin); };
			bool					empty() const { return (this->_begin == this->_end); };
			void					reserve(size_type n) {};

			reference				operator[] (size_type n) {};
			const_reference			operator[] (size_type n) const {};

			reference				at (size_type n) {};
			const_reference			at (size_type n) const {};

			reference				front() { /*if !empy() else*/ return (*this->_begin); };
			const_reference			front() const { /*tak zhe*/ };
			
			reference				back() { /*back() called for empty vector*/ return *(this->_end - 1); };
			const_reference			back() const {};

			template <typename InputIterator>
				void				assign(InputIterator first, InputIterator last) {};
			void					assign(size_type n, const value_type& val) {};

			void					push_back(const value_type& val)
			{
				if (_end_capacity == nullptr)
				{
					_begin = _alloc.allocate(1);
					_end_capacity = _begin + 1;
					_end = _end_capacity;
					_alloc.construct(_begin, val);
				}
				else
				{



				}
			};

			void					pop_back() {};

			iterator				insert(iterator position, const value_type& val) {};
			void					insert(iterator position, size_type n, const value_type& val) {};
			template <typename InputIterator>
				void				insert(iterator position, InputIterator first, InputIterator last) {};

			iterator				erase(iterator position) {};
			iterator				erase(iterator first, iterator last) {};

			void					swap(vector& x) {};
			void					clear() {};

			allocator_type			get_allocator() const {};

			//operator
			//swap
    };
}

#endif
