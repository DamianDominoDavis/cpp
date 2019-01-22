#ifndef PONY_HPP
# define PONY_HPP

# include <string>
# include <iostream>

class Pony {
	public:
		Pony(void);
		~Pony(void);
		static void ponyOnTheHeap(void);
		static void ponyOnTheStack(void);
};

#endif
