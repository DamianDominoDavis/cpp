#include "P.class.hpp"

P P::names[8];

void P::searchreport(void) {
	std::string f;
	for (int field = 0; field < 3; field++) {
		f = fields[field];
		if (f.length() > 10) {
			f.resize(10);
			f[9] = '.';
		}
		while (f.length() < 10)
			f = " " + f;
		std::cout << f << (field < 2 ? "|" : "");
	}
	std::cout << std::endl;
}
