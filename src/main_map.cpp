#include <vector>
#include <map>
#include <memory>
#include "vector.hpp"
#include "map.hpp"
#include "tree.hpp"

#define	COLO "\033[1;44;1m"
#define NO_C "\033[0m"
#define FIL "\033[1;48;5;55m"

int				main( void )
{
#ifdef FT
    std::cout << COLO << "FT" << NO_C << std::endl;
#else
    std::cout << COLO << "STD" << NO_C << std::endl;
	namespace	ft = std;
#endif

	ft::map<int, std::string>		mp;

	std::pair< ft::map<int, std::string>::iterator, bool >		res;

	res = mp.insert(std::pair<int, std::string>(5, "pat"));
	res = mp.insert(std::pair<int, std::string>(2, "at"));
	res = mp.insert(std::pair<int, std::string>(5, "p"));

	std::cout << res.first->first << " => " << res.first->second << std::endl;

	std::cout << "size = " << mp.size() << std::endl;


	std::pair<int, std::string>		pa(523, "sdf");

	std::pair<int, std::string>::first_type	u = pa.first;

	std::cout << u << std::endl;

	//std::cout << "max_size = " << mp.max_size() << std::endl;


	//res = mp.insert(std::pair<int, std::string>(5, "pat"));
	//tmp = mp.insert(std::pair<int, std::string>(5, "one"));
	//if (tmp.second)
		//std::cout << tmp.first->first << " => " << tmp.first->second << std::endl;
	//std::cout << tmp->first << " => " tmp->second << std::endl;

	std::cout << "end main" << std::endl;
	return (0);
}
