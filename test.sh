#!/bin/bash

if [ ! -d 'log' ]; then
    mkdir log
fi

vector=true
map=true
stack=true

if [ -n "$1" ]
then
	flag=$1
	if [ $1 == "clear" ]
	then
		rm -rf log
		echo "delete log dir"
		exit 0
	elif [ $1 == "vector" ]
	then
		map=false
		stack=false
	elif [ $1 == "map" ]
	then
		vector=false
		stack=false
	elif [ $1 == "stack" ]
	then
		vector=false
		map=false
	else
		echo -e "\033[1;45;5;58mno found command (vector, map, stack, clear)\033[0m"
		exit 0
	fi
fi

##_____VECTOR
_main="src/main_vector.cpp"
_log="log/vector"

if $vector
then
clang++ $_main -Iinclude -std=c++98 -o test
./test > ${_log}'_std.log'
clang++ $_main -Iinclude -Wall -Wextra -Werror -std=c++98 -D FT -o test
./test > ${_log}'_my.log'
echo -e "\033[1;45;5;58m__TEST_VECTOR__                                                                         \033[0m"
diff -y --suppress-common-lines ${_log}'_my.log' ${_log}'_std.log'
rm -rf test
clang++ $_main -Iinclude -Wall -Wextra -Werror -std=c++98 -D FT -o ${_log}'_a.out'
fi

##_____MAP
_main="src/main_map.cpp"
_log="log/map"

if $map
then
clang++ $_main -Iinclude -std=c++98 -o test
./test > ${_log}'_std.log'
clang++ $_main -Iinclude -Wall -Wextra -Werror -std=c++98 -D FT -o test
./test > ${_log}'_my.log'
echo -e "\033[1;45;5;58m__TEST_MAP__                                                                         \033[0m"
diff -y --suppress-common-lines ${_log}'_my.log' ${_log}'_std.log'
rm -rf test
clang++ $_main -Iinclude -Wall -Wextra -Werror -std=c++98 -D FT -o ${_log}'_a.out'
fi

##_____STACK
_main="src/main_stack.cpp"
_log="log/stack"

if $stack
then
clang++ $_main -Iinclude -std=c++98 -o test
./test > ${_log}'_std.log'
clang++ $_main -Iinclude -Wall -Wextra -Werror -std=c++98 -D FT -o test
./test > ${_log}'_my.log'
echo -e "\033[1;45;5;58m__TEST_STACK__                                                                         \033[0m"
diff -y --suppress-common-lines ${_log}'_my.log' ${_log}'_std.log'
rm -rf test
clang++ $_main -Iinclude -Wall -Wextra -Werror -std=c++98 -D FT -o ${_log}'_a.out'
fi
