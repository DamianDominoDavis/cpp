#include <string>
#include <sstream>
#include <iostream>

class Brain {
	public:
		std::string identify(void) const;
};
std::string Brain::identify(void) const {
	std::stringstream ss;
	ss << (const void*)this;
	return ("0x" + ss.str());
}

class Human : public Brain {
	private:
		Brain const mybrain;
	public:
		std::string identify(void) const;
		Brain getBrain(void) const;
};
std::string Human::identify(void) const {
	return (mybrain.identify());
}
Brain Human::getBrain(void) const {
	return (mybrain);
}

int main()
{
	Human bob;
	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
}

// Produces:
// 0x0x7ffee2cad419
// 0x0x7ffee2cad3d0
// >:(
