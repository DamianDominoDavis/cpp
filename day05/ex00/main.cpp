#include <iostream>
#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat b = Bureaucrat("Bom", 20);
	std::cout << b << std::endl;
	std::cout << ++b << std::endl;
	b = 1;
	std::cout << b << std::endl;
	try {
		std::cout << ++b << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException e) {
		std::cerr << e.msg() << std::endl;
	}
	b = Bureaucrat("discarded const", 150);
	std::cout << b << std::endl;
	try {
		std::cout << --b << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException e) {
		std::cerr << e.msg() << std::endl;
	}
	return (0);
}
