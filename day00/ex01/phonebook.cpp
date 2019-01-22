#include "P.class.hpp"

const std::string P::prompts[] = {"firstname", "lastname", "nickname", "login",
	"postal address", "email address", "phone number", "birthday date",
	"favorite meal", "underwear color", "darkest secret"};

int main(void) {
	int i = 0;
	std::string take;
	
	while (true) {
		std::cout << "% ";
		std::getline(std::cin, take);
		if (!take.compare("EXIT"))
			return (0);
		if (!take.compare("ADD")) {
			P p;
			for (int j = 0; j < 11; j++) {
				std::cout << "  ADD " << P::prompts[j] << ": ";
				std::getline(std::cin, p.fields[j]);
			}
			std::cout << "  Added " << p.fields[0] << " " << p.fields[1]
				<< " (" << p.fields[2] << ")" << std::endl;
			P::names[i] = p;
			++i %= 8;
		}
		if (!take.compare("SEARCH")) {
			std::cout << "     index|first name| last name|  nickname"
				<< std::endl;
			for (int j = 0; j < 8; j++) {
				if (P::names[j].fields[0].length() > 0) {
					std::cout << "         " << j << "|";
					P::names[j].searchreport();
				}
			}
		}
	}
}
