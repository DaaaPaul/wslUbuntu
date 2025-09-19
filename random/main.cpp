#include <iostream>

int i = 0;

int A(const char* s, bool b) {
	++i;
	std::cerr << i << '\n';
	return A("yay", false);
}

int main() {

}
