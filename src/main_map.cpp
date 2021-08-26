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
void	test_operator_kv(const std::string& promo);
void	test_insert_iterator(const std::string& promo);
void	test_find(const std::string& promo);
void	test_erase(const std::string& promo);
void	test_key_compare(const std::string& promo);
void	test_value_compare(const std::string& promo);
void	test_count(const std::string& promo);
void	test_insert_2(const std::string& promo);
void	test_rbegin_rend(const std::string& promo);
void	test_clear(const std::string& promo);
void	test_lower_upper(const std::string& promo);
void	test_equal(const std::string& promo);
void	test_get_alloc(const std::string& promo);
void	test_iterator_dec_icr(const std::string& promo);
void	test_reverse_iterator(const std::string& promo);
void	test_operator_copy(const std::string& promo);
void	test_constructor(const std::string& promo);
void	test_const_iterator(const std::string& promo);
void	test_const_iterator_op(const std::string& promo);
void	test_swap(const std::string& promo);


//TEST__________________________________________________FIL
bool fncomp (char lhs, char rhs) {return lhs<rhs;}
//TEST__________________________________________________FIL
struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int				main( void )
{
#ifdef FT
    std::cout << COLO << "FT" << NO_C << std::endl;
#else
    std::cout << COLO << "STD" << NO_C << std::endl;
	namespace	ft = std;
#endif
	/*
	*/
	test_insert_1("TEST INSERT 1");
	test_size("TEST SIZE EMPTY");
	test_pair("TEST PAIR");
	test_begin_end("TEST BEGIN END");
	test_operator_kv("TEST OPERATOR []");
	test_find("TEST FIND");
	test_insert_iterator("TEST INSERT INTERATOR");
	test_erase("TEST ERASE");
	test_key_compare("TEST KEY COMPARE");
	test_value_compare("TEST VALUE COMPARE");
	test_count("TEST COUNT");
	test_insert_2("TEST INSERT 2");
	test_rbegin_rend("TEST RBEGIN REND");
	test_clear("TEST CLEAR");
	test_lower_upper("TEST LOWER UPPER");
	test_equal("TEST EQUAL");
	test_get_alloc("TEST GET ALLOCATOR");
	test_iterator_dec_icr("TEST ITERATOR INC DEC");
	test_reverse_iterator("TEST REVERSE ITERATOR");
	test_operator_copy("TEST OPERATOR COPY");
	test_constructor("TEST CONSTRUCT");
	/*
	*/
	test_const_iterator("TEST CONST ITERATOR");
	test_const_iterator_op("TEST CONST ITERATOR OP");
	test_swap("TEST SWAP");



	std::cout << "end main" << std::endl;
	return 0;
}
void	test_swap(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	std::map<char,int> foo,bar;
	foo['x']=100;
	foo['y']=200;
	bar['a']=11;
	bar['b']=22;
	bar['c']=33;
	foo.swap(bar);
	std::cout << "foo contains:\n";
	for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "bar contains:\n";
	for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}
void	test_const_iterator_op(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	ft::map<char,int>::iterator			it = mymap.begin();
	ft::map<char,int>::const_iterator	it_c = mymap.begin();
	ft::map<char,int>::const_iterator	it_e = mymap.end();

	if (it == it_c)
		std::cout << "==" << std::endl;
	if (it != it_c)
		std::cout << "!=" << std::endl;

	if (it_c == it)
		std::cout << "==c" << std::endl;
	if (it_c != it)
		std::cout << "!=c" << std::endl;

	if (it_c == it_e)
		std::cout << "==e" << std::endl;
	if (it_c != it_e)
		std::cout << "!=e" << std::endl;
}
void	test_const_iterator(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	for (ft::map<char,int>::const_iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}
void	test_constructor(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::map<char,int> first;
	
	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	
	ft::map<char,int> second (first.begin(),first.end());
	
	ft::map<char,int> third (second);
	second['c']=865;
	
	ft::map<char,int,classcomp> fourth;                 // class as Compare
	fourth['p']=230;
	fourth['z']=25;
	fourth['b']=545;
	fourth['t']=599;

	bool(*fn_pt)(char,char) = fncomp;

	ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	fifth['a']=230;
	fifth['z']=25;
	fifth['b']=545;
	fifth['t']=599;

	for (ft::map<char,int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << it->first << " " << it->second;
	std::cout << std::endl;

	for (ft::map<char,int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << it->first << " " << it->second;
	std::cout << std::endl;

	for (ft::map<char,int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << it->first << " " << it->second;
	std::cout << std::endl;

	for (ft::map<char,int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << it->first << "" << it->second;
	std::cout << std::endl;
}
void	test_operator_copy(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::map<char,int> mymap;
	ft::map<char,int> first;
	ft::map<char,int> second;
	
	first['x']=8;
	first['y']=16;
	first['z']=32;
	
	second=first;                // second now contains 3 ints
	first=ft::map<char,int>();  // and first is now empty
	
	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';
}
void	test_reverse_iterator(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;
	
	// show content:
	ft::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';
}

void	test_iterator_dec_icr(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::map<char, int>	ma;

	ft::map<char, int>::iterator	it;
	ft::map<char, int>::iterator	it_e;

	ma.insert(ft::make_pair<char,int>('a', 34));
	ma.insert(ft::make_pair<char,int>('b', 4));
	ma.insert(ft::make_pair<char,int>('d', 3));
	ma.insert(ft::make_pair<char,int>('r', 23));

	it = ma.begin();
	std::cout << it->first << std::endl;
	std::cout << (it++)->first << std::endl;
	std::cout << it->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (++it)->first << std::endl;
	std::cout << (--it)->first << std::endl;
	std::cout << (it--)->first << std::endl;
	std::cout << (it)->first << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	it = ma.begin();
	it_e = ma.end();

	--it_e;
	std::cout << it_e->first << std::endl;

	while (it != it_e)
	{
		std::cout << it_e->first << std::endl;
		--it_e;
	}
}

void	test_get_alloc(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	int psize;
	ft::map<char,int> mymap;
  	ft::pair<const char,int>* p;

  	// allocate an array of 5 elements using mymap's allocator:
  	p = mymap.get_allocator().allocate(5);

  	// assign some values to array
  	psize = sizeof(ft::map<char,int>::value_type) * 5;

  	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

  	mymap.get_allocator().deallocate(p,5);
}
void	test_equal(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	
	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');
	
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
	
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}
void	test_lower_upper(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow,itup;
	mymap['a']=20;
	mymap['d']=40;
	mymap['h']=60;
	mymap['r']=80;
	mymap['x']=100;
	itlow = mymap.upper_bound('h');
	if (itlow != mymap.end())
		std::cout << itlow->first << std::endl;
	itlow = mymap.lower_bound('d');
	if (itlow != mymap.end())
		std::cout << itlow->first << std::endl;
	itlow = mymap.lower_bound ('b');  // itlow points to b
	itup = mymap.upper_bound ('d');   // itup points to e (not d!)
	mymap.erase(itlow,itup);        // erases [itlow,itup)
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}
void	test_clear(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;
	
	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	  std::cout << it->first << " => " << it->second << '\n';
	
	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;
	
	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}
void	test_rbegin_rend(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::map<char,int> mymap;
	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;
	ft::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';
}
void	test_insert_2(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::map<char,int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

	ft::map<char,int> second (first.begin(),first.end());
	ft::map<char,int>::iterator	it;

	for (it = second.begin(); it != second.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << second.size() << std::endl;

	for (it = first.begin(); it != first.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << first.size() << std::endl;
}

void	test_count(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::map<char,int> mymap;
	char c;
	
	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;
	
	for (c='a'; c<'h'; c++)
	{
		std::cout << "count = " << mymap.count(c) << std::endl;
		std::cout << c;
		if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
		else 
			std::cout << " is not an element of mymap.\n";
	}
}

void	test_value_compare(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	ft::pair<char,int> highest = *mymap.begin();
	ft::map<char,int>::iterator it = mymap.begin();
	++it;

	if (mymap.value_comp()(*it, highest))
		std::cout << it->first << " => " << it->second << '\n';

	if (mymap.value_comp()(highest, *it))
		std::cout << it->first << " => " << it->second << '\n';
}

void	test_key_compare(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::map<char,int> mymap;
	ft::map<char,int>::key_compare mycomp = mymap.key_comp();
	
	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;
	
	ft::map<char,int>::iterator it = mymap.begin();
	ft::map<char,int>::iterator sec = it;
	++sec;
	if (mycomp (it->first, sec->first))
		std::cout << "less" << std::endl;
	++it;
	++it;
	if (mycomp (it->first, sec->first))
		std::cout << "less" << std::endl;
}

void	test_erase(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;
	
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;
	
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	it = mymap.find('b');
	mymap.erase (it);                   // erasing by iterator
	size_t	sz = mymap.erase ('c');                  // erasing by key
	std::cout << "size = " << sz << std::endl;

	it = mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range
	
	std::cout << "show before erase" << std::endl;
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	test_find(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
}

void	test_insert_iterator(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::map<char,int> mymap;
	
	// first insert function version (single parameter):
	mymap.insert ( ft::pair<char,int>('a',100) );
	mymap.insert ( ft::pair<char,int>('z',200) );
	
	ft::pair<ft::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( ft::pair<char,int>('z',500) );
	if (ret.second==false)
	{
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}
	
	// second insert function version (with hint position):
	ft::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
	
// third insert function version (range insertion):
	ft::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}


void	test_operator_kv(const std::string& promo)
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
	m[2] = "loli_pop";
	std::cout << "m[] = " << m[2] << std::endl;
	m[5] = "five";
	std::cout << "m[] = " << m[6] << std::endl;

	ft::map<int, std::string>::iterator		it = m.begin();
	ft::map<int, std::string>::iterator		it_e = m.end();
	while (it != it_e)
	{
		std::cout << it->first << " => " << it->second << std::endl;
		++it;
	}
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
