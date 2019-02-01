#include "Array.tpp"
#include <iostream>

template <typename T> void prettyprint(Array<T> arr) {
	std::cout << '[';
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << (arr[i]<10?" ":"") << arr[i] << (i+1<arr.size()?",":"");
	std::cout << ']' << std::endl;	
}

int main(void) {
	Array<int> byIndex = Array<int>(10);
	prettyprint(byIndex);
	
	srand(time(0));
	for (unsigned int i = 0; i < byIndex.size(); i++)
		byIndex[i] = rand() % 100;
	prettyprint(byIndex);

	Array<int> byAssignment = byIndex;
	prettyprint(byAssignment);

	Array<int> byCopyCon = Array<int>(byIndex);
	prettyprint(byCopyCon);

	try {
		std::cout << Array<char>(0)[0];
	}
	catch (std::exception e) {
		std::cout << "\u2717 can't fetch [0] of size 0" << std::endl;
	}
	return (0);
}
