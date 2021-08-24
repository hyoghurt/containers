#include <vector>
#include <memory>
#include <iostream>
#include "vector.hpp"

#define	COLO "\033[1;44;1m"
#define NO_C "\033[0m"
#define FIL "\033[1;48;5;55m"

void	test_capac_size(const std::string& promo);
void	test_iterator_inc_decr(const std::string& promo);
void	test_operator(const std::string& promo);
void	test_front_back(const std::string& promo);
void	test_oper_qr(const std::string& promo); //operator v[]
void	test_point_allocat(const std::string& promo);
void	test_pop_back(const std::string& promo);
void	test_constructor(const std::string& promo);
void	test_constructor_1(const std::string& promo);
void	test_constructor_2(const std::string& promo);
void	test_resize(const std::string& promo);
void	test_reserve(const std::string& promo);
void	test_at(const std::string& promo);
void	test_assign(const std::string& promo);
void	test_insert_1(const std::string& promo);
void	test_insert_2(const std::string& promo);
void	test_insert_3(const std::string& promo);
void	test_insert_4(const std::string& promo);
void	test_insert_5(const std::string& promo);
void	test_insert_6(const std::string& promo);
void	test_erase_1(const std::string& promo);
void	test_erase_2(const std::string& promo);
void	test_swap(const std::string& promo);
void	test_clear(const std::string& promo);
void	test_get_alloc(const std::string& promo);
void	test_revers_iterator(const std::string& promo);
void	test_const_iterator(const std::string& promo);
void	test_operator_comp(const std::string& promo);
void	test_const_iterator_operat(const std::string& promo);


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
	test_capac_size("TEST CAPACITY SIZE");
	test_iterator_inc_decr("TEST ITERATOR OPER");
	test_operator("TEST OPERATOR");
	test_front_back("TEST FRONT BACK");
	test_oper_qr("TEST OPER []"); //operator v[]
	test_point_allocat("TEST POIN ALLOCAT");
	test_pop_back("TEST POP_BACK");
	test_constructor("TEST CONST");
	test_constructor_1("TEST CONST 1");
	test_constructor_2("TEST CONST 2");
	test_resize("TEST RESIZE");
	test_reserve("TEST RESERVE");
	test_at("TEST AT");
	test_assign("TEST ASSIGN");
	test_insert_1("TEST INSERT 1");
	test_insert_2("TEST INSERT 2");
	test_insert_3("TEST INSERT 3");
	test_insert_4("TEST INSERT 4");
	test_insert_5("TEST INSERT 5");
	test_insert_6("TEST INSERT 6");
	test_erase_1("TEST ERASE 1");
	test_erase_2("TEST ERASE 2");
	test_swap("TEST SWAP");
	test_clear("TEST CLEAR");
	test_get_alloc("TEST GET ALLOC");
	test_revers_iterator("TEST REVERSE ITERATOR");
	test_const_iterator("TEST CONST ITERATOR");
	test_operator_comp("TEST OPERATOR COMP");
	test_const_iterator_operat("TEST CONT ITERATOR OPER");
	/*
	*/

	ft::vector<int>	m;

	m.push_back(5);
	m.push_back(15);
	m.push_back(4);

	std::cout << m.size() << std::endl;
	std::cout << m.capacity() << std::endl;

	m.assign(2, 9);

	std::cout << m.size() << std::endl;
	std::cout << m.capacity() << std::endl;

	for (ft::vector<int>::iterator it = m.begin(); it != m.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;


	return (0);
}

void	test_const_iterator_operat(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::vector<int>		vec;
	vec.push_back(3);
	vec.push_back(4);

	ft::vector<int>::iterator		it = vec.begin();
	ft::vector<int>::iterator		it_t = vec.begin();

	std::cout << *it_t << std::endl;
	if (it == it_t)
		std::cout << "==" << std::endl;
	if (it != it_t)
		std::cout << "!=" << std::endl;
	if (it < it_t)
		std::cout << "<" << std::endl;
	if (it <= it_t)
		std::cout << "<=" << std::endl;
	if (it > it_t)
		std::cout << ">" << std::endl;
	if (it >= it_t)
		std::cout << ">=" << std::endl;

	++it_t;

	std::cout << *it_t << std::endl;
	if (it == it_t)
		std::cout << "==" << std::endl;
	if (it != it_t)
		std::cout << "!=" << std::endl;
	if (it < it_t)
		std::cout << "<" << std::endl;
	if (it <= it_t)
		std::cout << "<=" << std::endl;
	if (it > it_t)
		std::cout << ">" << std::endl;
	if (it >= it_t)
		std::cout << ">=" << std::endl;

	ft::vector<int>::const_iterator	it_c = vec.begin();

	std::cout << *it_c << std::endl;
	if (it == it_c)
		std::cout << "==" << std::endl;
	if (it != it_c)
		std::cout << "!=" << std::endl;
	if (it < it_c)
		std::cout << "<" << std::endl;
	if (it <= it_c)
		std::cout << "<=" << std::endl;
	if (it > it_c)
		std::cout << ">" << std::endl;
	if (it >= it_c)
		std::cout << ">=" << std::endl;

	++it_c;
	std::cout << *it_c << std::endl;
	if (it == it_c)
		std::cout << "==" << std::endl;
	if (it != it_c)
		std::cout << "!=" << std::endl;
	if (it < it_c)
		std::cout << "<" << std::endl;
	if (it <= it_c)
		std::cout << "<=" << std::endl;
	if (it > it_c)
		std::cout << ">" << std::endl;
	if (it >= it_c)
		std::cout << ">=" << std::endl;

	it = vec.begin();
	it_c = it;

	std::cout << *it_c << std::endl;
}
void	test_operator_comp(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	ft::vector<int> myvector_2;
	for (int i=1; i<=4; i++) myvector_2.push_back(i);
	myvector_2.push_back(8);

	if (myvector == myvector_2)
		std::cout << "vector ==" << std::endl;
	if (myvector != myvector_2)
		std::cout << "vector !=" << std::endl;
	if (myvector < myvector_2)
		std::cout << "vector <" << std::endl;
	if (myvector <= myvector_2)
		std::cout << "vector <=" << std::endl;
	if (myvector > myvector_2)
		std::cout << "vector >" << std::endl;
	if (myvector >= myvector_2)
		std::cout << "vector >=" << std::endl;

	myvector_2.clear();
	for (int i=1; i<=5; i++) myvector_2.push_back(i);

	if (myvector == myvector_2)
		std::cout << "vector ==" << std::endl;
	if (myvector != myvector_2)
		std::cout << "vector !=" << std::endl;
	if (myvector < myvector_2)
		std::cout << "vector <" << std::endl;
	if (myvector <= myvector_2)
		std::cout << "vector <=" << std::endl;
	if (myvector > myvector_2)
		std::cout << "vector >" << std::endl;
	if (myvector >= myvector_2)
		std::cout << "vector >=" << std::endl;
}

void	test_const_iterator(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::vector<int> myvector;

	for (int i=1; i<=5; i++) myvector.push_back(i);

  	std::cout << "myvector contains:";
  	for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
  	  std::cout << ' ' << *it;
  	std::cout << '\n';

	ft::vector<int>::const_iterator	c_it = myvector.begin();
	ft::vector<int>::iterator		it = myvector.begin();
	//ft::vector<int>::reverse_iterator	r_it = myvector.rbegin();
	//ft::vector<int>::reverse_iterator	r_it_e = myvector.rend();
	
	if (c_it == it)
		std::cout << "no" << std::endl;
	if (++c_it < it)
		std::cout << "no" << std::endl;

	std::cout << "const iterator.begin = " << *c_it << std::endl;
	//*c_it = 3;
}

void	test_revers_iterator(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::vector<int>	v;

	for (int i=1; i<=10; i++) v.push_back(i);

	ft::vector<int>::reverse_iterator	r_b = v.rbegin();
	ft::vector<int>::reverse_iterator	r_e = v.rend();

	std::cout << std::endl;
	std::cout << *(r_e - 1) << std::endl;
	std::cout << *r_b << std::endl;
	std::cout << *r_b++ << std::endl;
	std::cout << *++r_b << std::endl;
	std::cout << *r_b-- << std::endl;
	std::cout << *--r_b << std::endl;
	std::cout << *(r_b + 2) << std::endl;
	std::cout << *(r_b + 3) << std::endl;
	r_b += 4;
	std::cout << *r_b << std::endl;
	std::cout << *(r_b - 2) << std::endl;
	std::cout << *(r_b - 3) << std::endl;
	r_b -= 3;
	std::cout << *r_b << std::endl;
	std::cout << r_b[4] << std::endl;
	std::cout << *r_b << std::endl;
	ft::vector<int>::iterator	rom = r_b.base();
	r_b += 4;
	std::cout << *rom << std::endl;

	if (r_b == r_e)
		std::cout << "error: r_b = r_e" << std::endl;
	if (r_b + 5 == r_e)
		std::cout << "success: r_b = r_e" << std::endl;
	if (r_b + 4 != r_e)
		std::cout << "success: r_b != r_e" << std::endl;
	if (r_b < r_e)
		std::cout << "success" << std::endl;
	if (r_b > r_e)
		std::cout << "success" << std::endl;
	if (r_b <= r_e)
		std::cout << "success" << std::endl;
	if (r_b >= r_e)
		std::cout << "success" << std::endl;
}

void	test_get_alloc(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::vector<int> myvector;
	int * p;
  	unsigned int i;

  	// allocate an array with space for 5 elements using vector's allocator:
  	p = myvector.get_allocator().allocate(5);

  	// construct values in-place on the array:
  	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

  	std::cout << "The allocated array contains:";
  	for (i=0; i<5; i++) std::cout << ' ' << p[i];
  	std::cout << '\n';

  	// destroy and deallocate:
  	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
  	myvector.get_allocator().deallocate(p,5);
}

void	test_clear(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::vector<int> myvector;
	myvector.push_back (100);
  	myvector.push_back (200);
  	myvector.push_back (300);

	std::cout << "size = " << myvector.size() << std::endl;
	std::cout << "capacity = " << myvector.capacity() << std::endl;

  	std::cout << "myvector contains:";
  	for (unsigned i=0; i<myvector.size(); i++)
  	  std::cout << ' ' << myvector[i];
  	std::cout << '\n';

  	myvector.clear();
  	myvector.push_back (1101);
  	myvector.push_back (2202);

	std::cout << "size = " << myvector.size() << std::endl;
	std::cout << "capacity = " << myvector.capacity() << std::endl;

  	std::cout << "myvector contains:";
  	for (unsigned i=0; i<myvector.size(); i++)
  	  std::cout << ' ' << myvector[i];
  	std::cout << '\n';
}

void	test_swap(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200

  	foo.swap(bar);

  	std::cout << "foo contains:";
  	for (unsigned i=0; i<foo.size(); i++)
  	  std::cout << ' ' << foo[i];
  	std::cout << '\n';

  	std::cout << "bar contains:";
  	for (unsigned i=0; i<bar.size(); i++)
  	  std::cout << ' ' << bar[i];
  	std::cout << '\n';
}

void	test_erase_2(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	
	ft::vector<int>::iterator	it;

	ft::vector<int> first;

	// set some values (from 1 to 10)
  	for (int i=1; i<=10; i++) first.push_back(i);

	std::cout << "size = " << first.size() << std::endl;
	std::cout << "capacity = " << first.capacity() << std::endl;

	std::cout << std::endl << "erase" << std::endl;
  	// erase the 6th element
  	it = first.erase (first.begin(), first.begin()+7);

	std::cout << std::endl << "return = " << *it << std::endl;

	std::cout << "size = " << first.size() << std::endl;
	std::cout << "capacity = " << first.capacity() << std::endl;

	std::cout << std::endl;
  	for (unsigned i=0; i<first.size(); ++i)
  	  std::cout << ' ' << first[i];
  	std::cout << '\n';
}

void	test_erase_1(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	
	ft::vector<int>::iterator	it;

	ft::vector<int> first;

	// set some values (from 1 to 10)
  	for (int i=1; i<=10; i++) first.push_back(i);

	std::cout << "size = " << first.size() << std::endl;
	std::cout << "capacity = " << first.capacity() << std::endl;

	std::cout << std::endl << "erase" << std::endl;
  	// erase the 6th element
  	it = first.erase (first.begin()+5);

	std::cout << std::endl << "return = " << *it << std::endl;

	std::cout << "size = " << first.size() << std::endl;
	std::cout << "capacity = " << first.capacity() << std::endl;

  	// erase the first 3 elements:
  	//first.erase (myvector.begin(),myvector.begin()+3);

	std::cout << std::endl;
  	for (unsigned i=0; i<first.size(); ++i)
  	  std::cout << ' ' << first[i];
  	std::cout << '\n';
}

void	test_insert_6(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::vector<int> first;

	first.push_back(23);
	first.push_back(3);
	first.push_back(4);
	first.push_back(2);
	first.push_back(34);

	std::cout << "size = " << first.size() << std::endl;
	std::cout << "capacity = " << first.capacity() << std::endl;

	ft::vector<int>::iterator	c_b = first.begin();
	ft::vector<int>::iterator	c_e = first.end();

	while (c_b != c_e)
		std::cout << " " << *c_b++;
	std::cout << std::endl;

	ft::vector<int> second(3,56);

	std::cout << std::endl << "insert" << std::endl;
	first.insert(first.begin() + 1, second.begin() + 1, second.end());

	std::cout << std::endl;
	std::cout << "first.size = " << first.size() << std::endl;
	std::cout << "first.capacity = " << first.capacity() << std::endl;

	c_b = first.begin();
	c_e = first.end();
	while (c_b != c_e)
		std::cout << " " << *c_b++;
	std::cout << std::endl;
}

void	test_insert_5(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::vector<int> first;

	first.push_back(23);
	first.push_back(3);
	first.push_back(4);
	first.push_back(2);
	first.push_back(34);
	first.push_back(134);

	std::cout << "size = " << first.size() << std::endl;
	std::cout << "capacity = " << first.capacity() << std::endl;

	ft::vector<int>::iterator	c_b = first.begin();
	ft::vector<int>::iterator	c_e = first.end();

	while (c_b != c_e)
		std::cout << " " << *c_b++;
	std::cout << std::endl;

	ft::vector<int> second(3,56);

	std::cout << std::endl;
	std::cout << "second.size = " << second.size() << std::endl;
	std::cout << "second.capacity = " << second.capacity() << std::endl;

	std::cout << std::endl << "insert" << std::endl;
	second.insert(second.begin() + 1, first.begin(), first.end());

	std::cout << std::endl;
	std::cout << "second.size = " << second.size() << std::endl;
	std::cout << "second.capacity = " << second.capacity() << std::endl;

	c_b = second.begin();
	c_e = second.end();
	while (c_b != c_e)
		std::cout << " " << *c_b++;
	std::cout << std::endl;
}

void	test_insert_4(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::vector<int> first;

	first.push_back(23);
	first.push_back(3);
	first.push_back(4);
	first.push_back(2);
	first.push_back(34);

	std::cout << "size = " << first.size() << std::endl;
	std::cout << "capacity = " << first.capacity() << std::endl;

	ft::vector<int>::iterator	c_b = first.begin();
	ft::vector<int>::iterator	c_e = first.end();

	while (c_b != c_e)
		std::cout << " " << *c_b++;
	std::cout << std::endl;

	first.insert(first.begin() + 2, 23, 99);

	std::cout << std::endl;
	std::cout << "size = " << first.size() << std::endl;
	std::cout << "capacity = " << first.capacity() << std::endl;

	c_b = first.begin();
	c_e = first.end();
	while (c_b != c_e)
		std::cout << " " << *c_b++;
	std::cout << std::endl;
}

void	test_insert_3(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::vector<int> first(3, 100);

	std::vector<int>::iterator it;

	std::cout << "size = " << first.size() << std::endl;
	std::cout << "capacity = " << first.capacity() << std::endl;

	ft::vector<int>::iterator	c_b = first.begin();
	ft::vector<int>::iterator	c_e = first.end();

	while (c_b != c_e)
		std::cout << " " << *c_b++;
	std::cout << std::endl;

	first.insert (first.begin() + 1,2,300);

	std::cout << std::endl;
	std::cout << "size = " << first.size() << std::endl;
	std::cout << "capacity = " << first.capacity() << std::endl;

	c_b = first.begin();
	c_e = first.end();
	while (c_b != c_e)
		std::cout << " " << *c_b++;
	std::cout << std::endl;
}

void	test_insert_2(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::vector<int> first;

	first.push_back(23);
	first.push_back(3);
	first.push_back(4);
	first.push_back(2);
	first.push_back(34);

	std::cout << "size = " << first.size() << std::endl;
	std::cout << "capacity = " << first.capacity() << std::endl;

	ft::vector<int>::iterator	c_b = first.begin();
	ft::vector<int>::iterator	c_e = first.end();

	while (c_b != c_e)
		std::cout << " " << *c_b++;
	std::cout << std::endl;

	ft::vector<int>::iterator	nw;

	nw = first.insert(first.begin() + 2, 10);

	std::cout << std::endl;
	std::cout << "new position = " << *nw << std::endl;

	std::cout << std::endl;
	std::cout << "size = " << first.size() << std::endl;
	std::cout << "capacity = " << first.capacity() << std::endl;

	c_b = first.begin();
	c_e = first.end();
	while (c_b != c_e)
		std::cout << " " << *c_b++;
	std::cout << std::endl;
}

void	test_insert_1(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::vector<int> first(5, 43);

	std::cout << "size = " << first.size() << std::endl;
	std::cout << "capacity = " << first.capacity() << std::endl;

	ft::vector<int>::iterator	c_b = first.begin();
	ft::vector<int>::iterator	c_e = first.end();

	while (c_b != c_e)
		std::cout << " " << *c_b++;
	std::cout << std::endl;

	ft::vector<int>::iterator	nw = first.insert(first.begin() + 1, 300);

	std::cout << std::endl;
	std::cout << "new position = " << *nw << std::endl;

	std::cout << std::endl;
	std::cout << "size = " << first.size() << std::endl;
	std::cout << "capacity = " << first.capacity() << std::endl;

	c_b = first.begin();
	c_e = first.end();
	while (c_b != c_e)
		std::cout << " " << *c_b++;
	std::cout << std::endl;
}

void	test_assign(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::vector<int> first;

	first.push_back(23);
	first.push_back(2);
	first.push_back(4);
	first.push_back(5);
	first.push_back(56);

	ft::vector<int>::iterator	c_b = first.begin();
	ft::vector<int>::iterator	c_e = first.end();

	while (c_b != c_e)
		std::cout << " " << *c_b++;
	std::cout << std::endl;


	std::cout << std::endl;
	std::cout << "SECOND TEST" << std::endl;

	ft::vector<int> second;

	c_b = first.begin() + 1;

	second.assign(c_b, first.end() - 1);

	c_b = second.begin();
	c_e = second.end();

	while (c_b != c_e)
		std::cout << " " << *c_b++;
	std::cout << std::endl;

	std::cout << "size = " << first.size() << std::endl;
	std::cout << "capacity = " << first.capacity() << std::endl;
	std::cout << "size = " << second.size() << std::endl;
	std::cout << "capacity = " << second.capacity() << std::endl;


	std::cout << std::endl;
	std::cout << "FIRST TEST" << std::endl;

	first.assign(3, 23);

	c_b = first.begin();
	c_e = first.end();

	while (c_b != c_e)
		std::cout << " " << *c_b++;
	std::cout << std::endl;

	std::cout << "size = " << first.size() << std::endl;
	std::cout << "capacity = " << first.capacity() << std::endl;
}

void	test_constructor_1(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::vector<std::string>::iterator	it_i;
	ft::vector<std::string>::iterator	end_;

	ft::vector<std::string> foo (3, "hello");

	ft::vector<std::string> bar (5, "fix");

  	bar = foo;
  	foo = ft::vector<std::string>();

  	std::cout << "Size of foo: " << int(foo.size()) << '\n';
  	std::cout << "Size of bar: " << int(bar.size()) << '\n';
  	std::cout << "capacity of foo: " << int(foo.capacity()) << '\n';
  	std::cout << "capacity of bar: " << int(bar.capacity()) << '\n';

	it_i = foo.begin();
	end_ = foo.end();

	while (it_i != end_)
		std::cout << " " << *it_i++;
	std::cout << std::endl;

	it_i = bar.begin();
	end_ = bar.end();

	while (it_i != end_)
		std::cout << " " << *it_i++;
	std::cout << std::endl;
}

void	test_at(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	try
	{
		ft::vector<int>				v(10);

		v.at(23) = 100;
	}
	catch (const std::out_of_range & orr)
	{
		std::cout << "out_of_range: " << orr.what() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << "exceptiron: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "..." << std::endl;
	}
}

void	test_reserve(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

    ft::vector<int>				v;

	v.reserve(10);

	v.push_back(32);
	v.push_back(85);
	v.push_back(12);
	v.push_back(-23);
	v.push_back(12);

	ft::vector<int>::iterator	it_i = v.begin();
	ft::vector<int>::iterator	end_ = v.end();

	while (it_i != end_)
		std::cout << " " << *it_i++;

	std::cout << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	std::cout << "capacity = " << v.capacity() << std::endl;

	v.reserve(5);
	std::cout << "size = " << v.size() << std::endl;
	std::cout << "capacity = " << v.capacity() << std::endl;

	v.reserve(20);

	it_i = v.begin();
	end_ = v.end();

	while (it_i != end_)
		std::cout << " " << *it_i++;

	std::cout << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	std::cout << "capacity = " << v.capacity() << std::endl;

	return;
}

void	test_resize(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	{
    ft::vector<int>				v;

	v.push_back(32);
	v.push_back(85);
	v.push_back(12);
	v.push_back(-23);
	v.push_back(12);

	ft::vector<int>::iterator	it_i = v.begin();
	ft::vector<int>::iterator	end_ = v.end();

	while (it_i != end_)
		std::cout << " " << *it_i++;

	std::cout << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	std::cout << "capacity = " << v.capacity() << std::endl;

	v.resize(3);

	it_i = v.begin();
	end_ = v.end();

	while (it_i != end_)
		std::cout << " " << *it_i++;

	std::cout << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	std::cout << "capacity = " << v.capacity() << std::endl;
	}
	
	{
    ft::vector<int>				v;

	v.push_back(32);
	v.push_back(85);
	v.push_back(12);
	v.push_back(-23);
	v.push_back(12);

	ft::vector<int>::iterator	it_i = v.begin();
	ft::vector<int>::iterator	end_ = v.end();

	while (it_i != end_)
		std::cout << " " << *it_i++;

	std::cout << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	std::cout << "capacity = " << v.capacity() << std::endl;

	v.resize(3,4);

	std::cout << std::endl;
	it_i = v.begin();
	end_ = v.end();
	while (it_i != end_)
		std::cout << " " << *it_i++;
	std::cout << std::endl;

	v.resize(18, 23);

	it_i = v.begin();
	end_ = v.end();

	while (it_i != end_)
		std::cout << " " << *it_i++;

	std::cout << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	std::cout << "capacity = " << v.capacity() << std::endl;

	v.resize(50);

	it_i = v.begin();
	end_ = v.end();

	while (it_i != end_)
		std::cout << " " << *it_i++;

	std::cout << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	std::cout << "capacity = " << v.capacity() << std::endl;
	}
}

void	test_constructor(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::vector<int>		second(3);

	std::cout << "size = " << second.size() << std::endl;
	std::cout << "capacity = " << second.capacity() << std::endl;

	second.push_back(32);

	std::cout << "size = " << second.size() << std::endl;
	std::cout << "capacity = " << second.capacity() << std::endl;

	ft::vector<int>::iterator	it = second.begin();
	ft::vector<int>::iterator	end = second.end();
	while (it != end)
	{
		std::cout << "it = " << *it << std::endl;
		++it;
	}
}

void	test_constructor_2(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

	ft::vector<std::string>		second(3, "lol");

	std::cout << "size = " << second.size() << std::endl;
	std::cout << "capacity = " << second.capacity() << std::endl;

	second.push_back("kek");

	std::cout << "size = " << second.size() << std::endl;
	std::cout << "capacity = " << second.capacity() << std::endl;

	ft::vector<std::string>::iterator	it = second.begin();
	ft::vector<std::string>::iterator	end = second.end();

	while (it != end)
	{
		std::cout << "it = " << *it << std::endl;
		++it;
	}

	std::cout << std::endl;
	std::cout << COLO << "TEST consturct begin end" << NO_C << std::endl;

	ft::vector<int>				sec(9, 34);
	ft::vector<int>				third(sec.begin(), sec.end());

	std::cout << "size = " << third.size() << std::endl;
	std::cout << "capacity = " << third.capacity() << std::endl;

	ft::vector<int>::iterator	it_i = third.begin();
	ft::vector<int>::iterator	end_ = third.end();

	while (it_i != end_)
	{
		std::cout << "it = " << *it_i << std::endl;
		++it_i;
	}

}

void	test_capac_size(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

    ft::vector<int>				v;

	std::cout << "TEST capacity size" << std::endl;
    std::cout << "max_size = " << v.max_size() << std::endl;
	std::cout << "capacity = " << v.capacity() << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	v.push_back(32);
	std::cout << "capacity = " << v.capacity() << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	v.push_back(85);
	std::cout << "capacity = " << v.capacity() << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	v.push_back(12);
	std::cout << "capacity = " << v.capacity() << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	v.push_back(-23);
	std::cout << "capacity = " << v.capacity() << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	v.push_back(1433);
	std::cout << "capacity = " << v.capacity() << std::endl;
	std::cout << "size = " << v.size() << std::endl;
}

void	test_iterator_inc_decr(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif

    ft::vector<int>				v;
	v.push_back(32);
	v.push_back(85);
	v.push_back(12);
	v.push_back(-23);
	v.push_back(1433);

	ft::vector<int>::iterator	it;
	ft::vector<int>::iterator	en;
	it = v.begin();
	++it;
	std::cout << "increment test" << std::endl;
	std::cout << *it << std::endl;
	std::cout << *(++it) << std::endl;
	std::cout << *it << std::endl;
	std::cout << *(--it) << std::endl;
	std::cout << *it << std::endl;
	std::cout << *it-- << std::endl;
	std::cout << *it << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << *it << std::endl;

	it = v.begin();
	en = v.end();

	while (it != en)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	test_operator(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
    ft::vector<int>				v;
	ft::vector<int>::iterator	it;

	v.push_back(32);
	v.push_back(85);
	v.push_back(12);
	v.push_back(-23);
	v.push_back(1433);

	std::cout << "TEST a + n" << std::endl;
	it = v.begin();
	std::cout << *it << std::endl;
	std::cout << *(it + 2) << std::endl;
	std::cout << *(it + 1) << std::endl;

	it = it + 3;
	std::cout << "TEST a - n" << std::endl;
	std::cout << *(it - 2) << std::endl;
	std::cout << *(it - 1) << std::endl;
	it = it - 1;
	std::cout << *it << std::endl;
	
	std::cout << "TEST a - b" << std::endl;
	ft::vector<int>::iterator	ts;
	it = v.begin();
	ts = it;
	ts = ts + 2;
	std::cout << ts - it << std::endl;

	std::cout << "TEST a < b" << std::endl;
	if (ts < it)
		std::cout << "ts < it" << std::endl;
	else
		std::cout << "ts > it" << std::endl;

	std::cout << "TEST a > b" << std::endl;
	if (ts > it)
		std::cout << "ts > it" << std::endl;
	else
		std::cout << "ts < it" << std::endl;

	std::cout << "TEST a <= b" << std::endl;
	if (it <= it + 1)
		std::cout << "it <= it" << std::endl;
	else
		std::cout << "it >= it" << std::endl;

	std::cout << "TEST a <= b" << std::endl;
	if (ts <= it)
		std::cout << "ts <= it" << std::endl;
	else
		std::cout << "ts >= it" << std::endl;

	std::cout << "TEST a >= b" << std::endl;
	if (it >= it + 1)
		std::cout << "it >= it" << std::endl;
	else
		std::cout << "it >= it" << std::endl;

	std::cout << "TEST a >= b" << std::endl;
	if (ts >= it)
		std::cout << "ts >= it" << std::endl;
	else
		std::cout << "ts >= it" << std::endl;

	std::cout << "TEST a += n" << std::endl;
	it = v.begin();
	it += 3;
	std::cout << *it << std::endl;

	std::cout << "TEST a -= n" << std::endl;
	it = v.begin();
	it = it + 3;
	it -= 2;
	std::cout << *it << std::endl;
	std::cout << std::endl;

	std::cout << "TEST a[n]" << std::endl;
	std::cout << "it[0] = " << it[0] << std::endl;
	std::cout << "it[1] = " << it[1] << std::endl;
	std::cout << std::endl;
}

void	test_front_back(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
    ft::vector<int>				v;

	v.push_back(32);
	v.push_back(85);
	v.push_back(12);
	v.push_back(-23);
	v.push_back(1433);

	std::cout << "TEST v.front()" << std::endl;
	std::cout << v.front() << std::endl;
	ft::vector<int>		v_f;
	std::cout << &v_f.front() << std::endl;
	std::cout << std::endl;

	std::cout << "TEST v.back()" << std::endl;
	std::cout << v.back() << std::endl;
	ft::vector<int>		v_b;
	std::cout << &v_b.back() << std::endl;
}

void	test_oper_qr(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
    ft::vector<int>				v;
	ft::vector<int>::iterator	it;

	v.push_back(32);
	v.push_back(85);
	v.push_back(12);
	v.push_back(-23);
	v.push_back(1433);

	std::cout << "TEST v[]" << std::endl;
	std::cout << "v[0] = " << v[0] << std::endl;
	v[0] = 43;
	std::cout << "v[0] = " << v[0] << std::endl;
	std::cout << std::endl;
}

void	test_point_allocat(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
    ft::vector<int>				v;
	ft::vector<int>::iterator	it;

	v.push_back(12);
	std::cout << &v.front() << std::endl;
	v.push_back(-23);
	std::cout << &v.front() << std::endl;
	v.push_back(1433);
	std::cout << &v.front() << std::endl;
	v.push_back(32);
	std::cout << &v.front() << std::endl;
	v.push_back(85);
	std::cout << &v.front() << std::endl;
	v.push_back(12);
	std::cout << &v.front() << std::endl;
	v.push_back(-23);
	std::cout << &v.front() << std::endl;
	v.push_back(12);
	std::cout << &v.front() << std::endl;
	v.push_back(-23);
	std::cout << &v.front() << std::endl;
	v.push_back(1433);
	std::cout << &v.front() << std::endl;
	v.push_back(32);
	std::cout << &v.front() << std::endl;
	v.push_back(85);
	std::cout << &v.front() << std::endl;
	v.push_back(12);
	std::cout << &v.front() << std::endl;
	v.push_back(-23);
	std::cout << &v.front() << std::endl;
	v.push_back(1433);
	std::cout << &v.front() << std::endl;
	v.push_back(12);
	std::cout << &v.front() << std::endl;
	v.push_back(-23);
	std::cout << &v.front() << std::endl;
	v.push_back(1433);
	std::cout << &v.front() << std::endl;
}

void	test_pop_back(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
    ft::vector<int>				v;
	ft::vector<int>::iterator	it;
	std::cout << std::endl;
	v.push_back(32);
	std::cout << "size = " << v.size() << std::endl;
	std::cout << "capacity = " << v.capacity() << std::endl;
	std::vector<int>::reference	i = v.front();
	std::cout << "i = " << i << std::endl;
	//std::cout << &v.front() << std::endl;
	v.pop_back();
	std::cout << "v.front = " << v.front() << std::endl;
	std::cout << "v.back = " << v.back() << std::endl;
	std::cout << "i = " << i << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	std::cout << "capacity = " << v.capacity() << std::endl;
}
