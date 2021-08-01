#include <iostream>
#include <vector>
#include <memory>



namespace ft
{
    template < typename T, typename Allocator = std::allocator<T> >
    class vector
    {
        public:
            typedef typename Allocator::pointer    pointer;

        private:
            pointer     _begin;
            Allocator   _alloc;

            size_t      _size;
            size_t      _end;
            size_t      _capacity;

        public:
            vector()
            {
                _begin = nullptr;
                _size = _capacity = _end = 0;
            };

            size_t const&   size() {return this->_size;};
            size_t const    max_size() {return _alloc.max_size();};
            size_t const&   capacity() {return this->_capacity;};
    };
}


int		main( void )
{
//    std::allocator<int>             alloc;
//    int *a = alloc.allocate(0);
//    alloc.deallocate(a, 1);
#ifdef STD
    std::vector<int>    v;
    std::cout << "STD" << std::endl;
#else
    ft::vector<int>     v;
    std::cout << "FT" << std::endl;
#endif

    std::cout << "capacity = " << v.capacity() << std::endl;
    std::cout << "size = " << v.size() << std::endl;
    std::cout << "max_size = " << v.max_size() << std::endl;


	return (0);
}
