#include <iostream>
#include <vector>

int main() {
	int totalDays{0};
	std::cin >> totalDays;
	
	std::vector<std::vector<int>> daysAndWeight(totalDays);
	for(int i = 0; i < totalDays; ++i) {
		int T{0};
		std::cin >> T;
		if(T != 0) {
			daysAndWeight[i].resize(T, 0);
			for(int j = 0; j < T; ++j) {
				std::cin >> daysAndWeight[i][j];
			}
		} else {
			daysAndWeight[i].resize(1, 0);
		}
	}

	std::vector<int> sums(totalDays);

	for(int i = 0; i < totalDays; ++i) {
		for(int j = 0; j < daysAndWeight[i].size(); ++j) {
			sums[i] += daysAndWeight[i][j];
		}
	}	

	for(int i = 0; i < daysAndWeight.size(); ++i) {
		if(sums[i] != 0) {
			std::cout << "Day " << (i + 1) << ": " << sums[i] << '\n';
		} else {
			std::cout << "Weekend" << '\n';
		}
	}	

	return 0;
}
