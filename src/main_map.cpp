#include <vector>
#include <map>
#include <memory>
#include "vector.hpp"
#include "map.hpp"
#include "tree.hpp"

#define	COLO "\033[1;44;1m"
#define NO_C "\033[0m"
#define FIL "\033[1;48;5;55m"

void	test_insert_1(const std::string& promo);
void	test_size(const std::string& promo);

int				main( void )
{
#ifdef FT
    std::cout << COLO << "FT" << NO_C << std::endl;
#else
    std::cout << COLO << "STD" << NO_C << std::endl;
	namespace	ft = std;
#endif

	test_insert_1("TEST INSERT 1");
	test_size("TEST SIZE");


	std::cout << "end main" << std::endl;
	return (0);
}

void	test_insert_1(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::map<int, std::string>		mp;

	std::pair< ft::map<int, std::string>::iterator, bool >		res;

	res = mp.insert(std::pair<int, std::string>(5, "pat"));
	std::cout << res.first->first << " => " << res.first->second << std::endl;

	res = mp.insert(std::pair<int, std::string>(2, "at"));
	if (res.second)
		std::cout << res.first->first << " => " << res.first->second << std::endl;

	res = mp.insert(std::pair<int, std::string>(5, "p"));
	std::cout << res.first->first << " => " << res.first->second << std::endl;
	if (res.second)
		std::cout << res.first->first << " => " << res.first->second << std::endl;
}

void	test_size(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::map<int, std::string>		mp;

	std::cout << "size = " << mp.size() << std::endl;

	mp.insert(std::pair<int, std::string>(5, "pat"));
	mp.insert(std::pair<int, std::string>(2, "at"));
	mp.insert(std::pair<int, std::string>(5, "p"));

	std::cout << "size = " << mp.size() << std::endl;
	std::cout << "max_size = " << mp.max_size() << std::endl;

}
