#include <iostream>
#include <stdio.h>

using namespace std;

bool is_carmichael(const int n);

int main() {

	int number;

	while (scanf("%d", &number) != EOF) {
		if (number == 0)
			break;
		if (is_carmichael(number)) {
			cout << "The number " << number << " is a Carmichael number." << endl;
		}
		else {
			cout << number << " is normal." << endl;
		}
	}

	return 0;
}

bool is_carmichael(const int n)
{
	if (n < 2)
		return false;

	int k = n;
	for (int i = 2; i <= k / i; ++i)
	{
		if (k % i == 0)
		{
			if ((k / i) % i == 0)
				return false;
			if ((n - 1) % (i - 1) != 0)
				return false;
			k /= i;
			i = 1;
		}
	}
	return k != n && (n - 1) % (k - 1) == 0;
}