#include <iostream>

using namespace std;

int main() {
	int s = 0;
	int ss = 0;
	int h_i[100];
	cin >> s;


	while (s) {
		int days = 0;
		int party = 0;
		int count = 0;
		cin >> days;
		cin >> party;

		for (int i = 0; i < party; i++) {
			cin >> h_i[i];
		}

		for (int j = 1; j <= days; j++) {
			if (j % 7 == 6 || j % 7 == 0) {

			}
			else {
				for (int i = 0; i < party; i++) {
					if (j%h_i[i] == 0) {
						count++;
						break;
					}
				}
			}
		}
		s--;
		cout << count << endl;
	}


	return 0;
}