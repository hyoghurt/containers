#include <vector>
#include <memory>
#include "vector.hpp"

#define	COLO "\033[1;44;1m"
#define NO_C "\033[0m"

void	test_capac_size();
void	test_iterator_inc_decr();
void	test_operator();
void	test_front_back();
void	test_oper_qr(); //operator v[]
void	test_point_allocat();
void	test_pop_back();

int				main( void )
{
#ifdef FT
    std::cout << COLO << "FT" << NO_C << std::endl;
#else
    std::cout << COLO << "STD" << NO_C << std::endl;
	namespace	ft = std;
#endif

	test_capac_size();
	test_iterator_inc_decr();
	test_operator();
	test_front_back();
	test_oper_qr(); //operator v[]
	//test_point_allocat();
	test_pop_back();

    ft::vector<int>				v;
	ft::vector<int>::iterator	it;

	v.push_back(32);
	v.push_back(85);
	v.push_back(12);
	v.push_back(-23);

	return (0);
}

void	test_capac_size(void)
{
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

void	test_iterator_inc_decr()
{
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

void	test_operator()
{
    ft::vector<int>				v;
	ft::vector<int>::iterator	it;

	v.push_back(32);
	v.push_back(85);
	v.push_back(12);
	v.push_back(-23);
	v.push_back(1433);

	std::cout << "TEST a + n" << std::endl;
	it = v.begin();
	it = it + 3;
	std::cout << *it << std::endl;
	/*
	std::cout << "TEST n + a" << std::endl;
	it = v.begin();
	it = 2 + it;
	std::cout << *it << std::endl;
	*/
	std::cout << "TEST a - n" << std::endl;
	it = it - 2;
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
	if (it <= it)
		std::cout << "it <= it" << std::endl;
	else
		std::cout << "it >= it" << std::endl;

	std::cout << "TEST a <= b" << std::endl;
	if (ts <= it)
		std::cout << "ts <= it" << std::endl;
	else
		std::cout << "ts >= it" << std::endl;

	std::cout << "TEST a >= b" << std::endl;
	if (it >= it)
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

void	test_front_back()
{
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

void	test_oper_qr()
{
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

void	test_point_allocat()
{
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

void	test_pop_back()
{
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
