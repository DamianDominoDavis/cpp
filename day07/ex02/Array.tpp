#ifndef ARRAY_TPP
# define ARRAY_TPP
# include <cstddef>
# include <iostream>

template <typename T> class Array {
	T			*_arr;
	size_t		_size;
public:
	Array<T>(void): _size(0), _arr(0) {}
	Array<T>(size_t n): _size(n) {
		_arr = new T[n]();
	}
 	Array<T>(const Array<T> &o) {
		_size = o.size();
		_arr = new T[_size]();
		for (size_t i = 0; i < _size; i++)
			_arr[i] = o[i];
	}
	~Array<T>(void) {
		delete[] _arr;
	}

	Array<T>	operator= (const Array<T> &copy) {
		_size = copy.size();
		_arr = new T[_size]();
		for (size_t i = 0; i < _size; i++)
			_arr[i] = copy[i];
		return *this;
	}
	T& 			operator[](size_t i) const {
		if (i >= _size)
			throw std::exception();
		return _arr[i];
	}

	size_t		size(void) const { return _size; }
};

#endif
