#include <iostream>
#include <stdio.h>

using namespace std;

int arr[2] = { 9, 2 };

void Play_game(float);
int main() {
	float number;
	while (scanf("%f", &number) != EOF) {
		if (number == 1)
			cout << "Ollie wins." << endl;
		else
			Play_game(number);
	}
	return 0;
}
void Play_game(float number) {
	bool check = 0;
	int temp;

	while (1) {
		number /= arr[check];
		temp = number;
		if (number != temp)
			number = temp + 1;

		if (number < 10)
			break;
		check = !check;
	}

	//cout << "check :: " << check << endl;
	//cout << "number:: " << number << endl;
	if (number == 2)
		cout << "Ollie wins." << endl;
	else
		cout << "Stan wins." << endl;
}