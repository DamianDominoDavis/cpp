#include "Scalar.hpp"

Scalar::Scalar(const char *number):
	_asint(atoi(number)), _asfloat(atof(number)), _asstr(number) {
		init();
}
Scalar::Scalar(Scalar const &src):
	_asint(src._asint), _asfloat(src._asfloat) {
		init();
}
Scalar &Scalar::operator=(Scalar const &s) {
	_asint = s._asint;
	_asfloat = s._asfloat;
	return *this;
}
Scalar::~Scalar(void) {}

void Scalar::init(void) {
	if (_asstr == "nan" || _asstr == "NULL") {
		_strint = "int: impossible";
		_strfloat = "float: nanf";
		_strdouble = "double: nan";
	}
	else {
		std::stringstream stream;
		_strint = "int: " + std::to_string(_asint);
		stream << std::fixed << std::setprecision(1) << static_cast<float>(_asfloat);
		_strfloat = "float: " + stream.str() + "f";
		stream.str(std::string());
		stream << std::fixed << std::setprecision(1) << static_cast<double>(_asfloat);
		_strdouble = "double: " + stream.str();
	}
	_to_char = (_asstr == "0" || _asstr == "NULL" || _asint < 33)?
		0 : static_cast<char>(_asint);
}

char		Scalar::toChar()		{ return _to_char; }
int			Scalar::toInt()			{ return _asint; }
std::string	Scalar::toString()		{ return _asstr; }
std::string	Scalar::toIntString()	{ return _strint; }
std::string	Scalar::toFloatString()	{ return _strfloat; }
std::string	Scalar::toDoubleString(){ return _strdouble; }

Scalar::operator char()				{ return static_cast<char>(_asint); }
Scalar::operator int()				{ return static_cast<int>(_asint); }
Scalar::operator float()			{ return static_cast<float>(_asfloat); }
Scalar::operator double()			{ return static_cast<double>(_asfloat); }

std::ostream &operator<<(std::ostream &out, Scalar &sin) {
	std::string str;
	if (sin.toString() == "nan" || sin.toInt() > 126)
		str = "char: impossible";
	else if (!sin.toChar()) 
		str = "char: unprintable";
	else
		str = "char: ";
	return (out << str << sin.toChar() << std::endl
		<< sin.toIntString() << std::endl
		<< sin.toFloatString() << std::endl
		<< sin.toDoubleString() << std::endl);
}
