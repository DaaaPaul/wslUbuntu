#include <iostream>

void printReverse(const char* s) {
	if(!(*s)) return;
	printReverse(s + 1);
	std::cout << *s;
}

int main() {
	printReverse("Auspix777");
	std::cout << '\n';
}
