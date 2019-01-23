#include <string>
#include <iostream>



class Brain {
	public:
		Brain& identify(void);
};

Brain& Brain::identify(void) {
	return (this);
}



class Human : public Brain {
	private:
		Brain mybrain;
	public:
		Brain* identify(void);
		Brain getBrain(void);
};

Brain* Human::identify(void) {
	return (&mybrain.identify());
}

Brain Human::getBrain(void) {
	return (mybrain);
}



int main()
{
	Human bob;
	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
}
