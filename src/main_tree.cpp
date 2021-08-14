#include <vector>
#include <map>
#include <memory>
#include "tree.hpp"

#define	COLO "\033[1;44;1m"
#define NO_C "\033[0m"
#define FIL "\033[1;48;5;55m"

int				main( void )
{
	tree< ft::pair<int, std::string> >	tr;

	tree< ft::pair<int, std::string> >::tree_iterator	it;

	ft::pair< tree< ft::pair<int, std::string> >::tree_iterator, bool>	ret;

	ret = tr.insert_node(ft::pair<int, std::string>(4, "sdf"));
	std::cout << ret.first->first << " => " << ret.first->second << std::endl;
	//std::cout << ret.first->first << std::endl;
	//if (ret.first->first)
		//std::cout << "ok" << std::endl;

	std::cout << std::endl;
	//tr.show_debag();
	std::cout << std::endl;



	return (0);
}
