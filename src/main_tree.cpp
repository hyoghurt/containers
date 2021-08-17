#include <vector>
#include <map>
#include <memory>
#include "tree.hpp"

#define	COLO "\033[1;44;1m"
#define NO_C "\033[0m"
#define FIL "\033[1;48;5;55m"

int				main( void )
{
	tree< ft::pair<char, int> >	tr;

	tree< ft::pair<char, int> >::tree_iterator	it;

	//ft::pair< tree< ft::pair<int, std::string> >::tree_iterator, bool>	ret;

	//ret = tr.insert_node(ft::pair<int, std::string>(4, "sdf"));
	//std::cout << ret.first->first << " => " << ret.first->second << std::endl;
	//std::cout << ret.first->first << std::endl;
	//if (ret.first->first)
		//std::cout << "ok" << std::endl;

	tr.insert_node(ft::pair<char, int>('a', 10));
	tr.insert_node(ft::pair<char, int>('b', 20));
	tr.insert_node(ft::pair<char, int>('c', 30));
	tr.insert_node(ft::pair<char, int>('d', 40));
	tr.insert_node(ft::pair<char, int>('e', 50));
	tr.insert_node(ft::pair<char, int>('f', 60));
	
	for (it = tr.begin(); it != tr.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << std::endl;
	tr.show_debag();
	std::cout << std::endl;

	it = tr.find('b');
	//tr.delete_node_tmp(it.p);


	std::cout << "first = " << it->first << std::endl;
	tr.delete_node_p(it.p);
	//tr.delete_node('b');

	std::cout << std::endl;
	tr.show_debag();
	std::cout << std::endl;




	/*
	it = mymap.find('b');
	mymap.erase (it);                   // erasing by iterator
	size_t	sz = mymap.erase ('c');                  // erasing by key
	std::cout << "size = " << sz << std::endl;

	it = mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range
	
	std::cout << "show before erase" << std::endl;
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
		*/


	return (0);
}
