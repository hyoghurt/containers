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
void	test_constructor();
void	test_constructor_1();
void	test_constructor_2();
void	test_resize();
void	test_reserve();
void	test_at();
void	test_assign();
void	test_insert_1();
void	test_insert_2();


int				main( void )
{
#ifdef FT
    std::cout << COLO << "FT" << NO_C << std::endl;
#else
    std::cout << COLO << "STD" << NO_C << std::endl;
	namespace	ft = std;
#endif
	//ERRRROR	vector<int>	v(3, 3);

	//test_capac_size();
	//test_iterator_inc_decr();
	//test_operator();
	//test_front_back();
	//test_oper_qr(); //operator v[]
	//test_point_allocat();
	//test_pop_back();
	//test_constructor();
	//test_constructor_1();
	//test_constructor_2();
	//test_resize();
	//test_reserve();
	//test_at();
	//test_assign();
	test_insert_1();
	test_insert_2();


	return (0);
}

void	test_insert_2()
{
	std::cout << std::endl;
	std::cout << "TEST INSERT 2" << std::endl;

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

	ft::vector<int>::iterator	nw = first.insert(++first.begin(), 10);

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

void	test_insert_1()
{
	std::cout << "TEST ONE" << std::endl;

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

void	test_assign()
{
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

void	test_constructor_1()
{
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

void	test_at()
{
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

void	test_reserve()
{
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

void	test_resize()
{
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

void	test_constructor()
{
	std::cout << std::endl;
	std::cout << COLO << "TEST consturct" << NO_C << std::endl;

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

void	test_constructor_2()
{
	std::cout << std::endl;
	std::cout << COLO << "TEST consturct" << NO_C << std::endl;

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
	size_t	abi = 2;
	it = abi + it;
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
