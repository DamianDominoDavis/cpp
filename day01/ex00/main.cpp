#include <iostream>
#include "Pony.cpp"

int main(void)
{
	Pony *p = new Pony();
	std::cout << Pony::motto() << "\n";
	delete p;
	return (0);
}
