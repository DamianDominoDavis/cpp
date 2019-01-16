#include <iostream>

int main(int c, char **v)
{
	if (c > 1)
		for (int w = 1; v[w]; w++)
		{
			for (int l = 0; v[w][l]; l++)
				if (v[w][l] >= 'a' && v[w][l] <= 'z')
					v[w][l] += 'A' - 'a';
			std::cout << v[w];
		}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << '\n';
	return (0);
}
