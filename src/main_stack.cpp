#include <stack>
#include <vector>
#include <iostream>
#include <sys/time.h>
#include "stack.hpp"

#define	COLO "\033[1;44;1m"
#define NO_C "\033[0m"
#define FIL "\033[1;48;5;55m"

void	test_constructor(const std::string& promo);
void	test_empty(const std::string& promo);
void	test_size(const std::string& promo);
void	test_top(const std::string& promo);
void	test_push_pop(const std::string& promo);
void	test_operator(const std::string& promo);

int				main( void )
{
#ifdef FT
    std::cout << COLO << "FT" << NO_C << std::endl;
#else
    std::cout << COLO << "STD" << NO_C << std::endl;
	namespace	ft = std;
#endif
	struct timeval	time_now;
	gettimeofday(&time_now,nullptr);
	time_t msecs_time = (time_now.tv_sec % 100) * 1000000000 + time_now.tv_usec;

	test_constructor("CONSTRUCT");
	test_empty("EMPTY");
	test_size("SIZE");
	test_top("TOP");
	test_push_pop("PUSH POP");
	test_operator("OPERATOR");

	std::cout << "end main" << std::endl;
	gettimeofday(&time_now,nullptr);
	time_t msecs_end = (time_now.tv_sec % 100) * 1000000000 + time_now.tv_usec;
#ifdef FT
    std::cout << COLO << "FT";
	std::cout << "	time: "  << msecs_end - msecs_time << NO_C << std::endl << std::endl;
#else
    std::cout << COLO << "STD";
	std::cout << "	time: "  << msecs_end - msecs_time << NO_C << std::endl << std::endl;
#endif
	return (0);
}
void	test_operator(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::stack<int> mystack;
	for (int i=0; i<5; ++i) mystack.push(i);
	
	ft::stack<int> mi;
	for (int i=0; i<5; ++i) mi.push(i);
	mi.pop();

	if (mi == mystack)
		std::cout << "==" << std::endl;
	if (mi != mystack)
		std::cout << "!=" << std::endl;
	if (mi < mystack)
		std::cout << "<" << std::endl;
	if (mi <= mystack)
		std::cout << "<=" << std::endl;
	if (mi > mystack)
		std::cout << ">" << std::endl;
	if (mi >= mystack)
		std::cout << ">=" << std::endl;
}
void	test_push_pop(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::stack<int> mystack;

	for (int i=0; i<5; ++i) mystack.push(i);
	
	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
	   std::cout << ' ' << mystack.top();
	   mystack.pop();
	}
	std::cout << '\n';
}
void	test_top(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::stack<int> mystack;
	mystack.push(10);
	mystack.push(20);
	mystack.top() -= 5;
	std::cout << "mystack.top() is now " << mystack.top() << '\n';
}
void	test_size(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

  	for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

  	myints.pop();
  	std::cout << "2. size: " << myints.size() << '\n';
}
void	test_empty(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	ft::stack<int> mystack;
	int sum (0);

  	for (int i=1;i<=10;i++) mystack.push(i);

  	while (!mystack.empty())
  	{
  	   sum += mystack.top();
  	   mystack.pop();
  	}
	std::cout << "total: " << sum << '\n';	
}
void	test_constructor(const std::string& promo)
{
#ifndef FT
	namespace	ft = std;
	std::cout << FIL << "STD " << promo << NO_C << std::endl;
#else
	std::cout << FIL << "FT " << promo << NO_C << std::endl;
#endif
	std::deque<int> mydeque (3,100);          // deque with 3 elements
	ft::vector<int> myvector (2,200);        // vector with 2 elements
	
	ft::stack<int> first;                    // empty stack
	
	ft::stack<int,ft::vector<int> > third;  // empty stack using vector
	ft::stack<int,ft::vector<int> > fourth (myvector);
	
	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';
}
