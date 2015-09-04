#include <iostream>
#include <stdio.h>

using namespace std;

void count(int);

int digit[10][10] = { {},
{ 1, 0, 9, 8, 7, 6, 5, 4, 3, 2 },{},
{ 7, 0, 3, 6, 9, 2, 5, 8, 1, 4 },{},{},{},
{ 3, 0, 7, 4, 1, 8, 5, 2, 9, 6 },{},
{ 9, 0, 1, 2, 3, 4, 5, 6, 7, 8 } };;

int last_digit;
int carry = 0;

int main() {

	int number;

	while (scanf("%lld", &number) != EOF) {
		//cin >> number;
		//cin.ignore();

		if (number == 1)
			cout << "1" << endl;
		else {
			last_digit = number % 10;
			carry = 0;
			count(number);
		}
	}

	return 0;
}

void count(int number) {
	int result = 0;
	int i = 1;
	while (result != 1) {
		result += digit[last_digit][carry] * number;
		result /= 10;
		carry = result % 10;
		i++;
	}
	cout << i << endl;
}