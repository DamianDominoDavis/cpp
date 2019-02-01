#include <cstddef>
#include <iostream>

template <typename T, typename F> void iter(T *arr, size_t len, F f) {
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

void	rint(int &a) { a = rand() % 100; }
void	logint(int a) { std::cout << a << ' '; }
void	rch(char &a) { a = 'a' + rand() % 26; }
void	logch(char a) { std::cout << a; }

int main(void) {
	int	is[10];
	iter(is, 10, rint);
	iter(is, 10, logint);
	std::cout << std::endl;

	iter(is, 10, rint);
	iter(is, 10, logint);
	std::cout << std::endl << std::endl;

	char cs[10];
	iter(cs, 10, rch);
	iter(cs, 10, logch);
	std::cout << std::endl;
	
	iter(cs, 10, rch);
	iter(cs, 10, logch);
	std::cout << std::endl;
	return (0);
}
