#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <ostream>
# include <stdexcept>

class Bureaucrat {
	const std::string _name;
	double _grade;
public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &o);
	~Bureaucrat(void);

	Bureaucrat&			operator= (const Bureaucrat&);
	Bureaucrat&			operator= (int);
	Bureaucrat&			operator++(void);
	Bureaucrat			operator++(int);
	Bureaucrat&			operator--(void);
	Bureaucrat			operator--(int);

	const std::string	getName(void) const;
	int					getGrade(void) const;

	class GradeTooLowException : public std::exception {
	public:
		GradeTooLowException(void);
		GradeTooLowException(const GradeTooLowException&);
		virtual ~GradeTooLowException(void) throw();
		GradeTooLowException	&operator= (const GradeTooLowException&);
		virtual const char		*msg() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(void);
		GradeTooHighException(const GradeTooHighException &src);
		virtual ~GradeTooHighException(void) throw();
		GradeTooHighException	&operator= (const GradeTooHighException&);
		virtual const char		*msg() const throw();
	};
};
std::ostream&	operator<<(std::ostream &o, const Bureaucrat &b);

#endif
