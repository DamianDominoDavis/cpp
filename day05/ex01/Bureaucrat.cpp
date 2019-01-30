#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):
	_name(""),
	_grade(150) {}
Bureaucrat::Bureaucrat(std::string name, int grade):
	_name(name),
	_grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade >150)
		throw GradeTooLowException();
	}
Bureaucrat::Bureaucrat(const Bureaucrat &o) {
	*this = o;
}
Bureaucrat::~Bureaucrat(void) {}

std::ostream&		operator<<(std::ostream &o, const Bureaucrat &b) {
	return (o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".");
}

Bureaucrat&			Bureaucrat::operator= (const Bureaucrat &o) {
	// _name = o.getName();
	_grade = o.getGrade();
	return (*this);
}
Bureaucrat&			Bureaucrat::operator= (int i) {
	// _name = o.getName();
	_grade = i;
	return (*this);
}
Bureaucrat&			Bureaucrat::operator++(void) {
	_grade--;
	if (_grade < 1) throw GradeTooHighException();
	return (*this);
}
Bureaucrat			Bureaucrat::operator++(int) {
	Bureaucrat pre = *this;
	++*this;
	if (_grade < 1) throw GradeTooHighException();
	return (pre);
}
Bureaucrat&			Bureaucrat::operator--(void) {
	_grade++;
	if (_grade >= 150) throw GradeTooLowException();
	return (*this);
}
Bureaucrat			Bureaucrat::operator--(int) {
	if (_grade >= 150) throw GradeTooLowException();
	Bureaucrat pre = *this;
	--*this;
	return (pre);
}

const std::string	Bureaucrat::getName(void) const { return (_name); }
int					Bureaucrat::getGrade(void) const { return (_grade); }

void				Bureaucrat::signForm(Form &f) {
	try{
		f.sign(*this);
	}
	catch (GradeTooLowException e) {
		std::cout << *this << " can't sign " << f << " because " << e.msg() << std::endl;
	}
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void) {}
Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException &src) {
	*this = src;
}
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}
Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator= (const GradeTooLowException &rhs) {
	(void)rhs;
	return (*this);
}
const char *Bureaucrat::GradeTooLowException::msg() const throw() {
	return ("Grade is too low...");
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) {}
Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException &src) {
	*this = src;
}
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}
Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator= (const GradeTooHighException &rhs) {
	(void)rhs;
	return (*this);
}
const char *Bureaucrat::GradeTooHighException::msg() const throw() {
	return ("Grade is too high...");
}
