#include <iostream>
#include <stdio.h>

using namespace std;

int gcd(int m, int n);

int main() {
	int testcase;
	int M, N, x, y;
	int lcm;
	bool check = true;
	scanf("%d", &testcase);

	while (testcase--) {
		scanf("%d %d %d %d", &M, &N, &x, &y);
		lcm = M * N / gcd(M, N);
		while(x <= lcm && y <= lcm){
			if (x == y){
				cout << x << endl;
				check = false;
				break;
			}

			if (x < y)
				x += M;
			else
				y += N;
		}
		if (check)
			cout << "-1" << endl;
		check = true;
	}

	return 0;
}
int gcd(int m, int n) {
	if (n == 0) return m;
	gcd(n, m % n);
}