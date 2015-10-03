#include <iostream>

using namespace std;
int reverse(int n);

int main() {
	int testcase;
	int num;
	int reverse_num;
	scanf("%d", &testcase);
	
	while (testcase--) {
		scanf("%d", &num);
		while(num < 1000000){
			//cout << reverse(num) << endl;
			reverse_num = reverse(num);
			if (num == reverse_num){
				cout << "1" << endl;
				break;
			}
			else 
				num += reverse_num;
		}
		if (num >= 1000000)
			cout << "0" << endl;

	}
	return 0;
}

int reverse(int n) {
	int reverse = 0;
	while (n != 0) {
		int remainder = n % 10;
		reverse = reverse * 10 + remainder;
		n /= 10;
	}
	return reverse;
}