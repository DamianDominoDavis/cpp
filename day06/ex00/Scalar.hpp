#ifndef SCALAR_HPP
# define SCALAR_HPP
# include <iostream>
# include <cstdlib>
# include <sstream>
# include <iomanip>

class Scalar {
	int			_asint;
	float		_asfloat;
	char		_to_char;
	std::string	_asstr;
	std::string	_strint;
	std::string	_strchar;
	std::string	_strdouble;
	std::string	_strfloat;

	void		init(void);

public:
	Scalar(const char*);
	~Scalar(void);
	Scalar(const Scalar&);
	Scalar& operator=(const Scalar&);

	int toInt(void);
	char toChar(void);
	std::string toString(void);
	std::string toIntString(void);
	std::string toFloatString(void);
	std::string toDoubleString(void);

	operator char(void);
	operator int(void);
	operator float(void);
	operator double(void);
};

std::ostream &operator<<(std::ostream&, Scalar&);

#endif
