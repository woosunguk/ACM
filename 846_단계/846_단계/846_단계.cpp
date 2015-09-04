#include <iostream>
#include <vector>


using namespace std;

int main() {
	int testcase;
	int num1, num2;
	int step;
	int two = 2;
	int i = 1;
	int j = 2;

	scanf("%d", &testcase);


	while (testcase--) {
		scanf("%d %d", &num1, &num2);

		step = num2 - num1;
		if (step == 0)
			cout << "0" << endl;

		else {
			for (i = 1, j = 2, two = 2; step > two; i += 2, j++) {
				two = j*(j + 1);
			}

			if (step > two - (j - 1))
				cout << i + 1 << endl;
			else
				cout << i << endl;
		}
	}
	return 0;
}