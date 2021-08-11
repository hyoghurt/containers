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

	std::map<int, std::string>		mp;
	std::pair<std::map<int, std::string>::iterator, bool>		tmp;

	tmp = mp.insert(std::pair<int, std::string>(5, "pat"));
	std::cout << tmp.first->first << std::endl;
	//std::cout << tmp->first << " => " tmp->second << std::endl;



	//std::pair<int, std::string>	p1(10, "keks");
	//mp.insert(p1);
	//std::cout << mp[10] << std::endl;

	/*
	tree< int, std::string >	tr;

	std::pair<int, std::string>	p1(10, "keks");
	tr.insert_node(p1);

	std::pair<int, std::string>	p2(9, "keks");
	tr.insert_node(p2);

	std::pair<int, std::string>	p21(8, "keks");
	tr.insert_node(p21);

	std::pair<int, std::string>	p22(7, "keks");
	tr.insert_node(p22);

	std::cout << std::endl;
	tr.show_debag();
	std::cout << std::endl;
	tr.delete_node(8);
	tr.show_debag();
	*/

	std::cout << "end main" << std::endl;
	return (0);
}
