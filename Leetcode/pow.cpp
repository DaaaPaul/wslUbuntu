#include <iostream>

int counter(double x, int n, int cnt) {
	if(n == 0) return cnt;
	return counter(x, n - 1, cnt + 1);
}

double myPow(double x, int n) {
	double ans = 1.0;
	int cnt = counter(x, (n > 0) ? n : -n, 0);
	
	if(n > 0) {
		for(int i = 0; i < cnt; ++i) ans *= x;
	} else {
		for(int i = 0; i < cnt; ++i) ans /= x;
	}
	
	std::cout << ans << '\n';
	return ans;
}

int main() {

}
