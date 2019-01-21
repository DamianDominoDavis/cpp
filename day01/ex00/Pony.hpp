#ifndef PONY_HPP
# define PONY_HPP

#include <string>
#include "Pony.hpp"

class Pony {
	public:
		std::string name, element;

		static const std::string motto(void) {
			return ("Remember, kids: Solidarity is a Tool of the Occult!\u2122");
		}

		void ponyOnTheHeap(void) {
			;
		}

		void ponyOnTheStack(void) {
			;
		}
};

#endif
