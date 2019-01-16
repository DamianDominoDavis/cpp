#include <iostream>
#include <string>

class P
{
	public:
		std::string fields[11];
	P(){}
};

int main(void)
{
	int i = 0;
	int j;
	P names[8] = {};
	std::string take;
	while (1)
	{
		std::cin >> take;
		if (!take.compare("EXIT"))
			return (0);
		if (!take.compare("ADD"))
		{
			P p = P();
			for (j=0; j<11; j++)
			{
				std::cout << "Enter: ";
				std::cin >> p.fields[j];
			}
			names[i] = p;
			i = (i + 1) % 8;
		}
		if (!take.compare("SEARCH"))
		{
			std::string nom;
			std::cout << "Who: ";
			std::cin >> nom;
			for (j=0; j < 8; j++)
				if (!nom.compare(names[j]))
				{
					std::cout << nom << " found.\n";
					break ;
				}
		}
	}
}
