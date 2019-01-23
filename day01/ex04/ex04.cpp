#include <string>
#include <iostream>

int main(void) {
	std::string s = "HI THIS IS BRAIN";
	std::string *pointer = &s;
	std::string &reference = s;
	std::cout << *pointer << std::endl << reference << std::endl;
	return (0);
}
