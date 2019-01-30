#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	const std::string	_name;
	bool				_signed;
	const int			_toSign;
	const int			_toExec;

public:
	Form(void);
	Form(std::string n, int s, int e);
	Form(const Form &o);
	~Form(void);

	Form&		operator= (const Form &o);
	std::string	name(void) const;

	bool		isSigned(void) const;
	int			toSign(void) const;
	int			toExec(void) const;

	void		sign(const Bureaucrat &b);

	class GradeTooLowException : public std::exception {
	public:
		GradeTooLowException(void);
		GradeTooLowException(const GradeTooLowException&);
		virtual ~GradeTooLowException(void) throw();
		GradeTooLowException	&operator= (const GradeTooLowException&);
		virtual const char		*msg() const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
		GradeTooHighException(void);
		GradeTooHighException(const GradeTooHighException &src);
		virtual ~GradeTooHighException(void) throw();
		GradeTooHighException	&operator= (const GradeTooHighException&);
		virtual const char		*msg() const throw();
	};
};
std::ostream&	operator<<(std::ostream &o, const Form &f);

#endif
