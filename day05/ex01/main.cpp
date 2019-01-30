#include "Bureaucrat.hpp"

int main(void) {
	try {
		Form nope = Form("bad", -1, 1);
	}
	catch (Form::GradeTooHighException e) {
		std::cerr << e.msg() << std::endl;
	}
	Form f = Form("Official", 50, 100);
	std::cout << f << std::endl;
	Bureaucrat b = Bureaucrat("Hermes", 51);
	b.signForm(f);
	b++;
	b.signForm(f);
	return (0);
}
