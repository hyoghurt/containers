clang++ src/main.cpp -Iinclude -std=c++98 -o test
./test > std.log
clang++ src/main.cpp -Iinclude -std=c++98 -D FT -o test
./test > my.log
echo -e "\033[1;45;5;58m__TEST__                                                                               \033[0m"
diff -y --suppress-common-lines my.log std.log
##rm -rf my.log std.log test
rm -rf test
