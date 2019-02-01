#include <iostream>

template <typename T> void swap(T &x, T &y) {
	T t = x;
	x = y;
	y = t;
}
template <typename T> T min(T x, T y) { 
	return (x < y)? x: y;
} 
template <typename T> T max(T x, T y) { 
	return (x > y)? x: y; 
} 

class Smurf {
	int _k;
public:
	Smurf(int k): _k(k) {};
	int k(void) { return _k; };
	bool operator< (Smurf s) { return (_k < s._k); }
	bool operator> (Smurf s) { return (_k > s._k); }
	bool operator==(Smurf s) { return (_k == s._k); }
};

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "max( Smurf(6), Smurf(9) ) = "
		<< ::max( Smurf(6), Smurf(9) ).k() << std::endl;	
	return 0;
}
