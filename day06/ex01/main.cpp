#include <iostream>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void *serialize(void) {
	std::string alnum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	Data *p = new Data;
	while (p->s1.size() != 8) {
		p->s1 += alnum[(rand() % (alnum.size() - 1))];
		p->s2 += alnum[(rand() % (alnum.size() - 1))];
	}
	p->n = rand();
	return p;
}

Data *deserialize(void *raw) { return static_cast<Data*>(raw); }

int main() {
	srand(time(0));
	void *raw = serialize();
	std::cout << "breakfast cereal: " << raw << std::endl;
	Data *d = deserialize(raw);
	std::cout << "breakfast decereal: \"" << d->s1 << "\" " << d->n << " \""
		<< d->s2 << "\"" << std::endl;
	std::cout << sizeof(*d) << " bytes" << std::endl;
}
