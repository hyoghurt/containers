#include <vector>
#include <map>
#include <memory>
#include "map.hpp"

#define	COLO "\033[1;44;1m"
#define NO_C "\033[0m"
#define FIL "\033[1;48;5;55m"

void	test_insert_1(const std::string& promo);
void	test_size(const std::string& promo);
void	test_pair(const std::string& promo);
void	test_begin_end(const std::string& promo);

int				main( void )
{
#ifdef FT
    std::cout << COLO << "FT" << NO_C << std::endl;
#else
    std::cout << COLO << "STD" << NO_C << std::endl;
	namespace	ft = std;
#endif

	//test_insert_1("TEST INSERT 1");
	//test_size("TEST SIZE EMPTY");
	//test_pair("TEST PAIR");
	//test_begin_end("TEST BEGIN END");

	ft::map<int, std::string>	m;

	m.insert(ft::pair<int, std::string>(3, "try"));
	m.insert(ft::pair<int, std::string>(2, "two"));

	m[2] = "loli_pop";

	std::cout << "m[] = " << m[2] << std::endl;

	ft::map<int, std::string>::iterator		it = m.begin();
	ft::map<int, std::string>::iterator		it_e = m.end();
	while (it != it_e)
	{
		std::cout << it->first << " => " << it->second << std::endl;
		++it;
	}


	std::cout << "end main" << std::endl;
	return (0);
}


void	test_begin_end(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::map<int, std::string>	m;

	m.insert(ft::pair<int, std::string>(3, "try"));
	m.insert(ft::pair<int, std::string>(2, "two"));
	m.insert(ft::pair<int, std::string>(4, "try"));
	m.insert(ft::pair<int, std::string>(1, "one"));
	m.insert(ft::pair<int, std::string>(5, "try"));
	m.insert(ft::pair<int, std::string>(6, "one"));
	m.insert(ft::pair<int, std::string>(7, "try"));
	m.insert(ft::pair<int, std::string>(8, "one"));

	ft::map<int, std::string>::iterator		it = m.begin();
	ft::map<int, std::string>::iterator		it_e = m.end();
	while (it != it_e)
	{
		std::cout << it->first << " => " << it->second << std::endl;
		++it;
	}
}

void	test_pair(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::pair<int, std::string>	ab(5, "pop");

	std::cout << ab.first << std::endl;
	std::cout << ab.second << std::endl;

	ft::pair <std::string,double> product1;
	ft::pair <std::string,double> product2 ("tomatoes",2.30);
	ft::pair <std::string,double> product3 (product2);

	product1 = product3;

	product2.first = "shoes";                  // the type of first is string
	product2.second = 39.90;                   // the type of second is double

	std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
	std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
	std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';

	if (product1 == product2) std::cout << "==" << std::endl;
	if (product1 != product2) std::cout << "!=" << std::endl;
	if (product1 < product2) std::cout << "<" << std::endl;
	if (product1 <= product2) std::cout << "<=" << std::endl;
	if (product1 > product2) std::cout << ">" << std::endl;
	if (product1 >= product2) std::cout << ">=" << std::endl;

	
	ft::pair <int,int> foo;
	ft::pair <int,int> bar;

	foo = ft::make_pair (10,20);
	//bar = ft::make_pair (10.5,'A');

	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	//std::cout << "bar: " << bar.first << ", " << bar.second << '\n'; return (0);
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

	ft::pair< ft::map<int, std::string>::iterator, bool >		res;

	res = mp.insert(ft::pair<int, std::string>(5, "pat"));
	std::cout << res.first->first << " => " << res.first->second << std::endl;

	res = mp.insert(ft::pair<int, std::string>(2, "at"));
	std::cout << res.first->first << " => " << res.first->second << std::endl;

	res = mp.insert(ft::pair<int, std::string>(5, "p"));
	std::cout << res.first->first << " => " << res.first->second << std::endl;
	if (res.second)
		std::cout << res.first->first << " => " << res.first->second << std::endl;

	res = mp.insert(ft::pair<int, std::string>(2, "at"));
	std::cout << res.first->first << " => " << res.first->second << std::endl;
	++res.first;
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

	if (mp.empty())
		std::cout << "empty" <<std::endl;

	std::cout << "size = " << mp.size() << std::endl;

	mp.insert(ft::pair<int, std::string>(5, "pat"));
	mp.insert(ft::pair<int, std::string>(2, "at"));
	mp.insert(ft::pair<int, std::string>(5, "p"));

	if (mp.empty())
		std::cout << "empty" <<std::endl;

	std::cout << "size = " << mp.size() << std::endl;
	std::cout << "max_size = " << mp.max_size() << std::endl;

}
