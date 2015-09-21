#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int testcase;
	int h, w, n;
	int floor = 0;
	int room = 0;
	scanf("%d", &testcase);

	while (testcase--) {
		scanf("%d %d %d", &h, &w, &n);
		floor = n % h;
		room = (n / h) + 1;
		cout << n%h;
		if (room < 10)
			cout << "0";
		cout << room << endl;
	}

	return 0;
}