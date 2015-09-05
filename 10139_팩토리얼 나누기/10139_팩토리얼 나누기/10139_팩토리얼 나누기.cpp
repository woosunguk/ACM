#include <iostream>
#include <math.h>

using namespace std;
#define MAX 2147483648

int primefactors(long m);
int abcd(int prime);
void init();

short int arr[220][1000000] = { 0 };
int init_array[1000][2] = { 0 };
int init_number = 0;
long n;

int main() {
	long i = MAX;
	long m;

	while (scanf("%ld %ld", &n, &m) != EOF) {
		if (n > m)
			cout << m << " divides " << n << "!" << endl;
		else {
			if (primefactors(m))
				cout << m << " divides " << n << "!" << endl;
			else
				cout << m << " does not divide " << n << "!" << endl;
		}
		init();
	}
	return 0;
}
void init() {
	for (int i = 0; i < init_number; i++) {
		arr[init_array[i][0]][init_array[i][1]] = 0;
	}
	init_number = 0;
}

int abcd(int prime) {
	long i = prime;
	int j = 1;
	int quotient;
	int remember;

	while (i <= n) {
		quotient = i / 10000000;
		remember = i % 10000000;
		if (arr[quotient][remember] != -1) {
			arr[quotient][remember] -= 1;
			init_array[init_number][0] = quotient;
			init_array[init_number++][1] = remember;
			quotient = j / 1000000;
			remember = j % 1000000;
			arr[quotient][remember] += 1;
			init_array[init_number][0] = quotient;
			init_array[init_number++][1] = remember;
			return 0;
		}
		i += prime;
		j++;
	}
	return 1;
}
int primefactors(long m) {
	int sqrtn = sqrt(m);

	while (m % 2 == 0) {
		m /= 2;
		if (abcd(2))
			return 0;
	}
	for (int div = 3; div <= sqrtn; div += 2)
		while (m % div == 0) {
			m /= div;
			if (abcd(div))
				return 0;
		}
	if (m > 1) {
		if (abcd(m))
			return 0;
	}
	return 1;
}