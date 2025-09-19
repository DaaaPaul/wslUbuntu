#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct PairHash {
	template<typename T1, typename T2>
	size_t operator()(const pair<T1, T2>& p) const {
		size_t T1hash = hash<T1>{}(p.first);
		size_t T2hash = hash<T2>{}(p.second);
		return T1hash ^ (T2hash << 1);
	}
};

unordered_map<pair<int, int>, int, PairHash> cache;

int getNum(int row, int col) {
	if(row == 0 || col == 0 || col == row) return 1;
	if(cache.contains({row, col})) return cache[{row, col}];
	
	int value = getNum(row - 1, col - 1) + getNum(row - 1, col);
	cache.insert({{row, col}, value});
	return value;
}

vector<int> getRow(int rowIndex) {
	vector<int> ans;
	for(int i = 0; i <= rowIndex; ++i) {
		ans.push_back(getNum(rowIndex, i));
	}
	return ans;
}

int main() {
	int r;
	cin >> r;
	vector<int> row = getRow(r);
	for(int i : row) cout << i << ' ';
	cout << '\n';
}
