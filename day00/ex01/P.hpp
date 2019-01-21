#include <iostream> //std::cin, std::cout
#include <string>

class P
{
	public:
		std::string fields[11];
	
		static const std::string prompts[11];
	
		void searchreport() {
			std::string f;
			for (int field = 0; field < 3; field++)
			{
				f = fields[field];
				if (f.length() > 10)
				{
					f.resize(10);
					f[9] = '.';
				}
				else while (f.length() < 10)
				{
					f = " " + f;
				}
				std::cout << f << (field < 2 ? "|" : "\n");
			}
		}
};
