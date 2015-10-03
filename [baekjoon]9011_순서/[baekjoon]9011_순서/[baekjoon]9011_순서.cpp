#include <iostream>

using namespace std;

int main() {
	int testcase;
	int subcase;
	int num;
	int i;
	scanf("%d", &testcase);
	while (testcase--) {
		scanf("%d", &subcase);
		int arr[100] = { 0, };
		i = 0;
		int temp = subcase;
		while (subcase--) {
			scanf("%d", &num);

			int j = 0;
			int count = 0;
			for (j = 0; j < i; j++) {
				if (arr[j] > num)
					arr[j]++;
			}
			arr[j] = num + 1;

			i++;
		}

		int sum = i * (i + 1) / 2;
		for (int j = 0; j < i; j++) {
			sum -= arr[j];
		}

		if (sum)
			cout << "IMPOSSIBLE" << endl;
		else {
			for (int j = 0; j < i - 1; j++)
				cout << arr[j] << " ";
			cout << arr[i - 1] << endl;
		}
	}
	return 0;
}