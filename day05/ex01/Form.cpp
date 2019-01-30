#include "Form.hpp"
#include <ostream>

Form::Form(void): _name("none"), _toSign(150), _toExec(150) {}
Form::Form(std::string n, int s, int e):
	_name(n), _signed(false), _toSign(s), _toExec(e) {
		if (s < 1 || e < 1 )
			throw GradeTooHighException();
		if (s > 150 || e > 150)
			throw GradeTooLowException();
	}
Form::Form(const Form &o): _name(o.name()), _signed(o.isSigned()),
	_toSign(o.toSign()), _toExec(o.toExec()) {
	*this = o;
}
Form::~Form(void) {}

std::string	Form::name(void) const { return (_name); }
bool		Form::isSigned(void) const { return (_signed); }
int			Form::toSign(void) const { return (_toSign); }
int			Form::toExec(void) const { return (_toExec); }

std::ostream&	operator<<(std::ostream &o, const Form &f) {
	return (o << f.name() << " (" << (f.isSigned() ? "signed) " : "unsigned) ")
		<< f.toSign() << "/" << f.toExec());
}
Form&		Form::operator= (const Form &o) {
	_signed = o.isSigned();
	return (*this);
}

void		Form::sign(const Bureaucrat &b) {
	if (b.getGrade() > _toSign)
		throw Bureaucrat::GradeTooLowException();
	_signed = true;
	std::cout << b << " signed " << *this << std::endl;
}

Form::GradeTooLowException::GradeTooLowException(void) {}
Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException &src) {
	*this = src;
}
Form::GradeTooLowException::~GradeTooLowException(void) throw() {}
Form::GradeTooLowException &Form::GradeTooLowException::operator= (const GradeTooLowException &rhs) {
	(void)rhs;
	return (*this);
}
const char *Form::GradeTooLowException::msg() const throw() {
	return ("Grade is too low...");
}

Form::GradeTooHighException::GradeTooHighException(void) {}
Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException &src) {
	*this = src;
}
Form::GradeTooHighException::~GradeTooHighException(void) throw() {}
Form::GradeTooHighException &Form::GradeTooHighException::operator= (const GradeTooHighException &rhs) {
	(void)rhs;
	return (*this);
}
const char *Form::GradeTooHighException::msg() const throw() {
	return ("Grade is too high...");
}
