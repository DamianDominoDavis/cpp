#include <string>
#include <iostream>

class Brain {
	public:
		const Brain* identify(void) const;
};
const Brain* Brain::identify(void) const {
	return (this);
}

class Human : public Brain {
	private:
		Brain const mybrain;
	public:
		const Brain* identify(void) const;
		Brain getBrain(void) const;
};
const Brain* Human::identify(void) const {
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
// 0x7ffee8d06419
// 0x7ffee8d06410
// >:(

// Filthy cheat:
// std::string Brain::identify(void) const {
// 	std::stringstream ss;
// 	ss << (const void*)this;
// 	return ("0x" + ss.str());
// }
