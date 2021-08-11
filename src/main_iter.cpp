
#include <vector>
#include <map>
#include <memory>
#include "vector.hpp"
#include "map.hpp"
#include "tree.hpp"

#define	COLO "\033[1;44;1m"
#define NO_C "\033[0m"

int				main( void )
{
#ifdef FT
    std::cout << COLO << "FT" << NO_C << std::endl;
#else
    std::cout << COLO << "STD" << NO_C << std::endl;
	namespace	ft = std;
#endif

	ft::vector<int> myvector;

	for (int i=1; i<=5; i++) myvector.push_back(i);

	ft::vector<int>::iterator	it_b = myvector.begin();
	ft::vector<int>::iterator	it_e = myvector.end();

	std::cout << *it_b << std::endl;
	std::cout << *--it_e << std::endl;

	ft::vector<int>::const_iterator		c_it_b = myvector.begin();

	std::cout << *c_it_b << std::endl;
	//c_it_b[0] = 3;

	return (0);
}
