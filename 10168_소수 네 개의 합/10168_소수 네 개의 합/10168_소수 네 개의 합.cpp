#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

#define MAX 10000000
void SieveOfEratosthenes();
void init();

bool arr[MAX] = { false };
int for_primes[4] = { 2, 2, 2, 2 };

int main() {

	SieveOfEratosthenes();

	int number;

	while (scanf("%lld", &number) != EOF) {
		if (number > 7) {
			int i = 3;
			number -= 8;
			while (true) {
				number += 2;
				if (i < 0) {
					cout << "Impossible." << endl;
					init();
					break;
				}
				if (arr[number]) {
					int temp = number;
					while (temp--) {
						if (!arr[temp])
							break;
					}
					for_primes[i] = temp;
					number -= temp;
					i--;
				}

				else {
					for_primes[i] = number;
					cout << for_primes[0] << " " << for_primes[1] << " " << for_primes[2] << " " << for_primes[3] << endl;
					init();
					break;
				}

			}
		}
		else if (number > 0) {
			cout << "Impossible." << endl;
		}
	}

	return 0;
}

void init() {
	for (int i = 0; i < 4; i++) {
		for_primes[i] = 2;
	}
}

void SieveOfEratosthenes()
{
	for (int i = 2; i < sqrt(MAX); i++) {
		for (int j = i*i; j < MAX; j += i) {
			arr[j] = true;
		}
	}
}