#include <iostream>

using namespace std;

int digit[8] = { 0,0,0,0,0,0,0,0 };
int getSize(int num) {
	int i = 0;
	while (num > 10) {
		digit[i] = num % 10;
		num /= 10;
		i++;
	}
	digit[i] = num;
	return i + 1;
}
int main(void) {

	int s = 4;
	int number;
	int number_size;
	cin >> s;
	int ss = s - 1;
	int sss = s - 1;

	int num[10][15] = {
		{ 5, 3, 5,		4, 2, 4,		5, 2, 5,		4, 2, 4,		5, 3, 5 },
		{ 5, 2, 5,		5, 2, 4,		5, 2, 5,		5, 2, 4,		5, 2, 5 },
		{ 5, 3, 5,		5, 2, 4,		5, 3, 5,		4, 2, 5,		5, 3, 5 },
		{ 5, 3, 5,		5, 2, 4,		5, 3, 5,		5, 2, 4,		5, 3, 5 },
		{ 5, 2, 5,		4, 2, 4,		5, 3, 5,		5, 2, 4,		5, 2, 5 },
		{ 5, 3, 5,		4, 2, 5,		5, 3, 5,		5, 2, 4,		5, 3, 5 },
		{ 5, 2, 5,		4, 2, 5,		5, 3, 5,		4, 2, 4,		5, 3, 5 },
		{ 5, 3, 5,		5, 2, 4,		5, 2, 5,		5, 2, 4,		5, 2, 5 },
		{ 5, 3, 5,		4, 2, 4,		5, 3, 5,		4, 2, 4,		5, 3, 5 },
		{ 5, 3, 5,		4, 2, 4,		5, 3, 5,		5, 2, 4,		5, 2, 5 } };

	cin >> number;
	number_size = getSize(number);

	for (int i = 0; i < 15; i += 3) {
		for (int j = 1; j <= number_size; j++) {
			for (int k = i; k < i + 3; k++) {
				if (num[digit[number_size - j]][k] == 5) {
					cout << " ";
				}
				else if (num[digit[number_size - j]][k] == 3) {
					for (int q = 0; q < s; q++)
						cout << "-";
				}
				else if (num[digit[number_size - j]][k] == 4) {
					cout << "|";
				}
				else if (num[digit[number_size - j]][k] == 2) {
					for (int q = 0; q < s; q++)
						cout << " ";
				}
			}
			cout << " ";
		}
		cout << endl;

		if (i == 3) {
			if (ss) {
				ss--;
				i -= 3;
			}
		}
		if (i == 9) {
			if (sss) {
				sss--;
				i -= 3;
			}
		}

	}

}