#include <vector>
#include <memory>
#include "vector.hpp"

int		main( void )
{
#ifdef FT
    ft::vector<int>				v;
	ft::vector<int>::iterator	it;
    std::cout << "FT" << std::endl;

#else
    std::vector<int>			v;
	std::vector<int>::iterator	it;
    std::cout << "\033[1;44;1mSTD\033[0m" << std::endl;

#endif

	std::cout << "capacity = " << v.capacity() << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	v.push_back(32);
	std::cout << "capacity = " << v.capacity() << std::endl;
	std::cout << "size = " << v.size() << std::endl;
    std::cout << "max_size = " << v.max_size() << std::endl;


	return (0);
}
