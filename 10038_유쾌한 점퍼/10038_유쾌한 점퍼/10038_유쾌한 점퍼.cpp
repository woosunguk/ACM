#include <iostream>

using namespace std;

int main() {
	int num = 0;
	int sum = 0;
	int absnum = 0;
	int newnum = 0;
	int prenum = 0;


	while (1) {

		if (cin.peek() == '\n') break;
		cin >> num;

		if (num <= 3000) {
			sum = (num - 1)*(1 + (num - 1)) / 2;

			cin >> newnum;
			prenum = newnum;
			num--;
			while (num>0) {
				cin >> newnum;
				absnum = prenum - newnum;
				if (absnum < 0)
					absnum *= -1;
				sum -= absnum;
				prenum = newnum;
				num--;
			}

			if (sum < 0)
				cout << "Jolly" << endl;
			else
				cout << "Not jolly" << endl;

		}
		cin.ignore();

	}
	return 0;

}