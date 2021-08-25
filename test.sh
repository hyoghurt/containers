dir_test="src/main_stack.cpp"

clang++ $dir_test -Iinclude -std=c++98 -o test
./test > std.log
clang++ $dir_test -Iinclude -std=c++98 -D FT -o test
./test > my.log
echo -e "\033[1;45;5;58m__TEST__                                                                               \033[0m"
diff -y --suppress-common-lines my.log std.log
##rm -rf my.log std.log test
rm -rf test

clang++ $dir_test -Iinclude -std=c++98 -D FT -o mytest
